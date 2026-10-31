/**
 *    Name:        stage/drill_arrival.c
 *    Description: the drill pod that comes down through the ceiling in areas 1 and 7 and lets out Rocksteady or the flying drones
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the drill pod's arrival in areas 1 and 7, a step a frame */
void run_drill_arrival(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;

	if (drill_arrival >= 0)
	{
		switch (drill_arrival_step)
		{
		case 0:
			d7 = drill_arrival_wait(d7);
			break;
		case 1:
			d7 = drill_arrival_rumble(d7);
			break;
		case 2:
			drill_arrival_descend(&d5, &d7, p_a1);
			break;
		case 3:
			d7 = drill_arrival_open(d7);
			break;
		case 4:
			d7 = drill_arrival_end();
			break;
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* at its place in the area the scroll stops and the rumbling starts */
uint32_t drill_arrival_wait(uint32_t d7)
{
	uint32_t d7_2 = 0;

	if (stage != 1u)
	{
		if (LAYER(LAYER_B)->x < 0x4B000u)
			return d7;
		hurry_time = 0u;
		drill_arrival = 1;
		scroll_held_right = 0xFFu;
		drill_arrival_time = 0xC0u;
		shake_step = 0u;
		d7_2 = (d7 & ~0xFFu) | 0xFEu;
		queue_sound((uint8_t)d7_2, 0u);
		d7_2 = (d7_2 & ~0xFFu) | 0x34u;
		queue_sound((uint8_t)d7_2, 0u);
		drill_rumbling = 0xFFu;
		drill_arrival_step++;
		return d7_2;
	}
	if (LAYER(LAYER_B)->x < 0xA000u)
		return d7;
	hurry_time = 0u;
	drill_arrival = 1;
	scroll_held_right = 0xFFu;
	drill_arrival_time = 0xC0u;
	shake_step = 0u;
	d7_2 = (d7 & ~0xFFu) | 0xFEu;
	queue_sound((uint8_t)d7_2, 0u);
	d7_2 = (d7_2 & ~0xFFu) | 0x34u;
	queue_sound((uint8_t)d7_2, 0u);
	drill_rumbling = 0xFFu;
	drill_arrival_step++;
	return d7_2;
}

/* the screen shakes, then the hole, the drill pod and its door appear */
uint32_t drill_arrival_rumble(uint32_t d7)
{
	uint32_t animation = 0, d0 = 0, d1 = 0, d7_2 = 0, object = 0;
	uint8_t t1 = 0;

	hurry_time = 0u;
	t1 = drill_arrival_time;
	drill_arrival_time = t1 - 1u;
	if (t1 != 1u)
	{
		shake_layers_and_objects();
		return d7;
	}
	d7_2 = (d7 & ~0xFFu) | 0xCu;
	queue_sound((uint8_t)d7_2, 0u);
	object = OBJECT_ADDRESS(44);
	OBJECT(OBJECT_ADDRESS(44))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(45))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(46))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(44))->colour = 0xFFu;
	OBJECT(OBJECT_ADDRESS(45))->colour = 0xFFu;
	OBJECT(OBJECT_ADDRESS(46))->colour = 0xFFu;
	d1 = 0x6500u;
	d0 = 0x1D6FFu;
	if (stage != 1u)
	{
		d1 = 0x8500u;
		d0 = 0x5B7FFu;
	}
	d0 -= LAYER(LAYER_B)->x;
	OBJECT(object)->x = d0;
	OBJECT(object + 0x50u)->x = d0;
	OBJECT(object + 0xA0u)->x = d0;
	d0 = d0 >> 8;
	OBJECT(object)->screen_x = d0;
	OBJECT(object + 0x50u)->screen_x = d0;
	OBJECT(object + 0xA0u)->screen_x = d0;
	OBJECT(object)->y = d1;
	d1 += 0xE00u;
	OBJECT(object + 0x50u)->y = d1;
	d1 -= 0xC00u;
	OBJECT(object + 0xA0u)->y = d1;
	d1 = d1 >> 8;
	OBJECT(object + 0xA0u)->screen_y = d1;
	d1 = (uint16_t)(d1 + 0xCu);
	OBJECT(object + 0x50u)->screen_y = d1;
	OBJECT(object)->screen_y = d1 - 0xEu;
	animation = 0x2D7BAu;
	if (stage != 1u)
		animation = 0x2D7F8u;
	set_animation(d1, object, animation);
	animation = animations_02D796_ADDRESS;
	object += 0x50u;
	set_animation(d1, object, animation);
	animation = 0x2D836u;
	object += 0x50u;
	set_animation(d1, object, animation);
	shake_layers_and_objects();
	drill_arrival_step++;
	return d7_2;
}

