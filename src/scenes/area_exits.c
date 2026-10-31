/**
 *    Name:        scenes/area_exits.c
 *    Description: the areas' exits: the turtles walk out, and the cutscenes between the areas (Shredder takes April, the villains' picture, the van, April's thanks, the van's crash, Splinter freed)
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the area is cleared: the turtles start walking out */
void turtle_start_area_exit(uint32_t *p_d1, uint32_t *p_d7)
{
	uint16_t d0 = 0;
	uint32_t a6 = 0, object = 0, turtle = 0;

	turtle = OBJECT_ADDRESS(0);
	object = OBJECT_ADDRESS(40);
	a6 = marker_times_ADDRESS;
	d0 = 0u;
	do
	{
		if ((OBJECT(turtle)->flags & 1u) != 0u)
		{
			OBJECT(turtle)->flags |= 0x80u;
			OBJECT(object)->flags = (uint8_t)d0;
			mem_write8(a6, (uint8_t)d0);
			OBJECT(turtle)->turtle.invulnerable_time = (uint8_t)d0;
		}
		turtle += 0x50u;
		a6++;
		object += 0x50u;
	} while (turtle < OBJECT_ADDRESS(4));
	time_since_balloon = d0;
	balloons_said = (uint8_t)d0;
	balloon_time = (uint8_t)d0;
	cutscene_step = 0u;
	switch (stage)
	{
	case 0:
		turtle_exit_building_start(p_d1, p_d7);
		return;
	case 1:
		turtle_exit_apartment_start(p_d1, p_d7);
		return;
	case 2:
		turtle_exit_street_start(p_d1, p_d7);
		return;
	case 3:
		turtle_exit_sewer_start(p_d1, p_d7);
		return;
	case 4:
		turtle_exit_car_street_start(p_d1, p_d7);
		return;
	case 5:
		turtle_exit_highway_start(p_d1, p_d7);
		return;
	case 6:
		exit_skateboard_start();
		return;
	case 7:
		turtle_exit_building_site_start(p_d1, p_d7);
		return;
	case 8:
		turtle_exit_technodrome_start(p_d1, p_d7);
		return;
	case 9:
		turtle_exit_final_start();
		return;
	}
}

void turtle_exit_building_start(uint32_t *p_d1, uint32_t *p_d7)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, turtle = 0;

	turtle = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(turtle)->flags & 1u) != 0u)
		{
			OBJECT(turtle)->flags &= 0xBFu;
			OBJECT(turtle)->turtle.exit_step = 0u;
			d0 = 0x100u;
			if (OBJECT(turtle)->y < indexed_table_of_32_bit_values_005000_ADDRESS)
				d0++;
			turtle_set_state(d0, turtle, p_d1, &ignored, &ignored_2, &ignored_3, p_d7);
		}
		turtle += 0x50u;
	} while (turtle < OBJECT_ADDRESS(4));
	cutscene_counter = 0u;
}

void turtle_exit_apartment_start(uint32_t *p_d1, uint32_t *p_d7)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, object = 0;

	cutscene_wait = 0x20u;
	balloons_said = 2u;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			d0 = 0u;
			turtle_set_state(d0, object, p_d1, &ignored, &ignored_2, &ignored_3, p_d7);
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
}

void turtle_exit_street_start(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;

	turtle = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(turtle)->flags & 1u) != 0u)
		{
			OBJECT(turtle)->flags &= 0xBFu;
			OBJECT(turtle)->turtle.exit_step = 0u;
			if (OBJECT(turtle)->x >= 0x13C00u)
				OBJECT(turtle)->flags |= 0x40u;
			d0 = 0x100u;
			turtle_set_state(d0, turtle, p_d1, &ignored, &ignored_3, &ignored_4, &d7);
		}
		turtle += 0x50u;
	} while (turtle < OBJECT_ADDRESS(4));
	cutscene_time = 0xA0u;
	d7_2 = (d7 & ~0xFFu) | 0x73u;
	queue_sound((uint8_t)d7_2, 0u);
	*p_d7 = d7_2;
}

void turtle_exit_sewer_start(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;

	turtle = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(turtle)->flags & 1u) != 0u)
		{
			OBJECT(turtle)->flags |= 0x40u;
			OBJECT(turtle)->contacts &= 0x7Fu;
			OBJECT(turtle)->turtle.exit_step = 0u;
			d0 = 0x100u;
			if (OBJECT(turtle)->screen_y < 0x50u)
				d0++;
			turtle_set_state(d0, turtle, p_d1, &ignored, &ignored_3, &ignored_4, &d7);
		}
		turtle += 0x50u;
	} while (turtle < OBJECT_ADDRESS(4));
	d7_2 = (d7 & ~0xFFu) | 0x6Eu;
	queue_sound((uint8_t)d7_2, 0u);
	*p_d7 = d7_2;
}

void turtle_exit_car_street_start(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint16_t d0 = 0;
	uint32_t a0 = 0, animation = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, object = 0, turtle = 0;

	object = OBJECT_ADDRESS(24);
	do
	{
		OBJECT(object)->flags = 0u;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(32));
	turtle = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(turtle)->flags & 1u) != 0u)
		{
			OBJECT(turtle)->flags &= 0xBFu;
			d1 = OBJECT(turtle)->x >> 8;
			if (indexed_table_of_16_bit_values_02C0F0[OBJECT(turtle)->kind * 2u] < (uint16_t)d1)
				OBJECT(turtle)->flags |= 0x40u;
			d0 = 0x100u;
			OBJECT(turtle)->turtle.exit_step = 0u;
			if (OBJECT(turtle)->y < 0x4000u)
				d0++;
			turtle_set_state(d0, turtle, &d1, &ignored, &ignored_2, &ignored_3, p_d7);
		}
		turtle += 0x50u;
	} while (turtle < OBJECT_ADDRESS(4));
	a0 = OBJECT_ADDRESS(44);
	animation = 0x2E134u;
	d1 = set_animation(d1, a0, animation);
	OBJECT(OBJECT_ADDRESS(40))->colour = 0xFFu;
	OBJECT(OBJECT_ADDRESS(41))->colour = 0xFFu;
	layer_priority = 4u;
	io_write8(PRIORITY_0C0001, 4u);
	*p_d1 = d1;
}

void turtle_exit_highway_start(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, object = 0;

	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			OBJECT(object)->flags &= 0xBFu;
			OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | 0x10u;
			d0 = 0x200u;
			turtle_set_state(d0, object, p_d1, &ignored, &ignored_3, &ignored_4, &d7);
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	d7_2 = (d7 & ~0xFFu) | 0xFEu;
	queue_sound((uint8_t)d7_2, 0u);
	*p_d7 = d7_2;
}

/* the ride's exit starts: the van's colours and the road going round */
void exit_skateboard_start(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	d7 = 0x43Bu;
	a6 = 0xC824u;
	post_palette_request(d7, a6);
	d7 = 0x43Cu;
	a6 = 0xC844u;
	post_palette_request(d7, a6);
	exit_skateboard_road_round();
}

void turtle_exit_building_site_start(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a0 = 0, animation = 0, d7_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, object = 0;

	object = OBJECT_ADDRESS(24);
	do
	{
		OBJECT(object)->flags = 0u;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(32));
	a0 = OBJECT_ADDRESS(44);
	animation = 0x2DB0Au;
	*p_d1 = set_animation(*p_d1, a0, animation);
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			OBJECT(object)->flags &= 0xBFu;
			if (OBJECT(object)->x >= 0x10000u)
				OBJECT(object)->flags |= 0x40u;
			OBJECT(object)->y_speed = 0;
			d0 = 0x101u;
			turtle_set_state(d0, object, p_d1, &ignored, &ignored_2, &ignored_3, &d7);
			OBJECT(object)->frame_time = 0u;
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	d7_2 = (d7 & ~0xFFu) | 0x6Eu;
	queue_sound((uint8_t)d7_2, animation);
	*p_d7 = d7_2;
}

void turtle_exit_technodrome_start(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, object = 0;

	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			OBJECT(object)->flags &= 0xBFu;
			d0 = 0x100u;
			if (OBJECT(object)->y < indexed_table_of_32_bit_values_005000_ADDRESS)
				d0++;
			turtle_set_state(d0, object, p_d1, &ignored, &ignored_3, &ignored_4, &d7);
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	layer_priority = 4u;
	io_write8(PRIORITY_0C0001, 4u);
	cutscene_wait = 0xC0u;
	d7_2 = (d7 & ~0xFFu) | 0x73u;
	queue_sound((uint8_t)d7_2, 0u);
	*p_d7 = d7_2;
}

void turtle_exit_final_start(void)
{
	uint32_t object = 0;

	cutscene_time = 0xC000u;
	object = OBJECT_ADDRESS(0);
	do
	{
		OBJECT(object)->frame_time = 0u;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
}

uint32_t run_area_exit(uint32_t d1)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;
	uint8_t t1 = 0;

	time_since_balloon++;
	if (balloon_time != 0u)
	{
		t1 = balloon_time;
		balloon_time = t1 - 1u;
		if (t1 == 1u)
			erase_balloon(&ignored, &ignored_2, &ignored_3);
	}
	switch (stage)
	{
	case 0:
		return turtle_exit_building(d1, 0u);
	case 1:
		return run_exit_apartment(d1, 0u);
	case 2:
		return turtle_exit_street(d1, 0u);
	case 3:
		return run_exit_sewer(d1);
	case 4:
		return run_exit_car_street(d1, 0u);
	case 5:
		return turtle_exit_highway(d1);
	case 6:
		return run_exit_skateboard(d1, 0u);
	case 7:
		return run_exit_building_site(d1, 0u);
	case 8:
		return turtle_exit_technodrome(d1, 0u);
	case 9:
		return run_exit_final(d1);
	}
}

uint32_t turtle_exit_building(uint32_t d1, uint32_t d2)
{
	uint32_t d0 = 0, d1_2 = 0, object = 0;
	uint8_t t1 = 0;

	if (cutscene_counter != 0u)
	{
		t1 = cutscene_counter;
		cutscene_counter = t1 - 1u;
		if (t1 == 1u)
		{
			area_beaten = 0u;
			area_cleared = 0u;
			scene_step++;
		}
		return d1;
	}
	turtles_on_the_way = 0u;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			d1 = (d1 & ~0xFFFFu) | OBJECT(object)->screen_x;
			if ((uint16_t)d1 < 0x170u)
			{
				turtles_on_the_way--;
				d1_2 = (d1 & ~0xFFFFu) | 0x170u;
				d2 = (d2 & ~0xFFFFu) | 0x50u;
				direction_to(object, &d0, &d1_2, &d2);
				d1 = (d1_2 & ~0xFFFFu) | 0x300u;
				move_in_direction((uint8_t)d0, (uint16_t)d1, object);
			}
			else
			{
				d2 = (d2 & ~0xFFFFu) | OBJECT(object)->screen_y;
				if ((uint16_t)d2 >= 0x54u || (uint16_t)d2 < 0x4Cu)
				{
					turtles_on_the_way--;
					d1_2 = (d1 & ~0xFFFFu) | 0x170u;
					d2 = (d2 & ~0xFFFFu) | 0x50u;
					direction_to(object, &d0, &d1_2, &d2);
					d1 = (d1_2 & ~0xFFFFu) | 0x300u;
					move_in_direction((uint8_t)d0, (uint16_t)d1, object);
				}
				else
					OBJECT(object)->flags &= 0x7Fu;
			}
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	if (turtles_on_the_way == 0u)
		cutscene_counter = 0x20u;
	return d1;
}

uint32_t run_exit_apartment(uint32_t d1, uint32_t d2)
{
	uint32_t ignored = 0, ignored_3 = 0;

	if (cutscene_step < 3u)
		april_wait_for_rescue(0u, &d1, &ignored, &ignored_3);
	switch (cutscene_step)
	{
	case 0:
		d1 = exit_apartment_shredder_appears(d1);
		break;
	case 1:
		exit_apartment_shredder_takes_april();
		break;
	case 2:
		exit_apartment_shredder_leaps();
		break;
	case 3:
		d1 = exit_apartment_shredder_escapes(d1, d2);
		break;
	case 4:
		d1 = exit_apartment_kidnap_picture(d1);
		break;
	case 5:
		exit_apartment_picture_wait();
		break;
	}
	set_layers_scroll();
	return d1;
}

/* the turtles turn to the door and Shredder appears in it */
uint32_t exit_apartment_shredder_appears(uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0;
	uint32_t a0 = 0, animation = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, object = 0;
	uint8_t t1 = 0;

	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 != 1u)
		return d1;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			OBJECT(object)->flags &= 0xBFu;
			if (OBJECT(object)->x >= 0x12C00u)
				OBJECT(object)->flags |= 0x40u;
			d0 = 0x101u;
			turtle_set_state(d0, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
			OBJECT(object)->frame_time = 0u;
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	a0 = OBJECT_ADDRESS(48);
	OBJECT(OBJECT_ADDRESS(48))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(48))->colour = 0xFFu;
	OBJECT(OBJECT_ADDRESS(48))->animation_delay = 0u;
	OBJECT(OBJECT_ADDRESS(48))->x = 0x12C00u;
	OBJECT(OBJECT_ADDRESS(48))->y = 0x6000u;
	OBJECT(OBJECT_ADDRESS(48))->screen_x = 0x120u;
	OBJECT(OBJECT_ADDRESS(48))->screen_y = 0x60u;
	OBJECT(OBJECT_ADDRESS(48))->height = 0u;
	OBJECT(OBJECT_ADDRESS(48))->floor_height = 0u;
	animation = 0x2D842u;
	d1 = set_animation(d1, a0, animation);
	d7 = 0xFEu;
	queue_sound(d7, animation);
	cutscene_wait = 0x20u;
	next_area_step();
	return d1;
}

