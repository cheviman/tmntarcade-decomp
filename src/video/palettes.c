/**
 *    Name:        video/palettes.c
 *    Description: the palettes: requests queued and done a frame later, the palette effects
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint32_t post_palette_request(uint16_t d7, uint32_t a6)
{
	uint32_t palette_request = 0;

	palette_request = palette_queue_write;
	PALETTE_REQUEST(palette_request)->kind = d7;
	palette_request += 2u;
	PALETTE_REQUEST(palette_request - 0x2u)->data = a6;
	palette_request += 4u;
	if (palette_request > 0x60BEFu)
		palette_request = PALETTE_REQUEST_ADDRESS(0);
	palette_queue_write = palette_request;
	return palette_request;
}

void unreached_009264(uint32_t a4)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	for (;;)
	{
		d7 = mem_read16(a4);
		a4 += 2u;
		if (d7 == 0xFFFFu)
			break;
		a6 = mem_read32(a4);
		a4 += 4u;
		post_palette_request(d7, a6);
	}
}

/* a bank of the palette requests a frame: the one under way, or the next one queued */
void run_palette_requests(uint32_t d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t a6 = 0, d7_2 = 0, data = 0, ignored = 0, palette_request = 0;
	uint16_t kind = 0;
	uint32_t t1 = 0;

	if (palette_area_banks != 0u)
	{
		d7_2 = (d7 & ~0xFFu) | palette_area_banks;
		palette_request_area(&ignored, &d5, p_d6, &d7_2, p_a5);
	}
	else if (palette_set_banks != 0u)
	{
		d7_2 = (d7 & ~0xFFu) | palette_set_banks;
		a6 = palette_set;
		palette_request_set_next_bank(a6, &ignored, p_d6, &d7_2, p_a5);
	}
	else if (palette_black_banks != 0u)
	{
		d7_2 = (d7 & ~0xFFu) | palette_black_banks;
		palette_request_black(&ignored, p_d6, &d7_2, p_a5);
	}
	else if (palette_second_half == 0u)
	{
		palette_request = palette_queue_read;
		kind = PALETTE_REQUEST(palette_request)->kind;
		d0 = kind;
		if (kind != 0u)
		{
			d7_2 = (uint8_t)d0;
			data = PALETTE_REQUEST(palette_request)->data;
			d0 = (d0 & 0x3F00u) >> 6;
			PALETTE_REQUEST(palette_request)->kind = 0u;
			palette_request += 2u;
			PALETTE_REQUEST(palette_request - 0x2u)->data = 0u;
			palette_request += 4u;
			if (palette_request > 0x60BEFu)
				palette_request = PALETTE_REQUEST_ADDRESS(0);
			palette_queue_read = palette_request;
			switch (d0)
			{
			case 0:
			case 36:
				palette_request_none();
				break;
			case 4:
				palette_request_area(&ignored, &d5, p_d6, &d7_2, p_a5);
				break;
			case 8:
				palette_request_set(data, &ignored, p_d6, &d7_2, p_a5);
				break;
			case 12:
				palette_request_list(data, &ignored, p_d6, &d7_2, p_a5);
				break;
			case 16:
				palette_request_palette(d7_2, data, p_d6, p_a5);
				break;
			case 20:
				palette_request_colours((uint8_t)d7_2, data, p_d6, p_a5);
				break;
			case 24:
				palette_request_black(&ignored, p_d6, &d7_2, p_a5);
				break;
			case 28:
			case 32:
				palette_request_spare();
				break;
			}
		}
		palettes_busy = 0u;
		t1 = (((uint32_t)palette_area_banks << 24u) | ((uint32_t)palette_set_banks << 16u) | ((uint32_t)palette_black_banks << 8u) | palette_second_half);
		d7_2 = t1;
		if (t1 != 0u)
			palettes_busy = 1u;
	}
	else
	{
		d7_2 = palette_second_half;
		d7_2 = (uint16_t)(d7_2 << 2);
		switch (d7_2)
		{
		case 0:
		case 16:
		case 20:
		case 28:
		case 32:
			palette_request_none();
			break;
		case 4:
			palette_request_area_second_half(&ignored, &d5, p_d6, &d7_2, p_a5);
			break;
		case 8:
			palette_request_set_second_half(&ignored, p_d6, &d7_2, p_a5);
			break;
		case 12:
			palette_request_list_second_half(&ignored, p_d6, &d7_2, p_a5);
			break;
		case 24:
			palette_request_black_second_half(&ignored, p_d6, &d7_2, p_a5);
			break;
		}
		palette_second_half = 0u;
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d7 = d7_2;
}

/* a palette request that does nothing */
void palette_request_none(void)
{
}

/* the area's palettes into the banks asked for, a bank a frame */
void palette_request_area(uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d4 = (uint8_t)*p_d4;
	uint16_t d5 = (uint16_t)*p_d5;
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d6 = 0;

	a6 = area_palettes_ADDRESS;
	d6 = 0u;
	for (;;)
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) == 0u)
		{
			d6 = (uint8_t)(d6 + 1u);
			if (d6 < 4u)
				continue;
			palette_area_banks = 0u;
			break;
		}
		d4 = (uint8_t)d6;
		palette_area_banks = d7 & ~shl32(1u, (int)(d6 & 0x1Fu));
		d7 = palette_bank_counts[d6];
		d5 = (uint16_t)((uint32_t)stage << 2);
		d6 = (uint16_t)(d6 << 2);
		a6 = mem_read32(DATA32(a6 + d5) + d6);
		*p_a5 = palette_bank_addresses[d6 / 4u];
		if (palette_second_half != 0u)
		{
			*p_a5 += 0x200u;
			a6 += 0x20u;
		}
		if (d4 == 3u)
			palette_second_half = 1u;
		copy_palette_list((uint16_t)d7, a6, &d6, p_a5);
		break;
	}
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | d4;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_d6 = d6;
	*p_d7 = d7;
}

