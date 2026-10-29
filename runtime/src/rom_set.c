/**
 *    Name:        rom_set.c
 *    Description: the player's ROM set into the board's memory (game/data.h), from a .zip or a folder
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Each of the set's 16 files is known by its CRC32: in a .zip by its own, whatever its name (stored or
 *    deflated: inflate.c); in a folder by MAME's name, or in the folder's tmnt.zip. The regions are laid out
 *    after ROM_START( tmnt ) and init_tmnt in MAME's src/mame/konami/tmnt.cpp (BSD-3-Clause). The reference
 *    runs the original code, so it reads the set when it starts, as MAME does.
 */
#include "game/extract.h"

#include "game/data.h"
#include "inflate.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZIP_END             0x06054B50u    /* the end of the central directory */
#define ZIP_ENTRY           0x02014B50u    /* a central directory entry */
#define ZIP_LOCAL           0x04034B50u    /* a local header */
#define ZIP_STORED          0
#define ZIP_DEFLATED        8
#define ZIP_COMMENT_MOST    0xFFFFu
#define SET_ZIP             "tmnt.zip"    /* MAME's name for the set's .zip */

typedef struct
{
	const char *name;
	uint32_t crc, size;
} rom_file;

enum
{
	J17, K17, J15, K15, G13, H27, K27, H4, K4, H6, K6, G7, G19, C13, D18, D5, FILES
};

static const rom_file files[FILES] = {
	{ "963-x23.j17", 0xa9549004u, 0x020000u },
	{ "963-x24.k17", 0xe5cc9067u, 0x020000u },
	{ "963-x21.j15", 0x5789cf92u, 0x010000u },
	{ "963-x22.k15", 0x0a74e277u, 0x010000u },
	{ "963e20.g13", 0x1692a6d6u, 0x008000u },
	{ "963a28.h27", 0xdb4769a8u, 0x080000u },
	{ "963a29.k27", 0x8069cd2eu, 0x080000u },
	{ "963a17.h4", 0xb5239a44u, 0x080000u },
	{ "963a15.k4", 0x1f324eedu, 0x080000u },
	{ "963a18.h6", 0xdd51adefu, 0x080000u },
	{ "963a16.k6", 0xd4bd9984u, 0x080000u },
	{ "963a30.g7", 0xabd82680u, 0x000100u },
	{ "963a31.g19", 0xf8004a1cu, 0x000100u },
	{ "963a26.c13", 0xe2ac3063u, 0x020000u },
	{ "963a27.d18", 0x2dfd674bu, 0x020000u },
	{ "963a25.d5", 0xfca078c7u, 0x080000u },
};

static uint32_t crc32_of(const uint8_t *data, uint32_t size)
{
	static uint32_t table[256];
	uint32_t crc = 0xFFFFFFFFu, index;
	int bit;

	if (table[1] == 0u)
		for (index = 0; index < 256u; index++)
		{
			table[index] = index;
			for (bit = 0; bit < 8; bit++)
				table[index] = (table[index] >> 1) ^ (0xEDB88320u & (0u - (table[index] & 1u)));
		}
	for (index = 0; index < size; index++)
		crc = (crc >> 8) ^ table[(crc ^ data[index]) & 0xFFu];
	return ~crc;
}

static uint32_t little16(const uint8_t *bytes)
{
	return (uint32_t)bytes[0] | (uint32_t)bytes[1] << 8;
}

static uint32_t little32(const uint8_t *bytes)
{
	return little16(bytes) | little16(bytes + 2) << 16;
}

/* A whole file into memory (the caller frees it), or NULL */
static uint8_t *read_whole(const char *path, size_t *size)
{
	FILE *input = fopen(path, "rb");
	uint8_t *data = NULL;
	long length;

	if (!input)
		return NULL;
	if (fseek(input, 0, SEEK_END) == 0 && (length = ftell(input)) > 0 && fseek(input, 0, SEEK_SET) == 0
		&& (data = malloc((size_t)length)) != NULL && fread(data, 1, (size_t)length, input) != (size_t)length)
	{
		free(data);
		data = NULL;
	}
	fclose(input);
	if (data)
		*size = (size_t)length;
	return data;
}

