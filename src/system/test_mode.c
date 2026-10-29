/**
 *    Name:        system/test_mode.c
 *    Description: the exceptions' handler and the test mode's pages: the RAM and ROM check, the mask ROM check, the inputs, the sounds, the DIP switches
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void func_00193E(void)
{
	for (;;)
	{
	}
}

void func_001942(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_00196C();
		return;
	case 1:
		func_001984();
		return;
	case 2:
		func_0019AE();
		return;
	case 3:
		func_0019E0();
		return;
	case 4:
		func_001A5A();
		return;
	}
}

void func_00196C(void)
{
	uint16_t d7 = 0;

	unk_060082++;
	d7 = 7u;
	func_004164(d7);
	unk_060007++;
}

void func_001984(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (unk_060082 == 0u)
	{
		d7 = 8u;
		func_0022AA(d7);
		a6 = 0xA07Eu;
		d7 = 0x20Fu;
		post_palette_request(d7, a6);
		unk_060007++;
	}
}

void func_0019AE(void)
{
	uint16_t d1 = 0, d7 = 0;
	uint32_t a0 = 0, d0 = 0;
	uint16_t t1 = 0;

	if (unk_060083 != 0u)
		return;
	d0 = 0u;
	d1 = 5u;
	a0 = unk_063500_ADDRESS;
	do
	{
		mem_write32(a0, d0);
		t1 = d1 - 1u;
		d1 = t1;
		a0 += 4u;
	} while (t1 != 0xFFFFu);
	unk_060082++;
	d7 = 0x1100u;
	func_004164(d7);
	unk_060007++;
}

void func_0019E0(void)
{
	uint16_t d1 = 0, d2 = 0, d4 = 0, d7 = 0;
	uint32_t a0 = 0, a6 = 0, d0 = 0;
	uint16_t t2 = 0, t3 = 0;
	uint32_t t1 = 0;

	if (unk_060082 != 0u)
		return;
	unk_060007++;
	unk_060004 = 0x80u;
	a0 = table_loaded_by_lea_001E34_ADDRESS;
	a6 = unk_063500_ADDRESS;
	d0 = 0u;
	d4 = 5u;
	do
	{
		d0 = d0 << 1;
		d7 = DATA16(a0);
		t1 = a6;
		a6 += 2u;
		a0 += 2u;
		if (d7 != mem_read16(t1))
			d0 |= 1u;
		t2 = d4 - 1u;
		d4 = t2;
	} while (t2 != 0xFFFFu);
	if (d0 == 0u)
	{
		d7 = 9u;
		func_0022AA(d7);
		return;
	}
	unk_060004 = 0u;
	d7 = 0xAu;
	func_0022AA(d7);
	d2 = 5u;
	d1 = 0xBu;
	do
	{
		if ((d0 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
		{
			d7 = (uint16_t)d1;
			func_0022AA(d7);
		}
		d1++;
		t3 = d2 - 1u;
		d2 = t3;
	} while (t3 != 0xFFFFu);
}

void func_001A5A(void)
{
	uint8_t t1 = 0;

	if (unk_060004 != 0u)
	{
		t1 = unk_060004;
		unk_060004 = t1 - 1u;
		if (t1 == 1u)
		{
			unk_060005++;
			unk_060007 = 0u;
		}
	}
	func_005DA4();
}

uint32_t func_001A7E(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7)
{
	uint32_t a0 = 0;

	a0 = unk_063500_ADDRESS;
	d7 = func_001A98(d4, d5, d6, d7, a0);
	d7 = func_001ADA(d4, d5, d6, d7, a0);
	d5 = func_001BD6(d4, d5, d6, d7, a0);
	unk_060082--;
	return d5;
}

uint32_t func_001A98(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	unk_063512 = 0u;
	unk_063510 = 0u;
	unk_063516 = 0u;
	unk_063514 = 0u;
	unk_063518 = 0u;
	unk_063519 = 3u;
	func_001B1C(d4, d5, d6, d7);
	d7_2 = (d7 & ~0xFFFFu) | unk_063510;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 + unk_063512);
	unk_063500 = d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | unk_063514;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 + unk_063516);
	unk_063502 = d7_2;
	return d7_2;
}

uint32_t func_001ADA(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	unk_063512 = 0u;
	unk_063510 = 0u;
	unk_063516 = 0u;
	unk_063514 = 0u;
	unk_063518 = 0x40u;
	unk_063519 = 0x43u;
	func_001B1C(d4, d5, d6, d7);
	d7_2 = (d7 & ~0xFFFFu) | unk_063510;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 + unk_063512);
	unk_063504 = d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | unk_063514;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 + unk_063516);
	unk_063506 = d7_2;
	return d7_2;
}

void func_001B1C(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7)
{
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a1 = 0, a2 = 0, d7_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	unk_06005A |= 0x20u;
	io_write8(SPRITE_CONTROL_140000, unk_06005A);
	unk_06350E = unk_063518;
	unk_063512 = 0u;
	unk_063510 = 0u;
	unk_063516 = 0u;
	unk_063514 = 0u;
	do
	{
		d0 = 0u;
		d7_2 = (d7 & ~0xFFu) | unk_06350E;
		io_write8(SPRITE_CONTROL_140003, d7_2);
		do
		{
			a1 = SPRITE_RAM;
			d1 = 0u;
			io_write8(SPRITE_CONTROL_140002, d0);
			do
			{
				a2 = a1 + (int16_t)d1;
				(void)mem_read8(a2);
				(void)mem_read8(a2);
				t1 = io_read8(SPRITE_CONTROL_140004);
				t2 = io_read8(SPRITE_CONTROL_140004);
				d4 = (d4 & ~0xFFu) | t2;
				t3 = io_read8(SPRITE_CONTROL_140005);
				t4 = io_read8(SPRITE_CONTROL_140005);
				d5 = (d5 & ~0xFFu) | t4;
				t5 = io_read8(SPRITE_CONTROL_140006);
				t6 = io_read8(SPRITE_CONTROL_140006);
				d6 = (d6 & ~0xFFu) | t6;
				t7 = io_read8(SPRITE_CONTROL_140007);
				t8 = io_read8(SPRITE_CONTROL_140007);
				d7_2 = (d7_2 & ~0xFFu) | t8;
				func_001D06(d4, d5, d6, d7_2);
				d1 += 4u;
			} while (d1 < 0x400u);
			carry = (uint8_t)(d0 + 1u) < d0;
			d0++;
		} while (carry == 0u);
		unk_06350E++;
		d7 = (d7_2 & ~0xFFu) | unk_063519;
	} while (unk_06350E <= (uint8_t)d7);
	unk_06005A &= 0xDFu;
	io_write8(SPRITE_CONTROL_140000, unk_06005A);
}

uint32_t func_001BD6(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a1 = 0, a2 = 0, d7_2 = 0;
	uint16_t t1 = 0;

	unk_06350E = 0u;
	unk_063512 = 0u;
	unk_063510 = 0u;
	unk_063516 = 0u;
	unk_063514 = 0u;
	do
	{
		d0 = 0u;
		d7 = (d7 & ~0xFFu) | unk_06350E;
		unk_060064 = d7;
		io_write8(TILES_106B00, unk_060064);
		unk_060065 = d7;
		io_write8(TILES_106E00, unk_060065);
		do
		{
			a1 = 0x100000u;
			d1 = 0u;
			io_write8(TILES_106C00, d0);
			io_write8(TILES_106C00, d0);
			io_write8(TILES_106C00, d0);
			unk_060058 |= 0x80u;
			io_write8(IO_0A0001, unk_060058);
			for (;;)
			{
				a2 = a1 + (int16_t)d1;
				do
				{
					d4 = (d4 & ~0xFFu) | mem_read8(a2);
				} while ((uint8_t)d4 != mem_read8(a2));
				do
				{
					d5 = (d5 & ~0xFFu) | mem_read8(a2 + 2u);
				} while ((uint8_t)d5 != mem_read8(a2 + 2u));
				do
				{
					d6 = (d6 & ~0xFFu) | mem_read8(a2 + 4u);
				} while ((uint8_t)d6 != mem_read8(a2 + 4u));
				do
				{
					d7 = (d7 & ~0xFFu) | mem_read8(a2 + 6u);
				} while ((uint8_t)d7 != mem_read8(a2 + 6u));
				func_001D06(d4, d5, d6, d7);
				d1 += 8u;
				if (d1 >= 0x7000u)
					break;
				d7_2 = (d7 & ~0xFFFFu) | d1;
				t1 = d7_2 & 0x1000u;
				d7 = (d7_2 & ~0xFFFFu) | t1;
				if (t1 == 0u)
					continue;
				d1 += 0x1000u;
			}
			unk_060058 &= 0x7Fu;
			io_write8(IO_0A0001, unk_060058);
			d0++;
		} while (d0 < 0x20u);
		unk_06350E += 0x44u;
	} while (unk_06350E != 0x10u);
	unk_063508 = unk_063510 + unk_063512;
	unk_06350A = unk_063514 + unk_063516;
	io_write8(TILES_106B00, 0u);
	unk_060064 = 0u;
	io_write8(TILES_106E00, 0u);
	unk_060065 = 0u;
	return d5;
}

void func_001D06(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7)
{
	uint8_t d3 = 0;
	uint16_t d2 = 0;
	uint32_t a6 = 0;

	d2 = 0u;
	a6 = unk_063510_ADDRESS;
	do
	{
		unk_06350F = 0u;
		d3 = (uint8_t)(uint16_t)(d2 + 1u);
		if ((d4 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			unk_06350F |= 1u;
		if ((d5 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			unk_06350F |= 2u;
		if ((d6 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			unk_06350F |= 4u;
		if ((d7 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			unk_06350F |= 8u;
		if ((d4 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			unk_06350F |= 0x10u;
		if ((d5 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			unk_06350F |= 0x20u;
		if ((d6 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			unk_06350F |= 0x40u;
		if ((d7 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			unk_06350F |= 0x80u;
		mem_write16(a6, mem_read16(a6) + unk_06350F);
		d2 += 2u;
		a6 += 2u;
	} while (d2 < 8u);
}

void unreached_001D9E(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7)
{
	uint8_t d3 = 0;
	uint16_t d2 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	d2 = 3u;
	a6 = unk_063510_ADDRESS;
	do
	{
		unk_06350F = 0u;
		d2 = (uint16_t)((uint32_t)d2 << 1);
		d3 = (uint8_t)(uint16_t)(d2 + 1u);
		if ((d7 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			unk_06350F |= 1u;
		if ((d6 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			unk_06350F |= 2u;
		if ((d5 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			unk_06350F |= 4u;
		if ((d4 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			unk_06350F |= 8u;
		if ((d7 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			unk_06350F |= 0x10u;
		if ((d6 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			unk_06350F |= 0x20u;
		if ((d5 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			unk_06350F |= 0x40u;
		if ((d4 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			unk_06350F |= 0x80u;
		mem_write16(a6, mem_read16(a6) + unk_06350F);
		t1 = (d2 >> 1) - 1u;
		d2 = t1;
		a6 += 2u;
	} while (t1 != 0xFFFFu);
}

void func_001E40(void)
{
}

void func_001E42(uint8_t d7)
{
	uint32_t a6 = 0, d1 = 0, d2 = 0;

	func_001E7C(&d1, &d2);
	if ((d7 & 1u) != 0u)
	{
		a6 = 0x100000u;
		func_001E82((uint8_t)d1, (uint8_t)d2, a6);
	}
	if ((d7 & 2u) != 0u)
	{
		a6 = TILE_RAM + 0x2000u;
		func_001E8A((uint8_t)d1, (uint8_t)d2, a6);
	}
	if ((d7 & 4u) != 0u)
	{
		a6 = TILE_RAM + 0x4000u;
		func_001E8A((uint8_t)d1, (uint8_t)d2, a6);
	}
	unk_060082--;
}

void func_001E7C(uint32_t *p_d1, uint32_t *p_d2)
{
	*p_d1 = 0u;
	*p_d2 = 0x10u;
}

void func_001E82(uint8_t d1, uint8_t d2, uint32_t a6)
{
	uint16_t d0 = 0;
	uint16_t t1 = 0;

	d0 = 0x7FFu;
	do
	{
		mem_write8(a6, d1);
		a6++;
		mem_write8(a6, d2);
		t1 = d0 - 1u;
		d0 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
}

void func_001E8A(uint8_t d1, uint8_t d2, uint32_t a6)
{
	uint16_t d0 = 0;
	uint16_t t1 = 0;

	d0 = 0xFFFu;
	do
	{
		mem_write8(a6, d1);
		a6++;
		mem_write8(a6, d2);
		t1 = d0 - 1u;
		d0 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
}
