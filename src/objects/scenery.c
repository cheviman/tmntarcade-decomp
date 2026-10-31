/**
 *    Name:        objects/scenery.c
 *    Description: the areas' scenery and traps: balls, hydrants, signs, rats, oil drums, turrets, nozzles, electric beams, spiked poles, the parked car
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* an unseen spot high up that will drop four balls */
void ball_dropper_start(uint32_t a0)
{
	uint32_t stats = 0;

	stats = ball_dropper_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->routine++;
	OBJECT(a0)->ball_dropper.balls_left = 3u;
}

/* a ball drops each time the screen reaches the next place; the dropper is gone after the last */
uint32_t ball_dropper_wait(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;
	uint8_t t1 = 0;

	d7 = OBJECT(a0)->ball_dropper.balls_left;
	d7 = (uint16_t)(d7 << 1);
	d7 = indexed_table_of_16_bit_values_00F938[d7 / 2u];
	if (OBJECT(a0)->screen_x <= d7)
	{
		a6 = OBJECT_ADDRESS(4);
		d7 = IN_PAGE(d7, 8u);
		d7 = (uint8_t)d7;
		find_free_object(&d7, &a6);
		if ((uint8_t)d7 != 0u)
		{
			ball_dropper_drop_ball(a0, a6);
			t1 = OBJECT(a0)->ball_dropper.balls_left - 1u;
			OBJECT(a0)->ball_dropper.balls_left = t1;
			if ((int8_t)t1 < 0)
			{
				remove_object(a0);
				return d7;
			}
		}
	}
	return d7;
}

/* a ball at the dropper's place */
void ball_dropper_drop_ball(uint32_t a0, uint32_t a6)
{
	OBJECT(a6)->flags = 1u;
	OBJECT(a6)->contacts = 0u;
	OBJECT(a6)->kind = 0x60u;
	OBJECT(a6)->parameter = 0u;
	OBJECT(a6)->colour = 0xFFu;
	OBJECT(a6)->animation_delay = 0u;
	place_at_object(a0, a6);
	OBJECT(a6)->routine = 0u;
	OBJECT(a6)->state = 0u;
}

/* a dark ball, high up */
void ball_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = ball_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_015D68;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the ball drops and starts bouncing away, knocking turtles flying */
uint32_t ball_drop(uint32_t d7, uint32_t a0)
{
	OBJECT(a0)->height -= 0x480u;
	if (OBJECT(a0)->height < 0x3000u)
	{
		OBJECT(a0)->routine++;
		OBJECT(a0)->height = 0x3000u;
		OBJECT(a0)->x_speed = 0x1E0;
		OBJECT(a0)->y_speed = -0x1E0;
		OBJECT(a0)->height_speed = 0x400;
		OBJECT(a0)->contacts |= 0x80u;
		OBJECT(a0)->shadow = 0x16660u;
		d7 = (d7 & ~0xFFu) | 0x24u;
		queue_sound((uint8_t)d7, 0u);
		OBJECT(a0)->flags |= 4u;
	}
	return d7;
}

/* the ball bounces on until it is gone at the area's back */
uint32_t ball_bounce(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = move_by_speeds(a0);
	OBJECT(a0)->height_speed -= 0x60u;
	if ((int16_t)(uint16_t)(OBJECT(a0)->y >> 16u) < 0)
	{
		remove_object(a0);
		return d7;
	}
	if ((int8_t)OBJECT(a0)->height_whole < 0)
	{
		OBJECT(a0)->height_speed = 0x400;
		OBJECT(a0)->height = 0u;
		d7 = (d7 & ~0xFFu) | 0x24u;
		queue_sound((uint8_t)d7, 0u);
	}
	return d7;
}

/* Unused as an entry: only the dispatcher's switch has it, in the middle of an instruction; the ball's
   landing sound without a new bounce */
uint32_t ball_land(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	OBJECT(a0)->height = 0u;
	d7_2 = (d7 & ~0xFFu) | 0x24u;
	queue_sound((uint8_t)d7_2, 0u);
	return d7_2;
}

/* a barrier across the highway, or one of its unseen parts that knock turtles down */
void road_barrier_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	stats = road_barrier_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->flags |= 4u;
	animation = rom_015EC2;
	if (OBJECT(a0)->parameter == 0u)
	{
		OBJECT(a0)->flags &= ~4u;
		OBJECT(a0)->flags |= 0x80u;
		animation = rom_015EBE;
	}
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the barrier stays until it leaves the screen */
void road_barrier_stay(uint32_t a0)
{
	remove_if_off_screen(a0);
}

/* tires lying on the highway, two or one by the parameter */
void tire_stack_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = tire_stack_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_015EEA;
	if (OBJECT(a0)->parameter != 0u)
		animation = rom_015EEE;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the tires stay until they leave the screen */
void tire_stack_stay(uint32_t a0)
{
	remove_if_off_screen(a0);
}

/* a ball high up in the Technodrome */
void technodrome_ball_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	technodrome_ball_drift(a0);
	OBJECT(a0)->colour = 9u;
	OBJECT(a0)->animation_delay = 0u;
	OBJECT(a0)->flags |= 0x80u;
	stats = technodrome_ball_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_015D68;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the ball drops and starts bouncing off to the right, knocking turtles flying */
uint32_t technodrome_ball_drop(uint32_t d7, uint32_t a0)
{
	uint16_t height = 0;

	technodrome_ball_drift(a0);
	OBJECT(a0)->x += 0x480u;
	height = OBJECT(a0)->height;
	OBJECT(a0)->height = height - 0x480u;
	if (height < 0x480u)
	{
		OBJECT(a0)->routine++;
		OBJECT(a0)->height = 0u;
		OBJECT(a0)->x_speed = 0x3C0;
		OBJECT(a0)->y_speed = 0;
		OBJECT(a0)->height_speed = 0x4E0;
		OBJECT(a0)->contacts |= 0x80u;
		OBJECT(a0)->shadow = 0x16660u;
		OBJECT(a0)->technodrome_ball.shadow_time = 0x32u;
		d7 = (d7 & ~0xFFu) | 0x24u;
		queue_sound((uint8_t)d7, 0u);
		OBJECT(a0)->flags |= 4u;
	}
	return d7;
}

/* the ball bounces on until it is past the screen's right edge */
uint32_t technodrome_ball_bounce(uint32_t a0)
{
	uint32_t d7 = 0;
	uint8_t shadow_time = 0;

	technodrome_ball_drift(a0);
	d7 = move_by_speeds(a0);
	if (OBJECT(a0)->technodrome_ball.shadow_time != 0u)
	{
		shadow_time = OBJECT(a0)->technodrome_ball.shadow_time;
		OBJECT(a0)->technodrome_ball.shadow_time = shadow_time - 1u;
		if (shadow_time == 1u)
			OBJECT(a0)->contacts &= 0x7Fu;
	}
	OBJECT(a0)->height_speed -= 0x40u;
	if (OBJECT(a0)->screen_x >= 0x1A0u)
	{
		remove_object(a0);
		return d7;
	}
	if ((int8_t)OBJECT(a0)->height_whole < 0)
	{
		OBJECT(a0)->height_speed = 0x4E0;
		OBJECT(a0)->height = 0u;
		d7 = (d7 & ~0xFFu) | 0x24u;
		queue_sound((uint8_t)d7, 0u);
	}
	return d7;
}

/* the ball moves along the area's diagonal */
void technodrome_ball_drift(uint32_t a0)
{
	OBJECT(a0)->x += 0x400u;
	OBJECT(a0)->y -= 0x400u;
}

/* a fire hydrant with four bars */
void hydrant_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x82u;
	stats = record_0180FA_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_01443E;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the hydrant stays until it leaves the screen */
void hydrant_stay(uint32_t a0)
{
	remove_if_off_screen(a0);
}

/* the broken hydrant sprays a jet of water every few frames until jets_left runs out */
uint32_t hydrant_spray(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t timer = 0, jets_left = 0;

	timer = OBJECT(a0)->hydrant.timer;
	OBJECT(a0)->hydrant.timer = timer - 1u;
	if (timer != 0u)
		return d7;
	jets_left = OBJECT(a0)->hydrant.jets_left;
	OBJECT(a0)->hydrant.jets_left = jets_left - 1u;
	if (jets_left == 0u)
	{
		OBJECT(a0)->routine++;
		OBJECT(a0)->hydrant.timer = 0u;
		OBJECT(a0)->hydrant.jets_left = 0u;
		return d7;
	}
	a6 = OBJECT_ADDRESS(4);
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint8_t)d7_2;
	find_free_object(&d7_2, &a6);
	return hydrant_spray_jet(d7_2, a0, a6);
}

/* a jet of water if there is room for it, else the spray ends */
uint32_t hydrant_spray_jet(uint32_t d7, uint32_t a0, uint32_t a6)
{
	if ((uint8_t)d7 == 0u)
	{
		OBJECT(a0)->routine++;
		OBJECT(a0)->hydrant.timer = 0u;
		OBJECT(a0)->hydrant.jets_left = 0u;
		return d7;
	}
	d7 = hydrant_start_water(d7, a0, a6);
	OBJECT(a0)->hydrant.timer = 4u;
	return d7;
}

