/**
 *    Name:        scenes/attract.c
 *    Description: the attract mode's steps: the title, the coin's screen, the opening's steps, a character's profile, BEST 10 PLAYERS, its end
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* layer B all one tile */
void fill_layer_b(uint8_t d6, uint32_t d7)
{
	uint16_t d5 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	d7 = fill_colour(d7);
	d6 += 0x30u;
	d5 = 0xFFEu;
	a6 = TILE_RAM + 0x4000u;
	do
	{
		io_write8(a6, d7);
		a6++;
		io_write8(a6, d6);
		t1 = d5 - 1u;
		d5 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
}

/* the colour of the tile layer B is filled with */
uint32_t fill_colour(uint32_t d7)
{
	uint32_t d7_2 = 0;

	d7_2 = text_colours[d7];
	return d7_2;
}

/* nothing */
void do_nothing(void)
{
}

/* the title screen */
void attract_title(void)
{
	uint8_t d7 = 0;

	if (new_credit != 0u)
	{
		d7 = 0x7Eu;
		queue_sound(d7, 0u);
		go_to_coin_screen();
		return;
	}
	switch ((uint32_t)(int8_t)scene)
	{
	case 0:
		title_setup();
		return;
	case 1:
		title_logo();
		return;
	}
}

/* the title's screen set up */
void title_setup(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		title_clear();
		return;
	case 1:
		title_palettes();
		return;
	case 2:
		title_background();
		return;
	}
}

/* the title's screen cleared */
void title_clear(void)
{
	uint16_t d7 = 0;

	if (jobs_pending == 0u)
	{
		clear_play();
		jobs_pending++;
		d7 = 7u;
		queue_job(d7);
		scene_step++;
	}
}

/* the title's palettes */
void title_palettes(void)
{
	if (jobs_pending == 0u)
	{
		request_game_step_palettes();
		clear_palette_effects();
		start_game_step_palette_effects();
		scene_step++;
	}
}

/* the title's blue background */
void title_background(void)
{
	uint8_t d6 = 0;
	uint16_t d7 = 0;

	if (jobs_pending == 0u && palettes_busy == 0u)
	{
		do_nothing();
		layer_b_scroll_x = 0x60u;
		layer_b_scroll_y = 0u;
		d7 = 1u;
		d6 = 3u;
		fill_layer_b(d6, d7);
		hide_all_sprites();
		scene++;
		scene_step = 0u;
	}
}

/* the title's logo */
void title_logo(void)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		start_title_logo();
		break;
	case 1:
		title_banner_move();
		break;
	case 2:
		title_turtles_slide_in();
		break;
	case 3:
		title_wait();
		break;
	}
	build_draw_list(&ignored, &ignored_2);
	draw_sprites(&ignored_3, &ignored_2);
}

/* the logo's pieces placed */
void start_title_logo(void)
{
	uint16_t d0 = 0, d6 = 0, d7_2 = 0;
	uint32_t a6 = 0, animation = 0, d7 = 0, ignored = 0, object = 0;
	uint16_t t1 = 0;

	object = OBJECT_ADDRESS(12);
	d0 = 2u;
	do
	{
		OBJECT(object)->flags = 0x81u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->colour = 0xFFu;
		d7 = version;
		d7 = (uint16_t)(d7 << 3);
		a6 = 0x151D8u + d7;
		d6 = 0u;
		if ((uint8_t)d0 != 0u)
		{
			d6 = 1u;
			if ((uint8_t)d0 != 2u)
			{
				d6 = 8u;
				a6 -= d7;
			}
		}
		animation = DATA32(a6 + (uint16_t)((uint32_t)d6 << 2));
		set_animation(ignored, object, animation);
		a6 = indexed_table_of_16_bit_values_004B58_ADDRESS;
		if ((version & 2u) != 0u)
			a6 = 0x4B64u;
		d7_2 = (uint16_t)((uint32_t)d0 << 2);
		OBJECT(object)->screen_x = mem_read16(a6 + (int16_t)d7_2);
		OBJECT(object)->screen_y = mem_read16(a6 + 2u + (int16_t)d7_2);
		t1 = d0 - 1u;
		d0 = t1;
		object += 0x50u;
	} while (t1 != 0xFFFFu);
	initials_entered(0) = 0u;
	initials_entered(1) = 0u;
	scene_step++;
}

