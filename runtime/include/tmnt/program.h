/**
 *    Name:        program.h
 *    Description: the TMNT program as a port runs it: its reset, its run on a stack of its own, the frames it
 *                 makes
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The program runs with frame timing (tmnt/frame.h): it takes no time, and the board moves on to the start of
 *    its next VBLANK when the program has nothing to do. Each time, after the board's VBLANK events (the sprite
 *    DMA, IRQ5), program_frame_done runs: the port applies its controls, takes the frame's hashes, and calls
 *    program_stop when it has had enough.
 */
#ifndef TMNT_PROGRAM_H
#define TMNT_PROGRAM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The CPU as the 68000's reset leaves it, from the program's vectors */
void program_reset(void);

/* Runs the program, on a stack of its own, until program_stop */
void program_run(void);

/* Called by program_frame_done: program_run returns */
void program_stop(void);

/* The port's, on the way to the next frame: VBLANK ends (line 16: the video takes the scroll), VBLANK starts
   (line 240: the frame is drawn, before the board's events), and the frame is done (after them) */
extern void (*program_vblank_end)(void);
extern void (*program_vblank_start)(void);
extern void (*program_frame_done)(void);

/* The frames so far, and the interrupts the program took */
uint64_t program_frames(void);
uint32_t program_interrupts(void);

#ifdef __cplusplus
}
#endif

#endif
