"""
Name:        decompile.py
Description: runs the shared core's decompile.py (tools/core) for this game: the 68000 program as readable C in
             src/, with the names of symbols.txt
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

The script is the core's (arcade-decomp, which tools/core holds); tools/game_profile.py tells it about this game
(DECOMPILER: the 68000's driver, m68000/decompile.py; the board's memory map, its interrupt handler's frame).
Its usage is the core's:
  python tools/decompile.py            src/ (game.h, ram.h, table.c and the functions' files)
  python tools/decompile.py --check    what does not lift
The C runs on the game's runtime (runtime/src/game_cpu.c), with its data from the assets.
"""
import runpy
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
runpy.run_path(str(TOOLS / "core" / "decompile.py"), run_name="__main__")
