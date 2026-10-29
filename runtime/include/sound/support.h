/**
 *    Name:        support.h
 *    Description: what the decompiled sound program uses besides its own C: its memory, the board's registers
 *                 on its bus, and the sound board's timing model
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The program's memory is the game's sound board's (tmnt/sound_board.h): SOUND_RAM8/16 is the Z80's RAM
 *    (8000-87FF), and a computed address goes over the Z80's bus (z80_read8 and the rest: the RAM, 9000, the
 *    68000's latch, the K007232, the YM2151, the uPD7759). The program's data is the game's assets': a table
 *    the C reads by name (NAME[i]) is a pointer the board sets from the table registry (src/sound/tables.c),
 *    and an address of the program ROM the program keeps in its variables (a pointer into its data: a track,
 *    a voice) reaches the piece it falls in (sound_rom_at, SOUND_ROM8). No image of the ROM is made.
 *
 *    The timing model (runtime/src/sound_cpu.c): every basic block of the original starts with
 *    z80_block(cycles). There the board runs what is due by the Z80's time (the YM2151's timers) and the Z80
 *    takes the 68000's interrupt if it is pending and the Z80 lets interrupts in; then the block's accesses
 *    happen at that time and its cycles pass. z80_cycles() adds the extra cycles of a condition that takes
 *    the longer way. EI that ends a block lets interrupts in from the block after the next start, as the Z80
 *    waits one instruction.
 */
#ifndef SOUND_SUPPORT_H
#define SOUND_SUPPORT_H

#include "tmnt/sound_board.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define SOUND_RAM8(address)  (tmnt_sound.ram[(address) & (TMNT_SOUND_RAM_SIZE - 1u)])
#define SOUND_RAM16(address) (*(uint16_t *)&tmnt_sound.ram[(address) & (TMNT_SOUND_RAM_SIZE - 1u)])
#define SOUND_RAM8S(address)  (*(int8_t *)&SOUND_RAM8(address))
#define SOUND_RAM16S(address) (*(int16_t *)&SOUND_RAM8(address))

/* A table of the sound program its C reads by name (the decompiler's registry, src/sound/tables.c): its
   name (the asset piece's), its address, and the pointer the board sets to its data */
typedef struct
{
	const char *name;
	uint32_t address;
	const void **data;
} sound_table;

extern const sound_table sound_tables[];
extern const size_t sound_table_count;

/* A table read with another width than its elements': 'offset' bytes into it */
#define TABLE8(table, offset)  (*(const uint8_t *)((const uint8_t *)table##_data + (offset)))
#define TABLE16(table, offset) (*(const uint16_t *)((const uint8_t *)table##_data + (offset)))

/* The program's data where an address the program holds falls (tmnt_sound_data_at: the asset piece's bytes) */
#define SOUND_ROM8(address)  (*tmnt_sound_data_at(address))
#define SOUND_ROM16(address) ((uint16_t)(SOUND_ROM8(address) | SOUND_ROM8((address) + 1u) << 8))

/* Where an address of the RAM or the program's data is: the program's structures (sound.h) are laid over
   these bytes, so the RAM compares byte for byte with the reference */
#define sound_ram_at(address) ((void *)&tmnt_sound.ram[(address) & (TMNT_SOUND_RAM_SIZE - 1u)])
#define sound_rom_at(address) ((const void *)tmnt_sound_data_at(address))

/* A pointer moved to another place of its 256-byte page: the low byte replaced (the random bytes' pointers) */
#define IN_PAGE(pointer, low) ((uint16_t)(((pointer) & 0xFF00u) | (low)))

/* A part of a variable or field read on its own: the variable's first bytes, or bytes further in */
#define AS8(variable)  (*(uint8_t *)&(variable))
#define AS16(variable) (*(uint16_t *)&(variable))
#define AT8(variable, offset)  (*(uint8_t *)((uint8_t *)&(variable) + (offset)))
#define AT16(variable, offset) (*(uint16_t *)((uint8_t *)&(variable) + (offset)))

/* The board puts its own in place of a function of the program (runtime/sound_replaced.txt): the original
   keeps its C under this name */
#define BOARD_ORIGINAL(name) original_##name

uint8_t z80_read8(uint16_t address);
uint16_t z80_read16(uint16_t address);
void z80_write8(uint16_t address, uint8_t value);
void z80_write16(uint16_t address, uint16_t value);

/* A jump through a table or a record's slot to an address none of its handlers has: the original would run
   whatever is there; the game stops */
#if defined(_MSC_VER)
__declspec(noreturn)
#else
_Noreturn
#endif
void sound_invalid_jump(uint32_t address);    /* the default of a switch on a jump's target */

void z80_block(int cycles);
void z80_cycles(int cycles);

void interrupts_on(void);
void interrupts_on_after_block(void);
void interrupts_off(void);

/* 1 when the byte has an even number of bits set: the Z80's P/V after logic */
static inline uint32_t parity8(uint32_t value)
{
	value &= 0xff;
	value ^= value >> 4;
	value ^= value >> 2;
	value ^= value >> 1;
	return (~value) & 1u;
}

/* The flags of a + b + carry and a - b - borrow at 8 and 16 bits, where the program keeps them */
static inline uint32_t z80_carry_add8(uint32_t a, uint32_t b, uint32_t c)
{
	return ((a & 0xff) + (b & 0xff) + c) >> 8 & 1u;
}

static inline uint32_t z80_carry_sub8(uint32_t a, uint32_t b, uint32_t c)
{
	return ((a & 0xff) - (b & 0xff) - c) >> 8 & 1u;
}

static inline uint32_t z80_carry_add16(uint32_t a, uint32_t b, uint32_t c)
{
	return ((a & 0xffff) + (b & 0xffff) + c) >> 16 & 1u;
}

static inline uint32_t z80_carry_sub16(uint32_t a, uint32_t b, uint32_t c)
{
	return ((a & 0xffff) - (b & 0xffff) - c) >> 16 & 1u;
}

static inline uint32_t z80_overflow_add8(uint32_t a, uint32_t b, uint32_t c)
{
	const uint32_t result = a + b + c;

	return ((a ^ result) & (b ^ result)) >> 7 & 1u;
}

static inline uint32_t z80_overflow_sub8(uint32_t a, uint32_t b, uint32_t c)
{
	const uint32_t result = a - b - c;

	return ((a ^ b) & (a ^ result)) >> 7 & 1u;
}

static inline uint32_t z80_overflow_add16(uint32_t a, uint32_t b, uint32_t c)
{
	const uint32_t result = a + b + c;

	return ((a ^ result) & (b ^ result)) >> 15 & 1u;
}

static inline uint32_t z80_overflow_sub16(uint32_t a, uint32_t b, uint32_t c)
{
	const uint32_t result = a - b - c;

	return ((a ^ b) & (a ^ result)) >> 15 & 1u;
}

#endif
