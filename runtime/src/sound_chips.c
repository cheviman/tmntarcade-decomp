/**
 *    Name:        sound_chips.c
 *    Description: TMNT's sound chips besides the YM2151: the K007232 (two PCM voices), the uPD7759 (ADPCM speech)
 *                 and the title music (a sample the sound board plays through a DAC)
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME 0.289 sample for sample: sound/k007232.cpp (Hiromitsu Shioya), sound/upd7759.cpp
 *    (Juergen Buchmueller, Mike Balfour, Howie Cohen, Olivier Galibert, Aaron Giles) and konami/tmnt.cpp's
 *    title music (its samples device over tmnt_decode_sample, and ymfm's decode_fp). kref --sound-check
 *    compares them. MAME's terms are in tools/core/konami/reference/mame/LICENSE.
 *
 *    The K007232: each voice steps through its samples (7 bits, a set bit 7 ending them) at a rate its
 *    12-bit step sets, and adds the sample less 0x40 times its volume to each output.
 *    The uPD7759: a state machine clocked at 640 kHz reads the ROM's header, finds the sample asked for, and
 *    plays its blocks: silences, runs of ADPCM nibbles, repeats; the output is the ADPCM's sum.
 */
#include "tmnt/sound_chips.h"

#include <string.h>

/* ---- K007232 ---- */

#define PCM_LIMIT  (1u << 17)

static uint8_t pcm_sample(const k007232 *chip, int voice, uint32_t address)
{
	return chip->rom[(chip->voices[voice].bank + address) % chip->rom_size];
}

void k007232_init(k007232 *chip, const uint8_t *rom, uint32_t rom_size)
{
	void (*port_write)(void *, uint8_t) = chip->port_write;
	void *host = chip->host;

	memset(chip, 0, sizeof(*chip));
	chip->port_write = port_write;
	chip->host = host;
	chip->rom = rom;
	chip->rom_size = rom_size;
	for (int voice = 0; voice < 2; voice++)
		chip->voices[voice].counter = 0x1000;
	chip->voices[0].volume[0] = 255;
	chip->voices[1].volume[1] = 255;
}

static void k007232_start(k007232 *chip, int voice)
{
	k007232_voice *channel = &chip->voices[voice];
	const uint32_t limit = chip->rom_size < PCM_LIMIT ? chip->rom_size : PCM_LIMIT;

	if (channel->start < limit)
	{
		channel->playing = true;
		channel->address = channel->start;
		channel->counter = 0x1000;
	}
}

void k007232_write(k007232 *chip, int offset, uint8_t data)
{
	chip->registers[offset & 15] = data;
	if (offset == 12)
	{
		if (chip->port_write)
			chip->port_write(chip->host, data);
	}
	else if (offset < 12)
	{
		k007232_voice *channel = &chip->voices[offset >= 6 ? 1 : 0];
		const int base = offset >= 6 ? 6 : 0;

		switch (offset - base)
		{
		case 0:
		case 1:
			channel->step = (uint32_t)(chip->registers[base + 1] & 0x0F) << 8 | chip->registers[base];
			break;
		case 2:
		case 3:
		case 4:
			channel->start = (uint32_t)(chip->registers[base + 4] & 1) << 16 | (uint32_t)chip->registers[base + 3] << 8
				| chip->registers[base + 2];
			break;
		case 5:
			k007232_start(chip, base ? 1 : 0);
			break;
		}
	}
}

uint8_t k007232_read(k007232 *chip, int offset)
{
	if (offset == 5 || offset == 11)
		k007232_start(chip, offset == 11 ? 1 : 0);
	return 0;
}

void k007232_set_volume(k007232 *chip, int voice, int volume_a, int volume_b)
{
	chip->voices[voice].volume[0] = volume_a;
	chip->voices[voice].volume[1] = volume_b;
}

