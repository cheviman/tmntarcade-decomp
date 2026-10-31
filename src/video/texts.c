/**
 *    Name:        video/texts.c
 *    Description: the texts: from the program's tables of texts into the fixed layer, big characters, numbers
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
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
	print_table_text(d7, a6);
}

void print_test_text(uint16_t d7)
{
	uint32_t a6 = 0;

	a6 = test_mode_texts_ADDRESS;
	print_table_text(d7, a6);
}

void print_game_text(uint16_t d7)
{
	uint32_t a6 = 0;

	a6 = game_texts_ADDRESS;
	print_table_text(d7, a6);
}

/* a text of a table of texts into the fixed layer, or erased */
void print_table_text(uint16_t d7, uint32_t a6)
{
	uint8_t d6 = 0, d7_2 = 0;
	uint32_t a4 = 0, a6_2 = 0;

	d7 = (uint16_t)((uint32_t)d7 << 2);
	if ((d7 & 0x200u) != 0u)
	{
		a6_2 = mem_read32(a6 + (d7 & 0x1FFu));
		d7_2 = text_colour;
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
	a6_2 = mem_read32(a6 + d7);
	d7_2 = text_colour;
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

/* the colour of the texts printed next */
void set_text_colour(uint16_t d7)
{
	text_colour = text_colours[d7];
}

/* a second texts' colour no text uses */
void set_spare_text_colour(uint16_t d7)
{
	spare_text_colour = text_colours[d7];
}

/* an enemy defeated: a point to the players' scores, the top score kept */
uint32_t add_point(uint32_t d4, uint32_t d7)
{
	uint32_t a4 = 0, d4_2 = 0;

	if (game_on == 0u)
		return d4;
	d4_2 = d7;
	if ((d4_2 & 1u) != 0u)
	{
		a4 = unk_060106_ADDRESS;
		add_point_to_score(a4);
	}
	if ((d4_2 & 2u) != 0u)
	{
		a4 = unk_06010E_ADDRESS;
		add_point_to_score(a4);
	}
	if ((d4_2 & 4u) != 0u)
	{
		a4 = unk_060116_ADDRESS;
		add_point_to_score(a4);
	}
	if ((d4_2 & 8u) != 0u)
	{
		a4 = unk_06011E_ADDRESS;
		add_point_to_score(a4);
	}
	draw_scores((uint8_t)d4_2);
	return d4_2;
}

/* a point to a player's score and the top score kept */
void add_point_to_score(uint32_t a4)
{
	uint32_t carry = 0, extend = 0;
	uint16_t d7 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	a5 = draw_score_digits_ADDRESS;
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
	a6 = top_score_ADDRESS;
	if (top_score < d7)
		top_score = d7;
}

/* the chosen players' scores drawn in their boxes */
void draw_scores(uint8_t d4)
{
	if ((d4 & 1u) != 0u)
		draw_score_player_1();
	if ((d4 & 2u) != 0u)
		draw_score_player_2();
	if ((d4 & 4u) != 0u)
		draw_score_player_3();
	if ((d4 & 8u) != 0u)
		draw_score_player_4();
}

/* the first player's score in his box */
void draw_score_player_1(void)
{
	uint32_t a4 = 0, a6 = 0;

	a6 = unk_060104_ADDRESS;
	a4 = TILE_RAM + 0x1A4u;
	draw_score_digits(a4, a6);
}

/* the second player's score in his box */
void draw_score_player_2(void)
{
	uint32_t a4 = 0, a6 = 0;

	a6 = unk_06010C_ADDRESS;
	a4 = TILE_RAM + 0x1B6u;
	draw_score_digits(a4, a6);
}

/* the third player's score in his box */
void draw_score_player_3(void)
{
	uint32_t a4 = 0, a6 = 0;

	a6 = unk_060114_ADDRESS;
	a4 = TILE_RAM + 0x1C8u;
	draw_score_digits(a4, a6);
}

/* the fourth player's score in his box */
void draw_score_player_4(void)
{
	uint32_t a4 = 0, a6 = 0;

	a6 = unk_06011C_ADDRESS;
	a4 = TILE_RAM + 0x1DAu;
	draw_score_digits(a4, a6);
}

/* the top score after HIGH */
void draw_top_score(void)
{
	uint32_t a4 = 0, a6 = 0;

	a6 = top_score_ADDRESS;
	a4 = TILE_RAM + 0x1C2u;
	draw_score_digits(a4, a6);
}

/* a score's four digits, without leading zeros */
void draw_score_digits(uint32_t a4, uint32_t a6)
{
	uint8_t d6 = 0;

	if (mem_read8(a6) >> 4 != 0u)
	{
		d6 = mem_read8(a6) >> 4;
		a4 = draw_digit(d6, a4);
		d6 = mem_read8(a6) & 0xFu;
		a4 = draw_digit(d6, a4);
		d6 = mem_read8(a6 + 1u) >> 4;
		a4 = draw_digit(d6, a4);
		d6 = mem_read8(a6 + 1u) & 0xFu;
		draw_digit(d6, a4);
		return;
	}
	a4 = draw_blank_digit(a4);
	if ((mem_read8(a6) & 0xFu) != 0u)
	{
		d6 = mem_read8(a6) & 0xFu;
		a4 = draw_digit(d6, a4);
		d6 = mem_read8(a6 + 1u) >> 4;
		a4 = draw_digit(d6, a4);
		d6 = mem_read8(a6 + 1u) & 0xFu;
		draw_digit(d6, a4);
		return;
	}
	a4 = draw_blank_digit(a4);
	if (mem_read8(a6 + 1u) >> 4 != 0u)
	{
		d6 = mem_read8(a6 + 1u) >> 4;
		a4 = draw_digit(d6, a4);
		d6 = mem_read8(a6 + 1u) & 0xFu;
		draw_digit(d6, a4);
		return;
	}
	a4 = draw_blank_digit(a4);
	d6 = mem_read8(a6 + 1u) & 0xFu;
	draw_digit(d6, a4);
}

/* a blank in place of a leading zero */
uint32_t draw_blank_digit(uint32_t a4)
{
	uint8_t d6 = 0;

	d6 = 0x10u;
	return draw_digit(d6, a4);
}

/* a digit of a score */
uint32_t draw_digit(uint8_t d6, uint32_t a4)
{
	io_write8(a4, 0u);
	a4++;
	io_write8(a4, d6);
	a4++;
	return a4;
}

/* the chosen scores to 0 */
void clear_scores(uint8_t d7)
{
	if ((d7 & 1u) != 0u)
		PLAYER(PLAYER_ADDRESS(0))->score = 0u;
	if ((d7 & 2u) != 0u)
		PLAYER(PLAYER_ADDRESS(1))->score = 0u;
	if ((d7 & 4u) != 0u)
		PLAYER(PLAYER_ADDRESS(2))->score = 0u;
	if ((d7 & 8u) != 0u)
		PLAYER(PLAYER_ADDRESS(3))->score = 0u;
	if ((d7 & 0x10u) != 0u)
		top_score = 0u;
}

/* a short text in the plain colour */
void print_plain_text(uint32_t a4, uint32_t a5)
{
	uint8_t d6 = 0;

	for (;;)
	{
		d6 = mem_read8(a5);
		a5++;
		if (d6 == 0x3Fu)
			break;
		io_write8(a4, 0u);
		a4++;
		io_write8(a4, d6 - 0x30u);
		a4++;
	}
}

/* unused: the labels 1UP to 4UP and the top score */
void draw_score_labels(uint8_t d7)
{
	uint32_t a4 = 0, a5 = 0;

	if ((d7 & 1u) == 0u)
	{
		a5 = table_loaded_by_lea_0020EC_ADDRESS;
		a4 = TILE_RAM + 0x11Cu;
		print_plain_text(a4, a5);
		a5 = 0x20F0u;
		a4 = TILE_RAM + 0x12Eu;
		print_plain_text(a4, a5);
		a5 = 0x20F4u;
		a4 = TILE_RAM + 0x140u;
		print_plain_text(a4, a5);
		a5 = 0x20F8u;
		a4 = TILE_RAM + 0x152u;
		print_plain_text(a4, a5);
		return;
	}
	if ((d7 & 2u) != 0u)
	{
		a5 = 0x20FCu;
		a4 = TILE_RAM + 0x138u;
		print_plain_text(a4, a5);
		draw_top_score();
	}
	if ((d7 & 1u) == 0u)
	{
		a5 = table_loaded_by_lea_0020EC_ADDRESS;
		a4 = TILE_RAM + 0x11Cu;
		print_plain_text(a4, a5);
		a5 = 0x20F0u;
		a4 = TILE_RAM + 0x12Eu;
		print_plain_text(a4, a5);
		return;
	}
	a5 = table_loaded_by_lea_0020EC_ADDRESS;
	a4 = TILE_RAM + 0x11Cu;
	print_plain_text(a4, a5);
	a5 = 0x20F0u;
	a4 = TILE_RAM + 0x12Eu;
	print_plain_text(a4, a5);
	a5 = 0x20F4u;
	a4 = TILE_RAM + 0x140u;
	print_plain_text(a4, a5);
	a5 = 0x20F8u;
	a4 = TILE_RAM + 0x152u;
	print_plain_text(a4, a5);
}

void unreached_00218A(void)
{
	lost_stack(0x00218Au);
}

/* a text of the test mode's and the credits' table, in its own colour */
void print_colour_text(uint16_t d7)
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

/* unused: a picture of rows of tiles */
uint32_t draw_tile_picture(uint16_t d7)
{
	uint8_t d6 = 0, d7_2 = 0;
	uint16_t d3 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0, d4 = 0;
	uint16_t t1 = 0, t2 = 0;

	a6 = indexed_table_of_32_bit_values_0031F2[d7 & 0x3FFFu];
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

/* the chosen players' boxes, and their scores */
void draw_player_boxes(uint32_t d7, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6)
{
	uint32_t d4 = *p_d4;
	uint32_t d5 = *p_d5;
	uint32_t d6 = 0;

	d6 = 0u;
	do
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) != 0u)
			draw_player_box((uint16_t)d6, (uint8_t)d7, p_d1, &d4, &d5);
		d6 = (uint8_t)(d6 + 1u);
	} while (d6 < 4u);
	if ((d7 & 0x80u) == 0u && (d7 & 0x40u) != 0u)
	{
		d4 = (uint8_t)d7;
		d4 = d4 & 0x1Fu;
		draw_scores((uint8_t)d4);
	}
	*p_d4 = d4;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d6 = d6;
}

