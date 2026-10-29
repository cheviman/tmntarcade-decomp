/**
 *    Name:        stage/fire.c
 *    Description: the fire's tiles redrawn in the first two areas
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void animate_fire_tiles(uint32_t *p_d5, uint32_t *p_d6)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint8_t d0 = 0, d1 = 0;
	uint16_t d0_2 = 0, d7 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, d5_2 = 0, d6_2 = 0;
	uint16_t t1 = 0;

	if (unk_060001 != 2u)
		return;
	if (unk_060005 != 5u)
	{
		if (unk_060005 != 4u)
			return;
		if (unk_060007 != 0u)
		{
			if (unk_060007 != 1u || unk_060009 != 0u)
				return;
		}
		else if (unk_060009 != 4u)
			return;
		if (unk_060121 != 0u && unk_060121 != 1u)
			return;
	}
	else if (unk_060121 != 0u && (unk_060121 != 1u || unk_0633EA >= 4u))
		return;
	unk_063340 = unk_063380;
	unk_063344 = unk_063384;
	d0 = (uint8_t)unk_0600A4;
	if (d0 == unk_0633F1)
		return;
	unk_0633F1 = d0;
	unk_0633F2++;
	if (unk_0633F2 >= 4u)
	{
		unk_0633F2 = 0u;
		unk_0633F3++;
		if (unk_0633F3 >= 8u)
			unk_0633F3 = 0u;
	}
	if (unk_060121 != 0u)
	{
		unk_0633C6++;
		if (unk_0633C6 >= 4u)
		{
			unk_0633C6 = 0u;
			unk_0633C7++;
			if (unk_0633C7 >= 8u)
				unk_0633C7 = 0u;
		}
		d0_2 = (uint16_t)((uint32_t)unk_0633C6 << 2);
		a0 = fire_tiles[d0_2 / 4u];
		a2 = mem_read32(a0);
		a0 = mem_read32(a0 + 4u + (uint16_t)(IN_PAGE(d0_2, unk_0633C7) << 2));
		a1 = fire_blocks_ADDRESS;
		d7 = 7u;
		d6_2 = 0x10u;
		d5_2 = 0x20u;
	}
	else
	{
		d0_2 = (uint16_t)((uint32_t)unk_0633F2 << 2);
		a0 = fire_tiles_area_0[d0_2 / 4u];
		a2 = mem_read32(a0);
		a0 = mem_read32(a0 + 4u + (uint16_t)(IN_PAGE(d0_2, unk_0633F3) << 2));
		a1 = fire_blocks_ADDRESS;
		d7 = 3u;
		d6_2 = 8u;
		d5_2 = 0x10u;
	}
	do
	{
		d0_2 = mem_read16(a0);
		d1 = mem_read8(a1 + (int16_t)d0_2);
		mem_write8(a2, d1);
		mem_write8(a2 + 2u, d1);
		mem_write8(a2 + 4u, d1);
		mem_write8(a2 + 6u, d1);
		mem_write8(a2 + 0x80u, d1);
		mem_write8(a2 + 0x82u, d1);
		mem_write8(a2 + 0x84u, d1);
		mem_write8(a2 + 0x86u, d1);
		mem_write8(a2 + 0x100u, d1);
		mem_write8(a2 + 0x102u, d1);
		mem_write8(a2 + 0x104u, d1);
		mem_write8(a2 + 0x106u, d1);
		mem_write8(a2 + 0x180u, d1);
		mem_write8(a2 + 0x182u, d1);
		mem_write8(a2 + 0x184u, d1);
		mem_write8(a2 + 0x186u, d1);
		mem_write8(a2 + 1u, mem_read8(a1 + 1u + (int16_t)d0_2));
		mem_write8(a2 + 3u, mem_read8(a1 + 2u + (int16_t)d0_2));
		mem_write8(a2 + 5u, mem_read8(a1 + 3u + (int16_t)d0_2));
		mem_write8(a2 + 7u, mem_read8(a1 + 4u + (int16_t)d0_2));
		mem_write8(a2 + 0x81u, mem_read8(a1 + 5u + (int16_t)d0_2));
		mem_write8(a2 + 0x83u, mem_read8(a1 + 6u + (int16_t)d0_2));
		mem_write8(a2 + 0x85u, mem_read8(a1 + 7u + (int16_t)d0_2));
		mem_write8(a2 + 0x87u, mem_read8(a1 + 8u + (int16_t)d0_2));
		mem_write8(a2 + 0x101u, mem_read8(a1 + 9u + (int16_t)d0_2));
		mem_write8(a2 + 0x103u, mem_read8(a1 + 0xAu + (int16_t)d0_2));
		mem_write8(a2 + 0x105u, mem_read8(a1 + 0xBu + (int16_t)d0_2));
		mem_write8(a2 + 0x107u, mem_read8(a1 + 0xCu + (int16_t)d0_2));
		mem_write8(a2 + 0x181u, mem_read8(a1 + 0xDu + (int16_t)d0_2));
		mem_write8(a2 + 0x183u, mem_read8(a1 + 0xEu + (int16_t)d0_2));
		mem_write8(a2 + 0x185u, mem_read8(a1 + 0xFu + (int16_t)d0_2));
		mem_write8(a2 + 0x187u, mem_read8(a1 + 0x10u + (int16_t)d0_2));
		d0_2 = mem_read16(a0 + d6_2);
		d1 = mem_read8(a1 + (int16_t)d0_2);
		mem_write8(a2 + 0x200u, d1);
		mem_write8(a2 + 0x202u, d1);
		mem_write8(a2 + 0x204u, d1);
		mem_write8(a2 + 0x206u, d1);
		mem_write8(a2 + 0x280u, d1);
		mem_write8(a2 + 0x282u, d1);
		mem_write8(a2 + 0x284u, d1);
		mem_write8(a2 + 0x286u, d1);
		mem_write8(a2 + 0x300u, d1);
		mem_write8(a2 + 0x302u, d1);
		mem_write8(a2 + 0x304u, d1);
		mem_write8(a2 + 0x306u, d1);
		mem_write8(a2 + 0x380u, d1);
		mem_write8(a2 + 0x382u, d1);
		mem_write8(a2 + 0x384u, d1);
		mem_write8(a2 + 0x386u, d1);
		mem_write8(a2 + 0x201u, mem_read8(a1 + 1u + (int16_t)d0_2));
		mem_write8(a2 + 0x203u, mem_read8(a1 + 2u + (int16_t)d0_2));
		mem_write8(a2 + 0x205u, mem_read8(a1 + 3u + (int16_t)d0_2));
		mem_write8(a2 + 0x207u, mem_read8(a1 + 4u + (int16_t)d0_2));
		mem_write8(a2 + 0x281u, mem_read8(a1 + 5u + (int16_t)d0_2));
		mem_write8(a2 + 0x283u, mem_read8(a1 + 6u + (int16_t)d0_2));
		mem_write8(a2 + 0x285u, mem_read8(a1 + 7u + (int16_t)d0_2));
		mem_write8(a2 + 0x287u, mem_read8(a1 + 8u + (int16_t)d0_2));
		mem_write8(a2 + 0x301u, mem_read8(a1 + 9u + (int16_t)d0_2));
		mem_write8(a2 + 0x303u, mem_read8(a1 + 0xAu + (int16_t)d0_2));
		mem_write8(a2 + 0x305u, mem_read8(a1 + 0xBu + (int16_t)d0_2));
		mem_write8(a2 + 0x307u, mem_read8(a1 + 0xCu + (int16_t)d0_2));
		mem_write8(a2 + 0x381u, mem_read8(a1 + 0xDu + (int16_t)d0_2));
		mem_write8(a2 + 0x383u, mem_read8(a1 + 0xEu + (int16_t)d0_2));
		mem_write8(a2 + 0x385u, mem_read8(a1 + 0xFu + (int16_t)d0_2));
		mem_write8(a2 + 0x387u, mem_read8(a1 + 0x10u + (int16_t)d0_2));
		d0_2 = mem_read16(a0 + d5_2);
		d1 = mem_read8(a1 + (int16_t)d0_2);
		mem_write8(a2 + 0x400u, d1);
		mem_write8(a2 + 0x402u, d1);
		mem_write8(a2 + 0x404u, d1);
		mem_write8(a2 + 0x406u, d1);
		mem_write8(a2 + 0x480u, d1);
		mem_write8(a2 + 0x482u, d1);
		mem_write8(a2 + 0x484u, d1);
		mem_write8(a2 + 0x486u, d1);
		mem_write8(a2 + 0x401u, mem_read8(a1 + 1u + (int16_t)d0_2));
		mem_write8(a2 + 0x403u, mem_read8(a1 + 2u + (int16_t)d0_2));
		mem_write8(a2 + 0x405u, mem_read8(a1 + 3u + (int16_t)d0_2));
		mem_write8(a2 + 0x407u, mem_read8(a1 + 4u + (int16_t)d0_2));
		mem_write8(a2 + 0x481u, mem_read8(a1 + 5u + (int16_t)d0_2));
		mem_write8(a2 + 0x483u, mem_read8(a1 + 6u + (int16_t)d0_2));
		mem_write8(a2 + 0x485u, mem_read8(a1 + 7u + (int16_t)d0_2));
		mem_write8(a2 + 0x487u, mem_read8(a1 + 8u + (int16_t)d0_2));
		t1 = d7 - 1u;
		d7 = t1;
		a2 += 8u;
		a0 += 2u;
	} while (t1 != 0xFFFFu);
	*p_d5 = d5_2;
	*p_d6 = d6_2;
}