void k007232_generate(k007232 *chip, float out[2])
{
	const uint32_t limit = chip->rom_size < PCM_LIMIT ? chip->rom_size : PCM_LIMIT;
	int32_t left = 0, right = 0;

	for (int voice = 0; voice < 2; voice++)
	{
		k007232_voice *channel = &chip->voices[voice];

		if (!channel->playing)
			continue;

		const int volume_a = channel->volume[0] * 2, volume_b = channel->volume[1] * 2;
		uint32_t address = channel->address & 0x1FFFF;

		while (channel->counter <= channel->step)
		{
			if (address >= limit || (pcm_sample(chip, voice, address++) & 0x80))
			{
				if (chip->registers[13] & (1u << voice))
					address = channel->start;
				else
				{
					channel->playing = false;
					break;
				}
			}
			channel->counter += 0x1000 - channel->step;
		}
		channel->address = address;
		/* (a voice that stops leaves the other out of this sample: MAME's loop breaks) */
		if (!channel->playing)
			break;
		channel->counter -= 32;

		const int sample = (pcm_sample(chip, voice, address) & 0x7F) - 0x40;

		left += sample * volume_a;
		right += sample * volume_b;
	}
	out[0] = (float)left * (1.0f / 32768.0f);
	out[1] = (float)right * (1.0f / 32768.0f);
}

/* ---- uPD7759 ---- */

#define FRAC_BITS  20
#define FRAC_ONE   (1u << FRAC_BITS)

enum
{
	STATE_IDLE, STATE_DROP_DRQ, STATE_START, STATE_FIRST_REQ, STATE_LAST_SAMPLE, STATE_DUMMY1, STATE_ADDR_MSB,
	STATE_ADDR_LSB, STATE_DUMMY2, STATE_BLOCK_HEADER, STATE_NIBBLE_COUNT, STATE_NIBBLE_MSN, STATE_NIBBLE_LSN
};

static const int adpcm_steps[16][16] =
{
	{ 0, 0, 1, 2, 3, 5, 7, 10, 0, 0, -1, -2, -3, -5, -7, -10 },
	{ 0, 1, 2, 3, 4, 6, 8, 13, 0, -1, -2, -3, -4, -6, -8, -13 },
	{ 0, 1, 2, 4, 5, 7, 10, 15, 0, -1, -2, -4, -5, -7, -10, -15 },
	{ 0, 1, 3, 4, 6, 9, 13, 19, 0, -1, -3, -4, -6, -9, -13, -19 },
	{ 0, 2, 3, 5, 8, 11, 15, 23, 0, -2, -3, -5, -8, -11, -15, -23 },
	{ 0, 2, 4, 7, 10, 14, 19, 29, 0, -2, -4, -7, -10, -14, -19, -29 },
	{ 0, 3, 5, 8, 12, 16, 22, 33, 0, -3, -5, -8, -12, -16, -22, -33 },
	{ 1, 4, 7, 10, 15, 20, 29, 43, -1, -4, -7, -10, -15, -20, -29, -43 },
	{ 1, 4, 8, 13, 18, 25, 35, 53, -1, -4, -8, -13, -18, -25, -35, -53 },
	{ 1, 6, 10, 16, 22, 31, 43, 64, -1, -6, -10, -16, -22, -31, -43, -64 },
	{ 2, 7, 12, 19, 27, 37, 51, 76, -2, -7, -12, -19, -27, -37, -51, -76 },
	{ 2, 9, 16, 24, 34, 46, 64, 96, -2, -9, -16, -24, -34, -46, -64, -96 },
	{ 3, 11, 19, 29, 41, 57, 79, 117, -3, -11, -19, -29, -41, -57, -79, -117 },
	{ 4, 13, 24, 36, 50, 69, 96, 143, -4, -13, -24, -36, -50, -69, -96, -143 },
	{ 4, 16, 29, 44, 62, 85, 118, 175, -4, -16, -29, -44, -62, -85, -118, -175 },
	{ 6, 20, 36, 54, 76, 104, 144, 214, -6, -20, -36, -54, -76, -104, -144, -214 }
};

static const int adpcm_states[16] = { -1, -1, 0, 0, 1, 2, 2, 3, -1, -1, 0, 0, 1, 2, 2, 3 };

static uint8_t speech_byte(const upd7759 *chip, uint32_t address)
{
	return chip->rom[(address & 0x3FFFF) % chip->rom_size];
}

static void upd7759_device_reset(upd7759 *chip)
{
	chip->position = 0;
	chip->state = STATE_IDLE;
	chip->clocks_left = 0;
	chip->nibbles_left = 0;
	chip->repeat_count = 0;
	chip->post_drq_state = STATE_IDLE;
	chip->post_drq_clocks = 0;
	chip->request = 0;
	chip->last_sample = 0;
	chip->block_header = 0;
	chip->sample_rate = 0;
	chip->first_valid_header = 0;
	chip->offset = 0;
	chip->repeat_offset = 0;
	chip->adpcm_state = 0;
	chip->adpcm_data = 0;
	chip->sample = 0;
	chip->drq = 0;
}

