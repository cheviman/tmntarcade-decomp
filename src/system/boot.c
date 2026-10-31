/**
 *    Name:        system/boot.c
 *    Description: the reset, the RAM and ROM tests, and the main loop that runs the jobs the frames queue
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the board's start: the RAM and ROM check, the work RAM, the DIP switches, then the main loop that runs
   the queued jobs */
void reset(void)
{
	uint32_t negative = 0;
	uint8_t d0 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	uint16_t d0_2 = 0, d1_2 = 0, d2_3 = 0, d4_3 = 0, d6 = 0, d7_2 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a6 = 0, d0_3 = 0, d1_3 = 0, d2_2 = 0, d3_2 = 0, d4_2 = 0, d5 = 0, d6_2 = 0, d7 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t19 = 0, t20 = 0, t21 = 0;
	uint32_t t2 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0;

	write_status(0x2600u);
	take_interrupts();
	io_write8(IO_0A0011, 0u);
	io_write8(UNMAPPED_10E801, 0x13u);
	io_write8(IO_0A0001, 0u);
	io_write8(0x140000u, 0x10u);
	io_write8(TILES_106402, 0u);
	io_write8(TILES_106400, 0u);
	io_write8(TILES_106403, 0u);
	io_write8(TILES_106401, 0u);
	io_write8(TILES_106018, 0u);
	io_write8(TILES_106019, 0u);
	d1 = 0u;
	if ((io_read8(IO_0A0019) & 1u) == 0u)
	{
		d1 |= 1u;
		io_write8(0x140000u, 0x18u);
	}
	io_write8(TILES_106D00, d1);
	write_status(0x2500u);
	take_interrupts();
	d7 = 0u;
	a2 = 0x16C4u;
	a0 = PALETTE_RAM;
	d0_2 = 0u;
	d7 = test_palette_ram(d0_2, d7, a0, a2);
	a2 = 0x16C6u;
	a0 = TILE_RAM;
	d0_2 = 0x17u;
	d7 = test_ram(d0_2, d7, a0, a2);
	start_boot_screen();
	a2 = 0x16C8u;
	a0 = 0x60000u;
	d0_2 = 0xFu;
	d7 = test_ram(d0_2, d7, a0, a2);
	d0_2 = 0x1000u;
	do
	{
		t1 = d0_2 - 1u;
		d0_2 = t1;
	} while (t1 != 0xFFFFu);
	a2 = 0x16CAu;
	a0 = SPRITE_RAM;
	d0_2 = 0u;
	d7 = test_ram(d0_2, d7, a0, a2);
	sum_program_chips();
	a2 = sound_queue_write_ADDRESS;
	a3 = 0x16F8u;
	d0_2 = 3u;
	do
	{
		d6 = mem_read16(a2);
		t2 = a3;
		a2 += 2u;
		a3 += 2u;
		if (d6 != DATA16(t2))
			d7 = (d7 & ~0xFFFFu) | (uint16_t)(d7 + 1u);
		d7 = (d7 & ~0xFFFFu) | (uint16_t)(d7 << 1);
		t3 = d0_2 - 1u;
		d0_2 = t3;
	} while (t3 != 0xFFFFu);
	job_queue_write = d7;
	d7 = show_boot_check(d7);
	if (d7 != 0u)
	{
		a0 = sound_queue_write_ADDRESS;
		a1 = 0x16E8u;
		d0_2 = 3u;
		do
		{
			a4 = DATA32(a1);
			d4_3 = mem_read16(a0);
			a1 += 4u;
			a0 += 2u;
			print_boot_hex(d4_3, a4);
			t4 = d0_2 - 1u;
			d0_2 = t4;
		} while (t4 != 0xFFFFu);
	}
	d0_2 = 0x2Fu;
	if (d7 != 0u)
		d0_2 = 0x2Fu;
	do
	{
		d1_2 = 0x7FFFu;
		do
		{
			t5 = d1_2 - 1u;
			d1_2 = t5;
		} while (t5 != 0xFFFFu);
		io_write8(IO_0A0011, (uint8_t)d0_2);
		t6 = d0_2 - 1u;
		d0_2 = t6;
	} while (t6 != 0xFFFFu);
	if (d7 == 0u)
	{
		io_write8(0x140000u, 0x10u);
		io_write16(TILES_106B00, 0u);
		io_write16(TILES_106E00, 0u);
		clear_sprite_chip_registers();
		clear_sprite_ram();
		clear_objects();
		ignored = clear_tile_chip_registers();
		clear_tile_ram();
		a6 = 0xA01Eu;
		d7 = 1u;
		palette_second_half = 0u;
		palette_request_set(a6, &ignored_2, &ignored_3, &d7, &ignored_4);
		a6 = TILE_RAM;
		d0 = 0u;
		d1 = 0x2Cu;
		d2 = 0x2Du;
		d3 = 0x2Eu;
		d4 = 0x2Fu;
		d6 = 0xFu;
		do
		{
			d7_2 = 0x1Fu;
			do
			{
				io_write8(a6 + 0x80u, d0);
				io_write8(a6 + 0x81u, d1);
				io_write8(a6 + 0x82u, d0);
				io_write8(a6 + 0x83u, d2);
				io_write8(a6, d0);
				a6++;
				io_write8(a6, d3);
				a6++;
				io_write8(a6, d0);
				a6++;
				io_write8(a6, d4);
				t7 = d7_2 - 1u;
				d7_2 = t7;
				a6++;
			} while (t7 != 0xFFFFu);
			t8 = d6 - 1u;
			d6 = t8;
			a6 += 0x80u;
		} while (t8 != 0xFFFFu);
		io_write8(IO_0A0011, d0);
		d0_2 = 0x80u;
		do
		{
			d1_2 = 0x3000u;
			do
			{
				t9 = d1_2;
				d1_2 = (uint16_t)(t9 - 1u);
			} while (t9 != 1u);
			io_write8(IO_0A0011, (uint8_t)d0_2);
			t10 = d0_2 - 1u;
			d0_2 = t10;
		} while (t10 != 0xFFFFu);
		a0 = 0x64000u;
		d7_2 = 0x1FFu;
		zero_boot_fill_registers(&d1_3, &d2_2, &d3_2, &d4_2, &d5, &d6_2, &a1, &a2);
		do
		{
			t11 = a0 - 4u;
			mem_write16(t11 + 2u, a2);
			mem_write16(t11, a2 >> 16);
			t12 = t11 - 4u;
			mem_write16(t12 + 2u, a1);
			mem_write16(t12, a1 >> 16);
			t13 = t12 - 4u;
			mem_write16(t13 + 2u, d6_2);
			mem_write16(t13, d6_2 >> 16);
			t14 = t13 - 4u;
			mem_write16(t14 + 2u, d5);
			mem_write16(t14, d5 >> 16);
			t15 = t14 - 4u;
			mem_write16(t15 + 2u, d4_2);
			mem_write16(t15, d4_2 >> 16);
			t16 = t15 - 4u;
			mem_write16(t16 + 2u, d3_2);
			mem_write16(t16, d3_2 >> 16);
			t17 = t16 - 4u;
			mem_write16(t17 + 2u, d2_2);
			mem_write16(t17, d2_2 >> 16);
			t18 = t17 - 4u;
			mem_write16(t18 + 2u, d1_3);
			mem_write16(t18, d1_3 >> 16);
			a0 = t18;
			t19 = d7_2 - 1u;
			d7_2 = t19;
		} while (t19 != 0xFFFFu);
		io_write8(IO_0A0011, (uint8_t)d0_2);
		sound_queue_read = sound_queue_ADDRESS;
		sound_queue_write = sound_queue_ADDRESS;
		palette_queue_write = PALETTE_REQUEST_ADDRESS(0);
		palette_queue_read = PALETTE_REQUEST_ADDRESS(0);
		palette_area_banks = 0u;
		palette_set_banks = 0u;
		palette_black_banks = 0u;
		palette_second_half = 0u;
		palette_set = 0u;
		a0 = job_queue_ADDRESS;
		job_queue_read = job_queue_ADDRESS;
		job_queue_write = job_queue_ADDRESS;
		d0_3 = 0xFFFFFFFFu;
		d1_2 = 0x1Fu;
		do
		{
			mem_write32(a0, d0_3);
			t20 = d1_2 - 1u;
			d1_2 = t20;
			a0 += 4u;
		} while (t20 != 0xFFFFu);
		reset_ranking();
		dip_switches_1 = ~io_read8(IO_0A0011);
		dip_switches_2 = ~io_read8(IO_0A0013);
		dip_switches_3 = ~io_read8(IO_0A0019);
		d0 = 0u;
		d1_2 = dip_switches_1;
		d2_3 = (uint16_t)d1_2;
		d1_2 = d1_2 & 0xFu;
		free_play = d0;
		d1_2 = (uint16_t)((uint32_t)d1_2 << 1);
		COIN_SLOT(COIN_SLOT_ADDRESS(0))->coins_per_credit = rom_001452[d1_2];
		COIN_SLOT(COIN_SLOT_ADDRESS(0))->credits_per_coins = rom_001453[d1_2];
		d2_3 = (d2_3 & ~0xFu) >> 3;
		COIN_SLOT(COIN_SLOT_ADDRESS(1))->coins_per_credit = rom_001472[d2_3];
		COIN_SLOT(COIN_SLOT_ADDRESS(1))->credits_per_coins = rom_001473[d2_3];
		d0_2 = dip_switches_2;
		lives_per_credit = rom_001426[d0_2 & 3u];
		d0_2 = 0u;
		if ((dip_switches_2 & 4u) == 0u)
			d0_2 = (uint8_t)(d0_2 + 1u);
		unused_dip_flag = (uint8_t)d0_2;
		version = 0u;
		d0_2 = dip_switches_2;
		d0_2 = d0_2 & 0x18u;
		a0 = 0x142Au + (uint16_t)(d0_2 + (d0_2 >> 2));
		unused_dip_setting_flag = (uint8_t)DATA16(a0);
		a0 += 2u;
		unused_dip_setting_value = DATA32(a0);
		AT32(unused_dip_setting, -2) = mem_read32(a0 + 4u);
		difficulty_setting = (dip_switches_2 & 0x60u) >> 5;
		demo_sounds = dip_switches_2 & 0x80u;
		d0 = 4u;
		if ((dip_switches_3 & 8u) != 0u)
			d0 = 6u;
		unused_dip_number = d0;
		board_control = 0u;
		io_write8(IO_0A0009, 0u);
		io_write8(IO_0A0001, 8u);
		d1 = 0u;
		d2 = 0u;
		if ((dip_switches_3 & 1u) != 0u)
		{
			d1 |= 7u;
			d2 |= 8u;
		}
		layer_priority = d1;
		io_write8(PRIORITY_0C0001, d1);
		sprite_control = d2;
		io_write8(0x140000u, d2);
		write_status(0u);
		take_interrupts();
		board_control |= 0x20u;
		io_write8(IO_0A0001, board_control);
		for (;;)
		{
			animate_fire_tiles(&d5, &d6_2);
			a0 = job_queue_read;
			frame_wait();
			t21 = mem_read16(a0);
			negative = t21 >> 15;
			d1_2 = t21;
			take_interrupts();
			if (negative)
				continue;
			d7 = (uint8_t)d1_2;
			d1_2 = (d1_2 & 0x3F00u) >> 6;
			mem_write16(a0, 0xFFFFu);
			a0 += 2u;
			if (a0 > job_queue_ADDRESS + 0x7Fu)
				a0 = job_queue_ADDRESS;
			job_queue_read = a0;
			switch (d1_2)
			{
			case 0:
				clear_layers_job((uint8_t)d7);
				break;
			case 4:
				print_game_text((uint16_t)d7);
				break;
			case 8:
				set_text_colour((uint16_t)d7);
				break;
			case 12:
				set_spare_text_colour((uint16_t)d7);
				break;
			case 16:
				d4_2 = add_point(d4_2, d7);
				break;
			case 20:
				clear_scores((uint8_t)d7);
				break;
			case 24:
				draw_score_labels((uint8_t)d7);
				break;
			case 28:
				func_001E40();
				break;
			case 32:
				func_0022FE();
				break;
			case 36:
				d4_2 = draw_tile_picture((uint16_t)d7);
				break;
			case 40:
				func_002334();
				break;
			case 44:
				draw_player_boxes(d7, &ignored_5, &d4_2, &d5, &d6_2);
				break;
			case 48:
				print_stage_title();
				break;
			case 52:
				draw_player_message(&d4_2, &d5, &d6_2, &d7);
				break;
			case 56:
				print_demo_text((uint16_t)d7);
				break;
			case 60:
				print_tall_text((uint8_t)d7, &d4_2, &d6_2);
				break;
			case 64:
				print_test_text((uint16_t)d7);
				break;
			case 68:
				d5 = sum_mask_roms(d4_2, d5, d6_2, d7);
				break;
			}
		}
	}
	for (;;)
	{
	}
}

