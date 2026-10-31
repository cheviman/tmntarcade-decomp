/**
 *    Name:        system/frame.c
 *    Description: the VBLANK interrupt: the inputs, the frame's work, the game's states and the job queue
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the coins: the coin counters, the coins inserted turned into credits */
void update_coins(void)
{
	uint32_t carry = 0;
	uint8_t d0_2 = 0, d7 = 0;
	uint16_t d6 = 0;
	uint32_t a0 = 0, coin_slot = 0, d0 = 0;
	uint16_t t1 = 0, t2 = 0, credits = 0, t3 = 0;

	new_credit = 0u;
	d7 = board_control | 1u;
	coin_slot = COIN_SLOT_ADDRESS(0);
	d6 = 3u;
	if (COIN_SLOT(COIN_SLOT_ADDRESS(0))->counter_pulse == 0u)
	{
		d6 = (uint8_t)(d6 - 1u);
		coin_slot += 8u;
		if (COIN_SLOT(COIN_SLOT_ADDRESS(1))->counter_pulse == 0u)
		{
			d6 = (uint8_t)(d6 - 1u);
			coin_slot += 8u;
			if (COIN_SLOT(COIN_SLOT_ADDRESS(2))->counter_pulse == 0u)
			{
				d6 = (uint8_t)(d6 - 1u);
				coin_slot += 8u;
				if (COIN_SLOT(COIN_SLOT_ADDRESS(3))->counter_pulse == 0u)
				{
					coin_slot = COIN_SLOT_ADDRESS(0);
					d6 = 3u;
				}
			}
		}
	}
	for (;;)
	{
		pulse_coin_counter(coin_slot);
		if (COIN_SLOT(coin_slot)->counter_on != 0u)
			break;
		if (COIN_SLOT(coin_slot)->counter_pulse == 0u)
		{
			t1 = d6 - 1u;
			d6 = t1;
			coin_slot += 8u;
			if (t1 != 0xFFFFu)
				continue;
		}
		d7 &= ~1u;
		break;
	}
	board_control = d7;
	io_write8(IO_0A0001, d7);
	d0 = new_coin_presses(0u);
	new_coin_switches = d0;
	d0_2 = new_coin_switches;
	a0 = COIN_SLOT_ADDRESS(0);
	d6 = 3u;
	do
	{
		carry = d0_2 & 1u;
		d0_2 = d0_2 >> 1;
		if (carry)
			count_coin(a0);
		t2 = d6 - 1u;
		d6 = t2;
		a0 += 8u;
	} while (t2 != 0xFFFFu);
	d0_2 = new_coin_switches >> 4;
	coin_slot = COIN_SLOT_ADDRESS(0);
	d6 = 3u;
	do
	{
		carry = d0_2 & 1u;
		d0_2 = d0_2 >> 1;
		if (carry)
		{
			new_credit = 1u;
			credits = COIN_SLOT(coin_slot)->credits;
			carry = (uint16_t)(credits + 1u) < credits;
			COIN_SLOT(coin_slot)->credits = credits + 1u;
			if (carry)
				COIN_SLOT(coin_slot)->credits--;
		}
		t3 = d6 - 1u;
		d6 = t3;
		coin_slot += 8u;
	} while (t3 != 0xFFFFu);
}

/* the coin switches just pressed, with the coin's sound */
uint32_t new_coin_presses(uint32_t d0)
{
	uint8_t d7 = 0;
	uint32_t d0_2 = 0;
	uint8_t t1 = 0;

	d0_2 = (d0 & ~0xFFu) | coin_switches;
	d0_2 = d0_2 | coin_switches_last_frame;
	d0_2 = (d0_2 & ~0xFFu) | (uint8_t)~d0_2;
	t1 = d0_2 & coin_switches_2_frames_ago;
	d0_2 = (d0_2 & ~0xFFu) | t1;
	if (t1 == 0u || game_state == 3u)
		return d0_2;
	if (game_on != 0u)
	{
		d7 = 0x86u;
		queue_sound_command(d7);
	}
	else
	{
		d7 = 0xFFu;
		queue_sound_command(d7);
		d7 = 0x86u;
		queue_sound_command(d7);
		sound_stopped_by_coin = 1u;
	}
	return d0_2;
}

/* a coin slot's counter pulsed for each coin */
void pulse_coin_counter(uint32_t a0)
{
	uint8_t d0 = 0, d1 = 0;
	uint8_t counter_pulse = 0;

	d1 = 0u;
	counter_pulse = COIN_SLOT(a0)->counter_pulse;
	d0 = counter_pulse;
	if (counter_pulse == 0u)
	{
		if (COIN_SLOT(a0)->coins_to_count != 0u)
		{
			COIN_SLOT(a0)->coins_to_count--;
			COIN_SLOT(a0)->counter_on = d1 + 1u;
			COIN_SLOT(a0)->counter_pulse = 0x3Cu;
		}
		return;
	}
	d0--;
	COIN_SLOT(a0)->counter_pulse = d0;
	if (d0 != 0x1Eu)
		return;
	COIN_SLOT(a0)->counter_on = d1;
}

