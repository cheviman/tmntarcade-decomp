/**
 *    Name:        sound.h
 *    Description: the sound program's ports, variables, tables, structures and functions
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#ifndef TMNT_SOUND_H
#define TMNT_SOUND_H

#include "sound/support.h"

/* the sound program's variables and channel records, in the Z80's RAM (8000-87FF) */
#define unk_8000_ADDRESS 0x8000u
#define unk_8000 SOUND_RAM8(unk_8000_ADDRESS)
#define unk_8001_ADDRESS 0x8001u
#define unk_8001 SOUND_RAM8(unk_8001_ADDRESS)
#define unk_8002_ADDRESS 0x8002u
#define unk_8002 SOUND_RAM16(unk_8002_ADDRESS)
#define unk_800F_ADDRESS 0x800Fu
#define unk_800F SOUND_RAM8(unk_800F_ADDRESS)
#define unk_8040_ADDRESS 0x8040u
#define unk_8040 SOUND_RAM8(unk_8040_ADDRESS)
#define unk_8042_ADDRESS 0x8042u
#define unk_8042 SOUND_RAM16(unk_8042_ADDRESS)
#define unk_8080_ADDRESS 0x8080u
#define unk_8080 SOUND_RAM8(unk_8080_ADDRESS)
#define unk_8082_ADDRESS 0x8082u
#define unk_8082 SOUND_RAM16(unk_8082_ADDRESS)
#define unk_80C0_ADDRESS 0x80C0u
#define unk_80C0 SOUND_RAM8(unk_80C0_ADDRESS)
#define unk_80C2_ADDRESS 0x80C2u
#define unk_80C2 SOUND_RAM16(unk_80C2_ADDRESS)
#define unk_8100_ADDRESS 0x8100u
#define unk_8100 SOUND_RAM8(unk_8100_ADDRESS)
#define unk_8102_ADDRESS 0x8102u
#define unk_8102 SOUND_RAM16(unk_8102_ADDRESS)
#define unk_8140_ADDRESS 0x8140u
#define unk_8140 SOUND_RAM8(unk_8140_ADDRESS)
#define unk_8142_ADDRESS 0x8142u
#define unk_8142 SOUND_RAM16(unk_8142_ADDRESS)
#define unk_8180_ADDRESS 0x8180u
#define unk_8180 SOUND_RAM8(unk_8180_ADDRESS)
#define unk_8182_ADDRESS 0x8182u
#define unk_8182 SOUND_RAM16(unk_8182_ADDRESS)
#define unk_81C0_ADDRESS 0x81C0u
#define unk_81C0 SOUND_RAM8(unk_81C0_ADDRESS)
#define unk_81C2_ADDRESS 0x81C2u
#define unk_81C2 SOUND_RAM16(unk_81C2_ADDRESS)
#define unk_8200_ADDRESS 0x8200u
#define unk_8200 SOUND_RAM8(unk_8200_ADDRESS)
#define unk_8201_ADDRESS 0x8201u
#define unk_8201 SOUND_RAM8(unk_8201_ADDRESS)
#define unk_8202_ADDRESS 0x8202u
#define unk_8202 SOUND_RAM16(unk_8202_ADDRESS)
#define unk_8240_ADDRESS 0x8240u
#define unk_8240 SOUND_RAM8(unk_8240_ADDRESS)
#define unk_8242_ADDRESS 0x8242u
#define unk_8242 SOUND_RAM16(unk_8242_ADDRESS)
#define unk_8280_ADDRESS 0x8280u
#define unk_8280 SOUND_RAM8(unk_8280_ADDRESS)
#define unk_8281_ADDRESS 0x8281u
#define unk_8281 SOUND_RAM8(unk_8281_ADDRESS)
#define unk_8282_ADDRESS 0x8282u
#define unk_8282 SOUND_RAM16(unk_8282_ADDRESS)
#define unk_82C0_ADDRESS 0x82C0u
#define unk_82C0 SOUND_RAM8(unk_82C0_ADDRESS)
#define unk_82C1_ADDRESS 0x82C1u
#define unk_82C1 SOUND_RAM8(unk_82C1_ADDRESS)
#define unk_82C2_ADDRESS 0x82C2u
#define unk_82C2 SOUND_RAM16(unk_82C2_ADDRESS)
#define unk_82CF_ADDRESS 0x82CFu
#define unk_82CF SOUND_RAM8(unk_82CF_ADDRESS)
#define unk_8300_ADDRESS 0x8300u
#define unk_8300 SOUND_RAM8(unk_8300_ADDRESS)
#define unk_8301_ADDRESS 0x8301u
#define unk_8301 SOUND_RAM8(unk_8301_ADDRESS)
#define unk_8302_ADDRESS 0x8302u
#define unk_8302 SOUND_RAM8(unk_8302_ADDRESS)
#define unk_8303_ADDRESS 0x8303u
#define unk_8303 SOUND_RAM8(unk_8303_ADDRESS)
#define unk_830F_ADDRESS 0x830Fu
#define unk_830F SOUND_RAM8(unk_830F_ADDRESS)
#define unk_8340_ADDRESS 0x8340u
#define unk_8340 SOUND_RAM8(unk_8340_ADDRESS)
#define unk_8341_ADDRESS 0x8341u
#define unk_8341 SOUND_RAM8(unk_8341_ADDRESS)
#define unk_8342_ADDRESS 0x8342u
#define unk_8342 SOUND_RAM16(unk_8342_ADDRESS)
#define unk_834F_ADDRESS 0x834Fu
#define unk_834F SOUND_RAM8(unk_834F_ADDRESS)
#define unk_8380_ADDRESS 0x8380u
#define unk_8380 SOUND_RAM8(unk_8380_ADDRESS)
#define unk_8381_ADDRESS 0x8381u
#define unk_8381 SOUND_RAM8(unk_8381_ADDRESS)
#define unk_8382_ADDRESS 0x8382u
#define unk_8382 SOUND_RAM16(unk_8382_ADDRESS)
#define unk_838F_ADDRESS 0x838Fu
#define unk_838F SOUND_RAM8(unk_838F_ADDRESS)
#define song_header_ADDRESS 0x83C0u
#define song_header SOUND_RAM16(song_header_ADDRESS)
#define pcm_volumes_ADDRESS 0x83C2u
#define pcm_volumes SOUND_RAM8(pcm_volumes_ADDRESS)
#define pcm_loops_ADDRESS 0x83C3u
#define pcm_loops SOUND_RAM8(pcm_loops_ADDRESS)
#define title_music_on_ADDRESS 0x83C4u
#define title_music_on SOUND_RAM8(title_music_on_ADDRESS)
#define title_music_passes_ADDRESS 0x83C5u
#define title_music_passes SOUND_RAM8(title_music_passes_ADDRESS)
#define title_music_rounds_ADDRESS 0x83C6u
#define title_music_rounds SOUND_RAM8(title_music_rounds_ADDRESS)
#define unk_83C7_ADDRESS 0x83C7u
#define unk_83C7 SOUND_RAM8(unk_83C7_ADDRESS)
#define speech_priority_ADDRESS 0x83C8u
#define speech_priority SOUND_RAM8(speech_priority_ADDRESS)
#define fade_timer_ADDRESS 0x83C9u
#define fade_timer SOUND_RAM8(fade_timer_ADDRESS)
#define fade_step_ADDRESS 0x83CAu
#define fade_step SOUND_RAM8(fade_step_ADDRESS)
#define fade_attenuation_ADDRESS 0x83CBu
#define fade_attenuation SOUND_RAM8(fade_attenuation_ADDRESS)
#define unk_83CC_ADDRESS 0x83CCu
#define unk_83CC SOUND_RAM8(unk_83CC_ADDRESS)
#define random_seed_ADDRESS 0x83CDu
#define random_seed SOUND_RAM16(random_seed_ADDRESS)
#define random_source_ADDRESS 0x83CFu
#define random_source SOUND_RAM16(random_source_ADDRESS)
#define random_write_ADDRESS 0x83D1u
#define random_write SOUND_RAM16(random_write_ADDRESS)
#define random_read_ADDRESS 0x83D3u
#define random_read SOUND_RAM16(random_read_ADDRESS)
#define music_volume_ADDRESS 0x83D5u
#define music_volume SOUND_RAM8(music_volume_ADDRESS)
#define music_transpose_ADDRESS 0x83D6u
#define music_transpose SOUND_RAM8(music_transpose_ADDRESS)
#define accelerando_ADDRESS 0x83D7u
#define accelerando SOUND_RAM16(accelerando_ADDRESS)
#define tempo_ADDRESS 0x83D9u
#define tempo SOUND_RAM8(tempo_ADDRESS)
#define tempo_increase_ADDRESS 0x83DAu
#define tempo_increase SOUND_RAM8(tempo_increase_ADDRESS)
#define music_attenuation_ADDRESS 0x83DBu
#define music_attenuation SOUND_RAM8(music_attenuation_ADDRESS)
#define music_pcm_hold_ADDRESS 0x83DEu
#define music_pcm_hold SOUND_RAM8(music_pcm_hold_ADDRESS)
#define unk_83DF_ADDRESS 0x83DFu
#define unk_83DF SOUND_RAM8(unk_83DF_ADDRESS)
#define unk_83E2_ADDRESS 0x83E2u
#define unk_83E2 SOUND_RAM8(unk_83E2_ADDRESS)
#define unk_83E3_ADDRESS 0x83E3u
#define unk_83E3 SOUND_RAM8(unk_83E3_ADDRESS)
#define unk_83E4_ADDRESS 0x83E4u
#define unk_83E4 SOUND_RAM16(unk_83E4_ADDRESS)
#define unk_83E6_ADDRESS 0x83E6u
#define unk_83E6 SOUND_RAM8(unk_83E6_ADDRESS)
#define unk_83E7_ADDRESS 0x83E7u
#define unk_83E7 SOUND_RAM8(unk_83E7_ADDRESS)
#define unk_83E8_ADDRESS 0x83E8u
#define unk_83E8 SOUND_RAM8(unk_83E8_ADDRESS)
#define unk_83E9_ADDRESS 0x83E9u
#define unk_83E9 SOUND_RAM8(unk_83E9_ADDRESS)
#define unk_83EA_ADDRESS 0x83EAu
#define unk_83EA SOUND_RAM8(unk_83EA_ADDRESS)
#define unk_83EF_ADDRESS 0x83EFu
#define unk_83EF SOUND_RAM8(unk_83EF_ADDRESS)
#define unk_83F0_ADDRESS 0x83F0u
#define unk_83F0 SOUND_RAM8(unk_83F0_ADDRESS)
#define unk_83F1_ADDRESS 0x83F1u
#define unk_83F1 SOUND_RAM8(unk_83F1_ADDRESS)
#define unk_83F2_ADDRESS 0x83F2u
#define unk_83F2 SOUND_RAM8(unk_83F2_ADDRESS)
#define unk_83F3_ADDRESS 0x83F3u
#define unk_83F3 SOUND_RAM8(unk_83F3_ADDRESS)
#define unk_83F4_ADDRESS 0x83F4u
#define unk_83F4 SOUND_RAM8(unk_83F4_ADDRESS)
#define unk_83F5_ADDRESS 0x83F5u
#define unk_83F5 SOUND_RAM8(unk_83F5_ADDRESS)
#define unk_83F6_ADDRESS 0x83F6u
#define unk_83F6 SOUND_RAM8(unk_83F6_ADDRESS)
#define unk_83F7_ADDRESS 0x83F7u
#define unk_83F7 SOUND_RAM8(unk_83F7_ADDRESS)
#define unk_83F8_ADDRESS 0x83F8u
#define unk_83F8 SOUND_RAM16(unk_83F8_ADDRESS)
#define unk_83FA_ADDRESS 0x83FAu
#define unk_83FA SOUND_RAM8(unk_83FA_ADDRESS)
#define unk_83FB_ADDRESS 0x83FBu
#define unk_83FB SOUND_RAM8(unk_83FB_ADDRESS)
#define unk_83FC_ADDRESS 0x83FCu
#define unk_83FC SOUND_RAM8(unk_83FC_ADDRESS)
#define unk_83FD_ADDRESS 0x83FDu
#define unk_83FD SOUND_RAM8(unk_83FD_ADDRESS)
#define unk_83FE_ADDRESS 0x83FEu
#define unk_83FE SOUND_RAM8(unk_83FE_ADDRESS)
#define unk_83FF_ADDRESS 0x83FFu
#define unk_83FF SOUND_RAM8(unk_83FF_ADDRESS)
#define unk_8400_ADDRESS 0x8400u
#define unk_8400 SOUND_RAM8(unk_8400_ADDRESS)
#define unk_8401_ADDRESS 0x8401u
#define unk_8401 SOUND_RAM16(unk_8401_ADDRESS)
#define unk_8403_ADDRESS 0x8403u
#define unk_8403 SOUND_RAM8(unk_8403_ADDRESS)
#define unk_8404_ADDRESS 0x8404u
#define unk_8404 SOUND_RAM8(unk_8404_ADDRESS)
#define unk_8405_ADDRESS 0x8405u
#define unk_8405 SOUND_RAM8(unk_8405_ADDRESS)
#define unk_8406_ADDRESS 0x8406u
#define unk_8406 SOUND_RAM8(unk_8406_ADDRESS)
#define unk_8407_ADDRESS 0x8407u
#define unk_8407 SOUND_RAM16(unk_8407_ADDRESS)
#define unk_8409_ADDRESS 0x8409u
#define unk_8409 SOUND_RAM8(unk_8409_ADDRESS)
#define unk_840A_ADDRESS 0x840Au
#define unk_840A SOUND_RAM16(unk_840A_ADDRESS)
#define unk_840C_ADDRESS 0x840Cu
#define unk_840C SOUND_RAM8(unk_840C_ADDRESS)
#define unk_840D_ADDRESS 0x840Du
#define unk_840D SOUND_RAM8(unk_840D_ADDRESS)
#define unk_840E_ADDRESS 0x840Eu
#define unk_840E SOUND_RAM8(unk_840E_ADDRESS)
#define unk_840F_ADDRESS 0x840Fu
#define unk_840F SOUND_RAM8(unk_840F_ADDRESS)
#define unk_8410_ADDRESS 0x8410u
#define unk_8410 SOUND_RAM8(unk_8410_ADDRESS)
#define unk_8411_ADDRESS 0x8411u
#define unk_8411 SOUND_RAM8(unk_8411_ADDRESS)
#define unk_8412_ADDRESS 0x8412u
#define unk_8412 SOUND_RAM16(unk_8412_ADDRESS)
#define unk_8414_ADDRESS 0x8414u
#define unk_8414 SOUND_RAM16(unk_8414_ADDRESS)
#define unk_8416_ADDRESS 0x8416u
#define unk_8416 SOUND_RAM8(unk_8416_ADDRESS)
#define unk_8417_ADDRESS 0x8417u
#define unk_8417 SOUND_RAM8(unk_8417_ADDRESS)
#define unk_8418_ADDRESS 0x8418u
#define unk_8418 SOUND_RAM16(unk_8418_ADDRESS)
#define unk_841A_ADDRESS 0x841Au
#define unk_841A SOUND_RAM8(unk_841A_ADDRESS)
#define unk_841B_ADDRESS 0x841Bu
#define unk_841B SOUND_RAM8(unk_841B_ADDRESS)
#define unk_841C_ADDRESS 0x841Cu
#define unk_841C SOUND_RAM16(unk_841C_ADDRESS)
#define unk_841E_ADDRESS 0x841Eu
#define unk_841E SOUND_RAM8(unk_841E_ADDRESS)
#define unk_841F_ADDRESS 0x841Fu
#define unk_841F SOUND_RAM8(unk_841F_ADDRESS)
#define unk_8420_ADDRESS 0x8420u
#define unk_8420 SOUND_RAM16(unk_8420_ADDRESS)
#define unk_8422_ADDRESS 0x8422u
#define unk_8422 SOUND_RAM8(unk_8422_ADDRESS)
#define unk_8423_ADDRESS 0x8423u
#define unk_8423 SOUND_RAM16(unk_8423_ADDRESS)
#define unk_8425_ADDRESS 0x8425u
#define unk_8425 SOUND_RAM16(unk_8425_ADDRESS)
#define unk_8427_ADDRESS 0x8427u
#define unk_8427 SOUND_RAM8(unk_8427_ADDRESS)
#define unk_8428_ADDRESS 0x8428u
#define unk_8428 SOUND_RAM8(unk_8428_ADDRESS)
#define unk_8429_ADDRESS 0x8429u
#define unk_8429 SOUND_RAM8(unk_8429_ADDRESS)
#define unk_842A_ADDRESS 0x842Au
#define unk_842A SOUND_RAM8(unk_842A_ADDRESS)
#define unk_842B_ADDRESS 0x842Bu
#define unk_842B SOUND_RAM8(unk_842B_ADDRESS)
#define unk_842C_ADDRESS 0x842Cu
#define unk_842C SOUND_RAM16(unk_842C_ADDRESS)
#define unk_842E_ADDRESS 0x842Eu
#define unk_842E SOUND_RAM8(unk_842E_ADDRESS)
#define unk_842F_ADDRESS 0x842Fu
#define unk_842F SOUND_RAM8(unk_842F_ADDRESS)
#define unk_8430_ADDRESS 0x8430u
#define unk_8430 SOUND_RAM8(unk_8430_ADDRESS)
#define unk_8431_ADDRESS 0x8431u
#define unk_8431 SOUND_RAM8(unk_8431_ADDRESS)
#define unk_8432_ADDRESS 0x8432u
#define unk_8432 SOUND_RAM16(unk_8432_ADDRESS)
#define unk_8434_ADDRESS 0x8434u
#define unk_8434 SOUND_RAM16(unk_8434_ADDRESS)
#define unk_8436_ADDRESS 0x8436u
#define unk_8436 SOUND_RAM16(unk_8436_ADDRESS)
#define unk_8438_ADDRESS 0x8438u
#define unk_8438 SOUND_RAM8(unk_8438_ADDRESS)
#define unk_8439_ADDRESS 0x8439u
#define unk_8439 SOUND_RAM8(unk_8439_ADDRESS)
#define unk_843A_ADDRESS 0x843Au
#define unk_843A SOUND_RAM8(unk_843A_ADDRESS)
#define unk_843C_ADDRESS 0x843Cu
#define unk_843C SOUND_RAM8(unk_843C_ADDRESS)
#define unk_843D_ADDRESS 0x843Du
#define unk_843D SOUND_RAM8(unk_843D_ADDRESS)
#define unk_843E_ADDRESS 0x843Eu
#define unk_843E SOUND_RAM16(unk_843E_ADDRESS)
#define unk_8440_ADDRESS 0x8440u
#define unk_8440 SOUND_RAM8(unk_8440_ADDRESS)
#define unk_8441_ADDRESS 0x8441u
#define unk_8441 SOUND_RAM8(unk_8441_ADDRESS)
#define unk_8442_ADDRESS 0x8442u
#define unk_8442 SOUND_RAM8(unk_8442_ADDRESS)
#define unk_8443_ADDRESS 0x8443u
#define unk_8443 SOUND_RAM16(unk_8443_ADDRESS)
#define unk_8445_ADDRESS 0x8445u
#define unk_8445 SOUND_RAM16(unk_8445_ADDRESS)
#define unk_8447_ADDRESS 0x8447u
#define unk_8447 SOUND_RAM8(unk_8447_ADDRESS)
#define unk_8448_ADDRESS 0x8448u
#define unk_8448 SOUND_RAM8(unk_8448_ADDRESS)
#define unk_8449_ADDRESS 0x8449u
#define unk_8449 SOUND_RAM8(unk_8449_ADDRESS)
#define unk_844A_ADDRESS 0x844Au
#define unk_844A SOUND_RAM16(unk_844A_ADDRESS)
#define unk_844C_ADDRESS 0x844Cu
#define unk_844C SOUND_RAM8(unk_844C_ADDRESS)
#define unk_844D_ADDRESS 0x844Du
#define unk_844D SOUND_RAM8(unk_844D_ADDRESS)
#define unk_844E_ADDRESS 0x844Eu
#define unk_844E SOUND_RAM8(unk_844E_ADDRESS)
#define unk_844F_ADDRESS 0x844Fu
#define unk_844F SOUND_RAM16(unk_844F_ADDRESS)
#define unk_8451_ADDRESS 0x8451u
#define unk_8451 SOUND_RAM8(unk_8451_ADDRESS)
#define unk_8452_ADDRESS 0x8452u
#define unk_8452 SOUND_RAM16(unk_8452_ADDRESS)
#define unk_8454_ADDRESS 0x8454u
#define unk_8454 SOUND_RAM8(unk_8454_ADDRESS)
#define unk_8455_ADDRESS 0x8455u
#define unk_8455 SOUND_RAM8(unk_8455_ADDRESS)
#define unk_8456_ADDRESS 0x8456u
#define unk_8456 SOUND_RAM8(unk_8456_ADDRESS)
#define unk_8457_ADDRESS 0x8457u
#define unk_8457 SOUND_RAM8(unk_8457_ADDRESS)
#define unk_8458_ADDRESS 0x8458u
#define unk_8458 SOUND_RAM8(unk_8458_ADDRESS)
#define unk_8459_ADDRESS 0x8459u
#define unk_8459 SOUND_RAM8(unk_8459_ADDRESS)
#define unk_845B_ADDRESS 0x845Bu
#define unk_845B SOUND_RAM16(unk_845B_ADDRESS)
#define unk_845E_ADDRESS 0x845Eu
#define unk_845E SOUND_RAM8(unk_845E_ADDRESS)
#define unk_845F_ADDRESS 0x845Fu
#define unk_845F SOUND_RAM8(unk_845F_ADDRESS)
#define unk_8460_ADDRESS 0x8460u
#define unk_8460 SOUND_RAM8(unk_8460_ADDRESS)
#define unk_8461_ADDRESS 0x8461u
#define unk_8461 SOUND_RAM8(unk_8461_ADDRESS)
#define unk_8462_ADDRESS 0x8462u
#define unk_8462 SOUND_RAM8(unk_8462_ADDRESS)
#define unk_8463_ADDRESS 0x8463u
#define unk_8463 SOUND_RAM16(unk_8463_ADDRESS)
#define unk_8465_ADDRESS 0x8465u
#define unk_8465 SOUND_RAM8(unk_8465_ADDRESS)
#define unk_8466_ADDRESS 0x8466u
#define unk_8466 SOUND_RAM16(unk_8466_ADDRESS)
#define unk_8468_ADDRESS 0x8468u
#define unk_8468 SOUND_RAM8(unk_8468_ADDRESS)
#define unk_8469_ADDRESS 0x8469u
#define unk_8469 SOUND_RAM8(unk_8469_ADDRESS)
#define unk_846A_ADDRESS 0x846Au
#define unk_846A SOUND_RAM8(unk_846A_ADDRESS)
#define unk_846B_ADDRESS 0x846Bu
#define unk_846B SOUND_RAM8(unk_846B_ADDRESS)
#define random_pool_ADDRESS 0x8600u
#define random_pool ((uint8_t *)sound_ram_at(random_pool_ADDRESS))

