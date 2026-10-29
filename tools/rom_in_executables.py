"""
Name:        rom_in_executables.py
Description: looks for the ROM set's content in the built executables: none of the game's may hold any
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

Usage: py tools/rom_in_executables.py [EXECUTABLE ...]   (default: the game's in build/bin)

Every 32-byte stretch of each region of the ROM set (rom/), at every 32nd byte, is looked for in the
executables, as the files have it and as the board lays it out (the program's words, the graphics' planes); a
stretch any binary could hold (almost all one byte, up to three runs of two bytes, or bytes or 16-bit words in
an arithmetic progression) is left out. Prints, for each executable, how many stretches of each region it
holds; the game's must hold none.
"""
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import tmnt_graphics  # noqa: E402
import tmnt_rom  # noqa: E402

SPAN = 32
GAME = ["tmnt_game_headless.exe", "tmnt_headless.exe", "tmnt.exe"]


def trivial(chunk):
    """Almost one byte over and over (all but 4 of them: a run of padding with a value at an edge), up to three
    runs of two bytes (zeros, ones, zeros), or bytes or 16-bit words in an arithmetic progression."""
    if max(chunk.count(value) for value in set(chunk)) >= len(chunk) - 4:
        return True
    if len(set(chunk)) == 2 and sum(1 for index in range(1, len(chunk)) if chunk[index] != chunk[index - 1]) <= 2:
        return True
    steps = {(chunk[index + 1] - chunk[index]) & 0xFF for index in range(len(chunk) - 1)}
    if len(steps) == 1:
        return True
    for order in "<>":
        words = struct.unpack(f"{order}{len(chunk) // 2}H", chunk)
        if len({(words[index + 1] - words[index]) & 0xFFFF for index in range(len(words) - 1)}) == 1:
            return True
    return False


def main():
    paths = [Path(argument) for argument in sys.argv[1:]] or \
        [ROOT / "build" / "bin" / name for name in GAME if (ROOT / "build" / "bin" / name).exists()]
    rom = tmnt_rom.load_set(ROOT / "rom")
    proms = tmnt_rom.build_proms(rom)
    tiles, sprites = tmnt_rom.build_tiles(rom), tmnt_rom.build_sprites(rom)
    regions = {"program": tmnt_rom.build_program(rom), "sound": tmnt_rom.build_sound(rom), "tiles": tiles,
               "tiles (planar)": tmnt_graphics.tiles_for_chips(tiles), "sprites": sprites,
               "sprites (planar)": tmnt_graphics.sprites_for_chips(sprites, proms), "pcm": tmnt_rom.build_pcm(rom),
               "speech": tmnt_rom.build_speech(rom), "title": tmnt_rom.build_title(rom)}
    failed = False
    for path in paths:
        data = path.read_bytes()
        windows = {data[at:at + SPAN] for at in range(len(data) - SPAN + 1)}
        found = {}
        for name, region in regions.items():
            count = 0
            for at in range(0, len(region) - SPAN + 1, SPAN):
                chunk = bytes(region[at:at + SPAN])
                if not trivial(chunk) and chunk in windows:
                    count += 1
            found[name] = count
        failed |= any(found.values())
        print(f"{path.name}: " + ", ".join(f"{name} {count}" for name, count in found.items())
              + " stretches of the ROM set")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