/* a coin inserted, counted towards the slot's credits */
void count_coin(uint32_t a0)
{
	uint32_t carry = 0;
	uint16_t d7 = 0;
	uint16_t credits = 0;

	COIN_SLOT(a0)->coins_to_count++;
	COIN_SLOT(a0)->coins++;
	if (COIN_SLOT(a0)->coins != COIN_SLOT(COIN_SLOT_ADDRESS(0))->coins_per_credit)
		return;
	new_credit = 1u;
	d7 = COIN_SLOT(COIN_SLOT_ADDRESS(0))->credits_per_coins;
	credits = COIN_SLOT(a0)->credits;
	carry = (uint16_t)(d7 + credits) < d7;
	d7 += credits;
	if (carry == 0u)
		COIN_SLOT(a0)->credits = d7;
	COIN_SLOT(a0)->coins = 0u;
}

/* each slot's credits added to its player's lives */
void add_credit_lives(uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t carry = 0, extend = 0;
	uint8_t d3 = 0;
	uint16_t d4 = 0, d6 = 0, d7 = 0;
	uint32_t coin_slot = 0, d6_2 = 0, d7_2 = 0, player = 0, player_2 = 0;
	uint16_t credits = 0, t1 = 0, t2 = 0, t3 = 0;

	coin_slot = COIN_SLOT_ADDRESS(0);
	player_2 = PLAYER_ADDRESS(0);
	d7 = 3u;
	d3 = 0u;
	do
	{
		credits = COIN_SLOT(coin_slot)->credits;
		d6 = credits;
		if (credits != 0u)
		{
			players_credited |= shl32(1u, (int)(d3 & 7u));
			d6 = (uint16_t)((d6 & ~0xFFu) | (uint8_t)(d6 - 1u));
			do
			{
				d5 = lives_per_credit;
				d4 = PLAYER(player_2)->lives;
				extend = 0u;
				carry = m68k_abcd_cy((uint8_t)d4, d5, extend);
				d4 = (uint16_t)((d4 & ~0xFFu) | m68k_abcd((uint8_t)d4, d5, extend));
				if (carry)
				{
					d4 += 0x100u;
					if (d4 >= 0x999u)
						d4 = 0x999u;
				}
				PLAYER(player_2)->lives = d4;
				COIN_SLOT(coin_slot)->credits--;
				t1 = d6 - 1u;
				d6 = t1;
			} while (t1 != 0xFFFFu);
		}
		d3++;
		t2 = d7 - 1u;
		d7 = t2;
		coin_slot += 8u;
		player_2 += 8u;
	} while (t2 != 0xFFFFu);
	player = PLAYER_ADDRESS(3);
	d7_2 = 3u;
	d6_2 = 0u;
	do
	{
		if (PLAYER(player)->lives != 0u)
		{
			d6_2 |= shl32(1u, (int)(d7_2 & 0x1Fu));
			players_out_of_lives &= ~shl32(1u, (int)(d7_2 & 7u));
		}
		t3 = d7_2 - 1u;
		d7_2 = t3;
		player -= 8u;
	} while (t3 != 0xFFFFu);
	players_with_lives = d6_2;
	*p_d5 = d5;
	*p_d6 = d6_2;
	*p_d7 = d7_2;
}

void unreached_003DAA(uint8_t d0)
{
	uint16_t d1 = 0;
	uint32_t a0 = 0;
	uint16_t t1 = 0;

	a0 = TILE_RAM + 0x11Au;
	d1 = 0x1Bu;
	do
	{
		io_write8(a0, 0u);
		io_write8(a0 + 1u, d0);
		a0 += 0x80u;
		t1 = d1 - 1u;
		d1 = t1;
	} while (t1 != 0xFFFFu);
}

/* the frame's interrupt: the inputs, the coins, the sound, the palettes and the game state's frame */
void vblank_interrupt(void)
{
	uint32_t a5 = 0, d5 = 0, d6 = 0, d7 = 0;

	board_control &= 0xDFu;
	io_write8(IO_0A0001, board_control);
	io_write8(IO_0A0011, 0u);
	write_status(0u);
	take_interrupts();
	frame_count++;
	sound_stopped_by_coin = 0u;
	d6 = send_sound_command(0u);
	d7 = read_inputs(0u);
	if (game_state != 3u)
	{
		update_coins();
		add_credit_lives(&d5, &d6, &d7);
	}
	run_palette_requests(0u, &d5, &d6, &d7, &a5);
	step_palette_effects();
	switch (game_state)
	{
	case 0:
		run_startup();
		break;
	case 1:
		run_attract(0u, (uint16_t)d5, (uint16_t)d6, d7, a5);
		break;
	case 2:
		run_game(0u, (uint16_t)d5, (uint16_t)d6, d7, a5);
		break;
	case 3:
		run_test_mode();
		break;
	}
	board_control |= 0x20u;
	io_write8(IO_0A0001, board_control);
}