/* the second half of the sprites' palettes of the area's set */
void palette_request_area_second_half(uint32_t *p_d4, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d4 = *p_d4;
	uint32_t d5 = *p_d5;

	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	palette_request_area(&d4, &d5, p_d6, p_d7, p_a5);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | (d4 & 0xFFu);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

/* a set of palettes into the banks asked for, a bank a frame */
void palette_request_set(uint32_t a6, uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d4 = *p_d4;

	palette_set = a6;
	palette_request_set_next_bank(a6, &d4, p_d6, p_d7, p_a5);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | (d4 & 0xFFu);
}

/* the set's next bank */
void palette_request_set_next_bank(uint32_t a6, uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d4 = (uint8_t)*p_d4;
	uint32_t d7 = *p_d7;
	uint32_t a6_2 = 0, d6 = 0;

	d6 = 0u;
	for (;;)
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) == 0u)
		{
			d6 = (uint8_t)(d6 + 1u);
			if (d6 < 4u)
				continue;
			palette_set_banks = 0u;
			palette_set = 0u;
			break;
		}
		d4 = (uint8_t)d6;
		palette_set_banks = d7 & ~shl32(1u, (int)(d6 & 0x1Fu));
		d7 = palette_bank_counts[d6];
		d6 = (uint16_t)(d6 << 2);
		a6_2 = mem_read32(a6 + d6);
		*p_a5 = palette_bank_addresses[d6 / 4u];
		if (palette_second_half != 0u)
		{
			*p_a5 += 0x200u;
			a6_2 += 0x20u;
		}
		if (d4 == 3u)
			palette_second_half = 2u;
		copy_palette_list((uint16_t)d7, a6_2, &d6, p_a5);
		break;
	}
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | d4;
	*p_d6 = d6;
	*p_d7 = d7;
}

/* the second half of the sprites' palettes of the set */
void palette_request_set_second_half(uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d4 = *p_d4;
	uint32_t a6 = 0;

	a6 = palette_set;
	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	palette_request_set(a6, &d4, p_d6, p_d7, p_a5);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | (d4 & 0xFFu);
}