/* the sprite chip's registers cleared */
void clear_sprite_chip_registers(void)
{
	io_write8(SPRITE_CONTROL_140001, 0u);
	io_write8(SPRITE_CONTROL_140003, 0u);
	io_write8(SPRITE_CONTROL_140002, 0u);
}

/* the tile chip's registers cleared */
uint32_t clear_tile_chip_registers(void)
{
	uint32_t d7 = 0;

	d7 = 0u;
	io_write8(TILES_106900, 0u);
	io_write8(TILES_106B00, 0u);
	io_write8(TILES_106E00, 0u);
	io_write8(TILES_106C00, 0u);
	return d7;
}

/* the three tile layers blank and their scroll at 0 */
void clear_tile_ram(void)
{
	uint8_t d0 = 0, d1 = 0;
	uint16_t d7 = 0;
	uint32_t a0 = 0;
	uint16_t t1 = 0, t2 = 0;

	d0 = 0u;
	d1 = 0x10u;
	a0 = TILE_RAM;
	d7 = 0x7FFu;
	do
	{
		io_write8(a0, d0);
		a0++;
		io_write8(a0, d1);
		t1 = d7 - 1u;
		d7 = t1;
		a0++;
	} while (t1 != 0xFFFFu);
	io_write8(IO_0A0011, d0);
	a0 = TILE_RAM + 0x2000u;
	d7 = 0x1FFFu;
	do
	{
		io_write8(a0, d0);
		a0++;
		io_write8(a0, d1);
		t2 = d7 - 1u;
		d7 = t2;
		a0++;
	} while (t2 != 0xFFFFu);
	io_write8(TILES_106402, 0u);
	io_write8(TILES_106400, 0u);
	io_write8(TILES_106403, 0u);
	io_write8(TILES_106401, 0u);
	io_write8(TILES_106018, 0u);
	io_write8(TILES_106019, 0u);
	io_write8(IO_0A0011, 0u);
}

