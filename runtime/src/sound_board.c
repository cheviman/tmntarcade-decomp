/**
 *    Name:        sound_board.c
 *    Description: the game's own sound board: the Z80's memory map, the sound chips and their samples, the
 *                 frame's hashes and mix
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME's konami/tmnt.cpp (Nicola Salmoria): tmnt_audio_map, sres_r and sres_w (bit 1 the
 *    uPD7759's reset, bit 2 the title music), tmnt_upd_start_w, tmnt_upd_busy_r, the K007232's volume
 *    callback and the routes' gains; and how MAME's sound streams make their samples, as
 *    tools/core/konami/reference/sound/ksound.cpp keeps them for the reference. MAME's terms are in
 *    tools/core/konami/reference/mame/LICENSE. Every chip catches up with the present (the running block's
 *    time) before the program reads or writes it, as MAME's streams update before each change.
 */
#include "sound_internal.h"

#include "game/assets.h"
#include "game/data.h"
#include "sound/support.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tmnt_sound_board tmnt_sound;

/* a source's rate: num / den samples a second */
typedef struct
{
	uint64_t num, den;
} rate;

static const rate FM_RATE = { TMNT_SOUND_CLOCK, 64 };
static const rate PCM_RATE = { TMNT_SOUND_CLOCK, 128 };
static const rate SPEECH_RATE = { TMNT_SPEECH_CLOCK, 4 };
static const rate TITLE_RATE = { TMNT_SPEECH_CLOCK, 32 };

#define NO_TIME UINT64_MAX

/* how many of a source's samples start before Z80 cycle 'cycle', and which one is playing at it */
static uint64_t samples_before(uint64_t cycle, rate source)
{
	return (cycle * source.num + TMNT_SOUND_CLOCK * source.den - 1) / (TMNT_SOUND_CLOCK * source.den);
}

static uint64_t sample_at(uint64_t cycle, rate source)
{
	return cycle * source.num / (TMNT_SOUND_CLOCK * source.den);
}

/* ---- a source's samples: 'outputs' channels interleaved, from sample number 'first' on ---- */

typedef struct
{
	int outputs;
	float *data;
	size_t count, capacity;     /* values, not samples */
	uint64_t first;
	uint64_t made;              /* samples made so far */
	float last[2];              /* the last sample taken out, for the mix */
	float *taken;               /* the frame's, taken out */
	size_t taken_count;
} samples;

static samples g_fm_samples = { .outputs = 2 }, g_pcm_samples = { .outputs = 2 }, g_speech_samples = { .outputs = 1 },
	g_title_samples = { .outputs = 1 };

static void reserve(float **data, size_t *capacity, size_t needed)
{
	if (needed <= *capacity)
		return;
	*capacity = needed + needed / 2 + 1024;
	*data = (float *)realloc(*data, *capacity * sizeof(float));
	if (!*data)
	{
		fprintf(stderr, "The sound board ran out of memory for its samples\n");
		exit(3);
	}
}

static void push(samples *source, const float *values)
{
	reserve(&source->data, &source->capacity, source->count + (size_t)source->outputs);
	memcpy(source->data + source->count, values, (size_t)source->outputs * sizeof(float));
	source->count += (size_t)source->outputs;
	source->made++;
}

static void reset_samples(samples *source)
{
	source->count = 0;
	source->first = source->made = 0;
	source->last[0] = source->last[1] = 0.0f;
	source->taken_count = 0;
}

/* ---- time ---- */

static uint64_t g_now_override = NO_TIME;    /* while a timer runs out, its own time */

static uint64_t now(void)
{
	return g_now_override != NO_TIME ? g_now_override : sound_cpu_access();
}

/* ---- the YM2151 (its IRQ goes nowhere on this board) ---- */

static uint64_t g_deadline[2] = { NO_TIME, NO_TIME };
static uint64_t g_busy_until;

static void fm_catch_up(uint64_t cycle)
{
	const uint64_t due = samples_before(cycle, FM_RATE);

	while (g_fm_samples.made < due)
	{
		int32_t output[2];
		float values[2];

		ym2151_generate(&tmnt_sound.fm, output);
		values[0] = (float)output[0] * (1.0f / 32768.0f);
		values[1] = (float)output[1] * (1.0f / 32768.0f);
		push(&g_fm_samples, values);
	}
}

static void fm_set_timer(void *host, int timer, int32_t clocks)
{
	(void)host;
	g_deadline[timer] = clocks < 0 ? NO_TIME : now() + (uint64_t)clocks;
}

