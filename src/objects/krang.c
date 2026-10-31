/**
 *    Name:        objects/krang.c
 *    Description: Krang's android body (area 9), his fist, his lasers and the curtain he appears behind
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Krang's appearance, step by step */
void krang_appear(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->state;
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		d7 = krang_appear_setup(a0);
		break;
	case 4:
		d7 = krang_appear_wait(d7, a0);
		break;
	case 8:
		krang_appear_end(a0, &d7, p_a5);
		break;
	}
	*p_d7 = d7;
}

/* Krang stands ready, with his hits by the number of players */
uint32_t krang_appear_setup(uint32_t a0)
{
	uint16_t d6 = 0;
	uint32_t animation = 0, d7 = 0, stats = 0;
	uint16_t t1 = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = krang_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->krang.hits_left = OBJECT(a0)->health_bars;
	d7 = 0u;
	d6 = 3u;
	do
	{
		if ((players_in_play & shl32(1u, (int)(d6 & 7u))) != 0u)
			d7 = (uint8_t)(d7 + 1u);
		t1 = d6 - 1u;
		d6 = t1;
	} while (t1 != 0xFFFFu);
	d7 = (uint16_t)(d7 << 1);
	OBJECT(a0)->krang.hits_left += d7;
	animation = rom_00EC9C;
	set_animation(0u, a0, animation);
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->krang.laser_angle = 0u;
	OBJECT(a0)->krang.hit_delay = 0u;
	OBJECT(a0)->state++;
	return d7;
}

/* Krang waits for the curtain to go, then raises his arms */
uint32_t krang_appear_wait(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;

	if ((OBJECT(krang_curtain)->flags | OBJECT(krang_curtain)->contacts) == 0u)
	{
		OBJECT(a0)->state++;
		d7 = (d7 & ~0xFFu) | 0xB0u;
		queue_sound((uint8_t)d7, 0u);
		animation = rom_00ECA0;
		set_animation(0u, a0, animation);
	}
	return d7;
}

/* Krang can be hit and starts his first move */
void krang_appear_end(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	krang_posed_last = 0u;
	OBJECT(a0)->flags |= 6u;
	d0 = 0u;
	krang_pick_move(d0, a0, p_d7, p_a5);
}

