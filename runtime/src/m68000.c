/**
 *    Name:        m68000.c
 *    Description: the 68000 runtime of the translated program: the status register, exceptions and
 *                 interrupts, calls and jumps through computed addresses, the frame, and the program's run on a
 *                 stack of its own
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME's 68000 core (src/devices/cpu/m68000, Olivier Galibert): an exception or an
 *    interrupt enters supervisor mode, pushes the PC's low word, the old status register and the PC's high
 *    word, in that order, and reads its vector; an interrupt sets the mask to its level, and takes the
 *    autovector of its level (the Konami boards answer every acknowledge with one). The frame timing is
 *    tools/core/konami/reference/kref's --timing frames (tmnt/frame.h).
 */
#include "m68000/code.h"
#include "m68000/cpu.h"
#include "m68000/ops.h"
#include "host/tasks.h"
#include "tmnt/frame.h"
#include "tmnt/machine.h"
#include "tmnt/program.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SP_INDEX 15
#define MAX_CALLS 4096

m68k_cpu cpu;
void (*program_vblank_end)(void);
void (*program_vblank_start)(void);
void (*program_frame_done)(void);

static uint32_t calls[MAX_CALLS];     /* the return addresses the calls wait for, the last one on top */
static size_t call_depth;
static host_task *port_task;

/* the last call that came back somewhere else (m68k_returned_to), for the messages */
static uint32_t past_from;
static uint32_t past_expected;
static uint32_t past_to;

/* ---- the status register ---- */

uint32_t m68k_read_sr(void)
{
	return (cpu.r[M68K_SR_SYSTEM] & M68K_SR_MASK) | (uint32_t)cpu.x << 4 | (uint32_t)cpu.s << 3
		| (uint32_t)cpu.z << 2 | (uint32_t)cpu.ov << 1 | cpu.cy;
}

void m68k_write_sr(uint32_t value)
{
	const uint32_t system = value & M68K_SR_MASK;

	/* a change of mode swaps A7 and the other mode's stack pointer */
	if ((system ^ cpu.r[M68K_SR_SYSTEM]) & M68K_SR_S)
	{
		const uint32_t sp = cpu.r[SP_INDEX];

		cpu.r[SP_INDEX] = cpu.r[M68K_OTHER_SP];
		cpu.r[M68K_OTHER_SP] = sp;
	}
	cpu.r[M68K_SR_SYSTEM] = system;
	cpu.x = (uint8_t)(value >> 4 & 1u);
	cpu.s = (uint8_t)(value >> 3 & 1u);
	cpu.z = (uint8_t)(value >> 2 & 1u);
	cpu.ov = (uint8_t)(value >> 1 & 1u);
	cpu.cy = (uint8_t)(value & 1u);
}

/* ---- calls and jumps through computed addresses ---- */

static const m68k_code_entry *find_code(uint32_t address)
{
	const uint32_t key = address & 0xFFFFFFu;
	size_t low = 0;
	size_t high = m68k_code_entry_count;

	while (low < high)
	{
		const size_t middle = (low + high) / 2;
		if (m68k_code_entries[middle].address < key)
			low = middle + 1;
		else
			high = middle;
	}
	return low < m68k_code_entry_count && m68k_code_entries[low].address == key ? &m68k_code_entries[low] : NULL;
}

static void run_code(uint32_t address, uint32_t from)
{
	const m68k_code_entry *code = find_code(address);

	if (!code)
	{
		fprintf(stderr, "No translated code starts at %06X, reached from %06X (frame %llu)\n", address & 0xFFFFFFu,
			from & 0xFFFFFFu, (unsigned long long)tmnt_board.frame);
		exit(3);
	}
	code->function();
}

void m68k_calls_push(uint32_t address)
{
	if (call_depth == MAX_CALLS)
	{
		fprintf(stderr, "More than %d calls nest (frame %llu)\n", MAX_CALLS, (unsigned long long)tmnt_board.frame);
		exit(3);
	}
	calls[call_depth++] = address & 0xFFFFFFu;
}

bool m68k_returned_to(uint32_t expected, uint32_t from)
{
	if (call_depth)
		call_depth--;
	if ((cpu.pc & 0xFFFFFFu) == (expected & 0xFFFFFFu))
		return true;
	past_from = from;
	past_expected = expected;
	past_to = cpu.pc;
	return false;
}

void m68k_call(uint32_t address, uint32_t from)
{
	run_code(address, from);
}

void m68k_jump(uint32_t address, uint32_t from)
{
	size_t depth;

	/* to a return address a call waits for: a return, to that call */
	for (depth = call_depth; depth > 0; depth--)
		if (calls[depth - 1] == (address & 0xFFFFFFu))
		{
			cpu.pc = address;
			return;
		}
	run_code(address, from);
}

/* ---- exceptions and interrupts ---- */