/* data in the program ROM the code reads, which the game loads from its assets */
#define speech_priorities_ADDRESS 0x0130u
extern const void *speech_priorities_data;
#define speech_priorities ((const uint8_t *)speech_priorities_data)
#define speech_music_attenuation_ADDRESS 0x0154u
extern const void *speech_music_attenuation_data;
#define speech_music_attenuation ((const uint8_t *)speech_music_attenuation_data)
#define pcm_effect_priorities_ADDRESS 0x025Au
extern const void *pcm_effect_priorities_data;
#define pcm_effect_priorities ((const uint8_t *)pcm_effect_priorities_data)
#define fm_effect_priorities_ADDRESS 0x02FBu
extern const void *fm_effect_priorities_data;
#define fm_effect_priorities ((const uint8_t *)fm_effect_priorities_data)
#define fm_key_codes_ADDRESS 0x073Du
extern const void *fm_key_codes_data;
#define fm_key_codes ((const uint8_t *)fm_key_codes_data)
#define fm_carrier_masks_ADDRESS 0x07DEu
extern const void *fm_carrier_masks_data;
#define fm_carrier_masks ((const uint8_t *)fm_carrier_masks_data)
#define fm_note_pitches_ADDRESS 0x0B1Cu
extern const void *fm_note_pitches_data;
#define fm_note_pitches (*(const uint16_t *)fm_note_pitches_data)
#define pcm_note_pitches_ADDRESS 0x0C96u
extern const void *pcm_note_pitches_data;
#define pcm_note_pitches (*(const uint8_t *)pcm_note_pitches_data)
#define note_lengths_ADDRESS 0x0CF9u
extern const void *note_lengths_data;
#define note_lengths ((const uint8_t *)note_lengths_data)
#define track_commands_e0_ADDRESS 0x0D4Du
extern const void *track_commands_e0_data;
#define track_commands_e0 (*(const uint16_t *)track_commands_e0_data)
#define track_commands_f0_ADDRESS 0x0D6Du
extern const void *track_commands_f0_data;
#define track_commands_f0 (*(const uint16_t *)track_commands_f0_data)
#define pcm_effect_handlers_ADDRESS 0x106Cu
extern const void *pcm_effect_handlers_data;
#define pcm_effect_handlers (*(const uint16_t *)pcm_effect_handlers_data)
#define fm_effect_26_pitches_ADDRESS 0x2B04u
extern const void *fm_effect_26_pitches_data;
#define fm_effect_26_pitches (*(const uint16_t *)fm_effect_26_pitches_data)
#define fm_voice_pointers_ADDRESS 0x37B5u
extern const void *fm_voice_pointers_data;
#define fm_voice_pointers (*(const uint16_t *)fm_voice_pointers_data)