/* a turtle's hit sparks on the hydrant, or breaks it and starts the spray the way the hit sent it */
uint32_t hydrant_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	if (OBJECT(a0)->health_bars == 0u)
	{
		hydrant_sprays_left = 0u;
		animation = rom_014446;
		if ((int8_t)OBJECT(a0)->hit < 0)
		{
			animation = rom_01444A;
			hydrant_sprays_left = 1u;
		}
		set_animation(0u, a0, animation);
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->hydrant.timer = 0u;
		OBJECT(a0)->hydrant.jets_left = 4u;
		stats = hydrant_struck_stats_ADDRESS;
		set_object_stats(a0, stats);
		d7_2 = (d7 & ~0xFFu) | 5u;
		queue_sound((uint8_t)d7_2, stats);
		OBJECT(a0)->flags &= ~6u;
		return d7_2;
	}
	OBJECT(a0)->health = 1u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->hydrant.timer = 0x28u;
	OBJECT(a0)->flags &= ~2u;
	d7_2 = (d7 & ~0xFFu) | 5u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_014442;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the hydrant can be hit again */
void hydrant_recover(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->hydrant.timer;
	OBJECT(a0)->hydrant.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->health = 1u;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->hydrant.timer = 8u;
		OBJECT(a0)->flags |= 2u;
	}
}

/* a jet of water from the hydrant, weaker as the jets go */
uint32_t hydrant_start_water(uint32_t d7, uint32_t a0, uint32_t water)
{
	uint32_t d7_2 = 0;

	OBJECT(water)->flags = 1u;
	OBJECT(water)->contacts = 0u;
	OBJECT(water)->kind = 0x21u;
	OBJECT(water)->parameter = 0u;
	OBJECT(water)->colour = 0xFFu;
	OBJECT(water)->animation_delay = 0u;
	place_at_object(a0, water);
	d7_2 = (d7 & ~0xFFFFu) | 0x2000u;
	if (hydrant_sprays_left != 0u)
		d7_2 = (int16_t)~d7_2;
	OBJECT(water)->x += d7_2;
	OBJECT(water)->height = 0xA00u;
	OBJECT(water)->hydrant_water.jet = 0u;
	if (OBJECT(a0)->hydrant.jets_left != 3u)
		OBJECT(water)->hydrant_water.jet = 1u;
	if (OBJECT(a0)->hydrant.jets_left == 0u)
		OBJECT(water)->hydrant_water.jet++;
	if (hydrant_sprays_left != 0u)
		OBJECT(water)->hydrant_water.jet |= 0x80u;
	OBJECT(water)->routine = 0u;
	OBJECT(water)->state = 0u;
	return d7_2;
}

/* a jet of water flies across, hitting what it meets */
uint32_t hydrant_water_start(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0, stats = 0;

	OBJECT(a0)->flags = 0x85u;
	stats = hydrant_water_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->x_speed = 0x580;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)OBJECT(a0)->hydrant_water.jet < 0)
	{
		OBJECT(a0)->x_speed = ~OBJECT(a0)->x_speed;
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->attack &= 0x7Fu;
	}
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	d7 = OBJECT(a0)->hydrant_water.jet;
	d7 = d7 & 3u;
	d7 = (uint16_t)(d7 << 2);
	animation = rom_0144E8[d7 / 4u];
	set_animation(0u, a0, animation);
	d7 = 0xEu;
	queue_sound((uint8_t)d7, animation);
	OBJECT(a0)->routine++;
	return d7;
}

/* the water flies on until it leaves the screen */
uint32_t hydrant_water_fly(uint32_t a0)
{
	uint32_t x_speed = 0;

	remove_if_off_screen(a0);
	x_speed = OBJECT(a0)->x_speed;
	OBJECT(a0)->x += x_speed;
	return x_speed;
}

/* a traffic cone */
void roadside_cone_start(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = roadside_cone_stats_ADDRESS;
	roadside_stand(a0, a6);
}

/* a parking meter or a speed limit sign */
void roadside_pole_start(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = roadside_pole_stats_ADDRESS;
	roadside_stand(a0, a6);
}

/* the thing stands by the road, and a turtle can hit it */
void roadside_stand(uint32_t a0, uint32_t a6)
{
	uint32_t a6_2 = 0, animation = 0;

	set_object_stats(a0, a6);
	OBJECT(a0)->flags |= 0x82u;
	a6_2 = 0x1452Au;
	if (OBJECT(a0)->kind != 0x22u)
	{
		a6_2 = 0x1456Au;
		if (OBJECT(a0)->kind != 0x59u)
			a6_2 = 0x15AF6u;
	}
	animation = DATA32(a6_2);
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* it stays until it leaves the screen */
void roadside_stay(uint32_t a0)
{
	remove_if_off_screen(a0);
}

/* it flies on until it leaves the screen */
uint32_t roadside_fly(uint32_t a0)
{
	uint32_t x_speed = 0;

	remove_if_off_screen(a0);
	x_speed = OBJECT(a0)->x_speed;
	OBJECT(a0)->x += x_speed;
	return x_speed;
}

/* a turtle's hit sends the speed limit sign flying */
uint32_t roadside_speed_sign_struck(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x1456Au;
	OBJECT(a0)->x_speed = 0x500;
	return roadside_knock_away(d7, a0, a6);
}

/* a turtle's hit sends the traffic cone flying */
uint32_t roadside_cone_struck(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x15AF6u;
	OBJECT(a0)->x_speed = 0x600;
	return roadside_knock_away(d7, a0, a6);
}

/* a turtle's hit sends the parking meter flying */
uint32_t roadside_parking_meter_struck(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x1452Au;
	OBJECT(a0)->x_speed = 0x400;
	return roadside_knock_away(d7, a0, a6);
}

/* it flies off the way the hit sent it, knocking down what it hits */
uint32_t roadside_knock_away(uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t animation = 0, d7_2 = 0;

	if ((int8_t)OBJECT(a0)->hit < 0)
	{
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->x_speed = ~OBJECT(a0)->x_speed;
		OBJECT(a0)->attack &= 0x7Fu;
	}
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	animation = mem_read32(a6 + 4u);
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 5u;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->flags |= 4u;
	return d7_2;
}

/* a sewer rat, which drops in or runs */
uint32_t rat_start(uint32_t a0)
{
	uint16_t d7 = 0;
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	d7 = 0x1C0u;
	OBJECT(a0)->flags |= 0x40u;
	if ((int8_t)OBJECT(a0)->parameter >= 0)
	{
		d7 = (uint16_t)~d7;
		OBJECT(a0)->flags &= 0xBFu;
	}
	OBJECT(a0)->x_speed = d7;
	OBJECT(a0)->parameter &= 0x7Fu;
	OBJECT(a0)->x -= indexed_table_of_32_bit_values_00FF60[OBJECT(a0)->parameter];
	animation = rom_0145A0;
	OBJECT(a0)->routine = 3u;
	if (OBJECT(a0)->height != 0u)
	{
		animation = rom_014598;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->height_speed = 0x500;
	}
	set_animation(0u, a0, animation);
	d7_2 = rat_random_run_time(a0);
	return d7_2;
}

/* the rat drops in and sits */
uint32_t rat_drop(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	OBJECT(a0)->height -= d7_2;
	if (OBJECT(a0)->height < 0x1800u)
	{
		animation = rom_01459C;
		set_animation(0u, a0, animation);
		OBJECT(a0)->rat.timer = 0x40u;
		OBJECT(a0)->routine++;
	}
	return d7_2;
}

/* the rat sits a while, then runs */
uint32_t rat_sit(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->rat.timer;
	OBJECT(a0)->rat.timer = timer - 1u;
	if (timer == 0u)
	{
		animation = rom_0145A0;
		set_animation(0u, a0, animation);
		d7 = rat_random_run_time(a0);
		OBJECT(a0)->routine++;
	}
	return d7;
}

/* the rat runs, and is gone once it leaves the screen */
uint32_t rat_run(uint32_t d7, uint32_t a0)
{
	remove_if_off_screen(a0);
	return rat_run_step(d7, a0);
}

/* Unused as an entry: only the dispatcher's switch has it, in the middle of an instruction; the rat's
   run */
uint32_t rat_run_on(uint32_t d7, uint32_t a0)
{
	return rat_run_step(d7, a0);
}

/* the rat runs a while, then stops with a squeak */
uint32_t rat_run_step(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, x_speed = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->rat.timer;
	OBJECT(a0)->rat.timer = timer - 1u;
	if (timer != 0u)
	{
		x_speed = OBJECT(a0)->x_speed;
		OBJECT(a0)->x += x_speed;
		return x_speed;
	}
	animation = rom_01459C;
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 0x32u;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->rat.timer = 0x40u;
	OBJECT(a0)->routine--;
	return d7_2;
}

/* Unused as an entry: only the dispatcher's switch has it, in the middle of an instruction; the rat
   squeaks and sits */
uint32_t rat_squeak(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x32u;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->rat.timer = 0x40u;
	OBJECT(a0)->routine--;
	return d7_2;
}

/* how long the rat runs, at random */
uint32_t rat_random_run_time(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 8u;
	d7 = random_below((uint16_t)d7, a0);
	OBJECT(a0)->rat.timer = indexed_table_of_8_bit_values_010012[d7];
	return d7;
}

/* an alligator swims slowly in the sewer's water */
void alligator_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = alligator_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_0145FC;
	set_animation(0u, a0, animation);
	OBJECT(a0)->x_speed = -0x40;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->routine++;
}