void next_area_step(void)
{
	cutscene_step++;
}

/* Shredder draws his sword, walks to April and grabs her */
void exit_apartment_shredder_takes_april(void)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0;
	uint32_t animation = 0, object = 0;
	uint8_t t1 = 0;

	object = OBJECT_ADDRESS(48);
	if (cutscene_wait == 0u)
	{
		OBJECT(object)->x -= 0x300u;
		d0 = (uint16_t)(OBJECT(object)->x >> 8);
		OBJECT(object)->screen_x = d0;
		if ((uint16_t)d0 >= 0xB0u)
			return;
		animation = 0x2D88Eu;
		set_animation(0u, object, animation);
		cutscene_wait = 0x18u;
		next_area_step();
		return;
	}
	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 != 1u)
		return;
	animation = 0x2D84Cu;
	set_animation(0u, object, animation);
	d7 = 0x72u;
	queue_sound(d7, animation);
}

/* April is in Shredder's arms and he leaps away */
void exit_apartment_shredder_leaps(void)
{
	uint32_t object = 0;
	uint8_t t1 = 0;

	object = OBJECT_ADDRESS(48);
	if (OBJECT(OBJECT_ADDRESS(48))->frame_time == 0u)
	{
		OBJECT(object)->x_speed = 0x380;
		OBJECT(object)->y_speed &= 0xFFu;
		next_area_step();
		return;
	}
	if (cutscene_wait != 0u)
	{
		t1 = cutscene_wait;
		cutscene_wait = t1 - 1u;
		if (t1 == 1u)
		{
			OBJECT(OBJECT_ADDRESS(47))->flags = 0u;
			return;
		}
	}
}

/* Shredder bounds off with April, the turtles after him, and the screen is cleared */
uint32_t exit_apartment_shredder_escapes(uint32_t d1, uint32_t d2)
{
	uint16_t d7 = 0, x_speed = 0;
	uint32_t a6 = 0, d0 = 0, d1_2 = 0, ignored = 0, object = 0;
	uint16_t x_speed_2 = 0, x_speed_3 = 0;

	object = OBJECT_ADDRESS(48);
	if (OBJECT(OBJECT_ADDRESS(48))->screen_x < 0x178u)
	{
		d1_2 = (d1 & ~0xFFFFu) | 0x178u;
		d2 = 0x70u;
		direction_to(object, &d0, &d1_2, &d2);
		d1_2 = (d1_2 & ~0xFFFFu) | 0x300u;
		move_in_direction((uint8_t)d0, (uint16_t)d1_2, object);
		if ((uint8_t)(OBJECT(object)->y_speed >> 8u) != 0u)
		{
			x_speed = (uint16_t)OBJECT(object)->x_speed;
			x_speed_2 = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = x_speed_2 - x_speed;
			if (x_speed_2 < x_speed)
				OBJECT(object)->height = 0u;
			OBJECT(object)->x_speed += 0x18u;
		}
		else
		{
			OBJECT(object)->y = (OBJECT(object)->y & 0xFFFF0000u) | ((uint16_t)OBJECT(object)->y + OBJECT(object)->x_speed & 0xFFFFu);
			x_speed_3 = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = x_speed_3 - 0x10u;
			if (x_speed_3 < 0x10u)
			{
				OBJECT(object)->x_speed = 0u - OBJECT(object)->x_speed;
				OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFFu) | (((uint8_t)(OBJECT(object)->y_speed >> 8u) - 1u & 0xFFu) << 8u);
			}
		}
		object = OBJECT_ADDRESS(0);
		do
		{
			if ((OBJECT(object)->flags & 1u) != 0u)
			{
				if (OBJECT(object)->frame_time == 0u)
					OBJECT(object)->frame_time = 4u;
				d1_2 = (d1_2 & ~0xFFFFu) | 0x150u;
				d2 = (d2 & ~0xFFFFu) | 0x58u;
				direction_to(object, &d0, &d1_2, &d2);
				d1_2 = (d1_2 & ~0xFFFFu) | 0x100u;
				move_in_direction((uint8_t)d0, (uint16_t)d1_2, object);
			}
			object += 0x50u;
		} while (object < OBJECT_ADDRESS(4));
		return d1_2;
	}
	OBJECT(object)->flags = 0u;
	OBJECT(OBJECT_ADDRESS(0))->flags &= 0x7Fu;
	OBJECT(OBJECT_ADDRESS(1))->flags &= 0x7Fu;
	OBJECT(OBJECT_ADDRESS(2))->flags &= 0x7Fu;
	OBJECT(OBJECT_ADDRESS(3))->flags &= 0x7Fu;
	next_area_step();
	exit_cutscene = 0xFFu;
	LAYER(LAYER_A)->x = 0x800u;
	LAYER(LAYER_B)->x = 0x800u;
	LAYER(WORKING_LAYER)->x = 0x800u;
	LAYER(LAYER_A)->y = 0x10000u;
	LAYER(LAYER_B)->y = 0x10000u;
	LAYER(WORKING_LAYER)->y = 0x10000u;
	clear_layers(&d1_2, &ignored);
	a6 = 0xA13Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	return d1_2;
}

/* the picture of Shredder carrying April off with the turtles leaping after him */
uint32_t exit_apartment_kidnap_picture(uint32_t d1)
{
	uint32_t carry = 0;
	uint8_t d0 = 0, d7_2 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a0 = 0, a5 = 0, animation = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, object = 0, object_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (palettes_busy != 0u)
		return d1;
	clear_layers(&ignored, &ignored_2);
	a0 = TILE_RAM + 0x4008u;
	d0 = 0x34u;
	d1_2 = 0u;
	d7 = 0x1Fu;
	do
	{
		d6 = 0x1Fu;
		do
		{
			io_write8(a0, d0);
			a0++;
			io_write8(a0, d1_2);
			carry = (uint8_t)(d1_2 + 1u) < d1_2;
			d1_2 = (uint8_t)(d1_2 + 1u);
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
	io_write8(TILES_106B00, 0xE0u);
	tile_banks_0_1 = 0xE0u;
	a0 = TILE_RAM + 0x2418u;
	d0 = 0xBu;
	d1_2 = 0u;
	d7 = 0x17u;
	do
	{
		d6 = 0x17u;
		do
		{
			io_write8(a0, d0);
			a0++;
			io_write8(a0, d1_2);
			carry = (uint8_t)(d1_2 + 1u) < d1_2;
			d1_2 = (uint8_t)(d1_2 + 1u);
			a0++;
			if (carry)
			{
				d0++;
				if (d0 == 0xCu)
					d0 = 0x18u;
			}
			t3 = d6 - 1u;
			d6 = t3;
		} while (t3 != 0xFFFFu);
		t4 = d7 - 1u;
		d7 = t4;
		a0 += 0x50u;
	} while (t4 != 0xFFFFu);
	io_write8(TILES_106E00, 0x2Du);
	tile_banks_2_3 = 0x2Du;
	a5 = animations_02BA9A_ADDRESS;
	object = OBJECT_ADDRESS(44);
	object_2 = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object_2)->flags & 1u) != 0u)
		{
			OBJECT(object)->flags = 0x81u;
			OBJECT(object)->height = 0u;
			OBJECT(object)->colour = 0xFFu;
			OBJECT(object)->animation_delay = 0u;
			OBJECT(object)->screen_x = 0x78u;
			OBJECT(object)->screen_y = 0x80u;
			animation = DATA32(a5);
			d1_2 = set_animation(d1_2, object, animation);
		}
		object_2 += 0x50u;
		a5 += 4u;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(48));
	OBJECT(object)->flags = 0x81u;
	OBJECT(object)->height = 0u;
	OBJECT(object)->colour = 0xFFu;
	OBJECT(object)->animation_delay = 0u;
	OBJECT(object)->screen_x = 0xA7u;
	OBJECT(object)->screen_y = 0x40u;
	animation = 0x2DC36u;
	d1_2 = set_animation(d1_2, object, animation);
	d7_2 = 0x40u;
	queue_sound(d7_2, animation);
	cutscene_time = 0x108u;
	next_area_step();
	return d1_2;
}

/* the picture stays a while with Shredder's speech, then the exit is over */
void exit_apartment_picture_wait(void)
{
	uint8_t d7 = 0;
	uint16_t t1 = 0;

	t1 = cutscene_time;
	cutscene_time = t1 - 1u;
	if (t1 == 1u)
	{
		area_beaten = 0u;
		area_cleared = 0u;
		scene_step++;
		return;
	}
	if (cutscene_time != 0xF0u)
		return;
	d7 = 0xA7u;
	queue_sound(d7, 0u);
}

/* area 2's exit: the turtles walk to one place and jump in there */
uint32_t turtle_exit_street(uint32_t d1, uint32_t d2)
{
	uint32_t turtle = 0;
	uint16_t t1 = 0;

	turtle = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(turtle)->flags & 1u) != 0u)
		{
			switch (OBJECT(turtle)->turtle.exit_step)
			{
			case 0:
				turtle_exit_street_walk(0u, 0u, turtle, &d1, &d2);
				break;
			case 1:
				turtle_exit_street_jump(0u, 0u, turtle, &d1, &d2);
				break;
			case 2:
				turtle_exit_street_vanish(turtle);
				break;
			}
		}
		turtle += 0x50u;
	} while (turtle < OBJECT_ADDRESS(4));
	t1 = cutscene_time;
	cutscene_time = t1 - 1u;
	if (t1 == 1u)
	{
		area_beaten = 0u;
		area_cleared = 0u;
		scene_step++;
	}
	return d1;
}

void turtle_exit_street_walk(uint32_t d5, uint32_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint32_t d1 = *p_d1;
	uint32_t d2 = *p_d2;
	uint16_t d0_2 = 0;
	uint32_t d0 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0;

	turtles_on_the_way--;
	d1_2 = (d1 & ~0xFFFFu) | OBJECT(a0)->screen_x;
	if ((uint16_t)d1_2 < 0x100u)
	{
		d1_2 = (d1_2 & ~0xFFFFu) | 0x13Cu;
		d2 = (d2 & ~0xFFFFu) | 0x34u;
		direction_to(a0, &d0, &d1_2, &d2);
		d1_2 = (d1_2 & ~0xFFFFu) | 0x280u;
		move_in_direction((uint8_t)d0, (uint16_t)d1_2, a0);
	}
	else
	{
		d2 = (d2 & ~0xFFFFu) | OBJECT(a0)->screen_y;
		if ((uint16_t)d2 < 0x60u)
		{
			OBJECT(a0)->turtle.jump_speed = 0x700u;
			OBJECT(a0)->height = 0u;
			OBJECT(a0)->floor_height = 0u;
			OBJECT(a0)->turtle.falling = 0u;
			OBJECT(a0)->contacts |= 0x80u;
			d0_2 = 0x201u;
			turtle_set_state(d0_2, a0, &d1_2, &ignored, &d5, &d6, &ignored_2);
			OBJECT(a0)->turtle.exit_step++;
		}
		else
		{
			d1_2 = (d1_2 & ~0xFFFFu) | 0x13Cu;
			d2 = (d2 & ~0xFFFFu) | 0x34u;
			direction_to(a0, &d0, &d1_2, &d2);
			d1_2 = (d1_2 & ~0xFFFFu) | 0x280u;
			move_in_direction((uint8_t)d0, (uint16_t)d1_2, a0);
		}
	}
	*p_d1 = d1_2;
	*p_d2 = d2;
}

