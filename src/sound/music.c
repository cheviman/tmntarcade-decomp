/**
 *    Name:        music.c
 *    Description: the music: the random bytes, the tracks' tick, their commands and notes, the note hooks
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

uint16_t next_random_byte(void)
{
	uint16_t hl = 0;

	z80_block(53);
	hl = random_read;
	hl = (hl & ~0xFFu) | (uint8_t)(hl + 1u);
	random_read = hl;
	return hl;
}

uint32_t music_track_start(uint16_t ix)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0, b = 0, chip_channel = 0, e = 0;
	uint16_t hl = 0;
	uint16_t saved_ix = 0;

	z80_block(36);
	chip_channel = CHANNEL(ix)->chip_channel;
	if (chip_channel < 8u)
	{
		z80_block(17);
		zero = (uint8_t)(chip_channel - 6u) == 0u;
		if (chip_channel < 6u)
		{
			z80_block(17);
			fm_key_off(ix);
			z80_block(17);
			carry = fm_fast_release(ix);
		}
		else
		{
			z80_block(23);
			a = unk_8341;
			if (zero == 0u)
			{
				z80_block(13);
				a = unk_8381;
			}
			z80_block(14);
			if (a == 0u)
			{
				z80_block(17);
				fm_key_off(ix);
				z80_block(17);
				carry = fm_fast_release(ix);
			}
		}
	}
	z80_block(53);
	saved_ix = ix;
	b = 0x2Eu;
	hl = saved_ix + 0x12u;
	for (;;)
	{
		z80_block(24);
		z80_write8(hl, 0u);
		hl++;
		b--;
		if (b == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(139);
	e = CHANNEL(ix)->chip_channel;
	e = ((uint32_t)e << 1) | (e >> 7);
	hl = song_header;
	carry = (uint16_t)(hl + e) < hl;
	hl += e;
	AS8(CHANNEL(ix)->unk_10) = z80_read8(hl);
	AT8(CHANNEL(ix)->unk_10, 1) = z80_read8((uint16_t)(hl + 1u));
	hl = 0x8CDu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t music_track_first_tick(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x8D6u;
	set_channel_handler(hl, ix);
	z80_block(10);
	return read_track(ix);
}

uint32_t music_track_tick(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, bc_2 = 0, c = 0, d = 0, e = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;
	uint32_t jump_target = 0;

	z80_block(36);
	if (CHANNEL(ix)->chip_channel == 1u)
	{
		z80_cycles(7);
		accelerando_tick();
	}
	z80_block(44);
	t1 = tempo_increase + tempo;
	a = t1;
	if (t1 == 0u)
		return stop_channel(ix);
	z80_block(67);
	CHANNEL(ix)->unk_14 = a;
	t2 = CHANNEL(ix)->unk_12;
	t3 = a;
	CHANNEL(ix)->unk_12 = t3 + t2;
	if ((uint8_t)(t3 + t2) < t3)
	{
		z80_block(33);
		t4 = CHANNEL(ix)->unk_13;
		CHANNEL(ix)->unk_13 = t4 - 1u;
		if (t4 == 1u)
			return read_track(ix);
	}
	z80_block(30);
	if (((CHANNEL(ix)->chip_channel >> 3) & 1u) != 0u)
	{
		z80_block(43);
		a = unk_8281;
		if (CHANNEL(ix)->chip_channel & 1u)
		{
			z80_block(13);
			a = unk_82C1;
		}
		z80_block(9);
		carry = 0u;
		if (a != 0u)
		{
			z80_cycles(6);
			return carry;
		}
		z80_block(28);
		t5 = CHANNEL(ix)->unk_21;
		CHANNEL(ix)->unk_21 = t5 - 1u;
		if (t5 != 1u)
		{
			z80_cycles(6);
			return carry;
		}
		z80_block(69);
		CHANNEL(ix)->unk_21 = 3u;
		a = CHANNEL(ix)->unk_1D;
		t6 = CHANNEL(ix)->unk_13;
		carry = a < t6;
		if (a < t6)
		{
			z80_cycles(6);
			return carry;
		}
		z80_block(31);
		a = CHANNEL(ix)->unk_3C;
		carry = a < 2u;
		if (a < 2u)
		{
			z80_cycles(6);
			return carry;
		}
		z80_block(37);
		a--;
		CHANNEL(ix)->unk_3C = a;
		bc_2 = a;
		return set_pcm_volume(bc_2, ix);
	}
	z80_block(17);
	carry = check_fm_effect_override(ix);
	z80_block(25);
	if ((CHANNEL(ix)->unk_3F & 1u) != 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(30);
	if ((CHANNEL(ix)->unk_18 & 1u) != 0u)
	{
		z80_block(42);
		jump_target = (CHANNEL(ix)->unk_28 | ((uint32_t)CHANNEL(ix)->unk_29 << 8u));
		switch (jump_target)
		{
		case 0x0009F5u:
			break;
		default:
			sound_invalid_jump(jump_target);
		}
		note_hook_none();
		return carry;
	}
	z80_block(27);
	if (unk_83CC != 0u)
	{
		z80_block(141);
		t7 = music_volume + (fade_step + music_attenuation) + CHANNEL(ix)->unk_1A + CHANNEL(ix)->unk_33 + CHANNEL(ix)->unk_39 + CHANNEL(ix)->unk_1F;
		a = t7;
		if ((int8_t)t7 < 0)
		{
			z80_block(7);
			a = 0x7Fu;
		}
		z80_block(17);
		carry = set_fm_volume(ix, a);
	}
	z80_block(48);
	if (CHANNEL(ix)->unk_13 == CHANNEL(ix)->unk_1D)
	{
		z80_cycles(7);
		fm_key_off(ix);
	}
	z80_block(33);
	if (CHANNEL(ix)->unk_17 != 0u)
	{
		z80_block(147);
		c = CHANNEL(ix)->unk_23;
		carry = c > 0u;
		hl = CHANNEL(ix)->unk_26 - CHANNEL(ix)->unk_24 - carry;
		c = 0u - c;
		d = (uint8_t)(hl >> 8);
		e = (uint8_t)hl;
		a = 0u;
		hl = 0u;
		b = 8u;
		for (;;)
		{
			z80_block(57);
			carry = d & 1u;
			d = (int8_t)d >> 1;
			t8 = (e >> 1) | (carry << 7);
			carry = e & 1u;
			e = t8;
			c = (c >> 1) | (carry << 7);
			t9 = CHANNEL(ix)->unk_17;
			CHANNEL(ix)->unk_17 = ((uint32_t)t9 << 1) | (t9 >> 7);
			if (t9 >> 7)
			{
				z80_block(19);
				carry = (uint8_t)(a + c) < a;
				a += c;
				hl = hl + (((uint32_t)d << 8) | e) + carry;
			}
			z80_block(8);
			b--;
			if (b == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(150);
		c = CHANNEL(ix)->unk_23;
		carry = (uint8_t)(a + c) < a;
		a += c;
		hl = hl + CHANNEL(ix)->unk_24 + carry;
		CHANNEL(ix)->unk_23 = a;
		CHANNEL(ix)->unk_24 = hl;
		if ((uint8_t)(a - 0x80u) < a)
		{
			z80_block(6);
			hl++;
		}
		z80_block(17);
		set_fm_pitch(hl, ix, &ignored16, &carry);
	}
	z80_block(28);
	a = CHANNEL(ix)->unk_16;
	carry = 0u;
	if (a == 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(28);
	t10 = CHANNEL(ix)->unk_21;
	CHANNEL(ix)->unk_21 = t10 - 1u;
	if (t10 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(62);
	CHANNEL(ix)->unk_21 = a;
	a = CHANNEL(ix)->unk_22 + 0x11u;
	if (a >= 0x88u)
	{
		z80_block(7);
		a = 0x77u;
	}
	z80_block(85);
	CHANNEL(ix)->unk_22 = a;
	c = a & 0x70u;
	a = CHANNEL(ix)->unk_22;
	bc = 0x3800u | (((a >> 1) | ((uint32_t)a << 7)) & 3u) | c;
	write_fm_channel_register(ix, &bc, &carry);
	return carry;
}

void clear_note_hook(uint16_t ix)
{
	z80_block(48);
	CHANNEL(ix)->unk_28 = 0xF5u;
	CHANNEL(ix)->unk_29 = 9u;
	note_hook_none();
}

void note_hook_none(void)
{
	z80_block(10);
}

void accelerando_tick(void)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(25);
	t1 = (uint8_t)accelerando & 0xFu;
	a = t1;
	if (t1 == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(26);
	hl = 0x83D8u;
	t2 = (uint8_t)(accelerando >> 8u);
	AT8(accelerando, 1) = t2 - 1u;
	if (t2 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(70);
	AT8(accelerando, 1) = ((((uint32_t)a << 1) << 1) << 1) << 1;
	tempo_increase++;
}

uint32_t check_fm_effect_override(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0;
	uint8_t chip_channel = 0;

	z80_block(49);
	a = unk_8341;
	if (6u != CHANNEL(ix)->chip_channel)
	{
		z80_block(31);
		chip_channel = CHANNEL(ix)->chip_channel;
		carry = chip_channel > 7u;
		if (7u != chip_channel)
		{
			z80_cycles(6);
			return carry;
		}
		z80_block(13);
		a = unk_8381;
	}
	z80_block(9);
	carry = 0u;
	if (a == 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(25);
	if ((CHANNEL(ix)->unk_3F & 1u) != 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(66);
	CHANNEL(ix)->unk_3F |= 1u;
	CHANNEL(ix)->unk_3F |= 0x80u;
	bc = 0x3800u;
	write_fm_channel_register(ix, &bc, &carry);
	return carry;
}

uint32_t read_track(uint16_t ix)
{
	bool play_note = false;
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0, b = 0, bc_2 = 0, c = 0, chip_channel = 0, de_2 = 0;
	uint16_t bc = 0, de = 0, hl = 0, ignored16 = 0;
	uint16_t saved_de = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t14 = 0, t15 = 0;
	uint16_t t13 = 0;
	uint32_t jump_target = 0;

	z80_block(40);
	CHANNEL(ix)->unk_3F &= ~1u;
	carry = check_fm_effect_override(ix);
	for (;;)
	{
		z80_block(70);
		hl = CHANNEL(ix)->unk_10;
		a = z80_read8(hl);
		b = a;
		t1 = a & ~0xFu;
		a = t1;
		de = (uint32_t)a << 8;
		if (t1 == 0u)
		{
			z80_block(45);
			de = hl;
			a = b & 0xFu;
			if (((CHANNEL(ix)->chip_channel >> 3) & 1u) == 0u)
			{
				z80_block(40);
				a = (((uint32_t)a << 1) << 1) << 1;
				a += (uint32_t)a << 1;
			}
			z80_block(29);
			CHANNEL(ix)->unk_1E = a;
			z80_block(6);
			de++;
			z80_block(48);
			CHANNEL(ix)->unk_10 = de;
			continue;
		}
		z80_block(17);
		if (a >= 0xE0u)
		{
			z80_block(31);
			de = hl + 1u;
			t2 = a;
			a = b;
			if (t2 == 0xF0u)
			{
				z80_block(25);
				a = (a & 0xFu) << 1;
				hl = track_commands_f0_ADDRESS;
			}
			else
			{
				z80_block(35);
				a = (a & 0xFu) << 1;
				hl = track_commands_e0_ADDRESS;
			}
			z80_block(50);
			hl += a;
			jump_target = SOUND_ROM16(hl);
			switch (jump_target)
			{
			case 0x000D8Du:
				z80_block(36);
				CHANNEL(ix)->unk_18 = z80_read8(de);
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000D94u:
				z80_block(30);
				tempo = z80_read8(de);
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000D9Bu:
				z80_block(56);
				a = z80_read8(de);
				CHANNEL(ix)->unk_38 = a;
				if (((CHANNEL(ix)->chip_channel >> 3) & 1u) != 0u)
				{
					z80_block(6);
					de++;
					z80_block(48);
					CHANNEL(ix)->unk_10 = de;
					continue;
				}
				z80_block(30);
				if (CHANNEL(ix)->unk_3F >> 7 == 0u)
				{
					z80_cycles(7);
					carry = load_instrument(ix, a);
				}
				z80_block(10);
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000DC0u:
				z80_block(44);
				a = z80_read8(de);
				b = 0u;
				if (((CHANNEL(ix)->chip_channel >> 3) & 1u) == 0u)
				{
					z80_block(7);
					b = 0xAu;
				}
				z80_block(52);
				CHANNEL(ix)->unk_1F = a + b;
				CHANNEL(ix)->unk_39 = 0u;
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000DD7u:
				z80_block(36);
				CHANNEL(ix)->unk_20 = z80_read8(de);
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000DDEu:
				break;
			case 0x000E25u:
				z80_block(36);
				CHANNEL(ix)->unk_15 = z80_read8(de);
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000E2Cu:
				z80_block(36);
				CHANNEL(ix)->unk_17 = z80_read8(de);
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000E33u:
				z80_block(17);
				a = read_transpose(de);
				z80_block(23);
				music_transpose = a;
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000E59u:
				z80_block(17);
				a = read_transpose(de);
				z80_block(29);
				CHANNEL(ix)->unk_19 = a;
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000E62u:
				z80_block(17);
				a = read_volume_offset(de);
				z80_block(23);
				music_volume = a;
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000E74u:
				z80_block(17);
				a = read_volume_offset(de);
				z80_block(29);
				CHANNEL(ix)->unk_1A = a;
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000E7Du:
				z80_block(33);
				t3 = CHANNEL(ix)->unk_31;
				CHANNEL(ix)->unk_31 = t3 - 1u;
				if (t3 == 1u)
				{
					z80_block(60);
					CHANNEL(ix)->unk_32 = 0u;
					CHANNEL(ix)->unk_33 = 0u;
					de += 2u;
					z80_block(12);
					de += 2u;
					z80_block(6);
					de++;
					z80_block(48);
					CHANNEL(ix)->unk_10 = de;
					continue;
				}
				z80_block(33);
				t4 = CHANNEL(ix)->unk_31 + 1u;
				CHANNEL(ix)->unk_31 = t4;
				if (t4 == 0u)
				{
					z80_block(64);
					CHANNEL(ix)->unk_31 = z80_read8(de);
					CHANNEL(ix)->unk_32 = 0u;
					CHANNEL(ix)->unk_33 = 0u;
				}
				z80_block(46);
				CHANNEL(ix)->unk_31--;
				de++;
				a = read_transpose(de);
				z80_block(61);
				CHANNEL(ix)->unk_32 += a;
				de++;
				a = read_volume_offset(de);
				z80_block(54);
				CHANNEL(ix)->unk_33 += a;
				de++;
				z80_block(68);
				AS8(CHANNEL(ix)->unk_10) = z80_read8(de);
				AT8(CHANNEL(ix)->unk_10, 1) = z80_read8((uint16_t)(de + 1u));
				continue;
			case 0x000EBDu:
				z80_block(35);
				bc = 0x1800u | z80_read8(de);
				carry = write_fm_register(bc);
				z80_block(48);
				de++;
				bc = 0x1900u | z80_read8(de) | 0x80u;
				carry = write_fm_register(bc);
				z80_block(31);
				bc = 0x1900u;
				carry = write_fm_register(bc);
				z80_block(31);
				bc = 0x1B02u;
				carry = write_fm_register(bc);
				z80_block(10);
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000EDFu:
				z80_block(36);
				CHANNEL(ix)->unk_16 = z80_read8(de);
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000EE6u:
				z80_block(10);
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000EE9u:
				z80_block(68);
				AS8(CHANNEL(ix)->unk_10) = z80_read8(de);
				AT8(CHANNEL(ix)->unk_10, 1) = z80_read8((uint16_t)(de + 1u));
				continue;
			case 0x000EF5u:
				z80_block(33);
				t5 = CHANNEL(ix)->unk_30;
				CHANNEL(ix)->unk_30 = t5 - 1u;
				if (t5 == 1u)
				{
					z80_block(16);
					de++;
					z80_block(68);
					AS8(CHANNEL(ix)->unk_10) = z80_read8(de);
					AT8(CHANNEL(ix)->unk_10, 1) = z80_read8((uint16_t)(de + 1u));
					continue;
				}
				z80_block(33);
				t6 = CHANNEL(ix)->unk_30 + 1u;
				CHANNEL(ix)->unk_30 = t6;
				if (t6 == 0u)
				{
					z80_block(26);
					CHANNEL(ix)->unk_30 = z80_read8(de);
				}
				z80_block(33);
				CHANNEL(ix)->unk_30--;
				z80_block(12);
				de += 2u;
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000F0Fu:
				z80_block(80);
				CHANNEL(ix)->unk_1B = z80_read8(de);
				de++;
				AS16(CHANNEL(ix)->unk_2C) = de;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000F1Du:
				z80_block(33);
				t7 = CHANNEL(ix)->unk_1B;
				CHANNEL(ix)->unk_1B = t7 - 1u;
				if (t7 == 1u)
				{
					z80_block(48);
					CHANNEL(ix)->unk_10 = de;
					continue;
				}
				z80_block(48);
				de = (CHANNEL(ix)->unk_2C | ((uint32_t)CHANNEL(ix)->unk_2D << 8u));
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000F2Cu:
				z80_block(80);
				CHANNEL(ix)->unk_1C = z80_read8(de);
				de++;
				AS16(CHANNEL(ix)->unk_2E) = de;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000F3Au:
				z80_block(33);
				t8 = CHANNEL(ix)->unk_1C;
				CHANNEL(ix)->unk_1C = t8 - 1u;
				if (t8 == 1u)
				{
					z80_block(48);
					CHANNEL(ix)->unk_10 = de;
					continue;
				}
				z80_block(48);
				de = AS16(CHANNEL(ix)->unk_2E);
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000F49u:
				z80_block(49);
				CHANNEL(ix)->unk_35 = z80_read8(de);
				de++;
				de = read_track_address(de, ix);
				z80_block(48);
				CHANNEL(ix)->unk_2A = de;
				continue;
			case 0x000F65u:
				z80_block(71);
				t9 = CHANNEL(ix)->unk_35;
				CHANNEL(ix)->unk_35 = t9 - 1u;
				de = CHANNEL(ix)->unk_2A;
				if (t9 == 1u)
				{
					z80_block(48);
					CHANNEL(ix)->unk_10 = de;
					continue;
				}
				z80_block(74);
				de--;
				AT8(CHANNEL(ix)->unk_10, 1) = z80_read8(de);
				AS8(CHANNEL(ix)->unk_10) = z80_read8((uint16_t)(de - 1u));
				continue;
			case 0x000F7Eu:
				z80_block(17);
				de = read_track_address(de, ix);
				z80_block(48);
				AS16(CHANNEL(ix)->unk_36) = de;
				continue;
			case 0x000F8Au:
				z80_block(48);
				de = AS16(CHANNEL(ix)->unk_36);
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000F93u:
				z80_block(17);
				de = read_track_address(de, ix);
				z80_block(48);
				CHANNEL(ix)->unk_3A = de;
				continue;
			case 0x000F9Fu:
				z80_block(48);
				de = CHANNEL(ix)->unk_3A;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000FA8u:
				z80_block(99);
				a = z80_read8(de);
				AS8(accelerando) = a;
				AT8(accelerando, 1) = ((((a & 0xFu) << 1) << 1) << 1) << 1;
				tempo_increase = 0u;
				z80_block(6);
				de++;
				z80_block(48);
				CHANNEL(ix)->unk_10 = de;
				continue;
			case 0x000FC0u:
				z80_block(36);
				chip_channel = CHANNEL(ix)->chip_channel;
				zero = (uint8_t)(chip_channel - 8u) == 0u;
				if (chip_channel >= 8u)
				{
					z80_block(23);
					a = unk_82C1;
					if (zero)
					{
						z80_block(13);
						a = music_pcm_hold;
					}
					z80_block(14);
					carry = 0u;
					if (a != 0u)
					{
						free_channel(ix);
						return carry;
					}
					z80_block(10);
					return stop_pcm_channel(ix);
				}
				z80_block(27);
				bc = 0x3800u;
				write_fm_channel_register(ix, &bc, &carry);
				z80_block(36);
				chip_channel = CHANNEL(ix)->chip_channel;
				zero = (uint8_t)(chip_channel - 6u) == 0u;
				if (chip_channel < 6u)
					return stop_channel(ix);
				z80_block(23);
				a = unk_8341;
				if (zero == 0u)
				{
					z80_block(13);
					a = unk_8381;
				}
				z80_block(14);
				carry = 0u;
				if (a != 0u)
				{
					free_channel(ix);
					return carry;
				}
				z80_block(10);
				return stop_channel(ix);
			default:
				sound_invalid_jump(jump_target);
			}
			break;
		}
		z80_block(17);
		if (a == 0x70u)
		{
			z80_block(44);
			de = hl;
			CHANNEL(ix)->unk_39 = b & 0xFu;
			z80_block(6);
			de++;
			z80_block(48);
			CHANNEL(ix)->unk_10 = de;
			continue;
		}
		z80_block(25);
		t10 = b & 0xFu;
		de |= t10;
		if (t10 == 0u)
		{
			z80_block(30);
			if ((CHANNEL(ix)->unk_3F & 1u) == 0u)
			{
				z80_block(17);
				fm_key_off(ix);
			}
			z80_block(48);
			CHANNEL(ix)->unk_28 = 0xF5u;
			CHANNEL(ix)->unk_29 = 9u;
			return next_note_length(de, hl, ix);
		}
		z80_block(17);
		carry = next_note_length(de, hl, ix);
		play_note = true;
		break;
	}
	if (!play_note)
	{
		z80_block(61);
		saved_de = de;
		CHANNEL(ix)->unk_13 = 0u;
		a = z80_read8(de) & ~0xFu;
		add_note_length_high(ix, a);
		for (;;)
		{
			z80_block(30);
			de++;
			t11 = z80_read8(de) & ~0xFu;
			a = t11;
			if (t11 == 0u)
				break;
			z80_block(17);
			add_note_length_high(ix, a);
			z80_block(24);
			t12 = z80_read8(de) & 0xFu;
			a = t12;
			if (t12 == 0u)
				break;
			z80_block(17);
			add_note_length(ix, a);
			z80_block(10);
		}
		z80_block(82);
		de++;
		CHANNEL(ix)->unk_10 = de;
		carry = 0u;
		de = z80_read8(saved_de) & 0xFu;
	}
	z80_block(30);
	if (((CHANNEL(ix)->chip_channel >> 3) & 1u) != 0u)
	{
		z80_block(43);
		a = unk_8281;
		if (CHANNEL(ix)->chip_channel & 1u)
		{
			z80_block(13);
			a = unk_82C1;
		}
		z80_block(9);
		carry = 0u;
		if (a != 0u)
		{
			z80_cycles(6);
			return carry;
		}
		z80_block(59);
		c = (uint8_t)de;
		hl = 0u;
		de = CHANNEL(ix)->unk_20;
		b = CHANNEL(ix)->unk_13;
		for (;;)
		{
			z80_block(19);
			hl += de;
			b--;
			if (b == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(11);
		de = c;
		a = 0xFFu;
		do
		{
			z80_block(43);
			a = (a + 1u) ^ (de >> 8);
			t13 = hl;
			hl = t13 - 0xFFu;
		} while (t13 >= 0xFFu);
		z80_block(75);
		CHANNEL(ix)->unk_1D = a;
		CHANNEL(ix)->unk_21 = 3u;
		if ((CHANNEL(ix)->unk_18 & 1u) != 0u)
		{
			z80_block(41);
			a = ((uint32_t)de << 1) | (de >> 7);
			de = (uint8_t)((((uint32_t)a << 1) | (a >> 7)) + de + de);
			hl = pcm_drums_ADDRESS - 0x6u;
		}
		else
		{
			z80_block(66);
			de = (uint8_t)(((uint32_t)CHANNEL(ix)->unk_38 << 1) << 1);
			hl = pcm_instruments_ADDRESS;
		}
		z80_block(67);
		hl += de;
		de = SOUND_ROM8(hl);
		hl++;
		de |= (uint32_t)SOUND_ROM8(hl) << 8;
		hl++;
		c = SOUND_ROM8(hl);
		hl++;
		bc_2 = c;
		set_pcm_start(bc_2, de, ix);
		z80_block(122);
		de_2 = (uint8_t)(fade_attenuation + music_attenuation + CHANNEL(ix)->unk_1F + CHANNEL(ix)->unk_39 + CHANNEL(ix)->unk_33);
		a = SOUND_ROM8(hl);
		hl++;
		t14 = a;
		a = t14 - de_2;
		if (t14 < de_2)
		{
			z80_block(4);
			a = 0u;
		}
		z80_block(40);
		CHANNEL(ix)->unk_3C = a;
		bc_2 = a;
		carry = set_pcm_volume(bc_2, ix);
		z80_block(30);
		if (CHANNEL(ix)->unk_18 & 1u)
		{
			z80_block(37);
			de = SOUND_ROM16(hl);
			set_pcm_pitch(de, ix);
			z80_block(10);
			start_pcm(ix);
			return carry;
		}
		z80_block(81);
		a = z80_read8((uint16_t)(CHANNEL(ix)->unk_10 - 1u)) & 0xFu;
		b = CHANNEL(ix)->unk_1E + 1u;
		for (;;)
		{
			z80_block(15);
			a += 0xCu;
			b--;
			if (b == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(63);
		de = a;
		carry = (uint16_t)(pcm_note_pitches_ADDRESS - 0xCu + de) < pcm_note_pitches_ADDRESS - 0xCu;
		de = SOUND_ROM8(pcm_note_pitches_ADDRESS - 0xCu + de) | 0xF00u;
		set_pcm_pitch(de, ix);
		z80_block(10);
		start_pcm(ix);
		return carry;
	}
	z80_block(25);
	if ((CHANNEL(ix)->unk_3F & 1u) != 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(30);
	if (CHANNEL(ix)->unk_3F >> 7)
	{
		z80_block(36);
		a = CHANNEL(ix)->unk_38;
		carry = load_instrument(ix, a);
		z80_block(23);
		CHANNEL(ix)->unk_3F &= 0x7Fu;
	}
	z80_block(30);
	if ((CHANNEL(ix)->unk_18 & 1u) != 0u)
	{
		z80_block(10);
		clear_note_hook(ix);
		return carry;
	}
	z80_block(17);
	carry = fm_fast_release(ix);
	z80_block(243);
	hl = fm_note_pitches_ADDRESS - 0x2u + (uint8_t)(music_transpose + ((((uint32_t)de << 1) | ((uint8_t)de >> 7)) + CHANNEL(ix)->unk_1E + CHANNEL(ix)->unk_19) + CHANNEL(ix)->unk_32);
	hl = SOUND_ROM16(hl) + CHANNEL(ix)->unk_15;
	CHANNEL(ix)->unk_26 = hl;
	if (CHANNEL(ix)->unk_17 == 0u)
	{
		z80_block(55);
		CHANNEL(ix)->unk_24 = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
	}
	z80_block(27);
	bc = 0x3800u;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(94);
	CHANNEL(ix)->unk_21 = CHANNEL(ix)->unk_16;
	CHANNEL(ix)->unk_22 = 0u;
	a = CHANNEL(ix)->unk_20;
	if (a != 0u)
	{
		z80_block(40);
		hl = 0u;
		de = CHANNEL(ix)->unk_13;
		b = 8u;
		for (;;)
		{
			z80_block(18);
			carry = a & 1u;
			a = (a >> 1) | ((uint32_t)a << 7);
			if (carry)
			{
				z80_block(11);
				hl += de;
			}
			z80_block(24);
			carry = (uint8_t)de >> 7;
			de = IN_PAGE(de, (uint8_t)((uint32_t)de << 1));
			de = (de & 0xFFu) | ((uint32_t)(uint8_t)(((uint32_t)(de >> 8) << 1) | carry) << 8);
			b--;
			if (b == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(8);
		a = (hl >> 8) + 1u;
	}
	z80_block(160);
	CHANNEL(ix)->unk_1D = a;
	t15 = music_volume + (fade_step + music_attenuation) + CHANNEL(ix)->unk_1A + CHANNEL(ix)->unk_33 + CHANNEL(ix)->unk_39 + CHANNEL(ix)->unk_1F;
	a = t15;
	if ((int8_t)t15 < 0)
	{
		z80_block(7);
		a = 0x7Fu;
	}
	z80_block(17);
	carry = set_fm_volume(ix, a);
	z80_block(17);
	fm_restore_release(ix);
	z80_block(10);
	return fm_key_on(ix);
}

uint32_t next_note_length(uint16_t de, uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t bc = 0;

	z80_block(148);
	hl++;
	CHANNEL(ix)->unk_10 = hl;
	bc = ((((de >> 8) >> 1) >> 1) >> 1) >> 1;
	carry = (uint16_t)(note_lengths_ADDRESS - 0x1u + bc) < note_lengths_ADDRESS - 0x1u;
	CHANNEL(ix)->unk_13 = SOUND_ROM8(note_lengths_ADDRESS - 0x1u + bc);
	return carry;
}

uint32_t load_instrument(uint16_t ix, uint8_t a)
{
	uint16_t hl = 0, voice = 0;

	z80_block(74);
	hl = fm_voice_pointers_ADDRESS + (uint8_t)((uint32_t)a << 1);
	voice = SOUND_ROM16(hl);
	return load_fm_voice(voice, ix);
}

void add_note_length_high(uint16_t ix, uint8_t a)
{
	z80_block(32);
	a = (((a >> 1) >> 1) >> 1) >> 1;
	add_note_length(ix, a);
}

void add_note_length(uint16_t ix, uint8_t a)
{
	z80_block(87);
	CHANNEL(ix)->unk_13 += note_lengths[(uint16_t)(a - 1u)];
}

uint8_t read_transpose(uint16_t de)
{
	uint8_t a = 0, b = 0, c = 0;
	uint8_t t1 = 0;

	z80_block(60);
	a = z80_read8(de) & 0xFu;
	c = ((uint32_t)a << 1) | (a >> 7);
	a = z80_read8(de) & 0x70u;
	a = (a >> 1) | ((uint32_t)a << 7);
	a = (a >> 1) | ((uint32_t)a << 7);
	a = (a >> 1) | ((uint32_t)a << 7);
	b = (a >> 1) | ((uint32_t)a << 7);
	a = 0u;
	for (;;)
	{
		z80_block(15);
		a += 0xCu;
		b--;
		if (b == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(36);
	t1 = z80_read8(de);
	a = (((uint32_t)a << 1) | (a >> 7)) + c;
	if (t1 >> 7 == 0u)
	{
		z80_cycles(6);
		return a;
	}
	z80_block(18);
	a = 0u - a;
	return a;
}

uint8_t read_volume_offset(uint16_t de)
{
	uint8_t a = 0;

	z80_block(20);
	a = z80_read8(de);
	if (a >> 7 == 0u)
	{
		z80_cycles(6);
		return a;
	}
	z80_block(25);
	a = 0u - (a & 0x7Fu);
	return a;
}

uint16_t read_track_address(uint16_t de, uint16_t ix)
{
	z80_block(74);
	AS8(CHANNEL(ix)->unk_10) = z80_read8(de);
	de++;
	AT8(CHANNEL(ix)->unk_10, 1) = z80_read8(de);
	de++;
	return de;
}

void unused_note_hook(uint16_t ix)
{
	z80_block(10);
	clear_note_hook(ix);
}