/* the alligator swims, and snaps its jaws as it comes on */
uint32_t alligator_swim(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0;

	d7 = move_across_screen(a0);
	if (OBJECT(a0)->screen_x >= 0xC0u)
		return d7;
	OBJECT(a0)->routine++;
	d7 = (d7 & ~0xFFu) | 0x12u;
	queue_sound((uint8_t)d7, 0u);
	animation = rom_014600;
	set_animation(0u, a0, animation);
	return d7;
}

/* the alligator swims on */
uint32_t alligator_snap(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = move_across_screen(a0);
	return d7;
}

/* it moves across until it leaves the screen */
uint32_t move_across_screen(uint32_t a0)
{
	uint32_t x_speed = 0;

	remove_if_off_screen(a0);
	x_speed = OBJECT(a0)->x_speed;
	OBJECT(a0)->x += x_speed;
	return x_speed;
}

/* a woman on a skateboard glides across the street */
void skateboarder_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x82u;
	stats = skateboarder_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_01461A;
	set_animation(0u, a0, animation);
	OBJECT(a0)->x_speed = -0x200;
	OBJECT(a0)->routine++;
	skateboarder_idle();
}

/* nothing */
void skateboarder_idle(void)
{
}

/* she glides on until she leaves the screen */
uint32_t skateboarder_glide(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = move_across_screen(a0);
	return d7;
}

/* a turtle's hit makes her duck with a cry */
uint32_t skateboarder_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->routine = 1u;
	d7_2 = (d7 & ~0xFFFFu) | 0xBAu;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_01461E;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* a pizza box, whose taking refills a turtle's health */
uint32_t pizza_start(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x84u;
	stats = indexed_table_of_32_bit_values_010148[OBJECT(a0)->parameter];
	set_object_stats(a0, stats);
	d7 = OBJECT(a0)->parameter;
	d7 = (uint16_t)(d7 << 2);
	animation = rom_014636[d7 / 4u];
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
	OBJECT(a0)->pizza.announced = 0u;
	return d7;
}

/* as the pizza comes on the screen it is announced; a turtle that takes it gets its health back */
void pizza_wait(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint16_t d0_2 = 0, d2 = 0;
	uint32_t animation = 0, d1 = 0, d7_2 = 0;

	if (OBJECT(a0)->screen_x < 0x170u && OBJECT(a0)->pizza.announced == 0u)
	{
		OBJECT(a0)->pizza.announced = 1u;
		d7 = (d7 & ~0xFFFFu) | 0xB7u;
		queue_sound((uint8_t)d7, 0u);
		d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
		d1 = (uint16_t)(OBJECT(a0)->screen_x - 0xCu);
		d2 = (uint16_t)(OBJECT(a0)->screen_y - 0x20u);
		if (d2 >= 0x300u)
			d2 = 0u;
		say_pizza_time(d0_2, d1, d2, a0, &d5, &d7);
	}
	remove_if_off_screen(a0);
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		d7_2 = (uint8_t)(4u + OBJECT(a0)->parameter);
		d7_2 = (uint16_t)(d7_2 << 2);
		animation = rom_014636[d7_2 / 4u];
		set_animation(d1, a0, animation);
		OBJECT(a0)->flags &= ~4u;
		d7 = 0x19u;
		queue_sound((uint8_t)d7, animation);
		OBJECT(a0)->routine++;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* the opened box is gone */
void pizza_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	remove_object(a0);
}

/* a billboard high up, with Foot soldiers behind it */
uint32_t billboard_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_01480E;
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFFFu) | frame_count;
	d7_2 = LINKED(d7_2, d7_2 & 6u);
	OBJECT(a0)->billboard.trigger_x = indexed_table_of_16_bit_values_010232[(uint16_t)d7_2 / 2u];
	OBJECT(a0)->routine++;
	return d7_2;
}

