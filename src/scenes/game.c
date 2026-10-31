/**
 *    Name:        scenes/game.c
 *    Description: the game's scenes: a new game, the players' turtles, an area's set-up, its story and title screens, the play, the area's exit
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* a new game, by its steps */
void scene_new_game(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		new_game_reset();
		break;
	case 1:
		new_game_first_area();
		break;
	}
	check_joins(0u);
}

/* the players' records and scores, the scroll, the difficulty and the play time reset for a new game */
void new_game_reset(void)
{
	uint8_t d7 = 0;

	if (jobs_pending == 0u)
	{
		clear_play();
		reset_player_1();
		reset_player_2();
		reset_player_3();
		reset_player_4();
		d7 = 0xFu;
		clear_scores(d7);
		layer_a_scroll_x = 0u;
		layer_a_scroll_y = 0u;
		layer_b_scroll_x = 0u;
		layer_b_scroll_y = 0u;
		difficulty_setting = (dip_switches_2 & 0x60u) >> 5;
		difficulty_from_time = 0u;
		hide_press_start = 0u;
		scene_step++;
	}
}

/* the game starts at the first area */
void new_game_first_area(void)
{
	area = 0u;
	scene++;
	scene_step = 0u;
}

/* the turtle each player plays, by its steps: in this set each player his own */
void scene_choose_turtles(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		choose_turtles_clear();
		break;
	case 1:
		choose_turtles_fixed();
		break;
	case 2:
		choose_turtles_done();
		break;
	}
	check_joins(0u);
}

/* every player on the first turtle */
void choose_turtles_clear(void)
{
	player_turtles(0) = 0u;
	player_turtles(1) = 0u;
	player_turtles(2) = 0u;
	player_turtles(3) = 0u;
	scene_step++;
}

/* each player on his own turtle, Leonardo first */
void choose_turtles_fixed(void)
{
	player_turtles(0) = 0u;
	player_turtles(1) = 1u;
	player_turtles(2) = 2u;
	player_turtles(3) = 3u;
	scene_step++;
}

/* on to the area's set-up */
void choose_turtles_done(void)
{
	scene++;
	scene_step = 0u;
}

/* an area's set-up, by its steps */
void scene_area_setup(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		area_setup_variables();
		break;
	case 1:
		area_setup_clear_objects();
		break;
	case 2:
		area_setup_done();
		break;
	}
	check_joins(0u);
}

/* the area's stage and variables set, the play's work and the layers cleared */
void area_setup_variables(void)
{
	uint16_t d1 = 0, d7 = 0;

	d1 = (uint16_t)((uint32_t)area << 1);
	area_continues_scene = indexed_table_of_8_bit_values_00634C[d1];
	stage = rom_00634D[d1];
	unk_060123 = 0u;
	unk_060124 = 0u;
	exit_cutscene = 0u;
	clear_play();
	area_cleared = 0u;
	area_beaten = 0u;
	hide_press_start = 0u;
	scene_step++;
	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
}

/* the objects cleared once the layers are */
void area_setup_clear_objects(void)
{
	if (jobs_pending == 0u)
	{
		clear_objects();
		scene_step++;
	}
}

/* on to the area's story and title */
void area_setup_done(void)
{
	scene++;
	scene_step = 0u;
}

/* the area's story and title screens, by their steps */
void scene_area_title(uint32_t d1)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		area_title_intro();
		break;
	case 1:
		area_title_screen(d1);
		break;
	case 2:
		area_title_done();
		break;
	}
	check_joins(d1);
}

/* in a game's first area the intro, by its steps; else straight to its end */
void area_title_intro(void)
{
	if (area != 0u || game_on == 0u)
	{
		area_title_intro_end();
		return;
	}
	switch ((uint32_t)(int8_t)scene_substep)
	{
	case 0:
		area_title_intro_start();
		return;
	case 1:
		area_title_intro_run();
		return;
	}
}