static void fm_set_busy_end(void *host, uint32_t clocks)
{
	(void)host;
	g_busy_until = now() + clocks;
}

static bool fm_is_busy(void *host)
{
	(void)host;
	return now() < g_busy_until;
}

void sound_timers_due(uint64_t cycle)
{
	for (;;)
	{
		const int timer = g_deadline[0] <= g_deadline[1] ? 0 : 1;
		const uint64_t when = g_deadline[timer];

		if (when > cycle)
			break;
		g_deadline[timer] = NO_TIME;
		fm_catch_up(when);
		g_now_override = when;
		ym2151_timer_expired(&tmnt_sound.fm, timer);
		g_now_override = NO_TIME;
	}
}

/* ---- the K007232, the uPD7759 and the title music ---- */

static void pcm_catch_up(uint64_t cycle)
{
	const uint64_t due = samples_before(cycle, PCM_RATE);

	while (g_pcm_samples.made < due)
	{
		float values[2];

		k007232_generate(&tmnt_sound.pcm, values);
		push(&g_pcm_samples, values);
	}
}

/* tmnt.cpp's volume_callback: the K007232's port sets its two channels' volumes */
static void pcm_port_write(void *host, uint8_t data)
{
	(void)host;
	k007232_set_volume(&tmnt_sound.pcm, 0, (data >> 4) * 0x11, 0);
	k007232_set_volume(&tmnt_sound.pcm, 1, 0, (data & 0x0f) * 0x11);
}

/* the uPD7759 makes its samples a block at a time, from where it stopped up to the present */
static void speech_catch_up(uint64_t cycle)
{
	const uint64_t due = samples_before(cycle, SPEECH_RATE);
	const size_t count = (size_t)(due - g_speech_samples.made);

	if (due <= g_speech_samples.made)
		return;
	reserve(&g_speech_samples.data, &g_speech_samples.capacity, g_speech_samples.count + count + 1);
	upd7759_generate(&tmnt_sound.speech, g_speech_samples.data + g_speech_samples.count, (int)count);
	g_speech_samples.count += count;
	g_speech_samples.made = due;
}

static void title_catch_up(uint64_t cycle)
{
	const uint64_t due = samples_before(cycle, TITLE_RATE);

	while (g_title_samples.made < due)
	{
		const float value = title_music_generate(&tmnt_sound.title);

		push(&g_title_samples, &value);
	}
}

/* ---- the Z80's bus ---- */

const uint8_t *tmnt_sound_data_at(uint32_t address)
{
	const uint8_t *found = assets_sound_data_at(address & 0xFFFFu);

	if (!found)
	{
		fprintf(stderr, "Sound program data read at %04X, where no asset has data\n", (unsigned)(address & 0xFFFFu));
		exit(3);
	}
	return found;
}

uint8_t sound_bus_read(uint16_t address)
{
	if (address < 0x8000u)
		return *tmnt_sound_data_at(address);
	if (address < 0x8000u + TMNT_SOUND_RAM_SIZE)
		return tmnt_sound.ram[address - 0x8000u];
	if (address == 0x9000u)
		return tmnt_sound.control;
	if (address == 0xA000u)
		return tmnt_board.sound_latch;
	if (address >= 0xB000u && address <= 0xB00Du)
	{
		pcm_catch_up(now());
		return k007232_read(&tmnt_sound.pcm, address - 0xB000u);
	}
	if (address == 0xC000u || address == 0xC001u)
	{
		fm_catch_up(now());
		return ym2151_read(&tmnt_sound.fm, address - 0xC000u);
	}
	if (address == 0xF000u)
	{
		speech_catch_up(now());
		return upd7759_busy(&tmnt_sound.speech) ? 1 : 0;
	}
	return 0;
}

void sound_bus_write(uint16_t address, uint8_t data)
{
	if (address >= 0x8000u && address < 0x8000u + TMNT_SOUND_RAM_SIZE)
		tmnt_sound.ram[address - 0x8000u] = data;
	else if (address == 0x9000u)
	{
		/* sres_w: bit 1 the uPD7759's reset, bit 2 the title music */
		speech_catch_up(now());
		upd7759_reset_write(&tmnt_sound.speech, (data >> 1) & 1);
		title_catch_up(now());
		if (data & 4)
			title_music_start(&tmnt_sound.title);
		else
			title_music_stop(&tmnt_sound.title);
		tmnt_sound.control = data;
	}
	else if (address >= 0xB000u && address <= 0xB00Du)
	{
		pcm_catch_up(now());
		k007232_write(&tmnt_sound.pcm, address - 0xB000u, data);
	}
	else if (address == 0xC000u || address == 0xC001u)
	{
		fm_catch_up(now());
		ym2151_write(&tmnt_sound.fm, address - 0xC000u, data);
	}
	else if (address == 0xD000u)
	{
		speech_catch_up(now());
		upd7759_port_write(&tmnt_sound.speech, data);
	}
	else if (address == 0xE000u)
	{
		/* tmnt_upd_start_w: the start line is bit 0, inverted */
		speech_catch_up(now());
		upd7759_start_write(&tmnt_sound.speech, !(data & 1));
	}
}