/* two Foot soldiers jump down and the billboard topples onto the turtles */
uint32_t billboard_wait(uint32_t d7, uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, animation = 0, d7_2 = 0, stats = 0;

	d7_2 = (d7 & ~0xFFFFu) | OBJECT(a0)->billboard.trigger_x;
	if ((uint16_t)d7_2 < OBJECT(a0)->screen_x)
		return d7_2;
	d0 = 0u;
	a6 = OBJECT_ADDRESS(12);
	d7_2 = (d7_2 & ~0xFFu) | 0xCu;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint8_t)d7_2;
	find_free_object(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
	{
		d7_2 = billboard_start_soldier(d0, d7_2, a0, a6);
		d0 = 1u;
		a6 = OBJECT_ADDRESS(12);
		d7_2 = (d7_2 & ~0xFFu) | 0xCu;
		d7_2 = (d7_2 & ~0xFFFFu) | (uint8_t)d7_2;
		find_free_object(&d7_2, &a6);
		if ((uint8_t)d7_2 != 0u)
			d7_2 = billboard_start_soldier(d0, d7_2, a0, a6);
	}
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->height_speed = 0x480;
	OBJECT(a0)->y -= 0x1000u;
	OBJECT(a0)->x += 0x1000u;
	stats = billboard_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_014812;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the billboard falls to the ground with a crash */
uint32_t billboard_fall(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint16_t height = 0;

	d7_2 = (d7 & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	height = OBJECT(a0)->height;
	OBJECT(a0)->height = height - d7_2;
	if ((uint16_t)d7_2 <= height)
		return d7_2;
	OBJECT(a0)->height = 0u;
	d7_2 = (d7_2 & ~0xFFu) | 0x3Eu;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->flags &= ~4u;
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the fallen billboard stays in the background */
uint32_t billboard_land(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x18854u;
	d7 &= ~0xFFFFu;
	draw_tile_block((uint16_t)d7, a6);
	remove_object(a0);
	return d7;
}

/* a Foot soldier on the billboard, counted as an enemy */
uint32_t billboard_start_soldier(uint8_t d0, uint32_t d7, uint32_t a0, uint32_t soldier)
{
	uint32_t d7_2 = 0;

	OBJECT(soldier)->flags = 1u;
	OBJECT(soldier)->contacts = 0u;
	OBJECT(soldier)->kind = 0x2Au;
	OBJECT(soldier)->parameter = 0u;
	OBJECT(soldier)->colour = 6u;
	OBJECT(soldier)->animation_delay = 0u;
	place_at_object(a0, soldier);
	d7_2 = (d7 & ~0xFFFFu) | 0x2000u;
	if (d0 != 0u)
		d7_2 = (int16_t)~d7_2;
	OBJECT(soldier)->x += d7_2;
	OBJECT(soldier)->y += 0x100u;
	OBJECT(soldier)->billboard_soldier.flipped = 0u;
	if (d0 != 0u)
		OBJECT(soldier)->billboard_soldier.flipped |= 0x80u;
	enemies_on_screen++;
	OBJECT(soldier)->routine = 0u;
	OBJECT(soldier)->state = 0u;
	return d7_2;
}

/* the soldier crouches on the billboard */
void billboard_soldier_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags = 0x81u;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	if ((int8_t)OBJECT(a0)->billboard_soldier.flipped < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->billboard_soldier.timer = 0x28u;
	animation = rom_014860;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the soldier jumps */
void billboard_soldier_wait(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->billboard_soldier.timer;
	OBJECT(a0)->billboard_soldier.timer = timer - 1u;
	if (timer == 1u)
	{
		animation = rom_014864;
		set_animation(0u, a0, animation);
		OBJECT(a0)->y_speed = 0x100;
		OBJECT(a0)->height_speed = 0x400;
		OBJECT(a0)->routine++;
		return;
	}
}

/* the soldier comes down to the ground and lands */
uint32_t billboard_soldier_jump_down(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0, y_speed = 0;
	uint16_t height = 0;

	y_speed = OBJECT(a0)->y_speed;
	OBJECT(a0)->y -= y_speed;
	d7 = (y_speed & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	height = OBJECT(a0)->height;
	OBJECT(a0)->height = height - d7;
	if (height < (uint16_t)d7)
	{
		animation = rom_014868;
		set_animation(0u, a0, animation);
		OBJECT(a0)->height = 0u;
		OBJECT(a0)->billboard_soldier.timer = 0x14u;
		OBJECT(a0)->routine++;
	}
	return d7;
}

/* the soldier goes on as a Foot soldier with a boomerang */
void billboard_soldier_become_boomerang_soldier(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->billboard_soldier.timer;
	OBJECT(a0)->billboard_soldier.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->flags = 0x81u;
		OBJECT(a0)->contacts = 0u;
		OBJECT(a0)->kind = 0xBu;
		OBJECT(a0)->parameter = 0u;
		OBJECT(a0)->routine = 0u;
		OBJECT(a0)->state = 0u;
		enemies_on_screen--;
		return;
	}
}

/* an oil drum with three bars */
void oil_drum_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x82u;
	stats = oil_drum_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_01488A;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the drum, or its wreck, stays until it leaves the screen */
void oil_drum_stay(uint32_t a0)
{
	remove_if_off_screen(a0);
}

/* the drum blows up, knocking flying what is near */
uint32_t oil_drum_blow_up(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, object = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->oil_drum.timer;
	OBJECT(a0)->oil_drum.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->routine++;
		OBJECT(a0)->oil_drum.timer = 0x1Eu;
		animation = rom_014896;
		set_animation(0u, a0, animation);
		object = OBJECT_ADDRESS(4);
		d7 = (d7 & ~0xFFu) | 8u;
		d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
		find_free_object(&d7, &object);
		if ((uint8_t)d7 == 0u)
			return d7;
		OBJECT(object)->flags = 5u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->kind = 0x33u;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		place_at_object(a0, object);
		OBJECT(object)->y -= 0x200u;
		OBJECT(object)->unk_2F = 0u;
		OBJECT(object)->routine = 0u;
		OBJECT(object)->state = 0u;
		d7_2 = (d7 & ~0xFFu) | 0x13u;
		queue_sound((uint8_t)d7_2, object);
		return d7_2;
	}
	return d7;
}

/* the burnt wreck of the drum is left */
void oil_drum_become_wreck(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->oil_drum.timer;
	OBJECT(a0)->oil_drum.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->flags &= ~6u;
		stats = oil_drum_stats_ADDRESS;
		set_object_stats(a0, stats);
		animation = rom_01489A;
		set_animation(0u, a0, animation);
		OBJECT(a0)->kind = 0x2Du;
		OBJECT(a0)->parameter = 0u;
		OBJECT(a0)->routine = 0u;
		OBJECT(a0)->state = 0u;
	}
}

/* a turtle's hit makes the drum flash, or lights its fuse */
uint32_t oil_drum_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	if (OBJECT(a0)->health_bars == 0u)
	{
		d7_2 = (d7 & ~0xFFu) | 5u;
		queue_sound((uint8_t)d7_2, 0u);
		animation = rom_014892;
		set_animation(0u, a0, animation);
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->oil_drum.timer = 0x3Cu;
		OBJECT(a0)->flags &= ~6u;
		return d7_2;
	}
	OBJECT(a0)->health = 1u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->oil_drum.timer = 0x28u;
	OBJECT(a0)->flags &= ~2u;
	d7_2 = (d7 & ~0xFFu) | 5u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_01488E;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the drum can be hit again */
void oil_drum_recover(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->oil_drum.timer;
	OBJECT(a0)->oil_drum.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->health = 1u;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->flags |= 2u;
	}
}

/* a gun on a tall column, with four bars */
uint32_t turret_start(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->shadow = 0x16660u;
	stats = turret_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_014A26;
	set_animation(0u, a0, animation);
	if ((int8_t)OBJECT(a0)->parameter < 0)
		OBJECT(a0)->flags |= 0x40u;
	d7 = turret_random_wait(a0);
	OBJECT(a0)->turret.phase = 0u;
	OBJECT(a0)->routine++;
	return d7;
}

/* the turret slides, waiting to fire */
uint32_t turret_move(uint32_t a0)
{
	uint32_t d7 = 0;
	uint8_t timer = 0;

	d7 = turret_slide(a0);
	timer = OBJECT(a0)->turret.timer;
	OBJECT(a0)->turret.timer = timer - 1u;
	if (timer == 0u)
	{
		OBJECT(a0)->turret.timer = 0u;
		OBJECT(a0)->turret.shots_left = 4u;
		OBJECT(a0)->routine++;
		return d7;
	}
	return d7;
}

/* the turret slides and fires a burst of four shots */
uint32_t turret_fire(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;
	uint8_t timer = 0, shots_left = 0;

	d7 = turret_slide(a0);
	timer = OBJECT(a0)->turret.timer;
	OBJECT(a0)->turret.timer = timer - 1u;
	if (timer != 0u)
		return d7;
	shots_left = OBJECT(a0)->turret.shots_left;
	OBJECT(a0)->turret.shots_left = shots_left - 1u;
	if (shots_left != 0u)
	{
		a6 = OBJECT_ADDRESS(32);
		d7 = (d7 & ~0xFFu) | 8u;
		d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
		find_free_object(&d7, &a6);
		if ((uint8_t)d7 != 0u)
		{
			turret_start_shot(a0, a6);
			OBJECT(a0)->turret.timer = 3u;
			return d7;
		}
	}
	OBJECT(a0)->routine--;
	d7 = turret_random_wait(a0);
	OBJECT(a0)->turret.shots_left = 0u;
	return d7;
}

/* the destroyed turret's explosions */
void turret_wreck(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d7 = OBJECT(a0)->state;
	*p_d7 = (uint16_t)(*p_d7 << 2);
	switch (*p_d7)
	{
	case 0:
		turret_wreck_explode(a0, p_d7, p_a5);
		return;
	case 4:
		turret_wreck_next(a0);
		return;
	case 8:
		turret_wreck_stay(a0);
		return;
	}
}

/* an explosion on the destroyed turret's column */
void turret_wreck_explode(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	OBJECT(a0)->turret.timer = 4u;
	OBJECT(a0)->state++;
	a6 = OBJECT_ADDRESS(24);
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (uint8_t)d7_2;
	find_free_object(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
	{
		d6 = 0u;
		*p_a5 = rom_010EAE_ADDRESS;
		d7_2 = rom_010EAE[OBJECT(a0)->turret.phase];
		start_small_explosion(d6, d7_2, a0, a6);
		d7_2 = OBJECT(a0)->turret.phase;
		d7_2 = d7_2 & 3u;
		d7_2 = indexed_table_of_8_bit_values_010EAA[d7_2];
		queue_sound((uint8_t)d7_2, a6);
	}
	else
		OBJECT(a0)->state = 2u;
	*p_d7 = d7_2;
}

/* the next explosion, higher up, until seven */
void turret_wreck_next(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->turret.timer;
	OBJECT(a0)->turret.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->state--;
		OBJECT(a0)->turret.phase++;
		if (OBJECT(a0)->turret.phase == 7u)
			OBJECT(a0)->state = 2u;
	}
}

/* the wreck stays until it leaves the screen */
void turret_wreck_stay(uint32_t a0)
{
	remove_if_off_screen(a0);
}

/* a turtle's hit makes the turret flash, or destroys it */
uint32_t turret_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	if (OBJECT(a0)->health_bars == 0u)
	{
		stats = turret_struck_stats_ADDRESS;
		set_object_stats(a0, stats);
		animation = rom_014A2E;
		set_animation(0u, a0, animation);
		OBJECT(a0)->routine = 3u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->turret.phase = 0u;
		OBJECT(a0)->flags &= ~6u;
		return d7;
	}
	OBJECT(a0)->health = 1u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->turret.timer = 0x28u;
	OBJECT(a0)->flags &= ~2u;
	d7_2 = (d7 & ~0xFFu) | 5u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_014A2A;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the turret can be hit again */
uint32_t turret_recover(uint32_t a0)
{
	uint32_t d7 = 0;
	uint8_t timer = 0;

	d7 = turret_slide(a0);
	timer = OBJECT(a0)->turret.timer;
	OBJECT(a0)->turret.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->health = 1u;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->flags |= 2u;
	}
	return d7;
}

/* the turret slides back and forth in depth */
uint32_t turret_slide(uint32_t a0)
{
	uint16_t d7_2 = 0;
	uint32_t a6 = 0, d6 = 0, d7 = 0;

	remove_if_off_screen(a0);
	d7 = OBJECT(a0)->parameter & 3u;
	a6 = table_loaded_by_lea_010776_ADDRESS + (uint16_t)(d7 << 3);
	d7_2 = OBJECT(a0)->turret.phase;
	d7_2 = (uint16_t)((d7_2 & 1u) << 2);
	d6 = (int16_t)DATA16(a6 + d7_2);
	d7 = (int16_t)DATA16(a6 + 2u + d7_2);
	OBJECT(a0)->x += d6;
	OBJECT(a0)->y += d7;
	if ((OBJECT(a0)->parameter & 0x40u) != 0u)
	{
		if (OBJECT(a0)->y >= 0x7000u || OBJECT(a0)->y < reset_ADDRESS)
			OBJECT(a0)->turret.phase ^= 1u;
	}
	else if (OBJECT(a0)->y >= 0x7000u || OBJECT(a0)->y < reset_ADDRESS)
	{
		OBJECT(a0)->turret.phase ^= 1u;
		return d7;
	}
	return d7;
}

/* how long the turret waits before its next burst, at random */
uint32_t turret_random_wait(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 4u;
	d7 = random_below((uint16_t)d7, a0);
	OBJECT(a0)->turret.timer = indexed_table_of_8_bit_values_0107AE[d7];
	return d7;
}

/* a shot from the turret's gun */
void turret_start_shot(uint32_t a0, uint32_t shot)
{
	OBJECT(shot)->flags = 1u;
	OBJECT(shot)->contacts = 0u;
	OBJECT(shot)->kind = 0x2Cu;
	OBJECT(shot)->parameter = 0u;
	OBJECT(shot)->colour = 0xFFu;
	OBJECT(shot)->animation_delay = 0u;
	place_at_object(a0, shot);
	OBJECT(shot)->routine = 0u;
	OBJECT(shot)->state = 0u;
	OBJECT(shot)->height += 0x800u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		OBJECT(shot)->turret_shot.flipped = 1u;
		OBJECT(shot)->x += 0x2000u;
		return;
	}
	OBJECT(shot)->turret_shot.flipped = 0u;
	OBJECT(shot)->x -= 0x2000u;
}

