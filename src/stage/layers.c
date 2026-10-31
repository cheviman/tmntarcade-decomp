/**
 *    Name:        stage/layers.c
 *    Description: the areas' layers: their maps of blocks drawn as the scroll goes on
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* a whole layer drawn from its map, and its floor cells into the floor map */
void draw_whole_layer_and_floor(uint32_t a0)
{
	uint8_t d1 = 0, d5 = 0, d6 = 0, d7 = 0;
	uint32_t a1 = 0, a2 = 0, a3 = 0, a4 = 0, d0 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d0 = LAYER(WORKING_LAYER)->x_page;
	d0 = (uint8_t)(d0 << 4);
	a2 = LAYER(WORKING_LAYER)->map + (uint16_t)(d0 + (((uint32_t)LAYER(WORKING_LAYER)->y_page << 3) * LAYER(WORKING_LAYER)->map_width - LAYER(WORKING_LAYER)->map_width));
	a1 = floor_map_ADDRESS;
	d7 = 8u;
	do
	{
		d6 = 0x10u;
		a3 = a2;
		do
		{
			a4 = LAYER(WORKING_LAYER)->blocks + DATA16(a3);
			d5 = 4u;
			d1 = DATA8(a4);
			a3 += 2u;
			do
			{
				io_write8(a0, d1);
				io_write8(a0 + 2u, d1);
				io_write8(a0 + 4u, d1);
				io_write8(a0 + 6u, d1);
				mem_write8(a1, DATA8(a4 + 1u));
				mem_write8(a1 + 1u, DATA8(a4 + 2u));
				mem_write8(a1 + 2u, DATA8(a4 + 3u));
				mem_write8(a1 + 3u, DATA8(a4 + 4u));
				io_write8(a0 + 1u, DATA8(a4 + 0x11u));
				io_write8(a0 + 3u, DATA8(a4 + 0x12u));
				io_write8(a0 + 5u, DATA8(a4 + 0x13u));
				io_write8(a0 + 7u, DATA8(a4 + 0x14u));
				a4 += 4u;
				t1 = d5;
				d5 = (uint8_t)(t1 - 1u);
				a0 += 0x80u;
				a1 += 0x40u;
			} while (t1 != 1u);
			t2 = d6;
			d6 = (uint8_t)(t2 - 1u);
			a0 -= 0x1F8u;
			a1 -= 0xFCu;
		} while (t2 != 1u);
		a2 -= LAYER(WORKING_LAYER)->map_width;
		t3 = d7;
		d7 = (uint8_t)(t3 - 1u);
		a0 += 0x180u;
		a1 += 0xC0u;
	} while (t3 != 1u);
}

/* a whole layer drawn from its map */
uint32_t draw_whole_layer(uint32_t a0)
{
	uint8_t d5 = 0, d6 = 0, d7 = 0;
	uint32_t a2 = 0, a3 = 0, a4 = 0, d0 = 0, d1 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	d0 = LAYER(WORKING_LAYER)->x_page;
	d0 = (uint8_t)(d0 << 4);
	d1 = (uint32_t)(uint16_t)((uint32_t)LAYER(WORKING_LAYER)->y_page << 3) * LAYER(WORKING_LAYER)->map_width;
	d1 = (d1 & ~0xFFFFu) | (uint16_t)(d1 - LAYER(WORKING_LAYER)->map_width);
	a2 = LAYER(WORKING_LAYER)->map + (uint16_t)(d0 + d1);
	d7 = 8u;
	do
	{
		d6 = 0x10u;
		a3 = a2;
		do
		{
			a4 = LAYER(WORKING_LAYER)->blocks + DATA16(a3);
			d5 = 4u;
			d1 = (d1 & ~0xFFu) | DATA8(a4);
			a3 += 2u;
			do
			{
				io_write8(a0, d1);
				io_write8(a0 + 2u, d1);
				io_write8(a0 + 4u, d1);
				io_write8(a0 + 6u, d1);
				io_write8(a0 + 1u, DATA8(a4 + 1u));
				io_write8(a0 + 3u, DATA8(a4 + 2u));
				io_write8(a0 + 5u, DATA8(a4 + 3u));
				io_write8(a0 + 7u, DATA8(a4 + 4u));
				t1 = d5;
				d5 = (uint8_t)(t1 - 1u);
				a0 += 0x80u;
				a4 += 4u;
			} while (t1 != 1u);
			t2 = d6;
			d6 = (uint8_t)(t2 - 1u);
			a0 -= 0x1F8u;
		} while (t2 != 1u);
		a2 -= LAYER(WORKING_LAYER)->map_width;
		t3 = d7;
		d7 = (uint8_t)(t3 - 1u);
		a0 += 0x180u;
	} while (t3 != 1u);
	return d1;
}

/* the area's layers from its record: the floor map, the first scroll segment and the layers drawn */
void start_area_layers(void)
{
	uint16_t d0 = 0;

	scroll_segment = 0u;
	LAYER(LAYER_A)->column_phase = 0u;
	LAYER(LAYER_B)->column_phase = 0u;
	LAYER(LAYER_A)->row_phase = 0u;
	LAYER(LAYER_B)->row_phase = 0u;
	apartment_fire_spot = 0u;
	apartment_fire_frame = 0u;
	building_fire_spot = 0u;
	building_fire_frame = 0u;
	AT16(layer_loops, -1) = 0u;
	layers_step = 0u;
	AT32(last_segment, -3) = 0u;
	fire_last_frame = 0u;
	hurry_time = 0u;
	balloon_time = 0u;
	time_since_balloon = 0u;
	balloons_said = 0u;
	floor_end_walled = 0u;
	drill_arrival = 0;
	drill_arrival_step = 0u;
	drill_rumbling = 0u;
	unk_061114 = 0u;
	unk_06110A = 0u;
	unk_06110C = 0u;
	unk_061116 = 0u;
	unk_0633F0 = 0u;
	tv_time = 0u;
	bebop_exchange_lines = 0u;
	prompt_shown(0) = 0u;
	prompt_shown(1) = 0u;
	prompt_shown(2) = 0u;
	prompt_shown(3) = 0u;
	d0 = (uint16_t)((uint32_t)stage << 2);
	d0 += (uint32_t)d0 << 3;
	LAYER(LAYER_A)->x = area_layers[d0 / 4u];
	LAYER(LAYER_A)->y = rom_01E5A4[d0 / 4u];
	LAYER(LAYER_B)->x = rom_01E5A8[d0 / 4u];
	LAYER(LAYER_B)->y = rom_01E5AC[d0 / 4u];
	LAYER(LAYER_A)->map = rom_01E5B0[d0 / 4u];
	LAYER(LAYER_A)->blocks = rom_01E5B4[d0 / 4u];
	LAYER(LAYER_B)->map = rom_01E5B8[d0 / 4u];
	LAYER(LAYER_B)->blocks = rom_01E5BC[d0 / 4u];
	LAYER(LAYER_A)->map_width = rom_01E5C0[d0 / 2u];
	LAYER(LAYER_B)->map_width = rom_01E5C2[d0 / 2u];
	switch (stage)
	{
	case 0:
		start_layers_building();
		break;
	case 1:
		start_layers_apartment();
		break;
	case 2:
		start_layers_street();
		break;
	case 3:
		start_layers_sewer();
		break;
	case 4:
		start_layers_car_street();
		break;
	case 5:
		start_layers_highway();
		break;
	case 6:
		start_layers_skateboard();
		break;
	case 7:
		start_layers_building_site();
		break;
	case 8:
		start_layers_technodrome();
		break;
	case 9:
		start_layers_final();
		break;
	}
	set_layers_scroll();
}

/* the burning building's floor map and layer */
void start_layers_building(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = floor_map_ADDRESS;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < floor_map_ADDRESS + 0x47Fu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= OBJECT_ADDRESS(0))
			break;
	}
	start_scroll_segment(0u);
	load_layer_b();
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	save_layer_b();
}

