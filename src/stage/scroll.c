/**
 *    Name:        stage/scroll.c
 *    Description: the areas' scroll segments: the layers' limits and speeds
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint32_t start_scroll_segment(uint32_t d7)
{
	uint32_t negative = 0;
	uint16_t d0 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	d0 = stage;
	a6 = mem_read32(area_scroll_segments[(uint8_t)((uint32_t)d0 << 2) / 4u] + (int16_t)scroll_segment);
	t1 = mem_read8(a6);
	negative = t1 >> 7;
	scroll_mode = t1;
	if (t1 == 0u)
		return check_area_cleared(d7);
	if (negative == 0u)
	{
		scroll_held = mem_read32(a6 + 6u);
		LAYER(LAYER_A)->x_max = mem_read32(a6 + 0xAu);
		LAYER(LAYER_A)->y_max = mem_read32(a6 + 0xEu);
		LAYER(LAYER_B)->x_max = mem_read32(a6 + 0x12u);
		LAYER(LAYER_B)->y_max = mem_read32(a6 + 0x16u);
		LAYER(LAYER_A)->x_min = mem_read32(a6 + 0x1Au);
		LAYER(LAYER_A)->y_min = mem_read32(a6 + 0x1Eu);
		LAYER(LAYER_B)->x_min = mem_read32(a6 + 0x22u);
		LAYER(LAYER_B)->y_min = mem_read32(a6 + 0x26u);
		if (indexed_table_of_8_bit_values_01A3C0[stage] != 0u)
		{
			LAYER(WORKING_LAYER)->x_max = LAYER(LAYER_B)->x_max;
			LAYER(WORKING_LAYER)->y_max = LAYER(LAYER_B)->y_max;
			LAYER(WORKING_LAYER)->x_min = LAYER(LAYER_B)->x_min;
			LAYER(WORKING_LAYER)->y_min = LAYER(LAYER_B)->y_min;
			return d7;
		}
		LAYER(WORKING_LAYER)->x_max = LAYER(LAYER_A)->x_max;
		LAYER(WORKING_LAYER)->y_max = LAYER(LAYER_A)->y_max;
		LAYER(WORKING_LAYER)->x_min = LAYER(LAYER_A)->x_min;
		LAYER(WORKING_LAYER)->y_min = LAYER(LAYER_A)->y_min;
		return d7;
	}
	LAYER(LAYER_A)->x_speed = mem_read16(a6 + 6u);
	LAYER(LAYER_A)->y_speed = mem_read16(a6 + 8u);
	LAYER(LAYER_B)->x_speed = mem_read16(a6 + 0xAu);
	LAYER(LAYER_B)->y_speed = mem_read16(a6 + 0xCu);
	LAYER(WORKING_LAYER)->y_direction = mem_read8(a6 + 0xEu);
	LAYER(LAYER_A)->y_direction = mem_read8(a6 + 0xEu);
	LAYER(LAYER_B)->y_direction = mem_read8(a6 + 0xEu);
	LAYER(WORKING_LAYER)->x_direction = mem_read8(a6 + 0xFu);
	LAYER(LAYER_A)->x_direction = mem_read8(a6 + 0xFu);
	LAYER(LAYER_B)->x_direction = mem_read8(a6 + 0xFu);
	if (indexed_table_of_8_bit_values_01A3C0[stage] != 0u)
	{
		LAYER(WORKING_LAYER)->x_speed = LAYER(LAYER_B)->x_speed;
		LAYER(WORKING_LAYER)->y_speed = LAYER(LAYER_B)->y_speed;
		return d7;
	}
	LAYER(WORKING_LAYER)->x_speed = LAYER(LAYER_A)->x_speed;
	LAYER(WORKING_LAYER)->y_speed = LAYER(LAYER_A)->y_speed;
	return d7;
}

uint32_t auto_scroll(uint32_t d1, uint32_t a0)
{
	uint32_t carry = 0;
	uint32_t d0 = 0, d1_2 = 0;
	uint16_t column_phase = 0, column_phase_2 = 0, row_phase = 0, row_phase_2 = 0;

	if (scroll_mode >= 0)
		return d1;
	d0 = LAYER(WORKING_LAYER)->x_speed;
	d1_2 = (d1 & ~0xFFFFu) | d0;
	d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(d1_2 << 5);
	if ((uint8_t)LAYER(WORKING_LAYER)->x_direction != 0u)
	{
		if (LAYER(WORKING_LAYER)->x_direction < 0)
		{
			LAYER(WORKING_LAYER)->x += d0;
			d0 = LAYER(WORKING_LAYER)->x + 0x15800u;
			column_phase = LAYER(WORKING_LAYER)->column_phase;
			carry = (uint16_t)(column_phase + d1_2) < column_phase;
			LAYER(WORKING_LAYER)->column_phase = column_phase + d1_2;
			if (carry)
			{
				LAYER(WORKING_LAYER)->new_column_x = d0;
				LAYER(WORKING_LAYER)->new_column--;
			}
		}
		else
		{
			LAYER(WORKING_LAYER)->x -= d0;
			d0 = LAYER(WORKING_LAYER)->x - 0x1800u;
			column_phase_2 = LAYER(WORKING_LAYER)->column_phase;
			LAYER(WORKING_LAYER)->column_phase = column_phase_2 - d1_2;
			if (column_phase_2 < (uint16_t)d1_2)
			{
				LAYER(WORKING_LAYER)->new_column_x = d0;
				LAYER(WORKING_LAYER)->new_column--;
			}
		}
	}
	d0 = LAYER(WORKING_LAYER)->y_speed;
	d1_2 = (d1_2 & ~0xFFFFu) | d0;
	d1_2 = (d1_2 & ~0xFFFFu) | (uint16_t)(d1_2 << 5);
	if ((uint8_t)LAYER(WORKING_LAYER)->y_direction == 0u)
		return d1_2;
	if (LAYER(WORKING_LAYER)->y_direction < 0)
	{
		LAYER(WORKING_LAYER)->y -= d0;
		d0 = LAYER(WORKING_LAYER)->y - 0xF800u;
		row_phase = LAYER(WORKING_LAYER)->row_phase;
		LAYER(WORKING_LAYER)->row_phase = row_phase - d1_2;
		if (row_phase < (uint16_t)d1_2)
			return queue_scroll_row(d0, d1_2, a0);
		return d1_2;
	}
	LAYER(WORKING_LAYER)->y += d0;
	d0 = LAYER(WORKING_LAYER)->y;
	row_phase_2 = LAYER(WORKING_LAYER)->row_phase;
	carry = (uint16_t)(row_phase_2 + d1_2) < row_phase_2;
	LAYER(WORKING_LAYER)->row_phase = row_phase_2 + d1_2;
	if (carry)
		return queue_scroll_row(d0, d1_2, a0);
	return d1_2;
}

/* every frame of play: the time without a knock-out, the difficulty it adds, the balloon's time */
void update_time_without_knockout(uint32_t d6, uint32_t *p_d1, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t carry = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	time_without_knockout++;
	difficulty_from_time = (uint8_t)(time_without_knockout >> 8u) >> 5;
	if (balloon_time == 0u)
		hold_scroll_for_enemies(p_d1, &carry);
	else
	{
		t1 = balloon_time;
		balloon_time = t1 - 1u;
		if (t1 != 1u)
			hold_scroll_for_enemies(p_d1, &carry);
		else
		{
			erase_balloon(&d5, &ignored, p_d7);
			hold_scroll_for_enemies(p_d1, &carry);
		}
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

/* the scroll is held while more enemies are on the screen than the stage allows at this difficulty */
void hold_scroll_for_enemies(uint32_t *p_d1, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t d0 = 0;
	uint32_t d1 = 0;

	d1 = stage;
	d1 = (uint16_t)(d1 << 3);
	d1 = (d1 & ~0xFFu) | DATA8(0x2F67Cu + d1 + difficulty);
	d0 = 0u;
	switch (stage)
	{
	case 0:
		carry = hold_scroll_building(d0, (uint8_t)d1);
		break;
	case 1:
		carry = hold_scroll_apartment(d0, (uint8_t)d1);
		break;
	case 2:
		carry = hold_scroll_street(d0, (uint8_t)d1);
		break;
	case 3:
		carry = hold_scroll_sewer(d0, (uint8_t)d1);
		break;
	case 4:
		carry = hold_scroll_car_street(d0, (uint8_t)d1);
		break;
	case 5:
		carry = hold_scroll_highway(d0, (uint8_t)d1);
		break;
	case 6:
		carry = hold_scroll_skateboard((uint8_t)d1);
		break;
	case 7:
		carry = hold_scroll_building_site(d0, (uint8_t)d1);
		break;
	case 8:
		carry = hold_scroll_technodrome(d0, (uint8_t)d1);
		break;
	case 9:
		carry = hold_scroll_final(d0, (uint8_t)d1);
		break;
	}
	*p_d1 = d1;
	*p_carry = carry;
}

/* the burning building's scroll held while the screen has too many enemies */
uint32_t hold_scroll_building(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < enemies_on_screen || building_scroll_hold != 0u)
		d0--;
	carry = 0u;
	scroll_held_right = d0;
	return carry;
}

/* the apartment's scroll held while the screen has too many enemies */
uint32_t hold_scroll_apartment(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < enemies_on_screen)
		d0--;
	carry = 0u;
	scroll_held_right = d0;
	return carry;
}