/* the banner's moves */
void title_banner_move(void)
{
	switch ((uint32_t)(int8_t)scene_substep)
	{
	case 0:
		title_banner_drop();
		break;
	case 1:
		title_banner_bounce();
		break;
	case 2:
		title_banner_wait();
		break;
	}
}

/* the banner drops to the middle */
void title_banner_drop(void)
{
	OBJECT(OBJECT_ADDRESS(14))->screen_y -= 7u;
	if (OBJECT(OBJECT_ADDRESS(14))->screen_y < 0x58u)
	{
		scene_substep++;
		initials_entered(0) = 0u;
		initials_entered(1) = 7u;
	}
}

/* the banner bounces back to the top */
void title_banner_bounce(void)
{
	uint16_t d7 = 0;
	uint32_t object = 0;
	uint32_t initials_entered_0_halfword = 0;

	object = OBJECT_ADDRESS(14);
	if ((((uint32_t)initials_entered(0) << 8u) | initials_entered(1)) != 0xFFF9u)
	{
		initials_entered_0_halfword = (((uint32_t)initials_entered(0) << 8u) | initials_entered(1)) - 1u;
		initials_entered(0) = (uint8_t)(initials_entered_0_halfword >> 8u);
		initials_entered(1) = (uint8_t)initials_entered_0_halfword;
	}
	OBJECT(object)->screen_y -= (((uint32_t)initials_entered(0) << 8u) | initials_entered(1));
	d7 = 0xC0u;
	if ((version & 2u) != 0u)
		d7 = 0xD0u;
	if (d7 < OBJECT(object)->screen_y)
	{
		OBJECT(object)->screen_y = d7;
		scene_substep++;
		attract_timer = 0x14u;
		initials_entered(0) = 0u;
		initials_entered(1) = 0u;
	}
}

/* the banner stays a moment */
void title_banner_wait(void)
{
	uint8_t t1 = 0;

	t1 = attract_timer;
	attract_timer = t1 - 1u;
	if (t1 == 1u)
	{
		scene_step++;
		scene_substep = 0u;
		return;
	}
}

/* TURTLES slides in, then the copyright */
void title_turtles_slide_in(void)
{
	uint32_t a5 = 0, object = 0;

	object = OBJECT_ADDRESS(12);
	OBJECT(OBJECT_ADDRESS(12))->screen_x -= 0xAu;
	if (OBJECT(OBJECT_ADDRESS(12))->screen_x >= 0x100u)
		return;
	OBJECT(object)->screen_x = 0x100u;
	attract_timer = 0xF0u;
	scene_step++;
	a5 = table_loaded_by_lea_004C76_ADDRESS;
	if ((version & 1u) != 0u)
		a5 = 0x4C7Cu;
	queue_jobs(a5);
}

/* the title stays, then the attract mode goes on */
void title_wait(void)
{
	uint8_t t1 = 0;

	t1 = attract_timer;
	attract_timer = t1 - 1u;
	if (t1 == 1u)
	{
		game_step++;
		scene = 0u;
		scene_step = 0u;
		return;
	}
}

/* a character's profile */
void attract_profile(void)
{
	if (new_credit != 0u)
	{
		go_to_coin_screen();
		return;
	}
	switch ((uint32_t)(int8_t)scene)
	{
	case 0:
		profile_setup();
		return;
	case 1:
		profile_show();
		return;
	}
}

/* the profile's screen set up */
void profile_setup(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		profile_pause();
		return;
	case 1:
		profile_clear();
		return;
	case 2:
		profile_clear_layers();
		return;
	case 3:
		profile_palettes();
		return;
	case 4:
		profile_start_text();
		return;
	}
}

/* a short pause */
void profile_pause(void)
{
	step_timer = 2u;
	scene_step++;
}

/* the play cleared */
void profile_clear(void)
{
	uint8_t t1 = 0;

	if (jobs_pending == 0u)
	{
		t1 = step_timer;
		step_timer = t1 - 1u;
		if (t1 == 0u)
		{
			clear_play();
			scene_step++;
		}
	}
}

/* the layers cleared */
void profile_clear_layers(void)
{
	uint16_t d7 = 0;

	if (jobs_pending == 0u)
	{
		jobs_pending++;
		d7 = 7u;
		queue_job(d7);
		scene_step++;
	}
}

