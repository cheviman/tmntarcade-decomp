# Teenage Mutant Ninja Turtles — decompilation

A reconstruction of Konami's 1989 arcade game *Teenage Mutant Ninja Turtles* (a 68000 main board with a Z80
sound board) into platform-agnostic C, not an emulator, following the method of
[segasonic-decomp](https://github.com/cheviman/segasonic-decomp) and
[outrunners-decomp](https://github.com/cheviman/outrunners-decomp): the game's program decompiled one
function at a time, checked frame by frame against MAME in picture and sound.

**Work in progress.** This repository will contain no game data. As with
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
- [x] Every byte of the program classified (`python tools/coverage.py --reads build/scenarios`, the core's,
      with the bytes the scenarios read as data: `kref --rom-reads`): 32.4% code, 65.8% data,
      1.6% fill, and 242 bytes (0.06%) not explained yet
- [x] The data the engines read, walked from where the code hands it over (`python tools/data_walk.py
      --reads build/scenarios`, no traces): the sprite engine's animations, sprite lists and boxes, the
      areas' layer maps and blocks, the palettes and their effects, the enemies' spawn lists and
      definitions, the texts, the scroll's segments, the attract mode's demos, and the tables the code reads
      by an index or through a register
- [ ] Every table of data described with its layout, its types and a name by subject, before any C is
      generated: the C reads the game's data by name from its first build, never by an address of the ROM
      (today 242 bytes are unexplained, and the tables the code loads with lea have no shape yet)
- [x] The sound program classified the same way (`python tools/sound_coverage.py --trace build/scenarios
      --reads build/scenarios`): its analysis finds the 4,481 addresses the scenarios run without traces, and
      every byte is code (35.6%), described data (64.3%: the driver's tables and the music) or fill
- [x] Assets extracted (`python tools/extract_assets.py`, into `assets/`, outside the repository) and checked
      byte for byte against the ROM set (`--check`): tilesets by area and sprite sheets by the animations
      that show them (indexed PNGs that keep each pen), the title music, the K007232's samples and the
      uPD7759's speech (WAV), and the data of both programs as text by subject, every piece by name
- [ ] The assets by theme throughout: tiles no area uses yet are in sheets by bank, the music is text (not
      MIDI yet), and many pieces are named by their kind and place
- [x] The 68000's instructions lifted to the decompiler's IR (`tools/core/m68000/lift.py`), checked
      against MAME's 68000 core one instruction at a time from random states (`python
      tools/core/konami/reference/compare_lift_with_mame.py --c`): every opcode of the program and every
      valid opcode of the 68000 leave the same registers, flags and bus cycles, in the IR and in the C
- [x] Translation scaffold (`python tools/recompile.py`): the program as C an instruction at a time, run by
      the board in C; the game's own video (`runtime/src/video.c`) and sound chips (`runtime/src/ym2151.c`,
      `sound_chips.c`) match MAME's frame for frame and sample for sample (`kref --video-check`,
      `--sound-check`)
- [x] The game runs from its assets (`runtime/src/assets.c`, `kref --assets-check`: every byte comes back),
      opening no ROM: all 17 scenarios match the reference frame by frame in state and picture
      (`python tools/check_scenarios.py --native-only --translated --video`), the window port (`tmnt`,
      SDL2) gives the same frames from a script, and no executable of the game holds a stretch of the ROM
      set (`python tools/rom_in_executables.py`)
- [x] The sound program decompiled (`python tools/decompile_sound.py`, into `src/sound/`: 381 functions, no
      goto, its tables read by name from the assets) and run by the game's own sound board
      (`runtime/src/sound_cpu.c`, `sound_board.c`) on the Z80's timing model, which the reference follows
      too: its samples and RAM match MAME's sound board in every frame of the 17 scenarios (`python
      tools/check_sound_board.py`, 241,282 frames), and the game matches the reference in state, picture
      and sound in all 17 (`python tools/check_scenarios.py --translated --video --sound`), in the window
      port too
- [x] The 68000 program decompiled (`python tools/decompile.py`, the core's 68000 driver, into `src/`): one C
      function for each of the program's 2,059, no goto, the stack, the return addresses and the status
      register's flags gone into the C's own calls and variables; the tables it reads by name (393) loaded
      from the assets, the data it reaches through the addresses it keeps resolved through the assets, never
      the ROM. The game runs it on its own runtime (`runtime/src/game_program.c`: the frame, the interrupts,
      the tables), and matches the reference in state, picture and sound in all 17 scenarios (`python
      tools/check_scenarios.py --native-only --video --sound`), in the window port too; the structure of
      every function, the code no scenario runs included, checks against its jumps (`python
      tools/check_structure.py build/structure_check`: 0 problems), and no executable holds a stretch of the
      ROM set. The work RAM the comparisons leave out is what the 68000 itself keeps there and the C has in
      its variables: the two stacks (060700-060AFF) and the registers the VBLANK handler saves (060440-06047B)
- [ ] The C readable: names for the functions, the variables and the objects' fields, the objects as
      structures, a comment for each function, files by subject (today 1,987 functions and 4,207 variables
      are named after their address, and the objects' fields are read through the bus: `python
      tools/noise_report.py`)

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

The game and the reference tools (for working on the decompilation: they run the original program on MAME's
cores) need CMake 3.20 or newer and a C11 and C++20 compiler (Visual Studio 2026 on Windows). The game's data
is its assets, which the extractor writes from your ROM set:

```bash
python tools/extract_assets.py
```


```bash
cmake -S . -B build/msvc
```

```bash
cmake --build build/msvc --config Release --parallel 6
```

The game, with no screen (`tmnt_game_headless`, hashes of every frame) or in a window (`tmnt`, with SDL2):

```bash
build/bin/tmnt_game_headless --script tests/controls/attract.txt --hashes build/attract.txt
```

```bash
build/bin/tmnt
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
tools/coverage.py          every byte of the program as code, data or fill: build/listing/coverage.txt
tools/data_walk.py         the data the engines read, walked from the code: build/listing/data_walk.txt
tools/sound_coverage.py    every byte of the sound program as code, data or fill (the core's)
tools/extract_assets.py    the assets from the ROM set, and --check back (tmnt_graphics, sound_assets,
                           data_assets, sound_data_assets)
tools/decompile.py         the 68000 program as C into src/ (the core's m68000/decompile.py)
tools/decompile_sound.py   the Z80 sound program as C into src/sound/
tools/check_structure.py   every function's ifs, loops and switches run against its jumps
tools/noise_report.py      what the C still has of the CPU and of the ROM's places, against tools/noise_baseline.txt
src/                the decompiled C (generated: change the tools or symbols.txt, not the C)
runtime/src/game_program.c the runtime of the decompiled program: the frame, the interrupts, the tables by name
runtime/replaced.txt       the program's functions the board puts its own in place of (the boot's ROM test)
ports/              the game with no screen (headless, for the checks) and in a window (sdl2)
sound_symbols.txt          the sound program's names, and what its analysis cannot work out alone
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