/* zeroes for the boot's clearing of the work RAM */
void zero_boot_fill_registers(uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_d3, uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_a1, uint32_t *p_a2)
{
	*p_d1 = 0u;
	*p_d2 = 0u;
	*p_d3 = 0u;
	*p_d4 = 0u;
	*p_d5 = 0u;
	*p_d6 = 0u;
	*p_a1 = 0u;
	*p_a2 = 0u;
}

/* the boot's screen: a palette, the fixed layer blank and "RAM ROM CHECK" */
void start_boot_screen(void)
{
	uint8_t d3 = 0, d6 = 0;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a1 = 0, a6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	a6 = PALETTE_RAM;
	d0 = 0xFu;
	do
	{
		a1 = table_loaded_by_lea_00191E_ADDRESS;
		d1 = 0xFu;
		do
		{
			io_write8(a6 + 1u, DATA8(a1));
			a1++;
			io_write8(a6 + 3u, DATA8(a1));
			a6 += 4u;
			t1 = d1 - 1u;
			d1 = t1;
			a1++;
		} while (t1 != 0xFFFFu);
		t2 = d0 - 1u;
		d0 = t2;
	} while (t2 != 0xFFFFu);
	a6 = PALETTE_RAM + 0x400u;
	d0 = 0x1FFu;
	d6 = 0u;
	do
	{
		io_write8(a6 + 1u, d6);
		io_write8(a6 + 3u, d6);
		a6 += 4u;
		t3 = d0 - 1u;
		d0 = t3;
	} while (t3 != 0xFFFFu);
	io_write8(IO_0A0011, (uint8_t)d0);
	a6 = TILE_RAM;
	d0 = 0x3FFu;
	do
	{
		io_write8(a6, 0u);
		a6++;
		io_write8(a6, 0x10u);
		a6++;
		io_write8(a6, 0u);
		a6++;
		io_write8(a6, 0x10u);
		t4 = d0 - 1u;
		d0 = t4;
		a6++;
	} while (t4 != 0xFFFFu);
	d3 = 0u;
	print_boot_text(d3);
}

