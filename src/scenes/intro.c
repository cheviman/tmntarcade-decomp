/**
 *    Name:        scenes/intro.c
 *    Description: the story before area 0: the rooftop, "Fire!!", the climb, the burning roof
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the story before the first area starts */
void start_intro(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	time_without_knockout = 0u;
	difficulty_from_time = 0u;
	prompt_shown(0) = 0u;
	prompt_shown(1) = 0u;
	prompt_shown(2) = 0u;
	prompt_shown(3) = 0u;
	cutscene_step = 0u;
	intro_over = 0u;
	balloon_time = 0u;
	balloons_said = 0u;
	cutscene_counter = 0u;
	LAYER(WORKING_LAYER)->x = 0x800u;
	LAYER(LAYER_A)->x = 0x800u;
	LAYER(LAYER_B)->x = 0x800u;
	LAYER(WORKING_LAYER)->y = 0x10000u;
	LAYER(LAYER_A)->y = 0x10000u;
	LAYER(LAYER_B)->y = 0x10000u;
	set_layers_scroll();
	start_box_opening();
	a6 = 0xA0EEu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
}

/* every frame of the story: its balloon, its step, the layers' scroll */
void run_intro(void)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;
	uint8_t t1 = 0;

	if (balloon_time != 0u)
	{
		t1 = balloon_time;
		balloon_time = t1 - 1u;
		if (t1 == 1u)
			erase_balloon(&ignored, &ignored_2, &ignored_3);
	}
	d0 = (uint16_t)((uint32_t)cutscene_step << 2);
	switch (d0)
	{
	case 0:
		intro_rooftop_start();
		break;
	case 4:
		intro_rooftop(d0);
		break;
	case 8:
		intro_climb_start();
		break;
	case 12:
		intro_climb();
		break;
	case 16:
		intro_roof_start();
		break;
	case 20:
		intro_roof_land();
		break;
	}
	set_layers_scroll();
}

/* the rooftop picture with Splinter and the four turtles by the burning building */
void intro_rooftop_start(void)
{
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a0 = 0, a5 = 0, a6 = 0, animation = 0, d1 = 0, object = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (palettes_busy != 0u)
		return;
	cutscene_time = 0x100u;
	a0 = TILE_RAM + 0x4008u;
	d0 = 0x24u;
	d1 = 0u;
	d7 = 0x1Fu;
	do
	{
		d6 = 0x1Fu;
		do
		{
			io_write8(a0, d0);
			a0++;
			io_write8(a0, d1);
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
	colour_tiles_8x8(d0, a0);
	a0 = TILE_RAM + 0x4438u;
	d0 = 5u;
	colour_tiles_8x8(d0, a0);
	a0 = TILE_RAM + 0x4838u;
	d0 = 6u;
	colour_tiles_8x8(d0, a0);
	a0 = TILE_RAM + 0x4C40u;
	d0 = 7u;
	colour_tiles_4x4(d0, a0);
	a0 = TILE_RAM + 0x4630u;
	d0 = 5u;
	colour_tiles_4x4(d0, a0);
	a0 = TILE_RAM + 0x4828u;
	d0 = 6u;
	colour_tiles_8x4(d0, a0);
	a0 = TILE_RAM + 0x4A28u;
	d0 = 0x46u;
	colour_tiles_4x4(d0, a0);
	a0 = TILE_RAM + 0x4A30u;
	d0 = 6u;
	colour_tiles_4x4(d0, a0);
	a0 = TILE_RAM + 0x4C30u;
	d0 = 0x47u;
	colour_tiles_8x4(d0, a0);
	io_write8(TILES_106B00, 0xF0u);
	tile_banks_0_1 = 0xF0u;
	io_write8(TILES_106E00, 0x21u);
	tile_banks_2_3 = 0x21u;
	a0 = OBJECT_ADDRESS(44);
	OBJECT(OBJECT_ADDRESS(44))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(44))->height = 0u;
	OBJECT(OBJECT_ADDRESS(44))->colour = 0xFFu;
	OBJECT(OBJECT_ADDRESS(44))->animation_delay = 0u;
	OBJECT(OBJECT_ADDRESS(44))->screen_x = 0xA0u;
	OBJECT(OBJECT_ADDRESS(44))->screen_y = 0x58u;
	animation = 0x2DB4Cu;
	set_animation(d1, a0, animation);
	object = OBJECT_ADDRESS(45);
	a5 = table_loaded_by_lea_030B16_ADDRESS;
	d0 = 0x70u;
	do
	{
		OBJECT(object)->flags = 0x81u;
		OBJECT(object)->height = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		OBJECT(object)->screen_x = 0xC0u;
		OBJECT(object)->screen_y = 0x70u;
		OBJECT(object)->x_speed = 0x500;
		OBJECT(object)->y_speed &= 0xFFu;
		OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | (d0 & 0xFFu);
		animation = DATA32(a5);
		set_animation(d1, object, animation);
		d0 += 0x14u;
		a5 += 4u;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(49));
	a0 = TILE_RAM + 0x2B28u;
	a6 = table_loaded_by_lea_030B26_ADDRESS;
	d0 = 0x3Bu;
	d7 = 9u;
	do
	{
		d6 = 0xFu;
		do
		{
			io_write8(a0, d0);
			a0++;
			io_write8(a0, DATA8(a6));
			t3 = d6 - 1u;
			d6 = t3;
			a0++;
			a6++;
		} while (t3 != 0xFFFFu);
		t4 = d7 - 1u;
		d7 = t4;
		a0 += 0x60u;
	} while (t4 != 0xFFFFu);
	cutscene_step++;
}

/* a square of 8 by 8 tiles given one colour */
void colour_tiles_8x8(uint8_t d0, uint32_t a0)
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
			io_write8(a0, d0);
			t1 = d6 - 1u;
			d6 = t1;
			a0 += 2u;
		} while (t1 != 0xFFFFu);
		a0 += d4;
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
}