/* the profile's palettes */
void profile_palettes(void)
{
	if (jobs_pending == 0u)
	{
		request_game_step_palettes();
		clear_palette_effects();
		start_game_step_palette_effects();
		scene_step++;
	}
}

/* the profile's text starts typing */
void profile_start_text(void)
{
	uint32_t carry = 0, extend = 0;
	uint8_t d7_2 = 0;
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (jobs_pending == 0u && palettes_busy == 0u)
	{
		d7 = profile_character;
		carry = d7 >> 14;
		extend = carry;
		a6 = texts_019272[d7 & 0x3FFFu];
		d7_2 = 1u;
		start_text_typed_in_colours(d7_2, a6, extend);
		hide_all_sprites();
		d7_2 = 0x78u;
		queue_sound(d7_2, a6);
		scene++;
		scene_step = 0u;
	}
}

/* the profile's picture and text */
void profile_show(void)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		profile_start_picture();
		break;
	case 1:
		profile_move_picture();
		break;
	case 2:
		profile_type_text();
		break;
	case 3:
		profile_wait();
		break;
	}
	build_draw_list(&ignored, &ignored_2);
	draw_sprites(&ignored_3, &ignored_2);
}

/* the character's picture placed */
void profile_start_picture(void)
{
	uint32_t a6 = 0, animation = 0, d7 = 0, picture = 0;
	uint32_t unk_22_halfword = 0;

	if (jobs_pending == 0u)
	{
		picture = OBJECT_ADDRESS(12);
		OBJECT(OBJECT_ADDRESS(12))->flags = 0x81u;
		OBJECT(OBJECT_ADDRESS(12))->contacts = 0u;
		OBJECT(OBJECT_ADDRESS(12))->colour = 0xFFu;
		animation = animations_0143D4[profile_character];
		set_animation(0u, picture, animation);
		d7 = profile_character;
		a6 = table_loaded_by_lea_005078_ADDRESS + (uint16_t)(d7 << 4);
		OBJECT(OBJECT_ADDRESS(12))->screen_x = DATA16(a6);
		a6 += 2u;
		OBJECT(OBJECT_ADDRESS(12))->screen_y = DATA16(a6);
		a6 += 2u;
		OBJECT(OBJECT_ADDRESS(12))->unk_20 = DATA16(a6);
		a6 += 2u;
		unk_22_halfword = DATA16(a6);
		OBJECT(OBJECT_ADDRESS(12))->unk_22 = (uint8_t)(unk_22_halfword >> 8u);
		OBJECT(OBJECT_ADDRESS(12))->unk_23 = (uint8_t)unk_22_halfword;
		a6 += 2u;
		OBJECT(OBJECT_ADDRESS(12))->x_speed = DATA16(a6);
		OBJECT(OBJECT_ADDRESS(12))->y_speed = DATA16(a6 + 2u);
		scene_step++;
	}
}

/* the picture moves into its place */
void profile_move_picture(void)
{
	uint8_t d7 = 0;
	uint16_t d7_2 = 0;
	uint32_t picture = 0;

	if (sound_stopped_by_coin != 0u)
	{
		d7 = 0x78u;
		queue_sound(d7, 0u);
	}
	picture = OBJECT_ADDRESS(12);
	d7_2 = (uint16_t)(OBJECT(OBJECT_ADDRESS(12))->x_speed + OBJECT(OBJECT_ADDRESS(12))->screen_x);
	if (d7_2 == OBJECT(OBJECT_ADDRESS(12))->unk_20)
		OBJECT(picture)->x_speed = 0;
	OBJECT(picture)->screen_x = d7_2;
	d7_2 = (uint16_t)(OBJECT(picture)->y_speed + OBJECT(picture)->screen_y);
	if (d7_2 == OBJECT(picture)->profile.end_y)
		OBJECT(picture)->y_speed = 0;
	OBJECT(picture)->screen_y = d7_2;
	if ((OBJECT(picture)->x_speed | OBJECT(picture)->y_speed) == 0u)
		scene_step++;
}

