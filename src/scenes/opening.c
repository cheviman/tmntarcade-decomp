/**
 *    Name:        scenes/opening.c
 *    Description: the attract mode's opening: the city at night, the manhole, the turtles leap out, their four pictures
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the opening's city at night and two clouds by the moon */
void start_opening(void)
{
	uint32_t a0 = 0, animation = 0, ignored = 0;

	fade_state = 0u;
	saved_turtle = 0xE0000000u;
	cutscene_step = 0u;
	LAYER(LAYER_A)->map = layers_03F196_ADDRESS;
	LAYER(LAYER_B)->map = layers_03E98A_ADDRESS;
	LAYER(LAYER_A)->blocks = 0x3F796u;
	LAYER(LAYER_B)->blocks = 0x3EB8Au;
	LAYER(LAYER_A)->x = 0u;
	LAYER(LAYER_B)->x = 0u;
	LAYER(LAYER_A)->y = 0x60000u;
	LAYER(LAYER_B)->y = 0x20000u;
	LAYER(LAYER_A)->map_width = 0x20u;
	LAYER(LAYER_B)->map_width = 0x20u;
	LAYER(LAYER_A)->x_speed = 0u;
	LAYER(LAYER_A)->y_speed = 0u;
	LAYER(LAYER_B)->x_speed = 0u;
	LAYER(LAYER_B)->y_speed = 0u;
	LAYER(LAYER_A)->row_phase = 0u;
	LAYER(LAYER_B)->row_phase = 0u;
	load_layer_b();
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	save_layer_b();
	load_layer_a();
	a0 = TILE_RAM + 0x2000u;
	draw_whole_layer(a0);
	save_layer_a();
	a0 = OBJECT_ADDRESS(0);
	OBJECT(OBJECT_ADDRESS(0))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(1))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(0))->screen_x = 0x88u;
	OBJECT(OBJECT_ADDRESS(0))->screen_y = 0xC4u;
	OBJECT(OBJECT_ADDRESS(1))->screen_x = 0x130u;
	OBJECT(OBJECT_ADDRESS(1))->screen_y = 0xA0u;
	OBJECT(OBJECT_ADDRESS(0))->contacts = 0u;
	OBJECT(OBJECT_ADDRESS(1))->contacts = 0u;
	OBJECT(OBJECT_ADDRESS(0))->height = 0u;
	OBJECT(OBJECT_ADDRESS(1))->height = 0u;
	OBJECT(OBJECT_ADDRESS(0))->colour = 0xFFu;
	OBJECT(OBJECT_ADDRESS(1))->colour = 0xFFu;
	animation = 0x2DADCu;
	set_animation(ignored, a0, animation);
	animation = 0x2DAD2u;
	a0 = OBJECT_ADDRESS(1);
	set_animation(ignored, a0, animation);
}

/* every frame of the opening: its step, then the layers' scroll */
void run_opening(uint16_t d6, uint32_t a5)
{
	uint16_t d0 = 0;

	d0 = cutscene_step;
	switch ((uint8_t)((uint32_t)d0 << 2))
	{
	case 0:
		opening_city_fade_in(d6, a5);
		break;
	case 4:
		opening_sweep();
		break;
	case 8:
		opening_sweep_fast();
		break;
	case 12:
		opening_sweep_to_street();
		break;
	case 16:
		opening_turtles_ready();
		break;
	case 20:
		opening_turtles_leap_out();
		break;
	case 24:
		opening_portraits_start();
		break;
	case 28:
		opening_portraits_slide_in();
		break;
	case 32:
		opening_hold();
		break;
	}
	set_layers_scroll();
}

/* the city fades in and the clouds drift apart across the moon */
void opening_city_fade_in(uint16_t d6, uint32_t a5)
{
	uint8_t d7 = 0;
	uint8_t t1 = 0;

	if (fading == 0u)
	{
		a5 = 0xA0AEu;
		d6 = 0xC02u;
		fade_state = 0u;
	}
	copy_palette_sets(d6, a5);
	if ((frame_count & 3u) == 0u)
	{
		OBJECT(OBJECT_ADDRESS(0))->screen_x++;
		OBJECT(OBJECT_ADDRESS(1))->screen_x--;
	}
	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 == 1u)
	{
		next_opening_step();
		return;
	}
	if (cutscene_wait != 0x30u)
		return;
	d7 = 0x7Du;
	queue_sound(d7, 0u);
}

