/**
 *    Name:        stage/scroll.c
 *    Description: the areas' scroll segments: the layers' limits and speeds
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint32_t start_scroll_segment(uint32_t d7)
{
	uint32_t negative = 0;
	uint16_t d0 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	d0 = unk_060121;
	a6 = mem_read32(area_scroll_segments[(uint8_t)((uint32_t)d0 << 2) / 4u] + (int16_t)unk_0633C0);
	t1 = mem_read8(a6);
	negative = t1 >> 7;
	unk_0633C9 = t1;
	if (t1 == 0u)
		return func_01A876(d7);
	if (negative == 0u)
	{
		unk_0633C2 = mem_read32(a6 + 6u);
		unk_06335C = mem_read32(a6 + 0xAu);
		unk_063360 = mem_read32(a6 + 0xEu);
		unk_06339C = mem_read32(a6 + 0x12u);
		unk_0633A0 = mem_read32(a6 + 0x16u);
		unk_063364 = mem_read32(a6 + 0x1Au);
		unk_063368 = mem_read32(a6 + 0x1Eu);
		unk_0633A4 = mem_read32(a6 + 0x22u);
		unk_0633A8 = mem_read32(a6 + 0x26u);
		if (indexed_table_of_8_bit_values_01A3C0[unk_060121] != 0u)
		{
			unk_06331C = unk_06339C;
			unk_063320 = unk_0633A0;
			unk_063324 = unk_0633A4;
			unk_063328 = unk_0633A8;
			return d7;
		}
		unk_06331C = unk_06335C;
		unk_063320 = unk_063360;
		unk_063324 = unk_063364;
		unk_063328 = unk_063368;
		return d7;
	}
	unk_06334C = mem_read16(a6 + 6u);
	unk_06334E = mem_read16(a6 + 8u);
	unk_06338C = mem_read16(a6 + 0xAu);
	unk_06338E = mem_read16(a6 + 0xCu);
	unk_06331A = mem_read8(a6 + 0xEu);
	unk_06335A = mem_read8(a6 + 0xEu);
	unk_06339A = mem_read8(a6 + 0xEu);
	unk_06331B = mem_read8(a6 + 0xFu);
	unk_06335B = mem_read8(a6 + 0xFu);
	unk_06339B = mem_read8(a6 + 0xFu);
	if (indexed_table_of_8_bit_values_01A3C0[unk_060121] != 0u)
	{
		unk_06330C = unk_06338C;
		unk_06330E = unk_06338E;
		return d7;
	}
	unk_06330C = unk_06334C;
	unk_06330E = unk_06334E;
	return d7;
}
