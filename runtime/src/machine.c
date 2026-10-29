/**
 *    Name:        machine.c
 *    Description: the TMNT board (Konami GX963) as the 68000 program sees it: memory map, inputs, interrupts,
 *                 the video chips' memories and registers
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME: konami/tmnt.cpp (tmnt_main_map, _0a0000_w, priority_w, vblank_w,
 *    k052109_word_noA12_r/w, tmnt_tile_callback, tmnt_sprite_callback), konami/k052109.cpp (read, write,
 *    device_reset) and konami/k051960.cpp (k051960_r/w, k051937_r/w, k051960_fetchromdata, vblank_callback,
 *    device_reset). MAME's terms are in tools/core/konami/reference/mame/LICENSE.
 */
#include "tmnt/machine.h"

#include "game/data.h"

#include <string.h>

tmnt_machine tmnt_board;

/* The odd byte of a 16-bit access: MAME's ACCESSING_BITS_0_7 */
#define LOW_BYTE(mask)     (((mask) & 0x00FFu) != 0)
#define HIGH_BYTE(mask)    (((mask) & 0xFF00u) != 0)

/* K052109: what the tile callback (tmnt_tile_callback) makes of a tile's code, color and bank */
static uint32_t tile_code(uint32_t code, uint8_t color, uint32_t bank)
{
	return code | ((color & 0x03u) << 8) | ((color & 0x10u) << 6) | ((color & 0x0Cu) << 9) | (bank << 13);
}

static uint8_t k052109_read(uint32_t offset)
{
	if (!tmnt_board.read_char_rom)
		return tmnt_board.tile_ram[offset];
	{
		/* the tile ROM through the RAM's window (TMNT reads it at 0000-1FFF): 32 bytes a tile, the tile
		   and its bank from the ROM subbank register, as the layers take them */
		const uint8_t color = tmnt_board.rom_subbank;
		const uint32_t bank = (uint32_t)(tmnt_board.char_rom_bank[(color & 0x0C) >> 2] >> 2)
			| (uint32_t)(tmnt_board.char_rom_bank_2[(color & 0x0C) >> 2] >> 2);
		const uint32_t code = tile_code((offset & 0x1FFFu) >> 5, color, bank);

		return game_tiles[((code << 5) + (offset & 0x1Fu)) & (GAME_TILES_SIZE - 1u)];
	}
}

static void k052109_write(uint32_t offset, uint8_t data)
{
	tmnt_board.tile_ram[offset] = data;
	if ((offset & 0x1FFFu) < 0x1800u)
		return;
	/* the registers that latch (the scroll and the others stay in the RAM, where the video reads them) */
	if (offset == 0x1D80u)
	{
		tmnt_board.char_rom_bank[0] = data & 0x0F;
		tmnt_board.char_rom_bank[1] = (data >> 4) & 0x0F;
	}
	else if (offset == 0x1E00u || offset == 0x3E00u)
		tmnt_board.rom_subbank = data;
	else if (offset == 0x1F00u)
	{
		tmnt_board.char_rom_bank[2] = data & 0x0F;
		tmnt_board.char_rom_bank[3] = (data >> 4) & 0x0F;
	}
	else if (offset == 0x3D80u)
	{
		tmnt_board.char_rom_bank_2[0] = data & 0x0F;
		tmnt_board.char_rom_bank_2[1] = (data >> 4) & 0x0F;
	}
	else if (offset == 0x3F00u)
	{
		tmnt_board.char_rom_bank_2[2] = data & 0x0F;
		tmnt_board.char_rom_bank_2[3] = (data >> 4) & 0x0F;
	}
}

/* The K052109 on a 16-bit bus without its A12 line: each word is a byte of the codes (high) and a byte of
   the colors (low, 0x2000 further). A word access takes the high byte alone, as MAME's handler does */
static uint32_t k052109_offset(uint32_t address)
{
	const uint32_t word = (address - 0x100000u) >> 1;
	return ((word & 0x3000u) >> 1) | (word & 0x07FFu);
}

