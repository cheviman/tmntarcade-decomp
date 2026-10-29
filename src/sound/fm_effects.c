/**
 *    Name:        fm_effects.c
 *    Description: the FM effects (commands 01-41)
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

uint32_t fm_effect_01(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(27);
	unk_83E2 = 3u;
	a = 7u;
	return sound_163F(ix, a);
}

uint32_t sound_163F(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(40);
	unk_83E3 = a;
	voice = 0x161Fu;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = pcm_instruments_ADDRESS - 0x2u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(30);
	a_2 = unk_83E3;
	carry = set_fm_volume(ix, a_2);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(40);
	unk_83DF = 0x34u;
	hl = 0x1662u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1662(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(31);
	hl = unk_83DF_ADDRESS;
	t1 = unk_83DF;
	unk_83DF = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(31);
		t2 = unk_83E2;
		unk_83E2 = t2 - 1u;
		if (t2 == 1u)
			return stop_channel(ix);
		z80_block(30);
		a = unk_83E3 + 0x10u;
		return sound_163F(ix, a);
	}
	z80_block(19);
	a = unk_83DF;
	carry = a < 5u;
	if (a != 5u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(17);
	a = 0x29u;
	return set_fm_volume(ix, a);
}

uint32_t fm_effect_02(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t voice = 0;

	z80_block(47);
	unk_83E9 = 0x19u;
	voice = 0x1681u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	unk_83EA = 2u;
	a = 0xDu;
	return sound_16AC(ix, a);
}

uint32_t sound_16AC(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(56);
	unk_83E7 = a;
	hl = 0x1400u;
	unk_83E4 = 0x1400u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(63);
	unk_83E6 = 8u;
	unk_83E8 = 8u;
	a_2 = unk_83E9;
	carry = set_fm_volume(ix, a_2);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x16CFu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_16CF(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	z80_block(31);
	t1 = unk_83E6;
	unk_83E6 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(63);
		hl = unk_83E4 - 2u;
		unk_83E4 = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(31);
	hl = unk_83E7_ADDRESS;
	t2 = unk_83E7;
	unk_83E7 = t2 - 1u;
	if (t2 == 1u)
	{
		z80_block(31);
		t3 = unk_83EA;
		unk_83EA = t3 - 1u;
		if (t3 == 1u)
			return stop_channel(ix);
		z80_block(44);
		unk_83E6 = 2u;
		a = 0x31u;
		carry = set_fm_volume(ix, a);
		z80_block(20);
		hl = 0x1727u;
		set_channel_handler(hl, ix);
		return carry;
	}
	z80_block(37);
	t4 = unk_83E7;
	a = unk_83E9;
	if (t4 >= 7u)
	{
		z80_block(7);
		a -= 4u;
	}
	z80_block(37);
	a += 3u;
	unk_83E9 = a;
	carry = set_fm_volume(ix, a);
	z80_block(79);
	a = unk_83E8 + 1u;
	unk_83E6 = a;
	unk_83E8 = a;
	hl = 0x1400u;
	unk_83E4 = 0x1400u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t sound_1727(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(26);
	t1 = unk_83E6;
	unk_83E6 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(37);
	unk_83E9 = 0x3Bu;
	a = 9u;
	return sound_16AC(ix, a);
}

uint32_t fm_effect_03(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t channel = 0, hl = 0, ignored16 = 0, voice = 0;
	uint16_t saved_ix = 0;

	z80_block(53);
	saved_ix = ix;
	a = 0xA6u;
	start_speech(a);
	z80_block(41);
	channel = saved_ix;
	voice = 0x1736u;
	carry = load_fm_voice(voice, channel);
	z80_block(27);
	hl = 0xC00u;
	sound_2B87(hl, channel, &ignored16, &carry);
	z80_block(62);
	CHANNEL(channel)->unk_20 = 0x1Cu;
	a = 0xBu;
	CHANNEL(channel)->unk_2E = 0xBu;
	carry = set_fm_volume(channel, a);
	z80_block(17);
	carry = fm_key_on(channel);
	z80_block(20);
	hl = 0x177Du;
	set_channel_handler(hl, channel);
	return carry;
}

uint32_t sound_177D(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(17);
		a = 8u;
		return sound_2405(ix, a);
	}
	z80_block(27);
	hl = 0xC00u;
	sound_2B87(hl, ix, &ignored16, &carry);
	z80_block(129);
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 0x10u;
	CHANNEL(ix)->unk_20 = 0xCu;
	CHANNEL(ix)->unk_28 = 8u;
	a = 0xBu;
	CHANNEL(ix)->unk_2C = 0xBu;
	carry = set_fm_volume(ix, a);
	z80_block(20);
	hl = 0x17ADu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_17AD(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t bc = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(20);
		bc = 0xFFA0u;
		return sound_241C(bc, ix);
	}
	z80_block(52);
	CHANNEL(ix)->unk_20 = 0xCu;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(55);
	a = CHANNEL(ix)->unk_2C + 4u;
	CHANNEL(ix)->unk_2C = a;
	return set_fm_volume(ix, a);
}

uint32_t fm_effect_04(uint16_t ix)
{
	uint16_t bc = 0, hl = 0;

	z80_block(68);
	CHANNEL(ix)->unk_2C = 0u;
	CHANNEL(ix)->unk_21 = 0x1Cu;
	hl = pcm_instruments_ADDRESS - 0x2u;
	bc = 0x17CEu;
	return sound_2646(bc, hl, ix);
}

uint32_t fm_effect_05(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ix_2 = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x37u;
	carry = start_fm_effect(a);
	z80_block(14);
	ix_2 = saved_ix;
	return sound_181A(ix_2);
}

uint32_t sound_181A(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(26);
	CHANNEL(ix)->unk_28 = 2u;
	a = 0u;
	return sound_1820(ix, a);
}

uint32_t sound_1820(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(46);
	CHANNEL(ix)->unk_2C = a;
	voice = 0x17F8u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0x1200u;
	sound_2B87(hl, ix, &ignored16, &carry);
	z80_block(17);
	carry = set_fm_volume_from_record(ix);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(39);
	CHANNEL(ix)->unk_20 = 0x20u;
	hl = 0x183Fu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_183F(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(46);
		CHANNEL(ix)->unk_20 = 0x40u;
		hl = 0x1020u;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		z80_block(17);
		carry = set_fm_volume_from_record(ix);
		z80_block(20);
		hl = 0x1868u;
		set_channel_handler(hl, ix);
		return carry;
	}
	z80_block(40);
	bc = 0xFF80u;
	if ((CHANNEL(ix)->unk_20 & 1u) != 0u)
	{
		sound_2B80(ix, &bc, &carry);
		return carry;
	}
	z80_block(20);
	bc = 0x40u;
	sound_2B80(ix, &bc, &carry);
	return carry;
}

uint32_t sound_1868(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(17);
	a = 0x14u;
	return sound_1820(ix, a);
}

void fm_effect_37(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_20 = 8u;
	hl = 0x1881u;
	set_channel_handler(hl, ix);
}

uint32_t sound_1881(uint16_t ix, uint32_t carry)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(10);
	return sound_181A(ix);
}

uint32_t fm_effect_06(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x1736u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0xC00u;
	sound_2B87(hl, ix, &ignored16, &carry);
	z80_block(62);
	CHANNEL(ix)->unk_20 = 0x20u;
	a = 5u;
	CHANNEL(ix)->unk_2E = 5u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x18A9u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_18A9(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(17);
		a = 0xCu;
		return sound_2405(ix, a);
	}
	z80_block(46);
	CHANNEL(ix)->unk_20 = 0x10u;
	hl = 0xC00u;
	sound_2B87(hl, ix, &ignored16, &carry);
	z80_block(110);
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 0x10u;
	CHANNEL(ix)->unk_28 = 0xEu;
	a = 5u;
	CHANNEL(ix)->unk_2C = 5u;
	carry = set_fm_volume(ix, a);
	z80_block(20);
	hl = 0x18D9u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_18D9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t bc = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(20);
		bc = 0xFFF0u;
		return sound_241C(bc, ix);
	}
	z80_block(52);
	CHANNEL(ix)->unk_20 = 0x10u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(55);
	a = CHANNEL(ix)->unk_2C + 3u;
	CHANNEL(ix)->unk_2C = a;
	return set_fm_volume(ix, a);
}

uint32_t fm_effect_07(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(47);
	unk_83F1 = 2u;
	unk_83F0 = 0xCu;
	a = 0u;
	return sound_1938(ix, a);
}

uint32_t sound_1938(uint16_t ix, uint8_t a)
{
	z80_block(13);
	unk_83F2 = a;
	return sound_193B(ix);
}

uint32_t sound_193B(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(17);
	hl = next_random_byte();
	z80_block(62);
	unk_83EF = ((hl | (hl >> 8)) & 7u) + 0x12u;
	voice = 0x18FAu;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0xA00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(30);
	a = unk_83F2;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x1962u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1962(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(31);
	hl = unk_83EF_ADDRESS;
	t1 = unk_83EF;
	unk_83EF = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(31);
		hl = unk_83F0_ADDRESS;
		t2 = unk_83F0;
		unk_83F0 = t2 - 1u;
		if (t2 == 1u)
		{
			z80_block(31);
			t3 = unk_83F1;
			unk_83F1 = t3 - 1u;
			if (t3 == 1u)
				return stop_channel(ix);
			z80_block(37);
			unk_83F0 = 6u;
			a = 0x1Cu;
			return sound_1938(ix, a);
		}
		z80_block(24);
		if (unk_83F0 != 1u)
			return sound_193B(ix);
		z80_block(43);
		unk_83F2 += 8u;
		return sound_193B(ix);
	}
	z80_block(19);
	a = unk_83EF;
	carry = a < 8u;
	if (a != 8u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(45);
	hl = unk_83F0_ADDRESS;
	unk_83F0--;
	if (unk_83F0 >= 9u)
		return sound_193B(ix);
	z80_block(38);
	unk_83F0++;
	voice = 0x1913u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = pcm_instruments_ADDRESS - 0x2u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(37);
	a = unk_83F2 + 4u;
	carry = set_fm_volume(ix, a);
	z80_block(10);
	return fm_key_on(ix);
}

uint32_t fm_effect_08(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(45);
	CHANNEL(ix)->unk_28 = 3u;
	CHANNEL(ix)->unk_2C = 0xFu;
	a = 0x48u;
	return sound_19DB(ix, a);
}

uint32_t sound_19DB(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(65);
	CHANNEL(ix)->unk_20 = a;
	CHANNEL(ix)->unk_21 = a;
	voice = 0x19B8u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0x200u;
	sound_2B87(hl, ix, &ignored16, &carry);
	z80_block(17);
	carry = set_fm_volume_from_record(ix);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x19F9u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_19F9(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(33);
		t2 = CHANNEL(ix)->unk_28;
		CHANNEL(ix)->unk_28 = t2 - 1u;
		if (t2 == 1u)
			return stop_channel(ix);
		z80_block(81);
		CHANNEL(ix)->unk_2C += 0x1Au;
		a = CHANNEL(ix)->unk_21 + 2u;
		return sound_19DB(ix, a);
	}
	z80_block(36);
	if (CHANNEL(ix)->unk_20 < 0x40u)
	{
		sound_2B73(ix, &ignored16, &carry);
		return carry;
	}
	z80_block(20);
	bc = 0x40u;
	sound_2B80(ix, &bc, &carry);
	return carry;
}

uint32_t fm_effect_09(uint16_t ix)
{
	z80_block(27);
	unk_83F3 = 0u;
	return stop_channel(ix);
}

uint32_t fm_effect_0a(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ix_2 = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x33u;
	carry = start_fm_effect(a);
	z80_block(61);
	ix_2 = saved_ix;
	unk_83F3 = 1u;
	unk_83FB = 0x1Cu;
	a = 6u;
	return sound_1A58(ix_2, a);
}

uint32_t sound_1A58(uint16_t ix, uint8_t a)
{
	z80_block(33);
	unk_83F7 = a;
	unk_83F5 = 0x10u;
	return sound_1A60(ix);
}

uint32_t sound_1A60(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t voice = 0;

	z80_block(47);
	unk_83FA = 2u;
	voice = 0x1A2Au;
	carry = load_fm_voice(voice, ix);
	z80_block(13);
	a = unk_83F7;
	return sound_1A6E(ix, a);
}

uint32_t sound_1A6E(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0, d = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(30);
	unk_83F6 = a;
	hl = next_random_byte();
	z80_block(73);
	d = hl & 3u;
	hl = 0x80u + (((uint32_t)d << 8) | (hl >> 8));
	unk_83F8 = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(54);
	unk_83F4 = 0xCu;
	a_2 = unk_83F6 + d;
	carry = set_fm_volume(ix, a_2);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x1A98u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1A98(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	z80_block(31);
	t1 = unk_83F4;
	unk_83F4 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(63);
		hl = unk_83F8 + 0x40u;
		unk_83F8 = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(27);
	if (unk_83F3 == 0u)
		return stop_channel(ix);
	z80_block(31);
	t2 = unk_83F5;
	unk_83F5 = t2 - 1u;
	if (t2 == 1u)
	{
		z80_block(31);
		t3 = unk_83FB;
		unk_83FB = t3 - 1u;
		if (t3 == 1u)
			return stop_channel(ix);
		z80_block(30);
		a = unk_83F7 + 1u;
		return sound_1A58(ix, a);
	}
	z80_block(31);
	t4 = unk_83FA;
	unk_83FA = t4 - 1u;
	if (t4 == 1u)
		return sound_1A60(ix);
	z80_block(30);
	a = unk_83F6 + 0x10u;
	return sound_1A6E(ix, a);
}

uint32_t sound_1AF8(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(40);
	unk_83FE = a;
	voice = 0x1AD8u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0xA0u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(50);
	unk_83FC = 0x60u;
	a_2 = unk_83FE;
	carry = set_fm_volume(ix, a_2);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x1B1Bu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1B1B(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(27);
	carry = 0u;
	if (unk_83F3 == 0u)
		return stop_channel(ix);
	z80_block(26);
	t1 = unk_83FC;
	unk_83FC = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(31);
	t2 = unk_83FD;
	unk_83FD = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(30);
	a = unk_83FE + 1u;
	return sound_1AF8(ix, a);
}

uint32_t fm_effect_0b(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(67);
	unk_8404 = 0x1Cu;
	unk_8403 = 2u;
	voice = 0x1B36u;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0x400u;
	unk_8401 = 0x400u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(37);
	a = 8u;
	unk_8400 = 8u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x1B79u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1B79(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(31);
	hl = unk_8404_ADDRESS;
	t1 = unk_8404;
	unk_8404 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(7);
		a = 0xAu;
		return sound_1B8B(ix, a);
	}
	z80_block(19);
	a = unk_8404;
	carry = a < 0xCu;
	if (a != 0xCu)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(17);
	a = 0x27u;
	return set_fm_volume(ix, a);
}

uint32_t sound_1B8B(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0;

	z80_block(30);
	unk_8400 = a;
	carry = set_fm_volume(ix, a);
	z80_block(40);
	unk_83FF = 0x60u;
	hl = 0x1B9Cu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1B9C(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(31);
	t1 = unk_83FF;
	unk_83FF = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(63);
		hl = unk_8401 - 8u;
		unk_8401 = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(31);
	t2 = unk_8403;
	unk_8403 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(43);
	hl = 0x400u;
	unk_8401 = 0x400u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(17);
	a = 0x17u;
	return sound_1B8B(ix, a);
}

uint32_t fm_effect_0c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t channel = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x90u;
	start_pcm_effect(a);
	z80_block(157);
	channel = saved_ix;
	CHANNEL(channel)->unk_21 = 0xAu;
	CHANNEL(channel)->unk_29 = 0x98u;
	CHANNEL(channel)->unk_2D = 1u;
	CHANNEL(channel)->unk_38 = 0xC5u;
	CHANNEL(channel)->unk_39 = 0x1Bu;
	CHANNEL(channel)->unk_3C = 0x30u;
	CHANNEL(channel)->unk_3D = 2u;
	return sound_1C04(channel);
}

uint32_t sound_1C04(uint16_t ix)
{
	z80_block(86);
	CHANNEL(ix)->unk_28 = CHANNEL(ix)->unk_29;
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 7u;
	return sound_1C13(ix);
}

uint32_t sound_1C13(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, voice = 0;

	z80_block(106);
	CHANNEL(ix)->unk_2C = music_attenuation + CHANNEL(ix)->unk_2D;
	voice = (CHANNEL(ix)->unk_38 | ((uint32_t)CHANNEL(ix)->unk_39 << 8u));
	carry = load_fm_voice(voice, ix);
	z80_block(10);
	hl = 0x500u;
	return sound_1C28(hl, ix);
}

uint32_t sound_1C28(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0;

	z80_block(17);
	sound_2B87(hl, ix, &ignored16, &carry);
	z80_block(19);
	a = CHANNEL(ix)->unk_2C;
	return sound_1C2E(ix, a);
}

uint32_t sound_1C2E(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0;

	z80_block(17);
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(58);
	CHANNEL(ix)->unk_20 = CHANNEL(ix)->unk_21;
	hl = 0x1C40u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1C40(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0, h = 0, l = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0, voice = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(40);
		bc = 0x100u;
		if ((CHANNEL(ix)->unk_20 & 1u) != 0u)
		{
			sound_2B80(ix, &bc, &carry);
			return carry;
		}
		z80_block(20);
		bc = 0xFE00u;
		sound_2B80(ix, &bc, &carry);
		return carry;
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(30);
	if ((CHANNEL(ix)->unk_28 & 1u) == 0u)
	{
		z80_block(48);
		if (CHANNEL(ix)->unk_3C <= CHANNEL(ix)->unk_28)
			return sound_1C13(ix);
		z80_block(55);
		voice = (CHANNEL(ix)->unk_38 | ((uint32_t)CHANNEL(ix)->unk_39 << 8u));
		carry = load_fm_voice(voice, ix);
		z80_block(168);
		a = CHANNEL(ix)->unk_2C;
		t3 = CHANNEL(ix)->unk_3D;
		carry = (uint8_t)(a + t3) < a;
		CHANNEL(ix)->unk_2C = a + t3;
		t4 = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u)) - 0x80u - carry;
		h = (uint8_t)(t4 >> 8);
		l = (uint8_t)t4;
		CHANNEL(ix)->unk_32 = l;
		CHANNEL(ix)->unk_33 = h;
		hl = ((uint32_t)h << 8) | l;
		return sound_1C28(hl, ix);
	}
	z80_block(27);
	hl = 0x500u;
	sound_2B87(hl, ix, &ignored16, &carry);
	z80_block(36);
	a = CHANNEL(ix)->unk_2C + 0x18u;
	return sound_1C2E(ix, a);
}

uint32_t fm_effect_0d(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x1736u;
	carry = load_fm_voice(voice, ix);
	z80_block(46);
	CHANNEL(ix)->unk_29 = 4u;
	hl = 0xD00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(110);
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 8u;
	CHANNEL(ix)->unk_20 = 0x18u;
	a = 1u;
	CHANNEL(ix)->unk_2E = 1u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x1CCEu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1CCE(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(7);
		a = 1u;
		return sound_1CDB(ix, a);
	}
	z80_block(17);
	a = 0xCu;
	return sound_2405(ix, a);
}

uint32_t sound_1CDB(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(55);
	CHANNEL(ix)->unk_2C = a;
	CHANNEL(ix)->unk_2D = a;
	carry = set_fm_volume(ix, a);
	z80_block(65);
	CHANNEL(ix)->unk_20 = 0x10u;
	CHANNEL(ix)->unk_28 = 6u;
	hl = 0xD00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(116);
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 8u;
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 0xAu;
	hl = 0x1D0Au;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1D0A(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(20);
		bc = 0xFFC0u;
		return sound_241C(bc, ix);
	}
	z80_block(52);
	CHANNEL(ix)->unk_20 = 0x10u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
	{
		z80_block(33);
		t3 = CHANNEL(ix)->unk_29;
		CHANNEL(ix)->unk_29 = t3 - 1u;
		if (t3 == 1u)
			return stop_channel(ix);
		z80_block(43);
		CHANNEL(ix)->unk_28 = 0xAu;
		a = 0x31u;
		carry = set_fm_volume(ix, a);
		z80_block(20);
		hl = 0x1D4Fu;
		set_channel_handler(hl, ix);
		return carry;
	}
	z80_block(62);
	a = CHANNEL(ix)->unk_2C + 2u;
	CHANNEL(ix)->unk_2C = a;
	carry = set_fm_volume(ix, a);
	z80_block(68);
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 0xAu;
	hl = 0x800u;
	sound_2B87(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t sound_1D4F(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(36);
	a = CHANNEL(ix)->unk_2D + 0x12u;
	return sound_1CDB(ix, a);
}

uint32_t fm_effect_0e(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x1D5Bu;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = pcm_instruments_ADDRESS - 0x2u;
	unk_8407 = pcm_instruments_ADDRESS - 0x2u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(44);
	unk_8405 = 0x14u;
	a = 0u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x1D96u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1D96(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0, voice = 0;
	uint8_t t1 = 0;

	z80_block(31);
	hl = unk_8405_ADDRESS;
	t1 = unk_8405;
	unk_8405 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(57);
		unk_8405 = 0x60u;
		unk_8409 = 0x10u;
		voice = 0x1D5Bu;
		carry = load_fm_voice(voice, ix);
		z80_block(43);
		hl = 0x600u;
		unk_8407 = 0x600u;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		z80_block(7);
		a = 0u;
		return sound_1DD5(ix, a);
	}
	z80_block(24);
	a = unk_8405;
	if (a == 6u)
	{
		z80_block(17);
		a = 0x10u;
		return set_fm_volume(ix, a);
	}
	z80_block(44);
	hl = unk_8407;
	bc = 0xFE00u;
	if (a & 1u)
	{
		z80_block(10);
		bc = 0x100u;
	}
	z80_block(37);
	hl += bc;
	unk_8407 = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t sound_1DD5(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0;

	z80_block(30);
	unk_8406 = a;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x1DE4u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1DE4(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(31);
	hl = unk_8405_ADDRESS;
	t1 = unk_8405;
	unk_8405 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(41);
		unk_8405 = 0x20u;
		t2 = unk_8409;
		unk_8409 = t2 - 1u;
		if (t2 == 1u)
			return stop_channel(ix);
		z80_block(43);
		hl = 0x600u;
		unk_8407 = 0x600u;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		z80_block(30);
		a = unk_8406 + 4u;
		return sound_1DD5(ix, a);
	}
	z80_block(48);
	t3 = unk_8405;
	hl = unk_8407;
	bc = 0xFF00u;
	if (t3 & 1u)
	{
		z80_block(10);
		bc = 0x200u;
	}
	z80_block(37);
	hl += bc;
	unk_8407 = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t fm_effect_0f(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t channel = 0, hl = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x91u;
	start_pcm_effect(a);
	z80_block(60);
	channel = saved_ix;
	CHANNEL(channel)->unk_2E = 3u;
	hl = 0x1E1Au;
	carry = sound_1E5E(hl, channel);
	z80_block(20);
	hl = 0x1E4Cu;
	set_channel_handler(hl, channel);
	return carry;
}

uint32_t sound_1E4C(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t ix_2 = 0;
	uint16_t saved_ix = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_1E83(ix);
	z80_block(39);
	saved_ix = ix;
	a = 0x91u;
	start_pcm_effect(a);
	z80_block(24);
	ix_2 = saved_ix;
	return sound_1E88(ix_2);
}

uint32_t sound_1E5E(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl_2 = 0, ignored16 = 0;

	z80_block(17);
	carry = load_fm_voice(hl, ix);
	z80_block(27);
	hl_2 = pcm_instruments_ADDRESS - 0x2u;
	set_fm_pitch(hl_2, ix, &ignored16, &carry);
	z80_block(141);
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 6u;
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 6u;
	CHANNEL(ix)->unk_20 = 0x20u;
	a = CHANNEL(ix)->unk_2E;
	carry = set_fm_volume(ix, a);
	z80_block(10);
	return fm_key_on(ix);
}

uint32_t sound_1E83(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(17);
	a = 0x10u;
	return sound_2405(ix, a);
}

uint32_t sound_1E88(uint16_t ix)
{
	z80_block(19);
	CHANNEL(ix)->unk_29 = 0x11u;
	return sound_1E8C(ix);
}

uint32_t sound_1E8C(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(19);
	a = CHANNEL(ix)->unk_2E;
	return sound_1E8F(ix, a);
}

uint32_t sound_1E8F(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(55);
	CHANNEL(ix)->unk_2C = a;
	CHANNEL(ix)->unk_2D = a;
	carry = set_fm_volume(ix, a);
	z80_block(65);
	CHANNEL(ix)->unk_20 = 5u;
	CHANNEL(ix)->unk_28 = 5u;
	hl = 0xC00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(68);
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 0xAu;
	hl = 0x1EB5u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1EB5(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_2419(ix);
	z80_block(52);
	CHANNEL(ix)->unk_20 = 5u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 != 1u)
	{
		z80_block(17);
		sound_2433(ix, &bc, &carry);
		z80_block(83);
		t3 = 0xA00u - bc - carry;
		carry = z80_carry_sub16(0xA00u, bc, carry);
		hl = t3;
		AS16(CHANNEL(ix)->unk_32) = hl;
		hl = 0x600u;
		return sound_2B90(bc, hl, ix, carry);
	}
	z80_block(33);
	t4 = CHANNEL(ix)->unk_29;
	CHANNEL(ix)->unk_29 = t4 - 1u;
	if (t4 == 1u)
		return stop_channel(ix);
	z80_block(30);
	if ((((uint8_t)CHANNEL(ix)->unk_2A >> 4) & 1u) != 0u)
		return sound_1E8C(ix);
	z80_block(36);
	a = CHANNEL(ix)->unk_2D + 3u;
	return sound_1E8F(ix, a);
}

uint32_t fm_effect_10(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t channel = 0, hl = 0, ignored16 = 0, voice = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x84u;
	start_pcm_effect(a);
	z80_block(41);
	channel = saved_ix;
	voice = 0x1EEEu;
	carry = load_fm_voice(voice, channel);
	z80_block(27);
	hl = pcm_instruments_ADDRESS - 0x2u;
	set_fm_pitch(hl, channel, &ignored16, &carry);
	z80_block(27);
	hl = 0x800u;
	sound_2442(hl, channel);
	z80_block(62);
	CHANNEL(channel)->unk_20 = 0x20u;
	a = 5u;
	CHANNEL(channel)->unk_1E = 5u;
	carry = set_fm_volume(channel, a);
	z80_block(17);
	carry = fm_key_on(channel);
	z80_block(20);
	hl = 0x1F37u;
	set_channel_handler(hl, channel);
	return carry;
}

uint32_t sound_1F37(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(17);
		a = 0xCu;
		return sound_2405(ix, a);
	}
	z80_block(30);
	if (unk_82C1 < 0x12u)
	{
		z80_block(66);
		unk_82C2 = 0x1183u;
		unk_82C1 = 4u;
		unk_82CF = 0x11u;
	}
	z80_block(43);
	a = 5u;
	CHANNEL(ix)->unk_2C = 5u;
	carry = set_fm_volume(ix, a);
	z80_block(65);
	CHANNEL(ix)->unk_20 = 0x10u;
	CHANNEL(ix)->unk_28 = 0x10u;
	hl = 0xE00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(68);
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 0xAu;
	hl = 0x1F7Fu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_1F7F(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_2419(ix);
	z80_block(52);
	CHANNEL(ix)->unk_20 = 0x10u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(49);
	a = CHANNEL(ix)->unk_2C;
	if (((CHANNEL(ix)->unk_28 >> 3) & 1u) == 0u)
	{
		z80_block(7);
		a++;
	}
	z80_block(43);
	a += 2u;
	CHANNEL(ix)->unk_2C = a;
	carry = set_fm_volume(ix, a);
	z80_block(68);
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 0xAu;
	hl = 0x800u;
	sound_2B87(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t fm_effect_11(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t channel = 0, hl = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x93u;
	start_pcm_effect(a);
	z80_block(43);
	channel = saved_ix;
	CHANNEL(channel)->unk_2E = 0u;
	hl = 0x1FB2u;
	return sound_1FDB(hl, channel);
}

uint32_t sound_1FDB(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl_2 = 0;

	z80_block(17);
	carry = sound_1E5E(hl, ix);
	z80_block(20);
	hl_2 = 0x1FE4u;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_1FE4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t ix_2 = 0;
	uint16_t saved_ix = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_1E83(ix);
	z80_block(39);
	saved_ix = ix;
	a = 0x93u;
	start_pcm_effect(a);
	z80_block(24);
	ix_2 = saved_ix;
	return sound_1E88(ix_2);
}

uint32_t fm_effect_12(uint16_t ix)
{
	z80_block(10);
	return stop_channel(ix);
}

uint32_t fm_effect_13(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t channel = 0, hl = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x93u;
	start_pcm_effect(a);
	z80_block(53);
	channel = saved_ix;
	CHANNEL(channel)->unk_2E = 0u;
	hl = 0x1FF9u;
	return sound_1FDB(hl, channel);
}

uint32_t fm_effect_14(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x2025u;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0x1700u;
	unk_840A = 0x1700u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(89);
	unk_840C = 8u;
	unk_840D = 8u;
	unk_840E = 8u;
	a = 0xEu;
	unk_840F = 0xEu;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x2069u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2069(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(31);
	hl = unk_840C_ADDRESS;
	t1 = unk_840C;
	unk_840C = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(63);
		hl = unk_840A - 0x80u;
		unk_840A = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(32);
	unk_840C = 2u;
	hl++;
	t2 = unk_840D;
	unk_840D = t2 - 1u;
	if (t2 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(37);
	unk_840D = 8u;
	hl++;
	t3 = unk_840E;
	unk_840E = t3 - 1u;
	if (t3 == 1u)
		return stop_channel(ix);
	z80_block(43);
	a = unk_840F + 5u;
	unk_840F = a;
	return set_fm_volume(ix, a);
}

uint32_t fm_effect_15(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t channel = 0;
	uint16_t saved_ix = 0;

	z80_block(105);
	unk_8382 = 0x212Cu;
	unk_8381 = 0x15u;
	unk_838F = 0x13u;
	saved_ix = ix;
	a = 0x2Du;
	carry = start_fm_effect(a);
	z80_block(33);
	channel = saved_ix;
	CHANNEL(channel)->unk_2D = 0xBu;
	return sound_20CA(channel);
}

uint32_t sound_20CA(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(45);
	CHANNEL(ix)->unk_32 = 4u;
	CHANNEL(ix)->unk_28 = 0x14u;
	a = 0x2Cu;
	return sound_20D4(ix, a);
}

uint32_t sound_20D4(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(46);
	CHANNEL(ix)->unk_20 = a;
	voice = 0x2094u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0x400u;
	sound_2B87(hl, ix, &ignored16, &carry);
	z80_block(55);
	a_2 = CHANNEL(ix)->unk_2D;
	CHANNEL(ix)->unk_2C = a_2;
	carry = set_fm_volume(ix, a_2);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x20F5u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_20F5(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(52);
	CHANNEL(ix)->unk_20 = 0xEu;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(43);
	t3 = CHANNEL(ix)->unk_28;
	a = 0x58u;
	if (t3 == 0x13u)
		return sound_20D4(ix, a);
	z80_block(111);
	a = CHANNEL(ix)->unk_32;
	carry = (uint8_t)(a + 2u) < a;
	a += 2u;
	CHANNEL(ix)->unk_32 = a;
	bc = a;
	hl = (CHANNEL(ix)->unk_30 | ((uint32_t)CHANNEL(ix)->unk_31 << 8u));
	carry = sound_2B90(bc, hl, ix, carry);
	z80_block(55);
	a = CHANNEL(ix)->unk_2C + 3u;
	CHANNEL(ix)->unk_2C = a;
	return set_fm_volume(ix, a);
}

void sound_212C(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_20 = 0x10u;
	hl = 0x2136u;
	set_channel_handler(hl, ix);
}

uint32_t sound_2136(uint16_t ix, uint32_t carry)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(29);
	CHANNEL(ix)->unk_2D = 0x17u;
	return sound_20CA(ix);
}

uint32_t fm_effect_16(uint16_t ix)
{
	z80_block(66);
	unk_8342 = 0x21C6u;
	unk_8341 = 0x16u;
	unk_834F = 0x12u;
	return sound_216A(ix);
}

uint32_t sound_216A(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(48);
	CHANNEL(ix)->unk_34 = 8u;
	CHANNEL(ix)->unk_2C = 0xCu;
	hl = 0x1F0u;
	return sound_2175(hl, ix);
}

uint32_t sound_2175(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl_2 = 0, ignored16 = 0, voice = 0;

	z80_block(84);
	AS16(CHANNEL(ix)->unk_20) = hl;
	CHANNEL(ix)->unk_28 = 8u;
	voice = 0x2141u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl_2 = 0x100u;
	sound_2B87(hl_2, ix, &ignored16, &carry);
	z80_block(17);
	carry = set_fm_volume_from_record(ix);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl_2 = 0x2197u;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_2197(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t h = 0, l = 0;
	uint16_t bc = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	z80_block(100);
	t1 = (CHANNEL(ix)->unk_20 | ((uint32_t)CHANNEL(ix)->unk_21 << 8u)) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	CHANNEL(ix)->unk_20 = l;
	CHANNEL(ix)->unk_21 = h;
	if ((h | l) == 0u)
		return stop_channel(ix);
	z80_block(18);
	if (h == 0u)
	{
		z80_block(33);
		t2 = CHANNEL(ix)->unk_28;
		CHANNEL(ix)->unk_28 = t2 - 1u;
		if (t2 == 1u)
		{
			z80_block(59);
			CHANNEL(ix)->unk_28 = 8u;
			CHANNEL(ix)->unk_2C++;
			carry = set_fm_volume_from_record(ix);
		}
	}
	z80_block(36);
	bc = CHANNEL(ix)->unk_34;
	sound_2B80(ix, &bc, &carry);
	return carry;
}

uint32_t sound_21C6(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0;

	z80_block(17);
	fm_key_off(ix);
	z80_block(17);
	carry = fm_fast_release(ix);
	z80_block(39);
	CHANNEL(ix)->unk_20 = 0x50u;
	hl = 0x21D6u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_21D6(uint16_t ix, uint32_t carry)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(10);
	return sound_216A(ix);
}

uint32_t fm_effect_17(uint16_t ix)
{
	z80_block(20);
	unk_8416 = 0x14u;
	return sound_21FB(ix);
}

uint32_t sound_21FB(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, voice = 0;

	z80_block(47);
	unk_8411 = 7u;
	voice = 0x21DDu;
	carry = load_fm_voice(voice, ix);
	z80_block(10);
	hl = 0x500u;
	return sound_2209(hl, ix);
}

uint32_t sound_2209(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0;

	z80_block(49);
	unk_8412 = hl;
	unk_8414 = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(33);
	unk_8410 = 9u;
	a = unk_8411;
	return sound_221A(ix, a);
}

uint32_t sound_221A(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0;

	z80_block(17);
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x2226u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2226(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0, voice = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(31);
	hl = unk_8410_ADDRESS;
	t1 = unk_8410;
	unk_8410 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(48);
		t2 = unk_8410;
		hl = unk_8412;
		bc = 0x40u;
		if ((t2 & 1u) == 0u)
		{
			z80_block(10);
			bc = 0xFF80u;
		}
		z80_block(37);
		hl += bc;
		unk_8412 = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(41);
	unk_8410 = 8u;
	hl = unk_8416_ADDRESS;
	t3 = unk_8416;
	unk_8416 = t3 - 1u;
	if (t3 == 1u)
		return stop_channel(ix);
	z80_block(22);
	if ((unk_8416 & 1u) == 0u)
	{
		z80_block(24);
		if (unk_8416 >= 0xAu)
			return sound_21FB(ix);
		z80_block(27);
		voice = 0x21DDu;
		carry = load_fm_voice(voice, ix);
		z80_block(84);
		a = unk_8411;
		carry = (uint8_t)(a + 8u) < a;
		unk_8411 = a + 8u;
		hl = unk_8414 - 0x80u - carry;
		return sound_2209(hl, ix);
	}
	z80_block(43);
	hl = 0x500u;
	unk_8412 = 0x500u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(30);
	a = unk_8411 + 0x14u;
	return sound_221A(ix, a);
}

uint32_t fm_effect_18(uint16_t ix)
{
	z80_block(153);
	CHANNEL(ix)->unk_21 = 9u;
	CHANNEL(ix)->unk_29 = 0x10u;
	CHANNEL(ix)->unk_2D = 7u;
	CHANNEL(ix)->unk_38 = 0x80u;
	CHANNEL(ix)->unk_39 = 0x22u;
	CHANNEL(ix)->unk_3C = 0xAu;
	CHANNEL(ix)->unk_3D = 8u;
	return sound_1C04(ix);
}

uint32_t fm_effect_19(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ix_2 = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x1Eu;
	carry = start_fm_effect(a);
	z80_block(21);
	ix_2 = saved_ix;
	a = 0u;
	return sound_22DD(ix_2, a);
}

uint32_t sound_22DD(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, voice = 0;

	z80_block(65);
	CHANNEL(ix)->unk_2C = a;
	CHANNEL(ix)->unk_28 = 0x13u;
	voice = 0x22B9u;
	carry = load_fm_voice(voice, ix);
	z80_block(48);
	hl = 0xF00u;
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 0xFu;
	return sound_22F3(hl, ix);
}

uint32_t sound_22F3(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl_2 = 0, ignored16 = 0;

	z80_block(17);
	sound_2B87(hl, ix, &ignored16, &carry);
	z80_block(17);
	carry = set_fm_volume_from_record(ix);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(39);
	CHANNEL(ix)->unk_20 = 0xAu;
	hl_2 = 0x2306u;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_2306(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0, h = 0, l = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(31);
		t2 = CHANNEL(ix)->unk_20;
		carry = t2 > 2u;
		if (2u != t2)
		{
			z80_cycles(6);
			return carry;
		}
		z80_block(55);
		hl = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u));
		set_fm_pitch(hl, ix, &ignored16, &carry);
		z80_block(36);
		a = CHANNEL(ix)->unk_2C + 0x10u;
		return set_fm_volume(ix, a);
	}
	z80_block(33);
	t3 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t3 - 1u;
	if (t3 == 1u)
		return stop_channel(ix);
	z80_block(36);
	if (CHANNEL(ix)->unk_28 < 0xAu)
	{
		z80_block(30);
		if ((CHANNEL(ix)->unk_28 & 1u) == 0u)
		{
			z80_block(23);
			CHANNEL(ix)->unk_2C++;
		}
	}
	z80_block(107);
	l = CHANNEL(ix)->unk_30;
	h = CHANNEL(ix)->unk_31;
	CHANNEL(ix)->unk_32 = l;
	CHANNEL(ix)->unk_33 = h;
	t4 = (((uint32_t)h << 8) | l) + 0x40u;
	hl = t4;
	return sound_22F3(hl, ix);
}

uint32_t fm_effect_1a(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(152);
	unk_8382 = 0x244Fu;
	unk_8342 = 0x2012u;
	unk_8381 = 0x1Au;
	unk_8341 = 0x13u;
	unk_838F = 0x30u;
	unk_834F = 0x30u;
	voice = 0x1EEEu;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0x1080u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(27);
	hl = 0x680u;
	sound_2442(hl, ix);
	z80_block(62);
	CHANNEL(ix)->unk_20 = 0x18u;
	a = 0u;
	CHANNEL(ix)->unk_2E = 0u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x2393u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2393(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(26);
		CHANNEL(ix)->unk_29 = 0x20u;
		a = 0u;
		return sound_23A4(ix, a);
	}
	z80_block(17);
	a = 8u;
	return sound_2405(ix, a);
}

uint32_t sound_23A4(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(55);
	CHANNEL(ix)->unk_2C = a;
	CHANNEL(ix)->unk_2D = a;
	carry = set_fm_volume(ix, a);
	z80_block(65);
	CHANNEL(ix)->unk_20 = 6u;
	CHANNEL(ix)->unk_28 = 5u;
	hl = 0xD80u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(68);
	CHANNEL(ix)->unk_30 = 0x80u;
	CHANNEL(ix)->unk_31 = 0xAu;
	hl = 0x23CAu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_23CA(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_2419(ix);
	z80_block(52);
	CHANNEL(ix)->unk_20 = 6u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 != 1u)
	{
		z80_block(17);
		sound_2433(ix, &bc, &carry);
		z80_block(83);
		t3 = 0xA80u - bc - carry;
		carry = z80_carry_sub16(0xA80u, bc, carry);
		hl = t3;
		AS16(CHANNEL(ix)->unk_32) = hl;
		hl = 0x680u;
		return sound_2B90(bc, hl, ix, carry);
	}
	z80_block(33);
	t4 = CHANNEL(ix)->unk_29;
	CHANNEL(ix)->unk_29 = t4 - 1u;
	if (t4 == 1u)
		return stop_channel(ix);
	z80_block(49);
	a = CHANNEL(ix)->unk_2D;
	if (((CHANNEL(ix)->unk_29 >> 4) & 1u) == 0u)
	{
		z80_block(7);
		a++;
	}
	z80_block(17);
	a++;
	return sound_23A4(ix, a);
}

uint32_t sound_2405(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0;
	uint16_t bc = 0;

	z80_block(29);
	if (a == CHANNEL(ix)->unk_20)
	{
		z80_block(36);
		a_2 = CHANNEL(ix)->unk_2E + 0x20u;
		return set_fm_volume(ix, a_2);
	}
	z80_block(20);
	bc = 0xFF80u;
	sound_2B80(ix, &bc, &carry);
	return carry;
}

uint32_t sound_2419(uint16_t ix)
{
	uint16_t bc = 0;

	z80_block(10);
	bc = 0xFF80u;
	return sound_241C(bc, ix);
}

uint32_t sound_241C(uint16_t bc, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t h = 0, l = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint16_t t1 = 0;

	z80_block(30);
	if ((CHANNEL(ix)->unk_20 & 1u) != 0u)
	{
		sound_2B80(ix, &bc, &carry);
		return carry;
	}
	z80_block(97);
	t1 = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u)) + bc;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	CHANNEL(ix)->unk_32 = l;
	CHANNEL(ix)->unk_33 = h;
	hl = ((uint32_t)h << 8) | l;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

void sound_2433(uint16_t ix, uint16_t *p_bc, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t bc = 0, hl = 0;

	z80_block(40);
	CHANNEL(ix)->unk_2C++;
	carry = set_fm_volume_from_record(ix);
	z80_block(17);
	hl = next_random_byte();
	z80_block(29);
	carry = 0u;
	bc = (((hl >> 8) & 0xFu) << 8) | (uint8_t)hl;
	*p_bc = bc;
	*p_carry = carry;
}

void sound_2442(uint16_t hl, uint16_t ix)
{
	z80_block(86);
	AS16(CHANNEL(ix)->unk_30) = hl;
	AS16(CHANNEL(ix)->unk_32) = hl;
}

uint32_t sound_244F(uint16_t ix)
{
	z80_block(19);
	CHANNEL(ix)->unk_28 = 8u;
	return sound_2453(ix);
}

uint32_t sound_2453(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x1EEEu;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0x1100u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(27);
	hl = 0x700u;
	sound_2442(hl, ix);
	z80_block(62);
	CHANNEL(ix)->unk_20 = 0x20u;
	a = 4u;
	CHANNEL(ix)->unk_2E = 4u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x247Au;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_247A(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(17);
		a = 0x10u;
		return sound_2405(ix, a);
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 != 1u)
		return sound_2453(ix);
	z80_block(26);
	CHANNEL(ix)->unk_29 = 0x20u;
	a = 6u;
	return sound_2491(ix, a);
}

uint32_t sound_2491(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(55);
	CHANNEL(ix)->unk_2C = a;
	CHANNEL(ix)->unk_2D = a;
	carry = set_fm_volume(ix, a);
	z80_block(65);
	CHANNEL(ix)->unk_20 = 6u;
	CHANNEL(ix)->unk_28 = 5u;
	hl = 0xE00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(68);
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 0xBu;
	hl = 0x24B7u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_24B7(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;
	uint16_t t3 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_2419(ix);
	z80_block(52);
	CHANNEL(ix)->unk_20 = 6u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 != 1u)
	{
		z80_block(17);
		sound_2433(ix, &bc, &carry);
		z80_block(83);
		t3 = 0xB00u - bc - carry;
		carry = z80_carry_sub16(0xB00u, bc, carry);
		hl = t3;
		AS16(CHANNEL(ix)->unk_32) = hl;
		hl = 0x700u;
		return sound_2B90(bc, hl, ix, carry);
	}
	z80_block(33);
	t4 = CHANNEL(ix)->unk_29;
	CHANNEL(ix)->unk_29 = t4 - 1u;
	if (t4 == 1u)
		return stop_channel(ix);
	z80_block(55);
	t5 = CHANNEL(ix)->unk_29;
	carry = t5 < 0x1Eu;
	a = CHANNEL(ix)->unk_2D;
	if (t5 < 0x1Eu)
	{
		z80_block(17);
		a += 2u;
		return sound_2491(ix, a);
	}
	z80_block(17);
	a = a - 1u - carry;
	return sound_2491(ix, a);
}

uint32_t fm_effect_1b(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x24F6u;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0x240u;
	unk_8418 = 0x240u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(44);
	unk_8417 = 0xB0u;
	a = 9u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x2531u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2531(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0;

	z80_block(31);
	hl = unk_8417_ADDRESS;
	t1 = unk_8417;
	unk_8417 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(34);
		unk_8417 = 0x90u;
		a = 0x2Du;
		carry = set_fm_volume(ix, a);
		z80_block(20);
		hl = 0x2556u;
		set_channel_handler(hl, ix);
		return carry;
	}
	z80_block(53);
	hl = unk_8418 + 0x80u;
	a = (uint8_t)(hl >> 8);
	carry = a < 0x11u;
	if (a >= 0x11u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(26);
	unk_8418 = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t sound_2556(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(31);
	hl = unk_8417_ADDRESS;
	t1 = unk_8417;
	unk_8417 = t1 - 1u;
	if (t1 == 1u)
		return stop_channel(ix);
	z80_block(19);
	a = unk_8417;
	carry = a < 0x88u;
	if (a != 0x88u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(17);
	a = 0x19u;
	return set_fm_volume(ix, a);
}

uint32_t fm_effect_1c(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(73);
	unk_8342 = 0x25FEu;
	unk_8341 = 0x1Cu;
	unk_834F = 0x14u;
	a = 5u;
	return sound_2591(ix, a);
}

uint32_t sound_2591(uint16_t ix, uint8_t a)
{
	z80_block(19);
	CHANNEL(ix)->unk_29 = 2u;
	return sound_2595(ix, a);
}

uint32_t sound_2595(uint16_t ix, uint8_t a)
{
	z80_block(38);
	CHANNEL(ix)->unk_2C = a;
	CHANNEL(ix)->unk_28 = 0xEu;
	return sound_259C(ix);
}

uint32_t sound_259C(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(46);
	CHANNEL(ix)->unk_20 = 0x16u;
	voice = 0x2566u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0xA00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(17);
	carry = set_fm_volume_from_record(ix);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x25B8u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_25B8(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(33);
		t2 = CHANNEL(ix)->unk_28;
		CHANNEL(ix)->unk_28 = t2 - 1u;
		if (t2 == 1u)
		{
			z80_block(33);
			t3 = CHANNEL(ix)->unk_29;
			CHANNEL(ix)->unk_29 = t3 - 1u;
			if (t3 == 1u)
				return stop_channel(ix);
			z80_block(17);
			a = 0x1Du;
			return sound_2595(ix, a);
		}
		z80_block(36);
		if (CHANNEL(ix)->unk_28 != 1u)
			return sound_259C(ix);
		z80_block(55);
		CHANNEL(ix)->unk_2C += 8u;
		return sound_259C(ix);
	}
	z80_block(31);
	a = CHANNEL(ix)->unk_20;
	carry = a < 8u;
	if (a != 8u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(59);
	CHANNEL(ix)->unk_28--;
	if (CHANNEL(ix)->unk_28 >= 0xAu)
		return sound_259C(ix);
	z80_block(59);
	CHANNEL(ix)->unk_28++;
	a = CHANNEL(ix)->unk_2C + 0x30u;
	return set_fm_volume(ix, a);
}

void sound_25FE(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_20 = 0x16u;
	hl = 0x2608u;
	set_channel_handler(hl, ix);
}

uint32_t sound_2608(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(17);
	a = 8u;
	return sound_2591(ix, a);
}

uint32_t fm_effect_1d(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(88);
	unk_8382 = 0x26ACu;
	unk_8381 = 0x1Du;
	unk_838F = 0x1Du;
	CHANNEL(ix)->unk_2C = 0u;
	hl = pcm_instruments_ADDRESS - 0x2u;
	return sound_263F(hl, ix);
}

uint32_t sound_263F(uint16_t hl, uint16_t ix)
{
	uint16_t bc = 0;

	z80_block(29);
	CHANNEL(ix)->unk_21 = 0x1Au;
	bc = 0x2611u;
	return sound_2646(bc, hl, ix);
}

uint32_t sound_2646(uint16_t bc, uint16_t hl, uint16_t ix)
{
	z80_block(57);
	AS16(CHANNEL(ix)->unk_38) = bc;
	CHANNEL(ix)->unk_28 = 3u;
	return sound_2650(hl, ix);
}

uint32_t sound_2650(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl_2 = 0, ignored16 = 0, voice = 0;

	z80_block(131);
	AS16(CHANNEL(ix)->unk_30) = hl;
	CHANNEL(ix)->unk_20 = CHANNEL(ix)->unk_21;
	voice = (CHANNEL(ix)->unk_38 | ((uint32_t)CHANNEL(ix)->unk_39 << 8u));
	carry = load_fm_voice(voice, ix);
	z80_block(55);
	hl_2 = (CHANNEL(ix)->unk_30 | ((uint32_t)CHANNEL(ix)->unk_31 << 8u));
	set_fm_pitch(hl_2, ix, &ignored16, &carry);
	z80_block(17);
	carry = set_fm_volume_from_record(ix);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl_2 = 0x267Au;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_267A(uint16_t ix, uint32_t carry)
{
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
	{
		z80_block(39);
		CHANNEL(ix)->unk_20 = 0xC0u;
		hl = 0x26A5u;
		set_channel_handler(hl, ix);
		return carry;
	}
	z80_block(78);
	hl = (CHANNEL(ix)->unk_30 | ((uint32_t)CHANNEL(ix)->unk_31 << 8u));
	bc = 0x1C0u;
	if (CHANNEL(ix)->unk_28 & 1u)
	{
		z80_block(10);
		bc = 0x140u;
	}
	z80_block(21);
	hl += bc;
	return sound_2650(hl, ix);
}

uint32_t sound_26A5(uint16_t ix, uint32_t carry)
{
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 == 1u)
		return stop_channel(ix);
	z80_block(10);
	return carry;
}

void sound_26AC(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_20 = 8u;
	hl = 0x26B6u;
	set_channel_handler(hl, ix);
}

uint32_t sound_26B6(uint16_t ix, uint32_t carry)
{
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(39);
	CHANNEL(ix)->unk_2C = 8u;
	hl = pcm_instruments_ADDRESS - 0x1u;
	return sound_263F(hl, ix);
}

uint32_t fm_effect_1e(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0;

	z80_block(17);
	fm_key_off(ix);
	z80_block(17);
	carry = fm_fast_release(ix);
	z80_block(39);
	CHANNEL(ix)->unk_20 = 0x30u;
	hl = 0x26D4u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_26D4(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(17);
	a = 0xCu;
	return sound_22DD(ix, a);
}

uint32_t fm_effect_1f(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x26DDu;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0x500u;
	unk_841C = 0x500u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(24);
	a = 1u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x2713u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2713(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(58);
	hl = unk_841C + 0x80u;
	if (hl >> 8 != 0x10u)
	{
		z80_block(26);
		unk_841C = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(47);
	unk_841E = 0x10u;
	voice = 0x26DDu;
	carry = load_fm_voice(voice, ix);
	z80_block(7);
	a = 1u;
	return sound_2733(ix, a);
}

uint32_t sound_2733(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(30);
	unk_841B = a;
	carry = set_fm_volume(ix, a);
	z80_block(27);
	hl = pcm_instruments_ADDRESS - 0x2u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(37);
	unk_841A = 0x20u;
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x274Du;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_274D(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(26);
	hl = unk_841A_ADDRESS;
	t1 = unk_841A;
	unk_841A = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(41);
	unk_841A = 0x20u;
	hl = unk_841E_ADDRESS;
	t2 = unk_841E;
	unk_841E = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(19);
	a = unk_841E;
	carry = a < 8u;
	if (a >= 8u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(30);
	a = unk_841B + 1u;
	return sound_2733(ix, a);
}

uint32_t fm_effect_20(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(17);
	a = 8u;
	return sound_2591(ix, a);
}

uint32_t fm_effect_21(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(47);
	unk_841F = 1u;
	voice = 0x276Cu;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0x400u;
	unk_8423 = 0x400u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(24);
	a = 9u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x27A7u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_27A7(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(58);
	hl = unk_8423 + 0x10u;
	if (hl >> 8 != 0xBu)
	{
		z80_block(26);
		unk_8423 = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(53);
	unk_8420 = 0xF00u;
	voice = 0x276Cu;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = fm_note_pitches_ADDRESS - 0xCu;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(37);
	a = 0x11u;
	unk_8422 = 0x11u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x27DDu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_27DD(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	if (unk_841F == 0u)
		return stop_channel(ix);
	z80_block(51);
	hl = unk_8420 - 1u;
	unk_8420 = hl;
	carry = 0u;
	if ((uint8_t)((hl >> 8) | hl) != 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(64);
	unk_8420 = 0xF00u;
	a = unk_8422 + 1u;
	if (((a >> 6) & 1u) != 0u)
		return stop_channel(ix);
	z80_block(23);
	unk_8422 = a;
	return set_fm_volume(ix, a);
}

uint32_t fm_effect_22(uint16_t ix)
{
	uint8_t b = 0;
	uint16_t channel = 0, de = 0;
	uint16_t saved_ix = 0;

	z80_block(228);
	unk_8042 = 0x2875u;
	unk_8082 = 0x2870u;
	unk_80C2 = 0x286Bu;
	unk_8102 = 0x2866u;
	unk_8142 = 0x2861u;
	unk_8342 = 0x285Cu;
	unk_8382 = 0x2857u;
	saved_ix = ix;
	b = 7u;
	channel = CHANNEL_ADDRESS(1);
	de = 0x40u;
	for (;;)
	{
		z80_block(75);
		CHANNEL(channel)->sound = 0x22u;
		CHANNEL(channel)->priority = 0x12u;
		channel += de;
		b--;
		if (b == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(33);
	channel = saved_ix;
	CHANNEL(channel)->unk_2C = 0x14u;
	return sound_284D(channel);
}

uint32_t sound_284D(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_34 = 5u;
	hl = 0x2C0u;
	return sound_2175(hl, ix);
}

uint32_t sound_2857(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(17);
	a = 7u;
	return sound_2877(ix, a);
}

uint32_t sound_285C(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(17);
	a = 6u;
	return sound_2877(ix, a);
}

uint32_t sound_2861(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(17);
	a = 5u;
	return sound_2877(ix, a);
}

uint32_t sound_2866(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(17);
	a = 4u;
	return sound_2877(ix, a);
}

uint32_t sound_286B(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(17);
	a = 3u;
	return sound_2877(ix, a);
}

uint32_t sound_2870(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(17);
	a = 2u;
	return sound_2877(ix, a);
}

uint32_t sound_2875(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(7);
	a = 1u;
	return sound_2877(ix, a);
}

uint32_t sound_2877(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(111);
	CHANNEL(ix)->unk_28 = a;
	a = ((uint32_t)a << 1) + 0x14u;
	t1 = CHANNEL(ix)->unk_28;
	carry = (uint8_t)(a + t1) < a;
	CHANNEL(ix)->unk_2C = a + t1;
	CHANNEL(ix)->unk_20 = 0x50u;
	hl = 0x288Eu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_288E(uint16_t ix, uint32_t carry)
{
	uint8_t t1 = 0, t2 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(47);
	CHANNEL(ix)->unk_20 = 0x50u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(10);
	return sound_284D(ix);
}

uint32_t fm_effect_23(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x289Du;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0x1700u;
	unk_8425 = 0x1700u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(89);
	unk_8427 = 8u;
	unk_8428 = 8u;
	unk_8429 = 0xCu;
	a = 6u;
	unk_842A = 6u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x28E1u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_28E1(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(31);
	hl = unk_8427_ADDRESS;
	t1 = unk_8427;
	unk_8427 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(63);
		hl = unk_8425 - 0x90u;
		unk_8425 = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(32);
	unk_8427 = 3u;
	hl++;
	t2 = unk_8428;
	unk_8428 = t2 - 1u;
	if (t2 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(37);
	unk_8428 = 8u;
	hl++;
	t3 = unk_8429;
	unk_8429 = t3 - 1u;
	if (t3 == 1u)
		return stop_channel(ix);
	z80_block(43);
	a = unk_842A + 4u;
	unk_842A = a;
	return set_fm_volume(ix, a);
}

uint32_t fm_effect_24(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t channel = 0, hl = 0, ignored16 = 0, voice = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x93u;
	start_pcm_effect(a);
	z80_block(41);
	channel = saved_ix;
	voice = 0x290Cu;
	carry = load_fm_voice(voice, channel);
	z80_block(27);
	hl = 0xC00u;
	set_fm_pitch(hl, channel, &ignored16, &carry);
	z80_block(110);
	CHANNEL(channel)->unk_30 = 0u;
	CHANNEL(channel)->unk_31 = 6u;
	CHANNEL(channel)->unk_20 = 0x10u;
	a = 2u;
	CHANNEL(channel)->unk_2E = 2u;
	carry = set_fm_volume(channel, a);
	z80_block(17);
	carry = fm_key_on(channel);
	z80_block(20);
	hl = 0x2958u;
	set_channel_handler(hl, channel);
	return carry;
}

uint32_t sound_2958(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t voice = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(17);
		a = 8u;
		return sound_2405(ix, a);
	}
	z80_block(94);
	CHANNEL(ix)->unk_29 = 0x10u;
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 6u;
	voice = 0x290Cu;
	carry = load_fm_voice(voice, ix);
	z80_block(7);
	a = 2u;
	return sound_2978(ix, a);
}

uint32_t sound_2978(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(55);
	CHANNEL(ix)->unk_2C = a;
	CHANNEL(ix)->unk_2D = a;
	carry = set_fm_volume(ix, a);
	z80_block(65);
	CHANNEL(ix)->unk_20 = 4u;
	CHANNEL(ix)->unk_28 = 5u;
	hl = 0x200u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x2998u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2998(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(20);
		bc = 0xFF80u;
		sound_2B80(ix, &bc, &carry);
		return carry;
	}
	z80_block(52);
	CHANNEL(ix)->unk_20 = 4u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
	{
		z80_block(33);
		t3 = CHANNEL(ix)->unk_29;
		CHANNEL(ix)->unk_29 = t3 - 1u;
		if (t3 == 1u)
			return stop_channel(ix);
		z80_block(36);
		a = CHANNEL(ix)->unk_2D + 4u;
		return sound_2978(ix, a);
	}
	z80_block(17);
	sound_2433(ix, &bc, &carry);
	z80_block(98);
	t4 = 0xA00u - bc - carry;
	carry = z80_carry_sub16(0xA00u, bc, carry);
	hl = t4;
	AS16(CHANNEL(ix)->unk_30) = hl;
	hl = 0x600u - bc - carry;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t fm_effect_25(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x29D2u;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0x1100u;
	unk_842C = 0x1100u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(24);
	a = 0u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(40);
	unk_842B = 8u;
	hl = 0x2A0Du;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2A0D(uint16_t ix, uint32_t carry)
{
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0;

	z80_block(31);
	hl = unk_842B_ADDRESS;
	t1 = unk_842B;
	unk_842B = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(67);
		hl = unk_842C - 0x40u - carry;
		unk_842C = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(53);
	unk_842B = 0xF0u;
	hl = 0xF40u;
	unk_842C = 0xF40u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(20);
	hl = 0x2A33u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2A33(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0;

	z80_block(31);
	hl = unk_842B_ADDRESS;
	t1 = unk_842B;
	unk_842B = t1 - 1u;
	if (t1 == 1u)
		return stop_channel(ix);
	z80_block(19);
	a = unk_842B;
	carry = a < 0xD8u;
	if (a >= 0xD8u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(32);
	hl = unk_842C;
	a = (uint8_t)hl;
	carry = a < 0x68u;
	if (a == 0x68u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(47);
	hl += 2u;
	unk_842C = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t fm_effect_26(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ix_2 = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x28u;
	carry = start_fm_effect(a);
	z80_block(41);
	ix_2 = saved_ix;
	unk_8430 = 2u;
	a = 0u;
	return sound_2A78(ix_2, a);
}

uint32_t sound_2A78(uint16_t ix, uint8_t a)
{
	uint16_t de = 0;

	z80_block(63);
	unk_8431 = a;
	unk_842F = 9u;
	de = 0x1200u;
	unk_8434 = 0x1200u;
	return sound_2A87(de, ix);
}

uint32_t sound_2A87(uint16_t de, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(47);
	unk_8432 = de;
	voice = 0x2A4Fu;
	carry = load_fm_voice(voice, ix);
	z80_block(33);
	hl = unk_8432;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(30);
	a = unk_8431;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(40);
	unk_842E = 0x1Cu;
	hl = 0x2AABu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2AAB(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t de = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(31);
	hl = unk_842E_ADDRESS;
	t1 = unk_842E;
	unk_842E = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(19);
		a = unk_842E;
		carry = a < 0xCu;
		if (a != 0xCu)
		{
			z80_cycles(6);
			return carry;
		}
		z80_block(33);
		hl = unk_8434;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		z80_block(30);
		a = unk_8431 + 0x10u;
		return set_fm_volume(ix, a);
	}
	z80_block(31);
	t2 = unk_842F;
	unk_842F = t2 - 1u;
	if (t2 != 1u)
	{
		z80_block(115);
		unk_8434 = unk_8432;
		hl = fm_effect_26_pitches_ADDRESS - 0x2u + (uint8_t)((uint32_t)unk_842F << 1);
		de = SOUND_ROM16(hl);
		return sound_2A87(de, ix);
	}
	z80_block(31);
	t3 = unk_8430;
	unk_8430 = t3 - 1u;
	if (t3 != 1u)
	{
		z80_block(30);
		a = unk_8431 + 0x15u;
		return sound_2A78(ix, a);
	}
	z80_block(17);
	carry = stop_channel(ix);
	z80_block(22);
	carry = 0u;
	if (unk_8458 == 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(39);
	a = 0x34u;
	carry = start_fm_effect(a);
	z80_block(24);
	return carry;
}

uint32_t fm_effect_27(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t voice = 0;

	z80_block(113);
	CHANNEL(ix)->unk_28 = 2u;
	CHANNEL(ix)->unk_2C = 0x1Bu;
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 5u;
	voice = 0x2B14u;
	carry = load_fm_voice(voice, ix);
	z80_block(7);
	a = 0x28u;
	return sound_2B46(ix, a);
}

uint32_t sound_2B46(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0;

	z80_block(36);
	CHANNEL(ix)->unk_20 = a;
	carry = sound_2B95(ix);
	z80_block(20);
	hl = 0x2B52u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2B52(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(36);
		carry = CHANNEL(ix)->unk_20 < 0x24u;
		return sound_2BA4(ix, carry);
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(17);
	a = sound_2BB2(ix);
	z80_block(43);
	CHANNEL(ix)->unk_2C = a + 0x26u;
	a = 0x2Cu;
	return sound_2B46(ix, a);
}

void sound_2B73(uint16_t ix, uint16_t *p_bc, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t bc = 0;

	z80_block(40);
	bc = 0x80u;
	if ((CHANNEL(ix)->unk_20 & 1u) == 0u)
		sound_2B80(ix, &bc, &carry);
	else
	{
		z80_block(10);
		bc = 0xFF00u;
		sound_2B80(ix, &bc, &carry);
	}
	*p_bc = bc;
	*p_carry = carry;
}

void sound_2B80(uint16_t ix, uint16_t *p_bc, uint32_t *p_carry)
{
	uint16_t bc = (uint16_t)*p_bc;
	uint32_t carry = *p_carry;
	uint16_t hl = 0;

	z80_block(38);
	hl = (CHANNEL(ix)->unk_30 | ((uint32_t)CHANNEL(ix)->unk_31 << 8u));
	*p_bc = bc;
	sound_2B86(hl, ix, p_bc, &carry);
	*p_carry = carry;
}

void sound_2B86(uint16_t hl, uint16_t ix, uint16_t *p_bc, uint32_t *p_carry)
{
	uint16_t bc = (uint16_t)*p_bc;
	uint32_t carry = *p_carry;
	uint16_t bc_2 = 0;

	z80_block(11);
	hl += bc;
	*p_bc = bc_2;
	sound_2B87(hl, ix, p_bc, &carry);
	*p_carry = carry;
}

void sound_2B87(uint16_t hl, uint16_t ix, uint16_t *p_bc, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t bc = 0;

	z80_block(48);
	AS16(CHANNEL(ix)->unk_30) = hl;
	*p_bc = bc;
	set_fm_pitch(hl, ix, p_bc, &carry);
	*p_carry = carry;
}

uint32_t sound_2B90(uint16_t bc, uint16_t hl, uint16_t ix, uint32_t carry)
{
	uint16_t ignored16 = 0;

	z80_block(25);
	hl = hl - bc - carry;
	sound_2B87(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t sound_2B95(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(55);
	hl = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u));
	sound_2B87(hl, ix, &ignored16, &carry);
	z80_block(17);
	carry = set_fm_volume_from_record(ix);
	z80_block(10);
	return fm_key_on(ix);
}

uint32_t sound_2BA4(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t ignored16 = 0;

	z80_block(10);
	if (carry)
	{
		sound_2B73(ix, &ignored16, &carry);
		return carry;
	}
	z80_block(55);
	a = CHANNEL(ix)->unk_2C - 2u;
	CHANNEL(ix)->unk_2C = a;
	return set_fm_volume(ix, a);
}

uint8_t sound_2BB2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t t1 = 0;

	z80_block(126);
	t1 = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u)) + 0x100u;
	AS16(CHANNEL(ix)->unk_32) = t1;
	a = CHANNEL(ix)->unk_2C;
	return a;
}

uint32_t fm_effect_28(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, voice = 0;

	z80_block(80);
	unk_843A = 0x1Cu;
	voice = 0x2BC6u;
	unk_8438 = 1u;
	unk_8439 = 1u;
	carry = load_fm_voice(voice, ix);
	z80_block(10);
	hl = 0x1500u;
	return sound_2BF5(hl, ix);
}

uint32_t sound_2BF5(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl_2 = 0, ignored16 = 0;

	z80_block(33);
	unk_8436 = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(24);
	a = 0xAu;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl_2 = 0x2C09u;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_2C09(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(31);
	t1 = unk_8438;
	unk_8438 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(17);
		hl = next_random_byte();
		z80_block(48);
		hl = unk_8436 + (uint8_t)hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(31);
	hl = unk_843A_ADDRESS;
	t2 = unk_843A;
	unk_843A = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(35);
	a = unk_8439;
	if (((unk_843A >> 4) & 1u) == 0u)
	{
		z80_block(7);
		a++;
	}
	z80_block(67);
	a++;
	unk_8438 = a;
	unk_8439 = a;
	bc = 0x80u;
	if (unk_843A < 0x18u)
	{
		z80_block(10);
		bc = 0xFF00u;
	}
	z80_block(37);
	hl = unk_8436 + bc;
	return sound_2BF5(hl, ix);
}

uint32_t fm_effect_29(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, voice = 0;

	z80_block(47);
	unk_8440 = 1u;
	voice = 0x276Cu;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = pcm_drums_ADDRESS - 0x2u;
	carry = sound_2CCE(hl, ix);
	z80_block(20);
	hl = 0x2C60u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2C60(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(58);
	hl = unk_843E - 0x20u;
	if (hl >> 8 != 8u)
	{
		z80_block(26);
		unk_843E = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(60);
	unk_843C = 0x33u;
	unk_843D = 0x33u;
	voice = 0x276Cu;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0x910u;
	carry = sound_2CCE(hl, ix);
	z80_block(20);
	hl = 0x2C8Du;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2C8D(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(27);
	carry = 0u;
	if (unk_8440 == 0u)
	{
		z80_block(44);
		unk_843C = 0xB0u;
		a = 0u;
		carry = set_fm_volume(ix, a);
		z80_block(20);
		hl = 0x2CBAu;
		set_channel_handler(hl, ix);
		return carry;
	}
	z80_block(26);
	hl = unk_843C_ADDRESS;
	t1 = unk_843C;
	unk_843C = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(30);
	t2 = unk_843D - 1u;
	a = t2;
	if (t2 == 0u)
	{
		z80_block(7);
		a = 0x10u;
	}
	z80_block(30);
	unk_843D = a;
	unk_843C = a;
	return sound_2CC1(ix);
}

uint32_t sound_2CBA(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(31);
	t1 = unk_843C;
	unk_843C = t1 - 1u;
	if (t1 == 1u)
		return stop_channel(ix);
	return sound_2CC1(ix);
}

uint32_t sound_2CC1(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(63);
	hl = unk_843E - 8u;
	unk_843E = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t sound_2CCE(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0;

	z80_block(33);
	unk_843E = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(24);
	a = 0x10u;
	carry = set_fm_volume(ix, a);
	z80_block(10);
	return fm_key_on(ix);
}

uint32_t fm_effect_2a(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(93);
	CHANNEL(ix)->unk_28 = 3u;
	CHANNEL(ix)->unk_2C = 0x14u;
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 5u;
	a = 0x1Cu;
	return sound_2D08(ix, a);
}

uint32_t sound_2D08(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, voice = 0;

	z80_block(65);
	CHANNEL(ix)->unk_20 = a;
	CHANNEL(ix)->unk_21 = a;
	voice = 0x2CDCu;
	carry = load_fm_voice(voice, ix);
	z80_block(17);
	carry = sound_2B95(ix);
	z80_block(20);
	hl = 0x2D1Du;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2D1D(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(36);
		carry = CHANNEL(ix)->unk_20 < 0x18u;
		return sound_2BA4(ix, carry);
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(43);
	CHANNEL(ix)->unk_20 = 8u;
	a = 0x34u;
	carry = set_fm_volume(ix, a);
	z80_block(20);
	hl = 0x2D40u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2D40(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(178);
	t2 = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u)) + 0x40u;
	AS16(CHANNEL(ix)->unk_32) = t2;
	CHANNEL(ix)->unk_2C += 0x22u;
	a = CHANNEL(ix)->unk_21 + 4u;
	return sound_2D08(ix, a);
}

uint32_t fm_effect_2b(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t channel = 0, hl = 0;
	uint16_t saved_ix = 0;

	z80_block(69);
	unk_8440 = 0u;
	unk_841F = 0u;
	saved_ix = ix;
	a = 0x85u;
	start_pcm_effect(a);
	z80_block(60);
	channel = saved_ix;
	CHANNEL(channel)->unk_2E = 5u;
	hl = 0x2D64u;
	carry = sound_1E5E(hl, channel);
	z80_block(20);
	hl = 0x2D9Du;
	set_channel_handler(hl, channel);
	return carry;
}

uint32_t sound_2D9D(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_1E83(ix);
	z80_block(10);
	return sound_1E88(ix);
}

uint32_t fm_effect_2c(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(112);
	CHANNEL(ix)->unk_21 = 0xFu;
	CHANNEL(ix)->unk_22 = 0x18u;
	CHANNEL(ix)->unk_34 = 0u;
	CHANNEL(ix)->unk_35 = 0xDu;
	CHANNEL(ix)->unk_29 = 0x12u;
	a = 1u;
	return sound_2DD6(ix, a);
}

uint32_t sound_2DD6(uint16_t ix, uint8_t a)
{
	z80_block(19);
	CHANNEL(ix)->unk_28 = a;
	return sound_2DD9(ix);
}

uint32_t sound_2DD9(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;

	z80_block(17);
	hl = sound_2E64(ix);
	z80_block(27);
	bc = 0xFE00u;
	sound_2B86(hl, ix, &bc, &carry);
	z80_block(62);
	CHANNEL(ix)->unk_20 = CHANNEL(ix)->unk_22;
	a = 0u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x2DF6u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2DF6(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(33);
		t2 = CHANNEL(ix)->unk_28;
		CHANNEL(ix)->unk_28 = t2 - 1u;
		if (t2 != 1u)
			return sound_2DD9(ix);
		z80_block(55);
		CHANNEL(ix)->unk_28 = CHANNEL(ix)->unk_29;
		hl = sound_2E64(ix);
		return sound_2E1E(hl, ix);
	}
	z80_block(36);
	if (CHANNEL(ix)->unk_20 == 4u)
	{
		z80_block(17);
		a = 0x10u;
		return set_fm_volume(ix, a);
	}
	z80_block(20);
	bc = 0xFF7Fu;
	sound_2B80(ix, &bc, &carry);
	return carry;
}

uint32_t sound_2E1E(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl_2 = 0, ignored16 = 0;

	z80_block(17);
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(62);
	CHANNEL(ix)->unk_20 = CHANNEL(ix)->unk_21;
	a = 0u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl_2 = 0x2E35u;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_2E35(uint16_t ix, uint32_t carry)
{
	uint8_t d = 0, e = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(30);
	if (((CHANNEL(ix)->unk_28 >> 4) & 1u) != 0u)
	{
		z80_cycles(7);
		sound_2E64(ix);
	}
	z80_block(17);
	hl = next_random_byte();
	z80_block(145);
	d = (uint8_t)hl;
	e = (uint8_t)(hl >> 8);
	hl = (CHANNEL(ix)->unk_30 | ((uint32_t)CHANNEL(ix)->unk_31 << 8u)) + 0x80u;
	AS16(CHANNEL(ix)->unk_30) = hl;
	hl += e | ((d & 3u) << 8);
	return sound_2E1E(hl, ix);
}

uint16_t sound_2E64(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t h = 0, l = 0;
	uint16_t hl = 0, voice = 0;

	z80_block(27);
	voice = 0x2DA6u;
	carry = load_fm_voice(voice, ix);
	z80_block(86);
	l = CHANNEL(ix)->unk_34;
	h = CHANNEL(ix)->unk_35;
	CHANNEL(ix)->unk_30 = l;
	CHANNEL(ix)->unk_31 = h;
	hl = ((uint32_t)h << 8) | l;
	return hl;
}

uint32_t fm_effect_2d(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(50);
	unk_8447 = 0x20u;
	unk_8442 = 0xCu;
	hl = 0x600u;
	return sound_2E84(hl, ix);
}

uint32_t sound_2E84(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl_2 = 0, ignored16 = 0, voice = 0;

	z80_block(59);
	unk_8443 = hl;
	unk_8445 = hl;
	voice = 0x1EEEu;
	carry = load_fm_voice(voice, ix);
	z80_block(33);
	hl_2 = unk_8443;
	set_fm_pitch(hl_2, ix, &ignored16, &carry);
	z80_block(50);
	unk_8441 = 0xAu;
	a = unk_8442;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl_2 = 0x2EAAu;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_2EAA(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	z80_block(31);
	hl = unk_8441_ADDRESS;
	t1 = unk_8441;
	unk_8441 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(48);
		t2 = unk_8441;
		hl = unk_8445;
		bc = 0xFF80u;
		if (t2 & 1u)
		{
			z80_block(10);
			bc = 0x100u;
		}
		z80_block(41);
		hl = hl - bc - carry;
		unk_8445 = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(31);
	hl = unk_8447_ADDRESS;
	t3 = unk_8447;
	unk_8447 = t3 - 1u;
	if (t3 == 1u)
		return stop_channel(ix);
	z80_block(37);
	t4 = unk_8447;
	carry = t4 < 0x1Bu;
	a = unk_8442;
	if (t4 < 0x1Bu)
	{
		z80_block(29);
		a++;
		if (((unk_8447 >> 4) & 1u) == 0u)
		{
			z80_block(7);
			a++;
		}
		z80_block(23);
		unk_8442 = a;
		bc = 0xFFC0u;
	}
	else
	{
		z80_block(40);
		unk_8442 = a - 1u - carry;
		bc = 0x80u;
	}
	z80_block(37);
	hl = unk_8443 + bc;
	return sound_2E84(hl, ix);
}

uint32_t fm_effect_2e(uint16_t ix)
{
	z80_block(19);
	CHANNEL(ix)->unk_29 = 2u;
	return sound_2F15(ix);
}

uint32_t sound_2F15(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x2EF8u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0x1200u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(27);
	hl = 0x400u;
	sound_2442(hl, ix);
	z80_block(62);
	CHANNEL(ix)->unk_20 = 0x20u;
	a = 4u;
	CHANNEL(ix)->unk_2E = 4u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x2F3Cu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2F3C(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(17);
		a = 4u;
		return sound_2405(ix, a);
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_29;
	CHANNEL(ix)->unk_29 = t2 - 1u;
	if (t2 != 1u)
		return sound_2F15(ix);
	z80_block(26);
	CHANNEL(ix)->unk_29 = 0x18u;
	a = 4u;
	return sound_2F53(ix, a);
}

uint32_t sound_2F53(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(84);
	CHANNEL(ix)->unk_2C = a;
	CHANNEL(ix)->unk_20 = 6u;
	CHANNEL(ix)->unk_28 = 5u;
	hl = 0xE00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(65);
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 0xCu;
	carry = set_fm_volume_from_record(ix);
	z80_block(20);
	hl = 0x2F76u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2F76(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_2419(ix);
	z80_block(52);
	CHANNEL(ix)->unk_20 = 6u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
	{
		z80_block(33);
		t3 = CHANNEL(ix)->unk_29;
		CHANNEL(ix)->unk_29 = t3 - 1u;
		if (t3 == 1u)
			return stop_channel(ix);
		z80_block(36);
		a = CHANNEL(ix)->unk_2C + 6u;
		return sound_2F53(ix, a);
	}
	z80_block(93);
	bc = 0x200u;
	t4 = 0xA00u - carry;
	carry = z80_carry_sub16(0xC00u, 0x200u, carry);
	hl = t4;
	AS16(CHANNEL(ix)->unk_32) = hl;
	hl = 0x600u;
	return sound_2B90(bc, hl, ix, carry);
}

uint32_t fm_effect_2f(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(93);
	CHANNEL(ix)->unk_28 = 3u;
	CHANNEL(ix)->unk_2C = 0x1Eu;
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 5u;
	a = 0x2Cu;
	return sound_2FBB(ix, a);
}

uint32_t sound_2FBB(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, voice = 0;

	z80_block(65);
	CHANNEL(ix)->unk_20 = a;
	CHANNEL(ix)->unk_21 = a;
	voice = 0x2CDCu;
	carry = load_fm_voice(voice, ix);
	z80_block(17);
	carry = sound_2B95(ix);
	z80_block(20);
	hl = 0x2FD0u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_2FD0(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(36);
		carry = CHANNEL(ix)->unk_20 < 0x28u;
		return sound_2BA4(ix, carry);
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(17);
	a = sound_2BB2(ix);
	z80_block(62);
	CHANNEL(ix)->unk_2C = a + 0x2Au;
	a = CHANNEL(ix)->unk_21 + 3u;
	return sound_2FBB(ix, a);
}

uint32_t sound_300D(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(40);
	unk_8448 = a;
	voice = 0x2FF4u;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0x400u;
	unk_844A = 0x400u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(30);
	a_2 = unk_844C;
	carry = set_fm_volume(ix, a_2);
	z80_block(10);
	return fm_key_on(ix);
}

uint32_t sound_3028(uint16_t bc, uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(53);
	hl = unk_844A + bc;
	unk_844A = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t fm_effect_30(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(44);
	unk_844C = 2u;
	a = 0x14u;
	carry = sound_300D(ix, a);
	z80_block(20);
	hl = 0x3042u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_3042(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0;

	z80_block(31);
	hl = unk_8448_ADDRESS;
	t1 = unk_8448;
	unk_8448 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(27);
		unk_8449 = 5u;
		a = 2u;
		return sound_3061(ix, a);
	}
	z80_block(24);
	if (unk_8448 == 4u)
	{
		z80_block(17);
		a = 0x22u;
		return set_fm_volume(ix, a);
	}
	z80_block(20);
	bc = 0x100u;
	return sound_3028(bc, ix);
}

uint32_t sound_3061(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0;
	uint16_t hl = 0;

	z80_block(37);
	unk_844C = a;
	a_2 = 0x30u;
	carry = sound_300D(ix, a_2);
	z80_block(20);
	hl = 0x306Fu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_306F(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t bc = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(31);
	t1 = unk_8448;
	unk_8448 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(20);
		bc = 0x80u;
		return sound_3028(bc, ix);
	}
	z80_block(31);
	t2 = unk_8449;
	unk_8449 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(30);
	a = unk_844C + 0x10u;
	return sound_3061(ix, a);
}

uint32_t fm_effect_31(uint16_t ix)
{
	z80_block(19);
	CHANNEL(ix)->unk_29 = 2u;
	return sound_30A8(ix);
}

uint32_t sound_30A8(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x308Bu;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = pcm_instruments_ADDRESS - 0x2u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(27);
	hl = 0x400u;
	sound_2442(hl, ix);
	z80_block(62);
	CHANNEL(ix)->unk_20 = 0x18u;
	a = 7u;
	CHANNEL(ix)->unk_2E = 7u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x30CFu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_30CF(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(17);
		a = 4u;
		return sound_2405(ix, a);
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_29;
	CHANNEL(ix)->unk_29 = t2 - 1u;
	if (t2 != 1u)
		return sound_30A8(ix);
	z80_block(26);
	CHANNEL(ix)->unk_29 = 0x10u;
	a = 7u;
	return sound_30E6(ix, a);
}

uint32_t sound_30E6(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(84);
	CHANNEL(ix)->unk_2C = a;
	CHANNEL(ix)->unk_20 = 6u;
	CHANNEL(ix)->unk_28 = 5u;
	hl = 0xC00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(65);
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 0xAu;
	carry = set_fm_volume_from_record(ix);
	z80_block(20);
	hl = 0x3109u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_3109(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_2419(ix);
	z80_block(52);
	CHANNEL(ix)->unk_20 = 6u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
	{
		z80_block(33);
		t3 = CHANNEL(ix)->unk_29;
		CHANNEL(ix)->unk_29 = t3 - 1u;
		if (t3 == 1u)
			return stop_channel(ix);
		z80_block(36);
		a = CHANNEL(ix)->unk_2C + 8u;
		return sound_30E6(ix, a);
	}
	z80_block(93);
	bc = 0x200u;
	t4 = 0x800u - carry;
	carry = z80_carry_sub16(0xA00u, 0x200u, carry);
	hl = t4;
	AS16(CHANNEL(ix)->unk_32) = hl;
	hl = 0x400u;
	return sound_2B90(bc, hl, ix, carry);
}

uint32_t fm_effect_32(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t voice = 0;

	z80_block(47);
	unk_8451 = 2u;
	voice = 0x313Bu;
	carry = load_fm_voice(voice, ix);
	z80_block(7);
	a = 0xBu;
	return sound_3161(ix, a);
}

uint32_t sound_3161(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(56);
	unk_844E = a;
	hl = 0xF00u;
	unk_844F = 0xF00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(30);
	a_2 = unk_844E;
	carry = set_fm_volume(ix, a_2);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(40);
	unk_844D = 0x30u;
	hl = 0x3181u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_3181(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(31);
	hl = unk_844D_ADDRESS;
	t1 = unk_844D;
	unk_844D = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(31);
		t2 = unk_8451;
		unk_8451 = t2 - 1u;
		if (t2 == 1u)
			return stop_channel(ix);
		z80_block(17);
		a = 0x27u;
		return sound_3161(ix, a);
	}
	z80_block(19);
	a = unk_844D;
	carry = a < 8u;
	if (a < 8u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(43);
	hl = unk_844F;
	bc = 0xFFF8u;
	if (a >= 0x2Cu)
	{
		z80_block(10);
		bc = 4u;
	}
	z80_block(37);
	hl += bc;
	unk_844F = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t fm_effect_33(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(30);
	unk_83F3 = 1u;
	z80_block(27);
	unk_83FD = 0x14u;
	a = 0xBu;
	return sound_1AF8(ix, a);
}

uint32_t fm_effect_34(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(137);
	unk_8458 = 1u;
	unk_8342 = 0x329Cu;
	unk_8341 = CHANNEL(ix)->sound;
	unk_834F = CHANNEL(ix)->priority;
	voice = 0x31B5u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0x1080u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(27);
	hl = 0x400u;
	sound_2442(hl, ix);
	z80_block(60);
	CHANNEL(ix)->unk_20 = 0x18u;
	a = music_attenuation + 6u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x320Du;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_320D(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 == 1u)
		return sound_3226(ix);
	z80_block(36);
	if (8u == CHANNEL(ix)->unk_20)
	{
		z80_block(17);
		a = 0xCu;
		return set_fm_volume(ix, a);
	}
	z80_block(20);
	bc = 0xFF80u;
	sound_2B80(ix, &bc, &carry);
	return carry;
}

uint32_t sound_3226(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x31B5u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0xE80u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(108);
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 0xAu;
	a = music_attenuation + 6u;
	CHANNEL(ix)->unk_2C = a;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(58);
	CHANNEL(ix)->unk_20 = 6u;
	CHANNEL(ix)->unk_28 = 5u;
	hl = 0x3258u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_3258(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	z80_block(27);
	if (unk_8458 == 0u)
		return stop_channel(ix);
	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_2419(ix);
	z80_block(52);
	CHANNEL(ix)->unk_20 = 6u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return sound_3226(ix);
	z80_block(17);
	sound_2B73(ix, &bc, &carry);
	z80_block(83);
	t3 = 0xA00u - bc - carry;
	carry = z80_carry_sub16(0xA00u, bc, carry);
	hl = t3;
	AS16(CHANNEL(ix)->unk_32) = hl;
	hl = 0x400u;
	return sound_2B90(bc, hl, ix, carry);
}

uint32_t sound_329C(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(47);
	unk_8456 = 6u;
	unk_8457 = 8u;
	a = 0x20u;
	return sound_32A8(ix, a);
}

uint32_t sound_32A8(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(53);
	unk_8454 = a;
	unk_8455 = a;
	voice = 0x3283u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0x1100u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(77);
	unk_8452 = 0x700u;
	a_2 = music_attenuation + unk_8457;
	carry = set_fm_volume(ix, a_2);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x32D4u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_32D4(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, bc = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(27);
	if (unk_8458 == 0u)
		return stop_channel(ix);
	z80_block(31);
	hl = unk_8454_ADDRESS;
	t1 = unk_8454;
	unk_8454 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(31);
		t2 = unk_8456;
		unk_8456 = t2 - 1u;
		if (t2 == 1u)
			return sound_329C(ix);
		z80_block(17);
		hl = next_random_byte();
		z80_block(66);
		b = hl & 7u;
		unk_8457 = 4u + b;
		a = unk_8455 + b;
		return sound_32A8(ix, a);
	}
	z80_block(32);
	bc = 0x80u;
	b = 0u;
	if (unk_8454 & 1u)
	{
		z80_block(10);
		bc = 0u;
		b = 0xFFu;
	}
	z80_block(68);
	hl = unk_8452 + (((uint32_t)b << 8) | (bc & 0xFFu));
	unk_8452 = hl;
	hl = (hl & 0xFFu) | (((hl >> 8) & 7u) << 8);
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t fm_effect_35(uint16_t ix)
{
	z80_block(27);
	unk_8458 = 0u;
	return stop_channel(ix);
}

uint32_t fm_effect_36(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x331Du;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0x700u;
	unk_845B = 0x700u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(24);
	a = 0xAu;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x3353u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_3353(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(58);
	hl = unk_845B + 0x40u;
	if (hl >> 8 != 0xDu)
	{
		z80_block(26);
		unk_845B = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(27);
	voice = 0x331Du;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0xD10u;
	unk_845B = 0xD10u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(44);
	unk_8459 = 0xA0u;
	a = 0xAu;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x3388u;
	set_channel_handler(hl, ix);
	return carry;
}

void sound_3388(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(26);
	hl = unk_8459_ADDRESS;
	t1 = unk_8459;
	unk_8459 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(30);
	unk_8459 = 0x30u;
	hl = 0x3395u;
	set_channel_handler(hl, ix);
}

uint32_t sound_3395(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0;

	z80_block(31);
	t1 = unk_8459;
	unk_8459 = t1 - 1u;
	if (t1 == 1u)
		return stop_channel(ix);
	z80_block(63);
	hl = unk_845B - 0x40u;
	unk_845B = hl;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	return carry;
}

uint32_t fm_effect_38(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(47);
	unk_8460 = 0x30u;
	voice = 0x33A9u;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = 0x600u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(57);
	unk_845E = 0xCu;
	a = 0x12u;
	unk_845F = 0x12u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x33E9u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_33E9(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	z80_block(31);
	hl = unk_845E_ADDRESS;
	t1 = unk_845E;
	unk_845E = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(32);
		t2 = unk_845E;
		hl = 0x600u;
		if ((t2 & 1u) != 0u)
		{
			set_fm_pitch(hl, ix, &ignored16, &carry);
			return carry;
		}
		z80_block(20);
		hl = pcm_instruments_ADDRESS - 0x2u;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(41);
	unk_845E = 0xCu;
	hl = unk_8460_ADDRESS;
	t3 = unk_8460;
	unk_8460 = t3 - 1u;
	if (t3 == 1u)
		return stop_channel(ix);
	z80_block(37);
	t4 = unk_8460;
	a = unk_845F;
	if (t4 < 0x29u)
	{
		z80_block(7);
		a += 2u;
	}
	z80_block(27);
	a--;
	unk_845F = a;
	return set_fm_volume(ix, a);
}

uint32_t fm_effect_39(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl = 0, voice = 0;

	z80_block(67);
	unk_8462 = 2u;
	unk_8465 = 6u;
	voice = 0x3419u;
	carry = load_fm_voice(voice, ix);
	z80_block(26);
	hl = 0xA00u;
	unk_8463 = 0xA00u;
	return sound_3448(hl, ix);
}

uint32_t sound_3448(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl_2 = 0, ignored16 = 0;

	z80_block(17);
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(50);
	unk_8461 = 0x10u;
	a = unk_8462;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl_2 = 0x345Fu;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_345F(uint16_t ix, uint32_t carry)
{
	uint8_t d = 0, e = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(26);
	t1 = unk_8461;
	unk_8461 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(31);
	t2 = unk_8465;
	unk_8465 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(50);
	unk_8462 += 6u;
	hl = next_random_byte();
	z80_block(101);
	d = (uint8_t)hl;
	e = (uint8_t)(hl >> 8);
	hl = unk_8463 + 0x80u;
	unk_8463 = hl;
	hl += e | ((d & 3u) << 8);
	return sound_3448(hl, ix);
}

uint32_t fm_effect_3a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t channel = 0, hl = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x8Cu;
	start_pcm_effect(a);
	z80_block(88);
	channel = saved_ix;
	CHANNEL(channel)->unk_28 = 0x4Au;
	CHANNEL(channel)->unk_20 = 5u;
	CHANNEL(channel)->unk_2C = 0xAu;
	hl = 0x500u;
	return sound_34A5(hl, channel);
}

uint32_t sound_34A5(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl_2 = 0, ignored16 = 0, voice = 0;

	z80_block(17);
	sound_2442(hl, ix);
	z80_block(27);
	voice = 0x1EEEu;
	carry = load_fm_voice(voice, ix);
	z80_block(55);
	hl_2 = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u));
	set_fm_pitch(hl_2, ix, &ignored16, &carry);
	z80_block(17);
	carry = set_fm_volume_from_record(ix);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl_2 = 0x34C3u;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_34C3(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		sound_2B73(ix, &ignored16, &carry);
		return carry;
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(36);
	if (CHANNEL(ix)->unk_28 >= 0x42u)
	{
		z80_block(50);
		CHANNEL(ix)->unk_2C--;
		bc = 0x40u;
		a = 5u;
		z80_block(78);
		CHANNEL(ix)->unk_20 = a;
		hl = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u)) + bc;
		return sound_34A5(hl, ix);
	}
	z80_block(40);
	bc = 0u;
	if (((CHANNEL(ix)->unk_28 >> 6) & 1u) != 0u)
	{
		z80_block(7);
		a = 0xCu;
		z80_block(78);
		CHANNEL(ix)->unk_20 = a;
		hl = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u)) + bc;
		return sound_34A5(hl, ix);
	}
	z80_block(30);
	if ((CHANNEL(ix)->unk_28 & 1u) == 0u)
	{
		z80_block(23);
		CHANNEL(ix)->unk_2C++;
	}
	z80_block(33);
	CHANNEL(ix)->unk_2C++;
	bc = 0xFFF0u;
	z80_block(7);
	a = 0xCu;
	z80_block(78);
	CHANNEL(ix)->unk_20 = a;
	hl = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u)) + bc;
	return sound_34A5(hl, ix);
}

uint32_t fm_effect_3b(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t voice = 0;

	z80_block(113);
	CHANNEL(ix)->unk_28 = 4u;
	CHANNEL(ix)->unk_2C = 0x16u;
	CHANNEL(ix)->unk_32 = 0u;
	CHANNEL(ix)->unk_33 = 5u;
	voice = 0x350Bu;
	carry = load_fm_voice(voice, ix);
	z80_block(7);
	a = 0x24u;
	return sound_353D(ix, a);
}

uint32_t sound_353D(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0;

	z80_block(55);
	CHANNEL(ix)->unk_20 = a;
	CHANNEL(ix)->unk_21 = a;
	carry = sound_2B95(ix);
	z80_block(20);
	hl = 0x354Cu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_354C(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(36);
		carry = CHANNEL(ix)->unk_20 < 0x22u;
		return sound_2BA4(ix, carry);
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(17);
	a = sound_2BB2(ix);
	z80_block(62);
	CHANNEL(ix)->unk_2C = a + 0x1Au;
	a = CHANNEL(ix)->unk_21 + 3u;
	return sound_353D(ix, a);
}

uint32_t fm_effect_3c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t channel = 0, hl = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x83u;
	start_pcm_effect(a);
	z80_block(62);
	channel = saved_ix;
	CHANNEL(channel)->unk_28 = 0x20u;
	CHANNEL(channel)->unk_2C = 0xCu;
	hl = 0x500u;
	return sound_3584(hl, channel);
}

uint32_t sound_3584(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t hl_2 = 0, ignored16 = 0, voice = 0;

	z80_block(17);
	sound_2442(hl, ix);
	z80_block(27);
	voice = 0x1EEEu;
	carry = load_fm_voice(voice, ix);
	z80_block(55);
	hl_2 = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u));
	set_fm_pitch(hl_2, ix, &ignored16, &carry);
	z80_block(36);
	CHANNEL(ix)->unk_20 = 0xCu;
	carry = set_fm_volume_from_record(ix);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl_2 = 0x35A6u;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_35A6(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t bc = 0, hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		sound_2B73(ix, &ignored16, &carry);
		return carry;
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
		return stop_channel(ix);
	z80_block(36);
	if (CHANNEL(ix)->unk_28 < 0x1Bu)
	{
		z80_block(33);
		CHANNEL(ix)->unk_2C++;
		bc = 0xFF90u;
	}
	else
	{
		z80_block(43);
		CHANNEL(ix)->unk_2C--;
		bc = 0x80u;
	}
	z80_block(59);
	hl = (CHANNEL(ix)->unk_32 | ((uint32_t)CHANNEL(ix)->unk_33 << 8u)) + bc;
	return sound_3584(hl, ix);
}

uint32_t fm_effect_3d(uint16_t ix)
{
	z80_block(137);
	unk_8342 = 0x35FDu;
	unk_8382 = 0x3604u;
	unk_8341 = 0x22u;
	unk_8381 = 0x22u;
	unk_834F = 0x15u;
	unk_838F = 0x15u;
	CHANNEL(ix)->unk_2C = 8u;
	return sound_35F3(ix);
}

uint32_t sound_35F3(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_34 = 0x10u;
	hl = 0x140u;
	return sound_2175(hl, ix);
}

uint32_t sound_35FD(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t bc = 0;

	z80_block(24);
	a = 0x80u;
	bc = 0x1400u;
	return sound_3608(bc, ix, a);
}

uint32_t sound_3604(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t bc = 0;

	z80_block(14);
	a = 0xFFu;
	bc = 0x2000u;
	return sound_3608(bc, ix, a);
}

uint32_t sound_3608(uint16_t bc, uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0;

	z80_block(55);
	CHANNEL(ix)->unk_20 = a;
	CHANNEL(ix)->unk_2C = bc >> 8;
	fm_key_off(ix);
	z80_block(17);
	carry = fm_fast_release(ix);
	z80_block(20);
	hl = 0x361Au;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_361A(uint16_t ix, uint32_t carry)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(10);
	return sound_35F3(ix);
}

uint32_t fm_effect_3e(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ix_2 = 0;
	uint16_t saved_ix = 0;

	z80_block(105);
	unk_8342 = 0x363Au;
	unk_8341 = 0x3Eu;
	unk_834F = 0x15u;
	saved_ix = ix;
	a = 0x3Fu;
	carry = start_fm_effect(a);
	z80_block(14);
	ix_2 = saved_ix;
	sound_363A(ix_2);
	return carry;
}

void sound_363A(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_20 = 0x10u;
	hl = 0x3644u;
	set_channel_handler(hl, ix);
}

uint32_t sound_3644(uint16_t ix, uint32_t carry)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(10);
	return sound_366D(ix);
}

uint32_t fm_effect_3f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t ix_2 = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x85u;
	start_pcm_effect(a);
	z80_block(14);
	ix_2 = saved_ix;
	return sound_366D(ix_2);
}

uint32_t sound_366D(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x364Bu;
	carry = load_fm_voice(voice, ix);
	z80_block(27);
	hl = pcm_instruments_ADDRESS - 0x2u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(27);
	hl = 0x400u;
	sound_2442(hl, ix);
	z80_block(62);
	CHANNEL(ix)->unk_20 = 0x16u;
	a = 0u;
	CHANNEL(ix)->unk_2E = 0u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x3694u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_3694(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 == 1u)
	{
		z80_block(26);
		CHANNEL(ix)->unk_29 = 0x10u;
		a = 0u;
		return sound_36A5(ix, a);
	}
	z80_block(17);
	a = 6u;
	return sound_2405(ix, a);
}

uint32_t sound_36A5(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t hl = 0, ignored16 = 0;

	z80_block(84);
	CHANNEL(ix)->unk_2C = a;
	CHANNEL(ix)->unk_20 = 6u;
	CHANNEL(ix)->unk_28 = 5u;
	hl = 0xC00u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(65);
	CHANNEL(ix)->unk_30 = 0u;
	CHANNEL(ix)->unk_31 = 0xAu;
	carry = set_fm_volume_from_record(ix);
	z80_block(20);
	hl = 0x36C8u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_36C8(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	uint16_t t5 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_20;
	CHANNEL(ix)->unk_20 = t1 - 1u;
	if (t1 != 1u)
		return sound_2419(ix);
	z80_block(52);
	CHANNEL(ix)->unk_20 = 6u;
	t2 = CHANNEL(ix)->unk_28;
	CHANNEL(ix)->unk_28 = t2 - 1u;
	if (t2 == 1u)
	{
		z80_block(33);
		t3 = CHANNEL(ix)->unk_29;
		CHANNEL(ix)->unk_29 = t3 - 1u;
		if (t3 == 1u)
			return stop_channel(ix);
		z80_block(56);
		t4 = CHANNEL(ix)->unk_2C + 3u;
		a = t4;
		if (t4 == 0u)
			return sound_36A5(ix, a);
		z80_block(17);
		a += 7u;
		return sound_36A5(ix, a);
	}
	z80_block(93);
	bc = 0x200u;
	t5 = 0x800u - carry;
	carry = z80_carry_sub16(0xA00u, 0x200u, carry);
	hl = t5;
	AS16(CHANNEL(ix)->unk_32) = hl;
	hl = 0x400u;
	return sound_2B90(bc, hl, ix, carry);
}

uint32_t fm_effect_40(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t channel = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0x2Cu;
	carry = start_fm_effect(a);
	z80_block(136);
	channel = saved_ix;
	CHANNEL(channel)->unk_21 = 0x10u;
	CHANNEL(channel)->unk_22 = 0x14u;
	CHANNEL(channel)->unk_29 = 0x13u;
	CHANNEL(channel)->unk_34 = 0u;
	CHANNEL(channel)->unk_35 = 0xCu;
	a = 2u;
	return sound_2DD6(channel, a);
}

uint32_t fm_effect_41(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0, voice = 0;

	z80_block(27);
	voice = 0x3726u;
	carry = load_fm_voice(voice, ix);
	z80_block(43);
	hl = 0x1200u;
	unk_8466 = 0x1200u;
	set_fm_pitch(hl, ix, &ignored16, &carry);
	z80_block(89);
	unk_8468 = 8u;
	unk_8469 = 4u;
	unk_846A = 0x14u;
	a = 4u;
	unk_846B = 4u;
	carry = set_fm_volume(ix, a);
	z80_block(17);
	carry = fm_key_on(ix);
	z80_block(20);
	hl = 0x3769u;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_3769(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint16_t hl = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(31);
	hl = unk_8468_ADDRESS;
	t1 = unk_8468;
	unk_8468 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_block(63);
		hl = unk_8466 + 0x100u;
		unk_8466 = hl;
		set_fm_pitch(hl, ix, &ignored16, &carry);
		return carry;
	}
	z80_block(32);
	unk_8468 = 3u;
	hl++;
	t2 = unk_8469;
	unk_8469 = t2 - 1u;
	if (t2 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(37);
	unk_8469 = 4u;
	hl++;
	t3 = unk_846A;
	unk_846A = t3 - 1u;
	if (t3 == 1u)
		return stop_channel(ix);
	z80_block(43);
	a = unk_846B + 2u;
	unk_846B = a;
	return set_fm_volume(ix, a);
}