/* the intro started on a clean screen */
void area_title_intro_start(void)
{
	scene_substep++;
	game_scene_timer = 0xB4u;
	io_write8(PRIORITY_0C0001, 0u);
	layer_priority = 0u;
	clear_objects();
	clear_sprite_ram();
	start_intro();
	hide_all_sprites();
}

/* the intro played until it ends or a button skips it */
void area_title_intro_run(void)
{
	uint8_t d7 = 0;
	uint32_t ignored = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;

	if (intro_over != 0u)
	{
		area_title_intro_end();
		return;
	}
	t1 = game_scene_timer;
	game_scene_timer = t1 - 1u;
	if (t1 == 0u)
		game_scene_timer = 0u;
	if (palettes_busy != 0u || game_scene_timer != 0u || ((player_presses(0) | player_presses(1) | player_presses(2) | player_presses(3)) & 0x30u) == 0u)
	{
		run_intro();
		build_draw_list(&ignored, &ignored_3);
		draw_sprites(&ignored_4, &ignored_3);
		return;
	}
	d7 = 0x7Eu;
	queue_sound(d7, 0u);
	area_title_intro_end();
}

/* the screen cleared after the intro */
void area_title_intro_end(void)
{
	uint32_t ignored = 0, ignored_2 = 0;

	clear_palette_effects();
	clear_objects();
	clear_sprite_ram();
	clear_layers(&ignored, &ignored_2);
	scene_step++;
	scene_substep = 0u;
	scene_subsubstep = 0u;
}

/* the area's title screen, by its steps */
void area_title_screen(uint32_t d1)
{
	switch ((uint32_t)(int8_t)scene_substep)
	{
	case 0:
		area_title_clear();
		return;
	case 1:
		area_title_reset();
		return;
	case 2:
		area_title_start_text();
		return;
	case 3:
		area_title_wait(d1);
		return;
	}
}

/* the layers cleared and the area's palettes requested */
void area_title_clear(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	scene_substep++;
	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	a6 = area_palettes_ADDRESS;
	d7 = 0x10Fu;
	post_palette_request(d7, a6);
}

/* the objects cleared and the scroll reset */
void area_title_reset(void)
{
	if (jobs_pending == 0u && palettes_busy == 0u)
	{
		clear_objects();
		reset_layers_scroll();
		scene_substep++;
	}
}

/* the area's SCENE text started and the boxes drawn, in a game and for the areas that have one */
void area_title_start_text(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, d7_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	scene_substep++;
	d7 = 0x200u;
	queue_job(d7);
	if (game_on == 0u || (int8_t)area_continues_scene < 0)
	{
		scene_step++;
		scene_substep = 0u;
		return;
	}
	a6 = rom_019866[stage];
	ignored = start_typed_text_at_once(a6);
	game_scene_timer = 0xB4u;
	d7_2 = 0xB7Fu;
	draw_player_boxes(d7_2, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
}

/* the text typed and the health bars filled until the time runs out or a button */
void area_title_wait(uint32_t d1)
{
	uint16_t d7_2 = 0;
	uint32_t d7 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, player = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	refill_health_bars();
	d7 = players_in_play;
	d7 = (uint16_t)(d7 + 0xB20u);
	draw_player_boxes(d7, &d1, &ignored, &ignored_2, &ignored_3);
	update_players_in_game(d1, &ignored_2, &d7, &ignored_4);
	type_next_character();
	t1 = game_scene_timer;
	game_scene_timer = t1 - 1u;
	if (t1 != 1u && (game_scene_timer >= 0x8Cu || ((player_presses(0) | player_presses(1) | player_presses(2) | player_presses(3)) & 0x30u) == 0u))
		return;
	d7_2 = 3u;
	player = PLAYER_ADDRESS(3);
	do
	{
		if ((players_in_play & shl32(1u, (int)(d7_2 & 7u))) != 0u)
			PLAYER(player)->health_bars = 0xAu;
		t2 = d7_2 - 1u;
		d7_2 = t2;
		player -= 8u;
	} while (t2 != 0xFFFFu);
	scene_step++;
	scene_substep = 0u;
}

/* a bar more of health every 8 frames for the players in play, with a tick */
void refill_health_bars(void)
{
	uint8_t d6 = 0, d7_2 = 0;
	uint16_t d7 = 0;
	uint32_t player = 0;
	uint16_t t1 = 0;

	if (game_scene_timer >= 0xAAu || (frame_count & 7u) != 0u)
		return;
	d6 = 0u;
	d7 = 3u;
	player = PLAYER_ADDRESS(3);
	do
	{
		if ((players_in_play & shl32(1u, (int)(d7 & 7u))) != 0u && PLAYER(player)->health_bars < 0xAu)
		{
			PLAYER(player)->health_bars++;
			d6 = 1u;
		}
		t1 = d7 - 1u;
		d7 = t1;
		player -= 8u;
	} while (t1 != 0xFFFFu);
	if (d6 != 0u)
	{
		d7_2 = 1u;
		queue_sound(d7_2, player);
	}
}

/* on to the play */
void area_title_done(void)
{
	scene++;
	scene_step = 0u;
	scene_substep = 0u;
	scene_subsubstep = 0u;
}

/* the play, by its steps: the area's entry, then the play's frames */
void scene_play(uint32_t d1, uint16_t d5, uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | scene_step;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(int8_t)d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 2);
	switch ((uint32_t)(int16_t)d7_2)
	{
	case 0:
		play_entry(d1, d5, d7_2);
		return;
	case 4:
		play_main(d1, d5, d7_2);
		return;
	}
}