void turtle_exit_street_jump(uint32_t d5, uint32_t d6, uint32_t a0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint32_t d1 = *p_d1;
	uint32_t d2 = *p_d2;
	uint16_t d0 = 0, jump_speed = 0;
	uint32_t animation = 0, d0_2 = 0, d1_2 = 0, d2_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t height = 0, jump_speed_2 = 0, t1 = 0, t2 = 0;

	turtles_on_the_way--;
	if (OBJECT(a0)->turtle.falling != 0u)
	{
		jump_speed = OBJECT(a0)->turtle.jump_speed;
		height = OBJECT(a0)->height;
		OBJECT(a0)->height = height - jump_speed;
		if (height < jump_speed)
		{
			OBJECT(a0)->height = 0u;
			OBJECT(a0)->turtle.jump_speed = 0u;
		}
		OBJECT(a0)->turtle.jump_speed += 0x50u;
	}
	else
	{
		OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
		jump_speed_2 = OBJECT(a0)->turtle.jump_speed;
		OBJECT(a0)->turtle.jump_speed = jump_speed_2 - 0x50u;
		if (jump_speed_2 < 0x50u)
		{
			OBJECT(a0)->turtle.jump_speed = 0u - OBJECT(a0)->turtle.jump_speed;
			OBJECT(a0)->turtle.falling--;
			d0 = 0x203u;
			turtle_set_state(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
		}
	}
	d1_2 = (d1 & ~0xFFFFu) | OBJECT(a0)->screen_x;
	t1 = d1_2;
	d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(t1 - 0x139u);
	if (t1 < 0x139u || (uint16_t)d1_2 >= 7u)
	{
		d1_2 = (d1_2 & ~0xFFFFu) | 0x13Cu;
		d2 = (d2 & ~0xFFFFu) | 0x34u;
		direction_to(a0, &d0_2, &d1_2, &d2);
		d1_2 = (d1_2 & ~0xFFFFu) | 0x280u;
		move_in_direction((uint8_t)d0_2, (uint16_t)d1_2, a0);
	}
	else
	{
		d2_2 = (d2 & ~0xFFFFu) | OBJECT(a0)->screen_y;
		t2 = d2_2;
		d2 = (d2_2 & ~0xFFFFu) | (uint16_t)(t2 - 0x31u);
		if (t2 < 0x31u || (uint16_t)d2 >= 7u)
		{
			d1_2 = (d1_2 & ~0xFFFFu) | 0x13Cu;
			d2 = (d2 & ~0xFFFFu) | 0x34u;
			direction_to(a0, &d0_2, &d1_2, &d2);
			d1_2 = (d1_2 & ~0xFFFFu) | 0x280u;
			move_in_direction((uint8_t)d0_2, (uint16_t)d1_2, a0);
		}
		else if (OBJECT(a0)->height == 0u)
		{
			OBJECT(a0)->x = 0x13C00u;
			OBJECT(a0)->y = 0x3400u;
			d1_2 = 0x34u;
			OBJECT(a0)->screen_x = 0x13Cu;
			OBJECT(a0)->screen_y = 0x34u;
			animation = animations_02BC56[OBJECT(a0)->kind];
			d1_2 = set_animation(d1_2, a0, animation);
			OBJECT(a0)->turtle.exit_step++;
		}
	}
	*p_d1 = d1_2;
	*p_d2 = d2;
}

void turtle_exit_street_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags &= 0x7Fu;
		return;
	}
	turtles_on_the_way--;
}

uint32_t run_exit_sewer(uint32_t d1)
{
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)cutscene_step << 2);
	switch (d0)
	{
	case 0:
		d1 = turtle_exit_sewer(d1);
		break;
	case 4:
		d1 = exit_sewer_villains_picture(d1);
		break;
	case 8:
		d1 = exit_sewer_villains_taunt(d0, d1);
		break;
	}
	set_layers_scroll();
	return d1;
}

uint32_t turtle_exit_sewer(uint32_t d1)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d1_2 = 0, ignored = 0, turtle = 0;

	turtles_on_the_way = 0u;
	turtle = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(turtle)->flags & 1u) != 0u)
		{
			switch (OBJECT(turtle)->turtle.exit_step)
			{
			case 0:
				d1 = turtle_exit_sewer_walk(d1, turtle);
				break;
			case 1:
				d1 = turtle_exit_sewer_jump(d1, turtle);
				break;
			}
		}
		turtle += 0x50u;
	} while (turtle < OBJECT_ADDRESS(4));
	if (turtles_on_the_way != 0u)
		return d1;
	exit_cutscene = 0xFFu;
	LAYER(WORKING_LAYER)->x = 0u;
	LAYER(LAYER_A)->x = 0u;
	LAYER(LAYER_B)->x = 0u;
	LAYER(WORKING_LAYER)->y = 0x10000u;
	LAYER(LAYER_A)->y = 0x10000u;
	LAYER(LAYER_B)->y = 0x10000u;
	clear_layers(&d1_2, &ignored);
	layer_priority = 0u;
	io_write8(PRIORITY_0C0001, 0u);
	a6 = 0xA16Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	next_area_step();
	return d1_2;
}

uint32_t turtle_exit_sewer_walk(uint32_t d1, uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	turtles_on_the_way--;
	if (OBJECT(a0)->x >= 0x9000u)
	{
		OBJECT(a0)->x -= 0x300u;
		OBJECT(a0)->screen_x = OBJECT(a0)->x >> 8;
		return d1;
	}
	OBJECT(a0)->turtle.wait_timer = 0x20u;
	d0 = 0x200u;
	turtle_set_state(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
	OBJECT(a0)->turtle.exit_step++;
	return d1;
}

uint32_t turtle_exit_sewer_jump(uint32_t d1, uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t wait_timer = 0;

	if (OBJECT(a0)->turtle.wait_timer == 0u)
	{
		if (OBJECT(a0)->height + OBJECT(a0)->y < 0x10000u)
		{
			turtles_on_the_way--;
			OBJECT(a0)->height += 0x800u;
			if (OBJECT(a0)->height >= 0x4000u)
			{
				d0 = 0x202u;
				turtle_set_state(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
				return d1;
			}
		}
		return d1;
	}
	turtles_on_the_way--;
	wait_timer = OBJECT(a0)->turtle.wait_timer;
	OBJECT(a0)->turtle.wait_timer = wait_timer - 1u;
	if (wait_timer != 1u)
		return d1;
	d0 = 0x201u;
	turtle_set_state(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
	return d1;
}

/* the picture of Shredder, Bebop and Rocksteady with April tied up */
uint32_t exit_sewer_villains_picture(uint32_t d1)
{
	uint32_t a0 = 0, animation = 0, d1_2 = 0;

	if (palettes_busy != 0u)
		return d1;
	io_write8(TILES_106B00, 0x40u);
	tile_banks_0_1 = 0x40u;
	LAYER(WORKING_LAYER)->map = layers_0314C4_ADDRESS;
	LAYER(WORKING_LAYER)->blocks = 0x315C4u;
	LAYER(WORKING_LAYER)->map_width = 0x20u;
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	LAYER(WORKING_LAYER)->map = layers_03163C_ADDRESS;
	LAYER(WORKING_LAYER)->blocks = 0x3173Cu;
	a0 = TILE_RAM + 0x2000u;
	d1_2 = draw_whole_layer(a0);
	a0 = OBJECT_ADDRESS(44);
	OBJECT(OBJECT_ADDRESS(44))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(44))->contacts = 0u;
	OBJECT(OBJECT_ADDRESS(44))->screen_x = 0xD0u;
	OBJECT(OBJECT_ADDRESS(44))->screen_y = 0xA0u;
	OBJECT(OBJECT_ADDRESS(44))->height = 0u;
	OBJECT(OBJECT_ADDRESS(44))->colour = 0xFFu;
	OBJECT(OBJECT_ADDRESS(44))->animation_delay = 0u;
	animation = 0x2E162u;
	d1_2 = set_animation(d1_2, a0, animation);
	cutscene_time = 0x130u;
	next_area_step();
	return d1_2;
}

/* Rocksteady taunts the turtles, Shredder speaks, then the exit is over */
uint32_t exit_sewer_villains_taunt(uint32_t d0, uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d2 = 0, d3 = 0;
	uint32_t a0 = 0, animation = 0, d1_2 = 0, d4 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t t1 = 0;

	t1 = cutscene_time;
	cutscene_time = t1 - 1u;
	if (t1 == 1u)
	{
		area_beaten = 0u;
		area_cleared = 0u;
		scene_step++;
		return d1;
	}
	if (cutscene_time == 0x110u)
	{
		a0 = OBJECT_ADDRESS(45);
		OBJECT(OBJECT_ADDRESS(45))->flags = 0x81u;
		OBJECT(OBJECT_ADDRESS(45))->contacts = 0u;
		OBJECT(OBJECT_ADDRESS(45))->screen_x = 0x140u;
		OBJECT(OBJECT_ADDRESS(45))->screen_y = 0x58u;
		OBJECT(OBJECT_ADDRESS(45))->height = 0u;
		OBJECT(OBJECT_ADDRESS(45))->colour = 0xFFu;
		OBJECT(OBJECT_ADDRESS(45))->animation_delay = 0u;
		animation = animations_02E192_ADDRESS;
		d1 = set_animation(d1, a0, animation);
		d0 &= ~0xFFu;
		d1_2 = (d1 & ~0xFFFFu) | 0x110u;
		d2 = 0x40u;
		d4 = 0xFFFFFFD0u;
		d3 = 0x78u;
		show_balloon(d2, d3, &d0, &d1_2, &d4, &ignored_2, &ignored_3, &ignored_4, &ignored);
		draw_wide_balloon_pointer(ignored);
		return d1_2;
	}
	if (cutscene_time == 0xA0u)
	{
		OBJECT(OBJECT_ADDRESS(45))->flags = 0u;
		return d1;
	}
	if (cutscene_time != 0x80u)
		return d1;
	d7 = 0xA7u;
	queue_sound(d7, 0u);
	return d1;
}

uint32_t run_exit_car_street(uint32_t d1, uint32_t d2)
{
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)cutscene_step << 2);
	switch (d0)
	{
	case 0:
		d1 = turtle_exit_car_street(d1, d2);
		break;
	case 4:
		d1 = exit_car_street_van_start_up(d0, d1);
		break;
	case 8:
		d1 = exit_car_street_van_drives_off(d1);
		break;
	case 12:
		d1 = exit_car_street_april_hug_start(d1);
		break;
	case 16:
		d1 = exit_car_street_april_hug(d1);
		break;
	}
	set_layers_scroll();
	return d1;
}

uint32_t turtle_exit_car_street(uint32_t d1, uint32_t d2)
{
	uint32_t animation = 0, d0 = 0, d1_2 = 0, object = 0, turtle = 0;

	turtles_on_the_way = 0u;
	turtles_not_waiting = 0u;
	OBJECT(OBJECT_ADDRESS(40))->unk_20 &= 0xFFu;
	turtle = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(turtle)->flags & 1u) != 0u && (OBJECT(turtle)->flags & 0x80u) != 0u)
		{
			switch (OBJECT(turtle)->turtle.exit_step)
			{
			case 0:
				turtle_exit_car_street_wait(turtle, &d1, &d2);
				break;
			case 1:
				turtle_exit_car_street_board(turtle, &d1, &d2);
				break;
			case 2:
				d1 = turtle_exit_car_street_jump(d1, turtle);
				break;
			}
			update_screen_place(turtle);
		}
		turtle += 0x50u;
	} while (turtle < OBJECT_ADDRESS(4));
	if (turtles_on_the_way == 0u)
	{
		cutscene_time = 0x97u;
		next_area_step();
		return d1;
	}
	if (turtles_not_waiting != 0u)
		return d1;
	OBJECT(OBJECT_ADDRESS(0))->unk_2C = (OBJECT(OBJECT_ADDRESS(0))->unk_2C & 0xFFu) | 0x100u;
	OBJECT(OBJECT_ADDRESS(1))->unk_2C = (OBJECT(OBJECT_ADDRESS(1))->unk_2C & 0xFFu) | 0x100u;
	OBJECT(OBJECT_ADDRESS(2))->unk_2C = (OBJECT(OBJECT_ADDRESS(2))->unk_2C & 0xFFu) | 0x100u;
	OBJECT(OBJECT_ADDRESS(3))->unk_2C = (OBJECT(OBJECT_ADDRESS(3))->unk_2C & 0xFFu) | 0x100u;
	object = OBJECT_ADDRESS(40);
	OBJECT(OBJECT_ADDRESS(40))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(40))->contacts = 0u;
	OBJECT(OBJECT_ADDRESS(41))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(41))->contacts = 0u;
	OBJECT(OBJECT_ADDRESS(40))->screen_x = 0x50u;
	OBJECT(OBJECT_ADDRESS(41))->screen_x = 0x50u;
	OBJECT(OBJECT_ADDRESS(40))->height = 0u;
	OBJECT(OBJECT_ADDRESS(41))->height = 0u;
	OBJECT(OBJECT_ADDRESS(40))->x = indexed_table_of_32_bit_values_005000_ADDRESS;
	OBJECT(OBJECT_ADDRESS(41))->x = indexed_table_of_32_bit_values_005000_ADDRESS;
	d0 = 0xE000u;
	if (stage != 5u)
		d0 = 0xA000u;
	d0 -= LAYER(LAYER_B)->y & 0xFF00u;
	OBJECT(object)->y = d0;
	d1_2 = d0 - 0x400u;
	OBJECT(object + 0x50u)->y = d1_2;
	d1_2 = d1_2 >> 8;
	OBJECT(object)->screen_y = d0 >> 8;
	OBJECT(object + 0x50u)->screen_y = d1_2;
	OBJECT(object)->x_speed = 0x6A0;
	animation = 0x2D8C8u;
	d1_2 = set_animation(d1_2, object, animation);
	animation = 0x2D8E2u;
	object += 0x50u;
	return set_animation(d1_2, object, animation);
}

