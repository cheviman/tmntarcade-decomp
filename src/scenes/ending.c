/**
 *    Name:        scenes/ending.c
 *    Description: the ending after the last boss: the Technodrome explodes, the epilogue, the staff roll, GAME OVER
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the ending after the last boss, by its steps */
void scene_ending(uint16_t d6, uint32_t a5)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		ending_setup();
		return;
	case 1:
		ending_epilogue(d6, a5);
		return;
	}
}

/* the ending's first step, by its steps */
void ending_setup(void)
{
	switch ((uint32_t)(int8_t)scene_substep)
	{
	case 0:
		ending_clear();
		return;
	case 1:
		ending_show_technodrome();
		return;
	case 2:
		ending_open_box();
		return;
	}
}

/* the players taken out, the screen and the objects cleared, the ending's palettes requested */
void ending_clear(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	hide_press_start = 0u;
	drop_players_in_play();
	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	a6 = 0xA03Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	clear_palette_effects();
	clear_objects();
	clear_sprite_ram();
	scene_substep++;
}

/* the Technodrome's picture in a box that starts to open */
void ending_show_technodrome(void)
{
	if (jobs_pending == 0u && palettes_busy == 0u)
	{
		start_box_opening();
		draw_technodrome_screen();
		hide_all_sprites();
		scene_substep++;
		layer_b_scroll_x = 0x20u;
	}
}

/* the box opened, then a pause */
void ending_open_box(void)
{
	grow_tile_box();
	if (box_frames_left == 0u)
	{
		game_scene_timer = 0x28u;
		scene_step++;
		scene_substep = 0u;
	}
}

/* the explosion, the epilogue, the staff roll and GAME OVER, by their steps */
void ending_epilogue(uint16_t d6, uint32_t a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	switch ((uint32_t)(int8_t)scene_substep)
	{
	case 0:
		ending_pause();
		break;
	case 1:
		ending_technodrome_glows(d6, a5);
		break;
	case 2:
		ending_technodrome_explodes(d6, a5);
		break;
	case 3:
		ending_show_wreck();
		break;
	case 4:
		ending_fade_to_wreck(d6, a5);
		break;
	case 5:
		ending_start_epilogue();
		break;
	case 6:
		ending_type_epilogue();
		break;
	case 7:
		ending_dim_epilogue(d6, a5);
		break;
	case 8:
		ending_staff_roll();
		break;
	case 9:
		ending_game_over();
		break;
	}
	build_draw_list(&ignored, &ignored_2);
	draw_sprites(&ignored_3, &ignored_2);
}

/* a pause, then a sound */
void ending_pause(void)
{
	uint8_t d7 = 0;
	uint8_t t1 = 0;

	t1 = game_scene_timer;
	game_scene_timer = t1 - 1u;
	if (t1 == 0u)
	{
		d7 = 0x22u;
		queue_sound(d7, 0u);
		fade_state = 0u;
		game_scene_timer = 0x78u;
		scene_substep++;
	}
}

/* the Technodrome turns red */
void ending_technodrome_glows(uint16_t d6, uint32_t a5)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = game_scene_timer;
	game_scene_timer = t1 - 1u;
	if (t1 == 0u)
	{
		fade_state = 0u;
		game_scene_timer = 0x96u;
		scene_substep++;
		return;
	}
	a6 = record_0071DC_ADDRESS;
	if (fading == 0u)
	{
		d6 = DATA16(a6);
		a5 = mem_read32(a6 + 2u);
		fade_state = 0u;
	}
	copy_palette_sets(d6, a5);
}