/* the board's registers on the Z80's bus: 9000 (sres), the 68000's latch, the K007232, the
   YM2151 and the uPD7759 (read and written through the bus) */
#define sound_control 0x9000u
#define sound_latch 0xA000u
#define pcm_a_pitch 0xB000u
#define pcm_a_start 0xB002u
#define pcm_a_bank 0xB004u
#define pcm_a_key 0xB005u
#define pcm_b_pitch 0xB006u
#define pcm_b_start 0xB008u
#define pcm_b_bank 0xB00Au
#define pcm_b_key 0xB00Bu
#define pcm_volume_port 0xB00Cu
#define pcm_loop_flags 0xB00Du
#define fm_address 0xC000u
#define fm_data 0xC001u
#define speech_sample 0xD000u
#define speech_start 0xE000u
#define speech_busy 0xF000u

/* data in the program ROM sound_symbols.txt labels */
#define pcm_instruments_ADDRESS 0x1002u
#define pcm_drums_ADDRESS 0x1012u
#define fm_effect_handlers_ADDRESS 0x13D9u
#define songs_ADDRESS 0x145Du
#define unused_note_hooks_ADDRESS 0x3794u
#define unreached_end_4721_ADDRESS 0x4721u
#define unused_part_5eb2_ADDRESS 0x5EB2u
#define unused_part_5ec7_ADDRESS 0x5EC7u
#define unreached_end_63a5_ADDRESS 0x63A5u
#define unreached_return_6d46_ADDRESS 0x6D46u
#define unused_part_7caa_ADDRESS 0x7CAAu

