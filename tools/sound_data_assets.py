"""
Name:        sound_data_assets.py
Description: the Z80 sound program's data as text by name, the music a command a line, and back byte for byte
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

For tools/extract_assets.py, which writes assets/sound_data.txt. Every byte of the sound program that is not
code is in a piece: what sound_symbols.txt describes and the music tools/sound_data_walk.py walks
(tools/core/sound_coverage.py's description), the fill, and what nothing explains (none today). A piece is
written as lines of items, which give its bytes back in order (the Z80 is little endian):

    u8 0x0A 0x00          bytes              u16 0x1234 ...     words
    ref NAME[+0xNN]       the 16-bit address of a piece or of a function (by its sound_symbols.txt name, or
                          sound_XXXX)
    cmd E0 05             a command of a track, its bytes; @NAME[+0xNN] for an address it carries (2 bytes)

and assets/sound_layout.txt says where each piece was (for --check only).
"""
import re
from bisect import bisect_right
from collections import defaultdict
from pathlib import Path

import sound_data_walk

ADDRESS_AT = {0xEC: 4, 0xF1: 2, 0xF6: 2, 0xF8: 1, 0xFA: 1, 0xF0: 1}    # a track command's address, and where


def description(image):
    """The core's sound coverage's description of the program (sound_symbols.txt and the music's walk)"""
    import sound_coverage
    program = sound_coverage.analysis.load_program(image, sound_coverage.SYMBOLS)
    names = sound_coverage.disassemble.load_names(sound_coverage.SYMBOLS, sound_coverage.REGISTERS)
    tables, fills = sound_coverage.load_lines(sound_coverage.SYMBOLS)
    return program, sound_coverage.Description(program, names, tables, fills)


class Names:
    def __init__(self, pieces, functions):
        self.starts = sorted(pieces)
        self.pieces = pieces                    # start -> (stop, name)
        self.functions = functions              # address -> name
        self.addresses = {name: start for start, (_, name) in pieces.items()}
        self.addresses.update({name: address for address, name in functions.items()})

    def name(self, value):
        if value in self.functions:
            return self.functions[value]
        index = bisect_right(self.starts, value) - 1
        if index >= 0:
            start = self.starts[index]
            stop, name = self.pieces[start]
            if start <= value < stop:
                return name if value == start else f"{name}+0x{value - start:X}"
        return None

    def value(self, text, where):
        base, _, offset = text.partition("+")
        if base not in self.addresses:
            raise SystemExit(f"{where}: no piece or function named {base}")
        return self.addresses[base] + (int(offset, 16) if offset else 0)


def pieces_of(image, program, described):
    """[(name, kind, first, stop)] of every byte that is no code, in order (the music's runs merged by track)"""
    code = set()
    for address, instruction in program.analysis.instructions.items():
        code.update(range(address, address + instruction.length))
    found, taken = [], set()
    # code the program also reads as data (codedata lines: the main loop sums 0000-00FF into its random bytes):
    # a piece of its own, code bytes and all, which the C reads where the program's pointer says
    for piece in described.pieces:
        if getattr(piece, "code_read", False):
            span = range(piece.first, min(piece.stop, len(image)))
            found.append((piece.name, piece.kind, piece.first, span.stop))
            taken.update(span)
    for piece in sorted(described.pieces, key=lambda piece: (piece.first, piece.stop)):
        bytes_free = [address for address in range(piece.first, min(piece.stop, len(image)))
                      if address not in code and address not in taken]
        if not bytes_free:
            continue
        run = [bytes_free[0]]
        for address in bytes_free[1:] + [None]:
            if address is not None and address == run[-1] + 1:
                run.append(address)
                continue
            kind = piece.kind
            name = piece.name if run[0] == piece.first else f"{piece.name}_{run[0]:04X}"
            found.append((name, kind, run[0], run[-1] + 1))
            taken.update(run)
            if address is not None:
                run = [address]
    rest = [address for address in range(program.code_end) if address not in code and address not in taken]
    run = []
    for address in rest + [None]:
        if run and (address is None or address != run[-1] + 1):
            found.append((f"unexplained_{run[0]:04X}", "unexplained", run[0], run[-1] + 1))
            run = []
        if address is not None:
            run.append(address)
    names = defaultdict(int)
    unique = []
    found = [(re.sub(r"[^0-9A-Za-z_]+", "_", name).strip("_"), kind, first, stop) for name, kind, first, stop in found]
    for name, kind, first, stop in sorted(found, key=lambda piece: piece[2]):
        names[name] += 1
        unique.append((name if names[name] == 1 else f"{name}_{first:04X}", kind, first, stop))
    return unique


