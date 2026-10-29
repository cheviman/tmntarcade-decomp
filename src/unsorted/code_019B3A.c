/**
 *    Name:        unsorted/code_019B3A.c
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

void func_019B3A(uint8_t d7, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_a1)
{
	uint32_t carry = 0;
	uint8_t d6 = 0;
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = unk_062000_ADDRESS;
	*p_a1 = unk_062C80_ADDRESS;
	d0 = 0u;
	do
	{
		carry = d7 & 1u;
		d7 = (uint8_t)d7 >> 1;
		if (carry)
		{
			d6 = 0xFFu;
			func_019C94((uint8_t)d0, d6, p_d4, &a0);
			mem_write16(a0 + 8u, 0xA03u);
			unk_061100(d0) = 0x80u;
			func_019ECA(d0, p_d1, &a0, p_a1);
			if (unk_060127 == 0u)
				mem_write8(a0 + 0x2Du, mem_read8(a0 + 0x2Du) | 0x80u);
		}
		d0 = (uint8_t)(d0 + 1u);
		*p_a1 += 0x50u;
		a0 += 0x50u;
	} while (a0 < 0x62140u);
}

void func_019B92(uint8_t d7, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_a1)
{
	uint32_t carry = 0;
	uint8_t d6 = 0;
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = unk_062000_ADDRESS;
	*p_a1 = unk_062C80_ADDRESS;
	d0 = 0u;
	do
	{
		carry = d7 & 1u;
		d7 = (uint8_t)d7 >> 1;
		if (carry)
		{
			d6 = 0u;
			func_019C94((uint8_t)d0, d6, p_d4, &a0);
			mem_write16(a0 + 8u, 0xA03u);
			unk_061100(d0) = 0x80u;
			func_019ECA(d0, p_d1, &a0, p_a1);
			if (unk_060127 == 0u)
				mem_write8(a0 + 0x2Du, mem_read8(a0 + 0x2Du) | 0x80u);
		}
		d0 = (uint8_t)(d0 + 1u);
		*p_a1 += 0x50u;
		a0 += 0x50u;
	} while (a0 < 0x62140u);
}

void func_019BEA(uint8_t d7, uint32_t *p_d1, uint32_t *p_a1)
{
	uint32_t carry = 0;
	uint8_t d6 = 0;
	uint16_t d0 = 0;
	uint32_t a0 = 0, a2 = 0, ignored = 0;

	a0 = unk_062000_ADDRESS;
	*p_a1 = unk_062C80_ADDRESS;
	a2 = unk_060106_ADDRESS;
	d0 = 0u;
	do
	{
		AT32(unk_060066, -3) = a2;
		carry = d7 & 1u;
		d7 = d7 >> 1;
		if (carry)
		{
			d6 = 0xFFu;
			func_019C94((uint8_t)d0, d6, &ignored, &a0);
			a2 = AT32(unk_060066, -3);
			if ((unk_060122 & 0x80u) == 0u)
			{
				mem_write16(a0 + 8u, 0xA03u);
				mem_write16(a2, 0xA03u);
			}
			unk_061100(d0) = 0x80u;
			func_019ECA(d0, p_d1, &a0, p_a1);
			if (unk_060127 == 0u)
				mem_write8(a0 + 0x2Du, mem_read8(a0 + 0x2Du) | 0x80u);
		}
		d0 = (uint8_t)(d0 + 1u);
		a0 += 0x50u;
		a2 = AT32(unk_060066, -3) + 8u;
		*p_a1 += 0x50u;
	} while (a0 < 0x62140u);
	unk_062008 = unk_060106(0);
	unk_062058 = unk_06010E;
	unk_0620A8 = unk_060116;
	unk_0620F8 = unk_06011E;
}

void func_019C94(uint8_t d0, uint8_t d6, uint32_t *p_d4, uint32_t *p_a0)
{
	uint32_t a0 = *p_a0;
	uint16_t d2 = 0;
	uint32_t a0_2 = 0, a6 = 0, d1 = 0;
	uint16_t t1 = 0;

	a6 = a0;
	d1 = 0u;
	d2 = 0x13u;
	do
	{
		mem_write32(a0, d1);
		t1 = d2 - 1u;
		d2 = t1;
		a0 += 4u;
	} while (t1 != 0xFFFFu);
	a0_2 = a6;
	mem_write8(a0_2 + 0x48u, 0x40u);
	unk_061109 = d1;
	mem_write8(a0_2 + 2u, d0);
	mem_write16(a0_2, 0x8101u);
	mem_write8(a0_2 + 0x2Du, 0x7Fu);
	mem_write16(a0_2 + 0x34u, 4u);
	mem_write32(a0_2 + 0x3Au, 0x2E928u);
	mem_write16(a0_2 + 0x42u, 0xFF00u);
	unk_0633EA = 0u;
	if ((uint8_t)d6 != 0u && unk_060005 == 4u && unk_060007 == 0u && unk_060009 == 3u)
	{
		d1 = (uint16_t)((uint32_t)unk_060121 << 2);
		switch (d1)
		{
		case 0:
		case 4:
		case 20:
		case 24:
		case 32:
		case 36:
			func_019CDE(d1, a0_2);
			break;
		case 8:
		case 12:
		case 28:
			*p_d4 = func_019D7C(d1, a0_2);
			break;
		case 16:
			func_019DD4(d1, p_d4, &a0_2);
			break;
		}
	}
	else
		func_019CDE(d1, a0_2);
	*p_a0 = a0_2;
}

void func_019CDE(uint32_t d1, uint32_t a0)
{
	uint32_t a6 = 0, d2 = 0, d3 = 0;

	a6 = indexed_table_of_16_bit_values_019E62_ADDRESS;
	if (unk_060121 == 3u)
		a6 = 0x19E72u;
	d1 = (uint16_t)(IN_PAGE(d1, mem_read8(a0 + 2u)) << 2);
	d2 = DATA16(a6 + d1);
	d3 = DATA16(a6 + 2u + d1);
	mem_write16(a0 + 0xCu, d2);
	mem_write16(a0 + 0xEu, d3);
	mem_write32(a0 + 0x12u, d2 << 8);
	mem_write32(a0 + 0x16u, d3 << 8);
	func_01B920(d1, a0);
}

uint32_t func_019D7C(uint32_t d1, uint32_t a0)
{
	uint32_t a6 = 0, d3 = 0, d4 = 0;

	a6 = 0x19E82u;
	if (unk_060121 == 3u)
		a6 = 0x19E9Au;
	d1 = (uint16_t)(IN_PAGE(d1, mem_read8(a0 + 2u)) << 1);
	d1 = (uint16_t)((d1 << 1) + d1);
	d3 = DATA16(a6 + d1);
	d4 = DATA16(a6 + 2u + d1);
	mem_write16(a0 + 0x10u, DATA16(a6 + 4u + d1));
	mem_write16(a0 + 0xCu, d3);
	mem_write16(a0 + 0xEu, d4);
	d4 = d4 << 8;
	mem_write32(a0 + 0x12u, d3 << 8);
	mem_write32(a0 + 0x16u, d4);
	mem_write16(a0 + 4u, 0x203u);
	func_01B920(d1, a0);
	return d4;
}

void func_019DD4(uint32_t d1, uint32_t *p_d4, uint32_t *p_a0)
{
	uint32_t a0 = *p_a0;
	uint32_t a0_2 = 0, a5 = 0, a6 = 0, d3 = 0, d4 = 0;

	d1 = (uint16_t)(IN_PAGE(d1, mem_read8(a0 + 2u)) << 1);
	d1 = (uint16_t)((d1 << 1) + d1);
	d3 = rom_019EB2[d1 / 2u];
	d4 = rom_019EB4[d1 / 2u];
	mem_write16(a0 + 0x1Eu, rom_019EB6[d1 / 2u]);
	mem_write16(a0 + 0xCu, d3);
	mem_write16(a0 + 0xEu, d4);
	d4 = (uint32_t)(int16_t)d4 << 8;
	mem_write32(a0 + 0x12u, d3 << 8);
	mem_write32(a0 + 0x16u, d4);
	mem_write16(a0 + 0x1Au, 0x800u);
	mem_write16(a0 + 4u, 0x201u);
	func_01B920(d1, a0);
	a5 = a0;
	a0_2 = unk_062DC0_ADDRESS;
	if ((unk_062DC0 & 1u) == 0u)
	{
		AT16(unk_062DC0, -1) = 0x8100u;
		AT32(unk_062DCC, -2) = 0x60FFC8u;
		unk_062DD0 = 0u;
		unk_062DDA = 0x800u;
		unk_062DDC = 0u;
		unk_062E02 = 0xFF00u;
		a6 = 0x2E1C0u;
		set_animation(d1, a0_2, a6);
	}
	a0_2 = a5;
	*p_d4 = d4;
	*p_a0 = a0_2;
}

void func_019ECA(uint16_t d0, uint32_t *p_d1, uint32_t *p_a0, uint32_t *p_a1)
{
	uint32_t a0 = *p_a0;
	uint32_t a1 = *p_a1;
	uint8_t d2 = 0;
	uint32_t a0_2 = 0, a1_2 = 0, a6 = 0, d1 = 0;
	uint8_t t1 = 0;

	a6 = a1;
	d1 = 0u;
	d2 = 0x14u;
	do
	{
		mem_write32(a1, d1);
		t1 = d2;
		d2 = (uint8_t)(t1 - 1u);
		a1 += 4u;
	} while (t1 != 1u);
	a1_2 = a6;
	mem_write16(a1_2, 0x100u);
	mem_write32(a1_2 + 0xCu, mem_read32(a0 + 0xCu));
	mem_write16(a1_2 + 0x10u, mem_read16(a0 + 0x10u));
	mem_write32(a1_2 + 0x12u, mem_read32(a0 + 0x12u));
	mem_write32(a1_2 + 0x16u, mem_read32(a0 + 0x16u));
	mem_write16(a1_2 + 0x42u, 0xFF00u);
	d1 = d0;
	d1 = (uint16_t)(d1 << 2);
	a6 = animations_019F24[d1 / 4u];
	AT32(unk_0633DE, -3) = a0;
	a0_2 = a1_2;
	d1 = set_animation(d1, a0_2, a6);
	a1_2 = a0_2;
	a0_2 = AT32(unk_0633DE, -3);
	*p_d1 = d1;
	*p_a0 = a0_2;
	*p_a1 = a1_2;
}

void func_019F34(void)
{
	uint16_t d7 = 0;
	uint32_t a0 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	if (unk_0633FC != 0u)
	{
		t1 = unk_0633FC;
		unk_0633FC = t1 - 1u;
		if (t1 == 1u)
			func_03030C(&ignored, &ignored_2, &ignored_3);
	}
	unk_0633CB = 0u;
	switch (unk_060121)
	{
	case 0:
	case 1:
	case 5:
	case 6:
	case 8:
	case 9:
		func_019FBA();
		break;
	case 2:
	case 3:
	case 7:
		func_019FC8();
		break;
	case 4:
		func_01A138();
		break;
	}
	if (unk_061109 == 0u)
		return;
	a0 = unk_062C80_ADDRESS;
	d7 = 3u;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
			mem_write8(a0, 0x81u);
		t2 = d7 - 1u;
		d7 = t2;
		a0 += 0x50u;
	} while (t2 != 0xFFFFu);
}

void func_019FBA(void)
{
	unk_061109 = 0xFFu;
	func_01E1BA();
}

void func_019FC8(void)
{
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)unk_0633EA << 2);
	switch (d0)
	{
	case 0:
		func_019FE6();
		return;
	case 4:
		func_01A02C(d0);
		return;
	}
}

void func_019FE6(void)
{
	uint32_t a0 = 0, a6 = 0;

	func_01E1BA();
	if (unk_060121 == 7u)
	{
		a0 = unk_062DC0_ADDRESS;
		unk_062DC0 = 0x81u;
		unk_062DC1 = 0u;
		unk_062DD0 = 0u;
		unk_062E02 = 0xFF00u;
		unk_062DCC = 0x40u;
		unk_062DCE = 0x38u;
		a6 = 0x2E0ECu;
		set_animation(0u, a0, a6);
	}
	unk_0633EA++;
}

void func_01A02C(uint32_t d0)
{
	uint8_t d7 = 0;
	uint16_t d2 = 0;
	uint32_t a0 = 0, d1 = 0;
	uint8_t t1 = 0;
	uint16_t t3 = 0;
	uint32_t t2 = 0;

	if (unk_060121 != 7u || unk_062DCC >= 0x120u)
	{
		a0 = unk_062000_ADDRESS;
		do
		{
			if ((mem_read8(a0) & 1u) != 0u)
			{
				if (mem_read16(a0 + 0x10u) == 0u)
				{
					if (mem_read8(a0 + 4u) != 0u)
					{
						unk_0633CB--;
						t1 = mem_read8(a0 + 0x1Du);
						mem_write8(a0 + 0x1Du, t1 - 1u);
						if (t1 == 1u)
						{
							mem_write8(a0 + 4u, 0u);
							func_01B920(d1, a0);
						}
					}
					else if (unk_060121 == 7u && unk_061106 == 0u)
					{
						d0 &= ~0xFFu;
						d1 = mem_read16(a0 + 0xCu);
						d2 = mem_read16(a0 + 0xEu);
						d0 = func_02FFE6(d0, d1, d2);
					}
				}
				else
				{
					unk_0633CB--;
					t2 = mem_read32(a0 + 0x12u) + 0x300u;
					mem_write16(a0 + 0x14u, t2);
					mem_write16(a0 + 0x12u, t2 >> 16);
					mem_write16(a0 + 0xCu, mem_read32(a0 + 0x12u) >> 8);
					t3 = mem_read16(a0 + 0x10u);
					mem_write16(a0 + 0x10u, t3 - 0x600u);
					if (t3 < 0x600u)
					{
						mem_write16(a0 + 0x10u, 0u);
						mem_write8(a0 + 0x1Du, 8u);
						mem_write8(a0 + 5u, 0u);
						func_01B920(d1, a0);
					}
				}
			}
			a0 += 0x50u;
		} while (a0 < 0x62140u);
	}
	a0 = unk_062DC0_ADDRESS;
	if (unk_062DC0 == 0u)
	{
		if (unk_0633CB != 0u)
			return;
		unk_061109 = 0xFFu;
		return;
	}
	if ((unk_0600A4 & 0x1Fu) == 0u)
	{
		d7 = 0x39u;
		func_0091A4(d7, 0u);
	}
	unk_062DCC += 2u;
	if (unk_062DCC < 0x1C0u)
		return;
	unk_062DC0 = 0u;
}

void func_01A138(void)
{
	switch (unk_0633EA)
	{
	case 0:
		func_01A156();
		return;
	case 1:
		func_01A160();
		return;
	}
}

void func_01A156(void)
{
	func_01E1BA();
	unk_0633EA++;
}

void func_01A160(void)
{
	uint16_t d2 = 0;
	uint32_t a0 = 0, d1 = 0;
	uint8_t t7 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0;
	uint32_t t1 = 0, t2 = 0, t6 = 0;

	a0 = unk_062DC0_ADDRESS;
	if ((unk_062DC0 & 1u) != 0u)
	{
		unk_062DCC--;
		if (unk_062DDC != 0u)
		{
			t1 = unk_062DD6 - (int16_t)unk_062DDA;
			AS16(unk_062DD6) = t1;
			AT16(unk_062DD6, 2) = t1 >> 16;
			unk_062DDA += 0x20u;
		}
		else
		{
			t2 = unk_062DD6 + (int16_t)unk_062DDA;
			AS16(unk_062DD6) = t2;
			AT16(unk_062DD6, 2) = t2 >> 16;
			t3 = unk_062DDA;
			unk_062DDA = t3 - 0x40u;
			if (t3 < 0x40u)
			{
				unk_062DDC--;
				unk_062DDA = 0u - unk_062DDA;
			}
		}
	}
	unk_062DCE = unk_062DD6 >> 8;
	if (unk_062DCC < 0x28u)
		unk_062DC0 = 0u;
	a0 = unk_062000_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			if (mem_read8(a0 + 0x1Du) == 0u)
			{
				if (mem_read16(a0 + 4u) != 0u)
				{
					unk_0633CB--;
					if (mem_read8(a0 + 0x1Cu) != 0u)
					{
						mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + 0x50u);
						d1 = mem_read16(a0 + 0x1Au);
						t4 = mem_read16(a0 + 0x10u);
						mem_write16(a0 + 0x10u, t4 - d1);
						if (t4 < d1)
						{
							mem_write16(a0 + 0x10u, 0u);
							mem_write8(a0 + 5u, 0u);
							func_01B920(d1, a0);
							mem_write8(a0 + 0x1Du, 8u);
						}
					}
					else
					{
						mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Au));
						if (mem_read16(a0 + 0x10u) >= 0x3800u && (int8_t)mem_read8(a0 + 0x16u) < 0)
						{
							mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - 0x3800u);
							mem_write16(a0 + 0x18u, 0u);
							mem_write16(a0 + 0x16u, 0u);
							mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
						}
						t5 = mem_read16(a0 + 0x1Au);
						mem_write16(a0 + 0x1Au, t5 - 0x20u);
						if (t5 < 0x20u)
						{
							d1 = mem_read8(a0 + 2u);
							d1 = indexed_table_of_8_bit_values_01A2D2[d1];
							mem_write16(a0 + 0xEu, d1);
							d1 = (uint16_t)(d1 << 8);
							mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - d1);
							mem_write32(a0 + 0x16u, d1);
							mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
							mem_write8(a0 + 0x1Cu, mem_read8(a0 + 0x1Cu) - 1u);
						}
					}
					t6 = mem_read32(a0 + 0x12u) + (int16_t)mem_read16(a0 + 0x1Eu);
					mem_write16(a0 + 0x14u, t6);
					mem_write16(a0 + 0x12u, t6 >> 16);
					d2 = (uint16_t)(mem_read32(a0 + 0x16u) >> 8);
					mem_write16(a0 + 0xCu, mem_read32(a0 + 0x12u) >> 8);
					mem_write16(a0 + 0xEu, d2);
				}
			}
			else
			{
				unk_0633CB--;
				t7 = mem_read8(a0 + 0x1Du);
				mem_write8(a0 + 0x1Du, t7 - 1u);
				if (t7 == 1u)
				{
					mem_write16(a0 + 4u, 0u);
					func_01B920(d1, a0);
				}
			}
		}
		a0 += 0x50u;
	} while (a0 < 0x62140u);
	if (unk_0633CB != 0u)
		return;
	unk_061109 = 0xFFu;
	unk_062DC0 = 0u;
}

uint32_t func_01A2D6(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, a6 = 0;

	a0 = unk_062000_ADDRESS;
	a6 = indexed_table_of_32_bit_values_01A308_ADDRESS;
	do
	{
		d0 = 0u;
		if ((unk_0600A4 & 4u) != 0u)
			d0 = 4u;
		mem_write32(a0 + 0x3Au, DATA32(a6 + d0));
		a0 += 0x50u;
		a6 += 8u;
	} while (a0 < 0x62140u);
	return a0;
}

void func_01A328(uint32_t d1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t a4 = 0, a5 = 0, a6 = 0;
	uint8_t t1 = 0;

	a4 = unk_062000_ADDRESS;
	a5 = unk_062C80_ADDRESS;
	a6 = unk_061100_ADDRESS;
	do
	{
		if (mem_read8(a6) != 0u)
		{
			mem_write32(a5 + 0xCu, mem_read32(a4 + 0xCu));
			mem_write32(a5 + 0x10u, mem_read32(a4 + 0x10u));
			t1 = mem_read8(a6);
			mem_write8(a6, t1 - 1u);
			if (t1 == 1u)
				mem_write8(a5, 0u);
		}
		a6++;
		a4 += 0x50u;
		a5 += 0x50u;
	} while (a6 < unk_061104_ADDRESS);
	unk_060106(0) = unk_062008;
	unk_06010E = unk_062058;
	unk_060116 = unk_0620A8;
	unk_06011E = unk_0620F8;
	if (indexed_table_of_8_bit_values_01A3C0[unk_060121] != 0u)
	{
		func_01E712();
		func_01A3CA(d1, &d5, p_d7, p_a1);
		func_01E732();
	}
	else
	{
		func_01E708();
		func_01A3CA(d1, &d5, p_d7, p_a1);
		func_01E728();
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_01A3CA(uint32_t d1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint8_t d0_2 = 0, d1_3 = 0;
	uint16_t d0_3 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, d0 = 0, d1_2 = 0;
	uint8_t t1 = 0, t7 = 0;
	uint32_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	unk_061107 = 0u;
	if (unk_060121 == 2u && unk_0633C0 == 4u)
	{
		unk_061107--;
		if (unk_063384 < 0x1C000u)
			unk_0633C2 = (unk_0633C2 & 0xFF00FFFFu) | 0xFF0000u;
	}
	d0 = 0u;
	unk_063334 = 0u;
	unk_063335 = 0u;
	unk_063374 = 0u;
	unk_063375 = 0u;
	unk_0633B4 = 0u;
	unk_0633B5 = 0u;
	unk_0633CA = 0u;
	if ((int8_t)unk_0633C9 >= 0)
	{
		unk_06331A = (uint8_t)(d0 >> 8u);
		unk_06331B = (uint8_t)d0;
		unk_06330C = (uint16_t)(d0 >> 16u);
		unk_06330E = (uint16_t)d0;
	}
	a0 = unk_062000_ADDRESS;
	a1 = unk_060020_ADDRESS;
	a2 = unk_06004C_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			func_01B69E(0u, a0, a1, a2, &d1, &d5, &d7);
			d1 = func_01ADA0(d1, a0, a1);
			if (mem_read8(a0 + 2u) == 3u && mem_read16(a0 + 4u) == 0x307u)
				mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
			if (unk_060121 != 8u || (int8_t)unk_0633C9 >= 0)
			{
				if (mem_read32(a0 + 0x12u) >= 0x9000u)
				{
					if (mem_read32(a0 + 0x12u) >= 0x16000u)
						mem_write32(a0 + 0x12u, 0x16000u);
				}
				else
					mem_write32(a0 + 0x12u, 0x9000u);
				if (mem_read32(a0 + 0x16u) >= func_001000_ADDRESS)
				{
					if (mem_read32(a0 + 0x16u) >= 0xA000u)
						mem_write32(a0 + 0x16u, 0xA000u);
				}
				else
					mem_write32(a0 + 0x16u, func_001000_ADDRESS);
				if ((int8_t)mem_read8(a0 + 0x10u) < 0)
				{
					t1 = mem_read8(a0 + 4u);
					d0_2 = (uint8_t)(t1 - 2u);
					if (t1 < 2u || d0_2 >= 3u)
					{
						mem_write16(a0 + 0x10u, 0u);
						mem_write8(a0 + 0x32u, 0u);
					}
				}
			}
			else
			{
				if (mem_read32(a0 + 0x12u) >= 0x18800u)
					mem_write32(a0 + 0x12u, 0x18800u);
				t2 = mem_read32(a0 + 0x16u);
				d0 = t2 - 0x1000u;
				if (t2 < 0x1000u)
					d0 = 0u;
				d1 = d0 + 0x13000u;
				d0 += 0x8000u;
				if (mem_read32(a0 + 0x12u) <= d0)
					mem_write32(a0 + 0x12u, d0);
				if (d1 < mem_read32(a0 + 0x12u))
					mem_write32(a0 + 0x12u, d1);
			}
		}
		a2++;
		a0 += 0x50u;
		a1++;
	} while (a0 < 0x62140u);
	if (unk_060121 == 6u)
		a0 = func_01A2D6();
	func_01ACDA(d1, a0);
	a0 = unk_062000_ADDRESS;
	a1 = unk_060020_ADDRESS;
	do
	{
		if ((mem_read8(a0) & 1u) != 0u)
		{
			if ((int8_t)unk_0633C9 >= 0)
			{
				d0 = unk_06330C;
				d1_2 = unk_06330E;
				if ((mem_read8(a0 + 3u) & 0x7Fu) == 0u && unk_06331B != 0u)
				{
					if ((int8_t)unk_06331B < 0)
					{
						t3 = mem_read32(a0 + 0x12u) - d0;
						mem_write16(a0 + 0x14u, t3);
						mem_write16(a0 + 0x12u, t3 >> 16);
					}
					else
					{
						t4 = mem_read32(a0 + 0x12u) + d0;
						mem_write16(a0 + 0x14u, t4);
						mem_write16(a0 + 0x12u, t4 >> 16);
					}
				}
				if ((int8_t)mem_read8(a0 + 3u) >= 0 && unk_06331A != 0u)
				{
					if ((int8_t)unk_06331A >= 0)
					{
						t5 = mem_read32(a0 + 0x16u) - d1_2;
						mem_write16(a0 + 0x18u, t5);
						mem_write16(a0 + 0x16u, t5 >> 16);
					}
					else
					{
						t6 = mem_read32(a0 + 0x16u) + d1_2;
						mem_write16(a0 + 0x18u, t6);
						mem_write16(a0 + 0x16u, t6 >> 16);
					}
				}
			}
			mem_write8(a0 + 0xCu, mem_read8(a0 + 0x13u));
			mem_write8(a0 + 0xDu, mem_read8(a0 + 0x14u));
			mem_write8(a0 + 0xEu, mem_read8(a0 + 0x17u));
			mem_write8(a0 + 0xFu, mem_read8(a0 + 0x18u));
			if (unk_060121 == 8u)
			{
				func_01E732();
				func_01E708();
				func_01AB2C(a0, a1, &d5, &d7);
				func_01E728();
				func_01E712();
			}
			else
				func_01AB2C(a0, a1, &d5, &d7);
		}
		if (mem_read8(a0 + 2u) == 3u && mem_read8(a0 + 5u) == 7u)
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
		mem_write8(a0 + 0xCu, mem_read8(a0 + 0x13u));
		mem_write8(a0 + 0xDu, mem_read8(a0 + 0x14u));
		mem_write8(a0 + 0xEu, mem_read8(a0 + 0x17u));
		mem_write8(a0 + 0xFu, mem_read8(a0 + 0x18u));
		a0 += 0x50u;
		a1++;
	} while (a0 < 0x62140u);
	if (unk_0633EC == 0u)
	{
		d0_3 = unk_060121;
		a0 = mem_read32(area_scroll_segments[(uint8_t)((uint32_t)d0_3 << 2) / 4u] + (int16_t)unk_0633C0);
		if (mem_read8(a0) != 0u)
		{
			d0 = unk_063300;
			t7 = mem_read8(a0 + 1u);
			d1_3 = t7;
			if ((int8_t)t7 < 0)
				d0 = unk_063304;
			if ((d1_3 & 0x7Fu) != 0u)
			{
				if (d0 < mem_read32(a0 + 2u))
				{
					unk_0633C0 += 4u;
					d7 = start_scroll_segment(d7);
				}
			}
			else if (mem_read32(a0 + 2u) <= d0)
			{
				unk_0633C0 += 4u;
				d7 = start_scroll_segment(d7);
			}
		}
	}
	else
	{
		d7 = func_01A876(d7);
		if (unk_0633C8 != 0u && unk_0633CA == 0u)
			unk_0600BD--;
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
	*p_a1 = a1;
}
