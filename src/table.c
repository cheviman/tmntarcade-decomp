/**
 *    Name:        table.c
 *    Description: the code the board runs by address (the vectors' handlers), the reset entry, and the tables the game loads by name
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the handlers of the vectors (the reset, the exceptions, the interrupts), by address */
const game_code_entry game_code[] =
{
	{ 0x001000u, reset },
	{ 0x00193Eu, exception_hang },
	{ 0x003DC4u, vblank_interrupt },
	{ 0x004190u, irq6_interrupt },
};

const size_t game_code_count = 4;

/* the code at the reset vector */
void game_entry(void)
{
	reset();
}

const void *indexed_table_of_32_bit_values_0013DE_data;
const void *rom_001426_data;
const void *rom_001452_data;
const void *rom_001453_data;
const void *rom_001472_data;
const void *rom_001473_data;
const void *indexed_table_of_32_bit_values_0015AC_data;
const void *text_colours_data;
const void *rom_001F1B_data;
const void *indexed_table_of_32_bit_values_002678_data;
const void *text_layer_places_data;
const void *big_font_place_data;
const void *indexed_table_of_8_bit_values_002884_data;
const void *rom_002885_data;
const void *indexed_table_of_32_bit_values_0031F2_data;
const void *rom_00332A_data;
const void *rom_0033A2_data;
const void *rom_0033A3_data;
const void *rom_0033B6_data;
const void *rom_0033B7_data;
const void *rom_003402_data;
const void *positioned_texts_data;
const void *indexed_table_of_32_bit_values_003E60_data;
const void *indexed_table_of_32_bit_values_003F8E_data;
const void *indexed_table_of_32_bit_values_004100_data;
const void *indexed_table_of_32_bit_values_00413A_data;
const void *demo_settings_data;
const void *rom_004E89_data;
const void *rom_004E8A_data;
const void *demo_inputs_data;
const void *rom_004E98_data;
const void *rom_004E9C_data;
const void *rom_004EA0_data;
const void *rom_00584C_data;
const void *rom_005850_data;
const void *indexed_table_of_32_bit_values_0059A6_data;
const void *rom_0059B6_data;
const void *rom_0059C6_data;
const void *rom_0059CA_data;
const void *rom_0059CE_data;
const void *rom_0059D2_data;
const void *rom_0059DE_data;
const void *unexplained_005B40_data;
const void *rom_005B44_data;
const void *indexed_table_of_8_bit_values_006146_data;
const void *indexed_table_of_8_bit_values_00634C_data;
const void *rom_00634D_data;
const void *area_tile_banks_data;
const void *rom_00676F_data;
const void *area_layer_priorities_data;
const void *area_settings_060127_data;
const void *indexed_table_of_8_bit_values_006A18_data;
const void *indexed_table_of_8_bit_values_006DFC_data;
const void *indexed_table_of_16_bit_values_0072E2_data;
const void *rom_0072E4_data;
const void *indexed_table_of_8_bit_values_007592_data;
const void *rom_007593_data;
const void *rom_007594_data;
const void *rom_007595_data;
const void *unexplained_00917E_data;
const void *rom_009182_data;
const void *indexed_table_of_32_bit_values_009310_data;
const void *rom_009334_data;
const void *palette_bank_counts_data;
const void *palette_bank_addresses_data;
const void *indexed_table_of_32_bit_values_00975C_data;
const void *indexed_table_of_32_bit_values_0098F2_data;
const void *palettes_009A7C_data;
const void *palette_effects_009AD2_data;
const void *palette_effects_009B28_data;
const void *indexed_table_of_32_bit_values_009C30_data;
const void *indexed_table_of_32_bit_values_009EFA_data;
const void *rom_009F16_data;
const void *rom_009F1A_data;
const void *rom_009F1E_data;
const void *rom_009F22_data;
const void *rom_009F26_data;
const void *rom_009F2A_data;
const void *rom_009F2E_data;
const void *rom_009F46_data;
const void *indexed_table_of_32_bit_values_00DF92_data;
const void *indexed_table_of_32_bit_values_00E082_data;
const void *indexed_table_of_32_bit_values_00E13C_data;
const void *indexed_table_of_32_bit_values_00E1C0_data;
const void *indexed_table_of_32_bit_values_00E2F0_data;
const void *indexed_table_of_32_bit_values_00E3B0_data;
const void *indexed_table_of_16_bit_values_00E48A_data;
const void *indexed_table_of_32_bit_values_00E546_data;
const void *indexed_table_of_32_bit_values_00E582_data;
const void *indexed_table_of_8_bit_values_00E700_data;
const void *indexed_table_of_16_bit_values_00EB1E_data;
const void *rom_00EB20_data;
const void *rom_00EC9C_data;
const void *rom_00ECA0_data;
const void *rom_00ECA4_data;
const void *rom_00ECA8_data;
const void *rom_00ECAC_data;
const void *rom_00ECB0_data;
const void *rom_00ECB4_data;
const void *rom_00ECB8_data;
const void *rom_00ECBC_data;
const void *rom_00ECC0_data;
const void *rom_00ECC4_data;
const void *rom_00ECC8_data;
const void *rom_00ECCC_data;
const void *rom_00ECD0_data;
const void *rom_00ECD4_data;
const void *animations_00F674_data;
const void *rom_00F678_data;
const void *animations_00F760_data;
const void *rom_00F76C_data;
const void *indexed_table_of_16_bit_values_00F938_data;
const void *indexed_table_of_32_bit_values_00FF60_data;
const void *indexed_table_of_8_bit_values_010012_data;
const void *indexed_table_of_32_bit_values_010148_data;
const void *indexed_table_of_16_bit_values_010232_data;
const void *indexed_table_of_32_bit_values_010616_data;
const void *indexed_table_of_8_bit_values_0107AE_data;
const void *nozzle_row_routines_data;
const void *indexed_table_of_32_bit_values_010AB2_data;
const void *indexed_table_of_32_bit_values_010B7E_data;
const void *indexed_table_of_8_bit_values_010EAA_data;
const void *rom_010EAE_data;
const void *indexed_table_of_16_bit_values_010F1C_data;
const void *rom_010F1E_data;
const void *rom_010F44_data;
const void *indexed_table_of_16_bit_values_010F62_data;
const void *rom_010F64_data;
const void *indexed_table_of_16_bit_values_0113BE_data;
const void *rom_0113C0_data;
const void *indexed_table_of_32_bit_values_011562_data;
const void *rom_011782_data;
const void *indexed_table_of_32_bit_values_0119F2_data;
const void *indexed_table_of_8_bit_values_011D1A_data;
const void *indexed_table_of_8_bit_values_011DEE_data;
const void *rom_011DF2_data;
const void *indexed_table_of_8_bit_values_012108_data;
const void *rom_012109_data;
const void *indexed_table_of_32_bit_values_0121AC_data;
const void *rom_012360_data;
const void *indexed_table_of_8_bit_values_01255E_data;
const void *rom_012628_data;
const void *indexed_table_of_16_bit_values_012CFE_data;
const void *indexed_table_of_16_bit_values_013092_data;
const void *indexed_table_of_16_bit_values_0130F4_data;
const void *rom_0130FC_data;
const void *indexed_table_of_32_bit_values_0134CA_data;
const void *indexed_table_of_16_bit_values_0138AC_data;
const void *rom_0138B4_data;
const void *indexed_table_of_8_bit_values_0139A2_data;
const void *indexed_table_of_8_bit_values_0139D6_data;
const void *rom_0139DA_data;
const void *rom_0139DC_data;
const void *indexed_table_of_8_bit_values_013A74_data;
const void *indexed_table_of_32_bit_values_013C46_data;
const void *indexed_table_of_8_bit_values_013E30_data;
const void *indexed_table_of_32_bit_values_013F08_data;
const void *indexed_table_of_16_bit_values_01416E_data;
const void *rom_0141B4_data;
const void *indexed_table_of_8_bit_values_01424A_data;
const void *indexed_table_of_16_bit_values_01426A_data;
const void *rom_01426C_data;
const void *animations_0143D4_data;
const void *rom_01443E_data;
const void *rom_014442_data;
const void *rom_014446_data;
const void *rom_01444A_data;
const void *rom_0144E8_data;
const void *rom_014598_data;
const void *rom_01459C_data;
const void *rom_0145A0_data;
const void *rom_0145FC_data;
const void *rom_014600_data;
const void *rom_01461A_data;
const void *rom_01461E_data;
const void *rom_014636_data;
const void *rom_01480E_data;
const void *rom_014812_data;
const void *rom_014860_data;
const void *rom_014864_data;
const void *rom_014868_data;
const void *rom_01488A_data;
const void *rom_01488E_data;
const void *rom_014892_data;
const void *rom_014896_data;
const void *rom_01489A_data;
const void *rom_014A26_data;
const void *rom_014A2A_data;
const void *rom_014A2E_data;
const void *rom_014AA2_data;
const void *rom_014AA6_data;
const void *rom_014AD6_data;
const void *rom_014ADA_data;
const void *rom_014ADE_data;
const void *rom_014AE2_data;
const void *rom_014BA0_data;
const void *rom_014C3A_data;
const void *rom_014C86_data;
const void *rom_014D1C_data;
const void *rom_014DA0_data;
const void *rom_014DA4_data;
const void *rom_014DA8_data;
const void *rom_014DAC_data;
const void *rom_014DB0_data;
const void *rom_014FBE_data;
const void *rom_015042_data;
const void *rom_015046_data;
const void *rom_01504E_data;
const void *rom_0150E8_data;
const void *rom_0150EC_data;
const void *rom_01519C_data;
const void *rom_0151AA_data;
const void *rom_015258_data;
const void *rom_0152EE_data;
const void *rom_0152F2_data;
const void *rom_01534A_data;
const void *rom_015360_data;
const void *rom_015368_data;
const void *rom_01536C_data;
const void *rom_0153D8_data;
const void *rom_0153DC_data;
const void *rom_0153E0_data;
const void *rom_0153E4_data;
const void *rom_0153E8_data;
const void *rom_015692_data;
const void *rom_0156DA_data;
const void *rom_0156F0_data;
const void *rom_0156FE_data;
const void *rom_01574E_data;
const void *rom_015764_data;
const void *rom_01579C_data;
const void *rom_0157A0_data;
const void *rom_0157A4_data;
const void *rom_015838_data;
const void *rom_01584E_data;
const void *rom_01587E_data;
const void *rom_015882_data;
const void *rom_015938_data;
const void *rom_01593C_data;
const void *rom_015950_data;
const void *rom_015AA0_data;
const void *rom_015B36_data;
const void *rom_015C70_data;
const void *rom_015C74_data;
const void *rom_015C78_data;
const void *rom_015C7C_data;
const void *rom_015D4A_data;
const void *rom_015D68_data;
const void *rom_015E02_data;
const void *rom_015E06_data;
const void *rom_015EBE_data;
const void *rom_015EC2_data;
const void *rom_015EEA_data;
const void *rom_015EEE_data;
const void *indexed_table_of_8_bit_values_0184C2_data;
const void *rom_018560_data;
const void *unexplained_01867E_data;
const void *unexplained_018710_data;
const void *texts_019272_data;
const void *rom_019866_data;
const void *indexed_table_of_32_bit_values_019D54_data;
const void *rom_019EB2_data;
const void *rom_019EB4_data;
const void *rom_019EB6_data;
const void *animations_019F24_data;
const void *indexed_table_of_32_bit_values_019F92_data;
const void *indexed_table_of_32_bit_values_019FDE_data;
const void *indexed_table_of_32_bit_values_01A14E_data;
const void *indexed_table_of_8_bit_values_01A2D2_data;
const void *indexed_table_of_8_bit_values_01A3C0_data;
const void *indexed_table_of_32_bit_values_01A88C_data;
const void *indexed_table_of_32_bit_values_01AC9A_data;
const void *indexed_table_of_32_bit_values_01B714_data;
const void *indexed_table_of_32_bit_values_01BA88_data;
const void *indexed_table_of_16_bit_values_01C072_data;
const void *rom_01C074_data;
const void *animations_01C08A_data;
const void *indexed_table_of_8_bit_values_01C20E_data;
const void *indexed_table_of_32_bit_values_01C272_data;
const void *table_loaded_by_lea_01C546_data;
const void *rom_01C596_data;
const void *indexed_table_of_32_bit_values_01C678_data;
const void *indexed_table_of_32_bit_values_01C764_data;
const void *indexed_table_of_32_bit_values_01C7D0_data;
const void *indexed_table_of_32_bit_values_01C8CA_data;
const void *indexed_table_of_32_bit_values_01C8F8_data;
const void *indexed_table_of_32_bit_values_01CA82_data;
const void *indexed_table_of_32_bit_values_01CAC2_data;
const void *indexed_table_of_32_bit_values_01CC6E_data;
const void *indexed_table_of_32_bit_values_01CCAA_data;
const void *indexed_table_of_32_bit_values_01CD44_data;
const void *indexed_table_of_32_bit_values_01CDBC_data;
const void *indexed_table_of_32_bit_values_01CE52_data;
const void *indexed_table_of_32_bit_values_01CF4E_data;
const void *indexed_table_of_32_bit_values_01D028_data;
const void *indexed_table_of_32_bit_values_01D100_data;
const void *indexed_table_of_8_bit_values_01D200_data;
const void *rom_01D3FC_data;
const void *indexed_table_of_8_bit_values_01D526_data;
const void *rom_01D556_data;
const void *rom_01D592_data;
const void *rom_01D5F2_data;
const void *indexed_table_of_32_bit_values_01E2DA_data;
const void *area_layers_data;
const void *rom_01E5A4_data;
const void *rom_01E5A8_data;
const void *rom_01E5AC_data;
const void *rom_01E5B0_data;
const void *rom_01E5B4_data;
const void *rom_01E5B8_data;
const void *rom_01E5BC_data;
const void *rom_01E5C0_data;
const void *rom_01E5C2_data;
const void *indexed_table_of_32_bit_values_01ECEC_data;
const void *indexed_table_of_32_bit_values_01F43A_data;
const void *indexed_table_of_32_bit_values_01F82C_data;
const void *indexed_table_of_32_bit_values_01FC96_data;
const void *fire_tiles_data;
const void *fire_tiles_area_0_data;
const void *area_scroll_segments_data;
const void *animations_0208C0_data;
const void *indexed_table_of_32_bit_values_02B2C6_data;
const void *indexed_table_of_32_bit_values_02B62A_data;
const void *indexed_table_of_32_bit_values_02B728_data;
const void *indexed_table_of_32_bit_values_02BB16_data;
const void *animations_02BC56_data;
const void *indexed_table_of_32_bit_values_02BC98_data;
const void *indexed_table_of_32_bit_values_02BD44_data;
const void *indexed_table_of_32_bit_values_02BF10_data;
const void *indexed_table_of_32_bit_values_02C04C_data;
const void *indexed_table_of_16_bit_values_02C0F0_data;
const void *rom_02C0F2_data;
const void *indexed_table_of_16_bit_values_02C3BA_data;
const void *rom_02C3BC_data;
const void *indexed_table_of_32_bit_values_02C93A_data;
const void *indexed_table_of_16_bit_values_02CE62_data;
const void *rom_02CE64_data;
const void *indexed_table_of_32_bit_values_02CE8E_data;
const void *indexed_table_of_16_bit_values_02D304_data;
const void *rom_02D306_data;
const void *rom_02D308_data;
const void *rom_02D30A_data;
const void *animations_02D4F4_data;
const void *indexed_table_of_32_bit_values_02D616_data;
const void *indexed_table_of_32_bit_values_02F654_data;
const void *indexed_table_of_32_bit_values_02F8C6_data;
const void *indexed_table_of_16_bit_values_02FBE0_data;
const void *indexed_table_of_32_bit_values_0303EE_data;
const void *indexed_table_of_8_bit_values_030652_data;
const void *rom_030653_data;
const void *indexed_table_of_32_bit_values_030996_data;
const void *indexed_table_of_32_bit_values_031152_data;
const void *attack_check_objects_data;
const void *object_group_counts_data;
const void *object_groups_data;
const void *rom_04881C_data;
const void *rom_048830_data;
const void *indexed_table_of_8_bit_values_048C5E_data;
const void *animations_04A8A4_data;
const void *rom_04B7DE_data;
const void *animations_04BFD6_data;
const void *rom_04BFDA_data;
const void *indexed_table_of_8_bit_values_04C3EE_data;
const void *rom_04D764_data;
const void *indexed_table_of_8_bit_values_04DD2C_data;
const void *indexed_table_of_8_bit_values_04EFD0_data;
const void *animations_04EFD4_data;
const void *indexed_table_of_32_bit_values_04EFE0_data;
const void *indexed_table_of_16_bit_values_04F58C_data;
const void *rom_04F58E_data;
const void *rom_04F5B4_data;
const void *rom_04F5C4_data;
const void *rom_04F5CC_data;
const void *indexed_table_of_8_bit_values_04F6B6_data;
const void *animations_04F9DA_data;
const void *indexed_table_of_32_bit_values_04F9DE_data;
const void *animations_04FE56_data;
const void *animations_04FEBE_data;
const void *animations_04FEF6_data;
const void *animations_050692_data;
const void *animations_05101E_data;
const void *indexed_table_of_16_bit_values_05102A_data;
const void *rom_05102C_data;
const void *rom_051036_data;
const void *animations_0518CC_data;
const void *animations_051AE2_data;
const void *table_loaded_by_lea_051AEE_data;
const void *rom_051F9C_data;
const void *indexed_table_of_8_bit_values_052918_data;
const void *indexed_table_of_8_bit_values_052A60_data;
const void *rom_052ADE_data;
const void *indexed_table_of_16_bit_values_052B3A_data;
const void *indexed_table_of_16_bit_values_052B7C_data;
const void *rom_053896_data;