/* the turret's shot flies the way the turret faces, knocking turtles down */
uint32_t turret_shot_start(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags = 0x85u;
	OBJECT(a0)->contacts |= 0x80u;
	a6 = 0x16668u;
	if (stage == 8u)
		a6 = 0x16670u;
	OBJECT(a0)->shadow = a6;
	stats = turret_shot_stats_ADDRESS;
	set_object_stats(a0, stats);
	d7_2 = (d7 & ~0xFFFFu) | 0xF800u;
	OBJECT(a0)->flags &= 0xBFu;
	if (OBJECT(a0)->turret_shot.flipped != 0u)
	{
		d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)~d7_2;
		OBJECT(a0)->flags |= 0x40u;
	}
	OBJECT(a0)->x_speed = d7_2;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	animation = rom_014AA2;
	set_animation(0u, a0, animation);
	d7_2 = (d7_2 & ~0xFFu) | 0xBu;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the shot flies until it hits or leaves the screen */
uint32_t turret_shot_fly(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, x_speed = 0;

	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		remove_object(a0);
		return d7;
	}
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		OBJECT(a0)->routine++;
		OBJECT(a0)->contacts &= 0x7Fu;
		animation = rom_014AA6;
		set_animation(0u, a0, animation);
		return d7;
	}
	x_speed = OBJECT(a0)->x_speed;
	OBJECT(a0)->x += x_speed;
	return x_speed;
}

/* the shot's burst ends and it is gone */
void turret_shot_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		remove_object(a0);
		return;
	}
}

/* a Foot soldier standing with his back turned */
void waiting_soldier_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->colour = 7u;
	OBJECT(a0)->animation_delay = 0u;
	stats = waiting_soldier_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->routine++;
	animation = rom_0156FE;
	set_animation(0u, a0, animation);
}

/* the soldier waits until he is well on the screen */
void waiting_soldier_wait(uint32_t a0)
{
	if (OBJECT(a0)->screen_x < 0x140u)
	{
		waiting_soldier_become_knife_soldier(a0);
		return;
	}
	remove_if_off_screen(a0);
}

/* the soldier goes on as a Foot soldier with knives */
void waiting_soldier_become_knife_soldier(uint32_t a0)
{
	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->contacts = 0u;
	OBJECT(a0)->kind = 3u;
	OBJECT(a0)->parameter = 0u;
	OBJECT(a0)->routine = 0u;
	OBJECT(a0)->state = 0u;
}

/* a ONE WAY sign on a pole */
void one_way_sign_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x82u;
	stats = one_way_sign_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_015B36;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the sign stays until it leaves the screen */
void one_way_sign_stay(uint32_t a0)
{
	remove_if_off_screen(a0);
}

/* the sign spins, knocking flying what it hits, until it stops */
void one_way_sign_spin(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
	{
		one_way_sign_idle();
		return;
	}
	OBJECT(a0)->flags &= ~4u;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->routine--;
	one_way_sign_idle();
}

/* nothing */
void one_way_sign_idle(void)
{
}

/* a turtle's hit sets the sign spinning */
uint32_t one_way_sign_struck(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	a6 = rom_015B36_ADDRESS;
	if ((int8_t)OBJECT(a0)->hit < 0)
	{
		OBJECT(a0)->attack &= 0x7Fu;
		a6 += 4u;
	}
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	animation = DATA32(a6 + 4u);
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 5u;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->health_bars = 0x10u;
	OBJECT(a0)->health = 1u;
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->flags &= ~2u;
	return d7_2;
}

/* the marks of a row of nozzles in the Technodrome's floor */
void nozzle_row_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_0156F0;
	set_animation(0u, a0, animation);
	OBJECT(a0)->nozzle_row.nozzle_status = 0u;
	OBJECT(a0)->routine++;
}

/* the row watches for turtles, waits for its nozzle, or is done */
void nozzle_row_run(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->nozzle_row.nozzle_status;
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		nozzle_row_watch(a0, &d5, &d7, p_a5);
		break;
	case 4:
		nozzle_row_wait(a0);
		break;
	case 8:
		nozzle_row_done(a0);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

/* a turtle near one of the row's places makes a nozzle come up there */
void nozzle_row_watch(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = 0;
	uint32_t a6 = 0, d0 = 0, d7 = 0, object = 0;
	uint16_t screen_x = 0, screen_x_2 = 0, screen_y = 0, t1 = 0, t2 = 0, t3 = 0;

	remove_if_off_screen(a0);
	a6 = indexed_table_of_32_bit_values_010AB2[OBJECT(a0)->parameter];
	d7 = mem_read8(a6);
	a6++;
	do
	{
		d0 = mem_read8(a6);
		d6 = 3u;
		object = OBJECT_ADDRESS(3);
		a6++;
		do
		{
			if ((players_in_play & shl32(1u, (int)(d6 & 7u))) != 0u && OBJECT(object)->routine != 4u)
			{
				screen_x = OBJECT(object)->screen_x;
				screen_x_2 = OBJECT(a0)->screen_x;
				d5 = (uint16_t)(screen_x_2 - screen_x);
				if (screen_x <= screen_x_2 && d5 < 0x40u)
				{
					screen_y = OBJECT(object)->screen_y;
					t1 = OBJECT(a0)->screen_y - d0;
					d5 = (uint16_t)(t1 - screen_y);
					if (t1 < screen_y)
						d5 = (uint16_t)~d5;
					if (d5 < 8u)
					{
						a6 = OBJECT_ADDRESS(4);
						d7 = (d7 & ~0xFFu) | 8u;
						d7 = (uint8_t)d7;
						find_free_object(&d7, &a6);
						if ((uint8_t)d7 != 0u)
						{
							object = nozzle_row_start_nozzle(d0, a0, a6);
							OBJECT(a0)->nozzle_row.nozzle_status = 1u;
						}
						*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
						*p_d7 = d7;
						*p_a5 = object;
						return;
					}
				}
			}
			t2 = d6 - 1u;
			d6 = t2;
			object -= 0x50u;
		} while (t2 != 0xFFFFu);
		t3 = d7 - 1u;
		d7 = t3;
	} while (t3 != 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d7 = d7;
	*p_a5 = object;
}

/* a nozzle is up */
void nozzle_row_wait(uint32_t a0)
{
	remove_if_off_screen(a0);
}

/* the row's nozzle was broken: no more come up */
void nozzle_row_done(uint32_t a0)
{
	remove_if_off_screen(a0);
}

/* a nozzle at one of the row's places */
uint32_t nozzle_row_start_nozzle(uint32_t d0, uint32_t a0, uint32_t nozzle)
{
	uint32_t a5 = 0;

	OBJECT(nozzle)->flags = 1u;
	OBJECT(nozzle)->contacts = 0u;
	OBJECT(nozzle)->kind = 0x2Eu;
	OBJECT(nozzle)->parameter = 0u;
	OBJECT(nozzle)->colour = 0xFFu;
	OBJECT(nozzle)->animation_delay = 0u;
	place_at_object(a0, nozzle);
	OBJECT(nozzle)->y -= (uint16_t)(d0 << 8);
	a5 = a0 + 0x2Fu;
	OBJECT(nozzle)->freeze_nozzle.row_status = a5;
	OBJECT(nozzle)->unk_2F = 0u;
	OBJECT(nozzle)->routine = 0u;
	OBJECT(nozzle)->state = 0u;
	return a5;
}

/* a nozzle comes up out of the floor */
void freeze_nozzle_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = freeze_nozzle_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_014AD6;
	set_animation(0u, a0, animation);
	OBJECT(a0)->freeze_nozzle.timer = 0x15u;
	OBJECT(a0)->routine++;
}

/* the nozzle is up and can be hit */
void freeze_nozzle_rise(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->freeze_nozzle.timer;
	OBJECT(a0)->freeze_nozzle.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->freeze_nozzle.timer = 0xAu;
		OBJECT(a0)->routine++;
		OBJECT(a0)->state = 0u;
		return;
	}
}

/* the nozzle gets ready, then sprays */
uint32_t freeze_nozzle_spray(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->state;
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		return freeze_nozzle_spray_start(d7, a0);
	case 4:
		freeze_nozzle_spray_stop(a0);
		return d7;
	}
}

/* the nozzle sprays a cloud that freezes turtles in ice */
uint32_t freeze_nozzle_spray_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->freeze_nozzle.timer;
	OBJECT(a0)->freeze_nozzle.timer = timer - 1u;
	if (timer != 1u)
		return d7;
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->freeze_nozzle.timer = 0x3Cu;
	OBJECT(a0)->state++;
	d7_2 = (d7 & ~0xFFu) | 0x1Fu;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_014ADA;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the spray stops and the nozzle sinks */
void freeze_nozzle_spray_stop(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->freeze_nozzle.timer;
	OBJECT(a0)->freeze_nozzle.timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(a0)->flags &= ~6u;
	OBJECT(a0)->freeze_nozzle.timer = 0x15u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->state = 0u;
	animation = rom_014ADE;
	set_animation(0u, a0, animation);
}

