/**
 *    Name:        scenes/ranking.c
 *    Description: the ranking after a game: the players' places, their columns, the name entry, and the ranking's defaults
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the ranking after a game, by its steps */
void scene_ranking(void)
{
	switch ((uint32_t)(int8_t)scene_step)
	{
	case 0:
		ranking_setup();
		return;
	case 1:
		rank_players_scores();
		return;
	case 2:
		show_ranked_players();
		return;
	case 3:
		ranking_choose_entry();
		return;
	case 4:
		ranking_wait();
		return;
	case 5:
		enter_initials();
		return;
	case 6:
		ranking_entry_done();
		return;
	case 7:
		ranking_end_wait();
		return;
	}
}

/* the ranking's first step, by its steps */
void ranking_setup(void)
{
	switch ((uint32_t)(int8_t)scene_substep)
	{
	case 0:
		ranking_clear_layers();
		return;
	case 1:
		ranking_clear();
		return;
	case 2:
		ranking_reset();
		return;
	}
}

/* the layers cleared for the ranking */
void ranking_clear_layers(void)
{
	uint16_t d7 = 0;

	if (jobs_pending == 0u)
	{
		jobs_pending = 1u;
		d7 = 7u;
		queue_job(d7);
		scene_substep++;
	}
}

/* the objects cleared and the ranking's palettes requested */
void ranking_clear(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	if (jobs_pending == 0u)
	{
		clear_objects();
		clear_sprite_ram();
		a6 = 0xA02Eu;
		d7 = 0x20Fu;
		post_palette_request(d7, a6);
		clear_palette_effects();
		scene_substep++;
	}
}

/* the places, the tile banks and the scroll reset for the ranking */
void ranking_reset(void)
{
	if (jobs_pending != 0u || palettes_busy != 0u)
		return;
	ranking_places(0) = 0u;
	ranking_places(1) = 0u;
	ranking_places(2) = 0u;
	ranking_places(3) = 0u;
	tile_banks_0_1 = 0u;
	io_write8(TILES_106B00, 0u);
	tile_banks_2_3 = 0u;
	io_write8(TILES_106E00, 0u);
	layer_b_scroll_x = 0x60u;
	layer_b_scroll_y = 0u;
	name_entered = 0u;
	scene_step++;
	scene_substep = 0u;
}

/* each player's score put in the ranking, with his place */
void rank_players_scores(void)
{
	uint32_t carry = 0, extend = 0;
	uint8_t d0_2 = 0;
	uint16_t d0 = 0, d2 = 0, d6 = 0, d7 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0, d3 = 0, player = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;

	a6 = ranking_scores_ADDRESS;
	a5 = ranking_initials_ADDRESS;
	a4 = ranking_places_ADDRESS;
	player = PLAYER_ADDRESS(3);
	d7 = 3u;
	do
	{
		extend = 0u;
		ranking_new_initials = 0x41414100u;
		d6 = 0xC4u;
		ranking_new_score = PLAYER(player)->score;
		do
		{
			d0 = RAM16(ranking_scores_ADDRESS + (uint32_t)(int16_t)d6);
			if (RAM16(ranking_scores_ADDRESS + 0x2u + (uint32_t)(int16_t)d6) < d0)
				break;
			RAM16(ranking_scores_ADDRESS + (uint32_t)(int16_t)d6) = RAM16(ranking_scores_ADDRESS + 0x2u + (uint32_t)(int16_t)d6);
			RAM16(ranking_scores_ADDRESS + 0x2u + (uint32_t)(int16_t)d6) = d0;
			d0_2 = m68k_sbcd(ranking_places((uint32_t)(int16_t)d7), 1u, extend);
			ranking_places((uint32_t)(int16_t)d7) = d0_2;
			if (d0_2 < 0x11u)
			{
				d2 = (uint16_t)d0_2;
				if (d2 == 0x10u)
					d2 = 0xAu;
				d2 = (uint16_t)((d2 - 1u) << 2);
				d3 = AT32(ranking_initials(4 + (uint32_t)(int16_t)d2), -3);
				AT32(ranking_initials(4 + (uint32_t)(int16_t)d2), -3) = RAM32(ranking_initials_ADDRESS + (uint32_t)(int16_t)d2);
				RAM32(ranking_initials_ADDRESS + (uint32_t)(int16_t)d2) = d3;
			}
			t1 = d6;
			carry = t1 < 2u;
			extend = carry;
			d6 = (uint16_t)(t1 - 2u);
		} while (t1 >= 2u);
		t2 = d7 - 1u;
		d7 = t2;
		player -= 8u;
	} while (t2 != 0xFFFFu);
	d7 = 3u;
	do
	{
		d0_2 = ranking_places((uint32_t)(int16_t)d7);
		t3 = d7;
		carry = t3 == 0u;
		extend = carry;
		d6 = (uint16_t)(t3 - 1u);
		if (t3 != 0u)
		{
			do
			{
				if (d0_2 == 0u)
					break;
				if (ranking_places((uint32_t)(int16_t)d6) != 0u && ranking_places((uint32_t)(int16_t)d6) <= d0_2)
				{
					t4 = m68k_abcd(d0_2, 1u, extend);
					carry = m68k_abcd_cy(d0_2, 1u, extend);
					extend = carry;
					d0_2 = t4;
				}
				t5 = d6 - 1u;
				d6 = t5;
			} while (t5 != 0xFFFFu);
		}
		ranking_places((uint32_t)(int16_t)d7) = d0_2;
		t6 = d7 - 1u;
		d7 = t6;
	} while (t6 != 0xFFFFu);
	scene_step++;
}

