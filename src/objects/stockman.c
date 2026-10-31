/**
 *    Name:        objects/stockman.c
 *    Description: Baxter Stockman (area 3) and the Mousers he drops
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Stockman comes in, by the state of his way in */
void stockman_enter(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->state;
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		stockman_start(a0);
		break;
	case 4:
		stockman_wait_for_last_enemy(a0, &d7, p_a5);
		break;
	case 8:
		d7 = stockman_wait(d7, a0);
		break;
	case 12:
		stockman_fly_in(d0, a0, &d5, &d7, p_a5);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* Stockman waits in his flying machine */
void stockman_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->shadow = 0x17C20u;
	stats = stockman_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->stockman.time_left = (OBJECT(a0)->stockman.time_left & 0xFFu) | ((OBJECT(a0)->health_bars & 0xFFu) << 8u);
	animation = rom_015C70;
	set_animation(0u, a0, animation);
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	mousers_break_down = 0u;
	OBJECT(a0)->stockman.explosions = 0u;
	OBJECT(a0)->state++;
	enemies_on_screen++;
}

/* once he is the last enemy the music fades */
void stockman_wait_for_last_enemy(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint8_t d7_2 = 0;
	uint16_t d7_3 = 0;
	uint32_t a6 = 0;

	if (enemies_on_screen != 1u)
		return;
	d7_2 = 0xFEu;
	music = 0xFEu;
	queue_sound(d7_2, 0u);
	a6 = 0xC6C4u;
	d7_3 = 0x43Cu;
	*p_a5 = post_palette_request(d7_3, a6);
	OBJECT(a0)->stockman.timer = 0x64u;
	OBJECT(a0)->state++;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_3;
}

/* then the boss music, and he flies in */
uint32_t stockman_wait(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t timer = 0;

	if (palettes_busy == 0u)
	{
		timer = OBJECT(a0)->stockman.timer;
		OBJECT(a0)->stockman.timer = timer - 1u;
		if (timer == 1u)
		{
			d7_2 = 0x33u;
			queue_sound((uint8_t)d7_2, 0u);
			d7_2 = 0x64u;
			music = d7_2;
			queue_sound((uint8_t)d7_2, 0u);
			d7 = 0xBFu;
			queue_sound((uint8_t)d7, 0u);
			OBJECT(a0)->x_speed = -0x300;
			OBJECT(a0)->y_speed = 0;
			OBJECT(a0)->height_speed = 0x100;
			OBJECT(a0)->state++;
		}
	}
	return d7;
}

/* he flies in, picks a turtle and says "Yippee-I-Ay!" */
void stockman_fly_in(uint32_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint16_t d0_2 = 0, d2 = 0, screen_x = 0;

	stockman_set_floor(a0);
	*p_d7 = move_by_speeds(a0);
	if (OBJECT(a0)->x >= 0x47000u)
	{
		return;
	}
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->stockman.heading = 0x800u;
	OBJECT(a0)->stockman.turning = 1u;
	OBJECT(a0)->stockman.turn_speed = 0x20u;
	OBJECT(a0)->stockman.bob = 0u;
	OBJECT(a0)->stockman.target = 0u;
	OBJECT(a0)->stockman.time_left = 0xE10u;
	boss_pick_target(a0, &d0, p_d7, p_a5);
	if ((uint8_t)*p_d7 == 0u)
		OBJECT(a0)->stockman.target = 0u;
	*p_d7 = stockman_random_drop_time(a0);
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
	screen_x = OBJECT(a0)->screen_x;
	d2 = (uint16_t)(OBJECT(a0)->screen_y + 0x20u);
	say_yippee_i_ay(d0_2, screen_x, d2, &d5, p_d7);
	OBJECT(a0)->height = 0x2C00u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->state = 0u;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* he weaves at his turtle and now and then drops a Mouser; after a while he rises out of sight */
void stockman_fly(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, animation = 0, d7 = 0;
	uint8_t timer = 0;

	stockman_set_floor(a0);
	if (OBJECT(a0)->stockman.time_left == 0u)
	{
		stockman_steer(a0, p_d7, p_a5);
		OBJECT(a0)->height_whole++;
		if (OBJECT(a0)->height_whole >= 0xE0u)
		{
			enemies_on_screen--;
			remove_object(a0);
		}
		return;
	}
	OBJECT(a0)->stockman.time_left--;
	stockman_bob(a0, p_d5, p_d7);
	stockman_steer(a0, p_d7, p_a5);
	timer = OBJECT(a0)->stockman.timer;
	OBJECT(a0)->stockman.timer = timer - 1u;
	if (timer != 0u)
	{
		return;
	}
	highest_player_in_play(p_d5, &d7);
	d7 = indexed_table_of_8_bit_values_013E30[d7];
	if (enemies_on_screen <= d7)
	{
		a6 = OBJECT_ADDRESS(12);
		*p_d7 = 0xCu;
		find_free_object(p_d7, &a6);
		if ((uint8_t)*p_d7 != 0u)
		{
			*p_a5 = stockman_start_mouser(a0, *p_a5, a6);
			animation = rom_015C74;
			set_animation(0u, a0, animation);
			OBJECT(a0)->routine++;
			return;
		}
	}
	*p_d7 = stockman_random_drop_time(a0);
}

/* his claws open as the Mouser drops */
void stockman_drop_mouser(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	stockman_set_floor(a0);
	stockman_bob(a0, p_d5, p_d7);
	stockman_steer(a0, p_d7, p_a5);
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine--;
		animation = rom_015C70;
		set_animation(0u, a0, animation);
		*p_d7 = stockman_random_drop_time(a0);
		OBJECT(a0)->unk_31 = 0u;
	}
}