/* a list of palettes into one bank */
void palette_request_list(uint32_t a6, uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d4 = (uint8_t)*p_d4;
	uint32_t d7 = *p_d7;
	uint32_t d6 = 0;

	d6 = 0u;
	for (;;)
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) == 0u)
		{
			d6 = (uint8_t)(d6 + 1u);
			if (d6 >= 4u)
				break;
			continue;
		}
		d4 = (uint8_t)d6;
		d7 = palette_bank_counts[d6];
		*p_a5 = palette_bank_addresses[d6 & 0x3FFFu];
		if (palette_second_half != 0u)
		{
			*p_a5 += 0x200u;
			a6 += 0x20u;
		}
		if (d4 == 3u)
		{
			palette_set = a6;
			palette_second_half = 3u;
		}
		copy_palette_list((uint16_t)d7, a6, &d6, p_a5);
		break;
	}
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | d4;
	*p_d6 = d6;
	*p_d7 = d7;
}

/* the second half of the sprites' palettes of the list */
void palette_request_list_second_half(uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d4 = *p_d4;
	uint32_t a6 = 0;

	a6 = palette_set;
	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	palette_request_list(a6, &d4, p_d6, p_d7, p_a5);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | (d4 & 0xFFu);
}

/* sixteen colours into one palette */
void palette_request_palette(uint32_t d7, uint32_t a6, uint32_t *p_d6, uint32_t *p_a5)
{
	uint16_t d6 = 0;
	uint32_t a5 = 0, d6_2 = 0;
	uint16_t t1 = 0;

	d6 = (uint16_t)d7;
	d7 &= 0xFu;
	d6 = d6 & ~0xFu;
	a5 = TABLE32(palette_bank_addresses, d6 >> 2) + (uint16_t)(d7 << 6);
	d6_2 = 0xFu;
	do
	{
		mem_write8(a5 + 1u, mem_read8(a6));
		a6++;
		mem_write8(a5 + 3u, mem_read8(a6));
		t1 = d6_2 - 1u;
		d6_2 = t1;
		a6++;
		a5 += 4u;
	} while (t1 != 0xFFFFu);
	*p_d6 = d6_2;
	*p_a5 = a5;
}

/* single colours into a bank's palettes */
void palette_request_colours(uint8_t d7, uint32_t a6, uint32_t *p_d6, uint32_t *p_a5)
{
	uint16_t d6 = 0;
	uint32_t a4 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	d6 = (uint16_t)d7;
	d6 = d6 & ~0xFu;
	*p_a5 = TABLE32(palette_bank_addresses, d6 >> 2);
	for (;;)
	{
		t1 = mem_read8(a6);
		*p_d6 = t1;
		a6++;
		if ((int8_t)t1 < 0)
			break;
		d7_2 = mem_read8(a6);
		a4 = *p_a5 + (uint16_t)(*p_d6 << 6) + (uint16_t)(d7_2 << 2);
		a6++;
		mem_write8(a4 + 1u, mem_read8(a6));
		a6++;
		mem_write8(a4 + 3u, mem_read8(a6));
		a6++;
	}
}

/* the banks asked for turned black, a bank a frame */
void palette_request_black(uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d4 = (uint8_t)*p_d4;
	uint32_t d7 = *p_d7;
	uint32_t d6 = 0;

	d6 = 0u;
	for (;;)
	{
		if ((d7 & shl32(1u, (int)(d6 & 0x1Fu))) == 0u)
		{
			d6 = (uint8_t)(d6 + 1u);
			if (d6 < 4u)
				continue;
			palette_black_banks = 0u;
			break;
		}
		d4 = (uint8_t)d6;
		palette_black_banks = d7 & ~shl32(1u, (int)(d6 & 0x1Fu));
		d7 = palette_bank_counts[d6];
		*p_a5 = palette_bank_addresses[d6 & 0x3FFFu];
		if (palette_second_half != 0u)
			*p_a5 += 0x200u;
		if (d4 == 3u)
			palette_second_half = 6u;
		blacken_palettes((uint16_t)d7, &d6, p_a5);
		break;
	}
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | d4;
	*p_d6 = d6;
	*p_d7 = d7;
}