/* the coins and the four players' inputs read, and the layers' scroll written */
uint32_t read_inputs(uint32_t d7)
{
	uint8_t d0 = 0;
	uint32_t d7_2 = 0;

	player_inputs_3_frames_ago = player_inputs_2_frames_ago;
	player_inputs_2_frames_ago = (((uint32_t)player_inputs_last_frame(0) << 24u) | ((uint32_t)player_inputs_last_frame(1) << 16u) | ((uint32_t)player_inputs_last_frame(2) << 8u) | player_inputs_last_frame(3));
	player_inputs_last_frame(0) = player_inputs(0);
	player_inputs_last_frame(1) = player_inputs(1);
	player_inputs_last_frame(2) = player_inputs(2);
	player_inputs_last_frame(3) = player_inputs(3);
	coin_switches_3_frames_ago = coin_switches_2_frames_ago;
	coin_switches_2_frames_ago = coin_switches_last_frame;
	coin_switches_last_frame = coin_switches;
	coin_switches = ~io_read8(IO_0A0001);
	d0 = (uint8_t)~io_read8(IO_0A0003);
	player_inputs(0) = d0;
	player_presses(0) = d0 & ~player_inputs_last_frame(0);
	d0 = (uint8_t)~io_read8(IO_0A0005);
	player_inputs(1) = d0;
	player_presses(1) = d0 & ~player_inputs_last_frame(1);
	d0 = (uint8_t)~io_read8(IO_0A0007);
	player_inputs(2) = d0;
	player_presses(2) = d0 & ~player_inputs_last_frame(2);
	d0 = (uint8_t)~io_read8(IO_0A0015);
	player_inputs(3) = d0;
	player_presses(3) = d0 & ~player_inputs_last_frame(3);
	io_write8(TILES_106018, (uint8_t)layer_a_scroll_y);
	d7_2 = (d7 & ~0xFFFFu) | layer_a_scroll_x;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 - 0x60u);
	io_write8(TILES_106400, d7_2);
	d7_2 = (d7_2 & ~0xFFFFu) | ((uint16_t)d7_2 >> 8);
	io_write8(TILES_106402, d7_2);
	io_write8(TILES_106019, (uint8_t)layer_b_scroll_y);
	d7_2 = (d7_2 & ~0xFFFFu) | layer_b_scroll_x;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 - 0x60u);
	io_write8(TILES_106401, d7_2);
	d7_2 = (d7_2 & ~0xFFFFu) | ((uint16_t)d7_2 >> 8);
	io_write8(TILES_106403, d7_2);
	return d7_2;
}

/* the steps after the reset */
void run_startup(void)
{
	switch (game_step)
	{
	case 0:
		startup_begin();
		return;
	case 1:
		startup_wait();
		return;
	case 2:
		startup_end();
		return;
	}
}

/* the video chips set, the test mode when its switch is on, else the screen cleared */
void startup_begin(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	tile_banks_0_1 = 0u;
	io_write8(TILES_106B00, 0u);
	tile_banks_2_3 = 0u;
	io_write8(TILES_106E00, 0u);
	io_write8(0x140000u, sprite_control);
	set_screen_flip();
	game_on = 0u;
	if ((dip_switches_3 & 4u) != 0u)
	{
		game_state = 3u;
		return;
	}
	game_step++;
	jobs_pending = 1u;
	d7 = 1u;
	queue_job(d7);
	d7 = 0x20Fu;
	a6 = 0xA05Eu;
	post_palette_request(d7, a6);
}

/* the screen cleared */
void startup_wait(void)
{
	if (jobs_pending == 0u && palettes_busy == 0u)
	{
		step_timer = 1u;
		game_step++;
	}
}

/* on to the attract mode */
void startup_end(void)
{
	uint8_t t1 = 0;

	t1 = step_timer;
	step_timer = t1 - 1u;
	if (t1 == 1u || new_credit != 0u || (coin_switches != 0u && free_play != 0u))
	{
		game_state++;
		game_step = 0u;
		return;
	}
}

void unreached_004068(void)
{
	set_screen_flip();
}

/* the screen flipped by its DIP switch */
void set_screen_flip(void)
{
	uint8_t d6 = 0, d7 = 0;

	d7 = tile_flip & ~1u;
	d6 = sprite_control & ~8u;
	if ((dip_switches_3 & 1u) != 0u)
	{
		d7 ^= 1u;
		d6 ^= 8u;
	}
	tile_flip = d7;
	io_write8(TILES_106D00, d7);
	sprite_control = d6;
	io_write8(0x140000u, d6);
}

/* the attract mode's frame, and a game when a player starts */
void run_attract(uint32_t d1, uint16_t d5, uint16_t d6, uint32_t d7, uint32_t a5)
{
	uint8_t d7_2 = 0;

	switch (game_step)
	{
	case 0:
		attract_begin();
		break;
	case 1:
		attract_coin_screen(d1);
		break;
	case 2:
		attract_opening(d6, a5);
		break;
	case 3:
		attract_title();
		break;
	case 4:
		attract_demo(d1, d5, d6, d7, a5);
		break;
	case 5:
		attract_profile();
		break;
	case 6:
		attract_best_players();
		break;
	case 7:
		attract_spare_step();
		break;
	case 8:
		attract_end();
		break;
	}
	check_starts();
	if (scratch_byte != 0u)
	{
		d7_2 = 0u;
		queue_sound(d7_2, 0u);
		game_step = 0u;
		scene = 0u;
		scene_step = 0u;
		scene_substep = 0u;
		game_state++;
	}
}

/* the game's frame by its scene */
void run_game(uint32_t d1, uint16_t d5, uint16_t d6, uint32_t d7, uint32_t a5)
{
	switch (scene)
	{
	case 0:
		scene_new_game();
		return;
	case 1:
		scene_choose_turtles();
		return;
	case 2:
		scene_area_setup();
		return;
	case 3:
		scene_area_title(d1);
		return;
	case 4:
		scene_play(d1, d5, d7);
		return;
	case 5:
		scene_area_exit(d1, d7);
		return;
	case 6:
		scene_ending(d6, a5);
		return;
	case 7:
		scene_continue(d1, d6, a5);
		return;
	case 8:
		scene_ranking();
		return;
	}
}

