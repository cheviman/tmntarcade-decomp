/**
 *    Name:        video/tile_blocks.c
 *    Description: blocks of tiles drawn into the layers, and texts typed a character at a time
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* a text to type, its first character at once */
uint32_t start_typed_text_at_once(uint32_t a6)
{
	uint32_t d7 = 0;

	start_typed_text(&d7, &a6);
	typed_text_wait = 0u;
	return d7;
}

/* the typed text's next character, a new line, or its end */
void type_next_character(void)
{
	uint8_t d7 = 0;
	uint32_t a5 = 0, a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	if (typed_text == 0u)
		return;
	t1 = typed_text_wait;
	typed_text_wait = t1 - 1u;
	if (t1 != 0u)
		return;
	a6 = typed_text;
	a5 = typed_text_place;
	d7 = DATA8(a6);
	a6++;
	if (d7 == 0x21u)
	{
		typed_text_place = 0u;
		typed_text = 0u;
		typed_text_wait = 0u;
		typed_text_delay = 0u;
		unused_typed_text_flag = 0u;
		typed_text_colour = 0u;
		return;
	}
	if (d7 == 0x2Fu)
	{
		start_typed_text(&ignored, &a6);
		d7 = mem_read8(a6);
		a5 = typed_text_place;
		a6++;
	}
	io_write8(a5, typed_text_colour);
	a5++;
	io_write8(a5, d7 - 0x30u);
	typed_text = a6;
	typed_text_place = a5 + 1u;
	typed_text_wait = typed_text_delay;
}

void start_typed_text(uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t a6 = *p_a6;
	uint32_t a6_2 = 0, d7 = 0;

	typed_text_place = mem_read32(a6);
	a6 += 4u;
	typed_text_delay = mem_read8(a6);
	a6++;
	d7 = mem_read8(a6);
	typed_text = a6 + 1u;
	unused_typed_text_flag = 0u;
	if ((int8_t)d7 < 0)
	{
		d7 &= ~0x80u;
		unused_typed_text_flag = 1u;
	}
	typed_text_colour = text_colours[d7];
	a6_2 = typed_text;
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
	d7 = spawn_x >> 8;
	a6 = TILE_RAM + 0xE24u;
	draw_hex_digits(d6, d7, a6);
	d6 = 3u;
	d7 = spawn_y >> 8;
	a6 = TILE_RAM + 0xE30u;
	draw_hex_digits(d6, d7, a6);
}

/* a number drawn in hexadecimal digits */
void draw_hex_digits(uint16_t d6, uint32_t d7, uint32_t a6)
{
	uint8_t d1 = 0;
	uint16_t d0 = 0;
	uint16_t t1 = 0;

	do
	{
		d0 = d7 & 0xFu;
		d7 = d7 >> 4;
		d1 = (uint8_t)(uint16_t)(indexed_table_of_8_bit_values_0184C2[d0] - 0x30u);
		io_write8(a6, 0u);
		io_write8(a6 + 1u, d1);
		t1 = d6 - 1u;
		d6 = t1;
		a6 -= 2u;
	} while (t1 != 0xFFFFu);
}

/* a text typed eight times over, each pass in another colour and a little later */
void start_text_typed_in_colours(uint8_t d7, uint32_t a6, uint32_t extend)
{
	uint32_t carry = 0;
	uint8_t d5 = 0, d6 = 0;
	uint16_t d7_2 = 0;
	uint32_t a5 = 0, typed_pass = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	typed_pass = TYPED_PASS_ADDRESS(7);
	d5 = (uint8_t)d7;
	d7_2 = 7u;
	do
	{
		a5 = a6;
		start_typed_line(typed_pass, a6);
		a6 = a5;
		d6 = (uint8_t)d7_2;
		t1 = d5;
		t2 = m68k_shift(M68K_LSL, d6, t1, extend, 8);
		carry = m68k_shift_carry(M68K_LSL, d6, t1, extend, 8);
		extend = t1 != 0u ? carry : extend;
		TYPED_PASS(typed_pass)->wait = t2;
		t3 = d7_2 - 1u;
		d7_2 = t3;
		typed_pass -= 0xAu;
	} while (t3 != 0xFFFFu);
	typed_passes_left = 8u;
}