/* each ranked player's column: frame, label, score, place and his turtle */
void show_ranked_players(void)
{
	uint8_t d4 = 0;
	uint16_t d0 = 0, d7 = 0;
	uint32_t a0 = 0, d6 = 0, d7_2 = 0;
	uint16_t t1 = 0;

	d7 = 3u;
	a0 = ranking_places_ADDRESS;
	turtles_in_black = 0x4Fu;
	do
	{
		if (ranking_places((uint32_t)(int16_t)d7) != 0u)
		{
			d6 = draw_ranking_frame(d6, d7);
			draw_ranking_label((uint8_t)d6, d7);
			d4 = (uint8_t)shl32(1u, (int)(d7 & 0x1Fu));
			draw_scores(d4);
			d7 = (uint16_t)d7;
			draw_ranking_place(d7, a0);
			d0 = (uint16_t)d7;
			d7_2 = shl32(1u, (int)(d0 & 0x1Fu));
			turtles_in_black &= ~shl32(1u, (int)(d0 & 7u));
			draw_four_turtle_pictures(d7_2);
			d7 = (uint16_t)d0;
		}
		t1 = d7 - 1u;
		d7 = t1;
	} while (t1 != 0xFFFFu);
	scene_step++;
}

/* back to the attract mode with no players, else the name entry for the top ten or a wait */
void ranking_choose_entry(void)
{
	uint8_t d6 = 0, d7_2 = 0;
	uint16_t d7 = 0;
	uint32_t a5 = 0, a6 = 0, d7_3 = 0;
	uint16_t t1 = 0, t2 = 0;

	a6 = ranking_places_ADDRESS;
	d6 = 0u;
	d7 = 3u;
	for (;;)
	{
		if (ranking_places((uint32_t)(int16_t)d7) == 0u)
		{
			d6++;
			t1 = d7 - 1u;
			d7 = t1;
			if (t1 == 0xFFFFu)
				break;
			continue;
		}
		if (ranking_places((uint32_t)(int16_t)d7) < 0x11u)
		{
			d7_2 = 0x71u;
			queue_sound(d7_2, a6);
			a6 = ranking_places_ADDRESS;
			a5 = initials_entered_ADDRESS;
			d6 = 0u;
			d7 = 3u;
			do
			{
				if (ranking_places((uint32_t)(int16_t)d7) == 0u || ranking_places((uint32_t)(int16_t)d7) >= 0x11u)
					initials_entered((uint32_t)(int16_t)d7) = 3u;
				else
				{
					initials_entered((uint32_t)(int16_t)d7) = 0u;
					d6 |= shl32(1u, (int)(d7 & 0x1Fu));
				}
				t2 = d7 - 1u;
				d7 = t2;
			} while (t2 != 0xFFFFu);
			players_entering_names = d6;
			initials_buttons_held = 0u;
			d7_3 = draw_ranking_background();
			d7_3 = (d7_3 & ~0xFFu) | turtles_in_black;
			draw_four_turtle_pictures(d7_3);
			ranking_time = 0x5DCu;
			scene_step += 2u;
			return;
		}
		t1 = d7 - 1u;
		d7 = t1;
		if (t1 == 0xFFFFu)
			break;
	}
	if (d6 == 4u)
	{
		back_to_attract();
		return;
	}
	d7_2 = 0x71u;
	queue_sound(d7_2, a6);
	d7_3 = draw_ranking_background();
	d7_3 = (d7_3 & ~0xFFu) | turtles_in_black;
	draw_four_turtle_pictures(d7_3);
	ranking_time = 0x1E0u;
	scene_step++;
}

