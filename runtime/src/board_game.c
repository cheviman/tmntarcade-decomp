/**
 *    Name:        board_game.c
 *    Description: the code the board puts in place of the decompiled game's (runtime/replaced.txt)
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The boot's ROM test sums the program's chips, which the game does not have (its data is the assets', its
 *    code is C): the board gives what good chips sum to. The decompiled original stays in the game's C as
 *    original_sum_program_chips (BOARD_ORIGINAL), which nothing calls. The translation scaffold has its own
 *    (runtime/src/board_code.c), which leaves the 68000's registers as the original does.
 */
#include "game.h"

#define ROM_AREAS       0x0016CCu   /* the areas summed: a long address, a word count of blocks, a negative end */
#define GOOD_SUMS       0x0016F8u   /* the four the boot compares them with (00151E) */
#define ROM_SUMS        0x060018u   /* the work RAM the sums go to, a word each */
#define WATCHDOG        0x0A0011u

/* The boot's ROM test (001850-00188D): for each area of ROM_AREAS, the watchdog written after each block of it
   and the area's sum into the work RAM from ROM_SUMS; a good chip's sum is the one the boot compares it with */
void sum_program_chips(void)
{
	uint32_t entry = ROM_AREAS, sums = ROM_SUMS, good = GOOD_SUMS;

	while (!(DATA32(entry) & 0x80000000u))
	{
		const uint32_t blocks = DATA16(entry + 4u);

		for (uint32_t left = blocks; left-- > 0;)
			mem_write8(WATCHDOG, (uint8_t)left);
		RAM16(sums) = (uint16_t)DATA16(good);
		entry += 6u;
		sums += 2u;
		good += 2u;
	}
}
