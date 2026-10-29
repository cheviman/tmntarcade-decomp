/**
 *    Name:        engine/directions.c
 *    Description: the direction from one object to another
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void direction_to(uint32_t a0, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint32_t d0 = *p_d0;
	uint32_t d1 = *p_d1;
	uint32_t d2 = *p_d2;
	uint32_t carry = 0, extend = 0;
	uint8_t d3 = 0;
	uint32_t d1_2 = 0, d2_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;
	uint32_t t4 = 0;

	d0 &= ~0xFFFFu;
	t1 = d1 - mem_read16(a0 + 0xCu);
	d1_2 = (d1 & ~0xFFFFu) | t1;
	if ((int16_t)t1 < 0)
	{
		d0 = 0x40u;
		d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(0u - d1_2);
	}
	t2 = mem_read16(a0 + 0xEu);
	t3 = d2 - t2;
	carry = (uint16_t)d2 < t2;
	extend = carry;
	d2_2 = (d2 & ~0xFFFFu) | t3;
	if ((int16_t)t3 >= 0)
		d0 = d0 ^ 0xC0u;
	else
	{
		carry = (uint16_t)d2_2 > 0u;
		extend = carry;
		d2_2 = (d2_2 & ~0xFFFFu) | (uint16_t)(0u - d2_2);
	}
	d3 = 0u;
	if ((uint16_t)d2_2 <= (uint16_t)d1_2)
	{
		while ((uint16_t)d1_2 >= 0x20u)
		{
			d1_2 = (d1_2 & ~0xFFFFu) | ((uint16_t)d1_2 >> 1);
			carry = (uint8_t)(d3 + 1u) < d3;
			extend = carry;
			d3++;
		}
		d2_2 = (d2_2 & ~0xFFFFu) | m68k_shift(M68K_LSR, (uint16_t)d2_2, d3 & 0x3Fu, extend, 16);
	}
	else
	{
		while ((uint16_t)d2_2 >= 0x20u)
		{
			d2_2 = (d2_2 & ~0xFFFFu) | ((uint16_t)d2_2 >> 1);
			carry = (uint8_t)(d3 + 1u) < d3;
			extend = carry;
			d3++;
		}
		d1_2 = (d1_2 & ~0xFFFFu) | m68k_shift(M68K_LSR, (uint16_t)d1_2, d3 & 0x3Fu, extend, 16);
	}
	if ((d0 & 0x40u) != 0u)
	{
		t4 = d1_2;
		d1_2 = d2_2;
		d2_2 = t4;
	}
	d2_2 = (d2_2 & ~0xFFFFu) | (uint16_t)(d2_2 << 1);
	d0 = d0 | mem_read8(direction_table_ADDRESS + (int16_t)TABLE16(direction_rows, (uint32_t)(int16_t)d2_2) + (int16_t)d1_2);
	*p_d0 = d0;
	*p_d1 = d1_2;
	*p_d2 = d2_2;
}
