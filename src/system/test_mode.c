/**
 *    Name:        system/test_mode.c
 *    Description: the exceptions' handler and the test mode's pages: the RAM and ROM check, the mask ROM check, the inputs, the sounds, the DIP switches
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* an exception: the program stops until the watchdog resets the board */
void exception_hang(void)
{
	for (;;)
	{
	}
}

/* the test mode's mask ROM check */
void mask_rom_check_page(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		mask_rom_check_clear();
		return;
	case 1:
		draw_mask_rom_check();
		return;
	case 2:
		start_mask_rom_sums();
		return;
	case 3:
		show_mask_rom_check();
		return;
	case 4:
		mask_rom_check_wait();
		return;
	}
}

/* the layers cleared for the mask ROM check */
void mask_rom_check_clear(void)
{
	uint16_t d7 = 0;

	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	scene_step++;
}

/* the mask ROM check's heading and palette */
void draw_mask_rom_check(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (jobs_pending == 0u)
	{
		d7 = 8u;
		print_colour_text(d7);
		a6 = 0xA07Eu;
		d7 = 0x20Fu;
		post_palette_request(d7, a6);
		scene_step++;
	}
}

/* the mask ROMs' sums started */
void start_mask_rom_sums(void)
{
	uint16_t d1 = 0, d7 = 0;
	uint32_t a0 = 0, d0 = 0;
	uint16_t t1 = 0;

	if (palettes_busy != 0u)
		return;
	d0 = 0u;
	d1 = 5u;
	a0 = ranking_scores_ADDRESS;
	do
	{
		mem_write32(a0, d0);
		t1 = d1 - 1u;
		d1 = t1;
		a0 += 4u;
	} while (t1 != 0xFFFFu);
	jobs_pending++;
	d7 = 0x1100u;
	queue_job(d7);
	scene_step++;
}

/* each mask ROM's sum shown OK or BAD */
void show_mask_rom_check(void)
{
	uint16_t d1 = 0, d2 = 0, d4 = 0, d7 = 0;
	uint32_t a0 = 0, a6 = 0, d0 = 0;
	uint16_t t2 = 0, t3 = 0;
	uint32_t t1 = 0;

	if (jobs_pending != 0u)
		return;
	scene_step++;
	scene_timer = 0x80u;
	a0 = table_loaded_by_lea_001E34_ADDRESS;
	a6 = ranking_scores_ADDRESS;
	d0 = 0u;
	d4 = 5u;
	do
	{
		d0 = d0 << 1;
		d7 = DATA16(a0);
		t1 = a6;
		a6 += 2u;
		a0 += 2u;
		if (d7 != mem_read16(t1))
			d0 |= 1u;
		t2 = d4 - 1u;
		d4 = t2;
	} while (t2 != 0xFFFFu);
	if (d0 == 0u)
	{
		d7 = 9u;
		print_colour_text(d7);
		return;
	}
	scene_timer = 0u;
	d7 = 0xAu;
	print_colour_text(d7);
	d2 = 5u;
	d1 = 0xBu;
	do
	{
		if ((d0 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
		{
			d7 = (uint16_t)d1;
			print_colour_text(d7);
		}
		d1++;
		t3 = d2 - 1u;
		d2 = t3;
	} while (t3 != 0xFFFFu);
}

/* the results shown a while, then the next page */
void mask_rom_check_wait(void)
{
	uint8_t t1 = 0;

	if (scene_timer != 0u)
	{
		t1 = scene_timer;
		scene_timer = t1 - 1u;
		if (t1 == 1u)
		{
			scene++;
			scene_step = 0u;
		}
	}
	test_page_controls();
}

/* the graphics ROMs summed through the video chips */
uint32_t sum_mask_roms(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7)
{
	uint32_t a0 = 0;

	a0 = ranking_scores_ADDRESS;
	d7 = sum_sprite_roms_low(d4, d5, d6, d7, a0);
	d7 = sum_sprite_roms_high(d4, d5, d6, d7, a0);
	d5 = sum_tile_roms(d4, d5, d6, d7, a0);
	jobs_pending--;
	return d5;
}

/* the sprite ROMs' first half summed */
uint32_t sum_sprite_roms_low(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	mask_rom_part_sums(0) = 0u;
	mask_rom_part_sums(1) = 0u;
	mask_rom_part_sums(2) = 0u;
	mask_rom_part_sums(3) = 0u;
	mask_rom_first_bank = 0u;
	mask_rom_last_bank = 3u;
	sum_sprite_rom_banks(d4, d5, d6, d7);
	d7_2 = mask_rom_part_sums(0);
	d7_2 = (uint16_t)(d7_2 + ranking_scores(9));
	ranking_scores(0) = d7_2;
	d7_2 = ranking_scores(10);
	d7_2 = (uint16_t)(d7_2 + ranking_scores(11));
	ranking_scores(1) = d7_2;
	return d7_2;
}

/* the sprite ROMs' second half summed */
uint32_t sum_sprite_roms_high(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	mask_rom_part_sums(0) = 0u;
	mask_rom_part_sums(1) = 0u;
	mask_rom_part_sums(2) = 0u;
	mask_rom_part_sums(3) = 0u;
	mask_rom_first_bank = 0x40u;
	mask_rom_last_bank = 0x43u;
	sum_sprite_rom_banks(d4, d5, d6, d7);
	d7_2 = (d7 & ~0xFFFFu) | mask_rom_part_sums(0);
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 + ranking_scores(9));
	ranking_scores(2) = d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | ranking_scores(10);
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 + ranking_scores(11));
	ranking_scores(3) = d7_2;
	return d7_2;
}

