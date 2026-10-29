/**
 *    Name:        sound_cpu.c
 *    Description: runs the decompiled sound program on the sound board's time: the Z80's timing model
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The sound program is C (src/sound/, tools/decompile_sound.py) and keeps the Z80's time itself: every
 *    basic block of the original starts with z80_block(cycles). The rules, the same that
 *    tools/core/konami/reference/sound/ksound.cpp keeps around MAME's Z80 with kref --sound-timing (the table
 *    tools/decompile_sound.py writes, build/sound/timing.txt), so that the two compare sample for sample:
 *      - the Z80's time counts in its own cycles and moves on by each block's cycles (tools/core/z80/timing.py)
 *        and the extra cycles of a condition's longer way; the board's time is TMNT_CPU_CLOCK /
 *        TMNT_SOUND_CLOCK board cycles a Z80 cycle, rounded down;
 *      - when a block starts, the YM2151's timers due by then run out, and the Z80 takes the 68000's
 *        interrupt if the line is up and it lets interrupts in (not right after an EI that ended the block
 *        before): 13 cycles, the line goes down (MAME's HOLD_LINE), then the handler (sound_command, 0038);
 *        after it returns the same is looked at again. The main loop lets interrupts in for four NOPs (EI ...
 *        DI): a block starts after the first of them (game_profile's SOUND_INTERRUPT_WINDOWS), where the
 *        interrupt comes in;
 *      - everything a block reads and writes happens at the time it starts;
 *      - the board runs the program whenever its time moves on (tmnt_sound_run): from its reset, then the
 *        main loop again and again until the Z80's time is past the board's (the loop's top, 04C9, is where
 *        the program waits: sound_symbols.txt's "loop" line). A pass waits there for the YM2151's timer B
 *        (some 4 ms), so the Z80 may be a pass ahead of the board; the 68000 only reaches it through the latch
 *        and the interrupt, which the Z80 takes at the next pass's EI.
 *    The reset's ROM test is the board's (runtime/sound_replaced.txt): the game has no program ROM to add up.
 */
#include "sound_internal.h"

#include "sound/support.h"

#include <stdio.h>
#include <stdlib.h>

#define INTERRUPT_CYCLES 13

/* the sound program's ways in (sound_symbols.txt) */
void sound_reset(void);
void sound_command(void);
void sound_main_loop(void);
void sound_main(void);

static struct
{
	uint64_t clock;         /* where the next block starts, Z80 cycles */
	uint64_t access;        /* where the running block's reads and writes happen */
	bool interrupts;        /* IFF1 */
	bool after_ei;          /* EI ended the block before */
	bool line;              /* the 68000's IRQ, up until the Z80 takes it */
	bool running;           /* past the reset code: the main loop runs */
} z80;

void sound_cpu_reset(uint64_t cycle)
{
	z80.clock = z80.access = cycle;
	z80.interrupts = z80.after_ei = z80.line = z80.running = false;
}

uint64_t sound_cpu_access(void)
{
	return z80.access;
}

uint64_t sound_cpu_clock(void)
{
	return z80.clock;
}

void sound_cpu_irq(void)
{
	z80.line = true;
}

void sound_cpu_run(uint64_t until)
{
	if (!z80.running)
	{
		z80.running = true;
		sound_reset();
	}
	while (sound_board_time(z80.clock) < until)
		sound_main_loop();
}

/* ---- what the program calls ---- */

void z80_block(int cycles)
{
	for (;;)
	{
		sound_timers_due(z80.clock);
		if (!z80.interrupts || z80.after_ei || !z80.line)
			break;
		z80.interrupts = false;
		z80.line = false;
		z80.clock += INTERRUPT_CYCLES;
		sound_command();
	}
	z80.after_ei = false;
	z80.access = z80.clock;
	z80.clock += (uint64_t)cycles;
}

void z80_cycles(int cycles)
{
	z80.clock += (uint64_t)cycles;
}

void interrupts_on(void)
{
	z80.interrupts = true;
}

void interrupts_on_after_block(void)
{
	z80.interrupts = true;
	z80.after_ei = true;
}

void interrupts_off(void)
{
	z80.interrupts = false;
}

uint8_t z80_read8(uint16_t address)
{
	return sound_bus_read(address);
}

uint16_t z80_read16(uint16_t address)
{
	const uint8_t low = sound_bus_read(address);

	return (uint16_t)(low | sound_bus_read((uint16_t)(address + 1u)) << 8);
}

void z80_write8(uint16_t address, uint8_t value)
{
	sound_bus_write(address, value);
}

void z80_write16(uint16_t address, uint16_t value)
{
	sound_bus_write(address, (uint8_t)value);
	sound_bus_write((uint16_t)(address + 1u), (uint8_t)(value >> 8));
}

void sound_invalid_jump(uint32_t address)
{
	fprintf(stderr, "Sound program: a jump to %04X, which no handler has\n", (unsigned)address);
	exit(3);
}

/* The reset's ROM test (runtime/sound_replaced.txt). The original, BOARD_ORIGINAL(check_rom), adds up the
   program's 32 KB (0000-7FFF) a byte at a time and compares the sum with 783C before it goes on to
   sound_main. The game has no program ROM to add up: the board answers as good chips do, and the test takes
   the time it takes on them, its blocks as the original's C counts them (27 cycles, then 46 a byte and 5
   more for each turn back, then 21, 18 and 10) */
void check_rom(void)
{
	uint32_t address;

	z80_block(27);
	for (address = 0; address < 0x8000u; address++)
	{
		z80_block(46);
		if (address != 0x7FFFu)
			z80_cycles(5);
	}
	z80_block(21);
	z80_block(18);
	z80_block(10);
	sound_main();
}
