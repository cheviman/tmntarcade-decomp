/**
 *    Name:        objects/air_attacks.c
 *    Description: the helicopters of the skateboard ride, the missiles that fall on idle turtles, the flying drones
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* a helicopter comes in the air, its sound on */
uint32_t helicopter_start(uint32_t a0)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0, animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x86u;
	stats = helicopter_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_0152EE;
	if ((OBJECT(a0)->parameter & 1u) != 0u)
		animation = rom_0152F2;
	set_animation(0u, a0, animation);
	d7 = 0xAu;
	queue_sound(d7, animation);
	OBJECT(a0)->helicopter.stay_time = 0x384u;
	OBJECT(a0)->contacts |= 0x80u;
	a6 = 0x171A0u;
	if ((int8_t)OBJECT(a0)->parameter < 0)
	{
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->attack |= 0x80u;
		a6 = 0x171A8u;
	}
	OBJECT(a0)->shadow = a6;
	d7_2 = helicopter_random_wait(a0);
	OBJECT(a0)->helicopter.drift = 0u;
	OBJECT(a0)->routine++;
	enemies_on_screen++;
	helicopter_count++;
	return d7_2;
}

/* the helicopter hovers in front of the turtles until it fires */
void helicopter_hover(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint8_t timer = 0;

	helicopter_bob(a0);
	helicopter_fly(a0, p_d5, p_d7);
	timer = OBJECT(a0)->helicopter.timer;
	OBJECT(a0)->helicopter.timer = timer - 1u;
	if (timer != 0u)
	{
		return;
	}
	OBJECT(a0)->helicopter.timer = 0u;
	if ((OBJECT(a0)->parameter & 1u) != 0u)
	{
		OBJECT(a0)->helicopter.shots_left = 3u;
		OBJECT(a0)->routine += 2u;
		return;
	}
	OBJECT(a0)->helicopter.shots_left = 4u;
	OBJECT(a0)->routine++;
}

/* the helicopter fires a burst of bullets */
void helicopter_fire_bullets(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t a6 = 0;
	uint8_t timer = 0, shots_left = 0;

	helicopter_bob(a0);
	helicopter_fly(a0, p_d5, p_d7);
	timer = OBJECT(a0)->helicopter.timer;
	OBJECT(a0)->helicopter.timer = timer - 1u;
	if (timer != 0u)
	{
		return;
	}
	shots_left = OBJECT(a0)->helicopter.shots_left;
	OBJECT(a0)->helicopter.shots_left = shots_left - 1u;
	if (shots_left == 0u)
	{
		OBJECT(a0)->routine--;
		*p_d7 = helicopter_random_wait(a0);
		OBJECT(a0)->helicopter.shots_left = 0u;
		return;
	}
	a6 = OBJECT_ADDRESS(32);
	*p_d7 = 8u;
	find_free_object(p_d7, &a6);
	if ((uint8_t)*p_d7 == 0u)
	{
		OBJECT(a0)->routine--;
		*p_d7 = helicopter_random_wait(a0);
		OBJECT(a0)->helicopter.shots_left = 0u;
		return;
	}
	*p_d7 = helicopter_start_bullet(a0, a6);
	OBJECT(a0)->helicopter.timer = 5u;
}

/* the helicopter drops its missiles */
void helicopter_drop_missiles(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t a6 = 0;
	uint8_t timer = 0, shots_left = 0;

	helicopter_bob(a0);
	helicopter_fly(a0, p_d5, p_d7);
	timer = OBJECT(a0)->helicopter.timer;
	OBJECT(a0)->helicopter.timer = timer - 1u;
	if (timer != 0u)
	{
		return;
	}
	shots_left = OBJECT(a0)->helicopter.shots_left;
	OBJECT(a0)->helicopter.shots_left = shots_left - 1u;
	if (shots_left == 0u)
	{
		OBJECT(a0)->routine -= 2u;
		*p_d7 = helicopter_random_wait(a0);
		OBJECT(a0)->helicopter.shots_left = 0u;
		return;
	}
	a6 = OBJECT_ADDRESS(24);
	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	*p_d7 = (*p_d7 & ~0xFFFFu) | (uint8_t)*p_d7;
	find_free_object(p_d7, &a6);
	if ((uint8_t)*p_d7 == 0u)
	{
		OBJECT(a0)->routine -= 2u;
		*p_d7 = helicopter_random_wait(a0);
		OBJECT(a0)->helicopter.shots_left = 0u;
		return;
	}
	helicopter_start_missile(a0, a6);
	OBJECT(a0)->helicopter.timer = 7u;
}