void turtle_exit_car_street_wait(uint32_t a0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint32_t d1 = *p_d1;
	uint32_t d2 = *p_d2;
	uint16_t d0 = 0;
	uint32_t d0_2 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t screen_y = 0, screen_x = 0;

	turtles_on_the_way--;
	d1_2 = (d1 & ~0xFFFFu) | indexed_table_of_16_bit_values_02C0F0[OBJECT(a0)->kind * 2u];
	screen_y = OBJECT(a0)->screen_y;
	d0 = (uint16_t)(screen_y - 0x3Cu);
	if (screen_y < 0x3Cu || d0 >= 8u)
	{
		turtles_not_waiting = 0xFFu;
		d0 = (uint16_t)((uint32_t)OBJECT(a0)->kind << 2);
		d1_2 = (d1_2 & ~0xFFFFu) | indexed_table_of_16_bit_values_02C0F0[d0 / 2u];
		d2 = (d2 & ~0xFFFFu) | rom_02C0F2[d0 / 2u];
		direction_to(a0, &d0_2, &d1_2, &d2);
		d1_2 = (d1_2 & ~0xFFFFu) | 0x200u;
		move_in_direction((uint8_t)d0_2, (uint16_t)d1_2, a0);
	}
	else
	{
		screen_x = OBJECT(a0)->screen_x;
		d0 = (uint16_t)(screen_x - d1_2);
		if (screen_x < (uint16_t)d1_2 || d0 >= 8u)
		{
			turtles_not_waiting = 0xFFu;
			d0 = (uint16_t)((uint32_t)OBJECT(a0)->kind << 2);
			d1_2 = (d1_2 & ~0xFFFFu) | indexed_table_of_16_bit_values_02C0F0[d0 / 2u];
			d2 = (d2 & ~0xFFFFu) | rom_02C0F2[d0 / 2u];
			direction_to(a0, &d0_2, &d1_2, &d2);
			d1_2 = (d1_2 & ~0xFFFFu) | 0x200u;
			move_in_direction((uint8_t)d0_2, (uint16_t)d1_2, a0);
		}
		else
		{
			OBJECT(a0)->turtle.move_timer = 0x10u;
			OBJECT(a0)->flags &= 0xBFu;
			if (OBJECT(a0)->kind >= 2u)
				OBJECT(a0)->flags |= 0x40u;
			d0 = 0x101u;
			turtle_set_state(d0, a0, &d1_2, &ignored, &ignored_2, &ignored_3, &ignored_4);
			OBJECT(a0)->frame_time = 0u;
		}
	}
	*p_d1 = d1_2;
	*p_d2 = d2;
}

void turtle_exit_car_street_board(uint32_t a0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint8_t d7 = 0;
	uint16_t d0_2 = 0;
	uint32_t d0 = 0, d1 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, object = 0;
	uint8_t move_timer = 0;
	uint16_t screen_y = 0, screen_x = 0, x_speed = 0;

	turtles_on_the_way--;
	turtles_not_waiting = 0xFFu;
	object = OBJECT_ADDRESS(40);
	if ((uint16_t)OBJECT(OBJECT_ADDRESS(40))->x_speed == 0u)
	{
		if (OBJECT(object)->x - OBJECT(object + 0x50u)->x < 0x4000u)
		{
			if ((uint8_t)(OBJECT(object)->unk_20 >> 8u) == 0u)
			{
				OBJECT(object)->unk_20 = (OBJECT(object)->unk_20 & 0xFFu) | (((uint8_t)(OBJECT(object)->unk_20 >> 8u) - 1u & 0xFFu) << 8u);
				OBJECT(object + 0x50u)->x -= 0x300u;
				OBJECT(object + 0x50u)->screen_x = OBJECT(object + 0x50u)->x >> 8;
			}
			return;
		}
		if (OBJECT(a0)->turtle.move_timer != 0u)
		{
			move_timer = OBJECT(a0)->turtle.move_timer;
			OBJECT(a0)->turtle.move_timer = move_timer - 1u;
			if (move_timer != 1u)
			{
				return;
			}
			OBJECT(a0)->frame_time = 6u;
			return;
		}
		if (stage == 5u)
		{
			*p_d1 = LAYER(LAYER_B)->y >> 8;
			*p_d1 = *p_d1 & ~0xFF00u;
			*p_d2 = (uint16_t)(0x40u - *p_d1);
			*p_d2 = (uint16_t)(*p_d2 + 0x4Du);
		}
		else
			*p_d2 = (*p_d2 & ~0xFFFFu) | 0x4Du;
		screen_y = OBJECT(a0)->screen_y;
		d0_2 = (uint16_t)(screen_y - *p_d2);
		if ((uint16_t)*p_d2 <= screen_y && d0_2 < 7u)
		{
			screen_x = OBJECT(a0)->screen_x;
			d0_2 = (uint16_t)(screen_x - 0xCDu);
			if (screen_x >= 0xCDu && d0_2 < 7u)
			{
				OBJECT(a0)->turtle.exit_step++;
				OBJECT(a0)->turtle.jump_speed = 0x400u;
				OBJECT(a0)->turtle.falling = 0u;
				OBJECT(a0)->turtle.move_timer = 8u;
				d0_2 = 0x200u;
				turtle_set_state(d0_2, a0, p_d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
				return;
			}
		}
		*p_d2 = (*p_d2 & ~0xFFFFu) | (uint16_t)(*p_d2 + 3u);
		d1 = (*p_d1 & ~0xFFFFu) | 0xD0u;
		direction_to(a0, &d0, &d1, p_d2);
		*p_d1 = (d1 & ~0xFFFFu) | 0x200u;
		move_in_direction((uint8_t)d0, (uint16_t)*p_d1, a0);
	}
	else if ((uint8_t)(OBJECT(object)->unk_20 >> 8u) == 0u)
	{
		OBJECT(object)->unk_20 = (OBJECT(object)->unk_20 & 0xFFu) | (((uint8_t)(OBJECT(object)->unk_20 >> 8u) - 1u & 0xFFu) << 8u);
		if ((uint16_t)OBJECT(object)->x_speed < 0x414u && (uint16_t)OBJECT(object)->x_speed >= 0x400u)
		{
			d7 = 0x3Cu;
			queue_sound(d7, object);
			object = OBJECT_ADDRESS(40);
		}
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = x_speed - 0x14u;
		if (x_speed < 0x14u)
		{
			OBJECT(object)->x_speed = 0;
			OBJECT(OBJECT_ADDRESS(44))->flags = 0u;
			d7 = 0x12u;
			queue_sound(d7, object);
			object = OBJECT_ADDRESS(40);
		}
		OBJECT(object)->x += OBJECT(object)->x_speed;
		d0 = OBJECT(object)->x;
		OBJECT(object + 0x50u)->x = d0;
		d0 = d0 >> 8;
		OBJECT(object)->screen_x = d0;
		OBJECT(object + 0x50u)->screen_x = d0;
	}
}

uint32_t turtle_exit_car_street_jump(uint32_t d1, uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t move_timer = 0;
	uint16_t jump_speed = 0;

	turtles_on_the_way--;
	turtles_not_waiting = 0xFFu;
	if (OBJECT(a0)->turtle.move_timer != 0u)
	{
		move_timer = OBJECT(a0)->turtle.move_timer;
		OBJECT(a0)->turtle.move_timer = move_timer - 1u;
		if (move_timer != 1u)
			return d1;
		OBJECT(a0)->contacts |= 0x80u;
		d0 = 0x201u;
		turtle_set_state(d0, a0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
		return d1;
	}
	if (OBJECT(a0)->turtle.falling != 0u)
	{
		OBJECT(a0)->height -= OBJECT(a0)->turtle.jump_speed;
		OBJECT(a0)->turtle.jump_speed += 0x40u;
		if (OBJECT(a0)->height >= 0x1800u)
			return d1;
		OBJECT(a0)->flags &= 0x7Fu;
		return d1;
	}
	OBJECT(a0)->height += OBJECT(a0)->turtle.jump_speed;
	jump_speed = OBJECT(a0)->turtle.jump_speed;
	OBJECT(a0)->turtle.jump_speed = jump_speed - 0x40u;
	if (jump_speed >= 0x40u)
		return d1;
	OBJECT(a0)->turtle.jump_speed = 0u - OBJECT(a0)->turtle.jump_speed;
	OBJECT(a0)->turtle.falling--;
	OBJECT(a0)->height -= OBJECT(a0)->turtle.jump_speed;
	OBJECT(a0)->turtle.jump_speed += 0x40u;
	if (OBJECT(a0)->height < 0x1800u)
		OBJECT(a0)->flags &= 0x7Fu;
	return d1;
}

/* the turtles are in the van: its door shuts, "Let's move it", the engine runs */
uint32_t exit_car_street_van_start_up(uint16_t d0, uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d0_2 = 0, d2 = 0;
	uint32_t d0_3 = 0, d1_2 = 0, d2_2 = 0, object = 0;
	uint8_t t1 = 0;

	t1 = cutscene_count;
	cutscene_count = t1 - 1u;
	if (t1 != 1u)
	{
		if (cutscene_count == 0x60u)
		{
			d0 &= ~0xFFu;
			d1 = 0xE0u;
			d2 = 0x70u;
			d1 = say_lets_move_it(d0, d1, d2);
		}
		object = OBJECT_ADDRESS(40);
		if (OBJECT(OBJECT_ADDRESS(41))->x < OBJECT(OBJECT_ADDRESS(40))->x)
		{
			OBJECT(object + 0x50u)->x += 0x300u;
			OBJECT(object + 0x50u)->screen_x = OBJECT(object + 0x50u)->x >> 8;
			return d1;
		}
		if ((cutscene_count & 0x1Fu) == 0u)
		{
			d7 = 0x2Du;
			queue_sound(d7, 0u);
		}
		if ((frame_count & 1u) != 0u)
			return d1;
		d0_2 = cutscene_wait;
		cutscene_wait++;
		d0_2 = (uint16_t)((d0_2 & 7u) << 2);
		d2_2 = (int16_t)rom_02C3BC[d0_2 / 2u];
		OBJECT(OBJECT_ADDRESS(40))->x += (int16_t)indexed_table_of_16_bit_values_02C3BA[d0_2 / 2u];
		OBJECT(OBJECT_ADDRESS(40))->y += d2_2;
		d0_3 = OBJECT(OBJECT_ADDRESS(40))->x;
		d1_2 = OBJECT(OBJECT_ADDRESS(40))->y;
		OBJECT(OBJECT_ADDRESS(41))->x = d0_3;
		d2_2 = d1_2 - 0x400u;
		OBJECT(OBJECT_ADDRESS(41))->y = d2_2;
		d0_3 = d0_3 >> 8;
		d1_2 = d1_2 >> 8;
		OBJECT(OBJECT_ADDRESS(40))->screen_x = d0_3;
		OBJECT(OBJECT_ADDRESS(40))->screen_y = d1_2;
		OBJECT(OBJECT_ADDRESS(41))->screen_x = d0_3;
		OBJECT(OBJECT_ADDRESS(41))->screen_y = d2_2 >> 8;
		return d1_2;
	}
	d7 = 0x3Au;
	queue_sound(d7, 0u);
	d7 = 0x6Eu;
	queue_sound(d7, 0u);
	LAYER(LAYER_B)->x_speed = 0u;
	next_area_step();
	return d1;
}

/* the van drives off and the screen is cleared */
uint32_t exit_car_street_van_drives_off(uint32_t d1)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d0 = 0, d1_2 = 0, ignored = 0;

	d0 = (OBJECT(OBJECT_ADDRESS(40))->x + 0x600u) & 0x1FFFFu;
	OBJECT(OBJECT_ADDRESS(40))->x = d0;
	OBJECT(OBJECT_ADDRESS(41))->x = d0;
	d0 = d0 >> 8;
	OBJECT(OBJECT_ADDRESS(40))->screen_x = d0;
	OBJECT(OBJECT_ADDRESS(41))->screen_x = d0;
	if (d0 < 0x59u || d0 >= 0x60u)
		return d1;
	cutscene_wait = 0xC0u;
	exit_cutscene = 0xFFu;
	LAYER(LAYER_A)->x = 0u;
	LAYER(LAYER_B)->x = 0u;
	LAYER(WORKING_LAYER)->x = 0u;
	clear_layers(&d1_2, &ignored);
	a6 = 0xA11Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	next_area_step();
	return d1_2;
}

/* the picture of April hugging the turtle of the player with the best score */
uint32_t exit_car_street_april_hug_start(uint32_t d1)
{
	uint8_t d0 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, a3 = 0, a5 = 0, animation = 0, d1_2 = 0, object = 0, object_2 = 0, player = 0, player_2 = 0;
	uint8_t t1 = 0;

	if (palettes_busy != 0u)
		return d1;
	LAYER(WORKING_LAYER)->map = layers_046C52_ADDRESS;
	LAYER(WORKING_LAYER)->blocks = 0x46D52u;
	LAYER(WORKING_LAYER)->map_width = 0x20u;
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	io_write8(TILES_106B00, 0xD0u);
	tile_banks_0_1 = 0xD0u;
	LAYER(WORKING_LAYER)->map = 0x46622u;
	LAYER(WORKING_LAYER)->blocks = 0x46822u;
	LAYER(WORKING_LAYER)->map_width = 0x20u;
	a0 = TILE_RAM + 0x2000u;
	d1_2 = draw_whole_layer(a0);
	a0 = TILE_RAM + 0x2628u;
	d0 = 0xC4u;
	do
	{
		io_write8(a0, d0);
		io_write8(a0 + 0x80u, d0);
		io_write8(a0 + 0x100u, d0);
		io_write8(a0 + 0x180u, d0);
		a0 += 2u;
	} while (a0 < TILE_RAM + 0x2630u);
	object = OBJECT_ADDRESS(0);
	cutscene_counter = 0u;
	a1 = hug_turtle_colours_ADDRESS;
	hug_turtle_colours(0) = 8u;
	hug_turtle_colours(1) = 9u;
	hug_turtle_colours(2) = 0xAu;
	hug_turtle_colours(3) = 0xBu;
	do
	{
		if ((OBJECT(object)->flags & 1u) == 0u)
			mem_write8(a1, 0xFFu);
		else
			cutscene_counter++;
		object += 0x50u;
		a1++;
	} while (object < OBJECT_ADDRESS(4));
	cutscene_counter--;
	object = OBJECT_ADDRESS(0);
	object_2 = OBJECT_ADDRESS(1);
	a2 = hug_turtle_colours_ADDRESS;
	a3 = hug_turtle_colours_ADDRESS + 0x1u;
	player = unk_060104_ADDRESS;
	player_2 = unk_06010C_ADDRESS;
	do
	{
		if ((OBJECT(object)->flags & 1u) == 0u)
		{
			player += 8u;
			object += 0x50u;
			a2++;
		}
		else if ((OBJECT(object_2)->flags & 1u) != 0u && PLAYER(player - 0x4u)->score <= PLAYER(player_2 - 0x4u)->score)
		{
			object = object_2;
			a2 = a3;
			player = player_2;
		}
		player_2 += 8u;
		object_2 += 0x50u;
		a3++;
	} while (object_2 < OBJECT_ADDRESS(4));
	d0 = mem_read8(a2);
	mem_write8(a2, 0xFFu);
	a5 = animations_02C640_ADDRESS;
	object = OBJECT_ADDRESS(12);
	do
	{
		OBJECT(object)->flags = 1u;
		OBJECT(object)->height = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		OBJECT(object)->screen_x = 0xB8u;
		OBJECT(object)->screen_y = 0x80u;
		animation = DATA32(a5);
		a5 += 4u;
		d1_2 = set_animation(d1_2, object, animation);
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(16));
	OBJECT(OBJECT_ADDRESS(13))->screen_y = (OBJECT(OBJECT_ADDRESS(13))->screen_y & 0xFF00u) | 0x78u;
	OBJECT(OBJECT_ADDRESS(12))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(12))->colour = d0;
	OBJECT(OBJECT_ADDRESS(13))->colour = d0;
	object = OBJECT_ADDRESS(44);
	a1 = hug_turtle_colours_ADDRESS;
	a2 = 0x2C650u;
	while (cutscene_counter != 0u)
	{
		cutscene_counter--;
		OBJECT(object)->flags = 0x81u;
		OBJECT(object)->height = 0u;
		OBJECT(object)->screen_x = 0x90u;
		OBJECT(object)->screen_y = 0xB8u;
		OBJECT(object)->animation_delay = 0u;
		do
		{
			t1 = mem_read8(a1);
			d0 = t1;
			a1++;
		} while ((int8_t)t1 < 0);
		OBJECT(object)->colour = d0;
		mem_write8(a1 - 1u, 0xFFu);
		animation = DATA32(a2);
		a2 += 4u;
		d1_2 = set_animation(d1_2, object, animation);
		object += 0x50u;
	}
	cutscene_wait = 0u;
	next_area_step();
	return d1_2;
}

