/**
 *    Name:        scenes/continue.c
 *    Description: the continue's countdown and the GAME OVER after it
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the continue with its countdown, then GAME OVER, by its steps */
void scene_continue(uint32_t d1, uint16_t d6, uint32_t a5)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		continue_setup();
		break;
	case 1:
		continue_run(d1, d6);
		break;
	case 2:
		game_over(d6, a5);
		break;
	}
	do_nothing();
}

/* the continue's first step, by its steps */
void continue_setup(void)
{
	switch ((uint32_t)(int8_t)scene_substep)
	{
	case 0:
		continue_clear_text();
		break;
	case 1:
		continue_start();
		break;
	}
	check_joins(0u);
}

/* the texts cleared for the continue */
void continue_clear_text(void)
{
	uint16_t d7 = 0;

	jobs_pending = 1u;
	d7 = 1u;
	queue_job(d7);
	scene_substep++;
}

/* CONTINUE, the count from twenty and the continue's music */
void continue_start(void)
{
	uint8_t d7_2 = 0;
	uint16_t d7 = 0;

	if (jobs_pending != 0u)
		return;
	d7 = 0xB7Fu;
	queue_job(d7);
	d7 = 0xF02u;
	queue_job(d7);
	continue_count = 0x14u;
	continue_count_time = 1u;
	d7_2 = 0u;
	queue_sound(d7_2, 0u);
	d7_2 = 0x77u;
	queue_sound(d7_2, 0u);
	scene_step++;
	scene_substep = 0u;
}

/* the countdown, the messages under the boxes and the boxes of the players with lives */
void continue_run(uint32_t d1, uint16_t d6)
{
	uint16_t d7 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d7 = (uint16_t)((uint32_t)(int8_t)scene_substep << 2);
	switch ((uint32_t)(int16_t)d7)
	{
	case 0:
		d1 = continue_countdown(d1, d6, d7);
		break;
	}
	update_player_messages(d1, &ignored, &ignored_2, &ignored_3);
	d7 = (uint16_t)(0xB00u | 0x10u | players_with_lives);
	queue_job(d7);
}

/* the countdown: a count less every so often, the play back when a player joins, GAME OVER at zero */
uint32_t continue_countdown(uint32_t d1, uint16_t d6, uint32_t d7)
{
	uint8_t d0 = 0;
	uint16_t d7_2 = 0;
	uint32_t a6 = 0, player = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	if (jobs_pending != 0u)
		return check_joins(d1);
	t1 = continue_count_time;
	continue_count_time = t1 - 1u;
	if (t1 == 1u)
	{
		if (continue_count == 0u)
		{
			scene_step++;
			scene_substep = 0u;
			continue_count = 0u;
			continue_count_time = 0u;
			d7_2 = 0x200u;
			queue_job(d7_2);
			return d1;
		}
		continue_count_time = 0x48u;
		continue_count--;
		d7 = continue_count;
		d7 = draw_big_character(d6, (uint8_t)d7);
	}
	if ((players_joining | players_in_play) != 0u)
	{
		jobs_pending = 1u;
		d7_2 = 1u;
		queue_job(d7_2);
		d7_2 = 0xB7Fu;
		queue_job(d7_2);
		start_area_music();
		scene = 4u;
		scene_step = 1u;
		scene_substep = 0u;
		return d1;
	}
	if (continue_count > 0x10u)
		return check_joins(d1);
	d7_2 = (uint16_t)((d7 & ~0xFFu) | 3u);
	a6 = player_inputs_ADDRESS;
	player = PLAYER_ADDRESS(0);
	for (;;)
	{
		d0 = mem_read8(a6);
		a6++;
		if ((d0 & 0x30u) != 0u && PLAYER(player)->lives == 0u)
		{
			t2 = frame_count & 7u;
			d7_2 = t2;
			if (t2 == 0u)
				break;
		}
		t3 = d7_2 - 1u;
		d7_2 = t3;
		player += 8u;
		if (t3 == 0xFFFFu)
			return check_joins(d1);
	}
	continue_count_time = 1u;
	return check_joins(d1);
}

/* the GAME OVER after the continue, by its steps */
void game_over(uint16_t d6, uint32_t a5)
{
	switch ((uint32_t)(int8_t)scene_substep)
	{
	case 0:
		game_over_clear_text();
		return;
	case 1:
		game_over_start();
		return;
	case 2:
		game_over_wait(d6, a5);
		return;
	}
}

/* the texts cleared for GAME OVER */
void game_over_clear_text(void)
{
	uint16_t d7 = 0;

	jobs_pending++;
	d7 = 1u;
	queue_job(d7);
	scene_substep++;
}

/* the GAME OVER box with its colours and music */
void game_over_start(void)
{
	uint8_t d7_2 = 0;
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (jobs_pending != 0u)
		return;
	continue_count = 0xF0u;
	d7 = 1u;
	print_colour_text(d7);
	clear_palette_effects();
	a6 = 0xD2C4u;
	start_palette_effects(a6);
	a6 = 0xD2E6u;
	start_palette_effects(a6);
	fade_state = 0u;
	scene_substep++;
	d7_2 = 0x6Du;
	queue_sound(d7_2, a6);
}

/* GAME OVER held over the darkened play until the time runs out or a button, then the ranking */
void game_over_wait(uint16_t d6, uint32_t a5)
{
	uint8_t t1 = 0;

	if (jobs_pending == 0u)
	{
		game_over_skip();
		game_over_dim(d6, a5);
		t1 = continue_count;
		continue_count = t1 - 1u;
		if (t1 == 1u)
		{
			scene++;
			scene_step = 0u;
			scene_substep = 0u;
		}
	}
}

/* the play darkened behind the GAME OVER box */
void game_over_dim(uint16_t d6, uint32_t a5)
{
	if (fading == 0u)
	{
		a5 = 0xA08Eu;
		d6 = 0x1E02u;
		fade_state = 0u;
	}
	copy_palette_sets(d6, a5);
}

/* a button ends GAME OVER early */
void game_over_skip(void)
{
	uint8_t d7 = 0;

	if (continue_count >= 0xB0u || ((player_presses(0) | player_presses(1) | player_presses(2) | player_presses(3)) & 0x30u) == 0u)
		return;
	d7 = 0u;
	queue_sound(d7, 0u);
	scene++;
	scene_step = 0u;
	scene_substep = 0u;
}