/* K051960: a byte of its sprite ROM, from the sprite last read, the ROM bank registers and the sprite
   callback (tmnt_sprite_callback) */
static uint8_t k051960_rom(uint32_t offset)
{
	uint32_t address = tmnt_board.sprite_rom_offset + ((uint32_t)tmnt_board.sprite_rom_bank[0] << 8)
		+ ((uint32_t)(tmnt_board.sprite_rom_bank[1] & 0x03) << 16);
	uint32_t code = (address & 0x3FFE0u) >> 5;
	const uint32_t line = address & 0x1Fu;
	const uint32_t color = ((tmnt_board.sprite_rom_bank[1] & 0xFCu) >> 2)
		+ ((uint32_t)(tmnt_board.sprite_rom_bank[2] & 0x03) << 6);

	code |= (color & 0x10u) << 9;
	address = (code << 7) | (line << 2) | offset;
	return game_sprites[address & (GAME_SPRITES_SIZE - 1u)];
}

static uint8_t k051960_read(uint32_t offset)
{
	if (tmnt_board.sprite_control & 0x20)
	{
		tmnt_board.sprite_rom_offset = (uint16_t)((offset & 0x3FCu) >> 2);
		return k051960_rom(offset & 3u);
	}
	return tmnt_board.sprite_ram[offset];
}

static uint8_t k051937_read(uint32_t offset)
{
	offset &= 7u;
	if ((tmnt_board.sprite_control & 0x20) && (offset & 4u))
		return k051960_rom(offset & 3u);
	if (offset == 0)
		return tmnt_board.cycles * 3u < tmnt_board.sprites_busy_until ? 1 : 0;
	return 0;
}

static void k051937_write(uint32_t offset, uint8_t data)
{
	offset &= 7u;
	if (offset == 0)
		tmnt_board.sprite_control = data;
	else if (offset == 1)
		tmnt_board.shadow_config = data & 0x07;
	else if (offset >= 2 && offset < 5)
		tmnt_board.sprite_rom_bank[offset - 2] = data;
}

/* 0A0001: the coin counters, the Z80's IRQ, IRQ5's enable and the tile ROM's window */
static void control_write(uint8_t data)
{
	int counter;

	for (counter = 0; counter < 2; counter++)
		if ((data >> counter) & 1 && !((tmnt_board.control >> counter) & 1))
			tmnt_board.coin_counters[counter]++;
	if ((tmnt_board.control & 0x08) && !(data & 0x08))
	{
		tmnt_board.sound_irqs++;
		if (tmnt_board.sound_sync)
			tmnt_board.sound_sync();
		if (tmnt_board.sound_irq)
			tmnt_board.sound_irq();
	}
	tmnt_board.irq5_enabled = data & 0x20;
	if (!tmnt_board.irq5_enabled)
		tmnt_board.irq5 = false;
	tmnt_board.read_char_rom = (data & 0x80) != 0;
	tmnt_board.control = data;
}

void tmnt_reset(void)
{
	int player;

	memset(&tmnt_board, 0, sizeof(tmnt_board));
	tmnt_board.coins = 0xFF;
	for (player = 0; player < 4; player++)
		tmnt_board.players[player] = 0xFF;
	tmnt_board.dsw[0] = TMNT_DSW1_DEFAULT;
	tmnt_board.dsw[1] = TMNT_DSW2_DEFAULT;
	tmnt_board.dsw[2] = TMNT_DSW3_DEFAULT;
}

/* A byte of the program's data where program_at says it is; nowhere (its code), program_outside says so */
static uint8_t program_byte(uint32_t address)
{
	const uint8_t *data = tmnt_board.program_at(address);

	if (data)
		return *data;
	if (tmnt_board.program_outside)
		tmnt_board.program_outside(address);
	return 0;
}

/* The program's chips: the ROM set's image (game/data.h), or the bytes the mask asks for where program_at
   finds them */
static uint16_t program_word(uint32_t address, uint16_t mem_mask)
{
	uint16_t word = 0;

	if (!tmnt_board.program_at)
		return (uint16_t)(game_program[address] << 8 | game_program[address + 1]);
	if (mem_mask & 0xFF00u)
		word |= (uint16_t)(program_byte(address) << 8);
	if (mem_mask & 0x00FFu)
		word |= program_byte(address + 1u);
	return word;
}