/* a number as four hexadecimal digits, for a bad program chip's sum */
void print_boot_hex(uint16_t d4, uint32_t a4)
{
	uint16_t d5 = 0, d6 = 0;
	uint16_t t1 = 0;

	d5 = 3u;
	do
	{
		d6 = d4 & 0xFu;
		if (d6 >= 0xAu)
			d6 += 7u;
		a4--;
		mem_write8(a4, (uint8_t)d6);
		a4--;
		mem_write8(a4, 0u);
		d4 = d4 >> 4;
		t1 = d5 - 1u;
		d5 = t1;
	} while (t1 != 0xFFFFu);
}

/* a RAM written and read back with four patterns, its bad chips marked */
uint32_t test_ram(uint16_t d0, uint32_t d7, uint32_t a0, uint32_t a2)
{
	uint8_t d1 = 0;
	uint16_t d2 = 0, d3 = 0;
	uint32_t a1 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0, t4 = 0;

	d7 = d7 << 2;
	d1 = 0u;
	for (;;)
	{
		a1 = a0;
		d2 = (uint16_t)d0;
		do
		{
			d3 = 0x1FFu;
			do
			{
				mem_write8(a1, d1);
				t1 = mem_read8(a1);
				(void)t1;
				if (t1 != d1)
					d7 = d7 | mem_read8(a2);
				mem_write8(a1 + 1u, d1);
				t2 = mem_read8(a1 + 1u);
				(void)t2;
				if (t2 != d1)
					d7 = d7 | mem_read8(a2 + 1u);
				t3 = d3 - 1u;
				d3 = t3;
				a1 += 2u;
			} while (t3 != 0xFFFFu);
			io_write8(IO_0A0011, (uint8_t)d0);
			t4 = d2 - 1u;
			d2 = t4;
		} while (t4 != 0xFFFFu);
		if (d1 == 0xFFu)
			break;
		d1 += 0x55u;
	}
	return d7;
}

