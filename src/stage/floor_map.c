/**
 *    Name:        stage/floor_map.c
 *    Description: the floor map's cells around an object, for the turtles, the enemies and the missiles
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void read_floor_cells_on_screen(uint32_t a0, uint32_t *p_d5, uint32_t *p_a5, uint32_t *p_a6)
{
	uint8_t d6 = 0;
	uint16_t d7 = 0;
	uint32_t d5 = 0;

	d7 = ((OBJECT(a0)->screen_x - 0x60u + ((LAYER(WORKING_LAYER)->x >> 8) & 0x1FFu)) & 0x1FFu) >> 3;
	d6 = (uint8_t)OBJECT(a0)->screen_y;
	read_floor_cells_at(d6, d7, a0, &d5, p_a5, p_a6);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void read_floor_cells(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a6)
{
	uint8_t d6 = 0;
	uint32_t d5 = 0, d7 = 0, ignored = 0;

	d7 = OBJECT(a0)->x >> 8;
	d7 = (d7 & ~0xFFFFu) | (uint16_t)(d7 - 0x60u);
	d7 = (d7 & ~0xFFFFu) | (uint16_t)(d7 + ((LAYER(WORKING_LAYER)->x >> 8) & 0x1FFu));
	d7 = d7 & ~0xFE00u;
	d7 = (d7 & ~0xFFFFu) | ((uint16_t)d7 >> 3);
	d6 = (uint8_t)(OBJECT(a0)->y >> 8u);
	read_floor_cells_at(d6, (uint16_t)d7, a0, &d5, &ignored, p_a6);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7;
}

void read_floor_cells_at(uint8_t d6, uint16_t d7, uint32_t a0, uint32_t *p_d5, uint32_t *p_a5, uint32_t *p_a6)
{
	uint16_t d5 = 0;
	uint32_t a4 = 0, a5 = 0, a6 = 0;

	d6 += OBJECT(a0)->floor_height;
	d5 = (uint16_t)((((uint8_t)(0u - (d6 + (OBJECT(a0)->height_whole - OBJECT(a0)->floor_height)) - LAYER(WORKING_LAYER)->y_pixel) & 0xF8u) << 3) + d7);
	a6 = floor_map_ADDRESS + (uint16_t)((((uint8_t)(0u - d6 - LAYER(WORKING_LAYER)->y_pixel) & 0xF8u) << 3) + d7);
	a5 = floor_map_ADDRESS + d5;
	floor_cell = mem_read8(a6);
	height_cell = mem_read8(a5);
	if (a6 < floor_map_ADDRESS + 0x40u)
		floor_cell_up = mem_read8(a6 + 0x7C0u);
	else
		floor_cell_up = mem_read8(a6 - 0x40u);
	if ((a6 & 0x3Fu) == 0x3Fu)
		floor_cell_right = mem_read8(a6 - 0x3Fu);
	else
		floor_cell_right = mem_read8(a6 + 1u);
	if ((a6 & 0x3Fu) == 0u)
		floor_cell_left = mem_read8(a6 + 0x3Fu);
	else
		floor_cell_left = mem_read8(a6 - 1u);
	a4 = a6;
	if (a6 < floor_map_ADDRESS + 0x40u)
		a4 += 0x800u;
	if ((a6 & 0x3Fu) == 0x3Fu)
		a4 -= 0x40u;
	floor_cell_up_right = mem_read8(a4 - 0x3Fu);
	a4 = a6;
	if (a6 < floor_map_ADDRESS + 0x40u)
		a4 += 0x800u;
	if ((a6 & 0x3Fu) == 0u)
		a4 += 0x40u;
	floor_cell_up_left = mem_read8(a4 - 0x41u);
	a4 = a6;
	if (a6 >= floor_map_ADDRESS + 0x7C0u)
		a4 -= 0x800u;
	floor_cell_down = mem_read8(a4 + 0x40u);
	if (a5 < floor_map_ADDRESS + 0x40u)
		height_cell_up = mem_read8(a5 + 0x7C0u);
	else
		height_cell_up = mem_read8(a5 - 0x40u);
	if ((a5 & 0x3Fu) == 0x3Fu)
		height_cell_right = mem_read8(a5 - 0x3Fu);
	else
		height_cell_right = mem_read8(a5 + 1u);
	if ((a5 & 0x3Fu) == 0u)
		height_cell_left = mem_read8(a5 + 0x3Fu);
	else
		height_cell_left = mem_read8(a5 - 1u);
	a4 = a5;
	if (a5 < floor_map_ADDRESS + 0x40u)
		a4 += 0x800u;
	if ((a5 & 0x3Fu) == 0x3Fu)
		a4 -= 0x40u;
	height_cell_up_right = mem_read8(a4 - 0x3Fu);
	a4 = a5;
	if (a5 < floor_map_ADDRESS + 0x40u)
		a4 += 0x800u;
	if ((a5 & 0x3Fu) == 0u)
		a4 += 0x40u;
	height_cell_up_left = mem_read8(a4 - 0x41u);
	if ((int8_t)(uint8_t)(OBJECT(a0)->y >> 24u) < 0)
		floor_cell = 0u;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_a5 = a5;
	*p_a6 = a6;
}
