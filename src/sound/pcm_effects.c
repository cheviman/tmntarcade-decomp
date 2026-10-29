/**
 *    Name:        pcm_effects.c
 *    Description: the PCM effects (commands 80-93) and their samples
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

uint32_t play_pcm_sample(uint8_t bc, uint16_t de, uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc_2 = 0;
	uint16_t de_2 = 0;

	z80_block(55);
	AS16(CHANNEL(ix)->unk_30) = hl;
	set_pcm_start(bc, de, ix);
	z80_block(36);
	bc_2 = CHANNEL(ix)->unk_32;
	carry = set_pcm_volume(bc_2, ix);
	z80_block(55);
	de_2 = (CHANNEL(ix)->unk_33 | ((uint32_t)CHANNEL(ix)->unk_34 << 8u));
	set_pcm_pitch(de_2, ix);
	z80_block(10);
	start_pcm(ix);
	return carry;
}

uint32_t pcm_effect_countdown(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t h = 0, l = 0;
	uint16_t t1 = 0;

	z80_block(95);
	t1 = (CHANNEL(ix)->unk_30 | ((uint32_t)CHANNEL(ix)->unk_31 << 8u)) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	CHANNEL(ix)->unk_30 = l;
	CHANNEL(ix)->unk_31 = h;
	carry = 0u;
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(10);
	return stop_pcm_channel(ix);
}

void queue_pcm_effect_a(uint16_t hl)
{
	z80_block(22);
	if (music_pcm_hold != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(46);
	unk_8282 = hl;
	unk_8281 = 0x88u;
}

uint32_t pcm_effect_81(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1114u;
	queue_pcm_effect_a(hl);
	return sound_10D6(ix);
}

uint32_t sound_10D6(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(29);
	CHANNEL(ix)->unk_36 = 2u;
	hl = 0xF0u;
	return sound_10DD(hl, ix);
}

uint32_t sound_10DD(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc = 0;
	uint16_t de = 0, hl_2 = 0;

	z80_block(101);
	CHANNEL(ix)->unk_32 = 0xFu;
	CHANNEL(ix)->unk_33 = 0xAEu;
	CHANNEL(ix)->unk_34 = 0xFu;
	de = 0u;
	bc = 1u;
	carry = play_pcm_sample(bc, de, hl, ix);
	z80_block(20);
	hl_2 = 0x10F8u;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_10F8(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	z80_block(95);
	t1 = (CHANNEL(ix)->unk_30 | ((uint32_t)CHANNEL(ix)->unk_31 << 8u)) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	CHANNEL(ix)->unk_30 = l;
	CHANNEL(ix)->unk_31 = h;
	carry = 0u;
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_36;
	CHANNEL(ix)->unk_36 = t2 - 1u;
	if (t2 == 1u)
		return stop_pcm_channel(ix);
	z80_block(20);
	hl = 0x220u;
	return sound_10DD(hl, ix);
}

void sound_1114(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_35 = 0x20u;
	hl = 0x111Eu;
	set_channel_handler(hl, ix);
}

uint32_t sound_111E(uint16_t ix, uint32_t carry)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_35;
	CHANNEL(ix)->unk_35 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(10);
	return sound_10D6(ix);
}

uint32_t pcm_effect_82(uint16_t ix)
{
	uint16_t bc = 0;

	z80_block(10);
	bc = 0xF84u;
	return sound_1128(bc, ix);
}

uint32_t sound_1128(uint16_t bc, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc_2 = 0, c = 0;
	uint16_t de = 0, hl = 0;

	c = (uint8_t)bc;
	z80_block(134);
	CHANNEL(ix)->unk_33 = c;
	CHANNEL(ix)->unk_34 = ((bc & ~0xFFu) | c) >> 8;
	music_attenuation = 1u;
	unk_83CC = 1u;
	hl = 0x48u;
	CHANNEL(ix)->unk_32 = 0xFu;
	de = 0u;
	bc_2 = 1u;
	carry = play_pcm_sample(bc_2, de, hl, ix);
	z80_block(20);
	hl = 0x114Bu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_114B(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0, bc = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = CHANNEL(ix)->unk_30;
	CHANNEL(ix)->unk_30 = t1 - 1u;
	if (t1 == 1u)
		return stop_pcm_channel(ix);
	z80_block(31);
	a = CHANNEL(ix)->unk_30;
	carry = a < 0x1Eu;
	if (a >= 0x1Eu)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(25);
	if ((CHANNEL(ix)->unk_30 & 1u) == 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(52);
	CHANNEL(ix)->unk_32--;
	bc = CHANNEL(ix)->unk_32;
	return set_pcm_volume(bc, ix);
}

uint32_t pcm_effect_83(uint16_t ix)
{
	uint16_t bc = 0, hl = 0;

	z80_block(39);
	hl = 0x17Au;
	CHANNEL(ix)->unk_32 = 0xDu;
	bc = 0xFA3u;
	return sound_116F(bc, hl, ix);
}

uint32_t sound_116F(uint16_t bc, uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc_2 = 0, c = 0;
	uint16_t de = 0, hl_2 = 0;

	c = (uint8_t)bc;
	z80_block(72);
	CHANNEL(ix)->unk_33 = c;
	CHANNEL(ix)->unk_34 = ((bc & ~0xFFu) | c) >> 8;
	de = 0x6320u;
	bc_2 = 1u;
	carry = play_pcm_sample(bc_2, de, hl, ix);
	z80_block(20);
	hl_2 = 0x10AFu;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t pcm_effect_84(uint16_t ix)
{
	z80_block(19);
	CHANNEL(ix)->unk_32 = 9u;
	return sound_1187(ix);
}

uint32_t sound_1187(uint16_t ix)
{
	uint16_t bc = 0, hl = 0;

	z80_block(20);
	hl = 0xFCu;
	bc = 0xFA0u;
	return sound_118D(bc, hl, ix);
}

uint32_t sound_118D(uint16_t bc, uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc_2 = 0, c = 0;
	uint16_t de = 0, hl_2 = 0;

	c = (uint8_t)bc;
	z80_block(72);
	CHANNEL(ix)->unk_33 = c;
	CHANNEL(ix)->unk_34 = ((bc & ~0xFFu) | c) >> 8;
	de = 0x5620u;
	bc_2 = 0u;
	carry = play_pcm_sample(bc_2, de, hl, ix);
	z80_block(20);
	hl_2 = 0x10AFu;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t pcm_effect_85(uint16_t ix)
{
	uint16_t bc = 0, hl = 0;

	z80_block(49);
	hl = 0xFFu;
	CHANNEL(ix)->unk_32 = 0xFu;
	bc = 0xF90u;
	return sound_118D(bc, hl, ix);
}

uint32_t pcm_effect_86(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t bc = 0, hl = 0, ix_2 = 0;
	uint16_t saved_ix = 0;

	z80_block(59);
	music_pcm_hold = 1u;
	saved_ix = ix;
	a = 0x8Du;
	start_pcm_effect(a);
	z80_block(41);
	ix_2 = saved_ix;
	bc = 0xFD3u;
	carry = sound_11DF(bc, ix_2);
	z80_block(20);
	hl = 0x11C8u;
	set_channel_handler(hl, ix_2);
	return carry;
}

uint32_t sound_11C8(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t h = 0, l = 0;
	uint16_t t1 = 0;

	z80_block(95);
	t1 = (CHANNEL(ix)->unk_30 | ((uint32_t)CHANNEL(ix)->unk_31 << 8u)) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	CHANNEL(ix)->unk_30 = l;
	CHANNEL(ix)->unk_31 = h;
	carry = 0u;
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(27);
	music_pcm_hold = 0u;
	return stop_pcm_channel(ix);
}

uint32_t sound_11DF(uint16_t bc, uint16_t ix)
{
	uint8_t bc_2 = 0, c = 0;
	uint16_t de = 0, hl = 0;

	c = (uint8_t)bc;
	z80_block(94);
	CHANNEL(ix)->unk_33 = c;
	CHANNEL(ix)->unk_34 = ((bc & ~0xFFu) | c) >> 8;
	hl = speech_priorities_ADDRESS;
	CHANNEL(ix)->unk_32 = 0xFu;
	de = 0x9BE0u;
	bc_2 = 1u;
	return play_pcm_sample(bc_2, de, hl, ix);
}

void pcm_effect_8d(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_35 = 8u;
	hl = 0x11FEu;
	set_channel_handler(hl, ix);
}

uint32_t sound_11FE(uint16_t ix, uint32_t carry)
{
	uint16_t bc = 0, hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_35;
	CHANNEL(ix)->unk_35 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(27);
	bc = 0xFD5u;
	carry = sound_11DF(bc, ix);
	z80_block(20);
	hl = 0x10AFu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t pcm_effect_87(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc = 0;
	uint16_t de = 0, hl = 0;

	z80_block(111);
	hl = 0x48u;
	CHANNEL(ix)->unk_32 = 0xFu;
	CHANNEL(ix)->unk_33 = 0xA3u;
	CHANNEL(ix)->unk_34 = 0xFu;
	de = 0x5550u;
	bc = 1u;
	carry = play_pcm_sample(bc, de, hl, ix);
	z80_block(20);
	hl = 0x10AFu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t pcm_effect_88(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1250u;
	queue_pcm_effect_a(hl);
	return sound_1232(ix);
}

uint32_t sound_1232(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc = 0;
	uint16_t de = 0, hl = 0;

	z80_block(111);
	hl = 0x2A0u;
	CHANNEL(ix)->unk_32 = 0xFu;
	CHANNEL(ix)->unk_33 = 0x94u;
	CHANNEL(ix)->unk_34 = 0xFu;
	de = 0u;
	bc = 1u;
	carry = play_pcm_sample(bc, de, hl, ix);
	z80_block(20);
	hl = 0x10AFu;
	set_channel_handler(hl, ix);
	return carry;
}

void sound_1250(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_30 = 2u;
	hl = 0x125Au;
	set_channel_handler(hl, ix);
}

uint32_t sound_125A(uint16_t ix, uint32_t carry)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_30;
	CHANNEL(ix)->unk_30 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(10);
	return sound_1232(ix);
}

uint32_t pcm_effect_89(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t channel = 0, hl = 0;
	uint16_t saved_ix = 0;

	z80_block(39);
	saved_ix = ix;
	a = 0xA3u;
	start_speech(a);
	z80_block(43);
	channel = saved_ix;
	CHANNEL(channel)->unk_36 = 2u;
	hl = 0x14u;
	return sound_1271(hl, channel);
}

uint32_t sound_1271(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc = 0;
	uint16_t de = 0, hl_2 = 0;

	z80_block(101);
	CHANNEL(ix)->unk_32 = 0xFu;
	CHANNEL(ix)->unk_33 = 0x88u;
	CHANNEL(ix)->unk_34 = 0xFu;
	de = 0x5550u;
	bc = 1u;
	carry = play_pcm_sample(bc, de, hl, ix);
	z80_block(20);
	hl_2 = 0x128Cu;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_128C(uint16_t ix, uint32_t carry)
{
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_30;
	CHANNEL(ix)->unk_30 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_36;
	CHANNEL(ix)->unk_36 = t2 - 1u;
	if (t2 == 1u)
		return stop_pcm_channel(ix);
	z80_block(20);
	hl = 0x60u;
	return sound_1271(hl, ix);
}

uint32_t pcm_effect_8a(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(26);
	CHANNEL(ix)->unk_36 = 2u;
	a = 0xFu;
	return sound_12A2(ix, a);
}

uint32_t sound_12A2(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t bc = 0;
	uint16_t de = 0, hl = 0;

	z80_block(111);
	CHANNEL(ix)->unk_32 = a;
	CHANNEL(ix)->unk_33 = 0xAAu;
	CHANNEL(ix)->unk_34 = 0xFu;
	hl = 0x34u;
	de = 0x5550u;
	bc = 1u;
	carry = play_pcm_sample(bc, de, hl, ix);
	z80_block(20);
	hl = 0x12BFu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t sound_12BF(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_30;
	CHANNEL(ix)->unk_30 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_36;
	CHANNEL(ix)->unk_36 = t2 - 1u;
	if (t2 == 1u)
		return stop_pcm_channel(ix);
	z80_block(36);
	a = CHANNEL(ix)->unk_32 - 0xAu;
	return sound_12A2(ix, a);
}

uint32_t pcm_effect_8b(uint16_t ix)
{
	uint16_t bc = 0, hl = 0;

	z80_block(27);
	hl = 0x1338u;
	queue_pcm_effect_a(hl);
	z80_block(10);
	bc = 0xFA8u;
	return sound_12DA(bc, ix);
}

uint32_t sound_12DA(uint16_t bc, uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(86);
	AS16(CHANNEL(ix)->unk_33) = bc;
	CHANNEL(ix)->unk_36 = 4u;
	CHANNEL(ix)->unk_32 = 0xFu;
	hl = 0x80u;
	return sound_12EB(hl, ix);
}

uint32_t sound_12EB(uint16_t hl, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc = 0;
	uint16_t de = 0, hl_2 = 0;

	z80_block(53);
	CHANNEL(ix)->unk_35 = (uint8_t)hl;
	de = 0u;
	bc = 1u;
	carry = play_pcm_sample(bc, de, hl, ix);
	z80_block(20);
	hl_2 = 0x12FCu;
	set_channel_handler(hl_2, ix);
	return carry;
}

uint32_t sound_12FC(uint16_t ix, uint32_t carry)
{
	uint8_t a = 0, bc = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_30;
	CHANNEL(ix)->unk_30 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(33);
	t2 = CHANNEL(ix)->unk_36;
	CHANNEL(ix)->unk_36 = t2 - 1u;
	if (t2 == 1u)
	{
		z80_block(27);
		carry = 0u;
		if (unk_8201 == 0u)
			return stop_pcm_channel(ix);
		z80_block(10);
		free_channel(ix);
		return carry;
	}
	z80_block(24);
	bc = 0u;
	carry = set_pcm_volume(bc, ix);
	z80_block(17);
	carry = clear_pcm_loop(ix);
	z80_block(49);
	a = CHANNEL(ix)->unk_32;
	if (((CHANNEL(ix)->unk_36 >> 1) & 1u) == 0u)
	{
		z80_block(26);
		CHANNEL(ix)->sound = 0u;
		a += 2u;
	}
	z80_block(73);
	CHANNEL(ix)->unk_32 = a - 5u;
	hl = (uint8_t)(CHANNEL(ix)->unk_35 + 0xCu);
	return sound_12EB(hl, ix);
}

void sound_1338(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	CHANNEL(ix)->unk_36 = 8u;
	hl = 0x1342u;
	set_channel_handler(hl, ix);
}

uint32_t sound_1342(uint16_t ix, uint32_t carry)
{
	uint16_t bc = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = CHANNEL(ix)->unk_36;
	CHANNEL(ix)->unk_36 = t1 - 1u;
	if (t1 != 1u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(20);
	bc = 0xF68u;
	return sound_12DA(bc, ix);
}

uint32_t pcm_effect_8c(uint16_t ix)
{
	uint16_t bc = 0, hl = 0;

	z80_block(49);
	hl = 0x50u;
	CHANNEL(ix)->unk_32 = 0xBu;
	bc = 0xFB0u;
	return sound_116F(bc, hl, ix);
}

uint32_t pcm_effect_8e(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc = 0;
	uint16_t de = 0, hl = 0;

	z80_block(27);
	hl = 0x1232u;
	queue_pcm_effect_a(hl);
	z80_block(111);
	hl = 0x280u;
	CHANNEL(ix)->unk_33 = 0xF0u;
	CHANNEL(ix)->unk_34 = 0xEu;
	de = 0xD281u;
	CHANNEL(ix)->unk_32 = 0xFu;
	bc = 0u;
	carry = play_pcm_sample(bc, de, hl, ix);
	z80_block(20);
	hl = 0x10AFu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t pcm_effect_8f(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc = 0;
	uint16_t de = 0, hl = 0;

	z80_block(144);
	music_attenuation = 1u;
	unk_83CC = 1u;
	hl = 0x110u;
	CHANNEL(ix)->unk_32 = 0xFu;
	CHANNEL(ix)->unk_33 = 0x7Cu;
	CHANNEL(ix)->unk_34 = 0xFu;
	de = 0xD281u;
	bc = 0u;
	carry = play_pcm_sample(bc, de, hl, ix);
	z80_block(20);
	hl = 0x10AFu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t pcm_effect_90(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc = 0;
	uint16_t de = 0, hl = 0;

	z80_block(111);
	hl = 0x540u;
	CHANNEL(ix)->unk_32 = 0xFu;
	CHANNEL(ix)->unk_33 = 0x40u;
	CHANNEL(ix)->unk_34 = 0xEu;
	de = 0x9BE0u;
	bc = 1u;
	carry = play_pcm_sample(bc, de, hl, ix);
	z80_block(20);
	hl = 0x10AFu;
	set_channel_handler(hl, ix);
	return carry;
}

uint32_t pcm_effect_91(uint16_t ix)
{
	uint16_t bc = 0, hl = 0;

	z80_block(49);
	hl = 0xF8u;
	CHANNEL(ix)->unk_32 = 9u;
	bc = 0xFB0u;
	return sound_118D(bc, hl, ix);
}

uint32_t pcm_effect_92(uint16_t ix)
{
	uint16_t bc = 0;

	z80_block(20);
	bc = 0xF98u;
	return sound_1128(bc, ix);
}

uint32_t pcm_effect_93(uint16_t ix)
{
	z80_block(29);
	CHANNEL(ix)->unk_32 = 0xCu;
	return sound_1187(ix);
}