/* the area's entry, by its steps */
void play_entry(uint32_t d1, uint16_t d5, uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | scene_substep;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(int8_t)d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 2);
	switch ((uint32_t)(int16_t)d7_2)
	{
	case 0:
		play_entry_palettes();
		return;
	case 4:
		play_entry_layers();
		return;
	case 8:
		play_entry_show_game_over();
		return;
	case 12:
		play_entry_start(d1, d5, (uint16_t)d7_2);
		return;
	case 16:
		play_entry_run(d1, d7_2);
		return;
	}
}

/* the layers cleared, the area's palettes and palette effects requested */
void play_entry_palettes(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	a6 = area_palettes_ADDRESS;
	d7 = 0x10Fu;
	post_palette_request(d7, a6);
	start_area_palette_effects();
	scene_substep++;
}

/* the scroll, the objects, the boxes, and the stage's layer priority and tile banks */
void play_entry_layers(void)
{
	uint16_t d7 = 0;

	if (jobs_pending == 0u && palettes_busy == 0u)
	{
		reset_layers_scroll();
		clear_objects();
		d7 = 0xB7Fu;
		queue_job(d7);
		d7 = stage;
		layer_priority = area_layer_priorities[d7];
		io_write8(PRIORITY_0C0001, layer_priority);
		entry_without_blink = area_settings_060127[d7];
		d7 = (uint16_t)((uint32_t)d7 << 1);
		io_write8(TILES_106B00, area_tile_banks[d7]);
		tile_banks_0_1 = area_tile_banks[d7];
		io_write8(TILES_106E00, rom_00676F[d7]);
		tile_banks_2_3 = rom_00676F[d7];
		scene_substep++;
	}
}

/* the GAME OVER box when a demo plays */
void play_entry_show_game_over(void)
{
	uint16_t d7 = 0;

	if (jobs_pending != 0u)
		return;
	if (game_on == 0u)
	{
		d7 = 1u;
		print_colour_text(d7);
	}
	scene_substep++;
}