/* Unused: nothing */
void stockman_idle(void)
{
}

/* a hit makes him shake, or the last one defeats him */
uint32_t stockman_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	stockman_set_floor(a0);
	if (OBJECT(a0)->health_bars == 0u)
	{
		OBJECT(a0)->routine = 6u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->stockman.explosions = 0u;
		OBJECT(a0)->flags &= ~6u;
		animation = rom_015C7C;
		set_animation(0u, a0, animation);
		return d7;
	}
	OBJECT(a0)->health = 1u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->stockman.timer = 0x1Eu;
	OBJECT(a0)->flags &= ~2u;
	animation = rom_015C78;
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 5u;
	queue_sound((uint8_t)d7_2, animation);
	return d7_2;
}

/* he gets over the hit */
void stockman_recover(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;
	uint8_t timer = 0;

	stockman_set_floor(a0);
	stockman_shake(a0, p_d5, p_d7);
	stockman_steer(a0, p_d7, p_a5);
	timer = OBJECT(a0)->stockman.timer;
	OBJECT(a0)->stockman.timer = timer - 1u;
	if (timer == 1u)
	{
		animation = rom_015C70;
		set_animation(0u, a0, animation);
		OBJECT(a0)->health = 1u;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->flags |= 2u;
	}
}

/* the defeated Stockman, by the state of his defeat */
void stockman_defeated(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d7 = OBJECT(a0)->state;
	*p_d7 = (uint16_t)(*p_d7 << 2);
	switch (*p_d7)
	{
	case 0:
		stockman_defeated_explode(a0, p_d7, p_a5);
		return;
	case 4:
		stockman_defeated_next_explosion(a0);
		return;
	case 8:
		stockman_defeated_vanish(a0);
		return;
	}
}

/* an explosion on his machine */
void stockman_defeated_explode(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d6 = 0, d7_3 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	stockman_set_floor(a0);
	OBJECT(a0)->stockman.timer = 0xCu;
	OBJECT(a0)->state = 1u;
	a6 = OBJECT_ADDRESS(24);
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (uint8_t)d7_2;
	find_free_object(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
	{
		d7_3 = (uint16_t)((uint32_t)OBJECT(a0)->stockman.explosions << 2);
		d6 = indexed_table_of_16_bit_values_010F62[d7_3 / 2u];
		d7_3 = rom_010F64[d7_3 / 2u];
		start_big_explosion(d6, d7_3, a0, a6);
		*p_a5 = rom_010F44_ADDRESS;
		d7_2 = OBJECT(a0)->stockman.explosions;
		d7_2 = d7_2 & 1u;
		d7_2 = rom_010F44[d7_2];
		queue_sound((uint8_t)d7_2, a6);
	}
	else
		OBJECT(a0)->state = 2u;
	*p_d7 = d7_2;
}

/* the next explosion, until four; the boss is down */
void stockman_defeated_next_explosion(uint32_t a0)
{
	uint8_t timer = 0;

	stockman_set_floor(a0);
	timer = OBJECT(a0)->stockman.timer;
	OBJECT(a0)->stockman.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->state--;
		OBJECT(a0)->stockman.explosions++;
		mousers_break_down = 1u;
		if (OBJECT(a0)->stockman.explosions == 4u)
			OBJECT(a0)->state = 2u;
	}
}

/* he is gone when his defeat's animation ends */
void stockman_defeated_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	enemies_on_screen--;
	remove_object(a0);
}

/* the hit machine shakes at its height */
void stockman_shake(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint16_t y = 0;
	uint32_t a6 = 0, d5 = 0, d7 = 0;

	d7 = (uint8_t)frame_count;
	d7 = d7 & 6u;
	d7 = indexed_table_of_16_bit_values_01416E[d7 / 2u];
	a6 = 0x14176u;
	d5 = 0u;
	y = (uint16_t)OBJECT(a0)->y;
	do
	{
		if ((uint16_t)y < DATA16(a6))
			break;
		d5 = (uint16_t)(d5 + 2u);
	} while ((uint8_t)d5 < 0x1Eu);
	d7 = (uint16_t)(d7 + mem_read16(0x14194u + (int16_t)d5));
	OBJECT(a0)->height = d7;
	*p_d5 = d5;
	*p_d7 = d7;
}

