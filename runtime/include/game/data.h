/**
 *    Name:        data.h
 *    Description: the ROM set's regions as the board has them, for the tools that run the original code
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The reference (tools/core/konami/reference) runs the original code, so it fills these regions from the
 *    player's ROM set when it starts (game/extract.h). The regions are laid out as MAME's ROM_START( tmnt )
 *    and init_tmnt leave them: the files interleaved as tools/tmnt_rom.py interleaves them, and then the
 *    tile and sprite ROMs' bits from chunky to planar and the sprite ROM's address lines unscrambled by the
 *    PROM (which tools/tmnt_rom.py does not do: it keeps the files' bytes as they are). The program reads
 *    the tile and sprite ROMs through the video chips (the ROM test), so it sees what MAME gives it.
 */
#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GAME_PROGRAM_SIZE   0x60000      /* the 68000's program, big endian */
#define GAME_SOUND_SIZE     0x8000       /* the Z80's */
#define GAME_TILES_SIZE     0x100000     /* the K052109's tile ROM */
#define GAME_SPRITES_SIZE   0x200000     /* the K051960's sprite ROM */
#define GAME_PROMS_SIZE     0x200        /* the sprite address decoder, then the priority PROM */
#define GAME_PCM_SIZE       0x20000      /* the K007232's samples */
#define GAME_SPEECH_SIZE    0x20000      /* the uPD7759's */
#define GAME_TITLE_SIZE     0x80000      /* the title music */

extern uint8_t game_program[GAME_PROGRAM_SIZE];
extern uint8_t game_sound[GAME_SOUND_SIZE];
extern uint8_t game_tiles[GAME_TILES_SIZE];
extern uint8_t game_sprites[GAME_SPRITES_SIZE];
extern uint8_t game_proms[GAME_PROMS_SIZE];
extern uint8_t game_pcm[GAME_PCM_SIZE];
extern uint8_t game_speech[GAME_SPEECH_SIZE];
extern uint8_t game_title[GAME_TITLE_SIZE];

#ifdef __cplusplus
}
#endif

#endif
