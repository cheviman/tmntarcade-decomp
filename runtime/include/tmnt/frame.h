/**
 *    Name:        frame.h
 *    Description: where the TMNT program waits for its next frame, for the tools that run it with frame timing
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The program does a frame's work in its VBLANK handler (003DC4). Its main loop (0013C2-0013DC) runs the jobs
 *    the frames leave in a queue: the pointer at 060014 is the next one, and a negative word there means there is
 *    none. At 0013CE the loop reads that word: when it is negative the program has nothing to do until the next
 *    VBLANK. With frame timing (kref --timing frames, and the translated program, runtime/src/m68000.c)
 *    instructions take no time, and the board moves on to its next frame only there: the frames come where
 *    the program has finished its work, as on a board fast enough never to lag.
 */
#ifndef TMNT_FRAME_H
#define TMNT_FRAME_H

#include "tmnt/machine.h"

#include <stdbool.h>
#include <stdint.h>

#define TMNT_FRAME_WAIT    0x0013CEu    /* move.w (A0), D1: the main loop reads the next job */
#define TMNT_JOB_QUEUE     0x060014u    /* the pointer to it */

/* True when the main loop, at TMNT_FRAME_WAIT, finds no job */
static inline bool tmnt_frame_idle(void)
{
	const uint32_t queue = (uint32_t)tmnt_read16(TMNT_JOB_QUEUE, 0xFFFFu) << 16
		| tmnt_read16(TMNT_JOB_QUEUE + 2u, 0xFFFFu);
	return (tmnt_read16(queue & 0xFFFFFEu, 0xFFFFu) & 0x8000u) != 0;
}

#endif