/* the test mode's frame */
void run_test_mode(void)
{
	switch ((uint32_t)(int8_t)scene)
	{
	case 0:
		test_mode_start();
		break;
	case 1:
		mask_rom_check_page();
		break;
	case 2:
		cross_hatch_page();
		break;
	case 3:
		color_test_page();
		break;
	case 4:
		io_test_page();
		break;
	case 5:
		skip_coin_counter_test();
		break;
	case 6:
		sound_test_page();
		break;
	case 7:
		dip_switch_page();
		break;
	case 8:
		test_mode_restart();
		break;
	}
	read_inputs(0u);
}

/* a job into the main loop's queue */
void queue_job(uint16_t d7)
{
	uint32_t a6 = 0;

	a6 = job_queue_write;
	mem_write16(a6, d7);
	a6 += 2u;
	if (a6 > job_queue_ADDRESS + 0x7Fu)
		a6 = job_queue_ADDRESS;
	job_queue_write = a6;
}

/* a list of jobs into the main loop's queue */
void queue_jobs(uint32_t a5)
{
	uint16_t d7 = 0;

	for (;;)
	{
		d7 = mem_read16(a5);
		a5 += 2u;
		if (d7 == 0xFFFFu)
			break;
		queue_job(d7);
	}
}

/* the second interrupt, which the board never raises */
void irq6_interrupt(void)
{
	demo_hold_3 = 0u;
	return_from_exception();
}

/* in the attract mode, the players with lives who press a button start the game */
void check_starts(void)
{
	uint8_t d1 = 0;
	uint16_t d0 = 0;
	uint32_t a5 = 0, player = 0;
	uint8_t t1 = 0;

	scratch_byte = 0u;
	d0 = 0u;
	player = PLAYER_ADDRESS(0);
	a5 = player_inputs_ADDRESS;
	do
	{
		if (PLAYER(player)->lives != 0u && (player_inputs(d0) & 0x30u) != 0u && (player_inputs_last_frame(d0) & 0x30u) == 0u)
			scratch_byte |= shl32(1u, (int)(d0 & 7u));
		d0 = (uint8_t)(d0 + 1u);
		player += 8u;
	} while (d0 < 4u);
	t1 = scratch_byte;
	d1 = t1;
	if (t1 != 0u)
	{
		players_in_play = d1;
		players_joining = d1;
		game_on = 1u;
	}
}

/* in a game, the players with lives who press a button join it */
uint32_t check_joins(uint32_t d1)
{
	uint16_t d0 = 0;
	uint32_t a5 = 0, player = 0;
	uint8_t t1 = 0;
	uint16_t lives = 0;

	if (game_on == 0u)
		return d1;
	scratch_byte = 0u;
	d0 = 0u;
	player = PLAYER_ADDRESS(0);
	a5 = player_inputs_ADDRESS;
	do
	{
		if ((players_in_play & shl32(1u, (int)(d0 & 7u))) == 0u)
		{
			lives = PLAYER(player)->lives;
			d1 = lives;
			if (lives != 0u)
			{
				d1 = (d1 & ~0xFFu) | player_inputs(d0);
				if ((d1 & 0x30u) != 0u)
				{
					d1 = (d1 & ~0xFFu) | player_inputs_last_frame(d0);
					if ((d1 & 0x30u) == 0u)
						scratch_byte |= shl32(1u, (int)(d0 & 7u));
				}
			}
		}
		d0 = (uint8_t)(d0 + 1u);
		player += 8u;
	} while (d0 < 4u);
	t1 = scratch_byte;
	d1 = (d1 & ~0xFFu) | t1;
	if (t1 != 0u)
	{
		players_in_play |= d1;
		players_joining |= d1;
		game_on = 1u;
	}
	return d1;
}

/* the first player's score and health reset */
uint32_t reset_player_1(void)
{
	uint32_t a6 = 0;

	a6 = PLAYER_ADDRESS(0);
	reset_score(a6);
	PLAYER(PLAYER_ADDRESS(0))->health_bars = 0u;
	return a6;
}

/* the second player's score and health reset */
uint32_t reset_player_2(void)
{
	uint32_t a6 = 0;

	a6 = PLAYER_ADDRESS(1);
	reset_score(a6);
	PLAYER(PLAYER_ADDRESS(1))->health_bars = 0u;
	return a6;
}

/* the third player's score and health reset */
uint32_t reset_player_3(void)
{
	uint32_t a6 = 0;

	a6 = PLAYER_ADDRESS(2);
	reset_score(a6);
	PLAYER(PLAYER_ADDRESS(2))->health_bars = 0u;
	return a6;
}

/* the fourth player's score and health reset */
uint32_t reset_player_4(void)
{
	uint32_t a6 = 0;

	a6 = PLAYER_ADDRESS(3);
	reset_score(a6);
	PLAYER(PLAYER_ADDRESS(3))->health_bars = 0u;
	return a6;
}

/* a life of the first player's used */
void use_life_player_1(void)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	a6 = PLAYER_ADDRESS(0);
	d7 = 0u;
	use_life(d7, a6);
}

/* a life of the second player's used */
void use_life_player_2(void)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	a6 = PLAYER_ADDRESS(1);
	d7 = 1u;
	use_life(d7, a6);
}

/* a life of the third player's used */
void use_life_player_3(void)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	a6 = PLAYER_ADDRESS(2);
	d7 = 2u;
	use_life(d7, a6);
}