/* a hit makes the helicopter shake, or the last one destroys it in an explosion */
uint32_t helicopter_struck(uint32_t a0)
{
	uint16_t d6 = 0;
	uint32_t d7 = 0, object = 0;

	d7 = helicopter_bob(a0);
	if (OBJECT(a0)->health_bars == 0u)
	{
		OBJECT(a0)->routine = 6u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->helicopter.drift = 0u;
		OBJECT(a0)->flags &= ~6u;
		if (helicopter_count == 1u)
		{
			d7 = 9u;
			queue_sound((uint8_t)d7, 0u);
		}
		object = OBJECT_ADDRESS(24);
		d7 = (d7 & ~0xFFu) | 8u;
		d7 = (uint8_t)d7;
		find_free_object(&d7, &object);
		if ((uint8_t)d7 == 0u)
			return d7;
		d6 = 0u;
		d7 = 0u;
		OBJECT(object)->flags = 1u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->kind = 0x32u;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 2u;
		d7 = place_explosion(d6, (uint16_t)d7, a0, object);
		d7 = (d7 & ~0xFFu) | 0x11u;
		queue_sound((uint8_t)d7, object);
		return d7;
	}
	OBJECT(a0)->colour = 9u;
	OBJECT(a0)->health = 1u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->helicopter.timer = 0x28u;
	OBJECT(a0)->flags &= ~2u;
	d7 = (d7 & ~0xFFu) | 5u;
	queue_sound((uint8_t)d7, 0u);
	return d7;
}

/* the helicopter gets over the hit */
uint32_t helicopter_recover(uint32_t a0)
{
	uint32_t d7 = 0;
	uint8_t timer = 0;

	d7 = helicopter_shake(a0);
	if (OBJECT(a0)->helicopter.timer == 0x20u)
		OBJECT(a0)->colour = 0xFFu;
	timer = OBJECT(a0)->helicopter.timer;
	OBJECT(a0)->helicopter.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->health = 1u;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->flags |= 2u;
	}
	return d7;
}

/* the wreck stays behind until it leaves the screen */
void helicopter_destroyed(uint32_t a0)
{
	remove_if_off_screen(a0);
	if (OBJECT(a0)->flags == 0u)
	{
		enemies_on_screen--;
		helicopter_count--;
	}
}

/* the helicopter drifts in depth and keeps in front of the turtles; after a while it falls behind and is
   gone */
void helicopter_fly(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d4 = 0, d6 = 0, d7_2 = 0, drift = 0;
	uint32_t d7 = 0, object = 0;
	uint16_t t1 = 0, t2 = 0, stay_time = 0;

	drift = OBJECT(a0)->helicopter.drift;
	OBJECT(a0)->y += (int16_t)indexed_table_of_16_bit_values_013092[drift & 1u];
	if (OBJECT(a0)->y >= 0x7800u || OBJECT(a0)->y < reset_ADDRESS)
		OBJECT(a0)->helicopter.drift ^= 1u;
	object = OBJECT_ADDRESS(3);
	d7 = 3u;
	d6 = 0u;
	do
	{
		if ((players_in_play & shl32(1u, (int)(d7 & 7u))) != 0u && (players_knocked_out & shl32(1u, (int)(d7 & 7u))) == 0u && OBJECT(object)->routine != 4u)
		{
			if ((OBJECT(a0)->flags & 0x40u) != 0u)
			{
				if (d6 == 0u)
					d6 = 0x1FFu;
				if (OBJECT(object)->screen_x <= d6)
				{
					d6 = OBJECT(object)->screen_x;
					d5 = 0u;
					t1 = OBJECT(a0)->screen_y - OBJECT(object)->screen_y;
					d4 = t1;
					if ((int16_t)t1 < 0)
						d4 = (uint16_t)~d4;
					if (d4 < 6u)
						d5 = 1u;
				}
			}
			else if (d6 < OBJECT(object)->screen_x)
			{
				d6 = OBJECT(object)->screen_x;
				d5 = 0u;
				t1 = OBJECT(a0)->screen_y - OBJECT(object)->screen_y;
				d4 = t1;
				if ((int16_t)t1 < 0)
					d4 = (uint16_t)~d4;
				if (d4 < 6u)
					d5 = 1u;
			}
		}
		t2 = d7 - 1u;
		d7 = t2;
		object -= 0x50u;
	} while (t2 != 0xFFFFu);
	stay_time = OBJECT(a0)->helicopter.stay_time;
	OBJECT(a0)->helicopter.stay_time = stay_time - 1u;
	if (stay_time != 0u)
	{
		if (d6 != 0u)
		{
			d7_2 = (uint16_t)((frame_count & 0x3Fu) + 0x10u);
			if ((OBJECT(a0)->flags & 0x40u) != 0u)
				d7_2 = (uint16_t)~d7_2;
			d6 += d7_2;
			d7 = 0xFF80u;
			if ((uint8_t)d5 != 0u)
				d7 = (uint16_t)(d7 << 2);
			d7 = (int16_t)d7;
			if (OBJECT(a0)->screen_x <= d6)
				d7 = ~d7;
			OBJECT(a0)->x += d7;
		}
	}
	else
	{
		OBJECT(a0)->helicopter.stay_time = 0u;
		OBJECT(a0)->x -= 0x100u;
		if (OBJECT(a0)->screen_x < 0x10u)
		{
			enemies_on_screen--;
			helicopter_count--;
			if (helicopter_count == 0u)
			{
				d7 = 9u;
				queue_sound((uint8_t)d7, object);
			}
			remove_object(a0);
		}
	}
	*p_d5 = d5;
	*p_d7 = d7;
}