/* April thanks the turtle and a heart floats up, then the exit is over */
uint32_t exit_car_street_april_hug(uint32_t d1)
{
	uint8_t d0 = 0, d2_2 = 0, d3 = 0, d4 = 0;
	uint16_t d2 = 0, d3_2 = 0;
	uint32_t a0 = 0, d0_2 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;
	uint8_t t1 = 0;

	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 == 1u)
	{
		area_beaten = 0u;
		area_cleared = 0u;
		scene_step++;
		return d1;
	}
	if (stage == 5u)
		return d1;
	if (cutscene_wait == 0xD0u)
	{
		d0_2 = 0x7Fu;
		d1_2 = 0x110u;
		d2 = 0x70u;
		d3_2 = 0x37u;
		show_balloon_beside(d2, d3_2, &d0_2, &d1_2, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
		draw_balloon_pointer(ignored_5);
		return d1_2;
	}
	if (cutscene_wait == 0xB0u)
	{
		a0 = TILE_RAM + 0x2628u;
		d0 = 0xA5u;
		d1_2 = 0xDDu;
		d2_2 = 0xE1u;
		d3 = 0xE5u;
		d4 = 0xE8u;
		do
		{
			io_write8(a0, d0);
			io_write8(a0 + 0x80u, d0);
			io_write8(a0 + 0x100u, d0);
			io_write8(a0 + 0x180u, d0);
			io_write8(a0 + 1u, d1_2);
			io_write8(a0 + 0x81u, d2_2);
			io_write8(a0 + 0x101u, d3);
			io_write8(a0 + 0x181u, d4);
			d1_2 = (uint8_t)(d1_2 + 1u);
			d2_2++;
			d3++;
			d4++;
			a0 += 2u;
		} while (a0 < TILE_RAM + 0x2630u);
		io_write8(TILES_1027A9, 0x21u);
		return d1_2;
	}
	if (cutscene_wait == 0x90u)
	{
		LAYER(WORKING_LAYER)->map = 0x46722u;
		LAYER(WORKING_LAYER)->blocks = 0x46822u;
		LAYER(WORKING_LAYER)->map_width = 0x20u;
		a0 = TILE_RAM + 0x2000u;
		d1_2 = draw_whole_layer(a0);
		OBJECT(OBJECT_ADDRESS(13))->flags = 0x81u;
		return d1_2;
	}
	if (cutscene_wait == 0x70u)
	{
		OBJECT(OBJECT_ADDRESS(15))->flags = 0x81u;
		return d1;
	}
	if (cutscene_wait == 0x50u)
	{
		LAYER(WORKING_LAYER)->map = 0x46622u;
		LAYER(WORKING_LAYER)->blocks = 0x46822u;
		LAYER(WORKING_LAYER)->map_width = 0x20u;
		a0 = TILE_RAM + 0x2000u;
		d1_2 = draw_whole_layer(a0);
		a0 = TILE_RAM + 0x2628u;
		d0 = 0xC4u;
		do
		{
			io_write8(a0, d0);
			io_write8(a0 + 0x80u, d0);
			io_write8(a0 + 0x100u, d0);
			io_write8(a0 + 0x180u, d0);
			a0 += 2u;
		} while (a0 < TILE_RAM + 0x2630u);
		OBJECT(OBJECT_ADDRESS(14))->flags = 0x81u;
		OBJECT(OBJECT_ADDRESS(15))->screen_y++;
		return d1_2;
	}
	if (cutscene_wait >= 0x70u)
		return d1;
	if (cutscene_wait >= 0x30u)
	{
		OBJECT(OBJECT_ADDRESS(15))->screen_y++;
		return d1;
	}
	OBJECT(OBJECT_ADDRESS(15))->flags = 0u;
	return d1;
}

void move_in_direction(uint8_t d0, uint16_t d1, uint32_t a0)
{
	uint32_t d6 = 0, d7 = 0, ignored = 0;

	speeds_from_direction(d0, d1, &d6, &d7, &ignored);
	OBJECT(a0)->x += (int16_t)d6;
	OBJECT(a0)->y += (int16_t)d7;
	update_screen_place(a0);
}

void update_screen_place(uint32_t a0)
{
	uint16_t d4 = 0;

	d4 = (uint16_t)(OBJECT(a0)->y >> 8);
	OBJECT(a0)->screen_x = OBJECT(a0)->x >> 8;
	OBJECT(a0)->screen_y = d4;
}

uint32_t turtle_exit_highway(uint32_t d1)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, object = 0;
	uint8_t t1 = 0;

	turtles_on_the_way = 0u;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u && (OBJECT(object)->flags & 0x80u) != 0u)
		{
			if ((uint8_t)OBJECT(object)->y_speed == 0u)
			{
				turtles_on_the_way--;
				if (OBJECT(object)->screen_x < 0x1A0u)
				{
					OBJECT(object)->screen_x += 4u;
					if ((uint16_t)((OBJECT(object)->height >> 8) + OBJECT(object)->screen_y) < 0x100u)
						OBJECT(object)->height += 0x600u;
				}
				else
					OBJECT(object)->flags &= 0x7Fu;
			}
			else
			{
				turtles_on_the_way--;
				t1 = (uint8_t)OBJECT(object)->y_speed;
				OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | (t1 - 1u & 0xFFu);
				if (t1 == 1u)
				{
					OBJECT(object)->contacts |= 0x80u;
					d0 = 0x201u;
					turtle_set_state(d0, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
				}
			}
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	if (turtles_on_the_way == 0u)
	{
		area_beaten = 0u;
		area_cleared = 0u;
		scene_step++;
		return d1;
	}
	return d1;
}

uint32_t run_exit_skateboard(uint32_t d1, uint32_t d2)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0, ignored = 0, ignored_2 = 0;

	a0 = turtle_skateboard_shadow();
	if (cutscene_step < 4u)
	{
		load_layer_b();
		LAYER(WORKING_LAYER)->x += LAYER(WORKING_LAYER)->x_speed;
		LAYER(WORKING_LAYER)->x &= 0x1FFFFu;
		save_layer_b();
	}
	load_layer_a();
	d0 = (uint16_t)((uint32_t)cutscene_step << 2);
	switch (d0)
	{
	case 0:
		turtle_exit_skateboard_gather(d2, &d1, &a0);
		break;
	case 4:
		turtle_exit_skateboard_board(d2, &d1, &a0);
		break;
	case 8:
		exit_skateboard_van_door(&d1, &a0);
		break;
	case 12:
		exit_skateboard_van_drives(d0, &d1, &a0);
		break;
	case 16:
		a0 = exit_skateboard_crash_picture(a0);
		break;
	case 20:
		finish_area_exit();
		break;
	}
	if (cutscene_step < 4u)
	{
		d1 = auto_scroll(d1, a0);
		working_layer_tiles = TILE_RAM + 0x2000u;
		draw_new_row_and_column(&d1, &ignored, &ignored_2);
		OBJECT(OBJECT_ADDRESS(0))->contacts |= 0x80u;
		OBJECT(OBJECT_ADDRESS(1))->contacts |= 0x80u;
		OBJECT(OBJECT_ADDRESS(2))->contacts |= 0x80u;
		OBJECT(OBJECT_ADDRESS(3))->contacts |= 0x80u;
	}
	save_layer_a();
	set_layers_scroll();
	return d1;
}

void turtle_exit_skateboard_gather(uint32_t d2, uint32_t *p_d1, uint32_t *p_a0)
{
	uint32_t d1 = *p_d1;
	uint8_t d7 = 0;
	uint32_t a0 = 0, animation = 0, d0 = 0;

	turtles_on_the_way = 0u;
	exit_skateboard_road_round();
	a0 = OBJECT_ADDRESS(0);
	do
	{
		turtle_exit_go_to_place(a0, &d1, &d2);
		a0 += 0x50u;
	} while (a0 < OBJECT_ADDRESS(4));
	if (turtles_on_the_way == 0u)
	{
		a0 = OBJECT_ADDRESS(40);
		OBJECT(OBJECT_ADDRESS(40))->flags = 0x81u;
		OBJECT(OBJECT_ADDRESS(40))->contacts = 0u;
		OBJECT(OBJECT_ADDRESS(41))->flags = 0x81u;
		OBJECT(OBJECT_ADDRESS(41))->contacts = 0u;
		OBJECT(OBJECT_ADDRESS(40))->colour = 0xFFu;
		OBJECT(OBJECT_ADDRESS(40))->animation_delay = 0u;
		OBJECT(OBJECT_ADDRESS(41))->colour = 0xFFu;
		OBJECT(OBJECT_ADDRESS(41))->animation_delay = 0u;
		OBJECT(OBJECT_ADDRESS(40))->screen_x = 0x50u;
		OBJECT(OBJECT_ADDRESS(41))->screen_x = 0x50u;
		d1 = 0u;
		OBJECT(OBJECT_ADDRESS(40))->height = 0x50u;
		OBJECT(OBJECT_ADDRESS(41))->height = 0x50u;
		d0 = indexed_table_of_32_bit_values_005000_ADDRESS;
		OBJECT(OBJECT_ADDRESS(40))->x = d0;
		OBJECT(OBJECT_ADDRESS(41))->x = d0;
		OBJECT(OBJECT_ADDRESS(40))->y = 0xA000u;
		OBJECT(OBJECT_ADDRESS(40))->screen_y = 0xA0u;
		OBJECT(OBJECT_ADDRESS(41))->y = 0x9C00u;
		OBJECT(OBJECT_ADDRESS(41))->screen_y = 0x9Cu;
		OBJECT(OBJECT_ADDRESS(40))->x_speed = 0x600;
		animation = 0x2D8C8u;
		d1 = set_animation(d1, a0, animation);
		animation = 0x2D8E2u;
		a0 = OBJECT_ADDRESS(41);
		d1 = set_animation(d1, a0, animation);
		d7 = 0x15u;
		queue_sound(d7, animation);
		next_area_step();
	}
	*p_d1 = d1;
	*p_a0 = a0;
}