void upd7759_init(upd7759 *chip, const uint8_t *rom, uint32_t rom_size)
{
	memset(chip, 0, sizeof(*chip));
	chip->rom = rom;
	chip->rom_size = rom_size;
	chip->reset = 1;
	chip->start = 1;
	upd7759_device_reset(chip);
}

static void update_adpcm(upd7759 *chip, int data)
{
	chip->sample = (int16_t)(chip->sample + adpcm_steps[chip->adpcm_state][data]);
	chip->adpcm_state = (int8_t)(chip->adpcm_state + adpcm_states[data]);
	if (chip->adpcm_state < 0)
		chip->adpcm_state = 0;
	else if (chip->adpcm_state > 15)
		chip->adpcm_state = 15;
}

/* MAME's advance_state, stand-alone mode (the chip reads its own ROM) */
static void advance_state(upd7759 *chip)
{
	switch (chip->state)
	{
	case STATE_IDLE:
		chip->clocks_left = 4;
		break;
	case STATE_DROP_DRQ:
		chip->drq = 0;
		chip->clocks_left = chip->post_drq_clocks;
		chip->state = chip->post_drq_state;
		break;
	case STATE_START:
		chip->request = chip->fifo;
		chip->clocks_left = 70;
		chip->state = STATE_FIRST_REQ;
		break;
	case STATE_FIRST_REQ:
		chip->drq = 1;
		chip->clocks_left = 44;
		chip->state = STATE_LAST_SAMPLE;
		break;
	case STATE_LAST_SAMPLE:
		chip->last_sample = speech_byte(chip, 0);
		chip->drq = 1;
		chip->clocks_left = 28;
		chip->state = chip->request > chip->last_sample ? STATE_IDLE : STATE_DUMMY1;
		break;
	case STATE_DUMMY1:
		chip->drq = 1;
		chip->clocks_left = 32;
		chip->state = STATE_ADDR_MSB;
		break;
	case STATE_ADDR_MSB:
		chip->offset = (uint32_t)speech_byte(chip, chip->request * 2u + 5u) << 9;
		chip->drq = 1;
		chip->clocks_left = 44;
		chip->state = STATE_ADDR_LSB;
		break;
	case STATE_ADDR_LSB:
		chip->offset |= (uint32_t)speech_byte(chip, chip->request * 2u + 6u) << 1;
		chip->drq = 1;
		chip->clocks_left = 36;
		chip->state = STATE_DUMMY2;
		break;
	case STATE_DUMMY2:
		chip->offset++;
		chip->first_valid_header = 0;
		chip->drq = 1;
		chip->clocks_left = 36;
		chip->state = STATE_BLOCK_HEADER;
		break;
	case STATE_BLOCK_HEADER:
		if (chip->repeat_count)
		{
			chip->repeat_count--;
			chip->offset = chip->repeat_offset;
		}
		chip->block_header = speech_byte(chip, chip->offset++);
		chip->drq = 1;
		switch (chip->block_header & 0xC0)
		{
		case 0x00:      /* silence */
			chip->clocks_left = 1024 * ((chip->block_header & 0x3F) + 1);
			chip->state = (chip->block_header == 0 && chip->first_valid_header) ? STATE_IDLE : STATE_BLOCK_HEADER;
			chip->sample = 0;
			chip->adpcm_state = 0;
			break;
		case 0x40:      /* 256 nibbles */
			chip->sample_rate = (uint8_t)((chip->block_header & 0x3F) + 1);
			chip->nibbles_left = 256;
			chip->clocks_left = 36;
			chip->state = STATE_NIBBLE_MSN;
			break;
		case 0x80:      /* n nibbles */
			chip->sample_rate = (uint8_t)((chip->block_header & 0x3F) + 1);
			chip->clocks_left = 36;
			chip->state = STATE_NIBBLE_COUNT;
			break;
		case 0xC0:      /* repeat loop */
			chip->repeat_count = (uint8_t)((chip->block_header & 7) + 1);
			chip->repeat_offset = chip->offset;
			chip->clocks_left = 36;
			chip->state = STATE_BLOCK_HEADER;
			break;
		}
		if (chip->block_header != 0)
			chip->first_valid_header = 1;
		break;
	case STATE_NIBBLE_COUNT:
		chip->nibbles_left = speech_byte(chip, chip->offset++) + 1u;
		chip->drq = 1;
		chip->clocks_left = 36;
		chip->state = STATE_NIBBLE_MSN;
		break;
	case STATE_NIBBLE_MSN:
		chip->adpcm_data = speech_byte(chip, chip->offset++);
		update_adpcm(chip, chip->adpcm_data >> 4);
		chip->drq = 1;
		chip->clocks_left = chip->sample_rate * 4;
		chip->state = --chip->nibbles_left == 0 ? STATE_BLOCK_HEADER : STATE_NIBBLE_LSN;
		break;
	case STATE_NIBBLE_LSN:
		update_adpcm(chip, chip->adpcm_data & 15);
		chip->clocks_left = chip->sample_rate * 4;
		chip->state = --chip->nibbles_left == 0 ? STATE_BLOCK_HEADER : STATE_NIBBLE_MSN;
		break;
	}
	if (chip->drq)
	{
		chip->post_drq_state = chip->state;
		chip->post_drq_clocks = chip->clocks_left - 21;
		chip->state = STATE_DROP_DRQ;
		chip->clocks_left = 21;
	}
}