/* the nozzle is gone and its row watches again */
void freeze_nozzle_sink(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->freeze_nozzle.timer;
	OBJECT(a0)->freeze_nozzle.timer = timer - 1u;
	if (timer == 1u)
	{
		remove_object(a0);
		mem_write8(OBJECT(a0)->freeze_nozzle.row_status, 0u);
		return;
	}
}

/* a turtle's hit breaks the nozzle in a small explosion */
uint32_t freeze_nozzle_struck(uint32_t d7, uint32_t a0)
{
	uint16_t d6 = 0;
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	OBJECT(a0)->health = 1u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->flags &= ~6u;
	OBJECT(a0)->freeze_nozzle.timer = 0u;
	mem_write8(OBJECT(a0)->freeze_nozzle.row_status, 2u);
	d7_2 = (d7 & ~0xFFu) | 5u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_014AE2;
	set_animation(0u, a0, animation);
	a6 = OBJECT_ADDRESS(24);
	d7_2 = (d7_2 & ~0xFFu) | 8u;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint8_t)d7_2;
	find_free_object(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
	{
		d6 = 0u;
		d7_2 = reset_ADDRESS;
		d7_2 = start_small_explosion(d6, d7_2, a0, a6);
		d7_2 = (d7_2 & ~0xFFu) | 0x11u;
		queue_sound((uint8_t)d7_2, a6);
		return d7_2;
	}
	return d7_2;
}

/* the broken nozzle stays until it leaves the screen */
void freeze_nozzle_broken(uint32_t a0)
{
	remove_if_off_screen(a0);
}

/* an electric beam, off for a while */
void electric_beam_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t stats = 0;

	OBJECT(a0)->flags = 1u;
	stats = electric_beam_stats_ADDRESS;
	set_object_stats(a0, stats);
	*p_a5 = indexed_table_of_8_bit_values_010D5A_ADDRESS;
	*p_d7 = electric_random_wait(a0, *p_a5);
	OBJECT(a0)->routine++;
}

/* the beam comes on and electrocutes turtles */
uint32_t electric_beam_wait(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;
	uint8_t timer = 0;

	remove_if_off_screen(a0);
	if (OBJECT(a0)->flags == 0u)
		return d7;
	timer = OBJECT(a0)->electric.timer;
	OBJECT(a0)->electric.timer = timer - 1u;
	if (timer != 0u)
		return d7;
	OBJECT(a0)->flags |= 0x84u;
	OBJECT(a0)->electric.timer = 0x3Cu;
	OBJECT(a0)->routine++;
	d7_2 = (d7 & ~0xFFFFu) | 0x20u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_014BA0;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the beam stays on a second, then goes off again */
void electric_beam_shine(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t timer = 0;

	remove_if_off_screen(a0);
	if (OBJECT(a0)->flags == 0u)
		return;
	timer = OBJECT(a0)->electric.timer;
	OBJECT(a0)->electric.timer = timer - 1u;
	if (timer == 0u)
	{
		OBJECT(a0)->routine = 0u;
		electric_beam_start(a0, p_d7, p_a5);
		return;
	}
}

/* a spot in the floor that shoots electric columns */
void electric_vent_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t stats = 0;

	OBJECT(a0)->flags = 1u;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	*p_a5 = 0x10D62u;
	*p_d7 = electric_random_wait(a0, *p_a5);
	OBJECT(a0)->routine++;
}

/* now and then the vent shoots an electric column */
void electric_vent_wait(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t timer = 0;

	remove_if_off_screen(a0);
	timer = OBJECT(a0)->electric.timer;
	OBJECT(a0)->electric.timer = timer - 1u;
	if (timer == 0u)
	{
		*p_a5 = 0x10D62u;
		d7_2 = electric_random_wait(a0, *p_a5);
		a6 = OBJECT_ADDRESS(32);
		d7 = (d7_2 & ~0xFFu) | 8u;
		d7 = (uint8_t)d7;
		find_free_object(&d7, &a6);
		if ((uint8_t)d7 != 0u)
		{
			electric_vent_start_column(a0, a6);
			OBJECT(a0)->routine++;
			OBJECT(a0)->electric.column_done = 0u;
		}
	}
	*p_d7 = d7;
}

/* the vent waits for its column to be gone */
void electric_vent_wait_column(uint32_t a0)
{
	if (OBJECT(a0)->electric.column_done != 0u)
	{
		OBJECT(a0)->routine--;
		OBJECT(a0)->electric.column_done = 0u;
	}
}

/* how long the electric hazard waits, at random */
uint32_t electric_random_wait(uint32_t a0, uint32_t a5)
{
	uint32_t d7 = 0;

	d7 = 8u;
	d7 = random_below((uint16_t)d7, a0);
	OBJECT(a0)->electric.timer = mem_read8(a5 + d7);
	return d7;
}

/* an electric column at the vent */
void electric_vent_start_column(uint32_t a0, uint32_t column)
{
	OBJECT(column)->flags = 1u;
	OBJECT(column)->contacts = 0u;
	OBJECT(column)->kind = 0x3Au;
	OBJECT(column)->parameter = 0u;
	OBJECT(column)->colour = 0xFFu;
	OBJECT(column)->animation_delay = 0u;
	place_at_object(a0, column);
	OBJECT(column)->y -= 0x1000u;
	OBJECT(column)->electric.vent = a0;
	OBJECT(column)->electric.column_done = 0u;
	OBJECT(column)->routine = 0u;
	OBJECT(column)->state = 0u;
}

/* an electric column shoots up out of the floor, electrocuting turtles */
uint32_t electric_column_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x84u;
	stats = electric_column_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_0150E8;
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 0x1Bu;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the column is up */
void electric_column_rise(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->electric.timer = 0x30u;
		OBJECT(a0)->routine++;
	}
}

/* the column blinks a while, then goes */
uint32_t electric_column_flicker(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t timer = 0;

	d7 = electric_column_blink(d7, a0);
	timer = OBJECT(a0)->electric.timer;
	OBJECT(a0)->electric.timer = timer - 1u;
	if (timer == 0u)
	{
		animation = rom_0150EC;
		set_animation(0u, a0, animation);
		OBJECT(a0)->routine++;
		OBJECT(a0)->flags |= 0x80u;
	}
	return d7;
}

/* the column goes on up out of sight and tells its vent */
void electric_column_leave(uint32_t a0)
{
	uint32_t vent = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		vent = OBJECT(a0)->electric.vent;
		OBJECT(vent)->electric.column_done = 1u;
		remove_object(a0);
		return;
	}
	OBJECT(a0)->y -= 0x1000u;
}

/* the column shows on every other frame */
uint32_t electric_column_blink(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	OBJECT(a0)->flags |= 0x80u;
	d7_2 = (d7 & ~0xFFu) | (uint8_t)frame_count;
	if ((d7_2 & 1u) == 0u)
		OBJECT(a0)->flags &= 0x7Fu;
	return d7_2;
}

/* Unused: a slanted grille */
void grille_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->routine++;
	unused_grille = a0;
	animation = rom_01519C;
	set_animation(0u, a0, animation);
}

/* Unused: nothing */
void grille_idle(void)
{
}

/* a spiked pole hangs over the sewer */
void spiked_pole_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	if ((OBJECT(a0)->parameter & 1u) != 0u)
		OBJECT(a0)->flags |= 4u;
	stats = spiked_pole_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	spiked_poles_phase = 0u;
	animation = rom_015838;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the first pole on the screen starts the row dropping */
uint32_t spiked_pole_wait(uint32_t d7, uint32_t a0)
{
	d7 = spiked_pole_swap_hurting(d7, a0);
	if ((int8_t)OBJECT(a0)->parameter < 0 && OBJECT(a0)->screen_x < 0x160u)
		spiked_poles_phase = 1u;
	if (spiked_poles_phase == 1u)
	{
		OBJECT(a0)->routine++;
		OBJECT(a0)->spiked_pole.timer = 0xAu;
	}
	return d7;
}

/* the poles wait up a while, then drop */
uint32_t spiked_pole_hold_up(uint32_t d7, uint32_t a0)
{
	uint8_t timer = 0;

	d7 = spiked_pole_swap_hurting(d7, a0);
	if (OBJECT(a0)->parameter != 0u)
	{
		timer = OBJECT(a0)->spiked_pole.timer;
		OBJECT(a0)->spiked_pole.timer = timer - 1u;
		if (timer == 0u)
			spiked_poles_phase = 2u;
	}
	if (spiked_poles_phase == 2u)
	{
		OBJECT(a0)->height_speed = 0x600;
		OBJECT(a0)->routine++;
	}
	remove_if_off_screen(a0);
	return d7;
}