/* the text typed on */
void profile_type_text(void)
{
	uint8_t d7 = 0;

	type_text_in_colours();
	if (typed_passes_left == 0u)
	{
		step_timer = 0x64u;
		scene_step++;
		d7 = 0xFEu;
		queue_sound(d7, 0u);
		return;
	}
	if (sound_stopped_by_coin != 0u)
	{
		d7 = 0x78u;
		queue_sound(d7, 0u);
	}
}

/* the profile stays, then the next character's comes next time */
void profile_wait(void)
{
	uint8_t t1 = 0;

	t1 = step_timer;
	step_timer = t1 - 1u;
	if (t1 != 1u)
		return;
	profile_character++;
	if (profile_character >= 6u)
		profile_character = 0u;
	game_step++;
	scene = 0u;
	scene_step = 0u;
}

/* the attract mode's end */
void attract_end(void)
{
	if (new_credit != 0u)
	{
		go_to_coin_screen();
		return;
	}
	switch ((uint32_t)(int8_t)scene)
	{
	case 0:
		attract_end_clear();
		return;
	case 1:
		attract_end_reset();
		return;
	case 2:
		attract_end_restart();
		return;
	}
}

/* the screen cleared */
void attract_end_clear(void)
{
	uint16_t d7 = 0;

	clear_play();
	request_game_step_palettes();
	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	scene++;
}

/* the video set back */
void attract_end_reset(void)
{
	if (jobs_pending == 0u && palettes_busy == 0u)
	{
		layer_priority &= ~4u;
		set_screen_flip();
		reset_layers_scroll();
		scene_timer = 1u;
		scene++;
	}
}

/* the attract mode from its beginning */
void attract_end_restart(void)
{
	uint8_t t1 = 0;

	t1 = scene_timer;
	scene_timer = t1 - 1u;
	if (t1 == 1u)
	{
		game_step = 0u;
		scene = 0u;
		scene_step = 0u;
		scene_substep = 0u;
		scene_subsubstep = 0u;
	}
}

void unreached_005266(void)
{
	uint8_t d6 = 0;
	uint16_t d7 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint16_t t2 = 0;
	uint32_t t1 = 0;

	a6 = table_loaded_by_lea_005294_ADDRESS;
	a5 = SPRITE_RAM;
	d7 = 0x3Fu;
	do
	{
		t1 = a5;
		a5++;
		io_write8(t1, DATA8(a6));
		t2 = d7 - 1u;
		d7 = t2;
		a6++;
	} while (t2 != 0xFFFFu);
	layer_b_scroll_x = 0x60u;
	layer_b_scroll_y = 0u;
	d7 = 1u;
	d6 = 1u;
	fill_layer_b(d6, d7);
}

/* the attract mode's start, straight on to the coin's screen */
void attract_begin(void)
{
	game_step++;
	scene = 0u;
	scene_step = 0u;
	scene_substep = 0u;
}

/* the coin's screen, by its steps: the boxes, the players' turtles, PRESS START */
void attract_coin_screen(uint32_t d1)
{
	switch ((uint32_t)(int8_t)scene)
	{
	case 0:
		coin_screen_setup();
		return;
	case 1:
		coin_screen_show(d1);
		return;
	}
}

/* the coin's screen set up, by its steps */
void coin_screen_setup(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		coin_screen_pause();
		return;
	case 1:
		coin_screen_clear();
		return;
	case 2:
		coin_screen_palettes();
		return;
	case 3:
		coin_screen_check_credits();
		return;
	}
}

/* a two-frame pause */
void coin_screen_pause(void)
{
	scene_timer = 2u;
	scene_step++;
}

/* the play's work and the layers cleared */
void coin_screen_clear(void)
{
	uint16_t d7 = 0;
	uint8_t t1 = 0;

	if (jobs_pending == 0u)
	{
		t1 = scene_timer;
		scene_timer = t1 - 1u;
		if (t1 == 0u)
		{
			clear_play();
			jobs_pending++;
			d7 = 7u;
			queue_job(d7);
			scene_step++;
		}
	}
}

/* the attract mode's palettes and palette effects requested */
void coin_screen_palettes(void)
{
	if (jobs_pending == 0u)
	{
		request_game_step_palettes();
		clear_palette_effects();
		start_game_step_palette_effects();
		scene_step++;
	}
}