/* the clouds leave and the view starts sweeping down the city */
void opening_sweep(void)
{
	uint32_t object = 0;

	if ((frame_count & 3u) == 0u)
	{
		OBJECT(OBJECT_ADDRESS(0))->screen_x++;
		OBJECT(OBJECT_ADDRESS(1))->screen_x--;
	}
	object = OBJECT_ADDRESS(0);
	OBJECT(OBJECT_ADDRESS(0))->screen_y += 2u;
	OBJECT(OBJECT_ADDRESS(1))->screen_y += 2u;
	if (OBJECT(OBJECT_ADDRESS(1))->screen_y >= 0x100u)
	{
		OBJECT(object)->flags = 0u;
		OBJECT(object + 0x50u)->flags = 0u;
	}
	load_layer_b();
	LAYER(WORKING_LAYER)->y_speed = 0x200u;
	working_layer_tiles = TILE_RAM + 0x4000u;
	opening_scroll_layer();
	save_layer_b();
	load_layer_a();
	LAYER(WORKING_LAYER)->y_speed += 0x40u;
	if (LAYER(WORKING_LAYER)->y_speed >= 0x1000u)
		LAYER(WORKING_LAYER)->y_speed = 0xFFFu;
	working_layer_tiles = TILE_RAM + 0x2000u;
	opening_scroll_layer();
	save_layer_a();
	if (LAYER(LAYER_A)->y >= 0x30000u)
		return;
	next_opening_step();
}

/* the opening's next step */
void next_opening_step(void)
{
	cutscene_step++;
}

/* the view rushes down past the buildings */
void opening_sweep_fast(void)
{
	uint32_t y_speed = 0;

	load_layer_a();
	LAYER(WORKING_LAYER)->y_speed += 0x20u;
	if (LAYER(WORKING_LAYER)->y_speed >= 0x1000u)
		LAYER(WORKING_LAYER)->y_speed = 0xFFFu;
	y_speed = LAYER(WORKING_LAYER)->y_speed;
	LAYER(WORKING_LAYER)->y -= y_speed;
	LAYER(WORKING_LAYER)->row_phase -= y_speed << 4;
	if (LAYER(WORKING_LAYER)->y < 0x20000u)
	{
		LAYER(WORKING_LAYER)->y = (LAYER(WORKING_LAYER)->y & 0xFFFFu) | 0x20000u;
		cutscene_count++;
	}
	save_layer_a();
	if (cutscene_count < 3u || LAYER(LAYER_A)->y < 0x2C000u)
		return;
	next_opening_step();
}

/* the view slows down onto the street with the manhole */
void opening_sweep_to_street(void)
{
	uint32_t a0 = 0, animation = 0, ignored = 0;

	load_layer_a();
	if (LAYER(WORKING_LAYER)->y < 0x1A000u)
	{
		LAYER(WORKING_LAYER)->y_speed -= 0x60u;
		if (LAYER(WORKING_LAYER)->y_speed < 0x800u)
			LAYER(WORKING_LAYER)->y_speed = 0x800u;
	}
	working_layer_tiles = TILE_RAM + 0x2000u;
	opening_scroll_layer();
	save_layer_a();
	if (LAYER(WORKING_LAYER)->y < 0x14000u)
	{
		a0 = OBJECT_ADDRESS(0);
		OBJECT(OBJECT_ADDRESS(0))->flags = 0x81u;
		OBJECT(OBJECT_ADDRESS(0))->contacts = 0u;
		OBJECT(OBJECT_ADDRESS(0))->colour = 0xFFu;
		OBJECT(OBJECT_ADDRESS(0))->screen_x = 0x100u;
		OBJECT(OBJECT_ADDRESS(0))->height = 0u;
		OBJECT(OBJECT_ADDRESS(0))->screen_y = (0x11000u - LAYER(WORKING_LAYER)->y) >> 8;
		animation = 0x2DA30u;
		set_animation(0u, a0, animation);
		a0 = OBJECT_ADDRESS(1);
		OBJECT(OBJECT_ADDRESS(1))->flags = 0x81u;
		OBJECT(OBJECT_ADDRESS(1))->contacts = 0u;
		OBJECT(OBJECT_ADDRESS(1))->colour = 0xFFu;
		OBJECT(OBJECT_ADDRESS(1))->screen_x = 0x100u;
		OBJECT(OBJECT_ADDRESS(1))->height = 0u;
		OBJECT(OBJECT_ADDRESS(1))->screen_y = (0x10000u - LAYER(WORKING_LAYER)->y) >> 8;
		animation = 0x2DA26u;
		set_animation(ignored, a0, animation);
		if (LAYER(WORKING_LAYER)->y == 0x10000u)
		{
			cutscene_wait = 0x30u;
			next_opening_step();
			return;
		}
	}
}