/* a square of 4 by 4 tiles given one colour */
void colour_tiles_4x4(uint8_t d0, uint32_t a0)
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
			io_write8(a0, d0);
			t1 = d6 - 1u;
			d6 = t1;
			a0 += 2u;
		} while (t1 != 0xFFFFu);
		a0 += d4;
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
}

/* four rows of eight tiles given one colour */
void colour_tiles_8x4(uint8_t d0, uint32_t a0)
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
			io_write8(a0, d0);
			t1 = d6 - 1u;
			d6 = t1;
			a0 += 2u;
		} while (t1 != 0xFFFFu);
		a0 += d4;
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
}

/* "Fire!!": the turtles leap off the rooftop one after another, "Hang on, April" */
void intro_rooftop(uint32_t d0)
{
	uint8_t d0_2 = 0, d1_2 = 0, d7 = 0;
	uint16_t d2 = 0, d3 = 0, d6 = 0, d7_2 = 0;
	uint32_t a0 = 0, a5 = 0, a6 = 0, animation = 0, d1 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, ignored_6 = 0, object = 0;
	uint8_t t1 = 0;
	uint16_t height = 0, x_speed = 0, t2 = 0, t3 = 0, t4 = 0;

	grow_tile_box();
	d0 = intro_animate_fire(d0);
	turtles_on_the_way = 0u;
	object = OBJECT_ADDRESS(45);
	a5 = animations_030D7E_ADDRESS;
	do
	{
		if ((uint8_t)OBJECT(object)->y_speed == 0u)
		{
			if ((OBJECT(object)->flags & 0x80u) != 0u)
			{
				turtles_on_the_way--;
				if ((uint8_t)(OBJECT(object)->y_speed >> 8u) != 0u)
				{
					OBJECT(object)->height += 0x100u;
					d0 = (uint16_t)OBJECT(object)->x_speed;
					height = OBJECT(object)->height;
					OBJECT(object)->height = height - d0;
					if (height < d0)
						OBJECT(object)->flags &= 0x7Fu;
					OBJECT(object)->screen_x++;
					OBJECT(object)->screen_y--;
					OBJECT(object)->x_speed += 0x20u;
					if ((uint16_t)OBJECT(object)->x_speed >= 0x500u)
						OBJECT(object)->x_speed = 0x500;
				}
				else
				{
					if (object == OBJECT_ADDRESS(48) && (uint16_t)OBJECT(object)->x_speed == 0x360u)
					{
						io_write8(PRIORITY_0C0001, 4u);
						layer_priority = 4u;
					}
					OBJECT(object)->height += 0x100u;
					d0 = (uint16_t)OBJECT(object)->x_speed;
					OBJECT(object)->height += d0;
					OBJECT(object)->screen_x++;
					OBJECT(object)->screen_y--;
					x_speed = OBJECT(object)->x_speed;
					OBJECT(object)->x_speed = x_speed - 0x20u;
					if (x_speed < 0x20u)
					{
						OBJECT(object)->x_speed = 0u - OBJECT(object)->x_speed;
						OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFFu) | (((uint8_t)(OBJECT(object)->y_speed >> 8u) - 1u & 0xFFu) << 8u);
					}
				}
			}
		}
		else
		{
			turtles_on_the_way--;
			t1 = (uint8_t)OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | (t1 - 1u & 0xFFu);
			if (t1 == 1u)
			{
				animation = DATA32(a5);
				set_animation(ignored_6, object, animation);
			}
		}
		object += 0x50u;
		a5 += 4u;
	} while (object < OBJECT_ADDRESS(49));
	if (turtles_on_the_way == 0u)
	{
		start_box_opening();
		a0 = TILE_RAM + 0x2B28u;
		d0_2 = 0x3Bu;
		d1_2 = 0x41u;
		d7_2 = 9u;
		do
		{
			d6 = 0xFu;
			do
			{
				io_write8(a0, d0_2);
				a0++;
				io_write8(a0, d1_2);
				t2 = d6 - 1u;
				d6 = t2;
				a0++;
			} while (t2 != 0xFFFFu);
			t3 = d7_2 - 1u;
			d7_2 = t3;
			a0 += 0x60u;
		} while (t3 != 0xFFFFu);
		a6 = 0xA0FEu;
		d7_2 = 0x20Fu;
		post_palette_request(d7_2, a6);
		cutscene_step++;
		return;
	}
	t4 = cutscene_time;
	cutscene_time = t4 - 1u;
	if (t4 == 1u)
		cutscene_time++;
	if (cutscene_time == 0xD0u)
	{
		d0 &= ~0xFFu;
		d1 = 0x108u;
		d2 = 0x28u;
		d3 = 0x41u;
		show_balloon_beside(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
		draw_balloon_pointer(ignored_5);
		return;
	}
	if (cutscene_time == 0x90u)
	{
		d7 = 0x7Du;
		queue_sound(d7, animation);
		return;
	}
	if (cutscene_time != 0x70u)
		return;
	d0 &= ~0xFFu;
	d1 = 0xA8u;
	d2 = 0x28u;
	d3 = 0u;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
	draw_balloon_pointer(ignored_5);
}

