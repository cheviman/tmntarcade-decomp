/**
 *    Name:        board_code.c
 *    Description: the code the board puts in place of the game's (tools/game_profile.py's REPLACED_CODE)
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The game's code that measures the board's ROM chips, which the game does not have: what it finds is what
 *    a board with good chips gives, and it leaves the registers as the game's code does.
 */
#include "m68000/ops.h"
#include "m68000/registers.h"

#define ROM_SUMS        0x060018u   /* the work RAM the sums go to, a word each */
#define ROM_AREAS       0x0016CCu   /* the areas summed: a long address, a word count of blocks, a negative end */
#define GOOD_SUMS       0x0016F8u   /* the four the boot compares them with (00151E) */
#define BLOCK_BYTES     0x1000u     /* the bytes summed between two watchdog writes, every other one */
#define WATCHDOG        0x0A0011u

/* The boot's ROM test (001850-00188D): sums every other byte of each area of ROM_AREAS into the work RAM
   from ROM_SUMS, writing the watchdog after each block. A good chip's sum is the one the boot compares it
   with. */
void sum_rom_chips(void)
{
	uint32_t entry = ROM_AREAS, sums = ROM_SUMS, good = GOOD_SUMS;

	for (;;)
	{
		const uint32_t first = mem_read32(entry);
		uint32_t blocks;

		entry += 4u;
		if (first & 0x80000000u)
		{
			/* the end mark is what D6 keeps (the flags it sets, N, are set again before anything reads them) */
			D6 = first;
			break;
		}
		blocks = mem_read16(entry);
		entry += 2u;
		for (uint32_t left = blocks; left-- > 0;)
			mem_write8(WATCHDOG, (uint8_t)left);
		A1 = first + blocks * 2u * BLOCK_BYTES;
		D5 = mem_read8(A1 - 2u);            /* the last byte summed */
		D0 = (D0 & 0xFFFF0000u) | 0xFFFFu;  /* both counts run out */
		D2 = (D2 & 0xFFFF0000u) | 0xFFFFu;
		mem_write16(sums, (uint16_t)mem_read16(good));
		sums += 2u;
		good += 2u;
	}
	A0 = entry;
	A2 = sums;
}
