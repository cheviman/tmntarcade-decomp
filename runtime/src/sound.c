/**
 *    Name:        sound.c
 *    Description: the TMNT sound board as its Z80 program sees it: program, RAM, 9000, the latch, the chips
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME's konami/tmnt.cpp (tmnt_audio_map, sres_r, sres_w, tmnt_upd_start_w,
 *    tmnt_upd_busy_r). The chips are the sound board model's (tmnt_board.sound_chip_read and write).
 */
#include "tmnt/machine.h"

#include "game/data.h"

static uint8_t chip_read(int chip, int offset)
{
	return tmnt_board.sound_chip_read ? tmnt_board.sound_chip_read(chip, offset) : 0;
}

static void chip_write(int chip, int offset, uint8_t data)
{
	if (tmnt_board.sound_chip_write)
		tmnt_board.sound_chip_write(chip, offset, data);
}

uint8_t tmnt_z80_read(uint16_t address)
{
	if (address < GAME_SOUND_SIZE)
		return game_sound[address];
	if (address >= 0x8000u && address < 0x8000u + TMNT_SOUND_RAM_SIZE)
		return tmnt_board.sound_ram[address - 0x8000u];
	if (address == 0x9000u)
		return tmnt_board.sound_control;
	if (address == 0xA000u)
		return tmnt_board.sound_latch;
	if (address >= 0xB000u && address <= 0xB00Du)
		return chip_read(TMNT_CHIP_PCM, address - 0xB000u);
	if (address == 0xC000u || address == 0xC001u)
		return chip_read(TMNT_CHIP_FM, address - 0xC000u);
	if (address == 0xF000u)
		return chip_read(TMNT_CHIP_SPEECH_BUSY, 0);
	return 0;
}

void tmnt_z80_write(uint16_t address, uint8_t data)
{
	if (address >= 0x8000u && address < 0x8000u + TMNT_SOUND_RAM_SIZE)
		tmnt_board.sound_ram[address - 0x8000u] = data;
	else if (address == 0x9000u)
	{
		chip_write(TMNT_CHIP_SOUND_RESET, 0, data);
		tmnt_board.sound_control = data;
	}
	else if (address >= 0xB000u && address <= 0xB00Du)
		chip_write(TMNT_CHIP_PCM, address - 0xB000u, data);
	else if (address == 0xC000u || address == 0xC001u)
		chip_write(TMNT_CHIP_FM, address - 0xC000u, data);
	else if (address == 0xD000u)
		chip_write(TMNT_CHIP_SPEECH, 0, data);
	else if (address == 0xE000u)
		chip_write(TMNT_CHIP_SPEECH_START, 0, data);
}