/* the street's scroll held, right and down, while the screen has too many enemies */
uint32_t hold_scroll_street(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < enemies_on_screen)
		d0--;
	scroll_held_down = d0;
	carry = 0u;
	scroll_held_right = d0;
	return carry;
}

/* the sewer's scroll held while the screen has too many enemies */
uint32_t hold_scroll_sewer(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < enemies_on_screen)
		d0--;
	carry = 0u;
	scroll_held_right = d0;
	return carry;
}

/* the parked cars' street's scroll held while the screen has too many enemies */
uint32_t hold_scroll_car_street(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < enemies_on_screen)
		d0--;
	carry = 0u;
	scroll_held_right = d0;
	return carry;
}

/* the highway's scroll held while the screen has too many enemies */
uint32_t hold_scroll_highway(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < enemies_on_screen)
		d0--;
	carry = 0u;
	scroll_held_right = d0;
	return carry;
}

/* the skateboard ride is never held */
uint32_t hold_scroll_skateboard(uint8_t d1)
{
	uint32_t carry = 0;

	carry = (uint8_t)d1 < enemies_on_screen;
	return carry;
}

/* the building site's scroll held while the screen has too many enemies, unless the drill is arriving */
uint32_t hold_scroll_building_site(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	carry = 0u;
	if ((uint8_t)drill_arrival != 0u && drill_arrival >= 0)
		return carry;
	if ((uint8_t)d1 < enemies_on_screen)
		d0--;
	carry = 0u;
	scroll_held_right = d0;
	return carry;
}

/* the Technodrome's scroll held on its middle stretch, and while the screen has too many enemies */
uint32_t hold_scroll_technodrome(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((LAYER(LAYER_B)->x < 0xB8000u && LAYER(LAYER_B)->x >= 0x58000u) || (uint8_t)d1 < enemies_on_screen)
		d0--;
	carry = 0u;
	scroll_held_right = d0;
	return carry;
}

/* the last area's scroll held while the screen has too many enemies */
uint32_t hold_scroll_final(uint8_t d0, uint8_t d1)
{
	uint32_t carry = 0;

	if ((uint8_t)d1 < enemies_on_screen)
		d0--;
	carry = 0u;
	scroll_held_right = d0;
	return carry;
}
