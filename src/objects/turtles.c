/**
 *    Name:        objects/turtles.c
 *    Description: the turtles: joining the game, the area's start and entry, and every turtle's frame: the controls, the moves and the scroll they push, the jumps, the attacks, the hits and the floor map's walls
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* a player who has just put a coin in comes into the game with full health, blinking, with its marker */
void turtle_join(uint8_t d7, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_a1)
{
	uint32_t carry = 0;
	uint8_t d6 = 0;
	uint16_t d0 = 0;
	uint32_t object = 0;

	object = OBJECT_ADDRESS(0);
	*p_a1 = OBJECT_ADDRESS(40);
	d0 = 0u;
	do
	{
		carry = d7 & 1u;
		d7 = (uint8_t)d7 >> 1;
		if (carry)
		{
			d6 = 0xFFu;
			turtle_init((uint8_t)d0, d6, p_d4, &object);
			OBJECT(object)->health_bars = 0xAu;
			OBJECT(object)->health = 3u;
			marker_times(d0) = 0x80u;
			turtle_start_marker(d0, p_d1, &object, p_a1);
			if (entry_without_blink == 0u)
				OBJECT(object)->unk_2C |= 0x80u;
		}
		d0 = (uint8_t)(d0 + 1u);
		*p_a1 += 0x50u;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
}

/* a player whose turtle was knocked out comes back at the start point with full health */
void turtle_respawn(uint8_t d7, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_a1)
{
	uint32_t carry = 0;
	uint8_t d6 = 0;
	uint16_t d0 = 0;
	uint32_t object = 0;

	object = OBJECT_ADDRESS(0);
	*p_a1 = OBJECT_ADDRESS(40);
	d0 = 0u;
	do
	{
		carry = d7 & 1u;
		d7 = (uint8_t)d7 >> 1;
		if (carry)
		{
			d6 = 0u;
			turtle_init((uint8_t)d0, d6, p_d4, &object);
			OBJECT(object)->health_bars = 0xAu;
			OBJECT(object)->health = 3u;
			marker_times(d0) = 0x80u;
			turtle_start_marker(d0, p_d1, &object, p_a1);
			if (entry_without_blink == 0u)
				OBJECT(object)->unk_2C |= 0x80u;
		}
		d0 = (uint8_t)(d0 + 1u);
		*p_a1 += 0x50u;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
}

/* every player's turtle starts the area with the health bars it had */
void turtle_start_area(uint8_t d7, uint32_t *p_d1, uint32_t *p_a1)
{
	uint32_t carry = 0;
	uint8_t d6 = 0;
	uint16_t d0 = 0;
	uint32_t a2 = 0, ignored = 0, object = 0;

	object = OBJECT_ADDRESS(0);
	*p_a1 = OBJECT_ADDRESS(40);
	a2 = unk_060106_ADDRESS;
	d0 = 0u;
	do
	{
		scratch = a2;
		carry = d7 & 1u;
		d7 = d7 >> 1;
		if (carry)
		{
			d6 = 0xFFu;
			turtle_init((uint8_t)d0, d6, &ignored, &object);
			a2 = scratch;
			if ((area_continues_scene & 0x80u) == 0u)
			{
				OBJECT(object)->health_bars = 0xAu;
				OBJECT(object)->health = 3u;
				mem_write16(a2, 0xA03u);
			}
			marker_times(d0) = 0x80u;
			turtle_start_marker(d0, p_d1, &object, p_a1);
			if (entry_without_blink == 0u)
				OBJECT(object)->unk_2C |= 0x80u;
		}
		d0 = (uint8_t)(d0 + 1u);
		object += 0x50u;
		a2 = scratch + 8u;
		*p_a1 += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	OBJECT(OBJECT_ADDRESS(0))->health_bars = PLAYER(PLAYER_ADDRESS(0))->health_bars;
	OBJECT(OBJECT_ADDRESS(1))->health_bars = PLAYER(PLAYER_ADDRESS(1))->health_bars;
	OBJECT(OBJECT_ADDRESS(2))->health_bars = PLAYER(PLAYER_ADDRESS(2))->health_bars;
	OBJECT(OBJECT_ADDRESS(3))->health_bars = PLAYER(PLAYER_ADDRESS(3))->health_bars;
}

/* a turtle's object set up for its player, invulnerable for a while, and placed by the area's entry */
void turtle_init(uint8_t d0, uint8_t d6, uint32_t *p_d4, uint32_t *p_a0)
{
	uint32_t a0 = *p_a0;
	uint16_t d2 = 0;
	uint32_t a6 = 0, d1 = 0, object = 0;
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
	object = a6;
	OBJECT(object)->turtle.prompt_time = 0x40u;
	area_entry_done = d1;
	OBJECT(object)->kind = d0;
	OBJECT(object)->flags = 0x81u;
	OBJECT(object)->contacts = 1u;
	OBJECT(object)->turtle.invulnerable_time = 0x7Fu;
	OBJECT(object)->depth = 4u;
	OBJECT(object)->shadow = 0x2E928u;
	OBJECT(object)->colour = 0xFFu;
	OBJECT(object)->animation_delay = 0u;
	cutscene_step = 0u;
	if ((uint8_t)d6 != 0u && scene == 4u && scene_step == 0u && scene_substep == 3u)
	{
		d1 = (uint16_t)((uint32_t)stage << 2);
		switch (d1)
		{
		case 0:
		case 4:
		case 20:
		case 24:
		case 32:
		case 36:
			turtle_place_at_start(d1, object);
			break;
		case 8:
		case 12:
		case 28:
			*p_d4 = turtle_start_fall_in(d1, object);
			break;
		case 16:
			turtle_jump_in_start(d1, p_d4, &object);
			break;
		}
	}
	else
		turtle_place_at_start(d1, object);
	*p_a0 = object;
}

/* the turtle at its start point, standing */
void turtle_place_at_start(uint32_t d1, uint32_t a0)
{
	uint32_t a6 = 0, d2 = 0, d3 = 0;

	a6 = indexed_table_of_16_bit_values_019E62_ADDRESS;
	if (stage == 3u)
		a6 = 0x19E72u;
	d1 = (uint16_t)(IN_PAGE(d1, OBJECT(a0)->kind) << 2);
	d2 = DATA16(a6 + d1);
	d3 = DATA16(a6 + 2u + d1);
	OBJECT(a0)->screen_x = d2;
	OBJECT(a0)->screen_y = d3;
	OBJECT(a0)->x = d2 << 8;
	OBJECT(a0)->y = d3 << 8;
	turtle_set_animation(d1, a0);
}

/* the turtle starts the area falling in from above */
uint32_t turtle_start_fall_in(uint32_t d1, uint32_t a0)
{
	uint32_t a6 = 0, d3 = 0, d4 = 0;

	a6 = 0x19E82u;
	if (stage == 3u)
		a6 = 0x19E9Au;
	d1 = (uint16_t)(IN_PAGE(d1, OBJECT(a0)->kind) << 1);
	d1 = (uint16_t)((d1 << 1) + d1);
	d3 = DATA16(a6 + d1);
	d4 = DATA16(a6 + 2u + d1);
	OBJECT(a0)->height = DATA16(a6 + 4u + d1);
	OBJECT(a0)->screen_x = d3;
	OBJECT(a0)->screen_y = d4;
	d4 = d4 << 8;
	OBJECT(a0)->x = d3 << 8;
	OBJECT(a0)->y = d4;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 3u;
	turtle_set_animation(d1, a0);
	return d4;
}

/* the turtle starts area 4 jumping in, and the object that comes in with them */
void turtle_jump_in_start(uint32_t d1, uint32_t *p_d4, uint32_t *p_a0)
{
	uint32_t a0 = *p_a0;
	uint32_t a0_2 = 0, a5 = 0, animation = 0, d3 = 0, d4 = 0, object = 0;

	d1 = (uint16_t)(IN_PAGE(d1, OBJECT(a0)->kind) << 1);
	d1 = (uint16_t)((d1 << 1) + d1);
	d3 = rom_019EB2[d1 / 2u];
	d4 = rom_019EB4[d1 / 2u];
	OBJECT(a0)->turtle_jump_in.jump_in_speed = rom_019EB6[d1 / 2u];
	OBJECT(a0)->screen_x = d3;
	OBJECT(a0)->screen_y = d4;
	d4 = (uint32_t)(int16_t)d4 << 8;
	OBJECT(a0)->x = d3 << 8;
	OBJECT(a0)->y = d4;
	OBJECT(a0)->turtle_jump_in.jump_speed = 0x800u;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 1u;
	turtle_set_animation(d1, a0);
	a5 = a0;
	object = OBJECT_ADDRESS(44);
	if ((OBJECT(OBJECT_ADDRESS(44))->flags & 1u) == 0u)
	{
		OBJECT(object)->flags = 0x81u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->screen_x = 0x60u;
		OBJECT(object)->screen_y = 0xFFC8u;
		OBJECT(object)->height = 0u;
		OBJECT(object)->x_speed = 0x800;
		OBJECT(object)->y_speed &= 0xFFu;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		animation = 0x2E1C0u;
		set_animation(d1, object, animation);
	}
	a0_2 = a5;
	*p_d4 = d4;
	*p_a0 = a0_2;
}

/* the player's marker object starts at the turtle's place */
void turtle_start_marker(uint16_t d0, uint32_t *p_d1, uint32_t *p_a0, uint32_t *p_a1)
{
	uint32_t a0 = *p_a0;
	uint32_t a1 = *p_a1;
	uint8_t d2 = 0;
	uint32_t a0_2 = 0, a1_2 = 0, a6 = 0, animation = 0, d1 = 0, object = 0;
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
	object = a6;
	OBJECT(object)->flags = 1u;
	OBJECT(object)->contacts = 0u;
	OBJECT(object)->screen_x = OBJECT(a0)->screen_x;
	OBJECT(object)->screen_y = OBJECT(a0)->screen_y;
	OBJECT(object)->height = OBJECT(a0)->height;
	OBJECT(object)->x = OBJECT(a0)->x;
	OBJECT(object)->y = OBJECT(a0)->y;
	OBJECT(object)->colour = 0xFFu;
	OBJECT(object)->animation_delay = 0u;
	d1 = d0;
	d1 = (uint16_t)(d1 << 2);
	animation = animations_019F24[d1 / 4u];
	saved_turtle = a0;
	a0_2 = object;
	d1 = set_animation(d1, a0_2, animation);
	a1_2 = a0_2;
	a0_2 = saved_turtle;
	*p_d1 = d1;
	*p_a0 = a0_2;
	*p_a1 = a1_2;
}

void run_area_entry(void)
{
	uint16_t d7 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, object = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	if (balloon_time != 0u)
	{
		t1 = balloon_time;
		balloon_time = t1 - 1u;
		if (t1 == 1u)
			erase_balloon(&ignored, &ignored_2, &ignored_3);
	}
	turtles_on_the_way = 0u;
	switch (stage)
	{
	case 0:
	case 1:
	case 5:
	case 6:
	case 8:
	case 9:
		area_entry_standing();
		break;
	case 2:
	case 3:
	case 7:
		area_entry_fall_in();
		break;
	case 4:
		area_entry_jump_in();
		break;
	}
	if (area_entry_done == 0u)
		return;
	object = OBJECT_ADDRESS(40);
	d7 = 3u;
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
			OBJECT(object)->flags = 0x81u;
		t2 = d7 - 1u;
		d7 = t2;
		object += 0x50u;
	} while (t2 != 0xFFFFu);
}

void area_entry_standing(void)
{
	area_entry_done = 0xFFu;
	start_area_layers();
}

void area_entry_fall_in(void)
{
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)cutscene_step << 2);
	switch (d0)
	{
	case 0:
		start_fall_in_entry();
		return;
	case 4:
		turtle_fall_in(d0);
		return;
	}
}

void start_fall_in_entry(void)
{
	uint32_t a0 = 0, animation = 0;

	start_area_layers();
	if (stage == 7u)
	{
		a0 = OBJECT_ADDRESS(44);
		OBJECT(OBJECT_ADDRESS(44))->flags = 0x81u;
		OBJECT(OBJECT_ADDRESS(44))->contacts = 0u;
		OBJECT(OBJECT_ADDRESS(44))->height = 0u;
		OBJECT(OBJECT_ADDRESS(44))->colour = 0xFFu;
		OBJECT(OBJECT_ADDRESS(44))->animation_delay = 0u;
		OBJECT(OBJECT_ADDRESS(44))->screen_x = 0x40u;
		OBJECT(OBJECT_ADDRESS(44))->screen_y = 0x38u;
		animation = 0x2E0ECu;
		set_animation(0u, a0, animation);
	}
	cutscene_step++;
}

/* every frame of the entry: the turtles fall in across, land, wait and stand */
void turtle_fall_in(uint32_t d0)
{
	uint8_t d7 = 0;
	uint16_t screen_y = 0;
	uint32_t d1 = 0, object = 0;
	uint8_t t1 = 0;
	uint16_t height = 0;

	if (stage != 7u || OBJECT(OBJECT_ADDRESS(44))->screen_x >= 0x120u)
	{
		object = OBJECT_ADDRESS(0);
		do
		{
			if ((OBJECT(object)->flags & 1u) != 0u)
			{
				if (OBJECT(object)->height == 0u)
				{
					if (OBJECT(object)->routine != 0u)
					{
						turtles_on_the_way--;
						t1 = (uint8_t)OBJECT(object)->y_speed;
						OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | (t1 - 1u & 0xFFu);
						if (t1 == 1u)
						{
							OBJECT(object)->routine = 0u;
							turtle_set_animation(d1, object);
						}
					}
					else if (stage == 7u && balloons_said == 0u)
					{
						d0 &= ~0xFFu;
						d1 = OBJECT(object)->screen_x;
						screen_y = OBJECT(object)->screen_y;
						d0 = say_we_gotta_save_splinter(d0, d1, screen_y);
					}
				}
				else
				{
					turtles_on_the_way--;
					OBJECT(object)->x += 0x300u;
					OBJECT(object)->screen_x = OBJECT(object)->x >> 8;
					height = OBJECT(object)->height;
					OBJECT(object)->height = height - 0x600u;
					if (height < 0x600u)
					{
						OBJECT(object)->height = 0u;
						OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | 0x8u;
						OBJECT(object)->state = 0u;
						turtle_set_animation(d1, object);
					}
				}
			}
			object += 0x50u;
		} while (object < OBJECT_ADDRESS(4));
	}
	object = OBJECT_ADDRESS(44);
	if (OBJECT(OBJECT_ADDRESS(44))->flags == 0u)
	{
		if (turtles_on_the_way != 0u)
			return;
		area_entry_done = 0xFFu;
		return;
	}
	if ((frame_count & 0x1Fu) == 0u)
	{
		d7 = 0x39u;
		queue_sound(d7, 0u);
	}
	OBJECT(object)->screen_x += 2u;
	if (OBJECT(object)->screen_x < 0x1C0u)
		return;
	OBJECT(object)->flags = 0u;
}

void area_entry_jump_in(void)
{
	switch (cutscene_step)
	{
	case 0:
		start_jump_in_entry();
		return;
	case 1:
		turtle_jump_in_step();
		return;
	}
}

void start_jump_in_entry(void)
{
	start_area_layers();
	cutscene_step++;
}

/* every frame of area 4's entry: the object that came with them bounces away, the turtles jump in, land
   and stand */
void turtle_jump_in_step(void)
{
	uint16_t d2 = 0;
	uint32_t d1 = 0, kind = 0, object = 0;
	uint8_t t1 = 0;
	uint16_t x_speed = 0, height = 0, x_speed_2 = 0;

	object = OBJECT_ADDRESS(44);
	if ((OBJECT(OBJECT_ADDRESS(44))->flags & 1u) != 0u)
	{
		OBJECT(object)->screen_x--;
		if ((uint8_t)(OBJECT(object)->y_speed >> 8u) != 0u)
		{
			OBJECT(object)->y -= OBJECT(object)->x_speed;
			OBJECT(object)->x_speed += 0x20u;
		}
		else
		{
			OBJECT(object)->y += OBJECT(object)->x_speed;
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = x_speed - 0x40u;
			if (x_speed < 0x40u)
			{
				OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFFu) | (((uint8_t)(OBJECT(object)->y_speed >> 8u) - 1u & 0xFFu) << 8u);
				OBJECT(object)->x_speed = 0u - OBJECT(object)->x_speed;
			}
		}
	}
	OBJECT(object)->screen_y = OBJECT(object)->y >> 8;
	if (OBJECT(object)->screen_x < 0x28u)
		OBJECT(object)->flags = 0u;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			if ((uint8_t)OBJECT(object)->y_speed == 0u)
			{
				if ((OBJECT(object)->routine | OBJECT(object)->state) != 0u)
				{
					turtles_on_the_way--;
					if ((uint8_t)(OBJECT(object)->y_speed >> 8u) != 0u)
					{
						OBJECT(object)->x_speed += 0x50u;
						d1 = (uint16_t)OBJECT(object)->x_speed;
						height = OBJECT(object)->height;
						OBJECT(object)->height = height - d1;
						if (height < d1)
						{
							OBJECT(object)->height = 0u;
							OBJECT(object)->state = 0u;
							turtle_set_animation(d1, object);
							OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | 0x8u;
						}
					}
					else
					{
						OBJECT(object)->height += OBJECT(object)->x_speed;
						if (OBJECT(object)->height >= 0x3800u && (int8_t)(uint8_t)(OBJECT(object)->y >> 24u) < 0)
						{
							OBJECT(object)->height -= 0x3800u;
							OBJECT(object)->y = 0u;
							OBJECT(object)->contacts |= 0x80u;
						}
						x_speed_2 = OBJECT(object)->x_speed;
						OBJECT(object)->x_speed = x_speed_2 - 0x20u;
						if (x_speed_2 < 0x20u)
						{
							kind = OBJECT(object)->kind;
							d1 = indexed_table_of_8_bit_values_01A2D2[kind];
							OBJECT(object)->screen_y = d1;
							d1 = (uint16_t)(d1 << 8);
							OBJECT(object)->height -= d1;
							OBJECT(object)->y = d1;
							OBJECT(object)->x_speed = 0u - OBJECT(object)->x_speed;
							OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFFu) | (((uint8_t)(OBJECT(object)->y_speed >> 8u) - 1u & 0xFFu) << 8u);
						}
					}
					OBJECT(object)->x += OBJECT(object)->height_speed;
					d2 = (uint16_t)(OBJECT(object)->y >> 8);
					OBJECT(object)->screen_x = OBJECT(object)->x >> 8;
					OBJECT(object)->screen_y = d2;
				}
			}
			else
			{
				turtles_on_the_way--;
				t1 = (uint8_t)OBJECT(object)->y_speed;
				OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | (t1 - 1u & 0xFFu);
				if (t1 == 1u)
				{
					OBJECT(object)->routine = 0u;
					OBJECT(object)->state = 0u;
					turtle_set_animation(d1, object);
				}
			}
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	if (turtles_on_the_way != 0u)
		return;
	area_entry_done = 0xFFu;
	OBJECT(OBJECT_ADDRESS(44))->flags = 0u;
}

/* on the skateboard the turtles' shadows change every four frames */
uint32_t turtle_skateboard_shadow(void)
{
	uint16_t d0 = 0;
	uint32_t a6 = 0, object = 0;

	object = OBJECT_ADDRESS(0);
	a6 = indexed_table_of_32_bit_values_01A308_ADDRESS;
	do
	{
		d0 = 0u;
		if ((frame_count & 4u) != 0u)
			d0 = 4u;
		OBJECT(object)->shadow = DATA32(a6 + d0);
		object += 0x50u;
		a6 += 8u;
	} while (object < OBJECT_ADDRESS(4));
	return object;
}

void update_players(uint32_t d1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0, object = 0, object_2 = 0;
	uint8_t t1 = 0;
	uint32_t height_long = 0;

	object = OBJECT_ADDRESS(0);
	object_2 = OBJECT_ADDRESS(40);
	a6 = marker_times_ADDRESS;
	do
	{
		if (mem_read8(a6) != 0u)
		{
			OBJECT(object_2)->screen_x = OBJECT(object)->screen_x;
			OBJECT(object_2)->screen_y = OBJECT(object)->screen_y;
			height_long = (((uint32_t)OBJECT(object)->height << 16u) | (OBJECT(object)->x >> 16u));
			OBJECT(object_2)->height = (uint16_t)(height_long >> 16u);
			OBJECT(object_2)->x = (OBJECT(object_2)->x & 0xFFFFu) | ((height_long & 0xFFFFu) << 16u);
			t1 = mem_read8(a6);
			mem_write8(a6, t1 - 1u);
			if (t1 == 1u)
				OBJECT(object_2)->flags = 0u;
		}
		a6++;
		object += 0x50u;
		object_2 += 0x50u;
	} while (a6 < time_since_balloon_ADDRESS);
	PLAYER(PLAYER_ADDRESS(0))->health_bars = OBJECT(OBJECT_ADDRESS(0))->health_bars;
	PLAYER(PLAYER_ADDRESS(1))->health_bars = OBJECT(OBJECT_ADDRESS(1))->health_bars;
	PLAYER(PLAYER_ADDRESS(2))->health_bars = OBJECT(OBJECT_ADDRESS(2))->health_bars;
	PLAYER(PLAYER_ADDRESS(3))->health_bars = OBJECT(OBJECT_ADDRESS(3))->health_bars;
	if (indexed_table_of_8_bit_values_01A3C0[stage] != 0u)
	{
		load_layer_b();
		turtle_run_all(d1, &d5, p_d7, p_a1);
		save_layer_b();
	}
	else
	{
		load_layer_a();
		turtle_run_all(d1, &d5, p_d7, p_a1);
		save_layer_a();
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* every turtle in play a frame: controls, move, the screen's limits, the scroll, floor and walls */
void turtle_run_all(uint32_t d1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint8_t d0_2 = 0, d1_2 = 0;
	uint16_t d0_3 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, d0 = 0, object = 0, x_speed = 0, y_speed = 0;
	uint8_t routine = 0, t1 = 0;
	uint32_t y = 0;

	diagonal_scroll = 0;
	if (stage == 2u && scroll_segment == 4u)
	{
		diagonal_scroll--;
		if (LAYER(LAYER_B)->y < 0x1C000u)
			scroll_held_right = 0xFFu;
	}
	d0 = 0u;
	LAYER(WORKING_LAYER)->new_row = 0u;
	LAYER(WORKING_LAYER)->new_column = 0u;
	LAYER(LAYER_A)->new_row = 0u;
	LAYER(LAYER_A)->new_column = 0u;
	LAYER(LAYER_B)->new_row = 0u;
	LAYER(LAYER_B)->new_column = 0u;
	turtles_busy = 0u;
	if (scroll_mode >= 0)
	{
		LAYER(WORKING_LAYER)->y_direction = (uint8_t)(d0 >> 8u);
		LAYER(WORKING_LAYER)->x_direction = (uint8_t)d0;
		LAYER(WORKING_LAYER)->x_speed = (uint16_t)(d0 >> 16u);
		LAYER(WORKING_LAYER)->y_speed = (uint16_t)d0;
	}
	object = OBJECT_ADDRESS(0);
	a1 = turtle_inputs_ADDRESS;
	a2 = turtle_presses_ADDRESS;
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			turtle_control(0u, object, a1, a2, &d1, &d5, &d7);
			d1 = turtle_move(d1, object, a1);
			if (OBJECT(object)->kind == 3u && (((uint32_t)OBJECT(object)->routine << 8u) | OBJECT(object)->state) == 0x307u)
				OBJECT(object)->contacts |= 0x80u;
			if (stage != 8u || scroll_mode >= 0)
			{
				if (OBJECT(object)->x >= 0x9000u)
				{
					if (OBJECT(object)->x >= 0x16000u)
						OBJECT(object)->x = 0x16000u;
				}
				else
					OBJECT(object)->x = 0x9000u;
				if (OBJECT(object)->y >= reset_ADDRESS)
				{
					if (OBJECT(object)->y >= 0xA000u)
						OBJECT(object)->y = 0xA000u;
				}
				else
					OBJECT(object)->y = reset_ADDRESS;
				if ((int8_t)OBJECT(object)->height_whole < 0)
				{
					routine = OBJECT(object)->routine;
					d0_2 = (uint8_t)(routine - 2u);
					if (routine < 2u || d0_2 >= 3u)
					{
						OBJECT(object)->height = 0u;
						OBJECT(object)->floor_height = 0u;
					}
				}
			}
			else
			{
				if (OBJECT(object)->x >= 0x18800u)
					OBJECT(object)->x = 0x18800u;
				y = OBJECT(object)->y;
				d0 = y - 0x1000u;
				if (y < 0x1000u)
					d0 = 0u;
				d1 = d0 + 0x13000u;
				d0 += 0x8000u;
				if (OBJECT(object)->x <= d0)
					OBJECT(object)->x = d0;
				if (d1 < OBJECT(object)->x)
					OBJECT(object)->x = d1;
			}
		}
		a2++;
		object += 0x50u;
		a1++;
	} while (object < OBJECT_ADDRESS(4));
	if (stage == 6u)
		object = turtle_skateboard_shadow();
	auto_scroll(d1, object);
	object = OBJECT_ADDRESS(0);
	a1 = turtle_inputs_ADDRESS;
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			if (scroll_mode >= 0)
			{
				x_speed = LAYER(WORKING_LAYER)->x_speed;
				y_speed = LAYER(WORKING_LAYER)->y_speed;
				if ((OBJECT(object)->parameter & 0x7Fu) == 0u && (uint8_t)LAYER(WORKING_LAYER)->x_direction != 0u)
				{
					if (LAYER(WORKING_LAYER)->x_direction < 0)
						OBJECT(object)->x -= x_speed;
					else
						OBJECT(object)->x += x_speed;
				}
				if ((int8_t)OBJECT(object)->parameter >= 0 && (uint8_t)LAYER(WORKING_LAYER)->y_direction != 0u)
				{
					if (LAYER(WORKING_LAYER)->y_direction >= 0)
						OBJECT(object)->y -= y_speed;
					else
						OBJECT(object)->y += y_speed;
				}
			}
			OBJECT(object)->screen_x = (OBJECT(object)->screen_x & 0xFFu) | (((uint8_t)(OBJECT(object)->x >> 16u) & 0xFFu) << 8u);
			OBJECT(object)->screen_x = (OBJECT(object)->screen_x & 0xFF00u) | ((uint8_t)(OBJECT(object)->x >> 8u) & 0xFFu);
			OBJECT(object)->screen_y = (OBJECT(object)->screen_y & 0xFFu) | (((uint8_t)(OBJECT(object)->y >> 16u) & 0xFFu) << 8u);
			OBJECT(object)->screen_y = (OBJECT(object)->screen_y & 0xFF00u) | ((uint8_t)(OBJECT(object)->y >> 8u) & 0xFFu);
			if (stage == 8u)
			{
				save_layer_b();
				load_layer_a();
				turtle_collide(object, a1, &d5, &d7);
				save_layer_a();
				load_layer_b();
			}
			else
				turtle_collide(object, a1, &d5, &d7);
		}
		if (OBJECT(object)->kind == 3u && OBJECT(object)->state == 7u)
			OBJECT(object)->contacts |= 0x80u;
		OBJECT(object)->screen_x = (OBJECT(object)->screen_x & 0xFFu) | (((uint8_t)(OBJECT(object)->x >> 16u) & 0xFFu) << 8u);
		OBJECT(object)->screen_x = (OBJECT(object)->screen_x & 0xFF00u) | ((uint8_t)(OBJECT(object)->x >> 8u) & 0xFFu);
		OBJECT(object)->screen_y = (OBJECT(object)->screen_y & 0xFFu) | (((uint8_t)(OBJECT(object)->y >> 16u) & 0xFFu) << 8u);
		OBJECT(object)->screen_y = (OBJECT(object)->screen_y & 0xFF00u) | ((uint8_t)(OBJECT(object)->y >> 8u) & 0xFFu);
		object += 0x50u;
		a1++;
	} while (object < OBJECT_ADDRESS(4));
	if (last_segment == 0u)
	{
		d0_3 = stage;
		a0 = mem_read32(area_scroll_segments[(uint8_t)((uint32_t)d0_3 << 2) / 4u] + (int16_t)scroll_segment);
		if (mem_read8(a0) != 0u)
		{
			d0 = LAYER(WORKING_LAYER)->x;
			t1 = mem_read8(a0 + 1u);
			d1_2 = t1;
			if ((int8_t)t1 < 0)
				d0 = LAYER(WORKING_LAYER)->y;
			if ((d1_2 & 0x7Fu) != 0u)
			{
				if (d0 < mem_read32(a0 + 2u))
				{
					scroll_segment += 4u;
					d7 = start_scroll_segment(d7);
				}
			}
			else if (mem_read32(a0 + 2u) <= d0)
			{
				scroll_segment += 4u;
				d7 = start_scroll_segment(d7);
			}
		}
	}
	else
	{
		d7 = check_area_cleared(d7);
		if (area_beaten != 0u && turtles_busy == 0u)
			area_cleared--;
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
	*p_a1 = a1;
}