/* the layers shake and the turtles and the drill pod stay where they are */
void shake_layers_and_objects(void)
{
	uint16_t d0 = 0, d4 = 0;
	uint32_t d1 = 0, d2 = 0, object = 0;

	if ((frame_count & 1u) != 0u)
		return;
	d0 = shake_step;
	shake_step++;
	d0 = (uint16_t)((d0 & 7u) << 1);
	d2 = rom_030653[d0];
	d1 = (uint16_t)(int8_t)indexed_table_of_8_bit_values_030652[d0];
	layer_a_scroll_x += d1;
	layer_b_scroll_x += d1;
	layer_a_scroll_y = (layer_a_scroll_y & 0xFF00u) | ((uint8_t)layer_a_scroll_y + d2 & 0xFFu);
	layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | ((uint8_t)layer_b_scroll_y + d2 & 0xFFu);
	d1 = (uint32_t)(int16_t)(0u - d1) << 8;
	d2 = (uint32_t)(int16_t)(int8_t)d2 << 8;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u)
		{
			OBJECT(object)->x += d1;
			OBJECT(object)->y += d2;
			d4 = (uint16_t)(OBJECT(object)->y >> 8);
			OBJECT(object)->screen_x = OBJECT(object)->x >> 8;
			OBJECT(object)->screen_y = d4;
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	OBJECT(OBJECT_ADDRESS(44))->x += d1;
	OBJECT(OBJECT_ADDRESS(44))->y += d2;
	d4 = (uint16_t)(OBJECT(OBJECT_ADDRESS(44))->y >> 8);
	OBJECT(OBJECT_ADDRESS(44))->screen_x = OBJECT(OBJECT_ADDRESS(44))->x >> 8;
	OBJECT(OBJECT_ADDRESS(44))->screen_y = d4;
	OBJECT(OBJECT_ADDRESS(45))->x += d1;
	OBJECT(OBJECT_ADDRESS(45))->y += d2;
	d4 = (uint16_t)(OBJECT(OBJECT_ADDRESS(45))->y >> 8);
	OBJECT(OBJECT_ADDRESS(45))->screen_x = OBJECT(OBJECT_ADDRESS(45))->x >> 8;
	OBJECT(OBJECT_ADDRESS(45))->screen_y = d4;
	OBJECT(OBJECT_ADDRESS(46))->x += d1;
	OBJECT(OBJECT_ADDRESS(46))->y += d2;
	d4 = (uint16_t)(OBJECT(OBJECT_ADDRESS(46))->y >> 8);
	OBJECT(OBJECT_ADDRESS(46))->screen_x = OBJECT(OBJECT_ADDRESS(46))->x >> 8;
	OBJECT(OBJECT_ADDRESS(46))->screen_y = d4;
}

