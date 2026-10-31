/**
 *    Name:        machine.h
 *    Description: the TMNT board (Konami GX963) as the 68000 program sees it: memory map, inputs, interrupts,
 *                 the video chips' memories and registers
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME: konami/tmnt.cpp (Nicola Salmoria), konami/k052109.cpp and konami/k051960.cpp
 *    (Fabio Priuli, Acho A. Tang, R. Belmont, Nicola Salmoria). MAME's terms are in
 *    tools/core/konami/reference/mame/LICENSE.
 *
 *    The 68000 side is reached through tmnt_read16 / tmnt_write16: a big-endian 16-bit bus with 24 address
 *    lines, every access a word at an even address with MAME's mem_mask (0xFF00 for the even byte, 0x00FF
 *    for the odd one, 0xFFFF for both). What no device answers reads 0, MAME's default.
 *
 *    The names keep the family's prefix, tmnt: MAME's driver of the same name holds this board and its
 *    relatives (Cue Brick, M.I.A.), which differ in their memory maps.
 *
 *    Time: the caller advances tmnt_board.cycles as the CPU runs and calls the frame's events itself
 *    (tools/core/konami/reference/kref, to follow the real CPU's pace).
 *
 *    The work RAM is kept the other way round: the byte at its last address (063FFF) first. A big-endian value
 *    of any width at any address is then a little-endian value of the host's at tmnt_work_ram_at(), which the
 *    decompiled program reads and writes as plain C variables (game/support.h); the bus and the state hash see
 *    the bytes at their addresses.
 */
#ifndef TMNT_MACHINE_H
#define TMNT_MACHINE_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TMNT_CPU_CLOCK        8000000u     /* 24 MHz / 3: the 68000 */
#define TMNT_VIDEO_CLOCK      24000000u    /* the K052109 and the K051960 */
#define TMNT_LINE_CYCLES      512u         /* 384 pixels at 6 MHz: 64 us, 512 cycles of the 68000 */
#define TMNT_LINES            264
#define TMNT_VBLANK_START     240          /* the visible lines are 16-239 */
#define TMNT_VBLANK_END       16
#define TMNT_FRAME_CYCLES     (TMNT_LINE_CYCLES * TMNT_LINES)

#define TMNT_PROGRAM_SIZE     0x60000
#define TMNT_WORK_RAM         0x060000u
#define TMNT_WORK_RAM_SIZE    0x4000       /* 060000-063FFF */
#define TMNT_PALETTE_SIZE     0x800        /* 080000-080FFF, the odd bytes: 1024 colors, xBGR 555 */
#define TMNT_TILE_RAM_SIZE    0x6000       /* the K052109's */
#define TMNT_SPRITE_RAM_SIZE  0x400        /* the K051960's: 128 sprites of 8 bytes */

/* The sound board: a Z80, a YM2151 and a K007232 on 3.579545 MHz, a uPD7759 on 640 kHz, and the title
   music, a sample played through a DAC at 640 kHz / 32 */
#define TMNT_SOUND_CLOCK      3579545u
#define TMNT_SPEECH_CLOCK     640000u
#define TMNT_SOUND_RAM_SIZE   0x800        /* the Z80's RAM, 8000-87FF */

/* The sound board's chips as the Z80 reaches them (tmnt_z80_read / tmnt_z80_write) */
enum
{
	TMNT_CHIP_PCM,             /* K007232, B000-B00D */
	TMNT_CHIP_FM,              /* YM2151, C000-C001 */
	TMNT_CHIP_SPEECH,          /* uPD7759: its port (D000), its start line (E000), whether it is busy (F000) */
	TMNT_CHIP_SPEECH_START,
	TMNT_CHIP_SPEECH_BUSY,
	TMNT_CHIP_SOUND_RESET      /* 9000: bit 1 the uPD7759's reset line, bit 2 plays the title music */
};

/* The inputs, as MAME's ports have them: every bit active low */
enum
{
	TMNT_COIN1 = 0x01, TMNT_COIN2 = 0x02, TMNT_COIN3 = 0x04, TMNT_COIN4 = 0x08,
	TMNT_SERVICE1 = 0x10, TMNT_SERVICE2 = 0x20, TMNT_SERVICE3 = 0x40, TMNT_SERVICE4 = 0x80
};
enum
{
	TMNT_LEFT = 0x01, TMNT_RIGHT = 0x02, TMNT_UP = 0x04, TMNT_DOWN = 0x08,
	TMNT_JUMP = 0x10, TMNT_ATTACK = 0x20      /* (MAME: buttons 1 and 2; the 4-player board has no start) */
};
/* The DIP switches as MAME sets them by default: 1 coin 1 credit, 2 lives, normal difficulty, demo sounds on,
   no flip, test mode off */
#define TMNT_DSW1_DEFAULT     0xFF
#define TMNT_DSW2_DEFAULT     0x5E
#define TMNT_DSW3_DEFAULT     0xFF
#define TMNT_DSW3_SERVICE     0x04          /* active low: the test mode */

/* The work RAM the state comparisons leave out: what the 68000 itself keeps there, which the decompiled program
   keeps in its C variables instead: the registers the VBLANK handler saves for the code it interrupts (060440,
   D0-D7 and A0-A6), and the stacks (the user's below 060900, the supervisor's below 060B00: 060700-060AFF, which
   no data of the program's uses) */