/* the hit helicopter shakes, carried with the ride */
uint32_t helicopter_shake(uint32_t a0)
{
	uint32_t d7 = 0;

	OBJECT(a0)->x += 0x600u;
	d7 = (uint8_t)frame_count;
	d7 = d7 & 6u;
	d7 = indexed_table_of_16_bit_values_0130F4[d7 / 2u];
	d7 = (uint16_t)(d7 + 0x4000u);
	OBJECT(a0)->height = d7;
	return d7;
}

/* the helicopter bobs in the air, carried with the ride */
uint32_t helicopter_bob(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = (uint8_t)frame_count;
	d7 = d7 & 0x3Cu;
	d7 = d7 >> 1;
	d7 = TABLE16(rom_0130FC, d7);
	d7 = (uint16_t)(d7 + 0x4000u);
	OBJECT(a0)->height = d7;
	carry_with_ride(a0);
	return d7;
}

/* in the skateboard ride the object moves on with the scroll */
void carry_with_ride(uint32_t a0)
{
	if (stage == 6u)
		OBJECT(a0)->x += 0x600u;
}

/* how long until the helicopter fires, at random */
uint32_t helicopter_random_wait(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;

	d7 = 4u;
	d7 = random_below((uint16_t)d7, a0);
	a6 = indexed_table_of_8_bit_values_013150_ADDRESS;
	if ((OBJECT(a0)->parameter & 1u) != 0u)
		a6 = 0x13154u;
	OBJECT(a0)->helicopter.timer = DATA8(a6 + d7);
	d7 = IN_PAGE(d7, difficulty_setting);
	d7 = (d7 & ~0xFFu) | (uint8_t)(d7 << 3);
	OBJECT(a0)->helicopter.timer -= d7;
	return d7;
}

/* a bullet from the front of the helicopter */
uint32_t helicopter_start_bullet(uint32_t a0, uint32_t a6)
{
	uint32_t d7 = 0;

	OBJECT(a6)->flags = 1u;
	OBJECT(a6)->contacts = 0u;
	OBJECT(a6)->kind = 0x44u;
	OBJECT(a6)->parameter = 0u;
	OBJECT(a6)->colour = 0xFFu;
	OBJECT(a6)->animation_delay = 0u;
	place_at_object(a0, a6);
	OBJECT(a6)->y--;
	OBJECT(a6)->height -= 0x2200u;
	d7 = 0x3800u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		OBJECT(a6)->flags |= 0x40u;
		d7 = 0xFFFFD500u;
	}
	OBJECT(a6)->x -= d7;
	OBJECT(a6)->unk_2F = 0u;
	OBJECT(a6)->routine = 0u;
	OBJECT(a6)->state = 0u;
	return d7;
}

/* a bullet flies down at a slant, knocking turtles down */
uint32_t copter_bullet_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	carry_with_ride(a0);
	OBJECT(a0)->flags |= 0x84u;
	stats = copter_bullet_stats_ADDRESS;
	set_object_stats(a0, stats);
	d7_2 = (d7 & ~0xFFFFu) | 0xFB00u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		OBJECT(a0)->attack |= 0x80u;
		d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)~d7_2;
	}
	OBJECT(a0)->x_speed = d7_2;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = -0x500;
	animation = rom_015360;
	set_animation(0u, a0, animation);
	d7_2 = (d7_2 & ~0xFFu) | 0x17u;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the bullet bursts on what it hits, or sparks on the road */
uint32_t copter_bullet_fly(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0;

	carry_with_ride(a0);
	d7 = move_by_speeds(a0);
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		OBJECT(a0)->flags &= ~4u;
		OBJECT(a0)->routine += 2u;
		OBJECT(a0)->animation_delay = 2u;
		animation = rom_014AA6;
		set_animation(0u, a0, animation);
		return d7;
	}
	if ((int16_t)OBJECT(a0)->height < 0)
	{
		OBJECT(a0)->flags &= ~4u;
		OBJECT(a0)->height = 0u;
		OBJECT(a0)->routine++;
		animation = rom_015368;
		set_animation(0u, a0, animation);
		return d7;
	}
	return d7;
}

/* the bullet's burst goes on with the ride */
void copter_bullet_burst(uint32_t a0)
{
	carry_with_ride(a0);
	copter_bullet_vanish(a0);
}

