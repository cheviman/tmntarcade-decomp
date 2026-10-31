/**
 *    Name:        video/speech_balloons.c
 *    Description: the speech balloons in the fixed layer with their speeches, and the lines said with them
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the pointer of a narrow balloon on the left of its speaker */
uint32_t draw_balloon_pointer(uint32_t a6)
{
	uint32_t a6_2 = 0;

	if (balloon_on_right != 0u)
		return a6;
	if (game_on == 0u)
		return a6;
	a6_2 = balloon_place;
	io_write8(a6_2 + 0x188u, 0xBFu);
	io_write8(a6_2 + 0x18Au, 0xBFu);
	io_write8(a6_2 + 0x184u, 0xBFu);
	io_write8(a6_2 + 0x186u, 0xBFu);
	io_write8(a6_2 + 0x189u, 0xEEu);
	io_write8(a6_2 + 0x18Bu, 0xEFu);
	io_write8(a6_2 + 0x185u, 0xFEu);
	io_write8(a6_2 + 0x187u, 0xFFu);
	return a6_2;
}

/* the balloon and speech "We gotta save Splinter" */
uint32_t say_we_gotta_save_splinter(uint32_t d0, uint32_t d1, uint16_t d2)
{
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	d3 = 5u;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
	draw_balloon_pointer(ignored_5);
	return d0;
}

/* the balloon and speech "Let's move it" */
uint32_t say_lets_move_it(uint32_t d0, uint32_t d1, uint16_t d2)
{
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	d3 = 0xAu;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
	draw_balloon_pointer(ignored_5);
	return d1;
}

