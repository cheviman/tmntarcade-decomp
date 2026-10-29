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
STATIC_ANALYSIS = False                         # the 68000 frontend and its analysis are still to come