/* The set's files in the .zip 'zip' ('size' bytes) into 'chips', by their CRC32: 0 when it is no .zip */
static int read_zip(const uint8_t *zip, size_t size, uint8_t **chips)
{
	size_t end, entry, local;
	uint32_t entries, index;
	int file;

	if (size < 22)
		return 0;
	for (end = size - 22;; end--)
	{
		if (little32(zip + end) == ZIP_END)
			break;
		if (end == 0 || size - end > 22 + ZIP_COMMENT_MOST)
			return 0;
	}
	entries = little16(zip + end + 10);
	entry = little32(zip + end + 16);
	for (index = 0; index < entries; index++)
	{
		uint32_t method, crc, packed, unpacked;

		if (entry > size || size - entry < 46 || little32(zip + entry) != ZIP_ENTRY)
			return 0;
		method = little16(zip + entry + 10);
		crc = little32(zip + entry + 16);
		packed = little32(zip + entry + 20);
		unpacked = little32(zip + entry + 24);
		local = little32(zip + entry + 42);
		entry += 46 + little16(zip + entry + 28) + little16(zip + entry + 30) + little16(zip + entry + 32);
		for (file = 0; file < FILES; file++)
			if (!chips[file] && files[file].crc == crc && files[file].size == unpacked)
				break;
		if (file == FILES || local > size || size - local < 30 || little32(zip + local) != ZIP_LOCAL)
			continue;
		local += 30 + little16(zip + local + 26) + little16(zip + local + 28);
		if (local > size || packed > size - local || (method == ZIP_STORED && packed != unpacked)
			|| !(chips[file] = malloc(unpacked)))
			continue;    /* (what the entry says does not fit the file) */
		if ((method == ZIP_STORED ? (memcpy(chips[file], zip + local, unpacked), 1)
				: method == ZIP_DEFLATED && inflate_raw(zip + local, packed, chips[file], unpacked))
			&& crc32_of(chips[file], unpacked) == crc)
			continue;
		free(chips[file]);
		chips[file] = NULL;
	}
	return 1;
}

/* The set's files in the folder 'folder' into 'chips', by their MAME names and their CRC32 */
static void read_folder(const char *folder, uint8_t **chips)
{
	char path[1024];
	int file;

	for (file = 0; file < FILES; file++)
	{
		size_t size = 0;

		snprintf(path, sizeof(path), "%s/%s", folder, files[file].name);
		chips[file] = read_whole(path, &size);
		if (chips[file] && (size != files[file].size || crc32_of(chips[file], files[file].size) != files[file].crc))
		{
			free(chips[file]);
			chips[file] = NULL;
		}
	}
}

/* ROM_LOAD16_BYTE: even bytes from one chip, odd bytes from the other */
static void interleave16(uint8_t *out, const uint8_t *even, const uint8_t *odd, uint32_t size)
{
	uint32_t index;

	for (index = 0; index < size; index++)
	{
		out[index * 2u] = even[index];
		out[index * 2u + 1u] = odd[index];
	}
}

/* ROM_LOAD32_WORD: every 4-byte group takes a 16-bit word of each chip, the first chip's first */
static void interleave32(uint8_t *out, const uint8_t *first, const uint8_t *second, uint32_t size)
{
	uint32_t word;

	for (word = 0; word < size / 2u; word++)
	{
		out[word * 4u] = first[word * 2u];
		out[word * 4u + 1u] = first[word * 2u + 1u];
		out[word * 4u + 2u] = second[word * 2u];
		out[word * 4u + 3u] = second[word * 2u + 1u];
	}
}

/* MAME's chunky_to_planar: every 4-byte group, read as a little-endian word, takes its bits 3, 7, 11... 31
   to the top byte, 2, 6... 30 to the next, and so on */
static void chunky_to_planar(uint8_t *region, uint32_t size)
{
	uint32_t group;
	int bit;

	for (group = 0; group < size; group += 4u)
	{
		const uint32_t data = little32(region + group);
		uint32_t result = 0;

		for (bit = 0; bit < 32; bit++)
			result |= ((data >> ((bit & 7) * 4 + (bit >> 3))) & 1u) << bit;
		region[group] = (uint8_t)result;
		region[group + 1u] = (uint8_t)(result >> 8);
		region[group + 2u] = (uint8_t)(result >> 16);
		region[group + 3u] = (uint8_t)(result >> 24);
	}
}