void turtle_exit_skateboard_board(uint32_t d2, uint32_t *p_d1, uint32_t *p_a0)
{
	uint32_t d1 = *p_d1;
	uint16_t d0 = 0;
	uint32_t d0_2 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, object = 0;
	uint8_t t1 = 0;
	uint16_t x_speed = 0, screen_y = 0, screen_x = 0, x_speed_2 = 0;

	object = OBJECT_ADDRESS(40);
	if ((uint16_t)OBJECT(OBJECT_ADDRESS(40))->x_speed != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = x_speed - 0x14u;
		if (x_speed < 0x14u)
			OBJECT(object)->x_speed = 0;
		OBJECT(object)->x += (uint16_t)OBJECT(object)->x_speed;
		d0_2 = OBJECT(object)->x;
		OBJECT(object + 0x50u)->x = d0_2;
		d0_2 = d0_2 >> 8;
		OBJECT(object)->screen_x = d0_2;
		OBJECT(object + 0x50u)->screen_x = d0_2;
	}
	else if (OBJECT(object)->x - OBJECT(object + 0x50u)->x >= 0x4000u)
	{
		object = OBJECT_ADDRESS(0);
		do
		{
			if ((OBJECT(object)->flags & 1u) != 0u && (OBJECT(object)->flags & 0x80u) != 0u)
			{
				screen_y = OBJECT(object)->screen_y;
				d0 = (uint16_t)(screen_y - 0x4Du);
				if (screen_y < 0x4Du || d0 >= 7u)
				{
					OBJECT(object)->y_speed = 0;
					OBJECT(object)->height = 0u;
					d1_2 = (d1 & ~0xFFFFu) | 0xA0u;
					d2 = (d2 & ~0xFFFFu) | 0x50u;
					direction_to(object, &d0_2, &d1_2, &d2);
					d1 = (d1_2 & ~0xFFFFu) | 0x200u;
					move_in_direction((uint8_t)d0_2, (uint16_t)d1, object);
				}
				else
				{
					screen_x = OBJECT(object)->screen_x;
					d0 = (uint16_t)(screen_x - 0x9Du);
					if (screen_x < 0x9Du || d0 >= 7u)
					{
						OBJECT(object)->y_speed = 0;
						OBJECT(object)->height = 0u;
						d1_2 = (d1 & ~0xFFFFu) | 0xA0u;
						d2 = (d2 & ~0xFFFFu) | 0x50u;
						direction_to(object, &d0_2, &d1_2, &d2);
						d1 = (d1_2 & ~0xFFFFu) | 0x200u;
						move_in_direction((uint8_t)d0_2, (uint16_t)d1, object);
					}
					else
					{
						if ((uint8_t)OBJECT(object)->y_speed == 0u && OBJECT(object)->height == 0u)
						{
							OBJECT(object)->x_speed = 0x400;
							OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | 0x8u;
							d0 = 0x200u;
							turtle_set_state(d0, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
						}
						if ((uint8_t)OBJECT(object)->y_speed == 0u)
						{
							if ((uint8_t)(OBJECT(object)->y_speed >> 8u) != 0u)
							{
								OBJECT(object)->height -= OBJECT(object)->x_speed;
								OBJECT(object)->x_speed += 0x40u;
								if (OBJECT(object)->height < 0x1800u)
									OBJECT(object)->flags &= 0x7Fu;
							}
							else
							{
								OBJECT(object)->height += OBJECT(object)->x_speed;
								x_speed_2 = OBJECT(object)->x_speed;
								OBJECT(object)->x_speed = x_speed_2 - 0x40u;
								if (x_speed_2 < 0x40u)
								{
									OBJECT(object)->x_speed = 0u - OBJECT(object)->x_speed;
									OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFFu) | (((uint8_t)(OBJECT(object)->y_speed >> 8u) - 1u & 0xFFu) << 8u);
									OBJECT(object)->height -= OBJECT(object)->x_speed;
									OBJECT(object)->x_speed += 0x40u;
									if (OBJECT(object)->height < 0x1800u)
										OBJECT(object)->flags &= 0x7Fu;
								}
							}
						}
						else
						{
							t1 = (uint8_t)OBJECT(object)->y_speed;
							OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | (t1 - 1u & 0xFFu);
							if (t1 == 1u)
							{
								d0 = 0x201u;
								turtle_set_state(d0, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
								if ((uint8_t)(OBJECT(object)->y_speed >> 8u) != 0u)
								{
									OBJECT(object)->height -= OBJECT(object)->x_speed;
									OBJECT(object)->x_speed += 0x40u;
									if (OBJECT(object)->height < 0x1800u)
										OBJECT(object)->flags &= 0x7Fu;
								}
								else
								{
									OBJECT(object)->height += OBJECT(object)->x_speed;
									x_speed_2 = OBJECT(object)->x_speed;
									OBJECT(object)->x_speed = x_speed_2 - 0x40u;
									if (x_speed_2 < 0x40u)
									{
										OBJECT(object)->x_speed = 0u - OBJECT(object)->x_speed;
										OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFFu) | (((uint8_t)(OBJECT(object)->y_speed >> 8u) - 1u & 0xFFu) << 8u);
										OBJECT(object)->height -= OBJECT(object)->x_speed;
										OBJECT(object)->x_speed += 0x40u;
										if (OBJECT(object)->height < 0x1800u)
											OBJECT(object)->flags &= 0x7Fu;
									}
								}
							}
						}
					}
				}
			}
			object += 0x50u;
		} while (object < OBJECT_ADDRESS(4));
	}
	else
	{
		OBJECT(object + 0x50u)->x -= 0x300u;
		OBJECT(object + 0x50u)->screen_x = OBJECT(object + 0x50u)->x >> 8;
	}
	exit_skateboard_road_round();
	object = OBJECT_ADDRESS(0);
	while ((OBJECT(object)->flags & 0x80u) == 0u)
	{
		object += 0x50u;
		if (object >= OBJECT_ADDRESS(4))
		{
			next_area_step();
			break;
		}
	}
	*p_d1 = d1;
	*p_a0 = object;
}

/* the turtles are in the van and its door shuts */
void exit_skateboard_van_door(uint32_t *p_d1, uint32_t *p_a0)
{
	uint8_t d7 = 0;
	uint32_t x = 0;

	exit_skateboard_road_round();
	*p_a0 = OBJECT_ADDRESS(40);
	if (OBJECT(OBJECT_ADDRESS(40))->x == OBJECT(OBJECT_ADDRESS(41))->x)
	{
		if (LAYER(WORKING_LAYER)->x < 0x8A200u || LAYER(WORKING_LAYER)->x >= 0x8A800u)
		{
			return;
		}
		LAYER(WORKING_LAYER)->column_phase = (LAYER(WORKING_LAYER)->x & 0x700u) << 5;
		next_area_step();
		return;
	}
	OBJECT(*p_a0 + 0x50u)->x += 0x300u;
	x = OBJECT(*p_a0 + 0x50u)->x;
	*p_d1 = x >> 8;
	OBJECT(*p_a0 + 0x50u)->screen_x = *p_d1;
	if (x < OBJECT(*p_a0)->x)
	{
		return;
	}
	OBJECT(*p_a0 + 0x50u)->x = OBJECT(*p_a0)->x;
	OBJECT(*p_a0 + 0x50u)->screen_x = OBJECT(*p_a0)->x >> 8;
	d7 = 0x6Eu;
	queue_sound(d7, 0u);
	if (LAYER(WORKING_LAYER)->x < 0x8A200u || LAYER(WORKING_LAYER)->x >= 0x8A800u)
	{
		return;
	}
	LAYER(WORKING_LAYER)->column_phase = (LAYER(WORKING_LAYER)->x & 0x700u) << 5;
	next_area_step();
}

/* the van speeds round the curve, "Hang on, guys", and the screen is cleared */
void exit_skateboard_van_drives(uint32_t d0, uint32_t *p_d1, uint32_t *p_a0)
{
	uint8_t d7 = 0;
	uint16_t d2 = 0, d3 = 0, d7_2 = 0;
	uint32_t a6 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, ignored_6 = 0;

	if (LAYER(WORKING_LAYER)->x >= 0xA0000u)
	{
		if (LAYER(WORKING_LAYER)->x >= 0xA4000u)
		{
			if (LAYER(WORKING_LAYER)->x >= 0xA4600u)
			{
				if (LAYER(WORKING_LAYER)->x >= 0xA8000u)
				{
					OBJECT(OBJECT_ADDRESS(40))->flags = 0u;
					OBJECT(OBJECT_ADDRESS(41))->flags = 0u;
					exit_cutscene = 0xFFu;
					LAYER(WORKING_LAYER)->x = 0x800u;
					LAYER(LAYER_A)->x = 0x800u;
					LAYER(LAYER_B)->x = 0x800u;
					clear_layers(p_d1, p_a0);
					a6 = 0xA14Eu;
					d7_2 = 0x20Fu;
					post_palette_request(d7_2, a6);
					next_area_step();
				}
			}
			else
			{
				d7 = 0x3Cu;
				queue_sound(d7, 0u);
			}
		}
	}
	else if (balloons_said == 0u)
	{
		d0 &= ~0xFFu;
		*p_d1 = 0xC0u;
		d2 = 0x70u;
		d3 = 0x3Cu;
		show_balloon_beside(d2, d3, &d0, p_d1, &ignored_3, &ignored_4, &ignored_5, &ignored_6, &ignored);
		draw_balloon_pointer(ignored);
	}
}

/* the picture of the van crashing through the road's wall, the turtles leaping out */
uint32_t exit_skateboard_crash_picture(uint32_t a0)
{
	uint32_t carry = 0;
	uint8_t d0 = 0, d1 = 0, d6 = 0, d7 = 0;
	uint32_t a0_2 = 0, a5 = 0, animation = 0, d1_2 = 0, object = 0, object_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (palettes_busy != 0u)
		return a0;
	a0_2 = TILE_RAM + 0x4008u;
	d0 = 0x24u;
	d1 = 0u;
	d7 = 0x20u;
	do
	{
		d6 = 0x20u;
		do
		{
			io_write8(a0_2, d0);
			io_write8(a0_2 + 1u, d1);
			carry = (uint8_t)(d1 + 1u) < d1;
			d1++;
			a0_2 += 2u;
			if (carry)
				d0++;
			t1 = d6;
			d6 = (uint8_t)(t1 - 1u);
		} while (t1 != 1u);
		t2 = d7;
		d7 = (uint8_t)(t2 - 1u);
		a0_2 += 0x40u;
	} while (t2 != 1u);
	io_write8(TILES_106B00, 0xE0u);
	tile_banks_0_1 = 0xE0u;
	a0_2 = TILE_RAM + 0x2220u;
	d0 = 0x13u;
	d1_2 = 0u;
	d7 = 0x10u;
	do
	{
		d6 = 0x10u;
		do
		{
			io_write8(a0_2, d0);
			io_write8(a0_2 + 1u, d1_2);
			d1_2 = (uint8_t)(d1_2 + 1u);
			t3 = d6;
			d6 = (uint8_t)(t3 - 1u);
			a0_2 += 2u;
		} while (t3 != 1u);
		t4 = d7;
		d7 = (uint8_t)(t4 - 1u);
		a0_2 += 0x60u;
	} while (t4 != 1u);
	a5 = animations_02CD74_ADDRESS;
	object = OBJECT_ADDRESS(44);
	object_2 = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object_2)->flags & 1u) != 0u)
		{
			OBJECT(object)->flags = 0x81u;
			OBJECT(object)->height = 0u;
			OBJECT(object)->colour = 0xFFu;
			OBJECT(object)->animation_delay = 0u;
			OBJECT(object)->screen_x = 0xF8u;
			OBJECT(object)->screen_y = 0x80u;
			animation = DATA32(a5);
			set_animation(d1_2, object, animation);
		}
		object_2 += 0x50u;
		a5 += 4u;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(48));
	d7 = 0x1Au;
	queue_sound(d7, animation);
	cutscene_wait = 0xA0u;
	next_area_step();
	return object;
}

void finish_area_exit(void)
{
	uint8_t t1 = 0;

	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 == 1u)
	{
		area_beaten = 0u;
		area_cleared = 0u;
		scene_step++;
	}
}

/* the road goes round instead of running out of tiles */
void exit_skateboard_road_round(void)
{
	LAYER(WORKING_LAYER)->column_phase = 0u;
	if (LAYER(WORKING_LAYER)->x < 0xA0000u)
		return;
	LAYER(WORKING_LAYER)->x &= 0x80FFFu;
}