/* ---- the board ---- */

const char *tmnt_sound_init(void)
{
	static char problem[160];

	memset(&tmnt_sound, 0, sizeof(tmnt_sound));
	g_deadline[0] = g_deadline[1] = NO_TIME;
	g_busy_until = 0;
	g_now_override = NO_TIME;
	reset_samples(&g_fm_samples);
	reset_samples(&g_pcm_samples);
	reset_samples(&g_speech_samples);
	reset_samples(&g_title_samples);
	sound_cpu_reset(sound_z80_time(tmnt_board.cycles));

	tmnt_sound.fm.set_timer = fm_set_timer;
	tmnt_sound.fm.set_busy_end = fm_set_busy_end;
	tmnt_sound.fm.is_busy = fm_is_busy;
	ym2151_init(&tmnt_sound.fm);
	tmnt_sound.pcm.port_write = pcm_port_write;
	k007232_init(&tmnt_sound.pcm, game_pcm, GAME_PCM_SIZE);
	upd7759_init(&tmnt_sound.speech, game_speech, GAME_SPEECH_SIZE);
	title_music_init(&tmnt_sound.title, game_title, GAME_TITLE_SIZE);

	/* the tables the program reads by name: the asset pieces of those names */
	for (size_t index = 0; index < sound_table_count; index++)
	{
		const uint8_t *data = assets_sound_piece(sound_tables[index].name, NULL);

		if (!data)
		{
			snprintf(problem, sizeof(problem), "the sound program's table %s is in no asset", sound_tables[index].name);
			return problem;
		}
		*sound_tables[index].data = data;
	}
	return NULL;
}

void tmnt_sound_run(uint64_t time)
{
	sound_cpu_run(time);
}

static void sync_with_board(void)
{
	sound_cpu_run(tmnt_board.cycles);
}

void tmnt_sound_attach(void)
{
	tmnt_board.sound_sync = sync_with_board;
	tmnt_board.sound_irq = tmnt_sound_irq;
}

void tmnt_sound_irq(void)
{
	sound_cpu_irq();
}

uint64_t tmnt_sound_z80_cycles(void)
{
	return sound_cpu_clock();
}

/* ---- the frame ---- */

static uint64_t g_frame_samples_hash;
static uint64_t g_source_hashes[4];
static int16_t *g_mix;
static size_t g_mix_count, g_mix_capacity;

static uint64_t hash_bytes(const void *data, size_t size, uint64_t hash)
{
	const uint8_t *bytes = (const uint8_t *)data;

	for (size_t index = 0; index < size; index++)
		hash = (hash ^ bytes[index]) * 0x100000001b3ull;
	return hash;
}

/* the source's samples that start before 'due' out of it (into its 'taken'), into the hash */
static uint64_t take(samples *source, uint64_t due, uint64_t hash)
{
	const uint64_t available = source->count / (size_t)source->outputs;
	const uint64_t wanted = due - source->first;
	const size_t count = (size_t)(wanted < available ? wanted : available) * (size_t)source->outputs;

	free(source->taken);
	source->taken = (float *)malloc((count ? count : 1) * sizeof(float));
	if (!source->taken)
	{
		fprintf(stderr, "The sound board ran out of memory for its samples\n");
		exit(3);
	}
	memcpy(source->taken, source->data, count * sizeof(float));
	source->taken_count = count;
	memmove(source->data, source->data + count, (source->count - count) * sizeof(float));
	source->count -= count;
	source->first += count / (size_t)source->outputs;
	return hash_bytes(source->taken, count * sizeof(float), hash);
}

/* a source's value at sample 'index' of what was taken (from 'first' on), or the one before it */
static float value_at(const samples *source, uint64_t first, uint64_t index, int output)
{
	size_t at;

	if (index < first)
		return source->last[output];
	at = (size_t)(index - first) * (size_t)source->outputs + (size_t)output;
	return at < source->taken_count ? source->taken[at] : source->last[output];
}