/* April's apartment's floor map, its left wall, April at the window, and the layer */
void start_layers_apartment(void)
{
	uint8_t d0_2 = 0, d2 = 0, d3 = 0;
	uint32_t a0 = 0, a1 = 0, animation = 0, april = 0, d0 = 0, d1 = 0;
	uint8_t t1 = 0, t2 = 0;

	a0 = floor_map_ADDRESS;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < floor_map_ADDRESS + 0x4BFu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= OBJECT_ADDRESS(0))
			break;
	}
	a0 = floor_map_ADDRESS + 0x4u;
	d0_2 = 6u;
	d1 = 0x19u;
	d3 = 0xFDu;
	do
	{
		a1 = a0;
		d2 = (uint8_t)d1;
		d1 = (uint8_t)(d1 - 1u);
		a0++;
		do
		{
			mem_write8(a1, d3);
			t1 = d2;
			d2 = (uint8_t)(t1 - 1u);
			a1 += 0x40u;
		} while (t1 != 1u);
		t2 = d0_2;
		d0_2 = (uint8_t)(t2 - 1u);
	} while (t2 != 1u);
	april = OBJECT_ADDRESS(47);
	OBJECT(OBJECT_ADDRESS(47))->flags = 0x81u;
	OBJECT(OBJECT_ADDRESS(47))->colour = 0xFFu;
	OBJECT(OBJECT_ADDRESS(47))->animation_delay = 0u;
	OBJECT(OBJECT_ADDRESS(47))->x = 0x12000u;
	OBJECT(OBJECT_ADDRESS(47))->screen_x = 0x120u;
	OBJECT(OBJECT_ADDRESS(47))->y = 0x6000u;
	OBJECT(OBJECT_ADDRESS(47))->screen_y = 0x60u;
	OBJECT(OBJECT_ADDRESS(47))->x_speed &= 0xFFu;
	animation = 0x2D8AEu;
	set_animation(d1, april, animation);
	start_scroll_segment(0u);
	load_layer_b();
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	save_layer_b();
}

/* the street's layer and its floor map */
void start_layers_street(void)
{
	uint32_t a0 = 0;

	start_scroll_segment(0u);
	load_layer_b();
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer_and_floor(a0);
	save_layer_b();
}

/* the sewer's floor map and both layers */
void start_layers_sewer(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = floor_map_ADDRESS;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < floor_map_ADDRESS + 0x2FFu)
			continue;
		d0 = 0x1010101u;
		if (a0 < floor_map_ADDRESS + 0x4FFu)
			continue;
		d0 = 0xFCFCFCFCu;
		if (a0 < floor_map_ADDRESS + 0x5BFu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= OBJECT_ADDRESS(0))
			break;
	}
	start_scroll_segment(0u);
	load_layer_a();
	a0 = TILE_RAM + 0x2000u;
	draw_whole_layer(a0);
	save_layer_a();
	load_layer_b();
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	save_layer_b();
}

/* the street of the parked cars' floor map and layer */
void start_layers_car_street(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = floor_map_ADDRESS;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < floor_map_ADDRESS + 0x47Fu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= OBJECT_ADDRESS(0))
			break;
	}
	start_scroll_segment(0u);
	load_layer_b();
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	save_layer_b();
}

/* the highway's floor map and layer */
void start_layers_highway(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = floor_map_ADDRESS;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < floor_map_ADDRESS + 0x1FFu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= OBJECT_ADDRESS(0))
			break;
	}
	start_scroll_segment(0u);
	load_layer_b();
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	save_layer_b();
}

/* the skateboard ride's floor map and both layers */
void start_layers_skateboard(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = floor_map_ADDRESS;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < floor_map_ADDRESS + 0x3BFu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= OBJECT_ADDRESS(0))
			break;
	}
	start_scroll_segment(0u);
	load_layer_b();
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	save_layer_b();
	load_layer_a();
	a0 = TILE_RAM + 0x2000u;
	draw_whole_layer(a0);
	save_layer_a();
}

/* the building site's layers and floor map */
void start_layers_building_site(void)
{
	uint32_t a0 = 0;

	start_scroll_segment(0u);
	load_layer_a();
	a0 = TILE_RAM + 0x2000u;
	draw_whole_layer(a0);
	save_layer_a();
	load_layer_b();
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer_and_floor(a0);
	save_layer_b();
}

/* the last area starts with Krang counted as an enemy, then as the Technodrome */
void start_layers_final(void)
{
	enemies_on_screen = 1u;
	start_layers_technodrome();
}

/* the Technodrome's floor map and layer */
void start_layers_technodrome(void)
{
	uint32_t a0 = 0, d0 = 0;

	a0 = floor_map_ADDRESS;
	d0 = 0xFFFFFFFFu;
	for (;;)
	{
		mem_write32(a0, d0);
		a0 += 4u;
		if (a0 < floor_map_ADDRESS + 0x3FFu)
			continue;
		d0 = 0x1010101u;
		if (a0 >= OBJECT_ADDRESS(0))
			break;
	}
	start_scroll_segment(0u);
	load_layer_b();
	a0 = TILE_RAM + 0x4000u;
	draw_whole_layer(a0);
	save_layer_b();
}

/* layer A's variables into the working layer */
void load_layer_a(void)
{
	uint8_t d0 = 0;
	uint32_t a3 = 0, a4 = 0;
	uint8_t t2 = 0;
	uint32_t t1 = 0;

	a3 = LAYER_A;
	a4 = WORKING_LAYER;
	d0 = 0x10u;
	do
	{
		t1 = a4;
		a4 += 4u;
		mem_write32(t1, mem_read32(a3));
		t2 = d0;
		d0 = (uint8_t)(t2 - 1u);
		a3 += 4u;
	} while (t2 != 1u);
}

/* layer B's variables into the working layer */
void load_layer_b(void)
{
	uint8_t d0 = 0;
	uint32_t a3 = 0, a4 = 0;
	uint8_t t2 = 0;
	uint32_t t1 = 0;

	a3 = LAYER_B;
	a4 = WORKING_LAYER;
	d0 = 0x10u;
	do
	{
		t1 = a4;
		a4 += 4u;
		mem_write32(t1, mem_read32(a3));
		t2 = d0;
		d0 = (uint8_t)(t2 - 1u);
		a3 += 4u;
	} while (t2 != 1u);
}

/* the working layer back into layer A's variables */
void save_layer_a(void)
{
	uint8_t d0 = 0;
	uint32_t a3 = 0, a4 = 0;
	uint8_t t2 = 0;
	uint32_t t1 = 0;

	a4 = LAYER_A;
	a3 = WORKING_LAYER;
	d0 = 0x10u;
	do
	{
		t1 = a4;
		a4 += 4u;
		mem_write32(t1, mem_read32(a3));
		t2 = d0;
		d0 = (uint8_t)(t2 - 1u);
		a3 += 4u;
	} while (t2 != 1u);
}

/* the working layer back into layer B's variables */
void save_layer_b(void)
{
	uint8_t d0 = 0;
	uint32_t a3 = 0, a4 = 0;
	uint8_t t2 = 0;
	uint32_t t1 = 0;

	a4 = LAYER_B;
	a3 = WORKING_LAYER;
	d0 = 0x10u;
	do
	{
		t1 = a4;
		a4 += 4u;
		mem_write32(t1, mem_read32(a3));
		t2 = d0;
		d0 = (uint8_t)(t2 - 1u);
		a3 += 4u;
	} while (t2 != 1u);
}

