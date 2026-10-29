/**
 *    Name:        system/sound_commands.c
 *    Description: the commands to the sound board, queued and sent one a frame
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint32_t func_009202(uint32_t d6)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	a6 = unk_06001C;
	if (a6 == unk_060018)
		return d6;
	d7 = mem_read8(a6);
	a6++;
	if (a6 > 0x6043Fu)
		a6 = 0x60400u;
	unk_06001C = a6;
	io_write8(IO_0A0009, d7);
	d6 = (d6 & ~0xFFu) | unk_060058;
	d6 = d6 | 8u;
	io_write8(IO_0A0001, d6);
	return d6;
}