/* the sound program's structures in the shared RAM */
#pragma pack(push, 1)
struct channel
{
	uint8_t chip_channel;
	uint8_t sound;
	uint16_t handler;
	uint8_t unk_04;
	uint8_t unk_05;
	uint8_t unk_06;
	uint8_t unk_07;
	uint8_t unk_08;
	uint8_t unk_09;
	uint8_t unk_0A;
	uint8_t unk_0B;
	uint8_t unk_0C;
	uint8_t unk_0D;
	uint8_t pad_0E[0x1];
	uint8_t priority;
	uint16_t unk_10;
	uint8_t unk_12;
	uint8_t unk_13;
	uint8_t unk_14;
	uint8_t unk_15;
	uint8_t unk_16;
	uint8_t unk_17;
	uint8_t unk_18;
	uint8_t unk_19;
	uint8_t unk_1A;
	uint8_t unk_1B;
	uint8_t unk_1C;
	uint8_t unk_1D;
	uint8_t unk_1E;
	uint8_t unk_1F;
	uint8_t unk_20;
	uint8_t unk_21;
	uint8_t unk_22;
	uint8_t unk_23;
	uint16_t unk_24;
	uint16_t unk_26;
	uint8_t unk_28;
	uint8_t unk_29;
	uint16_t unk_2A;
	uint8_t unk_2C;
	uint8_t unk_2D;
	uint8_t unk_2E;
	uint8_t pad_2F[0x1];
	uint8_t unk_30;
	uint8_t unk_31;
	uint8_t unk_32;
	uint8_t unk_33;
	uint8_t unk_34;
	uint8_t unk_35;
	uint8_t unk_36;
	uint8_t pad_37[0x1];
	uint8_t unk_38;
	uint8_t unk_39;
	uint16_t unk_3A;
	uint8_t unk_3C;
	uint8_t unk_3D;
	uint8_t pad_3E[0x1];
	uint8_t unk_3F;
};