/* the four turtles wait under the manhole */
void opening_turtles_ready(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, animation = 0, object = 0;
	uint8_t t1 = 0;

	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 != 1u)
		return;
	cutscene_wait = 0x40u;
	a0 = OBJECT_ADDRESS(6);
	OBJECT(OBJECT_ADDRESS(6))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(6))->contacts = 0u;
	OBJECT(OBJECT_ADDRESS(6))->colour = 0xFFu;
	OBJECT(OBJECT_ADDRESS(6))->screen_x = 0x100u;
	OBJECT(OBJECT_ADDRESS(6))->screen_y = 8u;
	animation = 0x2DAB8u;
	set_animation(0u, a0, animation);
	object = OBJECT_ADDRESS(2);
	d0 = 0u;
	do
	{
		OBJECT(object)->kind = (uint8_t)d0;
		OBJECT(object)->y_speed = indexed_table_of_16_bit_values_02FBE0[d0 & 0x7FFFu];
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->screen_x = 0x100u;
		OBJECT(object)->screen_y = 0x14u;
		OBJECT(object)->x = 0x10000u;
		OBJECT(object)->y = 0x1400u;
		OBJECT(object)->height = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 8u;
		d0 = (uint8_t)(d0 + 1u);
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(6));
	next_opening_step();
}