/* the sprite ROMs' banks read through the sprite chip and summed */
void sum_sprite_rom_banks(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7)
{
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a1 = 0, a2 = 0, d7_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	sprite_control |= 0x20u;
	io_write8(0x140000u, sprite_control);
	mask_rom_bank = mask_rom_first_bank;
	mask_rom_part_sums(0) = 0u;
	mask_rom_part_sums(1) = 0u;
	mask_rom_part_sums(2) = 0u;
	mask_rom_part_sums(3) = 0u;
	do
	{
		d0 = 0u;
		d7_2 = (d7 & ~0xFFu) | mask_rom_bank;
		io_write8(SPRITE_CONTROL_140003, d7_2);
		do
		{
			a1 = SPRITE_RAM;
			d1 = 0u;
			io_write8(SPRITE_CONTROL_140002, d0);
			do
			{
				a2 = a1 + (int16_t)d1;
				(void)mem_read8(a2);
				(void)mem_read8(a2);
				t1 = io_read8(SPRITE_CONTROL_140004);
				t2 = io_read8(SPRITE_CONTROL_140004);
				d4 = (d4 & ~0xFFu) | t2;
				t3 = io_read8(SPRITE_CONTROL_140005);
				t4 = io_read8(SPRITE_CONTROL_140005);
				d5 = (d5 & ~0xFFu) | t4;
				t5 = io_read8(SPRITE_CONTROL_140006);
				t6 = io_read8(SPRITE_CONTROL_140006);
				d6 = (d6 & ~0xFFu) | t6;
				t7 = io_read8(SPRITE_CONTROL_140007);
				t8 = io_read8(SPRITE_CONTROL_140007);
				d7_2 = (d7_2 & ~0xFFu) | t8;
				add_to_rom_sums(d4, d5, d6, d7_2);
				d1 += 4u;
			} while (d1 < 0x400u);
			carry = (uint8_t)(d0 + 1u) < d0;
			d0++;
		} while (carry == 0u);
		mask_rom_bank++;
		d7 = (d7_2 & ~0xFFu) | mask_rom_last_bank;
	} while (mask_rom_bank <= (uint8_t)d7);
	sprite_control &= 0xDFu;
	io_write8(0x140000u, sprite_control);
}