struct fm_voice
{
	uint8_t connection;
	uint8_t m1_detune_multiple;
	uint8_t m1_total_level;
	uint8_t m1_attack;
	uint8_t m1_decay_1;
	uint8_t m1_decay_2;
	uint8_t m1_release;
	uint8_t c1_detune_multiple;
	uint8_t c1_total_level;
	uint8_t c1_attack;
	uint8_t c1_decay_1;
	uint8_t c1_decay_2;
	uint8_t c1_release;
	uint8_t m2_detune_multiple;
	uint8_t m2_total_level;
	uint8_t m2_attack;
	uint8_t m2_decay_1;
	uint8_t m2_decay_2;
	uint8_t m2_release;
	uint8_t c2_detune_multiple;
	uint8_t c2_total_level;
	uint8_t c2_attack;
	uint8_t c2_decay_1;
	uint8_t c2_decay_2;
	uint8_t c2_release;
};

struct pcm_instrument
{
	uint16_t start;
	uint8_t bank;
	uint8_t level;
};

struct pcm_drum
{
	uint16_t start;
	uint8_t bank;
	uint8_t level;
	uint16_t pitch;
};

struct song
{
	uint16_t tracks[0x9];
};

#pragma pack(pop)

_Static_assert(sizeof(struct channel) == 0x40, "struct channel has the size of the game's blocks");
_Static_assert(sizeof(struct fm_voice) == 0x19, "struct fm_voice has the size of the program ROM's records");
_Static_assert(sizeof(struct pcm_instrument) == 0x4, "struct pcm_instrument has the size of the program ROM's records");
_Static_assert(sizeof(struct pcm_drum) == 0x6, "struct pcm_drum has the size of the program ROM's records");
_Static_assert(sizeof(struct song) == 0x12, "struct song has the size of the program ROM's records");

#define CHANNEL(address) ((struct channel *)sound_ram_at(address))
#define FM_VOICE(address) ((const struct fm_voice *)sound_rom_at(address))
#define PCM_INSTRUMENT(address) ((const struct pcm_instrument *)sound_rom_at(address))
#define PCM_DRUM(address) ((const struct pcm_drum *)sound_rom_at(address))
#define SONG(address) ((const struct song *)sound_rom_at(address))
#define MUSIC_TRACK(address) ((const uint8_t *)sound_rom_at(address))
#define CHANNEL_ADDRESS(n) (0x8000u + (n) * 0x40u)    /* the 15 of them, from 0 */

/* chips.c: the chips' registers: the YM2151's writes and the frame's timer, its voices, keys, pitches and volumes; the K007232's start, pitch, volume and loop */
void write_fm_register_de(uint8_t bc, uint16_t de);
void write_fm_channel_register(uint16_t ix, uint16_t *p_bc, uint32_t *p_carry);
uint32_t write_fm_register(uint16_t bc);
void restart_frame_timer(void);
uint32_t load_fm_voice(uint16_t voice, uint16_t ix);
uint32_t fm_key_on(uint16_t ix);
void fm_key_off(uint16_t ix);
uint32_t fm_fast_release(uint16_t ix);
uint32_t sound_06F1(uint16_t bc, uint16_t ix, uint8_t a);
void fm_restore_release(uint16_t ix);
void set_fm_pitch(uint16_t hl, uint16_t ix, uint16_t *p_bc, uint32_t *p_carry);
uint32_t set_fm_volume_from_record(uint16_t ix);
uint32_t set_fm_volume(uint16_t ix, uint8_t a);
void sound_07CD(uint16_t bc, uint16_t ix, uint8_t a, uint16_t *p_hl, uint32_t *p_carry);
void set_pcm_start(uint8_t bc, uint16_t de, uint16_t ix);
void set_pcm_pitch(uint16_t de, uint16_t ix);
uint32_t set_pcm_volume(uint8_t bc, uint16_t ix);
void start_pcm(uint16_t ix);
void set_pcm_loop(uint16_t ix);
uint32_t clear_pcm_loop(uint16_t ix);

/* commands.c: the 68000's sound commands: the reset and its tests, the command's dispatch, the title music, the speech, the starts of the music and the effects, the fade, silence, the channels' stops */
void sound_reset(void);
void check_rom(void);
void BOARD_ORIGINAL(check_rom)(void);
void sound_command(void);
void self_test_failed(void);
void stop_title_music(void);
void title_music_timer(void);
void start_speech(uint8_t a);
void stop_speech(void);
uint32_t speech_play(uint16_t ix);
uint32_t speech_wait(uint16_t ix, uint32_t carry);
void start_pcm_effect(uint8_t a);
uint32_t start_fm_effect(uint8_t a);
void lower_priority_channel(uint16_t ix, uint16_t *p_hl, uint8_t *p_a);
void reset_sound(void);
void silence(void);
void stop_fm_effect_channels(void);
void stop_music_fm_6_7(void);
void stop_music_fm_1_5(void);
void free_music_fm_6_7(void);
void stop_music_pcm_a(void);
void free_music_pcm_a(void);
void stop_pcm_effect_b(void);
void free_music_pcm_b(void);
void stop_music_pcm_b(void);
void stop_pcm_effect_a(void);
void free_speech_channel(void);