/* the row and the column the scroll has brought into view, with their floor cells */
void draw_new_row_and_column_and_floor(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t a1 = *p_a1;
	uint8_t d3_2 = 0, d6_2 = 0;
	uint32_t a0 = 0, a2 = 0, a3 = 0, a4 = 0, blocks = 0, d0 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d6 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (LAYER(WORKING_LAYER)->new_row != 0u)
	{
		d0 = LAYER(WORKING_LAYER)->new_row_y;
		d3 = d0;
		d5 = d0;
		d1 = ((LAYER(WORKING_LAYER)->x - 0x2000u) & 0x1E000u) << 6;
		d0 &= 0xF800u;
		d0 = (uint16_t)(0u - d0);
		d0 = d0 >> 4;
		d0 = (uint16_t)(d0 + ((d1 << 16) | (d1 >> 16)));
		a0 = d0 + working_layer_tiles;
		a1 = (d0 >> 1) + floor_map_ADDRESS;
		d2 = ((LAYER(WORKING_LAYER)->x - 0x2000u) & 0xFFE000u) << 4;
		d3 = ((d3 - 0x800u) & 0xFFE000u) << 3;
		a2 = ((d2 << 16) | (d2 >> 16)) + ((d3 << 16) | (d3 >> 16)) * LAYER(WORKING_LAYER)->map_width + LAYER(WORKING_LAYER)->map;
		d5 = (d5 - 0x800u) << 7;
		d5 = (d5 << 16) | (d5 >> 16);
		d5 = LINKED(d5, d5 & 0xCu);
		d5 = LINKED(d5, (uint16_t)(d5 ^ 0xCu));
		d7 = 0xDu;
		do
		{
			a3 = LAYER(WORKING_LAYER)->blocks;
			d4 = mem_read16(a2);
			mem_write8(a0, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 2u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 4u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 6u, mem_read8(a3 + (int16_t)d4));
			a3 += d4;
			mem_write8(a1, DATA8(a3 + 1u + (uint16_t)d5));
			mem_write8(a1 + 1u, DATA8(a3 + 2u + (uint16_t)d5));
			mem_write8(a1 + 2u, DATA8(a3 + 3u + (uint16_t)d5));
			mem_write8(a1 + 3u, DATA8(a3 + 4u + (uint16_t)d5));
			mem_write8(a0 + 1u, DATA8(a3 + 0x11u + (uint16_t)d5));
			mem_write8(a0 + 3u, DATA8(a3 + 0x12u + (uint16_t)d5));
			mem_write8(a0 + 5u, DATA8(a3 + 0x13u + (uint16_t)d5));
			mem_write8(a0 + 7u, DATA8(a3 + 0x14u + (uint16_t)d5));
			d0 = a1;
			d3 = a0;
			a1 += 4u;
			d6 = d3 & ~0x7Fu;
			d0 = d0 & ~0x3Fu;
			a2 += 2u;
			a0 += 8u;
			if (((d3 + 8u) & 0xFF80u) != (uint16_t)d6)
			{
				a0 = d6;
				a1 = d0;
			}
			t1 = d7;
			d7 = (uint8_t)(t1 - 1u);
		} while (t1 != 1u);
	}
	if (LAYER(WORKING_LAYER)->new_column != 0u)
	{
		d0 = LAYER(WORKING_LAYER)->new_column_x;
		d4 = d0;
		d5 = d0;
		d1 = (LAYER(WORKING_LAYER)->y + 0x1800u) & 0xE000u;
		d0 = (d0 & 0x1F800u) << 6;
		d0 = (d0 << 16) | (d0 >> 16);
		d0 = (uint16_t)(d0 + ((uint16_t)(0u - d1) >> 4));
		a0 = d0 + working_layer_tiles;
		a1 = (d0 >> 1) + floor_map_ADDRESS;
		d2 = ((LAYER(WORKING_LAYER)->y - 0x800u) & 0xFFE000u) << 3;
		d4 = (d4 & 0xFFE000u) << 4;
		a2 = ((d2 << 16) | (d2 >> 16)) * LAYER(WORKING_LAYER)->map_width + ((d4 << 16) | (d4 >> 16)) + LAYER(WORKING_LAYER)->map;
		d5 = LINKED(d5, (uint16_t)d5 >> 8);
		d5 = LINKED(d5, d5 & 0x18u);
		d5 = LINKED(d5, (uint16_t)d5 >> 3);
		d7 = 8u;
		do
		{
			a3 = LAYER(WORKING_LAYER)->blocks;
			d4 = mem_read16(a2);
			mem_write8(a0, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x80u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x100u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x180u, mem_read8(a3 + (int16_t)d4));
			a3 += d4;
			mem_write8(a1, DATA8(a3 + 1u + (uint16_t)d5));
			mem_write8(a1 + 0x40u, DATA8(a3 + 5u + (uint16_t)d5));
			mem_write8(a1 + 0x80u, DATA8(a3 + 9u + (uint16_t)d5));
			mem_write8(a1 + 0xC0u, DATA8(a3 + 0xDu + (uint16_t)d5));
			mem_write8(a0 + 1u, DATA8(a3 + 0x11u + (uint16_t)d5));
			mem_write8(a0 + 0x81u, DATA8(a3 + 0x15u + (uint16_t)d5));
			mem_write8(a0 + 0x101u, DATA8(a3 + 0x19u + (uint16_t)d5));
			mem_write8(a0 + 0x181u, DATA8(a3 + 0x1Du + (uint16_t)d5));
			a2 -= LAYER(WORKING_LAYER)->map_width;
			a1 = ((a1 + 0x100u) & 0xFF1FFFu) | 0x61800u;
			d6 = LINKED(a0, (uint16_t)(a0 + 0x200u));
			a0 = d6 & ~0x9000u;
			t2 = d7;
			d7 = (uint8_t)(t2 - 1u);
		} while (t2 != 1u);
		blocks = LAYER(WORKING_LAYER)->blocks;
		d4 = mem_read16(a2);
		t3 = LAYER(WORKING_LAYER)->y_pixel & 0x18u;
		d3_2 = t3;
		if (t3 != 0u)
		{
			a4 = blocks + d4;
			mem_write8(a0, mem_read8(blocks + (int16_t)d4));
			mem_write8(a1, DATA8(a4 + 1u + (uint16_t)d5));
			mem_write8(a0 + 1u, DATA8(a4 + 0x11u + (uint16_t)d5));
			t4 = 4u - (d3_2 >> 3);
			d6_2 = (uint8_t)(t4 - 1u);
			if (t4 != 1u)
			{
				mem_write8(a0 + 0x80u, mem_read8(blocks + (int16_t)d4));
				mem_write8(a1 + 0x40u, DATA8(a4 + 5u + (uint16_t)d5));
				mem_write8(a0 + 0x81u, DATA8(a4 + 0x15u + (uint16_t)d5));
				if (d6_2 != 1u)
				{
					mem_write8(a0 + 0x100u, mem_read8(blocks + (int16_t)d4));
					mem_write8(a1 + 0x80u, DATA8(a4 + 9u + (uint16_t)d5));
					mem_write8(a0 + 0x101u, DATA8(a4 + 0x19u + (uint16_t)d5));
				}
			}
		}
	}
	*p_d5 = d5;
	*p_d7 = d7;
	*p_a1 = a1;
}

/* the row and the column of a layer the scroll has brought into view */
void draw_new_row_and_column(uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d1 = *p_d1;
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint8_t d3_2 = 0, d6_2 = 0;
	uint32_t a0 = 0, a2 = 0, a3 = 0, a4 = 0, blocks = 0, d0 = 0, d2 = 0, d3 = 0, d4 = 0, d6 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	if (LAYER(WORKING_LAYER)->new_row != 0u)
	{
		d0 = LAYER(WORKING_LAYER)->new_row_y;
		d3 = d0;
		d5 = d0;
		d1 = ((LAYER(WORKING_LAYER)->x - 0x2000u) & 0x1E000u) << 6;
		d1 = (d1 << 16) | (d1 >> 16);
		d0 &= 0xF800u;
		d0 = (uint16_t)(0u - d0);
		d0 = d0 >> 4;
		a0 = (uint16_t)(d0 + d1) + working_layer_tiles;
		d2 = ((LAYER(WORKING_LAYER)->x - 0x2000u) & 0xFFE000u) << 4;
		d3 = ((d3 - 0x800u) & 0xFFE000u) << 3;
		a2 = ((d2 << 16) | (d2 >> 16)) + ((d3 << 16) | (d3 >> 16)) * LAYER(WORKING_LAYER)->map_width + LAYER(WORKING_LAYER)->map;
		d5 = (d5 - 0x800u) << 7;
		d5 = (d5 << 16) | (d5 >> 16);
		d5 = LINKED(d5, d5 & 0xCu);
		d5 = LINKED(d5, (uint16_t)(d5 ^ 0xCu));
		d7 = 0xDu;
		do
		{
			a3 = LAYER(WORKING_LAYER)->blocks;
			d4 = mem_read16(a2);
			mem_write8(a0, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 2u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 4u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 6u, mem_read8(a3 + (int16_t)d4));
			a3 += d4;
			mem_write8(a0 + 1u, DATA8(a3 + 1u + (uint16_t)d5));
			mem_write8(a0 + 3u, DATA8(a3 + 2u + (uint16_t)d5));
			mem_write8(a0 + 5u, DATA8(a3 + 3u + (uint16_t)d5));
			mem_write8(a0 + 7u, DATA8(a3 + 4u + (uint16_t)d5));
			d3 = a0;
			d6 = d3 & ~0x7Fu;
			a2 += 2u;
			a0 += 8u;
			if (((d3 + 8u) & 0xFF80u) != (uint16_t)d6)
				a0 = d6;
			t1 = d7;
			d7 = (uint8_t)(t1 - 1u);
		} while (t1 != 1u);
	}
	if (LAYER(WORKING_LAYER)->new_column != 0u)
	{
		d0 = LAYER(WORKING_LAYER)->new_column_x;
		d4 = d0;
		d5 = d0;
		d1 = (LAYER(WORKING_LAYER)->y + 0x1800u) & 0xE000u;
		d1 = (uint16_t)(0u - d1) >> 4;
		d0 = (d0 & 0x1F800u) << 6;
		d0 = (d0 << 16) | (d0 >> 16);
		a0 = (uint16_t)(d0 + d1) + working_layer_tiles;
		d2 = ((LAYER(WORKING_LAYER)->y - 0x800u) & 0xFFE000u) << 3;
		d4 = (d4 & 0xFFE000u) << 4;
		a2 = ((d2 << 16) | (d2 >> 16)) * LAYER(WORKING_LAYER)->map_width + ((d4 << 16) | (d4 >> 16)) + LAYER(WORKING_LAYER)->map;
		d5 = LINKED(d5, (uint16_t)d5 >> 8);
		d5 = LINKED(d5, d5 & 0x18u);
		d5 = LINKED(d5, (uint16_t)d5 >> 3);
		d7 = 8u;
		do
		{
			a3 = LAYER(WORKING_LAYER)->blocks;
			d4 = mem_read16(a2);
			mem_write8(a0, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x80u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x100u, mem_read8(a3 + (int16_t)d4));
			mem_write8(a0 + 0x180u, mem_read8(a3 + (int16_t)d4));
			a3 += d4;
			mem_write8(a0 + 1u, DATA8(a3 + 1u + (uint16_t)d5));
			mem_write8(a0 + 0x81u, DATA8(a3 + 5u + (uint16_t)d5));
			mem_write8(a0 + 0x101u, DATA8(a3 + 9u + (uint16_t)d5));
			mem_write8(a0 + 0x181u, DATA8(a3 + 0xDu + (uint16_t)d5));
			a2 -= LAYER(WORKING_LAYER)->map_width;
			d6 = LINKED(a0, (uint16_t)(a0 + 0x200u));
			a0 = d6 & ~0x9000u;
			t2 = d7;
			d7 = (uint8_t)(t2 - 1u);
		} while (t2 != 1u);
		blocks = LAYER(WORKING_LAYER)->blocks;
		d4 = mem_read16(a2);
		t3 = LAYER(WORKING_LAYER)->y_pixel & 0x18u;
		d3_2 = t3;
		if (t3 != 0u)
		{
			a4 = blocks + d4;
			mem_write8(a0, mem_read8(blocks + (int16_t)d4));
			mem_write8(a0 + 1u, DATA8(a4 + 1u + (uint16_t)d5));
			t4 = 4u - (d3_2 >> 3);
			d6_2 = (uint8_t)(t4 - 1u);
			if (t4 != 1u)
			{
				mem_write8(a0 + 0x80u, mem_read8(blocks + (int16_t)d4));
				mem_write8(a0 + 0x81u, DATA8(a4 + 5u + (uint16_t)d5));
				if (d6_2 != 1u)
				{
					mem_write8(a0 + 0x100u, mem_read8(blocks + (int16_t)d4));
					mem_write8(a0 + 0x101u, DATA8(a4 + 9u + (uint16_t)d5));
				}
			}
		}
	}
	*p_d1 = d1;
	*p_d5 = d5;
	*p_d7 = d7;
}

