"""
Name:        extract_assets.py
Description: TMNT's assets from the player's ROM set into common formats, by subject, and back byte for byte
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

Usage: python tools/extract_assets.py [rom folder or .zip] [--check] [--out FOLDER]   (assets/ by default)

Writes the assets the game loads (none of them goes into the repository):
  tiles/    the K052109's tiles in tilesets by area: the tiles an area's layers (their maps' blocks, with the
            area's tile banks) and its fire use, each in the first area that uses it; the ones no area's
            layers use yet, in sheets by their bank. 8-bit indexed PNGs, 16 tiles a row: a pixel is the
            tile's pen plus 16 times the palette it shows with (the area's layer A palettes, then layer B's),
            so the pens come back as they are. tilesets.txt lists each sheet's tile codes, in its order.
  sprites/  the K051960's 16 x 16 sprites in sheets by the animations that show them (the function whose code
            names the animation or its table), each sprite in the first sheet that uses it; the ones no
            animation shows, by their bank. The same PNGs, with area 0's sprite palettes. sprites.txt lists
            each sheet's codes.
  sounds/   the title music, the K007232's samples and the uPD7759's speech as WAV files (tools/sound_assets.py)
  data/     the 68000 program's data, every piece by name, as text by subject (tools/data_assets.py)
  sound_data.txt  the Z80 sound program's data by name, the music a command a line (tools/sound_data_assets.py)
With --check, the tile, sprite and sample ROM files are rebuilt from the assets and compared with the set's,
byte for byte (nothing is written).
"""
import sys
from collections import defaultdict
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
import game_profile  # noqa: E402  (the game's: its root, its ROM set)
import asset_formats  # noqa: E402  (the core's PNG reader and writer)
import data_assets  # noqa: E402
import data_walk  # noqa: E402
import sound_assets  # noqa: E402
import sound_data_assets  # noqa: E402
import tmnt_graphics as graphics  # noqa: E402
from m68000 import analysis as m68000_analysis  # noqa: E402

ROOT = game_profile.ROOT
rom = game_profile.rom
TILES = 0x100000 // graphics.TILE_BYTES
SPRITES = 0x200000 // graphics.SPRITE_BYTES
COLUMNS = 16
AREAS = 10
OTHER_BANK = 1024           # the tiles and sprites no subject claims go in sheets of this many codes
SPRITE_PALETTES = 256       # the sprites' palettes start at this palette RAM entry (colour base 16)
LAYER_PALETTES = (512, 640)  # layer A's and layer B's (colour bases 32 and 40)
# the sprite sizes (top 3 bits of a sprite list entry): cells across and down, and each cell's code offset
SPRITE_WIDTH = (1, 2, 1, 2, 4, 2, 4, 8)
SPRITE_HEIGHT = (1, 1, 2, 2, 2, 4, 4, 8)
X_OFFSET = (0, 1, 4, 5, 16, 17, 20, 21)
Y_OFFSET = (0, 2, 8, 10, 32, 34, 40, 42)


def ranges(codes):
    """'0010-001F 0123' for the codes in order"""
    parts = []
    for code in codes:
        if parts and parts[-1][1] + 1 == code:
            parts[-1][1] = code
        else:
            parts.append([code, code])
    return " ".join(f"{first:04X}" if first == last else f"{first:04X}-{last:04X}" for first, last in parts)


def parse_ranges(text):
    codes = []
    for part in text.split():
        first, _, last = part.partition("-")
        codes.extend(range(int(first, 16), int(last or first, 16) + 1))
    return codes


# ---- the palettes the sheets show with ----