/* the second half of the sprites' palettes turned black */
void palette_request_black_second_half(uint32_t *p_d4, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d4 = *p_d4;

	*p_d7 = (*p_d7 & ~0xFFu) | 8u;
	palette_request_black(&d4, p_d6, p_d7, p_a5);
	*p_d4 = (*p_d4 & 0xFFFFFF00u) | (d4 & 0xFFu);
}

/* a spare palette request kind that does nothing */
void palette_request_spare(void)
{
}

void copy_palette_list(uint16_t d7, uint32_t a6, uint32_t *p_d6, uint32_t *p_a5)
{
	uint32_t a5 = *p_a5;
	uint32_t a4 = 0, d6 = 0;
	uint16_t t1 = 0, t2 = 0;

	do
	{
		d6 = 0xFu;
		a4 = mem_read32(a6);
		a6 += 4u;
		do
		{
			mem_write8(a5 + 1u, mem_read8(a4));
			a4++;
			mem_write8(a5 + 3u, mem_read8(a4));
			a5 += 4u;
			t1 = d6 - 1u;
			d6 = t1;
			a4++;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
	*p_d6 = d6;
	*p_a5 = a5;
}

/* palettes turned black */
void blacken_palettes(uint16_t d7, uint32_t *p_d6, uint32_t *p_a5)
{
	uint32_t a5 = *p_a5;
	uint32_t d6 = 0;
	uint16_t t1 = 0, t2 = 0;

	do
	{
		d6 = 0xFu;
		do
		{
			mem_write8(a5 + 1u, 0u);
			mem_write8(a5 + 3u, 0u);
			t1 = d6 - 1u;
			d6 = t1;
			a5 += 4u;
		} while (t1 != 0xFFFFu);
		t2 = d7 - 1u;
		d7 = t2;
	} while (t2 != 0xFFFFu);
	*p_d6 = d6;
	*p_a5 = a5;
}

/* the palettes faded toward a list of palette sets, over the next frames */
void copy_palette_sets(uint16_t d6, uint32_t a5)
{
	switch ((uint32_t)(int8_t)fade_pass_step)
	{
	case 0:
		fade_palettes_start(d6, a5);
		return;
	case 1:
		fade_palettes_read();
		return;
	case 3:
		fade_palettes_write();
		return;
	case 2:
		fade_palettes_step();
		return;
	}
}

/* a fade toward a set of palettes starts */
void fade_palettes_start(uint16_t d6, uint32_t a5)
{
	fading = 1u;
	fade_pass_step++;
	fade_part = 0u;
	fade_lists_left = 0u;
	fade_part_mask = (uint8_t)(d6 >> 8u);
	fade_rate = (uint8_t)d6;
	fade_target = a5;
	fade_buffer_place = 0x63800u;
	fade_palettes_read();
}

/* a part of the palettes read into the fade's buffer */
void fade_palettes_read(void)
{
	uint32_t a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0;

	for (;;)
	{
		d7 = fade_part;
		if ((fade_part_mask & shl32(1u, (int)(d7 & 7u))) != 0u)
		{
			fade_palettes_part(&d7, &a5, &a6);
			do
			{
				mem_write8(a5, mem_read8(a6 + 1u));
				a5++;
				mem_write8(a5, mem_read8(a6 + 3u));
				t1 = d7 - 1u;
				d7 = t1;
				a5++;
				a6 += 4u;
			} while (t1 != 0xFFFFu);
			fade_buffer_place = a5;
			fade_part++;
			if (fade_part < 5u)
				break;
			fade_pass_step++;
			fade_part = 0u;
			fade_lists_left = 0u;
			fade_buffer_place = 0x63800u;
			break;
		}
		fade_part++;
		if (fade_part < 5u)
			continue;
		fade_pass_step++;
		fade_part = 0u;
		fade_lists_left = 0u;
		fade_buffer_place = 0x63800u;
		return;
	}
}

/* the fade's colours written back into a part of the palettes */
void fade_palettes_write(void)
{
	uint32_t a5 = 0, a6 = 0, d7 = 0;
	uint16_t t1 = 0;

	for (;;)
	{
		d7 = fade_part;
		if ((fade_part_mask & shl32(1u, (int)(d7 & 7u))) != 0u)
		{
			fade_palettes_part(&d7, &a5, &a6);
			do
			{
				mem_write8(a6 + 1u, mem_read8(a5));
				a5++;
				mem_write8(a6 + 3u, mem_read8(a5));
				t1 = d7 - 1u;
				d7 = t1;
				a5++;
				a6 += 4u;
			} while (t1 != 0xFFFFu);
			fade_buffer_place = a5;
			fade_part++;
			if (fade_part < 5u)
				break;
			fade_state = 0u;
			break;
		}
		fade_part++;
		if (fade_part < 5u)
			continue;
		fade_state = 0u;
		return;
	}
}

/* where a part of the palettes is and how many colours it has */
void fade_palettes_part(uint32_t *p_d7, uint32_t *p_a5, uint32_t *p_a6)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint16_t d7_2 = 0;

	*p_a6 = indexed_table_of_32_bit_values_00975C[d7 & 0x3FFFu];
	d7_2 = 0x7Fu;
	*p_a5 = fade_buffer_place;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_2;
}

/* a part of the fade's colours a step toward the target palettes */
void fade_palettes_step(void)
{
	uint16_t d0 = 0, d1 = 0, d6 = 0;
	uint32_t a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, d5 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	a6 = fade_buffer_place;
	d0 = fade_rate & 0xFu;
	a5 = fade_target;
	while ((fade_part_mask & shl32(1u, (int)(fade_part & 7u))) == 0u)
	{
		fade_part++;
		if (fade_part >= 5u)
		{
			fade_buffer_place = 0x63800u;
			fade_pass_step++;
			fade_part = 0u;
			fade_lists_left = 0u;
			return;
		}
	}
	d6 = fade_part;
	if (d6 == 4u)
		d6 = 3u;
	a4 = DATA32(a5 + (uint16_t)((uint32_t)d6 << 2));
	fade_lists_left = 8u;
	do
	{
		a3 = mem_read32(a4);
		d6 = 0xFu;
		a4 += 4u;
		do
		{
			d1 = mem_read16(a6);
			a2 = table_loaded_by_lea_009872_ADDRESS;
			d5 = 0u;
			fade_colour_part(d0, d1, a3, &d5, &a2);
			fade_colour_part(d0, d1, a3, &d5, &a2);
			fade_colour_part(d0, d1, a3, &d5, &a2);
			mem_write16(a6, d5);
			t1 = d6 - 1u;
			d6 = t1;
			a6 += 2u;
			a3 += 2u;
		} while (t1 != 0xFFFFu);
		t2 = fade_lists_left;
		fade_lists_left = t2 - 1u;
	} while (t2 != 1u);
	fade_part++;
	if (fade_part >= 5u)
	{
		fade_buffer_place = 0x63800u;
		fade_pass_step++;
		fade_part = 0u;
		fade_lists_left = 0u;
		return;
	}
	fade_buffer_place = a6;
}

/* a colour's red, green or blue a step toward the target's */
void fade_colour_part(uint16_t d0, uint16_t d1, uint32_t a3, uint32_t *p_d5, uint32_t *p_a2)
{
	uint16_t d5 = (uint16_t)*p_d5;
	uint32_t a2 = *p_a2;
	uint16_t d2 = 0, d3 = 0, d4 = 0, d7 = 0;
	uint16_t t1 = 0;

	d3 = mem_read16(a2);
	d2 = d1 & d3;
	a2 += 2u;
	d4 = (uint16_t)((uint32_t)d0 * mem_read16(a2));
	d7 = mem_read16(a3) & d3;
	a2 += 2u;
	if (d2 != d7)
	{
		if (d7 <= d2)
		{
			t1 = d2;
			d2 = (uint16_t)(t1 - d4);
			if (t1 < (uint16_t)d4)
				d2 = 0u;
			if (d2 < d7)
				d2 = (uint16_t)d7;
		}
		else
		{
			d2 += d4;
			if (d7 <= d2)
				d2 = (uint16_t)d7;
		}
	}
	d5 |= d2;
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
	*p_a2 = a2;
}

void start_palette_effects(uint32_t a6)
{
	uint16_t d5 = 0, d6 = 0, d7 = 0;
	uint32_t a3 = 0, a4 = 0, palette_effect = 0;
	uint16_t t1 = 0;

	d7 = (uint16_t)(mem_read16(a6) - 1u);
	palette_effect = PALETTE_EFFECT_ADDRESS(0);
	a6 += 2u;
	for (;;)
	{
		if ((PALETTE_EFFECT(palette_effect)->flags & 0x80u) == 0u)
		{
			a4 = mem_read32(a6);
			d6 = mem_read16(a4);
			d5 = (d6 & 0xF00u) >> 6;
			a3 = TABLE32(indexed_table_of_32_bit_values_0098F2, d5) + (uint16_t)((d6 & 0xF0u) << 2) + (uint16_t)((d6 & 0xFu) << 2);
			PALETTE_EFFECT(palette_effect)->time = 0u;
			PALETTE_EFFECT(palette_effect)->flags = (d5 >> 2) | 0x80u;
			PALETTE_EFFECT(palette_effect)->step = a4 + 2u;
			PALETTE_EFFECT(palette_effect)->colour = a3;
			t1 = d7 - 1u;
			d7 = t1;
			a6 += 4u;
			if (t1 != 0xFFFFu)
				continue;
			break;
		}
		palette_effect += 0xAu;
		if (palette_effect >= 0x60700u)
			break;
	}
}

void step_palette_effects(void)
{
	uint32_t carry = 0;
	uint16_t d6 = 0, d7 = 0;
	uint32_t a5 = 0, colour = 0, palette_effect = 0;
	uint8_t time = 0;
	uint16_t t1 = 0, t2 = 0;

	palette_effect = PALETTE_EFFECT_ADDRESS(0);
	d7 = 0x3Fu;
	do
	{
		if ((PALETTE_EFFECT(palette_effect)->flags & 0x80u) != 0u)
		{
			time = PALETTE_EFFECT(palette_effect)->time;
			carry = time == 0u;
			PALETTE_EFFECT(palette_effect)->time = time - 1u;
			if (time == 1u || carry)
			{
				for (;;)
				{
					a5 = PALETTE_EFFECT(palette_effect)->step;
					t1 = DATA16(a5);
					d6 = t1;
					if ((int16_t)t1 < 0)
					{
						PALETTE_EFFECT(palette_effect)->flags = 0u;
						PALETTE_EFFECT(palette_effect)->time = 0u;
						PALETTE_EFFECT(palette_effect)->step = 0u;
						PALETTE_EFFECT(palette_effect)->colour = 0u;
						break;
					}
					if ((d6 & 0x4000u) != 0u)
					{
						PALETTE_EFFECT(palette_effect)->step = DATA32(a5 + 2u);
						continue;
					}
					if ((d6 & 0x2000u) != 0u)
						PALETTE_EFFECT(palette_effect)->flags |= 0x40u;
					else if ((d6 & 0x1000u) != 0u)
						PALETTE_EFFECT(palette_effect)->flags &= 0xBFu;
					PALETTE_EFFECT(palette_effect)->time = (uint8_t)d6;
					colour = PALETTE_EFFECT(palette_effect)->colour;
					io_write8(colour + 1u, DATA8(a5 + 2u));
					io_write8(colour + 3u, DATA8(a5 + 3u));
					if ((PALETTE_EFFECT(palette_effect)->flags & 0x40u) != 0u)
						a5 -= 4u;
					else
						a5 += 4u;
					PALETTE_EFFECT(palette_effect)->step = a5;
					break;
				}
			}
		}
		t2 = d7 - 1u;
		d7 = t2;
		palette_effect += 0xAu;
	} while (t2 != 0xFFFFu);
}

void unreached_0099B4(uint8_t d7)
{
	uint16_t d5 = 0, d6 = 0;
	uint32_t a5 = 0, palette_effect = 0;
	uint8_t flags = 0;
	uint16_t t1 = 0;
	uint32_t jump_target = 0;

	palette_effect = PALETTE_EFFECT_ADDRESS(0);
	d6 = 0x3Fu;
	do
	{
		a5 = indexed_table_of_32_bit_values_0099F0_ADDRESS;
		flags = PALETTE_EFFECT(palette_effect)->flags;
		d5 = flags;
		if ((int8_t)flags < 0)
		{
			jump_target = DATA32(a5 + (uint16_t)((d5 & 3u) << 2));
			switch (jump_target)
			{
			case 0x009A00u:
				stop_fixed_layer_effect(d7, palette_effect);
				break;
			case 0x009A0Eu:
				stop_layer_a_effect(d7, palette_effect);
				break;
			case 0x009A18u:
				stop_layer_b_effect(d7, palette_effect);
				break;
			case 0x009A22u:
				stop_sprite_effect(d7, palette_effect);
				break;
			}
		}
		t1 = d6 - 1u;
		d6 = t1;
		palette_effect += 0xAu;
	} while (t1 != 0xFFFFu);
}

/* the effect stopped if the fixed layer's palettes are asked for */
void stop_fixed_layer_effect(uint8_t d7, uint32_t a6)
{
	if ((d7 & 1u) == 0u)
		return;
	clear_palette_effect(a6);
}

/* the effect stopped if layer A's palettes are asked for */
void stop_layer_a_effect(uint8_t d7, uint32_t a6)
{
	if ((d7 & 2u) == 0u)
		return;
	clear_palette_effect(a6);
}

/* the effect stopped if layer B's palettes are asked for */
void stop_layer_b_effect(uint8_t d7, uint32_t a6)
{
	if ((d7 & 4u) == 0u)
		return;
	clear_palette_effect(a6);
}

/* the effect stopped if the sprites' palettes are asked for */
void stop_sprite_effect(uint8_t d7, uint32_t a6)
{
	if ((d7 & 8u) == 0u)
		return;
	clear_palette_effect(a6);
}

/* a palette effect stopped */
void clear_palette_effect(uint32_t a6)
{
	PALETTE_EFFECT(a6)->flags = 0u;
	PALETTE_EFFECT(a6)->time = 0u;
	PALETTE_EFFECT(a6)->step = 0u;
	PALETTE_EFFECT(a6)->colour = 0u;
}

/* every palette effect stopped */
void clear_palette_effects(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;
	uint16_t t1 = 0;

	a6 = PALETTE_EFFECT_ADDRESS(0);
	d7 = 0x40u;
	do
	{
		clear_palette_effect(a6);
		t1 = d7 - 1u;
		d7 = t1;
		a6 += 0xAu;
	} while (t1 != 0xFFFFu);
}

/* the palettes of the attract mode's screen asked for */
void request_game_step_palettes(void)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	a6 = palettes_009A7C[game_step];
	d7 = 0x20Fu;
	post_palette_request(d7, a6);
}

void unreached_009AA0(void)
{
	start_game_step_palette_effects();
}

/* the palette effects of the attract mode's screen started */
void start_game_step_palette_effects(void)
{
	uint32_t a0 = 0, a6 = 0;

	a0 = palette_effects_009AD2[game_step];
	for (;;)
	{
		a6 = mem_read32(a0);
		a0 += 4u;
		if (a6 == 0u)
			break;
		start_palette_effects(a6);
	}
}

/* the area's palette effects started */
void start_area_palette_effects(void)
{
	uint32_t a0 = 0;

	a0 = palette_effects_009B28[stage];
	start_palette_effect_lists(a0);
}

/* every effect of a list of effect lists started */
void start_palette_effect_lists(uint32_t a0)
{
	uint32_t a6 = 0;

	for (;;)
	{
		a6 = mem_read32(a0);
		a0 += 4u;
		if (a6 == 0u)
			break;
		start_palette_effects(a6);
	}
}
