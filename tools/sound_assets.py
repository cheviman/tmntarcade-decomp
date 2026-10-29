"""
Name:        sound_assets.py
Description: TMNT's samples as WAV files and back, byte for byte: the title music, the K007232's samples and the
             uPD7759's speech
Version:     0.1.0
Created:     29-10-2026
Modified:    29-10-2026
Author:      Sebastian Toyos

For tools/extract_assets.py, which writes them into assets/sounds:
  title.wav            the title music: 16 bits at 20 kHz (tmnt.cpp plays it at 640 kHz / 32), the ROM's words
                       being 3.10 floating point samples (ymfm's decode_fp of the word >> 3): every one of them
                       encodes back to the same word, and their 3 low bits are 0
  pcm/sample_NN.wav    the K007232's samples, each up to its end mark (the byte with bit 7 set), the bytes as
                       they are (8-bit WAVs); pcm.txt says where each starts
  speech/speech_NN.wav the uPD7759's speech: the ADPCM decoded to 16 bits at 20 kHz to listen to (MAME's
                       upd7759.cpp tables), and the ROM's bytes of the sample in a 'rawd' chunk, which is what
                       goes back; speech.txt holds the header (the last sample's number, its signature, each
                       sample's offset) and the bytes between the header and the first sample
"""
TITLE_RATE = 20000
SPEECH_RATE = 20000
PCM_RATE = 8000
SPEECH_CLOCK = 640000

UPD_STEP = (
    (0, 0, 1, 2, 3, 5, 7, 10, 0, 0, -1, -2, -3, -5, -7, -10),
    (0, 1, 2, 3, 4, 6, 8, 13, 0, -1, -2, -3, -4, -6, -8, -13),
    (0, 1, 2, 4, 5, 7, 10, 15, 0, -1, -2, -4, -5, -7, -10, -15),
    (0, 1, 3, 4, 6, 9, 13, 19, 0, -1, -3, -4, -6, -9, -13, -19),
    (0, 2, 3, 5, 8, 11, 15, 23, 0, -2, -3, -5, -8, -11, -15, -23),
    (0, 2, 4, 7, 10, 14, 19, 29, 0, -2, -4, -7, -10, -14, -19, -29),
    (0, 3, 5, 8, 12, 16, 22, 33, 0, -3, -5, -8, -12, -16, -22, -33),
    (1, 4, 7, 10, 15, 20, 29, 43, -1, -4, -7, -10, -15, -20, -29, -43),
    (1, 4, 8, 13, 18, 25, 35, 53, -1, -4, -8, -13, -18, -25, -35, -53),
    (1, 6, 10, 16, 22, 31, 43, 64, -1, -6, -10, -16, -22, -31, -43, -64),
    (2, 7, 12, 19, 27, 37, 51, 76, -2, -7, -12, -19, -27, -37, -51, -76),
    (2, 9, 16, 24, 34, 46, 64, 96, -2, -9, -16, -24, -34, -46, -64, -96),
    (3, 11, 19, 29, 41, 57, 79, 117, -3, -11, -19, -29, -41, -57, -79, -117),
    (4, 13, 24, 36, 50, 69, 96, 143, -4, -13, -24, -36, -50, -69, -96, -143),
    (4, 16, 29, 44, 62, 85, 118, 175, -4, -16, -29, -44, -62, -85, -118, -175),
    (6, 20, 36, 54, 76, 104, 144, 214, -6, -20, -36, -54, -76, -104, -144, -214),
)
UPD_STATE = (-1, -1, 0, 0, 1, 2, 2, 3, -1, -1, 0, 0, 1, 2, 2, 3)


def decode_fp(code):
    """ymfm's decode_fp: a 3.10 floating point sample to 16 bits"""
    code ^= 0x1E00
    value = (code << 6) & 0xFFFF
    return (value - 0x10000 if value & 0x8000 else value) >> ((code >> 10) & 7)


def encode_fp(value):
    """ymfm's encode_fp, back"""
    scan = value ^ (-1 if value < 0 else 0)
    exponent = max(7 - (32 - ((scan << 17) & 0xFFFFFFFF).bit_length()), 1)
    return ((exponent << 10) | ((value >> (exponent - 1)) & 0x3FF)) ^ 0x200


