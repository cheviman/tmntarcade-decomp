"""
Name:        check_sound_board.py
Description: runs every control script on kref with the game's own sound board beside MAME's, and says how many
             frames differ in each
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

Usage: python tools/check_sound_board.py [NAME ...] [--jobs N] [--bin DIR] [--out DIR]
  NAME      scripts of tests/controls to run (file names without .txt); all of them by default
  --jobs N  scripts at a time (6 by default: half the machine)
  --bin     where kref is (build/bin by default), built with the game's sound program (src/sound/)
  --out     where the runs go (build/sound_check by default)

For each script, kref runs the original 68000 program with MAME's sound board under the game's timing model
(--sound-timing build/sound/timing.txt, which tools/decompile_sound.py writes) and the game's own sound board
beside it (--sound-board-check: the decompiled sound program of src/sound/ on runtime/src/sound_cpu.c and
sound_board.c, with the program's data from assets/), fed the same commands at the same times; per frame the
hashes of the samples of the four sources and of the Z80's RAM (without its stack) are compared, and
OUT/NAME.txt has them ("FRAME REFERENCE_SAMPLES REFERENCE_RAM OWN_SAMPLES OWN_RAM").
"""
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CONTROLS = ROOT / "tests" / "controls"
TIMING = ROOT / "build" / "sound" / "timing.txt"


def run(kref, script, out):
    result = subprocess.run([str(kref), "--script", str(script), "--sound-timing", str(TIMING),
                             "--sound-board-check", str(out / f"{script.stem}.txt"), "--assets", str(ROOT / "assets")],
                            capture_output=True, text=True, cwd=str(ROOT))
    summary = next((line for line in result.stdout.splitlines() if line.startswith("sound board check:")), None)
    frames = next((line.split()[1] for line in result.stdout.splitlines() if line.startswith("frames:")), "?")
    details = [line for line in result.stderr.splitlines() if line.strip()]
    return script.stem, result.returncode, frames, summary, details


def main():
    arguments = sys.argv[1:]
    jobs, bin_dir, out = 6, ROOT / "build" / "bin", ROOT / "build" / "sound_check"
    names = []
    while arguments:
        argument = arguments.pop(0)
        if argument == "--jobs" and arguments:
            jobs = int(arguments.pop(0))
        elif argument == "--bin" and arguments:
            bin_dir = Path(arguments.pop(0))
        elif argument == "--out" and arguments:
            out = Path(arguments.pop(0))
        elif argument.startswith("--"):
            print(__doc__)
            return 1
        else:
            names.append(argument)
    kref = bin_dir / "kref.exe" if (bin_dir / "kref.exe").exists() else bin_dir / "kref"
    if not kref.exists():
        raise SystemExit(f"{kref}: no such file")
    if not TIMING.exists():
        raise SystemExit(f"{TIMING}: no such file")
    scripts = [CONTROLS / f"{name}.txt" for name in names] if names else sorted(CONTROLS.glob("*.txt"))
    out.mkdir(parents=True, exist_ok=True)
    failed = 0
    frames_total = 0
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for name, code, frames, summary, details in pool.map(lambda script: run(kref, script, out), scripts):
            differs = summary is None or not summary.startswith("sound board check: 0 frames")
            failed += differs or code != 0
            frames_total += int(frames) if frames.isdigit() else 0
            print(f"{name:<14} {frames:>7} frames  " + (summary[len('sound board check: '):] if summary else "did not run")
                  + ("" if code == 0 else f"  (exit {code})"))
            for line in details[:12] if differs or code != 0 else []:
                print("    " + line)
    print(f"{len(scripts)} scripts, {frames_total} frames: {len(scripts) - failed} with no frame that differs")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