/* he weaves toward his turtle */
void stockman_steer(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d6 = 0, d7_2 = 0, ignored = 0, target = 0;
	uint16_t t1 = 0;

	d7_2 = (d7 & ~0xFFFFu) | frame_count;
	t1 = d7_2 & 0x3Fu;
	d7_2 = (d7_2 & ~0xFFFFu) | t1;
	if (t1 == 0u)
	{
		boss_pick_target(a0, &ignored, &d7_2, p_a5);
		if ((uint8_t)d7_2 == 0u)
			OBJECT(a0)->stockman.target = 0u;
	}
	target = OBJECT(a0)->stockman.target;
	if (target != 0u)
	{
		if (OBJECT(a0)->screen_x < mem_read16(target + 0xCu))
		{
			if (OBJECT(a0)->stockman.turning != 0u)
			{
				OBJECT(a0)->stockman.heading -= OBJECT(a0)->stockman.turn_speed;
				OBJECT(a0)->stockman.direction &= 0xFu;
				if (OBJECT(a0)->stockman.direction == 0xCu)
					OBJECT(a0)->stockman.turning ^= 1u;
			}
			else
			{
				OBJECT(a0)->stockman.heading += OBJECT(a0)->stockman.turn_speed;
				OBJECT(a0)->stockman.direction &= 0xFu;
				if (OBJECT(a0)->stockman.direction == 4u)
					OBJECT(a0)->stockman.turning ^= 1u;
			}
		}
		else if (OBJECT(a0)->stockman.turning != 0u)
		{
			OBJECT(a0)->stockman.heading -= OBJECT(a0)->stockman.turn_speed;
			OBJECT(a0)->stockman.direction &= 0xFu;
			if (OBJECT(a0)->stockman.direction == 4u)
				OBJECT(a0)->stockman.turning ^= 1u;
		}
		else
		{
			OBJECT(a0)->stockman.heading += OBJECT(a0)->stockman.turn_speed;
			OBJECT(a0)->stockman.direction &= 0xFu;
			if (OBJECT(a0)->stockman.direction == 0xCu)
				OBJECT(a0)->stockman.turning ^= 1u;
		}
		d6 = 0x100u;
		if (mem_read16(target + 0xEu) <= OBJECT(a0)->screen_y)
			d6 = ~d6;
		OBJECT(a0)->y += d6;
		d7_2 = stockman_move(a0);
		stockman_keep_in_area(a0);
	}
	*p_d7 = d7_2;
}

/* he is kept within his part of the sewer */
void stockman_keep_in_area(uint32_t a0)
{
	if (OBJECT(a0)->x >= 0x47000u)
		OBJECT(a0)->x = 0x47000u;
	else if (OBJECT(a0)->x < 0x3C000u)
		OBJECT(a0)->x = 0x3C000u;
	if (OBJECT(a0)->y >= 0x7800u)
	{
		OBJECT(a0)->y = 0x7800u;
		return;
	}
	if (OBJECT(a0)->y < 0x1800u)
	{
		OBJECT(a0)->y = 0x1800u;
		return;
	}
}

/* he bobs in the air at a height by how far back he is */
void stockman_bob(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint16_t y = 0;
	uint32_t a6 = 0, d5 = 0, d7 = 0;

	d7 = OBJECT(a0)->stockman.bob;
	d7 = d7 & 0x3Eu;
	d7 = rom_0141B4[d7 / 2u];
	a6 = 0x14176u;
	d5 = 0u;
	y = (uint16_t)OBJECT(a0)->y;
	do
	{
		if ((uint16_t)y < DATA16(a6))
			break;
		d5 = (uint16_t)(d5 + 2u);
	} while ((uint8_t)d5 < 0x1Eu);
	d7 = (uint16_t)(d7 + mem_read16(0x14194u + (int16_t)d5));
	OBJECT(a0)->height = d7;
	OBJECT(a0)->stockman.bob++;
	OBJECT(a0)->stockman.bob &= 0x3Fu;
	*p_d5 = d5;
	*p_d7 = d7;
}

/* he moves the way he flies */
uint32_t stockman_move(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->stockman.direction;
	d7 = (uint16_t)(d7 << 2);
	OBJECT(a0)->x += (int16_t)indexed_table_of_16_bit_values_01426A[d7 / 2u];
	OBJECT(a0)->y += (int16_t)rom_01426C[d7 / 2u];
	return d7;
}