/* the tables the game loads from its assets: their names, addresses, pointers and the bytes of
   their elements (the loader puts each element in the host's byte order) */
const game_table game_tables[] =
{
	{ "indexed_table_of_32_bit_values_0013DE", 0x0013DEu, &indexed_table_of_32_bit_values_0013DE_data, 4 },
	{ "rom_001426", 0x001426u, &rom_001426_data, 1 },
	{ "rom_001452", 0x001452u, &rom_001452_data, 1 },
	{ "rom_001453", 0x001453u, &rom_001453_data, 1 },
	{ "rom_001472", 0x001472u, &rom_001472_data, 1 },
	{ "rom_001473", 0x001473u, &rom_001473_data, 1 },
	{ "indexed_table_of_32_bit_values_0015AC", 0x0015ACu, &indexed_table_of_32_bit_values_0015AC_data, 4 },
	{ "text_colours", 0x001F1Au, &text_colours_data, 1 },
	{ "rom_001F1B", 0x001F1Bu, &rom_001F1B_data, 1 },
	{ "indexed_table_of_32_bit_values_002678", 0x002678u, &indexed_table_of_32_bit_values_002678_data, 4 },
	{ "text_layer_places", 0x0027A2u, &text_layer_places_data, 4 },
	{ "big_font_place", 0x002802u, &big_font_place_data, 4 },
	{ "indexed_table_of_8_bit_values_002884", 0x002884u, &indexed_table_of_8_bit_values_002884_data, 1 },
	{ "rom_002885", 0x002885u, &rom_002885_data, 1 },
	{ "indexed_table_of_32_bit_values_0031F2", 0x0031F2u, &indexed_table_of_32_bit_values_0031F2_data, 4 },
	{ "rom_00332A", 0x00332Au, &rom_00332A_data, 4 },
	{ "rom_0033A2", 0x0033A2u, &rom_0033A2_data, 1 },
	{ "rom_0033A3", 0x0033A3u, &rom_0033A3_data, 1 },
	{ "rom_0033B6", 0x0033B6u, &rom_0033B6_data, 1 },
	{ "rom_0033B7", 0x0033B7u, &rom_0033B7_data, 1 },
	{ "rom_003402", 0x003402u, &rom_003402_data, 4 },
	{ "positioned_texts", 0x0035ACu, &positioned_texts_data, 4 },
	{ "indexed_table_of_32_bit_values_003E60", 0x003E60u, &indexed_table_of_32_bit_values_003E60_data, 4 },
	{ "indexed_table_of_32_bit_values_003F8E", 0x003F8Eu, &indexed_table_of_32_bit_values_003F8E_data, 4 },
	{ "indexed_table_of_32_bit_values_004100", 0x004100u, &indexed_table_of_32_bit_values_004100_data, 4 },
	{ "indexed_table_of_32_bit_values_00413A", 0x00413Au, &indexed_table_of_32_bit_values_00413A_data, 4 },
	{ "demo_settings", 0x004E88u, &demo_settings_data, 1 },
	{ "rom_004E89", 0x004E89u, &rom_004E89_data, 1 },
	{ "rom_004E8A", 0x004E8Au, &rom_004E8A_data, 1 },
	{ "demo_inputs", 0x004E94u, &demo_inputs_data, 4 },
	{ "rom_004E98", 0x004E98u, &rom_004E98_data, 4 },
	{ "rom_004E9C", 0x004E9Cu, &rom_004E9C_data, 4 },
	{ "rom_004EA0", 0x004EA0u, &rom_004EA0_data, 4 },
	{ "rom_00584C", 0x00584Cu, &rom_00584C_data, 4 },
	{ "rom_005850", 0x005850u, &rom_005850_data, 4 },
	{ "indexed_table_of_32_bit_values_0059A6", 0x0059A6u, &indexed_table_of_32_bit_values_0059A6_data, 4 },
	{ "rom_0059B6", 0x0059B6u, &rom_0059B6_data, 4 },
	{ "rom_0059C6", 0x0059C6u, &rom_0059C6_data, 4 },
	{ "rom_0059CA", 0x0059CAu, &rom_0059CA_data, 4 },
	{ "rom_0059CE", 0x0059CEu, &rom_0059CE_data, 4 },
	{ "rom_0059D2", 0x0059D2u, &rom_0059D2_data, 4 },
	{ "rom_0059DE", 0x0059DEu, &rom_0059DE_data, 4 },
	{ "unexplained_005B40", 0x005B40u, &unexplained_005B40_data, 4 },
	{ "rom_005B44", 0x005B44u, &rom_005B44_data, 4 },
	{ "indexed_table_of_8_bit_values_006146", 0x006146u, &indexed_table_of_8_bit_values_006146_data, 1 },
	{ "indexed_table_of_8_bit_values_00634C", 0x00634Cu, &indexed_table_of_8_bit_values_00634C_data, 1 },
	{ "rom_00634D", 0x00634Du, &rom_00634D_data, 1 },
	{ "area_tile_banks", 0x00676Eu, &area_tile_banks_data, 1 },
	{ "rom_00676F", 0x00676Fu, &rom_00676F_data, 1 },
	{ "area_layer_priorities", 0x006782u, &area_layer_priorities_data, 1 },
	{ "area_settings_060127", 0x00678Cu, &area_settings_060127_data, 1 },
	{ "indexed_table_of_8_bit_values_006A18", 0x006A18u, &indexed_table_of_8_bit_values_006A18_data, 1 },
	{ "indexed_table_of_8_bit_values_006DFC", 0x006DFCu, &indexed_table_of_8_bit_values_006DFC_data, 1 },
	{ "indexed_table_of_16_bit_values_0072E2", 0x0072E2u, &indexed_table_of_16_bit_values_0072E2_data, 2 },
	{ "rom_0072E4", 0x0072E4u, &rom_0072E4_data, 2 },
	{ "indexed_table_of_8_bit_values_007592", 0x007592u, &indexed_table_of_8_bit_values_007592_data, 1 },
	{ "rom_007593", 0x007593u, &rom_007593_data, 1 },
	{ "rom_007594", 0x007594u, &rom_007594_data, 1 },
	{ "rom_007595", 0x007595u, &rom_007595_data, 1 },
	{ "unexplained_00917E", 0x00917Eu, &unexplained_00917E_data, 4 },
	{ "rom_009182", 0x009182u, &rom_009182_data, 4 },
	{ "indexed_table_of_32_bit_values_009310", 0x009310u, &indexed_table_of_32_bit_values_009310_data, 4 },
	{ "rom_009334", 0x009334u, &rom_009334_data, 4 },
	{ "palette_bank_counts", 0x0095D2u, &palette_bank_counts_data, 1 },
	{ "palette_bank_addresses", 0x0095D6u, &palette_bank_addresses_data, 4 },
	{ "indexed_table_of_32_bit_values_00975C", 0x00975Cu, &indexed_table_of_32_bit_values_00975C_data, 4 },
	{ "indexed_table_of_32_bit_values_0098F2", 0x0098F2u, &indexed_table_of_32_bit_values_0098F2_data, 4 },
	{ "palettes_009A7C", 0x009A7Cu, &palettes_009A7C_data, 4 },
	{ "palette_effects_009AD2", 0x009AD2u, &palette_effects_009AD2_data, 4 },
	{ "palette_effects_009B28", 0x009B28u, &palette_effects_009B28_data, 4 },
	{ "indexed_table_of_32_bit_values_009C30", 0x009C30u, &indexed_table_of_32_bit_values_009C30_data, 4 },
	{ "indexed_table_of_32_bit_values_009EFA", 0x009EFAu, &indexed_table_of_32_bit_values_009EFA_data, 4 },
	{ "rom_009F16", 0x009F16u, &rom_009F16_data, 1 },
	{ "rom_009F1A", 0x009F1Au, &rom_009F1A_data, 4 },
	{ "rom_009F1E", 0x009F1Eu, &rom_009F1E_data, 1 },
	{ "rom_009F22", 0x009F22u, &rom_009F22_data, 4 },
	{ "rom_009F26", 0x009F26u, &rom_009F26_data, 4 },
	{ "rom_009F2A", 0x009F2Au, &rom_009F2A_data, 4 },
	{ "rom_009F2E", 0x009F2Eu, &rom_009F2E_data, 4 },
	{ "rom_009F46", 0x009F46u, &rom_009F46_data, 1 },
	{ "indexed_table_of_32_bit_values_00DF92", 0x00DF92u, &indexed_table_of_32_bit_values_00DF92_data, 4 },
	{ "indexed_table_of_32_bit_values_00E082", 0x00E082u, &indexed_table_of_32_bit_values_00E082_data, 4 },
	{ "indexed_table_of_32_bit_values_00E13C", 0x00E13Cu, &indexed_table_of_32_bit_values_00E13C_data, 4 },
	{ "indexed_table_of_32_bit_values_00E1C0", 0x00E1C0u, &indexed_table_of_32_bit_values_00E1C0_data, 4 },
	{ "indexed_table_of_32_bit_values_00E2F0", 0x00E2F0u, &indexed_table_of_32_bit_values_00E2F0_data, 4 },
	{ "indexed_table_of_32_bit_values_00E3B0", 0x00E3B0u, &indexed_table_of_32_bit_values_00E3B0_data, 4 },
	{ "indexed_table_of_16_bit_values_00E48A", 0x00E48Au, &indexed_table_of_16_bit_values_00E48A_data, 2 },
	{ "indexed_table_of_32_bit_values_00E546", 0x00E546u, &indexed_table_of_32_bit_values_00E546_data, 4 },
	{ "indexed_table_of_32_bit_values_00E582", 0x00E582u, &indexed_table_of_32_bit_values_00E582_data, 4 },
	{ "indexed_table_of_8_bit_values_00E700", 0x00E700u, &indexed_table_of_8_bit_values_00E700_data, 1 },
	{ "indexed_table_of_16_bit_values_00EB1E", 0x00EB1Eu, &indexed_table_of_16_bit_values_00EB1E_data, 2 },
	{ "rom_00EB20", 0x00EB20u, &rom_00EB20_data, 2 },
	{ "rom_00EC9C", 0x00EC9Cu, &rom_00EC9C_data, 4 },
	{ "rom_00ECA0", 0x00ECA0u, &rom_00ECA0_data, 4 },
	{ "rom_00ECA4", 0x00ECA4u, &rom_00ECA4_data, 4 },
	{ "rom_00ECA8", 0x00ECA8u, &rom_00ECA8_data, 4 },
	{ "rom_00ECAC", 0x00ECACu, &rom_00ECAC_data, 4 },
	{ "rom_00ECB0", 0x00ECB0u, &rom_00ECB0_data, 4 },
	{ "rom_00ECB4", 0x00ECB4u, &rom_00ECB4_data, 4 },
	{ "rom_00ECB8", 0x00ECB8u, &rom_00ECB8_data, 4 },
	{ "rom_00ECBC", 0x00ECBCu, &rom_00ECBC_data, 4 },
	{ "rom_00ECC0", 0x00ECC0u, &rom_00ECC0_data, 4 },
	{ "rom_00ECC4", 0x00ECC4u, &rom_00ECC4_data, 4 },
	{ "rom_00ECC8", 0x00ECC8u, &rom_00ECC8_data, 4 },
	{ "rom_00ECCC", 0x00ECCCu, &rom_00ECCC_data, 4 },
	{ "rom_00ECD0", 0x00ECD0u, &rom_00ECD0_data, 4 },
	{ "rom_00ECD4", 0x00ECD4u, &rom_00ECD4_data, 4 },
	{ "animations_00F674", 0x00F674u, &animations_00F674_data, 4 },
	{ "rom_00F678", 0x00F678u, &rom_00F678_data, 4 },
	{ "animations_00F760", 0x00F760u, &animations_00F760_data, 4 },
	{ "rom_00F76C", 0x00F76Cu, &rom_00F76C_data, 4 },
	{ "indexed_table_of_16_bit_values_00F938", 0x00F938u, &indexed_table_of_16_bit_values_00F938_data, 2 },
	{ "indexed_table_of_32_bit_values_00FF60", 0x00FF60u, &indexed_table_of_32_bit_values_00FF60_data, 4 },
	{ "indexed_table_of_8_bit_values_010012", 0x010012u, &indexed_table_of_8_bit_values_010012_data, 1 },
	{ "indexed_table_of_32_bit_values_010148", 0x010148u, &indexed_table_of_32_bit_values_010148_data, 4 },
	{ "indexed_table_of_16_bit_values_010232", 0x010232u, &indexed_table_of_16_bit_values_010232_data, 2 },
	{ "indexed_table_of_32_bit_values_010616", 0x010616u, &indexed_table_of_32_bit_values_010616_data, 4 },
	{ "indexed_table_of_8_bit_values_0107AE", 0x0107AEu, &indexed_table_of_8_bit_values_0107AE_data, 1 },
	{ "nozzle_row_routines", 0x010A0Eu, &nozzle_row_routines_data, 4 },
	{ "indexed_table_of_32_bit_values_010AB2", 0x010AB2u, &indexed_table_of_32_bit_values_010AB2_data, 4 },
	{ "indexed_table_of_32_bit_values_010B7E", 0x010B7Eu, &indexed_table_of_32_bit_values_010B7E_data, 4 },
	{ "indexed_table_of_8_bit_values_010EAA", 0x010EAAu, &indexed_table_of_8_bit_values_010EAA_data, 1 },
	{ "rom_010EAE", 0x010EAEu, &rom_010EAE_data, 2 },
	{ "indexed_table_of_16_bit_values_010F1C", 0x010F1Cu, &indexed_table_of_16_bit_values_010F1C_data, 2 },
	{ "rom_010F1E", 0x010F1Eu, &rom_010F1E_data, 2 },
	{ "rom_010F44", 0x010F44u, &rom_010F44_data, 1 },
	{ "indexed_table_of_16_bit_values_010F62", 0x010F62u, &indexed_table_of_16_bit_values_010F62_data, 2 },
	{ "rom_010F64", 0x010F64u, &rom_010F64_data, 2 },
	{ "indexed_table_of_16_bit_values_0113BE", 0x0113BEu, &indexed_table_of_16_bit_values_0113BE_data, 2 },
	{ "rom_0113C0", 0x0113C0u, &rom_0113C0_data, 2 },
	{ "indexed_table_of_32_bit_values_011562", 0x011562u, &indexed_table_of_32_bit_values_011562_data, 4 },
	{ "rom_011782", 0x011782u, &rom_011782_data, 4 },
	{ "indexed_table_of_32_bit_values_0119F2", 0x0119F2u, &indexed_table_of_32_bit_values_0119F2_data, 4 },
	{ "indexed_table_of_8_bit_values_011D1A", 0x011D1Au, &indexed_table_of_8_bit_values_011D1A_data, 1 },
	{ "indexed_table_of_8_bit_values_011DEE", 0x011DEEu, &indexed_table_of_8_bit_values_011DEE_data, 1 },
	{ "rom_011DF2", 0x011DF2u, &rom_011DF2_data, 1 },
	{ "indexed_table_of_8_bit_values_012108", 0x012108u, &indexed_table_of_8_bit_values_012108_data, 1 },
	{ "rom_012109", 0x012109u, &rom_012109_data, 1 },
	{ "indexed_table_of_32_bit_values_0121AC", 0x0121ACu, &indexed_table_of_32_bit_values_0121AC_data, 4 },
	{ "rom_012360", 0x012360u, &rom_012360_data, 4 },
	{ "indexed_table_of_8_bit_values_01255E", 0x01255Eu, &indexed_table_of_8_bit_values_01255E_data, 1 },
	{ "rom_012628", 0x012628u, &rom_012628_data, 1 },
	{ "indexed_table_of_16_bit_values_012CFE", 0x012CFEu, &indexed_table_of_16_bit_values_012CFE_data, 2 },
	{ "indexed_table_of_16_bit_values_013092", 0x013092u, &indexed_table_of_16_bit_values_013092_data, 2 },
	{ "indexed_table_of_16_bit_values_0130F4", 0x0130F4u, &indexed_table_of_16_bit_values_0130F4_data, 2 },
	{ "rom_0130FC", 0x0130FCu, &rom_0130FC_data, 2 },
	{ "indexed_table_of_32_bit_values_0134CA", 0x0134CAu, &indexed_table_of_32_bit_values_0134CA_data, 4 },
	{ "indexed_table_of_16_bit_values_0138AC", 0x0138ACu, &indexed_table_of_16_bit_values_0138AC_data, 2 },
	{ "rom_0138B4", 0x0138B4u, &rom_0138B4_data, 2 },
	{ "indexed_table_of_8_bit_values_0139A2", 0x0139A2u, &indexed_table_of_8_bit_values_0139A2_data, 1 },
	{ "indexed_table_of_8_bit_values_0139D6", 0x0139D6u, &indexed_table_of_8_bit_values_0139D6_data, 1 },
	{ "rom_0139DA", 0x0139DAu, &rom_0139DA_data, 2 },
	{ "rom_0139DC", 0x0139DCu, &rom_0139DC_data, 2 },
	{ "indexed_table_of_8_bit_values_013A74", 0x013A74u, &indexed_table_of_8_bit_values_013A74_data, 1 },
	{ "indexed_table_of_32_bit_values_013C46", 0x013C46u, &indexed_table_of_32_bit_values_013C46_data, 4 },
	{ "indexed_table_of_8_bit_values_013E30", 0x013E30u, &indexed_table_of_8_bit_values_013E30_data, 1 },
	{ "indexed_table_of_32_bit_values_013F08", 0x013F08u, &indexed_table_of_32_bit_values_013F08_data, 4 },
	{ "indexed_table_of_16_bit_values_01416E", 0x01416Eu, &indexed_table_of_16_bit_values_01416E_data, 2 },
	{ "rom_0141B4", 0x0141B4u, &rom_0141B4_data, 2 },
	{ "indexed_table_of_8_bit_values_01424A", 0x01424Au, &indexed_table_of_8_bit_values_01424A_data, 1 },
	{ "indexed_table_of_16_bit_values_01426A", 0x01426Au, &indexed_table_of_16_bit_values_01426A_data, 2 },
	{ "rom_01426C", 0x01426Cu, &rom_01426C_data, 2 },
	{ "animations_0143D4", 0x0143D4u, &animations_0143D4_data, 4 },
	{ "rom_01443E", 0x01443Eu, &rom_01443E_data, 4 },
	{ "rom_014442", 0x014442u, &rom_014442_data, 4 },
	{ "rom_014446", 0x014446u, &rom_014446_data, 4 },
	{ "rom_01444A", 0x01444Au, &rom_01444A_data, 4 },
	{ "rom_0144E8", 0x0144E8u, &rom_0144E8_data, 4 },
	{ "rom_014598", 0x014598u, &rom_014598_data, 4 },
	{ "rom_01459C", 0x01459Cu, &rom_01459C_data, 4 },
	{ "rom_0145A0", 0x0145A0u, &rom_0145A0_data, 4 },
	{ "rom_0145FC", 0x0145FCu, &rom_0145FC_data, 4 },
	{ "rom_014600", 0x014600u, &rom_014600_data, 4 },
	{ "rom_01461A", 0x01461Au, &rom_01461A_data, 4 },
	{ "rom_01461E", 0x01461Eu, &rom_01461E_data, 4 },
	{ "rom_014636", 0x014636u, &rom_014636_data, 4 },
	{ "rom_01480E", 0x01480Eu, &rom_01480E_data, 4 },
	{ "rom_014812", 0x014812u, &rom_014812_data, 4 },
	{ "rom_014860", 0x014860u, &rom_014860_data, 4 },
	{ "rom_014864", 0x014864u, &rom_014864_data, 4 },
	{ "rom_014868", 0x014868u, &rom_014868_data, 4 },
	{ "rom_01488A", 0x01488Au, &rom_01488A_data, 4 },
	{ "rom_01488E", 0x01488Eu, &rom_01488E_data, 4 },
	{ "rom_014892", 0x014892u, &rom_014892_data, 4 },
	{ "rom_014896", 0x014896u, &rom_014896_data, 4 },
	{ "rom_01489A", 0x01489Au, &rom_01489A_data, 4 },
	{ "rom_014A26", 0x014A26u, &rom_014A26_data, 4 },
	{ "rom_014A2A", 0x014A2Au, &rom_014A2A_data, 4 },
	{ "rom_014A2E", 0x014A2Eu, &rom_014A2E_data, 4 },
	{ "rom_014AA2", 0x014AA2u, &rom_014AA2_data, 4 },
	{ "rom_014AA6", 0x014AA6u, &rom_014AA6_data, 4 },
	{ "rom_014AD6", 0x014AD6u, &rom_014AD6_data, 4 },
	{ "rom_014ADA", 0x014ADAu, &rom_014ADA_data, 4 },
	{ "rom_014ADE", 0x014ADEu, &rom_014ADE_data, 4 },
	{ "rom_014AE2", 0x014AE2u, &rom_014AE2_data, 4 },
	{ "rom_014BA0", 0x014BA0u, &rom_014BA0_data, 4 },
	{ "rom_014C3A", 0x014C3Au, &rom_014C3A_data, 4 },
	{ "rom_014C86", 0x014C86u, &rom_014C86_data, 4 },
	{ "rom_014D1C", 0x014D1Cu, &rom_014D1C_data, 4 },
	{ "rom_014DA0", 0x014DA0u, &rom_014DA0_data, 4 },
	{ "rom_014DA4", 0x014DA4u, &rom_014DA4_data, 4 },
	{ "rom_014DA8", 0x014DA8u, &rom_014DA8_data, 4 },
	{ "rom_014DAC", 0x014DACu, &rom_014DAC_data, 4 },
	{ "rom_014DB0", 0x014DB0u, &rom_014DB0_data, 4 },
	{ "rom_014FBE", 0x014FBEu, &rom_014FBE_data, 4 },
	{ "rom_015042", 0x015042u, &rom_015042_data, 4 },
	{ "rom_015046", 0x015046u, &rom_015046_data, 4 },
	{ "rom_01504E", 0x01504Eu, &rom_01504E_data, 4 },
	{ "rom_0150E8", 0x0150E8u, &rom_0150E8_data, 4 },
	{ "rom_0150EC", 0x0150ECu, &rom_0150EC_data, 4 },
	{ "rom_01519C", 0x01519Cu, &rom_01519C_data, 4 },
	{ "rom_0151AA", 0x0151AAu, &rom_0151AA_data, 4 },
	{ "rom_015258", 0x015258u, &rom_015258_data, 4 },
	{ "rom_0152EE", 0x0152EEu, &rom_0152EE_data, 4 },
	{ "rom_0152F2", 0x0152F2u, &rom_0152F2_data, 4 },
	{ "rom_01534A", 0x01534Au, &rom_01534A_data, 4 },
	{ "rom_015360", 0x015360u, &rom_015360_data, 4 },
	{ "rom_015368", 0x015368u, &rom_015368_data, 4 },
	{ "rom_01536C", 0x01536Cu, &rom_01536C_data, 4 },
	{ "rom_0153D8", 0x0153D8u, &rom_0153D8_data, 4 },
	{ "rom_0153DC", 0x0153DCu, &rom_0153DC_data, 4 },
	{ "rom_0153E0", 0x0153E0u, &rom_0153E0_data, 4 },
	{ "rom_0153E4", 0x0153E4u, &rom_0153E4_data, 4 },
	{ "rom_0153E8", 0x0153E8u, &rom_0153E8_data, 4 },
	{ "rom_015692", 0x015692u, &rom_015692_data, 4 },
	{ "rom_0156DA", 0x0156DAu, &rom_0156DA_data, 4 },
	{ "rom_0156F0", 0x0156F0u, &rom_0156F0_data, 4 },
	{ "rom_0156FE", 0x0156FEu, &rom_0156FE_data, 4 },
	{ "rom_01574E", 0x01574Eu, &rom_01574E_data, 4 },
	{ "rom_015764", 0x015764u, &rom_015764_data, 4 },
	{ "rom_01579C", 0x01579Cu, &rom_01579C_data, 4 },
	{ "rom_0157A0", 0x0157A0u, &rom_0157A0_data, 4 },
	{ "rom_0157A4", 0x0157A4u, &rom_0157A4_data, 4 },
	{ "rom_015838", 0x015838u, &rom_015838_data, 4 },
	{ "rom_01584E", 0x01584Eu, &rom_01584E_data, 4 },
	{ "rom_01587E", 0x01587Eu, &rom_01587E_data, 4 },
	{ "rom_015882", 0x015882u, &rom_015882_data, 4 },
	{ "rom_015938", 0x015938u, &rom_015938_data, 4 },
	{ "rom_01593C", 0x01593Cu, &rom_01593C_data, 4 },
	{ "rom_015950", 0x015950u, &rom_015950_data, 4 },
	{ "rom_015AA0", 0x015AA0u, &rom_015AA0_data, 4 },
	{ "rom_015B36", 0x015B36u, &rom_015B36_data, 4 },
	{ "rom_015C70", 0x015C70u, &rom_015C70_data, 4 },
	{ "rom_015C74", 0x015C74u, &rom_015C74_data, 4 },
	{ "rom_015C78", 0x015C78u, &rom_015C78_data, 4 },
	{ "rom_015C7C", 0x015C7Cu, &rom_015C7C_data, 4 },
	{ "rom_015D4A", 0x015D4Au, &rom_015D4A_data, 4 },
	{ "rom_015D68", 0x015D68u, &rom_015D68_data, 4 },
	{ "rom_015E02", 0x015E02u, &rom_015E02_data, 4 },
	{ "rom_015E06", 0x015E06u, &rom_015E06_data, 4 },
	{ "rom_015EBE", 0x015EBEu, &rom_015EBE_data, 4 },
	{ "rom_015EC2", 0x015EC2u, &rom_015EC2_data, 4 },
	{ "rom_015EEA", 0x015EEAu, &rom_015EEA_data, 4 },
	{ "rom_015EEE", 0x015EEEu, &rom_015EEE_data, 4 },
	{ "indexed_table_of_8_bit_values_0184C2", 0x0184C2u, &indexed_table_of_8_bit_values_0184C2_data, 1 },
	{ "rom_018560", 0x018560u, &rom_018560_data, 1 },
	{ "unexplained_01867E", 0x01867Eu, &unexplained_01867E_data, 4 },
	{ "unexplained_018710", 0x018710u, &unexplained_018710_data, 4 },
	{ "texts_019272", 0x019272u, &texts_019272_data, 4 },
	{ "rom_019866", 0x019866u, &rom_019866_data, 4 },
	{ "indexed_table_of_32_bit_values_019D54", 0x019D54u, &indexed_table_of_32_bit_values_019D54_data, 4 },
	{ "rom_019EB2", 0x019EB2u, &rom_019EB2_data, 2 },
	{ "rom_019EB4", 0x019EB4u, &rom_019EB4_data, 2 },
	{ "rom_019EB6", 0x019EB6u, &rom_019EB6_data, 2 },
	{ "animations_019F24", 0x019F24u, &animations_019F24_data, 4 },
	{ "indexed_table_of_32_bit_values_019F92", 0x019F92u, &indexed_table_of_32_bit_values_019F92_data, 4 },
	{ "indexed_table_of_32_bit_values_019FDE", 0x019FDEu, &indexed_table_of_32_bit_values_019FDE_data, 4 },
	{ "indexed_table_of_32_bit_values_01A14E", 0x01A14Eu, &indexed_table_of_32_bit_values_01A14E_data, 4 },
	{ "indexed_table_of_8_bit_values_01A2D2", 0x01A2D2u, &indexed_table_of_8_bit_values_01A2D2_data, 1 },
	{ "indexed_table_of_8_bit_values_01A3C0", 0x01A3C0u, &indexed_table_of_8_bit_values_01A3C0_data, 1 },
	{ "indexed_table_of_32_bit_values_01A88C", 0x01A88Cu, &indexed_table_of_32_bit_values_01A88C_data, 4 },
	{ "indexed_table_of_32_bit_values_01AC9A", 0x01AC9Au, &indexed_table_of_32_bit_values_01AC9A_data, 4 },
	{ "indexed_table_of_32_bit_values_01B714", 0x01B714u, &indexed_table_of_32_bit_values_01B714_data, 4 },
	{ "indexed_table_of_32_bit_values_01BA88", 0x01BA88u, &indexed_table_of_32_bit_values_01BA88_data, 4 },
	{ "indexed_table_of_16_bit_values_01C072", 0x01C072u, &indexed_table_of_16_bit_values_01C072_data, 2 },
	{ "rom_01C074", 0x01C074u, &rom_01C074_data, 4 },
	{ "animations_01C08A", 0x01C08Au, &animations_01C08A_data, 4 },
	{ "indexed_table_of_8_bit_values_01C20E", 0x01C20Eu, &indexed_table_of_8_bit_values_01C20E_data, 1 },
	{ "indexed_table_of_32_bit_values_01C272", 0x01C272u, &indexed_table_of_32_bit_values_01C272_data, 4 },
	{ "table_loaded_by_lea_01C546", 0x01C546u, &table_loaded_by_lea_01C546_data, 2 },
	{ "rom_01C596", 0x01C596u, &rom_01C596_data, 2 },
	{ "indexed_table_of_32_bit_values_01C678", 0x01C678u, &indexed_table_of_32_bit_values_01C678_data, 4 },
	{ "indexed_table_of_32_bit_values_01C764", 0x01C764u, &indexed_table_of_32_bit_values_01C764_data, 4 },
	{ "indexed_table_of_32_bit_values_01C7D0", 0x01C7D0u, &indexed_table_of_32_bit_values_01C7D0_data, 4 },
	{ "indexed_table_of_32_bit_values_01C8CA", 0x01C8CAu, &indexed_table_of_32_bit_values_01C8CA_data, 4 },
	{ "indexed_table_of_32_bit_values_01C8F8", 0x01C8F8u, &indexed_table_of_32_bit_values_01C8F8_data, 4 },
	{ "indexed_table_of_32_bit_values_01CA82", 0x01CA82u, &indexed_table_of_32_bit_values_01CA82_data, 4 },
	{ "indexed_table_of_32_bit_values_01CAC2", 0x01CAC2u, &indexed_table_of_32_bit_values_01CAC2_data, 4 },
	{ "indexed_table_of_32_bit_values_01CC6E", 0x01CC6Eu, &indexed_table_of_32_bit_values_01CC6E_data, 4 },
	{ "indexed_table_of_32_bit_values_01CCAA", 0x01CCAAu, &indexed_table_of_32_bit_values_01CCAA_data, 4 },
	{ "indexed_table_of_32_bit_values_01CD44", 0x01CD44u, &indexed_table_of_32_bit_values_01CD44_data, 4 },
	{ "indexed_table_of_32_bit_values_01CDBC", 0x01CDBCu, &indexed_table_of_32_bit_values_01CDBC_data, 4 },
	{ "indexed_table_of_32_bit_values_01CE52", 0x01CE52u, &indexed_table_of_32_bit_values_01CE52_data, 4 },
	{ "indexed_table_of_32_bit_values_01CF4E", 0x01CF4Eu, &indexed_table_of_32_bit_values_01CF4E_data, 4 },
	{ "indexed_table_of_32_bit_values_01D028", 0x01D028u, &indexed_table_of_32_bit_values_01D028_data, 4 },
	{ "indexed_table_of_32_bit_values_01D100", 0x01D100u, &indexed_table_of_32_bit_values_01D100_data, 4 },
	{ "indexed_table_of_8_bit_values_01D200", 0x01D200u, &indexed_table_of_8_bit_values_01D200_data, 1 },
	{ "rom_01D3FC", 0x01D3FCu, &rom_01D3FC_data, 1 },
	{ "indexed_table_of_8_bit_values_01D526", 0x01D526u, &indexed_table_of_8_bit_values_01D526_data, 1 },
	{ "rom_01D556", 0x01D556u, &rom_01D556_data, 1 },
	{ "rom_01D592", 0x01D592u, &rom_01D592_data, 2 },
	{ "rom_01D5F2", 0x01D5F2u, &rom_01D5F2_data, 4 },
	{ "indexed_table_of_32_bit_values_01E2DA", 0x01E2DAu, &indexed_table_of_32_bit_values_01E2DA_data, 4 },
	{ "area_layers", 0x01E5A0u, &area_layers_data, 4 },
	{ "rom_01E5A4", 0x01E5A4u, &rom_01E5A4_data, 4 },
	{ "rom_01E5A8", 0x01E5A8u, &rom_01E5A8_data, 4 },
	{ "rom_01E5AC", 0x01E5ACu, &rom_01E5AC_data, 4 },
	{ "rom_01E5B0", 0x01E5B0u, &rom_01E5B0_data, 4 },
	{ "rom_01E5B4", 0x01E5B4u, &rom_01E5B4_data, 4 },
	{ "rom_01E5B8", 0x01E5B8u, &rom_01E5B8_data, 4 },
	{ "rom_01E5BC", 0x01E5BCu, &rom_01E5BC_data, 4 },
	{ "rom_01E5C0", 0x01E5C0u, &rom_01E5C0_data, 2 },
	{ "rom_01E5C2", 0x01E5C2u, &rom_01E5C2_data, 2 },
	{ "indexed_table_of_32_bit_values_01ECEC", 0x01ECECu, &indexed_table_of_32_bit_values_01ECEC_data, 4 },
	{ "indexed_table_of_32_bit_values_01F43A", 0x01F43Au, &indexed_table_of_32_bit_values_01F43A_data, 4 },
	{ "indexed_table_of_32_bit_values_01F82C", 0x01F82Cu, &indexed_table_of_32_bit_values_01F82C_data, 4 },
	{ "indexed_table_of_32_bit_values_01FC96", 0x01FC96u, &indexed_table_of_32_bit_values_01FC96_data, 4 },
	{ "fire_tiles", 0x0200F2u, &fire_tiles_data, 4 },
	{ "fire_tiles_area_0", 0x0203D2u, &fire_tiles_area_0_data, 4 },
	{ "area_scroll_segments", 0x0205F2u, &area_scroll_segments_data, 4 },
	{ "animations_0208C0", 0x0208C0u, &animations_0208C0_data, 4 },
	{ "indexed_table_of_32_bit_values_02B2C6", 0x02B2C6u, &indexed_table_of_32_bit_values_02B2C6_data, 4 },
	{ "indexed_table_of_32_bit_values_02B62A", 0x02B62Au, &indexed_table_of_32_bit_values_02B62A_data, 4 },
	{ "indexed_table_of_32_bit_values_02B728", 0x02B728u, &indexed_table_of_32_bit_values_02B728_data, 4 },
	{ "indexed_table_of_32_bit_values_02BB16", 0x02BB16u, &indexed_table_of_32_bit_values_02BB16_data, 4 },
	{ "animations_02BC56", 0x02BC56u, &animations_02BC56_data, 4 },
	{ "indexed_table_of_32_bit_values_02BC98", 0x02BC98u, &indexed_table_of_32_bit_values_02BC98_data, 4 },
	{ "indexed_table_of_32_bit_values_02BD44", 0x02BD44u, &indexed_table_of_32_bit_values_02BD44_data, 4 },
	{ "indexed_table_of_32_bit_values_02BF10", 0x02BF10u, &indexed_table_of_32_bit_values_02BF10_data, 4 },
	{ "indexed_table_of_32_bit_values_02C04C", 0x02C04Cu, &indexed_table_of_32_bit_values_02C04C_data, 4 },
	{ "indexed_table_of_16_bit_values_02C0F0", 0x02C0F0u, &indexed_table_of_16_bit_values_02C0F0_data, 2 },
	{ "rom_02C0F2", 0x02C0F2u, &rom_02C0F2_data, 2 },
	{ "indexed_table_of_16_bit_values_02C3BA", 0x02C3BAu, &indexed_table_of_16_bit_values_02C3BA_data, 2 },
	{ "rom_02C3BC", 0x02C3BCu, &rom_02C3BC_data, 2 },
	{ "indexed_table_of_32_bit_values_02C93A", 0x02C93Au, &indexed_table_of_32_bit_values_02C93A_data, 4 },
	{ "indexed_table_of_16_bit_values_02CE62", 0x02CE62u, &indexed_table_of_16_bit_values_02CE62_data, 2 },
	{ "rom_02CE64", 0x02CE64u, &rom_02CE64_data, 2 },
	{ "indexed_table_of_32_bit_values_02CE8E", 0x02CE8Eu, &indexed_table_of_32_bit_values_02CE8E_data, 4 },
	{ "indexed_table_of_16_bit_values_02D304", 0x02D304u, &indexed_table_of_16_bit_values_02D304_data, 2 },
	{ "rom_02D306", 0x02D306u, &rom_02D306_data, 2 },
	{ "rom_02D308", 0x02D308u, &rom_02D308_data, 2 },
	{ "rom_02D30A", 0x02D30Au, &rom_02D30A_data, 2 },
	{ "animations_02D4F4", 0x02D4F4u, &animations_02D4F4_data, 4 },
	{ "indexed_table_of_32_bit_values_02D616", 0x02D616u, &indexed_table_of_32_bit_values_02D616_data, 4 },
	{ "indexed_table_of_32_bit_values_02F654", 0x02F654u, &indexed_table_of_32_bit_values_02F654_data, 4 },
	{ "indexed_table_of_32_bit_values_02F8C6", 0x02F8C6u, &indexed_table_of_32_bit_values_02F8C6_data, 4 },
	{ "indexed_table_of_16_bit_values_02FBE0", 0x02FBE0u, &indexed_table_of_16_bit_values_02FBE0_data, 2 },
	{ "indexed_table_of_32_bit_values_0303EE", 0x0303EEu, &indexed_table_of_32_bit_values_0303EE_data, 4 },
	{ "indexed_table_of_8_bit_values_030652", 0x030652u, &indexed_table_of_8_bit_values_030652_data, 1 },
	{ "rom_030653", 0x030653u, &rom_030653_data, 1 },
	{ "indexed_table_of_32_bit_values_030996", 0x030996u, &indexed_table_of_32_bit_values_030996_data, 4 },
	{ "indexed_table_of_32_bit_values_031152", 0x031152u, &indexed_table_of_32_bit_values_031152_data, 4 },
	{ "attack_check_objects", 0x0471F4u, &attack_check_objects_data, 4 },
	{ "object_group_counts", 0x047BDEu, &object_group_counts_data, 1 },
	{ "object_groups", 0x047BE2u, &object_groups_data, 4 },
	{ "rom_04881C", 0x04881Cu, &rom_04881C_data, 2 },
	{ "rom_048830", 0x048830u, &rom_048830_data, 1 },
	{ "indexed_table_of_8_bit_values_048C5E", 0x048C5Eu, &indexed_table_of_8_bit_values_048C5E_data, 1 },
	{ "animations_04A8A4", 0x04A8A4u, &animations_04A8A4_data, 4 },
	{ "rom_04B7DE", 0x04B7DEu, &rom_04B7DE_data, 2 },
	{ "animations_04BFD6", 0x04BFD6u, &animations_04BFD6_data, 4 },
	{ "rom_04BFDA", 0x04BFDAu, &rom_04BFDA_data, 4 },
	{ "indexed_table_of_8_bit_values_04C3EE", 0x04C3EEu, &indexed_table_of_8_bit_values_04C3EE_data, 1 },
	{ "rom_04D764", 0x04D764u, &rom_04D764_data, 1 },
	{ "indexed_table_of_8_bit_values_04DD2C", 0x04DD2Cu, &indexed_table_of_8_bit_values_04DD2C_data, 1 },
	{ "indexed_table_of_8_bit_values_04EFD0", 0x04EFD0u, &indexed_table_of_8_bit_values_04EFD0_data, 1 },
	{ "animations_04EFD4", 0x04EFD4u, &animations_04EFD4_data, 4 },
	{ "indexed_table_of_32_bit_values_04EFE0", 0x04EFE0u, &indexed_table_of_32_bit_values_04EFE0_data, 4 },
	{ "indexed_table_of_16_bit_values_04F58C", 0x04F58Cu, &indexed_table_of_16_bit_values_04F58C_data, 2 },
	{ "rom_04F58E", 0x04F58Eu, &rom_04F58E_data, 2 },
	{ "rom_04F5B4", 0x04F5B4u, &rom_04F5B4_data, 1 },
	{ "rom_04F5C4", 0x04F5C4u, &rom_04F5C4_data, 1 },
	{ "rom_04F5CC", 0x04F5CCu, &rom_04F5CC_data, 1 },
	{ "indexed_table_of_8_bit_values_04F6B6", 0x04F6B6u, &indexed_table_of_8_bit_values_04F6B6_data, 1 },
	{ "animations_04F9DA", 0x04F9DAu, &animations_04F9DA_data, 4 },
	{ "indexed_table_of_32_bit_values_04F9DE", 0x04F9DEu, &indexed_table_of_32_bit_values_04F9DE_data, 4 },
	{ "animations_04FE56", 0x04FE56u, &animations_04FE56_data, 4 },
	{ "animations_04FEBE", 0x04FEBEu, &animations_04FEBE_data, 4 },
	{ "animations_04FEF6", 0x04FEF6u, &animations_04FEF6_data, 4 },
	{ "animations_050692", 0x050692u, &animations_050692_data, 4 },
	{ "animations_05101E", 0x05101Eu, &animations_05101E_data, 4 },
	{ "indexed_table_of_16_bit_values_05102A", 0x05102Au, &indexed_table_of_16_bit_values_05102A_data, 2 },
	{ "rom_05102C", 0x05102Cu, &rom_05102C_data, 2 },
	{ "rom_051036", 0x051036u, &rom_051036_data, 1 },
	{ "animations_0518CC", 0x0518CCu, &animations_0518CC_data, 4 },
	{ "animations_051AE2", 0x051AE2u, &animations_051AE2_data, 4 },
	{ "table_loaded_by_lea_051AEE", 0x051AEEu, &table_loaded_by_lea_051AEE_data, 1 },
	{ "rom_051F9C", 0x051F9Cu, &rom_051F9C_data, 1 },
	{ "indexed_table_of_8_bit_values_052918", 0x052918u, &indexed_table_of_8_bit_values_052918_data, 1 },
	{ "indexed_table_of_8_bit_values_052A60", 0x052A60u, &indexed_table_of_8_bit_values_052A60_data, 1 },
	{ "rom_052ADE", 0x052ADEu, &rom_052ADE_data, 1 },
	{ "indexed_table_of_16_bit_values_052B3A", 0x052B3Au, &indexed_table_of_16_bit_values_052B3A_data, 2 },
	{ "indexed_table_of_16_bit_values_052B7C", 0x052B7Cu, &indexed_table_of_16_bit_values_052B7C_data, 2 },
	{ "rom_053896", 0x053896u, &rom_053896_data, 4 },
};

const size_t game_table_count = 394;
