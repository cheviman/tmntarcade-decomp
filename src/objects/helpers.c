/**
 *    Name:        objects/helpers.c
 *    Description: small routines the objects of these files share: their stats, moves, free objects, the bosses' targets
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* picks one of the turtles in play at random as the boss's target and aims at it; none, none picked */
void boss_pick_target(uint32_t a0, uint32_t *p_d0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d6 = 0;
	uint32_t d7 = 0, object = 0;
	uint16_t t1 = 0;

	object = OBJECT_ADDRESS(3);
	*p_a5 = boss_target_choices_ADDRESS;
	boss_target_choices(0) = 0u;
	boss_target_choices(1) = 0u;
	boss_target_choices(2) = 0u;
	boss_target_choices(3) = 0u;
	d6 = 3u;
	d7 = 0u;
	do
	{
		if ((players_in_play & shl32(1u, (int)(d6 & 7u))) != 0u && (players_knocked_out & shl32(1u, (int)(d6 & 7u))) == 0u && OBJECT(object)->routine != 4u)
		{
			boss_target_choices(d7) = (uint8_t)d6;
			d7 = (uint8_t)(d7 + 1u);
		}
		t1 = d6 - 1u;
		d6 = t1;
		object -= 0x50u;
	} while (t1 != 0xFFFFu);
	if (d7 != 0u)
	{
		d7 = random_below((uint16_t)d7, a0);
		d7 = ((d7 & ~0xFFu) | boss_target_choices(d7)) * 0x50u;
		OBJECT(a0)->boss.target = OBJECT_ADDRESS(0) + d7;
		boss_aim_at_target(a0, p_d0, &d7, p_a5);
		d7 = IN_PAGE(d7, 1u);
	}
	*p_d7 = d7;
}

/* sets the boss's speeds toward its target and turns it that way */
void boss_aim_at_target(uint32_t a0, uint32_t *p_d0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d0 = 0;

	boss_direction_to_target(a0, &d0, p_a5);
	a6 = indexed_table_of_16_bit_values_011EB2_ADDRESS;
	if (OBJECT(a0)->kind != 0x1Eu)
		a6 = 0x11EF2u;
	d0 = (uint16_t)(d0 << 2);
	OBJECT(a0)->x_speed = DATA16(a6 + d0);
	d7 = DATA16(a6 + 2u + d0);
	OBJECT(a0)->y_speed = d7;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->flags &= 0xBFu;
	if (OBJECT(a0)->x_speed >= 0)
		OBJECT(a0)->flags |= 0x40u;
	*p_d0 = d0;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
}

/* an object's attack, health, depth and the sound a turtle it hits makes, from its record */
void set_object_stats(uint32_t a0, uint32_t stats)
{
	OBJECT(a0)->attack = OBJECT_STATS(stats)->attack;
	OBJECT(a0)->hit = OBJECT_STATS(stats)->hit;
	OBJECT(a0)->health_bars = OBJECT_STATS(stats)->health_bars;
	OBJECT(a0)->health = OBJECT_STATS(stats)->health;
	OBJECT(a0)->damage = OBJECT_STATS(stats)->damage;
	OBJECT(a0)->depth = OBJECT_STATS(stats)->depth;
	OBJECT(a0)->set_object_stats.hit_sound = OBJECT_STATS(stats)->hit_sound;
}

/* moves the object by its speeds across, up or down the screen, and in height */
uint32_t move_by_speeds(uint32_t a0)
{
	uint32_t d7 = 0, y_speed = 0;

	OBJECT(a0)->x += OBJECT(a0)->x_speed;
	y_speed = OBJECT(a0)->y_speed;
	OBJECT(a0)->y += y_speed;
	d7 = (y_speed & ~0xFFFFu) | (uint16_t)OBJECT(a0)->height_speed;
	OBJECT(a0)->height += d7;
	return d7;
}

/* finds an object not in use among the next ones */
void find_free_object(uint32_t *p_d7, uint32_t *p_a6)
{
	uint8_t d7 = (uint8_t)*p_d7;
	uint8_t t1 = 0;

	do
	{
		if (OBJECT(*p_a6)->flags == 0u)
			break;
		t1 = d7;
		d7 = (uint8_t)(t1 - 1u);
		*p_a6 += 0x50u;
	} while (t1 != 1u);
	*p_d7 = (*p_d7 & 0xFFFFFF00u) | d7;
}

/* the object is gone once it is off the screen */
void remove_if_off_screen(uint32_t a0)
{
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		remove_object(a0);
		return;
	}
}

/* the object is gone: out of use */
void remove_object(uint32_t a0)
{
	OBJECT(a0)->flags = 0u;
	OBJECT(a0)->contacts = 0u;
	OBJECT(a0)->kind = 0u;
	OBJECT(a0)->parameter = 0u;
	OBJECT(a0)->routine = 0u;
	OBJECT(a0)->state = 0u;
}

/* the direction, one of sixteen, from the boss to its target */
void boss_direction_to_target(uint32_t a0, uint32_t *p_d0, uint32_t *p_a5)
{
	uint32_t overflow = 0;
	uint16_t d1 = 0, d2 = 0, d3 = 0;
	uint32_t a6 = 0, d0 = 0, target = 0;
	uint16_t t1 = 0, t2 = 0;

	target = OBJECT(a0)->boss.target;
	d2 = 0u;
	a6 = indexed_table_of_8_bit_values_018550_ADDRESS;
	t1 = mem_read16(target + 0xCu) - OBJECT(a0)->screen_x;
	d0 = t1;
	if ((int16_t)t1 < 0)
	{
		d2 = (uint8_t)(d2 + 1u);
		d0 = (uint16_t)~d0;
		d0 = (d0 & ~0xFFu) | (uint8_t)(d0 + 1u);
	}
	t2 = mem_read16(target + 0xEu) - OBJECT(a0)->screen_y;
	d1 = t2;
	if ((int16_t)t2 < 0)
	{
		d2 = (uint8_t)(d2 + 2u);
		d1 = (uint16_t)~d1;
		d1 = (uint16_t)((d1 & ~0xFFu) | (uint8_t)(d1 + 1u));
	}
	if (d0 == 0u)
		d0 = DATA8(a6 + d2);
	else if (d1 == 0u)
		d0 = DATA8(a6 + 3u + d2);
	else
	{
		d3 = 0u;
		d0 = d0 * 0x3E8u;
		overflow = m68k_divu_ov(d0, d1);
		d0 = d1 == 0u ? d0 : m68k_divu(d0, d1);
		if (d1 == 0u)
			exception_hang();
		if (overflow == 0u)
		{
			while ((uint16_t)d0 < mem_read16(a6 + 6u + (int16_t)d3))
			{
				d3 += 2u;
			}
		}
		d0 = rom_018560[d2 * 5u + (d3 >> 1)];
	}
	*p_d0 = d0;
	*p_a5 = target;
}

/* puts the other object where this one is */
void place_at_object(uint32_t a0, uint32_t a6)
{
	OBJECT(a6)->x = OBJECT(a0)->x;
	OBJECT(a6)->y = OBJECT(a0)->y;
	OBJECT(a6)->height = OBJECT(a0)->height;
}