/* explosions over the Technodrome, the screen shaking, the colours going to white */
void ending_technodrome_explodes(uint16_t d6, uint32_t a5)
{
	uint8_t d7 = 0;
	uint16_t d7_2 = 0;
	uint32_t a6 = 0, d7_3 = 0;
	uint8_t t1 = 0;

	remove_spent_explosions();
	t1 = game_scene_timer;
	game_scene_timer = t1 - 1u;
	if (t1 == 0u)
	{
		fade_state = 0u;
		scene_substep++;
		return;
	}
	if (game_scene_timer >= 0x32u)
	{
		if (game_scene_timer == 0x32u)
		{
			d7 = 0x1Au;
			queue_sound(d7, 0u);
			a6 = OBJECT_ADDRESS(12);
			d7_3 = 0xCu;
			find_free_object(&d7_3, &a6);
			if ((uint8_t)d7_3 != 0u)
				a5 = start_technodrome_explosion(a6);
			a6 = 0x71E2u;
			if (game_scene_timer < 0x78u)
				a6 = 0x71E8u;
			if (fading == 0u)
			{
				d6 = DATA16(a6);
				a5 = mem_read32(a6 + 2u);
				fade_state = 0u;
			}
			copy_palette_sets(d6, a5);
			return;
		}
		shake_technodrome();
		if ((game_scene_timer & 7u) == 0u)
		{
			d7_2 = (uint8_t)frame_count;
			d7_2 = d7_2 & 0x18u;
			d7 = indexed_table_of_8_bit_values_006DFC[d7_2 >> 3];
			queue_sound(d7, 0u);
			a6 = OBJECT_ADDRESS(12);
			d7_3 = 0xCu;
			find_free_object(&d7_3, &a6);
			if ((uint8_t)d7_3 != 0u)
				a5 = start_technodrome_explosion(a6);
		}
	}
	a6 = 0x71E2u;
	if (game_scene_timer < 0x78u)
		a6 = 0x71E8u;
	if (fading == 0u)
	{
		d6 = DATA16(a6);
		a5 = mem_read32(a6 + 2u);
		fade_state = 0u;
	}
	copy_palette_sets(d6, a5);
}

/* the Technodrome's wreck drawn */
void ending_show_wreck(void)
{
	clear_technodrome_top();
	draw_technodrome_wreck();
	fade_state = 0u;
	game_scene_timer = 0xB4u;
	scene_substep++;
}

/* the colours back from white to the wreck, then the epilogue's music */
void ending_fade_to_wreck(uint16_t d6, uint32_t a5)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	remove_spent_explosions();
	t1 = game_scene_timer;
	game_scene_timer = t1 - 1u;
	if (t1 != 0u)
	{
		a6 = 0x71EEu;
		if (fading == 0u)
		{
			d6 = DATA16(a6);
			a5 = mem_read32(a6 + 2u);
			fade_state = 0u;
		}
		copy_palette_sets(d6, a5);
		return;
	}
	fade_state = 0u;
	game_scene_timer = 0x1Eu;
	d7 = 0x6Cu;
	queue_sound(d7, 0u);
	scene_substep++;
}

/* the epilogue's text started */
void ending_start_epilogue(void)
{
	uint32_t carry = 0, extend = 0;
	uint8_t d7 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = game_scene_timer;
	carry = t1 == 0u;
	extend = carry;
	game_scene_timer = t1 - 1u;
	if (t1 == 1u)
	{
		a6 = 0x199A4u;
		d7 = 2u;
		start_text_typed_in_colours(d7, a6, extend);
		scene_substep++;
	}
}

/* the epilogue typed until it is done */
void ending_type_epilogue(void)
{
	type_text_in_colours();
	if (typed_passes_left == 0u)
	{
		fade_state = 0u;
		game_scene_timer = 0xB4u;
		scene_substep++;
	}
}

/* the picture darkened before the staff roll */
void ending_dim_epilogue(uint16_t d6, uint32_t a5)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = game_scene_timer;
	game_scene_timer = t1 - 1u;
	if (t1 == 0u)
	{
		fade_state = 0u;
		game_scene_timer = 0xB4u;
		scene_substep++;
		scene_subsubstep = 0u;
		return;
	}
	a6 = 0x71F4u;
	if (fading == 0u)
	{
		d6 = DATA16(a6);
		a5 = mem_read32(a6 + 2u);
		fade_state = 0u;
	}
	copy_palette_sets(d6, a5);
}

/* the staff roll, by its steps */
void ending_staff_roll(void)
{
	switch ((uint32_t)(int8_t)scene_subsubstep)
	{
	case 0:
		staff_roll_clear();
		return;
	case 1:
		staff_roll_start();
		return;
	case 2:
		staff_roll_next_credit();
		return;
	case 3:
		staff_roll_type_name();
		return;
	case 4:
		staff_roll_hold_name();
		return;
	case 5:
		staff_roll_erase_name();
		return;
	case 6:
		staff_roll_end();
		return;
	}
}

/* the screen cleared and the staff roll's palettes requested */
void staff_roll_clear(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	a6 = 0xA0DEu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	scene_subsubstep++;
}