def write_piece(image, kind, first, stop, names):
    lines = []
    if kind.startswith("music"):
        place = first
        while place < stop:
            command = image[place]
            length = 1
            if command >= 0xE0:
                if command == 0xE5:
                    length = sound_data_walk.Walk.held_note(type("held", (), {"image": image, "code_end": stop})(), place)
                elif command in sound_data_walk.FIXED:
                    length = sound_data_walk.FIXED[command]
                elif command in sound_data_walk.JUMPS:
                    length = sound_data_walk.JUMPS[command][0]
                elif command in sound_data_walk.CALLS:
                    length = sound_data_walk.CALLS[command][0]
                elif command == 0xF0:
                    length = 3
            length = max(1, min(length, stop - place))
            items = []
            at = 0
            while at < length:
                offset = ADDRESS_AT.get(command)
                if offset is not None and at == offset and at + 2 <= length:
                    target = image[place + at] | image[place + at + 1] << 8
                    name = names.name(target)
                    items.append(f"@{name}" if name else f"{image[place + at]:02X} {image[place + at + 1]:02X}")
                    at += 2
                else:
                    items.append(f"{image[place + at]:02X}")
                    at += 1
            lines.append("cmd " + " ".join(items))
            place += length
    elif kind == "code addresses":
        for at in range(first, stop - 1, 2):
            value = image[at] | image[at + 1] << 8
            name = names.name(value)
            lines.append(f"ref {name}" if name else f"u16 0x{value:04X}")
        if (stop - first) % 2:
            lines.append(f"u8 0x{image[stop - 1]:02X}")
    elif kind.startswith("u16"):
        values = [f"0x{image[at] | image[at + 1] << 8:04X}" for at in range(first, stop - 1, 2)]
        lines += ["u16 " + " ".join(values[at:at + 8]) for at in range(0, len(values), 8)]
        if (stop - first) % 2:
            lines.append(f"u8 0x{image[stop - 1]:02X}")
    else:
        values = [f"0x{byte:02X}" for byte in image[first:stop]]
        lines += ["u8 " + " ".join(values[at:at + 16]) for at in range(0, len(values), 16)]
    return lines


def read_piece(lines, names, where):
    out = bytearray()
    for number, line in enumerate(lines):
        here = f"{where}, line {number + 1}"
        token, _, rest = line.partition(" ")
        parts = rest.split()
        if token == "u8":
            out += bytes(int(value, 16) for value in parts)
        elif token == "u16":
            out += b"".join(int(value, 16).to_bytes(2, "little") for value in parts)
        elif token == "ref":
            out += names.value(parts[0], here).to_bytes(2, "little")
        elif token == "cmd":
            for part in parts:
                out += names.value(part[1:], here).to_bytes(2, "little") if part.startswith("@") else bytes([int(part, 16)])
        else:
            raise SystemExit(f"{here}: '{token}' is no item of a piece")
    return bytes(out)


def function_names(program):
    found = {address: symbol.name for address, symbol in program.symbols.items() if symbol.kind in ("func", "code", "loop")}
    for address in program.analysis.instructions:
        pass
    for address in getattr(program, "entries", {}) or {}:
        found.setdefault(address, f"sound_{address:04X}")
    return found


def extract(image, out):
    program, described = description(image)
    pieces = pieces_of(image, program, described)
    functions = function_names(program)
    names = Names({first: (stop, name) for name, _, first, stop in pieces}, functions)
    lines = ["# the sound program's data: its pieces by name"]
    layout = ["# each piece and where the sound program had it (for --check)"]
    for name, kind, first, stop in pieces:
        lines.append(f"[{name}]  # {kind}")
        lines += ["  " + line for line in write_piece(image, kind, first, stop, names)]
        layout.append(f"{name} {first:04X}")
    (out / "sound_data.txt").write_text("\n".join(lines) + "\n", encoding="ascii")
    (out / "sound_layout.txt").write_text("\n".join(layout) + "\n", encoding="ascii")
    (out / "sound_functions.txt").write_text("# the sound program's places in its code the data names, and their addresses\n"
                                             + "".join(f"{name} {address:04X}\n" for address, name in sorted(functions.items())),
                                             encoding="ascii")
    return len(pieces)


def check(image, out):
    program, _ = description(image)
    layout = {}
    for line in (out / "sound_layout.txt").read_text(encoding="ascii").splitlines():
        if line and not line.startswith("#"):
            name, address = line.split()
            layout[name] = int(address, 16)
    texts, current = {}, None
    for line in (out / "sound_data.txt").read_text(encoding="ascii").splitlines():
        if line.startswith("["):
            current = line[1:line.index("]")]
            texts[current] = []
        elif line.startswith("  ") and current:
            texts[current].append(line.strip())
    names = Names({address: (address, name) for name, address in layout.items()}, function_names(program))
    problems = []
    for name, address in layout.items():
        data = read_piece(texts.get(name, []), names, f"sound_data.txt [{name}]")
        if image[address:address + len(data)] != data:
            problems.append(f"the sound program's {name} does not come back")
    return problems[:20]
