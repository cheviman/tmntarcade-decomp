"""
Name:        sound_coverage.py
Description: runs the shared core's sound_coverage.py (tools/core) for this game: every byte of the Z80 sound program as code, described data or fill, and what is still unknown
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

The script is the core's (arcade-decomp, which tools/core holds); tools/game_profile.py tells it about this game
(its SOUND_ settings, and SOUND_DATA_WALK: tools/sound_data_walk.py walks the music). Its usage is the core's.
What the reference executed and read as data comes from the scenarios' runs:
  python tools/sound_coverage.py --trace build/scenarios --reads build/scenarios
(kref --sound-trace build/scenarios/NAME/sound_executed.txt and --sound-rom-reads
build/scenarios/NAME/sound_rom_reads.txt for each control script).
"""
import runpy
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
runpy.run_path(str(TOOLS / "core" / "sound_coverage.py"), run_name="__main__")