/* fm_effects.c: the FM effects (commands 01-41) */
uint32_t fm_effect_01(uint16_t ix);
uint32_t sound_163F(uint16_t ix, uint8_t a);
uint32_t sound_1662(uint16_t ix);
uint32_t fm_effect_02(uint16_t ix);
uint32_t sound_16AC(uint16_t ix, uint8_t a);
uint32_t sound_16CF(uint16_t ix);
uint32_t sound_1727(uint16_t ix, uint32_t carry);
uint32_t fm_effect_03(uint16_t ix);
uint32_t sound_177D(uint16_t ix);
uint32_t sound_17AD(uint16_t ix);
uint32_t fm_effect_04(uint16_t ix);
uint32_t fm_effect_05(uint16_t ix);
uint32_t sound_181A(uint16_t ix);
uint32_t sound_1820(uint16_t ix, uint8_t a);
uint32_t sound_183F(uint16_t ix);
uint32_t sound_1868(uint16_t ix, uint32_t carry);
void fm_effect_37(uint16_t ix);
uint32_t sound_1881(uint16_t ix, uint32_t carry);
uint32_t fm_effect_06(uint16_t ix);
uint32_t sound_18A9(uint16_t ix);
uint32_t sound_18D9(uint16_t ix);
uint32_t fm_effect_07(uint16_t ix);
uint32_t sound_1938(uint16_t ix, uint8_t a);
uint32_t sound_193B(uint16_t ix);
uint32_t sound_1962(uint16_t ix);
uint32_t fm_effect_08(uint16_t ix);
uint32_t sound_19DB(uint16_t ix, uint8_t a);
uint32_t sound_19F9(uint16_t ix);
uint32_t fm_effect_09(uint16_t ix);
uint32_t fm_effect_0a(uint16_t ix);
uint32_t sound_1A58(uint16_t ix, uint8_t a);
uint32_t sound_1A60(uint16_t ix);
uint32_t sound_1A6E(uint16_t ix, uint8_t a);
uint32_t sound_1A98(uint16_t ix);
uint32_t sound_1AF8(uint16_t ix, uint8_t a);
uint32_t sound_1B1B(uint16_t ix);
uint32_t fm_effect_0b(uint16_t ix);
uint32_t sound_1B79(uint16_t ix);
uint32_t sound_1B8B(uint16_t ix, uint8_t a);
uint32_t sound_1B9C(uint16_t ix);
uint32_t fm_effect_0c(uint16_t ix);
uint32_t sound_1C04(uint16_t ix);
uint32_t sound_1C13(uint16_t ix);
uint32_t sound_1C28(uint16_t hl, uint16_t ix);
uint32_t sound_1C2E(uint16_t ix, uint8_t a);
uint32_t sound_1C40(uint16_t ix);
uint32_t fm_effect_0d(uint16_t ix);
uint32_t sound_1CCE(uint16_t ix);
uint32_t sound_1CDB(uint16_t ix, uint8_t a);
uint32_t sound_1D0A(uint16_t ix);
uint32_t sound_1D4F(uint16_t ix, uint32_t carry);
uint32_t fm_effect_0e(uint16_t ix);
uint32_t sound_1D96(uint16_t ix);
uint32_t sound_1DD5(uint16_t ix, uint8_t a);
uint32_t sound_1DE4(uint16_t ix);
uint32_t fm_effect_0f(uint16_t ix);
uint32_t sound_1E4C(uint16_t ix);
uint32_t sound_1E5E(uint16_t hl, uint16_t ix);
uint32_t sound_1E83(uint16_t ix);
uint32_t sound_1E88(uint16_t ix);
uint32_t sound_1E8C(uint16_t ix);
uint32_t sound_1E8F(uint16_t ix, uint8_t a);
uint32_t sound_1EB5(uint16_t ix);
uint32_t fm_effect_10(uint16_t ix);
uint32_t sound_1F37(uint16_t ix);
uint32_t sound_1F7F(uint16_t ix);
uint32_t fm_effect_11(uint16_t ix);
uint32_t sound_1FDB(uint16_t hl, uint16_t ix);
uint32_t sound_1FE4(uint16_t ix);
uint32_t fm_effect_12(uint16_t ix);
uint32_t fm_effect_13(uint16_t ix);
uint32_t fm_effect_14(uint16_t ix);
uint32_t sound_2069(uint16_t ix, uint32_t carry);
uint32_t fm_effect_15(uint16_t ix);
uint32_t sound_20CA(uint16_t ix);
uint32_t sound_20D4(uint16_t ix, uint8_t a);
uint32_t sound_20F5(uint16_t ix, uint32_t carry);
void sound_212C(uint16_t ix);
uint32_t sound_2136(uint16_t ix, uint32_t carry);
uint32_t fm_effect_16(uint16_t ix);
uint32_t sound_216A(uint16_t ix);
uint32_t sound_2175(uint16_t hl, uint16_t ix);
uint32_t sound_2197(uint16_t ix);
uint32_t sound_21C6(uint16_t ix);
uint32_t sound_21D6(uint16_t ix, uint32_t carry);
uint32_t fm_effect_17(uint16_t ix);
uint32_t sound_21FB(uint16_t ix);
uint32_t sound_2209(uint16_t hl, uint16_t ix);
uint32_t sound_221A(uint16_t ix, uint8_t a);
uint32_t sound_2226(uint16_t ix);
uint32_t fm_effect_18(uint16_t ix);
uint32_t fm_effect_19(uint16_t ix);
uint32_t sound_22DD(uint16_t ix, uint8_t a);
uint32_t sound_22F3(uint16_t hl, uint16_t ix);
uint32_t sound_2306(uint16_t ix);
uint32_t fm_effect_1a(uint16_t ix);
uint32_t sound_2393(uint16_t ix);
uint32_t sound_23A4(uint16_t ix, uint8_t a);
uint32_t sound_23CA(uint16_t ix);
uint32_t sound_2405(uint16_t ix, uint8_t a);
uint32_t sound_2419(uint16_t ix);
uint32_t sound_241C(uint16_t bc, uint16_t ix);
void sound_2433(uint16_t ix, uint16_t *p_bc, uint32_t *p_carry);
void sound_2442(uint16_t hl, uint16_t ix);
uint32_t sound_244F(uint16_t ix);
uint32_t sound_2453(uint16_t ix);
uint32_t sound_247A(uint16_t ix);
uint32_t sound_2491(uint16_t ix, uint8_t a);
uint32_t sound_24B7(uint16_t ix);
uint32_t fm_effect_1b(uint16_t ix);
uint32_t sound_2531(uint16_t ix);
uint32_t sound_2556(uint16_t ix);
uint32_t fm_effect_1c(uint16_t ix);
uint32_t sound_2591(uint16_t ix, uint8_t a);
uint32_t sound_2595(uint16_t ix, uint8_t a);
uint32_t sound_259C(uint16_t ix);
uint32_t sound_25B8(uint16_t ix);
void sound_25FE(uint16_t ix);
uint32_t sound_2608(uint16_t ix, uint32_t carry);
uint32_t fm_effect_1d(uint16_t ix);
uint32_t sound_263F(uint16_t hl, uint16_t ix);
uint32_t sound_2646(uint16_t bc, uint16_t hl, uint16_t ix);
uint32_t sound_2650(uint16_t hl, uint16_t ix);
uint32_t sound_267A(uint16_t ix, uint32_t carry);
uint32_t sound_26A5(uint16_t ix, uint32_t carry);
void sound_26AC(uint16_t ix);
uint32_t sound_26B6(uint16_t ix, uint32_t carry);
uint32_t fm_effect_1e(uint16_t ix);
uint32_t sound_26D4(uint16_t ix, uint32_t carry);
uint32_t fm_effect_1f(uint16_t ix);
uint32_t sound_2713(uint16_t ix);
uint32_t sound_2733(uint16_t ix, uint8_t a);
uint32_t sound_274D(uint16_t ix, uint32_t carry);
uint32_t fm_effect_20(uint16_t ix);
uint32_t fm_effect_21(uint16_t ix);
uint32_t sound_27A7(uint16_t ix);
uint32_t sound_27DD(uint16_t ix);
uint32_t fm_effect_22(uint16_t ix);
uint32_t sound_284D(uint16_t ix);
uint32_t sound_2857(uint16_t ix);
uint32_t sound_285C(uint16_t ix);
uint32_t sound_2861(uint16_t ix);
uint32_t sound_2866(uint16_t ix);
uint32_t sound_286B(uint16_t ix);
uint32_t sound_2870(uint16_t ix);
uint32_t sound_2875(uint16_t ix);
uint32_t sound_2877(uint16_t ix, uint8_t a);
uint32_t sound_288E(uint16_t ix, uint32_t carry);
uint32_t fm_effect_23(uint16_t ix);
uint32_t sound_28E1(uint16_t ix, uint32_t carry);
uint32_t fm_effect_24(uint16_t ix);
uint32_t sound_2958(uint16_t ix);
uint32_t sound_2978(uint16_t ix, uint8_t a);
uint32_t sound_2998(uint16_t ix);
uint32_t fm_effect_25(uint16_t ix);
uint32_t sound_2A0D(uint16_t ix, uint32_t carry);
uint32_t sound_2A33(uint16_t ix);
uint32_t fm_effect_26(uint16_t ix);
uint32_t sound_2A78(uint16_t ix, uint8_t a);
uint32_t sound_2A87(uint16_t de, uint16_t ix);
uint32_t sound_2AAB(uint16_t ix);
uint32_t fm_effect_27(uint16_t ix);
uint32_t sound_2B46(uint16_t ix, uint8_t a);
uint32_t sound_2B52(uint16_t ix);
void sound_2B73(uint16_t ix, uint16_t *p_bc, uint32_t *p_carry);
void sound_2B80(uint16_t ix, uint16_t *p_bc, uint32_t *p_carry);
void sound_2B86(uint16_t hl, uint16_t ix, uint16_t *p_bc, uint32_t *p_carry);
void sound_2B87(uint16_t hl, uint16_t ix, uint16_t *p_bc, uint32_t *p_carry);
uint32_t sound_2B90(uint16_t bc, uint16_t hl, uint16_t ix, uint32_t carry);
uint32_t sound_2B95(uint16_t ix);
uint32_t sound_2BA4(uint16_t ix, uint32_t carry);
uint8_t sound_2BB2(uint16_t ix);
uint32_t fm_effect_28(uint16_t ix);
uint32_t sound_2BF5(uint16_t hl, uint16_t ix);
uint32_t sound_2C09(uint16_t ix);
uint32_t fm_effect_29(uint16_t ix);
uint32_t sound_2C60(uint16_t ix);
uint32_t sound_2C8D(uint16_t ix);
uint32_t sound_2CBA(uint16_t ix);
uint32_t sound_2CC1(uint16_t ix);
uint32_t sound_2CCE(uint16_t hl, uint16_t ix);
uint32_t fm_effect_2a(uint16_t ix);
uint32_t sound_2D08(uint16_t ix, uint8_t a);
uint32_t sound_2D1D(uint16_t ix);
uint32_t sound_2D40(uint16_t ix, uint32_t carry);
uint32_t fm_effect_2b(uint16_t ix);
uint32_t sound_2D9D(uint16_t ix);
uint32_t fm_effect_2c(uint16_t ix);
uint32_t sound_2DD6(uint16_t ix, uint8_t a);
uint32_t sound_2DD9(uint16_t ix);
uint32_t sound_2DF6(uint16_t ix);
uint32_t sound_2E1E(uint16_t hl, uint16_t ix);
uint32_t sound_2E35(uint16_t ix, uint32_t carry);
uint16_t sound_2E64(uint16_t ix);
uint32_t fm_effect_2d(uint16_t ix);
uint32_t sound_2E84(uint16_t hl, uint16_t ix);
uint32_t sound_2EAA(uint16_t ix, uint32_t carry);
uint32_t fm_effect_2e(uint16_t ix);
uint32_t sound_2F15(uint16_t ix);
uint32_t sound_2F3C(uint16_t ix);
uint32_t sound_2F53(uint16_t ix, uint8_t a);
uint32_t sound_2F76(uint16_t ix, uint32_t carry);
uint32_t fm_effect_2f(uint16_t ix);
uint32_t sound_2FBB(uint16_t ix, uint8_t a);
uint32_t sound_2FD0(uint16_t ix);
uint32_t sound_300D(uint16_t ix, uint8_t a);
uint32_t sound_3028(uint16_t bc, uint16_t ix);
uint32_t fm_effect_30(uint16_t ix);
uint32_t sound_3042(uint16_t ix);
uint32_t sound_3061(uint16_t ix, uint8_t a);
uint32_t sound_306F(uint16_t ix);
uint32_t fm_effect_31(uint16_t ix);
uint32_t sound_30A8(uint16_t ix);
uint32_t sound_30CF(uint16_t ix);
uint32_t sound_30E6(uint16_t ix, uint8_t a);
uint32_t sound_3109(uint16_t ix, uint32_t carry);
uint32_t fm_effect_32(uint16_t ix);
uint32_t sound_3161(uint16_t ix, uint8_t a);
uint32_t sound_3181(uint16_t ix);
uint32_t fm_effect_33(uint16_t ix);
uint32_t fm_effect_34(uint16_t ix);
uint32_t sound_320D(uint16_t ix);
uint32_t sound_3226(uint16_t ix);
uint32_t sound_3258(uint16_t ix);
uint32_t sound_329C(uint16_t ix);
uint32_t sound_32A8(uint16_t ix, uint8_t a);
uint32_t sound_32D4(uint16_t ix);
uint32_t fm_effect_35(uint16_t ix);
uint32_t fm_effect_36(uint16_t ix);
uint32_t sound_3353(uint16_t ix);
void sound_3388(uint16_t ix);
uint32_t sound_3395(uint16_t ix);
uint32_t fm_effect_38(uint16_t ix);
uint32_t sound_33E9(uint16_t ix);
uint32_t fm_effect_39(uint16_t ix);
uint32_t sound_3448(uint16_t hl, uint16_t ix);
uint32_t sound_345F(uint16_t ix, uint32_t carry);
uint32_t fm_effect_3a(uint16_t ix);
uint32_t sound_34A5(uint16_t hl, uint16_t ix);
uint32_t sound_34C3(uint16_t ix);
uint32_t fm_effect_3b(uint16_t ix);
uint32_t sound_353D(uint16_t ix, uint8_t a);
uint32_t sound_354C(uint16_t ix);
uint32_t fm_effect_3c(uint16_t ix);
uint32_t sound_3584(uint16_t hl, uint16_t ix);
uint32_t sound_35A6(uint16_t ix);
uint32_t fm_effect_3d(uint16_t ix);
uint32_t sound_35F3(uint16_t ix);
uint32_t sound_35FD(uint16_t ix);
uint32_t sound_3604(uint16_t ix);
uint32_t sound_3608(uint16_t bc, uint16_t ix, uint8_t a);
uint32_t sound_361A(uint16_t ix, uint32_t carry);
uint32_t fm_effect_3e(uint16_t ix);
void sound_363A(uint16_t ix);
uint32_t sound_3644(uint16_t ix, uint32_t carry);
uint32_t fm_effect_3f(uint16_t ix);
uint32_t sound_366D(uint16_t ix);
uint32_t sound_3694(uint16_t ix);
uint32_t sound_36A5(uint16_t ix, uint8_t a);
uint32_t sound_36C8(uint16_t ix, uint32_t carry);
uint32_t fm_effect_40(uint16_t ix);
uint32_t fm_effect_41(uint16_t ix);
uint32_t sound_3769(uint16_t ix, uint32_t carry);