/* The frame of the exception 'vector' (with 'level', an interrupt's: its mask) pushed with 'pc' to come back
   to, in supervisor mode; the handler's address */
static uint32_t enter_exception(uint32_t vector, uint32_t pc, int level)
{
	const uint32_t old = m68k_read_sr();
	uint32_t sr = (old & ~0x8000u) | M68K_SR_S;
	uint32_t sp;

	if (level > 0)
		sr = (sr & ~0x0700u) | (uint32_t)level << 8;
	m68k_write_sr(sr);
	sp = cpu.r[SP_INDEX];
	mem_write16(sp - 2u, (uint16_t)pc);
	mem_write16(sp - 6u, (uint16_t)old);
	mem_write16(sp - 4u, (uint16_t)(pc >> 16));
	cpu.r[SP_INDEX] = sp - 6u;
	return mem_read32(vector * 4u);
}

bool m68k_exception(uint32_t vector, uint32_t pc, uint32_t from)
{
	const uint32_t handler = enter_exception(vector, pc, 0);

	m68k_calls_push(pc);
	run_code(handler, from);
	return m68k_returned_to(pc, from);
}

void m68k_take_interrupts(uint32_t resume)
{
	for (;;)
	{
		const int level = tmnt_irq_level();
		const uint32_t sp = cpu.r[SP_INDEX];
		const uint32_t mode = cpu.r[M68K_SR_SYSTEM] & M68K_SR_S;
		uint32_t handler;

		if (level == 0 || (uint32_t)level <= (cpu.r[M68K_SR_SYSTEM] >> 8 & 7u))
			return;
		handler = enter_exception(24u + (uint32_t)level, resume, level);
		cpu.interrupts++;
		m68k_calls_push(resume);
		run_code(handler, resume);
		/* the handler comes back into the code it interrupted, on its stack: one task */
		if (!m68k_returned_to(resume, handler) || cpu.r[SP_INDEX] != sp
			|| (cpu.r[M68K_SR_SYSTEM] & M68K_SR_S) != mode)
		{
			fprintf(stderr, "The interrupt of level %d taken at %06X came back to %06X with A7 %08X (it was %08X) "
				"(frame %llu)\n", level, resume & 0xFFFFFFu, cpu.pc & 0xFFFFFFu, cpu.r[SP_INDEX], sp,
				(unsigned long long)tmnt_board.frame);
			exit(3);
		}
	}
}

/* ---- the frame ---- */

/* The board moves on to the start of its next VBLANK, line 240, past the end of the last one, line 16 (where
   the video takes the scroll); the frame is drawn when VBLANK starts, before the board's events */
static void next_frame(void)
{
	const uint64_t start = tmnt_board.frame * TMNT_FRAME_CYCLES;

	tmnt_board.cycles = start + (uint64_t)TMNT_VBLANK_END * TMNT_LINE_CYCLES;
	if (program_vblank_end)
		program_vblank_end();
	tmnt_board.cycles = start + (uint64_t)TMNT_VBLANK_START * TMNT_LINE_CYCLES;
	if (program_vblank_start)
		program_vblank_start();
	tmnt_vblank_start();
	if (program_frame_done)
		program_frame_done();
}

void program_frame_wait(void)
{
	if (tmnt_frame_idle())
		next_frame();
}

void m68k_stop(uint32_t value)
{
	m68k_write_sr(value);
	while (tmnt_irq_level() == 0 || (uint32_t)tmnt_irq_level() <= (cpu.r[M68K_SR_SYSTEM] >> 8 & 7u))
		next_frame();
}

void m68k_reset_devices(void)
{
	/* (the board connects nothing to the 68000's RESET line) */
}

/* ---- the program as a port runs it (tmnt/program.h) ---- */

void program_reset(void)
{
	memset(&cpu, 0, sizeof(cpu));
	call_depth = 0;
	cpu.r[M68K_SR_SYSTEM] = 0x2700u;
	cpu.r[SP_INDEX] = mem_read32(0);
	cpu.pc = mem_read32(4);
}

static void run_program(void)
{
	const uint32_t start = cpu.pc;

	run_code(start, start);
	fprintf(stderr, "The program came to its end at %06X (frame %llu)\n", cpu.pc & 0xFFFFFFu,
		(unsigned long long)tmnt_board.frame);
	if (past_to)
		fprintf(stderr, "The last call that came back somewhere else: from %06X, to %06X instead of %06X\n",
			past_from & 0xFFFFFFu, past_to & 0xFFFFFFu, past_expected & 0xFFFFFFu);
	exit(3);
}

void program_run(void)
{
	port_task = host_task_main();
	host_task_switch(host_task_create(run_program));
}

void program_stop(void)
{
	host_task_switch(port_task);
}

uint64_t program_frames(void)
{
	return tmnt_board.frame;
}

uint32_t program_interrupts(void)
{
	return cpu.interrupts;
}
