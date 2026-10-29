/**
 *    Name:        game_data.c
 *    Description: the ROM set's regions (game/data.h), which the reference fills when it starts
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 */
#include "game/data.h"

uint8_t game_program[GAME_PROGRAM_SIZE];
uint8_t game_sound[GAME_SOUND_SIZE];
uint8_t game_tiles[GAME_TILES_SIZE];
uint8_t game_sprites[GAME_SPRITES_SIZE];
uint8_t game_proms[GAME_PROMS_SIZE];
uint8_t game_pcm[GAME_PCM_SIZE];
uint8_t game_speech[GAME_SPEECH_SIZE];
uint8_t game_title[GAME_TITLE_SIZE];
