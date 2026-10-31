/**
 *    Name:        system/palette_editor.c
 *    Description: an unused colour editor for the palette RAM, worked with the first player's joystick
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Unused: a colour editor for the palette, run a step at a time */
void palette_editor(void)
{
	switch (palette_editor_step)
	{
	case 0:
		palette_editor_start();
		break;
	case 1:
		palette_editor_frame();
		break;
	}
}

/* Unused: the colour editor's page, its numbers cleared */
void palette_editor_start(void)
{
	uint32_t a5 = 0;

	a5 = table_loaded_by_lea_009C5C_ADDRESS;
	queue_jobs(a5);
	palette_editor_numbers(0) = 0u;
	palette_editor_numbers(1) = 0u;
	palette_editor_numbers(2) = 0u;
	palette_editor_numbers(3) = 0u;
	AT32(palette_editor_pick, -3) = 0u;
	palette_editor_last_pick = 1u;
	palette_editor_step++;
}

/* Unused: the joystick picks one of the colour editor's numbers and changes it */
void palette_editor_frame(void)
{
	uint8_t d0 = 0, d6 = 0;
	uint16_t d1 = 0, d2 = 0, d3 = 0, d7 = 0;
	uint32_t a0 = 0, a4 = 0, a6 = 0;
	uint8_t t1 = 0, t4 = 0;
	uint32_t t2 = 0, t3 = 0;

	if ((frame_count & 3u) != 0u)
		return;
	a0 = palette_editor_numbers_ADDRESS;
	palette_editor_draw(a0);
	palette_editor_show_colour(a0);
	palette_editor_last_pick = palette_editor_pick;
	mem_write8(6u, io_read8(IO_0A0003));
	mem_write8(6u, ~mem_read8(6u));
	d0 = mem_read8(6u) & 0xFu;
	if ((d0 & 2u) == 0u)
	{
		if ((d0 & 1u) != 0u)
		{
			t1 = palette_editor_pick;
			palette_editor_pick = t1 - 1u;
			if (t1 == 0u)
				palette_editor_pick = 5u;
		}
	}
	else
	{
		palette_editor_pick++;
		if (palette_editor_pick >= 6u)
			palette_editor_pick = 0u;
	}
	if (palette_editor_pick >= 3u)
	{
		d7 = palette_editor_pick;
		palette_editor_part = rom_009F16[(uint8_t)(d7 - 3u)];
		a6 = palette_editor_entry(a0);
		d1 = (uint16_t)((uint32_t)mem_read8(a6 + 1u) << 8);
		d1 |= (uint8_t)(d1 + mem_read8(a6 + 3u));
		a4 = 0x9F0Au;
		d2 = palette_editor_part;
		d2 = (uint8_t)((uint32_t)d2 << 2);
		d3 = (uint16_t)d1;
		if ((d0 & 4u) != 0u)
			d3 += DATA16(a4 + 2u + d2);
		if ((d0 & 8u) != 0u)
			d3 -= DATA16(a4 + 2u + d2);
		d1 = (uint16_t)((d1 & ~DATA16(a4 + d2)) + (d3 & DATA16(a4 + d2)));
		mem_write8(a6 + 3u, (uint8_t)d1);
		io_write8(PALETTE_08000F, (uint8_t)d1);
		d1 = d1 >> 8;
		mem_write8(a6 + 1u, (uint8_t)d1);
		io_write8(PALETTE_08000D, (uint8_t)d1);
		return;
	}
	a6 = indexed_table_of_8_bit_values_009D40_ADDRESS;
	d7 = palette_editor_pick;
	if (palette_editor_numbers(1) != 3u)
	{
		d7 = (uint8_t)(d7 + 3u);
		if (palette_editor_numbers(2) >= 8u)
			palette_editor_numbers(2) = 7u;
	}
	d6 = DATA8(a6 + d7);
	d7 = palette_editor_pick;
	d7 = (uint8_t)(d7 + 1u);
	if ((d0 & 8u) == 0u)
	{
		if ((d0 & 4u) != 0u)
		{
			t2 = a0 + d7;
			mem_write8(t2, mem_read8(t2) + 1u);
			if (d6 < palette_editor_numbers(d7))
				palette_editor_numbers(d7) = 0u;
		}
	}
	else
	{
		t3 = a0 + d7;
		t4 = mem_read8(t3);
		mem_write8(t3, t4 - 1u);
		if (t4 == 0u)
			palette_editor_numbers(d7) = d6;
	}
}

/* Unused: the colour picked is shown */
void palette_editor_show_colour(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = palette_editor_entry(a0);
	io_write8(PALETTE_08000D, mem_read8(a6 + 1u));
	io_write8(PALETTE_08000F, mem_read8(a6 + 3u));
}

/* Unused: the colour editor's numbers drawn, the one picked in another colour */
void palette_editor_draw(uint32_t a0)
{
	uint8_t d3 = 0;
	uint16_t d1 = 0, d7 = 0;
	uint32_t a6 = 0;

	a6 = rom_009F1A;
	d7 = palette_editor_numbers(1);
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, rom_009F1E[d7]);
	a6 = rom_009F22;
	d7 = palette_editor_numbers(2);
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, rom_009F46[d7]);
	a6 = rom_009F26;
	d7 = palette_editor_numbers(3);
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, rom_009F46[d7]);
	a6 = rom_009F2A;
	d1 = (uint16_t)((uint32_t)io_read8(PALETTE_08000D) << 8);
	d1 |= (uint8_t)(d1 + io_read8(PALETTE_08000F));
	d3 = (uint8_t)d1;
	palette_editor_draw_part(d3, a6);
	d1 = d1 >> 5;
	d3 = (uint8_t)d1;
	a6 += 6u;
	palette_editor_draw_part(d3, a6);
	d3 = (uint8_t)(d1 >> 5);
	a6 += 6u;
	palette_editor_draw_part(d3, a6);
	d7 = palette_editor_pick;
	if (d7 != palette_editor_last_pick)
	{
		a6 = rom_009F2E[d7 & 0x3FFFu];
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, 0x1Fu);
		a6 = rom_009F2E[palette_editor_last_pick];
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, 0x10u);
	}
}

/* Unused: a part of a colour drawn as two digits */
void palette_editor_draw_part(uint8_t d3, uint32_t a6)
{
	uint8_t d2 = 0, d3_2 = 0;

	d2 = 0u;
	d3 &= 0x1Fu;
	if ((d3 & 0x10u) != 0u)
		d2++;
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, d2);
	d3_2 = rom_009F46[d3 & 0xFu];
	mem_write8(a6 + 2u, 0u);
	mem_write8(a6 + 3u, d3_2);
}

/* Unused: the palette entry the colour editor's numbers pick */
uint32_t palette_editor_entry(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_009EFA[palette_editor_numbers(1)] + (uint16_t)((uint32_t)palette_editor_numbers(2) << 6) + (uint16_t)((uint32_t)palette_editor_numbers(3) << 2);
	return a6;
}