/* a life of the fourth player's used */
void use_life_player_4(void)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	a6 = PLAYER_ADDRESS(3);
	d7 = 3u;
	use_life(d7, a6);
}

/* a life used and the health full; with none left the player is out */
void use_life(uint8_t d7, uint32_t a6)
{
	uint32_t carry = 0, extend = 0;
	uint8_t d1 = 0;

	extend = 0u;
	d1 = PLAYER(a6)->lives_low;
	carry = m68k_sbcd_cy(d1, 1u, extend);
	d1 = m68k_sbcd(d1, 1u, extend);
	if (carry == 0u)
	{
		PLAYER(a6)->lives_low = d1;
		PLAYER(a6)->health_bars = 0xAu;
		return;
	}
	if ((uint8_t)(PLAYER(a6)->lives >> 8u) == 0u)
	{
		players_in_play &= ~shl32(1u, (int)(d7));
		players_out_of_lives |= shl32(1u, (int)(d7));
		return;
	}
	PLAYER(a6)->lives = (PLAYER(a6)->lives & 0xFFu) | (((uint8_t)(PLAYER(a6)->lives >> 8u) - 1u & 0xFFu) << 8u);
	d1 = 0x99u;
	PLAYER(a6)->lives_low = d1;
	PLAYER(a6)->health_bars = 0xAu;
}

/* a player's score reset */
void reset_score(uint32_t a6)
{
	PLAYER(a6)->score = 0u;
	PLAYER(a6)->unused_setting_copy = unused_dip_setting;
}

