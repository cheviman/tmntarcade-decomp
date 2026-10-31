/**
 *    Name:        objects/rock_soldiers.c
 *    Description: the two rock soldier bosses (areas 7 and 8), their shots, bars and rubble
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the building site's rock soldier comes in, by the state of his way in */
void rock_soldier_site_enter(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->state;
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		d7 = rock_soldier_site_start(a0);
		break;
	case 4:
		d7 = rock_soldier_site_enter_wait_for_scroll(d7, a0);
		break;
	case 8:
		rock_soldier_site_enter_wait(a0);
		break;
	case 12:
		rock_soldier_site_enter_drop(d0, a0, &d5, &d7);
		break;
	case 16:
		rock_soldier_site_enter_land(a0, &d7, p_a5);
		break;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* the rock soldier waits high up, his hits set by the players in play; the area is not cleared */
uint32_t rock_soldier_site_start(uint32_t a0)
{
	uint16_t d6 = 0;
	uint32_t animation = 0, d7 = 0, stats = 0;
	uint16_t t1 = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = rock_soldier_site_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->rock_soldier.hits_left = OBJECT(a0)->health_bars;
	d7 = 0u;
	d6 = 3u;
	do
	{
		if ((players_in_play & shl32(1u, (int)(d6 & 7u))) != 0u)
			d7 = (uint8_t)(d7 + 1u);
		t1 = d6 - 1u;
		d6 = t1;
	} while (t1 != 0xFFFFu);
	OBJECT(a0)->rock_soldier.players = d7;
	d7 = (uint16_t)(d7 << 1);
	OBJECT(a0)->rock_soldier.hits_left += d7;
	animation = rom_014DA0[0];
	set_animation(0u, a0, animation);
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->rock_soldier.explosions = 0u;
	OBJECT(a0)->rock_soldier.hurt = 0u;
	OBJECT(a0)->rock_soldier.hit_delay = 0u;
	OBJECT(a0)->rock_soldier.blows = 0u;
	OBJECT(a0)->state++;
	enemies_on_screen++;
	mousers_break_down = 0u;
	boss_defeated = 0u;
	return d7;
}

/* once the scroll reaches him the music fades */
uint32_t rock_soldier_site_enter_wait_for_scroll(uint32_t d7, uint32_t a0)
{
	if (LAYER(LAYER_B)->x >= 0x6E000u)
	{
		d7 = 0xFEu;
		music = d7;
		queue_sound((uint8_t)d7, 0u);
		OBJECT(a0)->state++;
		OBJECT(a0)->rock_soldier.timer = 0x50u;
	}
	return d7;
}

/* after a while he drops */
void rock_soldier_site_enter_wait(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->rock_soldier.timer;
	OBJECT(a0)->rock_soldier.timer = timer - 1u;
	if (timer == 1u)
	{
		animation = rom_014DA4;
		set_animation(0u, a0, animation);
		OBJECT(a0)->y_speed = 0x200;
		OBJECT(a0)->height_speed = -0x800;
		OBJECT(a0)->state++;
	}
}

/* he drops to the ground, then the boss music and his balloon "Crash the turtles!" */
void rock_soldier_site_enter_drop(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0_2 = 0, d1 = 0, d2 = 0;
	uint32_t d7 = 0;

	d7 = rock_soldier_site_move(a0);
	if (OBJECT(a0)->height == 0u)
	{
		d7 = (d7 & ~0xFFFFu) | 0x3Eu;
		queue_sound((uint8_t)d7, 0u);
		d7 = (d7 & ~0xFFFFu) | 0x64u;
		music = d7;
		queue_sound((uint8_t)d7, 0u);
		d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
		d1 = (uint16_t)(OBJECT(a0)->screen_x - 0x20u);
		d2 = (uint16_t)(OBJECT(a0)->screen_y + 0x20u);
		say_crash_the_turtles(d0_2, d1, d2, &d5, &d7);
		OBJECT(a0)->rock_soldier.timer = 0x28u;
		OBJECT(a0)->state++;
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* the screen shakes from his landing, then he fights */
void rock_soldier_site_enter_land(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->rock_soldier.timer;
	OBJECT(a0)->rock_soldier.timer = timer - 1u;
	if (timer == 0u)
	{
		OBJECT(a0)->flags |= 6u;
		d0 = 0u;
		rock_soldier_site_next_move(d0, a0, p_d7, p_a5);
		return;
	}
	*p_d7 = rock_soldier_site_shake_screen(*p_d7);
}

/* Unused: ends the way in, the next routine */
void rock_soldier_site_enter_end(uint32_t a0)
{
	mem_write16(a0 + 0x30u, 0u);
	mem_write8(a0 + 5u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

/* the screen shakes */
uint32_t rock_soldier_site_shake_screen(uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)frame_count;
	d7_2 = d7_2 & ~0xFDu;
	d7_2 = (d7_2 & ~0xFFu) | (uint8_t)(d7_2 << 1);
	d7_2 = (d7_2 & ~0xFFu) | (uint8_t)(d7_2 + LAYER(LAYER_B)->y_pixel);
	d7_2 = (d7_2 & ~0xFFu) | (uint8_t)(0u - d7_2);
	layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | (d7_2 & 0xFFu);
	return d7_2;
}

/* he strikes a turtle close by at a chance, else goes on with his move */
void rock_soldier_site_think(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint8_t d7_2 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, animation = 0, d0 = 0, d1_2 = 0, d7 = 0, ignored = 0;

	rock_soldier_site_weak_flash(a0, &d5, &ignored);
	if (OBJECT(a0)->state == 3u || OBJECT(a0)->state == 4u)
	{
		d7 = OBJECT(a0)->state;
		d7 = (uint16_t)(d7 << 2);
		switch (d7)
		{
		case 0:
			rock_soldier_site_walk(a0, &d5, &d7, p_a5);
			break;
		case 4:
			rock_soldier_site_walk_on(a0, &d5, &d7, p_a5);
			break;
		case 8:
			rock_soldier_site_stand(a0, &d5, &d7, p_a5);
			break;
		case 12:
			d7 = rock_soldier_site_jump(d7, a0);
			break;
		case 16:
			rock_soldier_site_jump_land(a0, &d5, &d7, p_a5);
			break;
		}
	}
	else
	{
		rock_soldier_find_close_turtle(a0, &d0, &d5);
		if ((uint8_t)d0 == 0u)
		{
			d7 = OBJECT(a0)->state;
			d7 = (uint16_t)(d7 << 2);
			switch (d7)
			{
			case 0:
				rock_soldier_site_walk(a0, &d5, &d7, p_a5);
				break;
			case 4:
				rock_soldier_site_walk_on(a0, &d5, &d7, p_a5);
				break;
			case 8:
				rock_soldier_site_stand(a0, &d5, &d7, p_a5);
				break;
			case 12:
				d7 = rock_soldier_site_jump(d7, a0);
				break;
			case 16:
				rock_soldier_site_jump_land(a0, &d5, &d7, p_a5);
				break;
			}
		}
		else
		{
			a6 = indexed_table_of_8_bit_values_01175A_ADDRESS;
			d1 = (uint16_t)((uint32_t)OBJECT(a0)->rock_soldier.blows << 1);
			if ((int8_t)d0 < 0)
			{
				if ((OBJECT(a0)->flags & 0x40u) == 0u)
					d1 = (uint16_t)((d1 & ~0xFFu) | (uint8_t)(d1 + 1u));
			}
			else if ((OBJECT(a0)->flags & 0x40u) != 0u)
				d1 = (uint16_t)((d1 & ~0xFFu) | (uint8_t)(d1 + 1u));
			d1_2 = DATA8(a6 + (uint16_t)(d1 + ((uint32_t)turtles_in_play << 2)));
			d7 = 0x40u;
			d7 = random_below((uint16_t)d7, a0);
			if (d1_2 <= (uint8_t)d7)
			{
				d7 = OBJECT(a0)->state;
				d7 = (uint16_t)(d7 << 2);
				switch (d7)
				{
				case 0:
					rock_soldier_site_walk(a0, &d5, &d7, p_a5);
					break;
				case 4:
					rock_soldier_site_walk_on(a0, &d5, &d7, p_a5);
					break;
				case 8:
					rock_soldier_site_stand(a0, &d5, &d7, p_a5);
					break;
				case 12:
					d7 = rock_soldier_site_jump(d7, a0);
					break;
				case 16:
					rock_soldier_site_jump_land(a0, &d5, &d7, p_a5);
					break;
				}
			}
			else
			{
				OBJECT(a0)->rock_soldier.close_turtle = d0;
				OBJECT(a0)->rock_soldier.explosions = 0u;
				OBJECT(a0)->routine = 3u;
				OBJECT(a0)->state = 0u;
				OBJECT(a0)->flags &= 0xBFu;
				OBJECT(a0)->attack &= 0x7Fu;
				if ((int8_t)OBJECT(a0)->rock_soldier.close_turtle >= 0)
				{
					OBJECT(a0)->flags |= 0x40u;
					OBJECT(a0)->attack |= 0x80u;
				}
				OBJECT(a0)->rock_soldier.close_turtle = 0u;
				d7_2 = 8u;
				queue_sound(d7_2, a6);
				d7 = turtles_in_play;
				d7 = (uint16_t)(d7 << 2);
				d7 = (d7 & ~0xFFu) | (uint8_t)(d7 + OBJECT(a0)->rock_soldier.blows);
				d7 = (d7 & ~0xFFu) | indexed_table_of_8_bit_values_011D1A[d7];
				animation = TABLE32(rom_014DA0, d7);
				set_animation(d1_2, a0, animation);
				OBJECT(a0)->rock_soldier.blows++;
				if (OBJECT(a0)->rock_soldier.blows >= 4u)
					OBJECT(a0)->rock_soldier.blows = 3u;
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

/* he walks at his target, aiming at it now and then */
void rock_soldier_site_walk(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0, move_time = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)frame_count;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
		boss_aim_at_target(a0, &ignored, &d7_2, p_a5);
	t2 = d7_2 & 1u;
	d7_2 = (d7_2 & ~0xFFu) | t2;
	if (t2 == 0u)
		d7_2 = rock_soldier_site_move(a0);
	move_time = OBJECT(a0)->rock_soldier.move_time;
	OBJECT(a0)->rock_soldier.move_time = move_time - 1u;
	if (move_time == 0u)
	{
		d0 = 1u;
		rock_soldier_site_move_done(d0, a0, &d5, &d7_2, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

/* he walks on at his target */
void rock_soldier_site_walk_on(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0, move_time = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)frame_count;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
		boss_aim_at_target(a0, &ignored, &d7_2, p_a5);
	if ((frame_count & 2u) == 0u)
		d7_2 = rock_soldier_site_move(a0);
	move_time = OBJECT(a0)->rock_soldier.move_time;
	OBJECT(a0)->rock_soldier.move_time = move_time - 1u;
	if (move_time == 0u)
	{
		d0 = 2u;
		rock_soldier_site_move_done(d0, a0, &d5, &d7_2, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

/* he stands a while */
void rock_soldier_site_stand(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->rock_soldier.move_time;
	OBJECT(a0)->rock_soldier.move_time = move_time - 1u;
	if (move_time != 0u)
		return;
	d0 = 3u;
	rock_soldier_site_move_done(d0, a0, &d5, p_d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* he is in the air until he lands */
uint32_t rock_soldier_site_jump(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint16_t t1 = 0;

	d7_2 = (d7 & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	t1 = OBJECT(a0)->height + d7_2;
	OBJECT(a0)->height = t1;
	if ((int16_t)t1 >= 0)
	{
		OBJECT(a0)->rock_soldier.move_time--;
		OBJECT(a0)->height_speed -= 0x80u;
		return d7_2;
	}
	d7_2 = (d7_2 & ~0xFFFFu) | 0x3Fu;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->height = 0u;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	return d7_2;
}

/* the screen shakes from his landing, then he can be hit again */
void rock_soldier_site_jump_land(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0;
	uint8_t move_time = 0;

	*p_d7 = rock_soldier_site_shake_screen(*p_d7);
	move_time = OBJECT(a0)->rock_soldier.move_time;
	OBJECT(a0)->rock_soldier.move_time = move_time - 1u;
	if (move_time == 0u)
	{
		OBJECT(a0)->flags |= 2u;
		d0 = 4u;
		rock_soldier_site_move_done(d0, a0, &d5, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* a move over: a burst at a turtle in front within reach, else the next move */
void rock_soldier_site_move_done(uint32_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t animation = 0, d7 = 0;

	rock_soldier_find_turtle_ahead(a0, &d5, &d7);
	if ((uint8_t)d7 != 0u)
	{
		OBJECT(a0)->rock_soldier.explosions = 0u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->rock_soldier.shot_hit = 0u;
		d7 = 4u;
		d7 = random_below((uint16_t)d7, a0);
		OBJECT(a0)->rock_soldier.timer = indexed_table_of_8_bit_values_011DEE[d7];
		OBJECT(a0)->rock_soldier.move_time = 0x20u;
		animation = rom_014DB0;
		set_animation(0u, a0, animation);
	}
	else
		rock_soldier_site_next_move(d0, a0, &d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

/* he fires gun blasts until the burst is over */
void rock_soldier_site_fire(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint32_t animation = 0, blast = 0, d5 = 0, d7_2 = 0;
	uint8_t timer = 0, move_time = 0, t1 = 0;

	rock_soldier_site_weak_flash(a0, &d5, &d7);
	timer = OBJECT(a0)->rock_soldier.timer;
	OBJECT(a0)->rock_soldier.timer = timer - 1u;
	if (timer == 0u)
	{
		OBJECT(a0)->routine++;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->rock_soldier.shot_hit = 0u;
		animation = rom_014DB0;
		set_animation(0u, a0, animation);
	}
	else
	{
		move_time = OBJECT(a0)->rock_soldier.move_time;
		OBJECT(a0)->rock_soldier.move_time = move_time - 1u;
		if (move_time != 0u)
		{
			d7_2 = (d7 & ~0xFFu) | OBJECT(a0)->rock_soldier.timer;
			t1 = d7_2 & 3u;
			d7 = (d7_2 & ~0xFFu) | t1;
			if (t1 == 0u)
			{
				blast = OBJECT_ADDRESS(24);
				d7 = (d7 & ~0xFFu) | 8u;
				d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
				find_free_object(&d7, &blast);
				if ((uint8_t)d7 != 0u)
				{
					OBJECT(blast)->flags = 1u;
					OBJECT(blast)->contacts = 0u;
					OBJECT(blast)->kind = 0x34u;
					OBJECT(blast)->parameter = 0u;
					OBJECT(blast)->colour = 0xFFu;
					OBJECT(blast)->animation_delay = 0u;
					place_at_object(a0, blast);
					OBJECT(blast)->gun_blast.flies_left = 0u;
					d7 = (d7 & ~0xFFFFu) | 0x4800u;
					if ((OBJECT(a0)->flags & 0x40u) == 0u)
					{
						d7 = (int16_t)~d7;
						OBJECT(blast)->gun_blast.flies_left |= 0x80u;
					}
					OBJECT(blast)->x += d7;
					OBJECT(blast)->height = 0x3000u;
					OBJECT(blast)->gun_blast.shooter = a0;
					if ((OBJECT(a0)->flags & 0x40u) == 0u)
						OBJECT(blast)->flags |= 0x40u;
					OBJECT(blast)->routine = 0u;
					OBJECT(blast)->state = 0u;
				}
			}
		}
		else
		{
			OBJECT(a0)->rock_soldier.move_time = 0u;
			if ((int8_t)OBJECT(a0)->rock_soldier.shot_hit < 0)
			{
				OBJECT(a0)->routine++;
				OBJECT(a0)->state = 0u;
				OBJECT(a0)->rock_soldier.shot_hit = 0u;
				animation = rom_014DB0;
				set_animation(0u, a0, animation);
			}
			else
			{
				d7_2 = (d7 & ~0xFFu) | OBJECT(a0)->rock_soldier.timer;
				t1 = d7_2 & 3u;
				d7 = (d7_2 & ~0xFFu) | t1;
				if (t1 == 0u)
				{
					blast = OBJECT_ADDRESS(24);
					d7 = (d7 & ~0xFFu) | 8u;
					d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
					find_free_object(&d7, &blast);
					if ((uint8_t)d7 != 0u)
					{
						OBJECT(blast)->flags = 1u;
						OBJECT(blast)->contacts = 0u;
						OBJECT(blast)->kind = 0x34u;
						OBJECT(blast)->parameter = 0u;
						OBJECT(blast)->colour = 0xFFu;
						OBJECT(blast)->animation_delay = 0u;
						place_at_object(a0, blast);
						OBJECT(blast)->gun_blast.flies_left = 0u;
						d7 = (d7 & ~0xFFFFu) | 0x4800u;
						if ((OBJECT(a0)->flags & 0x40u) == 0u)
						{
							d7 = (int16_t)~d7;
							OBJECT(blast)->gun_blast.flies_left |= 0x80u;
						}
						OBJECT(blast)->x += d7;
						OBJECT(blast)->height = 0x3000u;
						OBJECT(blast)->gun_blast.shooter = a0;
						if ((OBJECT(a0)->flags & 0x40u) == 0u)
							OBJECT(blast)->flags |= 0x40u;
						OBJECT(blast)->routine = 0u;
						OBJECT(blast)->state = 0u;
					}
				}
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

/* the blow, or the gun held up after the burst, plays out; then the next move */
void rock_soldier_site_finish_attack(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0, d5 = 0;

	rock_soldier_site_weak_flash(a0, &d5, p_d7);
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->rock_soldier.hurt = 0u;
		d0 = 5u;
		rock_soldier_site_next_move(d0, a0, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* a hit makes the rock soldier flinch, or the last one defeats him */
void rock_soldier_struck(uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	uint8_t d7 = 0;
	uint32_t a1 = 0, animation = 0;
	uint8_t hits_left = 0;

	OBJECT(a0)->rock_soldier.hurt = 0x80u;
	OBJECT(a0)->colour = 0xFFu;
	a1 = rom_014DA0_ADDRESS;
	if (OBJECT(a0)->kind != 0x1Eu)
		a1 = rom_0153D8_ADDRESS;
	hits_left = OBJECT(a0)->rock_soldier.hits_left;
	OBJECT(a0)->rock_soldier.hits_left = hits_left - 1u;
	if (hits_left == 1u)
	{
		animation = DATA32(a1 + 0x1Cu);
		set_animation(0u, a0, animation);
		if (enemies_on_screen == 1u)
		{
			d7 = 0u;
			queue_sound(d7, animation);
		}
		d7 = 0x88u;
		queue_sound(d7, animation);
		OBJECT(a0)->routine += 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->rock_soldier.explosions = 0u;
		OBJECT(a0)->rock_soldier.timer = 0u;
		OBJECT(a0)->rock_soldier.blows = 0u;
		OBJECT(a0)->flags &= ~6u;
	}
	else
	{
		OBJECT(a0)->health_bars = 0xAu;
		if (OBJECT(a0)->rock_soldier.hits_left == 1u)
			OBJECT(a0)->health_bars = 1u;
		OBJECT(a0)->routine++;
		OBJECT(a0)->health = 1u;
		OBJECT(a0)->rock_soldier.blows = 0u;
		OBJECT(a0)->rock_soldier.timer = 0x1Cu;
		OBJECT(a0)->flags &= ~2u;
		d7 = 0x82u;
		queue_sound(d7, 0u);
		animation = DATA32(a1 + 0x18u);
		set_animation(0u, a0, animation);
	}
	*p_d7 = (*p_d7 & 0xFFFFFF00u) | d7;
	*p_a1 = a1;
}

/* the rock soldier gets over the hit and moves on */
void rock_soldier_recover(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0;
	uint8_t timer = 0;

	if (OBJECT(a0)->rock_soldier.hits_left < 0x14u)
		OBJECT(a0)->colour = 8u;
	timer = OBJECT(a0)->rock_soldier.timer;
	OBJECT(a0)->rock_soldier.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->rock_soldier.hurt = 0u;
		OBJECT(a0)->rock_soldier.hit_delay = 8u;
		OBJECT(a0)->colour = 0xFFu;
		d0 = 6u;
		if (OBJECT(a0)->kind == 0x1Eu)
			rock_soldier_site_next_move(d0, a0, p_d7, p_a5);
		else
			rock_soldier_technodrome_next_move(d0, a0, p_d7, p_a5);
	}
}

/* the defeated rock soldier, by the state of his defeat */
void rock_soldier_defeated(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d7 = OBJECT(a0)->state;
	*p_d7 = (uint16_t)(*p_d7 << 2);
	switch (*p_d7)
	{
	case 0:
		rock_soldier_defeated_start(a0);
		return;
	case 4:
		rock_soldier_defeated_wait(a0);
		return;
	case 8:
		rock_soldier_defeated_explode(a0, p_d7, p_a5);
		return;
	case 12:
		rock_soldier_defeated_next_explosion(a0);
		return;
	case 16:
		rock_soldier_defeated_crumble(a0, p_d7, p_a5);
		return;
	case 20:
		rock_soldier_defeated_stay();
		return;
	}
}

/* the defeated rock soldier stands a while */
void rock_soldier_defeated_start(uint32_t a0)
{
	OBJECT(a0)->rock_soldier.timer = 0x64u;
	OBJECT(a0)->state++;
}

/* he stands until the explosions */
void rock_soldier_defeated_wait(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->rock_soldier.timer;
	OBJECT(a0)->rock_soldier.timer = timer - 1u;
	if (timer == 1u)
		OBJECT(a0)->state++;
}

/* an explosion on him */
void rock_soldier_defeated_explode(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;

	OBJECT(a0)->rock_soldier.timer = 0xCu;
	OBJECT(a0)->state = 3u;
	a6 = OBJECT_ADDRESS(24);
	d7_2 = (d7 & ~0xFFu) | 8u;
	d7_2 = (uint8_t)d7_2;
	find_free_object(&d7_2, &a6);
	if ((uint8_t)d7_2 != 0u)
		boss_start_explosion(a0, a6, &d7_2, p_a5);
	else
		OBJECT(a0)->state = 4u;
	*p_d7 = d7_2;
}

/* the next explosion, until ten */
void rock_soldier_defeated_next_explosion(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->rock_soldier.timer;
	OBJECT(a0)->rock_soldier.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->state--;
		OBJECT(a0)->rock_soldier.explosions++;
		if (OBJECT(a0)->rock_soldier.explosions == 0xAu)
		{
			OBJECT(a0)->state = 4u;
			OBJECT(a0)->rock_soldier.timer = 0x96u;
		}
	}
}

/* rubble falls off him; then the boss is down and the area cleared */
void rock_soldier_defeated_crumble(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a6 = 0, rubble = 0;
	uint8_t timer = 0;
	uint16_t t1 = 0;

	timer = OBJECT(a0)->rock_soldier.timer;
	OBJECT(a0)->rock_soldier.timer = timer - 1u;
	if (timer == 0u)
	{
		OBJECT(a0)->state = 5u;
		enemies_on_screen--;
		mousers_break_down = 1u;
		boss_defeated = 1u;
	}
	else
	{
		d7 = IN_PAGE(d7, OBJECT(a0)->rock_soldier.timer);
		d0 = 3u;
		a6 = indexed_table_of_8_bit_values_011AD2_ADDRESS;
		do
		{
			if ((uint8_t)d7 == mem_read8(a6 + (int16_t)d0))
			{
				rubble = OBJECT_ADDRESS(32);
				d7 = IN_PAGE(d7, 8u);
				d7 = (uint8_t)d7;
				find_free_object(&d7, &rubble);
				if ((uint8_t)d7 != 0u)
				{
					OBJECT(rubble)->flags = 1u;
					OBJECT(rubble)->contacts = 0u;
					OBJECT(rubble)->kind = 0x41u;
					OBJECT(rubble)->parameter = 0u;
					OBJECT(rubble)->parameter = (uint8_t)d0;
					OBJECT(rubble)->colour = 8u;
					OBJECT(rubble)->animation_delay = 0u;
					place_at_object(a0, rubble);
					*p_a5 = indexed_table_of_8_bit_values_012108_ADDRESS;
					d7 = OBJECT(rubble)->parameter;
					d7 = (uint16_t)(d7 << 1);
					OBJECT(rubble)->x += (uint32_t)(int16_t)(int8_t)indexed_table_of_8_bit_values_012108[d7] << 8;
					OBJECT(rubble)->y += (uint32_t)(int16_t)(int8_t)rom_012109[d7] << 8;
					OBJECT(rubble)->height = 0x8000u;
					OBJECT(rubble)->routine = 0u;
					OBJECT(rubble)->state = 0u;
					break;
				}
				break;
			}
			t1 = d0 - 1u;
			d0 = t1;
		} while (t1 != 0xFFFFu);
	}
	*p_d7 = d7;
}

/* he stays a heap of rocks */
void rock_soldier_defeated_stay(void)
{
}

/* a turtle close enough to strike, and on which side */
void rock_soldier_find_close_turtle(uint32_t a0, uint32_t *p_d0, uint32_t *p_d5)
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
			if (d5 < 0xCu)
			{
				t2 = OBJECT(object)->screen_x - OBJECT(a0)->screen_x;
				d5 = t2;
				if ((int16_t)t2 < 0)
				{
					d0 = d0 | 0x80u;
					d5 = (uint16_t)~d5;
				}
				if (d5 < 0x3Cu)
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

/* a turtle in front of him at the range of his weapon */
void rock_soldier_find_turtle_ahead(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint16_t d6 = 0;
	uint32_t d7 = 0, object = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

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
		if (OBJECT(a0)->kind == 0x1Du)
		{
			if ((OBJECT(a0)->flags & 0x40u) != 0u)
			{
				t3 = OBJECT(object)->screen_x - OBJECT(a0)->screen_x;
				d5 = t3;
				if ((int16_t)t3 < 0 || d5 < 0x46u)
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
				if (d5 >= 0x46u)
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
			continue;
		}
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
		{
			t5 = OBJECT(object)->screen_x - OBJECT(a0)->screen_x;
			d5 = t5;
			if ((int16_t)t5 < 0 || d5 >= 0x8Cu)
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
		t6 = OBJECT(object)->screen_x - OBJECT(a0)->screen_x;
		d5 = t6;
		if ((int16_t)t6 < 0)
		{
			d5 = (uint16_t)~d5;
			if (d5 < 0x8Cu)
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

/* the next move by chance, by what he did before */
void rock_soldier_site_next_move(uint32_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d6 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	*p_d7 = 0x10u;
	*p_d7 = random_below((uint16_t)*p_d7, a0);
	d6 = 3u;
	a6 = table_loaded_by_lea_011C42_ADDRESS + (uint16_t)(d0 << 2);
	for (;;)
	{
		t1 = mem_read8(a6 + (int16_t)d6);
		t2 = *p_d7;
		*p_d7 = (uint8_t)(t2 - t1);
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
		*p_a5 = a5;
		rock_soldier_site_walk_start(a0, p_d7, p_a5);
		return;
	case 4:
		*p_d7 = rock_soldier_site_walk_on_start(a0);
		return;
	case 8:
		*p_d7 = rock_soldier_site_stand_start(a0);
		return;
	case 12:
		*p_d7 = rock_soldier_site_jump_start(a0);
		return;
	}
}

/* he picks a turtle and walks at it, or stands if there is none */
void rock_soldier_site_walk_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0, d7 = 0, ignored = 0;

	boss_pick_target(a0, &ignored, &d7, p_a5);
	if ((uint8_t)d7 == 0u)
		d7 = rock_soldier_site_stand_start(a0);
	else
	{
		d7 = 8u;
		d7 = rock_soldier_site_random_move_time(d7, a0);
		OBJECT(a0)->rock_soldier.explosions = 0u;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->state = 0u;
		animation = rom_014DA8;
		set_animation(0u, a0, animation);
	}
	*p_d7 = d7;
}

/* he walks on as he was */
uint32_t rock_soldier_site_walk_on_start(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 8u;
	d7 = rock_soldier_site_random_move_time(d7, a0);
	OBJECT(a0)->rock_soldier.explosions = 0u;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->state = 1u;
	return d7;
}

/* he stands a while */
uint32_t rock_soldier_site_stand_start(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0;

	d7 = 4u;
	d7 = rock_soldier_site_random_move_time(d7, a0);
	OBJECT(a0)->rock_soldier.explosions = 0u;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->state = 2u;
	animation = rom_014DAC;
	set_animation(0u, a0, animation);
	return d7;
}

/* he jumps where he stands, now and then with "Crash the turtles!" */
uint32_t rock_soldier_site_jump_start(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0;

	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->rock_soldier.move_time = 0x28u;
	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->rock_soldier.explosions = 0u;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->state = 3u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->shadow = 0x16C50u;
	d7 = 4u;
	d7 = random_below((uint16_t)d7, a0);
	if ((uint8_t)d7 == 0u)
	{
		d7 = 0xB1u;
		queue_sound((uint8_t)d7, 0u);
	}
	animation = rom_014DA4;
	set_animation(0u, a0, animation);
	return d7;
}

/* how long the move lasts, at random */
uint32_t rock_soldier_site_random_move_time(uint32_t d7, uint32_t a0)
{
	d7 = random_below((uint16_t)d7, a0);
	OBJECT(a0)->rock_soldier.move_time = rom_011DF2[d7];
	return d7;
}

/* his flashing as he weakens, in his colours */
void rock_soldier_technodrome_weak_flash(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint8_t d5 = 0, d6 = 0;

	d5 = 8u;
	d6 = 0xEu;
	*p_d7 = rock_soldier_weak_flash(d5, d6, *p_d7, a0);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
}

/* his flashing as he weakens, in his colours */
void rock_soldier_site_weak_flash(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint8_t d5 = 0, d6 = 0;

	d5 = 8u;
	d6 = 0xDu;
	*p_d7 = rock_soldier_weak_flash(d5, d6, *p_d7, a0);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
}

/* he can be hit again after a while, and flashes more as he weakens */
uint32_t rock_soldier_weak_flash(uint8_t d5, uint8_t d6, uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t hit_delay = 0, t1 = 0;

	if (OBJECT(a0)->rock_soldier.hit_delay != 0u)
	{
		hit_delay = OBJECT(a0)->rock_soldier.hit_delay;
		OBJECT(a0)->rock_soldier.hit_delay = hit_delay - 1u;
		if (hit_delay == 1u)
			OBJECT(a0)->flags |= 2u;
	}
	if (OBJECT(a0)->rock_soldier.hits_left >= 0x1Cu)
		return d7;
	d7_2 = 0x1Cu;
	if (OBJECT(a0)->rock_soldier.hits_left < 0x14u)
	{
		d7_2 = 8u;
		if (OBJECT(a0)->rock_soldier.hits_left < 0xAu)
			d7_2 = 1u;
	}
	OBJECT(a0)->colour = d6;
	t1 = d7_2 & (uint8_t)frame_count;
	d7 = t1;
	if (t1 == 0u)
		OBJECT(a0)->colour = d5;
	return d7;
}

/* he moves by his speeds within the area's depth */
uint32_t rock_soldier_site_move(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = move_by_speeds(a0);
	if (OBJECT(a0)->y >= 0x7800u)
		OBJECT(a0)->y = 0x7800u;
	if (OBJECT(a0)->y < reset_ADDRESS)
		OBJECT(a0)->y = reset_ADDRESS;
	return d7;
}

/* a gun blast flies the way the rock soldier faces */
uint32_t gun_blast_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x84u;
	stats = gun_blast_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->flags &= 0xBFu;
	OBJECT(a0)->x_speed = 0x400;
	if ((int8_t)OBJECT(a0)->gun_blast.flies_left < 0)
	{
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->attack &= 0x7Fu;
		OBJECT(a0)->x_speed = ~OBJECT(a0)->x_speed;
	}
	animation = rom_014FBE;
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 6u;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the blast swells as it flies, and tells its rock soldier when it hits a turtle */
uint32_t gun_blast_fly(uint32_t d7, uint32_t a0)
{
	uint32_t shooter = 0, x_speed = 0;

	if (OBJECT(a0)->frame_time == 0u || (OBJECT(a0)->flags & 0x20u) != 0u)
	{
		remove_object(a0);
		return d7;
	}
	x_speed = OBJECT(a0)->x_speed;
	OBJECT(a0)->x += x_speed;
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		shooter = OBJECT(a0)->gun_blast.shooter;
		OBJECT(shooter)->rock_soldier.shot_hit = 0x80u;
	}
	return x_speed;
}

/* a piece of rock falls off the defeated rock soldier */
uint32_t rubble_start(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x80u;
	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = -0x600;
	d7 = OBJECT(a0)->parameter;
	d7 = (uint16_t)(d7 << 2);
	animation = rom_0151AA[d7 / 4u];
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
	return d7;
}

/* the piece falls to the ground */
uint32_t rubble_fall(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = move_by_speeds(a0);
	if ((int16_t)OBJECT(a0)->height < 0)
	{
		OBJECT(a0)->height = 0u;
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = 0;
		OBJECT(a0)->height_speed = 0;
		d7 = (d7 & ~0xFFFFu) | 0x31u;
		queue_sound((uint8_t)d7, 0u);
		OBJECT(a0)->routine++;
	}
	return d7;
}

/* the piece stays on the ground */
void rubble_stay(void)
{
}

/* the Technodrome's rock soldier comes in, by the state of his way in */
void rock_soldier_technodrome_enter(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = 0;

	d7 = OBJECT(a0)->state;
	d7 = (uint16_t)(d7 << 2);
	switch (d7)
	{
	case 0:
		d7 = rock_soldier_technodrome_start(a0);
		break;
	case 4:
		d7 = rock_soldier_technodrome_enter_wait_for_scroll(d7, a0);
		break;
	case 8:
		d7 = rock_soldier_technodrome_enter_wait(d7, a0);
		break;
	case 12:
		rock_soldier_technodrome_enter_appear(a0, &d7, p_a5);
		break;
	}
	*p_d7 = d7;
}

/* the rock soldier waits unseen, his hits set by the players in play; the area is not cleared */
uint32_t rock_soldier_technodrome_start(uint32_t a0)
{
	uint16_t d6 = 0;
	uint32_t animation = 0, d7 = 0, stats = 0;
	uint16_t t1 = 0;

	stats = rock_soldier_technodrome_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->rock_soldier.hits_left = OBJECT(a0)->health_bars;
	d7 = 0u;
	d6 = 3u;
	do
	{
		if ((players_in_play & shl32(1u, (int)(d6 & 7u))) != 0u)
			d7 = (uint8_t)(d7 + 1u);
		t1 = d6 - 1u;
		d6 = t1;
	} while (t1 != 0xFFFFu);
	OBJECT(a0)->rock_soldier.players = d7;
	OBJECT(a0)->rock_soldier.hits_left += d7;
	animation = rom_0153D8[0];
	set_animation(0u, a0, animation);
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->rock_soldier.explosions = 0u;
	OBJECT(a0)->rock_soldier.hurt = 0u;
	OBJECT(a0)->rock_soldier.hit_delay = 0u;
	OBJECT(a0)->rock_soldier.blows = 0u;
	OBJECT(a0)->state++;
	enemies_on_screen++;
	missile_out = 0u;
	mousers_break_down = 0u;
	boss_defeated = 0u;
	return d7;
}

/* once the scroll reaches him the music fades */
uint32_t rock_soldier_technodrome_enter_wait_for_scroll(uint32_t d7, uint32_t a0)
{
	if (LAYER(LAYER_B)->x >= 0xD1000u)
	{
		d7 = 0xFEu;
		music = d7;
		queue_sound((uint8_t)d7, 0u);
		OBJECT(a0)->state++;
		OBJECT(a0)->rock_soldier.timer = 0x50u;
	}
	return d7;
}

/* the boss music starts */
uint32_t rock_soldier_technodrome_enter_wait(uint32_t d7, uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->rock_soldier.timer;
	OBJECT(a0)->rock_soldier.timer = timer - 1u;
	if (timer == 1u)
	{
		d7 = 0x64u;
		music = d7;
		queue_sound((uint8_t)d7, 0u);
		OBJECT(a0)->rock_soldier.timer = 0x28u;
		OBJECT(a0)->state++;
	}
	return d7;
}

/* he appears and fights, with the wall slab flying off and the shock bars */
void rock_soldier_technodrome_enter_appear(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, bars = 0, d0 = 0, d7_2 = 0, hit_box = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->rock_soldier.timer;
	OBJECT(a0)->rock_soldier.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->flags |= 0x86u;
		d0 = 0u;
		rock_soldier_technodrome_next_move(d0, a0, &d7_2, p_a5);
		a6 = OBJECT_ADDRESS(24);
		d7 = (d7_2 & ~0xFFu) | 8u;
		d7 = (uint8_t)d7;
		find_free_object(&d7, &a6);
		if ((uint8_t)d7 != 0u)
		{
			rock_soldier_technodrome_start_wall_slab(a0, a6);
			bars = OBJECT_ADDRESS(24);
			d7 = (d7 & ~0xFFu) | 8u;
			d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
			find_free_object(&d7, &bars);
			if ((uint8_t)d7 != 0u)
			{
				OBJECT(bars)->flags = 1u;
				OBJECT(bars)->contacts = 0u;
				OBJECT(bars)->kind = 0x4Cu;
				OBJECT(bars)->parameter = 0u;
				OBJECT(bars)->colour = 0xFFu;
				OBJECT(bars)->animation_delay = 0u;
				place_at_object(a0, bars);
				OBJECT(bars)->y += 0x8A00u;
				OBJECT(bars)->shock_bars.leader = a0;
				OBJECT(bars)->routine = 0u;
				OBJECT(bars)->state = 0u;
				*p_a5 = bars;
				hit_box = OBJECT_ADDRESS(24);
				d7 = (d7 & ~0xFFu) | 8u;
				d7 = (d7 & ~0xFFFFu) | (uint8_t)d7;
				find_free_object(&d7, &hit_box);
				if ((uint8_t)d7 != 0u)
				{
					OBJECT(hit_box)->flags = 1u;
					OBJECT(hit_box)->contacts = 0u;
					OBJECT(hit_box)->kind = 0x4Du;
					OBJECT(hit_box)->parameter = 0u;
					OBJECT(hit_box)->colour = 0xFFu;
					OBJECT(hit_box)->animation_delay = 0u;
					place_at_object(a0, hit_box);
					OBJECT(hit_box)->shock_bars.leader = *p_a5;
					OBJECT(hit_box)->routine = 0u;
					OBJECT(hit_box)->state = 0u;
				}
			}
		}
	}
	*p_d7 = d7;
}

/* he strikes a turtle close by at a chance, more often as he weakens, else goes on with his move */
void rock_soldier_technodrome_think(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint8_t d7_2 = 0;
	uint32_t a6 = 0, animation = 0, d0 = 0, d1 = 0, d7 = 0, ignored = 0;

	rock_soldier_technodrome_weak_flash(a0, &d5, &ignored);
	if (OBJECT(a0)->state == 3u)
	{
		d7 = OBJECT(a0)->state;
		d7 = (uint16_t)(d7 << 2);
		switch (d7)
		{
		case 0:
			rock_soldier_technodrome_walk(a0, &d5, &d7, p_a5);
			break;
		case 4:
			rock_soldier_technodrome_walk_on(a0, &d5, &d7, p_a5);
			break;
		case 8:
			rock_soldier_technodrome_stand(a0, &d5, &d7, p_a5);
			break;
		case 12:
			rock_soldier_technodrome_taunt(a0, &d5, &d7, p_a5);
			break;
		}
	}
	else
	{
		rock_soldier_find_close_turtle(a0, &d0, &d5);
		if ((uint8_t)d0 == 0u)
		{
			d7 = OBJECT(a0)->state;
			d7 = (uint16_t)(d7 << 2);
			switch (d7)
			{
			case 0:
				rock_soldier_technodrome_walk(a0, &d5, &d7, p_a5);
				break;
			case 4:
				rock_soldier_technodrome_walk_on(a0, &d5, &d7, p_a5);
				break;
			case 8:
				rock_soldier_technodrome_stand(a0, &d5, &d7, p_a5);
				break;
			case 12:
				rock_soldier_technodrome_taunt(a0, &d5, &d7, p_a5);
				break;
			}
		}
		else
		{
			a6 = indexed_table_of_8_bit_values_012338_ADDRESS;
			if (OBJECT(a0)->rock_soldier.hits_left < 0x14u)
				a6 = 0x1234Cu;
			d1 = DATA8(a6 + (uint16_t)(OBJECT(a0)->rock_soldier.blows + ((uint32_t)turtles_in_play << 2)));
			d7 = 0x40u;
			d7 = random_below((uint16_t)d7, a0);
			if (d1 <= (uint8_t)d7)
			{
				d7 = OBJECT(a0)->state;
				d7 = (uint16_t)(d7 << 2);
				switch (d7)
				{
				case 0:
					rock_soldier_technodrome_walk(a0, &d5, &d7, p_a5);
					break;
				case 4:
					rock_soldier_technodrome_walk_on(a0, &d5, &d7, p_a5);
					break;
				case 8:
					rock_soldier_technodrome_stand(a0, &d5, &d7, p_a5);
					break;
				case 12:
					rock_soldier_technodrome_taunt(a0, &d5, &d7, p_a5);
					break;
				}
			}
			else
			{
				OBJECT(a0)->rock_soldier.close_turtle = d0;
				OBJECT(a0)->rock_soldier.explosions = 0u;
				OBJECT(a0)->routine = 3u;
				OBJECT(a0)->state = 0u;
				OBJECT(a0)->flags &= 0xBFu;
				OBJECT(a0)->attack &= 0x7Fu;
				if ((int8_t)OBJECT(a0)->rock_soldier.close_turtle >= 0)
				{
					OBJECT(a0)->flags |= 0x40u;
					OBJECT(a0)->attack |= 0x80u;
				}
				OBJECT(a0)->rock_soldier.close_turtle = 0u;
				d7_2 = 8u;
				queue_sound(d7_2, a6);
				d7 = turtles_in_play;
				d7 = (uint16_t)(d7 << 2);
				d7 = (d7 & ~0xFFu) | (uint8_t)(d7 + OBJECT(a0)->rock_soldier.blows);
				d7 = (d7 & ~0xFFu) | indexed_table_of_8_bit_values_01255E[d7];
				animation = TABLE32(rom_0153D8, d7);
				set_animation(d1, a0, animation);
				OBJECT(a0)->rock_soldier.blows++;
				if (OBJECT(a0)->rock_soldier.blows >= 4u)
					OBJECT(a0)->rock_soldier.blows = 3u;
			}
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

/* he walks at his target, aiming at it now and then */
void rock_soldier_technodrome_walk(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0, move_time = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)frame_count;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
		boss_aim_at_target(a0, &ignored, &d7_2, p_a5);
	t2 = d7_2 & 1u;
	d7_2 = (d7_2 & ~0xFFu) | t2;
	if (t2 == 0u)
		d7_2 = rock_soldier_technodrome_move(a0);
	move_time = OBJECT(a0)->rock_soldier.move_time;
	OBJECT(a0)->rock_soldier.move_time = move_time - 1u;
	if (move_time == 0u)
	{
		d0 = 1u;
		rock_soldier_technodrome_move_done(d0, a0, &d5, &d7_2, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

/* he walks on at his target */
void rock_soldier_technodrome_walk_on(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0, move_time = 0;

	d7_2 = (d7 & ~0xFFu) | (uint8_t)frame_count;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
		boss_aim_at_target(a0, &ignored, &d7_2, p_a5);
	if ((frame_count & 2u) == 0u)
		d7_2 = rock_soldier_technodrome_move(a0);
	move_time = OBJECT(a0)->rock_soldier.move_time;
	OBJECT(a0)->rock_soldier.move_time = move_time - 1u;
	if (move_time == 0u)
	{
		d0 = 2u;
		rock_soldier_technodrome_move_done(d0, a0, &d5, &d7_2, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

/* he stands a while */
void rock_soldier_technodrome_stand(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->rock_soldier.move_time;
	OBJECT(a0)->rock_soldier.move_time = move_time - 1u;
	if (move_time != 0u)
		return;
	d0 = 3u;
	rock_soldier_technodrome_move_done(d0, a0, &d5, p_d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* he taunts until the animation ends */
void rock_soldier_technodrome_taunt(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d0 = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	d0 = 4u;
	rock_soldier_technodrome_move_done(d0, a0, &d5, p_d7, p_a5);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* a move over: now and then a missile at a turtle far enough in front, else the next move */
void rock_soldier_technodrome_move_done(uint32_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0, animation = 0, d7 = 0;

	if (missile_out != 0u)
		rock_soldier_technodrome_next_move(d0, a0, &d7, p_a5);
	else
	{
		rock_soldier_find_turtle_ahead(a0, &d5, &d7);
		if ((uint8_t)d7 == 0u)
			rock_soldier_technodrome_next_move(d0, a0, &d7, p_a5);
		else
		{
			d7 = 0x10u;
			d7 = random_below((uint16_t)d7, a0);
			if ((uint8_t)d7 < 4u)
			{
				OBJECT(a0)->rock_soldier.explosions = 0u;
				OBJECT(a0)->routine = 2u;
				OBJECT(a0)->state = 0u;
				OBJECT(a0)->rock_soldier.shot_hit = 0u;
				a6 = OBJECT_ADDRESS(24);
				d7 = (d7 & ~0xFFu) | 8u;
				d7 = (uint8_t)d7;
				find_free_object(&d7, &a6);
				if ((uint8_t)d7 == 0u)
					rock_soldier_technodrome_walk_start(a0, &d7, p_a5);
				else
				{
					rock_soldier_technodrome_start_missile(a0, a6, &d7, p_a5);
					animation = rom_0153E8;
					set_animation(0u, a0, animation);
				}
			}
			else
				rock_soldier_technodrome_next_move(d0, a0, &d7, p_a5);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

/* the missile's firing plays out, then the next move */
void rock_soldier_technodrome_fire(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0, d5 = 0;

	rock_soldier_technodrome_weak_flash(a0, &d5, p_d7);
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->rock_soldier.hurt = 0u;
		d0 = 5u;
		rock_soldier_technodrome_next_move(d0, a0, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the blow plays out, then the next move */
void rock_soldier_technodrome_finish_blow(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d0 = 0, d5 = 0;

	rock_soldier_technodrome_weak_flash(a0, &d5, p_d7);
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->rock_soldier.hurt = 0u;
		d0 = 5u;
		rock_soldier_technodrome_next_move(d0, a0, p_d7, p_a5);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the next move by chance, by what he did before */
void rock_soldier_technodrome_next_move(uint32_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d6 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	*p_d7 = 0x10u;
	*p_d7 = random_below((uint16_t)*p_d7, a0);
	d6 = 3u;
	a6 = table_loaded_by_lea_012486_ADDRESS + (uint16_t)(d0 << 2);
	for (;;)
	{
		t1 = mem_read8(a6 + (int16_t)d6);
		t2 = *p_d7;
		*p_d7 = (uint8_t)(t2 - t1);
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
		*p_a5 = a5;
		rock_soldier_technodrome_walk_start(a0, p_d7, p_a5);
		return;
	case 4:
		*p_d7 = rock_soldier_technodrome_walk_on_start(a0);
		return;
	case 8:
		*p_d7 = rock_soldier_technodrome_stand_start(a0);
		return;
	case 12:
		*p_d7 = rock_soldier_technodrome_taunt_start(a0);
		return;
	}
}

/* he picks a turtle and walks at it, or taunts if there is none */
void rock_soldier_technodrome_walk_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0, d7 = 0, ignored = 0;

	boss_pick_target(a0, &ignored, &d7, p_a5);
	if ((uint8_t)d7 == 0u)
		d7 = rock_soldier_technodrome_taunt_start(a0);
	else
	{
		d7 = 8u;
		d7 = rock_soldier_technodrome_random_move_time(d7, a0);
		OBJECT(a0)->rock_soldier.explosions = 0u;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->state = 0u;
		animation = rom_0153E0;
		set_animation(0u, a0, animation);
	}
	*p_d7 = d7;
}

/* he walks on as he was */
uint32_t rock_soldier_technodrome_walk_on_start(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 8u;
	d7 = rock_soldier_technodrome_random_move_time(d7, a0);
	OBJECT(a0)->rock_soldier.explosions = 0u;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->state = 1u;
	return d7;
}

/* he stands a while, crouched on his way in */
uint32_t rock_soldier_technodrome_stand_start(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0;

	d7 = 4u;
	d7 = rock_soldier_technodrome_random_move_time(d7, a0);
	animation = rom_0153D8[0];
	if (OBJECT(a0)->routine == 0u)
		animation = rom_0153DC;
	OBJECT(a0)->rock_soldier.explosions = 0u;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->state = 2u;
	set_animation(0u, a0, animation);
	return d7;
}

/* he taunts with a speech */
uint32_t rock_soldier_technodrome_taunt_start(uint32_t a0)
{
	uint8_t d6 = 0;
	uint32_t animation = 0, d7 = 0;

	OBJECT(a0)->rock_soldier.explosions = 0u;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->state = 3u;
	d7 = 4u;
	d7 = random_below((uint16_t)d7, a0);
	d6 = (uint8_t)d7;
	d7 = 0xA6u;
	if (d6 == 0u)
		d7 = 0xB1u;
	queue_sound((uint8_t)d7, 0u);
	animation = rom_0153E4;
	set_animation(0u, a0, animation);
	return d7;
}

/* how long the move lasts, at random */
uint32_t rock_soldier_technodrome_random_move_time(uint32_t d7, uint32_t a0)
{
	d7 = random_below((uint16_t)d7, a0);
	OBJECT(a0)->rock_soldier.move_time = rom_012628[d7];
	return d7;
}

/* he moves by his speeds within the area's depth */
uint32_t rock_soldier_technodrome_move(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = move_by_speeds(a0);
	if (OBJECT(a0)->y >= 0xF68000u)
		OBJECT(a0)->y = 0xF68000u;
	if (OBJECT(a0)->y < 0xF61000u)
		OBJECT(a0)->y = 0xF61000u;
	return d7;
}

/* the wall slab flies off where he appears */
void rock_soldier_technodrome_start_wall_slab(uint32_t a0, uint32_t slab)
{
	OBJECT(slab)->flags = 1u;
	OBJECT(slab)->contacts = 0u;
	OBJECT(slab)->kind = 0x48u;
	OBJECT(slab)->parameter = 0u;
	OBJECT(slab)->colour = 0xFFu;
	OBJECT(slab)->animation_delay = 0u;
	place_at_object(a0, slab);
	OBJECT(slab)->y -= 0x800u;
	OBJECT(slab)->y -= 0x800u;
	OBJECT(slab)->height += 0x400u;
	OBJECT(slab)->unk_2F = 0u;
	OBJECT(slab)->routine = 0u;
	OBJECT(slab)->state = 0u;
}

/* a slab of the wall flies off to the left, knocking turtles flying */
uint32_t wall_slab_start(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags = 0x85u;
	stats = wall_slab_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->x_speed = -0x800;
	OBJECT(a0)->flags &= 0xBFu;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	animation = rom_0156DA;
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 0x3Eu;
	queue_sound((uint8_t)d7_2, animation);
	a6 = 0x191A4u;
	d7_2 = (d7_2 & ~0xFFFFu) | 0x25u;
	draw_tile_block((uint16_t)d7_2, a6);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the slab flies until it leaves the screen */
uint32_t wall_slab_fly(uint32_t d7, uint32_t a0)
{
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		remove_object(a0);
		return d7;
	}
	return move_by_speeds(a0);
}

/* a missile from his launcher, the way he faces */
void rock_soldier_technodrome_start_missile(uint32_t a0, uint32_t missile, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;

	OBJECT(missile)->flags = 1u;
	OBJECT(missile)->contacts = 0u;
	OBJECT(missile)->kind = 0x49u;
	OBJECT(missile)->parameter = 0u;
	OBJECT(missile)->colour = 0xFFu;
	OBJECT(missile)->animation_delay = 0u;
	place_at_object(a0, missile);
	OBJECT(missile)->missile.flies_left = 0u;
	d7_2 = (d7 & ~0xFFFFu) | 0x4000u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		d7_2 = (int16_t)~d7_2;
		OBJECT(missile)->missile.flies_left |= 0x80u;
	}
	OBJECT(missile)->x += d7_2;
	OBJECT(missile)->height = 0x3800u;
	OBJECT(missile)->missile.shooter = a0;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(missile)->routine = 0u;
	OBJECT(missile)->state = 0u;
	OBJECT(missile)->contacts |= 0x80u;
	*p_a5 = 0x16F20u;
	OBJECT(missile)->shadow = 0x16F20u;
	*p_d7 = d7_2;
}

/* a missile flies the way the rock soldier faces, knocking turtles flying */
uint32_t missile_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0, stats = 0;

	OBJECT(a0)->flags |= 0x86u;
	stats = missile_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->flags &= 0xBFu;
	OBJECT(a0)->x_speed = 0x300;
	OBJECT(a0)->flags |= 0x40u;
	if ((int8_t)OBJECT(a0)->missile.flies_left < 0)
	{
		OBJECT(a0)->flags &= 0xBFu;
		OBJECT(a0)->attack &= 0x7Fu;
		OBJECT(a0)->x_speed = ~OBJECT(a0)->x_speed;
	}
	animation = rom_015692;
	set_animation(0u, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 6u;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the missile flies until it meets a wall or reaches the screen's sides, and explodes */
void missile_fly(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	if (OBJECT(a0)->screen_x < 0x60u || OBJECT(a0)->screen_x >= 0x180u)
	{
		OBJECT(a0)->routine++;
		d7_2 = (d7 & ~0xFFu) | 0x13u;
		queue_sound((uint8_t)d7_2, a6);
		animation = rom_015258;
		set_animation(0u, a0, animation);
	}
	else
	{
		LAYER(WORKING_LAYER)->x = LAYER(LAYER_B)->x;
		read_floor_cells_on_screen(a0, &d5, p_a5, &a6);
		turtle_walls_right(a0, a6);
		if ((OBJECT(a0)->contacts & 8u) != 0u)
		{
			OBJECT(a0)->routine++;
			d7_2 = (d7 & ~0xFFu) | 0x13u;
			queue_sound((uint8_t)d7_2, a6);
			animation = rom_015258;
			set_animation(0u, a0, animation);
		}
		else
		{
			d7_2 = OBJECT(a0)->x_speed;
			OBJECT(a0)->x += d7_2;
		}
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

/* the explosion ends and the missile is gone */
void missile_explode(uint32_t a0)
{
	if (OBJECT(a0)->height != 0u)
		OBJECT(a0)->height -= 0x400u;
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 1u;
		if (hold_spent_missiles == 0u)
		{
			missile_out = 0u;
			remove_object(a0);
			return;
		}
	}
	missile_idle();
}

/* nothing */
void missile_idle(void)
{
}

/* a turtle's attack bursts the missile */
void missile_struck(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->routine++;
	animation = rom_014C3A;
	set_animation(0u, a0, animation);
}

/* the burst ends and the missile is gone */
void missile_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		remove_object(a0);
		return;
	}
}

/* the shock bars appear, blinking */
void shock_bars_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	stats = inert_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->shock_bars.blink_period = 0x3Du;
	OBJECT(a0)->shock_bars.blink_timer = OBJECT(a0)->shock_bars.blink_period;
	OBJECT(a0)->routine++;
	animation = rom_01574E;
	set_animation(0u, a0, animation);
}

/* the bars blink faster until they flicker on */
uint32_t shock_bars_blink_in(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	shock_bars_blink(a0);
	d7_2 = (d7 & ~0xFFu) | (uint8_t)frame_count;
	t1 = d7_2 & 0xFu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 == 0u)
	{
		OBJECT(a0)->shock_bars.blink_period -= 4u;
		if (OBJECT(a0)->shock_bars.blink_period == 1u)
			OBJECT(a0)->routine++;
	}
	return d7_2;
}

/* the bars flicker until their rock soldier is defeated */
void shock_bars_on(uint32_t a0)
{
	shock_bars_blink(a0);
	if (mem_read8(OBJECT(a0)->shock_bars.leader + 4u) == 6u)
		OBJECT(a0)->routine++;
}

/* the bars blink slower until they are gone */
uint32_t shock_bars_blink_out(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	shock_bars_blink(a0);
	d7_2 = (d7 & ~0xFFu) | (uint8_t)frame_count;
	t1 = d7_2 & 7u;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 != 0u)
		return d7_2;
	OBJECT(a0)->shock_bars.blink_period++;
	if (OBJECT(a0)->shock_bars.blink_period < 0x28u)
		return d7_2;
	remove_object(a0);
	return d7_2;
}

/* the bars show now and then */
void shock_bars_blink(uint32_t a0)
{
	uint8_t blink_timer = 0;

	OBJECT(a0)->flags &= 0x7Fu;
	blink_timer = OBJECT(a0)->shock_bars.blink_timer;
	OBJECT(a0)->shock_bars.blink_timer = blink_timer - 1u;
	if (blink_timer == 0u)
	{
		OBJECT(a0)->shock_bars.blink_timer = OBJECT(a0)->shock_bars.blink_period;
		OBJECT(a0)->flags |= 0x80u;
	}
}

/* the unseen part of the bars that electrocutes turtles */
void shock_bars_hit_box_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	stats = shock_bars_hit_box_stats_ADDRESS;
	set_object_stats(a0, stats);
	OBJECT(a0)->routine++;
	animation = rom_01574E;
	set_animation(0u, a0, animation);
}

/* Unused: counts down as the bars blink in */
void shock_bars_hit_box_blink_in(uint32_t a0)
{
	if ((frame_count & 0xFu) == 0u)
	{
		mem_write8(a0 + 0x2Eu, mem_read8(a0 + 0x2Eu) - 4u);
		if (mem_read8(a0 + 0x2Eu) == 1u)
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
}

/* while the bars flicker on it electrocutes turtles now and then; it goes with them */
uint32_t shock_bars_hit_box_zap(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	d7_2 = (d7 & ~0xFFu) | mem_read8(OBJECT(a0)->shock_bars.leader + 4u);
	if ((uint8_t)d7_2 == 3u)
	{
		remove_object(a0);
		return d7_2;
	}
	OBJECT(a0)->flags &= ~4u;
	if ((uint8_t)d7_2 == 2u)
	{
		d7_2 = (d7_2 & ~0xFFu) | (uint8_t)frame_count;
		t1 = d7_2 & 0xFu;
		d7_2 = (d7_2 & ~0xFFu) | t1;
		if (t1 == 0u)
			OBJECT(a0)->flags |= 4u;
	}
	return d7_2;
}