/* every frame of play: the area's layers, and the HURRY! sign and the missiles when the players dawdle */
void update_area_layers(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint16_t d0 = 0;
	uint32_t animation = 0, object = 0;

	time_since_balloon++;
	unk_061114++;
	unk_06110A++;
	unk_06110C++;
	unk_061116++;
	d0 = (uint16_t)((uint32_t)stage << 2);
	switch (d0)
	{
	case 0:
		update_layers_building(d0, p_d5, p_d7, p_a1);
		break;
	case 4:
		update_layers_apartment(p_d5, p_d7, p_a1);
		break;
	case 8:
		update_layers_street(d0, p_d5, p_d7, p_a1);
		break;
	case 12:
		update_layers_sewer(p_d5, p_d7, p_a1);
		break;
	case 16:
		update_layers_car_street(p_d5, p_d7);
		break;
	case 20:
		update_layers_highway(p_d5, p_d7, p_a1);
		break;
	case 24:
		update_layers_skateboard(p_d5, p_d7);
		break;
	case 28:
		update_layers_building_site(p_d5, p_d7, p_a1);
		break;
	case 32:
		update_layers_technodrome(p_d5, p_d7, p_a1);
		break;
	case 36:
		update_layers_final(p_d5, p_d7);
		break;
	}
	if ((uint8_t)(LAYER(LAYER_A)->x_direction | LAYER(LAYER_B)->x_direction | last_segment) != 0u)
	{
		hurry_time = 0u;
		OBJECT(OBJECT_ADDRESS(49))->flags = 0u;
		return;
	}
	hurry_time++;
	if (enemies_on_screen >= 3u)
	{
		hurry_time = 0u;
		OBJECT(OBJECT_ADDRESS(49))->flags = 0u;
		return;
	}
	if ((uint8_t)(hurry_time >> 8u) == 0u)
	{
		OBJECT(OBJECT_ADDRESS(49))->flags = 0u;
		return;
	}
	object = OBJECT_ADDRESS(49);
	if (OBJECT(OBJECT_ADDRESS(49))->flags == 0u)
	{
		OBJECT(object)->flags = 0x81u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->height = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		OBJECT(object)->screen_x = 0x158u;
		OBJECT(object)->screen_y = 0u;
		animation = 0x2DB76u;
		if ((uint8_t)diagonal_scroll != 0u)
			animation = 0x2DBAEu;
		set_animation(0u, object, animation);
	}
	if (enemies_on_screen != 0u)
	{
		hurry_time = 0x100u;
		return;
	}
	if (hurry_time < 0x600u)
	{
		return;
	}
	rain_missiles_on_turtles(p_d5, p_d7);
	hurry_time = 0u;
	OBJECT(OBJECT_ADDRESS(49))->flags = 0u;
}

/* the two layers' places into the scroll the frame shows */
void set_layers_scroll(void)
{
	layer_a_scroll_x = (LAYER(LAYER_A)->x >> 8) & 0x1FFu;
	layer_b_scroll_x = (LAYER(LAYER_B)->x >> 8) & 0x1FFu;
	layer_a_scroll_y = (layer_a_scroll_y & 0xFF00u) | (0u - LAYER(LAYER_A)->y_pixel & 0xFFu);
	layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | (0u - LAYER(LAYER_B)->y_pixel & 0xFFu);
}

/* the burning building's layer, the first cry of attack, and the wall at its end */
void update_layers_building(uint16_t d0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a1 = *p_a1;
	uint8_t d0_2 = 0, d1 = 0, d2 = 0, d3 = 0;
	uint16_t screen_x = 0, screen_y = 0;
	uint32_t a0 = 0, ignored = 0, object = 0;
	uint8_t t1 = 0, t2 = 0;

	if (balloons_said == 0u && time_since_balloon == 0x30u)
	{
		object = OBJECT_ADDRESS(0);
		do
		{
			if ((OBJECT(object)->flags & 1u) != 0u)
			{
				d0 &= ~0xFFu;
				if ((OBJECT(object)->flags & 0x40u) != 0u)
					d0 |= (uint8_t)(d0 - 1u);
				screen_x = OBJECT(object)->screen_x;
				screen_y = OBJECT(object)->screen_y;
				say_attack(d0, screen_x, screen_y, p_d5, p_d7);
				break;
			}
			object += 0x50u;
		} while (object < OBJECT_ADDRESS(4));
	}
	LAYER(LAYER_A)->x_direction = 0;
	load_layer_b();
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column(&ignored, p_d5, p_d7);
	save_layer_b();
	set_layers_scroll();
	if (floor_end_walled == 0u && LAYER(LAYER_B)->x >= 0x3C000u)
	{
		a0 = floor_map_ADDRESS + 0x24u;
		d0_2 = 0xCu;
		d1 = 0x12u;
		d3 = 0xFEu;
		do
		{
			d2 = (uint8_t)d1;
			d1++;
			a1 = a0;
			a0++;
			do
			{
				mem_write8(a1, d3);
				t1 = d2;
				d2 = (uint8_t)(t1 - 1u);
				a1 += 0x40u;
			} while (t1 != 1u);
			t2 = d0_2;
			d0_2 = (uint8_t)(t2 - 1u);
		} while (t2 != 1u);
		floor_end_walled--;
	}
	*p_a1 = a1;
}

/* the apartment's layer, the wall at its end, and April */
void update_layers_apartment(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a1 = *p_a1;
	uint8_t d0 = 0, d1 = 0, d2 = 0, d3 = 0;
	uint32_t a0 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	if (floor_end_walled == 0u && LAYER(LAYER_B)->x >= 0x2000u)
	{
		a0 = floor_map_ADDRESS + 0x34u;
		d0 = 8u;
		d1 = 0x13u;
		d3 = 0xFEu;
		do
		{
			d2 = (uint8_t)d1;
			d1++;
			a1 = a0;
			a0++;
			do
			{
				mem_write8(a1, d3);
				t1 = d2;
				d2 = (uint8_t)(t1 - 1u);
				a1 += 0x40u;
			} while (t1 != 1u);
			t2 = d0;
			d0 = (uint8_t)(t2 - 1u);
		} while (t2 != 1u);
		floor_end_walled--;
	}
	LAYER(LAYER_A)->x_direction = 0;
	load_layer_b();
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column(&ignored, p_d5, p_d7);
	save_layer_b();
	set_layers_scroll();
	run_drill_arrival(p_d5, p_d7, &a1);
	april_wait_for_rescue(0u, &ignored, p_d5, p_d7);
	*p_a1 = a1;
}

