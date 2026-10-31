/**
 *    Name:        scenes/demo.c
 *    Description: the players' inputs, the demos' recorded ones, and the demo game
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the players' inputs for the turtles, or a demo's recorded ones */
uint32_t update_game_inputs(uint32_t d7)
{
	uint8_t d0 = 0;
	uint16_t d6 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	if (game_on == 0u)
	{
		turtle_inputs_3_frames_ago = turtle_inputs_2_frames_ago;
		turtle_inputs_2_frames_ago = turtle_inputs_last_frame;
		turtle_inputs_last_frame = (((uint32_t)demo_held_inputs(0) << 24u) | ((uint32_t)demo_held_inputs(1) << 16u) | ((uint32_t)demo_held_inputs(2) << 8u) | demo_held_inputs(3));
		d7_2 = 3u;
		a6 = channel_records_ADDRESS;
		a0 = demo_held_inputs_ADDRESS;
		do
		{
			d6 = (uint16_t)(d7_2 << 4);
			a1 = mem_read32(a6 + (int16_t)d6);
			a4 = mem_read32(a6 + 4u + (int16_t)d6);
			a3 = mem_read32(a6 + 8u + (int16_t)d6);
			a2 = mem_read32(a6 + 0xCu + (int16_t)d6);
			a5 = mem_read32(a1);
			t1 = mem_read8(a4);
			mem_write8(a4, t1 - 1u);
			if (t1 != 1u)
				mem_write8(a3, demo_held_inputs((uint32_t)(int16_t)d7_2));
			else
			{
				d0 = mem_read8(a5);
				a5++;
				mem_write8(a4, mem_read8(a5));
				scratch_byte = d0;
				d0 &= 0x7Fu;
				mem_write8(a3, d0);
				demo_held_inputs((uint32_t)(int16_t)d7_2) = d0;
				mem_write32(a1, a5 + 1u);
				switch (a2)
				{
				case 0x0048B2u:
					a6 = demo_join_player_1(a6);
					break;
				case 0x0048E6u:
					a6 = demo_join_player_2(a6);
					break;
				case 0x00491Au:
					a6 = demo_join_player_3(a6);
					break;
				case 0x00494Eu:
					a6 = demo_join_player_4(a6);
					break;
				}
			}
			t2 = d7_2 - 1u;
			d7_2 = t2;
		} while (t2 != 0xFFFFu);
		turtle_presses(0) = turtle_inputs(0) & ~(uint8_t)(turtle_inputs_last_frame >> 24u);
		turtle_presses(1) = turtle_inputs(1) & ~(uint8_t)(turtle_inputs_last_frame >> 16u);
		turtle_presses(2) = turtle_inputs(2) & ~(uint8_t)(turtle_inputs_last_frame >> 8u);
		turtle_presses(3) = turtle_inputs(3) & ~(uint8_t)turtle_inputs_last_frame;
		return d7_2;
	}
	turtle_inputs_3_frames_ago = turtle_inputs_2_frames_ago;
	turtle_inputs_2_frames_ago = turtle_inputs_last_frame;
	turtle_inputs_last_frame = (((uint32_t)turtle_inputs(0) << 24u) | ((uint32_t)turtle_inputs(1) << 16u) | ((uint32_t)turtle_inputs(2) << 8u) | turtle_inputs(3));
	turtle_inputs(0) = player_inputs(0);
	turtle_inputs(1) = player_inputs(1);
	turtle_inputs(2) = player_inputs(2);
	turtle_inputs(3) = player_inputs(3);
	turtle_presses(0) = player_presses(0);
	turtle_presses(1) = player_presses(1);
	turtle_presses(2) = player_presses(2);
	turtle_presses(3) = player_presses(3);
	return d7;
}

/* in a demo, the first player joins */
uint32_t demo_join_player_1(uint32_t a6)
{
	if ((int8_t)scratch_byte < 0 && (players_in_play & 1u) == 0u)
	{
		players_in_play |= 1u;
		players_joining |= 1u;
		a6 = reset_player_1();
		PLAYER(PLAYER_ADDRESS(0))->lives = (PLAYER(PLAYER_ADDRESS(0))->lives & 0xFFu) | 0x100u;
	}
	return a6;
}

/* in a demo, the second player joins */
uint32_t demo_join_player_2(uint32_t a6)
{
	if ((int8_t)scratch_byte < 0 && (players_in_play & 2u) == 0u)
	{
		players_in_play |= 2u;
		players_joining |= 2u;
		a6 = reset_player_2();
		PLAYER(PLAYER_ADDRESS(1))->lives = (PLAYER(PLAYER_ADDRESS(1))->lives & 0xFFu) | 0x100u;
	}
	return a6;
}