/* a player's box: its frame and label, its lives, its health bar */
void draw_player_box(uint16_t d6, uint8_t d7, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5)
{
	uint32_t d4 = *p_d4;
	uint16_t d5 = 0;
	uint32_t a5 = 0, a6 = 0;

	a6 = 0x32C2u;
	d5 = (uint16_t)((uint32_t)d6 << 4);
	if ((d7 & 0x40u) != 0u)
	{
		a5 = DATA32(a6 + d5);
		draw_box_frame_and_label(d5, d6, d7, a5, a6, p_d1, &d4);
	}
	if ((d7 & 0x10u) != 0u)
	{
		a5 = DATA32(a6 + 8u + d5);
		d4 = draw_lives(d4, d6, d7, a5);
	}
	if ((d7 & 0x20u) != 0u)
	{
		a5 = DATA32(a6 + 0xCu + d5);
		d4 = draw_health_bar(d6, d7, a5);
	}
	*p_d4 = d4;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
}

/* a player's box frame and label in his colour */
void draw_box_frame_and_label(uint16_t d5, uint16_t d6, uint8_t d7, uint32_t a5, uint32_t a6, uint32_t *p_d1, uint32_t *p_d4)
{
	uint32_t d4 = *p_d4;
	uint32_t d0 = 0;

	d0 = player_box_colour(0u, d6);
	*p_d1 = draw_box_frame((uint8_t)d0, d7, a5);
	d4 = draw_box_label((uint8_t)d0, d4, d5, d6, d7, a6);
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
}