uint16_t tmnt_read16(uint32_t address, uint16_t mem_mask)
{
	address &= 0xFFFFFEu;
	if (address < TMNT_PROGRAM_SIZE)
		return program_word(address, mem_mask);
	if (address >= 0x060000u && address < 0x064000u)
		return (uint16_t)(*tmnt_work_ram_byte(address) << 8 | *tmnt_work_ram_byte(address + 1u));
	if (address >= 0x080000u && address < 0x081000u)
		return LOW_BYTE(mem_mask) ? tmnt_board.palette[(address - 0x080000u) >> 1] : 0;
	switch (address)
	{
	case 0x0A0000u: return tmnt_board.coins;
	case 0x0A0002u: return tmnt_board.players[0];
	case 0x0A0004u: return tmnt_board.players[1];
	case 0x0A0006u: return tmnt_board.players[2];
	case 0x0A0010u: return tmnt_board.dsw[0];
	case 0x0A0012u: return tmnt_board.dsw[1];
	case 0x0A0014u: return tmnt_board.players[3];
	case 0x0A0018u: return tmnt_board.dsw[2];
	default: break;
	}
	if (address >= 0x100000u && address < 0x108000u)
	{
		const uint32_t offset = k052109_offset(address);
		return HIGH_BYTE(mem_mask) ? (uint16_t)(k052109_read(offset) << 8) : k052109_read(offset + 0x2000u);
	}
	/* the 8-bit chips: the even byte first, as MAME reads the lanes (a read of the K051960's ROM moves its
	   offset) */
	if (address >= 0x140000u && address < 0x140008u)
	{
		const uint16_t high = HIGH_BYTE(mem_mask) ? (uint16_t)(k051937_read(address - 0x140000u) << 8) : 0;
		return (uint16_t)(high | (LOW_BYTE(mem_mask) ? k051937_read(address - 0x140000u + 1u) : 0));
	}
	if (address >= 0x140400u && address < 0x140800u)
	{
		const uint16_t high = HIGH_BYTE(mem_mask) ? (uint16_t)(k051960_read(address - 0x140400u) << 8) : 0;
		return (uint16_t)(high | (LOW_BYTE(mem_mask) ? k051960_read(address - 0x140400u + 1u) : 0));
	}
	return 0;
}

void tmnt_write16(uint32_t address, uint16_t data, uint16_t mem_mask)
{
	address &= 0xFFFFFEu;
	if (tmnt_board.write_watch)
		tmnt_board.write_watch(address, data, mem_mask);
	if (address >= 0x060000u && address < 0x064000u)
	{
		if (HIGH_BYTE(mem_mask))
			*tmnt_work_ram_byte(address) = (uint8_t)(data >> 8);
		if (LOW_BYTE(mem_mask))
			*tmnt_work_ram_byte(address + 1u) = (uint8_t)data;
		return;
	}
	if (address >= 0x080000u && address < 0x081000u)
	{
		if (LOW_BYTE(mem_mask))
			tmnt_board.palette[(address - 0x080000u) >> 1] = (uint8_t)data;
		return;
	}
	switch (address)
	{
	case 0x0A0000u:
		/* (a 16-bit handler that takes the data as it is: the 68000 puts a byte on both lanes, so a byte
		   written to either address reaches it) */
		control_write((uint8_t)data);
		return;
	case 0x0A0008u:
		if (LOW_BYTE(mem_mask))
		{
			if (tmnt_board.sound_sync)
				tmnt_board.sound_sync();
			tmnt_board.sound_latch = (uint8_t)data;
		}
		return;
	case 0x0A0010u:
		tmnt_board.watchdog_resets++;
		return;
	case 0x0C0000u:
		tmnt_board.priority = (uint8_t)((data & 0x0Cu) >> 2);
		return;
	default:
		break;
	}
	if (address >= 0x100000u && address < 0x108000u)
	{
		const uint32_t offset = k052109_offset(address);
		if (HIGH_BYTE(mem_mask))
			k052109_write(offset, (uint8_t)(data >> 8));
		else
			k052109_write(offset + 0x2000u, (uint8_t)data);
		return;
	}
	if (address >= 0x140000u && address < 0x140008u)
	{
		if (HIGH_BYTE(mem_mask))
			k051937_write(address - 0x140000u, (uint8_t)(data >> 8));
		if (LOW_BYTE(mem_mask))
			k051937_write(address - 0x140000u + 1u, (uint8_t)data);
		return;
	}
	if (address >= 0x140400u && address < 0x140800u)
	{
		if (HIGH_BYTE(mem_mask))
			tmnt_board.sprite_ram[address - 0x140400u] = (uint8_t)(data >> 8);
		if (LOW_BYTE(mem_mask))
			tmnt_board.sprite_ram[address - 0x140400u + 1u] = (uint8_t)data;
	}
}

