/**
 *    Name:        video/tile_blocks.c
 *    Description: blocks of tiles drawn into the layers, and texts typed a character at a time
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void func_0180E0(uint32_t a0, uint32_t a6)
{
	mem_write16(a0 + 6u, mem_read16(a6));
	mem_write32(a0 + 8u, mem_read32(a6 + 2u));
	mem_write16(a0 + 0x34u, mem_read16(a6 + 6u));
	mem_write16(a0 + 0x28u, mem_read16(a6 + 8u));
}

uint32_t func_0182EE(uint32_t a0)
{
	uint32_t d7 = 0;
	uint32_t t1 = 0, t2 = 0;

	t1 = mem_read32(a0 + 0x12u) + (int16_t)mem_read16(a0 + 0x1Au);
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	d7 = (int16_t)mem_read16(a0 + 0x1Cu);
	t2 = mem_read32(a0 + 0x16u) + d7;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
	d7 = (d7 & ~0xFFFFu) | mem_read16(a0 + 0x1Eu);
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + d7);
	return d7;
}

void func_01830C(uint32_t *p_d7, uint32_t *p_a6)
{
	uint8_t d7 = (uint8_t)*p_d7;
	uint8_t t1 = 0;

	do
	{
		if (mem_read8(*p_a6) == 0u)
			break;
		t1 = d7;
		d7 = (uint8_t)(t1 - 1u);
		*p_a6 += 0x50u;
	} while (t1 != 1u);
	*p_d7 = (*p_d7 & 0xFFFFFF00u) | d7;
}

void func_01831E(uint32_t a0)
{
	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		func_01832A(a0);
		return;
	}
}

void func_01832A(uint32_t a0)
{
	mem_write16(a0, 0u);
	mem_write16(a0 + 4u, 0u);
	mem_write16(a0 + 2u, 0u);
}

uint32_t func_018334(uint32_t a6)
{
	uint32_t d7 = 0;

	start_typed_text(&d7, &a6);
	unk_063428 = 0u;
	return d7;
}

void func_018340(void)
{
	uint8_t d7 = 0;
	uint32_t a5 = 0, a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	if (unk_063424 == 0u)
		return;
	t1 = unk_063428;
	unk_063428 = t1 - 1u;
	if (t1 != 0u)
		return;
	a6 = unk_063424;
	a5 = unk_063420;
	d7 = mem_read8(a6);
	a6++;
	if (d7 != 0x21u)
	{
		if (d7 == 0x2Fu)
		{
			start_typed_text(&ignored, &a6);
			d7 = mem_read8(a6);
			a5 = unk_063420;
			a6++;
		}
		mem_write8(a5, unk_06342B);
		a5++;
		mem_write8(a5, d7 - 0x30u);
		unk_063424 = a6;
		unk_063420 = a5 + 1u;
		unk_063428 = unk_063429;
		return;
	}
	unk_063420 &= 0xFFFF0000u;
	unk_063420 &= 0xFFFFu;
	unk_063424 &= 0xFFFF0000u;
	unk_063424 &= 0xFFFFu;
	unk_06342A = 0u;
	unk_06342B = 0u;
	unk_063428 = 0u;
	unk_063429 = 0u;
}

void start_typed_text(uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t a6 = *p_a6;
	uint32_t a6_2 = 0, d7 = 0;

	unk_063420 = mem_read32(a6);
	a6 += 4u;
	unk_063429 = mem_read8(a6);
	a6++;
	d7 = mem_read8(a6);
	unk_063424 = a6 + 1u;
	unk_06342A = 0u;
	if ((int8_t)d7 < 0)
	{
		d7 &= ~0x80u;
		unk_06342A = 1u;
	}
	unk_06342B = text_colours[d7];
	a6_2 = unk_063424;
	*p_d7 = d7;
	*p_a6 = a6_2;
}

void draw_tile_block(uint16_t d7, uint32_t a6)
{
	uint16_t d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7_3 = 0;
	uint32_t a4 = 0, a5 = 0, d7_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	d7_2 = TABLE32(tile_block_places, (uint32_t)(int16_t)((uint32_t)d7 << 2));
	d4 = (uint16_t)d7_2;
	d7_2 &= ~0x7Fu;
	d4 -= d7_2;
	a5 = d7_2;
	d7_3 = mem_read8(a6);
	a6++;
	d6 = mem_read8(a6);
	a6++;
	do
	{
		a4 = a5;
		d5 = (uint16_t)d7_3;
		d3 = (uint16_t)d4;
		do
		{
			mem_write8(a4 + (int16_t)d3, mem_read8(a6));
			a6++;
			mem_write8(a4 + 1u + (int16_t)d3, mem_read8(a6));
			d3 = (d3 + 2u) & 0x7Fu;
			t1 = d5 - 1u;
			d5 = t1;
			a6++;
		} while (t1 != 0xFFFFu);
		a5 = ((a5 + 0x80u) & 0xFFFu) | (a5 & ~0xFFFu);
		t2 = d6 - 1u;
		d6 = t2;
	} while (t2 != 0xFFFFu);
}

void unreached_01845E(void)
{
	uint16_t d6 = 0;
	uint32_t a6 = 0, d7 = 0;

	d6 = 3u;
	d7 = unk_061218 >> 8;
	a6 = TILE_RAM + 0xE24u;
	func_01848C(d6, d7, a6);
	d6 = 3u;
	d7 = unk_06121C >> 8;
	a6 = TILE_RAM + 0xE30u;
	func_01848C(d6, d7, a6);
}

void func_01848C(uint16_t d6, uint32_t d7, uint32_t a6)
{
	uint8_t d1 = 0;
	uint16_t d0 = 0;
	uint16_t t1 = 0;

	do
	{
		d0 = d7 & 0xFu;
		d7 = d7 >> 4;
		d1 = (uint8_t)(uint16_t)(indexed_table_of_8_bit_values_0184C2[d0] - 0x30u);
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, d1);
		t1 = d6 - 1u;
		d6 = t1;
		a6 -= 2u;
	} while (t1 != 0xFFFFu);
}

void func_0184D2(uint32_t a0, uint32_t *p_d0, uint32_t *p_a5)
{
	uint32_t overflow = 0;
	uint16_t d1 = 0, d2 = 0, d3 = 0;
	uint32_t a5 = 0, a6 = 0, d0 = 0;
	uint16_t t1 = 0, t2 = 0;

	a5 = mem_read32(a0 + 0x20u);
	d2 = 0u;
	a6 = indexed_table_of_8_bit_values_018550_ADDRESS;
	t1 = mem_read16(a5 + 0xCu) - mem_read16(a0 + 0xCu);
	d0 = t1;
	if ((int16_t)t1 < 0)
	{
		d2 = (uint8_t)(d2 + 1u);
		d0 = (uint16_t)~d0;
		d0 = (d0 & ~0xFFu) | (uint8_t)(d0 + 1u);
	}
	t2 = mem_read16(a5 + 0xEu) - mem_read16(a0 + 0xEu);
	d1 = t2;
	if ((int16_t)t2 < 0)
	{
		d2 = (uint8_t)(d2 + 2u);
		d1 = (uint16_t)~d1;
		d1 = (uint16_t)((d1 & ~0xFFu) | (uint8_t)(d1 + 1u));
	}
	if (d0 == 0u)
		d0 = DATA8(a6 + d2);
	else if (d1 == 0u)
		d0 = DATA8(a6 + 3u + d2);
	else
	{
		d3 = 0u;
		d0 = d0 * 0x3E8u;
		overflow = m68k_divu_ov(d0, d1);
		d0 = d1 == 0u ? d0 : m68k_divu(d0, d1);
		if (d1 == 0u)
			func_00193E();
		if (overflow == 0u)
		{
			while ((uint16_t)d0 < mem_read16(a6 + 6u + (int16_t)d3))
			{
				d3 += 2u;
			}
		}
		d0 = rom_018560[d2 * 5u + (d3 >> 1)];
	}
	*p_d0 = d0;
	*p_a5 = a5;
}

void func_018574(uint32_t a0, uint32_t a6)
{
	mem_write32(a6 + 0x12u, mem_read32(a0 + 0x12u));
	mem_write32(a6 + 0x16u, mem_read32(a0 + 0x16u));
	mem_write16(a6 + 0x10u, mem_read16(a0 + 0x10u));
}

void func_018588(uint8_t d7, uint32_t a6, uint32_t extend)
{
	uint32_t carry = 0;
	uint8_t d5 = 0, d6 = 0;
	uint16_t d7_2 = 0;
	uint32_t a4 = 0, a5 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	a4 = 0x63476u;
	d5 = (uint8_t)d7;
	d7_2 = 7u;
	do
	{
		a5 = a6;
		start_typed_line(a4, a6);
		a6 = a5;
		d6 = (uint8_t)d7_2;
		t1 = d5;
		t2 = m68k_shift(M68K_LSL, d6, t1, extend, 8);
		carry = m68k_shift_carry(M68K_LSL, d6, t1, extend, 8);
		extend = t1 != 0u ? carry : extend;
		mem_write8(a4 + 8u, t2);
		t3 = d7_2 - 1u;
		d7_2 = t3;
		a4 -= 0xAu;
	} while (t3 != 0xFFFFu);
	unk_06342F = 8u;
}

void func_0185B6(void)
{
	uint16_t d7 = 0;
	uint32_t a4 = 0;
	uint16_t t1 = 0;

	a4 = 0x63476u;
	d7 = 7u;
	do
	{
		func_0185D2(d7, a4);
		t1 = d7 - 1u;
		d7 = t1;
		a4 -= 0xAu;
	} while (t1 != 0xFFFFu);
}

void func_0185D2(uint16_t d7, uint32_t a4)
{
	uint8_t d6 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint8_t t1 = 0;

	if (mem_read32(a4 + 4u) == 0u)
		return;
	t1 = mem_read8(a4 + 8u);
	mem_write8(a4 + 8u, t1 - 1u);
	if (t1 != 0u)
		return;
	a6 = mem_read32(a4 + 4u);
	a5 = mem_read32(a4);
	d6 = mem_read8(a6);
	a6++;
	if (d6 != 0x21u)
	{
		if (d6 == 0x2Fu)
		{
			a6 = start_typed_line(a4, a6);
			d6 = mem_read8(a6);
			a5 = mem_read32(a4);
			a6++;
		}
		mem_write8(a5, TABLE8(text_colours, (uint32_t)(int16_t)d7));
		a5++;
		mem_write8(a5, d6 - 0x30u);
		mem_write32(a4 + 4u, a6);
		mem_write32(a4, a5 + 1u);
		mem_write8(a4 + 8u, mem_read8(a4 + 9u));
		return;
	}
	mem_write16(a4 + 2u, 0u);
	mem_write16(a4, 0u);
	mem_write16(a4 + 6u, 0u);
	mem_write16(a4 + 4u, 0u);
	mem_write16(a4 + 8u, 0u);
	unk_06342F--;
}

uint32_t start_typed_line(uint32_t a4, uint32_t a6)
{
	mem_write32(a4, mem_read32(a6));
	a6 += 4u;
	mem_write8(a4 + 9u, mem_read8(a6));
	a6 += 2u;
	mem_write32(a4 + 4u, a6);
	return a6;
}

void func_01864E(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	unk_063497 = 0x14u;
	unk_063494 = 1u;
	unk_063495 = 1u;
	unk_063496 = 0x10u;
	unk_063490 = unexplained_01867E;
	a6 = TILE_RAM;
	d7 = 0xFFFu;
	do
	{
		mem_write8(a6, 0u);
		a6++;
		mem_write8(a6, 0x3Au);
		t1 = d7 - 1u;
		d7 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
}

void func_018682(void)
{
	uint8_t d7 = 0;
	uint16_t d5 = 0, d6 = 0;
	uint32_t a6 = 0;
	uint32_t t1 = 0, t2 = 0;

	if (unk_063497 != 0u)
	{
		a6 = unk_063490;
		d7 = unk_063496;
		d5 = unk_063494;
		d6 = unk_063495;
		func_018776(d5, d6, d7, a6);
		unk_063497--;
		unk_063494 += 2u;
		t1 = unk_063490 - 2u;
		unk_063490 = (unk_063490 & 0xFFFF0000u) | (t1 & 0xFFFFu);
		unk_063490 = (unk_063490 & 0xFFFFu) | ((t1 >> 16 & 0xFFFFu) << 16u);
		if (unk_063495 < 0x1Du)
		{
			unk_063495 += 2u;
			t2 = unk_063490 - 0x80u;
			unk_063490 = (unk_063490 & 0xFFFF0000u) | (t2 & 0xFFFFu);
			unk_063490 = (unk_063490 & 0xFFFFu) | ((t2 >> 16 & 0xFFFFu) << 16u);
		}
	}
}

void unreached_0186E2(void)
{
	unk_063497 = 0x10u;
	unk_063494 = 0x1Fu;
	unk_063495 = 0x1Fu;
	unk_063496 = 0u;
	unk_063490 = unexplained_018710;
}

void func_018776(uint16_t d5, uint16_t d6, uint8_t d7, uint32_t a6)
{
	uint16_t d4 = 0;
	uint32_t a5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	d4 = (uint16_t)d5;
	a5 = a6;
	do
	{
		mem_write8(a5, 0u);
		a5++;
		mem_write8(a5, d7);
		t1 = d4 - 1u;
		d4 = t1;
		a5++;
	} while (t1 != 0xFFFFu);
	d4 = (uint16_t)((uint32_t)d5 << 1);
	d6 = (uint8_t)(d6 - 1u);
	a6 += 0x80u;
	for (;;)
	{
		t2 = d6 - 1u;
		d6 = t2;
		if (t2 == 0xFFFFu)
			break;
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, d7);
		mem_write8(a6 + d4, 0u);
		mem_write8(a6 + 1u + d4, d7);
		a6 += 0x80u;
	}
	do
	{
		mem_write8(a6, 0u);
		a6++;
		mem_write8(a6, d7);
		t3 = d5 - 1u;
		d5 = t3;
		a6++;
	} while (t3 != 0xFFFFu);
}
