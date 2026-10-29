/**
 *    Name:        stage/layers.c
 *    Description: the areas' layers: their maps of blocks drawn as the scroll goes on
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void func_01E050(uint32_t a0)
{
	uint8_t d1 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint32_t a1 = 0, a2 = 0, a3 = 0, a4 = 0, d0 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d0 = (uint8_t)(unk_063300 >> 16u);
	d0 = (uint8_t)(d0 << 4);
	a2 = unk_063312 + (uint16_t)(d0 + (((uint32_t)(uint8_t)(unk_063304 >> 16u) << 3) * unk_063310 - unk_063310));
	a1 = 0x61800u;
	d7 = 8u;
	do
	{
		d6 = 0x10u;
		a3 = a2;
		do
		{
			a4 = unk_063316 + mem_read16(a3);
			d5 = 4u;
			d1 = mem_read8(a4);
			a3 += 2u;
			do
			{
				mem_write8(a0, d1);
				mem_write8(a0 + 2u, d1);
				mem_write8(a0 + 4u, d1);
				mem_write8(a0 + 6u, d1);
				mem_write8(a1, mem_read8(a4 + 1u));
				mem_write8(a1 + 1u, mem_read8(a4 + 2u));
				mem_write8(a1 + 2u, mem_read8(a4 + 3u));
				mem_write8(a1 + 3u, mem_read8(a4 + 4u));
				mem_write8(a0 + 1u, mem_read8(a4 + 0x11u));
				mem_write8(a0 + 3u, mem_read8(a4 + 0x12u));
				mem_write8(a0 + 5u, mem_read8(a4 + 0x13u));
				mem_write8(a0 + 7u, mem_read8(a4 + 0x14u));
				a4 += 4u;
				t1 = d5;
				d5 = (uint8_t)(t1 - 1u);
				a0 += 0x80u;
				a1 += 0x40u;
			} while (t1 != 1u);
			t2 = d6;
			d6 = (uint8_t)(t2 - 1u);
			a0 -= 0x1F8u;
			a1 -= 0xFCu;
		} while (t2 != 1u);
		a2 -= unk_063310;
		t3 = d7;
		d7 = (uint8_t)(t3 - 1u);
		a0 += 0x180u;
		a1 += 0xC0u;
	} while (t3 != 1u);
}

uint32_t func_01E11E(uint32_t a0)
{
	uint8_t d5 = 0, d6 = 0, d7 = 0;
	uint32_t a2 = 0, a3 = 0, a4 = 0, d0 = 0, d1 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d0 = (uint8_t)(unk_063300 >> 16u);
	d0 = (uint8_t)(d0 << 4);
	d1 = (uint32_t)(uint16_t)((uint32_t)(uint8_t)(unk_063304 >> 16u) << 3) * unk_063310;
	d1 = (d1 & ~0xFFFFu) | (uint16_t)(d1 - unk_063310);
	a2 = unk_063312 + (uint16_t)(d0 + d1);
	d7 = 8u;
	do
	{
		d6 = 0x10u;
		a3 = a2;
		do
		{
			a4 = unk_063316 + mem_read16(a3);
			d5 = 4u;
			d1 = (d1 & ~0xFFu) | mem_read8(a4);
			a3 += 2u;
			do
			{
				mem_write8(a0, d1);
				mem_write8(a0 + 2u, d1);
				mem_write8(a0 + 4u, d1);
				mem_write8(a0 + 6u, d1);
				mem_write8(a0 + 1u, mem_read8(a4 + 1u));
				mem_write8(a0 + 3u, mem_read8(a4 + 2u));
				mem_write8(a0 + 5u, mem_read8(a4 + 3u));
				mem_write8(a0 + 7u, mem_read8(a4 + 4u));
				t1 = d5;
				d5 = (uint8_t)(t1 - 1u);
				a0 += 0x80u;
				a4 += 4u;
			} while (t1 != 1u);
			t2 = d6;
			d6 = (uint8_t)(t2 - 1u);
			a0 -= 0x1F8u;
		} while (t2 != 1u);
		a2 -= unk_063310;
		t3 = d7;
		d7 = (uint8_t)(t3 - 1u);
		a0 += 0x180u;
	} while (t3 != 1u);
	return d1;
}

void func_01E1BA(void)
{
	uint16_t d0 = 0;

	unk_0633C0 = 0u;
	unk_063348 = 0u;
	unk_063388 = 0u;
	unk_06334A = 0u;
	unk_06338A = 0u;
	unk_0633C6 = 0u;
	unk_0633C7 = 0u;
	unk_0633F2 = 0u;
	unk_0633F3 = 0u;
	AT16(unk_0633D0, -1) = 0u;
	unk_0633D2 = 0u;
	AT32(unk_0633EC, -3) = 0u;
	unk_0633F1 = 0u;
	unk_0633F6 = 0u;
	unk_0633FC = 0u;
	unk_061104 = 0u;
	unk_061106 = 0u;
	unk_0633FD = 0u;
	unk_0633FE = 0u;
	unk_0633FF = 0u;
	unk_063488 = 0u;
	unk_061114 = 0u;
	unk_06110A = 0u;
	unk_06110C = 0u;
	unk_061116 = 0u;
	unk_0633F0 = 0u;
	unk_061110 = 0u;
	unk_061112 = 0u;
	unk_06014C(0) = 0u;
	unk_06014C(1) = 0u;
	unk_06014C(2) = 0u;
	unk_06014C(3) = 0u;
	d0 = (uint16_t)((uint32_t)unk_060121 << 2);
	d0 += (uint32_t)d0 << 3;
	unk_063340 = area_layers[d0 / 4u];
	unk_063344 = rom_01E5A4[d0 / 4u];
	unk_063380 = rom_01E5A8[d0 / 4u];
	unk_063384 = rom_01E5AC[d0 / 4u];
	unk_063352 = rom_01E5B0[d0 / 4u];
	unk_063356 = rom_01E5B4[d0 / 4u];
	unk_063392 = rom_01E5B8[d0 / 4u];
	unk_063396 = rom_01E5BC[d0 / 4u];
	unk_063350 = rom_01E5C0[d0 / 2u];
	unk_063390 = rom_01E5C2[d0 / 2u];
	switch (unk_060121)
	{
	case 0:
		func_01E302();
		break;
	case 1:
		func_01E340();
		break;
	case 2:
		func_01E3DC();
		break;
	case 3:
		func_01E3F6();
		break;
	case 4:
		func_01E462();
		break;
	case 5:
		func_01E4A0();
		break;
	case 6:
		func_01E4DE();
		break;
	case 7:
		func_01E52E();
		break;
	case 8:
		func_01E562();
		break;
	case 9:
		func_01E55A();
		break;
	}
	func_01ECAA();
}

void func_01E302(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = 0x61800u;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < 0x61C7Fu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= unk_062000_ADDRESS)
			break;
	}
	start_scroll_segment(0u);
	func_01E712();
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	func_01E732();
}

void func_01E340(void)
{
	uint8_t d0_2 = 0, d2 = 0, d3 = 0;
	uint32_t a0 = 0, a1 = 0, a6 = 0, d0 = 0, d1 = 0;
	uint8_t t1 = 0, t2 = 0;

	a0 = 0x61800u;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < 0x61CBFu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= unk_062000_ADDRESS)
			break;
	}
	a0 = 0x61804u;
	d0_2 = 6u;
	d1 = 0x19u;
	d3 = 0xFDu;
	do
	{
		a1 = a0;
		d2 = (uint8_t)d1;
		d1 = (uint8_t)(d1 - 1u);
		a0++;
		do
		{
			mem_write8(a1, d3);
			t1 = d2;
			d2 = (uint8_t)(t1 - 1u);
			a1 += 0x40u;
		} while (t1 != 1u);
		t2 = d0_2;
		d0_2 = (uint8_t)(t2 - 1u);
	} while (t2 != 1u);
	a0 = unk_062EB0_ADDRESS;
	unk_062EB0 = 0x81u;
	unk_062EF2 = 0xFF00u;
	unk_062EC2 = 0x12000u;
	unk_062EBC = 0x120u;
	unk_062EC6 = 0x6000u;
	unk_062EBE = 0x60u;
	unk_062ECA = 0u;
	a6 = 0x2D8AEu;
	set_animation(d1, a0, a6);
	start_scroll_segment(0u);
	func_01E712();
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	func_01E732();
}

void func_01E3DC(void)
{
	uint32_t a0 = 0;

	start_scroll_segment(0u);
	func_01E712();
	a0 = TILE_RAM + 0x4000u;
	func_01E050(a0);
	func_01E732();
}

void func_01E3F6(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = 0x61800u;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < 0x61AFFu)
			continue;
		d0 = 0x1010101u;
		if (a0 < 0x61CFFu)
			continue;
		d0 = 0xFCFCFCFCu;
		if (a0 < 0x61DBFu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= unk_062000_ADDRESS)
			break;
	}
	start_scroll_segment(0u);
	func_01E708();
	a0 = TILE_RAM + 0x2000u;
	func_01E11E(a0);
	func_01E728();
	func_01E712();
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	func_01E732();
}

void func_01E462(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = 0x61800u;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < 0x61C7Fu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= unk_062000_ADDRESS)
			break;
	}
	start_scroll_segment(0u);
	func_01E712();
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	func_01E732();
}

void func_01E4A0(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = 0x61800u;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < 0x619FFu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= unk_062000_ADDRESS)
			break;
	}
	start_scroll_segment(0u);
	func_01E712();
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	func_01E732();
}

void func_01E4DE(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = 0x61800u;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < 0x61BBFu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= unk_062000_ADDRESS)
			break;
	}
	start_scroll_segment(0u);
	func_01E712();
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	func_01E732();
	func_01E708();
	a0 = TILE_RAM + 0x2000u;
	func_01E11E(a0);
	func_01E728();
}

void func_01E52E(void)
{
	uint32_t a0 = 0;

	start_scroll_segment(0u);
	func_01E708();
	a0 = TILE_RAM + 0x2000u;
	func_01E11E(a0);
	func_01E728();
	func_01E712();
	a0 = TILE_RAM + 0x4000u;
	func_01E050(a0);
	func_01E732();
}

void func_01E55A(void)
{
	unk_06120C = 1u;
	func_01E562();
}

void func_01E562(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = 0x61800u;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < 0x61BFFu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= unk_062000_ADDRESS)
			break;
	}
	start_scroll_segment(0u);
	func_01E712();
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	func_01E732();
}

void func_01E708(void)
{
	uint8_t d0 = 0;
	uint32_t a3 = 0, a4 = 0;
	uint8_t t2 = 0;
	uint32_t t1 = 0;

	a3 = unk_063340_ADDRESS;
	a4 = unk_063300_ADDRESS;
	d0 = 0x10u;
	do
	{
		t1 = a4;
		a4 += 4u;
		mem_write32(t1, mem_read32(a3));
		t2 = d0;
		d0 = (uint8_t)(t2 - 1u);
		a3 += 4u;
	} while (t2 != 1u);
}

void func_01E712(void)
{
	uint8_t d0 = 0;
	uint32_t a3 = 0, a4 = 0;
	uint8_t t2 = 0;
	uint32_t t1 = 0;

	a3 = unk_063380_ADDRESS;
	a4 = unk_063300_ADDRESS;
	d0 = 0x10u;
	do
	{
		t1 = a4;
		a4 += 4u;
		mem_write32(t1, mem_read32(a3));
		t2 = d0;
		d0 = (uint8_t)(t2 - 1u);
		a3 += 4u;
	} while (t2 != 1u);
}

void func_01E728(void)
{
	uint8_t d0 = 0;
	uint32_t a3 = 0, a4 = 0;
	uint8_t t2 = 0;
	uint32_t t1 = 0;

	a4 = unk_063340_ADDRESS;
	a3 = unk_063300_ADDRESS;
	d0 = 0x10u;
	do
	{
		t1 = a4;
		a4 += 4u;
		mem_write32(t1, mem_read32(a3));
		t2 = d0;
		d0 = (uint8_t)(t2 - 1u);
		a3 += 4u;
	} while (t2 != 1u);
}

void func_01E732(void)
{
	uint8_t d0 = 0;
	uint32_t a3 = 0, a4 = 0;
	uint8_t t2 = 0;
	uint32_t t1 = 0;

	a4 = unk_063380_ADDRESS;
	a3 = unk_063300_ADDRESS;
	d0 = 0x10u;
	do
	{
		t1 = a4;
		a4 += 4u;
		mem_write32(t1, mem_read32(a3));
		t2 = d0;
		d0 = (uint8_t)(t2 - 1u);
		a3 += 4u;
	} while (t2 != 1u);
}

void func_01E740(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t a1 = *p_a1;
	uint8_t d3_2 = 0, d6_2 = 0;
	uint32_t a0 = 0, a2 = 0, a3 = 0, a4 = 0, d0 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d6 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (unk_063334 != 0u)
	{
		d0 = unk_063330;
		d3 = d0;
		d5 = d0;
		d1 = ((unk_063300 - 0x2000u) & 0x1E000u) << 6;
		d0 &= 0xF800u;
		d0 = (uint16_t)(0u - d0);
		d0 = d0 >> 4;
		d0 = (uint16_t)(d0 + ((d1 << 16) | (d1 >> 16)));
		a0 = d0 + unk_0633CC;
		a1 = (d0 >> 1) + 0x61800u;
		d2 = ((unk_063300 - 0x2000u) & 0xFFE000u) << 4;
		d3 = ((d3 - 0x800u) & 0xFFE000u) << 3;
		a2 = ((d2 << 16) | (d2 >> 16)) + ((d3 << 16) | (d3 >> 16)) * unk_063310 + unk_063312;
		d5 = (d5 - 0x800u) << 7;
		d5 = (d5 << 16) | (d5 >> 16);
		d5 = d5 & ~0xFFF3u;
		d5 = d5 ^ 0xCu;
		d7 = 0xDu;
		do
		{
			a3 = unk_063316;
			d4 = mem_read16(a2);
			mem_write8(a0, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 2u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 4u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 6u, mem_read8(a3 + (int16_t)d4));
			a3 += d4;
			mem_write8(a1, mem_read8(a3 + 1u + (uint16_t)d5));
			mem_write8(a1 + 1u, mem_read8(a3 + 2u + (uint16_t)d5));
			mem_write8(a1 + 2u, mem_read8(a3 + 3u + (uint16_t)d5));
			mem_write8(a1 + 3u, mem_read8(a3 + 4u + (uint16_t)d5));
			mem_write8(a0 + 1u, mem_read8(a3 + 0x11u + (uint16_t)d5));
			mem_write8(a0 + 3u, mem_read8(a3 + 0x12u + (uint16_t)d5));
			mem_write8(a0 + 5u, mem_read8(a3 + 0x13u + (uint16_t)d5));
			mem_write8(a0 + 7u, mem_read8(a3 + 0x14u + (uint16_t)d5));
			d0 = a1;
			d3 = a0;
			a1 += 4u;
			d6 = d3 & ~0x7Fu;
			d0 = d0 & ~0x3Fu;
			a2 += 2u;
			a0 += 8u;
			if (((d3 + 8u) & 0xFF80u) != (uint16_t)d6)
			{
				a0 = d6;
				a1 = d0;
			}
			t1 = d7;
			d7 = (uint8_t)(t1 - 1u);
		} while (t1 != 1u);
	}
	if (unk_063335 != 0u)
	{
		d0 = unk_06332C;
		d4 = d0;
		d5 = d0;
		d1 = (unk_063304 + 0x1800u) & 0xE000u;
		d0 = (d0 & 0x1F800u) << 6;
		d0 = (d0 << 16) | (d0 >> 16);
		d0 = (uint16_t)(d0 + ((uint16_t)(0u - d1) >> 4));
		a0 = d0 + unk_0633CC;
		a1 = (d0 >> 1) + 0x61800u;
		d2 = ((unk_063304 - 0x800u) & 0xFFE000u) << 3;
		d4 = (d4 & 0xFFE000u) << 4;
		a2 = ((d2 << 16) | (d2 >> 16)) * unk_063310 + ((d4 << 16) | (d4 >> 16)) + unk_063312;
		d5 = (d5 & ~0xFFFFu) | ((uint16_t)d5 >> 8);
		d5 = d5 & ~0xFFE7u;
		d5 = (d5 & ~0xFFFFu) | ((uint16_t)d5 >> 3);
		d7 = 8u;
		do
		{
			a3 = unk_063316;
			d4 = mem_read16(a2);
			mem_write8(a0, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x80u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x100u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x180u, mem_read8(a3 + (int16_t)d4));
			a3 += d4;
			mem_write8(a1, mem_read8(a3 + 1u + (uint16_t)d5));
			mem_write8(a1 + 0x40u, mem_read8(a3 + 5u + (uint16_t)d5));
			mem_write8(a1 + 0x80u, mem_read8(a3 + 9u + (uint16_t)d5));
			mem_write8(a1 + 0xC0u, mem_read8(a3 + 0xDu + (uint16_t)d5));
			mem_write8(a0 + 1u, mem_read8(a3 + 0x11u + (uint16_t)d5));
			mem_write8(a0 + 0x81u, mem_read8(a3 + 0x15u + (uint16_t)d5));
			mem_write8(a0 + 0x101u, mem_read8(a3 + 0x19u + (uint16_t)d5));
			mem_write8(a0 + 0x181u, mem_read8(a3 + 0x1Du + (uint16_t)d5));
			a2 -= unk_063310;
			a1 = ((a1 + 0x100u) & 0xFF1FFFu) | 0x61800u;
			d6 = LINKED(a0, (uint16_t)(a0 + 0x200u));
			a0 = d6 & ~0x9000u;
			t2 = d7;
			d7 = (uint8_t)(t2 - 1u);
		} while (t2 != 1u);
		a3 = unk_063316;
		d4 = mem_read16(a2);
		t3 = (uint8_t)(unk_063304 >> 8u) & 0x18u;
		d3_2 = t3;
		if (t3 != 0u)
		{
			a4 = a3 + d4;
			mem_write8(a0, mem_read8(a3 + (int16_t)d4));
			mem_write8(a1, mem_read8(a4 + 1u + (uint16_t)d5));
			mem_write8(a0 + 1u, mem_read8(a4 + 0x11u + (uint16_t)d5));
			t4 = 4u - (d3_2 >> 3);
			d6_2 = (uint8_t)(t4 - 1u);
			if (t4 != 1u)
			{
				mem_write8(a0 + 0x80u, mem_read8(a3 + (int16_t)d4));
				mem_write8(a1 + 0x40u, mem_read8(a4 + 5u + (uint16_t)d5));
				mem_write8(a0 + 0x81u, mem_read8(a4 + 0x15u + (uint16_t)d5));
				if (d6_2 != 1u)
				{
					mem_write8(a0 + 0x100u, mem_read8(a3 + (int16_t)d4));
					mem_write8(a1 + 0x80u, mem_read8(a4 + 9u + (uint16_t)d5));
					mem_write8(a0 + 0x101u, mem_read8(a4 + 0x19u + (uint16_t)d5));
				}
			}
		}
	}
	*p_d5 = d5;
	*p_d7 = d7;
	*p_a1 = a1;
}

void func_01E9C2(uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint8_t d3_2 = 0, d6_2 = 0;
	uint32_t a0 = 0, a2 = 0, a3 = 0, a4 = 0, d0 = 0, d2 = 0, d3 = 0, d4 = 0, d6 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (unk_063334 != 0u)
	{
		d0 = unk_063330;
		d3 = d0;
		d5 = d0;
		d1 = ((unk_063300 - 0x2000u) & 0x1E000u) << 6;
		d1 = (d1 << 16) | (d1 >> 16);
		d0 &= 0xF800u;
		d0 = (uint16_t)(0u - d0);
		d0 = d0 >> 4;
		a0 = (uint16_t)(d0 + d1) + unk_0633CC;
		d2 = ((unk_063300 - 0x2000u) & 0xFFE000u) << 4;
		d3 = ((d3 - 0x800u) & 0xFFE000u) << 3;
		a2 = ((d2 << 16) | (d2 >> 16)) + ((d3 << 16) | (d3 >> 16)) * unk_063310 + unk_063312;
		d5 = (d5 - 0x800u) << 7;
		d5 = (d5 << 16) | (d5 >> 16);
		d5 = d5 & ~0xFFF3u;
		d5 = d5 ^ 0xCu;
		d7 = 0xDu;
		do
		{
			a3 = unk_063316;
			d4 = mem_read16(a2);
			mem_write8(a0, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 2u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 4u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 6u, mem_read8(a3 + (int16_t)d4));
			a3 += d4;
			mem_write8(a0 + 1u, mem_read8(a3 + 1u + (uint16_t)d5));
			mem_write8(a0 + 3u, mem_read8(a3 + 2u + (uint16_t)d5));
			mem_write8(a0 + 5u, mem_read8(a3 + 3u + (uint16_t)d5));
			mem_write8(a0 + 7u, mem_read8(a3 + 4u + (uint16_t)d5));
			d3 = a0;
			d6 = d3 & ~0x7Fu;
			a2 += 2u;
			a0 += 8u;
			if (((d3 + 8u) & 0xFF80u) != (uint16_t)d6)
				a0 = d6;
			t1 = d7;
			d7 = (uint8_t)(t1 - 1u);
		} while (t1 != 1u);
	}
	if (unk_063335 != 0u)
	{
		d0 = unk_06332C;
		d4 = d0;
		d5 = d0;
		d1 = (unk_063304 + 0x1800u) & 0xE000u;
		d1 = (uint16_t)(0u - d1) >> 4;
		d0 = (d0 & 0x1F800u) << 6;
		d0 = (d0 << 16) | (d0 >> 16);
		a0 = (uint16_t)(d0 + d1) + unk_0633CC;
		d2 = ((unk_063304 - 0x800u) & 0xFFE000u) << 3;
		d4 = (d4 & 0xFFE000u) << 4;
		a2 = ((d2 << 16) | (d2 >> 16)) * unk_063310 + ((d4 << 16) | (d4 >> 16)) + unk_063312;
		d5 = (d5 & ~0xFFFFu) | ((uint16_t)d5 >> 8);
		d5 = d5 & ~0xFFE7u;
		d5 = (d5 & ~0xFFFFu) | ((uint16_t)d5 >> 3);
		d7 = 8u;
		do
		{
			a3 = unk_063316;
			d4 = mem_read16(a2);
			mem_write8(a0, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x80u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x100u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x180u, mem_read8(a3 + (int16_t)d4));
			a3 += d4;
			mem_write8(a0 + 1u, mem_read8(a3 + 1u + (uint16_t)d5));
			mem_write8(a0 + 0x81u, mem_read8(a3 + 5u + (uint16_t)d5));
			mem_write8(a0 + 0x101u, mem_read8(a3 + 9u + (uint16_t)d5));
			mem_write8(a0 + 0x181u, mem_read8(a3 + 0xDu + (uint16_t)d5));
			a2 -= unk_063310;
			d6 = LINKED(a0, (uint16_t)(a0 + 0x200u));
			a0 = d6 & ~0x9000u;
			t2 = d7;
			d7 = (uint8_t)(t2 - 1u);
		} while (t2 != 1u);
		a3 = unk_063316;
		d4 = mem_read16(a2);
		t3 = (uint8_t)(unk_063304 >> 8u) & 0x18u;
		d3_2 = t3;
		if (t3 != 0u)
		{
			a4 = a3 + d4;
			mem_write8(a0, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 1u, mem_read8(a4 + 1u + (uint16_t)d5));
			t4 = 4u - (d3_2 >> 3);
			d6_2 = (uint8_t)(t4 - 1u);
			if (t4 != 1u)
			{
				mem_write8(a0 + 0x80u, mem_read8(a3 + (int16_t)d4));
				mem_write8(a0 + 0x81u, mem_read8(a4 + 5u + (uint16_t)d5));
				if (d6_2 != 1u)
				{
					mem_write8(a0 + 0x100u, mem_read8(a3 + (int16_t)d4));
					mem_write8(a0 + 0x101u, mem_read8(a4 + 9u + (uint16_t)d5));
				}
			}
		}
	}
	*p_d1 = d1;
	*p_d5 = d5;
	*p_d7 = d7;
}

void func_01EBCE(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, a6 = 0;

	unk_061104++;
	unk_061114++;
	unk_06110A++;
	unk_06110C++;
	unk_061116++;
	d0 = (uint16_t)((uint32_t)unk_060121 << 2);
	switch (d0)
	{
	case 0:
		func_01ED14(d0, p_d5, p_d7, p_a1);
		break;
	case 4:
		func_01EDCC(p_d5, p_d7, p_a1);
		break;
	case 8:
		func_01EEAA(d0, p_d5, p_d7, p_a1);
		break;
	case 12:
		func_01F186(p_d5, p_d7, p_a1);
		break;
	case 16:
		func_01F252(p_d5, p_d7);
		break;
	case 20:
		func_01F7EC(p_d5, p_d7, p_a1);
		break;
	case 24:
		func_01FC20(p_d5, p_d7);
		break;
	case 28:
		func_01F314(p_d5, p_d7, p_a1);
		break;
	case 32:
		func_01F420(p_d5, p_d7, p_a1);
		break;
	case 36:
		func_01F2EE(p_d5, p_d7);
		break;
	}
	if ((unk_06335B | unk_06339B | unk_0633EC) != 0u)
	{
		unk_0633F6 = 0u;
		unk_062F50 = 0u;
		return;
	}
	unk_0633F6++;
	if (unk_06120C >= 3u)
	{
		unk_0633F6 = 0u;
		unk_062F50 = 0u;
		return;
	}
	if ((uint8_t)(unk_0633F6 >> 8u) == 0u)
	{
		unk_062F50 = 0u;
		return;
	}
	a0 = unk_062F50_ADDRESS;
	if (unk_062F50 == 0u)
	{
		AT16(unk_062F50, -1) = 0x8100u;
		unk_062F60 = 0u;
		unk_062F92 = 0xFF00u;
		unk_062F5C = 0x158u;
		unk_062F5E = 0u;
		a6 = 0x2DB76u;
		if (unk_061107 != 0u)
			a6 = 0x2DBAEu;
		set_animation(0u, a0, a6);
	}
	if (unk_06120C != 0u)
	{
		unk_0633F6 = 0x100u;
		return;
	}
	if (unk_0633F6 < 0x600u)
	{
		return;
	}
	func_013354(p_d5, p_d7);
	unk_0633F6 = 0u;
	unk_062F50 = 0u;
}

void func_01ECAA(void)
{
	unk_06005C = (unk_063340 >> 8) & 0x1FFu;
	unk_060060 = (unk_063380 >> 8) & 0x1FFu;
	unk_06005E = (unk_06005E & 0xFF00u) | (0u - (uint8_t)(unk_063344 >> 8u) & 0xFFu);
	unk_060062 = (unk_060062 & 0xFF00u) | (0u - (uint8_t)(unk_063384 >> 8u) & 0xFFu);
}

void func_01ED14(uint16_t d0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a1 = *p_a1;
	uint8_t d0_2 = 0, d1_2 = 0, d2_2 = 0, d3 = 0;
	uint16_t d1 = 0, d2 = 0;
	uint32_t a0 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_061106 == 0u && unk_061104 == 0x30u)
	{
		a0 = unk_062000_ADDRESS;
		do
		{
			if ((mem_read8(a0) & 1u) != 0u)
			{
				d0 &= ~0xFFu;
				if ((mem_read8(a0) & 0x40u) != 0u)
					d0 |= (uint8_t)(d0 - 1u);
				d1 = mem_read16(a0 + 0xCu);
				d2 = mem_read16(a0 + 0xEu);
				func_030034(d0, d1, d2, p_d5, p_d7);
				break;
			}
			a0 += 0x50u;
		} while (a0 < 0x62140u);
	}
	unk_06335B = 0u;
	func_01E712();
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E9C2(&ignored, p_d5, p_d7);
	func_01E732();
	func_01ECAA();
	if (unk_0633FD == 0u && unk_063380 >= 0x3C000u)
	{
		a0 = 0x61824u;
		d0_2 = 0xCu;
		d1_2 = 0x12u;
		d3 = 0xFEu;
		do
		{
			d2_2 = (uint8_t)d1_2;
			d1_2++;
			a1 = a0;
			a0++;
			do
			{
				mem_write8(a1, d3);
				t1 = d2_2;
				d2_2 = (uint8_t)(t1 - 1u);
				a1 += 0x40u;
			} while (t1 != 1u);
			t2 = d0_2;
			d0_2 = (uint8_t)(t2 - 1u);
		} while (t2 != 1u);
		unk_0633FD--;
	}
	*p_a1 = a1;
}

void func_01EDCC(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a1 = *p_a1;
	uint8_t d0 = 0, d1 = 0, d2 = 0, d3 = 0;
	uint32_t a0 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_0633FD == 0u && unk_063380 >= 0x2000u)
	{
		a0 = 0x61834u;
		d0 = 8u;
		d1 = 0x13u;
		d3 = 0xFEu;
		do
		{
			d2 = (uint8_t)d1;
			d1++;
			a1 = a0;
			a0++;
			do
			{
				mem_write8(a1, d3);
				t1 = d2;
				d2 = (uint8_t)(t1 - 1u);
				a1 += 0x40u;
			} while (t1 != 1u);
			t2 = d0;
			d0 = (uint8_t)(t2 - 1u);
		} while (t2 != 1u);
		unk_0633FD--;
	}
	unk_06335B = 0u;
	func_01E712();
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E9C2(&ignored, p_d5, p_d7);
	func_01E732();
	func_01ECAA();
	func_0303CE(p_d5, p_d7, &a1);
	func_01EE3A(0u, &ignored, p_d5, p_d7);
	*p_a1 = a1;
}

void func_01EE3A(uint32_t d6, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d2 = 0;
	uint32_t a0 = 0, d0 = 0, ignored = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0;

	a0 = unk_062EB0_ADDRESS;
	if (unk_061106 == 0u && unk_061104 == 0x30u)
	{
		d0 = 0x7Fu;
		*p_d1 = (*p_d1 & ~0xFFFFu) | unk_062EBC;
		d2 = 0x70u;
		func_03002C(d2, &d0, p_d1, &d5, &ignored, p_d7);
	}
	if (unk_062EE3 == 0x30u)
	{
		if (unk_062ECA != 0u)
		{
			t1 = unk_062EC2 - 0x400u;
			AS16(unk_062EC2) = t1;
			AT16(unk_062EC2, 2) = t1 >> 16;
		}
		else
		{
			t2 = unk_062EC2 + 0x400u;
			AS16(unk_062EC2) = t2;
			AT16(unk_062EC2, 2) = t2 >> 16;
		}
		unk_062ECA ^= 0xFFu;
	}
	t3 = unk_062EC2 - (int16_t)unk_06338C;
	AS16(unk_062EC2) = t3;
	AT16(unk_062EC2, 2) = t3 >> 16;
	unk_062EBC = unk_062EC2 >> 8;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_01EEAA(uint32_t d0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a1 = *p_a1;
	uint32_t carry = 0;
	uint8_t d1_2 = 0;
	uint16_t d1_3 = 0, d2 = 0, d6 = 0;
	uint32_t a0 = 0, a6 = 0, d1 = 0, ignored = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	unk_06335B = 0u;
	unk_063340 = unk_063380;
	unk_063344 = unk_063384;
	if (unk_063380 >= 0x12000u)
	{
		if (unk_063380 < 0x1E000u)
		{
			if (unk_061110 != 0u)
			{
				if (unk_061110 == 0x10u)
				{
					d0 = 0x7Fu;
					d2 = 0x70u;
					d1 = (0x26000u - unk_063380) >> 8;
					func_03002C(d2, &d0, &d1, p_d5, &ignored, p_d7);
				}
				else if (unk_061110 == 0xA0u)
				{
					a6 = 0x1F118u;
					d0 = 8u;
					func_01F080((uint8_t)d0, a6, p_d7, &a1);
				}
				else if (unk_061110 == 0xB0u)
				{
					d0 = 0x7Fu;
					d2 = 0x70u;
					d1_3 = (uint16_t)((0x26000u - unk_063380) >> 8);
					func_03000C(d1_3, d2, &d0, p_d5, p_d7);
				}
				else if (unk_061110 == 0x170u)
				{
					a0 = TILE_RAM + 0x2478u;
					a1 = TILE_RAM + 0x2400u;
					d0 &= ~0xFFu;
					d1_2 = 0x10u;
					*p_d7 = 7u;
					do
					{
						d6 = 3u;
						do
						{
							mem_write8(a1, d0);
							mem_write8(a0, d0);
							a1++;
							mem_write8(a1, d1_2);
							a0++;
							mem_write8(a0, d1_2);
							t1 = d6 - 1u;
							d6 = t1;
							a1++;
							a0++;
						} while (t1 != 0xFFFFu);
						t2 = *p_d7 - 1u;
						*p_d7 = t2;
						a0 += 0x78u;
						a1 += 0x78u;
					} while (t2 != 0xFFFFu);
				}
				else if (unk_061110 >= 0x10u && unk_061110 < 0xA0u)
				{
					a6 = 0x1F158u;
					d0 = unk_061110;
					if ((d0 & 7u) == 0u)
					{
						d0 = (d0 & 0x18u) >> 1;
						a6 = DATA32(a6 + d0);
						func_01F0AE(a6, p_d7, &a1);
					}
				}
			}
			else
			{
				a6 = record_01F0D8_ADDRESS;
				d0 = 0x28u;
				func_01F080((uint8_t)d0, a6, p_d7, &a1);
			}
			t3 = unk_061110;
			carry = (uint16_t)(t3 + 1u) < t3;
			unk_061110 = t3 + 1u;
			if (carry)
				unk_061110--;
		}
		else if (unk_061110 < 0x170u)
		{
			unk_061110 = 0x170u;
			a0 = TILE_RAM + 0x2478u;
			a1 = TILE_RAM + 0x2400u;
			d0 &= ~0xFFu;
			d1_2 = 0x10u;
			*p_d7 = 7u;
			do
			{
				d6 = 3u;
				do
				{
					mem_write8(a1, d0);
					mem_write8(a0, d0);
					a1++;
					mem_write8(a1, d1_2);
					a0++;
					mem_write8(a0, d1_2);
					t1 = d6 - 1u;
					d6 = t1;
					a1++;
					a0++;
				} while (t1 != 0xFFFFu);
				t2 = *p_d7 - 1u;
				*p_d7 = t2;
				a0 += 0x78u;
				a1 += 0x78u;
			} while (t2 != 0xFFFFu);
			t3 = unk_061110;
			carry = (uint16_t)(t3 + 1u) < t3;
			unk_061110 = t3 + 1u;
			if (carry)
				unk_061110--;
		}
	}
	if (unk_061112 != 1u || unk_061104 < 0xA0u)
	{
		func_01E712();
		unk_0633CC = TILE_RAM + 0x4000u;
		func_01E740(p_d5, p_d7, &a1);
		func_01E732();
		func_01ECAA();
		*p_a1 = a1;
		return;
	}
	a0 = unk_062000_ADDRESS;
	while ((mem_read8(a0) & 1u) == 0u)
	{
		a0 += 0x50u;
		if (a0 >= 0x62140u)
		{
			func_01E712();
			unk_0633CC = TILE_RAM + 0x4000u;
			func_01E740(p_d5, p_d7, &a1);
			func_01E732();
			func_01ECAA();
			*p_a1 = a1;
			return;
		}
	}
	d1_3 = mem_read16(a0 + 0xCu);
	if ((mem_read8(a0) & 0x40u) != 0u)
		d1_3 -= 0x18u;
	d2 = (uint16_t)(mem_read16(a0 + 0xEu) + 8u);
	d0 &= ~0xFFu;
	func_0300DA(d0, d1_3, d2, p_d5, p_d7);
	func_01E712();
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E740(p_d5, p_d7, &a1);
	func_01E732();
	func_01ECAA();
	*p_a1 = a1;
}

void func_01F080(uint8_t d0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a1)
{
	uint16_t d6 = 0;
	uint32_t a0 = 0, a1 = 0, d7 = 0;
	uint16_t t4 = 0, t5 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0;

	a0 = TILE_RAM + 0x2478u;
	a1 = TILE_RAM + 0x2400u;
	d7 = 7u;
	do
	{
		d6 = 3u;
		do
		{
			mem_write8(a1, d0);
			t1 = a0;
			a0++;
			mem_write8(t1, d0);
			a1++;
			mem_write8(a1, mem_read8(a6 + 4u));
			t2 = a6;
			a6++;
			t3 = a0;
			a0++;
			mem_write8(t3, mem_read8(t2));
			t4 = d6 - 1u;
			d6 = t4;
			a1++;
		} while (t4 != 0xFFFFu);
		a1 += 0x78u;
		a6 += 4u;
		t5 = d7 - 1u;
		d7 = t5;
		a0 += 0x78u;
	} while (t5 != 0xFFFFu);
	*p_d7 = d7;
	*p_a1 = a1;
}

void func_01F0AE(uint32_t a6, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a0 = 0, a1 = 0, d7 = 0;
	uint16_t t1 = 0;

	a0 = TILE_RAM + 0x25FDu;
	a1 = TILE_RAM + 0x2581u;
	d7 = 2u;
	do
	{
		mem_write8(a0, mem_read8(a6));
		mem_write8(a0 + 2u, mem_read8(a6 + 1u));
		mem_write8(a1, mem_read8(a6 + 2u));
		a1 += 0x80u;
		a6 += 3u;
		t1 = d7 - 1u;
		d7 = t1;
		a0 += 0x80u;
	} while (t1 != 0xFFFFu);
	*p_d7 = d7;
	*p_a1 = a1;
}

void func_01F186(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d7 = *p_d7;
	uint32_t a1 = *p_a1;
	uint8_t d0 = 0, d6 = 0;
	uint32_t a0 = 0, a6 = 0, ignored = 0;
	uint8_t t2 = 0, t3 = 0;
	uint32_t t1 = 0;

	if (unk_0633FD == 0u && unk_063380 >= 0x30000u)
	{
		a1 = 0x61810u;
		a6 = table_loaded_by_lea_01F242_ADDRESS;
		d0 = 0xFEu;
		d7 = 0x10u;
		do
		{
			a0 = a1;
			t1 = a6;
			a6++;
			d6 = DATA8(t1);
			a1++;
			do
			{
				mem_write8(a0, d0);
				t2 = d6;
				d6 = (uint8_t)(t2 - 1u);
				a0 += 0x40u;
			} while (t2 != 1u);
			t3 = d7;
			d7 = (uint8_t)(t3 - 1u);
		} while (t3 != 1u);
		unk_0633FD--;
	}
	func_01E712();
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E9C2(&ignored, p_d5, &d7);
	func_01E732();
	unk_063340 = unk_063380;
	unk_06336C = unk_0633AC;
	unk_063344 = unk_063384;
	unk_063370 = unk_0633B0;
	unk_063374 = unk_0633B4;
	unk_063375 = unk_0633B5;
	func_01E708();
	unk_0633CC = TILE_RAM + 0x2000u;
	func_01E9C2(&ignored, p_d5, &d7);
	func_01E728();
	func_01ECAA();
	*p_d7 = d7;
	*p_a1 = a1;
}

void func_01F252(uint32_t *p_d5, uint32_t *p_d7)
{
	uint8_t d0 = 0;
	uint32_t a0 = 0, a6 = 0, ignored = 0;

	unk_06335B = 0u;
	if (unk_063380 < 0x33000u)
	{
		func_01E712();
		unk_0633CC = TILE_RAM + 0x4000u;
		func_01E9C2(&ignored, p_d5, p_d7);
		func_01E732();
		func_01ECAA();
		return;
	}
	a0 = unk_062DC0_ADDRESS;
	if (unk_062DC0 == 0u)
	{
		AT16(unk_062DC0, -1) = 0x8100u;
		unk_062DD0 = 0u;
		unk_062E02 = 0xFF00u;
		unk_062DCE = 0xF0u;
		a6 = 0x2E11Au;
		set_animation(0u, a0, a6);
		a6 = 0xCA04u;
		*p_d7 = (*p_d7 & ~0xFFFFu) | 0x43Du;
		post_palette_request((uint16_t)*p_d7, a6);
	}
	unk_062DCC = (0x4D000u - unk_063380) >> 8;
	if ((uint8_t)unk_0600A4 != 0u)
	{
		func_01E712();
		unk_0633CC = TILE_RAM + 0x4000u;
		func_01E9C2(&ignored, p_d5, p_d7);
		func_01E732();
		func_01ECAA();
		return;
	}
	d0 = 0u;
	if (unk_062DF3 == 0u)
		d0 = 0x10u;
	unk_062DF3 = d0;
	func_01E712();
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E9C2(&ignored, p_d5, p_d7);
	func_01E732();
	func_01ECAA();
}

void func_01F2EE(uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t ignored = 0;

	unk_06335B = 0u;
	func_01E712();
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E9C2(&ignored, p_d5, p_d7);
	func_01E732();
	func_01ECAA();
}

void func_01F314(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d7 = *p_d7;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0;
	uint32_t a0 = 0, a6 = 0, d1 = 0;
	uint8_t t1 = 0;
	uint16_t t3 = 0;
	uint32_t t2 = 0;

	func_01E712();
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E740(p_d5, &d7, p_a1);
	func_01E732();
	t1 = unk_06339B;
	unk_06335B = t1;
	if (t1 != 0u)
	{
		d0 = unk_06338C;
		t2 = unk_063340 + (int16_t)(d0 + (d0 >> 2));
		unk_063340 = (unk_063340 & 0xFFFF0000u) | (t2 & 0xFFFFu);
		unk_063340 = (unk_063340 & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
	}
	func_01ECAA();
	if (unk_063380 < 0x60000u)
		func_0303CE(p_d5, &d7, p_a1);
	else
	{
		if (io_read16(TILES_102030) != 0x10u)
		{
			a0 = TILES_102030;
			d0_2 = 0u;
			d1 = 0x10u;
			d7 = 0x1Fu;
			do
			{
				mem_write8(a0, d0_2);
				a0++;
				mem_write8(a0, d1);
				a0++;
				mem_write8(a0, d0_2);
				a0++;
				mem_write8(a0, d1);
				a0++;
				mem_write8(a0, d0_2);
				a0++;
				mem_write8(a0, d1);
				a0++;
				mem_write8(a0, d0_2);
				a0++;
				mem_write8(a0, d1);
				t3 = d7 - 1u;
				d7 = t3;
				a0 += 0x79u;
			} while (t3 != 0xFFFFu);
			io_write8(TILES_102EAE, d0_2);
			io_write8(TILES_102EAF, d1);
			io_write8(TILES_102EB8, d0_2);
			io_write8(TILES_102EB9, d1);
		}
		if (unk_063380 >= 0x68800u)
		{
			a0 = unk_062DC0_ADDRESS;
			unk_062DCC = (0x84000u - unk_063380) >> 8;
			if (unk_062DC0 != 0u)
			{
				if ((uint8_t)unk_0600A4 == 0u)
				{
					a6 = 0x2DB0Au;
					if (unk_062DF3 == 0u)
						a6 = 0x2DAE6u;
					set_animation(d1, a0, a6);
				}
			}
			else
			{
				AT16(unk_062DC0, -1) = 0x8180u;
				unk_062E02 = 0xFF00u;
				unk_062DCE = 0x60u;
				unk_062DD0 = 0x3800u;
				unk_062DFA = 0x2E928u;
				a6 = 0x2DAE6u;
				set_animation(d1, a0, a6);
			}
		}
		else
			func_0303CE(p_d5, &d7, p_a1);
	}
	*p_d7 = d7;
}

void func_01F420(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	switch (unk_0633D2)
	{
	case 0:
		func_01F446(p_d5, p_d7);
		break;
	case 1:
		func_01F556(p_d5, p_d7, p_a1);
		break;
	case 2:
		func_01F690(p_d5, p_d7, p_a1);
		break;
	}
	func_01ECAA();
}

void func_01F446(uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t a0 = 0, a6 = 0, ignored = 0;

	func_01E712();
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E9C2(&ignored, p_d5, p_d7);
	func_01E732();
	if (unk_063380 < 0x42000u)
	{
		return;
	}
	unk_063340 = unk_063380 - 0x40000u;
	unk_06336C = unk_0633AC - 0x40000u;
	unk_063375 = unk_0633B5;
	func_01E708();
	unk_0633CC = TILE_RAM + 0x2000u;
	func_01E9C2(&ignored, p_d5, p_d7);
	func_01E728();
	if (unk_063380 < 0x58000u)
	{
		return;
	}
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | 0xFF0000u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u && mem_read32(a0 + 0x12u) <= mem_read32(a0 + 0x16u) - 0x2000u + 0x9000u)
		{
			return;
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	unk_0633C9 = 0xFFu;
	unk_06339A = 0x80u;
	unk_06339B = 0x80u;
	unk_06338C = 0u;
	unk_06338E = 0u;
	a0 = unk_062DC0_ADDRESS;
	unk_062DC0 = 1u;
	unk_062DC1 = 0u;
	unk_062E02 = (unk_062E02 & 0xFFu) | 0xFF00u;
	a6 = 0x2DB6Cu;
	set_animation(ignored, a0, a6);
	*p_d7 = (*p_d7 & ~0xFFu) | 0x21u;
	func_0091A4((uint8_t)*p_d7, a6);
	unk_0633D2++;
}

void func_01F556(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d7 = *p_d7;
	uint32_t a1 = *p_a1;
	uint8_t d0 = 0, d1 = 0, d2 = 0, d3 = 0;
	uint32_t a0 = 0, ignored = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0;
	uint32_t t1 = 0, t2 = 0;

	if ((int8_t)unk_0633D0 < 0)
	{
		if (unk_063300 < 0xA0000u)
		{
			if (unk_063300 + (int16_t)unk_06330C >= 0xA2800u && (int8_t)unk_0633D0 >= 0)
			{
				t1 = unk_063300 - 0x40000u;
				unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
				unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
				t2 = unk_063304 + 0x40000u;
				unk_063304 = (unk_063304 & 0xFFFF0000u) | (t2 & 0xFFFFu);
				unk_063304 = (unk_063304 & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
				t3 = unk_0633D0 + 1u;
				unk_0633D0 = t3;
				if ((int8_t)t3 >= 0)
					unk_0633D0 = 0x80u;
			}
		}
		else
		{
			if (unk_06330C < 0x120u && unk_06330C >= 0x110u)
			{
				d7 = (d7 & ~0xFFu) | 0x29u;
				func_0091A4((uint8_t)d7, 0u);
			}
			unk_06330C -= 0x10u;
			unk_06330E -= 0x10u;
			if (unk_06330C >= 0x100u)
			{
				if (unk_063300 + (int16_t)unk_06330C >= 0xA2800u && (int8_t)unk_0633D0 >= 0)
				{
					t1 = unk_063300 - 0x40000u;
					unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
					unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
					t2 = unk_063304 + 0x40000u;
					unk_063304 = (unk_063304 & 0xFFFF0000u) | (t2 & 0xFFFFu);
					unk_063304 = (unk_063304 & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
					t3 = unk_0633D0 + 1u;
					unk_0633D0 = t3;
					if ((int8_t)t3 >= 0)
						unk_0633D0 = 0x80u;
				}
			}
			else
			{
				unk_06330C = 0x100u;
				unk_06330E = 0x100u;
			}
		}
	}
	else
	{
		unk_06330C += 4u;
		unk_06330E += 4u;
		if (unk_06330C < 0x400u)
		{
			if (unk_063300 + (int16_t)unk_06330C >= 0xA2800u && (int8_t)unk_0633D0 >= 0)
			{
				t1 = unk_063300 - 0x40000u;
				unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
				unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
				t2 = unk_063304 + 0x40000u;
				unk_063304 = (unk_063304 & 0xFFFF0000u) | (t2 & 0xFFFFu);
				unk_063304 = (unk_063304 & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
				t3 = unk_0633D0 + 1u;
				unk_0633D0 = t3;
				if ((int8_t)t3 >= 0)
					unk_0633D0 = 0x80u;
			}
		}
		else
		{
			unk_06330C = 0x400u;
			unk_06330E = 0x400u;
			if (unk_063300 + (int16_t)unk_06330C >= 0xA2800u && (int8_t)unk_0633D0 >= 0)
			{
				t1 = unk_063300 - 0x40000u;
				unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
				unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
				t2 = unk_063304 + 0x40000u;
				unk_063304 = (unk_063304 & 0xFFFF0000u) | (t2 & 0xFFFFu);
				unk_063304 = (unk_063304 & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
				t3 = unk_0633D0 + 1u;
				unk_0633D0 = t3;
				if ((int8_t)t3 >= 0)
					unk_0633D0 = 0x80u;
			}
		}
	}
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E9C2(&ignored, p_d5, &d7);
	func_01E732();
	func_01F7A4();
	if ((int8_t)unk_0633C9 >= 0)
	{
		d7 = (d7 & ~0xFFu) | 0x2Bu;
		func_0091A4((uint8_t)d7, 0u);
		a0 = unk_061830_ADDRESS;
		d0 = 0x10u;
		d1 = 0x20u;
		d3 = 0xFDu;
		do
		{
			a1 = a0;
			d2 = (uint8_t)d1;
			d1--;
			a0++;
			do
			{
				mem_write8(a1, d3);
				t4 = d2;
				d2 = (uint8_t)(t4 - 1u);
				a1 += 0x40u;
			} while (t4 != 1u);
			t5 = d0;
			d0 = (uint8_t)(t5 - 1u);
		} while (t5 != 1u);
		unk_0633D2++;
	}
	*p_d7 = d7;
	*p_a1 = a1;
}

void func_01F690(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint8_t d0_2 = 0, d1 = 0, d2_2 = 0, d3 = 0;
	uint32_t a0 = 0, d0 = 0, d2 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	func_01E712();
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E9C2(&ignored, p_d5, p_d7);
	func_01E732();
	unk_063340 = unk_063380 - 0xA0000u;
	unk_06336C = unk_0633AC - 0xA0000u;
	unk_063375 = unk_0633B5;
	func_01E708();
	unk_0633CC = TILE_RAM + 0x2000u;
	func_01E9C2(&ignored, p_d5, p_d7);
	func_01E728();
	func_01F7A4();
	d0 = unk_063380;
	if (d0 >= 0xC0000u)
	{
		if (d0 < 0xC0200u)
		{
			a0 = unk_061830_ADDRESS;
			if (unk_061830 != 0xFFu)
			{
				d2 = 0xFFFFFFFFu;
				d0_2 = 0x10u;
				func_01F792(d0_2, d2, a0);
				a0 = 0x61C30u;
				d2 = 0x1010101u;
				d0_2 = 0x10u;
				func_01F792(d0_2, d2, a0);
			}
			return;
		}
		if (unk_0633FD == 0u && unk_063380 >= 0xC9000u)
		{
			a0 = 0x61838u;
			d0_2 = 0x10u;
			d1 = 0x10u;
			d3 = 0xFEu;
			do
			{
				d2_2 = (uint8_t)d1;
				d1++;
				*p_a1 = a0;
				a0++;
				if (a0 >= 0x61840u)
					a0 = 0x61800u;
				do
				{
					mem_write8(*p_a1, d3);
					t1 = d2_2;
					d2_2 = (uint8_t)(t1 - 1u);
					*p_a1 += 0x40u;
				} while (t1 != 1u);
				t2 = d0_2;
				d0_2 = (uint8_t)(t2 - 1u);
			} while (t2 != 1u);
			unk_0633FD--;
		}
	}
}

void func_01F792(uint8_t d0, uint32_t d2, uint32_t a0)
{
	uint8_t d1 = 0;
	uint8_t t1 = 0, t2 = 0;

	do
	{
		d1 = 4u;
		do
		{
			mem_write32(a0, d2);
			t1 = d1;
			d1 = (uint8_t)(t1 - 1u);
			a0 += 4u;
		} while (t1 != 1u);
		t2 = d0;
		d0 = (uint8_t)(t2 - 1u);
		a0 += 0x30u;
	} while (t2 != 1u);
}

void func_01F7A4(void)
{
	uint32_t a0 = 0, d0 = 0;
	uint32_t t1 = 0;

	a0 = unk_062DC0_ADDRESS;
	unk_062DC0 &= 0x7Fu;
	t1 = unk_063380;
	d0 = 0xCE000u - t1;
	if (t1 > 0xCE000u || d0 >= 0x1A000u)
		return;
	unk_062DCC = (d0 + 0x6000u) >> 8;
	unk_062DCE = (0x18000u - unk_063384) >> 8;
	unk_062DC0 |= 0x80u;
}

void func_01F7EC(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t ignored = 0;

	func_01E712();
	unk_0633CC = TILE_RAM + 0x4000u;
	func_01E9C2(&ignored, p_d5, p_d7);
	func_01E732();
	unk_063344 = unk_063384;
	switch (unk_0633D2)
	{
	case 0:
		func_01F848(p_d5, p_d7, p_a1);
		break;
	case 1:
		func_01F86C(p_d5, p_d7, p_a1);
		break;
	case 2:
		func_01F872(p_d5, p_d7, p_a1);
		break;
	case 3:
		func_01F88E(p_d5, p_d7, p_a1);
		break;
	case 4:
		func_01F894(p_d5, p_d7, p_a1);
		break;
	case 5:
		func_01F8B0(p_d5, p_d7, p_a1);
		break;
	case 6:
		func_01F8B6();
		break;
	}
	func_01ECAA();
}

void func_01F848(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint8_t d5 = (uint8_t)*p_d5;
	uint8_t d5_2 = 0;

	if (unk_063380 < 0x10000u)
		return;
	d5_2 = 0u;
	draw_screen_picture(d5_2, p_d7, p_a1);
	*p_d7 = func_04A90E(*p_d7);
	unk_0633D2++;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5_2;
}

void func_01F86C(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint8_t d5 = 0;

	d5 = 0u;
	func_01F8B8(d5, p_d7, p_a1);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
}

void func_01F872(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	if (unk_063380 < 0x30000u)
		return;
	*p_d5 = 0x40u;
	draw_screen_picture((uint8_t)*p_d5, p_d7, p_a1);
	*p_d7 = func_04A90E(*p_d7);
	unk_0633D2++;
}

void func_01F88E(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	*p_d5 = 0x40u;
	func_01F8B8((uint8_t)*p_d5, p_d7, p_a1);
}

void func_01F894(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	if (unk_063380 < 0x50000u)
		return;
	*p_d5 = 0xFFFFFF80u;
	draw_screen_picture((uint8_t)*p_d5, p_d7, p_a1);
	*p_d7 = func_04A90E(*p_d7);
	unk_0633D2++;
}

void func_01F8B0(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	*p_d5 = 0xFFFFFF80u;
	func_01F8B8((uint8_t)*p_d5, p_d7, p_a1);
}

void func_01F8B6(void)
{
}

void func_01F8B8(uint8_t d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d7 = *p_d7;
	uint32_t a1 = *p_a1;
	uint8_t d0 = 0;
	uint16_t d6 = 0;
	uint32_t a0 = 0, a2 = 0, a3 = 0, d0_2 = 0;
	uint16_t t3 = 0, t4 = 0;
	uint32_t t1 = 0, t2 = 0, t5 = 0, t6 = 0;

	if ((unk_0600A4 & 3u) == 0u)
	{
		d0 = 0x34u;
		a2 = table_loaded_by_lea_01FBE0_ADDRESS;
		a3 = 0x1FBF0u;
		if ((unk_0600A4 & 4u) != 0u)
		{
			d0++;
			a2 = 0x1FC00u;
			a3 = 0x1FC10u;
		}
		a0 = TILE_RAM + 0x2A56u;
		a1 = TILE_RAM + 0x2A6Cu;
		d7 = 3u;
		d0 += d5;
		do
		{
			d6 = 3u;
			do
			{
				mem_write8(a0, d0);
				mem_write8(a1, d0);
				t1 = a2;
				a2++;
				a0++;
				mem_write8(a0, DATA8(t1));
				t2 = a3;
				a3++;
				a1++;
				mem_write8(a1, DATA8(t2));
				t3 = d6 - 1u;
				d6 = t3;
				a0++;
				a1++;
			} while (t3 != 0xFFFFu);
			t4 = d7 - 1u;
			d7 = t4;
			a0 += 0x78u;
			a1 += 0x78u;
		} while (t4 != 0xFFFFu);
	}
	d0_2 = (uint16_t)(0x480u - unk_06338C);
	t5 = unk_063340;
	t6 = t5 - d0_2;
	unk_063340 = (unk_063340 & 0xFFFF0000u) | (t6 & 0xFFFFu);
	unk_063340 = (unk_063340 & 0xFFFFu) | ((t6 >> 16 & 0xFFFFu) << 16u);
	if (t5 < d0_2)
	{
		unk_063340 = 0x1FFFFu;
		unk_0633D2++;
	}
	*p_d7 = d7;
	*p_a1 = a1;
}

void draw_screen_picture(uint8_t d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint16_t d6 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, d7 = 0;
	uint16_t t4 = 0, t5 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0;

	a0 = TILE_RAM + 0x25D0u;
	a1 = screen_picture_tiles_ADDRESS;
	a2 = screen_picture_colours_ADDRESS;
	d7 = 0xCu;
	do
	{
		d6 = 0x17u;
		do
		{
			t1 = a0;
			a0++;
			mem_write8(t1, DATA8(a1) + d5);
			t2 = a2;
			a2++;
			t3 = a0;
			a0++;
			mem_write8(t3, DATA8(t2));
			t4 = d6 - 1u;
			d6 = t4;
			a1++;
		} while (t4 != 0xFFFFu);
		t5 = d7 - 1u;
		d7 = t5;
		a0 += 0x50u;
	} while (t5 != 0xFFFFu);
	d7 = (d7 & ~0xFFu) | 0x15u;
	func_0091A4((uint8_t)d7, 0u);
	*p_d7 = d7;
	*p_a1 = a1;
}

void func_01FC20(uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t ignored = 0;
	uint32_t t1 = 0, t2 = 0;

	func_01E712();
	t1 = unk_063300 + unk_06330C;
	unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
	t2 = unk_063300 & 0x1FF00u;
	unk_063300 = (unk_063300 & 0xFFFF0000u) | (t2 & 0xFFFFu);
	unk_063300 = (unk_063300 & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
	func_01E732();
	func_01E708();
	switch (unk_0633D2)
	{
	case 0:
		func_01FCAE();
		break;
	case 1:
		func_01FD06();
		break;
	case 2:
		func_01FD16();
		break;
	case 3:
		func_01FD54();
		break;
	case 4:
		func_01FD6A();
		break;
	case 5:
		func_01FDAA();
		break;
	}
	unk_0633CC = TILE_RAM + 0x2000u;
	func_01E9C2(&ignored, p_d5, p_d7);
	func_01E728();
	func_01ECAA();
	unk_062001 |= 0x80u;
	unk_062051 |= 0x80u;
	unk_0620A1 |= 0x80u;
	unk_0620F1 |= 0x80u;
}

void func_01FCAE(void)
{
	uint32_t t1 = 0;

	unk_063308 = 0u;
	if (unk_0633D0 == 0x14u)
	{
		if (unk_063300 < 0xA200u)
			return;
		func_01FCEA();
		return;
	}
	if ((unk_063300 & 0x20000u) == 0u)
		return;
	t1 = unk_063300 & 0x1FF00u;
	unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
	unk_0633D0++;
}

void func_01FCEA(void)
{
	unk_063308 = (unk_063300 & 0x700u) << 5;
	unk_0633D0 = 0u;
	unk_0633D2++;
}

void func_01FD06(void)
{
	if (unk_063300 >= 0x3A200u)
	{
		unk_0633D2++;
		return;
	}
}

void func_01FD16(void)
{
	unk_063308 = 0u;
	if (unk_0633D0 == 0x14u)
	{
		if (unk_063300 >= 0x3A200u)
		{
			func_01FCEA();
			return;
		}
		return;
	}
	if (unk_063300 < 0x50000u)
		return;
	unk_063300 = 0x30000u;
	unk_0633D0++;
}

void func_01FD54(void)
{
	if (unk_063300 < 0x6A200u)
		return;
	unk_063308 = 0u;
	unk_0633D2++;
}

void func_01FD6A(void)
{
	unk_063308 = 0u;
	if (unk_0633D0 == 0x14u)
	{
		if (unk_063300 >= 0x6A200u)
		{
			func_01FCEA();
			return;
		}
		func_01FDAA();
		return;
	}
	if (unk_063300 < 0x80000u)
		return;
	unk_063300 = 0x60000u;
	unk_0633D0++;
}

void func_01FDAA(void)
{
	unk_063308 = 0u;
	if (unk_063300 < 0xA0000u)
		return;
	unk_063300 = 0x80000u;
}