/* the tile ROMs read through the tile chip and summed */
uint32_t sum_tile_roms(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7, uint32_t a0)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a1 = 0, a2 = 0, d7_2 = 0;
	uint16_t t1 = 0;

	mask_rom_bank = 0u;
	mask_rom_part_sums(0) = 0u;
	mask_rom_part_sums(1) = 0u;
	mask_rom_part_sums(2) = 0u;
	mask_rom_part_sums(3) = 0u;
	do
	{
		d0 = 0u;
		d7 = (d7 & ~0xFFu) | mask_rom_bank;
		tile_banks_0_1 = d7;
		io_write8(TILES_106B00, tile_banks_0_1);
		tile_banks_2_3 = d7;
		io_write8(TILES_106E00, tile_banks_2_3);
		do
		{
			a1 = 0x100000u;
			d1 = 0u;
			io_write8(TILES_106C00, d0);
			io_write8(TILES_106C00, d0);
			io_write8(TILES_106C00, d0);
			board_control |= 0x80u;
			io_write8(IO_0A0001, board_control);
			for (;;)
			{
				a2 = a1 + (int16_t)d1;
				do
				{
					d4 = (d4 & ~0xFFu) | mem_read8(a2);
				} while ((uint8_t)d4 != mem_read8(a2));
				do
				{
					d5 = (d5 & ~0xFFu) | mem_read8(a2 + 2u);
				} while ((uint8_t)d5 != mem_read8(a2 + 2u));
				do
				{
					d6 = (d6 & ~0xFFu) | mem_read8(a2 + 4u);
				} while ((uint8_t)d6 != mem_read8(a2 + 4u));
				do
				{
					d7 = (d7 & ~0xFFu) | mem_read8(a2 + 6u);
				} while ((uint8_t)d7 != mem_read8(a2 + 6u));
				add_to_rom_sums(d4, d5, d6, d7);
				d1 += 8u;
				if (d1 >= 0x7000u)
					break;
				d7_2 = (d7 & ~0xFFFFu) | d1;
				t1 = d7_2 & 0x1000u;
				d7 = (d7_2 & ~0xFFFFu) | t1;
				if (t1 == 0u)
					continue;
				d1 += 0x1000u;
			}
			board_control &= 0x7Fu;
			io_write8(IO_0A0001, board_control);
			d0++;
		} while (d0 < 0x20u);
		mask_rom_bank += 0x44u;
	} while (mask_rom_bank != 0x10u);
	ranking_scores(4) = mask_rom_part_sums(0) + ranking_scores(9);
	ranking_scores(5) = ranking_scores(10) + ranking_scores(11);
	io_write8(TILES_106B00, 0u);
	tile_banks_0_1 = 0u;
	io_write8(TILES_106E00, 0u);
	tile_banks_2_3 = 0u;
	return d5;
}

