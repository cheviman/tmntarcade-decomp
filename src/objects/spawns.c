/**
 *    Name:        objects/spawns.c
 *    Description: the enemies' spawn lists, by the scroll
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void start_area_spawns(void)
{
	uint16_t d0 = 0;
	uint32_t a5 = 0;

	d0 = (uint16_t)((uint32_t)(int8_t)area << 2);
	spawn_next = TABLE32(area_spawn_lists, (uint32_t)(int16_t)d0);
	d0 = (uint16_t)((uint32_t)d0 << 1);
	a5 = TABLE32(area_spawn_scrolls, (uint32_t)(int16_t)d0);
	mem_write16(a5 + 2u, 0u);
	mem_write16(a5, 0u);
	spawn_speeds = a5;
	spawn_directions = mem_read32(0x47996u + (int16_t)d0);
	spawn_x = TABLE32(area_spawn_starts, (uint32_t)(int16_t)d0);
	spawn_y = mem_read32(0x479E6u + (int16_t)d0);
}

uint32_t spawn_enemies(uint32_t a1)
{
	uint32_t zero = 0, carry = 0;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a0 = 0, a5 = 0, a6 = 0, d3 = 0, ignored = 0, object = 0;
	uint32_t kind_halfword = 0, kind_halfword_2 = 0;

	a5 = spawn_speeds;
	a6 = spawn_directions;
	d0 = mem_read16(a5);
	if ((int8_t)mem_read8(a6 + 1u) >= 0)
		d0 = (uint16_t)(0u - d0);
	spawn_x += (int16_t)d0;
	d1 = mem_read16(a5 + 2u);
	if ((int8_t)mem_read8(a6) < 0)
		d1 = (uint16_t)(0u - d1);
	spawn_y += (int16_t)d1;
	a0 = spawn_next;
	if (mem_read16(a0) == 0xFFFFu || (int16_t)(spawn_x >> 8) < (int16_t)mem_read16(a0))
		return a1;
	if (area == 6u)
	{
		hold_scroll_for_enemies(&ignored, &carry);
		if (carry)
		{
			spawn_next = a0 + 8u;
			return a1;
		}
		if (difficulty < (mem_read8(a0 + 5u) & 0xFu))
			spawn_next = a0 + 8u;
		else
		{
			a1 = spawn_offset(a0);
			take_free_object(a0, &object, &zero);
			if (zero)
			{
				OBJECT(object)->flags = 1u;
				OBJECT(object)->contacts = 0u;
				kind_halfword = mem_read16(a0 + 6u);
				OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
				OBJECT(object)->parameter = (uint8_t)kind_halfword;
				OBJECT(object)->routine = 0u;
				OBJECT(object)->state = 0u;
				OBJECT(object)->hit_routine = 0u;
				OBJECT(object)->colour = 0xFFu;
				OBJECT(object)->animation_delay = 0u;
				OBJECT(object)->throw = 0u;
				OBJECT(object)->height_whole = mem_read8(a0 + 4u);
				OBJECT(object)->height &= 0xFF00u;
				d3 = mem_read16(a0);
				if ((mem_read8(a0 + 5u) & 0x40u) != 0u)
				{
					d3 = (uint16_t)(d3 - 0x140u);
					d3 = (uint16_t)(d3 - mem_read16(a1));
				}
				else
					d3 = (uint16_t)(d3 + mem_read16(a1));
				OBJECT(object)->x = d3 << 8;
				OBJECT(object)->y = (uint32_t)mem_read16(a0 + 2u) << 8;
				spawn_next = a0 + 8u;
				return a1;
			}
		}
		return a1;
	}
	if (difficulty < (mem_read8(a0 + 5u) & 0xFu))
		spawn_next = a0 + 8u;
	else
	{
		a1 = spawn_offset(a0);
		take_free_object(a0, &object, &zero);
		if (zero)
		{
			OBJECT(object)->flags = 1u;
			OBJECT(object)->contacts = 0u;
			kind_halfword_2 = mem_read16(a0 + 6u);
			OBJECT(object)->kind = (uint8_t)(kind_halfword_2 >> 8u);
			OBJECT(object)->parameter = (uint8_t)kind_halfword_2;
			OBJECT(object)->routine = 0u;
			OBJECT(object)->state = 0u;
			OBJECT(object)->hit_routine = 0u;
			OBJECT(object)->colour = 0xFFu;
			OBJECT(object)->animation_delay = 0u;
			OBJECT(object)->throw = 0u;
			OBJECT(object)->height_whole = mem_read8(a0 + 4u);
			OBJECT(object)->height &= 0xFF00u;
			d3 = mem_read16(a0);
			if ((mem_read8(a0 + 5u) & 0x40u) != 0u)
			{
				d3 = (uint16_t)(d3 - 0x140u);
				d3 = (uint16_t)(d3 - mem_read16(a1));
			}
			else
				d3 = (uint16_t)(d3 + mem_read16(a1));
			OBJECT(object)->x = d3 << 8;
			OBJECT(object)->y = (uint32_t)mem_read16(a0 + 2u) << 8;
			spawn_next = a0 + 8u;
			return a1;
		}
	}
	return a1;
}

void unreached_047B1C(uint32_t a0)
{
	uint32_t zero = 0;
	uint16_t d1 = 0;
	uint32_t a1 = 0, d3 = 0, object = 0;
	uint32_t kind_halfword = 0;

	d1 = (uint16_t)((spawn_y >> 8) + 8u);
	if ((int16_t)mem_read16(a0 + 2u) <= (int16_t)d1 && (int16_t)(d1 - 0x10u) <= (int16_t)mem_read16(a0 + 2u))
	{
		a1 = spawn_offset(a0);
		take_free_object(a0, &object, &zero);
		if (zero == 0u)
			return;
		OBJECT(object)->flags = 1u;
		OBJECT(object)->contacts = 0u;
		kind_halfword = mem_read16(a0 + 6u);
		OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
		OBJECT(object)->parameter = (uint8_t)kind_halfword;
		OBJECT(object)->routine = 0u;
		OBJECT(object)->state = 0u;
		OBJECT(object)->hit_routine = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		OBJECT(object)->throw = 0u;
		OBJECT(object)->height_whole = mem_read8(a0 + 4u);
		OBJECT(object)->height &= 0xFF00u;
		OBJECT(object)->x = (uint32_t)mem_read16(a0) << 8;
		d3 = mem_read16(a0 + 2u);
		if ((mem_read8(a0 + 5u) & 0x40u) != 0u)
		{
			d3 = (uint16_t)(d3 - 0x100u);
			d3 = (uint16_t)(d3 - mem_read16(a1 + 2u));
		}
		OBJECT(object)->y = d3 << 8;
		spawn_next = a0 + 8u;
	}
}

uint32_t spawn_offset(uint32_t a0)
{
	uint32_t a1 = 0;

	a1 = spawn_offsets_ADDRESS + (uint16_t)((mem_read8(a0 + 6u) & 0x7Fu) << 2);
	return a1;
}

void take_free_object(uint32_t a0, uint32_t *p_a2, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;
	uint16_t d0 = 0;
	uint32_t object = 0;
	uint8_t flags = 0;
	uint16_t t1 = 0;

	d0 = (mem_read8(a0 + 5u) & 0x30u) >> 2;
	object = TABLE32(object_groups, d0);
	d0 = d0 >> 2;
	d0 = object_group_counts[d0];
	do
	{
		flags = OBJECT(object)->flags;
		zero = flags == 0u;
		if (flags == 0u)
			break;
		t1 = d0 - 1u;
		d0 = t1;
		object += 0x50u;
	} while (t1 != 0xFFFFu);
	*p_a2 = object;
	*p_zero = zero;
}