/* main.c: the program's frame: sound_main, the main loop, the channels' handlers and their stop */
void sound_main(void);
void sound_main_loop(void);
uint32_t run_channel_handler(uint16_t ix, uint32_t carry);
uint32_t stop_channel(uint16_t ix);
void free_channel(uint16_t ix);
void set_channel_handler(uint16_t hl, uint16_t ix);
void channel_idle(void);
uint32_t stop_pcm_channel(uint16_t ix);

/* music.c: the music: the random bytes, the tracks' tick, their commands and notes, the note hooks */
uint16_t next_random_byte(void);
uint32_t music_track_start(uint16_t ix);
uint32_t music_track_first_tick(uint16_t ix);
uint32_t music_track_tick(uint16_t ix);
void clear_note_hook(uint16_t ix);
void note_hook_none(void);
void accelerando_tick(void);
uint32_t check_fm_effect_override(uint16_t ix);
uint32_t read_track(uint16_t ix);
uint32_t next_note_length(uint16_t de, uint16_t hl, uint16_t ix);
uint32_t load_instrument(uint16_t ix, uint8_t a);
void add_note_length_high(uint16_t ix, uint8_t a);
void add_note_length(uint16_t ix, uint8_t a);
uint8_t read_transpose(uint16_t de);
uint8_t read_volume_offset(uint16_t de);
uint16_t read_track_address(uint16_t de, uint16_t ix);
void unused_note_hook(uint16_t ix);

