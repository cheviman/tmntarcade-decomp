/**
 *    Name:        sound_board.h
 *    Description: the game's own sound board: the decompiled sound program (src/sound/) on its Z80's timing
 *                 model, the YM2151, the K007232, the uPD7759 and the title music
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME's konami/tmnt.cpp (tmnt_audio_map, sres_w, tmnt_upd_start_w, tmnt_upd_busy_r, the
 *    K007232's volume callback, the routes' gains), as tools/core/konami/reference/sound/ksound.cpp runs it
 *    with MAME's own chips: every sample and every byte of the Z80's RAM compare with it (kref
 *    --sound-board-check). No MAME code: the chips are runtime/src/ym2151.c and sound_chips.c.
 *
 *    The game drives it from the board's time (68000 cycles, TMNT_CPU_CLOCK): the 68000's latch is the board
 *    model's (tmnt_board.sound_latch), which the Z80 reads at A000; before the 68000 writes it or raises the
 *    Z80's IRQ, the sound board catches up with the present (tmnt_sound_run); the IRQ stays up until the Z80
 *    takes it, as MAME's HOLD_LINE (tmnt_sound_irq); at the end of a frame the frame's samples close
 *    (tmnt_sound_end_frame). The program's data comes from the game's assets (game/assets.h): the tables by
 *    their names, an address the program holds from the piece it falls in.
 *
 *    The samples: the YM2151 makes one every 64 clocks of the Z80's clock (its two outputs), the K007232 one
 *    every 128 (its two outputs), the uPD7759 one every 4 of its 640 kHz clock, the title music one every 32
 *    of them; sample n of a source is the one it makes from Z80 cycle n x period on. The uPD7759 makes them in
 *    blocks, as MAME's stream does: from where it last stopped up to every access and every frame's end.
 */
#ifndef TMNT_SOUND_BOARD_H
#define TMNT_SOUND_BOARD_H

#include "tmnt/machine.h"
#include "tmnt/sound_chips.h"
#include "tmnt/ym2151.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The Z80's stack (SP starts at 8600; the deepest the program goes in the scenarios is 85F6): the decompiled
   program keeps what the original pushes in its own variables, so the RAM's hash leaves these bytes out, the
   reference's too (ksound.cpp). Nothing else of the program lives in 846C-85FF */
#define TMNT_SOUND_STACK_START   0x8500u
#define TMNT_SOUND_STACK_END     0x8600u

typedef struct
{
	uint8_t ram[TMNT_SOUND_RAM_SIZE];    /* the Z80's, 8000-87FF */
	uint8_t control;                     /* 9000 (sres): what the program last wrote, which it reads back */
	ym2151 fm;
	k007232 pcm;
	upd7759 speech;
	title_music title;
} tmnt_sound_board;

extern tmnt_sound_board tmnt_sound;

/* The sound board at power on, at the board's present (tmnt_board.cycles): its chips on the samples' memories
   (game/data.h's game_pcm, game_speech, game_title), the program's tables from the loaded assets. NULL, or
   what failed (a table the assets have no piece for) */
const char *tmnt_sound_init(void);

/* Hooks it to the board model, for the game: before the 68000 writes the latch or raises the Z80's IRQ
   (tmnt_board.sound_sync and sound_irq), the sound board catches up with the board's present
   (tmnt_board.cycles) */
void tmnt_sound_attach(void);

/* The board's time moves on to 'time': the program runs up to its main loop's top past it */
void tmnt_sound_run(uint64_t time);

/* The 68000 raises the Z80's IRQ (0A0001 bit 3 going low): up until the Z80 takes it */
void tmnt_sound_irq(void);

/* Runs the board up to 'time' and closes the frame's samples: the ones each source starts before it */
void tmnt_sound_end_frame(uint64_t time);

/* FNV-1a hashes of the frame just closed, as kref's --sound-hashes writes them: the samples of the four
   sources (the YM2151's, the K007232's, the uPD7759's, the title music's, each as MAME's floats), and the
   Z80's RAM without its stack */
uint64_t tmnt_sound_samples_hash(void);
uint64_t tmnt_sound_state_hash(void);

/* The frame's samples of each source alone (0 the YM2151, 1 the K007232, 2 the uPD7759, 3 the title music):
   which one differs */
void tmnt_sound_source_hashes(uint64_t hashes[4]);

/* The frame's samples mixed as MAME's routes do (the YM2151's two outputs at 0.40, the K007232's at 0.15,
   the uPD7759 at 0.30, the title music at 0.25, to one speaker) at the YM2151's rate */
const int16_t *tmnt_sound_mix(size_t *count);
uint32_t tmnt_sound_mix_rate(void);

/* The Z80's time: the cycles of the timing model so far */
uint64_t tmnt_sound_z80_cycles(void);

/* The program's data at an address of its program ROM it holds (a pointer into a track, a voice, its random
   bytes): the bytes of the asset piece it falls in. The program stops where no piece is */
const uint8_t *tmnt_sound_data_at(uint32_t address);

#ifdef __cplusplus
}
#endif

#endif