/* on to the coin's screen when a player has lives, else to the opening */
void coin_screen_check_credits(void)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0;

	if (jobs_pending != 0u || palettes_busy != 0u)
		return;
	set_screen_flip();
	reset_layers_scroll();
	d0 = PLAYER(PLAYER_ADDRESS(0))->lives | PLAYER(PLAYER_ADDRESS(1))->lives | PLAYER(PLAYER_ADDRESS(2))->lives | PLAYER(PLAYER_ADDRESS(3))->lives;
	d0 = (uint16_t)(d0 | free_play);
	if ((d0 | extra_credits) == 0u)
	{
		game_step++;
		scene = 0u;
		scene_step = 0u;
		return;
	}
	d7 = 0x7Eu;
	queue_sound(d7, 0u);
	scene++;
	scene_step = 0u;
}

/* the coin's screen shown, by its steps */
void coin_screen_show(uint32_t d1)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		coin_screen_boxes();
		return;
	case 1:
		coin_screen_first_wait();
		return;
	case 2:
		coin_screen_second_wait();
		return;
	case 3:
		coin_screen_draw();
		return;
	case 4:
		coin_screen_wait(d1);
		return;
	}
}

/* the four players' boxes drawn */
void coin_screen_boxes(void)
{
	uint16_t d7 = 0;

	d7 = 0xB5Fu;
	queue_job(d7);
	scene_step++;
}

/* a frame's wait */
void coin_screen_first_wait(void)
{
	scene_step++;
}

/* another frame's wait */
void coin_screen_second_wait(void)
{
	scene_step++;
}

/* the Konami texts, the pictures of the players with lives and the coin screen's music */
void coin_screen_draw(void)
{
	uint8_t d7_2 = 0;
	uint16_t d6 = 0;
	uint32_t a5 = 0, d7 = 0, player = 0;
	uint16_t t1 = 0;

	a5 = table_loaded_by_lea_008ABE_ADDRESS;
	queue_jobs(a5);
	d7 = 0u;
	d6 = 3u;
	player = PLAYER_ADDRESS(3);
	do
	{
		if (PLAYER(player)->lives != 0u)
			d7 |= shl32(1u, (int)(d6 & 0x1Fu));
		t1 = d6 - 1u;
		d6 = t1;
		player -= 8u;
	} while (t1 != 0xFFFFu);
	player_turtles(0) = 0u;
	player_turtles(1) = 1u;
	player_turtles(2) = 2u;
	player_turtles(3) = 3u;
	draw_four_turtle_pictures(d7);
	scene_timer = 0xAu;
	continue_count = 0u;
	scene_step++;
	d7_2 = 0x6Fu;
	queue_sound(d7_2, player);
}

/* the coin's screen held until a player starts, redrawn when a coin comes in */
void coin_screen_wait(uint32_t d1)
{
	uint8_t d7 = 0;
	uint16_t d7_2 = 0;
	uint32_t ignored = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;

	update_player_messages(d1, &ignored, &ignored_3, &ignored_4);
	if (new_credit != 0u)
	{
		d7_2 = (uint16_t)(0xB00u | 0x10u | players_credited);
		queue_job(d7_2);
		scene_step--;
		return;
	}
	if (sound_stopped_by_coin != 0u)
	{
		d7 = 0x6Fu;
		queue_sound(d7, 0u);
	}
	if ((frame_count & 0x3Fu) == 0u)
	{
		t1 = scene_timer;
		scene_timer = t1 - 1u;
		if (t1 == 1u)
			return;
	}
}

/* a coin in the attract mode: on to the coin's screen with no demo player left */
void go_to_coin_screen(void)
{
	scene = 0u;
	scene_step = 0u;
	scene_substep = 0u;
	scene_subsubstep = 0u;
	game_step = 1u;
	players_in_play = 0u;
	players_joining = 0u;
	players_knocked_out = 0u;
	players_out_of_lives = 0u;
}

/* the pictures of the turtles of the players chosen */
void draw_four_turtle_pictures(uint32_t d7)
{
	uint16_t d6 = 0;

	d6 = 3u;
	draw_turtle_pictures(d6, d7);
}

