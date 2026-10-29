/**
 *    Name:        script.h
 *    Description: scripted controls for test runs: coins, service buttons, the four players' joysticks and
 *                 buttons, DIP switches and memory pokes, applied when VBLANK starts in the frames a text
 *                 script names
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    A run that applies the same script at the same frame boundaries sees the same inputs, so the game and
 *    tools/core/konami/reference/kref stay comparable frame by frame. The format is OutRunners' (its
 *    runtime/include/s32/script.h), with this board's controls.
 *
 *    Script format, one event per line, '#' starts a comment:
 *      FRAME ACTION [ARGUMENTS]        FRAME is a frame number (the VBLANKs before it), or +N for N frames
 *                                      after the previous event
 *      press INPUT [FRAMES]            pressed for FRAMES frames (4 by default), then released
 *      hold INPUT / release INPUT      pressed / released until another event changes it
 *      dip BANK SWITCH on|off          DIP switch 1-8 of bank 1-3 (MAME's SW1-SW3); the test mode is 3 3
 *      poke ADDRESS VALUE              writes a byte through the bus (hexadecimal address and value)
 *      end                             the run ends with this frame
 *    INPUT: coin1-coin4, service1-service4, and for players 1-4 leftN rightN upN downN attackN jumpN
 */
#ifndef TMNT_SCRIPT_H
#define TMNT_SCRIPT_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tmnt_script tmnt_script;

/* NULL if the script cannot be read or parsed; 'error' then says what and where */
tmnt_script *tmnt_script_load(const char *path, char *error, size_t error_size);
void tmnt_script_free(tmnt_script *script);

/* Applies what is due in 'frame': call it when the frame's VBLANK starts, the moment MAME polls the
   controls, with the VBLANKs so far (frame 0 before the program starts) */
void tmnt_script_apply(tmnt_script *script, uint64_t frame);

/* Frames the script asks to run ('end'), or 0 if it does not say */
uint64_t tmnt_script_frames(const tmnt_script *script);

#ifdef __cplusplus
}
#endif

#endif