/* the balloon and speech "You're dead, shell-brain", counted among the lines said */
void say_youre_dead_shell_brain(uint32_t d1, uint16_t d2, uint32_t *p_d0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	bebop_exchange_lines++;
	d3 = 0x14u;
	show_balloon_beside(d2, d3, p_d0, &d1, &ignored, &d5, &ignored_2, p_d7, p_a6);
	*p_a6 = draw_balloon_pointer(*p_a6);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the balloon and speech "Tonight I dine on turtle soup" */
void say_turtle_soup(uint32_t d1, uint16_t d2, uint32_t *p_d0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d3 = 0x19u;
	show_balloon_beside(d2, d3, p_d0, &d1, &ignored, &d5, &ignored_2, p_d7, &ignored_3);
	draw_balloon_pointer(ignored_3);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the balloon and speech "I'm invincible!" */
void say_im_invincible(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d3 = 0x1Eu;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &d5, &ignored_2, p_d7, &ignored_3);
	draw_balloon_pointer(ignored_3);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the balloon and speech "Crash the turtles!" */
void say_crash_the_turtles(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d3 = 0x23u;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &d5, &ignored_2, p_d7, &ignored_3);
	draw_balloon_pointer(ignored_3);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the balloon and speech "Do not resist us" */
void say_do_not_resist_us(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d3 = 0x28u;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &d5, &ignored_2, p_d7, &ignored_3);
	draw_balloon_pointer(ignored_3);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the balloon and speech "Help meeee...!" */
void say_help_me(uint16_t d2, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0;

	d3 = 0x2Du;
	show_balloon_beside(d2, d3, p_d0, p_d1, &ignored, &d5, &d6, p_d7, &ignored_2);
	draw_balloon_pointer(ignored_2);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the balloon and speech "Attaaaack!" */
void say_attack(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d3 = 0x32u;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &d5, &ignored_2, p_d7, &ignored_3);
	draw_balloon_pointer(ignored_3);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the balloon and speech "Pizza time!" above the speaker's height */
void say_pizza_time(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(d2 + OBJECT(a0)->height_whole));
	d3 = 0x46u;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &d5, &ignored_2, p_d7, &ignored_3);
	draw_balloon_pointer(ignored_3);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void unreached_030062(uint32_t d0, uint32_t d1, uint16_t d2)
{
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	d3 = 0x4Bu;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
	draw_balloon_pointer(ignored_5);
}

void unreached_03006C(uint32_t d0, uint32_t d1, uint16_t d2)
{
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;

	d3 = 0x50u;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &ignored_2, &ignored_3, &ignored_4, &ignored_5);
	draw_balloon_pointer(ignored_5);
}

/* the balloon and speech "Shell Shock" above the speaker's height */
void say_shell_shock(uint32_t d0, uint16_t d2, uint32_t a0, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d3 = 0;
	uint32_t ignored = 0;

	d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(d2 + OBJECT(a0)->height_whole));
	d3 = 0x55u;
	show_balloon_beside(d2, d3, &d0, p_d1, p_d4, &d5, &d6, p_d7, &ignored);
	draw_balloon_pointer(ignored);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the balloon and speech "Yippee-I-Ay!" */
void say_yippee_i_ay(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0;

	d3 = 0x5Au;
	show_balloon_beside(d2, d3, &d0, &d1, &ignored, &d5, &ignored_2, p_d7, &ignored_3);
	draw_balloon_pointer(ignored_3);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the wide balloon and speech "Say your prayers, toitles" */
void say_your_prayers_toitles(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t d4 = 0, ignored = 0, ignored_2 = 0;

	d3 = 0x5Fu;
	d4 = 0x20u;
	show_balloon(d2, d3, &d0, &d1, &d4, &d5, &ignored, p_d7, &ignored_2);
	draw_wide_balloon_pointer(ignored_2);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the wide balloon and speech "They ain't getting any prettier!" */
void say_they_aint_getting_prettier(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t d4 = 0, ignored = 0, ignored_2 = 0;

	bebop_exchange_lines++;
	d4 = 0xFFFFFFD0u;
	d1 = (uint16_t)(d1 - 0x30u);
	d3 = 0x69u;
	show_balloon(d2, d3, &d0, &d1, &d4, &d5, &ignored, p_d7, &ignored_2);
	draw_wide_balloon_pointer(ignored_2);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the wide balloon and speech "Watch your mouth, slime ball!" */
void say_watch_your_mouth(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t d4 = 0, ignored = 0;

	bebop_exchange_lines++;
	d4 = 0xFFFFFFD0u;
	d1 = (uint16_t)(d1 - 0x30u);
	d3 = 0x6Eu;
	show_balloon(d2, d3, &d0, &d1, &d4, &d5, &ignored, p_d7, p_a6);
	*p_a6 = draw_wide_balloon_pointer(*p_a6);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the wide balloon and speech "Oh no, it's that overgrown cork-screw again" */
void say_overgrown_cork_screw(uint32_t d0, uint32_t d1, uint16_t d2, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d3 = 0;
	uint32_t a6 = 0, d4 = 0, ignored = 0, ignored_2 = 0;

	d4 = 0xFFFFFFD0u;
	d3 = 0x73u;
	show_balloon(d2, d3, &d0, &d1, &d4, &d5, &ignored, p_d7, &ignored_2);
	if (game_on != 0u)
	{
		a6 = balloon_place;
		io_write8(a6 + 0x198u, 0xBFu);
		io_write8(a6 + 0x19Au, 0xBFu);
		io_write8(a6 + 0x18Eu, 0xBFu);
		io_write8(a6 + 0x190u, 0xBFu);
		io_write8(a6 + 0x199u, 0xEEu);
		io_write8(a6 + 0x19Bu, 0xEFu);
		io_write8(a6 + 0x18Fu, 0xFEu);
		io_write8(a6 + 0x191u, 0xFFu);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the wide balloon's pointer drawn into its bottom row */
uint32_t draw_wide_balloon_pointer(uint32_t a6)
{
	uint32_t a6_2 = 0;

	if (game_on == 0u)
		return a6;
	a6_2 = balloon_place;
	io_write8(a6_2 + 0x190u, 0xBFu);
	io_write8(a6_2 + 0x192u, 0xBFu);
	io_write8(a6_2 + 0x18Au, 0xBFu);
	io_write8(a6_2 + 0x18Cu, 0xBFu);
	io_write8(a6_2 + 0x191u, 0xEEu);
	io_write8(a6_2 + 0x193u, 0xEFu);
	io_write8(a6_2 + 0x18Bu, 0xFEu);
	io_write8(a6_2 + 0x18Du, 0xFFu);
	return a6_2;
}

/* a narrow balloon to one side of the speaker */
void show_balloon_beside(uint16_t d2, uint16_t d3, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	balloon_on_right = *p_d0;
	if ((uint8_t)*p_d0 != 0u)
		d1 = (d1 & ~0xFFFFu) | (uint16_t)(d1 + 0x20u);
	else
		d1 = (d1 & ~0xFFFFu) | (uint16_t)(d1 - 0x20u);
	*p_d4 = 0x20u;
	show_balloon(d2, d3, p_d0, &d1, p_d4, &d5, &d6, p_d7, p_a6);
	*p_d1 = d1;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* a speech balloon on the screen by the speaker, with its speech and the time it stays */
void show_balloon(uint16_t d2, uint16_t d3, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d0 = *p_d0;
	uint32_t d1 = *p_d1;
	uint32_t d4 = *p_d4;
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint8_t d2_2 = 0, d3_2 = 0, d5_2 = 0;
	uint16_t d4_2 = 0, d6_2 = 0;
	uint32_t d7 = 0, ignored = 0, ignored_2 = 0;

	if (game_on != 0u)
	{
		if (balloon_time != 0u)
		{
			scratch_word = d0;
			balloon_kept_y = d2;
			balloon_kept_line = d3;
			balloon_kept_bank = d4;
			erase_balloon(&ignored, &ignored_2, p_d7);
			d0 = (d0 & ~0xFFFFu) | scratch_word;
			d2 = balloon_kept_y;
			d3 = balloon_kept_line;
			d4 = balloon_kept_bank;
		}
		d5_2 = (uint8_t)((tile_banks_2_3 & 0xFu) | d4);
		tile_banks_2_3 = d5_2;
		io_write8(TILES_106E00, d5_2);
		balloons_said++;
		time_since_balloon = 0u;
		d7 = (*p_d7 & ~0xFFu) | TABLE8(indexed_table_of_8_bit_values_030350, (uint32_t)(int16_t)d3);
		d4_2 = (uint16_t)((d4 & ~0xFFu) | mem_read8(0x30352u + (int16_t)d3));
		d6_2 = mem_read8(0x30353u + (int16_t)d3);
		balloon_time = mem_read8(0x30354u + (int16_t)d3);
		d3_2 = mem_read8(0x30351u + (int16_t)d3);
		queue_sound((uint8_t)d7, *p_a6);
		if ((uint8_t)d0 != 0u)
		{
			if ((uint16_t)d1 >= 0xB0u)
				d1 = ((d1 - 0x50u) & 0x1F8u) >> 2;
			else
				d1 = 0x18u;
		}
		else if ((uint16_t)d1 < 0x130u)
			d1 = ((d1 + 0x10u) & 0x1F8u) >> 2;
		else
			d1 = 0x50u;
		if ((uint16_t)d2 < 0x70u)
			d2 = (uint16_t)(((0u - d2 - 0x50u) & 0xF8u) << 4);
		else
			d2 = 0x400u;
		d1 = (uint16_t)(d1 + d2) + 0x100000u;
		*p_a6 = d1;
		balloon_place = d1;
		*p_d7 = (d7 & ~0xFFFFu) | d6_2;
		d0 &= ~0xFFu;
		d2_2 = (uint8_t)d4_2;
		d4 = (d4_2 & ~0xFFu) | d3_2;
		d6 = d3_2;
		d4 = (d4 & ~0xFFu) | (uint8_t)(d4 + 0x10u);
		d5 = (uint8_t)(d3_2 + 0x20u);
		d6 = (uint8_t)(d6 + 0x30u);
		draw_balloon_rows((uint8_t)d0, d2_2, d3_2, &d4, &d5, &d6, p_d7, p_a6);
	}
	*p_d0 = d0;
	*p_d1 = d1;
	*p_d4 = (*p_d4 & 0xFFFF0000u) | (d4 & 0xFFFFu);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

/* the speech balloon erased */
void erase_balloon(uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t d0 = 0, d2 = 0, d3 = 0;
	uint32_t a6 = 0, d4 = 0, d5 = 0, d6 = 0;

	a6 = balloon_place;
	d0 = 0xFFu;
	*p_d7 = 0xFu;
	d2 = 0u;
	d3 = 0x10u;
	d4 = 0x10u;
	d5 = 0x10u;
	d6 = 0x10u;
	draw_balloon_rows(d0, d2, d3, &d4, &d5, &d6, p_d7, &a6);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFFFF00u) | (d6 & 0xFFu);
}

/* the four rows of a balloon's tiles drawn across */
void draw_balloon_rows(uint8_t d0, uint8_t d2, uint8_t d3, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a6)
{
	uint8_t d4 = (uint8_t)*p_d4;
	uint8_t d5 = (uint8_t)*p_d5;
	uint8_t d6 = (uint8_t)*p_d6;
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t a6 = *p_a6;
	uint16_t t1 = 0;

	do
	{
		io_write8(a6 + 0x80u, d2);
		io_write8(a6 + 0x100u, d2);
		io_write8(a6 + 0x180u, d2);
		io_write8(a6, d2);
		a6++;
		io_write8(a6 + 0x80u, d4);
		io_write8(a6 + 0x100u, d5);
		io_write8(a6 + 0x180u, d6);
		io_write8(a6, d3);
		a6++;
		if ((int8_t)d0 >= 0)
		{
			d3++;
			d4++;
			d5++;
			d6++;
		}
		t1 = d7 - 1u;
		d7 = t1;
	} while (t1 != 0xFFFFu);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | d4;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
	*p_d6 = (*p_d6 & 0xFFFFFF00u) | d6;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
	*p_a6 = a6;
}
