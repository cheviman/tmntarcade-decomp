"""
Name:        tmnt_graphics.py
Description: TMNT's tile and sprite graphics: from the ROM files to pixels and back, as the board's chips see them
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

The tile ROMs (K052109) and the sprite ROMs (K051960) as MAME's tmnt.cpp loads them (tools/tmnt_rom.py's
build_tiles and build_sprites) and as runtime/src/rom_set.c prepares them for the chips: chunky_to_planar on
both, and the sprite ROMs' address lines unscrambled by the PROM 963a30.g7 (init_tmnt). Every step goes back
(the bits of a 4-byte group are permuted, and so are the 10 low address bits of a 32-bit word within its
size's block), so the files come back byte for byte from the pixels.

A tile is 8 x 8 pixels of 4 bits, 32 bytes: a row is a 32-bit word whose bytes are the four planes, the most
significant pen bit in its last byte (MAME's k052109 charlayout: planes 24, 16, 8, 0). A sprite is 16 x 16,
128 bytes: four such 8 x 8 quarters, the top right one 32 bytes on, the bottom left 64, the bottom right 96
(k051960's spritelayout_reverse, the plane order tmnt.cpp sets).
"""
TILE_BYTES = 32
SPRITE_BYTES = 128

# rom_set.c's unscramble_sprites: for each of the 10 low bits of a word's address, the bit it comes from, by
# the PROM's entry for the word's 2 KB (the sprite size: 1x1, 2x1, 1x2, 2x2, 4x2, 2x4, 4x4, 8x8)
BIT_PICK = ((3, 3, 3, 3, 3, 3, 3, 3), (0, 0, 5, 5, 5, 5, 5, 5), (1, 1, 0, 0, 0, 7, 7, 7), (2, 2, 1, 1, 1, 0, 0, 9),
            (4, 4, 2, 2, 2, 1, 1, 0), (5, 6, 4, 4, 4, 2, 2, 1), (6, 5, 6, 6, 6, 4, 4, 2), (7, 7, 7, 7, 8, 6, 6, 4),
            (8, 8, 8, 8, 7, 8, 8, 6), (9, 9, 9, 9, 9, 9, 9, 8))


def _planar_tables():
    """For each byte value of each byte of a little-endian 32-bit group, its share of the planar word, and back"""
    forward = [[0] * 256 for _ in range(4)]
    for lane in range(4):
        for value in range(256):
            result = 0
            for bit in range(8):
                if value >> bit & 1:
                    source = lane * 8 + bit             # bit 'source' of the chunky word ...
                    # ... goes to the planar bit whose (bit & 7) * 4 + (bit >> 3) is 'source'
                    result |= 1 << ((source % 4) * 8 + source // 4)
            forward[lane][value] = result
    return forward


_FORWARD = _planar_tables()


def chunky_to_planar(data):
    """MAME's chunky_to_planar: every 4-byte group, a little-endian word, its bits regrouped by plane"""
    out = bytearray(len(data))
    for group in range(0, len(data), 4):
        word = (_FORWARD[0][data[group]] | _FORWARD[1][data[group + 1]] | _FORWARD[2][data[group + 2]]
                | _FORWARD[3][data[group + 3]])
        out[group:group + 4] = word.to_bytes(4, "little")
    return bytes(out)


def planar_to_chunky(data):
    out = bytearray(len(data))
    for group in range(0, len(data), 4):
        word = int.from_bytes(data[group:group + 4], "little")
        result = 0
        for bit in range(32):
            if word >> bit & 1:
                result |= 1 << ((bit & 7) * 4 + (bit >> 3))
        out[group:group + 4] = result.to_bytes(4, "little")
    return bytes(out)


def _sprite_sources(proms):
    """For every 32-bit word of the unscrambled sprite ROM, the word of the file it comes from"""
    sources = []
    for word in range(0x200000 // 4):
        entry = proms[(word & 0x7F800) >> 11] & 7
        source = word & 0x7FC00
        for bit in range(10):
            source |= ((word >> BIT_PICK[bit][entry]) & 1) << bit
        sources.append(source)
    return sources


def unscramble_sprites(data, proms):
    sources = _sprite_sources(proms)
    out = bytearray(len(data))
    for word, source in enumerate(sources):
        out[word * 4:word * 4 + 4] = data[source * 4:source * 4 + 4]
    return bytes(out)


def scramble_sprites(data, proms):
    sources = _sprite_sources(proms)
    out = bytearray(len(data))
    for word, source in enumerate(sources):
        out[source * 4:source * 4 + 4] = data[word * 4:word * 4 + 4]
    return bytes(out)


def tiles_for_chips(files_order):
    """build_tiles' bytes -> what the K052109 reads"""
    return chunky_to_planar(files_order)


def sprites_for_chips(files_order, proms):
    return unscramble_sprites(chunky_to_planar(files_order), proms)


def _block_pens(data, base, rows):
    """An 8 x 8 block of pens from the planar data at 'base' (rows 4 bytes apart)"""
    pens = []
    for row in range(rows):
        at = base + 4 * row
        planes = (data[at + 3], data[at + 2], data[at + 1], data[at])     # most significant pen bit first
        pens.append([((planes[0] >> (7 - x)) & 1) << 3 | ((planes[1] >> (7 - x)) & 1) << 2
                     | ((planes[2] >> (7 - x)) & 1) << 1 | ((planes[3] >> (7 - x)) & 1) for x in range(8)])
    return pens


def _block_bytes(pens):
    out = bytearray(32)
    for row, line in enumerate(pens):
        for lane, plane_bit in ((3, 3), (2, 2), (1, 1), (0, 0)):
            value = 0
            for x in range(8):
                value |= ((line[x] >> plane_bit) & 1) << (7 - x)
            out[4 * row + lane] = value
    return bytes(out)


def tile_pens(data, code):
    """8 rows of 8 pens of the tile 'code' (the K052109's data)"""
    return _block_pens(data, code * TILE_BYTES, 8)


def tile_bytes(pens):
    return _block_bytes(pens)


def sprite_pens(data, code):
    """16 rows of 16 pens of the sprite 'code' (the K051960's data)"""
    base = code * SPRITE_BYTES
    quarters = [_block_pens(data, base + offset, 8) for offset in (0, 32, 64, 96)]
    return [quarters[0][row] + quarters[1][row] for row in range(8)] + \
           [quarters[2][row] + quarters[3][row] for row in range(8)]


def sprite_bytes(pens):
    top = [line[:8] for line in pens[:8]], [line[8:] for line in pens[:8]]
    bottom = [line[:8] for line in pens[8:]], [line[8:] for line in pens[8:]]
    return _block_bytes(top[0]) + _block_bytes(top[1]) + _block_bytes(bottom[0]) + _block_bytes(bottom[1])
