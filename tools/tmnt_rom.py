"""
Name:        tmnt_rom.py
Description: MAME 'tmnt' ROM set (Teenage Mutant Ninja Turtles, World 4 Players, version X) and its regions
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

Files are identified by CRC32 + SHA1, not by name. Accepts a folder or the .zip as is.
Region layouts follow ROM_START( tmnt ) in MAME src/mame/konami/tmnt.cpp (BSD-3-Clause).
"""
import hashlib
import zipfile
import zlib
from pathlib import Path

SET_NAME = "tmnt"

# MAME name -> (crc32, sha1, size)
ROM_FILES = {
    "963-x23.j17": ("a9549004", "bf9be5983af2282f627fb8408c069415c9b90229", 0x020000),
    "963-x24.k17": ("e5cc9067", "649db4a09864eb8aba44cb77b580f1f28cfd80ed", 0x020000),
    "963-x21.j15": ("5789cf92", "c1d1c958813062e5df5ac62e90ee4ce11f7e4a24", 0x010000),
    "963-x22.k15": ("0a74e277", "c349d3c25eb05cc30ec1fd823475d971f3649f8b", 0x010000),
    "963e20.g13": ("1692a6d6", "68c3419012b2863e91a7d7e479fce5ceabb10b88", 0x008000),
    "963a28.h27": ("db4769a8", "810811914f9c1fbf2320d5a9030cbf124f6d78cf", 0x080000),
    "963a29.k27": ("8069cd2e", "54095d3546119ccd1e8814d692aceb1327c9369f", 0x080000),
    "963a17.h4": ("b5239a44", "84e94807e7c51aa652b4e4b827b36be59a53d0d6", 0x080000),
    "963a15.k4": ("1f324eed", "971a675578518fffa341a943d0cc4fdea005fde0", 0x080000),
    "963a18.h6": ("dd51adef", "5010c0911b0b9e4f23a785e8a751a0bde5be5be0", 0x080000),
    "963a16.k6": ("d4bd9984", "d780ae7f72e16767c3a492544f02f0f1a332ab22", 0x080000),
    "963a30.g7": ("abd82680", "945a71e6ec65202f13209b45d45b616372d6c0f5", 0x000100),
    "963a31.g19": ("f8004a1c", "ed6694b8eebfe0238b50ebd05007d519f6e57b1b", 0x000100),
    "963a26.c13": ("e2ac3063", "5bb294c46fb5eaba9935a18c0aa5d3931168f474", 0x020000),
    "963a27.d18": ("2dfd674b", "bbec5896c70056964fbc972a84bd5b0dfc6af257", 0x020000),
    "963a25.d5": ("fca078c7", "3e1124d72c9db4cb11d8de6c44b7aeca967f44e1", 0x080000),
}

# The 68000 program image: 0x000000-0x05FFFF, no mirrors (the board maps work RAM at 0x060000)
PROGRAM_AREAS = [
    (0x000000, 0x040000),  # 963-x23.j17 (even bytes) + 963-x24.k17 (odd bytes)
    (0x040000, 0x060000),  # 963-x21.j15 (even bytes) + 963-x22.k15 (odd bytes)
]
PROGRAM_SIZE = 0x060000


def read_files(source):
    """Return {original_name: bytes} from a folder or a .zip."""
    source = Path(source)
    contents = {}
    if source.is_file() and source.suffix.lower() == ".zip":
        with zipfile.ZipFile(source) as archive:
            for entry in archive.infolist():
                if not entry.is_dir():
                    contents[Path(entry.filename).name] = archive.read(entry)
        return contents
    for path in sorted(source.iterdir()):
        if path.is_file():
            contents[path.name] = path.read_bytes()
    return contents


def identify_set(source):
    """Return ({mame_name: bytes}, [report lines]), matching every file by its hashes. A folder that holds
    none of the set's files loose is read through the first .zip in it that does."""
    found, report = _identify(source)
    if not found and Path(source).is_dir():
        for archive in sorted(Path(source).glob("*.zip")):
            found, report = _identify(archive)
            if found:
                break
    return found, report