/* how long until his next drop, at random */
uint32_t stockman_random_drop_time(uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t d7 = 0;
	uint8_t timer = 0, t1 = 0;

	d7 = 8u;
	d7 = random_below((uint16_t)d7, a0);
	OBJECT(a0)->stockman.timer = indexed_table_of_8_bit_values_01424A[d7];
	d7 = IN_PAGE(d7, difficulty_setting);
	d7 = (d7 & ~0xFFu) | (uint8_t)(d7 << 3);
	timer = OBJECT(a0)->stockman.timer;
	t1 = timer - d7;
	zero = t1 == 0u;
	OBJECT(a0)->stockman.timer = t1;
	if (timer < (uint8_t)d7 || zero)
		OBJECT(a0)->stockman.timer = 1u;
	return d7;
}

/* the floor under him, higher at the back */
void stockman_set_floor(uint32_t a0)
{
	OBJECT(a0)->floor_height = 0u;
	if (OBJECT(a0)->y >= 0x6000u)
		OBJECT(a0)->floor_height = 0x18u;
}

/* the number of the highest player in play */
void highest_player_in_play(uint32_t *p_d5, uint32_t *p_d7)
{
	uint8_t d5 = 0;
	uint16_t d6 = 0;
	uint32_t d7 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	d7 = 0u;
	d6 = 3u;
	d5 = players_in_play;
	do
	{
		t1 = d5 >> 1;
		d5 = t1;
		if (t1 != 0u)
			d7 = (uint8_t)(d7 + 1u);
		t2 = d6 - 1u;
		d6 = t2;
	} while (t2 != 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
	*p_d7 = d7;
}

/* a Mouser drops from his claws, unless he is over the middle of the sewer */
uint32_t stockman_start_mouser(uint32_t a0, uint32_t a5, uint32_t a6)
{
	uint32_t a5_2 = 0;

	if (OBJECT(a0)->y >= 0x3800u && OBJECT(a0)->y < 0x6800u)
		return a5;
	OBJECT(a6)->flags = 1u;
	OBJECT(a6)->contacts = 0u;
	OBJECT(a6)->kind = 0x5Eu;
	OBJECT(a6)->parameter = 0u;
	OBJECT(a6)->colour = 0xFFu;
	OBJECT(a6)->animation_delay = 0u;
	OBJECT(a6)->contacts |= 0x80u;
	a5_2 = 0x17C38u;
	OBJECT(a6)->shadow = 0x17C38u;
	place_at_object(a0, a6);
	OBJECT(a6)->y += 0x280u;
	OBJECT(a6)->height -= 0x800u;
	OBJECT(a6)->unk_2F = 0u;
	enemies_on_screen++;
	OBJECT(a6)->routine = 0u;
	OBJECT(a6)->state = 0u;
	return a5_2;
}

/* a Mouser falls from Stockman's claws */
void falling_mouser_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags = 0x81u;
	stats = falling_mouser_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0x400;
	animation = rom_015D4A;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the Mouser falls to the floor and is a Mouser that goes after the turtles */
uint32_t falling_mouser_fall(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint16_t height = 0;

	d7_2 = (d7 & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	height = OBJECT(a0)->height;
	OBJECT(a0)->height = height - d7_2;
	if (height < (uint16_t)d7_2)
		OBJECT(a0)->height = 0u;
	if (OBJECT(a0)->y >= 0x4800u)
	{
		if (OBJECT(a0)->height >= 0x1800u)
		{
			falling_mouser_idle();
			return d7_2;
		}
		OBJECT(a0)->height = 0x1800u;
		OBJECT(a0)->floor_height = 0x18u;
		OBJECT(a0)->flags = 0x81u;
		OBJECT(a0)->contacts = 0u;
		OBJECT(a0)->kind = 0x4Eu;
		OBJECT(a0)->parameter = 0x80u;
		OBJECT(a0)->routine = 0u;
		OBJECT(a0)->state = 0u;
		enemies_on_screen--;
		falling_mouser_idle();
		return d7_2;
	}
	if (OBJECT(a0)->height != 0u)
	{
		falling_mouser_idle();
		return d7_2;
	}
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->contacts = 0u;
	OBJECT(a0)->kind = 0x4Eu;
	OBJECT(a0)->parameter = 0x80u;
	OBJECT(a0)->routine = 0u;
	OBJECT(a0)->state = 0u;
	enemies_on_screen--;
	falling_mouser_idle();
	return d7_2;
}

/* nothing */
void falling_mouser_idle(void)
{
}

/* Unused: the falling Mouser cannot be hit; it would be a Mouser on the floor */
void falling_mouser_struck(uint32_t a0)
{
	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->contacts = 0u;
	OBJECT(a0)->kind = 0x4Eu;
	OBJECT(a0)->parameter = 0u;
	OBJECT(a0)->routine = 0u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->floor_height = 0u;
	enemies_on_screen--;
}
