"""
Name:        coverage.py
Description: runs the shared core's coverage.py (tools/core) for this game: every byte of the 68000 program as code, data or fill, and what is still unknown
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

The script is the core's (arcade-decomp, which tools/core holds); tools/game_profile.py tells it about this game.
Its usage is the core's. The bytes the reference read as data come from the scenarios' runs:
  python tools/coverage.py --reads build/scenarios
(kref --rom-reads build/scenarios/NAME/rom_reads.txt for each control script).
"""
import runpy
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
runpy.run_path(str(TOOLS / "core" / "coverage.py"), run_name="__main__")