/* the players who join or come back, their boxes and messages */
void update_players_in_game(uint32_t d1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0, ignored = 0;

	join_players(d7, &d1, &d5, p_a1);
	redraw_new_lives(0u, d7, &d1, &d5);
	respawn_players(0u, d7, &d1, &d5, p_a1);
	update_player_messages(d1, &d5, &ignored, &d7_2);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

/* the boxes whose lives a coin changed */
void redraw_new_lives(uint32_t d4, uint32_t d7, uint32_t *p_d1, uint32_t *p_d5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7_2 = 0, ignored = 0, ignored_2 = 0;

	d7_2 = (d7 & ~0xFFFFu) | 0xB00u;
	d7_2 |= (uint8_t)(d7_2 + players_credited);
	d7_2 = d7_2 | 0x30u;
	draw_player_boxes(d7_2, p_d1, &ignored, &d5, &ignored_2);
	players_credited = 0u;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* the players who join: their turtles in, a life each */
void join_players(uint32_t d7, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7_2 = 0, ignored = 0, ignored_2 = 0;

	if (players_joining == 0u)
		return;
	d7_2 = (d7 & ~0xFFu) | players_joining;
	turtle_join((uint8_t)d7_2, p_d1, &ignored, p_a1);
	if ((players_joining & 1u) != 0u)
		use_life_player_1();
	if ((players_joining & 2u) != 0u)
		use_life_player_2();
	if ((players_joining & 4u) != 0u)
		use_life_player_3();
	if ((players_joining & 8u) != 0u)
		use_life_player_4();
	d7_2 = (d7_2 & ~0xFFFFu) | 0xB00u;
	d7_2 |= (uint8_t)(d7_2 + players_joining);
	d7_2 = d7_2 | 0x30u;
	draw_player_boxes(d7_2, p_d1, &ignored, &d5, &ignored_2);
	players_joining = 0u;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* the players whose turtle was knocked out: a life each, the turtle back */
void respawn_players(uint32_t d4, uint32_t d7, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7_2 = 0, ignored = 0, ignored_2 = 0;

	if (players_knocked_out == 0u)
		return;
	if ((players_knocked_out & 1u) != 0u)
		use_life_player_1();
	if ((players_knocked_out & 2u) != 0u)
		use_life_player_2();
	if ((players_knocked_out & 4u) != 0u)
		use_life_player_3();
	if ((players_knocked_out & 8u) != 0u)
		use_life_player_4();
	d7_2 = (d7 & ~0xFFu) | players_in_play;
	d7_2 = d7_2 & (players_knocked_out | 0xFFFFFF00u);
	turtle_respawn((uint8_t)d7_2, p_d1, &ignored, p_a1);
	d7_2 = (d7_2 & ~0xFFFFu) | 0xB00u;
	d7_2 |= (uint8_t)(d7_2 + players_knocked_out);
	d7_2 = d7_2 | 0x30u;
	draw_player_boxes(d7_2, p_d1, &ignored, &d5, &ignored_2);
	players_knocked_out = 0u;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* the messages under the four boxes */
void update_player_messages(uint32_t d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d0 = 0;
	uint16_t t1 = 0;

	d0 = 3u;
	do
	{
		update_player_message((uint8_t)d0, d1, 0u, &d5, p_d6, p_d7);
		t1 = d0 - 1u;
		d0 = t1;
	} while (t1 != 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the message under a player's box by how he stands */
void update_player_message(uint8_t d0, uint32_t d1, uint32_t d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d1_2 = 0, d7 = 0, ignored = 0;

	d1_2 = (d1 & ~0xFFu) | players_with_lives;
	d1_2 = d1_2 | players_joining;
	d1_2 = d1_2 | players_in_play;
	d1_2 = d1_2 | players_knocked_out;
	if ((d1_2 & shl32(1u, (int)(d0 & 0x1Fu))) != 0u)
	{
		d1_2 = (d1_2 & ~0xFFu) | players_joining;
		d1_2 = d1_2 | players_in_play;
		d1_2 = d1_2 | players_knocked_out;
		if (((d1_2 | players_out_of_lives) & shl32(1u, (int)(d0 & 0x1Fu))) != 0u || (players_with_lives & shl32(1u, (int)(d0 & 7u))) == 0u)
			d7 = 0xCu;
		else
			d7 = 4u;
	}
	else if ((players_out_of_lives & shl32(1u, (int)(d0 & 7u))) != 0u)
		d7 = 8u;
	else
		d7 = 0u;
	d7 = (uint8_t)(d7 | d0);
	d7 = (uint16_t)(d7 + 0xD00u);
	draw_player_message(&ignored, &d5, p_d6, &d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7;
}

void unreached_0044EE(uint16_t d7)
{
	d7 |= 0xB30u;
	queue_job(d7);
}

/* the objects, the sprites, the palette effects and the play's variables cleared */
void clear_play(void)
{
	clear_palette_effects();
	clear_objects();
	clear_sprite_ram();
	clear_engine_variables();
	clear_area_variables();
	clear_engine_ram();
}

/* a stretch of work RAM zeroed */
void zero_ram_below(uint16_t d0, uint32_t a0)
{
	uint32_t a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t65 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t30 = 0, t31 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0, t39 = 0, t40 = 0, t41 = 0, t42 = 0, t43 = 0, t44 = 0, t45 = 0, t46 = 0, t47 = 0, t48 = 0, t49 = 0, t50 = 0, t51 = 0, t52 = 0, t53 = 0, t54 = 0, t55 = 0, t56 = 0, t57 = 0, t58 = 0, t59 = 0, t60 = 0, t61 = 0, t62 = 0, t63 = 0, t64 = 0;

	zero_fill_registers(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		t25 = t24 - 4u;
		mem_write16(t25 + 2u, a1);
		mem_write16(t25, a1 >> 16);
		t26 = t25 - 4u;
		mem_write16(t26 + 2u, d7);
		mem_write16(t26, d7 >> 16);
		t27 = t26 - 4u;
		mem_write16(t27 + 2u, d6);
		mem_write16(t27, d6 >> 16);
		t28 = t27 - 4u;
		mem_write16(t28 + 2u, d5);
		mem_write16(t28, d5 >> 16);
		t29 = t28 - 4u;
		mem_write16(t29 + 2u, d4);
		mem_write16(t29, d4 >> 16);
		t30 = t29 - 4u;
		mem_write16(t30 + 2u, d3);
		mem_write16(t30, d3 >> 16);
		t31 = t30 - 4u;
		mem_write16(t31 + 2u, d2);
		mem_write16(t31, d2 >> 16);
		t32 = t31 - 4u;
		mem_write16(t32 + 2u, d1);
		mem_write16(t32, d1 >> 16);
		t33 = t32 - 4u;
		mem_write16(t33 + 2u, a1);
		mem_write16(t33, a1 >> 16);
		t34 = t33 - 4u;
		mem_write16(t34 + 2u, d7);
		mem_write16(t34, d7 >> 16);
		t35 = t34 - 4u;
		mem_write16(t35 + 2u, d6);
		mem_write16(t35, d6 >> 16);
		t36 = t35 - 4u;
		mem_write16(t36 + 2u, d5);
		mem_write16(t36, d5 >> 16);
		t37 = t36 - 4u;
		mem_write16(t37 + 2u, d4);
		mem_write16(t37, d4 >> 16);
		t38 = t37 - 4u;
		mem_write16(t38 + 2u, d3);
		mem_write16(t38, d3 >> 16);
		t39 = t38 - 4u;
		mem_write16(t39 + 2u, d2);
		mem_write16(t39, d2 >> 16);
		t40 = t39 - 4u;
		mem_write16(t40 + 2u, d1);
		mem_write16(t40, d1 >> 16);
		t41 = t40 - 4u;
		mem_write16(t41 + 2u, a1);
		mem_write16(t41, a1 >> 16);
		t42 = t41 - 4u;
		mem_write16(t42 + 2u, d7);
		mem_write16(t42, d7 >> 16);
		t43 = t42 - 4u;
		mem_write16(t43 + 2u, d6);
		mem_write16(t43, d6 >> 16);
		t44 = t43 - 4u;
		mem_write16(t44 + 2u, d5);
		mem_write16(t44, d5 >> 16);
		t45 = t44 - 4u;
		mem_write16(t45 + 2u, d4);
		mem_write16(t45, d4 >> 16);
		t46 = t45 - 4u;
		mem_write16(t46 + 2u, d3);
		mem_write16(t46, d3 >> 16);
		t47 = t46 - 4u;
		mem_write16(t47 + 2u, d2);
		mem_write16(t47, d2 >> 16);
		t48 = t47 - 4u;
		mem_write16(t48 + 2u, d1);
		mem_write16(t48, d1 >> 16);
		t49 = t48 - 4u;
		mem_write16(t49 + 2u, a1);
		mem_write16(t49, a1 >> 16);
		t50 = t49 - 4u;
		mem_write16(t50 + 2u, d7);
		mem_write16(t50, d7 >> 16);
		t51 = t50 - 4u;
		mem_write16(t51 + 2u, d6);
		mem_write16(t51, d6 >> 16);
		t52 = t51 - 4u;
		mem_write16(t52 + 2u, d5);
		mem_write16(t52, d5 >> 16);
		t53 = t52 - 4u;
		mem_write16(t53 + 2u, d4);
		mem_write16(t53, d4 >> 16);
		t54 = t53 - 4u;
		mem_write16(t54 + 2u, d3);
		mem_write16(t54, d3 >> 16);
		t55 = t54 - 4u;
		mem_write16(t55 + 2u, d2);
		mem_write16(t55, d2 >> 16);
		t56 = t55 - 4u;
		mem_write16(t56 + 2u, d1);
		mem_write16(t56, d1 >> 16);
		t57 = t56 - 4u;
		mem_write16(t57 + 2u, a1);
		mem_write16(t57, a1 >> 16);
		t58 = t57 - 4u;
		mem_write16(t58 + 2u, d7);
		mem_write16(t58, d7 >> 16);
		t59 = t58 - 4u;
		mem_write16(t59 + 2u, d6);
		mem_write16(t59, d6 >> 16);
		t60 = t59 - 4u;
		mem_write16(t60 + 2u, d5);
		mem_write16(t60, d5 >> 16);
		t61 = t60 - 4u;
		mem_write16(t61 + 2u, d4);
		mem_write16(t61, d4 >> 16);
		t62 = t61 - 4u;
		mem_write16(t62 + 2u, d3);
		mem_write16(t62, d3 >> 16);
		t63 = t62 - 4u;
		mem_write16(t63 + 2u, d2);
		mem_write16(t63, d2 >> 16);
		t64 = t63 - 4u;
		mem_write16(t64 + 2u, d1);
		mem_write16(t64, d1 >> 16);
		a0 = t64;
		t65 = d0 - 1u;
		d0 = t65;
	} while (t65 != 0xFFFFu);
}

/* zeroes for the clearing of the work RAM */
void zero_fill_registers(uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_d3, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1)
{
	*p_d1 = 0u;
	*p_d2 = 0u;
	*p_d3 = 0u;
	*p_d4 = 0u;
	*p_d5 = 0u;
	*p_d6 = 0u;
	*p_d7 = 0u;
	*p_a1 = 0u;
}

/* the area's and the play's variables cleared */
void clear_area_variables(void)
{
	clear_area_counters();
	clear_enemy_variables();
	clear_spare_ram();
}

void unreached_00456A(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	clear_player_1();
	clear_player_2();
	clear_player_3();
	clear_player_4();
	a0 = 0x60200u;
	d0 = 0u;
	zero_ram_below(d0, a0);
	a0 = marker_times_ADDRESS;
	d0 = 0u;
	zero_ram_below(d0, a0);
}

/* the first player's record cleared */
void clear_player_1(void)
{
	uint32_t player = 0;

	player = PLAYER_ADDRESS(0);
	PLAYER(player)->lives = 0u;
	PLAYER(player)->unused_setting_copy = 0u;
	PLAYER(player)->score = 0u;
	PLAYER(player)->health_bars = 0u;
	PLAYER(player)->message = 0u;
}

/* the second player's record cleared */
void clear_player_2(void)
{
	uint32_t player = 0;

	player = PLAYER_ADDRESS(1);
	PLAYER(player)->lives = 0u;
	PLAYER(player)->unused_setting_copy = 0u;
	PLAYER(player)->score = 0u;
	PLAYER(player)->health_bars = 0u;
	PLAYER(player)->message = 0u;
}

/* the third player's record cleared */
void clear_player_3(void)
{
	uint32_t player = 0;

	player = PLAYER_ADDRESS(2);
	PLAYER(player)->lives = 0u;
	PLAYER(player)->unused_setting_copy = 0u;
	PLAYER(player)->score = 0u;
	PLAYER(player)->health_bars = 0u;
	PLAYER(player)->message = 0u;
}

/* the fourth player's record cleared */
void clear_player_4(void)
{
	PLAYER(PLAYER_ADDRESS(3))->lives = 0u;
	PLAYER(PLAYER_ADDRESS(3))->unused_setting_copy = 0u;
	PLAYER(PLAYER_ADDRESS(3))->score = 0u;
	PLAYER(PLAYER_ADDRESS(3))->health_bars = 0u;
	PLAYER(PLAYER_ADDRESS(3))->message = 0u;
}

/* the area's counters cleared */
void clear_area_counters(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = spawn_next_ADDRESS;
	d0 = 0u;
	zero_ram_below(d0, a0);
}

/* the spawns' and the enemies' variables cleared */
void clear_enemy_variables(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = hydrant_sprays_left_ADDRESS;
	d0 = 0u;
	zero_ram_below(d0, a0);
}

/* the engine's variables cleared */
void clear_engine_variables(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = draw_list_ADDRESS;
	d0 = 2u;
	zero_ram_below(d0, a0);
}

/* the engine's variables and the draw list cleared */
void clear_engine_ram(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = floor_map_ADDRESS;
	d0 = 7u;
	zero_ram_below(d0, a0);
}

/* a stretch of work RAM nothing uses cleared */
void clear_spare_ram(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = 0x63200u;
	d0 = 0u;
	zero_ram_below(d0, a0);
}

/* every object cleared */
void clear_objects(void)
{
	uint16_t d0 = 0;
	uint32_t a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, objects_end = 0;
	uint16_t t9 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	objects_end = PLAYER_SLOT_ADDRESS(0);
	d0 = 0x7Cu;
	zero_fill_registers(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = objects_end - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		objects_end = t8;
		t9 = d0 - 1u;
		d0 = t9;
	} while (t9 != 0xFFFFu);
}

/* the sprite chip's sprites cleared */
void clear_sprite_ram(void)
{
	uint16_t d0 = 0;
	uint32_t a0 = 0;

	a0 = 0x140800u;
	d0 = 3u;
	zero_ram_below(d0, a0);
}

void unreached_004620(uint16_t d0)
{
	uint16_t d0_2 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t25 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0;

	a0 = OBJECT_ADDRESS(0);
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 3u);
	zero_fill_registers(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		a0 = t24;
		t25 = d0_2 - 1u;
		d0_2 = t25;
	} while (t25 != 0xFFFFu);
}

void unreached_00462E(uint16_t d0)
{
	uint16_t d0_2 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t25 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0;

	a0 = OBJECT_ADDRESS(12);
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xBu);
	zero_fill_registers(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		a0 = t24;
		t25 = d0_2 - 1u;
		d0_2 = t25;
	} while (t25 != 0xFFFFu);
}

void unreached_00463C(uint16_t d0)
{
	uint16_t d0_2 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t25 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0;

	a0 = OBJECT_ADDRESS(24);
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 7u);
	zero_fill_registers(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		a0 = t24;
		t25 = d0_2 - 1u;
		d0_2 = t25;
	} while (t25 != 0xFFFFu);
}

void unreached_00464A(uint16_t d0)
{
	uint16_t d0_2 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t25 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0;

	a0 = OBJECT_ADDRESS(4);
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 7u);
	zero_fill_registers(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		a0 = t24;
		t25 = d0_2 - 1u;
		d0_2 = t25;
	} while (t25 != 0xFFFFu);
}

void unreached_004658(uint16_t d0)
{
	uint16_t d0_2 = 0;
	uint32_t a0 = 0, a1 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint16_t t25 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0;

	a0 = OBJECT_ADDRESS(32);
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 7u);
	zero_fill_registers(&d1, &d2, &d3, &d4, &d5, &d6, &d7, &a1);
	do
	{
		t1 = a0 - 4u;
		mem_write16(t1 + 2u, a1);
		mem_write16(t1, a1 >> 16);
		t2 = t1 - 4u;
		mem_write16(t2 + 2u, d7);
		mem_write16(t2, d7 >> 16);
		t3 = t2 - 4u;
		mem_write16(t3 + 2u, d6);
		mem_write16(t3, d6 >> 16);
		t4 = t3 - 4u;
		mem_write16(t4 + 2u, d5);
		mem_write16(t4, d5 >> 16);
		t5 = t4 - 4u;
		mem_write16(t5 + 2u, d4);
		mem_write16(t5, d4 >> 16);
		t6 = t5 - 4u;
		mem_write16(t6 + 2u, d3);
		mem_write16(t6, d3 >> 16);
		t7 = t6 - 4u;
		mem_write16(t7 + 2u, d2);
		mem_write16(t7, d2 >> 16);
		t8 = t7 - 4u;
		mem_write16(t8 + 2u, d1);
		mem_write16(t8, d1 >> 16);
		t9 = t8 - 4u;
		mem_write16(t9 + 2u, a1);
		mem_write16(t9, a1 >> 16);
		t10 = t9 - 4u;
		mem_write16(t10 + 2u, d7);
		mem_write16(t10, d7 >> 16);
		t11 = t10 - 4u;
		mem_write16(t11 + 2u, d6);
		mem_write16(t11, d6 >> 16);
		t12 = t11 - 4u;
		mem_write16(t12 + 2u, d5);
		mem_write16(t12, d5 >> 16);
		t13 = t12 - 4u;
		mem_write16(t13 + 2u, d4);
		mem_write16(t13, d4 >> 16);
		t14 = t13 - 4u;
		mem_write16(t14 + 2u, d3);
		mem_write16(t14, d3 >> 16);
		t15 = t14 - 4u;
		mem_write16(t15 + 2u, d2);
		mem_write16(t15, d2 >> 16);
		t16 = t15 - 4u;
		mem_write16(t16 + 2u, d1);
		mem_write16(t16, d1 >> 16);
		t17 = t16 - 4u;
		mem_write16(t17 + 2u, a1);
		mem_write16(t17, a1 >> 16);
		t18 = t17 - 4u;
		mem_write16(t18 + 2u, d7);
		mem_write16(t18, d7 >> 16);
		t19 = t18 - 4u;
		mem_write16(t19 + 2u, d6);
		mem_write16(t19, d6 >> 16);
		t20 = t19 - 4u;
		mem_write16(t20 + 2u, d5);
		mem_write16(t20, d5 >> 16);
		t21 = t20 - 4u;
		mem_write16(t21 + 2u, d4);
		mem_write16(t21, d4 >> 16);
		t22 = t21 - 4u;
		mem_write16(t22 + 2u, d3);
		mem_write16(t22, d3 >> 16);
		t23 = t22 - 4u;
		mem_write16(t23 + 2u, d2);
		mem_write16(t23, d2 >> 16);
		t24 = t23 - 4u;
		mem_write16(t24 + 2u, d1);
		mem_write16(t24, d1 >> 16);
		a0 = t24;
		t25 = d0_2 - 1u;
		d0_2 = t25;
	} while (t25 != 0xFFFFu);
}
