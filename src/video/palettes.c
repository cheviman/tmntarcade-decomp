/**
 *    Name:        video/palettes.c
 *    Description: the palettes: requests queued and done a frame later, the palette effects
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint32_t post_palette_request(uint16_t d7, uint32_t a6)
{
	uint32_t a5 = 0;

	a5 = unk_060BF0;
	mem_write16(a5, d7);
	a5 += 2u;
	mem_write32(a5, a6);
	a5 += 4u;
	if (a5 > 0x60BEFu)
		a5 = 0x60B00u;
	unk_060BF0 = a5;
	return a5;
}

void unreached_009264(uint32_t a4)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	for (;;)
	{
		d7 = mem_read16(a4);
		a4 += 2u;
		if (d7 == 0xFFFFu)
			break;
		a6 = mem_read32(a4);
		a4 += 4u;
		post_palette_request(d7, a6);
	}
}

void func_009272(uint32_t d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a0 = 0, a6 = 0, d7_2 = 0, ignored = 0;
	uint16_t t1 = 0;
	uint32_t t2 = 0;

	if (unk_060BF8 != 0u)
	{
		d7_2 = (d7 & ~0xFFu) | unk_060BF8;
		func_00935A(&ignored, &d5, p_d6, &d7_2, p_a5);
	}
	else if (unk_060BF9 != 0u)
	{
		d7_2 = (d7 & ~0xFFu) | unk_060BF9;
		a6 = unk_060BFC;
		func_0093F4(a6, &ignored, p_d6, &d7_2, p_a5);
	}
	else if (unk_060BFA != 0u)
	{
		d7_2 = (d7 & ~0xFFu) | unk_060BFA;
		func_009562(&ignored, p_d6, &d7_2, p_a5);
	}
	else if (unk_060BFB == 0u)
	{
		a0 = unk_060BF4;
		t1 = mem_read16(a0);
		d0 = t1;
		if (t1 != 0u)
		{
			d7_2 = (uint8_t)d0;
			a6 = mem_read32(a0 + 2u);
			d0 = (d0 & 0x3F00u) >> 6;
			mem_write16(a0, 0u);
			a0 += 2u;
			mem_write16(a0 + 2u, 0u);
			mem_write16(a0, 0u);
			a0 += 4u;
			if (a0 > 0x60BEFu)
				a0 = 0x60B00u;
			unk_060BF4 = a0;
			switch (d0)
			{
			case 0:
			case 36:
				func_009358();
				break;
			case 4:
				func_00935A(&ignored, &d5, p_d6, &d7_2, p_a5);
				break;
			case 8:
				func_0093EE(a6, &ignored, p_d6, &d7_2, p_a5);
				break;
			case 12:
				func_009484(a6, &ignored, p_d6, &d7_2, p_a5);
				break;
			case 16:
				func_0094F2(d7_2, a6, p_d6, p_a5);
				break;
			case 20:
				func_009526((uint8_t)d7_2, a6, p_d6, p_a5);
				break;
			case 24:
				func_009562(&ignored, p_d6, &d7_2, p_a5);
				break;
			case 28:
			case 32:
				func_0095D0();
				break;
			}
		}
		unk_060083 = 0u;
		t2 = (((uint32_t)unk_060BF8 << 24u) | ((uint32_t)unk_060BF9 << 16u) | ((uint32_t)unk_060BFA << 8u) | unk_060BFB);
		d7_2 = t2;
		if (t2 != 0u)
			unk_060083 = 1u;
	}
	else
	{
		d7_2 = unk_060BFB;
		d7_2 = (uint16_t)(d7_2 << 2);
		switch (d7_2)
		{
		case 0:
		case 16:
		case 20:
		case 28:
		case 32:
			func_009358();
			break;
		case 4:
			func_0093E2(&ignored, &d5, p_d6, &d7_2, p_a5);
			break;
		case 8:
			func_009472(&ignored, p_d6, &d7_2, p_a5);
			break;
		case 12:
			func_0094E2(&ignored, p_d6, &d7_2, p_a5);
			break;
		case 24:
			func_0095CA(&ignored, p_d6, &d7_2, p_a5);
			break;
		}
		unk_060BFB = 0u;
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

void func_009358(void)
{
}

void func_00935A(uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d4 = (uint8_t)*p_d4;
	uint16_t d5 = (uint16_t)*p_d5;
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d6 = 0;

	a6 = area_palettes_ADDRESS;
	d6 = 0u;
	for (;;)
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) == 0u)
		{
			d6 = (uint8_t)(d6 + 1u);
			if (d6 < 4u)
				continue;
			unk_060BF8 = 0u;
			break;
		}
		d4 = (uint8_t)d6;
		unk_060BF8 = d7 & ~shl32(1u, (int)(d6 & 0x1Fu));
		d7 = palette_bank_counts[d6];
		d5 = (uint16_t)((uint32_t)unk_060121 << 2);
		d6 = (uint16_t)(d6 << 2);
		a6 = mem_read32(DATA32(a6 + d5) + d6);
		*p_a5 = palette_bank_addresses[d6 / 4u];
		if (unk_060BFB != 0u)
		{
			*p_a5 += 0x200u;
			a6 += 0x20u;
		}
		if (d4 == 3u)
			unk_060BFB = 1u;
		copy_palette_list((uint16_t)d7, a6, &d6, p_a5);
		break;
	}
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | d4;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d6 = d6;
	*p_d7 = d7;
}

void func_0093E2(uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d4 = *p_d4;
	uint32_t d5 = *p_d5;

	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	func_00935A(&d4, &d5, p_d6, p_d7, p_a5);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | (d4 & 0xFFu);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void func_0093EE(uint32_t a6, uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d4 = *p_d4;

	unk_060BFC = a6;
	func_0093F4(a6, &d4, p_d6, p_d7, p_a5);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | (d4 & 0xFFu);
}

void func_0093F4(uint32_t a6, uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d4 = (uint8_t)*p_d4;
	uint32_t d7 = *p_d7;
	uint32_t a6_2 = 0, d6 = 0;

	d6 = 0u;
	for (;;)
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) == 0u)
		{
			d6 = (uint8_t)(d6 + 1u);
			if (d6 < 4u)
				continue;
			unk_060BF9 = 0u;
			unk_060BFC &= 0xFFFF0000u;
			unk_060BFC &= 0xFFFFu;
			break;
		}
		d4 = (uint8_t)d6;
		unk_060BF9 = d7 & ~shl32(1u, (int)(d6 & 0x1Fu));
		d7 = palette_bank_counts[d6];
		d6 = (uint16_t)(d6 << 2);
		a6_2 = mem_read32(a6 + d6);
		*p_a5 = palette_bank_addresses[d6 / 4u];
		if (unk_060BFB != 0u)
		{
			*p_a5 += 0x200u;
			a6_2 += 0x20u;
		}
		if (d4 == 3u)
			unk_060BFB = 2u;
		copy_palette_list((uint16_t)d7, a6_2, &d6, p_a5);
		break;
	}
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | d4;
	*p_d6 = d6;
	*p_d7 = d7;
}

void func_009472(uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d4 = *p_d4;
	uint32_t a6 = 0;

	a6 = unk_060BFC;
	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	func_0093EE(a6, &d4, p_d6, p_d7, p_a5);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | (d4 & 0xFFu);
}

void func_009484(uint32_t a6, uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d4 = (uint8_t)*p_d4;
	uint32_t d7 = *p_d7;
	uint32_t d6 = 0;

	d6 = 0u;
	for (;;)
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) == 0u)
		{
			d6 = (uint8_t)(d6 + 1u);
			if (d6 >= 4u)
				break;
			continue;
		}
		d4 = (uint8_t)d6;
		d7 = palette_bank_counts[d6];
		*p_a5 = palette_bank_addresses[d6 & 0x3FFFu];
		if (unk_060BFB != 0u)
		{
			*p_a5 += 0x200u;
			a6 += 0x20u;
		}
		if (d4 == 3u)
		{
			unk_060BFC = a6;
			unk_060BFB = 3u;
		}
		copy_palette_list((uint16_t)d7, a6, &d6, p_a5);
		break;
	}
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | d4;
	*p_d6 = d6;
	*p_d7 = d7;
}

void func_0094E2(uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d4 = *p_d4;
	uint32_t a6 = 0;

	a6 = unk_060BFC;
	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	func_009484(a6, &d4, p_d6, p_d7, p_a5);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | (d4 & 0xFFu);
}

void func_0094F2(uint32_t d7, uint32_t a6, uint32_t *p_d6, uint32_t *p_a5)
{
	uint16_t d6 = 0;
	uint32_t a5 = 0, d6_2 = 0;
	uint16_t t1 = 0;

	d6 = (uint16_t)d7;
	d7 &= 0xFu;
	d6 = d6 & ~0xFu;
	a5 = TABLE32(palette_bank_addresses, d6 >> 2) + (uint16_t)(d7 << 6);
	d6_2 = 0xFu;
	do
	{
		mem_write8(a5 + 1u, mem_read8(a6));
		a6++;
		mem_write8(a5 + 3u, mem_read8(a6));
		t1 = d6_2 - 1u;
		d6_2 = t1;
		a6++;
		a5 += 4u;
	} while (t1 != 0xFFFFu);
	*p_d6 = d6_2;
	*p_a5 = a5;
}

void func_009526(uint8_t d7, uint32_t a6, uint32_t *p_d6, uint32_t *p_a5)
{
	uint16_t d6 = 0;
	uint32_t a4 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	d6 = (uint16_t)d7;
	d6 = d6 & ~0xFu;
	*p_a5 = TABLE32(palette_bank_addresses, d6 >> 2);
	for (;;)
	{
		t1 = mem_read8(a6);
		*p_d6 = t1;
		a6++;
		if ((int8_t)t1 < 0)
			break;
		d7_2 = mem_read8(a6);
		a4 = *p_a5 + (uint16_t)(*p_d6 << 6) + (uint16_t)(d7_2 << 2);
		a6++;
		mem_write8(a4 + 1u, mem_read8(a6));
		a6++;
		mem_write8(a4 + 3u, mem_read8(a6));
		a6++;
	}
}

void func_009562(uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d4 = (uint8_t)*p_d4;
	uint32_t d7 = *p_d7;
	uint32_t d6 = 0;

	d6 = 0u;
	for (;;)
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) == 0u)
		{
			d6 = (uint8_t)(d6 + 1u);
			if (d6 < 4u)
				continue;
			unk_060BFA = 0u;
			break;
		}
		d4 = (uint8_t)d6;
		unk_060BFA = d7 & ~shl32(1u, (int)(d6 & 0x1Fu));
		d7 = palette_bank_counts[d6];
		*p_a5 = palette_bank_addresses[d6 & 0x3FFFu];
		if (unk_060BFB != 0u)
			*p_a5 += 0x200u;
		if (d4 == 3u)
			unk_060BFB = 6u;
		func_009602((uint16_t)d7, &d6, p_a5);
		break;
	}
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | d4;
	*p_d6 = d6;
	*p_d7 = d7;
}

void func_0095CA(uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d4 = *p_d4;

	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	func_009562(&d4, p_d6, p_d7, p_a5);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | (d4 & 0xFFu);
}

void func_0095D0(void)
{
}

void copy_palette_list(uint16_t d7, uint32_t a6, uint32_t *p_d6, uint32_t *p_a5)
{
	uint32_t a5 = *p_a5;
	uint32_t a4 = 0, d6 = 0;
	uint16_t t1 = 0, t2 = 0;

	do
	{
		d6 = 0xFu;
		a4 = mem_read32(a6);
		a6 += 4u;
		do
		{
			mem_write8(a5 + 1u, mem_read8(a4));
			a4++;
			mem_write8(a5 + 3u, mem_read8(a4));
			a5 += 4u;
			t1 = d6 - 1u;
			d6 = t1;
			a4++;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
	*p_d6 = d6;
	*p_a5 = a5;
}

void func_009602(uint16_t d7, uint32_t *p_d6, uint32_t *p_a5)
{
	uint32_t a5 = *p_a5;
	uint32_t d6 = 0;
	uint16_t t1 = 0, t2 = 0;

	do
	{
		d6 = 0xFu;
		do
		{
			mem_write8(a5 + 1u, 0u);
			mem_write8(a5 + 3u, 0u);
			t1 = d6 - 1u;
			d6 = t1;
			a5 += 4u;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
	*p_d6 = d6;
	*p_a5 = a5;
}

void copy_palette_sets(uint16_t d6, uint32_t a5)
{
	switch ((uint32_t)(int8_t)(uint8_t)unk_063410)
	{
	case 0:
		func_009642(d6, a5);
		return;
	case 1:
		func_009678();
		return;
	case 3:
		func_0096EA();
		return;
	case 2:
		func_009770();
		return;
	}
}

void func_009642(uint16_t d6, uint32_t a5)
{
	unk_063410 = (unk_063410 & 0xFFu) | 0x100u;
	unk_063410 = (unk_063410 & 0xFF00u) | ((uint8_t)unk_063410 + 1u & 0xFFu);
	unk_063412 = 0u;
	unk_063413 = 0u;
	unk_063418 = (uint8_t)(d6 >> 8u);
	unk_063419 = (uint8_t)d6;
	unk_063414 = a5;
	unk_06341A = 0x63800u;
	func_009678();
}

void func_009678(void)
{
	uint32_t a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0;

	for (;;)
	{
		d7 = unk_063412;
		if ((unk_063418 & shl32(1u, (int)(d7 & 7u))) != 0u)
		{
			func_009744(&d7, &a5, &a6);
			do
			{
				mem_write8(a5, mem_read8(a6 + 1u));
				a5++;
				mem_write8(a5, mem_read8(a6 + 3u));
				t1 = d7 - 1u;
				d7 = t1;
				a5++;
				a6 += 4u;
			} while (t1 != 0xFFFFu);
			unk_06341A = a5;
			unk_063412++;
			if (unk_063412 < 5u)
				break;
			unk_063410 = (unk_063410 & 0xFF00u) | ((uint8_t)unk_063410 + 1u & 0xFFu);
			unk_063412 = 0u;
			unk_063413 = 0u;
			unk_06341A = 0x63800u;
			break;
		}
		unk_063412++;
		if (unk_063412 < 5u)
			continue;
		unk_063410 = (unk_063410 & 0xFF00u) | ((uint8_t)unk_063410 + 1u & 0xFFu);
		unk_063412 = 0u;
		unk_063413 = 0u;
		unk_06341A = 0x63800u;
		return;
	}
}

void func_0096EA(void)
{
	uint32_t a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0;

	for (;;)
	{
		d7 = unk_063412;
		if ((unk_063418 & shl32(1u, (int)(d7 & 7u))) != 0u)
		{
			func_009744(&d7, &a5, &a6);
			do
			{
				mem_write8(a6 + 1u, mem_read8(a5));
				a5++;
				mem_write8(a6 + 3u, mem_read8(a5));
				t1 = d7 - 1u;
				d7 = t1;
				a5++;
				a6 += 4u;
			} while (t1 != 0xFFFFu);
			unk_06341A = a5;
			unk_063412++;
			if (unk_063412 < 5u)
				break;
			unk_063412 = 0u;
			unk_063413 = 0u;
			unk_063410 = 0u;
			break;
		}
		unk_063412++;
		if (unk_063412 < 5u)
			continue;
		unk_063412 = 0u;
		unk_063413 = 0u;
		unk_063410 = 0u;
		return;
	}
}

void func_009744(uint32_t *p_d7, uint32_t *p_a5, uint32_t *p_a6)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint16_t d7_2 = 0;

	*p_a6 = indexed_table_of_32_bit_values_00975C[d7 & 0x3FFFu];
	d7_2 = 0x7Fu;
	*p_a5 = unk_06341A;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_2;
}

void func_009770(void)
{
	uint16_t d0 = 0, d1 = 0, d6 = 0;
	uint32_t a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, d5 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	a6 = unk_06341A;
	d0 = unk_063419 & 0xFu;
	a5 = unk_063414;
	while ((unk_063418 & shl32(1u, (int)(unk_063412 & 7u))) == 0u)
	{
		unk_063412++;
		if (unk_063412 >= 5u)
		{
			unk_06341A = 0x63800u;
			unk_063410 = (unk_063410 & 0xFF00u) | ((uint8_t)unk_063410 + 1u & 0xFFu);
			unk_063412 = 0u;
			unk_063413 = 0u;
			return;
		}
	}
	d6 = unk_063412;
	if (d6 == 4u)
		d6 = 3u;
	a4 = mem_read32(a5 + (uint16_t)((uint32_t)d6 << 2));
	unk_063413 = 8u;
	do
	{
		a3 = mem_read32(a4);
		d6 = 0xFu;
		a4 += 4u;
		do
		{
			d1 = mem_read16(a6);
			a2 = table_loaded_by_lea_009872_ADDRESS;
			d5 = 0u;
			func_009838(d0, d1, a3, &d5, &a2);
			func_009838(d0, d1, a3, &d5, &a2);
			func_009838(d0, d1, a3, &d5, &a2);
			mem_write16(a6, d5);
			t1 = d6 - 1u;
			d6 = t1;
			a6 += 2u;
			a3 += 2u;
		} while (t1 != 0xFFFFu);
		t2 = unk_063413;
		unk_063413 = t2 - 1u;
	} while (t2 != 1u);
	unk_063412++;
	if (unk_063412 >= 5u)
	{
		unk_06341A = 0x63800u;
		unk_063410 = (unk_063410 & 0xFF00u) | ((uint8_t)unk_063410 + 1u & 0xFFu);
		unk_063412 = 0u;
		unk_063413 = 0u;
		return;
	}
	unk_06341A = a6;
}

void func_009838(uint16_t d0, uint16_t d1, uint32_t a3, uint32_t *p_d5, uint32_t *p_a2)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint32_t a2 = *p_a2;
	uint16_t d2 = 0, d3 = 0, d4 = 0, d7 = 0;
	uint16_t t1 = 0;

	d3 = mem_read16(a2);
	d2 = d1 & d3;
	a2 += 2u;
	d4 = (uint16_t)((uint32_t)d0 * mem_read16(a2));
	d7 = mem_read16(a3) & d3;
	a2 += 2u;
	if (d2 != d7)
	{
		if (d7 <= d2)
		{
			t1 = d2;
			d2 = (uint16_t)(t1 - d4);
			if (t1 < (uint16_t)d4)
				d2 = 0u;
			if (d2 < d7)
				d2 = (uint16_t)d7;
		}
		else
		{
			d2 += d4;
			if (d7 <= d2)
				d2 = (uint16_t)d7;
		}
	}
	d5 |= d2;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_a2 = a2;
}

void start_palette_effects(uint32_t a6)
{
	uint16_t d5 = 0, d6 = 0, d7 = 0;
	uint32_t a3 = 0, a4 = 0, a5 = 0;
	uint16_t t1 = 0;

	d7 = (uint16_t)(mem_read16(a6) - 1u);
	a5 = 0x60480u;
	a6 += 2u;
	for (;;)
	{
		if ((mem_read8(a5) & 0x80u) == 0u)
		{
			a4 = mem_read32(a6);
			d6 = mem_read16(a4);
			d5 = (d6 & 0xF00u) >> 6;
			a3 = TABLE32(indexed_table_of_32_bit_values_0098F2, d5) + (uint16_t)((d6 & 0xF0u) << 2) + (uint16_t)((d6 & 0xFu) << 2);
			mem_write8(a5 + 1u, 0u);
			mem_write8(a5, (d5 >> 2) | 0x80u);
			mem_write32(a5 + 2u, a4 + 2u);
			mem_write32(a5 + 6u, a3);
			t1 = d7 - 1u;
			d7 = t1;
			a6 += 4u;
			if (t1 != 0xFFFFu)
				continue;
			break;
		}
		a5 += 0xAu;
		if (a5 >= 0x60700u)
			break;
	}
}

void step_palette_effects(void)
{
	uint32_t carry = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	a6 = 0x60480u;
	d7 = 0x3Fu;
	do
	{
		if ((mem_read8(a6) & 0x80u) != 0u)
		{
			t1 = mem_read8(a6 + 1u);
			carry = t1 == 0u;
			mem_write8(a6 + 1u, t1 - 1u);
			if (t1 == 1u || carry)
			{
				for (;;)
				{
					a5 = mem_read32(a6 + 2u);
					t2 = mem_read16(a5);
					d6 = t2;
					if ((int16_t)t2 < 0)
					{
						mem_write16(a6, 0u);
						mem_write16(a6 + 4u, 0u);
						mem_write16(a6 + 2u, 0u);
						mem_write16(a6 + 8u, 0u);
						mem_write16(a6 + 6u, 0u);
						break;
					}
					if ((d6 & 0x4000u) != 0u)
					{
						mem_write32(a6 + 2u, mem_read32(a5 + 2u));
						continue;
					}
					if ((d6 & 0x2000u) != 0u)
						mem_write8(a6, mem_read8(a6) | 0x40u);
					else if ((d6 & 0x1000u) != 0u)
						mem_write8(a6, mem_read8(a6) & 0xBFu);
					mem_write8(a6 + 1u, (uint8_t)d6);
					a4 = mem_read32(a6 + 6u);
					mem_write8(a4 + 1u, mem_read8(a5 + 2u));
					mem_write8(a4 + 3u, mem_read8(a5 + 3u));
					if ((mem_read8(a6) & 0x40u) != 0u)
						a5 -= 4u;
					else
						a5 += 4u;
					mem_write32(a6 + 2u, a5);
					break;
				}
			}
		}
		t3 = d7 - 1u;
		d7 = t3;
		a6 += 0xAu;
	} while (t3 != 0xFFFFu);
}

void unreached_0099B4(uint8_t d7)
{
	uint16_t d5 = 0, d6 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;
	uint32_t jump_target = 0;

	a6 = 0x60480u;
	d6 = 0x3Fu;
	do
	{
		a5 = indexed_table_of_32_bit_values_0099F0_ADDRESS;
		t1 = mem_read8(a6);
		d5 = t1;
		if ((int8_t)t1 < 0)
		{
			jump_target = DATA32(a5 + (uint16_t)((d5 & 3u) << 2));
			switch (jump_target)
			{
			case 0x009A00u:
				func_009A00(d7, a6);
				break;
			case 0x009A0Eu:
				func_009A0E(d7, a6);
				break;
			case 0x009A18u:
				func_009A18(d7, a6);
				break;
			case 0x009A22u:
				func_009A22(d7, a6);
				break;
			}
		}
		t2 = d6 - 1u;
		d6 = t2;
		a6 += 0xAu;
	} while (t2 != 0xFFFFu);
}

void func_009A00(uint8_t d7, uint32_t a6)
{
	if ((d7 & 1u) == 0u)
		return;
	func_009A2C(a6);
}

void func_009A0E(uint8_t d7, uint32_t a6)
{
	if ((d7 & 2u) == 0u)
		return;
	func_009A2C(a6);
}

void func_009A18(uint8_t d7, uint32_t a6)
{
	if ((d7 & 4u) == 0u)
		return;
	func_009A2C(a6);
}

void func_009A22(uint8_t d7, uint32_t a6)
{
	if ((d7 & 8u) == 0u)
		return;
	func_009A2C(a6);
}

void func_009A2C(uint32_t a6)
{
	mem_write16(a6, 0u);
	mem_write16(a6 + 4u, 0u);
	mem_write16(a6 + 2u, 0u);
	mem_write16(a6 + 8u, 0u);
	mem_write16(a6 + 6u, 0u);
}

void func_009A3A(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	a6 = 0x60480u;
	d7 = 0x40u;
	do
	{
		func_009A2C(a6);
		t1 = d7 - 1u;
		d7 = t1;
		a6 += 0xAu;
	} while (t1 != 0xFFFFu);
}

void func_009A5C(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	a6 = palettes_009A7C[unk_060003];
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
}

void unreached_009AA0(void)
{
	func_009AA8();
}

void func_009AA8(void)
{
	uint32_t a0 = 0, a6 = 0;

	a0 = palette_effects_009AD2[unk_060003];
	for (;;)
	{
		a6 = mem_read32(a0);
		a0 += 4u;
		if (a6 == 0u)
			break;
		start_palette_effects(a6);
	}
}

void func_009AFE(void)
{
	uint32_t a0 = 0;

	a0 = palette_effects_009B28[unk_060121];
	func_009B12(a0);
}

void func_009B12(uint32_t a0)
{
	uint32_t a6 = 0;

	for (;;)
	{
		a6 = mem_read32(a0);
		a0 += 4u;
		if (a6 == 0u)
			break;
		start_palette_effects(a6);
	}
}
