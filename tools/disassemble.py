"""
Name:        disassemble.py
Description: runs the shared core's 68000 static analysis (tools/core/m68000/analysis.py) for this game: the
             program's code found without traces, its listing and a report
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

The script is the core's (arcade-decomp, which tools/core holds); tools/game_profile.py tells it about this game.
Its usage is the core's.
"""
import runpy
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
runpy.run_module("m68000.analysis", run_name="__main__")