/* every pass of the coloured text typed on */
void type_text_in_colours(void)
{
	uint16_t d7 = 0;
	uint32_t a4 = 0;
	uint16_t t1 = 0;

	a4 = TYPED_PASS_ADDRESS(7);
	d7 = 7u;
	do
	{
		type_colour_pass(d7, a4);
		t1 = d7 - 1u;
		d7 = t1;
		a4 -= 0xAu;
	} while (t1 != 0xFFFFu);
}

/* one pass's next character in its colour */
void type_colour_pass(uint16_t d7, uint32_t a4)
{
	uint8_t d6 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint8_t wait = 0;

	if (TYPED_PASS(a4)->text == 0u)
		return;
	wait = TYPED_PASS(a4)->wait;
	TYPED_PASS(a4)->wait = wait - 1u;
	if (wait != 0u)
		return;
	a6 = TYPED_PASS(a4)->text;
	a5 = TYPED_PASS(a4)->place;
	d6 = DATA8(a6);
	a6++;
	if (d6 == 0x21u)
	{
		TYPED_PASS(a4)->place = 0u;
		TYPED_PASS(a4)->text = 0u;
		TYPED_PASS(a4)->wait = 0u;
		TYPED_PASS(a4)->delay = 0u;
		typed_passes_left--;
		return;
	}
	if (d6 == 0x2Fu)
	{
		a6 = start_typed_line(a4, a6);
		d6 = mem_read8(a6);
		a5 = TYPED_PASS(a4)->place;
		a6++;
	}
	io_write8(a5, TABLE8(text_colours, (uint32_t)(int16_t)d7));
	a5++;
	io_write8(a5, d6 - 0x30u);
	TYPED_PASS(a4)->text = a6;
	TYPED_PASS(a4)->place = a5 + 1u;
	TYPED_PASS(a4)->wait = TYPED_PASS(a4)->delay;
}

uint32_t start_typed_line(uint32_t a4, uint32_t a6)
{
	TYPED_PASS(a4)->place = mem_read32(a6);
	a6 += 4u;
	TYPED_PASS(a4)->delay = mem_read8(a6);
	a6 += 2u;
	TYPED_PASS(a4)->text = a6;
	return a6;
}

/* the screen covered, and a box to open it from the middle */
void start_box_opening(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	box_frames_left = 0x14u;
	box_width = 1u;
	box_height = 1u;
	box_tile = 0x10u;
	box_place = unexplained_01867E;
	a6 = TILE_RAM;
	d7 = 0xFFFu;
	do
	{
		io_write8(a6, 0u);
		a6++;
		io_write8(a6, 0x3Au);
		t1 = d7 - 1u;
		d7 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
}

/* the box drawn bigger every frame */
void grow_tile_box(void)
{
	uint8_t d7 = 0;
	uint16_t d5 = 0, d6 = 0;
	uint32_t a6 = 0;

	if (box_frames_left != 0u)
	{
		a6 = box_place;
		d7 = box_tile;
		d5 = box_width;
		d6 = box_height;
		draw_tile_box(d5, d6, d7, a6);
		box_frames_left--;
		box_width += 2u;
		box_place -= 2u;
		if (box_height < 0x1Du)
		{
			box_height += 2u;
			box_place -= 0x80u;
		}
	}
}

void unreached_0186E2(void)
{
	box_frames_left = 0x10u;
	box_width = 0x1Fu;
	box_height = 0x1Fu;
	box_tile = 0u;
	box_place = unexplained_018710;
}

/* the outline of a box of tiles */
void draw_tile_box(uint16_t d5, uint16_t d6, uint8_t d7, uint32_t a6)
{
	uint16_t d4 = 0;
	uint32_t a5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	d4 = (uint16_t)d5;
	a5 = a6;
	do
	{
		io_write8(a5, 0u);
		a5++;
		io_write8(a5, d7);
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
		io_write8(a6, 0u);
		io_write8(a6 + 1u, d7);
		io_write8(a6 + d4, 0u);
		io_write8(a6 + 1u + d4, d7);
		a6 += 0x80u;
	}
	do
	{
		io_write8(a6, 0u);
		a6++;
		io_write8(a6, d7);
		t3 = d5 - 1u;
		d5 = t3;
		a6++;
	} while (t3 != 0xFFFFu);
}