def palette_ram(walk, area, bank_addresses):
    """The palette RAM's colours (1024 of (red, green, blue)) the area's palette set gives, banks 0-3"""
    mem = walk.mem
    colours = [(0, 0, 0)] * 1024
    bases = [(mem.r32(bank_addresses + 4 * bank) - 0x80000) // 2 for bank in range(4)]
    palette_set = mem.r32(walk.places["area_palettes"] + 4 * area)
    for bank in range(4):
        listed = mem.r32(palette_set + 4 * bank)
        if not listed:
            continue
        count = (mem.r8(walk.places["palette_bank_counts"] + bank) + 1) * (2 if bank == 3 else 1)
        for index in range(count):
            palette = mem.r32(listed + 4 * index)
            for colour in range(16):
                value = mem.r16(palette + 2 * colour)
                entry = bases[bank] + 16 * index + colour
                if entry < 1024:
                    colours[entry] = asset_formats.rgb555(value)
    return colours


def sheet_palette(colours, base):
    """256 entries: 16 palettes from the palette RAM entry 'base' on"""
    return [colours[(base + entry) % 1024] for entry in range(256)]


# ---- what uses which tile and sprite ----

def area_tiles(walk):
    """{area: [(tile code, palette 0-15)] in the order the area's blocks use them}"""
    mem = walk.mem
    banks_table = walk.places["area_tile_banks"]
    found = {}
    blocks_of = {}
    for first, (stop, kind) in walk.spans.items():
        if kind.startswith("layer blocks"):
            blocks_of[first] = (stop, 33 if "floor" in kind else 17)
    table = walk.places["area_layers"]
    for area in range(AREAS):
        registers = (mem.r8(banks_table + 2 * area), mem.r8(banks_table + 2 * area + 1))
        bank_regs = (registers[0] & 0x0F, registers[0] >> 4, registers[1] & 0x0F, registers[1] >> 4)
        record = table + 36 * area
        uses = []
        layers = [(mem.r32(record + 0x14), 0), (mem.r32(record + 0x1C), 1)]
        if area in (0, 1):
            layers.append((walk.places["fire_blocks"], 1))
        for blocks, layer in layers:
            stop, size = blocks_of.get(blocks, (blocks, 17))
            for block in range(blocks, stop - size + 1, size):
                attribute = mem.r8(block)
                tiles = range(block + size - 16, block + size)
                bank = bank_regs[(attribute & 0x0C) >> 2]
                colour = (attribute & 0xF3) | ((bank & 3) << 2)
                for at in tiles:
                    code = mem.r8(at) | ((colour & 3) << 8) | ((colour & 0x10) << 6) | ((colour & 0x0C) << 9) \
                        | ((bank >> 2) << 13)
                    uses.append((code, 8 * layer + ((colour & 0xE0) >> 5)))
        found[area] = uses
    return found


def animation_groups(walk, analysis):
    """{group name: [(sprite code, colour)]}: the sprites of the animations each function names"""
    functions = sorted(analysis.functions | {address for address, symbol in analysis.symbols.items()
                                             if symbol.kind == "func"})
    names = {address: symbol.name for address, symbol in analysis.symbols.items()}
    from bisect import bisect_right

    def function_of(address):
        index = bisect_right(functions, address) - 1
        start = functions[index] if index >= 0 else 0
        return names.get(start, f"func_{start:06X}")

    namer = {}
    for address, instruction in analysis.instructions.items():
        for value in m68000_analysis.data_places(instruction):
            namer.setdefault(value & 0xFFFFFF, function_of(address))
    owner = {}
    for table, (depth, entries) in walk.tables.items():
        for entry in entries:
            owner.setdefault(entry, namer.get(table, "unnamed"))
    groups = defaultdict(list)
    for animation in sorted(walk.animations):
        group = namer.get(animation) or owner.get(animation) or "unnamed"
        read = walk.frames(animation)
        if read is None:
            continue
        for first, length, kind in read[0]:
            if kind != "animation frame":
                continue
            listed = walk.mem.r32(first + 2)
            for sprite in range(walk.mem.r8(first + 1) + 1):
                entry = listed + 8 * sprite
                head, low, colour = walk.mem.r8(entry), walk.mem.r8(entry + 1), walk.mem.r8(entry + 2)
                code = ((head & 0x1F) << 8 | low) | ((colour & 0x10) << 9)
                size = head >> 5
                width, height = SPRITE_WIDTH[size], SPRITE_HEIGHT[size]
                for mask, limit in ((0x01, 2), (0x02, 2), (0x04, 4), (0x08, 4), (0x10, 8), (0x20, 8)):
                    if (mask in (0x01, 0x04, 0x10) and width >= limit) or (mask in (0x02, 0x08, 0x20) and height >= limit):
                        code &= ~mask
                for y in range(height):
                    for x in range(width):
                        groups[group].append((code + X_OFFSET[x] + Y_OFFSET[y], colour & 0x0F))
    return groups


def sheets(order, count, prefix):
    """{sheet: [(code, palette)]}: each code in the first sheet that uses it, the rest by bank"""
    taken = {}
    out = {}
    for sheet, uses in order:
        cells = []
        for code, palette in uses:
            if code not in taken and 0 <= code < count:
                taken[code] = sheet
                cells.append((code, palette))
        if cells:
            out[sheet] = cells
    for bank in range(0, count, OTHER_BANK):
        rest = [(code, 0) for code in range(bank, bank + OTHER_BANK) if code not in taken]
        if rest:
            out[f"{prefix}_other_{bank // OTHER_BANK:02d}"] = rest
    return out


# ---- writing and reading the sheets ----

def write_sheet(path, cells, pens_of, size, palette):
    rows_of_cells = (len(cells) + COLUMNS - 1) // COLUMNS
    rows = [[0] * (COLUMNS * size) for _ in range(rows_of_cells * size)]
    for index, (code, colour) in enumerate(cells):
        pens = pens_of(code)
        top, left = (index // COLUMNS) * size, (index % COLUMNS) * size
        for y in range(size):
            for x in range(size):
                rows[top + y][left + x] = pens[y][x] + 16 * colour
    asset_formats.write_png_indexed(path, rows, palette, 8)


def read_sheet(path, count, size):
    rows, _ = asset_formats.read_png_indexed(path)
    cells = []
    for index in range(count):
        top, left = (index // COLUMNS) * size, (index % COLUMNS) * size
        cells.append([[rows[top + y][left + x] & 15 for x in range(size)] for y in range(size)])
    return cells


def extract(source, out):
    sets = rom.load_set(source)
    image = rom.build_program(sets)
    analysis = m68000_analysis.Analysis(image, m68000_analysis.load_symbols(ROOT / "symbols.txt"))
    analysis.run()
    walk = data_walk.Walk(analysis)
    walk.run()
    proms = rom.build_proms(sets)
    tiles = graphics.tiles_for_chips(rom.build_tiles(sets))
    sprites = graphics.sprites_for_chips(rom.build_sprites(sets), proms)
    bank_addresses = next(address for address, symbol in analysis.symbols.items()
                          if symbol.name == "palette_bank_addresses")
    colours = palette_ram(walk, 0, bank_addresses)

    tile_sheets = sheets([(f"area_{area}", uses) for area, uses in area_tiles(walk).items()], TILES, "tiles")
    sprite_sheets = sheets(sorted(animation_groups(walk, analysis).items()), SPRITES, "sprites")
    for folder, sheet_cells, pens_of, size, palettes, listing in (
            ("tiles", tile_sheets, lambda code: graphics.tile_pens(tiles, code), 8, None, "tilesets.txt"),
            ("sprites", sprite_sheets, lambda code: graphics.sprite_pens(sprites, code), 16, SPRITE_PALETTES, "sprites.txt")):
        (out / folder).mkdir(parents=True, exist_ok=True)
        lines = [f"# {folder}: each sheet's codes in the order of its cells, {COLUMNS} a row"]
        for sheet, cells in sheet_cells.items():
            if palettes is None:
                area = int(sheet.split("_")[1]) if sheet.startswith("area_") else 0
                area_colours = palette_ram(walk, area, bank_addresses)
                palette = [area_colours[(LAYER_PALETTES[entry // 128] + entry % 128) % 1024] for entry in range(256)]
            else:
                palette = sheet_palette(colours, palettes)
            write_sheet(out / folder / f"{sheet}.png", cells, pens_of, size, palette)
            lines.append(f"{sheet}  {ranges([code for code, _ in cells])}")
        (out / folder / listing).write_text("\n".join(lines) + "\n", encoding="ascii")
    pcm, speech = sound_assets.extract(rom, sets, out / "sounds")
    pieces, files = data_assets.extract(image, walk, analysis, out / "data")
    sound_pieces = sound_data_assets.extract(rom.build_sound(sets), out)
    print(f"the program's data: {pieces} pieces in {files} files; the sound program's: {sound_pieces} pieces")
    print(f"tiles: {len(tile_sheets)} sheets, sprites: {len(sprite_sheets)} sheets, {pcm} K007232 samples, "
          f"{speech} speech samples and the title music in {out}")


def rebuild(folder, listing, count, size, to_bytes, unit):
    data = bytearray(count * unit)
    seen = set()
    for line in (folder / listing).read_text(encoding="ascii").splitlines():
        if not line.strip() or line.startswith("#"):
            continue
        sheet, codes = line.split(None, 1)
        codes = parse_ranges(codes)
        for code, pens in zip(codes, read_sheet(folder / f"{sheet}.png", len(codes), size)):
            data[code * unit:code * unit + unit] = to_bytes(pens)
            seen.add(code)
    missing = count - len(seen)
    return bytes(data), missing


def check(source, out):
    sets = rom.load_set(source)
    proms = rom.build_proms(sets)
    tiles, missing_tiles = rebuild(out / "tiles", "tilesets.txt", TILES, 8, graphics.tile_bytes, graphics.TILE_BYTES)
    sprites, missing_sprites = rebuild(out / "sprites", "sprites.txt", SPRITES, 16, graphics.sprite_bytes,
                                       graphics.SPRITE_BYTES)
    problems = []
    if missing_tiles or graphics.planar_to_chunky(tiles) != rom.build_tiles(sets):
        problems.append(f"the tiles do not come back ({missing_tiles} codes in no sheet)")
    if missing_sprites or graphics.planar_to_chunky(graphics.scramble_sprites(sprites, proms)) != rom.build_sprites(sets):
        problems.append(f"the sprites do not come back ({missing_sprites} codes in no sheet)")
    problems += sound_assets.check(rom, sets, out / "sounds")
    image = rom.build_program(sets)
    analysis = m68000_analysis.Analysis(image, m68000_analysis.load_symbols(ROOT / "symbols.txt"))
    analysis.run()
    problems += data_assets.check(image, analysis, out / "data")
    problems += sound_data_assets.check(rom.build_sound(sets), out)
    print("\n".join(problems) if problems else
          "tiles, sprites, samples, the program's and the sound program's data: the same as the ROM set, byte for byte")
    return 1 if problems else 0


def main():
    arguments = sys.argv[1:]
    out = ROOT / "assets"
    if "--out" in arguments:
        position = arguments.index("--out")
        out = Path(arguments[position + 1])
        del arguments[position:position + 2]
    checking = "--check" in arguments
    arguments = [argument for argument in arguments if argument != "--check"]
    source = Path(arguments[0]) if arguments else ROOT / "rom"
    if checking:
        return check(source, out)
    extract(source, out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
