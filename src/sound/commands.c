/**
 *    Name:        commands.c
 *    Description: the 68000's sound commands: the reset and its tests, the command's dispatch, the title music, the speech, the starts of the music and the effects, the fade, silence, the channels' stops
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

void sound_reset(void)
{
	uint8_t b = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(7);
	b = 0u;
	for (;;)
	{
		z80_block(10);
		hl = CHANNEL_ADDRESS(0);
		for (;;)
		{
			z80_block(28);
			z80_write8(hl, b);
			if (z80_read8(hl) != b)
			{
				self_test_failed();
				return;
			}
			z80_block(24);
			hl++;
			if (hl >> 8 == 0x88u)
				break;
			z80_cycles(5);
		}
		z80_block(22);
		t1 = b;
		b = t1 + 0x55u;
		if ((uint8_t)(t1 + 0x55u) < t1)
			break;
		z80_cycles(5);
	}
	check_rom();
}

void BOARD_ORIGINAL(check_rom)(void)
{
	uint16_t bc = 0, de = 0, hl = 0;

	z80_block(27);
	de = 0u;
	hl = 0u;
	bc = 0u;
	for (;;)
	{
		z80_block(46);
		bc = z80_read8(de);
		hl += bc;
		de++;
		if (de >> 8 == 0x80u)
			break;
		z80_cycles(5);
	}
	z80_block(21);
	if (hl >> 8 != 0x78u)
	{
		self_test_failed();
		return;
	}
	z80_block(18);
	if ((uint8_t)hl == 0x3Cu)
	{
		z80_block(10);
		sound_main();
		return;
	}
	z80_cycles(5);
	self_test_failed();
}

void sound_command(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t channel = 0, de = 0, hl = 0;
	uint16_t saved_hl = 0;
	uint8_t t1 = 0;

	z80_block(31);
	interrupts_off();
	t1 = z80_read8(sound_latch);
	a = t1;
	if (a == 0u)
	{
		reset_sound();
		return;
	}
	z80_block(17);
	if (a == 0xFFu)
	{
		silence();
		return;
	}
	z80_block(17);
	if (a == 0xFEu)
	{
		z80_block(30);
		fade_timer = 0x16u;
		return;
	}
	z80_block(17);
	if (a == 0x7Du)
	{
		z80_block(95);
		title_music_on = 1u;
		title_music_rounds = 0xDu;
		title_music_passes = 0xFAu;
		z80_write8(sound_control, z80_read8(sound_control) | 4u);
		return;
	}
	z80_block(17);
	if (a == 0x7Eu)
	{
		stop_title_music();
		return;
	}
	z80_block(17);
	if (a < 0x60u)
	{
		carry = start_fm_effect(a);
		return;
	}
	z80_block(17);
	if (a < 0x80u)
	{
		z80_block(19);
		a -= 0x60u;
		if (a >= 0x19u)
		{
			z80_cycles(6);
			return;
		}
		z80_block(27);
		if ((unk_8458 & 1u) != 0u)
		{
			z80_cycles(6);
			return;
		}
		z80_block(41);
		hl = 0x885u;
		de = 0x40u;
		b = 9u;
		channel = CHANNEL_ADDRESS(1);
		for (;;)
		{
			z80_block(99);
			CHANNEL(channel)->sound = 0xFFu;
			CHANNEL(channel)->handler = hl;
			CHANNEL(channel)->priority = 0xFFu;
			channel += de;
			b--;
			if (b == 0u)
				break;
			z80_cycles(5);
		}
		z80_block(255);
		hl = a * 2u;
		saved_hl = hl;
		song_header = hl * 2u * 2u * 2u + saved_hl + (songs_ADDRESS - 0x2u);
		unk_83CC = 0u;
		fade_timer = 0u;
		fade_step = 0u;
		fade_attenuation = 0u;
		music_attenuation = 0u;
		music_transpose = 0u;
		music_volume = 0u;
		AS8(accelerando) = 0u;
		tempo_increase = 0u;
		return;
	}
	z80_block(17);
	if (a < 0xA0u)
	{
		start_pcm_effect(a);
		return;
	}
	z80_block(17);
	if (a < 0xE0u)
	{
		start_speech(a);
		return;
	}
	z80_block(10);
}

void self_test_failed(void)
{
	uint8_t t1 = 0;

	z80_block(143);
	z80_write16(pcm_a_start, 0x8750u);
	z80_write8(pcm_a_bank, 0u);
	z80_write16(pcm_a_pitch, 0xFEAu);
	z80_write8(pcm_volume_port, 0xF0u);
	t1 = z80_read8(pcm_a_key);
	z80_write8(pcm_loop_flags, 1u);
	sound_reset();
}

void stop_title_music(void)
{
	z80_block(53);
	title_music_on = 0u;
	title_music_passes = 0u;
	title_music_rounds = 0u;
	stop_speech();
}

void title_music_timer(void)
{
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(26);
	hl = title_music_passes_ADDRESS;
	t1 = title_music_passes;
	title_music_passes = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(36);
	title_music_passes = 0xFAu;
	t2 = title_music_rounds;
	title_music_rounds = t2 - 1u;
	if (t2 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_title_music();
}

void start_speech(uint8_t a)
{
	uint8_t a_2 = 0, c = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(24);
	a += 0x60u;
	if (a == 0x3Fu)
	{
		stop_speech();
		return;
	}
	z80_block(12);
	if (a >= 0x24u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(66);
	c = a;
	a_2 = speech_priorities[c];
	hl = speech_priority_ADDRESS;
	if (speech_priority <= a_2)
	{
		z80_block(134);
		speech_priority = a_2;
		unk_8301 = c;
		z80_write8(sound_control, z80_read8(sound_control) & ~2u);
		unk_8302 = 0x78u;
		unk_8303 = 1u;
		if (c == 9u)
		{
			z80_block(35);
			z80_write8(sound_control, z80_read8(sound_control) | 2u);
			return;
		}
		z80_block(30);
		z80_write8(sound_control, 2u);
		return;
	}
	z80_block(24);
	t1 = a_2;
	a_2 = 0x87u;
	if (t1 == 0x12u)
	{
		start_pcm_effect(a_2);
		return;
	}
	z80_block(12);
	if (a_2 != 0x13u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	a_2 = 0x8Au;
	start_pcm_effect(a_2);
}

void stop_speech(void)
{
	z80_block(161);
	z80_write8(sound_control, 0u);
	speech_priority = 0u;
	unk_8301 = 0u;
	unk_830F = 0u;
	music_attenuation = 0u;
	unk_8302 = 0xE7u;
	unk_8303 = 5u;
	z80_write8(sound_control, 2u);
}

uint32_t speech_play(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, sound = 0;
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(speech_sample, CHANNEL(ix)->sound);
	b = 3u;
	for (;;)
	{
		z80_block(8);
		b--;
		if (b == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(27);
	z80_write8(speech_start, 1u);
	b = 6u;
	for (;;)
	{
		z80_block(8);
		b--;
		if (b == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(114);
	z80_write8(speech_start, 0u);
	sound = CHANNEL(ix)->sound;
	carry = (uint16_t)(speech_music_attenuation_ADDRESS + sound) < speech_music_attenuation_ADDRESS;
	a = speech_music_attenuation[sound];
	music_attenuation = a;
	unk_83CC = a;
	hl = 0x1A4u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t speech_wait(uint16_t ix, uint32_t carry)
{
	uint8_t t1 = 0;

	z80_block(26);
	t1 = z80_read8(speech_busy);
	if ((t1 & 1u) == 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(139);
	carry = 0u;
	CHANNEL(ix)->sound = 0u;
	CHANNEL(ix)->priority = 0u;
	speech_priority = 0u;
	music_attenuation = 0u;
	unk_83CC = 0u;
	AS8(CHANNEL(ix)->handler) = 0xE7u;
	AT8(CHANNEL(ix)->handler, 1) = 5u;
	return carry;
}

void start_pcm_effect(uint8_t a)
{
	uint8_t a_2 = 0, d = 0, e = 0;
	uint16_t channel = 0, hl = 0;
	uint8_t t1 = 0;

	z80_block(12);
	t1 = a;
	a_2 = t1 + 0x80u;
	if (t1 == 0x80u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(12);
	if (a_2 >= 0x14u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(74);
	e = a_2;
	d = pcm_effect_priorities[a_2];
	channel = CHANNEL_ADDRESS(10);
	if (a_2 != 6u)
	{
		z80_block(43);
		channel = CHANNEL_ADDRESS(11);
		if (a_2 != unk_82C1)
		{
			z80_block(28);
			if (d < CHANNEL(channel)->priority)
			{
				z80_cycles(6);
				return;
			}
		}
	}
	z80_block(142);
	CHANNEL(channel)->priority = d;
	CHANNEL(channel)->sound = e;
	hl = pcm_effect_handlers_ADDRESS + (uint8_t)((uint32_t)e << 1);
	d = SOUND_ROM8(hl + 1u);
	AS8(CHANNEL(channel)->handler) = SOUND_ROM8(hl);
	AT8(CHANNEL(channel)->handler, 1) = d;
}

uint32_t start_fm_effect(uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0, b = 0, c = 0, d = 0;
	uint16_t channel = 0, hl = 0, ix = 0;
	uint16_t saved_hl = 0;
	uint8_t t1 = 0;

	z80_block(12);
	carry = a < 0x42u;
	if (a >= 0x42u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(69);
	c = a;
	a_2 = fm_effect_priorities[c];
	unk_83C7 = a_2;
	if (a_2 >= 0x20u)
	{
		z80_block(38);
		channel = CHANNEL_ADDRESS(0);
		t1 = unk_800F;
		carry = a_2 < t1;
		if (a_2 < t1)
		{
			z80_cycles(6);
			return carry;
		}
		z80_block(10);
		z80_block(155);
		a_2 = unk_83C7;
		CHANNEL(channel)->sound = c;
		CHANNEL(channel)->priority = a_2;
		c = (uint32_t)c << 1;
		carry = (uint16_t)(fm_effect_handlers_ADDRESS + c) < fm_effect_handlers_ADDRESS;
		hl = fm_effect_handlers_ADDRESS + c;
		d = SOUND_ROM8(hl + 1u);
		AS8(CHANNEL(channel)->handler) = SOUND_ROM8(hl);
		AT8(CHANNEL(channel)->handler, 1) = d;
		return carry;
	}
	z80_block(35);
	a_2 = c;
	channel = CHANNEL_ADDRESS(13);
	if (a_2 == 0x21u)
	{
		z80_block(155);
		a_2 = unk_83C7;
		CHANNEL(channel)->sound = c;
		CHANNEL(channel)->priority = a_2;
		c = (uint32_t)c << 1;
		carry = (uint16_t)(fm_effect_handlers_ADDRESS + c) < fm_effect_handlers_ADDRESS;
		hl = fm_effect_handlers_ADDRESS + c;
		d = SOUND_ROM8(hl + 1u);
		AS8(CHANNEL(channel)->handler) = SOUND_ROM8(hl);
		AT8(CHANNEL(channel)->handler, 1) = d;
		return carry;
	}
	z80_block(17);
	if (a_2 == 0xAu)
	{
		z80_block(155);
		a_2 = unk_83C7;
		CHANNEL(channel)->sound = c;
		CHANNEL(channel)->priority = a_2;
		c = (uint32_t)c << 1;
		carry = (uint16_t)(fm_effect_handlers_ADDRESS + c) < fm_effect_handlers_ADDRESS;
		hl = fm_effect_handlers_ADDRESS + c;
		d = SOUND_ROM8(hl + 1u);
		AS8(CHANNEL(channel)->handler) = SOUND_ROM8(hl);
		AT8(CHANNEL(channel)->handler, 1) = d;
		return carry;
	}
	z80_block(29);
	if (a_2 == CHANNEL(channel)->sound)
	{
		z80_block(155);
		a_2 = unk_83C7;
		CHANNEL(channel)->sound = c;
		CHANNEL(channel)->priority = a_2;
		c = (uint32_t)c << 1;
		carry = (uint16_t)(fm_effect_handlers_ADDRESS + c) < fm_effect_handlers_ADDRESS;
		hl = fm_effect_handlers_ADDRESS + c;
		d = SOUND_ROM8(hl + 1u);
		AS8(CHANNEL(channel)->handler) = SOUND_ROM8(hl);
		AT8(CHANNEL(channel)->handler, 1) = d;
		return carry;
	}
	z80_block(43);
	channel = CHANNEL_ADDRESS(14);
	if (a_2 == unk_8381)
	{
		z80_block(155);
		a_2 = unk_83C7;
		CHANNEL(channel)->sound = c;
		CHANNEL(channel)->priority = a_2;
		c = (uint32_t)c << 1;
		carry = (uint16_t)(fm_effect_handlers_ADDRESS + c) < fm_effect_handlers_ADDRESS;
		hl = fm_effect_handlers_ADDRESS + c;
		d = SOUND_ROM8(hl + 1u);
		AS8(CHANNEL(channel)->handler) = SOUND_ROM8(hl);
		AT8(CHANNEL(channel)->handler, 1) = d;
		return carry;
	}
	z80_block(43);
	channel = CHANNEL_ADDRESS(0);
	if (a_2 == unk_8001)
	{
		z80_block(155);
		a_2 = unk_83C7;
		CHANNEL(channel)->sound = c;
		CHANNEL(channel)->priority = a_2;
		c = (uint32_t)c << 1;
		carry = (uint16_t)(fm_effect_handlers_ADDRESS + c) < fm_effect_handlers_ADDRESS;
		hl = fm_effect_handlers_ADDRESS + c;
		d = SOUND_ROM8(hl + 1u);
		AS8(CHANNEL(channel)->handler) = SOUND_ROM8(hl);
		AT8(CHANNEL(channel)->handler, 1) = d;
		return carry;
	}
	z80_block(54);
	hl = CHANNEL_ADDRESS(0);
	a_2 = unk_800F;
	ix = CHANNEL_ADDRESS(13);
	lower_priority_channel(ix, &hl, &a_2);
	z80_block(31);
	ix = CHANNEL_ADDRESS(14);
	lower_priority_channel(ix, &hl, &a_2);
	z80_block(26);
	b = a_2;
	a_2 = unk_83C7;
	carry = a_2 < b;
	if (a_2 < b)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(35);
	saved_hl = hl;
	channel = saved_hl;
	z80_block(155);
	a_2 = unk_83C7;
	CHANNEL(channel)->sound = c;
	CHANNEL(channel)->priority = a_2;
	c = (uint32_t)c << 1;
	carry = (uint16_t)(fm_effect_handlers_ADDRESS + c) < fm_effect_handlers_ADDRESS;
	hl = fm_effect_handlers_ADDRESS + c;
	d = SOUND_ROM8(hl + 1u);
	AS8(CHANNEL(channel)->handler) = SOUND_ROM8(hl);
	AT8(CHANNEL(channel)->handler, 1) = d;
	return carry;
}

void lower_priority_channel(uint16_t ix, uint16_t *p_hl, uint8_t *p_a)
{
	uint16_t hl = (uint16_t)*p_hl;
	uint8_t a = (uint8_t)*p_a;
	uint16_t saved_ix = 0;

	z80_block(24);
	if (a < CHANNEL(ix)->priority)
		z80_cycles(6);
	else
	{
		z80_block(54);
		saved_ix = ix;
		hl = saved_ix;
		a = CHANNEL(ix)->priority;
	}
	*p_hl = hl;
	*p_a = a;
}

void reset_sound(void)
{
	z80_block(154);
	z80_write8(sound_control, 0u);
	speech_priority = 0u;
	unk_83CC = 0u;
	fade_timer = 0u;
	fade_step = 0u;
	fade_attenuation = 0u;
	music_attenuation = 0u;
	unk_8458 = 0u;
	unk_83F3 = 0u;
	unk_841F = 0u;
	z80_write8(sound_control, 2u);
	silence();
}

void silence(void)
{
	uint8_t bc = 0, c = 0, e = 0;
	uint16_t de = 0;

	z80_block(17);
	c = 0u;
	de = 0x3800u;
	e = 0u;
	do
	{
		z80_block(17);
		bc = c;
		de = (de & ~0xFFu) | e;
		write_fm_register_de(bc, de);
		z80_block(22);
		e++;
	} while (((e >> 3) & 1u) == 0u);
	z80_block(27);
	if (music_pcm_hold == 0u)
	{
		z80_block(17);
		stop_music_pcm_a();
		z80_block(17);
		stop_pcm_effect_b();
		z80_block(17);
		stop_music_pcm_b();
		z80_block(17);
		stop_pcm_effect_a();
	}
	else
	{
		z80_block(17);
		free_music_pcm_a();
		z80_block(17);
		free_music_pcm_b();
		z80_block(10);
	}
	z80_block(17);
	stop_fm_effect_channels();
	z80_block(17);
	stop_music_fm_6_7();
	z80_block(17);
	stop_music_fm_1_5();
	z80_block(10);
	free_speech_channel();
}

void stop_fm_effect_channels(void)
{
	z80_block(68);
	unk_8002 = 0x5D0u;
	unk_8342 = 0x5D0u;
	unk_8382 = 0x5D0u;
}

void stop_music_fm_6_7(void)
{
	z80_block(52);
	unk_8182 = 0x5D0u;
	unk_81C2 = 0x5D0u;
}

void stop_music_fm_1_5(void)
{
	z80_block(100);
	unk_8042 = 0x5D0u;
	unk_8082 = 0x5D0u;
	unk_80C2 = 0x5D0u;
	unk_8102 = 0x5D0u;
	unk_8142 = 0x5D0u;
}

void free_music_fm_6_7(void)
{
	z80_block(52);
	unk_8182 = 0x5D6u;
	unk_81C2 = 0x5D6u;
}

void stop_music_pcm_a(void)
{
	z80_block(36);
	unk_8202 = 0x5E8u;
}

void free_music_pcm_a(void)
{
	z80_block(36);
	unk_8202 = 0x5D6u;
}

void stop_pcm_effect_b(void)
{
	z80_block(36);
	unk_82C2 = 0x5E8u;
}

void free_music_pcm_b(void)
{
	z80_block(36);
	unk_8242 = 0x5D6u;
}

void stop_music_pcm_b(void)
{
	z80_block(36);
	unk_8242 = 0x5E8u;
}

void stop_pcm_effect_a(void)
{
	z80_block(36);
	unk_8282 = 0x5E8u;
}

void free_speech_channel(void)
{
	z80_block(36);
	AS16(unk_8302) = 0x5D6u;
}
