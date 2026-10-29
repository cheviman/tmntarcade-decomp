/**
 *    Name:        scenes/demo.c
 *    Description: the demos' recorded inputs, the coins and the players' controls
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint32_t func_00467C(uint32_t d7)
{
	uint8_t d0 = 0;
	uint16_t d6 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	if (unk_0600A3 == 0u)
	{
		unk_06002C = unk_060028;
		unk_060028 = unk_060024;
		unk_060024 = (((uint32_t)unk_060048 << 16u) | unk_06004A);
		d7_2 = 3u;
		a6 = channel_records_ADDRESS;
		a0 = unk_060048_ADDRESS;
		do
		{
			d6 = (uint16_t)(d7_2 << 4);
			a1 = mem_read32(a6 + (int16_t)d6);
			a4 = mem_read32(a6 + 4u + (int16_t)d6);
			a3 = mem_read32(a6 + 8u + (int16_t)d6);
			a2 = mem_read32(a6 + 0xCu + (int16_t)d6);
			a5 = mem_read32(a1);
			t1 = mem_read8(a4);
			mem_write8(a4, t1 - 1u);
			if (t1 != 1u)
				mem_write8(a3, RAM8(unk_060048_ADDRESS + (uint32_t)(int16_t)d7_2));
			else
			{
				d0 = mem_read8(a5);
				a5++;
				mem_write8(a4, mem_read8(a5));
				unk_060066 = d0;
				d0 &= 0x7Fu;
				mem_write8(a3, d0);
				RAM8(unk_060048_ADDRESS + (uint32_t)(int16_t)d7_2) = d0;
				mem_write32(a1, a5 + 1u);
				switch (a2)
				{
				case 0x0048B2u:
					a6 = func_0048B2(a6);
					break;
				case 0x0048E6u:
					a6 = func_0048E6(a6);
					break;
				case 0x00491Au:
					a6 = func_00491A(a6);
					break;
				case 0x00494Eu:
					a6 = func_00494E(a6);
					break;
				}
			}
			t2 = d7_2 - 1u;
			d7_2 = t2;
		} while (t2 != 0xFFFFu);
		unk_06004C = unk_060020(0) & ~(uint8_t)(unk_060024 >> 24u);
		unk_06004D = unk_060021 & ~(uint8_t)(unk_060024 >> 16u);
		unk_06004E = unk_060022 & ~(uint8_t)(unk_060024 >> 8u);
		unk_06004F = unk_060023 & ~(uint8_t)unk_060024;
		return d7_2;
	}
	unk_06002C = unk_060028;
	unk_060028 = unk_060024;
	unk_060024 = (((uint32_t)unk_060020(0) << 24u) | ((uint32_t)unk_060021 << 16u) | ((uint32_t)unk_060022 << 8u) | unk_060023);
	unk_060020(0) = unk_060034(0);
	unk_060021 = unk_060035;
	unk_060022 = unk_060036;
	unk_060023 = unk_060037;
	unk_06004C = unk_060050;
	unk_06004D = unk_060051;
	unk_06004E = unk_060052;
	unk_06004F = unk_060053;
	return d7;
}

uint32_t func_0048B2(uint32_t a6)
{
	if ((int8_t)unk_060066 < 0 && (unk_0600A1 & 1u) == 0u)
	{
		unk_0600A1 |= 1u;
		unk_0600A6 |= 1u;
		a6 = func_004284();
		unk_060100(0) = (unk_060100(0) & 0xFFu) | 0x100u;
	}
	return a6;
}

uint32_t func_0048E6(uint32_t a6)
{
	if ((int8_t)unk_060066 < 0 && (unk_0600A1 & 2u) == 0u)
	{
		unk_0600A1 |= 2u;
		unk_0600A6 |= 2u;
		a6 = func_004294();
		unk_060108 = 1u;
	}
	return a6;
}

uint32_t func_00491A(uint32_t a6)
{
	if ((int8_t)unk_060066 < 0 && (unk_0600A1 & 4u) == 0u)
	{
		unk_0600A1 |= 4u;
		unk_0600A6 |= 4u;
		a6 = func_0042A4();
		unk_060110 = 1u;
	}
	return a6;
}

uint32_t func_00494E(uint32_t a6)
{
	if ((int8_t)unk_060066 < 0 && (unk_0600A1 & 8u) == 0u)
	{
		unk_0600A1 |= 8u;
		unk_0600A6 |= 8u;
		a6 = func_0042B4();
		unk_060118 = 1u;
	}
	return a6;
}

void func_004982(uint8_t d6, uint32_t d7)
{
	uint16_t d5 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	d7 = func_00499E(d7);
	d6 += 0x30u;
	d5 = 0xFFEu;
	a6 = TILE_RAM + 0x4000u;
	do
	{
		mem_write8(a6, d7);
		a6++;
		mem_write8(a6, d6);
		t1 = d5 - 1u;
		d5 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
}

uint32_t func_00499E(uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = text_colours[d7];
	return d7_2;
}

void func_0049AA(void)
{
}

void func_0049AC(void)
{
	uint8_t d7 = 0;

	if (unk_060327 != 0u)
	{
		d7 = 0x7Eu;
		func_0091A4(d7, 0u);
		func_008B1E();
		return;
	}
	switch ((uint32_t)(int8_t)unk_060005)
	{
	case 0:
		func_0049E2();
		return;
	case 1:
		func_004A92();
		return;
	}
}

void func_0049E2(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_004A04();
		return;
	case 1:
		func_004A2A();
		return;
	case 2:
		func_004A4E();
		return;
	}
}

void func_004A04(void)
{
	uint16_t d7 = 0;

	if (unk_060082 == 0u)
	{
		func_0044F8();
		unk_060082++;
		d7 = 7u;
		func_004164(d7);
		unk_060007++;
	}
}

void func_004A2A(void)
{
	if (unk_060082 == 0u)
	{
		func_009A5C();
		func_009A3A();
		func_009AA8();
		unk_060007++;
	}
}

void func_004A4E(void)
{
	uint8_t d6 = 0;
	uint16_t d7 = 0;

	if (unk_060082 == 0u && unk_060083 == 0u)
	{
		func_0049AA();
		unk_060062 = 0u;
		unk_060060 = 0x60u;
		d7 = 1u;
		d6 = 3u;
		func_004982(d6, d7);
		func_046EEA();
		unk_060005++;
		unk_060007 = 0u;
	}
}

void func_004A92(void)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_004AC4();
		break;
	case 1:
		func_004B70();
		break;
	case 2:
		func_004C2E();
		break;
	case 3:
		func_004C82();
		break;
	}
	func_046F08(&ignored, &ignored_2);
	draw_sprites(&ignored_3, &ignored_2);
}

void func_004AC4(void)
{
	uint16_t d0 = 0, d6 = 0, d7_2 = 0;
	uint32_t a0 = 0, a6 = 0, d7 = 0, ignored = 0;
	uint16_t t1 = 0;

	a0 = unk_0623C0_ADDRESS;
	d0 = 2u;
	do
	{
		mem_write16(a0, 0x8100u);
		mem_write8(a0 + 0x42u, 0xFFu);
		d7 = unk_06009F;
		d7 = (uint16_t)(d7 << 3);
		a6 = 0x151D8u + d7;
		d6 = 0u;
		if ((uint8_t)d0 != 0u)
		{
			d6 = 1u;
			if ((uint8_t)d0 != 2u)
			{
				d6 = 8u;
				a6 -= d7;
			}
		}
		a6 = DATA32(a6 + (uint16_t)((uint32_t)d6 << 2));
		set_animation(ignored, a0, a6);
		a6 = indexed_table_of_16_bit_values_004B58_ADDRESS;
		if ((unk_06009F & 2u) != 0u)
			a6 = 0x4B64u;
		d7_2 = (uint16_t)((uint32_t)d0 << 2);
		mem_write16(a0 + 0xCu, mem_read16(a6 + (int16_t)d7_2));
		mem_write16(a0 + 0xEu, mem_read16(a6 + 2u + (int16_t)d7_2));
		t1 = d0 - 1u;
		d0 = t1;
		a0 += 0x50u;
	} while (t1 != 0xFFFFu);
	unk_0635FA(0) = 0u;
	unk_0635FB = 0u;
	unk_060007++;
}

void func_004B70(void)
{
	switch ((uint32_t)(int8_t)unk_060009)
	{
	case 0:
		func_004B94();
		break;
	case 1:
		func_004BBA();
		break;
	case 2:
		func_004C12();
		break;
	}
}

void func_004B94(void)
{
	unk_06246E -= 7u;
	if (unk_06246E < 0x58u)
	{
		unk_060009++;
		unk_0635FA(0) = 0u;
		unk_0635FB = 7u;
	}
}

void func_004BBA(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint32_t unk_0635FA_halfword = 0;

	a6 = unk_062460_ADDRESS;
	if ((((uint32_t)unk_0635FA(0) << 8u) | unk_0635FB) != 0xFFF9u)
	{
		unk_0635FA_halfword = (((uint32_t)unk_0635FA(0) << 8u) | unk_0635FB) - 1u;
		unk_0635FA(0) = (uint8_t)(unk_0635FA_halfword >> 8u);
		unk_0635FB = (uint8_t)unk_0635FA_halfword;
	}
	unk_06246E -= (((uint32_t)unk_0635FA(0) << 8u) | unk_0635FB);
	d7 = 0xC0u;
	if ((unk_06009F & 2u) != 0u)
		d7 = 0xD0u;
	if (d7 < unk_06246E)
	{
		unk_06246E = d7;
		unk_060009++;
		unk_0600A8 = 0x14u;
		unk_0635FA(0) = 0u;
		unk_0635FB = 0u;
	}
}

void func_004C12(void)
{
	uint8_t t1 = 0;

	t1 = unk_0600A8;
	unk_0600A8 = t1 - 1u;
	if (t1 == 1u)
	{
		unk_060007++;
		unk_060009 = 0u;
		return;
	}
}

void func_004C2E(void)
{
	uint32_t a5 = 0, a6 = 0;

	a6 = unk_0623C0_ADDRESS;
	unk_0623CC -= 0xAu;
	if (unk_0623CC >= 0x100u)
		return;
	unk_0623CC = 0x100u;
	unk_0600A8 = 0xF0u;
	unk_060007++;
	a5 = table_loaded_by_lea_004C76_ADDRESS;
	if ((unk_06009F & 1u) != 0u)
		a5 = 0x4C7Cu;
	func_004184(a5);
}

void func_004C82(void)
{
	uint8_t t1 = 0;

	t1 = unk_0600A8;
	unk_0600A8 = t1 - 1u;
	if (t1 == 1u)
	{
		unk_060003++;
		unk_060005 = 0u;
		unk_060007 = 0u;
		return;
	}
}

void func_004CA4(uint32_t d1, uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0, uint32_t a5)
{
	uint32_t d7_2 = 0;

	if (unk_060327 != 0u)
	{
		unk_0600A4 = unk_0600BE;
		func_008B1E();
		return;
	}
	d7_2 = (d7 & ~0xFFu) | unk_060005;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(int8_t)d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 2);
	switch ((uint32_t)(int16_t)d7_2)
	{
	case 0:
		func_004CF6();
		return;
	case 16:
		func_004DC4(d1, (uint16_t)d5, d7_2);
		return;
	case 32:
		func_004DF6();
		return;
	case 4:
		func_006268();
		return;
	case 8:
		func_0062C8();
		return;
	case 12:
		func_006386(d1);
		return;
	case 20:
		func_006B16(d1, d4, d5, d6, d7_2, a0);
		return;
	case 24:
		func_006BE4((uint16_t)d6, a5);
		return;
	case 28:
		func_00781E(d1, (uint16_t)d6, a5);
		return;
	}
}

void func_004CF6(void)
{
	func_0044F8();
	unk_060106(0) = 0u;
	unk_06010E = 0u;
	unk_060116 = 0u;
	unk_06011E = 0u;
	unk_060094 = 0u;
	unk_060150 = 0u;
	unk_0600BE = unk_0600A4;
	unk_0600A4 = 0u;
	start_demo();
}

void start_demo(void)
{
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)unk_0600B6 << 2);
	unk_060120 = demo_settings[d0];
	unk_0600A1 = rom_004E89[d0];
	unk_0600A6 = rom_004E8A[d0];
	unk_0600A0 = 0u;
	unk_0600B3 = 0u;
	unk_06004A = 0u;
	unk_060048 = 0u;
	d0 = (uint16_t)((uint32_t)d0 << 2);
	unk_0600AA = demo_inputs[d0 / 4u];
	unk_0600AE = rom_004E98[d0 / 4u];
	unk_0600D2 = rom_004E9C[d0 / 4u];
	unk_0600D6 = rom_004EA0[d0 / 4u];
	unk_0600A8 = 1u;
	unk_0600A9 = 1u;
	unk_0600D0 = 1u;
	unk_0600D1 = 1u;
	unk_0600C0 = 0u;
	unk_060005++;
	unk_060007 = 0u;
}

void func_004DC4(uint32_t d1, uint16_t d5, uint32_t d7)
{
	if (unk_0600A1 != 0u)
	{
		unk_0600C0++;
		if (unk_0600C0 < 0x384u)
		{
			func_006672(d1, d5, d7);
			return;
		}
	}
	unk_060005 = 8u;
	unk_060007 = 0u;
}

void func_004DF6(void)
{
	uint8_t d7 = 0;

	d7 = 0u;
	func_0091A4(d7, 0u);
	unk_060059 = 0u;
	io_write8(PRIORITY_0C0001, unk_060059);
	unk_060122 = 0u;
	unk_0600A4 = unk_0600BE;
	unk_0600B6++;
	if (unk_0600B6 >= 3u)
		unk_0600B6 = 0u;
	unk_0600A1 = 0u;
	unk_0600A6 = 0u;
	unk_0600A0 = 0u;
	unk_0600B3 = 0u;
	unk_060106(0) = 0u;
	unk_06010E = 0u;
	unk_060116 = 0u;
	unk_06011E = 0u;
	unk_060003++;
	unk_060005 = 0u;
	unk_060007 = 0u;
	unk_060009 = 0u;
	unk_06000B = 0u;
}

void func_004EC4(void)
{
	if (unk_060327 != 0u)
	{
		func_008B1E();
		return;
	}
	switch ((uint32_t)(int8_t)unk_060005)
	{
	case 0:
		func_004EF0();
		return;
	case 1:
		func_004FDE();
		return;
	}
}

void func_004EF0(void)
{
	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_004F1A();
		return;
	case 1:
		func_004F2A();
		return;
	case 2:
		func_004F4C();
		return;
	case 3:
		func_004F6C();
		return;
	case 4:
		func_004F90();
		return;
	}
}

void func_004F1A(void)
{
	unk_060002 = 2u;
	unk_060007++;
}

void func_004F2A(void)
{
	uint8_t t1 = 0;

	if (unk_060082 == 0u)
	{
		t1 = unk_060002;
		unk_060002 = t1 - 1u;
		if (t1 == 0u)
		{
			func_0044F8();
			unk_060007++;
		}
	}
}

void func_004F4C(void)
{
	uint16_t d7 = 0;

	if (unk_060082 == 0u)
	{
		unk_060082++;
		d7 = 7u;
		func_004164(d7);
		unk_060007++;
	}
}

void func_004F6C(void)
{
	if (unk_060082 == 0u)
	{
		func_009A5C();
		func_009A3A();
		func_009AA8();
		unk_060007++;
	}
}

void func_004F90(void)
{
	uint32_t carry = 0, extend = 0;
	uint8_t d7_2 = 0;
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (unk_060082 == 0u && unk_060083 == 0u)
	{
		d7 = unk_060128;
		carry = d7 >> 14;
		extend = carry;
		a6 = texts_019272[d7 & 0x3FFFu];
		d7_2 = 1u;
		func_018588(d7_2, a6, extend);
		func_046EEA();
		d7_2 = 0x78u;
		func_0091A4(d7_2, a6);
		unk_060005++;
		unk_060007 = 0u;
	}
}

void func_004FDE(void)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	switch ((uint32_t)(int8_t)unk_060007)
	{
	case 0:
		func_005010();
		break;
	case 1:
		func_0050D8();
		break;
	case 2:
		func_005132();
		break;
	case 3:
		func_005170();
		break;
	}
	func_046F08(&ignored, &ignored_2);
	draw_sprites(&ignored_3, &ignored_2);
}