def write_riff(path, samples, rate, bits, raw=b""):
    """A mono WAV of 8-bit (unsigned) or 16-bit samples, and a 'rawd' chunk after its data if 'raw' is given"""
    data = bytes(samples) if bits == 8 else b"".join((sample & 0xFFFF).to_bytes(2, "little") for sample in samples)
    fmt = ((1).to_bytes(2, "little") + (1).to_bytes(2, "little") + rate.to_bytes(4, "little")
           + (rate * bits // 8).to_bytes(4, "little") + (bits // 8).to_bytes(2, "little") + bits.to_bytes(2, "little"))
    chunks = b"fmt " + len(fmt).to_bytes(4, "little") + fmt
    chunks += b"data" + len(data).to_bytes(4, "little") + data + bytes(len(data) % 2)
    if raw:
        chunks += b"rawd" + len(raw).to_bytes(4, "little") + raw + bytes(len(raw) % 2)
    path.write_bytes(b"RIFF" + (4 + len(chunks)).to_bytes(4, "little") + b"WAVE" + chunks)


def read_riff(path):
    """{chunk id: its bytes} of a WAV"""
    data = path.read_bytes()
    chunks, at = {}, 12
    while at + 8 <= len(data):
        kind, size = data[at:at + 4].decode("ascii"), int.from_bytes(data[at + 4:at + 8], "little")
        chunks[kind] = data[at + 8:at + 8 + size]
        at += 8 + size + (size & 1)
    return chunks


def decode_speech(data, start):
    """A uPD7759 sample (the byte at 'start' is a dummy, its blocks follow) as 16-bit PCM at SPEECH_RATE"""
    out, sample, state, at, valid, carry = [], 0, 0, start + 1, False, 0.0
    while at < len(data):
        header = data[at]
        at += 1
        kind = header & 0xC0
        if kind == 0x00:
            if header == 0 and valid:
                break
            out += [0] * (((header & 0x3F) + 1) * 1024 * SPEECH_RATE // SPEECH_CLOCK)
            sample, state = 0, 0
        elif kind in (0x40, 0x80):
            rate = (header & 0x3F) + 1
            nibbles = 256
            if kind == 0x80:
                nibbles = data[at] + 1
                at += 1
            for index in range(nibbles):
                if at + index // 2 >= len(data):
                    break
                nibble = (data[at + index // 2] >> (4 if index % 2 == 0 else 0)) & 15
                sample += UPD_STEP[state][nibble]
                state = min(max(state + UPD_STATE[nibble], 0), 15)
                carry += rate * 4 * SPEECH_RATE / SPEECH_CLOCK
                while carry >= 1:
                    out.append(max(-32768, min(32767, sample * 128)))
                    carry -= 1
            at += (nibbles + 1) // 2
        if header:
            valid = True
    return out


def extract(rom, sets, folder):
    for sub in ("pcm", "speech"):
        (folder / sub).mkdir(parents=True, exist_ok=True)
    title = rom.build_title(sets)
    write_riff(folder / "title.wav", [decode_fp((title[2 * index] | title[2 * index + 1] << 8) >> 3)
                                      for index in range(len(title) // 2)], TITLE_RATE, 16)
    pcm = rom.build_pcm(sets)
    pieces, start = [], 0
    for at, byte in enumerate(pcm):
        if byte & 0x80:
            pieces.append((start, at + 1))
            start = at + 1
    if start < len(pcm):
        pieces.append((start, len(pcm)))
    for number, (first, stop) in enumerate(pieces):
        write_riff(folder / "pcm" / f"sample_{number:02d}.wav", pcm[first:stop], PCM_RATE, 8)
    (folder / "pcm.txt").write_text("# the K007232's samples: number, first byte, end (after its end mark)\n"
                                    + "".join(f"{number:02d} {first:05X} {stop:05X}\n"
                                              for number, (first, stop) in enumerate(pieces)), encoding="ascii")
    speech = rom.build_speech(sets)
    last = speech[0]
    offsets = [((speech[index * 2 + 5] << 8) | speech[index * 2 + 6]) << 1 for index in range(last + 1)]
    starts = sorted(set(offsets))
    bounds = starts + [len(speech)]
    table_end = 5 + 2 * (last + 1)
    lines = ["# the uPD7759's header: the last sample's number, its signature, each sample's offset (by number);",
             "# then the bytes between the header and the first sample",
             f"last {last}", "signature " + speech[1:5].hex(), "offsets " + " ".join(f"{offset:05X}" for offset in offsets),
             "before " + speech[table_end:starts[0]].hex()]
    for number, offset in enumerate(starts):
        write_riff(folder / "speech" / f"speech_{number:02d}.wav", decode_speech(speech, offset), SPEECH_RATE, 16,
                   speech[offset:bounds[number + 1]])
    (folder / "speech.txt").write_text("\n".join(lines) + "\n", encoding="ascii")
    return len(pieces), len(starts)


def check(rom, sets, folder):
    """What does not come back"""
    problems = []
    samples = read_riff(folder / "title.wav")["data"]
    title = b"".join((encode_fp(int.from_bytes(samples[at:at + 2], "little", signed=True)) << 3).to_bytes(2, "little")
                     for at in range(0, len(samples), 2))
    if title != rom.build_title(sets):
        problems.append("the title music does not come back")
    pcm = bytearray()
    for line in (folder / "pcm.txt").read_text(encoding="ascii").splitlines():
        if line and not line.startswith("#"):
            number, first, stop = line.split()
            pcm += read_riff(folder / "pcm" / f"sample_{number}.wav")["data"][:int(stop, 16) - int(first, 16)]
    if bytes(pcm) != rom.build_pcm(sets):
        problems.append("the K007232's samples do not come back")
    fields = {}
    for line in (folder / "speech.txt").read_text(encoding="ascii").splitlines():
        if line and not line.startswith("#"):
            key, _, value = line.partition(" ")
            fields[key] = value
    offsets = [int(value, 16) for value in fields["offsets"].split()]
    speech = bytearray([int(fields["last"])]) + bytes.fromhex(fields["signature"])
    for offset in offsets:
        speech += bytes([(offset >> 9) & 0xFF, (offset >> 1) & 0xFF])
    speech += bytes.fromhex(fields["before"])
    for number in range(len(set(offsets))):
        speech += read_riff(folder / "speech" / f"speech_{number:02d}.wav")["rawd"]
    if bytes(speech) != rom.build_speech(sets):
        problems.append("the uPD7759's speech does not come back")
    return problems
