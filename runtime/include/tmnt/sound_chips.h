/**
 *    Name:        sound_chips.h
 *    Description: TMNT's sound chips besides the YM2151: the K007232 (two PCM voices), the uPD7759 (ADPCM speech)
 *                 and the title music (a sample the sound board plays through a DAC)
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The game's own chips (no MAME code): every sample is the one MAME's k007232.cpp and upd7759.cpp, and
 *    tmnt.cpp's samples device, make from the same writes (kref --sound-check compares them). The K007232
 *    makes a sample every 128 clocks of the Z80's clock, a pair (its two outputs); the uPD7759 one every 4
 *    of its 640 kHz clock; the title music one every 32 of them. Samples are in MAME's float range (1.0 at
 *    full scale).
 */
#ifndef TMNT_SOUND_CHIPS_H
#define TMNT_SOUND_CHIPS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ---- K007232 ---- */

typedef struct
{
	uint32_t address, start, counter, step, bank;
	bool playing;
	int volume[2];          /* to output A, to output B */
} k007232_voice;

typedef struct
{
	const uint8_t *rom;
	uint32_t rom_size;
	uint8_t registers[16];
	k007232_voice voices[2];
	/* register 12 goes to the board's port: tmnt.cpp's volume_callback sets the voices' volumes */
	void (*port_write)(void *host, uint8_t data);
	void *host;
} k007232;

void k007232_init(k007232 *chip, const uint8_t *rom, uint32_t rom_size);
void k007232_write(k007232 *chip, int offset, uint8_t data);
uint8_t k007232_read(k007232 *chip, int offset);
void k007232_set_volume(k007232 *chip, int voice, int volume_a, int volume_b);
/* The next pair of samples (outputs A and B), as MAME's put_int(.., 32768) gives them */
void k007232_generate(k007232 *chip, float out[2]);

/* ---- uPD7759 ---- */

typedef struct
{
	const uint8_t *rom;
	uint32_t rom_size;
	uint32_t position;      /* the clocks' fraction, 12.20 */
	int state, post_drq_state;
	int32_t clocks_left, post_drq_clocks;
	uint32_t nibbles_left;
	uint8_t repeat_count;
	uint8_t request, last_sample, block_header, sample_rate, first_valid_header;
	uint32_t offset, repeat_offset;
	int8_t adpcm_state;
	uint8_t adpcm_data;
	int16_t sample;
	uint8_t fifo, reset, start, drq;
} upd7759;

void upd7759_init(upd7759 *chip, const uint8_t *rom, uint32_t rom_size);
void upd7759_port_write(upd7759 *chip, uint8_t data);
void upd7759_start_write(upd7759 *chip, int state);
void upd7759_reset_write(upd7759 *chip, int state);
/* The busy line as the board reads it: 1 while the chip stands idle (MAME's busy_r) */
int upd7759_busy(const upd7759 *chip);
/* The next 'count' samples, as one block of MAME's stream (where blocks end changes them: see sound_chips.c) */
void upd7759_generate(upd7759 *chip, float *out, int count);

/* ---- the title music ---- */

typedef struct
{
	const uint8_t *rom;     /* 16-bit little-endian words, the sample in 3.10 floating point above 3 bits */
	size_t samples;
	size_t position;
	bool playing;
} title_music;

void title_music_init(title_music *music, const uint8_t *rom, size_t size);
void title_music_start(title_music *music);
void title_music_stop(title_music *music);
float title_music_generate(title_music *music);

#ifdef __cplusplus
}
#endif

#endif
