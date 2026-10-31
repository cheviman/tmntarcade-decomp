/**
 *    Name:        objects/explosions.c
 *    Description: the explosions other objects start
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* a small explosion, harmless */
uint32_t start_small_explosion(uint16_t d6, uint32_t d7, uint32_t a0, uint32_t a6)
{
	OBJECT(a6)->flags = 1u;
	OBJECT(a6)->contacts = 0u;
	OBJECT(a6)->kind = 0x31u;
	OBJECT(a6)->parameter = 0u;
	OBJECT(a6)->colour = 0xFFu;
	OBJECT(a6)->animation_delay = 0u;
	d7 = place_explosion(d6, (uint16_t)d7, a0, a6);
	return d7;
}

/* one of the explosions of a defeated boss, with its sound */
void boss_start_explosion(uint32_t a0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d6 = 0, d7 = 0;
	uint32_t d7_2 = 0;

	d7 = (uint16_t)((uint32_t)OBJECT(a0)->boss.explosions << 2);
	d6 = indexed_table_of_16_bit_values_010F1C[d7 / 2u];
	d7 = rom_010F1E[d7 / 2u];
	start_big_explosion(d6, d7, a0, a6);
	*p_a5 = rom_010F44_ADDRESS;
	d7_2 = OBJECT(a0)->boss.explosions;
	d7_2 = d7_2 & 1u;
	d7_2 = rom_010F44[d7_2];
	queue_sound((uint8_t)d7_2, a6);
	*p_d7 = d7_2;
}

/* a big explosion, harmless */
void start_big_explosion(uint16_t d6, uint32_t d7, uint32_t a0, uint32_t a6)
{
	OBJECT(a6)->flags = 1u;
	OBJECT(a6)->contacts = 0u;
	OBJECT(a6)->kind = 0x32u;
	OBJECT(a6)->parameter = 0u;
	OBJECT(a6)->colour = 0xFFu;
	OBJECT(a6)->animation_delay = 0u;
	place_explosion(d6, (uint16_t)d7, a0, a6);
}

/* Unused: an attacking small explosion where the object is, with its sound */
void explode_small(uint32_t a0, uint32_t a6)
{
	uint8_t d7_2 = 0;
	uint16_t d6 = 0, d7 = 0;

	d6 = 0u;
	d7 = 0u;
	start_small_blast(d6, d7, a0, a6);
	d7_2 = 0x11u;
	queue_sound(d7_2, a6);
}

/* Unused: a small explosion that knocks flying what it hits */
void start_small_blast(uint16_t d6, uint32_t d7, uint32_t a0, uint32_t a6)
{
	mem_write16(a6, 0x500u);
	mem_write16(a6 + 2u, 0x3100u);
	mem_write16(a6 + 0x42u, 0xFF00u);
	place_explosion(d6, (uint16_t)d7, a0, a6);
}

/* the explosion where the object is, moved across and up */
uint32_t place_explosion(uint16_t d6, uint16_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;

	OBJECT(a6)->height = OBJECT(a0)->height;
	OBJECT(a6)->height += d7;
	OBJECT(a6)->x = OBJECT(a0)->x;
	OBJECT(a6)->x += (int16_t)d6;
	OBJECT(a6)->y = OBJECT(a0)->y;
	d7_2 = OBJECT(a0)->depth;
	d7_2 = (uint16_t)(d7_2 << 8);
	d7_2 = (uint16_t)(d7_2 + 0x200u);
	OBJECT(a6)->y -= d7_2;
	OBJECT(a6)->unk_2F = 0u;
	OBJECT(a6)->routine = 0u;
	OBJECT(a6)->state = 0u;
	return d7_2;
}

/* a small explosion */
void explosion_small_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	animation = rom_014C3A;
	set_animation(0u, a0, animation);
	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->routine++;
	stats = explosion_stats_ADDRESS;
	set_object_stats(a0, stats);
}

/* a big explosion */
void explosion_big_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	animation = rom_014C86;
	set_animation(0u, a0, animation);
	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->routine++;
	stats = explosion_stats_ADDRESS;
	set_object_stats(a0, stats);
}

/* the oil drum's explosion */
void explosion_drum_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	animation = rom_014D1C;
	set_animation(0u, a0, animation);
	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->routine++;
	stats = explosion_stats_ADDRESS;
	set_object_stats(a0, stats);
}

/* Unused: an explosion like the rocket's */
void explosion_rocket_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	animation = rom_015258;
	set_animation(0u, a0, animation);
	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->routine++;
	stats = explosion_stats_ADDRESS;
	set_object_stats(a0, stats);
}

/* a medium explosion */
void explosion_medium_start(uint32_t a0)
{
	uint32_t animation = 0, stats = 0;

	animation = rom_015AA0;
	set_animation(0u, a0, animation);
	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->routine++;
	stats = explosion_stats_ADDRESS;
	set_object_stats(a0, stats);
}

/* the explosion ends and it is gone */
void explosion_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		remove_object(a0);
		return;
	}
}
