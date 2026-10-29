/**
 *    Name:        video/texts.c
 *    Description: the texts: from the program's tables of texts into the fixed layer, big characters, numbers
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void print_demo_text(uint16_t d7)
{
	uint32_t a6 = 0;

	a6 = demo_texts_ADDRESS;
	func_001EB2(d7, a6);
}

void print_test_text(uint16_t d7)
{
	uint32_t a6 = 0;

	a6 = test_mode_texts_ADDRESS;
	func_001EB2(d7, a6);
}

void print_game_text(uint16_t d7)
{
	uint32_t a6 = 0;

	a6 = game_texts_ADDRESS;
	func_001EB2(d7, a6);
}

void func_001EB2(uint16_t d7, uint32_t a6)
{
	uint8_t d6 = 0, d7_2 = 0;
	uint32_t a4 = 0, a6_2 = 0;

	d7 = (uint16_t)((uint32_t)d7 << 2);
	if ((d7 & 0x200u) != 0u)
	{
		a6_2 = mem_read32(a6 + (d7 & 0x1FFu));
		d7_2 = unk_06007A;
		for (;;)
		{
			a4 = mem_read32(a6_2);
			a6_2 += 4u;
			for (;;)
			{
				d6 = mem_read8(a6_2);
				a6_2++;
				if (d6 == 0x3Fu)
					return;
				if (d6 == 0x2Fu)
					break;
				mem_write8(a4, d7_2);
				a4++;
				mem_write8(a4, 0x10u);
				a4++;
			}
		}
	}
	a6_2 = mem_read32(a6 + (int16_t)d7);
	d7_2 = unk_06007A;
	for (;;)
	{
		a4 = mem_read32(a6_2);
		a6_2 += 4u;
		for (;;)
		{
			d6 = mem_read8(a6_2);
			a6_2++;
			if (d6 == 0x3Fu)
				return;
			if (d6 == 0x2Fu)
				break;
			mem_write8(a4, d7_2);
			a4++;
			mem_write8(a4, d6 - 0x30u);
			a4++;
		}
	}
}

void func_001F0A(uint16_t d7)
{
	unk_06007A = TABLE8(text_colours, (uint32_t)(int16_t)d7);
}

void func_001F2A(uint16_t d7)
{
	unk_06007B = TABLE8(text_colours, (uint32_t)(int16_t)d7);
}

uint32_t func_001F3A(uint32_t d4, uint32_t d7)
{
	uint32_t a4 = 0, d4_2 = 0;

	if (unk_0600A3 == 0u)
		return d4;
	d4_2 = d7;
	if ((d4_2 & 1u) != 0u)
	{
		a4 = unk_060106_ADDRESS;
		func_001F92(a4);
	}
	if ((d4_2 & 2u) != 0u)
	{
		a4 = unk_06010E_ADDRESS;
		func_001F92(a4);
	}
	if ((d4_2 & 4u) != 0u)
	{
		a4 = unk_060116_ADDRESS;
		func_001F92(a4);
	}
	if ((d4_2 & 8u) != 0u)
	{
		a4 = unk_06011E_ADDRESS;
		func_001F92(a4);
	}
	func_001FB8((uint8_t)d4_2);
	return d4_2;
}

void func_001F92(uint32_t a4)
{
	uint32_t carry = 0, extend = 0;
	uint16_t d7 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	a5 = func_002032_ADDRESS;
	d7 = 1u;
	extend = 0u;
	do
	{
		a5--;
		t1 = DATA8(a5);
		a4--;
		t2 = mem_read8(a4);
		t3 = m68k_abcd(t2, t1, extend);
		carry = m68k_abcd_cy(t2, t1, extend);
		extend = carry;
		mem_write8(a4, t3);
		t4 = d7 - 1u;
		d7 = t4;
	} while (t4 != 0xFFFFu);
	d7 = mem_read16(a4);
	a6 = unk_060076_ADDRESS;
	if (unk_060076 < d7)
		unk_060076 = d7;
}

void func_001FB8(uint8_t d4)
{
	if ((d4 & 1u) != 0u)
		func_001FEA();
	if ((d4 & 2u) != 0u)
		func_001FF8();
	if ((d4 & 4u) != 0u)
		func_002006();
	if ((d4 & 8u) != 0u)
		func_002014();
}

void func_001FEA(void)
{
	uint32_t a4 = 0, a6 = 0;

	a6 = unk_060104_ADDRESS;
	a4 = TILE_RAM + 0x1A4u;
	func_002032(a4, a6);
}

void func_001FF8(void)
{
	uint32_t a4 = 0, a6 = 0;

	a6 = unk_06010C_ADDRESS;
	a4 = TILE_RAM + 0x1B6u;
	func_002032(a4, a6);
}

void func_002006(void)
{
	uint32_t a4 = 0, a6 = 0;

	a6 = unk_060114_ADDRESS;
	a4 = TILE_RAM + 0x1C8u;
	func_002032(a4, a6);
}

void func_002014(void)
{
	uint32_t a4 = 0, a6 = 0;

	a6 = unk_06011C_ADDRESS;
	a4 = TILE_RAM + 0x1DAu;
	func_002032(a4, a6);
}

void func_002022(void)
{
	uint32_t a4 = 0, a6 = 0;

	a6 = unk_060076_ADDRESS;
	a4 = TILE_RAM + 0x1C2u;
	func_002032(a4, a6);
}

void func_002032(uint32_t a4, uint32_t a6)
{
	uint8_t d6 = 0;

	if (mem_read8(a6) >> 4 != 0u)
	{
		d6 = mem_read8(a6) >> 4;
		a4 = func_002090(d6, a4);
		d6 = mem_read8(a6) & 0xFu;
		a4 = func_002090(d6, a4);
		d6 = mem_read8(a6 + 1u) >> 4;
		a4 = func_002090(d6, a4);
		d6 = mem_read8(a6 + 1u) & 0xFu;
		func_002090(d6, a4);
		return;
	}
	a4 = func_00208C(a4);
	if ((mem_read8(a6) & 0xFu) != 0u)
	{
		d6 = mem_read8(a6) & 0xFu;
		a4 = func_002090(d6, a4);
		d6 = mem_read8(a6 + 1u) >> 4;
		a4 = func_002090(d6, a4);
		d6 = mem_read8(a6 + 1u) & 0xFu;
		func_002090(d6, a4);
		return;
	}
	a4 = func_00208C(a4);
	if (mem_read8(a6 + 1u) >> 4 != 0u)
	{
		d6 = mem_read8(a6 + 1u) >> 4;
		a4 = func_002090(d6, a4);
		d6 = mem_read8(a6 + 1u) & 0xFu;
		func_002090(d6, a4);
		return;
	}
	a4 = func_00208C(a4);
	d6 = mem_read8(a6 + 1u) & 0xFu;
	func_002090(d6, a4);
}

uint32_t func_00208C(uint32_t a4)
{
	uint8_t d6 = 0;

	d6 = 0x10u;
	return func_002090(d6, a4);
}

uint32_t func_002090(uint8_t d6, uint32_t a4)
{
	mem_write8(a4, 0u);
	a4++;
	mem_write8(a4, d6);
	a4++;
	return a4;
}

void func_002098(uint8_t d7)
{
	if ((d7 & 1u) != 0u)
		unk_060104 = 0u;
	if ((d7 & 2u) != 0u)
		unk_06010C = 0u;
	if ((d7 & 4u) != 0u)
		unk_060114 = 0u;
	if ((d7 & 8u) != 0u)
		unk_06011C = 0u;
	if ((d7 & 0x10u) != 0u)
		unk_060076 = 0u;
}

void func_0020D6(uint32_t a4, uint32_t a5)
{
	uint8_t d6 = 0;

	for (;;)
	{
		d6 = mem_read8(a5);
		a5++;
		if (d6 == 0x3Fu)
			break;
		mem_write8(a4, 0u);
		a4++;
		mem_write8(a4, d6 - 0x30u);
		a4++;
	}
}

void func_002102(uint8_t d7)
{
	uint32_t a4 = 0, a5 = 0;

	if ((d7 & 1u) == 0u)
	{
		a5 = table_loaded_by_lea_0020EC_ADDRESS;
		a4 = TILE_RAM + 0x11Cu;
		func_0020D6(a4, a5);
		a5 = 0x20F0u;
		a4 = TILE_RAM + 0x12Eu;
		func_0020D6(a4, a5);
		a5 = 0x20F4u;
		a4 = TILE_RAM + 0x140u;
		func_0020D6(a4, a5);
		a5 = 0x20F8u;
		a4 = TILE_RAM + 0x152u;
		func_0020D6(a4, a5);
		return;
	}
	if ((d7 & 2u) != 0u)
	{
		a5 = 0x20FCu;
		a4 = TILE_RAM + 0x138u;
		func_0020D6(a4, a5);
		func_002022();
	}
	if ((d7 & 1u) == 0u)
	{
		a5 = table_loaded_by_lea_0020EC_ADDRESS;
		a4 = TILE_RAM + 0x11Cu;
		func_0020D6(a4, a5);
		a5 = 0x20F0u;
		a4 = TILE_RAM + 0x12Eu;
		func_0020D6(a4, a5);
		return;
	}
	a5 = table_loaded_by_lea_0020EC_ADDRESS;
	a4 = TILE_RAM + 0x11Cu;
	func_0020D6(a4, a5);
	a5 = 0x20F0u;
	a4 = TILE_RAM + 0x12Eu;
	func_0020D6(a4, a5);
	a5 = 0x20F4u;
	a4 = TILE_RAM + 0x140u;
	func_0020D6(a4, a5);
	a5 = 0x20F8u;
	a4 = TILE_RAM + 0x152u;
	func_0020D6(a4, a5);
}

void unreached_00218A(void)
{
	lost_stack(0x00218Au);
}

void func_0022AA(uint16_t d7)
{
	uint8_t d6 = 0, d7_2 = 0;
	uint32_t a4 = 0, a6 = 0;

	a6 = 0x2F36u;
	d7 = (uint16_t)((uint32_t)d7 << 2);
	if ((d7 & 0x200u) != 0u)
	{
		a6 = DATA32(a6 + (d7 & 0x1FFu));
		for (;;)
		{
			a4 = mem_read32(a6);
			a6 += 4u;
			d6 = mem_read8(a6);
			a6++;
			for (;;)
			{
				d7_2 = mem_read8(a6);
				a6++;
				if (d7_2 == 0x3Fu)
					return;
				if (d7_2 == 0x2Fu)
					break;
				mem_write8(a4, d6);
				a4++;
				mem_write8(a4, 0x10u);
				a4++;
			}
		}
	}
	a6 = mem_read32(a6 + (int16_t)d7);
	for (;;)
	{
		a4 = mem_read32(a6);
		a6 += 4u;
		d6 = mem_read8(a6);
		a6++;
		for (;;)
		{
			d7_2 = mem_read8(a6);
			a6++;
			if (d7_2 == 0x3Fu)
				return;
			if (d7_2 == 0x2Fu)
				break;
			mem_write8(a4, d6);
			a4++;
			mem_write8(a4, d7_2 - 0x30u);
			a4++;
		}
	}
}

void func_0022FE(void)
{
}

uint32_t func_002300(uint16_t d7)
{
	uint8_t d6 = 0, d7_2 = 0;
	uint16_t d3 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0, d4 = 0;
	uint16_t t1 = 0, t2 = 0;

	a6 = TABLE32(indexed_table_of_32_bit_values_0031F2, (uint32_t)(int16_t)((uint32_t)d7 << 2));
	d3 = mem_read16(a6);
	a6 += 2u;
	a5 = a6 + (int16_t)(d3 * 6u);
	d3 = (uint16_t)((d3 & ~0xFFu) | (uint8_t)(d3 - 1u));
	do
	{
		a4 = mem_read32(a6);
		a6 += 4u;
		d4 = mem_read8(a6);
		d4 = (uint8_t)(d4 - 1u);
		a6++;
		d7_2 = mem_read8(a6);
		a6++;
		do
		{
			d6 = mem_read8(a5);
			mem_write8(a4, d7_2);
			a4++;
			mem_write8(a4, d6);
			t1 = d4 - 1u;
			d4 = t1;
			a5++;
			a4++;
		} while (t1 != 0xFFFFu);
		t2 = d3 - 1u;
		d3 = t2;
	} while (t2 != 0xFFFFu);
	return d4;
}

void func_002334(void)
{
}

void func_002336(uint32_t d7, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6)
{
	uint32_t d4 = *p_d4;
	uint32_t d5 = *p_d5;
	uint32_t d6 = 0;

	d6 = 0u;
	do
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) != 0u)
			func_002368((uint16_t)d6, (uint8_t)d7, p_d1, &d4, &d5);
		d6 = (uint8_t)(d6 + 1u);
	} while (d6 < 4u);
	if ((d7 & 0x80u) == 0u && (d7 & 0x40u) != 0u)
	{
		d4 = (uint8_t)d7;
		d4 = d4 & 0x1Fu;
		func_001FB8((uint8_t)d4);
	}
	*p_d4 = d4;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d6 = d6;
}

void func_002368(uint16_t d6, uint8_t d7, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5)
{
	uint32_t d4 = *p_d4;
	uint16_t d5 = 0;
	uint32_t a5 = 0, a6 = 0;

	a6 = 0x32C2u;
	d5 = (uint16_t)((uint32_t)d6 << 4);
	if ((d7 & 0x40u) != 0u)
	{
		a5 = DATA32(a6 + d5);
		func_0023A4(d5, d6, d7, a5, a6, p_d1, &d4);
	}
	if ((d7 & 0x10u) != 0u)
	{
		a5 = DATA32(a6 + 8u + d5);
		d4 = func_0023B2(d4, d6, d7, a5);
	}
	if ((d7 & 0x20u) != 0u)
	{
		a5 = DATA32(a6 + 0xCu + d5);
		d4 = func_00245A(d6, d7, a5);
	}
	*p_d4 = d4;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
}

void func_0023A4(uint16_t d5, uint16_t d6, uint8_t d7, uint32_t a5, uint32_t a6, uint32_t *p_d1, uint32_t *p_d4)
{
	uint32_t d4 = *p_d4;
	uint32_t d0 = 0;

	d0 = func_0024A6(0u, d6);
	*p_d1 = func_002546((uint8_t)d0, d7, a5);
	d4 = func_002584((uint8_t)d0, d4, d5, d6, d7, a6);
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
}

uint32_t func_0023B2(uint32_t d4, uint16_t d6, uint8_t d7, uint32_t a5)
{
	uint16_t d3 = 0;
	uint32_t a4 = 0, d0 = 0, d4_2 = 0;

	d0 = func_0024A6(0u, d6);
	func_0024B6((uint8_t)d0, a5);
	if ((d7 & 0x80u) != 0u)
		return d4;
	d4_2 = (d4 & ~0xFFFFu) | d6;
	d4_2 = (d4_2 & ~0xFFFFu) | (uint16_t)(d4_2 << 3);
	d4 = (d4_2 & ~0xFFFFu) | RAM16(unk_060100_ADDRESS + (uint16_t)d4_2);
	d3 = (uint8_t)d4;
	d3 = (uint16_t)((d3 & 0xFu) << 1);
	mem_write8(a5 + 4u, d0);
	mem_write8(a5 + 0x84u, d0);
	mem_write8(a5 + 5u, rom_0033A2[d3]);
	mem_write8(a5 + 0x85u, rom_0033A3[d3]);
	d3 = (uint8_t)d4;
	d3 = (d3 & ~0xFu) >> 3;
	mem_write8(a5 + 2u, d0);
	mem_write8(a5 + 0x82u, d0);
	a4 = rom_0033B6_ADDRESS;
	mem_write8(a5 + 3u, rom_0033B6[d3]);
	mem_write8(a5 + 0x83u, rom_0033B7[d3]);
	if (d3 == 0u && (d4 & 0xF00u) != 0u)
	{
		mem_write8(a5 + 3u, 0x10u);
		mem_write8(a5 + 0x83u, 0x20u);
	}
	d3 = (d4 & 0xF00u) >> 7;
	mem_write8(a5, d0);
	mem_write8(a5 + 0x80u, d0);
	a4 += 0x14u;
	mem_write8(a5 + 1u, DATA8(a4 + d3));
	mem_write8(a5 + 0x81u, DATA8(a4 + 1u + d3));
	return d4;
}

uint32_t func_00245A(uint16_t d6, uint8_t d7, uint32_t a5)
{
	uint32_t a4 = 0, d0 = 0, d4 = 0;
	uint16_t t1 = 0;

	d0 = func_0024A6(0u, d6);
	d4 = func_002506((uint8_t)d0, a5);
	if ((d7 & 0x80u) != 0u)
		return d4;
	a4 = 0x334Au + unk_060106((uint16_t)((uint32_t)d6 << 3)) * 8u;
	d4 = 3u;
	do
	{
		mem_write8(a5, d0);
		mem_write8(a5 + 0x80u, d0);
		mem_write8(a5 + 0x81u, DATA8(a4 + 4u));
		mem_write8(a5 + 1u, DATA8(a4));
		t1 = d4 - 1u;
		d4 = t1;
		a4++;
		a5 += 2u;
	} while (t1 != 0xFFFFu);
	return d4;
}

uint32_t func_0024A6(uint32_t d0, uint16_t d6)
{
	uint32_t d0_2 = 0;

	d0_2 = (d0 & ~0xFFu) | rom_001F1B[d6];
	d0_2 = d0_2 | 1u;
	return d0_2;
}

void func_0024B6(uint8_t d0, uint32_t a5)
{
	mem_write8(a5, d0);
	mem_write8(a5 + 2u, d0);
	mem_write8(a5 + 4u, d0);
	mem_write8(a5 + 0x80u, d0);
	mem_write8(a5 + 0x82u, d0);
	mem_write8(a5 + 0x84u, d0);
	mem_write8(a5 + 1u, 0x5Eu);
	mem_write8(a5 + 3u, 0x5Eu);
	mem_write8(a5 + 5u, 0x5Eu);
	mem_write8(a5 + 0x81u, 0x6Eu);
	mem_write8(a5 + 0x83u, 0x6Eu);
	mem_write8(a5 + 0x85u, 0x6Eu);
	mem_write8(a5 - 2u, d0);
	mem_write8(a5 + 0x7Eu, d0);
	mem_write8(a5 - 1u, 0x1Au);
	mem_write8(a5 + 0x7Fu, 0x2Au);
}

uint32_t func_002506(uint8_t d0, uint32_t a5)
{
	uint32_t d4 = 0;

	d4 = 0u;
	do
	{
		mem_write8(a5 + (int16_t)d4, d0);
		mem_write8(a5 + 1u + (int16_t)d4, 0x5Eu);
		d4 = (uint16_t)(d4 + 0x80u);
		mem_write8(a5 + (int16_t)d4, d0);
		mem_write8(a5 + 1u + (int16_t)d4, 0x6Eu);
		d4 = (uint16_t)(d4 - 0x80u);
		d4 = (d4 & ~0xFFu) | (uint8_t)(d4 + 2u);
	} while ((uint8_t)d4 < 8u);
	mem_write8(a5 + (int16_t)d4, d0);
	mem_write8(a5 + 1u + (int16_t)d4, 0x1Du);
	d4 = (uint16_t)(d4 + 0x80u);
	mem_write8(a5 + (int16_t)d4, d0);
	mem_write8(a5 + 1u + (int16_t)d4, 0x2Du);
	return d4;
}

uint32_t func_002546(uint8_t d0, uint8_t d7, uint32_t a5)
{
	uint8_t d2 = 0;
	uint32_t a4 = 0, d1 = 0;

	a4 = 0x3302u;
	d1 = 0u;
	for (;;)
	{
		d2 = DATA8(a4);
		a4++;
		if (d2 == 0x3Fu)
			break;
		if (d2 != 0x2Fu)
		{
			if ((d7 & 0x80u) != 0u)
				d2 = 0x5Eu;
			mem_write8(a5 + (int16_t)d1, d0);
			mem_write8(a5 + 1u + (int16_t)d1, d2);
			d1 = (uint16_t)(d1 + 2u);
			continue;
		}
		d1 = 0u;
		a5 += 0x80u;
	}
	return d1;
}

uint32_t func_002584(uint8_t d0, uint32_t d4, uint16_t d5, uint16_t d6, uint8_t d7, uint32_t a6)
{
	uint32_t a4 = 0, a5 = 0;

	if ((d7 & 0x80u) == 0u)
	{
		a5 = mem_read32(a6 + 4u + d5);
		d4 = LINKED(d4, d6);
		d4 = LINKED(d4, (uint16_t)(d4 << 2));
		a4 = rom_00332A[(uint16_t)d4 / 4u];
		mem_write8(a5, d0);
		mem_write8(a5 + 2u, d0);
		mem_write8(a5 + 0x80u, d0);
		mem_write8(a5 + 0x82u, d0);
		mem_write8(a5 + 1u, mem_read8(a4));
		mem_write8(a5 + 3u, mem_read8(a4 + 1u));
		mem_write8(a5 + 0x81u, mem_read8(a4 + 2u));
		mem_write8(a5 + 0x83u, mem_read8(a4 + 3u));
	}
	return d4;
}

void unreached_0025C8(void)
{
	uint8_t d0 = 0, d2 = 0;
	uint16_t d1 = 0;
	uint32_t a4 = 0, a5 = 0;

	a4 = 0x33DEu;
	a5 = TILE_RAM + 0x138u;
	d0 = 0x61u;
	d1 = 0u;
	for (;;)
	{
		d2 = DATA8(a4);
		a4++;
		if (d2 == 0x3Fu)
			break;
		if (d2 != 0x2Fu)
		{
			mem_write8(a5 + (int16_t)d1, d0);
			mem_write8(a5 + 1u + (int16_t)d1, d2);
			d1 += 2u;
			continue;
		}
		d1 = 0u;
		a5 += 0x80u;
	}
}

void func_002604(void)
{
	uint8_t d6 = 0, d7 = 0;
	uint32_t a4 = 0, a6 = 0;

	a6 = rom_003402[unk_060121];
	d7 = unk_06007A;
	for (;;)
	{
		a4 = mem_read32(a6);
		a6 += 4u;
		for (;;)
		{
			d6 = mem_read8(a6);
			a6++;
			if (d6 == 0x3Fu)
				return;
			if (d6 == 0x2Fu)
				break;
			mem_write8(a4, d7);
			a4++;
			mem_write8(a4, d6 - 0x30u);
			a4++;
		}
	}
}

void func_00263C(uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d4 = *p_d4;
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d6_2 = 0;

	d6 = d7 & 3u;
	unk_06007A = rom_001F1B[d6];
	unk_06007A |= 1u;
	a6 = unk_060100_ADDRESS + (uint16_t)((uint32_t)d6 << 3);
	d6_2 = (uint8_t)d7;
	d6_2 = d6_2 & 0x3Cu;
	switch (d6_2)
	{
	case 0:
		func_002688((uint8_t)d7, a6, &d4, &d5, &d6_2);
		break;
	case 4:
		func_0026A0((uint8_t)d7, a6, &d4, &d5, &d6_2);
		break;
	case 8:
		func_0026E4(a6, &d4, &d5, &d6_2, &d7);
		break;
	case 12:
		func_002746((uint8_t)d7, a6, &d4, &d5, &d6_2);
		break;
	}
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = d6_2;
	*p_d7 = (*p_d7 & 0xFFFFFF00u) | (d7 & 0xFFu);
}

void func_002688(uint8_t d7, uint32_t a6, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6)
{
	uint32_t d4 = 0, d5 = 0;

	if ((mem_read8(a6 + 7u) & 1u) == 0u)
		mem_write8(a6 + 7u, 1u);
	*p_d6 = 0u;
	print_text_at(d7, &d4, &d5, p_d6);
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_0026A0(uint8_t d7, uint32_t a6, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6)
{
	uint32_t d4 = *p_d4;
	uint32_t d5 = *p_d5;
	uint32_t None = *p_d6;
	uint32_t d6 = 0;
	uint8_t t1 = 0;

	if ((mem_read8(a6 + 7u) & 2u) != 0u)
	{
		d6 = (uint8_t)unk_0600A4;
		t1 = d6 & 0xFu;
		d6 = t1;
		if (t1 == 0u)
		{
			d6 = 2u;
			if (unk_0600B8 != 0u)
				d6 = 8u;
			if ((unk_0600A4 & 0x10u) != 0u)
				d6 = (uint8_t)(d6 + 1u);
			print_text_at(d7, &d4, &d5, &d6);
		}
	}
	else
	{
		mem_write8(a6 + 7u, 2u);
		d6 = 2u;
		if (unk_0600B8 != 0u)
			d6 = 8u;
		if ((unk_0600A4 & 0x10u) != 0u)
			d6 = (uint8_t)(d6 + 1u);
		print_text_at(d7, &d4, &d5, &d6);
	}
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = d6;
}

void func_0026E4(uint32_t a6, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d4 = *p_d4;
	uint8_t d5 = (uint8_t)*p_d5;
	uint32_t None = *p_d6;
	uint8_t d7 = (uint8_t)*p_d7;
	uint32_t d6 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	if ((mem_read8(a6 + 7u) & 4u) != 0u)
	{
		d6 = (uint8_t)unk_0600A4;
		t1 = d6 & 7u;
		d6 = t1;
		if (t1 == 0u)
		{
			d6 = (uint8_t)(4u + (((uint8_t)unk_0600A4 & 0x18u) >> 3));
			print_text_at(d7, &d4, &ignored, &d6);
			t2 = (uint8_t)unk_0600A4 & 0x18u;
			d5 = t2;
			if (t2 == 0u)
			{
				mem_write8(a6 + 7u, mem_read8(a6 + 7u) + 0x20u);
				if ((int8_t)mem_read8(a6 + 7u) < 0)
				{
					mem_write8(a6 + 7u, 0u);
					d7 &= 3u;
					unk_0600B3 &= ~shl32(1u, (int)(d7));
				}
			}
		}
	}
	else
	{
		mem_write8(a6 + 7u, 4u);
		d6 = (uint8_t)(4u + (((uint8_t)unk_0600A4 & 0x18u) >> 3));
		print_text_at(d7, &d4, &ignored, &d6);
		t2 = (uint8_t)unk_0600A4 & 0x18u;
		d5 = t2;
		if (t2 == 0u)
		{
			mem_write8(a6 + 7u, mem_read8(a6 + 7u) + 0x20u);
			if ((int8_t)mem_read8(a6 + 7u) < 0)
			{
				mem_write8(a6 + 7u, 0u);
				d7 &= 3u;
				unk_0600B3 &= ~shl32(1u, (int)(d7));
			}
		}
	}
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
	*p_d6 = d6;
	*p_d7 = (*p_d7 & 0xFFFFFF00u) | d7;
}

void func_002746(uint8_t d7, uint32_t a6, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6)
{
	uint16_t d4 = (uint16_t)*p_d4;
	uint8_t d5 = (uint8_t)*p_d5;
	uint32_t d4_2 = 0, d5_2 = 0;

	if ((mem_read8(a6 + 7u) & 8u) != 0u)
		return;
	mem_write8(a6 + 7u, 2u);
	*p_d6 = 1u;
	print_text_at(d7, &d4_2, &d5_2, p_d6);
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4_2 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5_2 & 0xFFu);
}

void print_text_at(uint8_t d7, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6)
{
	uint16_t d6 = (uint16_t)*p_d6;
	uint8_t d5 = 0;
	uint16_t d4 = 0, d6_2 = 0;
	uint32_t a4 = 0, a5 = 0;

	a5 = positioned_texts[d6 & 0x3FFFu];
	d4 = (uint16_t)(((uint8_t)d7 & 3u) << 2);
	a4 = text_layer_places[d4 / 4u];
	d4 = unk_06007A;
	for (;;)
	{
		d6_2 = mem_read16(a5);
		a5 += 2u;
		for (;;)
		{
			d5 = mem_read8(a5);
			a5++;
			if (d5 == 0x3Fu)
			{
				*p_d4 = (*p_d4 & 0xFFFF0000u) | d4;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
				*p_d6 = (*p_d6 & 0xFFFF0000u) | d6_2;
				return;
			}
			if (d5 == 0x2Fu)
				break;
			mem_write8(a4 + (int16_t)d6_2, (uint8_t)d4);
			mem_write8(a4 + 1u + (int16_t)d6_2, d5);
			d6_2 += 2u;
		}
	}
}

void draw_big_character(uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d6 = (uint16_t)*p_d6;
	uint8_t d7 = (uint8_t)*p_d7;
	uint16_t d4 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0, d5 = 0, d7_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	a4 = big_font_place;
	a6 = big_font_tiles_ADDRESS;
	a5 = big_font_ADDRESS + (uint16_t)((d7 & 0x1Fu) * 0x24u);
	d4 = 8u;
	do
	{
		d5 = 3u;
		d7_2 = 0u;
		d7_2 = func_00280C(d7_2);
		do
		{
			d6 = ((uint16_t)IN_PAGE(d6, DATA8(a5)) >> 4) & 0xFu;
			mem_write8(a4, d7_2);
			a4++;
			mem_write8(a4, DATA8(a6 + d6));
			d6 = DATA8(a5) & 0xFu;
			a4++;
			mem_write8(a4, d7_2);
			a4++;
			mem_write8(a4, DATA8(a6 + d6));
			t1 = d5 - 1u;
			d5 = t1;
			a4++;
			a5++;
		} while (t1 != 0xFFFFu);
		t2 = d4 - 1u;
		d4 = t2;
		a4 += 0x70u;
	} while (t2 != 0xFFFFu);
	*p_d5 = d5;
	*p_d6 = (*p_d6 & 0xFFFF0000u) | d6;
	*p_d7 = d7_2;
	*p_a5 = a5;
}

uint32_t func_00280C(uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = text_colours[d7];
	return d7_2;
}

void func_002818(uint8_t d7, uint32_t *p_d4, uint32_t *p_d6)
{
	uint32_t d4 = *p_d4;
	uint32_t d6 = *p_d6;
	uint32_t a4 = 0, a5 = 0, a6 = 0, d4_2 = 0, d6_2 = 0;

	a6 = indexed_table_of_32_bit_values_00375C_ADDRESS;
	a5 = indexed_table_of_8_bit_values_002884_ADDRESS;
	if ((d7 & 0x80u) != 0u)
	{
		a6 = DATA32(a6 + (uint16_t)((d7 & 0x3Fu) << 2));
		for (;;)
		{
			a4 = mem_read32(a6);
			a6 += 5u;
			for (;;)
			{
				d6 = (d6 & ~0xFFu) | mem_read8(a6);
				a6++;
				if ((uint8_t)d6 == 0x3Fu)
				{
					*p_d6 = d6;
					return;
				}
				if ((uint8_t)d6 == 0x2Fu)
					break;
				a4 = func_002908(a4);
			}
		}
	}
	a6 = DATA32(a6 + (uint16_t)((d7 & 0x3Fu) << 2));
	for (;;)
	{
		a4 = mem_read32(a6);
		a6 += 4u;
		d4_2 = mem_read8(a6);
		a6++;
		d4_2 = func_00291E(d4_2);
		for (;;)
		{
			d6_2 = mem_read8(a6);
			a6++;
			if (d6_2 == 0x3Fu)
			{
				*p_d4 = d4_2;
				*p_d6 = d6_2;
				return;
			}
			if (d6_2 == 0x2Fu)
				break;
			d6_2 = (uint8_t)(d6_2 - 0x30u);
			a4 = func_002862((uint8_t)d4_2, (uint16_t)d6_2, a4, a5);
		}
	}
}

uint32_t func_002862(uint8_t d4, uint16_t d6, uint32_t a4, uint32_t a5)
{
	if (d6 == 0xFEu)
	{
		a4 += 2u;
		return a4;
	}
	d6 = (uint16_t)((uint32_t)d6 << 1);
	mem_write8(a4 + 0x80u, d4);
	mem_write8(a4 + 0x81u, mem_read8(a5 + 1u + d6));
	mem_write8(a4, d4);
	a4++;
	mem_write8(a4, mem_read8(a5 + d6));
	a4++;
	return a4;
}

uint32_t func_002908(uint32_t a4)
{
	mem_write8(a4 + 0x80u, 0u);
	mem_write8(a4 + 0x81u, 0x10u);
	mem_write8(a4, 0u);
	a4++;
	mem_write8(a4, 0x10u);
	a4++;
	return a4;
}

uint32_t func_00291E(uint32_t d4)
{
	uint32_t d4_2 = 0;

	d4_2 = text_colours[d4];
	return d4_2;
}