/* the manhole cover blows off in a flash of light and the turtles leap out */
void opening_turtles_leap_out(void)
{
	uint8_t d0_2 = 0, d1_2 = 0;
	uint16_t d0 = 0, d1 = 0, d6 = 0, d7 = 0;
	uint32_t a0 = 0, animation = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, object = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	if (cutscene_wait == 0u)
	{
		object = OBJECT_ADDRESS(2);
		do
		{
			OBJECT(object)->height += 0x240u;
			OBJECT(object)->x_speed += OBJECT(object)->y_speed;
			OBJECT(object)->x += OBJECT(object)->x_speed;
			d1 = (uint16_t)(OBJECT(object)->y >> 8);
			OBJECT(object)->screen_x = OBJECT(object)->x >> 8;
			OBJECT(object)->screen_y = d1;
			object += 0x50u;
		} while (object < OBJECT_ADDRESS(6));
		if (OBJECT(OBJECT_ADDRESS(2))->screen_x < 0xE0u)
			next_opening_step();
	}
	else
	{
		t1 = cutscene_wait;
		cutscene_wait = t1 - 1u;
		if (t1 == 1u)
		{
			object = OBJECT_ADDRESS(2);
			do
			{
				OBJECT(object)->flags = 0x81u;
				OBJECT(object)->contacts = 0u;
				d0 = 0x204u;
				turtle_set_state(d0, object, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
				object += 0x50u;
			} while (object < OBJECT_ADDRESS(6));
			object = OBJECT_ADDRESS(2);
			do
			{
				OBJECT(object)->height += 0x240u;
				OBJECT(object)->x_speed += OBJECT(object)->y_speed;
				OBJECT(object)->x += OBJECT(object)->x_speed;
				d1 = (uint16_t)(OBJECT(object)->y >> 8);
				OBJECT(object)->screen_x = OBJECT(object)->x >> 8;
				OBJECT(object)->screen_y = d1;
				object += 0x50u;
			} while (object < OBJECT_ADDRESS(6));
			if (OBJECT(OBJECT_ADDRESS(2))->screen_x < 0xE0u)
				next_opening_step();
		}
		else if (cutscene_wait >= 0x20u)
		{
			if (cutscene_wait != 0x20u)
				return;
			a0 = OBJECT_ADDRESS(7);
			OBJECT(OBJECT_ADDRESS(7))->flags = 0x81u;
			OBJECT(OBJECT_ADDRESS(7))->contacts = 0u;
			OBJECT(OBJECT_ADDRESS(7))->colour = 0xFFu;
			OBJECT(OBJECT_ADDRESS(7))->animation_delay = 0u;
			OBJECT(OBJECT_ADDRESS(7))->screen_x = 0x100u;
			OBJECT(OBJECT_ADDRESS(7))->screen_y = 0x50u;
			animation = 0x2DA3Au;
			set_animation(0u, a0, animation);
			OBJECT(OBJECT_ADDRESS(1))->height = 0x1000u;
			OBJECT(OBJECT_ADDRESS(6))->frame_time = 0u;
			return;
		}
	}
	d1_2 = 0x3Cu;
	if (cutscene_wait != 0x1Cu)
	{
		if (cutscene_wait == 0x1Au)
			d1_2 = 0x10u;
		else
		{
			d1_2 = 0x3Cu;
			if (cutscene_wait != 0x10u)
			{
				if (cutscene_wait != 0xEu)
				{
					object = OBJECT_ADDRESS(1);
					if (OBJECT(OBJECT_ADDRESS(1))->flags != 0u)
					{
						OBJECT(object)->height += 0x1000u;
						if (OBJECT(object)->height_whole == 0xB0u)
						{
							OBJECT(object)->flags = 0u;
							OBJECT(OBJECT_ADDRESS(6))->frame_time = 1u;
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
			io_write8(a0, d0_2);
			a0++;
			io_write8(a0, d1_2);
			a0++;
			io_write8(a0, d0_2);
			a0++;
			io_write8(a0, d1_2);
			t2 = d6 - 1u;
			d6 = t2;
			a0++;
		} while (t2 != 0xFFFFu);
		t3 = d7 - 1u;
		d7 = t3;
		a0 += 0x30u;
	} while (t3 != 0xFFFFu);
	object = OBJECT_ADDRESS(1);
	if (OBJECT(OBJECT_ADDRESS(1))->flags != 0u)
	{
		OBJECT(object)->height += 0x1000u;
		if (OBJECT(object)->height_whole == 0xB0u)
		{
			OBJECT(object)->flags = 0u;
			OBJECT(OBJECT_ADDRESS(6))->frame_time = 1u;
		}
	}
}

/* the screen cleared and the four turtles' pictures at its corners */
void opening_portraits_start(void)
{
	uint8_t d0 = 0, d1 = 0;
	uint32_t a0 = 0, a1 = 0, a5 = 0, animation = 0, d0_2 = 0, d1_2 = 0, object = 0;

	a0 = TILE_RAM + 0x2000u;
	a1 = TILE_RAM + 0x4000u;
	d0 = 0u;
	d1 = 0x10u;
	do
	{
		io_write8(a1, d0);
		a1++;
		io_write8(a1, d1);
		a1++;
		io_write8(a1, d0);
		a1++;
		io_write8(a1, d1);
		a1++;
	} while (a1 < TILE_RAM + 0x5000u);
	do
	{
		io_write8(a0, d0);
		a0++;
		io_write8(a0, d1);
		a0++;
		io_write8(a0, d0);
		a0++;
		io_write8(a0, d1);
		a0++;
	} while (a0 < TILE_RAM + 0x3000u);
	object = OBJECT_ADDRESS(0);
	d0 = 0u;
	do
	{
		OBJECT(object)->flags = d0;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(19));
	object = OBJECT_ADDRESS(0);
	a5 = table_loaded_by_lea_02FDC0_ADDRESS;
	do
	{
		OBJECT(object)->flags = 0x81u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		OBJECT(object)->height = 0u;
		d0_2 = DATA32(a5);
		a5 += 4u;
		d1_2 = DATA32(a5);
		OBJECT(object)->x = d0_2;
		OBJECT(object)->y = d1_2;
		OBJECT(object)->screen_x = d0_2 >> 8;
		OBJECT(object)->screen_y = d1_2 >> 8;
		a5 += 4u;
		animation = DATA32(a5);
		a5 += 4u;
		set_animation(d1_2, object, animation);
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	next_opening_step();
}

/* the four pictures slide in from the corners */
void opening_portraits_slide_in(void)
{
	uint16_t d0 = 0, d1 = 0;
	uint32_t object = 0;

	object = OBJECT_ADDRESS(0);
	OBJECT(OBJECT_ADDRESS(0))->x += 0x400u;
	OBJECT(OBJECT_ADDRESS(1))->x -= 0x400u;
	OBJECT(OBJECT_ADDRESS(2))->x += 0x400u;
	OBJECT(OBJECT_ADDRESS(3))->x -= 0x400u;
	OBJECT(OBJECT_ADDRESS(0))->y -= 0x400u;
	OBJECT(OBJECT_ADDRESS(1))->y -= 0x400u;
	OBJECT(OBJECT_ADDRESS(2))->y += 0x400u;
	OBJECT(OBJECT_ADDRESS(3))->y += 0x400u;
	do
	{
		d0 = (uint16_t)(OBJECT(object)->x >> 8);
		d1 = (uint16_t)(OBJECT(object)->y >> 8);
		OBJECT(object)->screen_x = d0;
		OBJECT(object)->screen_y = d1;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	if ((uint16_t)d0 == 0x100u)
	{
		next_opening_step();
		return;
	}
	opening_hold();
}

/* the four pictures stay on the screen */
void opening_hold(void)
{
}

/* the opening's layer sweeps on by its speed and its new rows are drawn */
void opening_scroll_layer(void)
{
	uint8_t d7 = 0;
	uint16_t d1 = 0, y_speed = 0;
	uint32_t a0 = 0, a2 = 0, a3 = 0, d0 = 0, d3 = 0, d4 = 0, d5 = 0;
	uint8_t t1 = 0;
	uint16_t row_phase = 0;

	y_speed = LAYER(WORKING_LAYER)->y_speed;
	d1 = (uint16_t)((uint32_t)y_speed << 4);
	LAYER(WORKING_LAYER)->y -= y_speed;
	if (LAYER(WORKING_LAYER)->y < 0x10000u)
	{
		LAYER(WORKING_LAYER)->y = 0x10000u;
		return;
	}
	row_phase = LAYER(WORKING_LAYER)->row_phase;
	LAYER(WORKING_LAYER)->row_phase = row_phase - d1;
	if (d1 <= row_phase)
		return;
	d0 = LAYER(WORKING_LAYER)->y - 0xF000u;
	d3 = d0;
	d5 = d0;
	d0 &= 0xF000u;
	d0 = (uint16_t)(d0 + 0x1000u);
	d0 = (uint16_t)(0u - d0);
	a0 = (d0 >> 4) + working_layer_tiles;
	d3 = (d3 & 0xFFE000u) << 3;
	a2 = ((d3 << 16) | (d3 >> 16)) * LAYER(WORKING_LAYER)->map_width + LAYER(WORKING_LAYER)->map;
	d5 = d5 << 7;
	d5 = (((d5 << 16) | (d5 >> 16)) & 8u) ^ 8u;
	d7 = 0xBu;
	do
	{
		a3 = LAYER(WORKING_LAYER)->blocks;
		d4 = mem_read16(a2);
		io_write8(a0, mem_read8(a3 + (int16_t)d4));
		io_write8(a0 + 2u, mem_read8(a3 + (int16_t)d4));
		io_write8(a0 + 4u, mem_read8(a3 + (int16_t)d4));
		io_write8(a0 + 6u, mem_read8(a3 + (int16_t)d4));
		io_write8(a0 + 0x80u, mem_read8(a3 + (int16_t)d4));
		io_write8(a0 + 0x82u, mem_read8(a3 + (int16_t)d4));
		io_write8(a0 + 0x84u, mem_read8(a3 + (int16_t)d4));
		io_write8(a0 + 0x86u, mem_read8(a3 + (int16_t)d4));
		a3 += d4;
		io_write8(a0 + 1u, DATA8(a3 + 1u + d5));
		io_write8(a0 + 3u, DATA8(a3 + 2u + d5));
		io_write8(a0 + 5u, DATA8(a3 + 3u + d5));
		io_write8(a0 + 7u, DATA8(a3 + 4u + d5));
		io_write8(a0 + 0x81u, DATA8(a3 + 5u + d5));
		io_write8(a0 + 0x83u, DATA8(a3 + 6u + d5));
		io_write8(a0 + 0x85u, DATA8(a3 + 7u + d5));
		io_write8(a0 + 0x87u, DATA8(a3 + 8u + d5));
		t1 = d7;
		d7 = (uint8_t)(t1 - 1u);
		a2 += 2u;
		a0 += 8u;
	} while (t1 != 1u);
}