/* April at the window cries for help and paces, kept at her place */
void april_wait_for_rescue(uint32_t d6, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t d2 = 0;
	uint32_t april = 0, d0 = 0, ignored = 0;

	april = OBJECT_ADDRESS(47);
	if (balloons_said == 0u && time_since_balloon == 0x30u)
	{
		d0 = 0x7Fu;
		*p_d1 = (*p_d1 & ~0xFFFFu) | OBJECT(april)->screen_x;
		d2 = 0x70u;
		say_help_me(d2, &d0, p_d1, &d5, &ignored, p_d7);
	}
	if (OBJECT(april)->frame_time == 0x30u)
	{
		if (OBJECT(april)->april.stepping_left != 0u)
			OBJECT(april)->x -= 0x400u;
		else
			OBJECT(april)->x += 0x400u;
		OBJECT(april)->april.stepping_left ^= 0xFFu;
	}
	OBJECT(april)->x -= (int16_t)LAYER(LAYER_B)->x_speed;
	OBJECT(april)->screen_x = OBJECT(april)->x >> 8;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the street's layers: the TV in the shop window shows April and Shredder, and a turtle's answer */
void update_layers_street(uint32_t d0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a1 = *p_a1;
	uint32_t carry = 0;
	uint8_t d1_2 = 0;
	uint16_t d1_3 = 0, d2 = 0, d6 = 0;
	uint32_t a0 = 0, a6 = 0, d1 = 0, ignored = 0, object = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	LAYER(LAYER_A)->x_direction = 0;
	LAYER(LAYER_A)->x = LAYER(LAYER_B)->x;
	LAYER(LAYER_A)->y = LAYER(LAYER_B)->y;
	if (LAYER(LAYER_B)->x >= 0x12000u)
	{
		if (LAYER(LAYER_B)->x < 0x1E000u)
		{
			if (tv_time != 0u)
			{
				if (tv_time == 0x10u)
				{
					d0 = 0x7Fu;
					d2 = 0x70u;
					d1 = (0x26000u - LAYER(LAYER_B)->x) >> 8;
					say_help_me(d2, &d0, &d1, p_d5, &ignored, p_d7);
				}
				else if (tv_time == 0xA0u)
				{
					a6 = 0x1F118u;
					d0 = 8u;
					draw_tv_picture((uint8_t)d0, a6, p_d7, &a1);
				}
				else if (tv_time == 0xB0u)
				{
					d0 = 0x7Fu;
					d2 = 0x70u;
					d1_3 = (uint16_t)((0x26000u - LAYER(LAYER_B)->x) >> 8);
					say_turtle_soup(d1_3, d2, &d0, p_d5, p_d7);
				}
				else if (tv_time == 0x170u)
				{
					a0 = TILE_RAM + 0x2478u;
					a1 = TILE_RAM + 0x2400u;
					d0 &= ~0xFFu;
					d1_2 = 0x10u;
					*p_d7 = 7u;
					do
					{
						d6 = 3u;
						do
						{
							io_write8(a1, d0);
							io_write8(a0, d0);
							a1++;
							io_write8(a1, d1_2);
							a0++;
							io_write8(a0, d1_2);
							t1 = d6 - 1u;
							d6 = t1;
							a1++;
							a0++;
						} while (t1 != 0xFFFFu);
						t2 = *p_d7 - 1u;
						*p_d7 = t2;
						a0 += 0x78u;
						a1 += 0x78u;
					} while (t2 != 0xFFFFu);
				}
				else if (tv_time >= 0x10u && tv_time < 0xA0u)
				{
					a6 = 0x1F158u;
					d0 = tv_time;
					if ((d0 & 7u) == 0u)
					{
						d0 = (d0 & 0x18u) >> 1;
						a6 = DATA32(a6 + d0);
						animate_tv_picture(a6, p_d7, &a1);
					}
				}
			}
			else
			{
				a6 = record_01F0D8_ADDRESS;
				d0 = 0x28u;
				draw_tv_picture((uint8_t)d0, a6, p_d7, &a1);
			}
			t3 = tv_time;
			carry = (uint16_t)(t3 + 1u) < t3;
			tv_time = t3 + 1u;
			if (carry)
				tv_time--;
		}
		else if (tv_time < 0x170u)
		{
			tv_time = 0x170u;
			a0 = TILE_RAM + 0x2478u;
			a1 = TILE_RAM + 0x2400u;
			d0 &= ~0xFFu;
			d1_2 = 0x10u;
			*p_d7 = 7u;
			do
			{
				d6 = 3u;
				do
				{
					io_write8(a1, d0);
					io_write8(a0, d0);
					a1++;
					io_write8(a1, d1_2);
					a0++;
					io_write8(a0, d1_2);
					t1 = d6 - 1u;
					d6 = t1;
					a1++;
					a0++;
				} while (t1 != 0xFFFFu);
				t2 = *p_d7 - 1u;
				*p_d7 = t2;
				a0 += 0x78u;
				a1 += 0x78u;
			} while (t2 != 0xFFFFu);
			t3 = tv_time;
			carry = (uint16_t)(t3 + 1u) < t3;
			tv_time = t3 + 1u;
			if (carry)
				tv_time--;
		}
	}
	if (bebop_exchange_lines != 1u || time_since_balloon < 0xA0u)
	{
		load_layer_b();
		working_layer_tiles = TILE_RAM + 0x4000u;
		draw_new_row_and_column_and_floor(p_d5, p_d7, &a1);
		save_layer_b();
		set_layers_scroll();
		*p_a1 = a1;
		return;
	}
	object = OBJECT_ADDRESS(0);
	while ((OBJECT(object)->flags & 1u) == 0u)
	{
		object += 0x50u;
		if (object >= OBJECT_ADDRESS(4))
		{
			load_layer_b();
			working_layer_tiles = TILE_RAM + 0x4000u;
			draw_new_row_and_column_and_floor(p_d5, p_d7, &a1);
			save_layer_b();
			set_layers_scroll();
			*p_a1 = a1;
			return;
		}
	}
	d1_3 = OBJECT(object)->screen_x;
	if ((OBJECT(object)->flags & 0x40u) != 0u)
		d1_3 -= 0x18u;
	d2 = (uint16_t)(OBJECT(object)->screen_y + 8u);
	d0 &= ~0xFFu;
	say_they_aint_getting_prettier(d0, d1_3, d2, p_d5, p_d7);
	load_layer_b();
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column_and_floor(p_d5, p_d7, &a1);
	save_layer_b();
	set_layers_scroll();
	*p_a1 = a1;
}

/* a picture on the TV in the shop window */
void draw_tv_picture(uint8_t d0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a1)
{
	uint16_t d6 = 0;
	uint32_t a0 = 0, a1 = 0, d7 = 0;
	uint16_t t4 = 0, t5 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0;

	a0 = TILE_RAM + 0x2478u;
	a1 = TILE_RAM + 0x2400u;
	d7 = 7u;
	do
	{
		d6 = 3u;
		do
		{
			io_write8(a1, d0);
			t1 = a0;
			a0++;
			io_write8(t1, d0);
			a1++;
			io_write8(a1, mem_read8(a6 + 4u));
			t2 = a6;
			a6++;
			t3 = a0;
			a0++;
			io_write8(t3, mem_read8(t2));
			t4 = d6 - 1u;
			d6 = t4;
			a1++;
		} while (t4 != 0xFFFFu);
		a1 += 0x78u;
		a6 += 4u;
		t5 = d7 - 1u;
		d7 = t5;
		a0 += 0x78u;
	} while (t5 != 0xFFFFu);
	*p_d7 = d7;
	*p_a1 = a1;
}

/* April talking on the TV */
void animate_tv_picture(uint32_t a6, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a0 = 0, a1 = 0, d7 = 0;
	uint16_t t1 = 0;

	a0 = TILE_RAM + 0x25FDu;
	a1 = TILE_RAM + 0x2581u;
	d7 = 2u;
	do
	{
		io_write8(a0, mem_read8(a6));
		io_write8(a0 + 2u, mem_read8(a6 + 1u));
		io_write8(a1, mem_read8(a6 + 2u));
		a1 += 0x80u;
		a6 += 3u;
		t1 = d7 - 1u;
		d7 = t1;
		a0 += 0x80u;
	} while (t1 != 0xFFFFu);
	*p_d7 = d7;
	*p_a1 = a1;
}

/* the sewer's two layers and the wall at its end */
void update_layers_sewer(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d7 = *p_d7;
	uint32_t a1 = *p_a1;
	uint8_t d0 = 0, d6 = 0;
	uint32_t a0 = 0, a6 = 0, ignored = 0;
	uint8_t t2 = 0, t3 = 0;
	uint32_t t1 = 0;

	if (floor_end_walled == 0u && LAYER(LAYER_B)->x >= 0x30000u)
	{
		a1 = floor_map_ADDRESS + 0x10u;
		a6 = table_loaded_by_lea_01F242_ADDRESS;
		d0 = 0xFEu;
		d7 = 0x10u;
		do
		{
			a0 = a1;
			t1 = a6;
			a6++;
			d6 = DATA8(t1);
			a1++;
			do
			{
				mem_write8(a0, d0);
				t2 = d6;
				d6 = (uint8_t)(t2 - 1u);
				a0 += 0x40u;
			} while (t2 != 1u);
			t3 = d7;
			d7 = (uint8_t)(t3 - 1u);
		} while (t3 != 1u);
		floor_end_walled--;
	}
	load_layer_b();
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column(&ignored, p_d5, &d7);
	save_layer_b();
	LAYER(LAYER_A)->x = LAYER(LAYER_B)->x;
	LAYER(LAYER_A)->new_column_x = LAYER(LAYER_B)->new_column_x;
	LAYER(LAYER_A)->y = LAYER(LAYER_B)->y;
	LAYER(LAYER_A)->new_row_y = LAYER(LAYER_B)->new_row_y;
	LAYER(LAYER_A)->new_row = LAYER(LAYER_B)->new_row;
	LAYER(LAYER_A)->new_column = LAYER(LAYER_B)->new_column;
	load_layer_a();
	working_layer_tiles = TILE_RAM + 0x2000u;
	draw_new_row_and_column(&ignored, p_d5, &d7);
	save_layer_a();
	set_layers_scroll();
	*p_d7 = d7;
	*p_a1 = a1;
}

/* the street's layer, and April tied up at its end */
void update_layers_car_street(uint32_t *p_d5, uint32_t *p_d7)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, animation = 0, ignored = 0, object = 0;

	LAYER(LAYER_A)->x_direction = 0;
	if (LAYER(LAYER_B)->x < 0x33000u)
	{
		load_layer_b();
		working_layer_tiles = TILE_RAM + 0x4000u;
		draw_new_row_and_column(&ignored, p_d5, p_d7);
		save_layer_b();
		set_layers_scroll();
		return;
	}
	object = OBJECT_ADDRESS(44);
	if (OBJECT(OBJECT_ADDRESS(44))->flags == 0u)
	{
		OBJECT(object)->flags = 0x81u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->height = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		OBJECT(object)->screen_y = 0xF0u;
		animation = 0x2E11Au;
		set_animation(0u, object, animation);
		a6 = 0xCA04u;
		*p_d7 = (*p_d7 & ~0xFFFFu) | 0x43Du;
		post_palette_request((uint16_t)*p_d7, a6);
	}
	OBJECT(object)->screen_x = (0x4D000u - LAYER(LAYER_B)->x) >> 8;
	if ((uint8_t)frame_count != 0u)
	{
		load_layer_b();
		working_layer_tiles = TILE_RAM + 0x4000u;
		draw_new_row_and_column(&ignored, p_d5, p_d7);
		save_layer_b();
		set_layers_scroll();
		return;
	}
	d0 = 0u;
	if (OBJECT(object)->frame_time == 0u)
		d0 = 0x10u;
	OBJECT(object)->frame_time = d0;
	load_layer_b();
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column(&ignored, p_d5, p_d7);
	save_layer_b();
	set_layers_scroll();
}