/* init_tmnt: the sprite ROM's address lines, unscrambled. The PROM (963a30.g7) gives every 2 KB of 32-bit
   words its sprite size, and each size takes the word's 10 low address bits from other bits */
static void unscramble_sprites(void)
{
	/* for each of the 10 low bits of the address, the bit it comes from, by the PROM's entry (the size:
	   1x1, 2x1, 1x2, 2x2, 4x2, 2x4, 4x4, 8x8) */
	static const uint8_t bit_pick[10][8] = {
		{ 3, 3, 3, 3, 3, 3, 3, 3 },
		{ 0, 0, 5, 5, 5, 5, 5, 5 },
		{ 1, 1, 0, 0, 0, 7, 7, 7 },
		{ 2, 2, 1, 1, 1, 0, 0, 9 },
		{ 4, 4, 2, 2, 2, 1, 1, 0 },
		{ 5, 6, 4, 4, 4, 2, 2, 1 },
		{ 6, 5, 6, 6, 6, 4, 4, 2 },
		{ 7, 7, 7, 7, 8, 6, 6, 4 },
		{ 8, 8, 8, 8, 7, 8, 8, 6 },
		{ 9, 9, 9, 9, 9, 9, 9, 8 }
	};
	const uint32_t words = GAME_SPRITES_SIZE / 4u;
	uint8_t *scrambled = malloc(GAME_SPRITES_SIZE);
	uint32_t word;
	int bit;

	if (!scrambled)
		return;
	memcpy(scrambled, game_sprites, GAME_SPRITES_SIZE);
	for (word = 0; word < words; word++)
	{
		const int entry = game_proms[(word & 0x7F800u) >> 11] & 7;
		uint32_t source = word & 0x7FC00u;

		for (bit = 0; bit < 10; bit++)
			source |= ((word >> bit_pick[bit][entry]) & 1u) << bit;
		memcpy(game_sprites + word * 4u, scrambled + source * 4u, 4);
	}
	free(scrambled);
}

const char *game_rom_set_load(const char *source)
{
	static char problem[96];
	uint8_t *chips[FILES] = { NULL };
	size_t size = 0;
	uint8_t *whole = read_whole(source, &size);
	int file;

	if (whole)
	{
		const int zip = read_zip(whole, size, chips);

		free(whole);
		if (!zip)
			return "not a .zip";
	}
	else
	{
		char zip_path[1024];

		read_folder(source, chips);
		/* (a folder that holds the set's .zip, as MAME keeps it) */
		snprintf(zip_path, sizeof(zip_path), "%s/" SET_ZIP, source);
		if ((whole = read_whole(zip_path, &size)) != NULL)
		{
			read_zip(whole, size, chips);
			free(whole);
		}
	}
	problem[0] = '\0';
	for (file = 0; file < FILES && !problem[0]; file++)
		if (!chips[file])
			snprintf(problem, sizeof(problem), "no %s (or not this version of it)", files[file].name);
	if (!problem[0])
	{
		interleave16(game_program, chips[J17], chips[K17], 0x20000u);
		interleave16(game_program + 0x40000u, chips[J15], chips[K15], 0x10000u);
		memcpy(game_sound, chips[G13], GAME_SOUND_SIZE);
		interleave32(game_tiles, chips[H27], chips[K27], 0x80000u);
		interleave32(game_sprites, chips[H4], chips[K4], 0x80000u);
		interleave32(game_sprites + 0x100000u, chips[H6], chips[K6], 0x80000u);
		memcpy(game_proms, chips[G7], 0x100u);
		memcpy(game_proms + 0x100u, chips[G19], 0x100u);
		memcpy(game_pcm, chips[C13], GAME_PCM_SIZE);
		memcpy(game_speech, chips[D18], GAME_SPEECH_SIZE);
		memcpy(game_title, chips[D5], GAME_TITLE_SIZE);
		chunky_to_planar(game_tiles, GAME_TILES_SIZE);
		chunky_to_planar(game_sprites, GAME_SPRITES_SIZE);
		unscramble_sprites();
	}
	for (file = 0; file < FILES; file++)
		free(chips[file]);
	return problem[0] ? problem : NULL;
}