/* the turtles, the spawns, the players' slots and the music started for the area */
void play_entry_start(uint32_t d1, uint32_t d5, uint16_t d7)
{
	uint8_t d4 = 0;
	uint16_t d7_2 = 0;
	uint32_t a1 = 0, d7_3 = 0, player = 0;
	uint16_t t1 = 0;

	if (jobs_pending != 0u)
		return;
	if (game_on == 0u)
	{
		player = PLAYER_ADDRESS(3);
		d7_2 = (uint16_t)((d7 & ~0xFFu) | 3u);
		do
		{
			if ((players_in_play & shl32(1u, (int)(d7_2 & 7u))) != 0u)
				PLAYER(player)->lives = 1u;
			t1 = d7_2 - 1u;
			d7_2 = t1;
			player -= 8u;
		} while (t1 != 0xFFFFu);
	}
	if (game_on == 0u)
	{
		frame_count = 0u;
		difficulty = 0u;
	}
	area_entry_done = 0u;
	d7_3 = players_in_play;
	d7_3 = d7_3 & ~players_joining;
	turtle_start_area((uint8_t)d7_3, &d1, &a1);
	update_players_in_game(d1, &d5, &d7_3, &a1);
	entry_without_blink = 0u;
	d4 = 0xFu;
	draw_scores(d4);
	start_area_spawns();
	start_player_slots();
	hide_all_sprites();
	run_objects(&d5, &d7_3, &a1);
	run_objects(&d5, &d7_3, &a1);
	music = 0u;
	start_area_music();
	scene_substep++;
	hide_press_start = 1u;
}

/* the turtles walk in until the entry is done */
void play_entry_run(uint32_t d1, uint32_t d7)
{
	uint16_t d7_2 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	update_players_in_game(d1, &ignored, &d7, &ignored_2);
	do_nothing();
	if (area_entry_done == 0u)
	{
		run_area_entry();
		check_attacks();
		build_draw_list(&ignored_3, &ignored_4);
		draw_sprites(&ignored_5, &ignored_4);
		return;
	}
	d7_2 = 0xB7Fu;
	queue_job(d7_2);
	if (game_on == 0u)
	{
		frame_count = 0u;
		random_seed = 0u;
	}
	scene_step++;
	scene_substep = 0u;
	hide_press_start = 0u;
}

/* the play's frame with the inputs and the players who join */
void play_main(uint32_t d1, uint16_t d5, uint32_t d7)
{
	d7 = update_game_inputs(d7);
	play_frame(d1, d5, d7);
	check_joins(d1);
}

/* the play's frame work, then the continue when no one plays or the exit when the area is cleared */
void play_frame(uint32_t d1, uint32_t d5, uint32_t d7)
{
	uint8_t d6 = 0;
	uint32_t a0 = 0, a1 = 0, d1_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0;

	if (game_on == 0u)
	{
		d7 = (d7 & ~0xFFu) | (uint8_t)frame_count;
		d6 = (uint8_t)d7;
		if ((d7 & 0xFu) == 0u)
		{
			d7 = (d7 & ~0xFFFFu) | 1u;
			if ((d6 & 0x30u) == 0u)
				d7 = d7 | 0x80u;
			print_colour_text((uint16_t)d7);
		}
	}
	update_players_in_game(d1, &d5, &d7, &ignored);
	do_nothing();
	d7 = update_difficulty(d7);
	update_time_without_knockout(d6, &d1_2, &d5, &d7);
	update_players(d1_2, &d5, &d7, &a1);
	update_area_layers(&d5, &d7, &a1);
	run_objects(&d5, &d7, &a1);
	check_attacks();
	build_draw_list(&ignored_2, &a0);
	draw_sprites(&ignored_3, &a0);
	sound_flying_drones(a0);
	if (stage < 2u)
		flicker_fire_priority();
	if ((players_out_of_lives | players_joining | players_in_play) == 0u)
	{
		scene = 7u;
		scene_step = 0u;
		scene_substep = 0u;
		scene_subsubstep = 0u;
		return;
	}
	if (area_cleared == 0u || ((players_knocked_out | players_out_of_lives) & 0xFu) != 0u)
		return;
	scene = 5u;
	scene_step = 0u;
	scene_substep = 0u;
	scene_subsubstep = 0u;
}