static void remember_last(samples *source)
{
	if (source->taken_count >= (size_t)source->outputs)
		memcpy(source->last, source->taken + source->taken_count - (size_t)source->outputs,
			(size_t)source->outputs * sizeof(float));
}

static int16_t clamp16(int value)
{
	return (int16_t)(value < -32768 ? -32768 : value > 32767 ? 32767 : value);
}

void tmnt_sound_end_frame(uint64_t time)
{
	const uint64_t cycle = sound_z80_time(time);
	uint64_t fm_first, pcm_first, speech_first, title_first, hash = 0xcbf29ce484222325ull;

	sound_cpu_run(time);
	fm_catch_up(cycle);
	pcm_catch_up(cycle);
	speech_catch_up(cycle);
	title_catch_up(cycle);

	/* the samples that start before the frame's end */
	fm_first = g_fm_samples.first;
	pcm_first = g_pcm_samples.first;
	speech_first = g_speech_samples.first;
	title_first = g_title_samples.first;
	hash = take(&g_fm_samples, samples_before(cycle, FM_RATE), hash);
	hash = take(&g_pcm_samples, samples_before(cycle, PCM_RATE), hash);
	hash = take(&g_speech_samples, samples_before(cycle, SPEECH_RATE), hash);
	g_frame_samples_hash = take(&g_title_samples, samples_before(cycle, TITLE_RATE), hash);
	g_source_hashes[0] = hash_bytes(g_fm_samples.taken, g_fm_samples.taken_count * sizeof(float), 0xcbf29ce484222325ull);
	g_source_hashes[1] = hash_bytes(g_pcm_samples.taken, g_pcm_samples.taken_count * sizeof(float), 0xcbf29ce484222325ull);
	g_source_hashes[2] = hash_bytes(g_speech_samples.taken, g_speech_samples.taken_count * sizeof(float), 0xcbf29ce484222325ull);
	g_source_hashes[3] = hash_bytes(g_title_samples.taken, g_title_samples.taken_count * sizeof(float), 0xcbf29ce484222325ull);

	/* the mix, at the YM2151's rate (tmnt.cpp's routes to its one speaker) */
	g_mix_count = 0;
	if (g_mix_capacity < g_fm_samples.taken_count / 2)
	{
		g_mix_capacity = g_fm_samples.taken_count / 2 + 1024;
		g_mix = (int16_t *)realloc(g_mix, g_mix_capacity * sizeof(int16_t));
		if (!g_mix)
		{
			fprintf(stderr, "The sound board ran out of memory for its samples\n");
			exit(3);
		}
	}
	for (size_t index = 0; index < g_fm_samples.taken_count / 2; index++)
	{
		const uint64_t at = (fm_first + index) * FM_RATE.den;    /* the Z80 cycle this sample starts at */
		const uint64_t pcm = sample_at(at, PCM_RATE);
		const float mixed = 0.40f * (g_fm_samples.taken[index * 2] + g_fm_samples.taken[index * 2 + 1])
			+ 0.15f * (value_at(&g_pcm_samples, pcm_first, pcm, 0) + value_at(&g_pcm_samples, pcm_first, pcm, 1))
			+ 0.30f * value_at(&g_speech_samples, speech_first, sample_at(at, SPEECH_RATE), 0)
			+ 0.25f * value_at(&g_title_samples, title_first, sample_at(at, TITLE_RATE), 0);

		g_mix[g_mix_count++] = clamp16((int)(mixed * 32768.0f));
	}
	remember_last(&g_pcm_samples);
	remember_last(&g_speech_samples);
	remember_last(&g_title_samples);
}

uint64_t tmnt_sound_samples_hash(void)
{
	return g_frame_samples_hash;
}

void tmnt_sound_source_hashes(uint64_t hashes[4])
{
	for (int source = 0; source < 4; source++)
		hashes[source] = g_source_hashes[source];
}

uint64_t tmnt_sound_state_hash(void)
{
	const size_t stack = TMNT_SOUND_STACK_START - 0x8000u, above = TMNT_SOUND_STACK_END - 0x8000u;
	uint64_t hash = hash_bytes(tmnt_sound.ram, stack, 0xcbf29ce484222325ull);

	return hash_bytes(tmnt_sound.ram + above, TMNT_SOUND_RAM_SIZE - above, hash);
}

const int16_t *tmnt_sound_mix(size_t *count)
{
	*count = g_mix_count;
	return g_mix;
}

uint32_t tmnt_sound_mix_rate(void)
{
	return (uint32_t)(TMNT_SOUND_CLOCK / FM_RATE.den);
}