/* Krang walks; with a turtle close by, he may kick it, fire steep lasers or pose instead */
void krang_walk(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0, d7 = 0;

	d5 = krang_count_down(d5, a0);
	if (OBJECT(a0)->state == 3u)
	{
		d7 = OBJECT(a0)->state;
		d7 = (uint16_t)(d7 << 2);
		switch (d7)
		{
		case 0:
			krang_walk_at_target(a0, &d5, &d7, p_a5);
			break;
		case 4:
			krang_walk_on(a0, &d5, &d7, p_a5);
			break;
		case 8:
			krang_charge(a0, &d5, &d7, p_a5);
			break;
		case 12:
			krang_pose_end(a0, &d5, &d7, p_a5);
			break;
		}
	}
	else
	{
		krang_find_close_turtle(a0, &d0, &d5);
		if ((uint8_t)d0 == 0u)
		{
			d7 = OBJECT(a0)->state;
			d7 = (uint16_t)(d7 << 2);
			switch (d7)
			{
			case 0:
				krang_walk_at_target(a0, &d5, &d7, p_a5);
				break;
			case 4:
				krang_walk_on(a0, &d5, &d7, p_a5);
				break;
			case 8:
				krang_charge(a0, &d5, &d7, p_a5);
				break;
			case 12:
				krang_pose_end(a0, &d5, &d7, p_a5);
				break;
			}
		}
		else
		{
			d7 = 0x10u;
			d7 = random_below((uint16_t)d7, a0);
			if ((uint8_t)d7 < 7u)
			{
				d7 = OBJECT(a0)->state;
				d7 = (uint16_t)(d7 << 2);
				switch (d7)
				{
				case 0:
					krang_walk_at_target(a0, &d5, &d7, p_a5);
					break;
				case 4:
					krang_walk_on(a0, &d5, &d7, p_a5);
					break;
				case 8:
					krang_charge(a0, &d5, &d7, p_a5);
					break;
				case 12:
					krang_pose_end(a0, &d5, &d7, p_a5);
					break;
				}
			}
			else
			{
				OBJECT(a0)->krang.close_turtle = d0;
				d7 = 2u;
				d7 = random_below((uint16_t)d7, a0);
				d7 = (uint16_t)(d7 << 2);
				switch (d7)
				{
				case 8:
					d7 = krang_start_pose(d7, a0);
					break;
				case 0:
					d7 = krang_start_kick(d7, a0);
					break;
				case 4:
					krang_start_lasers_steep(a0);
					break;
				}
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

/* Krang walks at his target a while */
void krang_walk_at_target(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0, d0 = 0;
	uint8_t move_time = 0;

	a6 = krang_aim_walk_ADDRESS;
	krang_walk_step(a0, a6, p_d7, p_a5);
	move_time = OBJECT(a0)->krang.move_time;
	OBJECT(a0)->krang.move_time = move_time - 1u;
	if (move_time == 0u)
	{
		d0 = 1u;
		krang_next_move(d0, a0, &d5, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* Krang walks on at his target a while */
void krang_walk_on(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0, d0 = 0;
	uint8_t move_time = 0;

	a6 = krang_aim_walk_ADDRESS;
	krang_walk_step(a0, a6, p_d7, p_a5);
	move_time = OBJECT(a0)->krang.move_time;
	OBJECT(a0)->krang.move_time = move_time - 1u;
	if (move_time == 0u)
	{
		d0 = 2u;
		krang_next_move(d0, a0, &d5, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* Krang runs at his target a while */
void krang_charge(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0, d0 = 0;
	uint8_t move_time = 0;

	a6 = krang_aim_charge_ADDRESS;
	krang_walk_step(a0, a6, p_d7, p_a5);
	move_time = OBJECT(a0)->krang.move_time;
	OBJECT(a0)->krang.move_time = move_time - 1u;
	if (move_time == 0u)
	{
		d0 = 3u;
		krang_next_move(d0, a0, &d5, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* Krang's pose ends and he picks his next move */
void krang_pose_end(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	d0 = 4u;
	krang_next_move(d0, a0, &d5, p_d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* every 16 frames Krang aims again, and he moves every other frame */
void krang_walk_step(uint32_t a0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)frame_count;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
	{
		switch (a6)
		{
		case 0x00E708u:
			krang_aim_charge(a0, &d7_2, p_a5);
			break;
		case 0x00E718u:
			krang_aim_walk(a0, &d7_2, p_a5);
			break;
		}
	}
	t2 = d7_2 & 1u;
	d7_2 = (d7_2 & ~0xFFu) | t2;
	if (t2 == 0u)
		d7_2 = krang_move(a0);
	*p_d7 = d7_2;
}

/* with a turtle in front of him Krang fires lasers, punches or poses; else he picks another walk */
void krang_next_move(uint32_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = 0;

	krang_find_turtle_in_front(a0, &d5, &d7);
	if ((uint8_t)d7 != 0u)
	{
		d7 = 8u;
		d7 = random_below((uint16_t)d7, a0);
		d7 = (uint16_t)(d7 << 2);
		switch (d7)
		{
		case 32:
			d7 = krang_start_pose(d7, a0);
			break;
		case 0:
		case 12:
		case 24:
			krang_start_lasers(a0);
			break;
		case 4:
		case 16:
		case 28:
			krang_start_lasers_far(a0);
			break;
		case 8:
		case 20:
			krang_start_punch(a0);
			break;
		}
	}
	else
		krang_pick_move(d0, a0, &d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

/* Krang's kick or punch, step by step */
void krang_melee(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = 0, d7 = 0;

	d5 = krang_count_down(d5, a0);
	d7 = OBJECT(a0)->state;
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		krang_kick_end(a0, &d7, p_a5);
		break;
	case 4:
		d7 = krang_punch_throw(d7, a0);
		break;
	case 8:
		krang_punch_wait(a0, &d7, p_a5);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* Krang's kick ends and he walks again */
void krang_kick_end(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->state = 0u;
		d0 = 6u;
		krang_pick_move(d0, a0, p_d7, p_a5);
	}
}

/* Krang throws his arm out and his fist flies off it */
uint32_t krang_punch_throw(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->frame_time++;
		OBJECT(a0)->flags &= ~2u;
		OBJECT(a0)->state++;
		animation = rom_00ECD0;
		set_animation(0u, a0, animation);
		krang_fist_flying = 1u;
		d7 = krang_start_fist(d7, a0);
	}
	return d7;
}

/* Krang waits for his fist to fly off the screen */
void krang_punch_wait(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;

	if (krang_fist_flying != 0u)
		return;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->state = 0u;
	d0 = 6u;
	krang_pick_move(d0, a0, p_d7, p_a5);
}

/* Krang's lasers, step by step */
void krang_fire_lasers(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = 0, d7 = 0;

	d5 = krang_count_down(d5, a0);
	d7 = OBJECT(a0)->state;
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		krang_lasers_fire(a0, &d7, p_a5);
		break;
	case 4:
		krang_lasers_wait(a0);
		break;
	case 8:
		krang_lasers_end(a0, &d7, p_a5);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* Krang fires a stream of five lasers */
void krang_lasers_fire(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t laser = 0;
	uint16_t t1 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags &= ~2u;
		OBJECT(a0)->state++;
		d0 = 4u;
		for (;;)
		{
			laser = OBJECT_ADDRESS(32);
			d7 = (d7 & ~0xFFu) | 8u;
			d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
			find_free_object(&d7, &laser);
			if ((uint8_t)d7 == 0u)
				break;
			*p_a5 = krang_start_laser(a0, laser);
			d7 = d0 * 2u;
			OBJECT(laser)->krang_laser.delay = d7;
			OBJECT(laser)->krang_laser.last = 0u;
			t1 = d0 - 1u;
			d0 = t1;
			if (t1 == 0xFFFFu)
			{
				OBJECT(laser)->krang_laser.last |= 0x80u;
				break;
			}
		}
		if ((uint8_t)d0 != 4u)
		{
			d7 = (d7 & ~0xFFFFu) | 0x1Bu;
			queue_sound((uint8_t)d7, laser);
		}
	}
	*p_d7 = d7;
}

/* Krang waits for all his lasers to be on their way */
void krang_lasers_wait(uint32_t a0)
{
	if (krang_lasers_waiting == 0u)
	{
		OBJECT(a0)->state++;
		OBJECT(a0)->krang.timer = 0x14u;
		OBJECT(a0)->flags |= 2u;
	}
}

/* after his lasers Krang walks again */
void krang_lasers_end(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->krang.timer;
	OBJECT(a0)->krang.timer = timer - 1u;
	if (timer == 0u)
	{
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->state = 0u;
		d0 = 7u;
		krang_pick_move(d0, a0, p_d7, p_a5);
	}
}

/* a turtle's attack takes one of Krang's hits; with none left he starts to burst */
uint32_t krang_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;
	uint8_t hits_left = 0;

	krang_posed_last = 0u;
	OBJECT(a0)->krang.hurt = 0x80u;
	OBJECT(a0)->colour = 0xFFu;
	hits_left = OBJECT(a0)->krang.hits_left;
	OBJECT(a0)->krang.hits_left = hits_left - 1u;
	if (hits_left != 1u)
	{
		OBJECT(a0)->health_bars = 0xAu;
		if (OBJECT(a0)->krang.hits_left == 1u)
			OBJECT(a0)->health_bars = 1u;
		OBJECT(a0)->routine++;
		OBJECT(a0)->health = 1u;
		OBJECT(a0)->flags &= ~2u;
		d7_2 = (d7 & ~0xFFu) | 0x82u;
		queue_sound((uint8_t)d7_2, 0u);
		animation = rom_00ECB8;
		set_animation(0u, a0, animation);
		return d7_2;
	}
	animation = rom_00ECCC;
	set_animation(0u, a0, animation);
	d7 &= ~0xFFu;
	queue_sound((uint8_t)d7, animation);
	d7 |= 0x8Eu;
	queue_sound((uint8_t)d7, animation);
	OBJECT(a0)->routine += 2u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->krang.laser_angle = 0u;
	OBJECT(a0)->krang.timer = 0u;
	OBJECT(a0)->flags &= ~6u;
	return d7;
}

/* Krang recovers from a hit and goes on */
void krang_recoil(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;

	if (OBJECT(a0)->krang.hits_left < 0x14u)
		OBJECT(a0)->colour = 6u;
	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->krang.hurt = 0u;
	OBJECT(a0)->krang.hit_delay = 0xCu;
	OBJECT(a0)->colour = 0xFFu;
	d0 = 6u;
	krang_pick_move(d0, a0, p_d7, p_a5);
}

/* Krang's end, step by step */
void krang_explode(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d7 = OBJECT(a0)->state;
	*p_d7 = (uint16_t)(*p_d7 << 2);
	switch (*p_d7)
	{
	case 0:
		krang_explode_start(a0);
		return;
	case 4:
		krang_explode_wait(a0);
		return;
	case 8:
		krang_explode_burst(a0, p_d7, p_a5);
		return;
	case 12:
		*p_d7 = krang_explode_next(*p_d7, a0);
		return;
	}
}

/* Krang stops, with his shadow, before he bursts */
void krang_explode_start(uint32_t a0)
{
	OBJECT(a0)->krang_explode.timer = 0x8Cu;
	OBJECT(a0)->shadow = 0xF66Cu;
	OBJECT(a0)->state++;
}

/* Krang's body falls apart */
void krang_explode_wait(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->krang_explode.timer;
	OBJECT(a0)->krang_explode.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->state++;
		animation = rom_00ECBC;
		set_animation(0u, a0, animation);
	}
}

/* an explosion bursts on Krang's body as it floats */
void krang_explode_burst(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;

	if (OBJECT(a0)->frame_time == 0u)
		d7 = krang_hover(a0);
	OBJECT(a0)->krang_explode.timer = 0xEu;
	OBJECT(a0)->state = 3u;
	a6 = OBJECT_ADDRESS(24);
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (uint8_t)d7_2;
	find_free_object(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
		boss_start_explosion(a0, a6, &d7_2, p_a5);
	else
	{
		OBJECT(a0)->routine++;
		OBJECT(a0)->state = 0u;
	}
	*p_d7 = d7_2;
}

void unreached_00E364(void)
{
}

/* the next of Krang's ten explosions */
uint32_t krang_explode_next(uint32_t d7, uint32_t a0)
{
	uint8_t timer = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->contacts |= 0x80u;
		d7 = krang_hover(a0);
	}
	timer = OBJECT(a0)->krang_explode.timer;
	OBJECT(a0)->krang_explode.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->state--;
		OBJECT(a0)->krang_explode.explosions++;
		if (OBJECT(a0)->krang_explode.explosions == 0xAu)
		{
			OBJECT(a0)->routine++;
			OBJECT(a0)->state = 0u;
		}
	}
	return d7;
}

/* Krang's escape, step by step */
void krang_escape(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->state;
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		krang_escape_start(d0, a0, &d5, &d7);
		break;
	case 4:
		d7 = krang_escape_wait(d7, a0);
		break;
	case 8:
		d7 = krang_escape_dip(d7, a0);
		break;
	case 12:
		d7 = krang_escape_fly(d7, a0);
		break;
	case 16:
		krang_gone(a0);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* Krang's head comes out in his pod, saying he is invincible */
void krang_escape_start(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t None = *p_d7;
	uint16_t d0_2 = 0, d1 = 0, screen_y = 0;
	uint32_t animation = 0;

	animation = rom_00ECC0;
	set_animation(0u, a0, animation);
	*p_d7 = 0xB0u;
	queue_sound((uint8_t)*p_d7, animation);
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
	screen_y = OBJECT(a0)->screen_y;
	d1 = (uint16_t)(OBJECT(a0)->screen_x + 0x10u);
	say_im_invincible(d0_2, d1, screen_y, &d5, p_d7);
	OBJECT(a0)->state++;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the pod floats a while, then takes off */
uint32_t krang_escape_wait(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return krang_hover(a0);
	animation = rom_00ECC4;
	set_animation(0u, a0, animation);
	OBJECT(a0)->height_speed = 0x280;
	OBJECT(a0)->state++;
	return d7;
}

/* the pod dips, slower and slower */
uint32_t krang_escape_dip(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;
	uint16_t height_speed = 0;

	d7_2 = (d7 & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	OBJECT(a0)->height -= d7_2;
	height_speed = OBJECT(a0)->height_speed;
	OBJECT(a0)->height_speed = height_speed - 0x20u;
	if (height_speed < 0x20u)
	{
		d7_2 = (d7_2 & ~0xFFFFu) | 0x11u;
		queue_sound((uint8_t)d7_2, 0u);
		animation = rom_00ECC8;
		set_animation(0u, a0, animation);
		OBJECT(a0)->height_speed = 0x500;
		OBJECT(a0)->state++;
	}
	return d7_2;
}

/* the pod flies up off the screen */
uint32_t krang_escape_fly(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	OBJECT(a0)->height += d7_2;
	if (OBJECT(a0)->height >= 0xF000u)
	{
		krang_gone(a0);
		return d7_2;
	}
	return d7_2;
}

/* Krang is gone: one enemy less */
void krang_gone(uint32_t a0)
{
	enemies_on_screen--;
	remove_object(a0);
}

/* Krang floats up and down */
uint32_t krang_hover(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = frame_count;
	d7 = d7 & 0x3Eu;
	d7 = indexed_table_of_16_bit_values_00E48A[d7 / 2u];
	d7 = (uint16_t)(d7 + 0x4000u);
	OBJECT(a0)->height = d7;
	return d7;
}

/* picks Krang's next walk, charge or pose by its chances */
void krang_pick_move(uint32_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d6 = 0;
	uint32_t a6 = 0, d7 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	d7 = 0x10u;
	d7 = random_below((uint16_t)d7, a0);
	d6 = 3u;
	a6 = table_loaded_by_lea_00E4FE_ADDRESS + (uint16_t)(d0 << 2);
	for (;;)
	{
		t1 = mem_read8(a6 + (int16_t)d6);
		t2 = d7;
		d7 = (d7 & ~0xFFu) | (uint8_t)(t2 - t1);
		if (t2 < t1)
			break;
		t3 = d6 - 1u;
		d6 = t3;
		if (t3 == 0xFFFFu)
		{
			d6 = 2u;
			break;
		}
	}
	switch ((uint32_t)(int16_t)((uint32_t)d6 << 2))
	{
	case 0:
		krang_start_walk(a0, &d7, p_a5);
		break;
	case 4:
		d7 = krang_start_walk_on(a0);
		break;
	case 8:
		d7 = krang_start_charge(a0);
		break;
	case 12:
		d7 = krang_start_pose(d7, a0);
		break;
	}
	*p_d7 = d7;
}

/* Krang picks a turtle and walks at it; with none, he poses */
void krang_start_walk(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0, d7 = 0, ignored = 0;

	boss_pick_target(a0, &ignored, &d7, p_a5);
	if ((uint8_t)d7 == 0u)
		d7 = krang_start_pose(d7, a0);
	else
	{
		krang_posed_last = 0u;
		d7 = 8u;
		d7 = krang_set_move_time(d7, a0);
		OBJECT(a0)->krang.laser_angle = 0u;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->state = 0u;
		animation = rom_00ECA4;
		set_animation(0u, a0, animation);
	}
	*p_d7 = d7;
}

/* Krang walks on at his target */
uint32_t krang_start_walk_on(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 8u;
	d7 = krang_set_move_time(d7, a0);
	krang_posed_last = 0u;
	OBJECT(a0)->krang.laser_angle = 0u;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->state = 1u;
	return d7;
}

/* Krang runs at his target */
uint32_t krang_start_charge(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 8u;
	d7 = krang_set_move_time(d7, a0);
	krang_posed_last = 0u;
	OBJECT(a0)->krang.laser_angle = 0u;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->state = 2u;
	return d7;
}

/* Krang poses, with his cry the first time in a row */
uint32_t krang_start_pose(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->krang.laser_angle = 0u;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->state = 3u;
	if (krang_posed_last == 0u)
	{
		krang_posed_last = 1u;
		d7 = (d7 & ~0xFFFFu) | 0x8Fu;
		queue_sound((uint8_t)d7, 0u);
	}
	animation = rom_00ECB4;
	set_animation(0u, a0, animation);
	return d7;
}

/* Krang kicks the turtle close to him */
uint32_t krang_start_kick(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	krang_posed_last = 0u;
	OBJECT(a0)->krang.laser_angle = 0u;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->flags &= 0xBFu;
	OBJECT(a0)->attack &= 0x7Fu;
	if ((int8_t)OBJECT(a0)->krang.close_turtle >= 0)
	{
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->attack |= 0x80u;
	}
	OBJECT(a0)->krang.close_turtle = 0u;
	d7_2 = (d7 & ~0xFFu) | 8u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_00ECA8;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* Krang aims his lasers steeply, at a turtle close by */
void krang_start_lasers_steep(uint32_t a0)
{
	uint32_t animation = 0;

	krang_posed_last = 0u;
	OBJECT(a0)->krang.laser_angle = 2u;
	OBJECT(a0)->routine = 3u;
	OBJECT(a0)->state = 0u;
	animation = rom_00ECAC;
	if (OBJECT(a0)->krang.hits_left < 0x1Eu)
		animation = rom_00ECD4;
	set_animation(0u, a0, animation);
}

/* Krang aims his lasers at the middle angle */
void krang_start_lasers(uint32_t a0)
{
	uint32_t animation = 0;

	krang_posed_last = 0u;
	OBJECT(a0)->krang.laser_angle = 1u;
	OBJECT(a0)->routine = 3u;
	OBJECT(a0)->state = 0u;
	animation = rom_00ECAC;
	if (OBJECT(a0)->krang.hits_left < 0x1Eu)
		animation = rom_00ECD4;
	set_animation(0u, a0, animation);
}

/* Krang aims his lasers at the shallowest angle, far in front of him */
void krang_start_lasers_far(uint32_t a0)
{
	uint32_t animation = 0;

	krang_posed_last = 0u;
	OBJECT(a0)->krang.laser_angle = 0u;
	OBJECT(a0)->routine = 3u;
	OBJECT(a0)->state = 0u;
	animation = rom_00ECAC;
	if (OBJECT(a0)->krang.hits_left < 0x1Eu)
		animation = rom_00ECD4;
	set_animation(0u, a0, animation);
}

/* Krang draws back his arm to punch */
void krang_start_punch(uint32_t a0)
{
	uint32_t animation = 0;

	krang_posed_last = 0u;
	OBJECT(a0)->krang.laser_angle = 0u;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 1u;
	animation = rom_00ECB0;
	set_animation(0u, a0, animation);
}

/* how long Krang's walk lasts, at random */
uint32_t krang_set_move_time(uint32_t d7, uint32_t a0)
{
	d7 = random_below((uint16_t)d7, a0);
	OBJECT(a0)->krang.move_time = indexed_table_of_8_bit_values_00E700[d7];
	return d7;
}

/* aims Krang's run at his target */
void krang_aim_charge(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d0 = 0, d7 = 0;

	boss_direction_to_target(a0, &d0, p_a5);
	a6 = 0xE790u;
	d7 = krang_set_speeds((uint16_t)d0, d7, a0, a6);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* aims Krang's walk at his target */
void krang_aim_walk(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d0 = 0, d7 = 0;

	boss_direction_to_target(a0, &d0, p_a5);
	a6 = indexed_table_of_16_bit_values_00E750_ADDRESS;
	d7 = krang_set_speeds((uint16_t)d0, d7, a0, a6);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* Krang's speeds in the direction picked, and he turns that way */
uint32_t krang_set_speeds(uint16_t d0, uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;

	d0 = (uint16_t)((uint32_t)d0 << 2);
	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a6 + d0);
	OBJECT(a0)->x_speed = d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | mem_read16(a6 + 2u + d0);
	OBJECT(a0)->y_speed = d7_2;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->flags &= 0xBFu;
	if (OBJECT(a0)->x_speed >= 0)
		OBJECT(a0)->flags |= 0x40u;
	return d7_2;
}

/* Krang can be hit again after a while; weak, he flashes faster and faster */
uint32_t krang_count_down(uint32_t d5, uint32_t a0)
{
	uint8_t d6 = 0, d7 = 0;
	uint32_t d5_2 = 0;
	uint8_t hit_delay = 0;

	d5_2 = (d5 & ~0xFFu) | 6u;
	d6 = 0xFFu;
	if (OBJECT(a0)->krang.hit_delay != 0u)
	{
		hit_delay = OBJECT(a0)->krang.hit_delay;
		OBJECT(a0)->krang.hit_delay = hit_delay - 1u;
		if (hit_delay == 1u)
			OBJECT(a0)->flags |= 2u;
	}
	if (OBJECT(a0)->krang.hits_left >= 0x1Eu)
		return d5_2;
	d7 = 0x3Cu;
	if (OBJECT(a0)->krang.hits_left < 0x14u)
	{
		d7 = 8u;
		if (OBJECT(a0)->krang.hits_left < 0xAu)
			d7 = 1u;
	}
	OBJECT(a0)->colour = d6;
	if ((d7 & (uint8_t)frame_count) == 0u)
		OBJECT(a0)->colour = d5_2;
	return d5_2;
}

/* Krang moves, kept on the floor and on the screen */
uint32_t krang_move(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = move_by_speeds(a0);
	if (OBJECT(a0)->y >= 0x8000u)
		OBJECT(a0)->y = 0x8000u;
	if (OBJECT(a0)->y < reset_ADDRESS)
		OBJECT(a0)->y = reset_ADDRESS;
	if ((int16_t)OBJECT(a0)->screen_x < 0)
		OBJECT(a0)->x += 0x800u;
	return d7;
}

/* which turtle is close to Krang, and on which side */
void krang_find_close_turtle(uint32_t a0, uint32_t *p_d0, uint32_t *p_d5)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = 0;
	uint32_t d0 = 0, object = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	object = OBJECT_ADDRESS(3);
	d6 = 3u;
	d0 = 0u;
	do
	{
		if ((players_in_play & shl32(1u, (int)(d6 & 7u))) != 0u && (players_knocked_out & shl32(1u, (int)(d6 & 7u))) == 0u && OBJECT(object)->routine != 4u)
		{
			t1 = OBJECT(object)->screen_y - OBJECT(a0)->screen_y;
			d5 = t1;
			if ((int16_t)t1 < 0)
				d5 = (uint16_t)~d5;
			if (d5 < 0xBu)
			{
				t2 = OBJECT(object)->screen_x - OBJECT(a0)->screen_x;
				d5 = t2;
				if ((int16_t)t2 < 0)
				{
					d0 = d0 | 0x80u;
					d5 = (uint16_t)~d5;
				}
				if (d5 < 0x3Au)
				{
					d0 |= shl32(1u, (int)(d6 & 0x1Fu));
					break;
				}
			}
		}
		d0 = 0u;
		t3 = d6 - 1u;
		d6 = t3;
		object -= 0x50u;
	} while (t3 != 0xFFFFu);
	*p_d0 = d0;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
}

/* which turtle is level with Krang and in front of him, far enough */
void krang_find_turtle_in_front(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = 0;
	uint32_t d7 = 0, object = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	object = OBJECT_ADDRESS(3);
	d6 = 3u;
	d7 = 0u;
	for (;;)
	{
		if ((players_in_play & shl32(1u, (int)(d6 & 7u))) == 0u || (players_knocked_out & shl32(1u, (int)(d6 & 7u))) != 0u || OBJECT(object)->routine == 4u)
		{
			t1 = d6 - 1u;
			d6 = t1;
			object -= 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		t2 = OBJECT(object)->screen_y - OBJECT(a0)->screen_y;
		d5 = t2;
		if ((int16_t)t2 < 0)
			d5 = (uint16_t)~d5;
		if (d5 >= 0xBu)
		{
			t1 = d6 - 1u;
			d6 = t1;
			object -= 0x50u;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
		{
			t3 = OBJECT(object)->screen_x - OBJECT(a0)->screen_x;
			d5 = t3;
			if ((int16_t)t3 < 0 || d5 < 0x3Eu)
			{
				t1 = d6 - 1u;
				d6 = t1;
				object -= 0x50u;
				if (t1 == 0xFFFFu)
					break;
				continue;
			}
			d7 |= shl32(1u, (int)(d6 & 0x1Fu));
			break;
		}
		t4 = OBJECT(object)->screen_x - OBJECT(a0)->screen_x;
		d5 = t4;
		if ((int16_t)t4 < 0)
		{
			d5 = (uint16_t)~d5;
			if (d5 >= 0x3Eu)
			{
				d7 |= shl32(1u, (int)(d6 & 0x1Fu));
				break;
			}
		}
		t1 = d6 - 1u;
		d6 = t1;
		object -= 0x50u;
		if (t1 == 0xFFFFu)
			break;
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d7 = d7;
}

/* the curtain where Krang appears shimmers */
void krang_curtain_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->colour = 8u;
	OBJECT(a0)->animation_delay = 0u;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	animation = rom_015E02;
	set_animation(0u, a0, animation);
	krang_curtain = a0;
	OBJECT(a0)->routine++;
}

/* the curtain breaks up */
uint32_t krang_curtain_open(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	d7_2 = (d7 & ~0xFFFFu) | 0x16u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = rom_015E06;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the curtain is gone, and Krang starts */
void krang_curtain_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	remove_object(a0);
}

/* one laser of Krang's stream, from his body at the angle he aims */
uint32_t krang_start_laser(uint32_t a0, uint32_t laser)
{
	uint16_t d7 = 0;
	uint32_t a5 = 0;

	OBJECT(laser)->flags = 1u;
	OBJECT(laser)->contacts = 0u;
	OBJECT(laser)->kind = 0x67u;
	OBJECT(laser)->parameter = 0u;
	OBJECT(laser)->colour = 0xFFu;
	OBJECT(laser)->animation_delay = 0u;
	place_at_object(a0, laser);
	OBJECT(laser)->krang_laser.flipped = 0u;
	a5 = indexed_table_of_16_bit_values_00EA9E_ADDRESS;
	d7 = OBJECT(a0)->krang.laser_angle;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		d7 = (uint8_t)(d7 + 3u);
		OBJECT(laser)->krang_laser.flipped |= 0x80u;
	}
	d7 = (uint16_t)((uint32_t)d7 << 2);
	OBJECT(laser)->x += (int16_t)DATA16(a5 + d7);
	OBJECT(laser)->height += DATA16(a5 + 2u + d7);
	OBJECT(laser)->y -= 0x200u;
	OBJECT(laser)->krang_laser.shooter = a0;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(laser)->flags |= 0x40u;
	OBJECT(laser)->parameter = OBJECT(a0)->krang.laser_angle;
	OBJECT(laser)->routine = 0u;
	OBJECT(laser)->state = 0u;
	krang_lasers_waiting++;
	return a5;
}

/* a laser of Krang's stream, at its angle */
uint32_t krang_laser_start(uint32_t a0)
{
	uint16_t d7 = 0;
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x84u;
	stats = krang_laser_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->flags &= 0xBFu;
	d7 = (uint16_t)((uint32_t)OBJECT(a0)->parameter << 2);
	OBJECT(a0)->x_speed = indexed_table_of_16_bit_values_00EB1E[d7 / 2u];
	OBJECT(a0)->height_speed = rom_00EB20[d7 / 2u];
	if ((int8_t)OBJECT(a0)->krang_laser.flipped < 0)
	{
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->attack |= 0x80u;
		OBJECT(a0)->x_speed = ~OBJECT(a0)->x_speed;
	}
	d7_2 = OBJECT(a0)->parameter;
	d7_2 = (uint16_t)(d7_2 << 2);
	animation = animations_00F760[d7_2 / 4u];
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the laser waits its turn in the stream */
void krang_laser_wait(uint32_t a0)
{
	uint8_t delay = 0;

	delay = OBJECT(a0)->krang_laser.delay;
	OBJECT(a0)->krang_laser.delay = delay - 1u;
	if (delay == 0u)
	{
		OBJECT(a0)->routine++;
		krang_lasers_waiting--;
	}
}

/* the laser goes down to the floor; the stream's last one sparks there */
uint32_t krang_laser_fly(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0;

	d7 = move_by_speeds(a0);
	if ((int16_t)OBJECT(a0)->height >= 0)
		return d7;
	if (OBJECT(a0)->krang_laser.last != 0u)
	{
		OBJECT(a0)->height = 0u;
		OBJECT(a0)->routine++;
		animation = rom_00F76C;
		set_animation(0u, a0, animation);
		return d7;
	}
	remove_object(a0);
	return d7;
}

/* the laser's spark ends and it is gone */
void krang_laser_spark(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	remove_object(a0);
}

/* Krang's fist flies off his arm */
uint32_t krang_start_fist(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0, fist = 0;

	fist = OBJECT_ADDRESS(24);
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (uint8_t)d7_2;
	find_free_object(&d7_2, &fist);
	OBJECT(fist)->flags = 1u;
	OBJECT(fist)->contacts = 0u;
	OBJECT(fist)->kind = 0x66u;
	OBJECT(fist)->parameter = 0u;
	OBJECT(fist)->colour = 0xFFu;
	OBJECT(fist)->animation_delay = 0u;
	place_at_object(a0, fist);
	OBJECT(fist)->krang_fist.flipped = 0u;
	d7_2 = (d7_2 & ~0xFFFFu) | 0x4500u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		d7_2 = (int16_t)~d7_2;
		OBJECT(fist)->krang_fist.flipped |= 0x80u;
	}
	OBJECT(fist)->x += d7_2;
	OBJECT(fist)->y -= 0x200u;
	OBJECT(fist)->height = 0x3200u;
	OBJECT(fist)->krang_fist.shooter = a0;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(fist)->routine = 0u;
	OBJECT(fist)->state = 0u;
	return d7_2;
}

/* Krang's fist sets off across the screen */
void krang_fist_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = krang_fist_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->flags &= 0xBFu;
	OBJECT(a0)->x_speed = 0x680;
	OBJECT(a0)->flags |= 0x40u;
	if ((int8_t)OBJECT(a0)->krang_fist.flipped < 0)
	{
		OBJECT(a0)->flags &= 0xBFu;
		OBJECT(a0)->attack &= 0x7Fu;
		OBJECT(a0)->x_speed = ~OBJECT(a0)->x_speed;
	}
	animation = animations_00F674;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
}

/* the fist comes off and flies, hurting */
uint32_t krang_fist_launch(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		animation = rom_00F678;
		set_animation(0u, a0, animation);
		d7 = (d7 & ~0xFFu) | 6u;
		queue_sound((uint8_t)d7, animation);
		OBJECT(a0)->flags |= 4u;
		OBJECT(a0)->routine++;
	}
	return d7;
}

/* the fist flies across; off the screen, Krang's punch is over */
uint32_t krang_fist_fly(uint32_t d7, uint32_t a0)
{
	uint32_t x_speed = 0;

	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		krang_fist_flying = 0u;
		remove_object(a0);
		return d7;
	}
	x_speed = OBJECT(a0)->x_speed;
	OBJECT(a0)->x += x_speed;
	return x_speed;
}