/* the last area's layer */
void update_layers_final(uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t ignored = 0;

	LAYER(LAYER_A)->x_direction = 0;
	load_layer_b();
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column(&ignored, p_d5, p_d7);
	save_layer_b();
	set_layers_scroll();
}

/* the building site's layers, and Splinter hanging tied at its end */
void update_layers_building_site(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d7 = *p_d7;
	uint8_t d0 = 0;
	uint16_t x_speed = 0;
	uint32_t a0 = 0, animation = 0, d1 = 0, object = 0;
	uint8_t x_direction = 0;
	uint16_t t1 = 0;

	load_layer_b();
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column_and_floor(p_d5, &d7, p_a1);
	save_layer_b();
	x_direction = LAYER(LAYER_B)->x_direction;
	LAYER(LAYER_A)->x_direction = x_direction;
	if (x_direction != 0u)
	{
		x_speed = LAYER(LAYER_B)->x_speed;
		LAYER(LAYER_A)->x += (int16_t)(x_speed + (x_speed >> 2));
	}
	set_layers_scroll();
	if (LAYER(LAYER_B)->x < 0x60000u)
		run_drill_arrival(p_d5, &d7, p_a1);
	else
	{
		if (io_read16(TILES_102030) != 0x10u)
		{
			a0 = TILES_102030;
			d0 = 0u;
			d1 = 0x10u;
			d7 = 0x1Fu;
			do
			{
				io_write8(a0, d0);
				a0++;
				io_write8(a0, d1);
				a0++;
				io_write8(a0, d0);
				a0++;
				io_write8(a0, d1);
				a0++;
				io_write8(a0, d0);
				a0++;
				io_write8(a0, d1);
				a0++;
				io_write8(a0, d0);
				a0++;
				io_write8(a0, d1);
				t1 = d7 - 1u;
				d7 = t1;
				a0 += 0x79u;
			} while (t1 != 0xFFFFu);
			io_write8(TILES_102EAE, d0);
			io_write8(TILES_102EAF, d1);
			io_write8(TILES_102EB8, d0);
			io_write8(TILES_102EB9, d1);
		}
		if (LAYER(LAYER_B)->x >= 0x68800u)
		{
			object = OBJECT_ADDRESS(44);
			OBJECT(OBJECT_ADDRESS(44))->screen_x = (0x84000u - LAYER(LAYER_B)->x) >> 8;
			if (OBJECT(OBJECT_ADDRESS(44))->flags != 0u)
			{
				if ((uint8_t)frame_count == 0u)
				{
					animation = 0x2DB0Au;
					if (OBJECT(object)->frame_time == 0u)
						animation = 0x2DAE6u;
					set_animation(d1, object, animation);
				}
			}
			else
			{
				OBJECT(object)->flags = 0x81u;
				OBJECT(object)->contacts = 0x80u;
				OBJECT(object)->colour = 0xFFu;
				OBJECT(object)->animation_delay = 0u;
				OBJECT(object)->screen_y = 0x60u;
				OBJECT(object)->height = 0x3800u;
				OBJECT(object)->shadow = 0x2E928u;
				animation = 0x2DAE6u;
				set_animation(d1, object, animation);
			}
		}
		else
			run_drill_arrival(p_d5, &d7, p_a1);
	}
	*p_d7 = d7;
}

/* the Technodrome's layers by the step: to the lift, the ride, off the lift */
void update_layers_technodrome(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	switch (layers_step)
	{
	case 0:
		technodrome_reach_lift(p_d5, p_d7);
		break;
	case 1:
		technodrome_ride_lift(p_d5, p_d7, p_a1);
		break;
	case 2:
		technodrome_leave_lift(p_d5, p_d7, p_a1);
		break;
	}
	set_layers_scroll();
}

/* the layers up to the lift, and the ride starts when every turtle is on it */
void technodrome_reach_lift(uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t a0 = 0, animation = 0, ignored = 0, object = 0;

	load_layer_b();
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column(&ignored, p_d5, p_d7);
	save_layer_b();
	if (LAYER(LAYER_B)->x < 0x42000u)
	{
		return;
	}
	LAYER(LAYER_A)->x = LAYER(LAYER_B)->x - 0x40000u;
	LAYER(LAYER_A)->new_column_x = LAYER(LAYER_B)->new_column_x - 0x40000u;
	LAYER(LAYER_A)->new_column = LAYER(LAYER_B)->new_column;
	load_layer_a();
	working_layer_tiles = TILE_RAM + 0x2000u;
	draw_new_row_and_column(&ignored, p_d5, p_d7);
	save_layer_a();
	if (LAYER(LAYER_B)->x < 0x58000u)
	{
		return;
	}
	scroll_held_right = 0xFFu;
	object = OBJECT_ADDRESS(0);
	do
	{
		if ((OBJECT(object)->flags & 1u) != 0u && OBJECT(object)->x <= OBJECT(object)->y - 0x2000u + 0x9000u)
		{
			return;
		}
		object += 0x50u;
	} while (object < OBJECT_ADDRESS(4));
	scroll_mode = -1;
	LAYER(LAYER_B)->y_direction = -0x80;
	LAYER(LAYER_B)->x_direction = -0x80;
	LAYER(LAYER_B)->x_speed = 0u;
	LAYER(LAYER_B)->y_speed = 0u;
	a0 = OBJECT_ADDRESS(44);
	OBJECT(OBJECT_ADDRESS(44))->flags = 1u;
	OBJECT(OBJECT_ADDRESS(44))->contacts = 0u;
	OBJECT(OBJECT_ADDRESS(44))->colour = 0xFFu;
	animation = 0x2DB6Cu;
	set_animation(ignored, a0, animation);
	*p_d7 = (*p_d7 & ~0xFFu) | 0x21u;
	queue_sound((uint8_t)*p_d7, animation);
	layers_step++;
}