/* pcm_effects.c: the PCM effects (commands 80-93) and their samples */
uint32_t play_pcm_sample(uint8_t bc, uint16_t de, uint16_t hl, uint16_t ix);
uint32_t pcm_effect_countdown(uint16_t ix);
void queue_pcm_effect_a(uint16_t hl);
uint32_t pcm_effect_81(uint16_t ix);
uint32_t sound_10D6(uint16_t ix);
uint32_t sound_10DD(uint16_t hl, uint16_t ix);
uint32_t sound_10F8(uint16_t ix);
void sound_1114(uint16_t ix);
uint32_t sound_111E(uint16_t ix, uint32_t carry);
uint32_t pcm_effect_82(uint16_t ix);
uint32_t sound_1128(uint16_t bc, uint16_t ix);
uint32_t sound_114B(uint16_t ix);
uint32_t pcm_effect_83(uint16_t ix);
uint32_t sound_116F(uint16_t bc, uint16_t hl, uint16_t ix);
uint32_t pcm_effect_84(uint16_t ix);
uint32_t sound_1187(uint16_t ix);
uint32_t sound_118D(uint16_t bc, uint16_t hl, uint16_t ix);
uint32_t pcm_effect_85(uint16_t ix);
uint32_t pcm_effect_86(uint16_t ix);
uint32_t sound_11C8(uint16_t ix);
uint32_t sound_11DF(uint16_t bc, uint16_t ix);
void pcm_effect_8d(uint16_t ix);
uint32_t sound_11FE(uint16_t ix, uint32_t carry);
uint32_t pcm_effect_87(uint16_t ix);
uint32_t pcm_effect_88(uint16_t ix);
uint32_t sound_1232(uint16_t ix);
void sound_1250(uint16_t ix);
uint32_t sound_125A(uint16_t ix, uint32_t carry);
uint32_t pcm_effect_89(uint16_t ix);
uint32_t sound_1271(uint16_t hl, uint16_t ix);
uint32_t sound_128C(uint16_t ix, uint32_t carry);
uint32_t pcm_effect_8a(uint16_t ix);
uint32_t sound_12A2(uint16_t ix, uint8_t a);
uint32_t sound_12BF(uint16_t ix, uint32_t carry);
uint32_t pcm_effect_8b(uint16_t ix);
uint32_t sound_12DA(uint16_t bc, uint16_t ix);
uint32_t sound_12EB(uint16_t hl, uint16_t ix);
uint32_t sound_12FC(uint16_t ix, uint32_t carry);
void sound_1338(uint16_t ix);
uint32_t sound_1342(uint16_t ix, uint32_t carry);
uint32_t pcm_effect_8c(uint16_t ix);
uint32_t pcm_effect_8e(uint16_t ix);
uint32_t pcm_effect_8f(uint16_t ix);
uint32_t pcm_effect_90(uint16_t ix);
uint32_t pcm_effect_91(uint16_t ix);
uint32_t pcm_effect_92(uint16_t ix);
uint32_t pcm_effect_93(uint16_t ix);

#endif