/* the bullet is gone when its spark or burst ends */
void copter_bullet_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		remove_object(a0);
		return;
	}
}

/* a missile from the helicopter */
void helicopter_start_missile(uint32_t a0, uint32_t a6)
{
	OBJECT(a6)->flags = 1u;
	OBJECT(a6)->contacts = 0u;
	OBJECT(a6)->kind = 0x46u;
	OBJECT(a6)->parameter = 0u;
	OBJECT(a6)->colour = 0xFFu;
	OBJECT(a6)->animation_delay = 0u;
	place_at_object(a0, a6);
	OBJECT(a6)->height += 0x1000u;
	OBJECT(a6)->unk_2F = 0u;
	OBJECT(a6)->routine = 0u;
	OBJECT(a6)->state = 0u;
}

/* a missile drops from above */
uint32_t falling_missile_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	carry_with_ride(a0);
	OBJECT(a0)->flags |= 0x84u;
	stats = falling_missile_stats_ADDRESS;
	if (OBJECT(a0)->parameter != 0u)
		stats = falling_missile_at_turtle_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0x300;
	if (OBJECT(a0)->parameter != 0u)
		OBJECT(a0)->height_speed = 0x800;
	animation = rom_01536C;
	if (OBJECT(a0)->parameter != 0u)
		animation = rom_01534A;
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 3u;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->routine++;
	enemies_on_screen++;
	return d7_2;
}