/* the pole drops to just over the floor */
uint32_t spiked_pole_drop(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7 = spiked_pole_swap_hurting(d7, a0);
	d7_2 = (d7 & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	OBJECT(a0)->height -= d7_2;
	if (OBJECT(a0)->height < 0x1800u)
	{
		OBJECT(a0)->height = 0x1800u;
		OBJECT(a0)->routine++;
		if (OBJECT(a0)->parameter != 0u)
		{
			OBJECT(a0)->spiked_pole.timer = 0x28u;
			spiked_poles_phase = 3u;
			d7_2 = (d7_2 & ~0xFFu) | 0x24u;
			queue_sound((uint8_t)d7_2, 0u);
		}
	}
	return d7_2;
}

/* the poles wait down a while, then rise */
uint32_t spiked_pole_hold_down(uint32_t d7, uint32_t a0)
{
	uint8_t timer = 0;

	d7 = spiked_pole_swap_hurting(d7, a0);
	if (OBJECT(a0)->parameter != 0u)
	{
		timer = OBJECT(a0)->spiked_pole.timer;
		OBJECT(a0)->spiked_pole.timer = timer - 1u;
		if (timer == 0u)
			spiked_poles_phase = 4u;
	}
	if (spiked_poles_phase == 4u)
	{
		OBJECT(a0)->height_speed = 0x300;
		OBJECT(a0)->routine++;
	}
	remove_if_off_screen(a0);
	return d7;
}

/* the pole rises back up */
uint32_t spiked_pole_rise(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7 = spiked_pole_swap_hurting(d7, a0);
	d7_2 = (d7 & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	OBJECT(a0)->height += d7_2;
	if (OBJECT(a0)->height >= 0x8000u)
	{
		OBJECT(a0)->height = 0x8000u;
		OBJECT(a0)->routine = 2u;
		if (OBJECT(a0)->parameter != 0u)
		{
			OBJECT(a0)->spiked_pole.timer = 0x1Eu;
			spiked_poles_phase = 0u;
		}
	}
	return d7_2;
}

/* the poles that hurt and the ones that do not swap now and then */
uint32_t spiked_pole_swap_hurting(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)frame_count;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
		OBJECT(a0)->flags ^= 4u;
	return d7_2;
}

/* something lies hidden under the sewer's water */
void sewer_launcher_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags &= 0x7Fu;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->sewer_launcher.delay = 0x28u;
	OBJECT(a0)->sewer_launcher.missiles_left = 0xCu;
	animation = rom_0157A0;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
	OBJECT(a0)->sewer_launcher.drift = 0u;
}