void turtle_exit_go_to_place(uint32_t a0, uint32_t *p_d1, uint32_t *p_d2)
{
	uint32_t d1 = *p_d1;
	uint32_t d2 = *p_d2;
	uint16_t d0 = 0;
	uint32_t d0_2 = 0, d1_2 = 0, d2_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t screen_y = 0, screen_x = 0;

	d0 = (uint16_t)((uint32_t)OBJECT(a0)->kind << 2);
	d1_2 = (d1 & ~0xFFFFu) | indexed_table_of_16_bit_values_02CE62[d0 / 2u];
	d2_2 = (d2 & ~0xFFFFu) | rom_02CE64[d0 / 2u];
	screen_y = OBJECT(a0)->screen_y;
	d0 = (uint16_t)(screen_y - 0x2Du);
	if (screen_y < 0x2Du || d0 >= 7u)
	{
		turtles_on_the_way--;
		d0 = (uint16_t)((uint32_t)OBJECT(a0)->kind << 2);
		d1_2 = (d1_2 & ~0xFFFFu) | indexed_table_of_16_bit_values_02CE62[d0 / 2u];
		d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(d1_2 + 3u);
		d2_2 = (d2_2 & ~0xFFFFu) | rom_02CE64[d0 / 2u];
		direction_to(a0, &d0_2, &d1_2, &d2_2);
		d1_2 = (d1_2 & ~0xFFFFu) | 0x200u;
		move_in_direction((uint8_t)d0_2, (uint16_t)d1_2, a0);
	}
	else
	{
		screen_x = OBJECT(a0)->screen_x;
		d0 = (uint16_t)(screen_x - d1_2);
		if (screen_x < (uint16_t)d1_2 || d0 >= 7u)
		{
			turtles_on_the_way--;
			d0 = (uint16_t)((uint32_t)OBJECT(a0)->kind << 2);
			d1_2 = (d1_2 & ~0xFFFFu) | indexed_table_of_16_bit_values_02CE62[d0 / 2u];
			d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(d1_2 + 3u);
			d2_2 = (d2_2 & ~0xFFFFu) | rom_02CE64[d0 / 2u];
			direction_to(a0, &d0_2, &d1_2, &d2_2);
			d1_2 = (d1_2 & ~0xFFFFu) | 0x200u;
			move_in_direction((uint8_t)d0_2, (uint16_t)d1_2, a0);
		}
		else
		{
			d1_2 = (uint16_t)(d1_2 + 2u);
			d2_2 = (uint16_t)(d2_2 + 2u);
			OBJECT(a0)->screen_x = d1_2;
			OBJECT(a0)->screen_y = d2_2;
			d1_2 = (uint32_t)(int16_t)d1_2 << 8;
			d2_2 = (uint32_t)(int16_t)d2_2 << 8;
			OBJECT(a0)->x = d1_2;
			OBJECT(a0)->y = d2_2;
			OBJECT(a0)->turtle.move_timer = 0x10u;
			OBJECT(a0)->flags &= 0xBFu;
			d0 = 0x100u;
			turtle_set_state(d0, a0, &d1_2, &ignored, &ignored_2, &ignored_3, &ignored_4);
			OBJECT(a0)->frame_time = 0u;
		}
	}
	*p_d1 = d1_2;
	*p_d2 = d2_2;
}

uint32_t run_exit_building_site(uint32_t d1, uint32_t d2)
{
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)cutscene_step << 2);
	switch (d0)
	{
	case 0:
		exit_building_site_free_splinter();
		break;
	case 4:
		d1 = turtle_exit_building_site_walk(d1);
		break;
	case 8:
		d1 = turtle_exit_building_site_jump(d1, d2);
		break;
	case 12:
		d1 = exit_building_site_splinter_picture(d1);
		break;
	case 16:
		d1 = exit_building_site_splinter_thanks(d1);
		break;
	case 20:
		d1 = turtle_exit_building_site_drop(d1);
		break;
	case 24:
		d1 = turtle_exit_building_site_land(d1);
		break;
	case 28:
		d1 = turtle_exit_building_site_wait(d0, d1);
		break;
	case 32:
		turtle_exit_building_site_rise();
		break;
	case 36:
		turtle_exit_building_site_leave();
		break;
	}
	set_layers_scroll();
	return d1;
}

/* Splinter, tied up, is let down to the turtles */
void exit_building_site_free_splinter(void)
{
	uint32_t animation = 0, object = 0;
	uint16_t height = 0;

	object = OBJECT_ADDRESS(44);
	height = OBJECT(OBJECT_ADDRESS(44))->height;
	OBJECT(OBJECT_ADDRESS(44))->height = height - 0x100u;
	if (height == 0x100u)
	{
		cutscene_wait = 0x80u;
		OBJECT(object)->contacts = 0u;
		animation = 0x2DB28u;
		set_animation(0u, object, animation);
		next_area_step();
		return;
	}
	if (OBJECT(object)->height == 0x2000u)
	{
		animation = 0x2DB1Eu;
		set_animation(0u, object, animation);
		return;
	}
}

uint32_t turtle_exit_building_site_walk(uint32_t d1)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, object = 0;
	uint8_t t1 = 0;

	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 != 1u)
		return d1;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			d0 = 0x101u;
			turtle_set_state(d0, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	next_area_step();
	return d1;
}

uint32_t turtle_exit_building_site_jump(uint32_t d1, uint32_t d2)
{
	uint16_t d0_2 = 0, d7 = 0, x_speed = 0;
	uint32_t a6 = 0, d0 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, object = 0;
	uint8_t t1 = 0;
	uint16_t height = 0, x_speed_2 = 0;

	turtles_on_the_way = 0u;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u && (OBJECT(object)->flags & 0x80u) != 0u)
		{
			turtles_on_the_way--;
			if (OBJECT(object)->y < 0x7000u || OBJECT(object)->x < 0xF000u || OBJECT(object)->x > 0x10FFFu)
			{
				d1_2 = (d1 & ~0xFFFFu) | 0x100u;
				d2 = (d2 & ~0xFFFFu) | 0x90u;
				direction_to(object, &d0, &d1_2, &d2);
				d1 = (d1_2 & ~0xFFFFu) | 0x200u;
				move_in_direction((uint8_t)d0, (uint16_t)d1, object);
			}
			else if (OBJECT(object)->height != 0u)
			{
				if ((uint8_t)(OBJECT(object)->y_speed >> 8u) != 0u)
				{
					x_speed = (uint16_t)OBJECT(object)->x_speed;
					height = OBJECT(object)->height;
					OBJECT(object)->height = height - x_speed;
					if (height < x_speed)
						OBJECT(object)->flags &= 0x7Fu;
					else
						OBJECT(object)->x_speed += 0x20u;
				}
				else
				{
					OBJECT(object)->height += OBJECT(object)->x_speed;
					x_speed_2 = OBJECT(object)->x_speed;
					OBJECT(object)->x_speed = x_speed_2 - 0x30u;
					if (x_speed_2 < 0x30u)
					{
						OBJECT(object)->x_speed = 0u - OBJECT(object)->x_speed;
						OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFFu) | (((uint8_t)(OBJECT(object)->y_speed >> 8u) - 1u & 0xFFu) << 8u);
						d0_2 = 0x203u;
						turtle_set_state(d0_2, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
					}
				}
				if (OBJECT(object)->y < 0x8400u)
				{
					d1_2 = (d1 & ~0xFFFFu) | 0x100u;
					d2 = (d2 & ~0xFFFFu) | 0x90u;
					direction_to(object, &d0, &d1_2, &d2);
					d1 = (d1_2 & ~0xFFFFu) | 0x200u;
					move_in_direction((uint8_t)d0, (uint16_t)d1, object);
				}
			}
			else
			{
				if ((uint8_t)OBJECT(object)->y_speed == 0u)
				{
					OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | 0x8u;
					d0_2 = 0x200u;
					turtle_set_state(d0_2, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
					OBJECT(object)->contacts |= 0x80u;
				}
				t1 = (uint8_t)OBJECT(object)->y_speed;
				OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | (t1 - 1u & 0xFFu);
				if (t1 == 1u)
				{
					d0_2 = 0x201u;
					turtle_set_state(d0_2, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
					OBJECT(object)->x_speed = 0x500;
					if ((uint8_t)(OBJECT(object)->y_speed >> 8u) != 0u)
					{
						x_speed = (uint16_t)OBJECT(object)->x_speed;
						height = OBJECT(object)->height;
						OBJECT(object)->height = height - x_speed;
						if (height < x_speed)
							OBJECT(object)->flags &= 0x7Fu;
						else
							OBJECT(object)->x_speed += 0x20u;
					}
					else
					{
						OBJECT(object)->height += OBJECT(object)->x_speed;
						x_speed_2 = OBJECT(object)->x_speed;
						OBJECT(object)->x_speed = x_speed_2 - 0x30u;
						if (x_speed_2 < 0x30u)
						{
							OBJECT(object)->x_speed = 0u - OBJECT(object)->x_speed;
							OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFFu) | (((uint8_t)(OBJECT(object)->y_speed >> 8u) - 1u & 0xFFu) << 8u);
							d0_2 = 0x203u;
							turtle_set_state(d0_2, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
						}
					}
					if (OBJECT(object)->y < 0x8400u)
					{
						d1_2 = (d1 & ~0xFFFFu) | 0x100u;
						d2 = (d2 & ~0xFFFFu) | 0x90u;
						direction_to(object, &d0, &d1_2, &d2);
						d1 = (d1_2 & ~0xFFFFu) | 0x200u;
						move_in_direction((uint8_t)d0, (uint16_t)d1, object);
					}
				}
			}
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	if (turtles_on_the_way != 0u)
		return d1;
	OBJECT(OBJECT_ADDRESS(44))->flags = 0u;
	object = OBJECT_ADDRESS(32);
	do
	{
		OBJECT(object)->flags = 0u;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(40));
	object = OBJECT_ADDRESS(12);
	do
	{
		OBJECT(object)->flags = 0u;
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(24));
	exit_cutscene = 0xFFu;
	clear_layers(&d1_2, &ignored_5);
	LAYER(WORKING_LAYER)->x = 0u;
	LAYER(LAYER_A)->x = 0u;
	LAYER(LAYER_B)->x = 0u;
	a6 = 0xA12Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	next_area_step();
	return d1_2;
}

/* the picture of Splinter thanking his turtles */
uint32_t exit_building_site_splinter_picture(uint32_t d1)
{
	uint8_t d0 = 0;
	uint32_t a0 = 0, a1 = 0, d1_2 = 0;
	uint8_t t1 = 0;

	if (palettes_busy != 0u)
		return d1;
	io_write8(TILES_106B00, 0x70u);
	tile_banks_0_1 = 0x70u;
	LAYER(WORKING_LAYER)->map = layers_031280_ADDRESS;
	LAYER(WORKING_LAYER)->blocks = 0x31380u;
	LAYER(WORKING_LAYER)->map_width = 0x20u;
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	a0 = TILE_RAM + 0x4208u;
	a1 = table_loaded_by_lea_02D164_ADDRESS;
	d0 = 0x10u;
	d1_2 = 0x37u;
	do
	{
		io_write8(a0, d1_2);
		io_write8(a0 + 0x80u, d1_2);
		io_write8(a0 + 0x100u, d1_2);
		io_write8(a0 + 0x180u, d1_2);
		io_write8(a0 + 0x200u, d1_2);
		io_write8(a0 + 0x280u, d1_2);
		io_write8(a0 + 0x300u, d1_2);
		io_write8(a0 + 0x380u, d1_2);
		io_write8(a0 + 1u, DATA8(a1));
		io_write8(a0 + 0x81u, DATA8(a1 + 0x10u));
		io_write8(a0 + 0x101u, DATA8(a1 + 0x20u));
		io_write8(a0 + 0x181u, DATA8(a1 + 0x30u));
		io_write8(a0 + 0x201u, DATA8(a1 + 0x40u));
		io_write8(a0 + 0x281u, DATA8(a1 + 0x50u));
		io_write8(a0 + 0x301u, DATA8(a1 + 0x60u));
		io_write8(a0 + 0x381u, DATA8(a1 + 0x70u));
		a0 += 2u;
		t1 = d0;
		d0 = (uint8_t)(t1 - 1u);
		a1++;
	} while (t1 != 1u);
	cutscene_wait = 0xB0u;
	next_area_step();
	return d1_2;
}

void unreached_02D1D6(uint32_t a2)
{
	mem_write16(a2, mem_read16(a2) + 1u);
	mem_write16(a2, mem_read16(a2) + 1u);
	mem_write16(a2, mem_read16(a2) + 1u);
	mem_write16(a2, mem_read16(a2) + 1u);
	lost_stack(0x02D1DEu);
}

/* Splinter speaks his thanks, then the screen is cleared */
uint32_t exit_building_site_splinter_thanks(uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d7_2 = 0;
	uint32_t a0 = 0, a6 = 0, animation = 0, d1_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 == 1u)
	{
		clear_layers(&d1_2, &ignored);
		a6 = 0xA15Eu;
		d7_2 = 0x20Fu;
		post_palette_request(d7_2, a6);
		next_area_step();
		return d1_2;
	}
	if (cutscene_wait != 0x80u)
	{
		if (cutscene_wait != 0x30u)
			return d1;
		OBJECT(OBJECT_ADDRESS(44))->flags = 0u;
		return d1;
	}
	d7 = 0xB4u;
	queue_sound(d7, 0u);
	a0 = OBJECT_ADDRESS(44);
	OBJECT(OBJECT_ADDRESS(44))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(44))->contacts = 0u;
	OBJECT(OBJECT_ADDRESS(44))->height = 0u;
	OBJECT(OBJECT_ADDRESS(44))->colour = 0xFFu;
	OBJECT(OBJECT_ADDRESS(44))->animation_delay = 0u;
	OBJECT(OBJECT_ADDRESS(44))->screen_x = 0x100u;
	OBJECT(OBJECT_ADDRESS(44))->screen_y = 0x80u;
	animation = 0x2DEE6u;
	return set_animation(d1, a0, animation);
}