/* the missile drops until it hits the ground and explodes */
uint32_t falling_missile_fall(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;
	uint16_t height = 0;

	carry_with_ride(a0);
	d7_2 = (d7 & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	height = OBJECT(a0)->height;
	OBJECT(a0)->height = height - d7_2;
	if ((uint16_t)d7_2 <= height)
		return d7_2;
	OBJECT(a0)->height = 0u;
	OBJECT(a0)->routine++;
	d7_2 = (d7_2 & ~0xFFu) | 0x13u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_015258;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the explosion ends and the missile is gone */
void falling_missile_explode(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	enemies_on_screen--;
	remove_object(a0);
}

/* missiles drop on the turtles that dawdle */
void rain_missiles_on_turtles(uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint32_t a5 = 0, a6 = 0, d5 = 0;
	uint16_t t1 = 0;

	a5 = OBJECT_ADDRESS(3);
	d5 = 3u;
	do
	{
		if ((players_in_play & shl32(1u, (int)(d5 & 7u))) != 0u)
		{
			a6 = OBJECT_ADDRESS(12);
			d7 = (d7 & ~0xFFu) | 0xCu;
			d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
			find_free_object(&d7, &a6);
			if ((uint8_t)d7 != 0u)
				d7 = start_falling_missile_at_turtle(a5, a6);
		}
		t1 = d5 - 1u;
		d5 = t1;
		a5 -= 0x50u;
	} while (t1 != 0xFFFFu);
	*p_d5 = d5;
	*p_d7 = d7;
}

/* a missile high above a turtle */
uint32_t start_falling_missile_at_turtle(uint32_t a5, uint32_t a6)
{
	uint32_t d7 = 0;

	OBJECT(a6)->flags = 1u;
	OBJECT(a6)->contacts = 0u;
	OBJECT(a6)->kind = 0x46u;
	OBJECT(a6)->parameter = 1u;
	OBJECT(a6)->colour = 0xFFu;
	OBJECT(a6)->animation_delay = 0u;
	OBJECT(a6)->x = spawn_x - 0x1A000u + ((uint32_t)OBJECT(a5)->screen_x << 8);
	d7 = spawn_y - 0x10000u + ((uint32_t)OBJECT(a5)->screen_y << 8);
	OBJECT(a6)->y = d7;
	OBJECT(a6)->height = 0xF000u;
	OBJECT(a6)->unk_2F = 0u;
	OBJECT(a6)->routine = 0u;
	OBJECT(a6)->state = 0u;
	return d7;
}

/* the drones wait far back */
void start_flying_drones(void)
{
	uint16_t d0 = 0;
	uint32_t a6 = 0, d7 = 0;
	uint16_t t1 = 0;

	d0 = 6u;
	do
	{
		a6 = OBJECT_ADDRESS(12);
		d7 = 0xCu;
		find_free_object(&d7, &a6);
		if ((uint8_t)d7 != 0u)
			start_flying_drone(d0, a6);
		t1 = d0 - 1u;
		d0 = t1;
	} while (t1 != 0xFFFFu);
	flying_drones_released = 0u;
	flying_drone_count = 0u;
}

/* a drone with its own way to fly */
void start_flying_drone(uint16_t d0, uint32_t drone)
{
	OBJECT(drone)->flags = 1u;
	OBJECT(drone)->contacts = 0u;
	OBJECT(drone)->kind = 0x54u;
	OBJECT(drone)->parameter = 0u;
	OBJECT(drone)->colour = 0xFFu;
	OBJECT(drone)->animation_delay = 0u;
	OBJECT(drone)->x = 0x54C00u;
	OBJECT(drone)->y = 0x13800u;
	OBJECT(drone)->height = 0u;
	OBJECT(drone)->flying_drone.direction = TABLE8(indexed_table_of_8_bit_values_013486, (uint32_t)(int16_t)d0);
	OBJECT(drone)->flying_drone.heading &= 0xFF00u;
	OBJECT(drone)->flying_drone.turning = mem_read8(0x1348Eu + (int16_t)d0);
	OBJECT(drone)->flying_drone.turn_speed = mem_read8(0x13496u + (int16_t)d0);
	OBJECT(drone)->flying_drone.aim = (uint8_t)d0;
	OBJECT(drone)->routine = 0u;
	OBJECT(drone)->state = 0u;
}

/* the drones come out, their sound on */
void release_flying_drones(void)
{
	flying_drones_released = 1u;
	drone_sound_on = 1u;
	drone_sound_wait = 0u;
}

/* the drone comes in, by the state of its way in */
void flying_drone_enter(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a5 = 0;

	switch (OBJECT(a0)->state)
	{
	case 0:
		*p_d7 = flying_drone_start(a0);
		return;
	case 1:
		*p_d7 = flying_drone_wait(a0);
		return;
	case 2:
		*p_d7 = flying_drone_take_off(a0);
		return;
	case 3:
		*p_a5 = a5;
		flying_drone_ready(a0, p_d7, p_a5);
		return;
	}
}

/* the drone rests */
uint32_t flying_drone_start(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	enemies_on_screen++;
	flying_drone_count++;
	OBJECT(a0)->state++;
	OBJECT(a0)->flying_drone.bob = (uint32_t)OBJECT(a0)->flying_drone.aim << 2;
	d7 = flying_drone_bob_low(a0);
	OBJECT(a0)->flying_drone.target = 0u;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	stats = flying_drone_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_01587E;
	set_animation(0u, a0, animation);
	return d7;
}

/* the drone bobs until it is released, then takes off */
uint32_t flying_drone_wait(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = flying_drone_bob_low(a0);
	if (flying_drones_released != 0u)
	{
		OBJECT(a0)->state++;
		OBJECT(a0)->contacts |= 0x80u;
		OBJECT(a0)->shadow = 0x17958u;
		OBJECT(a0)->x = 0x54C00u;
		OBJECT(a0)->y = 0x8800u;
		OBJECT(a0)->flying_drone.timer = 0x12u;
		d7 = flying_drone_animate(a0);
	}
	return d7;
}

/* the drone flies out on its own way, rising */
uint32_t flying_drone_take_off(uint32_t a0)
{
	uint32_t d7 = 0;
	uint8_t timer = 0;

	d7 = flying_drone_move(a0);
	timer = OBJECT(a0)->flying_drone.timer;
	OBJECT(a0)->flying_drone.timer = timer - 1u;
	if (timer == 0u)
	{
		OBJECT(a0)->state++;
		return d7;
	}
	OBJECT(a0)->height += 0x100u;
	if (OBJECT(a0)->height >= 0x2C00u)
		OBJECT(a0)->height = 0x2C00u;
	return d7;
}

/* the drone picks a turtle and can be hit */
void flying_drone_ready(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t ignored = 0;

	OBJECT(a0)->flags |= 2u;
	boss_pick_target(a0, &ignored, p_d7, p_a5);
	if ((uint8_t)*p_d7 == 0u)
		OBJECT(a0)->flying_drone.target = 0u;
	*p_d7 = flying_drone_random_wait(a0);
	OBJECT(a0)->flying_drone.time_left = 0x708u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->state = 0u;
}

/* the drone weaves at its turtle until it fires; after a while it rises out of sight */
void flying_drone_fly(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t ignored = 0;
	uint8_t timer = 0;

	if (OBJECT(a0)->flying_drone.time_left != 0u)
	{
		OBJECT(a0)->flying_drone.time_left--;
		flying_drone_bob(a0);
		flying_drone_steer(a0, &ignored, p_a5);
		*p_d7 = flying_drone_animate(a0);
		timer = OBJECT(a0)->flying_drone.timer;
		OBJECT(a0)->flying_drone.timer = timer - 1u;
		if (timer == 0u)
		{
			OBJECT(a0)->flying_drone.timer = 0u;
			OBJECT(a0)->flying_drone.shots_left = 4u;
			OBJECT(a0)->routine++;
			return;
		}
		return;
	}
	flying_drone_steer(a0, &ignored, p_a5);
	*p_d7 = flying_drone_animate(a0);
	OBJECT(a0)->height_whole++;
	if (OBJECT(a0)->height_whole < 0xE0u)
	{
		return;
	}
	enemies_on_screen--;
	flying_drone_count--;
	remove_object(a0);
}

/* the drone fires a burst of shots */
void flying_drone_fire(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;
	uint8_t timer = 0, shots_left = 0;

	*p_d7 = flying_drone_bob(a0);
	flying_drone_steer(a0, p_d7, p_a5);
	timer = OBJECT(a0)->flying_drone.timer;
	OBJECT(a0)->flying_drone.timer = timer - 1u;
	if (timer != 0u)
	{
		return;
	}
	shots_left = OBJECT(a0)->flying_drone.shots_left;
	OBJECT(a0)->flying_drone.shots_left = shots_left - 1u;
	if (shots_left == 0u)
	{
		OBJECT(a0)->routine--;
		*p_d7 = flying_drone_random_wait(a0);
		OBJECT(a0)->flying_drone.shots_left = 0u;
		return;
	}
	a6 = OBJECT_ADDRESS(32);
	*p_d7 = 8u;
	find_free_object(p_d7, &a6);
	if ((uint8_t)*p_d7 == 0u)
	{
		OBJECT(a0)->routine--;
		*p_d7 = flying_drone_random_wait(a0);
		OBJECT(a0)->flying_drone.shots_left = 0u;
		return;
	}
	flying_drone_start_shot(a0, a6, p_d7, p_a5);
	OBJECT(a0)->flying_drone.timer = 7u;
}

/* a hit makes the drone shake, or the last one wrecks it in an explosion */
uint32_t flying_drone_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, object = 0;

	if (OBJECT(a0)->health_bars == 0u)
	{
		OBJECT(a0)->routine = 6u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->flags &= ~6u;
		animation = rom_015882;
		set_animation(0u, a0, animation);
		object = OBJECT_ADDRESS(24);
		d7_2 = (d7 & ~0xFFu) | 8u;
		d7_2 = (d7_2 & ~0xFFFFu) | (uint8_t)d7_2;
		find_free_object(&d7_2, &object);
		if ((uint8_t)d7_2 == 0u)
			return d7_2;
		OBJECT(object)->flags = 1u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->kind = 0x57u;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		place_at_object(a0, object);
		OBJECT(object)->y -= 0x1600u;
		OBJECT(object)->unk_2F = 0u;
		OBJECT(object)->routine = 0u;
		OBJECT(object)->state = 0u;
		d7_2 = (d7_2 & ~0xFFu) | 0x11u;
		queue_sound((uint8_t)d7_2, object);
		return d7_2;
	}
	OBJECT(a0)->colour = 8u;
	OBJECT(a0)->health = 1u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->flying_drone.timer = 0x1Eu;
	OBJECT(a0)->flags &= ~2u;
	d7_2 = (d7 & ~0xFFu) | 5u;
	queue_sound((uint8_t)d7_2, 0u);
	return d7_2;
}

/* the drone gets over the hit */
uint32_t flying_drone_recover(uint32_t a0)
{
	uint32_t d7 = 0;
	uint8_t timer = 0;

	d7 = flying_drone_shake(a0);
	if (OBJECT(a0)->flying_drone.timer == 0x16u)
		OBJECT(a0)->colour = 0xFFu;
	timer = OBJECT(a0)->flying_drone.timer;
	OBJECT(a0)->flying_drone.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->health = 1u;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->flags |= 2u;
	}
	return d7;
}

