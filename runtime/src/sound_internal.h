/**
 *    Name:        sound_internal.h
 *    Description: between the game's sound board (sound_board.c) and its Z80's timing model (sound_cpu.c)
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 */
#ifndef TMNT_SOUND_INTERNAL_H
#define TMNT_SOUND_INTERNAL_H

#include "tmnt/sound_board.h"

#include <stdbool.h>
#include <stdint.h>

/* The board's time when the Z80 has run 'cycles', and the first Z80 cycle at or after board time 'time' */
static inline uint64_t sound_board_time(uint64_t cycles)
{
	return cycles * TMNT_CPU_CLOCK / TMNT_SOUND_CLOCK;
}

static inline uint64_t sound_z80_time(uint64_t time)
{
	return (time * TMNT_SOUND_CLOCK + TMNT_CPU_CLOCK - 1) / TMNT_CPU_CLOCK;
}

/* ---- the Z80 (sound_cpu.c) ---- */

/* At power on, at Z80 cycle 'cycle' */
void sound_cpu_reset(uint64_t cycle);
/* The program up to its main loop's top past board time 'until' */
void sound_cpu_run(uint64_t until);
/* The 68000's IRQ goes up */
void sound_cpu_irq(void);
/* The Z80's time: where the running block's accesses happen, and where the next block starts */
uint64_t sound_cpu_access(void);
uint64_t sound_cpu_clock(void);

/* ---- the board (sound_board.c) ---- */

/* The Z80's bus: memory map and chips (MAME's tmnt_audio_map) */
uint8_t sound_bus_read(uint16_t address);
void sound_bus_write(uint16_t address, uint8_t data);
/* The YM2151's timers due by Z80 cycle 'cycle', in the order they run out */
void sound_timers_due(uint64_t cycle);

#endif