int tmnt_irq_level(void)
{
	return tmnt_board.irq5 ? 5 : 0;
}

void tmnt_vblank_start(void)
{
	tmnt_board.frame++;
	if (tmnt_board.irq5_enabled)
		tmnt_board.irq5 = true;
	/* the K051960's sprite DMA, unless the program stopped it: 32 clocks for each sprite shown, 18 for each
	   other, 4 ticks of 24 MHz a clock */
	if (!(tmnt_board.sprite_control & 0x10))
	{
		uint32_t sprite, shown = 0;

		memcpy(tmnt_board.sprite_buffer, tmnt_board.sprite_ram, TMNT_SPRITE_RAM_SIZE);
		for (sprite = 0; sprite < TMNT_SPRITE_RAM_SIZE; sprite += 8u)
			shown += tmnt_board.sprite_buffer[sprite] >> 7;
		tmnt_board.sprites_busy_until = tmnt_board.cycles * 3u + (shown * 32u + (128u - shown) * 18u) * 4u;
	}
}

static uint64_t hash_bytes(const void *data, size_t size, uint64_t hash)
{
	const uint8_t *bytes = (const uint8_t *)data;
	size_t index;

	for (index = 0; index < size; index++)
		hash = (hash ^ bytes[index]) * 0x100000001b3ull;
	return hash;
}

uint64_t tmnt_state_hash(void)
{
	const uint8_t registers[] = {
		tmnt_board.char_rom_bank[0], tmnt_board.char_rom_bank[1], tmnt_board.char_rom_bank[2],
		tmnt_board.char_rom_bank[3], tmnt_board.char_rom_bank_2[0], tmnt_board.char_rom_bank_2[1],
		tmnt_board.char_rom_bank_2[2], tmnt_board.char_rom_bank_2[3], tmnt_board.rom_subbank,
		tmnt_board.sprite_control, tmnt_board.shadow_config, tmnt_board.sprite_rom_bank[0],
		tmnt_board.sprite_rom_bank[1], tmnt_board.sprite_rom_bank[2], tmnt_board.priority, tmnt_board.control,
		tmnt_board.sound_latch
	};
	uint64_t hash = 0xcbf29ce484222325ull;

	for (uint32_t address = TMNT_WORK_RAM; address < TMNT_WORK_RAM + TMNT_WORK_RAM_SIZE; address++)
	{
		if ((address >= TMNT_SAVED_REGISTERS && address < TMNT_SAVED_REGISTERS_END)
			|| (address >= TMNT_STACKS && address < TMNT_STACKS_END))
			continue;
		hash = (hash ^ *tmnt_work_ram_byte(address)) * 0x100000001b3ull;
	}
	hash = hash_bytes(tmnt_board.palette, sizeof(tmnt_board.palette), hash);
	hash = hash_bytes(tmnt_board.tile_ram, sizeof(tmnt_board.tile_ram), hash);
	hash = hash_bytes(tmnt_board.sprite_ram, sizeof(tmnt_board.sprite_ram), hash);
	return hash_bytes(registers, sizeof(registers), hash);
}