#define TMNT_SAVED_REGISTERS      0x060440u
#define TMNT_SAVED_REGISTERS_END  0x06047Cu
#define TMNT_STACKS               0x060700u
#define TMNT_STACKS_END           0x060B00u

typedef struct
{
	uint8_t work_ram[TMNT_WORK_RAM_SIZE];    /* the other way round: tmnt_work_ram_at */
	uint8_t palette[TMNT_PALETTE_SIZE];

	/* K052109: three tile layers (codes, colors), their scroll and its registers, all in one RAM */
	uint8_t tile_ram[TMNT_TILE_RAM_SIZE];
	uint8_t char_rom_bank[4];      /* 1D80, 1F00 */
	uint8_t char_rom_bank_2[4];    /* 3D80 */
	uint8_t rom_subbank;           /* 1E00 */
	bool read_char_rom;            /* RMRD: the tile RAM's window reads the tile ROM (0A0000 bit 7) */

	/* K051960 / K051937: the sprite list, the copy it draws, and its registers */
	uint8_t sprite_ram[TMNT_SPRITE_RAM_SIZE];
	uint8_t sprite_buffer[TMNT_SPRITE_RAM_SIZE];    /* what the VBLANK's DMA copied */
	uint8_t sprite_control;        /* 051937 register 0 */
	uint8_t shadow_config;         /* register 1 */
	uint8_t sprite_rom_bank[3];    /* registers 2-4 */
	uint16_t sprite_rom_offset;
	uint64_t sprites_busy_until;   /* the DMA's end, in 24 MHz ticks */

	uint8_t priority;              /* 0C0000 bits 2-3 */
	uint8_t control;               /* the last byte written to 0A0001 */
	uint8_t irq5_enabled;          /* its bit 5 */
	bool irq5;                     /* the 68000's IRQ5, from VBLANK, until the program disables it */
	uint8_t sound_latch;           /* 0A0009, which the Z80 reads */
	uint32_t sound_irqs;           /* the Z80's IRQs: 0A0001 bit 3 going low */

	/* the sound board */
	uint8_t sound_ram[TMNT_SOUND_RAM_SIZE];
	uint8_t sound_control;         /* the last byte written to 9000, which reads it back */
	/* What the sound board's model (the reference's) does: brings the sound board up to the 68000's present
	   before the 68000 changes what the Z80 sees; raises the Z80's IRQ (held until the Z80 takes it); reads
	   and writes the sound chips. Unset, the sound board stands still */
	void (*sound_sync)(void);
	void (*sound_irq)(void);
	uint8_t (*sound_chip_read)(int chip, int offset);
	void (*sound_chip_write)(int chip, int offset, uint8_t data);
	/* Where the program's data is: unset, the ROM set's image (game/data.h's game_program, for the reference,
	   which runs the original code); the game sets the assets' pieces (assets_data_at), and a read where
	   they have nothing (the program's code: the game has none to read) goes to program_outside */
	const uint8_t *(*program_at)(uint32_t address);
	void (*program_outside)(uint32_t address);
	/* A development aid: called with every write the 68000 makes on the bus (runtime/src/game_program.c's watch) */
	void (*write_watch)(uint32_t address, uint16_t data, uint16_t mem_mask);
	uint32_t coin_counters[2];
	uint32_t watchdog_resets;

	/* the inputs, active low */
	uint8_t coins;
	uint8_t players[4];
	uint8_t dsw[3];

	uint64_t cycles;               /* the 68000's, since reset */
	uint64_t frame;                /* VBLANKs since reset */
} tmnt_machine;

extern tmnt_machine tmnt_board;

/* The host's place of the 'size' bytes of work RAM from 'address' (a big-endian value there is a little-endian
   one at this place) */
static inline void *tmnt_work_ram_at(uint32_t address, uint32_t size)
{
	return &tmnt_board.work_ram[TMNT_WORK_RAM_SIZE - size - ((address - TMNT_WORK_RAM) & (TMNT_WORK_RAM_SIZE - 1u))];
}

/* The work RAM's byte at 'address' */
static inline uint8_t *tmnt_work_ram_byte(uint32_t address)
{
	return (uint8_t *)tmnt_work_ram_at(address, 1u);
}

/* The board after its reset, the inputs idle and the DIP switches as MAME sets them (its ROMs are
   game/data.h's regions) */
void tmnt_reset(void);

uint16_t tmnt_read16(uint32_t address, uint16_t mem_mask);
void tmnt_write16(uint32_t address, uint16_t data, uint16_t mem_mask);

/* The interrupt level the 68000 sees: 5 while the IRQ5 line is asserted, else 0 */
int tmnt_irq_level(void);

/* The screen's VBLANK begins (line 240): the K051960's sprite DMA, and IRQ5 if the program enables it */
void tmnt_vblank_start(void);

/* A hash of the state the program keeps: work RAM (but what the 68000 itself keeps there: TMNT_STACKS...),
   palette, the video chips' memories and registers */
uint64_t tmnt_state_hash(void);

/* The Z80's memory map (MAME's tmnt_audio_map): its program, its RAM, 9000, the latch at A000, the chips.
   What no device answers reads 0 */
uint8_t tmnt_z80_read(uint16_t address);
void tmnt_z80_write(uint16_t address, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif
