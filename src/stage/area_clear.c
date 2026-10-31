/**
 *    Name:        stage/area_clear.c
 *    Description: the checks for the end of each area: the scroll locked, every player ready and no enemy left, then the area cleared
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint32_t check_area_cleared(uint32_t d7)
{
	switch (stage)
	{
	case 0:
		return check_cleared_building(d7);
	case 1:
		check_cleared_apartment();
		return d7;
	case 2:
		check_cleared_street();
		return d7;
	case 3:
		check_cleared_sewer();
		return d7;
	case 4:
		check_cleared_car_street();
		return d7;
	case 5:
		check_cleared_highway();
		return d7;
	case 6:
		check_cleared_skateboard();
		return d7;
	case 7:
		check_cleared_building_site();
		return d7;
	case 8:
		check_cleared_technodrome();
		return d7;
	case 9:
		check_cleared_final();
		return d7;
	}
}

uint32_t check_cleared_building(uint32_t d7)
{
	uint32_t zero = 0;
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	if (last_segment == 0u)
	{
		scroll_held = 0xFFFFFFFFu;
		last_segment = 0xFFu;
		building_clear_wait = 0u;
		return d7;
	}
	if (building_clear_wait == 0u)
	{
		zero = players_ready();
		if (zero || enemies_on_screen != 0u)
			return d7;
		building_clear_wait = 0x60u;
		return d7;
	}
	t1 = building_clear_wait;
	building_clear_wait = t1 - 1u;
	if (t1 != 1u)
	{
		if (building_clear_wait != 0x40u)
			return d7;
		d7_2 = (d7 & ~0xFFu) | 0xBAu;
		queue_sound((uint8_t)d7_2, 0u);
		d7_2 = (d7_2 & ~0xFFu) | 0xFEu;
		queue_sound((uint8_t)d7_2, 0u);
		return d7_2;
	}
	area_beaten = 0xFFu;
	return d7;
}

void check_cleared_apartment(void)
{
	uint32_t zero = 0;

	scroll_held = 0xFFFFFFFFu;
	last_segment = 0xFFu;
	zero = players_ready();
	if (zero == 0u && enemies_on_screen == 0u && drill_arrival < 0)
		area_beaten = 0xFFu;
}

void check_cleared_street(void)
{
	uint32_t zero = 0;

	scroll_held = 0xFFFFFFFFu;
	last_segment = 0xFFu;
	zero = players_ready();
	if (zero == 0u && enemies_on_screen == 0u)
		area_beaten = 0xFFu;
}

void check_cleared_sewer(void)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t object = 0;

	if ((uint8_t)frame_count != 0u)
	{
		scroll_held = (scroll_held & 0xFFFFu) | 0xFFFF0000u;
		last_segment = 0xFFu;
		zero = players_ready();
		if (zero == 0u && enemies_on_screen == 0u)
			area_beaten = 0xFFu;
		return;
	}
	object = OBJECT_ADDRESS(12);
	d0 = 0x88u;
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u && (OBJECT(object)->flags & 0x80u) != 0u && (int8_t)OBJECT(object)->throw < 0 && (int8_t)(uint8_t)(OBJECT(object)->y >> 24u) >= 0 && d0 < (uint8_t)(OBJECT(object)->y >> 8u))
		{
			OBJECT(object)->flags = 0u;
			enemies_on_screen--;
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(24));
	scroll_held = (scroll_held & 0xFFFFu) | 0xFFFF0000u;
	last_segment = 0xFFu;
	zero = players_ready();
	if (zero == 0u && enemies_on_screen == 0u)
		area_beaten = 0xFFu;
}

void check_cleared_car_street(void)
{
	uint32_t zero = 0;

	scroll_held = 0xFFFFFFFFu;
	last_segment = 0xFFu;
	zero = players_ready();
	if (zero == 0u && enemies_on_screen == 0u)
		area_beaten = 0xFFu;
}

void check_cleared_highway(void)
{
	uint32_t zero = 0;

	scroll_held = (scroll_held & 0xFFFFu) | 0xFFFF0000u;
	last_segment = 0xFFu;
	zero = players_ready();
	if (zero == 0u && enemies_on_screen == 0u)
		area_beaten = 0xFFu;
}

void check_cleared_skateboard(void)
{
	uint32_t zero = 0;

	scroll_mode = -1;
	last_segment = 0xFFu;
	zero = players_ready();
	if (zero == 0u && enemies_on_screen == 0u)
		area_beaten = 0xFFu;
}

void check_cleared_building_site(void)
{
	uint32_t zero = 0;

	scroll_held = 0xFFFFFFFFu;
	last_segment = 0xFFu;
	zero = players_ready();
	if (zero == 0u && enemies_on_screen == 0u)
		area_beaten = 0xFFu;
}

void check_cleared_technodrome(void)
{
	uint32_t zero = 0;

	scroll_held = 0xFFFFFFFFu;
	last_segment = 0xFFu;
	zero = players_ready();
	if (zero == 0u && enemies_on_screen == 0u)
		area_beaten = 0xFFu;
}

void check_cleared_final(void)
{
	uint32_t zero = 0;

	last_segment = 0xFFu;
	zero = players_ready();
	if (zero == 0u && enemies_on_screen == 0u)
		area_beaten = 0xFFu;
}

uint32_t players_ready(void)
{
	uint32_t zero = 0, carry = 0;
	uint8_t d0 = 0;
	uint32_t object = 0;
	uint8_t flags = 0, routine = 0;

	object = OBJECT_ADDRESS(0);
	d0 = players_in_play;
	do
	{
		carry = d0 & 1u;
		d0 = d0 >> 1;
		if (carry)
		{
			flags = OBJECT(object)->flags;
			zero = (flags & 1u) == 0u;
			if ((flags & 1u) == 0u)
				return zero;
			routine = OBJECT(object)->routine;
			zero = (uint8_t)(routine - 4u) == 0u;
			if (routine == 4u)
				return zero;
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	zero = 0xFFu == 0u;
	return zero;
}
