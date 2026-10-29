/**
 *    Name:        extract.h
 *    Description: the player's ROM set into the board's memory (game/data.h)
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The ROM set is MAME's 'tmnt' (World 4 Players, version X), each of its 16 files known by its CRC32: in
 *    a .zip (stored or deflated) or a folder of its files (by MAME's names).
 */
#ifndef GAME_EXTRACT_H
#define GAME_EXTRACT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The ROM set at 'source' into game/data.h's regions, laid out as the board has them, the code too (for
   the reference, which runs it): NULL, or what is wrong with it */
const char *game_rom_set_load(const char *source);

#ifdef __cplusplus
}
#endif

#endif
