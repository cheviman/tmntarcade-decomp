# Teenage Mutant Ninja Turtles — decompilation

A reconstruction of Konami's 1989 arcade game *Teenage Mutant Ninja Turtles* (a 68000 main board with a Z80
sound board) into platform-agnostic C, not an emulator, following the method of
[segasonic-decomp](https://github.com/cheviman/segasonic-decomp) and
[outrunners-decomp](https://github.com/cheviman/outrunners-decomp): the game's program decompiled one
function at a time, checked frame by frame against MAME in picture and sound.

**Work in progress: just started.** This repository will contain no game data. As with
[n64decomp/sm64](https://github.com/n64decomp/sm64), you bring your own ROM set (MAME's `tmnt`), and the
tools verify it, extract the assets and build your own executable.

## Status

- [x] ROM set verification (MAME set `tmnt`, World 4 Players, version X), by CRC32 and SHA-1 of every file
- [x] The board model in C (`runtime/`): the 68000's memory map, the inputs and DIP switches, IRQ5 on VBLANK,
      the K052109's and K051960's memories and registers, and their ROMs read through them
- [x] Reference run of the original program on MAME's 68000 core against that model (`kref`): it boots,
      passes its RAM and ROM check, runs the attract mode, and in the test mode passes its mask ROM check
      (the tile and sprite ROMs read through the video chips); the same frame by frame from one run to the
      next
- [x] The reference's picture: MAME's own tilemap, drawgfx and palette code with its K052109 and K051960
      drawing every frame (`kref --video-hashes`, `--video-dump`), as MAME's `tmnt.cpp` draws them
- [x] The reference's sound: the sound board on the board model (`runtime/src/sound.c`), with MAME's Z80,
      K007232 and uPD7759, ymfm's YM2151 and the title music (`kref --sound-hashes`, `--sound-wav`,
      `--sound-trace`): each source's samples at its own rate, the same from one run to the next
- [x] Scenarios (`tests/controls/`, written by `tools/make_scenarios.py`, the format in
      `runtime/include/tmnt/script.h`): the attract mode; the test mode through every screen, every input
      pressed in its I/O test; its sound test through all 135 codes; games of one player (to GAME OVER, and
      one that continues) and of four; one with the DIP switches changed (the screen flipped among them);
      and a four-player game in each of the program's ten areas, started there by a poke and with the lives
      kept up, four of them played until the boss falls and the next area starts. All 17 run to their end,
      and between them they execute 20,197 addresses of the 68000 program and 4,481 of the Z80's
      (`python tools/check_scenarios.py --reference-only --video --sound`)
- [ ] The rest of the game in scenarios: the bosses of five areas and the ending (the scripted players do
      not beat Shredder)
- [x] 68000 frontend in the shared core (`tools/core/m68000/`): decoder and disassembler ported from MAME's,
      the same text as MAME's at every even offset of the program and of an image of every opcode
      (`python tools/core/konami/reference/compare_m68k_with_mame.py`), with each instruction's operands
      and control flow
- [x] Recursive disassembly without traces (`python tools/disassemble.py`, the core's 68000 analysis, from
      the vectors and `symbols.txt`): it follows what the address registers can hold into the tables of
      object handlers the program jumps through, and finds 27,892 instructions, all 20,197 addresses the
      scenarios execute among them and none of them inside another instruction
- [ ] Every byte of the program classified as code, data or fill
- [ ] Translation scaffold, the board model in C, and a window port (SDL2) that matches the reference
- [ ] Decompiler: the program as C with no goto and nothing of the CPU left in it
- [ ] Assets extracted into common formats (PNG, MIDI, WAV, text), which the game loads by name

## Getting started

Requirements: Python 3.10 or newer, and git (and for the reference tools, CMake and a compiler: below).

```bash
git clone --recursive https://github.com/cheviman/tmntarcade-decomp
```

The decompiler and the analysis are in [arcade-decomp](https://github.com/cheviman/arcade-decomp), which this
repository keeps in `tools/core` as a git submodule (a clone made without `--recursive` takes it with
`git submodule update --init`).

Put your own copy of MAME's `tmnt` set in `rom/` (the .zip as is, or its files), and check it:

```bash
python tools/verify_rom.py
```

| File | Size | CRC32 | What it holds |
|---|---|---|---|
| `963-x23.j17`, `963-x24.k17` | 128 KB each | `a9549004`, `e5cc9067` | 68000 program, 0x00000-0x3FFFF (even, odd bytes) |
| `963-x21.j15`, `963-x22.k15` | 64 KB each | `5789cf92`, `0a74e277` | 68000 program, 0x40000-0x5FFFF (even, odd bytes) |
| `963e20.g13` | 32 KB | `1692a6d6` | Z80 sound program |
| `963a28.h27`, `963a29.k27` | 512 KB each | `db4769a8`, `8069cd2e` | tile graphics (K052109) |
| `963a17.h4`, `963a15.k4`, `963a18.h6`, `963a16.k6` | 512 KB each | `b5239a44`, `1f324eed`, `dd51adef`, `d4bd9984` | sprite graphics (K051960) |
| `963a30.g7`, `963a31.g19` | 256 bytes each | `abd82680`, `f8004a1c` | sprite address decoder, priority PROMs |
| `963a26.c13` | 128 KB | `e2ac3063` | K007232 samples |
| `963a27.d18` | 128 KB | `2dfd674b` | uPD7759 speech |
| `963a25.d5` | 512 KB | `fca078c7` | title music sample |

The reference tools (for working on the decompilation: they run the original program on MAME's cores) need
CMake 3.20 or newer and a C11 and C++20 compiler (Visual Studio 2026 on Windows):

```bash
cmake -S . -B build/msvc
```

```bash
cmake --build build/msvc --config Release --parallel 6
```

```bash
build/bin/kref --frames 3600 --hashes build/kref/hashes.txt --text 3000
```

```bash
build/bin/kref --frames 3600 --video-hashes build/kref/video_hashes.txt --video-dump 1200 2400 --video-dir build/kref
```

```bash
build/bin/kref --frames 3600 --sound-hashes build/kref/sound_hashes.txt --sound-wav build/kref/attract.wav
```

## Layout

```
rom/                your ROM set (not in the repository)
runtime/            the board as the program sees it (tmnt/machine.h), and the reader of the ROM set
tools/core/         arcade-decomp, the shared core (git submodule); its konami/reference/ holds kref
tools/game_profile.py   what the core needs to know of this game
tools/tmnt_rom.py   the ROM set: its files by hash, and the regions as the board lays them out
tools/verify_rom.py the ROM set's check (the core's script)
tools/check_scenarios.py   every control script on the reference, and the static analysis against them
tools/disassemble.py       the static analysis: build/listing/tmnt.s and report.txt (the core's)
symbols.txt         the program's names, and what the static analysis cannot work out alone
tools/make_scenarios.py    writes the control scripts
tests/controls/     the control scripts
```

## Legal

The code in this repository is under the BSD 3-Clause License (see `LICENSE`). It contains no ROM data, no
assets extracted from the ROM, and no code of the original game other than the decompiled C. MAME's
`tmnt.cpp`, `k052109.cpp` and `k051960.cpp` (BSD-3-Clause) are the source of the ROM set's layout and of the
board model's behavior. MAME's and ymfm's own code is in arcade-decomp's reference tools only, under their
licenses.

*Teenage Mutant Ninja Turtles* is a trademark of its owner, and the arcade game is Konami's. This project
is not affiliated with or endorsed by either.