/* the picture of a tall building seen from below with the turtles at its foot */
void intro_climb_start(void)
{
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a0 = 0, a5 = 0, animation = 0, d1 = 0, object = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	if (palettes_busy != 0u)
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
			io_write8(a0, d0);
			a0++;
			io_write8(a0, d1);
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
	object = OBJECT_ADDRESS(44);
	a5 = intro_object_animations_ADDRESS;
	d7 = 3u;
	do
	{
		OBJECT(object)->flags = 0x81u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->height = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		OBJECT(object)->screen_x = 0xF8u;
		OBJECT(object)->screen_y = 0xB8u;
		animation = DATA32(a5);
		a5 += 4u;
		OBJECT(object)->y_speed = DATA16(a5);
		a5 += 2u;
		set_animation(d1, object, animation);
		t3 = d7 - 1u;
		d7 = t3;
		object += 0x50u;
	} while (t3 != 0xFFFFu);
	cutscene_step++;
}

/* the turtles leap up the building out of sight */
void intro_climb(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, object = 0;

	grow_tile_box();
	object = OBJECT_ADDRESS(44);
	do
	{
		if (OBJECT(object)->frame_time == 0u && (OBJECT(object)->flags & 0x80u) != 0u)
		{
			OBJECT(object)->screen_y -= 8u;
			OBJECT(object)->screen_x += OBJECT(object)->y_speed;
			if (OBJECT(object)->screen_y < 0x80u)
				OBJECT(object)->flags &= 0x7Fu;
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(48));
	if ((OBJECT(object - 0x50u)->flags & 0x80u) != 0u)
		return;
	start_box_opening();
	LAYER(WORKING_LAYER)->x = 0u;
	LAYER(LAYER_A)->x = 0u;
	LAYER(LAYER_B)->x = 0u;
	a6 = 0xA10Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	cutscene_step++;
}

/* the burning roof with the four turtles dropping onto it */
void intro_roof_start(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, d4 = 0, d5 = 0, d6 = 0, ignored = 0, ignored_2 = 0, object = 0;

	if (palettes_busy != 0u)
		return;
	io_write8(TILES_106B00, 0x30u);
	tile_banks_0_1 = 0x30u;
	LAYER(WORKING_LAYER)->map = layers_04618C_ADDRESS;
	LAYER(WORKING_LAYER)->blocks = 0x4628Cu;
	LAYER(WORKING_LAYER)->map_width = 0x20u;
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	a0 = 0x9C08u;
	start_palette_effect_lists(a0);
	object = OBJECT_ADDRESS(44);
	d4 = 0u;
	d5 = 0xB0u;
	d6 = 0x20u;
	do
	{
		OBJECT(object)->flags = 0x81u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->kind = d4;
		OBJECT(object)->height = 0xB000u;
		OBJECT(object)->screen_x = d5;
		OBJECT(object)->screen_y = 0x50u;
		OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | (d6 & 0xFFu);
		OBJECT(object)->shadow = 0x2E928u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		d0 = 0x203u;
		turtle_set_state(d0, object, &ignored, &d4, &d5, &d6, &ignored_2);
		d4 = (uint8_t)(d4 + 1u);
		d5 = (uint16_t)(d5 - 0xCu);
		d6 = (uint8_t)(d6 + 0x10u);
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(48));
	cutscene_step++;
}

/* the turtles land on the roof, Michelangelo trips, and they walk off into the fire */
void intro_roof_land(void)
{
	uint16_t d0 = 0;
	uint32_t animation = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, ignored_6 = 0, object = 0;
	uint8_t t1 = 0;
	uint16_t height = 0;

	grow_tile_box();
	intro_animate_fire(0u);
	turtles_on_the_way = 0u;
	object = OBJECT_ADDRESS(44);
	do
	{
		if ((OBJECT(object)->flags & 0x80u) != 0u)
		{
			turtles_on_the_way--;
			if ((uint8_t)OBJECT(object)->y_speed == 0u)
			{
				if (OBJECT(object)->height == 0u)
				{
					OBJECT(object)->contacts = 0u;
					OBJECT(object)->screen_x += 2u;
					if (OBJECT(object)->screen_x >= 0x158u)
						OBJECT(object)->flags &= 0x7Fu;
				}
				else
				{
					OBJECT(object)->contacts = 0u;
					OBJECT(object)->screen_x += 3u;
					if (OBJECT(object)->screen_x >= 0xE0u)
						OBJECT(object)->contacts = 0x80u;
					height = OBJECT(object)->height;
					OBJECT(object)->height = height - 0x600u;
					if (height < 0x600u)
					{
						OBJECT(object)->height = 0u;
						if (OBJECT(object)->kind == 1u)
						{
							OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | 0x40u;
							animation = 0x2DF32u;
							set_animation(ignored, object, animation);
						}
						else
						{
							OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | 0xCu;
							d0 = 0x200u;
							turtle_set_state(d0, object, &ignored, &ignored_3, &ignored_4, &ignored_5, &ignored_6);
						}
					}
				}
			}
			else
			{
				t1 = (uint8_t)OBJECT(object)->y_speed;
				OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | (t1 - 1u & 0xFFu);
				if (t1 == 1u && OBJECT(object)->height == 0u)
				{
					d0 = 0x100u;
					turtle_set_state(d0, object, &ignored, &ignored_3, &ignored_4, &ignored_5, &ignored_6);
				}
			}
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(48));
	if (turtles_on_the_way != 0u)
		return;
	intro_over--;
}

/* the fire and its smoke in the story's pictures, a new picture every eight frames */
uint32_t intro_animate_fire(uint32_t d0)
{
	uint8_t d1 = 0, d2 = 0;
	uint16_t d1_2 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint32_t a0 = 0, a6 = 0, d0_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;

	d0_2 = (d0 & ~0xFFu) | (uint8_t)frame_count;
	t1 = d0_2 & 7u;
	d0_2 = (d0_2 & ~0xFFu) | t1;
	if (t1 != 0u)
		return d0_2;
	cutscene_counter += 4u;
	if (cutscene_counter >= 0xCu)
		cutscene_counter = 0u;
	if (cutscene_step != 1u)
	{
		a6 = TABLE32(indexed_table_of_32_bit_values_031152, cutscene_counter);
		a6 = draw_tile_square_8x8(a6);
		a6 = draw_tile_square_8x8(a6);
		a6 = draw_tile_square_4x4(a6);
		a6 = draw_tile_square_4x4(a6);
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
	if (cutscene_counter == 0u)
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
					io_write8(a0, d0_2);
					a0++;
					io_write8(a0, d1);
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
	if (cutscene_counter != 4u)
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
			io_write8(a0, d0_2);
			a0++;
			io_write8(a0, d1);
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

/* a square of 8 by 8 tiles drawn, each row on from its first tile */
uint32_t draw_tile_square_8x8(uint32_t a6)
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

/* a square of 4 by 4 tiles drawn, each row on from its first tile */
uint32_t draw_tile_square_4x4(uint32_t a6)
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