/* it drifts under the water; with a turtle in line, a missile leaps out at it */
void sewer_launcher_wait(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint8_t d0 = 0;
	uint32_t a6 = 0, animation = 0;

	remove_if_off_screen(a0);
	if (OBJECT(a0)->flags == 0u)
		sewer_launcher_remove(a0);
	else
	{
		d7 = sewer_launcher_drift(a0);
		if (OBJECT(a0)->sewer_launcher.delay != 0u)
		{
			OBJECT(a0)->sewer_launcher.delay--;
			remove_if_off_screen(a0);
		}
		else
		{
			sewer_launcher_find_turtle(a0, &d5, &d7);
			if ((uint8_t)d7 != 0u)
			{
				d0 = (uint8_t)d7;
				a6 = OBJECT_ADDRESS(32);
				d7 = (d7 & ~0xFFu) | 8u;
				d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
				find_free_object(&d7, &a6);
				if ((uint8_t)d7 != 0u)
				{
					sewer_launcher_start_missile(d0, a0, a6);
					OBJECT(a0)->routine++;
					OBJECT(a0)->flags |= 0x80u;
					animation = rom_0157A4;
					set_animation(0u, a0, animation);
				}
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

/* its ripples end and it hides a while; out of missiles, it is gone */
void sewer_launcher_fired(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t missiles_left = 0;

	remove_if_off_screen(a0);
	if (OBJECT(a0)->flags == 0u)
	{
		sewer_launcher_remove(a0);
		return;
	}
	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->flags &= 0x7Fu;
	OBJECT(a0)->sewer_launcher.delay = 0x64u;
	OBJECT(a0)->routine--;
	missiles_left = OBJECT(a0)->sewer_launcher.missiles_left;
	OBJECT(a0)->sewer_launcher.missiles_left = missiles_left - 1u;
	if (missiles_left == 0u)
	{
		sewer_launcher_remove(a0);
		return;
	}
	animation = rom_0157A0;
	set_animation(0u, a0, animation);
}

/* the launcher is gone */
void sewer_launcher_remove(uint32_t a0)
{
	remove_object(a0);
}

/* it drifts up and down the screen under the water */
uint32_t sewer_launcher_drift(uint32_t a0)
{
	uint16_t d7 = 0;
	uint32_t d6 = 0, d7_2 = 0;

	d7 = OBJECT(a0)->sewer_launcher.drift;
	d7 = (uint16_t)((d7 & 1u) << 2);
	d6 = (int16_t)indexed_table_of_16_bit_values_0113BE[d7 / 2u];
	d7_2 = (int16_t)rom_0113C0[d7 / 2u];
	OBJECT(a0)->x += d6;
	OBJECT(a0)->y += d7_2;
	if (OBJECT(a0)->y >= 0x4000u || OBJECT(a0)->y < 0x800u)
		OBJECT(a0)->sewer_launcher.drift ^= 1u;
	return d7_2;
}

/* which turtle is in line with it across the water, far enough */
void sewer_launcher_find_turtle(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = 0;
	uint32_t d7 = 0, object = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	object = OBJECT_ADDRESS(3);
	d6 = 3u;
	do
	{
		if ((players_in_play & shl32(1u, (int)(d6 & 7u))) != 0u && (players_knocked_out & shl32(1u, (int)(d6 & 7u))) == 0u && OBJECT(object)->routine != 4u)
		{
			t1 = OBJECT(object)->screen_y - OBJECT(a0)->screen_y;
			d5 = t1;
			if ((int16_t)t1 < 0)
				d5 = (uint16_t)~d5;
			if (d5 < 4u)
			{
				d7 = 0u;
				t2 = OBJECT(object)->screen_x - OBJECT(a0)->screen_x;
				d5 = t2;
				if ((int16_t)t2 < 0)
				{
					d5 = (uint16_t)~d5;
					d7 = 0x80u;
				}
				if (d5 >= 0x30u)
				{
					d7 |= shl32(1u, (int)(d6 & 0x1Fu));
					break;
				}
			}
		}
		d7 = 0u;
		t3 = d6 - 1u;
		d6 = t3;
		object -= 0x50u;
	} while (t3 != 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d7 = d7;
}

/* a missile leaps out at the turtle */
void sewer_launcher_start_missile(uint8_t d0, uint32_t a0, uint32_t missile)
{
	OBJECT(missile)->flags = 1u;
	OBJECT(missile)->contacts = 0u;
	OBJECT(missile)->kind = 0x50u;
	OBJECT(missile)->parameter = 0u;
	OBJECT(missile)->colour = 0xFFu;
	OBJECT(missile)->animation_delay = 0u;
	place_at_object(a0, missile);
	OBJECT(missile)->routine = 0u;
	OBJECT(missile)->state = 0u;
	OBJECT(missile)->sewer_missile.goes_right = 0u;
	if ((int8_t)d0 >= 0)
	{
		OBJECT(missile)->sewer_missile.goes_right = 1u;
		OBJECT(missile)->flags |= 0x40u;
	}
}

/* the missile rises out of the water */
uint32_t sewer_missile_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x86u;
	stats = sewer_missile_stats_ADDRESS;
	set_object_stats(a0, stats);
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->attack |= 0x80u;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0x200;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->routine++;
	animation = rom_01579C;
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 0xEu;
	queue_sound((uint8_t)d7_2, animation);
	return d7_2;
}

/* the missile rises, then flies at the turtle */
uint32_t sewer_missile_rise(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = move_by_speeds(a0);
	if (OBJECT(a0)->height < 0x2000u)
		return d7;
	OBJECT(a0)->routine++;
	d7 = (d7 & ~0xFFFFu) | 0xFB80u;
	if (OBJECT(a0)->sewer_missile.goes_right != 0u)
		d7 = (d7 & ~0xFFFFu) | (uint16_t)~d7;
	OBJECT(a0)->x_speed = d7;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	return d7;
}

/* the missile flies across until it leaves the screen */
uint32_t sewer_missile_fly(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = move_by_speeds(a0);
	remove_if_off_screen(a0);
	return d7;
}

/* the missile is gone */
void sewer_missile_remove(uint32_t a0)
{
	remove_object(a0);
}

/* a turtle's attack bursts the missile */
uint32_t sewer_missile_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	OBJECT(a0)->flags &= ~4u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->routine++;
	d7_2 = (d7 & ~0xFFu) | 0xFu;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_014C3A;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the missile's burst ends and it is gone */
void sewer_missile_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		remove_object(a0);
		return;
	}
}

/* the car's spot shows a piece of wall; the car's picture will go into the layer */
void parked_car_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_015042;
	set_animation(0u, a0, animation);
	OBJECT(a0)->parked_car.scroll_x = 0u;
	OBJECT(a0)->parked_car.scroll_y = 0u;
	OBJECT(a0)->parked_car.blank_row = TILE_RAM + 0x2F80u;
	parked_car_set_scroll(a0);
	OBJECT(a0)->unk_2F = 0u;
	OBJECT(a0)->routine++;
}

/* the parked car is drawn into the layer, where the object is */
uint32_t parked_car_draw(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	OBJECT(a0)->parked_car.last_screen_x = OBJECT(a0)->screen_x;
	d7 = parked_car_follow_object(d7, a0);
	a6 = 0x18C28u;
	d7_2 = (d7 & ~0xFFFFu) | 5u;
	draw_tile_block((uint16_t)d7_2, a6);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the car waits until it is well on the screen */
uint32_t parked_car_wait(uint32_t d7, uint32_t a0)
{
	d7 = parked_car_follow_object(d7, a0);
	if (OBJECT(a0)->screen_x < 0xE0u)
	{
		OBJECT(a0)->parked_car.counter = 0xAu;
		OBJECT(a0)->routine++;
		OBJECT(a0)->state = 0u;
	}
	return d7;
}

/* after a moment the car's three unseen hit boxes start */
void parked_car_start_drive(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a6 = 0;
	uint8_t counter = 0;
	uint16_t t1 = 0;

	d7 = parked_car_follow_object(d7, a0);
	counter = OBJECT(a0)->parked_car.counter;
	OBJECT(a0)->parked_car.counter = counter - 1u;
	if (counter == 1u)
	{
		d0 = 2u;
		do
		{
			a6 = OBJECT_ADDRESS(4);
			d7 = (d7 & ~0xFFu) | 8u;
			d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
			find_free_object(&d7, &a6);
			if ((uint8_t)d7 == 0u)
				break;
			parked_car_start_hit_box(d0, a0, a6, &d7, p_a5);
			t1 = d0 - 1u;
			d0 = t1;
		} while (t1 != 0xFFFFu);
		OBJECT(a0)->parked_car.counter = 0u;
		OBJECT(a0)->routine++;
		OBJECT(a0)->state = 0u;
	}
	*p_d7 = d7;
}

/* the car drives off to the front right, its picture blanked row by row as it goes */
uint32_t parked_car_drive_off(uint32_t d7, uint32_t a0)
{
	OBJECT(a0)->parked_car.counter++;
	if (OBJECT(a0)->parked_car.counter >= 0x38u)
	{
		OBJECT(a0)->parked_car.counter = 3u;
		if (turtles_in_play >= 2u)
			OBJECT(a0)->parked_car.counter = 4u;
		OBJECT(a0)->parked_car.soldier_time = 0u;
		OBJECT(a0)->routine++;
		OBJECT(a0)->state = 0u;
		return d7;
	}
	if ((OBJECT(a0)->parked_car.counter & 1u) == 0u)
		parked_car_blank_row(a0);
	OBJECT(a0)->parked_car.scroll_x -= 4u;
	OBJECT(a0)->parked_car.scroll_x &= 0x1FFu;
	OBJECT(a0)->parked_car.scroll_y = (OBJECT(a0)->parked_car.scroll_y & 0xFF00u) | ((uint8_t)OBJECT(a0)->parked_car.scroll_y - 4u & 0xFFu);
	d7 = parked_car_follow_object(d7, a0);
	return d7;
}

/* Foot soldiers leap out one after another, then the car's spot is gone */
uint32_t parked_car_release_soldiers(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t soldier_time = 0, counter = 0;

	soldier_time = OBJECT(a0)->parked_car.soldier_time;
	OBJECT(a0)->parked_car.soldier_time = soldier_time - 1u;
	if (soldier_time != 0u)
		return d7;
	counter = OBJECT(a0)->parked_car.counter;
	OBJECT(a0)->parked_car.counter = counter - 1u;
	if (counter != 0u)
	{
		a6 = OBJECT_ADDRESS(12);
		d7 = (d7 & ~0xFFu) | 0xCu;
		d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
		find_free_object(&d7, &a6);
		if ((uint8_t)d7 != 0u)
		{
			parked_car_start_soldier(a0, a6);
			OBJECT(a0)->parked_car.soldier_time = 8u;
			return d7;
		}
	}
	remove_object(a0);
	return d7;
}

/* the car's picture keeps with the object as the screen scrolls */
uint32_t parked_car_follow_object(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | OBJECT(a0)->parked_car.last_screen_x;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 - OBJECT(a0)->screen_x);
	OBJECT(a0)->parked_car.last_screen_x = OBJECT(a0)->screen_x;
	OBJECT(a0)->parked_car.scroll_x += d7_2;
	OBJECT(a0)->parked_car.scroll_x &= 0x1FFu;
	parked_car_set_scroll(a0);
	return d7_2;
}

/* the layer's scroll for the car's picture */
void parked_car_set_scroll(uint32_t a0)
{
	layer_a_scroll_x = OBJECT(a0)->parked_car.scroll_x;
	layer_a_scroll_y = OBJECT(a0)->parked_car.scroll_y;
}

/* a row of the layer blanked, then the one above next time */
void parked_car_blank_row(uint32_t a0)
{
	uint16_t d6 = 0, d7 = 0;
	uint32_t blank_row = 0;
	uint16_t t1 = 0;

	blank_row = OBJECT(a0)->parked_car.blank_row;
	d6 = 0x3Fu;
	d7 = 0u;
	do
	{
		mem_write8(blank_row + (int16_t)d7, 0u);
		mem_write8(blank_row + 1u + (int16_t)d7, 0x10u);
		d7 += 2u;
		t1 = d6 - 1u;
		d6 = t1;
	} while (t1 != 0xFFFFu);
	OBJECT(a0)->parked_car.blank_row = (OBJECT(a0)->parked_car.blank_row & 0xFFFF0000u) | ((uint16_t)OBJECT(a0)->parked_car.blank_row - 0x80u & 0xFFFFu);
}

/* an unseen hit box along the car's body */
void parked_car_start_hit_box(uint16_t d0, uint32_t a0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a5 = 0, d7 = 0;

	OBJECT(a6)->flags = 1u;
	OBJECT(a6)->contacts = 0u;
	OBJECT(a6)->kind = 0x36u;
	OBJECT(a6)->parameter = 0u;
	OBJECT(a6)->colour = 0xFFu;
	OBJECT(a6)->animation_delay = 0u;
	place_at_object(a0, a6);
	d7 = d0;
	a5 = table_loaded_by_lea_012C10_ADDRESS + (uint16_t)(d7 << 2);
	OBJECT(a6)->x += (int16_t)DATA16(a5);
	d7 = (int16_t)DATA16(a5 + 2u);
	OBJECT(a6)->y += d7;
	OBJECT(a6)->unk_2F = 0u;
	OBJECT(a6)->routine = 0u;
	OBJECT(a6)->state = 0u;
	*p_d7 = d7;
	*p_a5 = a5;
}

/* an unseen box that knocks flying the turtles in the car's way */
uint32_t car_hit_box_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags = 5u;
	stats = car_hit_box_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->x_speed = 0x400;
	OBJECT(a0)->y_speed = 0x400;
	OBJECT(a0)->height_speed = 0;
	animation = rom_015046;
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 0x3Au;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the box goes with the car until it is off the screen */
uint32_t car_hit_box_move(uint32_t d7, uint32_t a0)
{
	uint32_t x_speed = 0, y_speed = 0;

	if (OBJECT(a0)->screen_x < 0x10u)
	{
		remove_object(a0);
		return d7;
	}
	x_speed = (uint16_t)OBJECT(a0)->x_speed;
	OBJECT(a0)->x += x_speed;
	y_speed = (uint16_t)OBJECT(a0)->y_speed;
	OBJECT(a0)->y -= y_speed;
	return y_speed;
}

/* a Foot soldier where the car stood */
void parked_car_start_soldier(uint32_t a0, uint32_t soldier)
{
	OBJECT(soldier)->flags = 1u;
	OBJECT(soldier)->contacts = 0u;
	OBJECT(soldier)->kind = 0x38u;
	OBJECT(soldier)->parameter = 0u;
	OBJECT(soldier)->colour = 5u;
	OBJECT(soldier)->animation_delay = 0u;
	place_at_object(a0, soldier);
	OBJECT(soldier)->x += 0x1000u;
	OBJECT(soldier)->y += 0x2000u;
	OBJECT(soldier)->car_soldier.number = OBJECT(a0)->parked_car.counter;
	OBJECT(soldier)->routine = 0u;
	OBJECT(soldier)->state = 0u;
}

/* a Foot soldier leaps out */
uint32_t car_soldier_start(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0, stats = 0;

	OBJECT(a0)->flags = 0x81u;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->x_speed = 0x300;
	OBJECT(a0)->y_speed = -0x300;
	OBJECT(a0)->height_speed = 0;
	d7 = OBJECT(a0)->car_soldier.number;
	d7 = (uint16_t)(d7 << 1);
	OBJECT(a0)->car_soldier.stop_y = indexed_table_of_16_bit_values_012CFE[d7 / 2u];
	animation = rom_01504E;
	set_animation(0u, a0, animation);
	enemies_on_screen++;
	OBJECT(a0)->routine++;
	return d7;
}

/* the soldier leaps to his place, then is a gun soldier */
uint32_t car_soldier_leap(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | OBJECT(a0)->screen_y;
	if ((uint16_t)d7_2 < OBJECT(a0)->car_soldier.stop_y)
	{
		OBJECT(a0)->flags = 0x81u;
		OBJECT(a0)->contacts = 0u;
		OBJECT(a0)->kind = 9u;
		OBJECT(a0)->parameter = 0u;
		OBJECT(a0)->colour = 0xFFu;
		OBJECT(a0)->animation_delay = 0u;
		OBJECT(a0)->routine = 0u;
		OBJECT(a0)->state = 0u;
		enemies_on_screen--;
		return d7_2;
	}
	d7_2 = move_by_speeds(a0);
	return d7_2;
}
