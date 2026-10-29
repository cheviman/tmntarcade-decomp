"""
Name:        game_profile.py
Description: what the shared decompiler core (tools/core) needs to know of TMNT: where the game is, its ROM set,
             and its settings
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

The core (arcade-decomp: the decompiler, the CPU frontends, the analysis, the checks) is the same for every
game; this module gives it TMNT's: the repository's root, the ROM set's module (tmnt_rom: the regions as the
board has them) and the names the generated files carry. The decompiler's settings for the 68000 program
(its structures, the registers the whole program shares, its variables) come here as the steps that need
them are reached; until then the core's neutral defaults stand.
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent / "core"))

import tmnt_rom as rom  # noqa: E402,F401

ROOT = Path(__file__).resolve().parents[1]
GAME = "Teenage Mutant Ninja Turtles (arcade, Konami 1989)"    # in the generated files' headers
ROM_SET_TITLE = "Teenage Mutant Ninja Turtles (tmnt, World 4 Players, version X)"
CPU = "68000"
BINARY = "tmnt"                                 # its executables: tmnt_game_headless, tmnt_headless
GUARD = "TMNT"                                  # the generated headers' include guards: TMNT_GAME_H...
REFERENCE = "kref"                              # the reference (tools/core/konami/reference)
ANALYSIS = "m68000.analysis"                    # the static analysis and the disassembler of the 68000
DISASSEMBLER = "m68000.disassembler"
CODE_START = 0x1000                             # 000400-000FFF, after the vectors, is all zeros
DATA_WALK = "data_walk"                         # the data the engines read, walked (tools/data_walk.py)
OBJECT_REGISTER = "A0"                          # the object a handler runs on: its fields, for the analysis
TRANSLATOR = "m68000.translate"                 # the translation scaffold (tools/recompile.py) for the 68000
FRAME_WAIT = 0x0013CE                           # the main loop finds no job here: the frame (runtime/include/tmnt/frame.h)
# The game's code the board puts its own in place of (runtime/src/board_code.c): where it starts, the board's
# function, and where the game's code goes on after it. The boot's ROM test sums the program's chips, which
# the game does not have: the board gives what good chips sum to.
REPLACED_CODE = {0x001850: ("sum_rom_chips", 0x00188E)}

# The decompiler (tools/decompile.py: the core's m68000/decompile.py) and the board as the program's C sees it
DECOMPILER = "m68000.decompile"
DECOMPILED = "29-10-2026"                       # when src/ was first written (its files' headers)
WORK_RAM_AREA = (0x060000, 0x064000)
PROGRAM_AREA = (0x000000, 0x060000)
# the board's devices, reached through the bus (their registers by the area's name and address)
HARDWARE = [(0x080000, 0x081000, "PALETTE"), (0x0A0000, 0x0A0020, "IO"), (0x0C0000, 0x0C0002, "PRIORITY"),
            (0x100000, 0x108000, "TILES"), (0x10E800, 0x10E802, "UNMAPPED"), (0x140000, 0x140008, "SPRITE_CONTROL"),
            (0x140400, 0x140800, "SPRITES")]
# reading the K051937 and the K051960 does something (in the sprite ROM's readback mode, the read moves its
# offset): a read there stays where its value goes unused
EFFECT_READ_AREAS = [(0x140000, 0x140800)]
# the board's memories, as game/support.h names them (addresses the code computes into them)
REGIONS = [(0x080000, 0x081000, "PALETTE_RAM"), (0x100000, 0x108000, "TILE_RAM"), (0x140400, 0x140800, "SPRITE_RAM")]
# the VBLANK handler (003DC4) moves its return frame from the supervisor's stack to the user's (move USP, A6 ...
# move A6, USP) and goes on in user mode: the C has no stack, so that stretch is left out
INTERRUPT_STACK_SWITCH = (0x003DE6, 0x003DF4)
# the code that runs in supervisor mode only: the reset (up to 001380's move to SR, which leaves it), the VBLANK
# handler's start (up to its move to SR); a privileged instruction there needs no check of the mode
SUPERVISOR_CODE = ((0x001000, 0x001384), (0x003DC4, 0x003DF8))
NOISE_REGISTERS = r"[da][0-7]"                  # the 68000's: what tools/noise_report.py counts as named after a register
NOTES = {
    "variables": ["/* the game's variables in work RAM (060000-063FFF) */"],
    "scoped": ["/* work RAM as one family of functions uses it */"],
    "tables": ["/* the program's data the code reads by name, which the game loads from its assets */"],
    "hardware": ["/* the board's registers (read and written through the bus) */"],
}

# The Z80 sound program (963e20.g13, 32 KB at 0000-7FFF; the RAM at 8000): the reset and the interrupt (IM 1,
# the 68000's sound command) as on System 32, the program below 8000, and the jumps through registers followed
# by what the registers hold (the driver's channels keep the routine that runs them next in their record)
SOUND_ENTRIES = {0x0000: "func", 0x0038: "func"}
SOUND_CODE_END = 0x8000
SOUND_FOLLOW_VALUES = True
SOUND_DATA_WALK = "sound_data_walk"             # the sound data the driver reads, walked (tools/sound_data_walk.py)
# The decompiled sound program (tools/decompile_sound.py; it runs on runtime/src/sound_cpu.c): the Z80's own RAM
# holds its variables and its channel records, the program ROM its tables, which the game loads by name from its
# assets (src/sound/tables.c); the board's chips are registers on the Z80's bus (runtime/src/sound_board.c)
SOUND_RAM_AREA = (0x8000, 0x8800)
SOUND_ROM_AREA = (0x0000, 0x8000)
SOUND_HARDWARE = [(0x9000, 0x9001, "SOUND_CONTROL"), (0xA000, 0xA001, "SOUND_LATCH"), (0xB000, 0xB00E, "PCM"),
                  (0xC000, 0xC002, "FM"), (0xD000, 0xD001, "SPEECH"), (0xE000, 0xE001, "SPEECH_START"),
                  (0xF000, 0xF001, "SPEECH_BUSY")]
SOUND_NOTES = {
    "variables": ["/* the sound program's variables and channel records, in the Z80's RAM (8000-87FF) */"],
    "scoped": ["/* RAM as one family of functions uses it */"],
    "tables": ["/* data in the program ROM the code reads, which the game loads from its assets */"],
    "hardware": ["/* the board's registers on the Z80's bus: 9000 (sres), the 68000's latch, the K007232, the",
                 "   YM2151 and the uPD7759 (read and written through the bus) */"],
}
SOUND_LOADED_TABLES = True
SOUND_BLOCK_FETCHES = False                     # no LD A,R: the refresh register is never read
SOUND_INTERRUPT_WINDOWS = True                  # the main loop lets the 68000's command in for four NOPs only (EI ... DI)
SOUND_COUNTED_FROM_ONE = True                   # tables read from an element before them: note_lengths[i - 1]
SOUND_KEEP_HARDWARE_READS = True                # reading the K007232's key (B005, B00B) starts its channel: such a read stays
SOUND_NAMES_BEFORE_TABLES = 16                  # the base of a table indexed from past its start: pcm_note_pitches_ADDRESS - 0xCu
SOUND_CREATED = "29-10-2026"                    # when src/sound/ was first written (its files' headers)
