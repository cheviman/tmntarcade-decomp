/**
 *    Name:        chips.c
 *    Description: the chips' registers: the YM2151's writes and the frame's timer, its voices, keys, pitches and volumes; the K007232's start, pitch, volume and loop
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

void write_fm_register_de(uint8_t bc, uint16_t de)
{
	uint32_t carry = 0;
	uint16_t bc_2 = 0;

	z80_block(22);
	bc_2 = (bc & 0xFFu) | ((uint32_t)(uint8_t)((de >> 8) + de) << 8);
	carry = write_fm_register(bc_2);
}

void write_fm_channel_register(uint16_t ix, uint16_t *p_bc, uint32_t *p_carry)
{
	uint16_t bc = (uint16_t)*p_bc;
	uint32_t carry = *p_carry;

	z80_block(27);
	bc = (bc & 0xFFu) | ((uint32_t)(uint8_t)(CHANNEL(ix)->chip_channel + (bc >> 8)) << 8);
	carry = write_fm_register(bc);
	*p_bc = (*p_bc & 0xFFu) | bc;
	*p_carry = carry;
}

uint32_t write_fm_register(uint16_t bc)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	for (;;)
	{
		z80_block(27);
		t1 = z80_read8(fm_data);
		if ((t1 & 0x80u) == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(17);
	z80_write8(fm_address, bc >> 8);
	for (;;)
	{
		z80_block(27);
		t2 = z80_read8(fm_data);
		carry = 0u;
		if ((t2 & 0x80u) == 0u)
			break;
		z80_cycles(5);
	}
	z80_block(27);
	z80_write8(fm_data, (uint8_t)bc);
	return carry;
}

void restart_frame_timer(void)
{
	uint32_t carry = 0;
	uint16_t bc = 0;

	z80_block(27);
	bc = 0x1439u;
	carry = write_fm_register(bc);
	z80_block(27);
	bc = 0x12F2u;
	carry = write_fm_register(bc);
	z80_block(22);
	bc = 0x143Bu;
	carry = write_fm_register(bc);
}

uint32_t load_fm_voice(uint16_t voice, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t c1_release = 0, c2_release = 0, connection = 0, m1_release = 0, m2_release = 0;
	uint16_t bc = 0;

	z80_block(17);
	fm_key_off(ix);
	z80_block(17);
	carry = fm_fast_release(ix);
	z80_block(50);
	connection = FM_VOICE(voice)->connection;
	CHANNEL(ix)->unk_05 = connection;
	bc = 0x2000u | connection;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0x4000u | FM_VOICE(voice - 0x1u)->m1_detune_multiple;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(69);
	voice++;
	CHANNEL(ix)->unk_06 = FM_VOICE(voice - 0x2u)->m1_total_level;
	voice++;
	bc = 0x8000u | FM_VOICE(voice - 0x3u)->m1_attack;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0xA000u | FM_VOICE(voice - 0x4u)->m1_decay_1;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0xC000u | FM_VOICE(voice - 0x5u)->m1_decay_2;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(56);
	voice++;
	m1_release = FM_VOICE(voice - 0x6u)->m1_release;
	CHANNEL(ix)->unk_0A = m1_release;
	bc = 0xE000u | m1_release;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0x5000u | FM_VOICE(voice - 0x7u)->c1_detune_multiple;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(69);
	voice++;
	CHANNEL(ix)->unk_07 = FM_VOICE(voice - 0x8u)->c1_total_level;
	voice++;
	bc = 0x9000u | FM_VOICE(voice - 0x9u)->c1_attack;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0xB000u | FM_VOICE(voice - 0xAu)->c1_decay_1;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0xD000u | FM_VOICE(voice - 0xBu)->c1_decay_2;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(56);
	voice++;
	c1_release = FM_VOICE(voice - 0xCu)->c1_release;
	CHANNEL(ix)->unk_0B = c1_release;
	bc = 0xF000u | c1_release;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0x4800u | FM_VOICE(voice - 0xDu)->m2_detune_multiple;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(69);
	voice++;
	CHANNEL(ix)->unk_08 = FM_VOICE(voice - 0xEu)->m2_total_level;
	voice++;
	bc = 0x8800u | FM_VOICE(voice - 0xFu)->m2_attack;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0xA800u | FM_VOICE(voice - 0x10u)->m2_decay_1;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0xC800u | FM_VOICE(voice - 0x11u)->m2_decay_2;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(56);
	voice++;
	m2_release = FM_VOICE(voice - 0x12u)->m2_release;
	CHANNEL(ix)->unk_0C = m2_release;
	bc = 0xE800u | m2_release;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0x5800u | FM_VOICE(voice - 0x13u)->c2_detune_multiple;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(69);
	voice++;
	CHANNEL(ix)->unk_09 = FM_VOICE(voice - 0x14u)->c2_total_level;
	voice++;
	bc = 0x9800u | FM_VOICE(voice - 0x15u)->c2_attack;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0xB800u | FM_VOICE(voice - 0x16u)->c2_decay_1;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(37);
	voice++;
	bc = 0xD800u | FM_VOICE(voice - 0x17u)->c2_decay_2;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(49);
	c2_release = FM_VOICE(voice - 0x17u)->c2_release;
	CHANNEL(ix)->unk_0D = c2_release;
	bc = 0xF800u | c2_release;
	write_fm_channel_register(ix, &bc, &carry);
	return carry;
}

uint32_t fm_key_on(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t chip_channel = 0;
	uint16_t bc = 0;

	z80_block(31);
	chip_channel = CHANNEL(ix)->chip_channel;
	carry = chip_channel < 8u;
	if (chip_channel >= 8u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(28);
	bc = 0x800u | chip_channel | 0x78u;
	return write_fm_register(bc);
}

void fm_key_off(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t chip_channel = 0;
	uint16_t bc = 0;

	z80_block(31);
	chip_channel = CHANNEL(ix)->chip_channel;
	if (chip_channel >= 8u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(21);
	bc = 0x800u | chip_channel;
	carry = write_fm_register(bc);
}

uint32_t fm_fast_release(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0, chip_channel = 0;
	uint16_t bc = 0;

	z80_block(31);
	chip_channel = CHANNEL(ix)->chip_channel;
	carry = chip_channel < 8u;
	if (chip_channel >= 8u)
	{
		z80_cycles(6);
		return carry;
	}
	z80_block(43);
	a = CHANNEL(ix)->unk_0A;
	bc = speech_start;
	carry = sound_06F1(bc, ix, a);
	z80_block(43);
	a = CHANNEL(ix)->unk_0B;
	bc = speech_busy;
	carry = sound_06F1(bc, ix, a);
	z80_block(43);
	a = CHANNEL(ix)->unk_0C;
	bc = 0xE800u;
	carry = sound_06F1(bc, ix, a);
	z80_block(26);
	a = CHANNEL(ix)->unk_0D;
	bc = 0xF800u;
	return sound_06F1(bc, ix, a);
}

uint32_t sound_06F1(uint16_t bc, uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint16_t bc_2 = 0;

	z80_block(21);
	bc_2 = (bc & ~0xFFu) | a | 0xFu;
	write_fm_channel_register(ix, &bc_2, &carry);
	return carry;
}

void fm_restore_release(uint16_t ix)
{
	uint32_t carry = 0;
	uint16_t bc = 0;

	z80_block(31);
	if (CHANNEL(ix)->chip_channel >= 8u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(43);
	bc = 0xE000u | CHANNEL(ix)->unk_0A;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(43);
	bc = 0xF000u | CHANNEL(ix)->unk_0B;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(43);
	bc = 0xE800u | CHANNEL(ix)->unk_0C;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(36);
	bc = 0xF800u | CHANNEL(ix)->unk_0D;
	write_fm_channel_register(ix, &bc, &carry);
}

void set_fm_pitch(uint16_t hl, uint16_t ix, uint16_t *p_bc, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t bc = 0;
	uint8_t t1 = 0;

	z80_block(11);
	a = (hl >> 8) & 0x1Fu;
	do
	{
		z80_block(17);
		t1 = a;
		a = t1 - 0x18u;
	} while (t1 >= 0x18u);
	z80_block(61);
	hl = ((hl & 0xFFu) | ((uint32_t)(uint8_t)(a + 0x18u) << 8)) * 2u * 2u;
	bc = 0x3000u | (uint8_t)hl;
	write_fm_channel_register(ix, &bc, &carry);
	z80_block(56);
	bc = 0x2800u | fm_key_codes[hl >> 8];
	*p_bc = bc;
	write_fm_channel_register(ix, p_bc, &carry);
	*p_carry = carry;
}

uint32_t set_fm_volume_from_record(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(19);
	a = CHANNEL(ix)->unk_2C;
	return set_fm_volume(ix, a);
}

uint32_t set_fm_volume(uint16_t ix, uint8_t a)
{
	uint32_t carry = 0;
	uint8_t a_2 = 0;
	uint16_t bc = 0, hl = 0;

	z80_block(127);
	CHANNEL(ix)->unk_04 = a;
	hl = fm_carrier_masks[CHANNEL(ix)->unk_05 & 7u];
	a_2 = CHANNEL(ix)->unk_06;
	bc = 0x6000u;
	sound_07CD(bc, ix, a_2, &hl, &carry);
	z80_block(43);
	a_2 = CHANNEL(ix)->unk_08;
	bc = 0x6800u;
	sound_07CD(bc, ix, a_2, &hl, &carry);
	z80_block(43);
	a_2 = CHANNEL(ix)->unk_07;
	bc = 0x7000u;
	sound_07CD(bc, ix, a_2, &hl, &carry);
	z80_block(26);
	a_2 = CHANNEL(ix)->unk_09;
	bc = 0x7800u;
	sound_07CD(bc, ix, a_2, &hl, &carry);
	return carry;
}

void sound_07CD(uint16_t bc, uint16_t ix, uint8_t a, uint16_t *p_hl, uint32_t *p_carry)
{
	uint8_t hl = (uint8_t)*p_hl;
	uint32_t carry = *p_carry;
	uint8_t l = 0;
	uint16_t bc_2 = 0, hl_2 = 0;
	uint8_t t1 = 0;

	l = (uint8_t)hl;
	z80_block(18);
	carry = l >> 7;
	l = (uint32_t)l << 1;
	if (carry)
	{
		z80_block(29);
		t1 = a + CHANNEL(ix)->unk_04;
		a = t1;
		if ((int8_t)t1 < 0)
		{
			z80_block(7);
			a = 0x7Fu;
		}
	}
	z80_block(14);
	bc_2 = (bc & ~0xFFu) | a;
	hl_2 = l;
	write_fm_channel_register(ix, &bc_2, &carry);
	*p_hl = (*p_hl & 0xFF00u) | hl_2;
	*p_carry = carry;
}

void set_pcm_start(uint8_t bc, uint16_t de, uint16_t ix)
{
	uint8_t a = 0;

	z80_block(34);
	a = (uint8_t)bc;
	if ((CHANNEL(ix)->chip_channel & 1u) != 0u)
	{
		z80_block(43);
		z80_write16(pcm_b_start, de);
		z80_write8(pcm_b_bank, a);
		return;
	}
	z80_block(43);
	z80_write16(pcm_a_start, de);
	z80_write8(pcm_a_bank, a);
}

void set_pcm_pitch(uint16_t de, uint16_t ix)
{
	z80_block(30);
	if ((CHANNEL(ix)->chip_channel & 1u) != 0u)
	{
		z80_block(30);
		z80_write16(pcm_b_pitch, de);
		return;
	}
	z80_block(30);
	z80_write16(pcm_a_pitch, de);
}

uint32_t set_pcm_volume(uint8_t bc, uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0, c = 0;

	c = (uint8_t)bc;
	z80_block(43);
	a = pcm_volumes;
	if ((CHANNEL(ix)->chip_channel & 1u) != 0u)
	{
		z80_block(47);
		carry = 0u;
		a = (a & ~0xFu) | c;
		pcm_volumes = a;
		z80_write8(pcm_volume_port, a);
		return carry;
	}
	z80_block(79);
	carry = 0u;
	a = (a & 0xFu) | (((((uint32_t)c << 1) << 1) << 1) << 1);
	pcm_volumes = a;
	z80_write8(pcm_volume_port, a);
	return carry;
}

void start_pcm(uint16_t ix)
{
	uint8_t t1 = 0, t2 = 0;

	z80_block(30);
	if ((CHANNEL(ix)->chip_channel & 1u) != 0u)
	{
		z80_block(23);
		t1 = z80_read8(pcm_b_key);
		return;
	}
	z80_block(23);
	t2 = z80_read8(pcm_a_key);
}

void set_pcm_loop(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(43);
	a = pcm_loops;
	if ((z80_read8(ix) & 1u) != 0u)
	{
		z80_block(43);
		a |= 2u;
		pcm_loops = a;
		z80_write8(pcm_loop_flags, a);
		return;
	}
	z80_block(43);
	a |= 1u;
	pcm_loops = a;
	z80_write8(pcm_loop_flags, a);
}

uint32_t clear_pcm_loop(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t a = 0;

	z80_block(43);
	a = pcm_loops;
	if ((CHANNEL(ix)->chip_channel & 1u) != 0u)
	{
		z80_block(43);
		carry = 0u;
		a &= 1u;
		pcm_loops = a;
		z80_write8(pcm_loop_flags, a);
		return carry;
	}
	z80_block(43);
	carry = 0u;
	a &= 2u;
	pcm_loops = a;
	z80_write8(pcm_loop_flags, a);
	return carry;
}