/* a player's lives in his box */
uint32_t draw_lives(uint32_t d4, uint16_t d6, uint8_t d7, uint32_t a5)
{
	uint16_t d3 = 0;
	uint32_t a4 = 0, d0 = 0, d4_2 = 0;

	d0 = player_box_colour(0u, d6);
	clear_lives_digits((uint8_t)d0, a5);
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

/* a player's health bar in his box */
uint32_t draw_health_bar(uint16_t d6, uint8_t d7, uint32_t a5)
{
	uint32_t a4 = 0, d0 = 0, d4 = 0;
	uint16_t t1 = 0;

	d0 = player_box_colour(0u, d6);
	d4 = clear_health_bar((uint8_t)d0, a5);
	if ((d7 & 0x80u) != 0u)
		return d4;
	a4 = 0x334Au + PLAYER(PLAYER_ADDRESS(0) + (d6 & 0x1FFFu) * 0x8u)->health_bars * 8u;
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

/* a player's colour in the boxes */
uint32_t player_box_colour(uint32_t d0, uint16_t d6)
{
	uint32_t d0_2 = 0;

	d0_2 = (d0 & ~0xFFu) | rom_001F1B[d6];
	d0_2 = d0_2 | 1u;
	return d0_2;
}

/* the lives' place in a box blank */
void clear_lives_digits(uint8_t d0, uint32_t a5)
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

/* the health bar's place in a box blank */
uint32_t clear_health_bar(uint8_t d0, uint32_t a5)
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

/* a player's box frame */
uint32_t draw_box_frame(uint8_t d0, uint8_t d7, uint32_t a5)
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

/* a player's box label 1UP to 4UP */
uint32_t draw_box_label(uint8_t d0, uint32_t d4, uint16_t d5, uint16_t d6, uint8_t d7, uint32_t a6)
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

/* unused: the stage's number and its name of the development */
void print_stage_title(void)
{
	uint8_t d6 = 0, d7 = 0;
	uint32_t a4 = 0, a6 = 0;

	a6 = rom_003402[stage];
	d7 = text_colour;
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

/* the message under a player's box */
void draw_player_message(uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d4 = *p_d4;
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d6_2 = 0;

	d6 = d7 & 3u;
	text_colour = rom_001F1B[d6];
	text_colour |= 1u;
	a6 = PLAYER_ADDRESS(0) + (uint16_t)((uint32_t)d6 << 3);
	d6_2 = (uint8_t)d7;
	d6_2 = d6_2 & 0x3Cu;
	switch (d6_2)
	{
	case 0:
		message_insert_coin((uint8_t)d7, a6, &d4, &d5, &d6_2);
		break;
	case 4:
		message_press_start((uint8_t)d7, a6, &d4, &d5, &d6_2);
		break;
	case 8:
		message_out_of_lives(a6, &d4, &d5, &d6_2, &d7);
		break;
	case 12:
		message_clear((uint8_t)d7, a6, &d4, &d5, &d6_2);
		break;
	}
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = d6_2;
	*p_d7 = (*p_d7 & 0xFFFFFF00u) | (d7 & 0xFFu);
}

/* INSERT COIN(S) in a player's box */
void message_insert_coin(uint8_t d7, uint32_t a6, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6)
{
	uint32_t d4 = 0, d5 = 0;

	if ((PLAYER(a6)->message & 1u) == 0u)
		PLAYER(a6)->message = 1u;
	*p_d6 = 0u;
	print_text_at(d7, &d4, &d5, p_d6);
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* PRESS START blinking under a player's box */
void message_press_start(uint8_t d7, uint32_t a6, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6)
{
	uint32_t d4 = *p_d4;
	uint32_t d5 = *p_d5;
	uint32_t None = *p_d6;
	uint32_t d6 = 0;
	uint8_t t1 = 0;

	if ((PLAYER(a6)->message & 2u) != 0u)
	{
		d6 = (uint8_t)frame_count;
		t1 = d6 & 0xFu;
		d6 = t1;
		if (t1 == 0u)
		{
			d6 = 2u;
			if (hide_press_start != 0u)
				d6 = 8u;
			if ((frame_count & 0x10u) != 0u)
				d6 = (uint8_t)(d6 + 1u);
			print_text_at(d7, &d4, &d5, &d6);
		}
	}
	else
	{
		PLAYER(a6)->message = 2u;
		d6 = 2u;
		if (hide_press_start != 0u)
			d6 = 8u;
		if ((frame_count & 0x10u) != 0u)
			d6 = (uint8_t)(d6 + 1u);
		print_text_at(d7, &d4, &d5, &d6);
	}
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = d6;
}

/* the knocked-out head of a player who lost his last life */
void message_out_of_lives(uint32_t a6, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d4 = *p_d4;
	uint8_t d5 = (uint8_t)*p_d5;
	uint32_t None = *p_d6;
	uint8_t d7 = (uint8_t)*p_d7;
	uint32_t d6 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	if ((PLAYER(a6)->message & 4u) != 0u)
	{
		d6 = (uint8_t)frame_count;
		t1 = d6 & 7u;
		d6 = t1;
		if (t1 == 0u)
		{
			d6 = (uint8_t)(4u + (((uint8_t)frame_count & 0x18u) >> 3));
			print_text_at(d7, &d4, &ignored, &d6);
			t2 = (uint8_t)frame_count & 0x18u;
			d5 = t2;
			if (t2 == 0u)
			{
				PLAYER(a6)->message += 0x20u;
				if ((int8_t)PLAYER(a6)->message < 0)
				{
					PLAYER(a6)->message = 0u;
					d7 &= 3u;
					players_out_of_lives &= ~shl32(1u, (int)(d7));
				}
			}
		}
	}
	else
	{
		PLAYER(a6)->message = 4u;
		d6 = (uint8_t)(4u + (((uint8_t)frame_count & 0x18u) >> 3));
		print_text_at(d7, &d4, &ignored, &d6);
		t2 = (uint8_t)frame_count & 0x18u;
		d5 = t2;
		if (t2 == 0u)
		{
			PLAYER(a6)->message += 0x20u;
			if ((int8_t)PLAYER(a6)->message < 0)
			{
				PLAYER(a6)->message = 0u;
				d7 &= 3u;
				players_out_of_lives &= ~shl32(1u, (int)(d7));
			}
		}
	}
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
	*p_d6 = d6;
	*p_d7 = (*p_d7 & 0xFFFFFF00u) | d7;
}

/* the line under a player's box cleared */
void message_clear(uint8_t d7, uint32_t a6, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6)
{
	uint16_t d4 = (uint16_t)*p_d4;
	uint8_t d5 = (uint8_t)*p_d5;
	uint32_t d4_2 = 0, d5_2 = 0;

	if ((PLAYER(a6)->message & 8u) != 0u)
		return;
	PLAYER(a6)->message = 2u;
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
	d4 = text_colour;
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

uint32_t draw_big_character(uint16_t d6, uint8_t d7)
{
	uint16_t d4 = 0, d5 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0, d7_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	a4 = big_font_place;
	a6 = big_font_tiles_ADDRESS;
	a5 = big_font_ADDRESS + (uint16_t)((d7 & 0x1Fu) * 0x24u);
	d4 = 8u;
	do
	{
		d5 = 3u;
		d7_2 = 0u;
		d7_2 = big_character_colour(d7_2);
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
	return d7_2;
}

/* the colour of a big character */
uint32_t big_character_colour(uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = text_colours[d7];
	return d7_2;
}

/* a text in tall characters: the rankings, CONTINUE, GAME OVER */
void print_tall_text(uint8_t d7, uint32_t *p_d4, uint32_t *p_d6)
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
				a4 = erase_tall_character(a4);
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
		d4_2 = tall_text_colour(d4_2);
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
			a4 = draw_tall_character((uint8_t)d4_2, (uint16_t)d6_2, a4, a5);
		}
	}
}

/* a tall character */
uint32_t draw_tall_character(uint8_t d4, uint16_t d6, uint32_t a4, uint32_t a5)
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

/* a tall character erased */
uint32_t erase_tall_character(uint32_t a4)
{
	mem_write8(a4 + 0x80u, 0u);
	mem_write8(a4 + 0x81u, 0x10u);
	mem_write8(a4, 0u);
	a4++;
	mem_write8(a4, 0x10u);
	a4++;
	return a4;
}

/* the colour of a text in tall characters */
uint32_t tall_text_colour(uint32_t d4)
{
	uint32_t d4_2 = 0;

	d4_2 = text_colours[d4];
	return d4_2;
}