/* the wreck is gone when its animation ends */
void flying_drone_destroyed(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	enemies_on_screen--;
	flying_drone_count--;
	remove_object(a0);
}

/* the hit drone shakes */
uint32_t flying_drone_shake(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = (uint8_t)frame_count;
	d7 = d7 & 6u;
	d7 = indexed_table_of_16_bit_values_0138AC[d7 / 2u];
	d7 = (uint16_t)(d7 + 0x2C00u);
	OBJECT(a0)->height = d7;
	return d7;
}

/* the drone weaves toward its turtle */
void flying_drone_steer(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d6 = 0, d7_2 = 0, ignored = 0, target = 0;
	uint16_t t1 = 0;

	d7_2 = (d7 & ~0xFFFFu) | frame_count;
	t1 = d7_2 & 0x7Fu;
	d7_2 = (d7_2 & ~0xFFFFu) | t1;
	if (t1 == 0u)
	{
		boss_pick_target(a0, &ignored, &d7_2, p_a5);
		if ((uint8_t)d7_2 == 0u)
			OBJECT(a0)->flying_drone.target = 0u;
	}
	target = OBJECT(a0)->flying_drone.target;
	if (target != 0u)
	{
		if (OBJECT(a0)->screen_x < mem_read16(target + 0xCu))
		{
			if (OBJECT(a0)->flying_drone.turning != 0u)
			{
				OBJECT(a0)->flying_drone.heading -= OBJECT(a0)->flying_drone.turn_speed;
				OBJECT(a0)->flying_drone.direction &= 0xFu;
				if (OBJECT(a0)->flying_drone.direction == 0xCu)
					OBJECT(a0)->flying_drone.turning ^= 1u;
			}
			else
			{
				OBJECT(a0)->flying_drone.heading += OBJECT(a0)->flying_drone.turn_speed;
				OBJECT(a0)->flying_drone.direction &= 0xFu;
				if (OBJECT(a0)->flying_drone.direction == 4u)
					OBJECT(a0)->flying_drone.turning ^= 1u;
			}
		}
		else if (OBJECT(a0)->flying_drone.turning != 0u)
		{
			OBJECT(a0)->flying_drone.heading -= OBJECT(a0)->flying_drone.turn_speed;
			OBJECT(a0)->flying_drone.direction &= 0xFu;
			if (OBJECT(a0)->flying_drone.direction == 4u)
				OBJECT(a0)->flying_drone.turning ^= 1u;
		}
		else
		{
			OBJECT(a0)->flying_drone.heading += OBJECT(a0)->flying_drone.turn_speed;
			OBJECT(a0)->flying_drone.direction &= 0xFu;
			if (OBJECT(a0)->flying_drone.direction == 0xCu)
				OBJECT(a0)->flying_drone.turning ^= 1u;
		}
		d6 = 0x100u;
		if (mem_read16(target + 0xEu) <= OBJECT(a0)->screen_y)
			d6 = ~d6;
		OBJECT(a0)->y += d6;
		d7_2 = flying_drone_move(a0);
		flying_drone_keep_in_area(a0);
	}
	*p_d7 = d7_2;
}