def _identify(source):
    by_crc = {crc: name for name, (crc, _, _) in ROM_FILES.items()}
    found = {}
    report = []
    for original_name, data in read_files(source).items():
        crc = format(zlib.crc32(data) & 0xFFFFFFFF, "08x")
        mame_name = by_crc.get(crc)
        if mame_name and ROM_FILES[mame_name][1] == hashlib.sha1(data).hexdigest():
            found[mame_name] = data
            report.append(f"OK      {original_name:20} = {mame_name}")
        else:
            report.append(f"--      {original_name:20} not part of the set (crc {crc})")
    for mame_name in sorted(set(ROM_FILES) - set(found)):
        report.append(f"MISSING {mame_name}")
    return found, report


def load_set(source):
    """Like identify_set, but stops when a file is missing."""
    found, _ = identify_set(source)
    missing = sorted(set(ROM_FILES) - set(found))
    if missing:
        raise SystemExit(f"The '{SET_NAME}' ROM set is incomplete. Missing: " + ", ".join(missing))
    return found


def interleave16(even, odd):
    """ROM_LOAD16_BYTE: even bytes from one chip, odd bytes from the other."""
    result = bytearray(len(even) * 2)
    result[0::2] = even
    result[1::2] = odd
    return result


def interleave32(first, second):
    """ROM_LOAD32_WORD: every 4-byte group takes a 16-bit word of each chip, the first chip's first."""
    result = bytearray(len(first) * 2)
    for lane, chip in enumerate((first, second)):
        result[lane * 2::4] = chip[0::2]
        result[lane * 2 + 1::4] = chip[1::2]
    return result


def build_program(rom):
    """maincpu region (384 KB, big endian) as the 68000 sees it at 0x000000-0x05FFFF."""
    return bytes(interleave16(rom["963-x23.j17"], rom["963-x24.k17"])
                 + interleave16(rom["963-x21.j15"], rom["963-x22.k15"]))


def build_sound(rom):
    """audiocpu region (32 KB): the Z80 program at 0x0000-0x7FFF."""
    return bytes(rom["963e20.g13"])


def build_tiles(rom):
    """k052109 region (1 MB) in file byte order: the tile layers' graphics."""
    return bytes(interleave32(rom["963a28.h27"], rom["963a29.k27"]))


def build_sprites(rom):
    """k051960 region (2 MB) in file byte order: the sprites' graphics."""
    return bytes(interleave32(rom["963a17.h4"], rom["963a15.k4"])
                 + interleave32(rom["963a18.h6"], rom["963a16.k6"]))


def build_proms(rom):
    """proms region (512 bytes): the sprite address decoder, then the priority PROM (which MAME does not use)."""
    return bytes(rom["963a30.g7"] + rom["963a31.g19"])


def build_pcm(rom):
    """k007232 region (128 KB): the K007232's samples."""
    return bytes(rom["963a26.c13"])


def build_speech(rom):
    """upd region (128 KB): the uPD7759's speech samples."""
    return bytes(rom["963a27.d18"])


def build_title(rom):
    """title region (512 KB): the title music, a sample the sound board plays through a DAC."""
    return bytes(rom["963a25.d5"])


def canonical_address(address):
    """Map a 68000 address to its offset in the program image, or None if it is not ROM.

    The 68000 drives 24 address lines: the top byte of an address is not decoded."""
    address &= 0xFFFFFF
    return address if address < PROGRAM_SIZE else None


class ProgramMemory:
    """68000 view of the program ROM for the disassembler: big endian, anything outside it reads 0xFF."""

    def __init__(self, image):
        self.image = image

    def r8(self, address):
        offset = canonical_address(address)
        return self.image[offset] if offset is not None else 0xFF

    def r16(self, address):
        return (self.r8(address) << 8) | self.r8(address + 1)

    def r32(self, address):
        return (self.r16(address) << 16) | self.r16(address + 2)