/* the turtle against solid objects, the floor map and its walls, and falling when nothing holds it */
void turtle_collide(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d5 = 0, d7 = 0;
	uint8_t height_whole = 0;
	uint16_t height = 0;
	uint32_t y = 0;

	if (OBJECT(a0)->routine == 4u)
	{
		d0 = 2u;
		if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
			d0 = 1u;
		mem_write8(a1, d0);
	}
	else if (OBJECT(a0)->routine == 3u && (OBJECT(a0)->state >= 9u || (OBJECT(a0)->kind == 3u && OBJECT(a0)->state == 7u)))
	{
		d0 = 2u;
		if ((OBJECT(a0)->flags & 0x40u) == 0u)
			mem_write8(a1, d0);
		else
		{
			d0 = 1u;
			mem_write8(a1, d0);
		}
	}
	turtle_collide_with_objects(a0);
	read_floor_cells(a0, &d5, &d7, &a6);
	d0 = (uint8_t)(OBJECT(a0)->y >> 8u);
	height_whole = OBJECT(a0)->height_whole;
	carry = (uint8_t)(d0 + height_whole) < d0;
	d0 += height_whole;
	if (carry || d0 >= 0xF8u)
	{
		OBJECT(a0)->contacts = 0x86u;
		if (stage != 5u && (OBJECT(a0)->flags & 0x10u) == 0u && ((int8_t)floor_cell_right < 0 || (int8_t)floor_cell_left < 0))
			OBJECT(a0)->contacts = 0xFEu;
	}
	else
		turtle_check_walls(a0, a1, a6);
	if ((OBJECT(a0)->contacts & 1u) == 0u && OBJECT(a0)->routine != 2u && OBJECT(a0)->routine != 4u)
	{
		if (OBJECT(a0)->height != 0u)
		{
			height = OBJECT(a0)->height;
			OBJECT(a0)->height = height - 0x400u;
			if (height < 0x400u)
			{
				OBJECT(a0)->height = 0u;
				d7 = (d7 & ~0xFFu) | 0x12u;
				if (stage == 3u)
					d7 = (d7 & ~0xFFu) | 0x30u;
				queue_sound((uint8_t)d7, a6);
			}
			else if (OBJECT(a0)->height_whole < OBJECT(a0)->floor_height)
			{
				if (OBJECT(a0)->floor_height >= 0x60u)
					OBJECT(a0)->floor_height = 0u;
				OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
				OBJECT(a0)->height &= 0xFF00u;
				if ((OBJECT(a0)->contacts & 0x80u) != 0u)
				{
					d7 = (d7 & ~0xFFu) | 0x12u;
					if (stage != 3u || OBJECT(a0)->height != 0u)
						queue_sound((uint8_t)d7, a6);
					else
					{
						d7 = (d7 & ~0xFFu) | 0x30u;
						queue_sound((uint8_t)d7, a6);
					}
				}
			}
		}
		else
		{
			y = OBJECT(a0)->y;
			OBJECT(a0)->y = y - 0x400u;
			if (y < 0x400u)
			{
				OBJECT(a0)->height = 0u;
				d7 = (d7 & ~0xFFu) | 0x12u;
				if (stage == 3u)
					d7 = (d7 & ~0xFFu) | 0x30u;
				queue_sound((uint8_t)d7, a6);
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void unreached_01AC7E(uint32_t a0)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	read_floor_cells(a0, &ignored, &ignored_2, &ignored_3);
}

/* the walls around the turtle checked by the way its stick pushes */
void turtle_check_walls(uint32_t a0, uint32_t a1, uint32_t a6)
{
	switch ((uint16_t)((mem_read8(a1) & 0xFu) << 2))
	{
	case 0:
		turtle_walls_still(a0, a6);
		return;
	case 16:
		turtle_walls_up(a0, a6);
		return;
	case 12:
	case 32:
		turtle_walls_down(a0, a6);
		return;
	case 8:
		turtle_walls_right(a0, a6);
		return;
	case 4:
		turtle_walls_left(a0, a6);
		return;
	case 20:
		turtle_walls_up_left(a0, a6);
		return;
	case 24:
	case 28:
		turtle_walls_up_right(a0, a6);
		return;
	case 40:
	case 44:
	case 48:
	case 52:
	case 56:
	case 60:
		turtle_walls_down_right(a0, a6);
		return;
	case 36:
		turtle_walls_down_left(a0, a6);
		return;
	}
}

/* the stick moves the turtle across and up or down, or pushes the scroll at the screen's edges */
uint32_t turtle_move(uint32_t d1, uint32_t a0, uint32_t a1)
{
	bool L_01AE2C = false, L_01AEA8 = false, L_01AFD4 = false, L_01B012 = false, L_01B086 = false;
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d0_2 = 0, d2 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t column_phase = 0, x_speed = 0, column_phase_2 = 0, column_phase_3 = 0, x_speed_2 = 0, column_phase_4 = 0, row_phase = 0, y_speed = 0, row_phase_2 = 0, row_phase_3 = 0, row_phase_4 = 0, y_speed_2 = 0;

	OBJECT(a0)->turtle.scroll_push = 0u;
	t1 = mem_read8(a1) & 3u;
	d0 = t1;
	if (t1 != 0u)
	{
		if ((d0 & 1u) == 0u)
		{
			OBJECT(a0)->flags &= 0xBFu;
			if (scroll_mode >= 0)
			{
				if ((uint8_t)LAYER(WORKING_LAYER)->x_direction != 0u)
				{
					turtle_walk_speed(a0, a1, &d0_2, &a6);
					d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
					if ((mem_read8(a1) & 0xFu) != 0xAu)
					{
						if ((OBJECT(a0)->contacts & 8u) == 0u)
						{
							d1 &= 0xFFFFu;
							OBJECT(a0)->x += d1;
						}
					}
					else if ((OBJECT(a0)->contacts & 0x28u) == 0u)
					{
						d1 &= 0xFFFFu;
						OBJECT(a0)->x += d1;
					}
				}
				else
				{
					do
					{
						if (L_01AFD4 || (uint8_t)diagonal_scroll == 0u)
						{
							if (!L_01AFD4 && OBJECT(a0)->x < 0x12000u)
							{
								turtle_walk_speed(a0, a1, &d0_2, &a6);
								d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
								if ((mem_read8(a1) & 0xFu) != 0xAu)
								{
									if ((OBJECT(a0)->contacts & 8u) == 0u)
									{
										d1 &= 0xFFFFu;
										OBJECT(a0)->x += d1;
									}
								}
								else if ((OBJECT(a0)->contacts & 0x28u) == 0u)
								{
									d1 &= 0xFFFFu;
									OBJECT(a0)->x += d1;
								}
							}
							else
							{
								L_01AFD4 = false;
								if (OBJECT(a0)->x >= 0x16000u)
								{
									do
									{
										if (L_01B086 || (mem_read8(a1) & 0xFu) != 0xAu)
										{
											if (L_01B086 || (OBJECT(a0)->contacts & 8u) == 0u)
											{
												L_01B086 = false;
												if (scroll_held_right == 0u)
												{
													d0 = 0x7Fu;
													turtle_other_at_edge(d0, a0, &d1, &carry);
													if (carry == 0u)
													{
														turtle_push_scroll_right(a0, a1, &d0_2, &d1, &d2, &carry);
														if (carry)
														{
															LAYER(WORKING_LAYER)->x = d2;
															LAYER(WORKING_LAYER)->x_speed = 0u;
															LAYER(WORKING_LAYER)->column_phase = 0u;
															LAYER(WORKING_LAYER)->x_direction = 0;
														}
														else
														{
															column_phase = LAYER(WORKING_LAYER)->column_phase;
															carry = (uint16_t)(column_phase + d1) < column_phase;
															LAYER(WORKING_LAYER)->column_phase = column_phase + d1;
															if (carry)
															{
																LAYER(WORKING_LAYER)->new_column_x = d0_2;
																LAYER(WORKING_LAYER)->new_column--;
															}
														}
													}
												}
											}
										}
										else
											L_01B086 = (OBJECT(a0)->contacts & 0x28u) == 0u;
									} while (L_01B086);
								}
								else if (scroll_held_right != 0u)
								{
									turtle_walk_speed(a0, a1, &d0_2, &a6);
									d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
									if ((mem_read8(a1) & 0xFu) != 0xAu)
									{
										if ((OBJECT(a0)->contacts & 8u) == 0u)
										{
											d1 &= 0xFFFFu;
											OBJECT(a0)->x += d1;
										}
									}
									else if ((OBJECT(a0)->contacts & 0x28u) == 0u)
									{
										d1 &= 0xFFFFu;
										OBJECT(a0)->x += d1;
									}
								}
								else
								{
									do
									{
										if (L_01B012 || (mem_read8(a1) & 0xFu) != 0xAu)
										{
											if (L_01B012 || (OBJECT(a0)->contacts & 8u) == 0u)
											{
												L_01B012 = false;
												d0 = 0x7Fu;
												turtle_other_at_edge(d0, a0, &d1, &carry);
												if (carry)
												{
													turtle_walk_speed(a0, a1, &d0_2, &a6);
													d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
													if ((mem_read8(a1) & 0xFu) != 0xAu)
													{
														if ((OBJECT(a0)->contacts & 8u) == 0u)
														{
															d1 &= 0xFFFFu;
															OBJECT(a0)->x += d1;
														}
													}
													else if ((OBJECT(a0)->contacts & 0x28u) == 0u)
													{
														d1 &= 0xFFFFu;
														OBJECT(a0)->x += d1;
													}
												}
												else
												{
													turtle_push_scroll_right(a0, a1, &d0_2, &d1, &d2, &carry);
													if (carry)
													{
														d0_2 = LAYER(WORKING_LAYER)->x - d2;
														d1 = d0_2;
														d0_2 = (d0_2 << 16) | (d0_2 >> 16);
														x_speed = LAYER(WORKING_LAYER)->x_speed;
														LAYER(WORKING_LAYER)->x_speed = x_speed - d1;
														if (x_speed == (uint16_t)d1)
															LAYER(WORKING_LAYER)->x_direction = d0_2;
														LAYER(WORKING_LAYER)->x = d2;
														LAYER(WORKING_LAYER)->column_phase = d0_2;
														if ((mem_read8(a1) & 0xFu) != 0xAu)
														{
															if ((OBJECT(a0)->contacts & 8u) == 0u)
															{
																d1 &= 0xFFFFu;
																OBJECT(a0)->x += d1;
															}
														}
														else if ((OBJECT(a0)->contacts & 0x28u) == 0u)
														{
															d1 &= 0xFFFFu;
															OBJECT(a0)->x += d1;
														}
													}
													else
													{
														column_phase_2 = LAYER(WORKING_LAYER)->column_phase;
														carry = (uint16_t)(column_phase_2 + d1) < column_phase_2;
														LAYER(WORKING_LAYER)->column_phase = column_phase_2 + d1;
														if (carry)
														{
															LAYER(WORKING_LAYER)->new_column_x = d0_2;
															LAYER(WORKING_LAYER)->new_column--;
														}
													}
												}
											}
										}
										else
											L_01B012 = (OBJECT(a0)->contacts & 0x28u) == 0u;
									} while (L_01B012);
								}
							}
						}
						else
						{
							L_01AFD4 = OBJECT(a0)->x >= 0x15800u;
							if (!L_01AFD4)
							{
								turtle_walk_speed(a0, a1, &d0_2, &a6);
								d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
								if ((mem_read8(a1) & 0xFu) != 0xAu)
								{
									if ((OBJECT(a0)->contacts & 8u) == 0u)
									{
										d1 &= 0xFFFFu;
										OBJECT(a0)->x += d1;
									}
								}
								else if ((OBJECT(a0)->contacts & 0x28u) == 0u)
								{
									d1 &= 0xFFFFu;
									OBJECT(a0)->x += d1;
								}
							}
						}
					} while (L_01AFD4);
				}
			}
			else if (stage == 8u || OBJECT(a0)->x < 0x16000u)
			{
				turtle_walk_speed(a0, a1, &d0_2, &a6);
				d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
				if ((mem_read8(a1) & 0xFu) != 0xAu)
				{
					if ((OBJECT(a0)->contacts & 8u) == 0u)
					{
						d1 &= 0xFFFFu;
						OBJECT(a0)->x += d1;
					}
				}
				else if ((OBJECT(a0)->contacts & 0x28u) == 0u)
				{
					d1 &= 0xFFFFu;
					OBJECT(a0)->x += d1;
				}
			}
		}
		else
		{
			OBJECT(a0)->flags |= 0x40u;
			if (scroll_mode >= 0)
			{
				if ((uint8_t)LAYER(WORKING_LAYER)->x_direction != 0u || OBJECT(a0)->x >= 0xE000u)
				{
					turtle_walk_speed(a0, a1, &d0_2, &a6);
					d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
					if ((mem_read8(a1) & 0xFu) != 9u)
					{
						if ((OBJECT(a0)->contacts & 0x10u) == 0u)
						{
							d1 &= 0xFFFFu;
							OBJECT(a0)->x -= d1;
						}
					}
					else if ((OBJECT(a0)->contacts & 0x50u) == 0u)
					{
						d1 &= 0xFFFFu;
						OBJECT(a0)->x -= d1;
					}
				}
				else if (OBJECT(a0)->x < 0x9100u)
				{
					do
					{
						if (L_01AEA8 || (mem_read8(a1) & 0xFu) != 9u)
						{
							if (L_01AEA8 || (OBJECT(a0)->contacts & 0x10u) == 0u)
							{
								L_01AEA8 = false;
								if (scroll_held_left == 0u)
								{
									d0 = 0u;
									turtle_other_at_edge(d0, a0, &d1, &carry);
									if (carry == 0u)
									{
										turtle_push_scroll_left(a0, a1, &d0_2, &d1, &carry);
										if (carry)
										{
											LAYER(WORKING_LAYER)->x = LAYER(WORKING_LAYER)->x_min;
											LAYER(WORKING_LAYER)->x_speed = 0u;
											LAYER(WORKING_LAYER)->column_phase = 0u;
											LAYER(WORKING_LAYER)->x_direction = 0;
										}
										else
										{
											column_phase_3 = LAYER(WORKING_LAYER)->column_phase;
											LAYER(WORKING_LAYER)->column_phase = column_phase_3 - d1;
											if (column_phase_3 < (uint16_t)d1)
											{
												LAYER(WORKING_LAYER)->new_column_x = d0_2;
												LAYER(WORKING_LAYER)->new_column--;
											}
										}
									}
								}
							}
						}
						else
							L_01AEA8 = (OBJECT(a0)->contacts & 0x50u) == 0u;
					} while (L_01AEA8);
				}
				else if (scroll_held_left != 0u)
				{
					turtle_walk_speed(a0, a1, &d0_2, &a6);
					d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
					if ((mem_read8(a1) & 0xFu) != 9u)
					{
						if ((OBJECT(a0)->contacts & 0x10u) == 0u)
						{
							d1 &= 0xFFFFu;
							OBJECT(a0)->x -= d1;
						}
					}
					else if ((OBJECT(a0)->contacts & 0x50u) == 0u)
					{
						d1 &= 0xFFFFu;
						OBJECT(a0)->x -= d1;
					}
				}
				else
				{
					do
					{
						if (L_01AE2C || (mem_read8(a1) & 0xFu) != 9u)
						{
							if (L_01AE2C || (OBJECT(a0)->contacts & 0x10u) == 0u)
							{
								L_01AE2C = false;
								d0 = 0u;
								turtle_other_at_edge(d0, a0, &d1, &carry);
								if (carry)
								{
									turtle_walk_speed(a0, a1, &d0_2, &a6);
									d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
									if ((mem_read8(a1) & 0xFu) != 9u)
									{
										if ((OBJECT(a0)->contacts & 0x10u) == 0u)
										{
											d1 &= 0xFFFFu;
											OBJECT(a0)->x -= d1;
										}
									}
									else if ((OBJECT(a0)->contacts & 0x50u) == 0u)
									{
										d1 &= 0xFFFFu;
										OBJECT(a0)->x -= d1;
									}
								}
								else
								{
									turtle_push_scroll_left(a0, a1, &d0_2, &d1, &carry);
									if (carry)
									{
										d1 = (d1 & ~0xFFFFu) | (uint16_t)(LAYER(WORKING_LAYER)->x_min - LAYER(WORKING_LAYER)->x);
										x_speed_2 = LAYER(WORKING_LAYER)->x_speed;
										LAYER(WORKING_LAYER)->x_speed = x_speed_2 - d1;
										if (x_speed_2 == (uint16_t)d1)
											LAYER(WORKING_LAYER)->x_direction = 0;
										LAYER(WORKING_LAYER)->x = LAYER(WORKING_LAYER)->x_min;
										LAYER(WORKING_LAYER)->column_phase = 0u;
										if ((mem_read8(a1) & 0xFu) != 9u)
										{
											if ((OBJECT(a0)->contacts & 0x10u) == 0u)
											{
												d1 &= 0xFFFFu;
												OBJECT(a0)->x -= d1;
											}
										}
										else if ((OBJECT(a0)->contacts & 0x50u) == 0u)
										{
											d1 &= 0xFFFFu;
											OBJECT(a0)->x -= d1;
										}
									}
									else
									{
										column_phase_4 = LAYER(WORKING_LAYER)->column_phase;
										LAYER(WORKING_LAYER)->column_phase = column_phase_4 - d1;
										if (column_phase_4 < (uint16_t)d1)
										{
											LAYER(WORKING_LAYER)->new_column_x = d0_2;
											LAYER(WORKING_LAYER)->new_column--;
										}
									}
								}
							}
						}
						else
							L_01AE2C = (OBJECT(a0)->contacts & 0x50u) == 0u;
					} while (L_01AE2C);
				}
			}
			else if (OBJECT(a0)->x >= 0x9000u)
			{
				turtle_walk_speed(a0, a1, &d0_2, &a6);
				d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + (uint16_t)d0_2);
				if ((mem_read8(a1) & 0xFu) != 9u)
				{
					if ((OBJECT(a0)->contacts & 0x10u) == 0u)
					{
						d1 &= 0xFFFFu;
						OBJECT(a0)->x -= d1;
					}
				}
				else if ((OBJECT(a0)->contacts & 0x50u) == 0u)
				{
					d1 &= 0xFFFFu;
					OBJECT(a0)->x -= d1;
				}
			}
		}
	}
	t2 = mem_read8(a1) & 0xCu;
	d0 = t2;
	if (t2 == 0u)
		return d1;
	if ((d0 & 8u) != 0u)
	{
		if (scroll_mode >= 0)
		{
			if ((uint8_t)LAYER(WORKING_LAYER)->y_direction != 0u || OBJECT(a0)->y >= 0x6000u)
			{
				turtle_walk_speed(a0, a1, &d0_2, &a6);
				d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
				if ((OBJECT(a0)->contacts & 4u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (OBJECT(a0)->routine == 3u)
					d1 = d1 >> 3;
				OBJECT(a0)->y -= d1;
				return d1;
			}
			if (OBJECT(a0)->y < 0x1100u)
			{
				if ((OBJECT(a0)->contacts & 4u) != 0u || scroll_held_down != 0u)
					return d1;
				d0 = 0x80u;
				turtle_other_at_edge(d0, a0, &d1, &carry);
				if (carry)
					return d1;
				if ((uint8_t)diagonal_scroll != 0u)
				{
					d0 = 0x7Fu;
					turtle_other_at_edge(d0, a0, &d1, &carry);
					if (carry)
						return d1;
				}
				turtle_push_scroll_down(a0, a1, &d0_2, &d1, &carry);
				if (carry)
				{
					LAYER(WORKING_LAYER)->y = LAYER(WORKING_LAYER)->y_min;
					LAYER(WORKING_LAYER)->y_speed = 0u;
					LAYER(WORKING_LAYER)->row_phase = 0u;
					LAYER(WORKING_LAYER)->y_direction = 0;
					return d1;
				}
				row_phase = LAYER(WORKING_LAYER)->row_phase;
				LAYER(WORKING_LAYER)->row_phase = row_phase - d1;
				if (row_phase < (uint16_t)d1)
					return queue_scroll_row(d0_2, d1, a0);
				if ((uint8_t)diagonal_scroll != 0u)
					return push_scroll_diagonally(a0);
				return d1;
			}
			if (scroll_held_down != 0u)
			{
				turtle_walk_speed(a0, a1, &d0_2, &a6);
				d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
				if ((OBJECT(a0)->contacts & 4u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (OBJECT(a0)->routine == 3u)
					d1 = d1 >> 3;
				OBJECT(a0)->y -= d1;
				return d1;
			}
			if ((OBJECT(a0)->contacts & 4u) != 0u)
				return d1;
			d0 = 0x80u;
			turtle_other_at_edge(d0, a0, &d1, &carry);
			if (carry)
			{
				turtle_walk_speed(a0, a1, &d0_2, &a6);
				d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
				if ((OBJECT(a0)->contacts & 4u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (OBJECT(a0)->routine == 3u)
					d1 = d1 >> 3;
				OBJECT(a0)->y -= d1;
				return d1;
			}
			if ((uint8_t)diagonal_scroll != 0u)
			{
				d0 = 0x7Fu;
				turtle_other_at_edge(d0, a0, &d1, &carry);
				if (carry)
				{
					turtle_walk_speed(a0, a1, &d0_2, &a6);
					d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
					if ((OBJECT(a0)->contacts & 4u) != 0u)
						return d1;
					d1 &= 0xFFFFu;
					if (OBJECT(a0)->routine == 3u)
						d1 = d1 >> 3;
					OBJECT(a0)->y -= d1;
					return d1;
				}
			}
			turtle_push_scroll_down(a0, a1, &d0_2, &d1, &carry);
			if (carry)
			{
				d1 = (d1 & ~0xFFFFu) | (uint16_t)(LAYER(WORKING_LAYER)->y_min - LAYER(WORKING_LAYER)->y);
				y_speed = LAYER(WORKING_LAYER)->y_speed;
				LAYER(WORKING_LAYER)->y_speed = y_speed - d1;
				if (y_speed == (uint16_t)d1)
					LAYER(WORKING_LAYER)->y_direction = 0;
				LAYER(WORKING_LAYER)->y = LAYER(WORKING_LAYER)->y_min;
				LAYER(WORKING_LAYER)->row_phase = 0u;
				if ((OBJECT(a0)->contacts & 4u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (OBJECT(a0)->routine == 3u)
					d1 = d1 >> 3;
				OBJECT(a0)->y -= d1;
				return d1;
			}
			row_phase_2 = LAYER(WORKING_LAYER)->row_phase;
			LAYER(WORKING_LAYER)->row_phase = row_phase_2 - d1;
			if (row_phase_2 < (uint16_t)d1)
				return queue_scroll_row(d0_2, d1, a0);
			if ((uint8_t)diagonal_scroll != 0u)
				return push_scroll_diagonally(a0);
			return d1;
		}
		if (OBJECT(a0)->y < reset_ADDRESS)
			return d1;
		turtle_walk_speed(a0, a1, &d0_2, &a6);
		d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
		if ((OBJECT(a0)->contacts & 4u) != 0u)
			return d1;
		d1 &= 0xFFFFu;
		if (OBJECT(a0)->routine == 3u)
			d1 = d1 >> 3;
		OBJECT(a0)->y -= d1;
		return d1;
	}
	if (scroll_mode >= 0)
	{
		if ((uint8_t)LAYER(WORKING_LAYER)->y_direction != 0u || OBJECT(a0)->y < 0x6000u)
		{
			turtle_walk_speed(a0, a1, &d0_2, &a6);
			d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
			d0 = mem_read8(a1) & 0xFu;
			if (d0 == 5u)
			{
				if ((OBJECT(a0)->contacts & 0x52u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (OBJECT(a0)->routine == 3u)
					d1 = d1 >> 3;
				OBJECT(a0)->y += d1;
				return d1;
			}
			if (d0 != 6u)
			{
				if ((OBJECT(a0)->contacts & 0x62u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (OBJECT(a0)->routine == 3u)
					d1 = d1 >> 3;
				OBJECT(a0)->y += d1;
				return d1;
			}
			if ((OBJECT(a0)->contacts & 0x2Au) != 0u)
				return d1;
			d1 &= 0xFFFFu;
			if (OBJECT(a0)->routine == 3u)
				d1 = d1 >> 3;
			OBJECT(a0)->y += d1;
			return d1;
		}
		if (OBJECT(a0)->y >= 0xA000u)
		{
			d0 = mem_read8(a1) & 0xFu;
			if (d0 == 5u)
			{
				if ((OBJECT(a0)->contacts & 0x50u) != 0u)
					return d1;
				if (scroll_held_up != 0u)
					return d1;
				d0 = 0xFFu;
				turtle_other_at_edge(d0, a0, &d1, &carry);
				if (carry)
					return d1;
				turtle_push_scroll_up(a0, a1, &d0_2, &d1, &d2, &carry);
				if (carry)
				{
					LAYER(WORKING_LAYER)->y = d2;
					LAYER(WORKING_LAYER)->y_speed = 0u;
					LAYER(WORKING_LAYER)->row_phase = 0u;
					LAYER(WORKING_LAYER)->y_direction = 0;
					return d1;
				}
				row_phase_3 = LAYER(WORKING_LAYER)->row_phase;
				carry = (uint16_t)(row_phase_3 + d1) < row_phase_3;
				LAYER(WORKING_LAYER)->row_phase = row_phase_3 + d1;
				if (carry)
					return queue_scroll_row(d0_2, d1, a0);
				return d1;
			}
			if (d0 != 6u)
			{
				if ((OBJECT(a0)->contacts & 0x62u) != 0u)
					return d1;
				if (scroll_held_up != 0u)
					return d1;
				d0 = 0xFFu;
				turtle_other_at_edge(d0, a0, &d1, &carry);
				if (carry)
					return d1;
				turtle_push_scroll_up(a0, a1, &d0_2, &d1, &d2, &carry);
				if (carry)
				{
					LAYER(WORKING_LAYER)->y = d2;
					LAYER(WORKING_LAYER)->y_speed = 0u;
					LAYER(WORKING_LAYER)->row_phase = 0u;
					LAYER(WORKING_LAYER)->y_direction = 0;
					return d1;
				}
				row_phase_3 = LAYER(WORKING_LAYER)->row_phase;
				carry = (uint16_t)(row_phase_3 + d1) < row_phase_3;
				LAYER(WORKING_LAYER)->row_phase = row_phase_3 + d1;
				if (carry)
					return queue_scroll_row(d0_2, d1, a0);
				return d1;
			}
			if ((OBJECT(a0)->contacts & 0x28u) != 0u)
				return d1;
			if (scroll_held_up != 0u)
				return d1;
			d0 = 0xFFu;
			turtle_other_at_edge(d0, a0, &d1, &carry);
			if (carry)
				return d1;
			turtle_push_scroll_up(a0, a1, &d0_2, &d1, &d2, &carry);
			if (carry)
			{
				LAYER(WORKING_LAYER)->y = d2;
				LAYER(WORKING_LAYER)->y_speed = 0u;
				LAYER(WORKING_LAYER)->row_phase = 0u;
				LAYER(WORKING_LAYER)->y_direction = 0;
				return d1;
			}
			row_phase_3 = LAYER(WORKING_LAYER)->row_phase;
			carry = (uint16_t)(row_phase_3 + d1) < row_phase_3;
			LAYER(WORKING_LAYER)->row_phase = row_phase_3 + d1;
			if (carry)
				return queue_scroll_row(d0_2, d1, a0);
			return d1;
		}
		if (scroll_held_up != 0u)
		{
			turtle_walk_speed(a0, a1, &d0_2, &a6);
			d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
			d0 = mem_read8(a1) & 0xFu;
			if (d0 == 5u)
			{
				if ((OBJECT(a0)->contacts & 0x52u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (OBJECT(a0)->routine == 3u)
					d1 = d1 >> 3;
				OBJECT(a0)->y += d1;
				return d1;
			}
			if (d0 != 6u)
			{
				if ((OBJECT(a0)->contacts & 0x62u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (OBJECT(a0)->routine == 3u)
					d1 = d1 >> 3;
				OBJECT(a0)->y += d1;
				return d1;
			}
			if ((OBJECT(a0)->contacts & 0x2Au) != 0u)
				return d1;
			d1 &= 0xFFFFu;
			if (OBJECT(a0)->routine == 3u)
				d1 = d1 >> 3;
			OBJECT(a0)->y += d1;
			return d1;
		}
		d0 = mem_read8(a1) & 0xFu;
		if (d0 == 5u)
		{
			if ((OBJECT(a0)->contacts & 0x50u) != 0u)
				return d1;
		}
		else if (d0 != 6u)
		{
			if ((OBJECT(a0)->contacts & 0x62u) != 0u)
				return d1;
		}
		else if ((OBJECT(a0)->contacts & 0x28u) != 0u)
			return d1;
		d0 = 0xFFu;
		turtle_other_at_edge(d0, a0, &d1, &carry);
		if (carry)
		{
			turtle_walk_speed(a0, a1, &d0_2, &a6);
			d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
			d0 = mem_read8(a1) & 0xFu;
			if (d0 == 5u)
			{
				if ((OBJECT(a0)->contacts & 0x52u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (OBJECT(a0)->routine == 3u)
					d1 = d1 >> 3;
				OBJECT(a0)->y += d1;
				return d1;
			}
			if (d0 != 6u)
			{
				if ((OBJECT(a0)->contacts & 0x62u) != 0u)
					return d1;
				d1 &= 0xFFFFu;
				if (OBJECT(a0)->routine == 3u)
					d1 = d1 >> 3;
				OBJECT(a0)->y += d1;
				return d1;
			}
			if ((OBJECT(a0)->contacts & 0x2Au) != 0u)
				return d1;
			d1 &= 0xFFFFu;
			if (OBJECT(a0)->routine == 3u)
				d1 = d1 >> 3;
			OBJECT(a0)->y += d1;
			return d1;
		}
		turtle_push_scroll_up(a0, a1, &d0_2, &d1, &d2, &carry);
		if (carry == 0u)
		{
			row_phase_4 = LAYER(WORKING_LAYER)->row_phase;
			carry = (uint16_t)(row_phase_4 + d1) < row_phase_4;
			LAYER(WORKING_LAYER)->row_phase = row_phase_4 + d1;
			if (carry)
				return queue_scroll_row(d0_2, d1, a0);
			return d1;
		}
		d0_2 -= d2;
		d1 = (d1 & ~0xFFFFu) | (uint16_t)d0_2;
		d0_2 = (d0_2 << 16) | (d0_2 >> 16);
		y_speed_2 = LAYER(WORKING_LAYER)->y_speed;
		LAYER(WORKING_LAYER)->y_speed = y_speed_2 - d1;
		if (y_speed_2 == (uint16_t)d1)
			LAYER(WORKING_LAYER)->y_direction = d0_2;
		LAYER(WORKING_LAYER)->y = d2;
		LAYER(WORKING_LAYER)->row_phase = d0_2;
		d0 = mem_read8(a1) & 0xFu;
		if (d0 == 5u)
		{
			if ((OBJECT(a0)->contacts & 0x52u) != 0u)
				return d1;
			d1 &= 0xFFFFu;
			if (OBJECT(a0)->routine == 3u)
				d1 = d1 >> 3;
			OBJECT(a0)->y += d1;
			return d1;
		}
		if (d0 != 6u)
		{
			if ((OBJECT(a0)->contacts & 0x62u) != 0u)
				return d1;
			d1 &= 0xFFFFu;
			if (OBJECT(a0)->routine == 3u)
				d1 = d1 >> 3;
			OBJECT(a0)->y += d1;
			return d1;
		}
		if ((OBJECT(a0)->contacts & 0x2Au) != 0u)
			return d1;
		d1 &= 0xFFFFu;
		if (OBJECT(a0)->routine == 3u)
			d1 = d1 >> 3;
		OBJECT(a0)->y += d1;
		return d1;
	}
	if (OBJECT(a0)->y >= 0xA000u)
		return d1;
	turtle_walk_speed(a0, a1, &d0_2, &a6);
	d1 = (d1 & ~0xFFFFu) | mem_read16(a6 + 4u + (uint16_t)d0_2);
	d0 = mem_read8(a1) & 0xFu;
	if (d0 == 5u)
	{
		if ((OBJECT(a0)->contacts & 0x52u) != 0u)
			return d1;
		d1 &= 0xFFFFu;
		if (OBJECT(a0)->routine == 3u)
			d1 = d1 >> 3;
		OBJECT(a0)->y += d1;
		return d1;
	}
	if (d0 != 6u)
	{
		if ((OBJECT(a0)->contacts & 0x62u) != 0u)
			return d1;
		d1 &= 0xFFFFu;
		if (OBJECT(a0)->routine == 3u)
			d1 = d1 >> 3;
		OBJECT(a0)->y += d1;
		return d1;
	}
	if ((OBJECT(a0)->contacts & 0x2Au) != 0u)
		return d1;
	d1 &= 0xFFFFu;
	if (OBJECT(a0)->routine == 3u)
		d1 = d1 >> 3;
	OBJECT(a0)->y += d1;
	return d1;
}

/* the turtle at the left edge moves the scroll left at its walking speed */
void turtle_push_scroll_left(uint32_t a0, uint32_t a1, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d1 = 0, x_speed = 0;
	uint32_t a6 = 0, d0 = 0, d2 = 0;

	LAYER(WORKING_LAYER)->x_direction = 0x7F;
	turtle_walk_speed(a0, a1, &d0, &a6);
	LAYER(WORKING_LAYER)->x_speed = mem_read16(a6 + (uint16_t)d0);
	OBJECT(a0)->turtle.scroll_push = 0x7Fu;
	x_speed = LAYER(WORKING_LAYER)->x_speed;
	d1 = (uint16_t)((uint32_t)x_speed << 5);
	LAYER(WORKING_LAYER)->x -= x_speed;
	d0 = LAYER(WORKING_LAYER)->x;
	d2 = d0;
	d0 -= 0x1800u;
	carry = d2 < LAYER(WORKING_LAYER)->x_min;
	*p_d0 = d0;
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_carry = carry;
}

/* the turtle at the right edge moves the scroll right at its walking speed */
void turtle_push_scroll_right(uint32_t a0, uint32_t a1, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d1 = 0, x_speed = 0;
	uint32_t a6 = 0;

	LAYER(WORKING_LAYER)->x_direction = -0x80;
	turtle_walk_speed(a0, a1, p_d0, &a6);
	LAYER(WORKING_LAYER)->x_speed = mem_read16(a6 + (uint16_t)*p_d0);
	OBJECT(a0)->turtle.scroll_push = 0x7Fu;
	x_speed = LAYER(WORKING_LAYER)->x_speed;
	d1 = (uint16_t)((uint32_t)x_speed << 5);
	LAYER(WORKING_LAYER)->x += x_speed;
	*p_d0 = LAYER(WORKING_LAYER)->x + 0x15800u;
	*p_d2 = LAYER(WORKING_LAYER)->x_max;
	carry = *p_d2 < LAYER(WORKING_LAYER)->x;
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_carry = carry;
}

/* the turtle at the top moves the scroll up at its walking speed */
void turtle_push_scroll_up(uint32_t a0, uint32_t a1, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d0_2 = 0, d1 = 0;
	uint32_t a6 = 0, d0 = 0;

	LAYER(WORKING_LAYER)->y_direction = 0x7F;
	OBJECT(a0)->turtle.scroll_push |= 0x80u;
	turtle_walk_speed(a0, a1, &d0, &a6);
	d0_2 = mem_read16(a6 + 4u + (uint16_t)d0);
	if (OBJECT(a0)->routine == 3u)
		d0_2 = d0_2 >> 3;
	LAYER(WORKING_LAYER)->y_speed = d0_2;
	d1 = (uint16_t)((uint32_t)d0_2 << 5);
	LAYER(WORKING_LAYER)->y += d0_2;
	*p_d0 = LAYER(WORKING_LAYER)->y;
	*p_d2 = LAYER(WORKING_LAYER)->y_max;
	carry = *p_d2 < *p_d0;
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_carry = carry;
}

uint32_t push_scroll_diagonally(uint32_t a0)
{
	uint32_t carry = 0;
	uint8_t d0 = 0;
	uint32_t d0_2 = 0, d1 = 0;
	uint16_t column_phase = 0;

	d0 = 0x7Fu;
	turtle_other_at_edge(d0, a0, &d1, &carry);
	if (carry == 0u && (uint8_t)LAYER(WORKING_LAYER)->x_direction == 0u)
	{
		LAYER(WORKING_LAYER)->x_direction = -0x80;
		LAYER(WORKING_LAYER)->x_speed = 0x120u;
		d1 = 0x120u;
		d1 = (uint16_t)(d1 << 5);
		LAYER(WORKING_LAYER)->x += 0x120u;
		d0_2 = LAYER(WORKING_LAYER)->x;
		column_phase = LAYER(WORKING_LAYER)->column_phase;
		carry = (uint16_t)(column_phase + d1) < column_phase;
		LAYER(WORKING_LAYER)->column_phase = column_phase + d1;
		d0_2 += 0x15800u;
		if (carry)
		{
			LAYER(WORKING_LAYER)->new_column_x = d0_2;
			LAYER(WORKING_LAYER)->new_column--;
		}
	}
	return d1;
}

uint32_t queue_scroll_row(uint32_t d0, uint32_t d1, uint32_t a0)
{
	LAYER(WORKING_LAYER)->new_row_y = d0;
	LAYER(WORKING_LAYER)->new_row--;
	if ((uint8_t)diagonal_scroll != 0u)
		return push_scroll_diagonally(a0);
	return d1;
}

/* the turtle at the bottom moves the scroll down at its walking speed */
void turtle_push_scroll_down(uint32_t a0, uint32_t a1, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d0_2 = 0, d1 = 0;
	uint32_t a6 = 0, d0 = 0, d2 = 0;

	LAYER(WORKING_LAYER)->y_direction = -0x80;
	OBJECT(a0)->turtle.scroll_push |= 0x80u;
	turtle_walk_speed(a0, a1, &d0, &a6);
	d0_2 = mem_read16(a6 + 4u + (uint16_t)d0);
	if (OBJECT(a0)->routine == 3u)
		d0_2 = d0_2 >> 3;
	LAYER(WORKING_LAYER)->y_speed = d0_2;
	d1 = (uint16_t)((uint32_t)d0_2 << 5);
	LAYER(WORKING_LAYER)->y -= d0_2;
	d0 = LAYER(WORKING_LAYER)->y;
	d2 = d0;
	d0 -= 0xF800u;
	carry = d2 < LAYER(WORKING_LAYER)->y_min;
	*p_d0 = d0;
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_carry = carry;
}

/* the turtle's walking speeds, straight or on a diagonal */
void turtle_walk_speed(uint32_t a0, uint32_t a1, uint32_t *p_d0, uint32_t *p_a6)
{
	uint8_t d0 = 0, d1 = 0;
	uint16_t d0_2 = 0, d2 = 0;

	d2 = 0u;
	d0 = mem_read8(a1);
	d1 = (uint8_t)d0;
	if ((d0 & 3u) != 0u && (d1 & 0xCu) != 0u)
		d2 = 2u;
	*p_a6 = table_loaded_by_lea_01B5B2_ADDRESS;
	d0_2 = (uint16_t)(((OBJECT(a0)->kind & 3u) << 3) + d2);
	*p_d0 = (*p_d0 & 0xFFFF0000u) | d0_2;
}

/* whether another turtle stands at the opposite edge, so the scroll cannot move away from it */
void turtle_other_at_edge(uint8_t d0, uint32_t a0, uint32_t *p_d1, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t d1 = 0, object = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	object = OBJECT_ADDRESS(0);
	d1 = 4u;
	if ((uint8_t)d0 != 0u)
	{
		if ((int8_t)d0 < 0)
		{
			if ((d0 & 0x7Fu) != 0u)
			{
				do
				{
					if (object != a0 && (OBJECT(object)->flags & 1u) != 0u && OBJECT(object)->height + OBJECT(object)->y < 0x1100u)
					{
						carry = 1u;
						break;
					}
					t1 = d1;
					carry = t1 == 0u;
					d1 = (uint8_t)(t1 - 1u);
					object += 0x50u;
				} while (t1 != 1u);
			}
			else
			{
				do
				{
					if (object != a0 && (OBJECT(object)->flags & 1u) != 0u && OBJECT(object)->height + OBJECT(object)->y >= 0xA000u)
					{
						carry = 1u;
						break;
					}
					t2 = d1;
					carry = t2 == 0u;
					d1 = (uint8_t)(t2 - 1u);
					object += 0x50u;
				} while (t2 != 1u);
			}
		}
		else
		{
			do
			{
				if (object != a0 && (OBJECT(object)->flags & 1u) != 0u && OBJECT(object)->x < 0x9100u)
				{
					carry = 1u;
					break;
				}
				t3 = d1;
				carry = t3 == 0u;
				d1 = (uint8_t)(t3 - 1u);
				object += 0x50u;
			} while (t3 != 1u);
		}
	}
	else
	{
		do
		{
			if (object != a0 && (OBJECT(object)->flags & 1u) != 0u && OBJECT(object)->x >= 0x16000u)
			{
				carry = 1u;
				break;
			}
			t4 = d1;
			carry = t4 == 0u;
			d1 = (uint8_t)(t4 - 1u);
			object += 0x50u;
		} while (t4 != 1u);
	}
	*p_d1 = d1;
	*p_carry = carry;
}

/* every frame: the time it cannot be hit, the blinking, and its routine (stand, walk, jump, attack, hit) */
void turtle_control(uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t carry = 0;
	uint8_t d2 = 0;
	uint8_t t1 = 0, attack_press_time = 0;

	OBJECT(a0)->flags &= ~2u;
	if (OBJECT(a0)->turtle.invulnerable_time == 0u)
	{
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->flags |= 0x80u;
	}
	else
	{
		t1 = OBJECT(a0)->turtle.invulnerable_time - 1u;
		OBJECT(a0)->turtle.invulnerable_time = t1;
		if ((int8_t)t1 >= 0)
			OBJECT(a0)->flags |= 0x80u;
		else if (OBJECT(a0)->turtle.invulnerable_time != 0x80u)
		{
			if ((frame_count & 1u) == 0u)
				OBJECT(a0)->flags ^= 0x80u;
		}
		else
		{
			OBJECT(a0)->turtle.invulnerable_time = 0u;
			OBJECT(a0)->flags |= 2u;
			OBJECT(a0)->flags |= 0x80u;
		}
	}
	*p_d1 = (*p_d1 & ~0xFFu) | mem_read8(a1);
	d2 = mem_read8(a2);
	if ((d2 & 0x20u) != 0u)
		OBJECT(a0)->turtle.attack_press_time = 0u;
	attack_press_time = OBJECT(a0)->turtle.attack_press_time;
	carry = (uint8_t)(attack_press_time + 1u) < attack_press_time;
	OBJECT(a0)->turtle.attack_press_time = attack_press_time + 1u;
	if (carry)
		OBJECT(a0)->turtle.attack_press_time--;
	switch (OBJECT(a0)->routine)
	{
	case 0:
		turtle_stand(d2, d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	case 1:
		turtle_walk(d2, d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	case 2:
		turtle_jump(d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	case 3:
		turtle_attack(d2, d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	case 4:
		turtle_hit(d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	case 5:
		turtle_fire_gun(d2, d6, a0, a1, a2, p_d1, &d5, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the turtle starts walking, across or up, or stands on the skateboard */
void turtle_start_walk(uint32_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	if (stage == 6u)
	{
		OBJECT(a0)->flags &= ~0xCu;
		d0 = 0u;
		if (OBJECT(a0)->turtle.has_gun == 0u)
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
		else
		{
			d0 = 4u;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
		}
	}
	else
	{
		OBJECT(a0)->flags &= ~0xCu;
		d0 = 0x100u;
		if (OBJECT(a0)->turtle.has_gun != 0u)
			d0 += 2u;
		if ((*p_d1 & 4u) == 0u)
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
		else
		{
			d0++;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the jump button starts a jump, or the special attack with the attack button too */
void turtle_start_jump(uint32_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint8_t d0 = 0;
	uint16_t d0_2 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	if ((mem_read8(a2) & 0x20u) == 0u)
	{
		turtles_busy--;
		OBJECT(a0)->flags &= ~0xCu;
		OBJECT(a0)->contacts |= 0x80u;
		OBJECT(a0)->turtle.jump_speed = 0x500u;
		OBJECT(a0)->turtle.falling = 0u;
		OBJECT(a0)->turtle.move_timer = 0x10u;
		OBJECT(a0)->turtle.jump_flip = 0u;
		OBJECT(a0)->height += 0x500u;
		d0_2 = 0x201u;
		turtle_set_state(d0_2, a0, p_d1, &ignored_2, &d5, &ignored, p_d7);
		turtle_jump((uint8_t)ignored, a0, a1, a2, p_d1, &d5, p_d7);
	}
	else
	{
		OBJECT(a0)->flags &= ~8u;
		OBJECT(a0)->flags |= 4u;
		OBJECT(a0)->turtle.combo_step = 0u;
		OBJECT(a0)->turtle.combo = 6u;
		d0 = 7u;
		if (OBJECT(a0)->kind == 3u)
			turtle_start_attack(d0, a0, p_d1, &d5, &ignored, p_d7);
		else
		{
			d0 = 8u;
			OBJECT(a0)->turtle.jump_speed = 0x900u;
			OBJECT(a0)->turtle.falling = 0u;
			OBJECT(a0)->turtle.move_timer = 0u;
			turtle_start_attack(d0, a0, p_d1, &d5, &ignored, p_d7);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the attack button starts a combo at random, or the attack behind when an enemy is there */
void turtle_start_combo(uint32_t d6, uint32_t a0, uint32_t a1, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0;
	uint32_t a6 = 0, ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a1) & 3u;
	mem_write8(a1, t1);
	if (t1 != 0u)
	{
		if ((mem_read8(a1) & 1u) != 0u)
			OBJECT(a0)->flags |= 0x40u;
		else
			OBJECT(a0)->flags &= 0xBFu;
	}
	mem_write8(a1, 0u);
	if (OBJECT(a0)->turtle.has_gun == 0u)
	{
		d7 = 4u;
		d7 = random_below((uint16_t)d7, a0);
		d7 = d7 & 3u;
		d7 = (uint16_t)(d7 + (d7 << 1));
		OBJECT(a0)->turtle.combo = d7;
		a6 = rom_01D5F2[OBJECT(a0)->kind & 3u];
		if (OBJECT(a0)->turtle.enemy_behind == 0u)
		{
			d0_2 = mem_read8(a6 + d7);
			turtle_start_attack(d0_2, a0, p_d1, &d5, &ignored_2, &d7);
		}
		else
		{
			OBJECT(a0)->turtle.combo_step = 1u;
			d7 = (uint16_t)(d7 + 0xCu);
			OBJECT(a0)->turtle.combo += 0xCu;
			d0_2 = 3u;
			*p_d1 = (*p_d1 & ~0xFFu) | 3u;
			turtle_set_attack(d0_2, a0, p_d1, &d5, &ignored_2, &d7);
		}
	}
	else
	{
		OBJECT(a0)->flags &= ~8u;
		OBJECT(a0)->flags |= 4u;
		OBJECT(a0)->turtle.combo_step = 0u;
		d0 = 0x500u;
		turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, &d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* an attack from the first step of the combo */
void turtle_start_attack(uint8_t d0, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	*p_d1 = (*p_d1 & ~0xFFu) | d0;
	OBJECT(a0)->turtle.combo_step = 0u;
	turtle_set_attack(d0, a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the attack's kind, sound and damage, and the turtle attacking */
void turtle_set_attack(uint16_t d0, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0, ignored = 0;

	OBJECT(a0)->flags &= ~8u;
	OBJECT(a0)->flags |= 4u;
	d1 = (d1 & ~0xFFu) | (uint8_t)(d1 + indexed_table_of_8_bit_values_01C20E[OBJECT(a0)->kind & 3u]);
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		d1 = d1 | 0x80u;
	if (d0 == 3u)
		d1 = d1 ^ 0x80u;
	OBJECT(a0)->attack = d1;
	d1 = LINKED(d1, d1 & 0x7Fu);
	d7_2 = (d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1];
	queue_sound((uint8_t)d7_2, 0u);
	d1 = LINKED(d1, (uint16_t)(d1 << 1));
	OBJECT(a0)->damage = rom_01D592[(uint16_t)d1 / 2u];
	d0 = (uint16_t)((d0 & 0x7Fu) + 0x300u);
	turtle_set_state(d0, a0, &d1, &ignored, &d5, &d6, &d7_2);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7_2;
}

/* a new routine and state for the turtle with its animation */
void turtle_set_state(uint16_t d0, uint32_t a0, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint16_t d2 = 0;

	if (d0 == 0x411u)
	{
		d7 = (d7 & ~0xFFu) | 0x26u;
		queue_sound((uint8_t)d7, 0u);
		d1 = (d1 & ~0xFFFFu) | OBJECT(a0)->kind;
		d2 = (uint16_t)d1;
		d1 = (d1 & ~0xFFFFu) | (uint16_t)(d1 << 3);
		if (RAM16(unk_060100_ADDRESS + (uint16_t)d1) == 0u)
		{
			d0 &= ~0xFFu;
			prompt_shown(d2) = (uint8_t)d0;
			if ((OBJECT(a0)->flags & 0x40u) != 0u)
				d0 |= (uint8_t)(d0 - 1u);
			d1 = (d1 & ~0xFFFFu) | OBJECT(a0)->screen_x;
			d2 = (uint16_t)(OBJECT(a0)->screen_y - 0x10u);
			say_shell_shock(d0, d2, a0, &d1, p_d4, &d5, &d6, &d7);
			d0 = 0x411u;
		}
	}
	OBJECT(a0)->turtle.idle_time = 0u;
	OBJECT(a0)->routine = (uint8_t)(d0 >> 8u);
	OBJECT(a0)->state = (uint8_t)d0;
	d1 = turtle_set_animation(d1, a0);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

/* the turtle's animation for its routine and state */
uint32_t turtle_set_animation(uint32_t d1, uint32_t a0)
{
	uint16_t d3 = 0;
	uint32_t a6 = 0, animation = 0;

	d3 = (uint16_t)((uint32_t)OBJECT(a0)->kind << 2);
	a6 = animations_0208C0[d3 / 4u];
	d3 = (uint16_t)(IN_PAGE(d3, OBJECT(a0)->routine) << 2);
	animation = mem_read32(mem_read32(a6 + d3) + (uint16_t)(IN_PAGE(d3, OBJECT(a0)->state) << 2));
	return set_animation(d1, a0, animation);
}

/* standing: jump, attack, walk, or the idle animation */
void turtle_stand(uint8_t d2, uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint8_t d3 = 0;
	uint8_t t1 = 0, t2 = 0;

	OBJECT(a0)->flags &= ~0xCu;
	d3 = (uint8_t)d2;
	if (area_beaten != 0u)
	{
		t1 = d1 & 0xFu;
		d1 = (d1 & ~0xFFu) | t1;
		if (t1 != 0u)
			turtle_start_walk(d6, a0, &d1, &d5, p_d7);
		else if (OBJECT(a0)->turtle.has_gun == 0u && OBJECT(a0)->frame_time == 0u)
		{
			OBJECT(a0)->turtle.idle_time++;
			if (OBJECT(a0)->turtle.idle_time >= 0x18u)
			{
				OBJECT(a0)->turtle.idle_time = 0u;
				OBJECT(a0)->state++;
				t2 = OBJECT(a0)->state & 3u;
				OBJECT(a0)->state = t2;
				if (t2 != 0u)
					d1 = turtle_set_animation(d1, a0);
				else
				{
					OBJECT(a0)->state = 1u;
					d1 = turtle_set_animation(d1, a0);
				}
			}
		}
	}
	else if ((OBJECT(a0)->contacts & 1u) == 0u || (d2 & 0x10u) == 0u)
	{
		if ((d3 & 0x20u) != 0u)
			turtle_start_combo(d6, a0, a1, &d1, &d5, p_d7);
		else
		{
			t1 = d1 & 0xFu;
			d1 = (d1 & ~0xFFu) | t1;
			if (t1 != 0u)
				turtle_start_walk(d6, a0, &d1, &d5, p_d7);
			else if (OBJECT(a0)->turtle.has_gun == 0u && OBJECT(a0)->frame_time == 0u)
			{
				OBJECT(a0)->turtle.idle_time++;
				if (OBJECT(a0)->turtle.idle_time >= 0x18u)
				{
					OBJECT(a0)->turtle.idle_time = 0u;
					OBJECT(a0)->state++;
					t2 = OBJECT(a0)->state & 3u;
					OBJECT(a0)->state = t2;
					if (t2 != 0u)
						d1 = turtle_set_animation(d1, a0);
					else
					{
						OBJECT(a0)->state = 1u;
						d1 = turtle_set_animation(d1, a0);
					}
				}
			}
		}
	}
	else
		turtle_start_jump(d6, a0, a1, a2, &d1, &d5, p_d7);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* walking: jump, attack, stand, or across and up by the stick */
void turtle_walk(uint8_t d2, uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint8_t d3 = 0;
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	OBJECT(a0)->flags &= ~0xCu;
	d3 = (uint8_t)d2;
	if (area_beaten != 0u)
	{
		d0 = 0x100u;
		if (OBJECT(a0)->turtle.has_gun != 0u)
			d0 += 2u;
		t1 = d1 & 0xFu;
		d1 = (d1 & ~0xFFu) | t1;
		if (t1 == 0u)
		{
			OBJECT(a0)->flags &= ~0xCu;
			d0 = 0u;
			if (OBJECT(a0)->turtle.has_gun == 0u)
				turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			else
			{
				d0 = 4u;
				turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			}
		}
		else
		{
			t2 = d1 & 4u;
			d1 = (d1 & ~0xFFu) | t2;
			if (t2 != 0u)
			{
				d0++;
				if ((OBJECT(a0)->state & 1u) == 0u)
					turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			}
			else if ((OBJECT(a0)->state & 1u) != 0u)
				turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
		}
	}
	else if ((OBJECT(a0)->contacts & 1u) == 0u || (d2 & 0x10u) == 0u)
	{
		if ((d3 & 0x20u) != 0u)
			turtle_start_combo(d6, a0, a1, &d1, &d5, p_d7);
		else
		{
			d0 = 0x100u;
			if (OBJECT(a0)->turtle.has_gun != 0u)
				d0 += 2u;
			t1 = d1 & 0xFu;
			d1 = (d1 & ~0xFFu) | t1;
			if (t1 == 0u)
			{
				OBJECT(a0)->flags &= ~0xCu;
				d0 = 0u;
				if (OBJECT(a0)->turtle.has_gun == 0u)
					turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
				else
				{
					d0 = 4u;
					turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
				}
			}
			else
			{
				t2 = d1 & 4u;
				d1 = (d1 & ~0xFFu) | t2;
				if (t2 != 0u)
				{
					d0++;
					if ((OBJECT(a0)->state & 1u) == 0u)
						turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
				}
				else if ((OBJECT(a0)->state & 1u) != 0u)
					turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			}
		}
	}
	else
		turtle_start_jump(d6, a0, a1, a2, &d1, &d5, p_d7);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* in the air: a jump attack by its height, or the jump's state */
void turtle_jump(uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint8_t d0 = 0, d2 = 0;
	uint32_t ignored = 0;

	turtles_busy--;
	OBJECT(a0)->flags &= ~0xCu;
	if ((mem_read8(a2) & 0x20u) == 0u)
	{
		switch (OBJECT(a0)->state)
		{
		case 0:
		case 1:
			turtle_jump_rise(d6, a0, a1, &d1, &d5, p_d7);
			break;
		case 2:
			turtle_jump_top(d6, a0, a1, &d1, &d5, p_d7);
			break;
		case 3:
			turtle_jump_fall(d6, a0, &d1, &d5, p_d7);
			break;
		case 4:
			turtle_wall_jump(d6, a0, a1, &d1, &d5, p_d7);
			break;
		}
	}
	else
	{
		d2 = 0x38u;
		if (OBJECT(a0)->kind == 3u)
			d2 = 0x20u;
		OBJECT(a0)->flags |= 4u;
		d1 = (d1 & ~0xFFu) | OBJECT(a0)->height_whole;
		d1 = (d1 & ~0xFFu) | (uint8_t)(d1 - OBJECT(a0)->floor_height);
		OBJECT(a0)->turtle.falling = 0u;
		OBJECT(a0)->turtle.jump_speed = 0x500u;
		d0 = 0xAu;
		if ((uint8_t)d1 >= 0x60u)
			turtle_start_attack(d0, a0, &d1, &d5, &ignored, p_d7);
		else
		{
			d0--;
			if (d2 <= (uint8_t)d1)
				turtle_start_attack(d0, a0, &d1, &d5, &ignored, p_d7);
			else
			{
				OBJECT(a0)->turtle.jump_speed = 0x800u;
				d0 += 2u;
				OBJECT(a0)->turtle.move_timer = 0u;
				turtle_start_attack(d0, a0, &d1, &d5, &ignored, p_d7);
			}
		}
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the jump going up, higher while the button is held */
void turtle_jump_rise(uint32_t d6, uint32_t a0, uint32_t a1, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0;
	uint8_t move_timer = 0;

	if (OBJECT(a0)->turtle.move_timer == 0u)
		OBJECT(a0)->turtle.jump_speed -= 0x50u;
	else
	{
		move_timer = OBJECT(a0)->turtle.move_timer;
		OBJECT(a0)->turtle.move_timer = move_timer - 1u;
		if (move_timer == 1u)
			OBJECT(a0)->turtle.jump_speed -= 0x50u;
		else if ((mem_read8(a1) & 0x10u) == 0u)
			OBJECT(a0)->turtle.move_timer = 0u;
	}
	OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
	if (OBJECT(a0)->turtle.jump_speed < 0x400u)
	{
		d0 = 0x202u;
		turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the top of the jump: the somersault, or kicking off a wall it is pushed against */
void turtle_jump_top(uint32_t d6, uint32_t a0, uint32_t a1, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0, jump_speed = 0;
	uint32_t ignored = 0, ignored_2 = 0;
	uint8_t move_timer = 0, t1 = 0;
	uint16_t height = 0, jump_speed_2 = 0;

	if (OBJECT(a0)->turtle.jump_flip != 0u && OBJECT(a0)->frame_time == 0u)
	{
		d0 = 0x203u;
		turtle_set_state(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	}
	if (OBJECT(a0)->turtle.falling != 0u)
	{
		if (OBJECT(a0)->height + OBJECT(a0)->y < 0xF400u && (uint8_t)(OBJECT(a0)->height_whole - OBJECT(a0)->floor_height) >= 0x40u)
		{
			if ((mem_read8(a1) & 1u) != 0u)
			{
				if ((OBJECT(a0)->contacts & 0x10u) != 0u)
				{
					OBJECT(a0)->turtle.jump_flip = 0u;
					mem_write8(a1, 0u);
					OBJECT(a0)->turtle.jump_speed = 0u;
					d0 = 0x205u;
					turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
					OBJECT(a0)->turtle.move_timer = 8u;
					OBJECT(a0)->state = 4u;
					*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
					return;
				}
			}
			else if ((mem_read8(a1) & 2u) != 0u && (OBJECT(a0)->contacts & 8u) != 0u)
			{
				OBJECT(a0)->turtle.jump_flip = 0xFFu;
				mem_write8(a1, 0u);
				OBJECT(a0)->turtle.jump_speed = 0u;
				d0 = 0x205u;
				turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
				OBJECT(a0)->turtle.move_timer = 8u;
				OBJECT(a0)->state = 4u;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
		}
		if ((OBJECT(a0)->contacts & 1u) != 0u)
		{
			OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
			OBJECT(a0)->height &= 0xFF00u;
			turtle_land(d6, a0, p_d1, &d5, p_d7);
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		OBJECT(a0)->turtle.jump_speed += 0x50u;
		if (OBJECT(a0)->turtle.jump_speed >= 0x500u)
			OBJECT(a0)->turtle.jump_speed = 0x500u;
		jump_speed = OBJECT(a0)->turtle.jump_speed;
		height = OBJECT(a0)->height;
		OBJECT(a0)->height = height - jump_speed;
		if (height < jump_speed)
			turtle_land_on_ground((uint8_t)d6, a0, p_d1, &d5, p_d7);
	}
	else
	{
		if (OBJECT(a0)->height + OBJECT(a0)->y < 0xF400u && (uint8_t)(OBJECT(a0)->height_whole - OBJECT(a0)->floor_height) >= 0x40u)
		{
			if ((mem_read8(a1) & 1u) != 0u)
			{
				if ((OBJECT(a0)->contacts & 0x10u) != 0u)
				{
					OBJECT(a0)->turtle.jump_flip = 0u;
					mem_write8(a1, 0u);
					OBJECT(a0)->turtle.jump_speed = 0u;
					d0 = 0x205u;
					turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
					OBJECT(a0)->turtle.move_timer = 8u;
					OBJECT(a0)->state = 4u;
					*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
					return;
				}
			}
			else if ((mem_read8(a1) & 2u) != 0u && (OBJECT(a0)->contacts & 8u) != 0u)
			{
				OBJECT(a0)->turtle.jump_flip = 0xFFu;
				mem_write8(a1, 0u);
				OBJECT(a0)->turtle.jump_speed = 0u;
				d0 = 0x205u;
				turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
				OBJECT(a0)->turtle.move_timer = 8u;
				OBJECT(a0)->state = 4u;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
		}
		if (OBJECT(a0)->turtle.move_timer != 0u)
		{
			move_timer = OBJECT(a0)->turtle.move_timer;
			OBJECT(a0)->turtle.move_timer = move_timer - 1u;
			if (move_timer == 1u)
			{
				jump_speed_2 = OBJECT(a0)->turtle.jump_speed;
				OBJECT(a0)->turtle.jump_speed = jump_speed_2 - 0x50u;
				if (jump_speed_2 >= 0x50u)
				{
					OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
					if (OBJECT(a0)->turtle.jump_speed < 0x380u && OBJECT(a0)->turtle.jump_flip == 0u)
					{
						OBJECT(a0)->turtle.jump_flip--;
						d0 = 0x204u;
						turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
						OBJECT(a0)->state = 2u;
					}
				}
				else
				{
					OBJECT(a0)->turtle.jump_speed = 0u - OBJECT(a0)->turtle.jump_speed;
					OBJECT(a0)->turtle.falling = ~OBJECT(a0)->turtle.falling;
				}
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			t1 = *p_d1 & 0x10u;
			*p_d1 = (*p_d1 & ~0xFFu) | t1;
			if (t1 != 0u)
			{
				OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
				if (OBJECT(a0)->turtle.jump_speed < 0x380u && OBJECT(a0)->turtle.jump_flip == 0u)
				{
					OBJECT(a0)->turtle.jump_flip--;
					d0 = 0x204u;
					turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
					OBJECT(a0)->state = 2u;
				}
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			OBJECT(a0)->turtle.move_timer = 0u;
			OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
			if (OBJECT(a0)->turtle.jump_speed < 0x380u && OBJECT(a0)->turtle.jump_flip == 0u)
			{
				OBJECT(a0)->turtle.jump_flip--;
				d0 = 0x204u;
				turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
				OBJECT(a0)->state = 2u;
			}
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		jump_speed_2 = OBJECT(a0)->turtle.jump_speed;
		OBJECT(a0)->turtle.jump_speed = jump_speed_2 - 0x50u;
		if (jump_speed_2 >= 0x50u)
		{
			OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
			if (OBJECT(a0)->turtle.jump_speed < 0x380u && OBJECT(a0)->turtle.jump_flip == 0u)
			{
				OBJECT(a0)->turtle.jump_flip--;
				d0 = 0x204u;
				turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_2, p_d7);
				OBJECT(a0)->state = 2u;
			}
		}
		else
		{
			OBJECT(a0)->turtle.jump_speed = 0u - OBJECT(a0)->turtle.jump_speed;
			OBJECT(a0)->turtle.falling = ~OBJECT(a0)->turtle.falling;
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the jump coming down until it lands */
void turtle_jump_fall(uint8_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t jump_speed = 0;
	uint16_t height = 0;

	if ((OBJECT(a0)->contacts & 1u) == 0u)
	{
		OBJECT(a0)->turtle.jump_speed += 0x50u;
		if (OBJECT(a0)->turtle.jump_speed >= 0x500u)
			OBJECT(a0)->turtle.jump_speed = 0x500u;
		jump_speed = OBJECT(a0)->turtle.jump_speed;
		height = OBJECT(a0)->height;
		OBJECT(a0)->height = height - jump_speed;
		if (height < jump_speed)
			turtle_land_on_ground(d6, a0, p_d1, &d5, p_d7);
	}
	else
	{
		OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
		OBJECT(a0)->height &= 0xFF00u;
		turtle_land(d6, a0, p_d1, &d5, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the turtle lands on the ground */
void turtle_land_on_ground(uint8_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	OBJECT(a0)->height = 0u;
	turtle_land(d6, a0, p_d1, &d5, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the turtle lands and stands, with the landing's sound */
void turtle_land(uint32_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0, ignored = 0, ignored_3 = 0;

	OBJECT(a0)->contacts &= 0x7Fu;
	d0 = 0u;
	if (OBJECT(a0)->turtle.has_gun != 0u)
		d0 = 4u;
	turtle_set_state(d0, a0, p_d1, &ignored, &d5, &ignored_3, &d7);
	d7_2 = (d7 & ~0xFFu) | 0x12u;
	if (stage == 3u && OBJECT(a0)->height == 0u)
		d7_2 = (d7_2 & ~0xFFu) | 0x30u;
	queue_sound((uint8_t)d7_2, 0u);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7_2;
}

/* the turtle on a wall for a moment, then away from it falling */
void turtle_wall_jump(uint8_t d6, uint32_t a0, uint32_t a1, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t jump_speed = 0;
	uint16_t height = 0;

	mem_write8(a1, 0u);
	if (OBJECT(a0)->turtle.move_timer == 0u)
	{
		if ((OBJECT(a0)->contacts & 1u) == 0u)
		{
			if (OBJECT(a0)->turtle.jump_flip != 0u)
			{
				if ((OBJECT(a0)->contacts & 0x10u) == 0u)
					OBJECT(a0)->x -= 0x300u;
			}
			else if ((OBJECT(a0)->contacts & 8u) == 0u)
				OBJECT(a0)->x += 0x300u;
			OBJECT(a0)->turtle.jump_speed += 0x28u;
			jump_speed = OBJECT(a0)->turtle.jump_speed;
			height = OBJECT(a0)->height;
			OBJECT(a0)->height = height - jump_speed;
			if (height < jump_speed)
				turtle_land_on_ground(d6, a0, p_d1, &d5, p_d7);
		}
		else
		{
			OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
			OBJECT(a0)->height &= 0xFF00u;
			turtle_land(d6, a0, p_d1, &d5, p_d7);
		}
	}
	else
		OBJECT(a0)->turtle.move_timer--;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* attacking: the jump attacks' arcs, steps forward, the end of the attack */
void turtle_attack(uint8_t d2, uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint8_t d2_2 = 0;
	uint16_t jump_speed = 0;
	uint32_t d0 = 0;
	uint8_t move_timer = 0, t1 = 0;
	uint16_t height = 0, jump_speed_2 = 0;

	turtles_busy--;
	if (OBJECT(a0)->state >= 8u)
	{
		mem_write8(a1, mem_read8(a1) & 0x10u);
		d0 = 0x400u;
		if (OBJECT(a0)->state != 9u)
		{
			d0 = (uint16_t)(d0 - 0x180u);
			if (OBJECT(a0)->state != 0xBu)
			{
				d0 = (uint16_t)(d0 - 0x80u);
				if (OBJECT(a0)->state != 0xAu)
					d0 = 0u;
			}
		}
		d1 = 3u;
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
		{
			d1 = (uint8_t)(d1 + 1u);
			d0 = 0u - d0;
		}
		if ((OBJECT(a0)->contacts & shl32(1u, (int)(d1))) == 0u)
			OBJECT(a0)->x += d0;
		if (OBJECT(a0)->turtle.falling != 0u)
		{
			if ((OBJECT(a0)->contacts & 1u) == 0u)
			{
				OBJECT(a0)->turtle.jump_speed += 0x40u;
				if (OBJECT(a0)->turtle.jump_speed >= 0x500u)
					OBJECT(a0)->turtle.jump_speed = 0x500u;
				jump_speed = OBJECT(a0)->turtle.jump_speed;
				height = OBJECT(a0)->height;
				OBJECT(a0)->height = height - jump_speed;
				if (height < jump_speed)
					turtle_land_on_ground(d6, a0, &d1, &d5, p_d7);
			}
			else
			{
				OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
				OBJECT(a0)->height &= 0xFF00u;
				turtle_land(d6, a0, &d1, &d5, p_d7);
			}
		}
		else if (OBJECT(a0)->turtle.move_timer == 0u)
		{
			jump_speed_2 = OBJECT(a0)->turtle.jump_speed;
			OBJECT(a0)->turtle.jump_speed = jump_speed_2 - 0x40u;
			if (jump_speed_2 >= 0x40u)
				OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
			else
			{
				OBJECT(a0)->turtle.jump_speed = 0u - OBJECT(a0)->turtle.jump_speed;
				OBJECT(a0)->turtle.falling = ~OBJECT(a0)->turtle.falling;
			}
		}
		else
		{
			move_timer = OBJECT(a0)->turtle.move_timer;
			OBJECT(a0)->turtle.move_timer = move_timer - 1u;
			if (move_timer == 1u)
			{
				jump_speed_2 = OBJECT(a0)->turtle.jump_speed;
				OBJECT(a0)->turtle.jump_speed = jump_speed_2 - 0x40u;
				if (jump_speed_2 >= 0x40u)
					OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
				else
				{
					OBJECT(a0)->turtle.jump_speed = 0u - OBJECT(a0)->turtle.jump_speed;
					OBJECT(a0)->turtle.falling = ~OBJECT(a0)->turtle.falling;
				}
			}
			else
			{
				t1 = mem_read8(a1) & 0x10u;
				mem_write8(a1, t1);
				if (t1 != 0u)
					OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
				else
				{
					OBJECT(a0)->turtle.move_timer = 0u;
					OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
				}
			}
		}
	}
	else if (OBJECT(a0)->frame_time == 0u)
		turtle_attack_over(d2, d6, a0, a1, a2, &d1, &d5, p_d7);
	else if (OBJECT(a0)->state == 3u)
		mem_write8(a1, mem_read8(a1) & 0xCu);
	else if (OBJECT(a0)->kind != 3u || OBJECT(a0)->state != 7u)
	{
		d0 = 0x40u;
		d1 = 1u;
		d2_2 = 3u;
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
		{
			d0 = 0u - d0;
			d1 = 0u;
			d2_2++;
		}
		if ((OBJECT(a0)->contacts & shl32(1u, (int)(d2_2))) != 0u || (mem_read8(a1) & shl32(1u, (int)(d1))) == 0u)
			mem_write8(a1, mem_read8(a1) & 0xCu);
		else
		{
			OBJECT(a0)->x += d0;
			mem_write8(a1, mem_read8(a1) & 0xCu);
		}
	}
	else
	{
		mem_write8(a1, 0u);
		d0 = 0x300u;
		d1 = 3u;
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
		{
			d0 = 0u - d0;
			d1 = (uint8_t)(d1 + 1u);
		}
		if ((OBJECT(a0)->contacts & shl32(1u, (int)(d1))) == 0u)
		{
			OBJECT(a0)->x += d0;
			mem_write8(a1, mem_read8(a1) & 0xCu);
		}
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the attack ended: the combo's next attack, the throw, or back to standing */
void turtle_attack_over(uint8_t d2, uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0, animation = 0, d1_2 = 0, ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	OBJECT(a0)->contacts &= 0x7Fu;
	if (area_beaten != 0u)
	{
		OBJECT(a0)->flags &= ~0xCu;
		d0 = 0u;
		if (OBJECT(a0)->turtle.has_gun == 0u)
		{
			turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		d0 = 4u;
		turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
		*p_d1 = d1;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	if (OBJECT(a0)->state == 5u)
	{
		OBJECT(a0)->flags |= 8u;
		*p_d7 = (*p_d7 & ~0xFFFFu) | 0x401u;
		if (OBJECT(a0)->kind != 0u)
		{
			*p_d7 = (*p_d7 & ~0xFFFFu) | 0x408u;
			if (OBJECT(a0)->kind != 3u)
			{
				OBJECT(a0)->flags ^= 0x40u;
				*p_d7 = (*p_d7 & ~0xFFFFu) | 0x402u;
				if ((OBJECT(a0)->kind & 1u) == 0u)
					*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)(*p_d7 + 2u);
			}
		}
		queue_job((uint16_t)*p_d7);
	}
	if (OBJECT(a0)->turtle.attack_press_time < 0xDu)
	{
		if (area_beaten != 0u)
		{
			OBJECT(a0)->flags &= ~0xCu;
			d0 = 0u;
			if (OBJECT(a0)->turtle.has_gun == 0u)
			{
				turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
				*p_d1 = d1;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			d0 = 4u;
			turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		if (OBJECT(a0)->turtle.has_gun != 0u)
		{
			turtle_start_combo(d6, a0, a1, &d1, &d5, p_d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		if ((OBJECT(a0)->flags & 8u) == 0u)
		{
			OBJECT(a0)->flags &= ~0xCu;
			if ((d2 & 0x10u) != 0u)
			{
				turtle_start_jump(d6, a0, a1, a2, &d1, &d5, p_d7);
				*p_d1 = d1;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			if ((d2 & 0x20u) != 0u)
			{
				turtle_start_combo(d6, a0, a1, &d1, &d5, p_d7);
				*p_d1 = d1;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			t1 = d1 & 0xFu;
			d1 = (d1 & ~0xFFu) | t1;
			if (t1 != 0u)
			{
				turtle_start_walk(d6, a0, &d1, &d5, p_d7);
				*p_d1 = d1;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			OBJECT(a0)->flags &= ~0xCu;
			d0 = 0u;
			if (OBJECT(a0)->turtle.has_gun == 0u)
			{
				turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
				*p_d1 = d1;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			d0 = 4u;
			turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		OBJECT(a0)->flags &= ~8u;
		OBJECT(a0)->flags |= 4u;
		if (OBJECT(a0)->turtle.combo_step == 0u)
		{
			OBJECT(a0)->turtle.combo_step++;
			a4 = rom_01D5F2[OBJECT(a0)->kind & 3u];
			if (OBJECT(a0)->turtle.enemy_behind != 0u)
			{
				OBJECT(a0)->turtle.combo += 0xCu;
				mem_write8(a1, 0u);
				*p_d7 = (*p_d7 & ~0xFFFFu) | OBJECT(a0)->turtle.combo;
				d0 = mem_read8(a4 + 1u + (int16_t)*p_d7);
				d1_2 = (d1 & ~0xFFu) | d0;
				d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[OBJECT(a0)->kind & 3u]);
				if ((OBJECT(a0)->flags & 0x40u) != 0u)
					d1_2 = d1_2 | 0x80u;
				if (d0 == 3u)
					d1_2 = d1_2 ^ 0x80u;
				OBJECT(a0)->attack = d1_2;
				d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
				*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
				queue_sound((uint8_t)*p_d7, a6);
				d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
				OBJECT(a0)->damage = rom_01D592[(uint16_t)d1_2 / 2u];
				d0 = (uint16_t)((d0 & 7u) + 0x300u);
				turtle_set_state(d0, a0, &d1_2, &ignored, &d5, &ignored_2, p_d7);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			a6 = OBJECT(a0)->turtle.hit_target;
			if ((int8_t)mem_read8(a6 + 0x4Bu) < 0 && mem_read8(a6 + 9u) != 0u && mem_read8(a6 + 0x10u) == mem_read8(a6 + 0x32u))
			{
				d0 = (uint16_t)((uint32_t)OBJECT(a0)->kind << 1);
				d1_2 = (d1 & ~0xFFFFu) | d0;
				d0 = (uint16_t)(((uint32_t)d0 << 1) + d1_2);
				d1 = LINKED(d1_2, indexed_table_of_16_bit_values_01C072[d0 / 2u]);
				a5 = TABLE32(rom_01C074, d0);
				if (mem_read16(a5) >= 0x100u)
				{
					mem_write16(a5, 0u);
					OBJECT(a0)->turtle.idle_time = 0u;
					mem_write8(a1, 0u);
					mem_write16(a6 + 4u, 0x500u);
					mem_write16(a6 + 0x28u, d1);
					d0_2 = 0u;
					if ((OBJECT(a0)->flags & 0x40u) == 0u)
						d0_2 = 0x80u;
					mem_write8(a6 + 0x30u, d0_2);
					OBJECT(a0)->turtle.combo += 0x18u;
					d1_2 = (d1 & ~0xFFFFu) | 5u;
					OBJECT(a0)->routine = 3u;
					OBJECT(a0)->state = 5u;
					if (OBJECT(a0)->kind == 0u || OBJECT(a0)->kind == 3u)
						OBJECT(a0)->flags ^= 0x40u;
					d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[OBJECT(a0)->kind & 3u]);
					if ((OBJECT(a0)->flags & 0x40u) != 0u)
						d1_2 = d1_2 | 0x80u;
					OBJECT(a0)->attack = d1_2;
					d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
					*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
					queue_sound((uint8_t)*p_d7, a6);
					d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
					OBJECT(a0)->damage = rom_01D592[(uint16_t)d1_2 / 2u];
					animation = mem_read32(animations_01C08A[OBJECT(a0)->kind] - 0x10u + (uint16_t)((mem_read8(OBJECT(a0)->turtle.hit_target + 0x4Bu) & 7u) << 2));
					d1_2 = set_animation(d1_2, a0, animation);
					*p_d1 = d1_2;
					*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
					return;
				}
			}
			t2 = mem_read8(a1) & 3u;
			mem_write8(a1, t2);
			if (t2 == 0u)
			{
				mem_write8(a1, 0u);
				*p_d7 = (*p_d7 & ~0xFFFFu) | OBJECT(a0)->turtle.combo;
				d0 = mem_read8(a4 + 1u + (int16_t)*p_d7);
				d1_2 = (d1 & ~0xFFu) | d0;
				d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[OBJECT(a0)->kind & 3u]);
				if ((OBJECT(a0)->flags & 0x40u) != 0u)
					d1_2 = d1_2 | 0x80u;
				if (d0 == 3u)
					d1_2 = d1_2 ^ 0x80u;
				OBJECT(a0)->attack = d1_2;
				d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
				*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
				queue_sound((uint8_t)*p_d7, a6);
				d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
				OBJECT(a0)->damage = rom_01D592[(uint16_t)d1_2 / 2u];
				d0 = (uint16_t)((d0 & 7u) + 0x300u);
				turtle_set_state(d0, a0, &d1_2, &ignored, &d5, &ignored_2, p_d7);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			if ((mem_read8(a1) & 1u) != 0u)
			{
				OBJECT(a0)->flags |= 0x40u;
				mem_write8(a1, 0u);
				*p_d7 = (*p_d7 & ~0xFFFFu) | OBJECT(a0)->turtle.combo;
				d0 = mem_read8(a4 + 1u + (int16_t)*p_d7);
				d1_2 = (d1 & ~0xFFu) | d0;
				d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[OBJECT(a0)->kind & 3u]);
				if ((OBJECT(a0)->flags & 0x40u) != 0u)
					d1_2 = d1_2 | 0x80u;
				if (d0 == 3u)
					d1_2 = d1_2 ^ 0x80u;
				OBJECT(a0)->attack = d1_2;
				d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
				*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
				queue_sound((uint8_t)*p_d7, a6);
				d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
				OBJECT(a0)->damage = rom_01D592[(uint16_t)d1_2 / 2u];
				d0 = (uint16_t)((d0 & 7u) + 0x300u);
				turtle_set_state(d0, a0, &d1_2, &ignored, &d5, &ignored_2, p_d7);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
			OBJECT(a0)->flags &= 0xBFu;
			mem_write8(a1, 0u);
			*p_d7 = (*p_d7 & ~0xFFFFu) | OBJECT(a0)->turtle.combo;
			d0 = mem_read8(a4 + 1u + (int16_t)*p_d7);
			d1_2 = (d1 & ~0xFFu) | d0;
			d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[OBJECT(a0)->kind & 3u]);
			if ((OBJECT(a0)->flags & 0x40u) != 0u)
				d1_2 = d1_2 | 0x80u;
			if (d0 == 3u)
				d1_2 = d1_2 ^ 0x80u;
			OBJECT(a0)->attack = d1_2;
			d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
			*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
			queue_sound((uint8_t)*p_d7, a6);
			d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
			OBJECT(a0)->damage = rom_01D592[(uint16_t)d1_2 / 2u];
			d0 = (uint16_t)((d0 & 7u) + 0x300u);
			turtle_set_state(d0, a0, &d1_2, &ignored, &d5, &ignored_2, p_d7);
			*p_d1 = d1_2;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		if (OBJECT(a0)->turtle.combo_step != 1u)
		{
			turtle_start_combo(d6, a0, a1, &d1, &d5, p_d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		if (OBJECT(a0)->state != 5u)
		{
			t3 = mem_read8(a1) & 3u;
			mem_write8(a1, t3);
			if (t3 != 0u)
			{
				if ((mem_read8(a1) & 1u) != 0u)
					OBJECT(a0)->flags |= 0x40u;
				else
					OBJECT(a0)->flags &= 0xBFu;
			}
		}
		mem_write8(a1, 0u);
		OBJECT(a0)->turtle.combo_step++;
		*p_d7 = (*p_d7 & ~0xFFFFu) | OBJECT(a0)->turtle.combo;
		d0 = mem_read8(rom_01D5F2[OBJECT(a0)->kind & 3u] + 2u + (int16_t)*p_d7);
		d1_2 = (d1 & ~0xFFu) | d0;
		d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + indexed_table_of_8_bit_values_01C20E[OBJECT(a0)->kind & 3u]);
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
			d1_2 = d1_2 | 0x80u;
		if (d0 == 3u)
			d1_2 = d1_2 ^ 0x80u;
		OBJECT(a0)->attack = d1_2;
		d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
		*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D526[(uint16_t)d1_2];
		queue_sound((uint8_t)*p_d7, 0u);
		d1_2 = LINKED(d1_2, (uint16_t)(d1_2 << 1));
		OBJECT(a0)->damage = rom_01D592[(uint16_t)d1_2 / 2u];
		d0 = (uint16_t)((d0 & 7u) + 0x300u);
		turtle_set_state(d0, a0, &d1_2, &ignored, &d5, &ignored_2, p_d7);
		*p_d1 = d1_2;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	OBJECT(a0)->flags &= ~0xCu;
	if ((d2 & 0x10u) != 0u)
	{
		turtle_start_jump(d6, a0, a1, a2, &d1, &d5, p_d7);
		*p_d1 = d1;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	if ((d2 & 0x20u) != 0u)
	{
		turtle_start_combo(d6, a0, a1, &d1, &d5, p_d7);
		*p_d1 = d1;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	t1 = d1 & 0xFu;
	d1 = (d1 & ~0xFFu) | t1;
	if (t1 != 0u)
	{
		turtle_start_walk(d6, a0, &d1, &d5, p_d7);
		*p_d1 = d1;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	OBJECT(a0)->flags &= ~0xCu;
	d0 = 0u;
	if (OBJECT(a0)->turtle.has_gun == 0u)
	{
		turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
		*p_d1 = d1;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	d0 = 4u;
	turtle_set_state(d0, a0, &d1, &ignored, &d5, &ignored_2, p_d7);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* hit: the reaction by the attack that hit it, and out of play when its bars run out */
void turtle_hit(uint32_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0, d2 = 0, floor_height = 0;
	uint32_t a6 = 0, d1_2 = 0, d7_2 = 0, ignored = 0, ignored_2 = 0;
	uint8_t health_bars = 0;

	mem_write8(a1, 0u);
	OBJECT(a0)->flags &= ~0xEu;
	if (OBJECT(a0)->state == 0u)
	{
		d7_2 = (d7 & ~0xFFu) | rom_01D556[mem_read16(OBJECT(a0)->turtle.hit_by + 0x28u) >> 2];
		if ((uint8_t)d7_2 != 0xFFu)
			queue_sound((uint8_t)d7_2, 0u);
		OBJECT(a0)->turtle.falling = 0u;
		OBJECT(a0)->turtle.hit_reaction = 0u;
		OBJECT(a0)->turtle.reaction_step = 0u;
		OBJECT(a0)->turtle.reaction_variant = 0u;
		OBJECT(a0)->turtle.wait_timer = 0u;
		d0 = 0u;
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
		{
			if ((int8_t)OBJECT(a0)->hit >= 0)
			{
				d0 = 0x80u;
				d0 = d0 | 1u;
			}
		}
		else if ((int8_t)OBJECT(a0)->hit >= 0)
			d0 = d0 | 1u;
		else
			d0 = 0x80u;
		OBJECT(a0)->turtle.knockback_flags = (uint8_t)d0;
		if ((uint8_t)(OBJECT(a0)->hit_routine >> 8u) == 4u)
		{
			d1_2 = IN_PAGE(d1, OBJECT(a0)->hit);
			d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
			if ((uint8_t)d1_2 != 0xFu && (uint8_t)d1_2 != 0x10u)
			{
				d1_2 = 0x15u;
				if (OBJECT(a0)->turtle.escape_presses != 0x10u && OBJECT(a0)->turtle.escape_presses >= 5u)
					OBJECT(a0)->turtle.escape_presses = 4u;
				OBJECT(a0)->turtle.hit_reaction = d1_2;
				d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
				turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
				d7_2 = turtle_save_health(d7_2, a0);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				*p_d7 = d7_2;
				return;
			}
		}
		else
		{
			if ((uint8_t)(OBJECT(a0)->hit_routine >> 8u) == 3u && OBJECT(a0)->turtle.combo >= 0x18u)
			{
				a6 = OBJECT(a0)->turtle.hit_target;
				if ((mem_read8(a6) & 0x80u) == 0u)
				{
					mem_write16(a6 + 4u, 0x500u);
					d1 = LINKED(d1, OBJECT(a0)->kind);
					d1 = LINKED(d1, (uint16_t)(d1 << 1));
					mem_write16(a6 + 0x28u, rom_01C596[(uint16_t)d1 / 2u]);
				}
			}
			d1_2 = IN_PAGE(d1, OBJECT(a0)->hit);
			d1_2 = LINKED(d1_2, d1_2 & 0x7Fu);
			if ((uint8_t)d1_2 == 0xEu)
			{
				OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
				OBJECT(a0)->height &= 0xFF00u;
			}
			if ((uint8_t)d1_2 == 0x18u)
			{
				if (OBJECT(a0)->health_bars == 0u)
				{
					d7_2 = (d7_2 & ~0xFFu) | 0x26u;
					queue_sound((uint8_t)d7_2, a6);
					if ((int8_t)OBJECT(a0)->turtle.knockback_flags >= 0 || (uint8_t)d1_2 >= 9u)
					{
						OBJECT(a0)->turtle.hit_reaction = d1_2;
						d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
						turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
						d7_2 = turtle_save_health(d7_2, a0);
						*p_d1 = d1_2;
						*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
						*p_d7 = d7_2;
						return;
					}
					d1_2 = 6u;
					OBJECT(a0)->turtle.hit_reaction = d1_2;
					d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
					turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
					d7_2 = turtle_save_health(d7_2, a0);
					*p_d1 = d1_2;
					*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
					*p_d7 = d7_2;
					return;
				}
				d1_2 = 4u;
			}
		}
		if (OBJECT(a0)->turtle.escape_presses != 0x10u)
			OBJECT(a0)->turtle.escape_presses = 0u;
		if (OBJECT(a0)->health_bars == 0u && (uint8_t)d1_2 < 9u)
		{
			d1_2 = 7u;
			OBJECT(a0)->hit = 7u;
		}
		for (;;)
		{
			floor_height = OBJECT(a0)->floor_height;
			if (floor_height != OBJECT(a0)->height_whole)
			{
				if ((uint8_t)d1_2 >= 9u)
				{
					OBJECT(a0)->turtle.hit_reaction = d1_2;
					d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
					turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
					d7_2 = turtle_save_health(d7_2, a0);
					*p_d1 = d1_2;
					*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
					*p_d7 = d7_2;
					return;
				}
				if ((uint8_t)d1_2 < 4u)
				{
					d1_2 = 4u;
					if (OBJECT(a0)->health != 0u)
					{
						health_bars = OBJECT(a0)->health_bars;
						OBJECT(a0)->health_bars = health_bars - 1u;
						if (health_bars == 1u)
						{
							d1_2 = 7u;
							OBJECT(a0)->hit = 7u;
							continue;
						}
						d1_2 = 0x16u;
					}
				}
				if ((int8_t)OBJECT(a0)->turtle.knockback_flags >= 0)
					break;
				if ((uint8_t)d1_2 == 4u)
				{
					OBJECT(a0)->flags ^= 0x40u;
					OBJECT(a0)->turtle.knockback_flags &= 0x7Fu;
					break;
				}
				d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + 1u);
				break;
			}
			if (OBJECT(a0)->health != 0u)
			{
				if ((int8_t)OBJECT(a0)->turtle.knockback_flags < 0 && (uint8_t)d1_2 < 9u)
					d1_2 = 6u;
				OBJECT(a0)->turtle.hit_reaction = d1_2;
				d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
				turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
				d7_2 = turtle_save_health(d7_2, a0);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				*p_d7 = d7_2;
				return;
			}
			if ((uint8_t)d1_2 >= 9u)
			{
				OBJECT(a0)->turtle.hit_reaction = d1_2;
				d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
				turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
				d7_2 = turtle_save_health(d7_2, a0);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				*p_d7 = d7_2;
				return;
			}
			if ((uint8_t)d1_2 < 4u)
				d1_2 = 4u;
			if ((int8_t)OBJECT(a0)->turtle.knockback_flags >= 0)
				break;
			d1_2 = (d1_2 & ~0xFFu) | (uint8_t)(d1_2 + 1u);
			break;
		}
		d2 = (uint16_t)(d1_2 << 2);
		OBJECT(a0)->turtle.drift_speed = TABLE16(table_loaded_by_lea_01C546, d2 - 0x10u);
		OBJECT(a0)->turtle.jump_speed = TABLE16(table_loaded_by_lea_01C546, d2 - 0xEu);
		d0 = (uint8_t)frame_count;
		d0 = d0 & 1u;
		OBJECT(a0)->turtle.reaction_variant = (uint8_t)d0;
		d6 = 0xE000u;
		d7_2 = 0x12000u;
		if ((uint8_t)d1_2 != 4u)
		{
			if ((uint8_t)d1_2 != 5u)
			{
				OBJECT(a0)->turtle.hit_reaction = d1_2;
				d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
				turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
				d7_2 = turtle_save_health(d7_2, a0);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				*p_d7 = d7_2;
				return;
			}
			d6 = 0x10000u;
			d7_2 = 0x10000u;
		}
		if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
		{
			if (OBJECT(a0)->x <= d7_2)
			{
				d0 = 0u;
				if (OBJECT(a0)->health_bars < 5u)
					d0 = (uint8_t)(d0 + 1u);
				OBJECT(a0)->turtle.reaction_variant = (uint8_t)d0;
				OBJECT(a0)->turtle.hit_reaction = d1_2;
				d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
				turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
				d7_2 = turtle_save_health(d7_2, a0);
				*p_d1 = d1_2;
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				*p_d7 = d7_2;
				return;
			}
			OBJECT(a0)->turtle.reaction_variant += 2u;
			OBJECT(a0)->turtle.hit_reaction = d1_2;
			d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
			turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
			d7_2 = turtle_save_health(d7_2, a0);
			*p_d1 = d1_2;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			*p_d7 = d7_2;
			return;
		}
		if (d6 < OBJECT(a0)->x)
		{
			d0 = 0u;
			if (OBJECT(a0)->health_bars < 5u)
				d0 = (uint8_t)(d0 + 1u);
			OBJECT(a0)->turtle.reaction_variant = (uint8_t)d0;
			OBJECT(a0)->turtle.hit_reaction = d1_2;
			d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
			turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
			d7_2 = turtle_save_health(d7_2, a0);
			*p_d1 = d1_2;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			*p_d7 = d7_2;
			return;
		}
		OBJECT(a0)->turtle.reaction_variant += 2u;
		OBJECT(a0)->turtle.hit_reaction = d1_2;
		d0 = (uint16_t)(rom_01D3FC[(uint16_t)d1_2] + 0x400u);
		turtle_set_state(d0, a0, &d1_2, &ignored_2, &d5, &ignored, &d7_2);
		d7_2 = turtle_save_health(d7_2, a0);
		*p_d1 = d1_2;
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		*p_d7 = d7_2;
		return;
	}
	switch (OBJECT(a0)->turtle.hit_reaction)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 6:
	case 13:
		turtle_hit_wait(a0);
		break;
	case 4:
		turtle_knocked_down(a0, &d1, &d5, &ignored, &d7);
		break;
	case 5:
		turtle_knocked_back(a0, &d1, &d5, &ignored, &d7);
		break;
	case 7:
		turtle_knocked_flying(a0, &d1, &d5, &ignored, &d7);
		break;
	case 8:
		turtle_knocked_flying_from_behind(a0, &d1, &d5, &ignored, &d7);
		break;
	case 9:
		turtle_frozen(a0, &d1, &d5, &ignored, &d7);
		break;
	case 10:
	case 11:
		turtle_shocked(a0, &d1, &d5, &ignored, &d7);
		break;
	case 12:
		turtle_fall_in_manhole(a0, &d1, &d5, &ignored, &d7);
		break;
	case 14:
		turtle_held(a0, a2, &d1, &d5, &ignored, &d7);
		break;
	case 15:
		turtle_held_knock_off(a0, a2, &d1, &d5, &ignored, &d7);
		break;
	case 16:
		turtle_held_throw_off(a0, a2, &d1, &d5, &ignored, &d7);
		break;
	case 17:
	case 18:
	case 19:
	case 20:
		d7 = turtle_refill_health(d7, a0);
		break;
	case 21:
		turtle_held_briefly(a0, a2, &d1, &d5, &ignored, &d7);
		break;
	case 22:
	case 23:
		d7 = turtle_hit_fly(a0);
		break;
	case 24:
		turtle_hit_by_shredder_ray(a0, &d1, &d5, &ignored, &d7);
		break;
	case 25:
		turtle_walk_off_screen(a0);
		break;
	}
	if (OBJECT(a0)->turtle.reaction_step == 0xFFu)
	{
		if (OBJECT(a0)->health == 0u)
			OBJECT(a0)->health = 3u;
		if (OBJECT(a0)->health_bars != 0u)
		{
			d0 = 0u;
			turtle_set_state(d0, a0, &d1, &ignored_2, &d5, &ignored, &d7);
			*p_d1 = d1;
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			*p_d7 = d7;
			return;
		}
		time_without_knockout = 0u;
		OBJECT(a0)->flags = 0u;
		players_knocked_out |= shl32(1u, (int)(OBJECT(a0)->kind & 7u));
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* the reaction lasts its animation */
void turtle_hit_wait(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
		OBJECT(a0)->turtle.reaction_step = 0xFFu;
}

/* the turtle's health full again */
uint32_t turtle_refill_health(uint32_t d7, uint32_t a0)
{
	OBJECT(a0)->turtle.reaction_step = 0xFFu;
	OBJECT(a0)->health_bars = 0xAu;
	OBJECT(a0)->health = 3u;
	return turtle_save_health(d7, a0);
}

/* Shredder's ray turns the turtle into an ordinary turtle; with no lives left it walks off the screen */
void turtle_hit_by_shredder_ray(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0, d2 = 0;
	uint32_t ignored = 0;
	uint16_t screen_y = 0;

	OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
	OBJECT(a0)->height &= 0xFF00u;
	if (OBJECT(a0)->frame_time != 0u)
	{
		if (OBJECT(a0)->frame_time == 0x30u)
		{
			d0 = (uint16_t)((uint32_t)OBJECT(a0)->kind << 3);
			if (PLAYER(PLAYER_ADDRESS(0) + (d0 / 8u) * 0x8u)->lives == 0u)
			{
				*p_d1 = (*p_d1 & ~0xFFFFu) | OBJECT(a0)->screen_x;
				screen_y = OBJECT(a0)->screen_y;
				d2 = (uint16_t)(screen_y - 0x20u);
				if (screen_y < 0x20u)
					d2 = 0u;
				say_shell_shock(d0, d2, a0, p_d1, &ignored, &d5, &d6, p_d7);
			}
		}
	}
	else if (PLAYER(PLAYER_ADDRESS(0) + (OBJECT(a0)->kind) * 0x8u)->lives == 0u)
	{
		OBJECT(a0)->turtle.hit_reaction++;
		d0 = 0x42Bu;
		turtle_set_state(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	}
	else
		OBJECT(a0)->turtle.reaction_step = 0xFFu;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the turtle walks off the screen */
void turtle_walk_off_screen(uint32_t a0)
{
	uint32_t d0 = 0;

	d0 = 0x200u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		d0 = 0u - d0;
	OBJECT(a0)->x += d0;
	if (OBJECT(a0)->x >= 0x16000u || OBJECT(a0)->x < 0x9100u)
		OBJECT(a0)->turtle.reaction_step = 0xFFu;
}

/* knocked down: flies, slides, lies, gets up */
void turtle_knocked_down(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (OBJECT(a0)->turtle.reaction_step)
	{
	case 0:
		turtle_knocked_down_fly(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 1:
		turtle_knocked_down_slide(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
	case 3:
		turtle_knocked_down_lie(a0, p_d1, &d5, &d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_down_fly(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	OBJECT(a0)->turtle.wait_timer = 8u;
	*p_d7 = 0x60u;
	turtle_knockback_arc((uint16_t)*p_d7, a0);
	if (OBJECT(a0)->turtle.falling != 0u && ((OBJECT(a0)->contacts & 1u) != 0u || OBJECT(a0)->height == 0u))
		turtle_knocked_down_next(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_down_slide(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;

	turtle_drop_to_floor(a0);
	if (OBJECT(a0)->frame_time == 0u)
		turtle_knocked_down_next(a0, &d1, &d5, &d6, p_d7);
	else
	{
		d0 = 0u;
		if (OBJECT(a0)->turtle.wait_timer != 0u)
		{
			OBJECT(a0)->turtle.wait_timer--;
			d0 = 0x100u;
		}
		if (OBJECT(a0)->turtle.reaction_variant >= 2u)
			d0 = 0x280u;
		d1 = 3u;
		if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
		{
			d0 = (uint16_t)(0u - d0);
			d1 = (uint16_t)(d1 + 1u);
		}
		if ((OBJECT(a0)->contacts & shl32(1u, (int)(d1))) == 0u)
		{
			OBJECT(a0)->x += (int16_t)d0;
			if (OBJECT(a0)->x < 0x16000u)
			{
				if (OBJECT(a0)->x < 0x9000u)
					OBJECT(a0)->x = 0x9000u;
			}
			else
				OBJECT(a0)->x = 0x16000u;
		}
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_down_lie(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	turtle_drop_to_floor(a0);
	if (OBJECT(a0)->frame_time == 0u)
		turtle_knocked_down_next(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_down_next(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	OBJECT(a0)->turtle.reaction_step++;
	d0 = (uint16_t)((uint32_t)OBJECT(a0)->turtle.reaction_variant << 2);
	a6 = indexed_table_of_32_bit_values_01C764[d0 / 4u];
	d0 = (uint16_t)IN_PAGE(d0, OBJECT(a0)->turtle.reaction_step);
	t1 = mem_read8(a6 + d0);
	d0 = (uint16_t)IN_PAGE(d0, t1);
	if ((int8_t)t1 < 0)
	{
		OBJECT(a0)->turtle.reaction_step = (uint8_t)d0;
		return;
	}
	d0 += 0x400u;
	turtle_set_state(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the turtle comes down to its floor */
void turtle_drop_to_floor(uint32_t a0)
{
	uint8_t height_whole = 0;
	uint16_t height = 0;

	if ((OBJECT(a0)->contacts & 1u) != 0u)
		return;
	height = OBJECT(a0)->height;
	OBJECT(a0)->height = height - 0x300u;
	if (height >= 0x300u)
	{
		height_whole = OBJECT(a0)->height_whole;
		if (height_whole == OBJECT(a0)->floor_height || height_whole < OBJECT(a0)->floor_height)
		{
			OBJECT(a0)->contacts |= 1u;
			OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
			OBJECT(a0)->height &= 0xFF00u;
		}
		return;
	}
	OBJECT(a0)->contacts |= 1u;
	OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
	OBJECT(a0)->height &= 0xFF00u;
}

/* knocked back: pushed, slides, gets up */
void turtle_knocked_back(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (OBJECT(a0)->turtle.reaction_step)
	{
	case 0:
		turtle_knocked_back_start(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 1:
		turtle_knocked_back_slide(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
	case 3:
		turtle_knocked_back_lie(a0, p_d1, &d5, &d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_back_start(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d0 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		if (OBJECT(a0)->turtle.reaction_variant < 2u)
			turtle_knocked_back_next(a0, p_d1, &d5, &d6, p_d7);
		else
		{
			d0 = 0x1800u;
			if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
				d0 = 0u - d0;
			OBJECT(a0)->x += d0;
			turtle_knocked_back_next(a0, p_d1, &d5, &d6, p_d7);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_back_slide(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;

	turtle_drop_to_floor(a0);
	if (OBJECT(a0)->frame_time == 0u)
		turtle_knocked_back_next(a0, &d1, &d5, &d6, p_d7);
	else
	{
		d0 = 0u;
		if (OBJECT(a0)->turtle.reaction_variant >= 2u)
			d0 = 0x280u;
		d1 = 3u;
		if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
		{
			d0 = (uint16_t)(0u - d0);
			d1 = (uint16_t)(d1 + 1u);
		}
		if ((OBJECT(a0)->contacts & shl32(1u, (int)(d1))) == 0u)
		{
			OBJECT(a0)->x += (int16_t)d0;
			if (OBJECT(a0)->x < 0x16000u)
			{
				if (OBJECT(a0)->x < 0x9000u)
					OBJECT(a0)->x = 0x9000u;
			}
			else
				OBJECT(a0)->x = 0x16000u;
		}
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_back_lie(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	turtle_drop_to_floor(a0);
	if (OBJECT(a0)->frame_time == 0u)
		turtle_knocked_back_next(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_back_next(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t a6 = 0, d0_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	OBJECT(a0)->turtle.reaction_step++;
	d0 = (uint16_t)((uint32_t)OBJECT(a0)->turtle.reaction_variant << 2);
	a6 = indexed_table_of_32_bit_values_01C8CA[d0 / 4u];
	d0 = (uint16_t)IN_PAGE(d0, OBJECT(a0)->turtle.reaction_step);
	t1 = mem_read8(a6 + d0);
	d0 = (uint16_t)IN_PAGE(d0, t1);
	if ((int8_t)t1 < 0)
	{
		OBJECT(a0)->turtle.reaction_step = (uint8_t)d0;
		if (OBJECT(a0)->turtle.reaction_variant < 2u)
		{
			d0_2 = reset_ADDRESS;
			if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
				d0_2 = 0u - d0_2;
			OBJECT(a0)->x += d0_2;
		}
	}
	else
	{
		d0 += 0x400u;
		turtle_set_state(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* knocked flying, or knocked out by the hit that takes its last bar */
void turtle_knocked_flying(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (OBJECT(a0)->turtle.reaction_step)
	{
	case 0:
		turtle_knocked_flying_fly(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 1:
		turtle_knocked_flying_slide(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
	case 3:
		turtle_knocked_flying_lie(a0, p_d1, &d5, &d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_flying_fly(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint8_t d0 = 0;
	uint32_t d7_2 = 0;

	OBJECT(a0)->turtle.wait_timer = 8u;
	d0 = 3u;
	if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
		d0++;
	if ((OBJECT(a0)->contacts & shl32(1u, (int)(d0))) == 0u)
	{
		d7_2 = 0x50u;
		turtle_knockback_arc((uint16_t)d7_2, a0);
		if (OBJECT(a0)->turtle.falling != 0u && (OBJECT(a0)->height == 0u || (OBJECT(a0)->contacts & 1u) != 0u))
		{
			d0 = 0u;
			if (OBJECT(a0)->health_bars < 5u)
				d0++;
			if (OBJECT(a0)->health_bars == 0u)
				d0 = 3u;
			OBJECT(a0)->turtle.reaction_variant = d0;
			turtle_knocked_flying_next(a0, p_d1, &d5, &d6, &d7_2);
		}
	}
	else
	{
		d7_2 = (d7 & ~0xFFu) | 0x89u;
		queue_sound((uint8_t)d7_2, 0u);
		d0 = 2u;
		if (OBJECT(a0)->health_bars == 0u)
			d0 = 4u;
		OBJECT(a0)->turtle.reaction_variant = d0;
		turtle_knocked_flying_next(a0, p_d1, &d5, &d6, &d7_2);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7_2;
}

void turtle_knocked_flying_slide(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d0 = 0;
	uint16_t height = 0;

	if (OBJECT(a0)->turtle.reaction_variant == 2u || OBJECT(a0)->turtle.reaction_variant == 4u)
	{
		if (OBJECT(a0)->frame_time == 0u)
		{
			if ((OBJECT(a0)->contacts & 1u) != 0u)
				turtle_knocked_flying_wait(a0, p_d1, &d5, &d6, p_d7);
			else
			{
				height = OBJECT(a0)->height;
				OBJECT(a0)->height = height - 0x100u;
				if (height >= 0x100u)
				{
					if (OBJECT(a0)->height_whole < OBJECT(a0)->floor_height)
					{
						OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
						OBJECT(a0)->height &= 0xFF00u;
						turtle_knocked_flying_wait(a0, p_d1, &d5, &d6, p_d7);
					}
				}
				else
				{
					OBJECT(a0)->height = 0u;
					OBJECT(a0)->floor_height = 0u;
					turtle_knocked_flying_wait(a0, p_d1, &d5, &d6, p_d7);
				}
			}
		}
	}
	else
	{
		if (OBJECT(a0)->turtle.wait_timer != 0u)
		{
			OBJECT(a0)->turtle.wait_timer--;
			d0 = 0x100u;
			if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
				d0 = 0u - d0;
			OBJECT(a0)->x += d0;
			if (OBJECT(a0)->x < 0x16000u)
			{
				if (OBJECT(a0)->x < 0x9000u)
					OBJECT(a0)->x = 0x9000u;
			}
			else
				OBJECT(a0)->x = 0x16000u;
		}
		if (OBJECT(a0)->frame_time == 0u)
			turtle_knocked_flying_wait(a0, p_d1, &d5, &d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_flying_lie(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint8_t wait_timer = 0;

	turtle_drop_to_floor(a0);
	if (OBJECT(a0)->state == 0x11u)
	{
		wait_timer = OBJECT(a0)->turtle.wait_timer;
		OBJECT(a0)->turtle.wait_timer = wait_timer - 1u;
		if (wait_timer == 1u)
			turtle_knocked_flying_wait(a0, p_d1, &d5, &d6, p_d7);
	}
	else if (OBJECT(a0)->frame_time == 0u)
		turtle_knocked_flying_next(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_flying_wait(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	OBJECT(a0)->turtle.wait_timer = 0x60u;
	turtle_knocked_flying_next(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void turtle_knocked_flying_next(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	OBJECT(a0)->turtle.reaction_step++;
	d0 = (uint16_t)((uint32_t)OBJECT(a0)->turtle.reaction_variant << 2);
	a6 = indexed_table_of_32_bit_values_01CA82[d0 / 4u];
	d0 = (uint16_t)IN_PAGE(d0, OBJECT(a0)->turtle.reaction_step);
	t1 = mem_read8(a6 + d0);
	d0 = (uint16_t)IN_PAGE(d0, t1);
	if ((int8_t)t1 < 0)
	{
		OBJECT(a0)->turtle.reaction_step = (uint8_t)d0;
		return;
	}
	d0 += 0x400u;
	turtle_set_state(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* knocked flying from behind: flies, slides, lies, gets up */
void turtle_knocked_flying_from_behind(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (OBJECT(a0)->turtle.reaction_step)
	{
	case 0:
		turtle_knocked_flying_from_behind_fly(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 1:
		turtle_knocked_flying_from_behind_slide(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
	case 3:
		turtle_knocked_flying_from_behind_lie(a0, p_d1, &d5, &d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the knock from behind's flight until it lands or meets a wall */
void turtle_knocked_flying_from_behind_fly(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint8_t d0 = 0;

	OBJECT(a0)->turtle.wait_timer = 8u;
	d0 = 3u;
	if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
		d0++;
	if ((OBJECT(a0)->contacts & shl32(1u, (int)(d0))) == 0u)
	{
		*p_d7 = 0x50u;
		turtle_knockback_arc((uint16_t)*p_d7, a0);
		if (OBJECT(a0)->turtle.falling != 0u && (OBJECT(a0)->height == 0u || (OBJECT(a0)->contacts & 1u) != 0u))
		{
			d0 = 0u;
			if (OBJECT(a0)->health_bars == 0u)
				d0 = 3u;
			OBJECT(a0)->turtle.reaction_variant = d0;
			turtle_knocked_flying_from_behind_next(a0, p_d1, &d5, &d6, p_d7);
		}
	}
	else if (OBJECT(a0)->health_bars != 0u)
	{
		OBJECT(a0)->turtle.reaction_variant = 1u;
		turtle_knocked_flying_from_behind_next(a0, p_d1, &d5, &d6, p_d7);
	}
	else
	{
		OBJECT(a0)->turtle.reaction_variant = 4u;
		turtle_knocked_flying_from_behind_next(a0, p_d1, &d5, &d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the turtle slides along the ground, or drops down a wall */
void turtle_knocked_flying_from_behind_slide(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d0 = 0;
	uint16_t height = 0;

	if (OBJECT(a0)->turtle.reaction_variant == 1u || OBJECT(a0)->turtle.reaction_variant == 4u)
	{
		if (OBJECT(a0)->frame_time == 0u)
		{
			if ((OBJECT(a0)->contacts & 1u) != 0u)
				turtle_knocked_flying_from_behind_wait(a0, p_d1, &d5, &d6, p_d7);
			else
			{
				height = OBJECT(a0)->height;
				OBJECT(a0)->height = height - 0x100u;
				if (height >= 0x100u)
				{
					if (OBJECT(a0)->height_whole < OBJECT(a0)->floor_height)
					{
						OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
						OBJECT(a0)->height &= 0xFF00u;
						turtle_knocked_flying_from_behind_wait(a0, p_d1, &d5, &d6, p_d7);
					}
				}
				else
				{
					OBJECT(a0)->height = 0u;
					OBJECT(a0)->floor_height = 0u;
					turtle_knocked_flying_from_behind_wait(a0, p_d1, &d5, &d6, p_d7);
				}
			}
		}
	}
	else
	{
		if (OBJECT(a0)->turtle.wait_timer != 0u)
		{
			OBJECT(a0)->turtle.wait_timer--;
			d0 = 0x100u;
			if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
				d0 = 0u - d0;
			OBJECT(a0)->x += d0;
			if (OBJECT(a0)->x < 0x16000u)
			{
				if (OBJECT(a0)->x < 0x9000u)
					OBJECT(a0)->x = 0x9000u;
			}
			else
				OBJECT(a0)->x = 0x16000u;
		}
		if (OBJECT(a0)->frame_time == 0u)
			turtle_knocked_flying_from_behind_wait(a0, p_d1, &d5, &d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the turtle lies on its floor */
void turtle_knocked_flying_from_behind_lie(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint8_t wait_timer = 0;

	turtle_drop_to_floor(a0);
	if (OBJECT(a0)->state == 0x11u)
	{
		wait_timer = OBJECT(a0)->turtle.wait_timer;
		OBJECT(a0)->turtle.wait_timer = wait_timer - 1u;
		if (wait_timer == 1u)
			turtle_knocked_flying_from_behind_wait(a0, p_d1, &d5, &d6, p_d7);
	}
	else if (OBJECT(a0)->frame_time == 0u)
		turtle_knocked_flying_from_behind_next(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the turtle lies a while */
void turtle_knocked_flying_from_behind_wait(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	OBJECT(a0)->turtle.wait_timer = 0x60u;
	turtle_knocked_flying_from_behind_next(a0, p_d1, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the knock's next step, or its end */
void turtle_knocked_flying_from_behind_next(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t a6 = 0, d0_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	OBJECT(a0)->turtle.reaction_step++;
	d0 = (uint16_t)((uint32_t)OBJECT(a0)->turtle.reaction_variant << 2);
	a6 = indexed_table_of_32_bit_values_01CC6E[d0 / 4u];
	d0 = (uint16_t)IN_PAGE(d0, OBJECT(a0)->turtle.reaction_step);
	t1 = mem_read8(a6 + d0);
	d0 = (uint16_t)IN_PAGE(d0, t1);
	if ((int8_t)t1 < 0)
	{
		OBJECT(a0)->turtle.reaction_step = (uint8_t)d0;
		if (OBJECT(a0)->turtle.reaction_variant != 1u && OBJECT(a0)->turtle.reaction_variant != 4u)
		{
			d0_2 = reset_ADDRESS;
			if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
				d0_2 = 0u - d0_2;
			OBJECT(a0)->x += d0_2;
		}
	}
	else
	{
		d0 += 0x400u;
		turtle_set_state(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* frozen in a block of ice until it bursts */
void turtle_frozen(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (OBJECT(a0)->turtle.reaction_step)
	{
	case 0:
		turtle_frozen_start(a0);
		break;
	case 1:
		turtle_frozen_in_ice(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
		turtle_frozen_thaw(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 3:
		turtle_frozen_countdown(a0);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the turtle frozen for a while */
void turtle_frozen_start(uint32_t a0)
{
	OBJECT(a0)->turtle.reaction_step++;
	OBJECT(a0)->turtle.wait_timer = 0x60u;
}

/* the frozen turtle drops to the ground, then the ice bursts */
void turtle_frozen_in_ice(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0, ignored = 0;
	uint8_t wait_timer = 0;
	uint16_t height = 0;

	if (OBJECT(a0)->height != 0u)
	{
		OBJECT(a0)->floor_height = 0u;
		height = OBJECT(a0)->height;
		OBJECT(a0)->height = height - 0x300u;
		if (height < 0x300u)
			OBJECT(a0)->height = 0u;
	}
	wait_timer = OBJECT(a0)->turtle.wait_timer;
	OBJECT(a0)->turtle.wait_timer = wait_timer - 1u;
	if (wait_timer != 1u)
		return;
	OBJECT(a0)->turtle.reaction_step++;
	d0 = 0x41Du;
	turtle_set_state(d0, a0, p_d1, &ignored, &d5, &d6, &d7);
	d7_2 = (d7 & ~0xFFu) | 0x2Eu;
	queue_sound((uint8_t)d7_2, 0u);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7_2;
}

/* free of the ice, or dead with no health left */
void turtle_frozen_thaw(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t ignored = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		if (OBJECT(a0)->health_bars == 0u)
		{
			OBJECT(a0)->turtle.reaction_step++;
			OBJECT(a0)->turtle.wait_timer = 0x60u;
			d0 = 0x411u;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
		}
		else
			OBJECT(a0)->turtle.reaction_step = 0xFFu;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the turtle dies after a while */
void turtle_frozen_countdown(uint32_t a0)
{
	uint8_t wait_timer = 0;

	wait_timer = OBJECT(a0)->turtle.wait_timer;
	OBJECT(a0)->turtle.wait_timer = wait_timer - 1u;
	if (wait_timer == 1u)
	{
		OBJECT(a0)->turtle.reaction_step = 0xFFu;
		return;
	}
}

/* electrocuted or blasted until it drops, or dies with no health left */
void turtle_shocked(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	switch (OBJECT(a0)->turtle.reaction_step)
	{
	case 0:
		turtle_shocked_start(a0);
		break;
	case 1:
		turtle_shocked_drop(a0, p_d1, &d5, &d6, p_d7);
		break;
	case 2:
		turtle_hit_countdown(a0);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the turtle shocked for a while */
void turtle_shocked_start(uint32_t a0)
{
	OBJECT(a0)->turtle.reaction_step++;
	OBJECT(a0)->turtle.wait_timer = 0x50u;
}

/* the shocked turtle drops to the ground, then is free or dies */
void turtle_shocked_drop(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;
	uint32_t ignored = 0;
	uint8_t wait_timer = 0;
	uint16_t height = 0;

	if (OBJECT(a0)->height != 0u)
	{
		OBJECT(a0)->floor_height = 0u;
		height = OBJECT(a0)->height;
		OBJECT(a0)->height = height - 0x200u;
		if (height < 0x200u)
			OBJECT(a0)->height = 0u;
	}
	wait_timer = OBJECT(a0)->turtle.wait_timer;
	OBJECT(a0)->turtle.wait_timer = wait_timer - 1u;
	if (wait_timer == 1u)
	{
		if (OBJECT(a0)->health_bars == 0u)
		{
			OBJECT(a0)->turtle.reaction_step++;
			OBJECT(a0)->turtle.wait_timer = 0x60u;
			d0 = 0x411u;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, &d6, p_d7);
		}
		else
			OBJECT(a0)->turtle.reaction_step = 0xFFu;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the reaction's last wait */
void turtle_hit_countdown(uint32_t a0)
{
	uint8_t wait_timer = 0;

	wait_timer = OBJECT(a0)->turtle.wait_timer;
	OBJECT(a0)->turtle.wait_timer = wait_timer - 1u;
	if (wait_timer == 1u)
	{
		OBJECT(a0)->turtle.reaction_step = 0xFFu;
		return;
	}
}

/* the turtle falls into an open manhole and climbs out */
void turtle_fall_in_manhole(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)OBJECT(a0)->turtle.reaction_step << 2);
	switch (d0)
	{
	case 0:
		turtle_fall_in_manhole_start(a0, p_d1, p_d7);
		break;
	case 4:
		turtle_fall_in_manhole_climb_out(d0, a0, p_d1, &d5, &d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the turtle loses a bar and drops into the hole */
void turtle_fall_in_manhole_start(uint32_t a0, uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t hit_by = 0;

	if (OBJECT(a0)->health_bars != 1u)
	{
		OBJECT(a0)->health_bars--;
		*p_d7 = turtle_save_health(*p_d7, a0);
	}
	OBJECT(a0)->turtle.reaction_step++;
	OBJECT(a0)->flags &= 0xBFu;
	hit_by = OBJECT(a0)->turtle.hit_by;
	*p_d1 = (uint32_t)mem_read16(hit_by + 0xEu) << 8;
	OBJECT(a0)->x = (uint32_t)mem_read16(hit_by + 0xCu) << 8;
	OBJECT(a0)->y = *p_d1;
	OBJECT(a0)->turtle.move_timer = 0x1Au;
}

/* a speech in the hole, then the turtle climbs out */
void turtle_fall_in_manhole_climb_out(uint32_t d0, uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d2 = 0, d3 = 0, screen_y = 0;
	uint32_t d4 = 0, ignored = 0;
	uint8_t move_timer = 0;
	uint16_t t1 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->turtle.reaction_step = 0xFFu;
		OBJECT(a0)->y -= 0x1000u;
	}
	else if (OBJECT(a0)->turtle.move_timer != 0u)
	{
		move_timer = OBJECT(a0)->turtle.move_timer;
		OBJECT(a0)->turtle.move_timer = move_timer - 1u;
		if (move_timer == 1u)
		{
			d0 &= ~0xFFu;
			d1 = (d1 & ~0xFFFFu) | OBJECT(a0)->screen_x;
			screen_y = OBJECT(a0)->screen_y;
			if (bebop_exchange_lines == 0u || (bebop_exchange_lines >= 3u && bebop_exchange_lines == 3u && time_since_balloon >= 0x80u))
			{
				d1 = (d1 & ~0xFFFFu) | (uint16_t)(d1 - 0x30u);
				t1 = screen_y;
				d2 = (uint16_t)(t1 - 0x38u);
				if (t1 < 0x38u)
					d2 = 0u;
				d3 = 0x64u;
				d4 = 0x20u;
				show_balloon(d2, d3, &d0, &d1, &d4, &d5, &d6, p_d7, &ignored);
				draw_wide_balloon_pointer(ignored);
			}
		}
	}
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* held by an enemy until it breaks free or its health runs out */
void turtle_held(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	switch (OBJECT(a0)->turtle.reaction_step)
	{
	case 1:
		turtle_hit_countdown(a0);
		break;
	case 0:
		turtle_held_struggle(a0, a2, p_d1, &d5, p_d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* held: the prompt, the health draining, the presses to break free */
void turtle_held_struggle(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0, d2 = 0;
	uint32_t ignored = 0;

	*p_d1 = (*p_d1 & ~0xFFFFu) | OBJECT(a0)->screen_x;
	d2 = (uint16_t)(OBJECT(a0)->screen_y + OBJECT(a0)->height_whole);
	turtle_show_prompt(d2, a0, p_d1, p_d6, p_d7);
	if (stage != 8u || scroll_mode >= 0)
	{
		if (OBJECT(a0)->turtle.escape_presses < 8u)
		{
			if (OBJECT(a0)->health_bars == 0u)
				turtle_held_dies(a0, p_d1, &d5, p_d6, p_d7);
			else if ((frame_count & 0x7Fu) != 0u)
			{
				OBJECT(a0)->flags |= 2u;
				if (mem_read8(a2) != 0u)
				{
					OBJECT(a0)->turtle.escape_presses++;
					if (OBJECT(a0)->turtle.escape_presses >= 8u)
					{
						if (OBJECT(a0)->health_bars == 0u)
							turtle_held_dies(a0, p_d1, &d5, p_d6, p_d7);
						else
						{
							turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
							mem_write8(OBJECT(a0)->turtle.hit_by + 5u, 3u);
							OBJECT(a0)->health = 3u;
							OBJECT(a0)->flags &= ~2u;
							OBJECT(a0)->turtle.escape_presses = 0u;
							OBJECT(a0)->turtle.combo_step = 2u;
							d0_2 = 6u;
							turtle_start_attack(d0_2, a0, p_d1, &d5, p_d6, p_d7);
						}
					}
				}
			}
			else
			{
				OBJECT(a0)->health_bars--;
				*p_d7 = turtle_save_health(*p_d7, a0);
				if (OBJECT(a0)->health_bars == 0u)
					turtle_held_dies(a0, p_d1, &d5, p_d6, p_d7);
				else
				{
					OBJECT(a0)->flags |= 2u;
					if (mem_read8(a2) != 0u)
					{
						OBJECT(a0)->turtle.escape_presses++;
						if (OBJECT(a0)->turtle.escape_presses >= 8u)
						{
							if (OBJECT(a0)->health_bars == 0u)
								turtle_held_dies(a0, p_d1, &d5, p_d6, p_d7);
							else
							{
								turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
								mem_write8(OBJECT(a0)->turtle.hit_by + 5u, 3u);
								OBJECT(a0)->health = 3u;
								OBJECT(a0)->flags &= ~2u;
								OBJECT(a0)->turtle.escape_presses = 0u;
								OBJECT(a0)->turtle.combo_step = 2u;
								d0_2 = 6u;
								turtle_start_attack(d0_2, a0, p_d1, &d5, p_d6, p_d7);
							}
						}
					}
				}
			}
		}
		else
		{
			turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
			OBJECT(a0)->turtle.escape_presses = 0u;
			d0 = 0u;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		}
	}
	else if (OBJECT(a0)->health_bars == 0u)
		turtle_held_dies(a0, p_d1, &d5, p_d6, p_d7);
	else
	{
		turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
		mem_write8(OBJECT(a0)->turtle.hit_by + 5u, 3u);
		OBJECT(a0)->health = 3u;
		OBJECT(a0)->flags &= ~2u;
		OBJECT(a0)->turtle.escape_presses = 0u;
		OBJECT(a0)->turtle.combo_step = 2u;
		d0_2 = 6u;
		turtle_start_attack(d0_2, a0, p_d1, &d5, p_d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the turtle's health ran out while held: the holder lets go and it dies */
void turtle_held_dies(uint32_t a0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint32_t hit_by = 0, ignored = 0;

	turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
	hit_by = OBJECT(a0)->turtle.hit_by;
	if (mem_read8(hit_by + 4u) != 4u)
		mem_write8(hit_by + 5u, 3u);
	OBJECT(a0)->turtle.reaction_step++;
	OBJECT(a0)->turtle.wait_timer = 0x60u;
	d0 = 0x411u;
	turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* held by an enemy for a moment, free after fewer presses */
void turtle_held_briefly(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	switch (OBJECT(a0)->turtle.reaction_step)
	{
	case 1:
		turtle_hit_countdown(a0);
		break;
	case 0:
		turtle_held_briefly_struggle(a0, a2, p_d1, &d5, p_d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void turtle_held_briefly_struggle(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0, d2 = 0;
	uint32_t ignored = 0;

	*p_d1 = (*p_d1 & ~0xFFFFu) | OBJECT(a0)->screen_x;
	d2 = (uint16_t)(OBJECT(a0)->screen_y + OBJECT(a0)->height_whole);
	turtle_show_prompt(d2, a0, p_d1, p_d6, p_d7);
	if (stage != 8u || scroll_mode >= 0)
	{
		if (OBJECT(a0)->frame_time != 0u)
		{
			if (OBJECT(a0)->turtle.escape_presses < 6u)
			{
				if (mem_read8(a2) != 0u)
				{
					OBJECT(a0)->turtle.escape_presses++;
					if (OBJECT(a0)->turtle.escape_presses >= 6u)
					{
						if (OBJECT(a0)->health_bars == 0u)
							turtle_held_dies(a0, p_d1, &d5, p_d6, p_d7);
						else
						{
							turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
							mem_write8(OBJECT(a0)->turtle.hit_by + 5u, 3u);
							OBJECT(a0)->turtle.escape_presses = 0u;
							OBJECT(a0)->health = 3u;
							OBJECT(a0)->flags &= ~2u;
							OBJECT(a0)->turtle.combo_step = 2u;
							d0_2 = 6u;
							turtle_start_attack(d0_2, a0, p_d1, &d5, p_d6, p_d7);
						}
					}
				}
			}
			else
			{
				turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
				if (OBJECT(a0)->health_bars == 0u)
				{
					OBJECT(a0)->turtle.reaction_step++;
					OBJECT(a0)->turtle.wait_timer = 0x60u;
					d0 = 0x411u;
					turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
				}
				else
				{
					OBJECT(a0)->turtle.escape_presses = 0u;
					d0 = 0u;
					turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
				}
			}
		}
		else if (OBJECT(a0)->health_bars == 0u)
			turtle_held_dies(a0, p_d1, &d5, p_d6, p_d7);
		else
		{
			if (OBJECT(a0)->health == 0u)
				OBJECT(a0)->health = 3u;
			OBJECT(a0)->turtle.hit_reaction = 0xEu;
			OBJECT(a0)->turtle.reaction_step = 0u;
			d0 = 0x422u;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		}
	}
	else if (OBJECT(a0)->health_bars == 0u)
		turtle_held_dies(a0, p_d1, &d5, p_d6, p_d7);
	else
	{
		turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
		mem_write8(OBJECT(a0)->turtle.hit_by + 5u, 3u);
		OBJECT(a0)->turtle.escape_presses = 0u;
		OBJECT(a0)->health = 3u;
		OBJECT(a0)->flags &= ~2u;
		OBJECT(a0)->turtle.combo_step = 2u;
		d0_2 = 6u;
		turtle_start_attack(d0_2, a0, p_d1, &d5, p_d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* held by an enemy that is knocked away when the turtle breaks free */
void turtle_held_knock_off(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	switch (OBJECT(a0)->turtle.reaction_step)
	{
	case 1:
		turtle_hit_countdown(a0);
		break;
	case 0:
		turtle_held_knock_off_struggle(a0, a2, p_d1, &d5, p_d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void turtle_held_knock_off_struggle(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0, d2 = 0;
	uint32_t ignored = 0;

	*p_d1 = (*p_d1 & ~0xFFFFu) | OBJECT(a0)->screen_x;
	d2 = (uint16_t)(OBJECT(a0)->screen_y + OBJECT(a0)->height_whole);
	turtle_show_prompt(d2, a0, p_d1, p_d6, p_d7);
	if (stage != 8u || scroll_mode >= 0)
	{
		OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
		OBJECT(a0)->height &= 0xFF00u;
		if (OBJECT(a0)->turtle.escape_presses >= 8u)
		{
			turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
			d0 = 0u;
			OBJECT(a0)->turtle.escape_presses = 0u;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		}
		else if (OBJECT(a0)->health_bars == 0u)
		{
			mem_write8(OBJECT(a0)->turtle.hit_by + 4u, 2u);
			turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
			OBJECT(a0)->turtle.reaction_step++;
			OBJECT(a0)->turtle.wait_timer = 0x60u;
			d0 = 0x411u;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		}
		else if ((frame_count & 0x3Fu) != 0u)
		{
			if (mem_read8(a2) != 0u)
			{
				OBJECT(a0)->turtle.escape_presses++;
				if (OBJECT(a0)->turtle.escape_presses >= 8u)
				{
					if (OBJECT(a0)->health_bars == 0u)
					{
						mem_write8(OBJECT(a0)->turtle.hit_by + 4u, 2u);
						turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
						OBJECT(a0)->turtle.reaction_step++;
						OBJECT(a0)->turtle.wait_timer = 0x60u;
						d0 = 0x411u;
						turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
					}
					else
					{
						mem_write8(OBJECT(a0)->turtle.hit_by + 4u, 2u);
						turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
						d0 = 0u;
						OBJECT(a0)->turtle.escape_presses = 0u;
						turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
					}
				}
			}
		}
		else
		{
			OBJECT(a0)->health_bars--;
			*p_d7 = turtle_save_health(*p_d7, a0);
			if (OBJECT(a0)->health_bars == 0u)
			{
				mem_write8(OBJECT(a0)->turtle.hit_by + 4u, 2u);
				turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
				OBJECT(a0)->turtle.reaction_step++;
				OBJECT(a0)->turtle.wait_timer = 0x60u;
				d0 = 0x411u;
				turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
			}
			else if (mem_read8(a2) != 0u)
			{
				OBJECT(a0)->turtle.escape_presses++;
				if (OBJECT(a0)->turtle.escape_presses >= 8u)
				{
					if (OBJECT(a0)->health_bars == 0u)
					{
						mem_write8(OBJECT(a0)->turtle.hit_by + 4u, 2u);
						turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
						OBJECT(a0)->turtle.reaction_step++;
						OBJECT(a0)->turtle.wait_timer = 0x60u;
						d0 = 0x411u;
						turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
					}
					else
					{
						mem_write8(OBJECT(a0)->turtle.hit_by + 4u, 2u);
						turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
						d0 = 0u;
						OBJECT(a0)->turtle.escape_presses = 0u;
						turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
					}
				}
			}
		}
	}
	else if (OBJECT(a0)->health_bars == 0u)
	{
		mem_write8(OBJECT(a0)->turtle.hit_by + 4u, 2u);
		turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
		OBJECT(a0)->turtle.reaction_step++;
		OBJECT(a0)->turtle.wait_timer = 0x60u;
		d0 = 0x411u;
		turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
	}
	else
	{
		mem_write8(OBJECT(a0)->turtle.hit_by + 4u, 2u);
		turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
		d0 = 0u;
		OBJECT(a0)->turtle.escape_presses = 0u;
		turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* held by an enemy the turtle throws when it breaks free */
void turtle_held_throw_off(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	switch (OBJECT(a0)->turtle.reaction_step)
	{
	case 1:
		turtle_hit_countdown(a0);
		break;
	case 0:
		turtle_held_throw_off_struggle(a0, a2, p_d1, &d5, p_d6, p_d7);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void turtle_held_throw_off_struggle(uint32_t a0, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0, d2 = 0;
	uint32_t hit_by = 0, ignored = 0;
	uint8_t wait_timer = 0;

	*p_d1 = (*p_d1 & ~0xFFFFu) | OBJECT(a0)->screen_x;
	d2 = (uint16_t)(OBJECT(a0)->screen_y + OBJECT(a0)->height_whole);
	turtle_show_prompt(d2, a0, p_d1, p_d6, p_d7);
	OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
	OBJECT(a0)->height &= 0xFF00u;
	if (OBJECT(a0)->turtle.escape_presses < 0x10u)
	{
		if (OBJECT(a0)->health_bars == 0u)
		{
			turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
			hit_by = OBJECT(a0)->turtle.hit_by;
			mem_write8(hit_by, mem_read8(hit_by) | 2u);
			mem_write16(hit_by + 4u, 0x200u);
			mem_write8(hit_by + 0x10u, mem_read8(hit_by + 0x32u));
			mem_write8(hit_by + 0x22u, 0u);
			mem_write8(hit_by, mem_read8(hit_by) | 0x80u);
			OBJECT(a0)->turtle.escape_presses = 0u;
			OBJECT(a0)->turtle.reaction_step++;
			OBJECT(a0)->turtle.wait_timer = 0x60u;
			d0 = 0x411u;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		if ((frame_count & 0x3Fu) == 0u)
		{
			OBJECT(a0)->health_bars--;
			*p_d7 = turtle_save_health(*p_d7, a0);
			if (OBJECT(a0)->health_bars == 0u)
			{
				turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
				hit_by = OBJECT(a0)->turtle.hit_by;
				mem_write8(hit_by, mem_read8(hit_by) | 2u);
				mem_write16(hit_by + 4u, 0x200u);
				mem_write8(hit_by + 0x10u, mem_read8(hit_by + 0x32u));
				mem_write8(hit_by + 0x22u, 0u);
				mem_write8(hit_by, mem_read8(hit_by) | 0x80u);
				OBJECT(a0)->turtle.escape_presses = 0u;
				OBJECT(a0)->turtle.reaction_step++;
				OBJECT(a0)->turtle.wait_timer = 0x60u;
				d0 = 0x411u;
				turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
				*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
				return;
			}
		}
		if (mem_read8(a2) == 0u)
		{
			wait_timer = OBJECT(a0)->turtle.wait_timer;
			OBJECT(a0)->turtle.wait_timer = wait_timer - 1u;
			if (wait_timer != 1u || OBJECT(a0)->state == 0x24u)
			{
				return;
			}
			d0 = 0x424u;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
		OBJECT(a0)->turtle.wait_timer = 0x10u;
		OBJECT(a0)->turtle.escape_presses++;
		if (OBJECT(a0)->turtle.escape_presses < 8u)
		{
			if (OBJECT(a0)->state == 0x27u)
			{
				return;
			}
			d0 = 0x427u;
			turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
			*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
			return;
		}
	}
	turtle_erase_prompt(a0, p_d1, p_d6, p_d7);
	*p_d7 = (*p_d7 & ~0xFFFFu) | OBJECT(a0)->kind;
	*p_d7 = (*p_d7 & ~0xFFu) | indexed_table_of_8_bit_values_01D200[(uint16_t)*p_d7];
	*p_d7 = LINKED(*p_d7, (uint16_t)(*p_d7 + 0x400u));
	queue_job((uint16_t)*p_d7);
	if (OBJECT(a0)->health_bars == 0u)
	{
		OBJECT(a0)->turtle.escape_presses = 0u;
		OBJECT(a0)->turtle.reaction_step++;
		OBJECT(a0)->turtle.wait_timer = 0x60u;
		d0 = 0x411u;
		turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	hit_by = OBJECT(a0)->turtle.hit_by;
	if (mem_read8(hit_by + 4u) == 5u)
	{
		d0 = 0u;
		OBJECT(a0)->turtle.escape_presses = 0u;
		turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
		*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
		return;
	}
	mem_write16(hit_by + 4u, 0x500u);
	mem_write8(hit_by + 0x22u, 0u);
	mem_write16(hit_by + 0x28u, 0x94u);
	d0_2 = 0u;
	if ((int8_t)OBJECT(a0)->turtle.knockback_flags >= 0)
		d0_2 = 0x80u;
	mem_write8(hit_by + 0x30u, d0_2);
	d0 = 0u;
	OBJECT(a0)->turtle.escape_presses = 0u;
	turtle_set_state(d0, a0, p_d1, &ignored, &d5, p_d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* knocked into the air until it lands */
uint32_t turtle_hit_fly(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 0x50u;
	turtle_knockback_arc((uint16_t)d7, a0);
	if (OBJECT(a0)->turtle.falling == 0u || (OBJECT(a0)->contacts & 1u) == 0u)
		return d7;
	OBJECT(a0)->turtle.reaction_step = 0xFFu;
	return d7;
}

/* the prompt to press the buttons drawn blinking near the held turtle */
void turtle_show_prompt(uint16_t d2, uint32_t a0, uint32_t *p_d1, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint32_t a5 = 0, a6 = 0, d6_2 = 0, d7_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	if (game_on == 0u || prompt_shown(OBJECT(a0)->kind) != 0u)
		return;
	a6 = table_loaded_by_lea_01D35C_ADDRESS;
	if (OBJECT(a0)->turtle.prompt_frame != 0u)
		a6 = 0x1D3ACu;
	OBJECT(a0)->turtle.prompt_time--;
	if ((OBJECT(a0)->turtle.prompt_time & 0x7Fu) == 0u)
	{
		OBJECT(a0)->turtle.prompt_frame ^= 0xFFu;
		OBJECT(a0)->turtle.prompt_time = 0xC0u;
		return;
	}
	if (OBJECT(a0)->turtle.prompt_time == 0x3Fu)
	{
		d1 = ((d1 - 0x20u) & 0x1F8u) >> 2;
		if (d2 < 0x70u)
			d2 = (uint16_t)(((0u - d2 - 0x50u) & 0xF8u) << 4);
		else
			d2 = 0x400u;
		d1 = (uint16_t)(d1 + d2);
		OBJECT(a0)->turtle.prompt_place = d1;
		d1 += 0x100000u;
		a5 = d1;
	}
	else
	{
		if (OBJECT(a0)->turtle.prompt_time != 0xBFu)
			return;
		a5 = 0x100000u + (int16_t)OBJECT(a0)->turtle.prompt_place;
	}
	d7_2 = 3u;
	do
	{
		d6_2 = 9u;
		do
		{
			mem_write8(a5, DATA8(a6));
			a6++;
			a5++;
			mem_write8(a5, DATA8(a6));
			t1 = d6_2 - 1u;
			d6_2 = t1;
			a6++;
			a5++;
		} while (t1 != 0xFFFFu);
		t2 = d7_2 - 1u;
		d7_2 = t2;
		a5 += 0x6Cu;
	} while (t2 != 0xFFFFu);
	*p_d1 = d1;
	*p_d6 = d6_2;
	*p_d7 = d7_2;
}

/* the prompt erased */
void turtle_erase_prompt(uint32_t a0, uint32_t *p_d1, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6_2 = 0, d7_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	if (game_on == 0u)
		return;
	a6 = 0x100000u + (int16_t)OBJECT(a0)->turtle.prompt_place;
	d0 = 0u;
	*p_d1 = 0x10u;
	d7_2 = 3u;
	do
	{
		d6_2 = 9u;
		do
		{
			mem_write8(a6, d0);
			a6++;
			mem_write8(a6, *p_d1);
			t1 = d6_2 - 1u;
			d6_2 = t1;
			a6++;
		} while (t1 != 0xFFFFu);
		t2 = d7_2 - 1u;
		d7_2 = t2;
		a6 += 0x6Cu;
	} while (t2 != 0xFFFFu);
	prompt_shown(OBJECT(a0)->kind) = 0xFFu;
	*p_d6 = d6_2;
	*p_d7 = d7_2;
}

/* the turtle's health bars kept for its player and shown again */
uint32_t turtle_save_health(uint32_t d7, uint32_t a0)
{
	PLAYER(PLAYER_ADDRESS(0) + (OBJECT(a0)->kind) * 0x8u)->health_bars = OBJECT(a0)->health_bars;
	d7 = (d7 & ~0xFFFFu) | 0xB20u | shl32(1u, (int)(OBJECT(a0)->kind & 0x1Fu));
	queue_job((uint16_t)d7);
	return d7;
}

/* the turtle on a knock's arc across and through the air, until it lands */
void turtle_knockback_arc(uint16_t d7, uint32_t a0)
{
	uint16_t jump_speed = 0;
	uint16_t height = 0, jump_speed_2 = 0;

	if (OBJECT(a0)->turtle.falling != 0u && (OBJECT(a0)->contacts & 1u) != 0u)
	{
		OBJECT(a0)->contacts |= 1u;
		OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
		OBJECT(a0)->height &= 0xFF00u;
		return;
	}
	if ((OBJECT(a0)->turtle.knockback_flags & 1u) != 0u)
	{
		if ((OBJECT(a0)->contacts & 0x10u) == 0u)
		{
			OBJECT(a0)->x -= OBJECT(a0)->turtle.drift_speed;
			if (OBJECT(a0)->x < 0x9000u)
				OBJECT(a0)->x = 0x9000u;
			OBJECT(a0)->turtle.drift_speed -= d7;
			if (OBJECT(a0)->turtle.drift_speed < 0x200u)
				OBJECT(a0)->turtle.drift_speed = 0x200u;
		}
	}
	else if ((OBJECT(a0)->contacts & 8u) == 0u)
	{
		OBJECT(a0)->x += OBJECT(a0)->turtle.drift_speed;
		if (OBJECT(a0)->x < 0x16000u)
		{
			OBJECT(a0)->turtle.drift_speed -= d7;
			if (OBJECT(a0)->turtle.drift_speed < 0x200u)
				OBJECT(a0)->turtle.drift_speed = 0x200u;
		}
		else
		{
			OBJECT(a0)->x = 0x16000u;
			OBJECT(a0)->turtle.drift_speed -= d7;
			if (OBJECT(a0)->turtle.drift_speed < 0x200u)
				OBJECT(a0)->turtle.drift_speed = 0x200u;
		}
	}
	if (OBJECT(a0)->turtle.falling != 0u)
	{
		OBJECT(a0)->turtle.jump_speed += d7;
		jump_speed = OBJECT(a0)->turtle.jump_speed;
		height = OBJECT(a0)->height;
		OBJECT(a0)->height = height - jump_speed;
		if (height < jump_speed || OBJECT(a0)->height_whole < OBJECT(a0)->floor_height)
		{
			OBJECT(a0)->contacts |= 1u;
			OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
			OBJECT(a0)->height &= 0xFF00u;
			return;
		}
		return;
	}
	OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
	jump_speed_2 = OBJECT(a0)->turtle.jump_speed;
	OBJECT(a0)->turtle.jump_speed = jump_speed_2 - d7;
	if (d7 <= jump_speed_2)
		return;
	OBJECT(a0)->turtle.jump_speed = 0u - OBJECT(a0)->turtle.jump_speed;
	OBJECT(a0)->turtle.falling--;
}

/* Unused: the turtle fires a gun */
void turtle_fire_gun(uint8_t d2, uint8_t d6, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	turtles_busy--;
	if (OBJECT(a0)->frame_time == 0u)
		turtle_attack_over(d2, d6, a0, a1, a2, p_d1, &d5, p_d7);
	else
		mem_write8(a1, mem_read8(a1) & 0xCu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* on another object: whether the turtle stands on it or is in the air */
void turtle_floor_contact(uint8_t d0, uint32_t a0)
{
	if (OBJECT(a0)->height_whole != OBJECT(a0)->floor_height)
		d0 |= 0x80u;
	else if (floor_cell == 1u)
		d0 |= 1u;
	OBJECT(a0)->contacts |= d0;
}

void turtle_walls_still(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, height_whole = 0;

	d0 = 0u;
	if ((OBJECT(a0)->flags & 0x10u) != 0u)
	{
		turtle_floor_contact(d0, a0);
		return;
	}
	if (floor_cell != 1u)
	{
		if ((OBJECT(a0)->turtle.knockback_flags & 1u) == 0u)
		{
			turtle_leave_floor_right(d0, a0, a6);
			return;
		}
		turtle_leave_floor_left(d0, a0, a6);
		return;
	}
	height_whole = OBJECT(a0)->height_whole;
	if (height_whole == OBJECT(a0)->floor_height)
	{
		OBJECT(a0)->height &= 0xFF00u;
		d0 |= 1u;
		turtle_wall_contacts(d0, a0);
		return;
	}
	if (OBJECT(a0)->floor_height <= height_whole)
	{
		d0 |= 0x80u;
		turtle_wall_contacts(d0, a0);
		return;
	}
	OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
	OBJECT(a0)->height &= 0xFF00u;
	d0 |= 1u;
	turtle_wall_contacts(d0, a0);
}

void turtle_walls_up(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, height_whole = 0;

	d0 = 0u;
	if ((OBJECT(a0)->flags & 0x10u) != 0u)
	{
		turtle_floor_contact(d0, a0);
		return;
	}
	if (floor_cell != 1u)
	{
		turtle_raise_floor(d0, a0, a6);
		return;
	}
	height_whole = OBJECT(a0)->height_whole;
	if (height_whole == OBJECT(a0)->floor_height)
	{
		OBJECT(a0)->height &= 0xFF00u;
		d0 |= 1u;
		turtle_wall_contacts(d0, a0);
		return;
	}
	if (OBJECT(a0)->floor_height <= height_whole)
	{
		d0 |= 0x80u;
		turtle_wall_contacts(d0, a0);
		return;
	}
	OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
	OBJECT(a0)->height &= 0xFF00u;
	d0 |= 1u;
	turtle_wall_contacts(d0, a0);
}

/* the walls around the turtle from the floor map's cells around it */
void turtle_wall_contacts(uint8_t d0, uint32_t a0)
{
	uint8_t d1 = 0, d2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d2 = height_cell_up;
	t1 = floor_cell_up;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 2u;
	t2 = floor_cell_right;
	d1 = t2;
	if ((int8_t)t2 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && d0 == 0xFBu)))
		d0 |= 8u;
	d2 = height_cell_left;
	t3 = floor_cell_left;
	d1 = t3;
	if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || d2 != 0xFAu)))
	{
		turtle_corner_contacts(d0, a0);
		return;
	}
	d0 |= 0x10u;
	turtle_corner_contacts(d0, a0);
}

/* the turtle steps up a level of the floor map */
void turtle_raise_floor(uint8_t d0, uint32_t a0, uint32_t a6)
{
	uint8_t d0_2 = 0, d2 = 0, d3 = 0;

	if (OBJECT(a0)->y < 0x6800u)
	{
		OBJECT(a0)->y += 0x400u;
		OBJECT(a0)->screen_y = OBJECT(a0)->y >> 8;
	}
	d2 = 0u;
	d3 = 0x14u;
	do
	{
		OBJECT(a0)->floor_height += 8u;
		a6 -= 0x40u;
		if (a6 < floor_map_ADDRESS)
			a6 += 0x800u;
		d2++;
		if (d3 <= d2)
		{
			OBJECT(a0)->x = 0xC000u;
			OBJECT(a0)->y = 0x2000u;
			d0_2 = 0x7Bu;
			OBJECT(a0)->floor_height = 0u;
			OBJECT(a0)->contacts |= d0_2;
			return;
		}
	} while ((int8_t)mem_read8(a6) < 0);
	OBJECT(a0)->y = (OBJECT(a0)->y & 0xFFFFFF00u) | 0xFFu;
	d0 |= 0x82u;
	if (OBJECT(a0)->floor_height <= OBJECT(a0)->height_whole)
	{
		turtle_corner_contacts(d0, a0);
		return;
	}
	OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
	OBJECT(a0)->height &= 0xFF00u;
	d0 |= 1u;
	turtle_corner_contacts(d0, a0);
}

void turtle_walls_down(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, height_whole = 0;

	d0 = 0u;
	if ((OBJECT(a0)->flags & 0x10u) != 0u)
	{
		turtle_floor_contact(d0, a0);
		return;
	}
	if ((int8_t)floor_cell_up < 0)
		d0 |= 2u;
	if (floor_cell != 1u)
	{
		turtle_lower_floor(d0, a0, a6);
		OBJECT(a0)->y -= 0x400u;
		return;
	}
	height_whole = OBJECT(a0)->height_whole;
	if (height_whole == OBJECT(a0)->floor_height)
	{
		OBJECT(a0)->height &= 0xFF00u;
		d0 |= 1u;
		turtle_wall_contacts(d0, a0);
		return;
	}
	if (OBJECT(a0)->floor_height <= height_whole)
	{
		d0 |= 0x80u;
		turtle_wall_contacts(d0, a0);
		return;
	}
	OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
	OBJECT(a0)->height &= 0xFF00u;
	d0 |= 1u;
	turtle_wall_contacts(d0, a0);
}

/* the turtle steps down a level of the floor map */
void turtle_lower_floor(uint8_t d0, uint32_t a0, uint32_t a6)
{
	uint8_t d0_2 = 0, d2 = 0, d3 = 0;
	uint8_t floor_height = 0;

	d2 = 0u;
	d3 = 0x14u;
	for (;;)
	{
		floor_height = OBJECT(a0)->floor_height;
		OBJECT(a0)->floor_height = floor_height - 8u;
		if (floor_height < 8u)
			OBJECT(a0)->floor_height = 0u;
		a6 += 0x40u;
		if (a6 >= OBJECT_ADDRESS(0))
			a6 -= 0x800u;
		d2++;
		if (d3 <= d2)
			break;
		if ((int8_t)mem_read8(a6) >= 0)
		{
			OBJECT(a0)->y &= 0xFFFFFF00u;
			d0 |= 0x82u;
			turtle_corner_contacts(d0, a0);
			return;
		}
	}
	OBJECT(a0)->x = 0xC000u;
	OBJECT(a0)->y = 0x2000u;
	d0_2 = 0x7Bu;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->contacts |= d0_2;
}

void turtle_walls_right(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0, d2 = 0, height_whole = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	d0 = 0u;
	if ((OBJECT(a0)->flags & 0x10u) != 0u)
	{
		turtle_floor_contact(d0, a0);
		return;
	}
	d2 = height_cell_up;
	t1 = floor_cell_up;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 2u;
	if (floor_cell != 1u)
	{
		turtle_leave_floor_right(d0, a0, a6);
		return;
	}
	height_whole = OBJECT(a0)->height_whole;
	if (height_whole == OBJECT(a0)->floor_height)
	{
		OBJECT(a0)->height &= 0xFF00u;
		d0 |= 1u;
	}
	else
	{
		if (height_whole < OBJECT(a0)->floor_height)
		{
			OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
			OBJECT(a0)->height &= 0xFF00u;
			d0 |= 1u;
			t2 = floor_cell_right;
			d1 = t2;
			if ((int8_t)t2 >= 0)
			{
				t3 = floor_cell_left;
				d1 = t3;
				if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
				{
					turtle_corner_contacts(d0, a0);
					return;
				}
				d0 |= 0x10u;
				turtle_corner_contacts(d0, a0);
				return;
			}
			if (d1 == 0xFEu)
			{
				d0 |= 8u;
				t3 = floor_cell_left;
				d1 = t3;
				if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
				{
					turtle_corner_contacts(d0, a0);
					return;
				}
				d0 |= 0x10u;
				turtle_corner_contacts(d0, a0);
				return;
			}
			if (d1 != 0xFBu)
			{
				t3 = floor_cell_left;
				d1 = t3;
				if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
				{
					turtle_corner_contacts(d0, a0);
					return;
				}
				d0 |= 0x10u;
				turtle_corner_contacts(d0, a0);
				return;
			}
			t4 = height_cell_right;
			d1 = t4;
			if ((int8_t)t4 >= 0 || d1 != 0xFBu)
			{
				t3 = floor_cell_left;
				d1 = t3;
				if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
				{
					turtle_corner_contacts(d0, a0);
					return;
				}
				d0 |= 0x10u;
				turtle_corner_contacts(d0, a0);
				return;
			}
			d0 |= 8u;
			t3 = floor_cell_left;
			d1 = t3;
			if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
			{
				turtle_corner_contacts(d0, a0);
				return;
			}
			d0 |= 0x10u;
			turtle_corner_contacts(d0, a0);
			return;
		}
		d0 |= 0x80u;
	}
	t2 = floor_cell_right;
	d1 = t2;
	if ((int8_t)t2 >= 0)
	{
		t3 = floor_cell_left;
		d1 = t3;
		if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
		{
			turtle_corner_contacts(d0, a0);
			return;
		}
		d0 |= 0x10u;
		turtle_corner_contacts(d0, a0);
		return;
	}
	if (d1 == 0xFEu)
	{
		d0 |= 8u;
		t3 = floor_cell_left;
		d1 = t3;
		if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
		{
			turtle_corner_contacts(d0, a0);
			return;
		}
		d0 |= 0x10u;
		turtle_corner_contacts(d0, a0);
		return;
	}
	if (d1 != 0xFBu)
	{
		t3 = floor_cell_left;
		d1 = t3;
		if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
		{
			turtle_corner_contacts(d0, a0);
			return;
		}
		d0 |= 0x10u;
		turtle_corner_contacts(d0, a0);
		return;
	}
	t4 = height_cell_right;
	d1 = t4;
	if ((int8_t)t4 >= 0 || d1 != 0xFBu)
	{
		t3 = floor_cell_left;
		d1 = t3;
		if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
		{
			turtle_corner_contacts(d0, a0);
			return;
		}
		d0 |= 0x10u;
		turtle_corner_contacts(d0, a0);
		return;
	}
	d0 |= 8u;
	t3 = floor_cell_left;
	d1 = t3;
	if ((int8_t)t3 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
	{
		turtle_corner_contacts(d0, a0);
		return;
	}
	d0 |= 0x10u;
	turtle_corner_contacts(d0, a0);
}

void turtle_leave_floor_right(uint8_t d0, uint32_t a0, uint32_t a6)
{
	uint8_t d1_2 = 0;
	uint32_t d1 = 0;

	if (OBJECT(a0)->height_whole != OBJECT(a0)->floor_height)
	{
		d1_2 = floor_cell;
		if (d1_2 == 0xFBu || d1_2 == 0xFCu)
		{
			turtle_raise_floor(d0, a0, a6);
			return;
		}
		turtle_lower_floor(d0, a0, a6);
		OBJECT(a0)->x += 0x400u;
		return;
	}
	if (floor_cell == 0xFAu || floor_cell == 0xFCu || floor_cell == 0xFFu)
	{
		turtle_lower_floor(d0, a0, a6);
		OBJECT(a0)->x += 0x400u;
		return;
	}
	d1 = reset_ADDRESS;
	if (OBJECT(a0)->routine == 4u && OBJECT(a0)->turtle.reaction_variant >= 2u)
		d1 = 0x1800u;
	OBJECT(a0)->x -= d1;
	d0 |= 0x7Bu;
	OBJECT(a0)->contacts |= d0;
}

void turtle_walls_left(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0, d2 = 0, height_whole = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d0 = 0u;
	if ((OBJECT(a0)->flags & 0x10u) != 0u)
	{
		turtle_floor_contact(d0, a0);
		return;
	}
	d2 = height_cell_up;
	t1 = floor_cell_up;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 2u;
	if (floor_cell != 1u)
	{
		turtle_leave_floor_left(d0, a0, a6);
		return;
	}
	height_whole = OBJECT(a0)->height_whole;
	if (height_whole == OBJECT(a0)->floor_height)
	{
		OBJECT(a0)->height &= 0xFF00u;
		d0 |= 1u;
	}
	else
	{
		if (height_whole < OBJECT(a0)->floor_height)
		{
			OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
			OBJECT(a0)->height &= 0xFF00u;
			d0 |= 1u;
			t2 = floor_cell_left;
			d1 = t2;
			if ((int8_t)t2 < 0 && (d1 == 0xFDu || (d1 == 0xFAu && height_cell_left == 0xFAu)))
				d0 |= 0x10u;
			t3 = floor_cell_right;
			d1 = t3;
			if ((int8_t)t3 >= 0 || (d1 != 0xFEu && (d1 != 0xFBu || height_cell_right != 0xFBu)))
			{
				turtle_corner_contacts(d0, a0);
				return;
			}
			d0 |= 8u;
			turtle_corner_contacts(d0, a0);
			return;
		}
		d0 |= 0x80u;
	}
	t2 = floor_cell_left;
	d1 = t2;
	if ((int8_t)t2 < 0 && (d1 == 0xFDu || (d1 == 0xFAu && height_cell_left == 0xFAu)))
		d0 |= 0x10u;
	t3 = floor_cell_right;
	d1 = t3;
	if ((int8_t)t3 >= 0 || (d1 != 0xFEu && (d1 != 0xFBu || height_cell_right != 0xFBu)))
	{
		turtle_corner_contacts(d0, a0);
		return;
	}
	d0 |= 8u;
	turtle_corner_contacts(d0, a0);
}

void turtle_leave_floor_left(uint8_t d0, uint32_t a0, uint32_t a6)
{
	uint8_t d1_2 = 0;
	uint32_t d1 = 0;

	if (OBJECT(a0)->height_whole != OBJECT(a0)->floor_height)
	{
		d1_2 = floor_cell;
		if (d1_2 == 0xFAu || d1_2 == 0xFCu)
		{
			turtle_raise_floor(d0, a0, a6);
			return;
		}
		turtle_lower_floor(d0, a0, a6);
		OBJECT(a0)->x -= 0x400u;
		return;
	}
	if (floor_cell == 0xFBu || floor_cell == 0xFCu || floor_cell == 0xFFu)
	{
		turtle_lower_floor(d0, a0, a6);
		OBJECT(a0)->x -= 0x400u;
		return;
	}
	d1 = reset_ADDRESS;
	if (OBJECT(a0)->routine == 4u && OBJECT(a0)->turtle.reaction_variant >= 2u)
		d1 = 0x1800u;
	OBJECT(a0)->x += d1;
	d0 |= 0x7Bu;
	OBJECT(a0)->contacts |= d0;
}

void turtle_walls_up_left(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0;

	d0 = 0u;
	if ((OBJECT(a0)->flags & 0x10u) != 0u)
	{
		turtle_floor_contact(d0, a0);
		return;
	}
	if (floor_cell != 1u)
	{
		turtle_leave_floor_left(d0, a0, a6);
		return;
	}
	turtle_walls_up_diagonal(d0, a0);
}

void turtle_walls_up_right(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0;

	d0 = 0u;
	if ((OBJECT(a0)->flags & 0x10u) != 0u)
	{
		turtle_floor_contact(d0, a0);
		return;
	}
	if (floor_cell != 1u)
	{
		turtle_leave_floor_right(d0, a0, a6);
		return;
	}
	turtle_walls_up_diagonal(d0, a0);
}

void turtle_walls_up_diagonal(uint8_t d0, uint32_t a0)
{
	uint8_t d1 = 0, d2 = 0, height_whole = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	height_whole = OBJECT(a0)->height_whole;
	if (height_whole == OBJECT(a0)->floor_height)
	{
		OBJECT(a0)->height &= 0xFF00u;
		d0 |= 1u;
	}
	else if (OBJECT(a0)->floor_height <= height_whole)
		d0 |= 0x80u;
	else
	{
		OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
		OBJECT(a0)->height &= 0xFF00u;
		d0 |= 1u;
	}
	t1 = floor_cell_up;
	d1 = t1;
	if ((int8_t)t1 < 0)
	{
		if (d1 >= 0xFDu)
			d0 |= 2u;
		else
		{
			t2 = height_cell_up;
			d2 = t2;
			if ((int8_t)t2 < 0 && d2 < 0xFDu)
			{
				if (d1 != 0xFCu)
				{
					if (d1 != 0xFBu)
					{
						if (d1 == 0xFAu && d2 == 0xFAu)
						{
							d0 |= 2u;
							t3 = floor_cell_right;
							d1 = t3;
							if ((int8_t)t3 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && height_cell_right == 0xFBu)))
								d0 |= 8u;
							t4 = floor_cell_left;
							d1 = t4;
							if ((int8_t)t4 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
							{
								turtle_corner_contacts(d0, a0);
								return;
							}
							d0 |= 0x10u;
							turtle_corner_contacts(d0, a0);
							return;
						}
					}
					else if (d2 == 0xFBu)
					{
						d0 |= 2u;
						t3 = floor_cell_right;
						d1 = t3;
						if ((int8_t)t3 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && height_cell_right == 0xFBu)))
							d0 |= 8u;
						t4 = floor_cell_left;
						d1 = t4;
						if ((int8_t)t4 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
						{
							turtle_corner_contacts(d0, a0);
							return;
						}
						d0 |= 0x10u;
						turtle_corner_contacts(d0, a0);
						return;
					}
				}
				else if (d2 == 0xFCu)
				{
					d0 |= 2u;
					t3 = floor_cell_right;
					d1 = t3;
					if ((int8_t)t3 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && height_cell_right == 0xFBu)))
						d0 |= 8u;
					t4 = floor_cell_left;
					d1 = t4;
					if ((int8_t)t4 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
					{
						turtle_corner_contacts(d0, a0);
						return;
					}
					d0 |= 0x10u;
					turtle_corner_contacts(d0, a0);
					return;
				}
			}
		}
	}
	t3 = floor_cell_right;
	d1 = t3;
	if ((int8_t)t3 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && height_cell_right == 0xFBu)))
		d0 |= 8u;
	t4 = floor_cell_left;
	d1 = t4;
	if ((int8_t)t4 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
	{
		turtle_corner_contacts(d0, a0);
		return;
	}
	d0 |= 0x10u;
	turtle_corner_contacts(d0, a0);
}

void turtle_corner_contacts(uint8_t d0, uint32_t a0)
{
	uint8_t d1 = 0, d2 = 0;
	uint8_t t1 = 0, t2 = 0;

	d2 = height_cell_up_right;
	t1 = floor_cell_up_right;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 0x20u;
	d2 = height_cell_up_left;
	t2 = floor_cell_up_left;
	d1 = t2;
	if ((int8_t)t2 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 0x40u;
	OBJECT(a0)->contacts |= d0;
}

void turtle_walls_down_right(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0, d2 = 0, height_whole = 0;
	uint8_t t1 = 0, floor_height = 0;

	d0 = 0u;
	if (floor_cell == 0u)
	{
		OBJECT(a0)->contacts |= d0;
		return;
	}
	if ((OBJECT(a0)->flags & 0x10u) != 0u)
	{
		turtle_floor_contact(d0, a0);
		return;
	}
	d2 = height_cell_up;
	t1 = floor_cell_up;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 2u;
	if (floor_cell != 1u)
	{
		if (floor_cell == 0xFBu)
		{
			turtle_raise_floor(d0, a0, a6);
			return;
		}
		turtle_lower_floor(d0, a0, a6);
		OBJECT(a0)->x += 0x400u;
		OBJECT(a0)->y -= 0x400u;
		OBJECT(a0)->height += 0x400u;
		floor_height = OBJECT(a0)->floor_height;
		OBJECT(a0)->floor_height = floor_height - 4u;
		if (floor_height < 4u)
			OBJECT(a0)->floor_height = 0u;
		return;
	}
	height_whole = OBJECT(a0)->height_whole;
	if (height_whole == OBJECT(a0)->floor_height)
	{
		OBJECT(a0)->height &= 0xFF00u;
		d0 |= 1u;
		turtle_side_contacts(d0, a0);
		return;
	}
	if (OBJECT(a0)->floor_height <= height_whole)
	{
		d0 |= 0x80u;
		turtle_side_contacts(d0, a0);
		return;
	}
	OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
	OBJECT(a0)->height &= 0xFF00u;
	d0 |= 1u;
	turtle_side_contacts(d0, a0);
}

void turtle_side_contacts(uint8_t d0, uint32_t a0)
{
	uint8_t d1 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = floor_cell_right;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 == 0xFEu || (d1 == 0xFBu && height_cell_right == 0xFBu)))
		d0 |= 8u;
	t2 = floor_cell_left;
	d1 = t2;
	if ((int8_t)t2 >= 0 || (d1 != 0xFDu && (d1 != 0xFAu || height_cell_left != 0xFAu)))
	{
		turtle_corner_contacts(d0, a0);
		return;
	}
	d0 |= 0x10u;
	turtle_corner_contacts(d0, a0);
}

void turtle_walls_down_left(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0, d1 = 0, d2 = 0, height_whole = 0;
	uint8_t t1 = 0, floor_height = 0;

	d0 = 0u;
	if (floor_cell == 0u)
	{
		OBJECT(a0)->contacts |= d0;
		return;
	}
	if ((OBJECT(a0)->flags & 0x10u) != 0u)
	{
		turtle_floor_contact(d0, a0);
		return;
	}
	d2 = height_cell_up;
	t1 = floor_cell_up;
	d1 = t1;
	if ((int8_t)t1 < 0 && (d1 >= 0xFDu || d2 == d1))
		d0 |= 2u;
	if (floor_cell != 1u)
	{
		if (floor_cell == 0xFAu)
		{
			turtle_raise_floor(d0, a0, a6);
			return;
		}
		turtle_lower_floor(d0, a0, a6);
		OBJECT(a0)->x -= 0x400u;
		OBJECT(a0)->y -= 0x400u;
		OBJECT(a0)->height += 0x400u;
		floor_height = OBJECT(a0)->floor_height;
		OBJECT(a0)->floor_height = floor_height - 4u;
		if (floor_height < 4u)
			OBJECT(a0)->floor_height = 0u;
		return;
	}
	height_whole = OBJECT(a0)->height_whole;
	if (height_whole == OBJECT(a0)->floor_height)
	{
		OBJECT(a0)->height &= 0xFF00u;
		d0 |= 1u;
		turtle_side_contacts(d0, a0);
		return;
	}
	if (OBJECT(a0)->floor_height <= height_whole)
	{
		d0 |= 0x80u;
		turtle_side_contacts(d0, a0);
		return;
	}
	OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
	OBJECT(a0)->height &= 0xFF00u;
	d0 |= 1u;
	turtle_side_contacts(d0, a0);
}