/* the ranking shown until the time runs out or a button */
void ranking_wait(void)
{
	uint8_t d7 = 0;
	uint16_t t1 = 0;

	t1 = ranking_time;
	ranking_time = t1 - 1u;
	if (t1 != 1u && ((player_inputs(0) | player_inputs(1) | player_inputs(2) | player_inputs(3)) & 0x30u) == 0u)
		return;
	d7 = 0xFEu;
	queue_sound(d7, 0u);
	ranking_time = 0x3Cu;
	scene_step = 7u;
}

/* the top ten players enter their initials with the joystick and a button */
void enter_initials(void)
{
	uint8_t d0 = 0, d1 = 0, d4 = 0, d6 = 0, d7_2 = 0;
	uint16_t d5 = 0, d7 = 0;
	uint32_t a3 = 0, a4 = 0, a5 = 0, a6 = 0;
	uint32_t stack = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0;
	uint32_t turtle_inputs_0_long = 0, t4 = 0;

	t1 = ranking_time;
	ranking_time = t1 - 1u;
	if (t1 == 1u)
	{
		d7_2 = 0xFEu;
		queue_sound(d7_2, 0u);
		name_entered = 1u;
		ranking_time = 0x3Cu;
		scene_step = 7u;
		return;
	}
	if ((frame_count & 7u) != 0u)
		return;
	d7 = 3u;
	do
	{
		if ((players_entering_names & shl32(1u, (int)(d7 & 7u))) != 0u)
			draw_initials(d7);
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
	a3 = initials_entered_ADDRESS;
	a4 = ranking_initials_ADDRESS;
	a5 = ranking_places_ADDRESS;
	turtle_inputs_0_long = (((uint32_t)player_inputs(0) << 24u) | ((uint32_t)player_inputs(1) << 16u) | ((uint32_t)player_inputs(2) << 8u) | player_inputs(3)) | (((uint32_t)player_inputs_last_frame(0) << 24u) | ((uint32_t)player_inputs_last_frame(1) << 16u) | ((uint32_t)player_inputs_last_frame(2) << 8u) | player_inputs_last_frame(3)) | player_inputs_2_frames_ago | player_inputs_3_frames_ago;
	turtle_inputs(0) = (uint8_t)(turtle_inputs_0_long >> 24u);
	turtle_inputs(1) = (uint8_t)(turtle_inputs_0_long >> 16u);
	turtle_inputs(2) = (uint8_t)(turtle_inputs_0_long >> 8u);
	turtle_inputs(3) = (uint8_t)turtle_inputs_0_long;
	a6 = turtle_inputs_ADDRESS;
	d0 = 0u;
	d1 = 0u;
	d7 = 3u;
	do
	{
		if (initials_entered((uint32_t)(int16_t)d7) < 3u)
		{
			if ((players_entering_names & shl32(1u, (int)(d7 & 7u))) != 0u)
			{
				t3 = turtle_inputs((uint32_t)(int16_t)d7);
				d6 = t3;
				if (t3 != 0u)
				{
					if ((d6 & 0x30u) == 0u)
					{
						d5 = ranking_places((uint32_t)(int16_t)d7);
						if (d5 == 0x10u)
							d5 = 0xAu;
						d5 = (uint16_t)((uint32_t)(uint8_t)(d5 - 1u) << 2);
						d5 = (uint16_t)((d5 & ~0xFFu) | (uint8_t)(d5 + initials_entered((uint32_t)(int16_t)d7)));
						d4 = (uint8_t)(ranking_initials(d5) - 0x40u);
						if ((d6 & 1u) == 0u)
						{
							if ((d6 & 2u) != 0u)
							{
								ranking_initials(d5) = ((d4 + 1u) & 0x1Fu) + 0x40u;
								stack = d0;
								d0 = 1u;
								queue_sound_d0(d0);
								d0 = (uint8_t)stack;
							}
						}
						else
						{
							ranking_initials(d5) = ((d4 - 1u) & 0x1Fu) + 0x40u;
							stack = d0;
							d0 = 1u;
							queue_sound_d0(d0);
							d0 = (uint8_t)stack;
						}
					}
					else
					{
						d1 |= shl32(1u, (int)(d7 & 0x1Fu));
						if ((initials_buttons_held & shl32(1u, (int)(d7 & 7u))) != 0u)
						{
							d5 = ranking_places((uint32_t)(int16_t)d7);
							if (d5 == 0x10u)
								d5 = 0xAu;
							d5 = (uint16_t)((uint32_t)(uint8_t)(d5 - 1u) << 2);
							d5 = (uint16_t)((d5 & ~0xFFu) | (uint8_t)(d5 + initials_entered((uint32_t)(int16_t)d7)));
							d4 = (uint8_t)(ranking_initials(d5) - 0x40u);
							if ((d6 & 1u) == 0u)
							{
								if ((d6 & 2u) != 0u)
								{
									ranking_initials(d5) = ((d4 + 1u) & 0x1Fu) + 0x40u;
									stack = d0;
									d0 = 1u;
									queue_sound_d0(d0);
									d0 = (uint8_t)stack;
								}
							}
							else
							{
								ranking_initials(d5) = ((d4 - 1u) & 0x1Fu) + 0x40u;
								stack = d0;
								d0 = 1u;
								queue_sound_d0(d0);
								d0 = (uint8_t)stack;
							}
						}
						else
						{
							t4 = a3 + (int16_t)d7;
							mem_write8(t4, mem_read8(t4) + 1u);
							stack = d0;
							d0 = 0x1Du;
							queue_sound_d0(d0);
							d0 = (uint8_t)stack;
						}
					}
				}
			}
		}
		else
			d0++;
		t5 = d7 - 1u;
		d7 = t5;
	} while (t5 != 0xFFFFu);
	initials_buttons_held = d1;
	if (d0 == 4u)
	{
		d7_2 = 0xFEu;
		queue_sound(d7_2, a6);
		name_entered = 1u;
		ranking_time = 0x78u;
		scene_step++;
	}
}

/* a pause after the name entry */
void ranking_entry_done(void)
{
	uint16_t t1 = 0;

	t1 = ranking_time;
	ranking_time = t1 - 1u;
	if (t1 == 1u)
	{
		leave_ranking();
		return;
	}
}

/* the ranking's last pause */
void ranking_end_wait(void)
{
	uint16_t t1 = 0;

	t1 = ranking_time;
	ranking_time = t1 - 1u;
	if (t1 == 1u)
	{
		leave_ranking();
		return;
	}
}

/* BEST 10 PLAYERS after a name entered with no one left to play, else the attract mode */
void leave_ranking(void)
{
	if (players_with_lives != 0u || name_entered == 0u)
	{
		back_to_attract();
		return;
	}
	game_state = 1u;
	game_step = 6u;
	scene = 0u;
	scene_step = 0u;
	scene_substep = 0u;
	scene_subsubstep = 0u;
	game_on = 0u;
}

/* the game over, back to the attract mode's first step */
void back_to_attract(void)
{
	game_state = 1u;
	game_step = 0u;
	scene = 0u;
	scene_step = 0u;
	scene_substep = 0u;
	scene_subsubstep = 0u;
	game_on = 0u;
}

/* the ranking's background of coloured rows */
uint32_t draw_ranking_background(void)
{
	uint8_t d5 = 0;
	uint16_t d4 = 0, d6 = 0;
	uint32_t a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0, t2 = 0;

	a6 = TILE_RAM + 0x4F18u;
	a5 = indexed_table_of_8_bit_values_00807E_ADDRESS;
	d7 = 0x1Du;
	do
	{
		d6 = 0x27u;
		d5 = mem_read8(a5 + (int16_t)d7);
		do
		{
			d4 = (uint16_t)((uint32_t)(uint8_t)d6 << 1);
			io_write8(a6 + d4, 0u);
			io_write8(a6 + 1u + d4, d5);
			t1 = d6 - 1u;
			d6 = t1;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
		a6 -= 0x80u;
	} while (t2 != 0xFFFFu);
	return d7;
}

/* a player's three initials, the one being entered highlighted */
void draw_initials(uint16_t d7)
{
	uint8_t d0 = 0;
	uint16_t d5 = 0, d6 = 0;
	uint32_t a3 = 0, a4 = 0, a6 = 0;

	a6 = mem_read32(0x840Au + (int16_t)((uint32_t)d7 << 2));
	a3 = initials_entered_ADDRESS;
	a4 = ranking_initials_ADDRESS;
	d6 = mem_read8(ranking_places_ADDRESS + (int16_t)d7);
	if (d6 == 0x10u)
		d6 = 0xAu;
	d6 = (uint16_t)((uint32_t)(uint8_t)(d6 - 1u) << 2);
	d5 = ranking_initials(d6);
	d0 = 0u;
	if (initials_entered((uint32_t)(int16_t)d7) == 0u)
		d0 = 0xA0u;
	draw_initial(d0, d5, a6);
	d5 = ranking_initials(1 + d6);
	d0 = 0u;
	a6 += 4u;
	if (initials_entered((uint32_t)(int16_t)d7) == 1u)
		d0 = 0xA0u;
	draw_initial(d0, d5, a6);
	d5 = ranking_initials(2 + d6);
	d0 = 0u;
	a6 += 4u;
	if (initials_entered((uint32_t)(int16_t)d7) == 2u)
		d0 = 0xA0u;
	draw_initial(d0, d5, a6);
}

/* a tall letter in a colour */
void draw_initial(uint8_t d0, uint16_t d5, uint32_t a6)
{
	d5 = (uint16_t)((uint32_t)(uint8_t)(d5 - 0x30u) << 1);
	mem_write8(a6, d0);
	mem_write8(a6 + 1u, indexed_table_of_8_bit_values_002884[d5]);
	mem_write8(a6 + 0x80u, d0);
	mem_write8(a6 + 0x81u, rom_002885[d5]);
}

/* the frame of a player's column in his colour */
uint32_t draw_ranking_frame(uint32_t d6, uint16_t d7)
{
	uint16_t d4 = 0, d5 = 0;
	uint32_t a5 = 0, a6 = 0, d6_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	d6_2 = (d6 & ~0xFFFFu) | d7;
	d6_2 = (d6_2 & ~0xFFFFu) | (uint16_t)(d6_2 << 2);
	a6 = mem_read32(0x83DAu + (int16_t)d6_2);
	d6_2 = (d6_2 & ~0xFFFFu) | d7;
	d6_2 = ranking_frame_colour(d6_2);
	d5 = 8u;
	d4 = 0u;
	a5 = 0x841Au;
	do
	{
		d4 += 0x80u;
		mem_write8(a6 + (int16_t)d4, d6_2);
		mem_write8(a6 + 1u + (int16_t)d4, DATA8(a5 + 9u));
		d4 -= 0x80u;
		mem_write8(a6 + (int16_t)d4, d6_2);
		mem_write8(a6 + 1u + (int16_t)d4, DATA8(a5));
		d4 = (uint16_t)((d4 & ~0xFFu) | (uint8_t)(d4 + 2u));
		t1 = d5 - 1u;
		d5 = t1;
		a5++;
	} while (t1 != 0xFFFFu);
	d5 = 0x17u;
	a6 += 0x100u;
	do
	{
		mem_write8(a6, d6_2);
		mem_write8(a6 + 1u, 0x1Au);
		mem_write8(a6 + 0x10u, d6_2);
		mem_write8(a6 + 0x11u, 0x1Du);
		t2 = d5 - 1u;
		d5 = t2;
		a6 += 0x80u;
	} while (t2 != 0xFFFFu);
	d5 = 8u;
	d4 = 0u;
	a5 = 0x842Cu;
	do
	{
		mem_write8(a6 + d4, d6_2);
		mem_write8(a6 + 1u + d4, DATA8(a5));
		d4 = (uint8_t)(d4 + 2u);
		t3 = d5 - 1u;
		d5 = t3;
		a5++;
	} while (t3 != 0xFFFFu);
	return d6_2;
}

/* a player's label at the top of his column */
void draw_ranking_label(uint8_t d6, uint16_t d7)
{
	uint32_t a5 = 0, a6 = 0;

	a6 = mem_read32(0x83EAu + (int16_t)((uint32_t)d7 << 2));
	a5 = TABLE32(rom_00332A, (uint32_t)(int16_t)((uint32_t)d7 << 2));
	mem_write8(a6, d6);
	mem_write8(a6 + 2u, d6);
	mem_write8(a6 + 0x80u, d6);
	mem_write8(a6 + 0x82u, d6);
	mem_write8(a6 + 1u, mem_read8(a5));
	mem_write8(a6 + 3u, mem_read8(a5 + 1u));
	mem_write8(a6 + 0x81u, mem_read8(a5 + 2u));
	mem_write8(a6 + 0x83u, mem_read8(a5 + 3u));
}

/* a player's place, its digits and ending */
void draw_ranking_place(uint16_t d7, uint32_t a0)
{
	uint8_t d6 = 0;
	uint16_t d5 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint16_t t1 = 0;

	a6 = mem_read32(0x83FAu + (int16_t)((uint32_t)d7 << 2));
	a5 = 0x8436u;
	d6 = ranking_places((uint32_t)(int16_t)d7);
	d5 = (uint16_t)d6;
	d5 = (uint8_t)(d5 - 1u);
	if (d5 >= 3u)
		d5 = 3u;
	d5 = (uint16_t)((uint32_t)d5 << 1);
	mem_write8(a6 + 0x84u, 0u);
	mem_write8(a6 + 0x85u, DATA8(a5 + d5));
	mem_write8(a6 + 0x86u, 0u);
	mem_write8(a6 + 0x87u, DATA8(a5 + 1u + d5));
	a5 = indexed_table_of_8_bit_values_002884_ADDRESS;
	d5 = (uint16_t)((d6 & 0xFu) << 1);
	mem_write8(a6 + 2u, 0u);
	mem_write8(a6 + 3u, indexed_table_of_8_bit_values_002884[d5]);
	mem_write8(a6 + 0x82u, 0u);
	mem_write8(a6 + 0x83u, indexed_table_of_8_bit_values_002884[(uint8_t)(d5 + 1u)]);
	t1 = d6 & 0xF0u;
	d5 = t1;
	if (t1 != 0u)
	{
		d5 = d5 >> 3;
		mem_write8(a6, 0u);
		mem_write8(a6 + 1u, DATA8(a5 + d5));
		mem_write8(a6 + 0x80u, 0u);
		mem_write8(a6 + 0x81u, DATA8(a5 + (uint8_t)(d5 + 1u)));
	}
}

/* the colour of a player's column */
uint32_t ranking_frame_colour(uint32_t d6)
{
	uint32_t d6_2 = 0;

	d6_2 = (d6 & ~0xFFu) | TABLE8(rom_001F1B, (uint32_t)(int16_t)d6);
	d6_2 = d6_2 | 1u;
	return d6_2;
}

/* the ranking's default scores and initials, and the top score */
void reset_ranking(void)
{
	uint16_t d7 = 0;
	uint32_t a5 = 0, a6 = 0;
	uint16_t t2 = 0, t4 = 0;
	uint32_t t1 = 0, t3 = 0;

	a6 = ranking_scores_ADDRESS;
	a5 = table_loaded_by_lea_0082E6_ADDRESS;
	top_score = 0x1000u;
	d7 = 0x31u;
	do
	{
		t1 = a6;
		a6 += 4u;
		mem_write32(t1, DATA32(a5));
		t2 = d7 - 1u;
		d7 = t2;
		a5 += 4u;
	} while (t2 != 0xFFFFu);
	d7 = 0xAu;
	do
	{
		t3 = a6;
		a6 += 4u;
		mem_write32(t3, DATA32(a5));
		t4 = d7 - 1u;
		d7 = t4;
		a5 += 4u;
	} while (t4 != 0xFFFFu);
}