/* four bytes of a graphics ROM added to its sums */
void add_to_rom_sums(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7)
{
	uint8_t d3 = 0;
	uint16_t d2 = 0;
	uint32_t a6 = 0;

	d2 = 0u;
	a6 = mask_rom_part_sums_ADDRESS;
	do
	{
		mask_rom_bits = 0u;
		d3 = (uint8_t)(uint16_t)(d2 + 1u);
		if ((d4 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			mask_rom_bits |= 1u;
		if ((d5 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			mask_rom_bits |= 2u;
		if ((d6 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			mask_rom_bits |= 4u;
		if ((d7 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			mask_rom_bits |= 8u;
		if ((d4 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			mask_rom_bits |= 0x10u;
		if ((d5 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			mask_rom_bits |= 0x20u;
		if ((d6 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			mask_rom_bits |= 0x40u;
		if ((d7 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			mask_rom_bits |= 0x80u;
		mem_write16(a6, mem_read16(a6) + mask_rom_bits);
		d2 += 2u;
		a6 += 2u;
	} while (d2 < 8u);
}

void unreached_001D9E(uint32_t d4, uint32_t d5, uint32_t d6, uint32_t d7)
{
	uint8_t d3 = 0;
	uint16_t d2 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	d2 = 3u;
	a6 = mask_rom_part_sums_ADDRESS;
	do
	{
		mask_rom_bits = 0u;
		d2 = (uint16_t)((uint32_t)d2 << 1);
		d3 = (uint8_t)(uint16_t)(d2 + 1u);
		if ((d7 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			mask_rom_bits |= 1u;
		if ((d6 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			mask_rom_bits |= 2u;
		if ((d5 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			mask_rom_bits |= 4u;
		if ((d4 & shl32(1u, (int)(d2 & 0x1Fu))) != 0u)
			mask_rom_bits |= 8u;
		if ((d7 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			mask_rom_bits |= 0x10u;
		if ((d6 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			mask_rom_bits |= 0x20u;
		if ((d5 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			mask_rom_bits |= 0x40u;
		if ((d4 & shl32(1u, (int)(d3 & 0x1Fu))) != 0u)
			mask_rom_bits |= 0x80u;
		mem_write16(a6, mem_read16(a6) + mask_rom_bits);
		t1 = (d2 >> 1) - 1u;
		d2 = t1;
		a6 += 2u;
	} while (t1 != 0xFFFFu);
}

void func_001E40(void)
{
}

/* the tile layers chosen cleared */
void clear_layers_job(uint8_t d7)
{
	uint32_t a6 = 0, d1 = 0, d2 = 0;

	blank_tile(&d1, &d2);
	if ((d7 & 1u) != 0u)
	{
		a6 = 0x100000u;
		clear_fixed_layer((uint8_t)d1, (uint8_t)d2, a6);
	}
	if ((d7 & 2u) != 0u)
	{
		a6 = TILE_RAM + 0x2000u;
		clear_scroll_layer((uint8_t)d1, (uint8_t)d2, a6);
	}
	if ((d7 & 4u) != 0u)
	{
		a6 = TILE_RAM + 0x4000u;
		clear_scroll_layer((uint8_t)d1, (uint8_t)d2, a6);
	}
	jobs_pending--;
}

/* the blank tile and its colour */
void blank_tile(uint32_t *p_d1, uint32_t *p_d2)
{
	*p_d1 = 0u;
	*p_d2 = 0x10u;
}

/* the fixed layer blank */
void clear_fixed_layer(uint8_t d1, uint8_t d2, uint32_t a6)
{
	uint16_t d0 = 0;
	uint16_t t1 = 0;

	d0 = 0x7FFu;
	do
	{
		io_write8(a6, d1);
		a6++;
		io_write8(a6, d2);
		t1 = d0 - 1u;
		d0 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
}

/* a scrolling layer blank */
void clear_scroll_layer(uint8_t d1, uint8_t d2, uint32_t a6)
{
	uint16_t d0 = 0;
	uint16_t t1 = 0;

	d0 = 0xFFFu;
	do
	{
		io_write8(a6, d1);
		a6++;
		io_write8(a6, d2);
		t1 = d0 - 1u;
		d0 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
}

/* the test mode's start */
void test_mode_start(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		test_start_clear();
		return;
	case 1:
		test_start_palette();
		return;
	case 2:
		test_start_next();
		return;
	}
}

/* the layers cleared */
void test_start_clear(void)
{
	uint16_t d7 = 0;

	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	scene_step++;
}

/* the test mode's palette */
void test_start_palette(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (jobs_pending == 0u)
	{
		a6 = 0xA07Eu;
		d7 = 0x20Fu;
		post_palette_request(d7, a6);
		scene_step++;
	}
}

/* on to the mask ROM check */
void test_start_next(void)
{
	if (palettes_busy == 0u)
	{
		scene++;
		scene_step = 0u;
	}
}

/* the test mode's cross hatch */
void cross_hatch_page(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		draw_cross_hatch();
		return;
	case 1:
		test_page_controls();
		return;
	}
}

/* the cross hatch drawn */
void draw_cross_hatch(void)
{
	uint8_t d0 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0, t2 = 0;

	a6 = TILE_RAM;
	d0 = 0u;
	d1 = 0x2Cu;
	d2 = 0x2Du;
	d3 = 0x2Eu;
	d4 = 0x2Fu;
	d6 = 0xFu;
	do
	{
		d7 = 0x1Fu;
		do
		{
			io_write8(a6 + 0x80u, d0);
			io_write8(a6 + 0x81u, d1);
			io_write8(a6 + 0x82u, d0);
			io_write8(a6 + 0x83u, d2);
			io_write8(a6, d0);
			a6++;
			io_write8(a6, d3);
			a6++;
			io_write8(a6, d0);
			a6++;
			io_write8(a6, d4);
			t1 = d7 - 1u;
			d7 = t1;
			a6++;
		} while (t1 != 0xFFFFu);
		t2 = d6 - 1u;
		d6 = t2;
		a6 += 0x80u;
	} while (t2 != 0xFFFFu);
	scene_step++;
}

/* the test mode's colour test */
void color_test_page(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		color_test_clear();
		return;
	case 1:
		draw_color_test();
		return;
	case 2:
		test_page_controls();
		return;
	}
}

/* the layers cleared */
void color_test_clear(void)
{
	uint16_t d7 = 0;

	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	scene_step++;
}

/* the colour bars drawn */
void draw_color_test(void)
{
	uint8_t d3_2 = 0, d6 = 0;
	uint16_t d3 = 0, d4 = 0, d5 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	if (jobs_pending != 0u)
		return;
	a5 = table_loaded_by_lea_005846_ADDRESS;
	queue_jobs(a5);
	d7 = 1u;
	d7 = color_test_colour(d7);
	d5 = 7u;
	a5 = rom_00584C;
	a6 = a5;
	do
	{
		d4 = 7u;
		d6 = 0x31u;
		do
		{
			d3 = 3u;
			do
			{
				mem_write8(a6, d7);
				a6++;
				mem_write8(a6, d6);
				t1 = d3 - 1u;
				d3 = t1;
				a6++;
			} while (t1 != 0xFFFFu);
			d6++;
			t2 = d4 - 1u;
			d4 = t2;
		} while (t2 != 0xFFFFu);
		a5 += 0x80u;
		a6 = a5;
		t3 = d5 - 1u;
		d5 = t3;
	} while (t3 != 0xFFFFu);
	a4 = 0x1F1Cu;
	a5 = rom_005850;
	a6 = a5;
	d5 = 3u;
	do
	{
		d4 = 0xFu;
		d6 = 0x30u;
		do
		{
			d3_2 = mem_read8(a4 + (int16_t)d5);
			mem_write8(a6, d3_2);
			mem_write8(a6 + 2u, d3_2);
			mem_write8(a6 + 0x80u, d3_2);
			mem_write8(a6 + 0x82u, d3_2);
			mem_write8(a6 + 1u, d6);
			mem_write8(a6 + 3u, d6);
			mem_write8(a6 + 0x81u, d6);
			mem_write8(a6 + 0x83u, d6);
			d6++;
			t4 = d4 - 1u;
			d4 = t4;
			a6 += 4u;
		} while (t4 != 0xFFFFu);
		a5 += 0x180u;
		a6 = a5;
		t5 = d5 - 1u;
		d5 = t5;
	} while (t5 != 0xFFFFu);
	scene_step++;
}

/* a colour of the colour test */
uint32_t color_test_colour(uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = text_colours[d7];
	return d7_2;
}

/* the test mode's input test */
void io_test_page(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		io_test_clear();
		return;
	case 1:
		draw_io_test();
		return;
	case 2:
		show_inputs();
		return;
	}
}

/* the layers cleared */
void io_test_clear(void)
{
	uint16_t d7 = 0;

	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	scene_step++;
}

/* the input test's texts */
void draw_io_test(void)
{
	uint32_t a5 = 0;

	if (jobs_pending != 0u)
		return;
	a5 = table_loaded_by_lea_005896_ADDRESS;
	queue_jobs(a5);
	scene_step++;
}

/* every input shown */
void show_inputs(void)
{
	show_player_inputs();
	show_coin_inputs();
	show_dip_switches();
	test_page_controls();
}

/* the four players' inputs shown */
void show_player_inputs(void)
{
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0, d5 = 0;
	uint16_t t1 = 0;

	d7 = 0u;
	do
	{
		d6 = (uint16_t)((uint32_t)d7 << 2);
		d5 = (uint8_t)~mem_read8(indexed_table_of_32_bit_values_0059A6[d6 / 4u]);
		a6 = rom_0059B6[d6 / 4u];
		d6 = 7u;
		do
		{
			if ((uint8_t)d6 != 1u)
			{
				if ((uint8_t)d6 != 0u)
					d5 = show_input_bit(d5, a6);
			}
			else
				d5 = (uint8_t)d5 >> 1;
			t1 = d6 - 1u;
			d6 = t1;
			a6 += 0x100u;
		} while (t1 != 0xFFFFu);
		d7 = (uint8_t)(d7 + 1u);
	} while (d7 < 4u);
}

/* the coin and service switches shown */
void show_coin_inputs(void)
{
	uint16_t d6 = 0;
	uint32_t a6 = 0, d5 = 0;
	uint16_t t1 = 0, t2 = 0;

	d5 = (uint8_t)~mem_read8(rom_0059C6);
	a6 = rom_0059CA;
	d6 = 3u;
	do
	{
		d5 = show_input_bit(d5, a6);
		t1 = d6 - 1u;
		d6 = t1;
		a6 += 0x100u;
	} while (t1 != 0xFFFFu);
	d5 = (uint8_t)~mem_read8(rom_0059C6) >> 4;
	a6 = rom_0059CE;
	d6 = 3u;
	do
	{
		d5 = show_input_bit(d5, a6);
		t2 = d6 - 1u;
		d6 = t2;
		a6 += 0x100u;
	} while (t2 != 0xFFFFu);
}

/* the DIP switches shown */
void show_dip_switches(void)
{
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0, d5 = 0;
	uint16_t t1 = 0;

	d7 = 0u;
	do
	{
		d6 = (uint16_t)((uint32_t)d7 << 2);
		d5 = (uint8_t)~mem_read8(rom_0059D2[d6 / 4u]);
		a6 = rom_0059DE[d6 / 4u];
		d6 = 7u;
		if (d7 == 2u)
			d6 = 3u;
		do
		{
			d5 = show_input_bit(d5, a6);
			t1 = d6 - 1u;
			d6 = t1;
			a6 += 4u;
		} while (t1 != 0xFFFFu);
		d7 = (uint8_t)(d7 + 1u);
	} while (d7 < 3u);
}

/* an input shown as 0 or 1 */
uint32_t show_input_bit(uint32_t d5, uint32_t a6)
{
	uint32_t carry = 0;
	uint8_t d4 = 0;

	d4 = 0u;
	carry = d5 & 1u;
	d5 = (d5 & ~0xFFu) | ((uint8_t)d5 >> 1);
	if (carry)
		d4 = 1u;
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, d4);
	return d5;
}

/* the coin counter test left out */
void skip_coin_counter_test(void)
{
	scene++;
	scene_step = 0u;
}

/* Unused: the test mode's coin counter test */
void coin_counter_test_page(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		coin_counter_test_clear();
		break;
	case 1:
		draw_coin_counter_test();
		break;
	case 2:
		pulse_coin_counters();
		break;
	}
	test_page_controls();
}

/* unused: the layers cleared */
void coin_counter_test_clear(void)
{
	uint16_t d7 = 0;

	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	scene_step++;
}

/* unused: the coin counter test's texts */
void draw_coin_counter_test(void)
{
	uint32_t a5 = 0;

	if (jobs_pending == 0u)
	{
		a5 = table_loaded_by_lea_005A58_ADDRESS;
		queue_jobs(a5);
		scene_step++;
		turtles_in_black = 0u;
		initials_entered(0) = 0xFFu;
		initials_entered(1) = 0u;
		initials_entered(2) = 0u;
	}
}

/* unused: each coin counter pulsed in turn */
void pulse_coin_counters(void)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = turtles_in_black;
	turtles_in_black = t1 - 1u;
	if (t1 != 0u)
	{
		if (turtles_in_black == 0x1Eu)
			board_control &= ~3u;
		return;
	}
	initials_entered(0)++;
	if (initials_entered(0) < 4u)
	{
		a6 = unexplained_005B40;
		d7 = (uint8_t)(initials_entered(1) + 1u);
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, d7);
		a6 = rom_005B44;
		d7 = (uint8_t)(initials_entered(0) + 1u);
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, d7);
		d7 = (uint8_t)((board_control & ~3u) | shl32(1u, (int)(initials_entered(1) & 0x1Fu)));
		io_write8(IO_0A0001, d7);
		board_control = d7;
		turtles_in_black = 0x20u;
		return;
	}
	initials_entered(0) = 0u;
	initials_entered(1)++;
	if (initials_entered(1) < 2u)
	{
		a6 = unexplained_005B40;
		d7 = (uint8_t)(initials_entered(1) + 1u);
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, d7);
		a6 = rom_005B44;
		d7 = (uint8_t)(initials_entered(0) + 1u);
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, d7);
		d7 = (uint8_t)((board_control & ~3u) | shl32(1u, (int)(initials_entered(1) & 0x1Fu)));
		io_write8(IO_0A0001, d7);
		board_control = d7;
		turtles_in_black = 0x20u;
		return;
	}
	initials_entered(1) = 0u;
	initials_entered(2)++;
	if (initials_entered(2) >= 2u)
	{
		initials_entered(2) = 0u;
		scene++;
		scene_step = 0u;
		return;
	}
	tile_flip ^= 7u;
	a6 = unexplained_005B40;
	d7 = (uint8_t)(initials_entered(1) + 1u);
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, d7);
	a6 = rom_005B44;
	d7 = (uint8_t)(initials_entered(0) + 1u);
	mem_write8(a6, 0u);
	mem_write8(a6 + 1u, d7);
	d7 = (uint8_t)((board_control & ~3u) | shl32(1u, (int)(initials_entered(1) & 0x1Fu)));
	io_write8(IO_0A0001, d7);
	board_control = d7;
	turtles_in_black = 0x20u;
}

/* the test mode's sound test */
void sound_test_page(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		sound_test_clear();
		return;
	case 1:
		draw_sound_test();
		return;
	case 2:
		sound_test_play();
		return;
	}
}

/* the layers cleared */
void sound_test_clear(void)
{
	uint16_t d7 = 0;

	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	scene_step++;
}

/* the sound test's texts */
void draw_sound_test(void)
{
	uint32_t a5 = 0;

	if (jobs_pending == 0u)
	{
		a5 = table_loaded_by_lea_005B9C_ADDRESS;
		queue_jobs(a5);
		ranking_time = 0u;
		initials_entered(0) = 0u;
		initials_entered(1) = 0u;
		scene_step++;
	}
}

/* the next sound played, by itself or by the button */
void sound_test_play(void)
{
	uint8_t d7 = 0;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = ranking_time;
	ranking_time = t1 - 1u;
	if (t1 != 0u && (player_presses(0) & 0x20u) == 0u)
	{
		test_page_controls();
		return;
	}
	d7 = 0u;
	queue_test_sound(d7);
	d7_2 = initials_entered(0);
	t2 = indexed_table_of_8_bit_values_006146[d7_2];
	d7_2 = t2;
	if (t2 == 0u)
	{
		scene++;
		scene_step = 0u;
		return;
	}
	queue_test_sound((uint8_t)d7_2);
	a6 = TILE_RAM + 0x8CAu;
	d6 = 1u;
	d7_2 = initials_entered(1);
	draw_hex_digits(d6, d7_2, a6);
	initials_entered(0)++;
	initials_entered(1)++;
	ranking_time = 0x12Cu;
	test_page_controls();
}

void unreached_005C0C(void)
{
}

/* the test mode's DIP switch settings */
void dip_switch_page(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		dip_switch_clear();
		return;
	case 1:
		draw_dip_switch_page();
		return;
	case 2:
		show_dip_settings();
		return;
	}
}

/* the layers cleared */
void dip_switch_clear(void)
{
	uint16_t d7 = 0;

	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	scene_step++;
}

/* the settings' names */
void draw_dip_switch_page(void)
{
	uint32_t a5 = 0;

	if (jobs_pending == 0u)
	{
		a5 = table_loaded_by_lea_005C5E_ADDRESS;
		queue_jobs(a5);
		scene_step++;
	}
}

/* every setting shown */
void show_dip_settings(void)
{
	show_coinage();
	show_difficulty();
	show_lives_setting();
	show_demo_sound();
	show_screen_setting();
	show_test_switch();
	test_page_controls();
}

/* the coins and credits of each slot */
void show_coinage(void)
{
	uint8_t d0 = 0, d1 = 0, d4 = 0, d5 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0;

	d6 = io_read8(IO_0A0011);
	d6 = (uint8_t)~d6;
	d6 = d6 & 0xFu;
	d6 = (uint8_t)((uint32_t)d6 << 1);
	d0 = rom_001452[d6];
	d1 = rom_001453[d6];
	a6 = TILES_10032E;
	io_write8(TILES_10032E, 0u);
	io_write8(TILES_10032F, d0);
	io_write8(TILES_100340, 0u);
	io_write8(TILES_100341, d1);
	d4 = 0x10u;
	d5 = 0x10u;
	if (d0 != 1u)
		d4 = 0x23u;
	if (d1 != 1u)
		d5 = 0x23u;
	io_write8(a6 + 0xCu, 0u);
	io_write8(a6 + 0xDu, d4);
	io_write8(a6 + 0x1Eu, 0u);
	io_write8(a6 + 0x1Fu, d5);
	d7 = 0x1007u;
	queue_job(d7);
}

void unreached_005CF6(void)
{
	uint16_t d7 = 0;

	d7 = 0x1013u;
	queue_job(d7);
}

/* the difficulty */
void show_difficulty(void)
{
	uint16_t d7 = 0;

	d7 = io_read8(IO_0A0013);
	d7 = (uint8_t)~d7;
	d7 = d7 & 0x60u;
	d7 = d7 >> 5;
	d7 = (uint8_t)(d7 + 9u);
	d7 += 0x1000u;
	queue_job(d7);
}

/* the lives a credit gives */
void show_lives_setting(void)
{
	uint8_t d7_2 = 0;
	uint16_t d7 = 0;

	d7 = io_read8(IO_0A0013);
	d7 = (uint8_t)~d7;
	d7_2 = rom_001426[d7 & 3u];
	io_write8(TILES_100838, 0u);
	io_write8(TILES_100839, d7_2);
}

/* the demo sound on or off */
void show_demo_sound(void)
{
	uint16_t d7 = 0;

	d7 = 0xDu;
	if ((io_read8(IO_0A0013) & 0x80u) == 0u)
		d7 = (uint8_t)(d7 + 1u);
	d7 += 0x1000u;
	queue_job(d7);
}

/* the screen normal or upside down */
void show_screen_setting(void)
{
	uint16_t d7 = 0;

	d7 = 0xFu;
	if ((io_read8(IO_0A0019) & 1u) == 0u)
		d7 = (uint8_t)(d7 + 1u);
	d7 += 0x1000u;
	queue_job(d7);
}

/* the test switch */
void show_test_switch(void)
{
	uint16_t d7 = 0;

	d7 = 0x11u;
	if ((io_read8(IO_0A0019) & 4u) == 0u)
		d7 = (uint8_t)(d7 + 1u);
	d7 += 0x1000u;
	queue_job(d7);
}

/* back to the test mode's start */
void test_mode_restart(void)
{
	scene = 0u;
	scene_step = 0u;
}

/* the button to the next page, and the screen's flip */
void test_page_controls(void)
{
	uint8_t d7 = 0;

	if ((player_presses(0) & 0x10u) != 0u)
	{
		scene++;
		scene_step = 0u;
		stop_test_sound();
	}
	d7 = tile_flip;
	if (scene != 5u)
	{
		d7 &= 2u;
		if ((io_read8(IO_0A0019) & 1u) == 0u)
			d7 ^= 7u;
	}
	tile_flip = d7;
	io_write8(TILES_106D00, d7);
}

/* the sound stopped */
void stop_test_sound(void)
{
	uint8_t d7 = 0;

	d7 = 0u;
	queue_test_sound(d7);
}

/* a sound into the sound board's queue */
void queue_test_sound(uint8_t d7)
{
	uint32_t a6 = 0;

	a6 = sound_queue_write;
	mem_write8(a6, d7);
	a6++;
	if (a6 > sound_queue_ADDRESS + 0x3Fu)
		a6 = sound_queue_ADDRESS;
	sound_queue_write = a6;
}