uint32_t turtle_exit_building_site_drop(uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0, d1_2 = 0;
	uint32_t d1_3 = 0, d3 = 0, d4 = 0, ignored = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, ignored_6 = 0, turtle = 0;

	if (palettes_busy != 0u)
		return d1;
	turtle = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(turtle)->flags & 1u) != 0u)
		{
			OBJECT(turtle)->flags = 0x81u;
			OBJECT(turtle)->contacts = 0u;
			d1_2 = (uint16_t)((uint32_t)OBJECT(turtle)->kind << 3);
			d3 = indexed_table_of_16_bit_values_02D304[d1_2 / 2u];
			d4 = rom_02D306[d1_2 / 2u];
			OBJECT(turtle)->height = rom_02D308[d1_2 / 2u];
			OBJECT(turtle)->turtle.drift_speed = rom_02D30A[d1_2 / 2u];
			OBJECT(turtle)->screen_x = d3;
			OBJECT(turtle)->screen_y = d4;
			OBJECT(turtle)->x = d3 << 8;
			OBJECT(turtle)->y = d4 << 8;
			d0 = 0x203u;
			turtle_set_state(d0, turtle, &ignored, &ignored_3, &ignored_4, &ignored_5, &ignored_6);
		}
		turtle += 0x50u;
	} while (turtle < OBJECT_ADDRESS(4));
	LAYER(WORKING_LAYER)->x = 0x2000u;
	LAYER(LAYER_A)->x = 0x2000u;
	LAYER(LAYER_B)->x = 0x2000u;
	d1_3 = draw_technodrome_screen();
	layer_priority = 0u;
	io_write8(PRIORITY_0C0001, 0u);
	d7 = 0x75u;
	queue_sound(d7, 0u);
	next_area_step();
	return d1_3;
}

uint32_t turtle_exit_building_site_land(uint32_t d1)
{
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, object = 0;
	uint8_t t1 = 0;
	uint16_t height = 0;

	turtles_on_the_way = 0u;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			if ((uint8_t)OBJECT(object)->y_speed != 0u)
			{
				turtles_on_the_way--;
				t1 = (uint8_t)OBJECT(object)->y_speed;
				OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | (t1 - 1u & 0xFFu);
				if (t1 == 1u)
				{
					if (OBJECT(object)->screen_x >= 0x100u)
						OBJECT(object)->flags |= 0x40u;
					d0 = 0x101u;
					turtle_set_state(d0, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
					OBJECT(object)->frame_time = 0u;
				}
			}
			else if (OBJECT(object)->routine != 1u)
			{
				turtles_on_the_way--;
				OBJECT(object)->x += 0x300u;
				d1 = OBJECT(object)->x >> 8;
				OBJECT(object)->screen_x = d1;
				height = OBJECT(object)->height;
				OBJECT(object)->height = height - 0x600u;
				if (height < 0x600u)
				{
					OBJECT(object)->height = 0u;
					OBJECT(object)->y_speed = (OBJECT(object)->y_speed & 0xFF00u) | 0x8u;
					OBJECT(object)->state = 0u;
					d1 = turtle_set_animation(d1, object);
				}
			}
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	if (turtles_on_the_way != 0u)
		return d1;
	cutscene_wait = 0xA0u;
	next_area_step();
	return d1;
}

uint32_t turtle_exit_building_site_wait(uint32_t d0, uint32_t d1)
{
	uint16_t d0_2 = 0, d2 = 0, d3 = 0;
	uint32_t d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, object = 0;
	uint8_t t1 = 0;

	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 != 1u)
	{
		if (cutscene_wait == 0x30u)
		{
			erase_balloon(&ignored_2, &ignored_3, &ignored_4);
			return d1;
		}
		if (cutscene_wait != 0x70u)
		{
			if (cutscene_wait != 8u)
				return d1;
			object = OBJECT_ADDRESS(0);
			do
			{
				if ((OBJECT(object)->flags & 1u) != 0u)
				{
					d0_2 = 0x200u;
					turtle_set_state(d0_2, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
				}
				object += 0x50u;
			} while (object < OBJECT_ADDRESS(4));
			return d1;
		}
		object = OBJECT_ADDRESS(0);
		while ((OBJECT(object)->flags & 1u) == 0u)
		{
			object += 0x50u;
			if (object >= OBJECT_ADDRESS(4))
				return d1;
		}
		d0 &= ~0xFFu;
		if (OBJECT(object)->screen_x >= 0x100u)
			d0 |= (uint8_t)(d0 - 1u);
		d1_2 = OBJECT(object)->screen_x;
		d2 = 8u;
		d3 = 0xFu;
		show_balloon_beside(d2, d3, &d0, &d1_2, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
		draw_balloon_pointer(ignored_5);
		return d1_2;
	}
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			d0_2 = 0x201u;
			turtle_set_state(d0_2, object, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4);
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	next_area_step();
	return d1;
}

void turtle_exit_building_site_rise(void)
{
	uint32_t animation = 0, ignored = 0, object = 0;

	turtles_on_the_way = 0u;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			if (OBJECT(object)->screen_y >= 0x100u)
			{
				animation = animations_02D4F4[OBJECT(object)->kind];
				set_animation(ignored, object, animation);
			}
			else
			{
				turtles_on_the_way--;
				OBJECT(object)->y += 0x600u;
				OBJECT(object)->screen_y = OBJECT(object)->y >> 8;
			}
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	if (turtles_on_the_way == 0u)
	{
		next_area_step();
		return;
	}
}

void turtle_exit_building_site_leave(void)
{
	uint32_t turtle = 0;

	turtles_on_the_way = 0u;
	turtle = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(turtle)->flags & 1u) != 0u)
		{
			if (OBJECT(turtle)->frame_time != 0u)
			{
				OBJECT(turtle)->x += (int16_t)OBJECT(turtle)->turtle.drift_speed;
				OBJECT(turtle)->screen_x = OBJECT(turtle)->x >> 8;
				turtles_on_the_way--;
				OBJECT(turtle)->y -= 0x100u;
				OBJECT(turtle)->screen_y = OBJECT(turtle)->y >> 8;
			}
			else
				OBJECT(turtle)->flags &= 0x7Fu;
		}
		turtle += 0x50u;
	} while (turtle < OBJECT_ADDRESS(4));
	if (turtles_on_the_way != 0u)
		return;
	area_beaten = 0u;
	area_cleared = 0u;
	scene_step++;
}

uint32_t turtle_exit_technodrome(uint32_t d1, uint32_t d2)
{
	uint32_t d0 = 0, d1_2 = 0, object = 0;
	uint8_t t1 = 0;

	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 == 0u)
		cutscene_wait = 0u;
	turtles_on_the_way = 0u;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u && OBJECT(object)->x < 0x19000u)
		{
			turtles_on_the_way--;
			d1_2 = (d1 & ~0xFFFFu) | 0x198u;
			d2 = (d2 & ~0xFFFFu) | 0x58u;
			direction_to(object, &d0, &d1_2, &d2);
			d1 = (d1_2 & ~0xFFFFu) | 0x200u;
			move_in_direction((uint8_t)d0, (uint16_t)d1, object);
			if (OBJECT(object)->x >= 0x18800u)
				OBJECT(object)->flags &= 0x7Fu;
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	if (cutscene_wait == 0u && turtles_on_the_way == 0u)
	{
		area_beaten = 0u;
		area_cleared = 0u;
		scene_step++;
	}
	return d1;
}

uint32_t run_exit_final(uint32_t d1)
{
	switch (cutscene_step)
	{
	case 0:
		return turtle_exit_final_walk(d1);
	case 1:
		return exit_final_shake(d1);
	}
}

uint32_t turtle_exit_final_walk(uint32_t d1)
{
	uint8_t d2 = 0, d7 = 0;
	uint16_t d0 = 0;
	uint32_t ignored = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0, object = 0;

	if (cutscene_wait != 0u)
	{
		cutscene_wait--;
		if (cutscene_wait >= 0x80u)
		{
			if (cutscene_wait != 0x80u)
				return d1;
			object = OBJECT_ADDRESS(0);
			do
			{
				if ((OBJECT(object)->flags & 1u) != 0u)
				{
					OBJECT(object)->flags |= 0x40u;
					d0 = 0x100u;
					turtle_set_state(d0, object, &d1, &ignored, &ignored_3, &ignored_4, &ignored_5);
				}
				object += 0x50u;
			} while (object < OBJECT_ADDRESS(4));
			d7 = 0x34u;
			queue_sound(d7, 0u);
		}
		if ((frame_count & 1u) == 0u)
		{
			d0 = cutscene_count;
			cutscene_count++;
			d0 = (uint16_t)((d0 & 7u) << 1);
			d1 = (d1 & ~0xFFu) | indexed_table_of_8_bit_values_030652[d0];
			d2 = rom_030653[d0];
			d1 = (d1 & ~0xFFFFu) | (uint16_t)(int8_t)d1;
			layer_b_scroll_x += d1;
			layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | ((uint8_t)layer_b_scroll_y + d2 & 0xFFu);
		}
		if (cutscene_wait >= 0x70u)
		{
			if (cutscene_wait != 0x70u)
				return d1;
			object = OBJECT_ADDRESS(0);
			do
			{
				if ((OBJECT(object)->flags & 1u) != 0u)
				{
					d0 = 0x100u;
					turtle_set_state(d0, object, &d1, &ignored, &ignored_3, &ignored_4, &ignored_5);
				}
				object += 0x50u;
			} while (object < OBJECT_ADDRESS(4));
		}
	}
	turtles_on_the_way = 0u;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u && OBJECT(object)->x >= 0x4000u)
		{
			turtles_on_the_way--;
			OBJECT(object)->x -= 0x300u;
			OBJECT(object)->screen_x = OBJECT(object)->x >> 8;
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	if (turtles_on_the_way != 0u)
		return d1;
	cutscene_wait = 0x80u;
	next_area_step();
	return d1;
}

/* the screen shakes on a while, then the exit is over and the ending follows */
uint32_t exit_final_shake(uint32_t d1)
{
	uint8_t d2 = 0;
	uint16_t d0 = 0;
	uint8_t t1 = 0;

	if ((frame_count & 1u) == 0u)
	{
		d0 = cutscene_count;
		cutscene_count++;
		d0 = (uint16_t)((d0 & 7u) << 1);
		d1 = indexed_table_of_8_bit_values_030652[d0];
		d2 = rom_030653[d0];
		d1 = (uint16_t)(int8_t)d1;
		layer_b_scroll_x += d1;
		layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | ((uint8_t)layer_b_scroll_y + d2 & 0xFFu);
	}
	t1 = cutscene_wait;
	cutscene_wait = t1 - 1u;
	if (t1 == 1u)
	{
		area_beaten = 0u;
		area_cleared = 0u;
		scene_step++;
	}
	return d1;
}

/* the screen of the Technodrome in its cave */
uint32_t draw_technodrome_screen(void)
{
	uint32_t a0 = 0;

	io_write8(TILES_106B00, 0xC0u);
	tile_banks_0_1 = 0xC0u;
	LAYER(WORKING_LAYER)->map = layers_0458F8_ADDRESS;
	LAYER(WORKING_LAYER)->blocks = 0x459F8u;
	LAYER(WORKING_LAYER)->x = 0x2000u;
	LAYER(WORKING_LAYER)->y = 0x10000u;
	LAYER(WORKING_LAYER)->map_width = 0x20u;
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	io_write8(TILES_106E00, 0x2Cu);
	tile_banks_2_3 = 0x2Cu;
	LAYER(WORKING_LAYER)->map = 0x45D4Au;
	LAYER(WORKING_LAYER)->blocks = 0x45E4Au;
	LAYER(WORKING_LAYER)->x = 0x2000u;
	LAYER(WORKING_LAYER)->y = 0x10000u;
	a0 = TILE_RAM + 0x2000u;
	return draw_whole_layer(a0);
}

/* the three tile layers cleared to blank between two screens */
void clear_layers(uint32_t *p_d1, uint32_t *p_a0)
{
	uint8_t d0 = 0;
	uint16_t d7 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, d1 = 0;
	uint16_t t17 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0;

	a0 = TILE_RAM;
	a1 = TILE_RAM + 0x2000u;
	a2 = TILE_RAM + 0x4000u;
	d0 = 0u;
	d1 = 0x10u;
	d7 = 0x200u;
	do
	{
		io_write8(a0, d0);
		t1 = a1;
		a1++;
		io_write8(t1, d0);
		t2 = a2;
		a2++;
		io_write8(t2, d0);
		a0++;
		io_write8(a0, d1);
		t3 = a1;
		a1++;
		io_write8(t3, d1);
		t4 = a2;
		a2++;
		io_write8(t4, d1);
		a0++;
		io_write8(a0, d0);
		t5 = a1;
		a1++;
		io_write8(t5, d0);
		t6 = a2;
		a2++;
		io_write8(t6, d0);
		a0++;
		io_write8(a0, d1);
		t7 = a1;
		a1++;
		io_write8(t7, d1);
		t8 = a2;
		a2++;
		io_write8(t8, d1);
		a0++;
		io_write8(a0, d0);
		t9 = a1;
		a1++;
		io_write8(t9, d0);
		t10 = a2;
		a2++;
		io_write8(t10, d0);
		a0++;
		io_write8(a0, d1);
		t11 = a1;
		a1++;
		io_write8(t11, d1);
		t12 = a2;
		a2++;
		io_write8(t12, d1);
		a0++;
		io_write8(a0, d0);
		t13 = a1;
		a1++;
		io_write8(t13, d0);
		t14 = a2;
		a2++;
		io_write8(t14, d0);
		a0++;
		io_write8(a0, d1);
		t15 = a1;
		a1++;
		io_write8(t15, d1);
		t16 = a2;
		a2++;
		io_write8(t16, d1);
		t17 = d7;
		d7 = (uint16_t)(t17 - 1u);
		a0++;
	} while (t17 != 1u);
	*p_d1 = d1;
	*p_a0 = a0;
}