/* the turtles' big pictures as sprites, at their players' places, in colour or in black */
void draw_turtle_pictures(uint16_t d6, uint32_t d7)
{
	uint16_t d5 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	a6 = SPRITE_RAM;
	a4 = player_turtles_ADDRESS;
	do
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) != 0u)
		{
			d5 = (uint16_t)((uint32_t)player_turtles((uint32_t)(int16_t)d6) << 4);
			a5 = table_loaded_by_lea_008BEA_ADDRESS;
			if ((d7 & 0x80u) != 0u)
				a5 = 0x8C2Au;
			a5 += d5;
			d5 = 3u;
			do
			{
				mem_write8(a6 + (int16_t)d5, mem_read8(a5 + (int16_t)d5));
				mem_write8(a6 + 8u + (int16_t)d5, mem_read8(a5 + 8u + (int16_t)d5));
				t1 = d5 - 1u;
				d5 = t1;
			} while (t1 != 0xFFFFu);
			d5 = (uint16_t)((uint32_t)(uint8_t)d6 << 4);
			a5 = table_loaded_by_lea_008BEA_ADDRESS;
			if ((d7 & 0x80u) != 0u)
				a5 = 0x8C2Au;
			a5 += d5;
			d5 = 3u;
			do
			{
				mem_write8(a6 + 4u + (int16_t)d5, mem_read8(a5 + 4u + (int16_t)d5));
				mem_write8(a6 + 0xCu + (int16_t)d5, mem_read8(a5 + 0xCu + (int16_t)d5));
				t2 = d5 - 1u;
				d5 = t2;
			} while (t2 != 0xFFFFu);
			if ((d7 & 0x40u) != 0u)
			{
				io_write8(a6 + 3u, 8u);
				io_write8(a6 + 0xBu, 8u);
			}
		}
		t3 = d6 - 1u;
		d6 = t3;
		a6 += 0x10u;
	} while (t3 != 0xFFFFu);
}

/* the layers' scroll back to zero */
void reset_layers_scroll(void)
{
	layer_a_scroll_x = 0u;
	layer_a_scroll_y = 0u;
	layer_b_scroll_x = 0u;
	layer_b_scroll_y = 0u;
	unused_layer_a_scroll_x_copy = 0u;
	unused_layer_a_scroll_y_copy = 0u;
	unused_layer_b_scroll_x_copy = 0u;
	unused_layer_b_scroll_y_copy = 0u;
	unk_060054 = 0u;
	unk_060055 = 0u;
	unk_060056 = 0u;
	unk_060057 = 0u;
	io_write8(TILES_106400, 0u);
	io_write8(TILES_106402, 0u);
	io_write8(TILES_106018, 0u);
	io_write8(TILES_106401, 0u);
	io_write8(TILES_106403, 0u);
	io_write8(TILES_106019, 0u);
}

/* the opening, by its steps, until a coin */
void attract_opening(uint16_t d6, uint32_t a5)
{
	uint8_t d7 = 0;

	if (new_credit != 0u)
	{
		d7 = 0x7Eu;
		queue_sound(d7, 0u);
		go_to_coin_screen();
		return;
	}
	switch ((uint32_t)(int8_t)scene)
	{
	case 0:
		opening_setup();
		return;
	case 1:
		opening_show(d6, a5);
		return;
	}
}

/* the opening set up, by its steps */
void opening_setup(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		opening_setup_clear();
		return;
	case 1:
		opening_setup_palettes();
		return;
	case 2:
		opening_setup_priority();
		return;
	case 3:
		opening_setup_start();
		return;
	}
}

/* the play's work and the layers cleared */
void opening_setup_clear(void)
{
	uint16_t d7 = 0;

	if (jobs_pending == 0u)
	{
		clear_play();
		jobs_pending++;
		d7 = 7u;
		queue_job(d7);
		scene_step++;
	}
}

/* the attract mode's palettes and palette effects requested */
void opening_setup_palettes(void)
{
	if (jobs_pending == 0u)
	{
		request_game_step_palettes();
		clear_palette_effects();
		start_game_step_palette_effects();
		scene_step++;
	}
}

/* the layers' priority set */
void opening_setup_priority(void)
{
	if (jobs_pending == 0u && palettes_busy == 0u)
	{
		layer_priority = 0u;
		io_write8(PRIORITY_0C0001, layer_priority);
		scene_step++;
	}
}