/* the drone or its shot is kept on the screen and within the area's depth */
void flying_drone_keep_in_area(uint32_t a0)
{
	if (OBJECT(a0)->screen_x < 0x20u)
		OBJECT(a0)->x += 0x2000u;
	if (OBJECT(a0)->y >= 0x7C00u)
	{
		OBJECT(a0)->y = 0x7C00u;
		return;
	}
	if (OBJECT(a0)->y < reset_ADDRESS)
	{
		OBJECT(a0)->y = reset_ADDRESS;
		return;
	}
}

/* the resting drone bobs */
uint32_t flying_drone_bob_low(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->flying_drone.bob;
	d7 = (uint16_t)(d7 << 1);
	d7 = rom_0138B4[d7 / 2u];
	d7 = (uint16_t)(d7 + 0x2000u);
	OBJECT(a0)->height = d7;
	OBJECT(a0)->flying_drone.bob++;
	OBJECT(a0)->flying_drone.bob &= 0x1Fu;
	return d7;
}

/* the flying drone bobs */
uint32_t flying_drone_bob(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->flying_drone.bob;
	d7 = d7 & 0x3Eu;
	d7 = rom_0138B4[d7 / 2u];
	d7 = (uint16_t)(d7 + 0x2C00u);
	OBJECT(a0)->height = d7;
	OBJECT(a0)->flying_drone.bob++;
	OBJECT(a0)->flying_drone.bob &= 0x3Fu;
	return d7;
}

/* the drone moves the way it flies */
uint32_t flying_drone_move(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->flying_drone.direction;
	d7 = (uint16_t)(d7 << 2);
	OBJECT(a0)->x += (int16_t)rom_0139DA[d7 / 2u];
	OBJECT(a0)->y += (int16_t)rom_0139DC[d7 / 2u];
	return d7;
}

/* the drone faces its turtle and points its gun, the rotor turning */
uint32_t flying_drone_animate(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0, direction = 0;

	if (OBJECT(a0)->flying_drone.target == 0u)
	{
		direction = OBJECT(a0)->flying_drone.direction;
		d7 = indexed_table_of_8_bit_values_0139A2[direction];
		OBJECT(a0)->flags &= 0xBFu;
		if ((int8_t)d7 < 0)
		{
			d7 = d7 & 0x7Fu;
			OBJECT(a0)->flags |= 0x40u;
		}
	}
	else
	{
		OBJECT(a0)->flags &= 0xBFu;
		if (OBJECT(a0)->screen_x < mem_read16(OBJECT(a0)->flying_drone.target + 0xCu))
			OBJECT(a0)->flags |= 0x40u;
		direction = OBJECT(a0)->flying_drone.direction;
		d7 = indexed_table_of_8_bit_values_0139A2[direction];
		d7 = d7 & 3u;
	}
	OBJECT(a0)->flying_drone.aim = d7;
	d7 = (uint16_t)(d7 << 4);
	d7 = (d7 & ~0xFFu) | (uint8_t)(d7 + (((uint8_t)frame_count & 3u) << 2));
	animation = rom_01584E[d7 / 4u];
	set_animation(0u, a0, animation);
	return d7;
}

