"""
Name:        decompile_sound.py
Description: runs the shared core's decompile_sound.py (tools/core) for this game: the Z80 sound program as
             readable C in src/sound/, with the names of sound_symbols.txt
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

The script is the core's (arcade-decomp, which tools/core holds); tools/game_profile.py tells it about this game
(its SOUND_ settings: the Z80's memory map, the board's chips, the tables the game loads from its assets).
Its usage is the core's:
  python tools/decompile_sound.py            src/sound/ and build/sound/timing.txt (kref --sound-timing)
  python tools/decompile_sound.py --check    what does not lift, and what each function takes and hands back
The C runs on the game's own sound board (runtime/src/sound_cpu.c, sound_board.c).
"""
import runpy
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
runpy.run_path(str(TOOLS / "core" / "decompile_sound.py"), run_name="__main__")