/* the city, the turtles' portraits and the music for the staff roll */
void staff_roll_start(void)
{
	uint8_t d7 = 0;

	if (jobs_pending == 0u && palettes_busy == 0u)
	{
		io_write8(TILES_106B00, 0xF0u);
		tile_banks_0_1 = 0xF0u;
		io_write8(TILES_106E00, 7u);
		tile_banks_2_3 = 7u;
		layer_b_scroll_x = 0x48u;
		draw_staff_roll_city();
		start_staff_roll_portraits();
		scene_subsubstep++;
		staff_roll_credit = 0u;
		game_scene_timer = 0xB4u;
		d7 = 0x70u;
		queue_sound(d7, 0u);
	}
}

/* the next credit's title and name, or PRODUCED BY and the Konami logo after the last */
void staff_roll_next_credit(void)
{
	uint8_t d7_3 = 0;
	uint16_t d7_2 = 0;
	uint32_t a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0;

	slide_staff_roll_portraits();
	if (staff_roll_credit >= 0xEu)
	{
		a5 = TILE_RAM + 0x324u;
		a6 = table_loaded_by_lea_002F26_ADDRESS;
		d7_2 = 0xFu;
		do
		{
			io_write8(a5, 0u);
			a5++;
			io_write8(a5, DATA8(a6) - 0x30u);
			t1 = d7_2 - 1u;
			d7_2 = t1;
			a5++;
			a6++;
		} while (t1 != 0xFFFFu);
		a5 = table_loaded_by_lea_007018_ADDRESS;
		queue_jobs(a5);
		game_scene_timer = 0xB4u;
		scene_subsubstep = 6u;
		d7_3 = 0xFEu;
		queue_sound(d7_3, a6);
		return;
	}
	a5 = TILE_RAM + 0x324u;
	d7 = staff_roll_credit;
	a6 = 0x7612u + (uint16_t)(d7 << 4);
	d7_2 = 0xFu;
	do
	{
		io_write8(a5, 0u);
		a5++;
		io_write8(a5, DATA8(a6) - 0x30u);
		t2 = d7_2 - 1u;
		d7_2 = t2;
		a5++;
		a6++;
	} while (t2 != 0xFFFFu);
	start_credit_name();
	scene_subsubstep++;
}

/* the credit's name typed in colours */
void staff_roll_type_name(void)
{
	slide_staff_roll_portraits();
	staff_roll_skip();
	type_credit_name();
	if (typed_passes_left == 0u)
	{
		game_scene_timer = 0x14u;
		scene_subsubstep++;
	}
}

/* the name held a moment, then its erasing started */
void staff_roll_hold_name(void)
{
	uint8_t t1 = 0;

	slide_staff_roll_portraits();
	staff_roll_skip();
	t1 = game_scene_timer;
	game_scene_timer = t1 - 1u;
	if (t1 == 0u)
	{
		scene_subsubstep++;
		start_credit_name_erase();
	}
}

/* the name erased, then the next credit */
void staff_roll_erase_name(void)
{
	slide_staff_roll_portraits();
	staff_roll_skip();
	erase_credit_name();
	if (typed_passes_left == 0u)
	{
		staff_roll_credit++;
		scene_subsubstep -= 3u;
	}
}

/* the last pause of the staff roll */
void staff_roll_end(void)
{
	uint8_t t1 = 0;

	slide_staff_roll_portraits();
	staff_roll_skip();
	t1 = game_scene_timer;
	game_scene_timer = t1 - 1u;
	if (t1 == 0u)
	{
		scene_substep++;
		scene_subsubstep = 0u;
		return;
	}
}

/* the GAME OVER after the ending, by its steps */
void ending_game_over(void)
{
	switch ((uint32_t)(int8_t)scene_subsubstep)
	{
	case 0:
		ending_game_over_clear();
		return;
	case 1:
		ending_game_over_start();
		return;
	case 2:
		ending_game_over_wait();
		return;
	}
}

/* the screen and the objects cleared for GAME OVER */
void ending_game_over_clear(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	jobs_pending++;
	d7 = 7u;
	queue_job(d7);
	a6 = 0xA01Eu;
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
	clear_objects();
	clear_sprite_ram();
	scene_subsubstep++;
}

/* the GAME OVER box with its colours and music */
void ending_game_over_start(void)
{
	uint8_t d7_2 = 0;
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (jobs_pending != 0u || palettes_busy != 0u)
		return;
	d7 = 1u;
	print_colour_text(d7);
	a6 = 0xD2C4u;
	start_palette_effects(a6);
	a6 = 0xD2E6u;
	start_palette_effects(a6);
	game_scene_timer = 0xFAu;
	scene_subsubstep++;
	d7_2 = 0x6Du;
	queue_sound(d7_2, a6);
}