/* how long until the drone fires, at random */
uint32_t flying_drone_random_wait(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 4u;
	d7 = random_below((uint16_t)d7, a0);
	OBJECT(a0)->flying_drone.timer = indexed_table_of_8_bit_values_0139D6[d7];
	d7 = IN_PAGE(d7, difficulty_setting);
	d7 = (d7 & ~0xFFu) | (uint8_t)(d7 << 3);
	OBJECT(a0)->flying_drone.timer -= d7;
	return d7;
}

/* while drones are about their sound plays now and then */
void sound_flying_drones(uint32_t a0)
{
	uint8_t d7_2 = 0;
	uint32_t d7 = 0;
	uint8_t t1 = 0;

	if (stage != 7u || drone_sound_on == 0u)
		return;
	if (flying_drone_count == 0u)
	{
		drone_sound_on = 0u;
		drone_sound_wait = 0u;
		return;
	}
	t1 = drone_sound_wait;
	drone_sound_wait = t1 - 1u;
	if (t1 != 0u)
		return;
	d7 = 4u;
	d7 = random_below((uint16_t)d7, a0);
	drone_sound_wait = indexed_table_of_8_bit_values_013A74[d7];
	d7_2 = 0x38u;
	queue_sound(d7_2, 0u);
}

/* a shot from the drone's gun */
void flying_drone_start_shot(uint32_t a0, uint32_t shot, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a5 = 0, d7 = 0;

	OBJECT(shot)->flags = 1u;
	OBJECT(shot)->contacts = 0u;
	OBJECT(shot)->kind = 0x55u;
	OBJECT(shot)->parameter = 0u;
	OBJECT(shot)->colour = 0xFFu;
	OBJECT(shot)->animation_delay = 0u;
	place_at_object(a0, shot);
	a5 = indexed_table_of_16_bit_values_013AE4_ADDRESS;
	d7 = 0u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		OBJECT(shot)->flags |= 0x40u;
		d7 = 3u;
	}
	d7 = (uint8_t)(d7 + OBJECT(a0)->flying_drone.aim);
	d7 = (uint16_t)(d7 << 2);
	OBJECT(shot)->x += (int16_t)DATA16(a5 + d7);
	OBJECT(shot)->height += DATA16(a5 + 2u + d7);
	OBJECT(shot)->drone_shot.aim = OBJECT(a0)->flying_drone.aim;
	OBJECT(shot)->routine = 0u;
	OBJECT(shot)->state = 0u;
	*p_d7 = d7;
	*p_a5 = a5;
}

/* the shot flashes at the gun */
uint32_t drone_shot_start(uint32_t a0)
{
	uint32_t a6 = 0, animation = 0, d7 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x84u;
	stats = drone_shot_stats_ADDRESS;
	set_object_stats(a0, stats);
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->attack |= 0x80u;
	animation = rom_015938[OBJECT(a0)->drone_shot.aim * 2u];
	set_animation(0u, a0, animation);
	a6 = indexed_table_of_16_bit_values_013B72_ADDRESS;
	d7 = 0u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		d7 = 3u;
	d7 = (uint8_t)(d7 + OBJECT(a0)->drone_shot.aim);
	d7 = (uint16_t)(d7 << 2);
	OBJECT(a0)->x_speed = DATA16(a6 + d7);
	OBJECT(a0)->y_speed = DATA16(a6 + 2u + d7);
	OBJECT(a0)->height_speed = -0x400;
	d7 = IN_PAGE(d7, 0x14u);
	queue_sound((uint8_t)d7, a6);
	OBJECT(a0)->routine++;
	return d7;
}

/* after the flash the shot streaks down */
uint32_t drone_shot_flash(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		d7 = OBJECT(a0)->drone_shot.aim;
		d7 = (uint16_t)(d7 << 3);
		animation = rom_01593C[d7 / 4u];
		set_animation(0u, a0, animation);
		OBJECT(a0)->routine++;
		OBJECT(a0)->flags &= ~4u;
	}
	return d7;
}

/* the shot drops until it hits the ground and flashes there */
uint32_t drone_shot_fly(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0;

	d7 = move_by_speeds(a0);
	flying_drone_keep_in_area(a0);
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		OBJECT(a0)->flags &= ~4u;
		OBJECT(a0)->routine += 2u;
		OBJECT(a0)->animation_delay = 2u;
		animation = rom_014AA6;
		set_animation(0u, a0, animation);
		return d7;
	}
	if ((int16_t)OBJECT(a0)->height < 0)
	{
		OBJECT(a0)->flags |= 4u;
		OBJECT(a0)->height = 0u;
		OBJECT(a0)->routine++;
		animation = rom_015950;
		set_animation(0u, a0, animation);
		return d7;
	}
	return d7;
}

/* the shot is gone when its flash ends */
void drone_shot_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		remove_object(a0);
		return;
	}
}
