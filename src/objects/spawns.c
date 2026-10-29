/**
 *    Name:        objects/spawns.c
 *    Description: the enemies' spawn lists, by the scroll
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void start_area_spawns(void)
{
	uint16_t d0 = 0;
	uint32_t a5 = 0;

	d0 = (uint16_t)((uint32_t)(int8_t)unk_060120 << 2);
	unk_061200 = TABLE32(area_spawn_lists, (uint32_t)(int16_t)d0);
	d0 = (uint16_t)((uint32_t)d0 << 1);
	a5 = TABLE32(area_spawn_scrolls, (uint32_t)(int16_t)d0);
	mem_write16(a5 + 2u, 0u);
	mem_write16(a5, 0u);
	unk_061210 = a5;
	unk_061214 = mem_read32(0x47996u + (int16_t)d0);
	unk_061218 = TABLE32(area_spawn_starts, (uint32_t)(int16_t)d0);
	unk_06121C = mem_read32(0x479E6u + (int16_t)d0);
}

uint32_t spawn_enemies(uint32_t a1)
{
	uint32_t zero = 0, carry = 0;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a0 = 0, a2 = 0, a5 = 0, a6 = 0, d3 = 0, ignored = 0;
	uint32_t t1 = 0, t2 = 0;

	a5 = unk_061210;
	a6 = unk_061214;
	d0 = mem_read16(a5);
	if ((int8_t)mem_read8(a6 + 1u) >= 0)
		d0 = (uint16_t)(0u - d0);
	t1 = unk_061218 + (int16_t)d0;
	unk_061218 = (unk_061218 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_061218 = (unk_061218 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
	d1 = mem_read16(a5 + 2u);
	if ((int8_t)mem_read8(a6) < 0)
		d1 = (uint16_t)(0u - d1);
	t2 = unk_06121C + (int16_t)d1;
	unk_06121C = (unk_06121C & 0xFFFF0000u) | (t2 & 0xFFFFu);
	unk_06121C = (unk_06121C & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
	a0 = unk_061200;
	if (mem_read16(a0) == 0xFFFFu || (int16_t)(unk_061218 >> 8) < (int16_t)mem_read16(a0))
		return a1;
	if (unk_060120 == 6u)
	{
		func_02F61E(&ignored, &carry);
		if (carry)
		{
			unk_061200 = a0 + 8u;
			return a1;
		}
		if (unk_060130 < (mem_read8(a0 + 5u) & 0xFu))
			unk_061200 = a0 + 8u;
		else
		{
			a1 = spawn_offset(a0);
			func_047BAC(a0, &a2, &zero);
			if (zero)
			{
				mem_write16(a2, 0x100u);
				mem_write16(a2 + 2u, mem_read16(a0 + 6u));
				mem_write16(a2 + 4u, 0u);
				mem_write16(a2 + 0x40u, 0u);
				mem_write16(a2 + 0x42u, 0xFF00u);
				mem_write8(a2 + 0x4Bu, 0u);
				mem_write8(a2 + 0x10u, mem_read8(a0 + 4u));
				mem_write8(a2 + 0x11u, 0u);
				d3 = mem_read16(a0);
				if ((mem_read8(a0 + 5u) & 0x40u) != 0u)
				{
					d3 = (uint16_t)(d3 - 0x140u);
					d3 = (uint16_t)(d3 - mem_read16(a1));
				}
				else
					d3 = (uint16_t)(d3 + mem_read16(a1));
				mem_write32(a2 + 0x12u, d3 << 8);
				mem_write32(a2 + 0x16u, (uint32_t)mem_read16(a0 + 2u) << 8);
				unk_061200 = a0 + 8u;
				return a1;
			}
		}
		return a1;
	}
	if (unk_060130 < (mem_read8(a0 + 5u) & 0xFu))
		unk_061200 = a0 + 8u;
	else
	{
		a1 = spawn_offset(a0);
		func_047BAC(a0, &a2, &zero);
		if (zero)
		{
			mem_write16(a2, 0x100u);
			mem_write16(a2 + 2u, mem_read16(a0 + 6u));
			mem_write16(a2 + 4u, 0u);
			mem_write16(a2 + 0x40u, 0u);
			mem_write16(a2 + 0x42u, 0xFF00u);
			mem_write8(a2 + 0x4Bu, 0u);
			mem_write8(a2 + 0x10u, mem_read8(a0 + 4u));
			mem_write8(a2 + 0x11u, 0u);
			d3 = mem_read16(a0);
			if ((mem_read8(a0 + 5u) & 0x40u) != 0u)
			{
				d3 = (uint16_t)(d3 - 0x140u);
				d3 = (uint16_t)(d3 - mem_read16(a1));
			}
			else
				d3 = (uint16_t)(d3 + mem_read16(a1));
			mem_write32(a2 + 0x12u, d3 << 8);
			mem_write32(a2 + 0x16u, (uint32_t)mem_read16(a0 + 2u) << 8);
			unk_061200 = a0 + 8u;
			return a1;
		}
	}
	return a1;
}

void unreached_047B1C(uint32_t a0)
{
	uint32_t zero = 0;
	uint16_t d1 = 0;
	uint32_t a1 = 0, a2 = 0, d3 = 0;

	d1 = (uint16_t)((unk_06121C >> 8) + 8u);
	if ((int16_t)mem_read16(a0 + 2u) <= (int16_t)d1 && (int16_t)(d1 - 0x10u) <= (int16_t)mem_read16(a0 + 2u))
	{
		a1 = spawn_offset(a0);
		func_047BAC(a0, &a2, &zero);
		if (zero == 0u)
			return;
		mem_write16(a2, 0x100u);
		mem_write16(a2 + 2u, mem_read16(a0 + 6u));
		mem_write16(a2 + 4u, 0u);
		mem_write16(a2 + 0x40u, 0u);
		mem_write16(a2 + 0x42u, 0xFF00u);
		mem_write8(a2 + 0x4Bu, 0u);
		mem_write8(a2 + 0x10u, mem_read8(a0 + 4u));
		mem_write8(a2 + 0x11u, 0u);
		mem_write32(a2 + 0x12u, (uint32_t)mem_read16(a0) << 8);
		d3 = mem_read16(a0 + 2u);
		if ((mem_read8(a0 + 5u) & 0x40u) != 0u)
		{
			d3 = (uint16_t)(d3 - 0x100u);
			d3 = (uint16_t)(d3 - mem_read16(a1 + 2u));
		}
		mem_write32(a2 + 0x16u, d3 << 8);
		unk_061200 = a0 + 8u;
	}
}

uint32_t spawn_offset(uint32_t a0)
{
	uint32_t a1 = 0;

	a1 = spawn_offsets_ADDRESS + (uint16_t)((mem_read8(a0 + 6u) & 0x7Fu) << 2);
	return a1;
}

void func_047BAC(uint32_t a0, uint32_t *p_a2, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;
	uint16_t d0 = 0;
	uint32_t a2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	d0 = (mem_read8(a0 + 5u) & 0x30u) >> 2;
	a2 = DATA32(rom_047BE2_ADDRESS + d0);
	d0 = d0 >> 2;
	d0 = indexed_table_of_8_bit_values_047BDE[d0];
	do
	{
		t1 = mem_read8(a2);
		zero = t1 == 0u;
		if (t1 == 0u)
			break;
		t2 = d0 - 1u;
		d0 = t2;
		a2 += 0x50u;
	} while (t2 != 0xFFFFu);
	*p_a2 = a2;
	*p_zero = zero;
}