/* the lift's ride: the scroll speeds up, loops the shaft, slows down and stops */
void technodrome_ride_lift(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d7 = *p_d7;
	uint32_t a1 = *p_a1;
	uint8_t d0 = 0, d1 = 0, d2 = 0, d3 = 0;
	uint32_t a0 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	if (layer_loops < 0)
	{
		if (LAYER(WORKING_LAYER)->x < 0xA0000u)
		{
			if (LAYER(WORKING_LAYER)->x + (int16_t)LAYER(WORKING_LAYER)->x_speed >= 0xA2800u && layer_loops >= 0)
			{
				LAYER(WORKING_LAYER)->x -= 0x40000u;
				LAYER(WORKING_LAYER)->y += 0x40000u;
				t1 = layer_loops + 1u;
				layer_loops = t1;
				if ((int8_t)t1 >= 0)
					layer_loops = -0x80;
			}
		}
		else
		{
			if (LAYER(WORKING_LAYER)->x_speed < 0x120u && LAYER(WORKING_LAYER)->x_speed >= 0x110u)
			{
				d7 = (d7 & ~0xFFu) | 0x29u;
				queue_sound((uint8_t)d7, 0u);
			}
			LAYER(WORKING_LAYER)->x_speed -= 0x10u;
			LAYER(WORKING_LAYER)->y_speed -= 0x10u;
			if (LAYER(WORKING_LAYER)->x_speed >= 0x100u)
			{
				if (LAYER(WORKING_LAYER)->x + (int16_t)LAYER(WORKING_LAYER)->x_speed >= 0xA2800u && layer_loops >= 0)
				{
					LAYER(WORKING_LAYER)->x -= 0x40000u;
					LAYER(WORKING_LAYER)->y += 0x40000u;
					t1 = layer_loops + 1u;
					layer_loops = t1;
					if ((int8_t)t1 >= 0)
						layer_loops = -0x80;
				}
			}
			else
			{
				LAYER(WORKING_LAYER)->x_speed = 0x100u;
				LAYER(WORKING_LAYER)->y_speed = 0x100u;
			}
		}
	}
	else
	{
		LAYER(WORKING_LAYER)->x_speed += 4u;
		LAYER(WORKING_LAYER)->y_speed += 4u;
		if (LAYER(WORKING_LAYER)->x_speed < 0x400u)
		{
			if (LAYER(WORKING_LAYER)->x + (int16_t)LAYER(WORKING_LAYER)->x_speed >= 0xA2800u && layer_loops >= 0)
			{
				LAYER(WORKING_LAYER)->x -= 0x40000u;
				LAYER(WORKING_LAYER)->y += 0x40000u;
				t1 = layer_loops + 1u;
				layer_loops = t1;
				if ((int8_t)t1 >= 0)
					layer_loops = -0x80;
			}
		}
		else
		{
			LAYER(WORKING_LAYER)->x_speed = 0x400u;
			LAYER(WORKING_LAYER)->y_speed = 0x400u;
			if (LAYER(WORKING_LAYER)->x + (int16_t)LAYER(WORKING_LAYER)->x_speed >= 0xA2800u && layer_loops >= 0)
			{
				LAYER(WORKING_LAYER)->x -= 0x40000u;
				LAYER(WORKING_LAYER)->y += 0x40000u;
				t1 = layer_loops + 1u;
				layer_loops = t1;
				if ((int8_t)t1 >= 0)
					layer_loops = -0x80;
			}
		}
	}
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column(&ignored, p_d5, &d7);
	save_layer_b();
	place_lift_edge();
	if (scroll_mode >= 0)
	{
		d7 = (d7 & ~0xFFu) | 0x2Bu;
		queue_sound((uint8_t)d7, 0u);
		a0 = floor_map_ADDRESS + 0x30u;
		d0 = 0x10u;
		d1 = 0x20u;
		d3 = 0xFDu;
		do
		{
			a1 = a0;
			d2 = (uint8_t)d1;
			d1--;
			a0++;
			do
			{
				mem_write8(a1, d3);
				t2 = d2;
				d2 = (uint8_t)(t2 - 1u);
				a1 += 0x40u;
			} while (t2 != 1u);
			t3 = d0;
			d0 = (uint8_t)(t3 - 1u);
		} while (t3 != 1u);
		layers_step++;
	}
	*p_d7 = d7;
	*p_a1 = a1;
}

/* the layers after the ride, the floor map set again and the wall at the end */
void technodrome_leave_lift(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint8_t d0 = 0, d1 = 0, d2_2 = 0, d3 = 0;
	uint32_t a0 = 0, d2 = 0, ignored = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	load_layer_b();
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column(&ignored, p_d5, p_d7);
	save_layer_b();
	LAYER(LAYER_A)->x = LAYER(LAYER_B)->x - 0xA0000u;
	LAYER(LAYER_A)->new_column_x = LAYER(LAYER_B)->new_column_x - 0xA0000u;
	LAYER(LAYER_A)->new_column = LAYER(LAYER_B)->new_column;
	load_layer_a();
	working_layer_tiles = TILE_RAM + 0x2000u;
	draw_new_row_and_column(&ignored, p_d5, p_d7);
	save_layer_a();
	place_lift_edge();
	x = LAYER(LAYER_B)->x;
	if (x >= 0xC0000u)
	{
		if (x < 0xC0200u)
		{
			a0 = floor_map_ADDRESS + 0x30u;
			if (floor_map(48) != 0xFFu)
			{
				d2 = 0xFFFFFFFFu;
				d0 = 0x10u;
				fill_floor_map_rows(d0, d2, a0);
				a0 = floor_map_ADDRESS + 0x430u;
				d2 = 0x1010101u;
				d0 = 0x10u;
				fill_floor_map_rows(d0, d2, a0);
			}
			return;
		}
		if (floor_end_walled == 0u && LAYER(LAYER_B)->x >= 0xC9000u)
		{
			a0 = floor_map_ADDRESS + 0x38u;
			d0 = 0x10u;
			d1 = 0x10u;
			d3 = 0xFEu;
			do
			{
				d2_2 = (uint8_t)d1;
				d1++;
				*p_a1 = a0;
				a0++;
				if (a0 >= floor_map_ADDRESS + 0x40u)
					a0 = floor_map_ADDRESS;
				do
				{
					mem_write8(*p_a1, d3);
					t1 = d2_2;
					d2_2 = (uint8_t)(t1 - 1u);
					*p_a1 += 0x40u;
				} while (t1 != 1u);
				t2 = d0;
				d0 = (uint8_t)(t2 - 1u);
			} while (t2 != 1u);
			floor_end_walled--;
		}
	}
}

/* rows of the floor map filled with one kind of cell */
void fill_floor_map_rows(uint8_t d0, uint32_t d2, uint32_t a0)
{
	uint8_t d1 = 0;
	uint8_t t1 = 0, t2 = 0;

	do
	{
		d1 = 4u;
		do
		{
			mem_write32(a0, d2);
			t1 = d1;
			d1 = (uint8_t)(t1 - 1u);
			a0 += 4u;
		} while (t1 != 1u);
		t2 = d0;
		d0 = (uint8_t)(t2 - 1u);
		a0 += 0x30u;
	} while (t2 != 1u);
}

/* the lift's striped edge kept at its place while it is near */
void place_lift_edge(void)
{
	uint32_t d0 = 0, object = 0;
	uint32_t x = 0;

	object = OBJECT_ADDRESS(44);
	OBJECT(OBJECT_ADDRESS(44))->flags &= 0x7Fu;
	x = LAYER(LAYER_B)->x;
	d0 = 0xCE000u - x;
	if (x > 0xCE000u || d0 >= 0x1A000u)
		return;
	OBJECT(object)->screen_x = (d0 + 0x6000u) >> 8;
	OBJECT(object)->screen_y = (0x18000u - LAYER(LAYER_B)->y) >> 8;
	OBJECT(object)->flags |= 0x80u;
}

/* the highway's layer and the cars full of Foot soldiers */
void update_layers_highway(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t ignored = 0;

	load_layer_b();
	working_layer_tiles = TILE_RAM + 0x4000u;
	draw_new_row_and_column(&ignored, p_d5, p_d7);
	save_layer_b();
	LAYER(LAYER_A)->y = LAYER(LAYER_B)->y;
	switch (layers_step)
	{
	case 0:
		highway_first_car(p_d5, p_d7, p_a1);
		break;
	case 1:
		highway_first_car_drive(p_d5, p_d7, p_a1);
		break;
	case 2:
		highway_second_car(p_d5, p_d7, p_a1);
		break;
	case 3:
		highway_second_car_drive(p_d5, p_d7, p_a1);
		break;
	case 4:
		highway_third_car(p_d5, p_d7, p_a1);
		break;
	case 5:
		highway_third_car_drive(p_d5, p_d7, p_a1);
		break;
	case 6:
		highway_cars_over();
		break;
	}
	set_layers_scroll();
}