/* GAME OVER held until the time runs out or a button, then the ranking */
void ending_game_over_wait(void)
{
	uint8_t t1 = 0;

	ending_game_over_skip();
	t1 = game_scene_timer;
	game_scene_timer = t1 - 1u;
	if (t1 == 1u)
	{
		scene = 8u;
		scene_step = 0u;
		scene_substep = 0u;
		scene_subsubstep = 0u;
		return;
	}
}

/* the players in play leave the game when it ends */
void drop_players_in_play(void)
{
	uint16_t d7 = 0;
	uint32_t player = 0;
	uint16_t t1 = 0;

	d7 = 3u;
	player = PLAYER_ADDRESS(3);
	do
	{
		if ((players_in_play & shl32(1u, (int)(d7 & 7u))) != 0u && (players_joining & shl32(1u, (int)(d7 & 7u))) == 0u)
		{
			players_joining &= ~shl32(1u, (int)(d7 & 7u));
			players_in_play &= ~shl32(1u, (int)(d7 & 7u));
			PLAYER(player)->lives = 0u;
			PLAYER(player)->health_bars = 0u;
			PLAYER(player)->message = 0u;
		}
		t1 = d7 - 1u;
		d7 = t1;
		player -= 8u;
	} while (t1 != 0xFFFFu);
	players_knocked_out = 0u;
	players_out_of_lives = 0u;
}

/* the screen shaken while the Technodrome explodes */
void shake_technodrome(void)
{
	layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | (0u - ((((uint8_t)frame_count & 2u) << 1) + LAYER(LAYER_B)->y_pixel) & 0xFFu);
}