/* the palette RAM written and read back with four patterns */
uint32_t test_palette_ram(uint16_t d0, uint32_t d7, uint32_t a0, uint32_t a2)
{
	uint16_t d2 = 0, d3 = 0;
	uint32_t a1 = 0, d1 = 0;
	uint16_t t1 = 0, t2 = 0;

	d7 = d7 << 2;
	d1 = 0u;
	for (;;)
	{
		a1 = a0;
		d2 = (uint16_t)d0;
		do
		{
			d3 = 0x3FFu;
			do
			{
				io_write8(a1 + 1u, d1);
				if (io_read8(a1 + 1u) != (uint8_t)d1)
					d7 = d7 | mem_read8(a2);
				io_write8(a1 + 3u, d1);
				if (io_read8(a1 + 3u) != (uint8_t)d1)
					d7 = d7 | mem_read8(a2 + 1u);
				a1 += 4u;
				t1 = d3 - 1u;
				d3 = t1;
			} while (t1 != 0xFFFFu);
			io_write8(IO_0A0011, (uint8_t)d0);
			t2 = d2 - 1u;
			d2 = t2;
		} while (t2 != 0xFFFFu);
		if (d1 == 0xFFu)
			break;
		d1 += 0x55u;
	}
	return d7;
}

void BOARD_ORIGINAL(sum_program_chips)(void)
{
	uint16_t d0 = 0, d2 = 0, d5 = 0, d6_2 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, d6 = 0;
	uint16_t t2 = 0, t3 = 0;
	uint32_t t1 = 0;

	a2 = sound_queue_write_ADDRESS;
	a0 = 0x16CCu;
	for (;;)
	{
		t1 = DATA32(a0);
		d6 = t1;
		a0 += 4u;
		if ((int32_t)t1 < 0)
			break;
		a1 = d6;
		d0 = (uint16_t)(DATA16(a0) - 1u);
		d6_2 = 0u;
		d5 = 0u;
		a0 += 2u;
		do
		{
			d2 = 0xFFFu;
			for (;;)
			{
				d5 = mem_read8(a1);
				if (d5 != mem_read8(a1))
					continue;
				d6_2 += d5;
				a1 += 2u;
				t2 = d2 - 1u;
				d2 = t2;
				if (t2 == 0xFFFFu)
					break;
			}
			io_write8(IO_0A0011, (uint8_t)d0);
			t3 = d0 - 1u;
			d0 = t3;
		} while (t3 != 0xFFFFu);
		mem_write16(a2, d6_2);
		a2 += 2u;
	}
}