/* the first car full of Foot soldiers comes */
void highway_first_car(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint8_t d5 = (uint8_t)*p_d5;
	uint8_t d5_2 = 0;

	if (LAYER(LAYER_B)->x < 0x10000u)
		return;
	d5_2 = 0u;
	draw_screen_picture(d5_2, p_d7, p_a1);
	*p_d7 = start_foot_car(*p_d7);
	layers_step++;
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5_2;
}

/* the first car drives past */
void highway_first_car_drive(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint8_t d5 = 0;

	d5 = 0u;
	drive_foot_car(d5, p_d7, p_a1);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | d5;
}

/* the second car comes, in other colours */
void highway_second_car(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	if (LAYER(LAYER_B)->x < 0x30000u)
		return;
	*p_d5 = 0x40u;
	draw_screen_picture((uint8_t)*p_d5, p_d7, p_a1);
	*p_d7 = start_foot_car(*p_d7);
	layers_step++;
}

/* the second car drives past */
void highway_second_car_drive(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	*p_d5 = 0x40u;
	drive_foot_car((uint8_t)*p_d5, p_d7, p_a1);
}

/* the third car comes, in other colours */
void highway_third_car(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	if (LAYER(LAYER_B)->x < 0x50000u)
		return;
	*p_d5 = 0xFFFFFF80u;
	draw_screen_picture((uint8_t)*p_d5, p_d7, p_a1);
	*p_d7 = start_foot_car(*p_d7);
	layers_step++;
}

/* the third car drives past */
void highway_third_car_drive(uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1)
{
	*p_d5 = 0xFFFFFF80u;
	drive_foot_car((uint8_t)*p_d5, p_d7, p_a1);
}

/* no more cars */
void highway_cars_over(void)
{
}

/* the car's wheels turn and it drives across the screen */
void drive_foot_car(uint8_t d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d7 = *p_d7;
	uint32_t a1 = *p_a1;
	uint8_t d0 = 0;
	uint16_t d6 = 0;
	uint32_t a0 = 0, a2 = 0, a3 = 0, d0_2 = 0;
	uint16_t t3 = 0, t4 = 0;
	uint32_t t1 = 0, t2 = 0, x = 0;

	if ((frame_count & 3u) == 0u)
	{
		d0 = 0x34u;
		a2 = table_loaded_by_lea_01FBE0_ADDRESS;
		a3 = 0x1FBF0u;
		if ((frame_count & 4u) != 0u)
		{
			d0++;
			a2 = 0x1FC00u;
			a3 = 0x1FC10u;
		}
		a0 = TILE_RAM + 0x2A56u;
		a1 = TILE_RAM + 0x2A6Cu;
		d7 = 3u;
		d0 += d5;
		do
		{
			d6 = 3u;
			do
			{
				io_write8(a0, d0);
				io_write8(a1, d0);
				t1 = a2;
				a2++;
				a0++;
				io_write8(a0, DATA8(t1));
				t2 = a3;
				a3++;
				a1++;
				io_write8(a1, DATA8(t2));
				t3 = d6 - 1u;
				d6 = t3;
				a0++;
				a1++;
			} while (t3 != 0xFFFFu);
			t4 = d7 - 1u;
			d7 = t4;
			a0 += 0x78u;
			a1 += 0x78u;
		} while (t4 != 0xFFFFu);
	}
	d0_2 = (uint16_t)(0x480u - LAYER(LAYER_B)->x_speed);
	x = LAYER(LAYER_A)->x;
	LAYER(LAYER_A)->x = x - d0_2;
	if (x < d0_2)
	{
		LAYER(LAYER_A)->x = 0x1FFFFu;
		layers_step++;
	}
	*p_d7 = d7;
	*p_a1 = a1;
}

void draw_screen_picture(uint8_t d5, uint32_t *p_d7, uint32_t *p_a1)
{
	uint16_t d6 = 0;
	uint32_t a0 = 0, a1 = 0, a2 = 0, d7 = 0;
	uint16_t t4 = 0, t5 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0;

	a0 = TILE_RAM + 0x25D0u;
	a1 = screen_picture_colours_ADDRESS;
	a2 = screen_picture_tiles_ADDRESS;
	d7 = 0xCu;
	do
	{
		d6 = 0x17u;
		do
		{
			t1 = a0;
			a0++;
			io_write8(t1, DATA8(a1) + d5);
			t2 = a2;
			a2++;
			t3 = a0;
			a0++;
			io_write8(t3, DATA8(t2));
			t4 = d6 - 1u;
			d6 = t4;
			a1++;
		} while (t4 != 0xFFFFu);
		t5 = d7 - 1u;
		d7 = t5;
		a0 += 0x50u;
	} while (t5 != 0xFFFFu);
	d7 = (d7 & ~0xFFu) | 0x15u;
	queue_sound((uint8_t)d7, 0u);
	*p_d7 = d7;
	*p_a1 = a1;
}

/* the skateboard ride: the far background and the road scroll by themselves */
void update_layers_skateboard(uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t ignored = 0;

	load_layer_b();
	LAYER(WORKING_LAYER)->x += LAYER(WORKING_LAYER)->x_speed;
	LAYER(WORKING_LAYER)->x &= 0x1FF00u;
	save_layer_b();
	load_layer_a();
	switch (layers_step)
	{
	case 0:
		skateboard_road_first_loop();
		break;
	case 1:
		skateboard_road_to_second_loop();
		break;
	case 2:
		skateboard_road_second_loop();
		break;
	case 3:
		skateboard_road_to_third_loop();
		break;
	case 4:
		skateboard_road_third_loop();
		break;
	case 5:
		skateboard_road_last_loop();
		break;
	}
	working_layer_tiles = TILE_RAM + 0x2000u;
	draw_new_row_and_column(&ignored, p_d5, p_d7);
	save_layer_a();
	set_layers_scroll();
	OBJECT(OBJECT_ADDRESS(0))->contacts |= 0x80u;
	OBJECT(OBJECT_ADDRESS(1))->contacts |= 0x80u;
	OBJECT(OBJECT_ADDRESS(2))->contacts |= 0x80u;
	OBJECT(OBJECT_ADDRESS(3))->contacts |= 0x80u;
}

/* the road goes round its first stretch twenty times, then on */
void skateboard_road_first_loop(void)
{
	LAYER(WORKING_LAYER)->column_phase = 0u;
	if ((uint8_t)layer_loops == 0x14u)
	{
		if (LAYER(WORKING_LAYER)->x < 0xA200u)
			return;
		skateboard_road_go_on();
		return;
	}
	if ((LAYER(WORKING_LAYER)->x_page & 2u) == 0u)
		return;
	LAYER(WORKING_LAYER)->x &= 0x1FF00u;
	layer_loops++;
}

/* the road goes on to new stretches */
void skateboard_road_go_on(void)
{
	LAYER(WORKING_LAYER)->column_phase = (LAYER(WORKING_LAYER)->x & 0x700u) << 5;
	layer_loops = 0;
	layers_step++;
}

/* the road on to its second stretch */
void skateboard_road_to_second_loop(void)
{
	if (LAYER(WORKING_LAYER)->x >= 0x3A200u)
	{
		layers_step++;
		return;
	}
}

/* the road goes round its second stretch twenty times, then on */
void skateboard_road_second_loop(void)
{
	LAYER(WORKING_LAYER)->column_phase = 0u;
	if ((uint8_t)layer_loops == 0x14u)
	{
		if (LAYER(WORKING_LAYER)->x >= 0x3A200u)
		{
			skateboard_road_go_on();
			return;
		}
		return;
	}
	if (LAYER(WORKING_LAYER)->x < 0x50000u)
		return;
	LAYER(WORKING_LAYER)->x = 0x30000u;
	layer_loops++;
}

/* the road on to its third stretch */
void skateboard_road_to_third_loop(void)
{
	if (LAYER(WORKING_LAYER)->x < 0x6A200u)
		return;
	LAYER(WORKING_LAYER)->column_phase = 0u;
	layers_step++;
}

/* the road goes round its third stretch twenty times, then on */
void skateboard_road_third_loop(void)
{
	LAYER(WORKING_LAYER)->column_phase = 0u;
	if ((uint8_t)layer_loops == 0x14u)
	{
		if (LAYER(WORKING_LAYER)->x >= 0x6A200u)
		{
			skateboard_road_go_on();
			return;
		}
		skateboard_road_last_loop();
		return;
	}
	if (LAYER(WORKING_LAYER)->x < 0x80000u)
		return;
	LAYER(WORKING_LAYER)->x = 0x60000u;
	layer_loops++;
}

/* the road goes round its last stretch from then on */
void skateboard_road_last_loop(void)
{
	LAYER(WORKING_LAYER)->column_phase = 0u;
	if (LAYER(WORKING_LAYER)->x < 0xA0000u)
		return;
	LAYER(WORKING_LAYER)->x = 0x80000u;
}
