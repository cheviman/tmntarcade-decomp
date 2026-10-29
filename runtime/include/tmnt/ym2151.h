/**
 *    Name:        ym2151.h
 *    Description: Yamaha YM2151 (OPM) FM sound chip: eight four-operator channels, the LFO and the noise, two
 *                 timers
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The game's own YM2151 (no MAME or ymfm code): every sample is the one ymfm's ym2151 makes from the same
 *    writes (kref --sound-check compares them). A sample is made every 64 clocks of the chip (32 operators,
 *    prescale 2); the timers and the busy flag are counted in the chip's clocks, which the host keeps: it
 *    gets the timers through set_timer (clocks to wait, -1 to stop) and says when one runs out.
 */
#ifndef TMNT_YM2151_H
#define TMNT_YM2151_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define YM2151_CHANNELS  8
#define YM2151_OPERATORS 32

typedef struct
{
	uint32_t phase;
	uint16_t attenuation;           /* 10 bits, 0 the loudest */
	uint8_t stage;                  /* attack, decay, sustain, release */
	uint8_t key;                    /* the key it last took */
	uint8_t keys;                   /* the key from the register (bit 0) and from CSM (bit 2) */
	/* from the registers, at the last refresh */
	uint32_t block_frequency;
	int32_t detune;
	uint32_t multiple;              /* x.1 */
	uint32_t step;                  /* the phase step, or STEP_FOLLOWS_LFO */
	uint32_t total_level;
	uint32_t sustain_level;
	uint8_t rates[4];
} ym2151_operator;

typedef struct
{
	int16_t feedback[2];
	int16_t feedback_next;
	ym2151_operator *operators[4];  /* M1, C1, M2, C2 (ymfm's operators 1-4) */
} ym2151_channel;

typedef struct ym2151
{
	uint8_t registers[256];
	uint8_t address;
	uint8_t status;
	uint8_t irq_state;
	uint8_t timer_running[2];
	uint32_t total_clocks;
	uint32_t envelope_counter;
	uint32_t refresh_count;
	uint32_t modified_channels;
	uint32_t active_channels;
	/* the LFO and the noise */
	uint32_t lfo_counter;
	uint32_t noise_lfsr;
	uint8_t noise_counter;
	uint8_t noise_state;
	uint8_t lfo_am;
	int16_t lfo_waveforms[4][256];  /* AM in the low byte, PM (signed) in the high one */
	ym2151_operator operators[YM2151_OPERATORS];
	ym2151_channel channels[YM2151_CHANNELS];
	/* the host */
	void *host;
	void (*set_timer)(void *host, int timer, int32_t clocks);
	void (*set_busy_end)(void *host, uint32_t clocks);
	bool (*is_busy)(void *host);
	void (*update_irq)(void *host, bool asserted);
} ym2151;

/* Sets the chip up (the host's callbacks already in it) and resets it */
void ym2151_init(ym2151 *chip);
void ym2151_reset(ym2151 *chip);

/* The ports: 0 the address, 1 the data (reads: 1 the status, 0 nothing) */
uint8_t ym2151_read(ym2151 *chip, int offset);
void ym2151_write(ym2151 *chip, int offset, uint8_t data);

/* A timer the host was given ran out */
void ym2151_timer_expired(ym2151 *chip, int timer);

/* The next sample: left and right, 16 bits each, as the chip's DAC gives them */
void ym2151_generate(ym2151 *chip, int32_t out[2]);

#ifdef __cplusplus
}
#endif

#endif
