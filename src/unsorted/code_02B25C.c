/**
 *    Name:        unsorted/code_02B25C.c
 *    Description: 
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void func_02B25C(uint32_t *p_d1, uint32_t *p_d7)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, a1 = 0, a6 = 0;

	a0 = unk_062000_ADDRESS;
	a1 = unk_062C80_ADDRESS;
	a6 = unk_061100_ADDRESS;
	d0 = 0u;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			mem_write8(a0, mem_read8(a0) | 0x80u);
			mem_write8(a1, (uint8_t)d0);
			mem_write8(a6, (uint8_t)d0);
			mem_write8(a0 + 0x2Du, (uint8_t)d0);
		}
		a0 += 0x50u;
		a6++;
		a1 += 0x50u;
	} while (a0 < 0x62140u);
	unk_061104 = d0;
	unk_061106 = (uint8_t)d0;
	unk_0633FC = (uint8_t)d0;
	unk_0633EA = 0u;
	switch (unk_060121)
	{
	case 0:
		func_02B2EE(p_d1, p_d7);
		return;
	case 1:
		func_02B334(p_d1, p_d7);
		return;
	case 2:
		func_02B36A(p_d1, p_d7);
		return;
	case 3:
		func_02B3B8(p_d1, p_d7);
		return;
	case 4:
		func_02B400(p_d1, p_d7);
		return;
	case 5:
		func_02B4AA(p_d1, p_d7);
		return;
	case 6:
		func_02B4E2();
		return;
	case 7:
		func_02B506(p_d1, p_d7);
		return;
	case 8:
		func_02B578(p_d1, p_d7);
		return;
	case 9:
		func_02B5D4();
		return;
	}
}

void func_02B2EE(uint32_t *p_d1, uint32_t *p_d7)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0;

	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			mem_write8(a0 + 0x2Cu, 0u);
			d0 = 0x100u;
			if (mem_read32(a0 + 0x16u) < indexed_table_of_32_bit_values_005000_ADDRESS)
				d0++;
			func_01B8C2(d0, a0, p_d1, &ignored, &ignored_2, &ignored_3, p_d7);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	unk_0633E2 = 0u;
}

void func_02B334(uint32_t *p_d1, uint32_t *p_d7)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0;

	unk_0633DE = 0x20u;
	unk_061106 = 2u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			d0 = 0u;
			func_01B8C2(d0, a0, p_d1, &ignored, &ignored_2, &ignored_3, p_d7);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
}

void func_02B36A(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a0 = 0, d7_2 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0;

	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			mem_write8(a0 + 0x2Cu, 0u);
			if (mem_read32(a0 + 0x12u) >= 0x13C00u)
				mem_write8(a0, mem_read8(a0) | 0x40u);
			d0 = 0x100u;
			func_01B8C2(d0, a0, p_d1, &ignored, &ignored_3, &ignored_4, &d7);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	unk_0633DE = 0u;
	unk_0633DF = 0xA0u;
	d7_2 = (d7 & ~0xFFu) | 0x73u;
	func_0091A4((uint8_t)d7_2, 0u);
	*p_d7 = d7_2;
}

void func_02B3B8(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a0 = 0, d7_2 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0;

	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			mem_write8(a0, mem_read8(a0) | 0x40u);
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
			mem_write8(a0 + 0x2Cu, 0u);
			d0 = 0x100u;
			if (mem_read16(a0 + 0xEu) < 0x50u)
				d0++;
			func_01B8C2(d0, a0, p_d1, &ignored, &ignored_3, &ignored_4, &d7);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	d7_2 = (d7 & ~0xFFu) | 0x6Eu;
	func_0091A4((uint8_t)d7_2, 0u);
	*p_d7 = d7_2;
}

void func_02B400(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint16_t d0 = 0;
	uint32_t a0 = 0, a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0;

	a0 = 0x62780u;
	do
	{
		mem_write8(a0, 0u);
		a0 += 0x50u;
	} while (a0 < 0x62A00u);
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			d1 = mem_read32(a0 + 0x12u) >> 8;
			if (indexed_table_of_16_bit_values_02C0F0[mem_read8(a0 + 2u) * 2u] < (uint16_t)d1)
				mem_write8(a0, mem_read8(a0) | 0x40u);
			d0 = 0x100u;
			mem_write8(a0 + 0x2Cu, 0u);
			if (mem_read32(a0 + 0x16u) < 0x4000u)
				d0++;
			func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, p_d7);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	a0 = unk_062DC0_ADDRESS;
	a6 = 0x2E134u;
	d1 = set_animation(d1, a0, a6);
	unk_062CC2 = 0xFFu;
	unk_062D12 = 0xFFu;
	unk_060059 = 4u;
	io_write8(PRIORITY_0C0001, 4u);
	*p_d1 = d1;
}

void func_02B4AA(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a0 = 0, d7_2 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0;

	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			mem_write8(a0 + 0x1Du, 0x10u);
			d0 = 0x200u;
			func_01B8C2(d0, a0, p_d1, &ignored, &ignored_3, &ignored_4, &d7);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	d7_2 = (d7 & ~0xFFu) | 0xFEu;
	func_0091A4((uint8_t)d7_2, 0u);
	*p_d7 = d7_2;
}

void func_02B4E2(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	d7 = 0x43Bu;
	a6 = 0xC824u;
	post_palette_request(d7, a6);
	d7 = 0x43Cu;
	a6 = 0xC844u;
	post_palette_request(d7, a6);
	func_02CDA2();
}

void func_02B506(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a0 = 0, a6 = 0, d7_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0;

	a0 = 0x62780u;
	do
	{
		mem_write8(a0, 0u);
		a0 += 0x50u;
	} while (a0 < 0x62A00u);
	a0 = unk_062DC0_ADDRESS;
	a6 = 0x2DB0Au;
	*p_d1 = set_animation(*p_d1, a0, a6);
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			if (mem_read32(a0 + 0x12u) >= 0x10000u)
				mem_write8(a0, mem_read8(a0) | 0x40u);
			mem_write16(a0 + 0x1Cu, 0u);
			d0 = 0x101u;
			func_01B8C2(d0, a0, p_d1, &ignored, &ignored_2, &ignored_3, &d7);
			mem_write8(a0 + 0x33u, 0u);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	d7_2 = (d7 & ~0xFFu) | 0x6Eu;
	func_0091A4((uint8_t)d7_2, a6);
	*p_d7 = d7_2;
}

void func_02B578(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a0 = 0, d7_2 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0;

	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			d0 = 0x100u;
			if (mem_read32(a0 + 0x16u) < indexed_table_of_32_bit_values_005000_ADDRESS)
				d0++;
			func_01B8C2(d0, a0, p_d1, &ignored, &ignored_3, &ignored_4, &d7);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	unk_060059 = 4u;
	io_write8(PRIORITY_0C0001, 4u);
	unk_0633DE = 0xC0u;
	d7_2 = (d7 & ~0xFFu) | 0x73u;
	func_0091A4((uint8_t)d7_2, 0u);
	*p_d7 = d7_2;
}

void func_02B5D4(void)
{
	uint32_t a0 = 0;

	unk_0633DE = 0xC0u;
	unk_0633DF = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		mem_write8(a0 + 0x33u, 0u);
		a0 += 0x50u;
	} while (a0 < 0x62140u);
}

uint32_t func_02B5F4(uint32_t d1, uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0)
{
	uint8_t t1 = 0;

	unk_061104++;
	if (unk_0633FC != 0u)
	{
		t1 = unk_0633FC;
		unk_0633FC = t1 - 1u;
		if (t1 == 1u)
			func_03030C(&d5, &d6, &d7);
	}
	switch (unk_060121)
	{
	case 0:
		return func_02B652(d1, 0u);
	case 1:
		return func_02B6FA(d1, 0u);
	case 2:
		return func_02BACA(d1, 0u);
	case 3:
		return func_02BC7C(d1);
	case 4:
		return func_02BEF4(d1, 0u, d4, d5, d6, d7, a0);
	case 5:
		return func_02C80E(d1);
	case 6:
		return func_02C8A0(d1, 0u);
	case 7:
		return func_02CE72(d1, 0u);
	case 8:
		return func_02D56E(d1, 0u);
	case 9:
		return func_02D600(d1);
	}
}

uint32_t func_02B652(uint32_t d1, uint32_t d2)
{
	uint32_t a0 = 0, d0 = 0, d1_2 = 0;
	uint8_t t1 = 0;

	if (unk_0633E2 != 0u)
	{
		t1 = unk_0633E2;
		unk_0633E2 = t1 - 1u;
		if (t1 == 1u)
		{
			unk_0633C8 = 0u;
			unk_0600BD = 0u;
			unk_060007++;
		}
		return d1;
	}
	unk_0633CB = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			d1 = (d1 & ~0xFFFFu) | mem_read16(a0 + 0xCu);
			if ((uint16_t)d1 < 0x170u)
			{
				unk_0633CB--;
				d1_2 = (d1 & ~0xFFFFu) | 0x170u;
				d2 = (d2 & ~0xFFFFu) | 0x50u;
				direction_to(a0, &d0, &d1_2, &d2);
				d1 = (d1_2 & ~0xFFFFu) | 0x300u;
				func_02C7E6((uint8_t)d0, (uint16_t)d1, a0);
			}
			else
			{
				d2 = (d2 & ~0xFFFFu) | mem_read16(a0 + 0xEu);
				if ((uint16_t)d2 >= 0x54u || (uint16_t)d2 < 0x4Cu)
				{
					unk_0633CB--;
					d1_2 = (d1 & ~0xFFFFu) | 0x170u;
					d2 = (d2 & ~0xFFFFu) | 0x50u;
					direction_to(a0, &d0, &d1_2, &d2);
					d1 = (d1_2 & ~0xFFFFu) | 0x300u;
					func_02C7E6((uint8_t)d0, (uint16_t)d1, a0);
				}
				else
					mem_write8(a0, mem_read8(a0) & 0x7Fu);
			}
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB == 0u)
		unk_0633E2 = 0x20u;
	return d1;
}

uint32_t func_02B6FA(uint32_t d1, uint32_t d2)
{
	uint32_t ignored = 0, ignored_3 = 0;

	if (unk_0633EA < 3u)
		func_01EE3A(0u, &d1, &ignored, &ignored_3);
	switch (unk_0633EA)
	{
	case 0:
		d1 = func_02B740(d1);
		break;
	case 1:
		func_02B7E2();
		break;
	case 2:
		func_02B83E();
		break;
	case 3:
		d1 = func_02B872(d1, d2);
		break;
	case 4:
		d1 = func_02B986(d1);
		break;
	case 5:
		func_02BAAA();
		break;
	}
	func_01ECAA();
	return d1;
}

uint32_t func_02B740(uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0;
	uint32_t a0 = 0, a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;

	t1 = unk_0633DE;
	unk_0633DE = t1 - 1u;
	if (t1 != 1u)
		return d1;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			if (mem_read32(a0 + 0x12u) >= 0x12C00u)
				mem_write8(a0, mem_read8(a0) | 0x40u);
			d0 = 0x101u;
			func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
			mem_write8(a0 + 0x33u, 0u);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	a0 = unk_062F00_ADDRESS;
	unk_062F00 = 0x81u;
	unk_062F42 = 0xFF00u;
	unk_062F12 = 0x12C00u;
	unk_062F16 = 0x6000u;
	unk_062F0C = 0x120u;
	unk_062F0E = 0x60u;
	unk_062F10 = 0u;
	unk_062F32 = 0u;
	a6 = 0x2D842u;
	d1 = set_animation(d1, a0, a6);
	d7 = 0xFEu;
	func_0091A4(d7, a6);
	unk_0633DE = 0x20u;
	func_02B7DA();
	return d1;
}

void func_02B7DA(void)
{
	unk_0633EA++;
}

void func_02B7E2(void)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0;
	uint32_t a0 = 0, a6 = 0;
	uint8_t t2 = 0;
	uint32_t t1 = 0;

	a0 = unk_062F00_ADDRESS;
	if (unk_0633DE == 0u)
	{
		t1 = unk_062F12 - 0x300u;
		AS16(unk_062F12) = t1;
		AT16(unk_062F12, 2) = t1 >> 16;
		d0 = (uint16_t)(unk_062F12 >> 8);
		unk_062F0C = d0;
		if ((uint16_t)d0 >= 0xB0u)
			return;
		a6 = 0x2D88Eu;
		set_animation(0u, a0, a6);
		unk_0633DE = 0x18u;
		func_02B7DA();
		return;
	}
	t2 = unk_0633DE;
	unk_0633DE = t2 - 1u;
	if (t2 != 1u)
		return;
	a6 = 0x2D84Cu;
	set_animation(0u, a0, a6);
	d7 = 0x72u;
	func_0091A4(d7, a6);
}

void func_02B83E(void)
{
	uint32_t a0 = 0;
	uint8_t t1 = 0;

	a0 = unk_062F00_ADDRESS;
	if (unk_062F33 == 0u)
	{
		unk_062F1A = 0x380u;
		unk_062F1C = 0u;
		func_02B7DA();
		return;
	}
	if (unk_0633DE != 0u)
	{
		t1 = unk_0633DE;
		unk_0633DE = t1 - 1u;
		if (t1 == 1u)
		{
			unk_062EB0 = 0u;
			return;
		}
	}
}

uint32_t func_02B872(uint32_t d1, uint32_t d2)
{
	uint16_t d0_2 = 0, d7 = 0;
	uint32_t a0 = 0, a6 = 0, d0 = 0, d1_2 = 0, ignored = 0;
	uint16_t t1 = 0, t2 = 0;

	a0 = unk_062F00_ADDRESS;
	if (unk_062F0C < 0x178u)
	{
		d1_2 = (d1 & ~0xFFFFu) | 0x178u;
		d2 = 0x70u;
		direction_to(a0, &d0, &d1_2, &d2);
		d1_2 = (d1_2 & ~0xFFFFu) | 0x300u;
		func_02C7E6((uint8_t)d0, (uint16_t)d1_2, a0);
		if (unk_062F1C != 0u)
		{
			d0_2 = unk_062F1A;
			t1 = unk_062F1A;
			unk_062F1A = t1 - d0_2;
			if (t1 < d0_2)
				unk_062F10 = 0u;
			unk_062F1A += 0x18u;
		}
		else
		{
			AS16(unk_062F16) += unk_062F1A;
			t2 = unk_062F1A;
			unk_062F1A = t2 - 0x10u;
			if (t2 < 0x10u)
			{
				unk_062F1A = 0u - unk_062F1A;
				unk_062F1C--;
			}
		}
		a0 = unk_062000_ADDRESS;
		do
		{
			if ((mem_read8(a0) & 1u) != 0u)
			{
				if (mem_read8(a0 + 0x33u) == 0u)
					mem_write8(a0 + 0x33u, 4u);
				d1_2 = (d1_2 & ~0xFFFFu) | 0x150u;
				d2 = (d2 & ~0xFFFFu) | 0x58u;
				direction_to(a0, &d0, &d1_2, &d2);
				d1_2 = (d1_2 & ~0xFFFFu) | 0x100u;
				func_02C7E6((uint8_t)d0, (uint16_t)d1_2, a0);
			}
			a0 += 0x50u;
		} while (a0 < 0x62140u);
		return d1_2;
	}
	unk_062F00 = 0u;
	unk_062000 &= 0x7Fu;
	unk_062050 &= 0x7Fu;
	unk_0620A0 &= 0x7Fu;
	unk_0620F0 &= 0x7Fu;
	func_02B7DA();
	unk_060129 = 0xFFu;
	unk_063340 = 0x800u;
	unk_063380 = 0x800u;
	unk_063300 = 0x800u;
	unk_063344 = 0x10000u;
	unk_063384 = 0x10000u;
	unk_063304 = 0x10000u;
	func_031230(&d1_2, &ignored);
	a6 = 0xA13Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	return d1_2;
}

uint32_t func_02B986(uint32_t d1)
{
	uint32_t carry = 0;
	uint8_t d0 = 0, d7_2 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a0 = 0, a1 = 0, a5 = 0, a6 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (unk_060083 != 0u)
		return d1;
	func_031230(&ignored, &ignored_2);
	a0 = TILE_RAM + 0x4008u;
	d0 = 0x34u;
	d1_2 = 0u;
	d7 = 0x1Fu;
	do
	{
		d6 = 0x1Fu;
		do
		{
			mem_write8(a0, d0);
			a0++;
			mem_write8(a0, d1_2);
			carry = (uint8_t)(d1_2 + 1u) < d1_2;
			d1_2 = (uint8_t)(d1_2 + 1u);
			a0++;
			if (carry)
				d0++;
			t1 = d6 - 1u;
			d6 = t1;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
		a0 += 0x40u;
	} while (t2 != 0xFFFFu);
	io_write8(TILES_106B00, 0xE0u);
	unk_060064 = 0xE0u;
	a0 = TILE_RAM + 0x2418u;
	d0 = 0xBu;
	d1_2 = 0u;
	d7 = 0x17u;
	do
	{
		d6 = 0x17u;
		do
		{
			mem_write8(a0, d0);
			a0++;
			mem_write8(a0, d1_2);
			carry = (uint8_t)(d1_2 + 1u) < d1_2;
			d1_2 = (uint8_t)(d1_2 + 1u);
			a0++;
			if (carry)
			{
				d0++;
				if (d0 == 0xCu)
					d0 = 0x18u;
			}
			t3 = d6 - 1u;
			d6 = t3;
		} while (t3 != 0xFFFFu);
		t4 = d7 - 1u;
		d7 = t4;
		a0 += 0x50u;
	} while (t4 != 0xFFFFu);
	io_write8(TILES_106E00, 0x2Du);
	unk_060065 = 0x2Du;
	a5 = animations_02BA9A_ADDRESS;
	a0 = unk_062DC0_ADDRESS;
	a1 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a1) & 1u) != 0u)
		{
			mem_write8(a0, 0x81u);
			mem_write16(a0 + 0x10u, 0u);
			mem_write16(a0 + 0x42u, 0xFF00u);
			mem_write16(a0 + 0xCu, 0x78u);
			mem_write16(a0 + 0xEu, 0x80u);
			a6 = DATA32(a5);
			d1_2 = set_animation(d1_2, a0, a6);
		}
		a1 += 0x50u;
		a5 += 4u;
		a0 += 0x50u;
	} while (a0 < unk_062F00_ADDRESS);
	mem_write8(a0, 0x81u);
	mem_write16(a0 + 0x10u, 0u);
	mem_write16(a0 + 0x42u, 0xFF00u);
	mem_write16(a0 + 0xCu, 0xA7u);
	mem_write16(a0 + 0xEu, 0x40u);
	a6 = 0x2DC36u;
	d1_2 = set_animation(d1_2, a0, a6);
	d7_2 = 0x40u;
	func_0091A4(d7_2, a6);
	unk_0633DE = 1u;
	unk_0633DF = 8u;
	func_02B7DA();
	return d1_2;
}

void func_02BAAA(void)
{
	uint8_t d7 = 0;
	uint16_t t1 = 0;
	uint32_t unk_0633DE_halfword = 0;

	t1 = (((uint32_t)unk_0633DE << 8u) | unk_0633DF);
	unk_0633DE_halfword = t1 - 1u;
	unk_0633DE = (uint8_t)(unk_0633DE_halfword >> 8u);
	unk_0633DF = (uint8_t)unk_0633DE_halfword;
	if (t1 == 1u)
	{
		unk_0633C8 = 0u;
		unk_0600BD = 0u;
		unk_060007++;
		return;
	}
	if ((((uint32_t)unk_0633DE << 8u) | unk_0633DF) != 0xF0u)
		return;
	d7 = 0xA7u;
	func_0091A4(d7, 0u);
}

uint32_t func_02BACA(uint32_t d1, uint32_t d2)
{
	uint32_t a0 = 0;
	uint16_t t1 = 0;
	uint32_t unk_0633DE_halfword = 0;

	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			switch (mem_read8(a0 + 0x2Cu))
			{
			case 0:
				func_02BB22(0u, 0u, a0, &d1, &d2);
				break;
			case 1:
				func_02BB82(0u, 0u, a0, &d1, &d2);
				break;
			case 2:
				func_02BC66(a0);
				break;
			}
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	t1 = (((uint32_t)unk_0633DE << 8u) | unk_0633DF);
	unk_0633DE_halfword = t1 - 1u;
	unk_0633DE = (uint8_t)(unk_0633DE_halfword >> 8u);
	unk_0633DF = (uint8_t)unk_0633DE_halfword;
	if (t1 == 1u)
	{
		unk_0633C8 = 0u;
		unk_0600BD = 0u;
		unk_060007++;
	}
	return d1;
}

void func_02BB22(uint32_t d5, uint32_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint32_t d1 = *p_d1;
	uint32_t d2 = *p_d2;
	uint16_t d0_2 = 0;
	uint32_t d0 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0;

	unk_0633CB--;
	d1_2 = (d1 & ~0xFFFFu) | mem_read16(a0 + 0xCu);
	if ((uint16_t)d1_2 < 0x100u)
	{
		d1_2 = (d1_2 & ~0xFFFFu) | 0x13Cu;
		d2 = (d2 & ~0xFFFFu) | 0x34u;
		direction_to(a0, &d0, &d1_2, &d2);
		d1_2 = (d1_2 & ~0xFFFFu) | 0x280u;
		func_02C7E6((uint8_t)d0, (uint16_t)d1_2, a0);
	}
	else
	{
		d2 = (d2 & ~0xFFFFu) | mem_read16(a0 + 0xEu);
		if ((uint16_t)d2 < 0x60u)
		{
			mem_write16(a0 + 0x1Au, 0x700u);
			mem_write16(a0 + 0x10u, 0u);
			mem_write8(a0 + 0x32u, 0u);
			mem_write8(a0 + 0x1Cu, 0u);
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
			d0_2 = 0x201u;
			func_01B8C2(d0_2, a0, &d1_2, &ignored, &d5, &d6, &ignored_2);
			mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) + 1u);
		}
		else
		{
			d1_2 = (d1_2 & ~0xFFFFu) | 0x13Cu;
			d2 = (d2 & ~0xFFFFu) | 0x34u;
			direction_to(a0, &d0, &d1_2, &d2);
			d1_2 = (d1_2 & ~0xFFFFu) | 0x280u;
			func_02C7E6((uint8_t)d0, (uint16_t)d1_2, a0);
		}
	}
	*p_d1 = d1_2;
	*p_d2 = d2;
}

void func_02BB82(uint32_t d5, uint32_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint32_t d1 = *p_d1;
	uint32_t d2 = *p_d2;
	uint16_t d0 = 0;
	uint32_t a6 = 0, d0_2 = 0, d1_2 = 0, d2_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	unk_0633CB--;
	if (mem_read8(a0 + 0x1Cu) != 0u)
	{
		d0 = mem_read16(a0 + 0x1Au);
		t1 = mem_read16(a0 + 0x10u);
		mem_write16(a0 + 0x10u, t1 - d0);
		if (t1 < d0)
		{
			mem_write16(a0 + 0x10u, 0u);
			mem_write16(a0 + 0x1Au, 0u);
		}
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x50u);
	}
	else
	{
		mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
		t2 = mem_read16(a0 + 0x1Au);
		mem_write16(a0 + 0x1Au, t2 - 0x50u);
		if (t2 < 0x50u)
		{
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
			mem_write8(a0 + 0x1Cu, mem_read8(a0 + 0x1Cu) - 1u);
			d0 = 0x203u;
			func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
		}
	}
	d1_2 = (d1 & ~0xFFFFu) | mem_read16(a0 + 0xCu);
	t3 = d1_2;
	d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(t3 - 0x139u);
	if (t3 < 0x139u || (uint16_t)d1_2 >= 7u)
	{
		d1_2 = (d1_2 & ~0xFFFFu) | 0x13Cu;
		d2 = (d2 & ~0xFFFFu) | 0x34u;
		direction_to(a0, &d0_2, &d1_2, &d2);
		d1_2 = (d1_2 & ~0xFFFFu) | 0x280u;
		func_02C7E6((uint8_t)d0_2, (uint16_t)d1_2, a0);
	}
	else
	{
		d2_2 = (d2 & ~0xFFFFu) | mem_read16(a0 + 0xEu);
		t4 = d2_2;
		d2 = (d2_2 & ~0xFFFFu) | (uint16_t)(t4 - 0x31u);
		if (t4 < 0x31u || (uint16_t)d2 >= 7u)
		{
			d1_2 = (d1_2 & ~0xFFFFu) | 0x13Cu;
			d2 = (d2 & ~0xFFFFu) | 0x34u;
			direction_to(a0, &d0_2, &d1_2, &d2);
			d1_2 = (d1_2 & ~0xFFFFu) | 0x280u;
			func_02C7E6((uint8_t)d0_2, (uint16_t)d1_2, a0);
		}
		else if (mem_read16(a0 + 0x10u) == 0u)
		{
			mem_write32(a0 + 0x12u, 0x13C00u);
			mem_write32(a0 + 0x16u, 0x3400u);
			d1_2 = 0x34u;
			mem_write16(a0 + 0xCu, 0x13Cu);
			mem_write16(a0 + 0xEu, 0x34u);
			a6 = DATA32(animations_02BC56_ADDRESS + (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 2));
			d1_2 = set_animation(d1_2, a0, a6);
			mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) + 1u);
		}
	}
	*p_d1 = d1_2;
	*p_d2 = d2;
}

void func_02BC66(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0, mem_read8(a0) & 0x7Fu);
		return;
	}
	unk_0633CB--;
}

uint32_t func_02BC7C(uint32_t d1)
{
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)unk_0633EA << 2);
	switch (d0)
	{
	case 0:
		d1 = func_02BCA4(d1);
		break;
	case 4:
		d1 = func_02BDD4(d1);
		break;
	case 8:
		d1 = func_02BE68(d0, d1);
		break;
	}
	func_01ECAA();
	return d1;
}

uint32_t func_02BCA4(uint32_t d1)
{
	uint16_t d7 = 0;
	uint32_t a0 = 0, a6 = 0, d1_2 = 0, ignored = 0;

	unk_0633CB = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			switch (mem_read8(a0 + 0x2Cu))
			{
			case 0:
				d1 = func_02BD4C(d1, a0);
				break;
			case 1:
				d1 = func_02BD86(d1, a0);
				break;
			}
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB != 0u)
		return d1;
	unk_060129 = 0xFFu;
	unk_063300 &= 0xFFFF0000u;
	unk_063300 &= 0xFFFFu;
	unk_063340 &= 0xFFFF0000u;
	unk_063340 &= 0xFFFFu;
	unk_063380 &= 0xFFFF0000u;
	unk_063380 &= 0xFFFFu;
	unk_063304 = 0x10000u;
	unk_063344 = 0x10000u;
	unk_063384 = 0x10000u;
	func_031230(&d1_2, &ignored);
	unk_060059 = 0u;
	io_write8(PRIORITY_0C0001, 0u);
	a6 = 0xA16Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	func_02B7DA();
	return d1_2;
}

uint32_t func_02BD4C(uint32_t d1, uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint32_t t1 = 0;

	unk_0633CB--;
	if (mem_read32(a0 + 0x12u) >= 0x9000u)
	{
		t1 = mem_read32(a0 + 0x12u) - 0x300u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
		mem_write16(a0 + 0xCu, mem_read32(a0 + 0x12u) >> 8);
		return d1;
	}
	mem_write8(a0 + 0x26u, 0x20u);
	d0 = 0x200u;
	func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
	mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) + 1u);
	return d1;
}

uint32_t func_02BD86(uint32_t d1, uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x26u) == 0u)
	{
		if (mem_read16(a0 + 0x10u) + mem_read32(a0 + 0x16u) < 0x10000u)
		{
			unk_0633CB--;
			mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x800u);
			if (mem_read16(a0 + 0x10u) >= 0x4000u)
			{
				d0 = 0x202u;
				func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
				return d1;
			}
		}
		return d1;
	}
	unk_0633CB--;
	t1 = mem_read8(a0 + 0x26u);
	mem_write8(a0 + 0x26u, t1 - 1u);
	if (t1 != 1u)
		return d1;
	d0 = 0x201u;
	func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
	return d1;
}

uint32_t func_02BDD4(uint32_t d1)
{
	uint32_t a0 = 0, a6 = 0, d1_2 = 0;

	if (unk_060083 != 0u)
		return d1;
	io_write8(TILES_106B00, 0x40u);
	unk_060064 = 0x40u;
	unk_063312 = layers_0314C4_ADDRESS;
	unk_063316 = 0x315C4u;
	unk_063310 = 0x20u;
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	unk_063312 = layers_03163C_ADDRESS;
	unk_063316 = 0x3173Cu;
	a0 = TILE_RAM + 0x2000u;
	d1_2 = func_01E11E(a0);
	a0 = unk_062DC0_ADDRESS;
	unk_062DC0 = 0x81u;
	unk_062DC1 = 0u;
	unk_062DCC = 0xD0u;
	unk_062DCE = 0xA0u;
	unk_062DD0 = 0u;
	unk_062E02 = 0xFF00u;
	a6 = 0x2E162u;
	d1_2 = set_animation(d1_2, a0, a6);
	unk_0633DE = 1u;
	unk_0633DF = 0x30u;
	func_02B7DA();
	return d1_2;
}

uint32_t func_02BE68(uint32_t d0, uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d2 = 0, d3 = 0;
	uint32_t a0 = 0, a6 = 0, d1_2 = 0, d4 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t t1 = 0;
	uint32_t unk_0633DE_halfword = 0;

	t1 = (((uint32_t)unk_0633DE << 8u) | unk_0633DF);
	unk_0633DE_halfword = t1 - 1u;
	unk_0633DE = (uint8_t)(unk_0633DE_halfword >> 8u);
	unk_0633DF = (uint8_t)unk_0633DE_halfword;
	if (t1 == 1u)
	{
		unk_0633C8 = 0u;
		unk_0600BD = 0u;
		unk_060007++;
		return d1;
	}
	if ((((uint32_t)unk_0633DE << 8u) | unk_0633DF) == 0x110u)
	{
		a0 = unk_062E10_ADDRESS;
		AT16(unk_062E10, -1) = 0x8100u;
		unk_062E1C = 0x140u;
		unk_062E1E = 0x58u;
		unk_062E20 = 0u;
		AT16(unk_062E52, -1) = 0xFF00u;
		a6 = animations_02E192_ADDRESS;
		d1 = set_animation(d1, a0, a6);
		d0 &= ~0xFFu;
		d1_2 = (d1 & ~0xFFFFu) | 0x110u;
		d2 = 0x40u;
		d4 = 0xFFFFFFD0u;
		d3 = 0x78u;
		func_0301F0(d2, d3, &d0, &d1_2, &d4, &ignored_2, &ignored_3, &ignored_4, &ignored);
		func_03015C(ignored);
		return d1_2;
	}
	if ((((uint32_t)unk_0633DE << 8u) | unk_0633DF) == 0xA0u)
	{
		unk_062E10 = 0u;
		return d1;
	}
	if ((((uint32_t)unk_0633DE << 8u) | unk_0633DF) != 0x80u)
		return d1;
	d7 = 0xA7u;
	func_0091A4(d7, 0u);
	return d1;
}

uint32_t func_02BEF4(uint32_t d1, uint32_t d2, uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0)
{
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)unk_0633EA << 2);
	switch (d0)
	{
	case 0:
		d1 = func_02BF24(d1, d2);
		break;
	case 4:
		d1 = func_02C2C6(d0, d1);
		break;
	case 8:
		d1 = func_02C3DA(d1);
		break;
	case 12:
		d1 = func_02C44E(d1);
		break;
	case 16:
		d1 = func_02C65C(d1);
		break;
	case 20:
		d1 = func_0013C0(d4, d5, d6, d7, a0);
		break;
	}
	func_01ECAA();
	return d1;
}

uint32_t func_02BF24(uint32_t d1, uint32_t d2)
{
	uint32_t a0 = 0, a6 = 0, d0 = 0, d1_2 = 0;

	unk_0633CB = 0u;
	unk_0633EB = 0u;
	unk_062CA0 = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u && (mem_read8(a0) & 0x80u) != 0u)
		{
			switch (mem_read8(a0 + 0x2Cu))
			{
			case 0:
				func_02C058(a0, &d1, &d2);
				break;
			case 1:
				func_02C100(a0, &d1, &d2);
				break;
			case 2:
				d1 = func_02C256(d1, a0);
				break;
			}
			func_02C7F8(a0);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB == 0u)
	{
		unk_0633DE = 0u;
		unk_0633DF = 0x97u;
		func_02B7DA();
		return d1;
	}
	if (unk_0633EB != 0u)
		return d1;
	unk_06202C = 1u;
	unk_06207C = 1u;
	unk_0620CC = 1u;
	unk_06211C = 1u;
	a0 = unk_062C80_ADDRESS;
	unk_062C80 = 0x8100u;
	unk_062CD0 = 0x8100u;
	unk_062C8C = 0x50u;
	unk_062CDC = 0x50u;
	unk_062C90 = 0u;
	unk_062CE0 = 0u;
	unk_062C92 = indexed_table_of_32_bit_values_005000_ADDRESS;
	unk_062CE2 = indexed_table_of_32_bit_values_005000_ADDRESS;
	d0 = 0xE000u;
	if (unk_060121 != 5u)
		d0 = 0xA000u;
	d0 -= unk_063384 & 0xFF00u;
	unk_062C96 = d0;
	d1_2 = d0 - 0x400u;
	unk_062CE6 = d1_2;
	d1_2 = d1_2 >> 8;
	unk_062C8E = d0 >> 8;
	unk_062CDE = d1_2;
	unk_062C9A = 0x6A0u;
	a6 = 0x2D8C8u;
	d1_2 = set_animation(d1_2, a0, a6);
	a6 = 0x2D8E2u;
	a0 += 0x50u;
	return set_animation(d1_2, a0, a6);
}

void func_02C058(uint32_t a0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint32_t d1 = *p_d1;
	uint32_t d2 = *p_d2;
	uint16_t d0 = 0;
	uint32_t d0_2 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t t1 = 0, t2 = 0;

	unk_0633CB--;
	d1_2 = (d1 & ~0xFFFFu) | indexed_table_of_16_bit_values_02C0F0[mem_read8(a0 + 2u) * 2u];
	t1 = mem_read16(a0 + 0xEu);
	d0 = (uint16_t)(t1 - 0x3Cu);
	if (t1 < 0x3Cu || d0 >= 8u)
	{
		unk_0633EB = 0xFFu;
		d0 = (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 2);
		d1_2 = (d1_2 & ~0xFFFFu) | indexed_table_of_16_bit_values_02C0F0[d0 / 2u];
		d2 = (d2 & ~0xFFFFu) | rom_02C0F2[d0 / 2u];
		direction_to(a0, &d0_2, &d1_2, &d2);
		d1_2 = (d1_2 & ~0xFFFFu) | 0x200u;
		func_02C7E6((uint8_t)d0_2, (uint16_t)d1_2, a0);
	}
	else
	{
		t2 = mem_read16(a0 + 0xCu);
		d0 = (uint16_t)(t2 - d1_2);
		if (t2 < (uint16_t)d1_2 || d0 >= 8u)
		{
			unk_0633EB = 0xFFu;
			d0 = (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 2);
			d1_2 = (d1_2 & ~0xFFFFu) | indexed_table_of_16_bit_values_02C0F0[d0 / 2u];
			d2 = (d2 & ~0xFFFFu) | rom_02C0F2[d0 / 2u];
			direction_to(a0, &d0_2, &d1_2, &d2);
			d1_2 = (d1_2 & ~0xFFFFu) | 0x200u;
			func_02C7E6((uint8_t)d0_2, (uint16_t)d1_2, a0);
		}
		else
		{
			mem_write8(a0 + 0x1Du, 0x10u);
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			if (mem_read8(a0 + 2u) >= 2u)
				mem_write8(a0, mem_read8(a0) | 0x40u);
			d0 = 0x101u;
			func_01B8C2(d0, a0, &d1_2, &ignored, &ignored_2, &ignored_3, &ignored_4);
			mem_write8(a0 + 0x33u, 0u);
		}
	}
	*p_d1 = d1_2;
	*p_d2 = d2;
}

void func_02C100(uint32_t a0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint8_t d7 = 0;
	uint16_t d0_2 = 0;
	uint32_t a6 = 0, d0 = 0, d1 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t2 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0;
	uint32_t t1 = 0, t6 = 0;

	unk_0633CB--;
	unk_0633EB = 0xFFu;
	a6 = unk_062C80_ADDRESS;
	if (unk_062C9A == 0u)
	{
		if (unk_062C92 - unk_062CE2 < 0x4000u)
		{
			if (unk_062CA0 == 0u)
			{
				unk_062CA0--;
				t1 = unk_062CE2 - 0x300u;
				AS16(unk_062CE2) = t1;
				AT16(unk_062CE2, 2) = t1 >> 16;
				unk_062CDC = unk_062CE2 >> 8;
			}
			return;
		}
		if (mem_read8(a0 + 0x1Du) != 0u)
		{
			t2 = mem_read8(a0 + 0x1Du);
			mem_write8(a0 + 0x1Du, t2 - 1u);
			if (t2 != 1u)
			{
				return;
			}
			mem_write8(a0 + 0x33u, 6u);
			return;
		}
		if (unk_060121 == 5u)
		{
			*p_d1 = unk_063384 >> 8;
			*p_d1 = *p_d1 & ~0xFF00u;
			*p_d2 = (uint16_t)(0x40u - *p_d1);
			*p_d2 = (uint16_t)(*p_d2 + 0x4Du);
		}
		else
			*p_d2 = (*p_d2 & ~0xFFFFu) | 0x4Du;
		t3 = mem_read16(a0 + 0xEu);
		d0_2 = (uint16_t)(t3 - *p_d2);
		if ((uint16_t)*p_d2 <= t3 && d0_2 < 7u)
		{
			t4 = mem_read16(a0 + 0xCu);
			d0_2 = (uint16_t)(t4 - 0xCDu);
			if (t4 >= 0xCDu && d0_2 < 7u)
			{
				mem_write8(a0 + 0x2Cu, mem_read8(a0 + 0x2Cu) + 1u);
				mem_write16(a0 + 0x1Au, 0x400u);
				mem_write8(a0 + 0x1Cu, 0u);
				mem_write8(a0 + 0x1Du, 8u);
				d0_2 = 0x200u;
				func_01B8C2(d0_2, a0, p_d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
				return;
			}
		}
		*p_d2 = (*p_d2 & ~0xFFFFu) | (uint16_t)(*p_d2 + 3u);
		d1 = (*p_d1 & ~0xFFFFu) | 0xD0u;
		direction_to(a0, &d0, &d1, p_d2);
		*p_d1 = (d1 & ~0xFFFFu) | 0x200u;
		func_02C7E6((uint8_t)d0, (uint16_t)*p_d1, a0);
	}
	else if (unk_062CA0 == 0u)
	{
		unk_062CA0--;
		if (unk_062C9A < 0x414u && unk_062C9A >= 0x400u)
		{
			d7 = 0x3Cu;
			func_0091A4(d7, a6);
			a6 = unk_062C80_ADDRESS;
		}
		t5 = unk_062C9A;
		unk_062C9A = t5 - 0x14u;
		if (t5 < 0x14u)
		{
			unk_062C9A = 0u;
			unk_062DC0 = 0u;
			d7 = 0x12u;
			func_0091A4(d7, a6);
			a6 = unk_062C80_ADDRESS;
		}
		t6 = unk_062C92 + (int16_t)unk_062C9A;
		AS16(unk_062C92) = t6;
		AT16(unk_062C92, 2) = t6 >> 16;
		d0 = unk_062C92;
		unk_062CE2 = d0;
		d0 = d0 >> 8;
		unk_062C8C = d0;
		unk_062CDC = d0;
	}
}

uint32_t func_02C256(uint32_t d1, uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	unk_0633CB--;
	unk_0633EB = 0xFFu;
	if (mem_read8(a0 + 0x1Du) != 0u)
	{
		t1 = mem_read8(a0 + 0x1Du);
		mem_write8(a0 + 0x1Du, t1 - 1u);
		if (t1 != 1u)
			return d1;
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
		d0 = 0x201u;
		func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
		return d1;
	}
	if (mem_read8(a0 + 0x1Cu) != 0u)
	{
		mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - mem_read16(a0 + 0x1Au));
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x40u);
		if (mem_read16(a0 + 0x10u) >= 0x1800u)
			return d1;
		mem_write8(a0, mem_read8(a0) & 0x7Fu);
		return d1;
	}
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
	t2 = mem_read16(a0 + 0x1Au);
	mem_write16(a0 + 0x1Au, t2 - 0x40u);
	if (t2 >= 0x40u)
		return d1;
	mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	mem_write8(a0 + 0x1Cu, mem_read8(a0 + 0x1Cu) - 1u);
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - mem_read16(a0 + 0x1Au));
	mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x40u);
	if (mem_read16(a0 + 0x10u) < 0x1800u)
		mem_write8(a0, mem_read8(a0) & 0x7Fu);
	return d1;
}

uint32_t func_02C2C6(uint16_t d0, uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d0_2 = 0, d2 = 0;
	uint32_t a0 = 0, d0_3 = 0, d1_2 = 0, d2_2 = 0;
	uint8_t t1 = 0;
	uint32_t t2 = 0, t3 = 0, t4 = 0;

	t1 = unk_0633DF;
	unk_0633DF = t1 - 1u;
	if (t1 != 1u)
	{
		if (unk_0633DF == 0x60u)
		{
			d0 &= ~0xFFu;
			d1 = 0xE0u;
			d2 = 0x70u;
			d1 = func_02FFEE(d0, d1, d2);
		}
		a0 = unk_062C80_ADDRESS;
		if (unk_062CE2 < unk_062C92)
		{
			t2 = unk_062CE2 + 0x300u;
			AS16(unk_062CE2) = t2;
			AT16(unk_062CE2, 2) = t2 >> 16;
			unk_062CDC = unk_062CE2 >> 8;
			return d1;
		}
		if ((unk_0633DF & 0x1Fu) == 0u)
		{
			d7 = 0x2Du;
			func_0091A4(d7, 0u);
		}
		if ((unk_0600A4 & 1u) != 0u)
			return d1;
		d0_2 = unk_0633DE;
		unk_0633DE++;
		d0_2 = (uint16_t)((d0_2 & 7u) << 2);
		d2_2 = (int16_t)rom_02C3BC[d0_2 / 2u];
		t3 = unk_062C92 + (int16_t)indexed_table_of_16_bit_values_02C3BA[d0_2 / 2u];
		unk_062C92 = (unk_062C92 & 0xFFFF0000u) | (t3 & 0xFFFFu);
		unk_062C92 = (unk_062C92 & 0xFFFFu) | ((t3 >> 16 & 0xFFFFu) << 16u);
		t4 = unk_062C96 + d2_2;
		unk_062C96 = (unk_062C96 & 0xFFFF0000u) | (t4 & 0xFFFFu);
		unk_062C96 = (unk_062C96 & 0xFFFFu) | ((t4 >> 16 & 0xFFFFu) << 16u);
		d0_3 = unk_062C92;
		d1_2 = unk_062C96;
		unk_062CE2 = d0_3;
		d2_2 = d1_2 - 0x400u;
		unk_062CE6 = d2_2;
		d0_3 = d0_3 >> 8;
		d1_2 = d1_2 >> 8;
		unk_062C8C = d0_3;
		unk_062C8E = d1_2;
		unk_062CDC = d0_3;
		unk_062CDE = d2_2 >> 8;
		return d1_2;
	}
	d7 = 0x3Au;
	func_0091A4(d7, 0u);
	d7 = 0x6Eu;
	func_0091A4(d7, 0u);
	unk_06338C = 0u;
	func_02B7DA();
	return d1;
}

uint32_t func_02C3DA(uint32_t d1)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d0 = 0, d1_2 = 0, ignored = 0;

	d0 = (unk_062C92 + 0x600u) & 0x1FFFFu;
	unk_062C92 = d0;
	unk_062CE2 = d0;
	d0 = d0 >> 8;
	unk_062C8C = d0;
	unk_062CDC = d0;
	if (d0 < 0x59u || d0 >= 0x60u)
		return d1;
	unk_0633DE = 0xC0u;
	unk_060129 = 0xFFu;
	unk_063340 &= 0xFFFF0000u;
	unk_063340 &= 0xFFFFu;
	unk_063380 &= 0xFFFF0000u;
	unk_063380 &= 0xFFFFu;
	unk_063300 &= 0xFFFF0000u;
	unk_063300 &= 0xFFFFu;
	func_031230(&d1_2, &ignored);
	a6 = 0xA11Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	func_02B7DA();
	return d1_2;
}

uint32_t func_02C44E(uint32_t d1)
{
	uint8_t d0 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, d1_2 = 0;
	uint8_t t1 = 0;

	if (unk_060083 != 0u)
		return d1;
	unk_063312 = layers_046C52_ADDRESS;
	unk_063316 = 0x46D52u;
	unk_063310 = 0x20u;
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	io_write8(TILES_106B00, 0xD0u);
	unk_060064 = 0xD0u;
	unk_063312 = 0x46622u;
	unk_063316 = 0x46822u;
	unk_063310 = 0x20u;
	a0 = TILE_RAM + 0x2000u;
	d1_2 = func_01E11E(a0);
	a0 = TILE_RAM + 0x2628u;
	d0 = 0xC4u;
	do
	{
		mem_write8(a0, d0);
		mem_write8(a0 + 0x80u, d0);
		mem_write8(a0 + 0x100u, d0);
		mem_write8(a0 + 0x180u, d0);
		a0 += 2u;
	} while (a0 < TILE_RAM + 0x2630u);
	a0 = unk_062000_ADDRESS;
	unk_0633E2 = 0u;
	a1 = unk_0633E6_ADDRESS;
	unk_0633E6 = 0x8090A0Bu;
	do
	{
		if ((mem_read8(a0) & 1u) == 0u)
			mem_write8(a1, 0xFFu);
		else
			unk_0633E2++;
		a0 += 0x50u;
		a1++;
	} while (a0 < 0x62140u);
	unk_0633E2--;
	a0 = unk_062000_ADDRESS;
	a1 = unk_062050_ADDRESS;
	a2 = unk_0633E6_ADDRESS;
	a3 = 0x633E7u;
	a4 = unk_060104_ADDRESS;
	a5 = unk_06010C_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) == 0u)
		{
			a4 += 8u;
			a0 += 0x50u;
			a2++;
		}
		else if ((mem_read8(a1) & 1u) != 0u && mem_read16(a4) <= mem_read16(a5))
		{
			a0 = a1;
			a2 = a3;
			a4 = a5;
		}
		a5 += 8u;
		a1 += 0x50u;
		a3++;
	} while (a1 < 0x62140u);
	d0 = mem_read8(a2);
	mem_write8(a2, 0xFFu);
	a5 = animations_02C640_ADDRESS;
	a0 = unk_0623C0_ADDRESS;
	do
	{
		mem_write8(a0, 1u);
		mem_write16(a0 + 0x10u, 0u);
		mem_write16(a0 + 0x42u, 0xFF00u);
		mem_write16(a0 + 0xCu, 0xB8u);
		mem_write16(a0 + 0xEu, 0x80u);
		a6 = DATA32(a5);
		a5 += 4u;
		d1_2 = set_animation(d1_2, a0, a6);
		a0 += 0x50u;
	} while (a0 < 0x62500u);
	unk_06241F = 0x78u;
	unk_0623C0 = 0x81u;
	unk_062402 = d0;
	unk_062452 = d0;
	a0 = unk_062DC0_ADDRESS;
	a1 = unk_0633E6_ADDRESS;
	a2 = 0x2C650u;
	while (unk_0633E2 != 0u)
	{
		unk_0633E2--;
		mem_write8(a0, 0x81u);
		mem_write16(a0 + 0x10u, 0u);
		mem_write16(a0 + 0xCu, 0x90u);
		mem_write16(a0 + 0xEu, 0xB8u);
		mem_write8(a0 + 0x43u, 0u);
		do
		{
			t1 = mem_read8(a1);
			d0 = t1;
			a1++;
		} while ((int8_t)t1 < 0);
		mem_write8(a0 + 0x42u, d0);
		mem_write8(a1 - 1u, 0xFFu);
		a6 = DATA32(a2);
		a2 += 4u;
		d1_2 = set_animation(d1_2, a0, a6);
		a0 += 0x50u;
	}
	unk_0633DE = 0u;
	func_02B7DA();
	return d1_2;
}

uint32_t func_02C65C(uint32_t d1)
{
	uint8_t d0 = 0, d2_2 = 0, d3 = 0, d4 = 0;
	uint16_t d2 = 0, d3_2 = 0;
	uint32_t a0 = 0, d0_2 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;
	uint8_t t1 = 0;

	t1 = unk_0633DE;
	unk_0633DE = t1 - 1u;
	if (t1 == 1u)
	{
		unk_0633C8 = 0u;
		unk_0600BD = 0u;
		unk_060007++;
		return d1;
	}
	if (unk_060121 == 5u)
		return d1;
	if (unk_0633DE == 0xD0u)
	{
		d0_2 = 0x7Fu;
		d1_2 = 0x110u;
		d2 = 0x70u;
		d3_2 = 0x37u;
		func_0301D8(d2, d3_2, &d0_2, &d1_2, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
		func_02FFDA(ignored_5);
		return d1_2;
	}
	if (unk_0633DE == 0xB0u)
	{
		a0 = TILE_RAM + 0x2628u;
		d0 = 0xA5u;
		d1_2 = 0xDDu;
		d2_2 = 0xE1u;
		d3 = 0xE5u;
		d4 = 0xE8u;
		do
		{
			mem_write8(a0, d0);
			mem_write8(a0 + 0x80u, d0);
			mem_write8(a0 + 0x100u, d0);
			mem_write8(a0 + 0x180u, d0);
			mem_write8(a0 + 1u, d1_2);
			mem_write8(a0 + 0x81u, d2_2);
			mem_write8(a0 + 0x101u, d3);
			mem_write8(a0 + 0x181u, d4);
			d1_2 = (uint8_t)(d1_2 + 1u);
			d2_2++;
			d3++;
			d4++;
			a0 += 2u;
		} while (a0 < TILE_RAM + 0x2630u);
		io_write8(TILES_1027A9, 0x21u);
		return d1_2;
	}
	if (unk_0633DE == 0x90u)
	{
		unk_063312 = 0x46722u;
		unk_063316 = 0x46822u;
		unk_063310 = 0x20u;
		a0 = TILE_RAM + 0x2000u;
		d1_2 = func_01E11E(a0);
		unk_062410 = 0x81u;
		return d1_2;
	}
	if (unk_0633DE == 0x70u)
	{
		unk_0624B0 = 0x81u;
		return d1;
	}
	if (unk_0633DE == 0x50u)
	{
		unk_063312 = 0x46622u;
		unk_063316 = 0x46822u;
		unk_063310 = 0x20u;
		a0 = TILE_RAM + 0x2000u;
		d1_2 = func_01E11E(a0);
		a0 = TILE_RAM + 0x2628u;
		d0 = 0xC4u;
		do
		{
			mem_write8(a0, d0);
			mem_write8(a0 + 0x80u, d0);
			mem_write8(a0 + 0x100u, d0);
			mem_write8(a0 + 0x180u, d0);
			a0 += 2u;
		} while (a0 < TILE_RAM + 0x2630u);
		unk_062460 = 0x81u;
		unk_0624BE++;
		return d1_2;
	}
	if (unk_0633DE >= 0x70u)
		return d1;
	if (unk_0633DE >= 0x30u)
	{
		unk_0624BE++;
		return d1;
	}
	unk_0624B0 = 0u;
	return d1;
}

void func_02C7E6(uint8_t d0, uint16_t d1, uint32_t a0)
{
	uint32_t d6 = 0, d7 = 0, ignored = 0;
	uint32_t t1 = 0, t2 = 0;

	func_047CCC(d0, d1, &d6, &d7, &ignored);
	t1 = mem_read32(a0 + 0x12u) + (int16_t)d6;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	t2 = mem_read32(a0 + 0x16u) + (int16_t)d7;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
	func_02C7F8(a0);
}

void func_02C7F8(uint32_t a0)
{
	uint16_t d4 = 0;

	d4 = (uint16_t)(mem_read32(a0 + 0x16u) >> 8);
	mem_write16(a0 + 0xCu, mem_read32(a0 + 0x12u) >> 8);
	mem_write16(a0 + 0xEu, d4);
}

uint32_t func_02C80E(uint32_t d1)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;

	unk_0633CB = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u && (mem_read8(a0) & 0x80u) != 0u)
		{
			if (mem_read8(a0 + 0x1Du) == 0u)
			{
				unk_0633CB--;
				if (mem_read16(a0 + 0xCu) < 0x1A0u)
				{
					mem_write16(a0 + 0xCu, mem_read16(a0 + 0xCu) + 4u);
					if ((uint16_t)((mem_read16(a0 + 0x10u) >> 8) + mem_read16(a0 + 0xEu)) < 0x100u)
						mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x600u);
				}
				else
					mem_write8(a0, mem_read8(a0) & 0x7Fu);
			}
			else
			{
				unk_0633CB--;
				t1 = mem_read8(a0 + 0x1Du);
				mem_write8(a0 + 0x1Du, t1 - 1u);
				if (t1 == 1u)
				{
					mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
					d0 = 0x201u;
					func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
				}
			}
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB == 0u)
	{
		unk_0633C8 = 0u;
		unk_0600BD = 0u;
		unk_060007++;
		return d1;
	}
	return d1;
}

uint32_t func_02C8A0(uint32_t d1, uint32_t d2)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, ignored = 0, ignored_2 = 0;
	uint32_t t1 = 0, t2 = 0;

	a0 = func_01A2D6();
	if (unk_0633EA < 4u)
	{
		func_01E712();
		t1 = unk_063300 + unk_06330C;
		unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
		unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
		t2 = unk_063300 & 0x1FFFFu;
		unk_063300 = (unk_063300 & 0xFFFF0000u) | (t2 & 0xFFFFu);
		unk_063300 = (unk_063300 & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
		func_01E732();
	}
	func_01E708();
	d0 = (uint16_t)((uint32_t)unk_0633EA << 2);
	switch (d0)
	{
	case 0:
		func_02C952(d2, &d1, &a0);
		break;
	case 4:
		func_02CA0C(d2, &d1, &a0);
		break;
	case 8:
		func_02CB80(&d1, &a0);
		break;
	case 12:
		func_02CBFE(d0, &d1, &a0);
		break;
	case 16:
		a0 = func_02CCA0(a0);
		break;
	case 20:
		func_02CD84();
		break;
	}
	if (unk_0633EA < 4u)
	{
		d1 = func_01ACDA(d1, a0);
		unk_0633CC = TILE_RAM + 0x2000u;
		func_01E9C2(&d1, &ignored, &ignored_2);
		unk_062001 |= 0x80u;
		unk_062051 |= 0x80u;
		unk_0620A1 |= 0x80u;
		unk_0620F1 |= 0x80u;
	}
	func_01E728();
	func_01ECAA();
	return d1;
}

void func_02C952(uint32_t d2, uint32_t *p_d1, uint32_t *p_a0)
{
	uint32_t d1 = *p_d1;
	uint8_t d7 = 0;
	uint32_t a0 = 0, a6 = 0, d0 = 0;

	unk_0633CB = 0u;
	func_02CDA2();
	a0 = unk_062000_ADDRESS;
	do
	{
		func_02CDC0(a0, &d1, &d2);
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB == 0u)
	{
		a0 = unk_062C80_ADDRESS;
		unk_062C80 = 0x8100u;
		unk_062CD0 = 0x8100u;
		AT16(unk_062CC2, -1) = 0xFF00u;
		AT16(unk_062D12, -1) = 0xFF00u;
		unk_062C8C = 0x50u;
		unk_062CDC = 0x50u;
		d1 = 0u;
		unk_062C90 = 0x50u;
		unk_062CE0 = 0x50u;
		d0 = indexed_table_of_32_bit_values_005000_ADDRESS;
		unk_062C92 = d0;
		unk_062CE2 = d0;
		unk_062C96 = 0xA000u;
		unk_062C8E = 0xA0u;
		unk_062CE6 = 0x9C00u;
		unk_062CDE = 0x9Cu;
		unk_062C9A = 0x600u;
		a6 = 0x2D8C8u;
		d1 = set_animation(d1, a0, a6);
		a6 = 0x2D8E2u;
		a0 = unk_062CD0_ADDRESS;
		d1 = set_animation(d1, a0, a6);
		d7 = 0x15u;
		func_0091A4(d7, a6);
		func_02B7DA();
	}
	*p_d1 = d1;
	*p_a0 = a0;
}

void func_02CA0C(uint32_t d2, uint32_t *p_d1, uint32_t *p_a0)
{
	uint32_t d1 = *p_d1;
	uint16_t d0 = 0;
	uint32_t a0 = 0, d0_2 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t6 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint32_t t2 = 0, t7 = 0;

	a0 = unk_062C80_ADDRESS;
	if (unk_062C9A != 0u)
	{
		t1 = unk_062C9A;
		unk_062C9A = t1 - 0x14u;
		if (t1 < 0x14u)
			unk_062C9A = 0u;
		t2 = unk_062C92 + unk_062C9A;
		AS16(unk_062C92) = t2;
		AT16(unk_062C92, 2) = t2 >> 16;
		d0_2 = unk_062C92;
		unk_062CE2 = d0_2;
		d0_2 = d0_2 >> 8;
		unk_062C8C = d0_2;
		unk_062CDC = d0_2;
	}
	else if (unk_062C92 - unk_062CE2 >= 0x4000u)
	{
		a0 = unk_062000_ADDRESS;
		do
		{
			if ((mem_read8(a0) & 1u) != 0u && (mem_read8(a0) & 0x80u) != 0u)
			{
				t3 = mem_read16(a0 + 0xEu);
				d0 = (uint16_t)(t3 - 0x4Du);
				if (t3 < 0x4Du || d0 >= 7u)
				{
					mem_write16(a0 + 0x1Cu, 0u);
					mem_write16(a0 + 0x10u, 0u);
					d1_2 = (d1 & ~0xFFFFu) | 0xA0u;
					d2 = (d2 & ~0xFFFFu) | 0x50u;
					direction_to(a0, &d0_2, &d1_2, &d2);
					d1 = (d1_2 & ~0xFFFFu) | 0x200u;
					func_02C7E6((uint8_t)d0_2, (uint16_t)d1, a0);
				}
				else
				{
					t4 = mem_read16(a0 + 0xCu);
					d0 = (uint16_t)(t4 - 0x9Du);
					if (t4 < 0x9Du || d0 >= 7u)
					{
						mem_write16(a0 + 0x1Cu, 0u);
						mem_write16(a0 + 0x10u, 0u);
						d1_2 = (d1 & ~0xFFFFu) | 0xA0u;
						d2 = (d2 & ~0xFFFFu) | 0x50u;
						direction_to(a0, &d0_2, &d1_2, &d2);
						d1 = (d1_2 & ~0xFFFFu) | 0x200u;
						func_02C7E6((uint8_t)d0_2, (uint16_t)d1, a0);
					}
					else
					{
						if (mem_read8(a0 + 0x1Du) == 0u && mem_read16(a0 + 0x10u) == 0u)
						{
							mem_write16(a0 + 0x1Au, 0x400u);
							mem_write8(a0 + 0x1Du, 8u);
							d0 = 0x200u;
							func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
						}
						if (mem_read8(a0 + 0x1Du) == 0u)
						{
							if (mem_read8(a0 + 0x1Cu) != 0u)
							{
								mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - mem_read16(a0 + 0x1Au));
								mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x40u);
								if (mem_read16(a0 + 0x10u) < 0x1800u)
									mem_write8(a0, mem_read8(a0) & 0x7Fu);
							}
							else
							{
								mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
								t5 = mem_read16(a0 + 0x1Au);
								mem_write16(a0 + 0x1Au, t5 - 0x40u);
								if (t5 < 0x40u)
								{
									mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
									mem_write8(a0 + 0x1Cu, mem_read8(a0 + 0x1Cu) - 1u);
									mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - mem_read16(a0 + 0x1Au));
									mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x40u);
									if (mem_read16(a0 + 0x10u) < 0x1800u)
										mem_write8(a0, mem_read8(a0) & 0x7Fu);
								}
							}
						}
						else
						{
							t6 = mem_read8(a0 + 0x1Du);
							mem_write8(a0 + 0x1Du, t6 - 1u);
							if (t6 == 1u)
							{
								d0 = 0x201u;
								func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
								if (mem_read8(a0 + 0x1Cu) != 0u)
								{
									mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - mem_read16(a0 + 0x1Au));
									mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x40u);
									if (mem_read16(a0 + 0x10u) < 0x1800u)
										mem_write8(a0, mem_read8(a0) & 0x7Fu);
								}
								else
								{
									mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
									t5 = mem_read16(a0 + 0x1Au);
									mem_write16(a0 + 0x1Au, t5 - 0x40u);
									if (t5 < 0x40u)
									{
										mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
										mem_write8(a0 + 0x1Cu, mem_read8(a0 + 0x1Cu) - 1u);
										mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - mem_read16(a0 + 0x1Au));
										mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x40u);
										if (mem_read16(a0 + 0x10u) < 0x1800u)
											mem_write8(a0, mem_read8(a0) & 0x7Fu);
									}
								}
							}
						}
					}
				}
			}
			a0 += 0x50u;
		} while (a0 < 0x62140u);
	}
	else
	{
		t7 = unk_062CE2 - 0x300u;
		AS16(unk_062CE2) = t7;
		AT16(unk_062CE2, 2) = t7 >> 16;
		unk_062CDC = unk_062CE2 >> 8;
	}
	func_02CDA2();
	a0 = unk_062000_ADDRESS;
	while ((mem_read8(a0) & 0x80u) == 0u)
	{
		a0 += 0x50u;
		if (a0 >= 0x62140u)
		{
			func_02B7DA();
			break;
		}
	}
	*p_d1 = d1;
	*p_a0 = a0;
}

void func_02CB80(uint32_t *p_d1, uint32_t *p_a0)
{
	uint8_t d7 = 0;
	uint32_t d0 = 0;
	uint32_t t1 = 0;

	func_02CDA2();
	*p_a0 = unk_062C80_ADDRESS;
	if (unk_062C92 == unk_062CE2)
	{
		if (unk_063300 >= 0x8A200u && unk_063300 < 0x8A800u)
		{
			unk_063308 = (unk_063300 & 0x700u) << 5;
			func_02B7DA();
		}
		return;
	}
	t1 = unk_062CE2 + 0x300u;
	AS16(unk_062CE2) = t1;
	AT16(unk_062CE2, 2) = t1 >> 16;
	d0 = unk_062CE2;
	*p_d1 = d0 >> 8;
	unk_062CDC = *p_d1;
	if (d0 < unk_062C92)
	{
		return;
	}
	unk_062CE2 = unk_062C92;
	unk_062CDC = unk_062C92 >> 8;
	d7 = 0x6Eu;
	func_0091A4(d7, 0u);
	if (unk_063300 >= 0x8A200u && unk_063300 < 0x8A800u)
	{
		unk_063308 = (unk_063300 & 0x700u) << 5;
		func_02B7DA();
	}
}

void func_02CBFE(uint32_t d0, uint32_t *p_d1, uint32_t *p_a0)
{
	uint8_t d7 = 0;
	uint16_t d2 = 0, d3 = 0, d7_2 = 0;
	uint32_t a6 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, ignored_6 = 0;

	if (unk_063300 >= 0xA0000u)
	{
		if (unk_063300 >= 0xA4000u)
		{
			if (unk_063300 >= 0xA4600u)
			{
				if (unk_063300 >= 0xA8000u)
				{
					unk_062C80 &= 0xFFu;
					unk_062CD0 &= 0xFFu;
					unk_060129 = 0xFFu;
					unk_063300 = 0x800u;
					unk_063340 = 0x800u;
					unk_063380 = 0x800u;
					func_031230(p_d1, p_a0);
					a6 = 0xA14Eu;
					d7_2 = 0x20Fu;
					post_palette_request(d7_2, a6);
					func_02B7DA();
				}
			}
			else
			{
				d7 = 0x3Cu;
				func_0091A4(d7, 0u);
			}
		}
	}
	else if (unk_061106 == 0u)
	{
		d0 &= ~0xFFu;
		*p_d1 = 0xC0u;
		d2 = 0x70u;
		d3 = 0x3Cu;
		func_0301D8(d2, d3, &d0, p_d1, &ignored_3, &ignored_4, &ignored_5, &ignored_6, &ignored);
		func_02FFDA(ignored);
	}
}

uint32_t func_02CCA0(uint32_t a0)
{
	uint32_t carry = 0;
	uint8_t d0 = 0, d1 = 0, d6 = 0, d7 = 0;
	uint32_t a0_2 = 0, a1 = 0, a5 = 0, a6 = 0, d1_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (unk_060083 != 0u)
		return a0;
	a0_2 = TILE_RAM + 0x4008u;
	d0 = 0x24u;
	d1 = 0u;
	d7 = 0x20u;
	do
	{
		d6 = 0x20u;
		do
		{
			mem_write8(a0_2, d0);
			mem_write8(a0_2 + 1u, d1);
			carry = (uint8_t)(d1 + 1u) < d1;
			d1++;
			a0_2 += 2u;
			if (carry)
				d0++;
			t1 = d6;
			d6 = (uint8_t)(t1 - 1u);
		} while (t1 != 1u);
		t2 = d7;
		d7 = (uint8_t)(t2 - 1u);
		a0_2 += 0x40u;
	} while (t2 != 1u);
	io_write8(TILES_106B00, 0xE0u);
	unk_060064 = 0xE0u;
	a0_2 = TILE_RAM + 0x2220u;
	d0 = 0x13u;
	d1_2 = 0u;
	d7 = 0x10u;
	do
	{
		d6 = 0x10u;
		do
		{
			mem_write8(a0_2, d0);
			mem_write8(a0_2 + 1u, d1_2);
			d1_2 = (uint8_t)(d1_2 + 1u);
			t3 = d6;
			d6 = (uint8_t)(t3 - 1u);
			a0_2 += 2u;
		} while (t3 != 1u);
		t4 = d7;
		d7 = (uint8_t)(t4 - 1u);
		a0_2 += 0x60u;
	} while (t4 != 1u);
	a5 = animations_02CD74_ADDRESS;
	a0_2 = unk_062DC0_ADDRESS;
	a1 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a1) & 1u) != 0u)
		{
			mem_write8(a0_2, 0x81u);
			mem_write16(a0_2 + 0x10u, 0u);
			mem_write16(a0_2 + 0x42u, 0xFF00u);
			mem_write16(a0_2 + 0xCu, 0xF8u);
			mem_write16(a0_2 + 0xEu, 0x80u);
			a6 = DATA32(a5);
			set_animation(d1_2, a0_2, a6);
		}
		a1 += 0x50u;
		a5 += 4u;
		a0_2 += 0x50u;
	} while (a0_2 < unk_062F00_ADDRESS);
	d7 = 0x1Au;
	func_0091A4(d7, a6);
	unk_0633DE = 0xA0u;
	func_02B7DA();
	return a0_2;
}

void func_02CD84(void)
{
	uint8_t t1 = 0;

	t1 = unk_0633DE;
	unk_0633DE = t1 - 1u;
	if (t1 == 1u)
	{
		unk_0633C8 = 0u;
		unk_0600BD = 0u;
		unk_060007++;
	}
}

void func_02CDA2(void)
{
	uint32_t t1 = 0;

	unk_063308 = 0u;
	if (unk_063300 < 0xA0000u)
		return;
	t1 = unk_063300 & 0x80FFFu;
	unk_063300 = (unk_063300 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_063300 = (unk_063300 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
}

void func_02CDC0(uint32_t a0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint32_t d1 = *p_d1;
	uint32_t d2 = *p_d2;
	uint16_t d0 = 0;
	uint32_t d0_2 = 0, d1_2 = 0, d2_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t t1 = 0, t2 = 0;

	d0 = (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 2);
	d1_2 = (d1 & ~0xFFFFu) | indexed_table_of_16_bit_values_02CE62[d0 / 2u];
	d2_2 = (d2 & ~0xFFFFu) | rom_02CE64[d0 / 2u];
	t1 = mem_read16(a0 + 0xEu);
	d0 = (uint16_t)(t1 - 0x2Du);
	if (t1 < 0x2Du || d0 >= 7u)
	{
		unk_0633CB--;
		d0 = (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 2);
		d1_2 = (d1_2 & ~0xFFFFu) | indexed_table_of_16_bit_values_02CE62[d0 / 2u];
		d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(d1_2 + 3u);
		d2_2 = (d2_2 & ~0xFFFFu) | rom_02CE64[d0 / 2u];
		direction_to(a0, &d0_2, &d1_2, &d2_2);
		d1_2 = (d1_2 & ~0xFFFFu) | 0x200u;
		func_02C7E6((uint8_t)d0_2, (uint16_t)d1_2, a0);
	}
	else
	{
		t2 = mem_read16(a0 + 0xCu);
		d0 = (uint16_t)(t2 - d1_2);
		if (t2 < (uint16_t)d1_2 || d0 >= 7u)
		{
			unk_0633CB--;
			d0 = (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 2);
			d1_2 = (d1_2 & ~0xFFFFu) | indexed_table_of_16_bit_values_02CE62[d0 / 2u];
			d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(d1_2 + 3u);
			d2_2 = (d2_2 & ~0xFFFFu) | rom_02CE64[d0 / 2u];
			direction_to(a0, &d0_2, &d1_2, &d2_2);
			d1_2 = (d1_2 & ~0xFFFFu) | 0x200u;
			func_02C7E6((uint8_t)d0_2, (uint16_t)d1_2, a0);
		}
		else
		{
			d1_2 = (uint16_t)(d1_2 + 2u);
			d2_2 = (uint16_t)(d2_2 + 2u);
			mem_write16(a0 + 0xCu, d1_2);
			mem_write16(a0 + 0xEu, d2_2);
			d1_2 = (uint32_t)(int16_t)d1_2 << 8;
			d2_2 = (uint32_t)(int16_t)d2_2 << 8;
			mem_write32(a0 + 0x12u, d1_2);
			mem_write32(a0 + 0x16u, d2_2);
			mem_write8(a0 + 0x1Du, 0x10u);
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			d0 = 0x100u;
			func_01B8C2(d0, a0, &d1_2, &ignored, &ignored_2, &ignored_3, &ignored_4);
			mem_write8(a0 + 0x33u, 0u);
		}
	}
	*p_d1 = d1_2;
	*p_d2 = d2_2;
}

uint32_t func_02CE72(uint32_t d1, uint32_t d2)
{
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)unk_0633EA << 2);
	switch (d0)
	{
	case 0:
		func_02CEB6();
		break;
	case 4:
		d1 = func_02CEFA(d1);
		break;
	case 8:
		d1 = func_02CF2A(d1, d2);
		break;
	case 12:
		d1 = func_02D0AE(d1);
		break;
	case 16:
		d1 = func_02D1E4(d1);
		break;
	case 20:
		d1 = func_02D25E(d1);
		break;
	case 24:
		d1 = func_02D324(d1);
		break;
	case 28:
		d1 = func_02D3D2(d0, d1);
		break;
	case 32:
		func_02D48A();
		break;
	case 36:
		func_02D504();
		break;
	}
	func_01ECAA();
	return d1;
}

void func_02CEB6(void)
{
	uint32_t a0 = 0, a6 = 0;
	uint16_t t1 = 0;

	a0 = unk_062DC0_ADDRESS;
	t1 = unk_062DD0;
	unk_062DD0 = t1 - 0x100u;
	if (t1 == 0x100u)
	{
		unk_0633DE = 0x80u;
		unk_062DC1 = 0u;
		a6 = 0x2DB28u;
		set_animation(0u, a0, a6);
		func_02B7DA();
		return;
	}
	if (unk_062DD0 == 0x2000u)
	{
		a6 = 0x2DB1Eu;
		set_animation(0u, a0, a6);
		return;
	}
}

uint32_t func_02CEFA(uint32_t d1)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;

	t1 = unk_0633DE;
	unk_0633DE = t1 - 1u;
	if (t1 != 1u)
		return d1;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			d0 = 0x101u;
			func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	func_02B7DA();
	return d1;
}

uint32_t func_02CF2A(uint32_t d1, uint32_t d2)
{
	uint16_t d0_2 = 0, d7 = 0;
	uint32_t a0 = 0, a6 = 0, d0 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	unk_0633CB = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u && (mem_read8(a0) & 0x80u) != 0u)
		{
			unk_0633CB--;
			if (mem_read32(a0 + 0x16u) < 0x7000u || mem_read32(a0 + 0x12u) < 0xF000u || mem_read32(a0 + 0x12u) > 0x10FFFu)
			{
				d1_2 = (d1 & ~0xFFFFu) | 0x100u;
				d2 = (d2 & ~0xFFFFu) | 0x90u;
				direction_to(a0, &d0, &d1_2, &d2);
				d1 = (d1_2 & ~0xFFFFu) | 0x200u;
				func_02C7E6((uint8_t)d0, (uint16_t)d1, a0);
			}
			else if (mem_read16(a0 + 0x10u) != 0u)
			{
				if (mem_read8(a0 + 0x1Cu) != 0u)
				{
					d0_2 = mem_read16(a0 + 0x1Au);
					t1 = mem_read16(a0 + 0x10u);
					mem_write16(a0 + 0x10u, t1 - d0_2);
					if (t1 < d0_2)
						mem_write8(a0, mem_read8(a0) & 0x7Fu);
					else
						mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x20u);
				}
				else
				{
					mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
					t2 = mem_read16(a0 + 0x1Au);
					mem_write16(a0 + 0x1Au, t2 - 0x30u);
					if (t2 < 0x30u)
					{
						mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
						mem_write8(a0 + 0x1Cu, mem_read8(a0 + 0x1Cu) - 1u);
						d0_2 = 0x203u;
						func_01B8C2(d0_2, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
					}
				}
				if (mem_read32(a0 + 0x16u) < 0x8400u)
				{
					d1_2 = (d1 & ~0xFFFFu) | 0x100u;
					d2 = (d2 & ~0xFFFFu) | 0x90u;
					direction_to(a0, &d0, &d1_2, &d2);
					d1 = (d1_2 & ~0xFFFFu) | 0x200u;
					func_02C7E6((uint8_t)d0, (uint16_t)d1, a0);
				}
			}
			else
			{
				if (mem_read8(a0 + 0x1Du) == 0u)
				{
					mem_write8(a0 + 0x1Du, 8u);
					d0_2 = 0x200u;
					func_01B8C2(d0_2, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
					mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
				}
				t3 = mem_read8(a0 + 0x1Du);
				mem_write8(a0 + 0x1Du, t3 - 1u);
				if (t3 == 1u)
				{
					d0_2 = 0x201u;
					func_01B8C2(d0_2, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
					mem_write16(a0 + 0x1Au, 0x500u);
					if (mem_read8(a0 + 0x1Cu) != 0u)
					{
						d0_2 = mem_read16(a0 + 0x1Au);
						t1 = mem_read16(a0 + 0x10u);
						mem_write16(a0 + 0x10u, t1 - d0_2);
						if (t1 < d0_2)
							mem_write8(a0, mem_read8(a0) & 0x7Fu);
						else
							mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x20u);
					}
					else
					{
						mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
						t2 = mem_read16(a0 + 0x1Au);
						mem_write16(a0 + 0x1Au, t2 - 0x30u);
						if (t2 < 0x30u)
						{
							mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
							mem_write8(a0 + 0x1Cu, mem_read8(a0 + 0x1Cu) - 1u);
							d0_2 = 0x203u;
							func_01B8C2(d0_2, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
						}
					}
					if (mem_read32(a0 + 0x16u) < 0x8400u)
					{
						d1_2 = (d1 & ~0xFFFFu) | 0x100u;
						d2 = (d2 & ~0xFFFFu) | 0x90u;
						direction_to(a0, &d0, &d1_2, &d2);
						d1 = (d1_2 & ~0xFFFFu) | 0x200u;
						func_02C7E6((uint8_t)d0, (uint16_t)d1, a0);
					}
				}
			}
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB != 0u)
		return d1;
	unk_062DC0 = 0u;
	a0 = 0x62A00u;
	do
	{
		mem_write8(a0, 0u);
		a0 += 0x50u;
	} while (a0 < unk_062C80_ADDRESS);
	a0 = unk_0623C0_ADDRESS;
	do
	{
		mem_write8(a0, 0u);
		a0 += 0x50u;
	} while (a0 < 0x62780u);
	unk_060129 = 0xFFu;
	func_031230(&d1_2, &ignored_5);
	unk_063300 &= 0xFFFF0000u;
	unk_063300 &= 0xFFFFu;
	unk_063340 &= 0xFFFF0000u;
	unk_063340 &= 0xFFFFu;
	unk_063380 &= 0xFFFF0000u;
	unk_063380 &= 0xFFFFu;
	a6 = 0xA12Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	func_02B7DA();
	return d1_2;
}

uint32_t func_02D0AE(uint32_t d1)
{
	uint8_t d0 = 0;
	uint32_t a0 = 0, a1 = 0, d1_2 = 0;
	uint8_t t1 = 0;

	if (unk_060083 != 0u)
		return d1;
	io_write8(TILES_106B00, 0x70u);
	unk_060064 = 0x70u;
	unk_063312 = layers_031280_ADDRESS;
	unk_063316 = 0x31380u;
	unk_063310 = 0x20u;
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	a0 = TILE_RAM + 0x4208u;
	a1 = table_loaded_by_lea_02D164_ADDRESS;
	d0 = 0x10u;
	d1_2 = 0x37u;
	do
	{
		mem_write8(a0, d1_2);
		mem_write8(a0 + 0x80u, d1_2);
		mem_write8(a0 + 0x100u, d1_2);
		mem_write8(a0 + 0x180u, d1_2);
		mem_write8(a0 + 0x200u, d1_2);
		mem_write8(a0 + 0x280u, d1_2);
		mem_write8(a0 + 0x300u, d1_2);
		mem_write8(a0 + 0x380u, d1_2);
		mem_write8(a0 + 1u, DATA8(a1));
		mem_write8(a0 + 0x81u, DATA8(a1 + 0x10u));
		mem_write8(a0 + 0x101u, DATA8(a1 + 0x20u));
		mem_write8(a0 + 0x181u, DATA8(a1 + 0x30u));
		mem_write8(a0 + 0x201u, DATA8(a1 + 0x40u));
		mem_write8(a0 + 0x281u, DATA8(a1 + 0x50u));
		mem_write8(a0 + 0x301u, DATA8(a1 + 0x60u));
		mem_write8(a0 + 0x381u, DATA8(a1 + 0x70u));
		a0 += 2u;
		t1 = d0;
		d0 = (uint8_t)(t1 - 1u);
		a1++;
	} while (t1 != 1u);
	unk_0633DE = 0xB0u;
	func_02B7DA();
	return d1_2;
}

void unreached_02D1D6(uint32_t a2)
{
	mem_write16(a2, mem_read16(a2) + 1u);
	mem_write16(a2, mem_read16(a2) + 1u);
	mem_write16(a2, mem_read16(a2) + 1u);
	mem_write16(a2, mem_read16(a2) + 1u);
	lost_stack(0x02D1DEu);
}

uint32_t func_02D1E4(uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d7_2 = 0;
	uint32_t a0 = 0, a6 = 0, d1_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	t1 = unk_0633DE;
	unk_0633DE = t1 - 1u;
	if (t1 == 1u)
	{
		func_031230(&d1_2, &ignored);
		a6 = 0xA15Eu;
		d7_2 = 0x20Fu;
		post_palette_request(d7_2, a6);
		func_02B7DA();
		return d1_2;
	}
	if (unk_0633DE != 0x80u)
	{
		if (unk_0633DE != 0x30u)
			return d1;
		unk_062DC0 = 0u;
		return d1;
	}
	d7 = 0xB4u;
	func_0091A4(d7, 0u);
	a0 = unk_062DC0_ADDRESS;
	unk_062DC0 = 0x81u;
	unk_062DC1 = 0u;
	unk_062DD0 = 0u;
	unk_062E02 = 0xFF00u;
	unk_062DCC = 0x100u;
	unk_062DCE = 0x80u;
	a6 = 0x2DEE6u;
	return set_animation(d1, a0, a6);
}

uint32_t func_02D25E(uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0, d1_2 = 0;
	uint32_t a0 = 0, d1_3 = 0, d3 = 0, d4 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, ignored_6 = 0;

	if (unk_060083 != 0u)
		return d1;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			mem_write16(a0, 0x8100u);
			d1_2 = (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 3);
			d3 = indexed_table_of_16_bit_values_02D304[d1_2 / 2u];
			d4 = rom_02D306[d1_2 / 2u];
			mem_write16(a0 + 0x10u, rom_02D308[d1_2 / 2u]);
			mem_write16(a0 + 0x20u, rom_02D30A[d1_2 / 2u]);
			mem_write16(a0 + 0xCu, d3);
			mem_write16(a0 + 0xEu, d4);
			mem_write32(a0 + 0x12u, d3 << 8);
			mem_write32(a0 + 0x16u, d4 << 8);
			d0 = 0x203u;
			func_01B8C2(d0, a0, &ignored, &ignored_3, &ignored_4, &ignored_5, &ignored_6);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	unk_063300 = 0x2000u;
	unk_063340 = 0x2000u;
	unk_063380 = 0x2000u;
	d1_3 = func_02FF44();
	unk_060059 = 0u;
	io_write8(PRIORITY_0C0001, 0u);
	d7 = 0x75u;
	func_0091A4(d7, 0u);
	func_02B7DA();
	return d1_3;
}

uint32_t func_02D324(uint32_t d1)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;
	uint16_t t3 = 0;
	uint32_t t2 = 0;

	unk_0633CB = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			if (mem_read8(a0 + 0x1Du) != 0u)
			{
				unk_0633CB--;
				t1 = mem_read8(a0 + 0x1Du);
				mem_write8(a0 + 0x1Du, t1 - 1u);
				if (t1 == 1u)
				{
					if (mem_read16(a0 + 0xCu) >= 0x100u)
						mem_write8(a0, mem_read8(a0) | 0x40u);
					d0 = 0x101u;
					func_01B8C2(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
					mem_write8(a0 + 0x33u, 0u);
				}
			}
			else if (mem_read8(a0 + 4u) != 1u)
			{
				unk_0633CB--;
				t2 = mem_read32(a0 + 0x12u) + 0x300u;
				mem_write16(a0 + 0x14u, t2);
				mem_write16(a0 + 0x12u, t2 >> 16);
				d1 = mem_read32(a0 + 0x12u) >> 8;
				mem_write16(a0 + 0xCu, d1);
				t3 = mem_read16(a0 + 0x10u);
				mem_write16(a0 + 0x10u, t3 - 0x600u);
				if (t3 < 0x600u)
				{
					mem_write16(a0 + 0x10u, 0u);
					mem_write8(a0 + 0x1Du, 8u);
					mem_write8(a0 + 5u, 0u);
					d1 = func_01B920(d1, a0);
				}
			}
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB != 0u)
		return d1;
	unk_0633DE = 0xA0u;
	func_02B7DA();
	return d1;
}

uint32_t func_02D3D2(uint32_t d0, uint32_t d1)
{
	uint16_t d0_2 = 0, d2 = 0, d3 = 0;
	uint32_t a0 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;
	uint8_t t1 = 0;

	t1 = unk_0633DE;
	unk_0633DE = t1 - 1u;
	if (t1 != 1u)
	{
		if (unk_0633DE == 0x30u)
		{
			func_03030C(&ignored_2, &ignored_3, &ignored_4);
			return d1;
		}
		if (unk_0633DE != 0x70u)
		{
			if (unk_0633DE != 8u)
				return d1;
			a0 = unk_062000_ADDRESS;
			do
			{
				if ((mem_read8(a0) & 1u) != 0u)
				{
					d0_2 = 0x200u;
					func_01B8C2(d0_2, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
				}
				a0 += 0x50u;
			} while (a0 < 0x62140u);
			return d1;
		}
		a0 = unk_062000_ADDRESS;
		while ((mem_read8(a0) & 1u) == 0u)
		{
			a0 += 0x50u;
			if (a0 >= 0x62140u)
				return d1;
		}
		d0 &= ~0xFFu;
		if (mem_read16(a0 + 0xCu) >= 0x100u)
			d0 |= (uint8_t)(d0 - 1u);
		d1_2 = mem_read16(a0 + 0xCu);
		d2 = 8u;
		d3 = 0xFu;
		func_0301D8(d2, d3, &d0, &d1_2, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
		func_02FFDA(ignored_5);
		return d1_2;
	}
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			d0_2 = 0x201u;
			func_01B8C2(d0_2, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	func_02B7DA();
	return d1;
}

void func_02D48A(void)
{
	uint32_t a0 = 0, a6 = 0, ignored = 0;
	uint32_t t1 = 0;

	unk_0633CB = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			if (mem_read16(a0 + 0xEu) >= 0x100u)
			{
				a6 = DATA32(animations_02D4F4_ADDRESS + (uint16_t)((uint32_t)mem_read8(a0 + 2u) << 2));
				set_animation(ignored, a0, a6);
			}
			else
			{
				unk_0633CB--;
				t1 = mem_read32(a0 + 0x16u) + 0x600u;
				mem_write16(a0 + 0x18u, t1);
				mem_write16(a0 + 0x16u, t1 >> 16);
				mem_write16(a0 + 0xEu, mem_read32(a0 + 0x16u) >> 8);
			}
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB == 0u)
	{
		func_02B7DA();
		return;
	}
}

void func_02D504(void)
{
	uint32_t a0 = 0;
	uint32_t t1 = 0, t2 = 0;

	unk_0633CB = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			if (mem_read8(a0 + 0x33u) != 0u)
			{
				t1 = mem_read32(a0 + 0x12u) + (int16_t)mem_read16(a0 + 0x20u);
				mem_write16(a0 + 0x14u, t1);
				mem_write16(a0 + 0x12u, t1 >> 16);
				mem_write16(a0 + 0xCu, mem_read32(a0 + 0x12u) >> 8);
				unk_0633CB--;
				t2 = mem_read32(a0 + 0x16u) - 0x100u;
				mem_write16(a0 + 0x18u, t2);
				mem_write16(a0 + 0x16u, t2 >> 16);
				mem_write16(a0 + 0xEu, mem_read32(a0 + 0x16u) >> 8);
			}
			else
				mem_write8(a0, mem_read8(a0) & 0x7Fu);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB != 0u)
		return;
	unk_0633C8 = 0u;
	unk_0600BD = 0u;
	unk_060007++;
}

uint32_t func_02D56E(uint32_t d1, uint32_t d2)
{
	uint32_t a0 = 0, d0 = 0, d1_2 = 0;
	uint8_t t1 = 0;

	t1 = unk_0633DE;
	unk_0633DE = t1 - 1u;
	if (t1 == 0u)
		unk_0633DE = 0u;
	unk_0633CB = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u && mem_read32(a0 + 0x12u) < 0x19000u)
		{
			unk_0633CB--;
			d1_2 = (d1 & ~0xFFFFu) | 0x198u;
			d2 = (d2 & ~0xFFFFu) | 0x58u;
			direction_to(a0, &d0, &d1_2, &d2);
			d1 = (d1_2 & ~0xFFFFu) | 0x200u;
			func_02C7E6((uint8_t)d0, (uint16_t)d1, a0);
			if (mem_read32(a0 + 0x12u) >= 0x18800u)
				mem_write8(a0, mem_read8(a0) & 0x7Fu);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633DE == 0u && unk_0633CB == 0u)
	{
		unk_0633C8 = 0u;
		unk_0600BD = 0u;
		unk_060007++;
	}
	return d1;
}

uint32_t func_02D600(uint32_t d1)
{
	switch (unk_0633EA)
	{
	case 0:
		return func_02D61E(d1);
	case 1:
		return func_02D73C(d1);
	}
}

uint32_t func_02D61E(uint32_t d1)
{
	uint8_t d2 = 0, d7 = 0;
	uint16_t d0 = 0;
	uint32_t a0 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;
	uint32_t t1 = 0;

	if (unk_0633DE != 0u)
	{
		unk_0633DE--;
		if (unk_0633DE >= 0x80u)
		{
			if (unk_0633DE != 0x80u)
				return d1;
			a0 = unk_062000_ADDRESS;
			do
			{
				if ((mem_read8(a0) & 1u) != 0u)
				{
					mem_write8(a0, mem_read8(a0) | 0x40u);
					d0 = 0x100u;
					func_01B8C2(d0, a0, &d1, &ignored, &ignored_3, &ignored_4, &ignored_5);
				}
				a0 += 0x50u;
			} while (a0 < 0x62140u);
			d7 = 0x34u;
			func_0091A4(d7, 0u);
		}
		if ((unk_0600A4 & 1u) == 0u)
		{
			d0 = unk_0633DF;
			unk_0633DF++;
			d0 = (uint16_t)((d0 & 7u) << 1);
			d1 = (d1 & ~0xFFu) | indexed_table_of_8_bit_values_030652[d0];
			d2 = rom_030653[d0];
			d1 = (d1 & ~0xFFFFu) | (uint16_t)(int8_t)d1;
			unk_060060 += d1;
			unk_060062 = (unk_060062 & 0xFF00u) | ((uint8_t)unk_060062 + d2 & 0xFFu);
		}
		if (unk_0633DE >= 0x70u)
		{
			if (unk_0633DE != 0x70u)
				return d1;
			a0 = unk_062000_ADDRESS;
			do
			{
				if ((mem_read8(a0) & 1u) != 0u)
				{
					d0 = 0x100u;
					func_01B8C2(d0, a0, &d1, &ignored, &ignored_3, &ignored_4, &ignored_5);
				}
				a0 += 0x50u;
			} while (a0 < 0x62140u);
		}
	}
	unk_0633CB = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u && mem_read32(a0 + 0x12u) >= 0x4000u)
		{
			unk_0633CB--;
			t1 = mem_read32(a0 + 0x12u) - 0x300u;
			mem_write16(a0 + 0x14u, t1);
			mem_write16(a0 + 0x12u, t1 >> 16);
			mem_write16(a0 + 0xCu, mem_read32(a0 + 0x12u) >> 8);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB != 0u)
		return d1;
	unk_0633DE = 0x80u;
	func_02B7DA();
	return d1;
}

uint32_t func_02D73C(uint32_t d1)
{
	uint8_t d2 = 0;
	uint16_t d0 = 0;
	uint8_t t1 = 0;

	if ((unk_0600A4 & 1u) == 0u)
	{
		d0 = unk_0633DF;
		unk_0633DF++;
		d0 = (uint16_t)((d0 & 7u) << 1);
		d1 = indexed_table_of_8_bit_values_030652[d0];
		d2 = rom_030653[d0];
		d1 = (uint16_t)(int8_t)d1;
		unk_060060 += d1;
		unk_060062 = (unk_060062 & 0xFF00u) | ((uint8_t)unk_060062 + d2 & 0xFFu);
	}
	t1 = unk_0633DE;
	unk_0633DE = t1 - 1u;
	if (t1 == 1u)
	{
		unk_0633C8 = 0u;
		unk_0600BD = 0u;
		unk_060007++;
	}
	return d1;
}

void func_02F5F0(uint32_t d6, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t carry = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	unk_060150++;
	unk_06111E = (uint8_t)(unk_060150 >> 8u) >> 5;
	if (unk_0633FC == 0u)
		func_02F61E(p_d1, &carry);
	else
	{
		t1 = unk_0633FC;
		unk_0633FC = t1 - 1u;
		if (t1 != 1u)
			func_02F61E(p_d1, &carry);
		else
		{
			func_03030C(&d5, &ignored, p_d7);
			func_02F61E(p_d1, &carry);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_02F61E(uint32_t *p_d1, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t d0 = 0;
	uint32_t d1 = 0;

	d1 = unk_060121;
	d1 = (uint16_t)(d1 << 3);
	d1 = (d1 & ~0xFFu) | DATA8(0x2F67Cu + d1 + unk_060130);
	d0 = 0u;
	switch (unk_060121)
	{
	case 0:
		carry = func_02F6CC(d0, (uint8_t)d1);
		break;
	case 1:
		carry = func_02F6F4(d0, (uint8_t)d1);
		break;
	case 2:
		carry = func_02F700(d0, (uint8_t)d1);
		break;
	case 3:
		carry = func_02F70C(d0, (uint8_t)d1);
		break;
	case 4:
		carry = func_02F718(d0, (uint8_t)d1);
		break;
	case 5:
		carry = func_02F724(d0, (uint8_t)d1);
		break;
	case 6:
		carry = func_02F730((uint8_t)d1);
		break;
	case 7:
		carry = func_02F738(d0, (uint8_t)d1);
		break;
	case 8:
		carry = func_02F754(d0, (uint8_t)d1);
		break;
	case 9:
		carry = func_02F780(d0, (uint8_t)d1);
		break;
	}
	*p_d1 = d1;
	*p_carry = carry;
}

uint32_t func_02F6CC(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < unk_06120C || unk_0633F5 != 0u)
		d0--;
	carry = 0u;
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | ((d0 & 0xFFu) << 16u);
	return carry;
}

uint32_t func_02F6F4(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < unk_06120C)
		d0--;
	carry = 0u;
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | ((d0 & 0xFFu) << 16u);
	return carry;
}

uint32_t func_02F700(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < unk_06120C)
		d0--;
	unk_0633C2 = (unk_0633C2 & 0xFFFFFF00u) | (d0 & 0xFFu);
	carry = 0u;
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | ((d0 & 0xFFu) << 16u);
	return carry;
}

uint32_t func_02F70C(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < unk_06120C)
		d0--;
	carry = 0u;
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | ((d0 & 0xFFu) << 16u);
	return carry;
}

uint32_t func_02F718(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < unk_06120C)
		d0--;
	carry = 0u;
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | ((d0 & 0xFFu) << 16u);
	return carry;
}

uint32_t func_02F724(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < unk_06120C)
		d0--;
	carry = 0u;
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | ((d0 & 0xFFu) << 16u);
	return carry;
}

uint32_t func_02F730(uint8_t d1)
{
	uint32_t carry = 0;

	carry = (uint8_t)d1 < unk_06120C;
	return carry;
}

uint32_t func_02F738(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	carry = 0u;
	if (unk_0633FE != 0u && (int8_t)unk_0633FE >= 0)
		return carry;
	if ((uint8_t)d1 < unk_06120C)
		d0--;
	carry = 0u;
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | ((d0 & 0xFFu) << 16u);
	return carry;
}

uint32_t func_02F754(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((unk_063380 < 0xB8000u && unk_063380 >= 0x58000u) || (uint8_t)d1 < unk_06120C)
		d0--;
	carry = 0u;
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | ((d0 & 0xFFu) << 16u);
	return carry;
}

uint32_t func_02F780(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < unk_06120C)
		d0--;
	carry = 0u;
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | ((d0 & 0xFFu) << 16u);
	return carry;
}

void func_02F790(void)
{
	uint32_t a0 = 0, a6 = 0, ignored = 0;

	unk_063412 = 0u;
	unk_063413 = 0u;
	unk_063410 = 0u;
	AT32(unk_0633DE, -3) = 0xE0000000u;
	unk_0633EA = 0u;
	unk_063352 = layers_03F196_ADDRESS;
	unk_063392 = layers_03E98A_ADDRESS;
	unk_063356 = 0x3F796u;
	unk_063396 = 0x3EB8Au;
	unk_063340 = 0u;
	unk_063380 = 0u;
	unk_063344 = 0x60000u;
	unk_063384 = 0x20000u;
	unk_063350 = 0x20u;
	unk_063390 = 0x20u;
	unk_06334C = 0u;
	unk_06334E = 0u;
	unk_06338C = 0u;
	unk_06338E = 0u;
	unk_06334A = 0u;
	unk_06338A = 0u;
	func_01E712();
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	func_01E732();
	func_01E708();
	a0 = TILE_RAM + 0x2000u;
	func_01E11E(a0);
	func_01E728();
	a0 = unk_062000_ADDRESS;
	unk_062000 = 0x81u;
	unk_062050 = 0x81u;
	unk_06200C = 0x88u;
	unk_06200E = 0xC4u;
	unk_06205C = 0x130u;
	unk_06205E = 0xA0u;
	unk_062001 = 0u;
	unk_062051 = 0u;
	unk_062010 = 0u;
	unk_062060 = 0u;
	unk_062042 = 0xFFu;
	unk_062092 = 0xFFu;
	a6 = 0x2DADCu;
	set_animation(ignored, a0, a6);
	a6 = 0x2DAD2u;
	a0 = unk_062050_ADDRESS;
	set_animation(ignored, a0, a6);
}

void func_02F8AA(uint16_t d6, uint32_t a5)
{
	uint16_t d0 = 0;

	d0 = unk_0633EA;
	switch ((uint8_t)((uint32_t)d0 << 2))
	{
	case 0:
		func_02F8EA(d6, a5);
		break;
	case 4:
		func_02F946();
		break;
	case 8:
		func_02F9F2();
		break;
	case 12:
		func_02FA7A();
		break;
	case 16:
		func_02FB54();
		break;
	case 20:
		func_02FBE8();
		break;
	case 24:
		func_02FD30();
		break;
	case 28:
		func_02FDF0();
		break;
	case 32:
		func_02FE44();
		break;
	}
	func_01ECAA();
}

void func_02F8EA(uint16_t d6, uint32_t a5)
{
	uint8_t d7 = 0;
	uint8_t t1 = 0;

	if ((uint8_t)(unk_063410 >> 8u) == 0u)
	{
		a5 = 0xA0AEu;
		d6 = 0xC02u;
		unk_063412 = 0u;
		unk_063413 = 0u;
		unk_063410 = 0u;
	}
	copy_palette_sets(d6, a5);
	if ((unk_0600A4 & 3u) == 0u)
	{
		unk_06200C++;
		unk_06205C--;
	}
	t1 = unk_0633DE;
	unk_0633DE = t1 - 1u;
	if (t1 == 1u)
	{
		func_02F9EA();
		return;
	}
	if (unk_0633DE != 0x30u)
		return;
	d7 = 0x7Du;
	func_0091A4(d7, 0u);
}

void func_02F946(void)
{
	uint32_t a0 = 0;

	if ((unk_0600A4 & 3u) == 0u)
	{
		unk_06200C++;
		unk_06205C--;
	}
	a0 = unk_062000_ADDRESS;
	unk_06200E += 2u;
	unk_06205E += 2u;
	if (unk_06205E >= 0x100u)
	{
		unk_062000 = 0u;
		unk_062050 = 0u;
	}
	func_01E712();
	unk_06330E = 0x200u;
	unk_0633CC = TILE_RAM + 0x4000u;
	func_02FE46();
	func_01E732();
	func_01E708();
	unk_06330E += 0x40u;
	if (unk_06330E >= 0x1000u)
		unk_06330E = 0xFFFu;
	unk_0633CC = TILE_RAM + 0x2000u;
	func_02FE46();
	func_01E728();
	if (unk_063344 >= 0x30000u)
		return;
	func_02F9EA();
}

void func_02F9EA(void)
{
	unk_0633EA++;
}

void func_02F9F2(void)
{
	uint32_t d0 = 0;
	uint32_t t1 = 0;

	func_01E708();
	unk_06330E += 0x20u;
	if (unk_06330E >= 0x1000u)
		unk_06330E = 0xFFFu;
	d0 = unk_06330E;
	t1 = unk_063304 - d0;
	unk_063304 = (unk_063304 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_063304 = (unk_063304 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
	unk_06330A -= d0 << 4;
	if (unk_063304 < 0x20000u)
	{
		unk_063304 = (unk_063304 & 0xFFFFu) | 0x20000u;
		unk_0633DF++;
	}
	func_01E728();
	if (unk_0633DF < 3u || unk_063344 < 0x2C000u)
		return;
	func_02F9EA();
}

void func_02FA7A(void)
{
	uint32_t a0 = 0, a6 = 0, ignored = 0;

	func_01E708();
	if (unk_063304 < 0x1A000u)
	{
		unk_06330E -= 0x60u;
		if (unk_06330E < 0x800u)
			unk_06330E = 0x800u;
	}
	unk_0633CC = TILE_RAM + 0x2000u;
	func_02FE46();
	func_01E728();
	if (unk_063304 < 0x14000u)
	{
		a0 = unk_062000_ADDRESS;
		unk_062000 = 0x81u;
		unk_062001 = 0u;
		unk_062042 = 0xFFu;
		unk_06200C = 0x100u;
		unk_062010 = 0u;
		unk_06200E = (0x11000u - unk_063304) >> 8;
		a6 = 0x2DA30u;
		set_animation(0u, a0, a6);
		a0 = unk_062050_ADDRESS;
		unk_062050 = 0x81u;
		unk_062051 = 0u;
		unk_062092 = 0xFFu;
		unk_06205C = 0x100u;
		unk_062060 = 0u;
		unk_06205E = (0x10000u - unk_063304) >> 8;
		a6 = 0x2DA26u;
		set_animation(ignored, a0, a6);
		if (unk_063304 == 0x10000u)
		{
			unk_0633DE = 0x30u;
			func_02F9EA();
			return;
		}
	}
}

void func_02FB54(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, a6 = 0;
	uint8_t t1 = 0;

	t1 = unk_0633DE;
	unk_0633DE = t1 - 1u;
	if (t1 != 1u)
		return;
	unk_0633DE = 0x40u;
	a0 = unk_0621E0_ADDRESS;
	unk_0621E0 = 0x8100u;
	unk_062222 = 0xFFu;
	unk_0621EC = 0x1000008u;
	a6 = 0x2DAB8u;
	set_animation(0u, a0, a6);
	a0 = unk_0620A0_ADDRESS;
	d0 = 0u;
	do
	{
		mem_write8(a0 + 2u, (uint8_t)d0);
		mem_write16(a0 + 0x1Cu, indexed_table_of_16_bit_values_02FBE0[d0 & 0x7FFFu]);
		mem_write16(a0 + 0x1Au, 0u);
		mem_write32(a0 + 0xCu, 0x1000014u);
		mem_write32(a0 + 0x12u, 0x10000u);
		mem_write32(a0 + 0x16u, 0x1400u);
		mem_write16(a0 + 0x10u, 0u);
		mem_write16(a0 + 0x42u, 0xFF08u);
		d0 = (uint8_t)(d0 + 1u);
		a0 += 0x50u;
	} while (a0 < unk_0621E0_ADDRESS);
	func_02F9EA();
}

void func_02FBE8(void)
{
	uint8_t d0_2 = 0, d1_2 = 0;
	uint16_t d0 = 0, d1 = 0, d6 = 0, d7 = 0;
	uint32_t a0 = 0, a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;
	uint8_t t2 = 0;
	uint16_t t3 = 0, t4 = 0;
	uint32_t t1 = 0;

	if (unk_0633DE == 0u)
	{
		a0 = unk_0620A0_ADDRESS;
		do
		{
			mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x240u);
			mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + mem_read16(a0 + 0x1Cu));
			t1 = mem_read32(a0 + 0x12u) + (int16_t)mem_read16(a0 + 0x1Au);
			mem_write16(a0 + 0x14u, t1);
			mem_write16(a0 + 0x12u, t1 >> 16);
			d1 = (uint16_t)(mem_read32(a0 + 0x16u) >> 8);
			mem_write16(a0 + 0xCu, mem_read32(a0 + 0x12u) >> 8);
			mem_write16(a0 + 0xEu, d1);
			a0 += 0x50u;
		} while (a0 < unk_0621E0_ADDRESS);
		if (unk_0620AC < 0xE0u)
			func_02F9EA();
	}
	else
	{
		t2 = unk_0633DE;
		unk_0633DE = t2 - 1u;
		if (t2 == 1u)
		{
			a0 = unk_0620A0_ADDRESS;
			do
			{
				mem_write16(a0, 0x8100u);
				d0 = 0x204u;
				func_01B8C2(d0, a0, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
				a0 += 0x50u;
			} while (a0 < unk_0621E0_ADDRESS);
			a0 = unk_0620A0_ADDRESS;
			do
			{
				mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x240u);
				mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + mem_read16(a0 + 0x1Cu));
				t1 = mem_read32(a0 + 0x12u) + (int16_t)mem_read16(a0 + 0x1Au);
				mem_write16(a0 + 0x14u, t1);
				mem_write16(a0 + 0x12u, t1 >> 16);
				d1 = (uint16_t)(mem_read32(a0 + 0x16u) >> 8);
				mem_write16(a0 + 0xCu, mem_read32(a0 + 0x12u) >> 8);
				mem_write16(a0 + 0xEu, d1);
				a0 += 0x50u;
			} while (a0 < unk_0621E0_ADDRESS);
			if (unk_0620AC < 0xE0u)
				func_02F9EA();
		}
		else if (unk_0633DE >= 0x20u)
		{
			if (unk_0633DE != 0x20u)
				return;
			a0 = unk_062230_ADDRESS;
			unk_062230 = 0x8100u;
			unk_062272 = 0xFF00u;
			unk_06223C = 0x1000050u;
			a6 = 0x2DA3Au;
			set_animation(0u, a0, a6);
			unk_062060 = 0x1000u;
			unk_062213 = 0u;
			return;
		}
	}
	d1_2 = 0x3Cu;
	if (unk_0633DE != 0x1Cu)
	{
		if (unk_0633DE == 0x1Au)
			d1_2 = 0x10u;
		else
		{
			d1_2 = 0x3Cu;
			if (unk_0633DE != 0x10u)
			{
				if (unk_0633DE != 0xEu)
				{
					a0 = unk_062050_ADDRESS;
					if (unk_062050 != 0u)
					{
						unk_062060 += 0x1000u;
						if ((uint8_t)(unk_062060 >> 8u) == 0xB0u)
						{
							unk_062050 = 0u;
							unk_062213 = 1u;
						}
					}
					return;
				}
				d1_2 = 0x10u;
			}
		}
	}
	a0 = TILE_RAM + 0x118u;
	d0_2 = 0u;
	d7 = 0x1Bu;
	do
	{
		d6 = 0x13u;
		do
		{
			mem_write8(a0, d0_2);
			a0++;
			mem_write8(a0, d1_2);
			a0++;
			mem_write8(a0, d0_2);
			a0++;
			mem_write8(a0, d1_2);
			t3 = d6 - 1u;
			d6 = t3;
			a0++;
		} while (t3 != 0xFFFFu);
		t4 = d7 - 1u;
		d7 = t4;
		a0 += 0x30u;
	} while (t4 != 0xFFFFu);
	a0 = unk_062050_ADDRESS;
	if (unk_062050 != 0u)
	{
		unk_062060 += 0x1000u;
		if ((uint8_t)(unk_062060 >> 8u) == 0xB0u)
		{
			unk_062050 = 0u;
			unk_062213 = 1u;
		}
	}
}

void func_02FD30(void)
{
	uint8_t d0 = 0, d1 = 0;
	uint32_t a0 = 0, a1 = 0, a5 = 0, a6 = 0, d0_2 = 0, d1_2 = 0;

	a0 = TILE_RAM + 0x2000u;
	a1 = TILE_RAM + 0x4000u;
	d0 = 0u;
	d1 = 0x10u;
	do
	{
		mem_write8(a1, d0);
		a1++;
		mem_write8(a1, d1);
		a1++;
		mem_write8(a1, d0);
		a1++;
		mem_write8(a1, d1);
		a1++;
	} while (a1 < TILE_RAM + 0x5000u);
	do
	{
		mem_write8(a0, d0);
		a0++;
		mem_write8(a0, d1);
		a0++;
		mem_write8(a0, d0);
		a0++;
		mem_write8(a0, d1);
		a0++;
	} while (a0 < TILE_RAM + 0x3000u);
	a0 = unk_062000_ADDRESS;
	d0 = 0u;
	do
	{
		mem_write8(a0, d0);
		a0 += 0x50u;
	} while (a0 < 0x625F0u);
	a0 = unk_062000_ADDRESS;
	a5 = table_loaded_by_lea_02FDC0_ADDRESS;
	do
	{
		mem_write16(a0, 0x8100u);
		mem_write16(a0 + 0x42u, 0xFF00u);
		mem_write16(a0 + 0x10u, 0u);
		d0_2 = DATA32(a5);
		a5 += 4u;
		d1_2 = DATA32(a5);
		mem_write32(a0 + 0x12u, d0_2);
		mem_write32(a0 + 0x16u, d1_2);
		mem_write16(a0 + 0xCu, d0_2 >> 8);
		mem_write16(a0 + 0xEu, d1_2 >> 8);
		a5 += 4u;
		a6 = DATA32(a5);
		a5 += 4u;
		set_animation(d1_2, a0, a6);
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	func_02F9EA();
}

void func_02FDF0(void)
{
	uint16_t d0 = 0, d1 = 0;
	uint32_t a0 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	a0 = unk_062000_ADDRESS;
	t1 = (((uint32_t)unk_062012 << 16u) | unk_062014) + 0x400u;
	unk_062014 = t1;
	unk_062012 = t1 >> 16;
	t2 = (((uint32_t)unk_062062 << 16u) | unk_062064) - 0x400u;
	unk_062064 = t2;
	unk_062062 = t2 >> 16;
	t3 = (((uint32_t)unk_0620B2 << 16u) | unk_0620B4) + 0x400u;
	unk_0620B4 = t3;
	unk_0620B2 = t3 >> 16;
	t4 = (((uint32_t)unk_062102 << 16u) | unk_062104) - 0x400u;
	unk_062104 = t4;
	unk_062102 = t4 >> 16;
	t5 = (((uint32_t)unk_062016 << 16u) | unk_062018) - 0x400u;
	unk_062018 = t5;
	unk_062016 = t5 >> 16;
	t6 = (((uint32_t)unk_062066 << 16u) | unk_062068) - 0x400u;
	unk_062068 = t6;
	unk_062066 = t6 >> 16;
	t7 = (((uint32_t)unk_0620B6 << 16u) | unk_0620B8) + 0x400u;
	unk_0620B8 = t7;
	unk_0620B6 = t7 >> 16;
	t8 = (((uint32_t)unk_062106 << 16u) | unk_062108) + 0x400u;
	unk_062108 = t8;
	unk_062106 = t8 >> 16;
	do
	{
		d0 = (uint16_t)(mem_read32(a0 + 0x12u) >> 8);
		d1 = (uint16_t)(mem_read32(a0 + 0x16u) >> 8);
		mem_write16(a0 + 0xCu, d0);
		mem_write16(a0 + 0xEu, d1);
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if ((uint16_t)d0 == 0x100u)
	{
		func_02F9EA();
		return;
	}
	func_02FE44();
}

void func_02FE44(void)
{
}

void func_02FE46(void)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a0 = 0, a2 = 0, a3 = 0, d0_2 = 0, d3 = 0, d4 = 0, d5 = 0;
	uint8_t t3 = 0;
	uint16_t t2 = 0;
	uint32_t t1 = 0;

	d0 = unk_06330E;
	d1 = (uint16_t)((uint32_t)d0 << 4);
	t1 = unk_063304 - d0;
	unk_063304 = (unk_063304 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_063304 = (unk_063304 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
	if (unk_063304 < 0x10000u)
	{
		unk_063304 = 0x10000u;
		return;
	}
	t2 = unk_06330A;
	unk_06330A = t2 - d1;
	if (d1 <= t2)
		return;
	d0_2 = unk_063304 - 0xF000u;
	d3 = d0_2;
	d5 = d0_2;
	d0_2 &= 0xF000u;
	d0_2 = (uint16_t)(d0_2 + 0x1000u);
	d0_2 = (uint16_t)(0u - d0_2);
	a0 = (d0_2 >> 4) + unk_0633CC;
	d3 = (d3 & 0xFFE000u) << 3;
	a2 = ((d3 << 16) | (d3 >> 16)) * unk_063310 + unk_063312;
	d5 = d5 << 7;
	d5 = (((d5 << 16) | (d5 >> 16)) & 8u) ^ 8u;
	d7 = 0xBu;
	do
	{
		a3 = unk_063316;
		d4 = mem_read16(a2);
		mem_write8(a0, mem_read8(a3 + (int16_t)d4));
		mem_write8(a0 + 2u, mem_read8(a3 + (int16_t)d4));
		mem_write8(a0 + 4u, mem_read8(a3 + (int16_t)d4));
		mem_write8(a0 + 6u, mem_read8(a3 + (int16_t)d4));
		mem_write8(a0 + 0x80u, mem_read8(a3 + (int16_t)d4));
		mem_write8(a0 + 0x82u, mem_read8(a3 + (int16_t)d4));
		mem_write8(a0 + 0x84u, mem_read8(a3 + (int16_t)d4));
		mem_write8(a0 + 0x86u, mem_read8(a3 + (int16_t)d4));
		a3 += d4;
		mem_write8(a0 + 1u, mem_read8(a3 + 1u + d5));
		mem_write8(a0 + 3u, mem_read8(a3 + 2u + d5));
		mem_write8(a0 + 5u, mem_read8(a3 + 3u + d5));
		mem_write8(a0 + 7u, mem_read8(a3 + 4u + d5));
		mem_write8(a0 + 0x81u, mem_read8(a3 + 5u + d5));
		mem_write8(a0 + 0x83u, mem_read8(a3 + 6u + d5));
		mem_write8(a0 + 0x85u, mem_read8(a3 + 7u + d5));
		mem_write8(a0 + 0x87u, mem_read8(a3 + 8u + d5));
		t3 = d7;
		d7 = (uint8_t)(t3 - 1u);
		a2 += 2u;
		a0 += 8u;
	} while (t3 != 1u);
}

uint32_t func_02FF44(void)
{
	uint32_t a0 = 0;

	io_write8(TILES_106B00, 0xC0u);
	unk_060064 = 0xC0u;
	unk_063312 = layers_0458F8_ADDRESS;
	unk_063316 = 0x459F8u;
	unk_063300 = 0x2000u;
	unk_063304 = 0x10000u;
	unk_063310 = 0x20u;
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	io_write8(TILES_106E00, 0x2Cu);
	unk_060065 = 0x2Cu;
	unk_063312 = 0x45D4Au;
	unk_063316 = 0x45E4Au;
	unk_063300 = 0x2000u;
	unk_063304 = 0x10000u;
	a0 = TILE_RAM + 0x2000u;
	return func_01E11E(a0);
}

uint32_t func_02FFDA(uint32_t a6)
{
	uint32_t a6_2 = 0;

	if (unk_061113 != 0u)
		return a6;
	if (unk_0600A3 == 0u)
		return a6;
	a6_2 = unk_0633F8;
	mem_write8(a6_2 + 0x188u, 0xBFu);
	mem_write8(a6_2 + 0x18Au, 0xBFu);
	mem_write8(a6_2 + 0x184u, 0xBFu);
	mem_write8(a6_2 + 0x186u, 0xBFu);
	mem_write8(a6_2 + 0x189u, 0xEEu);
	mem_write8(a6_2 + 0x18Bu, 0xEFu);
	mem_write8(a6_2 + 0x185u, 0xFEu);
	mem_write8(a6_2 + 0x187u, 0xFFu);
	return a6_2;
}

uint32_t func_02FFE6(uint32_t d0, uint32_t d1, uint16_t d2)
{
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	d3 = 5u;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
	func_02FFDA(ignored_5);
	return d0;
}

uint32_t func_02FFEE(uint32_t d0, uint32_t d1, uint16_t d2)
{
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	d3 = 0xAu;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
	func_02FFDA(ignored_5);
	return d1;
}

void func_02FFFE(uint32_t d1, uint16_t d2, uint32_t *p_d0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t ignored = 0;

	unk_061112++;
	d3 = 0x14u;
	func_0301D8(d2, d3, p_d0, &d1, &ignored, &d5, &d6, p_d7, p_a6);
	*p_a6 = func_02FFDA(*p_a6);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_03000C(uint32_t d1, uint16_t d2, uint32_t *p_d0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d3 = 0x19u;
	func_0301D8(d2, d3, p_d0, &d1, &ignored, &d5, &ignored_2, p_d7, &ignored_3);
	func_02FFDA(ignored_3);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_030014(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	d3 = 0x1Eu;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &d5, &d6, p_d7, &ignored_2);
	func_02FFDA(ignored_2);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_03001C(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	d3 = 0x23u;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &d5, &d6, p_d7, &ignored_2);
	func_02FFDA(ignored_2);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_030024(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	d3 = 0x28u;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &d5, &d6, p_d7, &ignored_2);
	func_02FFDA(ignored_2);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_03002C(uint16_t d2, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	d3 = 0x2Du;
	func_0301D8(d2, d3, p_d0, p_d1, &ignored, &d5, &d6, p_d7, &ignored_2);
	func_02FFDA(ignored_2);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_030034(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d3 = 0x32u;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &d5, &ignored_2, p_d7, &ignored_3);
	func_02FFDA(ignored_3);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_030054(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(d2 + mem_read8(a0 + 0x10u)));
	d3 = 0x46u;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &d5, &d6, p_d7, &ignored_2);
	func_02FFDA(ignored_2);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void unreached_030062(uint32_t d0, uint32_t d1, uint16_t d2)
{
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	d3 = 0x4Bu;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
	func_02FFDA(ignored_5);
}

void unreached_03006C(uint32_t d0, uint32_t d1, uint16_t d2)
{
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	d3 = 0x50u;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
	func_02FFDA(ignored_5);
}

void func_030076(uint32_t d0, uint16_t d2, uint32_t a0, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t ignored = 0;

	d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(d2 + mem_read8(a0 + 0x10u)));
	d3 = 0x55u;
	func_0301D8(d2, d3, &d0, p_d1, p_d4, &d5, &d6, p_d7, &ignored);
	func_02FFDA(ignored);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_030084(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	d3 = 0x5Au;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &d5, &d6, p_d7, &ignored_2);
	func_02FFDA(ignored_2);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_03008E(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t d4 = 0, ignored = 0;

	d3 = 0x5Fu;
	d4 = 0x20u;
	func_0301F0(d2, d3, &d0, &d1, &d4, &d5, &d6, p_d7, &ignored);
	func_03015C(ignored);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0300DA(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t d4 = 0, ignored = 0, ignored_2 = 0;

	unk_061112++;
	d4 = 0xFFFFFFD0u;
	d1 = (uint16_t)(d1 - 0x30u);
	d3 = 0x69u;
	func_0301F0(d2, d3, &d0, &d1, &d4, &d5, &ignored, p_d7, &ignored_2);
	func_03015C(ignored_2);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void func_0300F0(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t d4 = 0;

	unk_061112++;
	d4 = 0xFFFFFFD0u;
	d1 = (uint16_t)(d1 - 0x30u);
	d3 = 0x6Eu;
	func_0301F0(d2, d3, &d0, &d1, &d4, &d5, &d6, p_d7, p_a6);
	*p_a6 = func_03015C(*p_a6);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_030106(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t a6 = 0, d4 = 0, ignored = 0, ignored_2 = 0;

	d4 = 0xFFFFFFD0u;
	d3 = 0x73u;
	func_0301F0(d2, d3, &d0, &d1, &d4, &d5, &ignored, p_d7, &ignored_2);
	if (unk_0600A3 != 0u)
	{
		a6 = unk_0633F8;
		mem_write8(a6 + 0x198u, 0xBFu);
		mem_write8(a6 + 0x19Au, 0xBFu);
		mem_write8(a6 + 0x18Eu, 0xBFu);
		mem_write8(a6 + 0x190u, 0xBFu);
		mem_write8(a6 + 0x199u, 0xEEu);
		mem_write8(a6 + 0x19Bu, 0xEFu);
		mem_write8(a6 + 0x18Fu, 0xFEu);
		mem_write8(a6 + 0x191u, 0xFFu);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

uint32_t func_03015C(uint32_t a6)
{
	uint32_t a6_2 = 0;

	if (unk_0600A3 == 0u)
		return a6;
	a6_2 = unk_0633F8;
	mem_write8(a6_2 + 0x190u, 0xBFu);
	mem_write8(a6_2 + 0x192u, 0xBFu);
	mem_write8(a6_2 + 0x18Au, 0xBFu);
	mem_write8(a6_2 + 0x18Cu, 0xBFu);
	mem_write8(a6_2 + 0x191u, 0xEEu);
	mem_write8(a6_2 + 0x193u, 0xEFu);
	mem_write8(a6_2 + 0x18Bu, 0xFEu);
	mem_write8(a6_2 + 0x18Du, 0xFFu);
	return a6_2;
}

void func_0301D8(uint16_t d2, uint16_t d3, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	unk_061113 = *p_d0;
	if ((uint8_t)*p_d0 != 0u)
		d1 = (d1 & ~0xFFFFu) | (uint16_t)(d1 + 0x20u);
	else
		d1 = (d1 & ~0xFFFFu) | (uint16_t)(d1 - 0x20u);
	*p_d4 = 0x20u;
	func_0301F0(d2, d3, p_d0, &d1, p_d4, &d5, &d6, p_d7, p_a6);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0301F0(uint16_t d2, uint16_t d3, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d0 = *p_d0;
	uint32_t d1 = *p_d1;
	uint32_t d4 = *p_d4;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint8_t d2_2 = 0, d3_2 = 0, d5_2 = 0;
	uint16_t d4_2 = 0, d6_2 = 0;
	uint32_t d7 = 0, ignored = 0, ignored_2 = 0;

	if (unk_0600A3 != 0u)
	{
		if (unk_0633FC != 0u)
		{
			AT16(unk_060066, -1) = d0;
			unk_060068 = d2;
			unk_06006A = d3;
			unk_06006C = d4;
			func_03030C(&ignored, &ignored_2, p_d7);
			d0 = (d0 & ~0xFFFFu) | AT16(unk_060066, -1);
			d2 = unk_060068;
			d3 = unk_06006A;
			d4 = unk_06006C;
		}
		d5_2 = (uint8_t)((unk_060065 & 0xFu) | d4);
		unk_060065 = d5_2;
		io_write8(TILES_106E00, d5_2);
		unk_061106++;
		unk_061104 = 0u;
		d7 = (*p_d7 & ~0xFFu) | TABLE8(indexed_table_of_8_bit_values_030350, (uint32_t)(int16_t)d3);
		d4_2 = (uint16_t)((d4 & ~0xFFu) | mem_read8(0x30352u + (int16_t)d3));
		d6_2 = mem_read8(0x30353u + (int16_t)d3);
		unk_0633FC = mem_read8(0x30354u + (int16_t)d3);
		d3_2 = mem_read8(0x30351u + (int16_t)d3);
		func_0091A4((uint8_t)d7, *p_a6);
		if ((uint8_t)d0 != 0u)
		{
			if ((uint16_t)d1 >= 0xB0u)
				d1 = ((d1 - 0x50u) & 0x1F8u) >> 2;
			else
				d1 = 0x18u;
		}
		else if ((uint16_t)d1 < 0x130u)
			d1 = ((d1 + 0x10u) & 0x1F8u) >> 2;
		else
			d1 = 0x50u;
		if ((uint16_t)d2 < 0x70u)
			d2 = (uint16_t)(((0u - d2 - 0x50u) & 0xF8u) << 4);
		else
			d2 = 0x400u;
		d1 = (uint16_t)(d1 + d2) + 0x100000u;
		*p_a6 = d1;
		unk_0633F8 = d1;
		*p_d7 = (d7 & ~0xFFFFu) | d6_2;
		d0 &= ~0xFFu;
		d2_2 = (uint8_t)d4_2;
		d4 = (d4_2 & ~0xFFu) | d3_2;
		d6 = d3_2;
		d4 = (d4 & ~0xFFu) | (uint8_t)(d4 + 0x10u);
		d5 = (uint8_t)(d3_2 + 0x20u);
		d6 = (uint8_t)(d6 + 0x30u);
		func_030320((uint8_t)d0, d2_2, d3_2, &d4, &d5, &d6, p_d7, p_a6);
	}
	*p_d0 = d0;
	*p_d1 = d1;
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_03030C(uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t d0 = 0, d2 = 0, d3 = 0;
	uint32_t a6 = 0, d4 = 0, d5 = 0, d6 = 0;

	a6 = unk_0633F8;
	d0 = 0xFFu;
	*p_d7 = 0xFu;
	d2 = 0u;
	d3 = 0x10u;
	d4 = 0x10u;
	d5 = 0x10u;
	d6 = 0x10u;
	func_030320(d0, d2, d3, &d4, &d5, &d6, p_d7, &a6);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFFFF00u) | (d6 & 0xFFu);
}

void func_030320(uint8_t d0, uint8_t d2, uint8_t d3, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a6)
{
	uint8_t d4 = (uint8_t)*p_d4;
	uint8_t d5 = (uint8_t)*p_d5;
	uint8_t d6 = (uint8_t)*p_d6;
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t a6 = *p_a6;
	uint16_t t1 = 0;

	do
	{
		mem_write8(a6 + 0x80u, d2);
		mem_write8(a6 + 0x100u, d2);
		mem_write8(a6 + 0x180u, d2);
		mem_write8(a6, d2);
		a6++;
		mem_write8(a6 + 0x80u, d4);
		mem_write8(a6 + 0x100u, d5);
		mem_write8(a6 + 0x180u, d6);
		mem_write8(a6, d3);
		a6++;
		if ((int8_t)d0 >= 0)
		{
			d3++;
			d4++;
			d5++;
			d6++;
		}
		t1 = d7 - 1u;
		d7 = t1;
	} while (t1 != 0xFFFFu);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | d4;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
	*p_d6 = (*p_d6 & 0xFFFFFF00u) | d6;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
	*p_a6 = a6;
}

void func_0303CE(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;

	if ((int8_t)unk_0633FE >= 0)
	{
		switch (unk_0633FF)
		{
		case 0:
			d7 = func_030402(d7);
			break;
		case 1:
			d7 = func_030468(d7);
			break;
		case 2:
			func_030662(&d5, &d7, p_a1);
			break;
		case 3:
			d7 = func_030716(d7);
			break;
		case 4:
			d7 = func_03086A();
			break;
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

uint32_t func_030402(uint32_t d7)
{
	uint32_t d7_2 = 0;

	if (unk_060121 != 1u)
	{
		if (unk_063380 < 0x4B000u)
			return d7;
		unk_0633F6 = 0u;
		unk_0633FE = 1u;
		unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | 0xFF0000u;
		unk_06110E = 0xC0u;
		unk_06110F = 0u;
		d7_2 = (d7 & ~0xFFu) | 0xFEu;
		func_0091A4((uint8_t)d7_2, 0u);
		d7_2 = (d7_2 & ~0xFFu) | 0x34u;
		func_0091A4((uint8_t)d7_2, 0u);
		unk_063488 = 0xFFu;
		unk_0633FF++;
		return d7_2;
	}
	if (unk_063380 < 0xA000u)
		return d7;
	unk_0633F6 = 0u;
	unk_0633FE = 1u;
	unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | 0xFF0000u;
	unk_06110E = 0xC0u;
	unk_06110F = 0u;
	d7_2 = (d7 & ~0xFFu) | 0xFEu;
	func_0091A4((uint8_t)d7_2, 0u);
	d7_2 = (d7_2 & ~0xFFu) | 0x34u;
	func_0091A4((uint8_t)d7_2, 0u);
	unk_063488 = 0xFFu;
	unk_0633FF++;
	return d7_2;
}

uint32_t func_030468(uint32_t d7)
{
	uint32_t a0 = 0, a6 = 0, d0 = 0, d1 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	unk_0633F6 = 0u;
	t1 = unk_06110E;
	unk_06110E = t1 - 1u;
	if (t1 != 1u)
	{
		func_030478();
		return d7;
	}
	d7_2 = (d7 & ~0xFFu) | 0xCu;
	func_0091A4((uint8_t)d7_2, 0u);
	a0 = unk_062DC0_ADDRESS;
	unk_062DC0 = 0x81u;
	unk_062E10 = 0x81u;
	unk_062E60 = 0x81u;
	unk_062E02 = (unk_062E02 & 0xFFu) | 0xFF00u;
	unk_062E52 = 0xFFu;
	unk_062EA2 = 0xFFu;
	d1 = 0x6500u;
	d0 = 0x1D6FFu;
	if (unk_060121 != 1u)
	{
		d1 = 0x8500u;
		d0 = 0x5B7FFu;
	}
	d0 -= unk_063380;
	unk_062DD2 = d0;
	unk_062E22 = d0;
	unk_062E72 = d0;
	d0 = d0 >> 8;
	unk_062DCC = d0;
	unk_062E1C = d0;
	unk_062E6C = d0;
	unk_062DD6 = d1;
	d1 += 0xE00u;
	unk_062E26 = d1;
	d1 -= 0xC00u;
	unk_062E76 = d1;
	d1 = d1 >> 8;
	unk_062E6E = d1;
	d1 = (uint16_t)(d1 + 0xCu);
	unk_062E1E = d1;
	unk_062DCE = d1 - 0xEu;
	a6 = 0x2D7BAu;
	if (unk_060121 != 1u)
		a6 = 0x2D7F8u;
	set_animation(d1, a0, a6);
	a6 = animations_02D796_ADDRESS;
	a0 += 0x50u;
	set_animation(d1, a0, a6);
	a6 = 0x2D836u;
	a0 += 0x50u;
	set_animation(d1, a0, a6);
	func_030478();
	unk_0633FF++;
	return d7_2;
}

void func_030478(void)
{
	uint16_t d0 = 0, d4 = 0;
	uint32_t a0 = 0, d1 = 0, d2 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	if ((unk_0600A4 & 1u) != 0u)
		return;
	d0 = unk_06110F;
	unk_06110F++;
	d0 = (uint16_t)((d0 & 7u) << 1);
	d2 = rom_030653[d0];
	d1 = (uint16_t)(int8_t)indexed_table_of_8_bit_values_030652[d0];
	unk_06005C += d1;
	unk_060060 += d1;
	unk_06005E = (unk_06005E & 0xFF00u) | ((uint8_t)unk_06005E + d2 & 0xFFu);
	unk_060062 = (unk_060062 & 0xFF00u) | ((uint8_t)unk_060062 + d2 & 0xFFu);
	d1 = (uint32_t)(int16_t)(0u - d1) << 8;
	d2 = (uint32_t)(int16_t)(int8_t)d2 << 8;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			t1 = mem_read32(a0 + 0x12u) + d1;
			mem_write16(a0 + 0x14u, t1);
			mem_write16(a0 + 0x12u, t1 >> 16);
			t2 = mem_read32(a0 + 0x16u) + d2;
			mem_write16(a0 + 0x18u, t2);
			mem_write16(a0 + 0x16u, t2 >> 16);
			d4 = (uint16_t)(mem_read32(a0 + 0x16u) >> 8);
			mem_write16(a0 + 0xCu, mem_read32(a0 + 0x12u) >> 8);
			mem_write16(a0 + 0xEu, d4);
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	t3 = unk_062DD2 + d1;
	unk_062DD2 = (unk_062DD2 & 0xFFFF0000u) | (t3 & 0xFFFFu);
	unk_062DD2 = (unk_062DD2 & 0xFFFFu) | ((t3 >> 16 & 0xFFFFu) << 16u);
	t4 = unk_062DD6 + d2;
	unk_062DD6 = (unk_062DD6 & 0xFFFF0000u) | (t4 & 0xFFFFu);
	unk_062DD6 = (unk_062DD6 & 0xFFFFu) | ((t4 >> 16 & 0xFFFFu) << 16u);
	d4 = (uint16_t)(unk_062DD6 >> 8);
	unk_062DCC = unk_062DD2 >> 8;
	unk_062DCE = d4;
	t5 = unk_062E22 + d1;
	unk_062E22 = (unk_062E22 & 0xFFFF0000u) | (t5 & 0xFFFFu);
	unk_062E22 = (unk_062E22 & 0xFFFFu) | ((t5 >> 16 & 0xFFFFu) << 16u);
	t6 = unk_062E26 + d2;
	unk_062E26 = (unk_062E26 & 0xFFFF0000u) | (t6 & 0xFFFFu);
	unk_062E26 = (unk_062E26 & 0xFFFFu) | ((t6 >> 16 & 0xFFFFu) << 16u);
	d4 = (uint16_t)(unk_062E26 >> 8);
	unk_062E1C = unk_062E22 >> 8;
	unk_062E1E = d4;
	t7 = unk_062E72 + d1;
	unk_062E72 = (unk_062E72 & 0xFFFF0000u) | (t7 & 0xFFFFu);
	unk_062E72 = (unk_062E72 & 0xFFFFu) | ((t7 >> 16 & 0xFFFFu) << 16u);
	t8 = unk_062E76 + d2;
	unk_062E76 = (unk_062E76 & 0xFFFF0000u) | (t8 & 0xFFFFu);
	unk_062E76 = (unk_062E76 & 0xFFFFu) | ((t8 >> 16 & 0xFFFFu) << 16u);
	d4 = (uint16_t)(unk_062E76 >> 8);
	unk_062E6C = unk_062E72 >> 8;
	unk_062E6E = d4;
}

void func_030662(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t a1 = *p_a1;
	uint16_t d0 = 0, d1 = 0, d2 = 0;
	uint32_t a0 = 0;
	uint32_t t1 = 0, t2 = 0;

	unk_0633F6 = 0u;
	func_030478();
	a0 = unk_062E10_ADDRESS;
	t1 = unk_062E76 + 0xC0u;
	unk_062E76 = (unk_062E76 & 0xFFFF0000u) | (t1 & 0xFFFFu);
	unk_062E76 = (unk_062E76 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
	unk_062E6E = unk_062E76 >> 8;
	t2 = unk_062E26 + 0xC0u;
	unk_062E26 = (unk_062E26 & 0xFFFF0000u) | (t2 & 0xFFFFu);
	unk_062E26 = (unk_062E26 & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
	d0 = (uint16_t)(unk_062E26 >> 8);
	unk_062E1E = d0;
	if (unk_060121 == 7u && unk_062E1E >= 0x9Eu && unk_061106 == 1u)
	{
		a1 = unk_062000_ADDRESS;
		do
		{
			if ((mem_read8(a1) & 1u) != 0u)
			{
				d0 &= ~0xFFu;
				d1 = (uint16_t)(mem_read16(a1 + 0xCu) - 0x40u);
				d2 = mem_read16(a1 + 0xEu);
				func_030106(d0, d1, d2, &d5, p_d7);
				break;
			}
			a1 += 0x50u;
		} while (a1 < 0x62140u);
	}
	d0 = 0x124u;
	if (unk_060121 != 1u)
		d0 = 0x144u;
	if (d0 < unk_062E1E)
	{
		unk_062E43 = 0u;
		unk_06110E = 0x70u;
		unk_0633FF++;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_a1 = a1;
}

uint32_t func_030716(uint32_t d7)
{
	uint8_t d0 = 0;
	uint16_t d0_3 = 0, d1_2 = 0;
	uint32_t a0 = 0, d0_2 = 0, d1 = 0, d7_2 = 0;
	uint8_t t1 = 0, t3 = 0;
	uint32_t t2 = 0;

	unk_0633F6 = 0u;
	t1 = unk_06110E;
	d0 = t1;
	if (t1 == 0u)
	{
		a0 = unk_062E60_ADDRESS;
		t2 = unk_062E76 - 0x200u;
		unk_062E76 = (unk_062E76 & 0xFFFF0000u) | (t2 & 0xFFFFu);
		unk_062E76 = (unk_062E76 & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
		if (unk_060121 == 1u && unk_062E76 == 0x11300u)
			d7 = func_04F6E6(d7);
		d0_3 = (uint16_t)(unk_062E76 >> 8);
		unk_062E6E = d0_3;
		d1_2 = 0xA0u;
		if (unk_060121 != 1u)
			d1_2 = 0xC0u;
		if (d1_2 <= (uint16_t)d0_3)
			return d7;
		if (unk_060121 == 7u)
			func_01349E();
		unk_0633FF++;
		return d7;
	}
	if (d0 >= 0x30u)
	{
		if (d0 != 0x30u)
			func_030478();
		else
		{
			unk_063488 = 0u;
			d7 = (d7 & ~0xFFu) | 0x35u;
			func_0091A4((uint8_t)d7, 0u);
			if (unk_060121 != 1u)
			{
				d7 = (d7 & ~0xFFu) | 0x66u;
				unk_060080 = d7;
				func_0091A4((uint8_t)d7, 0u);
			}
			d1 = 0x6500u;
			d0_2 = 0x1D6FFu;
			if (unk_060121 != 1u)
			{
				d1 = 0x8500u;
				d0_2 = 0x5B6FFu;
			}
			d0_2 -= unk_063380;
			unk_062DD2 = d0_2;
			unk_062E22 = d0_2;
			unk_062E72 = d0_2;
			d0_2 = d0_2 >> 8;
			unk_062DCC = d0_2;
			unk_062E1C = d0_2;
			unk_062E6C = d0_2;
			unk_062DD6 = d1;
			d1 += 0xC000u;
			unk_062E26 = d1;
			d1 -= 0xC00u;
			unk_062E76 = d1;
			d1 = d1 >> 8;
			unk_062E6E = d1;
			d1 = (uint16_t)(d1 + 0xCu);
			unk_062E1E = d1;
			unk_062DCE = d1 - 0xC0u;
		}
	}
	t3 = unk_06110E;
	unk_06110E = t3 - 1u;
	if (t3 != 1u)
		return d7;
	if (unk_060121 == 7u)
		func_0133FE();
	d7_2 = (d7 & ~0xFFu) | 0x36u;
	func_0091A4((uint8_t)d7_2, 0u);
	return d7_2;
}

uint32_t func_03086A(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	unk_0633F6 = 0u;
	unk_0633C2 &= 0xFF00FFFFu;
	unk_0633FE = 0xFFu;
	unk_062DC0 = 0u;
	unk_062E10 = 0u;
	unk_062E60 = 0u;
	d7 = 3u;
	a6 = 0x18AECu;
	if (unk_060121 != 1u)
	{
		d7 = 0x1Cu;
		a6 = 0x18F16u;
	}
	draw_tile_block(d7, a6);
	d7_2 = 4u;
	a6 = 0x18BAEu;
	if (unk_060121 != 1u)
	{
		d7_2 = 0x1Du;
		a6 = 0x18FB8u;
	}
	draw_tile_block((uint16_t)d7_2, a6);
	return d7_2;
}

void func_0308D6(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	unk_060150 = 0u;
	unk_06111E = 0u;
	unk_06014C(0) = 0u;
	unk_06014C(1) = 0u;
	unk_06014C(2) = 0u;
	unk_06014C(3) = 0u;
	unk_0633EA = 0u;
	unk_061108 = 0u;
	unk_0633FC = 0u;
	unk_061106 = 0u;
	unk_0633E2 = 0u;
	unk_063300 = 0x800u;
	unk_063340 = 0x800u;
	unk_063380 = 0x800u;
	unk_063304 = 0x10000u;
	unk_063344 = 0x10000u;
	unk_063384 = 0x10000u;
	func_01ECAA();
	func_01864E();
	a6 = 0xA0EEu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
}

void func_030960(void)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;
	uint8_t t1 = 0;

	if (unk_0633FC != 0u)
	{
		t1 = unk_0633FC;
		unk_0633FC = t1 - 1u;
		if (t1 == 1u)
			func_03030C(&ignored, &ignored_2, &ignored_3);
	}
	d0 = (uint16_t)((uint32_t)unk_0633EA << 2);
	switch (d0)
	{
	case 0:
		func_0309AE();
		break;
	case 4:
		func_030BF4(d0);
		break;
	case 8:
		func_030D8E();
		break;
	case 12:
		func_030E14();
		break;
	case 16:
		func_030E8E();
		break;
	case 20:
		func_030F38();
		break;
	}
	func_01ECAA();
}

void func_0309AE(void)
{
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a0 = 0, a5 = 0, a6 = 0, d1 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (unk_060083 != 0u)
		return;
	unk_0633DE = 1u;
	unk_0633DF = 0u;
	a0 = TILE_RAM + 0x4008u;
	d0 = 0x24u;
	d1 = 0u;
	d7 = 0x1Fu;
	do
	{
		d6 = 0x1Fu;
		do
		{
			mem_write8(a0, d0);
			a0++;
			mem_write8(a0, d1);
			carry = (uint8_t)(d1 + 1u) < d1;
			d1 = (uint8_t)(d1 + 1u);
			a0++;
			if (carry)
				d0++;
			t1 = d6 - 1u;
			d6 = t1;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
		a0 += 0x40u;
	} while (t2 != 0xFFFFu);
	a0 = TILE_RAM + 0x4038u;
	d0 = 4u;
	func_030BC6(d0, a0);
	a0 = TILE_RAM + 0x4438u;
	d0 = 5u;
	func_030BC6(d0, a0);
	a0 = TILE_RAM + 0x4838u;
	d0 = 6u;
	func_030BC6(d0, a0);
	a0 = TILE_RAM + 0x4C40u;
	d0 = 7u;
	func_030BD0(d0, a0);
	a0 = TILE_RAM + 0x4630u;
	d0 = 5u;
	func_030BD0(d0, a0);
	a0 = TILE_RAM + 0x4828u;
	d0 = 6u;
	func_030BDA(d0, a0);
	a0 = TILE_RAM + 0x4A28u;
	d0 = 0x46u;
	func_030BD0(d0, a0);
	a0 = TILE_RAM + 0x4A30u;
	d0 = 6u;
	func_030BD0(d0, a0);
	a0 = TILE_RAM + 0x4C30u;
	d0 = 0x47u;
	func_030BDA(d0, a0);
	io_write8(TILES_106B00, 0xF0u);
	unk_060064 = 0xF0u;
	io_write8(TILES_106E00, 0x21u);
	unk_060065 = 0x21u;
	a0 = unk_062DC0_ADDRESS;
	unk_062DC0 = 0x81u;
	unk_062DD0 = 0u;
	unk_062E02 = 0xFF00u;
	unk_062DCC = 0xA0u;
	unk_062DCE = 0x58u;
	a6 = 0x2DB4Cu;
	set_animation(d1, a0, a6);
	a0 = unk_062E10_ADDRESS;
	a5 = table_loaded_by_lea_030B16_ADDRESS;
	d0 = 0x70u;
	do
	{
		mem_write8(a0, 0x81u);
		mem_write16(a0 + 0x10u, 0u);
		mem_write16(a0 + 0x42u, 0xFF00u);
		mem_write16(a0 + 0xCu, 0xC0u);
		mem_write16(a0 + 0xEu, 0x70u);
		mem_write16(a0 + 0x1Au, 0x500u);
		mem_write8(a0 + 0x1Cu, 0u);
		mem_write8(a0 + 0x1Du, d0);
		a6 = DATA32(a5);
		set_animation(d1, a0, a6);
		d0 += 0x14u;
		a5 += 4u;
		a0 += 0x50u;
	} while (a0 < unk_062F50_ADDRESS);
	a0 = TILE_RAM + 0x2B28u;
	a6 = table_loaded_by_lea_030B26_ADDRESS;
	d0 = 0x3Bu;
	d7 = 9u;
	do
	{
		d6 = 0xFu;
		do
		{
			mem_write8(a0, d0);
			a0++;
			mem_write8(a0, DATA8(a6));
			t3 = d6 - 1u;
			d6 = t3;
			a0++;
			a6++;
		} while (t3 != 0xFFFFu);
		t4 = d7 - 1u;
		d7 = t4;
		a0 += 0x60u;
	} while (t4 != 0xFFFFu);
	unk_0633EA++;
}

void func_030BC6(uint8_t d0, uint32_t a0)
{
	uint16_t d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0;

	d4 = 0x70u;
	d7 = 7u;
	d5 = 7u;
	do
	{
		d6 = (uint16_t)d5;
		do
		{
			mem_write8(a0, d0);
			t1 = d6 - 1u;
			d6 = t1;
			a0 += 2u;
		} while (t1 != 0xFFFFu);
		a0 += d4;
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
}

void func_030BD0(uint8_t d0, uint32_t a0)
{
	uint16_t d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0;

	d4 = 0x78u;
	d7 = 3u;
	d5 = 3u;
	do
	{
		d6 = (uint16_t)d5;
		do
		{
			mem_write8(a0, d0);
			t1 = d6 - 1u;
			d6 = t1;
			a0 += 2u;
		} while (t1 != 0xFFFFu);
		a0 += d4;
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
}

void func_030BDA(uint8_t d0, uint32_t a0)
{
	uint16_t d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0;

	d4 = 0x70u;
	d7 = 3u;
	d5 = 7u;
	do
	{
		d6 = (uint16_t)d5;
		do
		{
			mem_write8(a0, d0);
			t1 = d6 - 1u;
			d6 = t1;
			a0 += 2u;
		} while (t1 != 0xFFFFu);
		a0 += d4;
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
}

void func_030BF4(uint32_t d0)
{
	uint8_t d0_2 = 0, d1_2 = 0, d7 = 0;
	uint16_t d2 = 0, d3 = 0, d6 = 0, d7_2 = 0;
	uint32_t a0 = 0, a5 = 0, a6 = 0, d1 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, ignored_6 = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint32_t unk_0633DE_halfword = 0, unk_0633DE_halfword_2 = 0;

	func_018682();
	d0 = func_03101C(d0);
	unk_0633CB = 0u;
	a0 = unk_062E10_ADDRESS;
	a5 = animations_030D7E_ADDRESS;
	do
	{
		if (mem_read8(a0 + 0x1Du) == 0u)
		{
			if ((mem_read8(a0) & 0x80u) != 0u)
			{
				unk_0633CB--;
				if (mem_read8(a0 + 0x1Cu) != 0u)
				{
					mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x100u);
					d0 = mem_read16(a0 + 0x1Au);
					t1 = mem_read16(a0 + 0x10u);
					mem_write16(a0 + 0x10u, t1 - d0);
					if (t1 < d0)
						mem_write8(a0, mem_read8(a0) & 0x7Fu);
					mem_write16(a0 + 0xCu, mem_read16(a0 + 0xCu) + 1u);
					mem_write16(a0 + 0xEu, mem_read16(a0 + 0xEu) - 1u);
					mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x20u);
					if (mem_read16(a0 + 0x1Au) >= 0x500u)
						mem_write16(a0 + 0x1Au, 0x500u);
				}
				else
				{
					if (a0 == unk_062F00_ADDRESS && mem_read16(a0 + 0x1Au) == 0x360u)
					{
						io_write8(PRIORITY_0C0001, 4u);
						unk_060059 = 4u;
					}
					mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x100u);
					d0 = mem_read16(a0 + 0x1Au);
					mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + d0);
					mem_write16(a0 + 0xCu, mem_read16(a0 + 0xCu) + 1u);
					mem_write16(a0 + 0xEu, mem_read16(a0 + 0xEu) - 1u);
					t2 = mem_read16(a0 + 0x1Au);
					mem_write16(a0 + 0x1Au, t2 - 0x20u);
					if (t2 < 0x20u)
					{
						mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
						mem_write8(a0 + 0x1Cu, mem_read8(a0 + 0x1Cu) - 1u);
					}
				}
			}
		}
		else
		{
			unk_0633CB--;
			t3 = mem_read8(a0 + 0x1Du);
			mem_write8(a0 + 0x1Du, t3 - 1u);
			if (t3 == 1u)
			{
				a6 = DATA32(a5);
				set_animation(ignored_6, a0, a6);
			}
		}
		a0 += 0x50u;
		a5 += 4u;
	} while (a0 < unk_062F50_ADDRESS);
	if (unk_0633CB == 0u)
	{
		func_01864E();
		a0 = TILE_RAM + 0x2B28u;
		d0_2 = 0x3Bu;
		d1_2 = 0x41u;
		d7_2 = 9u;
		do
		{
			d6 = 0xFu;
			do
			{
				mem_write8(a0, d0_2);
				a0++;
				mem_write8(a0, d1_2);
				t4 = d6 - 1u;
				d6 = t4;
				a0++;
			} while (t4 != 0xFFFFu);
			t5 = d7_2 - 1u;
			d7_2 = t5;
			a0 += 0x60u;
		} while (t5 != 0xFFFFu);
		a6 = 0xA0FEu;
		d7_2 = 0x20Fu;
		post_palette_request(d7_2, a6);
		unk_0633EA++;
		return;
	}
	t6 = (((uint32_t)unk_0633DE << 8u) | unk_0633DF);
	unk_0633DE_halfword = t6 - 1u;
	unk_0633DE = (uint8_t)(unk_0633DE_halfword >> 8u);
	unk_0633DF = (uint8_t)unk_0633DE_halfword;
	if (t6 == 1u)
	{
		unk_0633DE_halfword_2 = (((uint32_t)unk_0633DE << 8u) | unk_0633DF) + 1u;
		unk_0633DE = (uint8_t)(unk_0633DE_halfword_2 >> 8u);
		unk_0633DF = (uint8_t)unk_0633DE_halfword_2;
	}
	if ((((uint32_t)unk_0633DE << 8u) | unk_0633DF) == 0xD0u)
	{
		d0 &= ~0xFFu;
		d1 = 0x108u;
		d2 = 0x28u;
		d3 = 0x41u;
		func_0301D8(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
		func_02FFDA(ignored_5);
		return;
	}
	if ((((uint32_t)unk_0633DE << 8u) | unk_0633DF) == 0x90u)
	{
		d7 = 0x7Du;
		func_0091A4(d7, a6);
		return;
	}
	if ((((uint32_t)unk_0633DE << 8u) | unk_0633DF) != 0x70u)
		return;
	d0 &= ~0xFFu;
	d1 = 0xA8u;
	d2 = 0x28u;
	d3 = 0u;
	func_0301D8(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
	func_02FFDA(ignored_5);
}

void func_030D8E(void)
{
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a0 = 0, a5 = 0, a6 = 0, d1 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	if (unk_060083 != 0u)
		return;
	a0 = TILE_RAM + 0x4008u;
	d0 = 0x14u;
	d1 = 0u;
	d7 = 0x1Fu;
	do
	{
		d6 = 0x1Fu;
		do
		{
			mem_write8(a0, d0);
			a0++;
			mem_write8(a0, d1);
			carry = (uint8_t)(d1 + 1u) < d1;
			d1 = (uint8_t)(d1 + 1u);
			a0++;
			if (carry)
				d0++;
			t1 = d6 - 1u;
			d6 = t1;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
		a0 += 0x40u;
	} while (t2 != 0xFFFFu);
	a0 = unk_062DC0_ADDRESS;
	a5 = intro_object_animations_ADDRESS;
	d7 = 3u;
	do
	{
		mem_write16(a0, 0x8100u);
		mem_write16(a0 + 0x10u, 0u);
		mem_write16(a0 + 0x42u, 0xFF00u);
		mem_write16(a0 + 0xCu, 0xF8u);
		mem_write16(a0 + 0xEu, 0xB8u);
		a6 = DATA32(a5);
		a5 += 4u;
		mem_write16(a0 + 0x1Cu, DATA16(a5));
		a5 += 2u;
		set_animation(d1, a0, a6);
		t3 = d7 - 1u;
		d7 = t3;
		a0 += 0x50u;
	} while (t3 != 0xFFFFu);
	unk_0633EA++;
}

void func_030E14(void)
{
	uint16_t d7 = 0;
	uint32_t a0 = 0, a6 = 0;

	func_018682();
	a0 = unk_062DC0_ADDRESS;
	do
	{
		if (mem_read8(a0 + 0x33u) == 0u && (mem_read8(a0) & 0x80u) != 0u)
		{
			mem_write16(a0 + 0xEu, mem_read16(a0 + 0xEu) - 8u);
			mem_write16(a0 + 0xCu, mem_read16(a0 + 0xCu) + mem_read16(a0 + 0x1Cu));
			if (mem_read16(a0 + 0xEu) < 0x80u)
				mem_write8(a0, mem_read8(a0) & 0x7Fu);
		}
		a0 += 0x50u;
	} while (a0 < unk_062F00_ADDRESS);
	if ((mem_read8(a0 - 0x50u) & 0x80u) != 0u)
		return;
	func_01864E();
	unk_063300 &= 0xFFFF0000u;
	unk_063300 &= 0xFFFFu;
	unk_063340 &= 0xFFFF0000u;
	unk_063340 &= 0xFFFFu;
	unk_063380 &= 0xFFFF0000u;
	unk_063380 &= 0xFFFFu;
	a6 = 0xA10Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	unk_0633EA++;
}

void func_030E8E(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, d4 = 0, d5 = 0, d6 = 0, ignored = 0, ignored_2 = 0;

	if (unk_060083 != 0u)
		return;
	io_write8(TILES_106B00, 0x30u);
	unk_060064 = 0x30u;
	unk_063312 = layers_04618C_ADDRESS;
	unk_063316 = 0x4628Cu;
	unk_063310 = 0x20u;
	a0 = TILE_RAM + 0x4000u;
	func_01E11E(a0);
	a0 = 0x9C08u;
	func_009B12(a0);
	a0 = unk_062DC0_ADDRESS;
	d4 = 0u;
	d5 = 0xB0u;
	d6 = 0x20u;
	do
	{
		mem_write16(a0, 0x8100u);
		mem_write8(a0 + 2u, d4);
		mem_write16(a0 + 0x10u, 0xB000u);
		mem_write16(a0 + 0xCu, d5);
		mem_write16(a0 + 0xEu, 0x50u);
		mem_write8(a0 + 0x1Du, d6);
		mem_write32(a0 + 0x3Au, 0x2E928u);
		mem_write16(a0 + 0x42u, 0xFF00u);
		d0 = 0x203u;
		func_01B8C2(d0, a0, &ignored, &d4, &d5, &d6, &ignored_2);
		d4 = (uint8_t)(d4 + 1u);
		d5 = (uint16_t)(d5 - 0xCu);
		d6 = (d6 & ~0xFFu) | (uint8_t)(d6 + 0x10u);
		a0 += 0x50u;
	} while (a0 < unk_062F00_ADDRESS);
	unk_0633EA++;
}

void func_030F38(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, a6 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, ignored_6 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	func_018682();
	func_03101C(0u);
	unk_0633CB = 0u;
	a0 = unk_062DC0_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 0x80u) != 0u)
		{
			unk_0633CB--;
			if (mem_read8(a0 + 0x1Du) == 0u)
			{
				if (mem_read16(a0 + 0x10u) == 0u)
				{
					mem_write8(a0 + 1u, 0u);
					mem_write16(a0 + 0xCu, mem_read16(a0 + 0xCu) + 2u);
					if (mem_read16(a0 + 0xCu) >= 0x158u)
						mem_write8(a0, mem_read8(a0) & 0x7Fu);
				}
				else
				{
					mem_write8(a0 + 1u, 0u);
					mem_write16(a0 + 0xCu, mem_read16(a0 + 0xCu) + 3u);
					if (mem_read16(a0 + 0xCu) >= 0xE0u)
						mem_write8(a0 + 1u, 0x80u);
					t1 = mem_read16(a0 + 0x10u);
					mem_write16(a0 + 0x10u, t1 - 0x600u);
					if (t1 < 0x600u)
					{
						mem_write16(a0 + 0x10u, 0u);
						if (mem_read8(a0 + 2u) == 1u)
						{
							mem_write8(a0 + 0x1Du, 0x40u);
							a6 = 0x2DF32u;
							set_animation(ignored, a0, a6);
						}
						else
						{
							mem_write8(a0 + 0x1Du, 0xCu);
							d0 = 0x200u;
							func_01B8C2(d0, a0, &ignored, &ignored_3, &ignored_4, &ignored_5, &ignored_6);
						}
					}
				}
			}
			else
			{
				t2 = mem_read8(a0 + 0x1Du);
				mem_write8(a0 + 0x1Du, t2 - 1u);
				if (t2 == 1u && mem_read16(a0 + 0x10u) == 0u)
				{
					d0 = 0x100u;
					func_01B8C2(d0, a0, &ignored, &ignored_3, &ignored_4, &ignored_5, &ignored_6);
				}
			}
		}
		a0 += 0x50u;
	} while (a0 < unk_062F00_ADDRESS);
	if (unk_0633CB != 0u)
		return;
	unk_061108--;
}

uint32_t func_03101C(uint32_t d0)
{
	uint8_t d1 = 0, d2 = 0;
	uint16_t d1_2 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint32_t a0 = 0, a6 = 0, d0_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;

	d0_2 = (d0 & ~0xFFu) | (uint8_t)unk_0600A4;
	t1 = d0_2 & 7u;
	d0_2 = (d0_2 & ~0xFFu) | t1;
	if (t1 != 0u)
		return d0_2;
	unk_0633E2 += 4u;
	if (unk_0633E2 >= 0xCu)
		unk_0633E2 = 0u;
	if (unk_0633EA != 1u)
	{
		a6 = TABLE32(indexed_table_of_32_bit_values_031152, unk_0633E2);
		a6 = func_0310F8(a6);
		a6 = func_0310F8(a6);
		a6 = func_031118(a6);
		a6 = func_031118(a6);
		a0 = mem_read32(a6);
		a6 += 4u;
		d2 = mem_read8(a6);
		d0_2 = 3u;
		a6++;
		do
		{
			d1_2 = 3u;
			do
			{
				mem_write8(a0, d2);
				a0++;
				mem_write8(a0, mem_read8(a6));
				t2 = d1_2 - 1u;
				d1_2 = t2;
				a0++;
				a6++;
			} while (t2 != 0xFFFFu);
			t3 = d0_2 - 1u;
			d0_2 = t3;
			a0 += 0x78u;
		} while (t3 != 0xFFFFu);
		return d0_2;
	}
	if (unk_0633E2 == 0u)
	{
		a0 = TILE_RAM + 0x4038u;
		d0_2 = 4u;
		d1 = 0x18u;
		d7 = 2u;
		do
		{
			d6 = 7u;
			for (;;)
			{
				d5 = 7u;
				do
				{
					mem_write8(a0, d0_2);
					a0++;
					mem_write8(a0, d1);
					d1++;
					t4 = d5 - 1u;
					d5 = t4;
					a0++;
				} while (t4 != 0xFFFFu);
				d1 += 0x18u;
				t5 = d6 - 1u;
				d6 = t5;
				a0 += 0x70u;
				if (t5 != 0xFFFFu)
					continue;
				d0_2 = (uint8_t)(d0_2 + 1u);
				if ((uint8_t)d7 != 1u)
					break;
				d7 = (uint16_t)((d7 & ~0xFFu) | (uint8_t)(d7 - 1u));
				d6 = 3u;
			}
			t6 = d7 - 1u;
			d7 = t6;
		} while (t6 != 0xFFFFu);
		return d0_2;
	}
	d1 = 0u;
	d2 = 0u;
	if (unk_0633E2 != 4u)
	{
		d1 = 0x80u;
		d2 = 0x20u;
	}
	d0_2 = 0x1Au;
	a0 = TILE_RAM + 0x4038u;
	d7 = 1u;
	d6 = 0xFu;
	for (;;)
	{
		d5 = 7u;
		do
		{
			mem_write8(a0, d0_2);
			a0++;
			mem_write8(a0, d1);
			d1++;
			t7 = d5 - 1u;
			d5 = t7;
			a0++;
		} while (t7 != 0xFFFFu);
		t8 = d6 - 1u;
		d6 = t8;
		a0 += 0x70u;
		if (t8 == 0xFFFFu)
		{
			d6 = 3u;
			d0_2 = 0x1Bu;
			d1 = (uint8_t)d2;
			t9 = d7 - 1u;
			d7 = t9;
			if (t9 != 0xFFFFu)
				continue;
			break;
		}
	}
	return d0_2;
}

uint32_t func_0310F8(uint32_t a6)
{
	uint8_t d2 = 0, d3 = 0;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a0 = 0;
	uint16_t t1 = 0, t2 = 0;

	a0 = mem_read32(a6);
	a6 += 4u;
	d2 = mem_read8(a6);
	d0 = 7u;
	a6++;
	do
	{
		d1 = 7u;
		d3 = mem_read8(a6);
		a6++;
		do
		{
			mem_write8(a0, d2);
			a0++;
			mem_write8(a0, d3);
			d3++;
			t1 = d1 - 1u;
			d1 = t1;
			a0++;
		} while (t1 != 0xFFFFu);
		t2 = d0 - 1u;
		d0 = t2;
		a0 += 0x70u;
	} while (t2 != 0xFFFFu);
	a6++;
	return a6;
}

uint32_t func_031118(uint32_t a6)
{
	uint8_t d2 = 0, d3 = 0;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a0 = 0;
	uint16_t t1 = 0, t2 = 0;

	a0 = mem_read32(a6);
	a6 += 4u;
	d2 = mem_read8(a6);
	d0 = 3u;
	a6++;
	do
	{
		d1 = 3u;
		d3 = mem_read8(a6);
		a6++;
		do
		{
			mem_write8(a0, d2);
			a0++;
			mem_write8(a0, d3);
			d3++;
			t1 = d1 - 1u;
			d1 = t1;
			a0++;
		} while (t1 != 0xFFFFu);
		t2 = d0 - 1u;
		d0 = t2;
		a0 += 0x78u;
	} while (t2 != 0xFFFFu);
	a6++;
	return a6;
}

void func_031230(uint32_t *p_d1, uint32_t *p_a0)
{
	uint8_t d0 = 0;
	uint16_t d7 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, d1 = 0;
	uint16_t t17 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0;

	a0 = TILE_RAM;
	a1 = TILE_RAM + 0x2000u;
	a2 = TILE_RAM + 0x4000u;
	d0 = 0u;
	d1 = 0x10u;
	d7 = 0x200u;
	do
	{
		mem_write8(a0, d0);
		t1 = a1;
		a1++;
		mem_write8(t1, d0);
		t2 = a2;
		a2++;
		mem_write8(t2, d0);
		a0++;
		mem_write8(a0, d1);
		t3 = a1;
		a1++;
		mem_write8(t3, d1);
		t4 = a2;
		a2++;
		mem_write8(t4, d1);
		a0++;
		mem_write8(a0, d0);
		t5 = a1;
		a1++;
		mem_write8(t5, d0);
		t6 = a2;
		a2++;
		mem_write8(t6, d0);
		a0++;
		mem_write8(a0, d1);
		t7 = a1;
		a1++;
		mem_write8(t7, d1);
		t8 = a2;
		a2++;
		mem_write8(t8, d1);
		a0++;
		mem_write8(a0, d0);
		t9 = a1;
		a1++;
		mem_write8(t9, d0);
		t10 = a2;
		a2++;
		mem_write8(t10, d0);
		a0++;
		mem_write8(a0, d1);
		t11 = a1;
		a1++;
		mem_write8(t11, d1);
		t12 = a2;
		a2++;
		mem_write8(t12, d1);
		a0++;
		mem_write8(a0, d0);
		t13 = a1;
		a1++;
		mem_write8(t13, d0);
		t14 = a2;
		a2++;
		mem_write8(t14, d0);
		a0++;
		mem_write8(a0, d1);
		t15 = a1;
		a1++;
		mem_write8(t15, d1);
		t16 = a2;
		a2++;
		mem_write8(t16, d1);
		t17 = d7;
		d7 = (uint16_t)(t17 - 1u);
		a0++;
	} while (t17 != 1u);
	*p_d1 = d1;
	*p_a0 = a0;
}