/* in a demo, the third player joins */
uint32_t demo_join_player_3(uint32_t a6)
{
	if ((int8_t)scratch_byte < 0 && (players_in_play & 4u) == 0u)
	{
		players_in_play |= 4u;
		players_joining |= 4u;
		a6 = reset_player_3();
		PLAYER(PLAYER_ADDRESS(2))->lives = (PLAYER(PLAYER_ADDRESS(2))->lives & 0xFFu) | 0x100u;
	}
	return a6;
}

/* in a demo, the fourth player joins */
uint32_t demo_join_player_4(uint32_t a6)
{
	if ((int8_t)scratch_byte < 0 && (players_in_play & 8u) == 0u)
	{
		players_in_play |= 8u;
		players_joining |= 8u;
		a6 = reset_player_4();
		PLAYER(PLAYER_ADDRESS(3))->lives = (PLAYER(PLAYER_ADDRESS(3))->lives & 0xFFu) | 0x100u;
	}
	return a6;
}

/* the demo game */
void attract_demo(uint32_t d1, uint16_t d5, uint16_t d6, uint32_t d7, uint32_t a5)
{
	uint32_t d7_2 = 0;

	if (new_credit != 0u)
	{
		frame_count = saved_frame_count;
		go_to_coin_screen();
		return;
	}
	d7_2 = (d7 & ~0xFFu) | scene;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(int8_t)d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 2);
	switch ((uint32_t)(int16_t)d7_2)
	{
	case 0:
		begin_demo();
		return;
	case 16:
		demo_play(d1, d5, d7_2);
		return;
	case 32:
		end_demo();
		return;
	case 4:
		scene_choose_turtles();
		return;
	case 8:
		scene_area_setup();
		return;
	case 12:
		scene_area_title(d1);
		return;
	case 20:
		scene_area_exit(d1, d7_2);
		return;
	case 24:
		scene_ending(d6, a5);
		return;
	case 28:
		scene_continue(d1, d6, a5);
		return;
	}
}

/* the demo's start: the play cleared and the demo's settings */
void begin_demo(void)
{
	clear_play();
	PLAYER(PLAYER_ADDRESS(0))->health_bars = 0u;
	PLAYER(PLAYER_ADDRESS(1))->health_bars = 0u;
	PLAYER(PLAYER_ADDRESS(2))->health_bars = 0u;
	PLAYER(PLAYER_ADDRESS(3))->health_bars = 0u;
	difficulty_setting = 0u;
	time_without_knockout = 0u;
	saved_frame_count = frame_count;
	frame_count = 0u;
	start_demo();
}

void start_demo(void)
{
	uint16_t d0 = 0;

	d0 = (uint16_t)((uint32_t)demo << 2);
	area = demo_settings[d0];
	players_in_play = rom_004E89[d0];
	players_joining = rom_004E8A[d0];
	players_knocked_out = 0u;
	players_out_of_lives = 0u;
	demo_held_inputs(0) = 0u;
	demo_held_inputs(1) = 0u;
	demo_held_inputs(2) = 0u;
	demo_held_inputs(3) = 0u;
	d0 = (uint16_t)((uint32_t)d0 << 2);
	demo_inputs_1 = demo_inputs[d0 / 4u];
	demo_inputs_2 = rom_004E98[d0 / 4u];
	demo_inputs_3 = rom_004E9C[d0 / 4u];
	demo_inputs_4 = rom_004EA0[d0 / 4u];
	attract_timer = 1u;
	demo_hold_2 = 1u;
	demo_hold_3 = 1u;
	demo_hold_4 = 1u;
	demo_frames = 0u;
	scene++;
	scene_step = 0u;
}

/* the demo plays for a while */
void demo_play(uint32_t d1, uint16_t d5, uint32_t d7)
{
	if (players_in_play != 0u)
	{
		demo_frames++;
		if (demo_frames < 0x384u)
		{
			scene_play(d1, d5, d7);
			return;
		}
	}
	scene = 8u;
	scene_step = 0u;
}

/* the demo's end: the next demo, the players out */
void end_demo(void)
{
	uint8_t d7 = 0;

	d7 = 0u;
	queue_sound(d7, 0u);
	layer_priority = 0u;
	io_write8(PRIORITY_0C0001, layer_priority);
	area_continues_scene = 0u;
	frame_count = saved_frame_count;
	demo++;
	if (demo >= 3u)
		demo = 0u;
	players_in_play = 0u;
	players_joining = 0u;
	players_knocked_out = 0u;
	players_out_of_lives = 0u;
	PLAYER(PLAYER_ADDRESS(0))->health_bars = 0u;
	PLAYER(PLAYER_ADDRESS(1))->health_bars = 0u;
	PLAYER(PLAYER_ADDRESS(2))->health_bars = 0u;
	PLAYER(PLAYER_ADDRESS(3))->health_bars = 0u;
	game_step++;
	scene = 0u;
	scene_step = 0u;
	scene_substep = 0u;
	scene_subsubstep = 0u;
}