/* the drill pod drills down through the ceiling into the room */
void drill_arrival_descend(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t a1 = *p_a1;
	uint16_t d0 = 0, d1 = 0, screen_y = 0;
	uint32_t object = 0;

	hurry_time = 0u;
	shake_layers_and_objects();
	object = OBJECT_ADDRESS(45);
	OBJECT(OBJECT_ADDRESS(46))->y += 0xC0u;
	OBJECT(OBJECT_ADDRESS(46))->screen_y = OBJECT(OBJECT_ADDRESS(46))->y >> 8;
	OBJECT(OBJECT_ADDRESS(45))->y += 0xC0u;
	d0 = (uint16_t)(OBJECT(OBJECT_ADDRESS(45))->y >> 8);
	OBJECT(OBJECT_ADDRESS(45))->screen_y = d0;
	if (stage == 7u && OBJECT(object)->screen_y >= 0x9Eu && balloons_said == 1u)
	{
		a1 = OBJECT_ADDRESS(0);
		do
		{
			if ((OBJECT(a1)->flags & 1u) != 0u)
			{
				d0 &= ~0xFFu;
				d1 = (uint16_t)(OBJECT(a1)->screen_x - 0x40u);
				screen_y = OBJECT(a1)->screen_y;
				say_overgrown_cork_screw(d0, d1, screen_y, &d5, p_d7);
				break;
			}
			a1 += 0x50u;
		} while (a1 < OBJECT_ADDRESS(4));
	}
	d0 = 0x124u;
	if (stage != 1u)
		d0 = 0x144u;
	if (d0 < OBJECT(object)->screen_y)
	{
		OBJECT(object)->frame_time = 0u;
		drill_arrival_time = 0x70u;
		drill_arrival_step++;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_a1 = a1;
}

/* the drill pod's door opens and Rocksteady or the flying drones come out */
uint32_t drill_arrival_open(uint32_t d7)
{
	uint8_t d0 = 0;
	uint16_t d0_3 = 0, d1_2 = 0;
	uint32_t d0_2 = 0, d1 = 0, d7_2 = 0, object = 0;
	uint8_t t1 = 0, t2 = 0;

	hurry_time = 0u;
	t1 = drill_arrival_time;
	d0 = t1;
	if (t1 == 0u)
	{
		object = OBJECT_ADDRESS(46);
		OBJECT(OBJECT_ADDRESS(46))->y -= 0x200u;
		if (stage == 1u && OBJECT(object)->y == 0x11300u)
			d7 = start_rocksteady(d7);
		d0_3 = (uint16_t)(OBJECT(object)->y >> 8);
		OBJECT(object)->screen_y = d0_3;
		d1_2 = 0xA0u;
		if (stage != 1u)
			d1_2 = 0xC0u;
		if (d1_2 <= (uint16_t)d0_3)
			return d7;
		if (stage == 7u)
			release_flying_drones();
		drill_arrival_step++;
		return d7;
	}
	if (d0 >= 0x30u)
	{
		if (d0 != 0x30u)
			shake_layers_and_objects();
		else
		{
			drill_rumbling = 0u;
			d7 = (d7 & ~0xFFu) | 0x35u;
			queue_sound((uint8_t)d7, 0u);
			if (stage != 1u)
			{
				d7 = (d7 & ~0xFFu) | 0x66u;
				music = d7;
				queue_sound((uint8_t)d7, 0u);
			}
			d1 = 0x6500u;
			d0_2 = 0x1D6FFu;
			if (stage != 1u)
			{
				d1 = 0x8500u;
				d0_2 = 0x5B6FFu;
			}
			d0_2 -= LAYER(LAYER_B)->x;
			OBJECT(OBJECT_ADDRESS(44))->x = d0_2;
			OBJECT(OBJECT_ADDRESS(45))->x = d0_2;
			OBJECT(OBJECT_ADDRESS(46))->x = d0_2;
			d0_2 = d0_2 >> 8;
			OBJECT(OBJECT_ADDRESS(44))->screen_x = d0_2;
			OBJECT(OBJECT_ADDRESS(45))->screen_x = d0_2;
			OBJECT(OBJECT_ADDRESS(46))->screen_x = d0_2;
			OBJECT(OBJECT_ADDRESS(44))->y = d1;
			d1 += 0xC000u;
			OBJECT(OBJECT_ADDRESS(45))->y = d1;
			d1 -= 0xC00u;
			OBJECT(OBJECT_ADDRESS(46))->y = d1;
			d1 = d1 >> 8;
			OBJECT(OBJECT_ADDRESS(46))->screen_y = d1;
			d1 = (uint16_t)(d1 + 0xCu);
			OBJECT(OBJECT_ADDRESS(45))->screen_y = d1;
			OBJECT(OBJECT_ADDRESS(44))->screen_y = d1 - 0xC0u;
		}
	}
	t2 = drill_arrival_time;
	drill_arrival_time = t2 - 1u;
	if (t2 != 1u)
		return d7;
	if (stage == 7u)
		start_flying_drones();
	d7_2 = (d7 & ~0xFFu) | 0x36u;
	queue_sound((uint8_t)d7_2, 0u);
	return d7_2;
}

/* the drill pod stays as part of the room and the scroll goes on */
uint32_t drill_arrival_end(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	hurry_time = 0u;
	scroll_held_right = 0u;
	drill_arrival = -1;
	OBJECT(OBJECT_ADDRESS(44))->flags = 0u;
	OBJECT(OBJECT_ADDRESS(45))->flags = 0u;
	OBJECT(OBJECT_ADDRESS(46))->flags = 0u;
	d7 = 3u;
	a6 = 0x18AECu;
	if (stage != 1u)
	{
		d7 = 0x1Cu;
		a6 = 0x18F16u;
	}
	draw_tile_block(d7, a6);
	d7_2 = 4u;
	a6 = 0x18BAEu;
	if (stage != 1u)
	{
		d7_2 = 0x1Du;
		a6 = 0x18FB8u;
	}
	draw_tile_block((uint16_t)d7_2, a6);
	return d7_2;
}