/* the opening started */
void opening_setup_start(void)
{
	if (jobs_pending == 0u)
	{
		scene++;
		scene_step = 0u;
		attract_timer = 0xB2u;
		hide_all_sprites();
		start_opening();
		io_write8(TILES_106B00, 0u);
		tile_banks_0_1 = 0u;
		io_write8(TILES_106E00, 0u);
		tile_banks_2_3 = 0u;
	}
}

/* the opening played for its time, then the title */
void opening_show(uint16_t d6, uint32_t a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;
	uint8_t t1 = 0;

	if ((frame_count & 3u) == 0u)
	{
		t1 = attract_timer;
		attract_timer = t1 - 1u;
		if (t1 == 1u)
		{
			game_step++;
			scene = 0u;
			scene_step = 0u;
			return;
		}
	}
	run_opening(d6, a5);
	build_draw_list(&ignored, &ignored_2);
	draw_sprites(&ignored_3, &ignored_2);
}

/* BEST 10 PLAYERS, by its steps, until a coin */
void attract_best_players(void)
{
	if (new_credit != 0u)
	{
		go_to_coin_screen();
		return;
	}
	switch ((uint32_t)(int8_t)scene)
	{
	case 0:
		best_players_setup();
		return;
	case 1:
		best_players_show();
		return;
	}
}

/* BEST 10 PLAYERS set up, by its steps */
void best_players_setup(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		best_players_clear();
		return;
	case 1:
		best_players_palettes();
		return;
	case 2:
		best_players_draw();
		return;
	}
}

/* the play's work and the layers cleared */
void best_players_clear(void)
{
	uint16_t d7 = 0;

	if (jobs_pending == 0u)
	{
		clear_play();
		jobs_pending++;
		d7 = 7u;
		queue_job(d7);
		scene_step++;
	}
}

/* the attract mode's palettes and palette effects requested */
void best_players_palettes(void)
{
	if (jobs_pending == 0u)
	{
		request_game_step_palettes();
		clear_palette_effects();
		start_game_step_palette_effects();
		scene_step++;
	}
}

/* the background, the turtles' pictures and the table of the best ten drawn */
void best_players_draw(void)
{
	uint16_t d6 = 0, d7 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	if (jobs_pending == 0u && palettes_busy == 0u)
	{
		a6 = palettes_008F58_ADDRESS;
		d7 = 0x500u;
		post_palette_request(d7, a6);
		tile_banks_0_1 = 0u;
		io_write8(TILES_106B00, 0u);
		tile_banks_2_3 = 0u;
		io_write8(TILES_106E00, 0u);
		layer_b_scroll_x = 0x60u;
		layer_b_scroll_y = 0u;
		d7_2 = draw_ranking_background();
		d6 = 4u;
		d7_2 = (d7_2 & ~0xFFu) | 0x8Fu;
		player_turtles(0) = 0u;
		player_turtles(1) = 1u;
		player_turtles(2) = 2u;
		player_turtles(3) = 3u;
		draw_turtle_pictures(d6, d7_2);
		draw_best_players();
		scene++;
		scene_step = 0u;
	}
}

/* BEST 10 PLAYERS shown, by its steps */
void best_players_show(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		best_players_pause();
		return;
	case 1:
		best_players_scroll();
		return;
	}
}

/* a pause before the turtles move */
void best_players_pause(void)
{
	if (jobs_pending == 0u)
	{
		scene_step++;
		step_timer = 0xFFu;
	}
}

/* the turtles' pictures slide across behind the table, then the next attract step */
void best_players_scroll(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	t1 = step_timer;
	step_timer = t1 - 1u;
	if (t1 == 1u)
	{
		game_step++;
		scene = 0u;
		scene_step = 0u;
		return;
	}
	a6 = SPRITE_RAM;
	d7 = 7u;
	for (;;)
	{
		if ((io_read8(a6) & 0x80u) == 0u)
		{
			a6 += 8u;
			continue;
		}
		t2 = io_read8(a6 + 6u);
		turtles_in_black = t2;
		(void)t2;
		t3 = io_read8(a6 + 7u);
		ranking_time = (ranking_time & 0xFF00u) | (t3 & 0xFFu);
		(void)t3;
		ranking_time &= 0x1FFu;
		ranking_time += 4u;
		ranking_time &= 0x1FFu;
		io_write8(a6 + 6u, turtles_in_black);
		io_write8(a6 + 7u, (uint8_t)ranking_time);
		t4 = d7 - 1u;
		d7 = t4;
		a6 += 8u;
		if (t4 != 0xFFFFu)
			continue;
		break;
	}
}

