/**
 *    Name:        system/sound_commands.c
 *    Description: the commands to the sound board, queued and sent one a frame
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* queues a sound or a voice for the sound board, when the game lets sounds play; never a music */
void queue_sound(uint8_t d7, uint32_t a6)
{
	if ((dip_switches_3 & 4u) != 0u || game_on != 0u || (((uint8_t)d7 < 0x60u || (uint8_t)d7 > 0x6Bu) && demo_sounds != 0u))
	{
		queue_sound_command(d7);
		return;
	}
}

/* puts a command into the sound board's queue */
void queue_sound_command(uint8_t d7)
{
	uint32_t a6 = 0;

	a6 = sound_queue_write;
	mem_write8(a6, d7);
	a6++;
	if (a6 > sound_queue_ADDRESS + 0x3Fu)
		a6 = sound_queue_ADDRESS;
	sound_queue_write = a6;
}

/* queue_sound with the sound in another register */
void queue_sound_d0(uint8_t d0)
{
	uint8_t d7 = 0;

	d7 = (uint8_t)d0;
	queue_sound(d7, 0u);
}

/* the next sound command to the sound board */
uint32_t send_sound_command(uint32_t d6)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	a6 = sound_queue_read;
	if (a6 == sound_queue_write)
		return d6;
	d7 = mem_read8(a6);
	a6++;
	if (a6 > sound_queue_ADDRESS + 0x3Fu)
		a6 = sound_queue_ADDRESS;
	sound_queue_read = a6;
	io_write8(IO_0A0009, d7);
	d6 = (d6 & ~0xFFu) | board_control;
	d6 = d6 | 8u;
	io_write8(IO_0A0001, d6);
	return d6;
}