/* the top of the Technodrome taken off the picture */
void clear_technodrome_top(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	d7 = 0x1FFu;
	a6 = TILE_RAM + 0x2200u;
	do
	{
		io_write8(a6, 0u);
		a6++;
		io_write8(a6, 0x10u);
		t1 = d7 - 1u;
		d7 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
}

/* the Technodrome's wreck drawn in tiles */
void draw_technodrome_wreck(void)
{
	uint8_t d0 = 0, d1 = 0;
	uint16_t d5 = 0, d6 = 0, d7 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	d7 = 1u;
	a6 = record_007276_ADDRESS;
	do
	{
		a5 = DATA32(a6);
		d0 = DATA8(a6 + 4u);
		d6 = DATA8(a6 + 6u);
		d1 = 0u;
		do
		{
			a4 = a5;
			d5 = DATA8(a6 + 5u);
			d1 &= ~0xFu;
			do
			{
				mem_write8(a4, d0);
				a4++;
				mem_write8(a4, d1);
				d1++;
				t1 = d5 - 1u;
				d5 = t1;
				a4++;
			} while (t1 != 0xFFFFu);
			d1 = (uint8_t)(d1 - 1u + 0x10u);
			t2 = d6 - 1u;
			d6 = t2;
			a5 += 0x80u;
		} while (t2 != 0xFFFFu);
		t3 = d7 - 1u;
		d7 = t3;
		a6 += 8u;
	} while (t3 != 0xFFFFu);
}

/* an explosion started at one of the Technodrome's places */
uint32_t start_technodrome_explosion(uint32_t a6)
{
	uint16_t d7 = 0;
	uint32_t a0 = 0, a5 = 0, animation = 0;

	a5 = indexed_table_of_16_bit_values_0072E2_ADDRESS;
	d7 = technodrome_explosions;
	d7 = (uint16_t)((d7 & 7u) << 2);
	OBJECT(a6)->screen_x = indexed_table_of_16_bit_values_0072E2[d7 / 2u];
	OBJECT(a6)->screen_x += 0x100u;
	OBJECT(a6)->screen_y = rom_0072E4[d7 / 2u];
	OBJECT(a6)->screen_y += 0x60u;
	OBJECT(a6)->flags = 0x81u;
	OBJECT(a6)->contacts = 0u;
	OBJECT(a6)->kind = 0u;
	OBJECT(a6)->parameter = 0u;
	OBJECT(a6)->colour = 0xFFu;
	OBJECT(a6)->animation_delay = 0u;
	OBJECT(a6)->unk_2F = 0u;
	OBJECT(a6)->routine = 0u;
	OBJECT(a6)->state = 0u;
	a0 = a6;
	animation = rom_014C86;
	set_animation(0u, a0, animation);
	technodrome_explosions++;
	return a5;
}

/* the explosions whose animation is over removed */
void remove_spent_explosions(void)
{
	uint16_t d7 = 0;
	uint32_t object = 0;
	uint16_t t1 = 0;

	object = OBJECT_ADDRESS(12);
	d7 = 0xBu;
	do
	{
		if (OBJECT(object)->flags != 0u && OBJECT(object)->frame_time == 0u)
			remove_object(object);
		t1 = d7 - 1u;
		d7 = t1;
		object += 0x50u;
	} while (t1 != 0xFFFFu);
}

/* the four turtles' portraits put in for the staff roll */
void start_staff_roll_portraits(void)
{
	uint16_t d6 = 0;
	uint32_t a0 = 0, animation = 0, d7 = 0, ignored = 0, object = 0;
	uint16_t t1 = 0;

	d7 = 3u;
	object = OBJECT_ADDRESS(12);
	do
	{
		OBJECT(object)->flags = 0x81u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->kind = 0u;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		OBJECT(object)->unk_2F = 0u;
		OBJECT(object)->routine = 0u;
		OBJECT(object)->state = 0u;
		d6 = (uint16_t)(d7 << 2);
		OBJECT(object)->screen_x = TABLE16(indexed_table_of_16_bit_values_00738C, (uint32_t)(int16_t)d6);
		OBJECT(object)->screen_y = mem_read16(0x738Eu + (int16_t)d6);
		a0 = object;
		animation = rom_015764[d7 & 0x3FFFu];
		set_animation(ignored, a0, animation);
		t1 = d7 - 1u;
		d7 = t1;
		object = a0 + 0x50u;
	} while (t1 != 0xFFFFu);
}

/* the portraits slide to the left round the screen */
void slide_staff_roll_portraits(void)
{
	uint16_t d6 = 0, d7 = 0;
	uint32_t object = 0;
	uint16_t screen_x = 0, t1 = 0;

	d7 = 3u;
	object = OBJECT_ADDRESS(12);
	do
	{
		d6 = frame_count & 1u;
		screen_x = OBJECT(object)->screen_x;
		OBJECT(object)->screen_x = screen_x - d6;
		if (screen_x < d6)
			OBJECT(object)->screen_x = 0x300u;
		t1 = d7 - 1u;
		d7 = t1;
		object += 0x50u;
	} while (t1 != 0xFFFFu);
}

/* a button ends the staff roll after its first credit */
void staff_roll_skip(void)
{
	uint8_t d7 = 0;

	if (staff_roll_credit == 0u || ((player_presses(0) | player_presses(1) | player_presses(2) | player_presses(3)) & 0x30u) == 0u)
		return;
	d7 = 0xFEu;
	queue_sound(d7, 0u);
	scene_substep++;
	scene_subsubstep = 0u;
}

/* the city drawn behind the staff roll */
void draw_staff_roll_city(void)
{
	uint32_t carry = 0;
	uint8_t d0 = 0, d1 = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a0 = 0;
	uint16_t t1 = 0, t2 = 0;

	a0 = TILE_RAM + 0x4018u;
	d0 = 0x14u;
	d1 = 0u;
	d7 = 0x1Fu;
	do
	{
		d6 = 0x1Fu;
		do
		{
			io_write8(a0, d0);
			a0++;
			io_write8(a0, d1);
			carry = (uint8_t)(d1 + 1u) < d1;
			d1++;
			a0++;
			if (carry)
				d0++;
			t1 = d6 - 1u;
			d6 = t1;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
		a0 += 0x40u;
	} while (t2 != 0xFFFFu);
}

/* the credit's name started in seven colour passes */
void start_credit_name(void)
{
	uint16_t d7 = 0;
	uint32_t typed_pass = 0;
	uint16_t t1 = 0;

	typed_pass = TYPED_PASS_ADDRESS(7);
	d7 = 6u;
	do
	{
		set_credit_name_pass(typed_pass);
		TYPED_PASS(typed_pass)->wait = (uint32_t)d7 << 3;
		t1 = d7 - 1u;
		d7 = t1;
		typed_pass -= 0xAu;
	} while (t1 != 0xFFFFu);
	typed_passes_left = 7u;
}

/* the credit's name recoloured and then blanked in eight passes */
void start_credit_name_erase(void)
{
	uint16_t d7 = 0;
	uint32_t typed_pass = 0;
	uint16_t t1 = 0;

	typed_pass = TYPED_PASS_ADDRESS(7);
	d7 = 7u;
	do
	{
		set_credit_name_pass(typed_pass);
		TYPED_PASS(typed_pass)->wait = (8u - d7) << 3;
		t1 = d7 - 1u;
		d7 = t1;
		typed_pass -= 0xAu;
	} while (t1 != 0xFFFFu);
	typed_passes_left = 8u;
	TYPED_PASS(TYPED_PASS_ADDRESS(0))->text = 0x77D2u;
}

/* a pass of the credit's name set at its place, speed and text */
void set_credit_name_pass(uint32_t a4)
{
	uint32_t d6 = 0;

	TYPED_PASS(a4)->place = TILE_RAM + 0x42Au;
	TYPED_PASS(a4)->delay = 4u;
	d6 = staff_roll_credit;
	TYPED_PASS(a4)->text = 0x76F2u + (uint16_t)(d6 << 4);
}

/* the seven passes of the name typed on */
void type_credit_name(void)
{
	uint16_t d7 = 0;
	uint32_t a4 = 0;
	uint16_t t1 = 0;

	a4 = TYPED_PASS_ADDRESS(7);
	d7 = 6u;
	do
	{
		type_credit_name_pass(d7, a4);
		t1 = d7 - 1u;
		d7 = t1;
		a4 -= 0xAu;
	} while (t1 != 0xFFFFu);
}

/* the eight passes that take the name off typed on */
void erase_credit_name(void)
{
	uint16_t d0 = 0, d7 = 0;
	uint32_t a3 = 0, a4 = 0;
	uint16_t t1 = 0;

	a4 = TYPED_PASS_ADDRESS(7);
	d0 = 7u;
	do
	{
		a3 = a4;
		d7 = (uint16_t)d0;
		if (d0 != 0u)
			d7 = (uint16_t)((d7 & ~0xFFu) | (uint8_t)(d7 - 1u));
		type_credit_name_pass(d7, a4);
		t1 = d0 - 1u;
		d0 = t1;
		a4 = a3 - 0xAu;
	} while (t1 != 0xFFFFu);
}

/* the next big character of a pass in its colour */
void type_credit_name_pass(uint16_t d7, uint32_t a4)
{
	uint8_t d5 = 0;
	uint16_t d6 = 0;
	uint32_t place = 0;
	uint8_t wait = 0;

	if (TYPED_PASS(a4)->text == 0u)
		return;
	wait = TYPED_PASS(a4)->wait;
	TYPED_PASS(a4)->wait = wait - 1u;
	if (wait != 0u)
		return;
	place = TYPED_PASS(a4)->place;
	d6 = DATA8(TYPED_PASS(a4)->text);
	if (d6 == 0x21u)
	{
		TYPED_PASS(a4)->place = 0u;
		TYPED_PASS(a4)->text = 0u;
		TYPED_PASS(a4)->wait = 0u;
		TYPED_PASS(a4)->delay = 0u;
		typed_passes_left--;
		return;
	}
	d5 = TABLE8(rom_001F1B, (uint32_t)(int16_t)d7);
	if (d6 != 0x40u)
		d5 += 0x18u;
	io_write8(place, d5);
	io_write8(place + 2u, d5);
	io_write8(place + 0x80u, d5);
	io_write8(place + 0x82u, d5);
	d6 = (uint16_t)((uint32_t)(uint8_t)(d6 - 0x40u) << 2);
	io_write8(place + 1u, indexed_table_of_8_bit_values_007592[d6]);
	io_write8(place + 3u, rom_007593[d6]);
	io_write8(place + 0x81u, rom_007594[d6]);
	io_write8(place + 0x83u, rom_007595[d6]);
	TYPED_PASS(a4)->text++;
	TYPED_PASS(a4)->place += 4u;
	TYPED_PASS(a4)->wait = TYPED_PASS(a4)->delay;
}

/* a button ends GAME OVER early */
void ending_game_over_skip(void)
{
	uint8_t d7 = 0;

	if (game_scene_timer >= 0xF0u || ((player_presses(0) | player_presses(1) | player_presses(2) | player_presses(3)) & 0x30u) == 0u)
		return;
	d7 = 0u;
	queue_sound(d7, 0u);
	scene = 8u;
	scene_step = 0u;
	scene_substep = 0u;
	scene_subsubstep = 0u;
}