/* the title, the places, the initials and the scores of the best ten */
void draw_best_players(void)
{
	uint32_t a5 = 0;

	a5 = 0x9190u;
	queue_jobs(a5);
	draw_best_players_initials();
	draw_best_players_scores();
}

/* the ten players' initials, the first three in their colours */
void draw_best_players_initials(void)
{
	uint8_t d6 = 0;
	uint16_t d6_2 = 0, d7 = 0;
	uint32_t a3 = 0, a4 = 0, a5 = 0, a6 = 0;

	a6 = unexplained_00917E;
	a5 = ranking_initials_ADDRESS;
	a4 = 0x9186u;
	a3 = indexed_table_of_8_bit_values_002884_ADDRESS;
	d7 = 0u;
	do
	{
		d6 = DATA8(a4 + d7);
		mem_write8(a6, d6);
		mem_write8(a6 + 4u, d6);
		mem_write8(a6 + 8u, d6);
		mem_write8(a6 + 0x80u, d6);
		mem_write8(a6 + 0x84u, d6);
		mem_write8(a6 + 0x88u, d6);
		d6_2 = mem_read8(a5);
		draw_best_players_character(d6_2, a3, a6);
		d6_2 = mem_read8(a5 + 1u);
		a6 += 4u;
		draw_best_players_character(d6_2, a3, a6);
		d6_2 = mem_read8(a5 + 2u);
		a6 += 4u;
		draw_best_players_character(d6_2, a3, a6);
		d7 = (uint8_t)(d7 + 1u);
		a6 += 0xF8u;
		a5 += 4u;
	} while (d7 < 0xAu);
}

/* a tall character's tiles */
void draw_best_players_character(uint16_t d6, uint32_t a3, uint32_t a6)
{
	d6 = (uint16_t)((uint32_t)(uint8_t)(d6 - 0x30u) << 1);
	mem_write8(a6 + 1u, mem_read8(a3 + d6));
	mem_write8(a6 + 0x81u, mem_read8(a3 + 1u + d6));
}

/* the ten scores with PTS */
void draw_best_players_scores(void)
{
	uint8_t d6 = 0;
	uint16_t d0 = 0, d5 = 0, d7 = 0;
	uint32_t a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0;

	a5 = ranking_scores_ADDRESS;
	a4 = 0x9186u;
	a3 = indexed_table_of_8_bit_values_002884_ADDRESS;
	d7 = 0u;
	do
	{
		a6 = rom_009182 + d7 * 0x100u;
		a2 = a6;
		d0 = mem_read16(a5);
		while (d0 != 0u)
		{
			d6 = DATA8(a4 + d7);
			mem_write8(a6, d6);
			mem_write8(a6 + 0x80u, d6);
			d5 = (uint8_t)d0;
			d5 = (uint16_t)((d5 & 0xFu) << 1);
			mem_write8(a6 + 1u, DATA8(a3 + d5));
			mem_write8(a6 + 0x81u, DATA8(a3 + 1u + d5));
			d0 = d0 >> 4;
			a6 -= 4u;
		}
		d6 = DATA8(a4 + d7);
		mem_write8(a2 + 4u, d6);
		mem_write8(a2 + 6u, d6);
		mem_write8(a2 + 8u, d6);
		mem_write8(a2 + 0x84u, d6);
		mem_write8(a2 + 0x86u, d6);
		mem_write8(a2 + 0x88u, d6);
		mem_write8(a2 + 5u, mem_read8(a3 + 0x40u));
		mem_write8(a2 + 0x85u, DATA8(a3 + 0x41u));
		mem_write8(a2 + 7u, mem_read8(a3 + 0x48u));
		mem_write8(a2 + 0x87u, DATA8(a3 + 0x49u));
		mem_write8(a2 + 9u, mem_read8(a3 + 0x46u));
		mem_write8(a2 + 0x89u, DATA8(a3 + 0x47u));
		d7 = (uint8_t)(d7 + 1u);
		a5 += 2u;
	} while (d7 < 0xAu);
}

/* an empty attract step */
void attract_spare_step(void)
{
	game_step++;
}