/* the check's results: each chip OK or BAD */
uint32_t show_boot_check(uint32_t d7)
{
	uint32_t carry = 0;
	uint8_t d3 = 0;
	uint16_t d0 = 0, d5 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint16_t t1 = 0, t2 = 0;

	a6 = TILE_RAM;
	d0 = 0x3FFu;
	do
	{
		io_write8(a6, 0u);
		a6++;
		io_write8(a6, 0x10u);
		a6++;
		io_write8(a6, 0u);
		a6++;
		io_write8(a6, 0x10u);
		t1 = d0 - 1u;
		d0 = t1;
		a6++;
	} while (t1 != 0xFFFFu);
	d3 = 1u;
	print_boot_text(d3);
	d5 = 0xBu;
	d3 = 2u;
	d7 = d7 >> 1;
	d6 = d7;
	do
	{
		carry = d6 & 1u;
		d6 = d6 >> 1;
		if (carry)
			print_boot_text(d3);
		d3++;
		t2 = d5 - 1u;
		d5 = t2;
	} while (t2 != 0xFFFFu);
	return d7;
}

/* a text of the boot's screen */
void print_boot_text(uint8_t d3)
{
	uint8_t d4 = 0;
	uint32_t a5 = 0, a6 = 0;

	a5 = indexed_table_of_32_bit_values_0015AC[d3 & 0x7Fu];
	for (;;)
	{
		a6 = TILE_RAM + 0x18u + (int16_t)mem_read16(a5);
		a5 += 2u;
		for (;;)
		{
			d4 = mem_read8(a5);
			a5++;
			if (d4 == 0x3Fu)
				return;
			if (d4 == 0x2Fu)
				break;
			mem_write8(a6, 0u);
			a6++;
			mem_write8(a6, (uint8_t)(d4 - 0x30u));
			a6++;
		}
	}
}