void upd7759_port_write(upd7759 *chip, uint8_t data)
{
	chip->fifo = data;
}

void upd7759_start_write(upd7759 *chip, int state)
{
	const uint8_t before = chip->start;

	chip->start = state != 0;
	if (chip->state == STATE_IDLE && before && !chip->start && chip->reset)
		chip->state = STATE_START;
}

void upd7759_reset_write(upd7759 *chip, int state)
{
	const uint8_t before = chip->reset;

	chip->reset = state != 0;
	if (before && !chip->reset)
		upd7759_device_reset(chip);
}

int upd7759_busy(const upd7759 *chip)
{
	return chip->state == STATE_IDLE;
}

/* MAME's sound_stream_update: 'count' samples, the state machine moving on 4 clocks for each. As there, a
   block that goes idle holds its last sample to its end (and its clocks run on), and the next block starts
   silent: the samples depend on where the blocks end, which the host keeps where MAME's are (each change of
   the chip, and the end of the frame) */
void upd7759_generate(upd7759 *chip, float *out, int count)
{
	const float scale = 128.0f / 32768.0f;
	float sample = (float)chip->sample * scale;
	int32_t clocks_left = chip->clocks_left;
	uint32_t position = chip->position;
	int index = 0;

	if (chip->state != STATE_IDLE)
		for (; index < count; index++)
		{
			out[index] = sample;
			position += 4 * FRAC_ONE;
			while (position >= FRAC_ONE)
			{
				int32_t clocks = (int32_t)(position >> FRAC_BITS);

				if (clocks > clocks_left)
					clocks = clocks_left;
				position -= (uint32_t)clocks * FRAC_ONE;
				clocks_left -= clocks;
				if (clocks_left == 0)
				{
					advance_state(chip);
					if (chip->state == STATE_IDLE)
						break;
					clocks_left = chip->clocks_left;
					sample = (float)chip->sample * scale;
				}
			}
		}
	for (; index < count; index++)
		out[index] = 0.0f;
	chip->clocks_left = clocks_left;
	chip->position = position;
}

/* ---- the title music ---- */

/* ymfm's decode_fp */
static int16_t decode_fp(int16_t value)
{
	value = (int16_t)(value ^ 0x1E00);
	return (int16_t)((int16_t)(value << 6) >> ((value >> 10) & 7));
}

void title_music_init(title_music *music, const uint8_t *rom, size_t size)
{
	memset(music, 0, sizeof(*music));
	music->rom = rom;
	music->samples = size / 2;
}

void title_music_start(title_music *music)
{
	if (!music->playing)
	{
		music->playing = true;
		music->position = 0;
	}
}

void title_music_stop(title_music *music)
{
	music->playing = false;
}

float title_music_generate(title_music *music)
{
	float value = 0.0f;

	if (music->playing)
	{
		const int word = music->rom[2 * music->position] + music->rom[2 * music->position + 1] * 256;

		value = (float)decode_fp((int16_t)(word >> 3)) * (1.0f / 32768.0f);
		if (++music->position == music->samples)
			music->playing = false;
	}
	return value;
}