/* the fire flickering over the sprites in the first two stages */
void flicker_fire_priority(void)
{
	uint8_t d7 = 0;

	if ((uint8_t)drill_arrival == 0u || (uint8_t)drill_arrival == 0xFFu)
	{
		d7 = indexed_table_of_8_bit_values_006A18[(uint8_t)frame_count & 7u];
		layer_priority = d7;
		io_write8(PRIORITY_0C0001, d7);
		return;
	}
	io_write8(PRIORITY_0C0001, 4u);
	layer_priority = 4u;
}

/* the enemies' level from the settings, the players in play and the play time */
uint32_t update_difficulty(uint32_t d7)
{
	uint32_t d7_2 = 0;
	uint16_t t1 = 0;

	difficulty = 2u;
	if (game_on == 0u)
		return d7;
	difficulty = difficulty_setting;
	d7_2 = (d7 & ~0xFFFFu) | 3u;
	do
	{
		if ((players_in_play & shl32(1u, (int)(d7_2 & 7u))) != 0u)
			difficulty++;
		t1 = d7_2 - 1u;
		d7_2 = (d7_2 & ~0xFFFFu) | t1;
	} while (t1 != 0xFFFFu);
	d7 = (d7_2 & ~0xFFu) | difficulty_from_time;
	difficulty += d7;
	if (difficulty >= 7u)
		difficulty = 7u;
	return d7;
}

/* the area's music or a boss's in a game */
void start_area_music(void)
{
	uint8_t d7 = 0;
	uint8_t t1 = 0;

	if (game_on == 0u)
		return;
	if (drill_rumbling != 0u)
	{
		d7 = 0x34u;
		queue_sound(d7, 0u);
		if (stage == 6u && helicopter_count != 0u)
		{
			d7 = 0xAu;
			queue_sound(d7, 0u);
		}
		return;
	}
	t1 = music;
	d7 = t1;
	if (t1 == 0u)
	{
		d7 = TABLE8(indexed_table_of_8_bit_values_006B0C, (uint32_t)(int16_t)(int8_t)stage);
		music = d7;
	}
	queue_sound(d7, 0u);
	if (stage == 6u && helicopter_count != 0u)
	{
		d7 = 0xAu;
		queue_sound(d7, 0u);
	}
}

/* the area's exit, by its steps */
void scene_area_exit(uint32_t d1, uint32_t d7)
{
	uint32_t d7_2 = 0, ignored = 0, ignored_2 = 0;

	d7_2 = (d7 & ~0xFFu) | scene_step;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(int8_t)d7_2;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 2);
	switch ((uint32_t)(int16_t)d7_2)
	{
	case 0:
		area_exit_begin(&d1, &d7_2);
		break;
	case 4:
		area_exit_play(&d1, &d7_2);
		break;
	case 8:
		area_exit_next_area();
		break;
	}
	do_nothing();
	if (exit_cutscene != 0u)
		return;
	update_players_in_game(d1, &ignored, &d7_2, &ignored_2);
}

/* the turtles start walking out of the cleared area */
void area_exit_begin(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;

	scene_step++;
	if (stage != 0u)
	{
		d7 = (d7 & ~0xFFFFu) | 0xFEu;
		queue_sound((uint8_t)d7, 0u);
	}
	turtle_start_area_exit(p_d1, &d7);
	hide_press_start = 1u;
	unk_060081 = 0x78u;
	*p_d7 = d7;
}

/* the exit's frame */
void area_exit_play(uint32_t *p_d1, uint32_t *p_d7)
{
	uint32_t ignored = 0;

	*p_d1 = run_area_exit(*p_d1);
	build_draw_list(p_d7, &ignored);
	draw_sprites(p_d1, &ignored);
	if (stage < 2u)
		flicker_fire_priority();
}

/* on to the next area, or to the ending after the last one */
void area_exit_next_area(void)
{
	uint8_t d7 = 0;

	d7 = 0u;
	queue_sound(d7, 0u);
	if (stage == 9u)
	{
		scene++;
		scene_step = 0u;
		return;
	}
	area++;
	area_cleared = 0u;
	scene = 2u;
	scene_step = 0u;
}
