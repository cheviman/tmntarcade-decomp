/**
 *    Name:        main.c
 *    Description: the program's frame: sound_main, the main loop, the channels' handlers and their stop
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

void sound_main(void)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t bc = 0, hl = 0;

	z80_block(17);
	b = 0u;
	hl = CHANNEL_ADDRESS(0);
	do
	{
		z80_block(34);
		z80_write8(hl, b);
		hl++;
	} while (hl >> 8 != 0x88u);
	z80_block(104);
	z80_write8(pcm_loop_flags, 0u);
	pcm_loops = 0u;
	z80_write8(pcm_volume_port, 0u);
	pcm_volumes = 0u;
	music_pcm_hold = 0u;
	reset_sound();
	z80_block(27);
	bc = 0x1900u;
	carry = write_fm_register(bc);
	z80_block(27);
	bc = 0x1980u;
	carry = write_fm_register(bc);
	z80_block(411);
	random_seed = 0x305u;
	random_source = 0u;
	random_write = random_pool_ADDRESS;
	random_read = random_pool_ADDRESS;
	unk_8000 = 0u;
	unk_8040 = 1u;
	unk_8080 = 2u;
	unk_80C0 = 3u;
	unk_8100 = 4u;
	unk_8140 = 5u;
	unk_8180 = 6u;
	unk_81C0 = 7u;
	unk_8200 = 8u;
	unk_8240 = 9u;
	unk_8280 = 0xAu;
	unk_82C0 = 0xBu;
	unk_8300 = 0xCu;
	unk_8340 = 6u;
	unk_8380 = 7u;
	restart_frame_timer();
}

void sound_main_loop(void)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t de = 0, hl = 0, ix = 0;
	uint16_t saved_hl = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(8);
	interrupts_on();
	z80_block(16);
	interrupts_off();
	for (;;)
	{
		z80_block(200);
		hl = random_seed;
		saved_hl = hl;
		de = saved_hl;
		hl = hl * 2u + de;
		a = de + (hl >> 8);
		random_seed = (hl & 0xFFu) | ((uint32_t)a << 8);
		hl = random_source;
		a += z80_read8(hl);
		random_source = IN_PAGE(hl, (uint8_t)(hl + 1u));
		hl = random_write;
		z80_write8(hl, a);
		random_write = IN_PAGE(hl, (uint8_t)(hl + 1u));
		t1 = z80_read8(fm_data);
		if ((t1 & 2u) != 0u)
			break;
		z80_cycles(5);
	}
	z80_block(17);
	restart_frame_timer();
	z80_block(31);
	hl = fade_timer_ADDRESS;
	carry = 0u;
	if (fade_timer != 0u)
	{
		z80_block(21);
		t2 = fade_timer;
		fade_timer = t2 - 1u;
		if (t2 == 1u)
		{
			z80_block(71);
			fade_timer = 0x16u;
			unk_83CC = 1u;
			hl++;
			fade_step++;
			if ((fade_step & 3u) == 0u)
			{
				z80_block(30);
				fade_attenuation++;
			}
			z80_block(24);
			t3 = fade_step;
			carry = t3 > 0x30u;
			if (0x30u == t3)
			{
				z80_block(60);
				fade_timer = 0u;
				fade_step = 0u;
				fade_attenuation = 0u;
				free_music_pcm_a();
				z80_block(17);
				free_music_pcm_b();
				z80_block(27);
				if (unk_8281 == 0u)
				{
					z80_block(27);
					if (unk_82C1 == 0u)
					{
						z80_block(17);
						stop_music_pcm_b();
					}
					z80_block(17);
					stop_music_pcm_a();
				}
				z80_block(17);
				free_music_fm_6_7();
				z80_block(27);
				carry = 0u;
				if (unk_8458 == 0u)
				{
					z80_block(17);
					stop_music_fm_6_7();
				}
				z80_block(17);
				stop_music_fm_1_5();
			}
		}
	}
	z80_block(31);
	ix = CHANNEL_ADDRESS(0);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(1);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(2);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(3);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(4);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(5);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(6);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(7);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(8);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(9);
	carry = run_channel_handler(ix, carry);
	z80_block(48);
	carry = 0u;
	unk_83CC = 0u;
	ix = CHANNEL_ADDRESS(11);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(10);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(12);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(13);
	carry = run_channel_handler(ix, carry);
	z80_block(31);
	ix = CHANNEL_ADDRESS(14);
	carry = run_channel_handler(ix, carry);
	z80_block(27);
	if (title_music_on != 0u)
	{
		z80_cycles(7);
		title_music_timer();
	}
	z80_block(10);
}

uint32_t run_channel_handler(uint16_t ix, uint32_t carry)
{
	uint32_t jump_target = 0;

	z80_block(42);
	jump_target = CHANNEL(ix)->handler;
	switch (jump_target)
	{
	case 0x000178u:
		return speech_play(ix);
	case 0x0001A4u:
		return speech_wait(ix, carry);
	case 0x0005D0u:
		return stop_channel(ix);
	case 0x0005D6u:
		free_channel(ix);
		return carry;
	case 0x0005E7u:
		channel_idle();
		return carry;
	case 0x0005E8u:
		return stop_pcm_channel(ix);
	case 0x000885u:
		return music_track_start(ix);
	case 0x0008CDu:
		return music_track_first_tick(ix);
	case 0x0008D6u:
		return music_track_tick(ix);
	case 0x0010AFu:
		return pcm_effect_countdown(ix);
	case 0x0010D0u:
		return pcm_effect_81(ix);
	case 0x0010F8u:
		return sound_10F8(ix);
	case 0x001114u:
		sound_1114(ix);
		return carry;
	case 0x00111Eu:
		return sound_111E(ix, carry);
	case 0x001125u:
		return pcm_effect_82(ix);
	case 0x00114Bu:
		return sound_114B(ix);
	case 0x001165u:
		return pcm_effect_83(ix);
	case 0x001183u:
		return pcm_effect_84(ix);
	case 0x0011A1u:
		return pcm_effect_85(ix);
	case 0x0011AEu:
		return pcm_effect_86(ix);
	case 0x0011C8u:
		return sound_11C8(ix);
	case 0x0011F4u:
		pcm_effect_8d(ix);
		return carry;
	case 0x0011FEu:
		return sound_11FE(ix, carry);
	case 0x00120Eu:
		return pcm_effect_87(ix);
	case 0x00122Cu:
		return pcm_effect_88(ix);
	case 0x001232u:
		return sound_1232(ix);
	case 0x001250u:
		sound_1250(ix);
		return carry;
	case 0x00125Au:
		return sound_125A(ix, carry);
	case 0x001261u:
		return pcm_effect_89(ix);
	case 0x00128Cu:
		return sound_128C(ix, carry);
	case 0x00129Cu:
		return pcm_effect_8a(ix);
	case 0x0012BFu:
		return sound_12BF(ix, carry);
	case 0x0012D1u:
		return pcm_effect_8b(ix);
	case 0x0012FCu:
		return sound_12FC(ix, carry);
	case 0x001338u:
		sound_1338(ix);
		return carry;
	case 0x001342u:
		return sound_1342(ix, carry);
	case 0x00134Cu:
		return pcm_effect_8c(ix);
	case 0x001359u:
		return pcm_effect_8e(ix);
	case 0x00137Du:
		return pcm_effect_8f(ix);
	case 0x0013A3u:
		return pcm_effect_90(ix);
	case 0x0013C1u:
		return pcm_effect_91(ix);
	case 0x0013CEu:
		return pcm_effect_92(ix);
	case 0x0013D4u:
		return pcm_effect_93(ix);
	case 0x001638u:
		return fm_effect_01(ix);
	case 0x001662u:
		return sound_1662(ix);
	case 0x00169Au:
		return fm_effect_02(ix);
	case 0x0016CFu:
		return sound_16CF(ix);
	case 0x001727u:
		return sound_1727(ix, carry);
	case 0x00174Fu:
		return fm_effect_03(ix);
	case 0x00177Du:
		return sound_177D(ix);
	case 0x0017ADu:
		return sound_17AD(ix);
	case 0x0017E7u:
		return fm_effect_04(ix);
	case 0x001811u:
		return fm_effect_05(ix);
	case 0x00183Fu:
		return sound_183F(ix);
	case 0x001868u:
		return sound_1868(ix, carry);
	case 0x001877u:
		fm_effect_37(ix);
		return carry;
	case 0x001881u:
		return sound_1881(ix, carry);
	case 0x001888u:
		return fm_effect_06(ix);
	case 0x0018A9u:
		return sound_18A9(ix);
	case 0x0018D9u:
		return sound_18D9(ix);
	case 0x00192Cu:
		return fm_effect_07(ix);
	case 0x001962u:
		return sound_1962(ix);
	case 0x0019D1u:
		return fm_effect_08(ix);
	case 0x0019F9u:
		return sound_19F9(ix);
	case 0x001A23u:
		return fm_effect_09(ix);
	case 0x001A43u:
		return fm_effect_0a(ix);
	case 0x001A98u:
		return sound_1A98(ix);
	case 0x001B1Bu:
		return sound_1B1B(ix);
	case 0x001B4Fu:
		return fm_effect_0b(ix);
	case 0x001B79u:
		return sound_1B79(ix);
	case 0x001B9Cu:
		return sound_1B9C(ix);
	case 0x001BDEu:
		return fm_effect_0c(ix);
	case 0x001C40u:
		return sound_1C40(ix);
	case 0x001CA0u:
		return fm_effect_0d(ix);
	case 0x001CCEu:
		return sound_1CCE(ix);
	case 0x001D0Au:
		return sound_1D0A(ix);
	case 0x001D4Fu:
		return sound_1D4F(ix, carry);
	case 0x001D74u:
		return fm_effect_0e(ix);
	case 0x001D96u:
		return sound_1D96(ix);
	case 0x001DE4u:
		return sound_1DE4(ix);
	case 0x001E33u:
		return fm_effect_0f(ix);
	case 0x001E4Cu:
		return sound_1E4C(ix);
	case 0x001EB5u:
		return sound_1EB5(ix);
	case 0x001F07u:
		return fm_effect_10(ix);
	case 0x001F37u:
		return sound_1F37(ix);
	case 0x001F7Fu:
		return sound_1F7F(ix);
	case 0x001FCBu:
		return fm_effect_11(ix);
	case 0x001FE4u:
		return sound_1FE4(ix);
	case 0x001FF6u:
		return fm_effect_12(ix);
	case 0x002012u:
		return fm_effect_13(ix);
	case 0x00203Eu:
		return fm_effect_14(ix);
	case 0x002069u:
		return sound_2069(ix, carry);
	case 0x0020ADu:
		return fm_effect_15(ix);
	case 0x0020F5u:
		return sound_20F5(ix, carry);
	case 0x00212Cu:
		sound_212C(ix);
		return carry;
	case 0x002136u:
		return sound_2136(ix, carry);
	case 0x00215Au:
		return fm_effect_16(ix);
	case 0x002197u:
		return sound_2197(ix);
	case 0x0021C6u:
		return sound_21C6(ix);
	case 0x0021D6u:
		return sound_21D6(ix, carry);
	case 0x0021F6u:
		return fm_effect_17(ix);
	case 0x002226u:
		return sound_2226(ix);
	case 0x002299u:
		return fm_effect_18(ix);
	case 0x0022D2u:
		return fm_effect_19(ix);
	case 0x002306u:
		return sound_2306(ix);
	case 0x00234Eu:
		return fm_effect_1a(ix);
	case 0x002393u:
		return sound_2393(ix);
	case 0x0023CAu:
		return sound_23CA(ix);
	case 0x00244Fu:
		return sound_244F(ix);
	case 0x00247Au:
		return sound_247A(ix);
	case 0x0024B7u:
		return sound_24B7(ix);
	case 0x00250Fu:
		return fm_effect_1b(ix);
	case 0x002531u:
		return sound_2531(ix);
	case 0x002556u:
		return sound_2556(ix);
	case 0x00257Fu:
		return fm_effect_1c(ix);
	case 0x0025B8u:
		return sound_25B8(ix);
	case 0x0025FEu:
		sound_25FE(ix);
		return carry;
	case 0x002608u:
		return sound_2608(ix, carry);
	case 0x00262Au:
		return fm_effect_1d(ix);
	case 0x00267Au:
		return sound_267A(ix, carry);
	case 0x0026A5u:
		return sound_26A5(ix, carry);
	case 0x0026ACu:
		sound_26AC(ix);
		return carry;
	case 0x0026B6u:
		return sound_26B6(ix, carry);
	case 0x0026C4u:
		return fm_effect_1e(ix);
	case 0x0026D4u:
		return sound_26D4(ix, carry);
	case 0x0026F6u:
		return fm_effect_1f(ix);
	case 0x002713u:
		return sound_2713(ix);
	case 0x00274Du:
		return sound_274D(ix, carry);
	case 0x002767u:
		return fm_effect_20(ix);
	case 0x002785u:
		return fm_effect_21(ix);
	case 0x0027A7u:
		return sound_27A7(ix);
	case 0x0027DDu:
		return sound_27DD(ix);
	case 0x002804u:
		return fm_effect_22(ix);
	case 0x002857u:
		return sound_2857(ix);
	case 0x00285Cu:
		return sound_285C(ix);
	case 0x002861u:
		return sound_2861(ix);
	case 0x002866u:
		return sound_2866(ix);
	case 0x00286Bu:
		return sound_286B(ix);
	case 0x002870u:
		return sound_2870(ix);
	case 0x002875u:
		return sound_2875(ix);
	case 0x00288Eu:
		return sound_288E(ix, carry);
	case 0x0028B6u:
		return fm_effect_23(ix);
	case 0x0028E1u:
		return sound_28E1(ix, carry);
	case 0x002925u:
		return fm_effect_24(ix);
	case 0x002958u:
		return sound_2958(ix);
	case 0x002998u:
		return sound_2998(ix);
	case 0x0029EBu:
		return fm_effect_25(ix);
	case 0x002A0Du:
		return sound_2A0D(ix, carry);
	case 0x002A33u:
		return sound_2A33(ix);
	case 0x002A68u:
		return fm_effect_26(ix);
	case 0x002AABu:
		return sound_2AAB(ix);
	case 0x002B2Du:
		return fm_effect_27(ix);
	case 0x002B52u:
		return sound_2B52(ix);
	case 0x002BDFu:
		return fm_effect_28(ix);
	case 0x002C09u:
		return sound_2C09(ix);
	case 0x002C49u:
		return fm_effect_29(ix);
	case 0x002C60u:
		return sound_2C60(ix);
	case 0x002C8Du:
		return sound_2C8D(ix);
	case 0x002CBAu:
		return sound_2CBA(ix);
	case 0x002CF5u:
		return fm_effect_2a(ix);
	case 0x002D1Du:
		return sound_2D1D(ix);
	case 0x002D40u:
		return sound_2D40(ix, carry);
	case 0x002D7Du:
		return fm_effect_2b(ix);
	case 0x002D9Du:
		return sound_2D9D(ix);
	case 0x002DBFu:
		return fm_effect_2c(ix);
	case 0x002DF6u:
		return sound_2DF6(ix);
	case 0x002E35u:
		return sound_2E35(ix, carry);
	case 0x002E77u:
		return fm_effect_2d(ix);
	case 0x002EAAu:
		return sound_2EAA(ix, carry);
	case 0x002F11u:
		return fm_effect_2e(ix);
	case 0x002F3Cu:
		return sound_2F3C(ix);
	case 0x002F76u:
		return sound_2F76(ix, carry);
	case 0x002FA8u:
		return fm_effect_2f(ix);
	case 0x002FD0u:
		return sound_2FD0(ix);
	case 0x003032u:
		return fm_effect_30(ix);
	case 0x003042u:
		return sound_3042(ix);
	case 0x00306Fu:
		return sound_306F(ix);
	case 0x0030A4u:
		return fm_effect_31(ix);
	case 0x0030CFu:
		return sound_30CF(ix);
	case 0x003109u:
		return sound_3109(ix, carry);
	case 0x003154u:
		return fm_effect_32(ix);
	case 0x003181u:
		return sound_3181(ix);
	case 0x0031ADu:
		return fm_effect_33(ix);
	case 0x0031CEu:
		return fm_effect_34(ix);
	case 0x00320Du:
		return sound_320D(ix);
	case 0x003258u:
		return sound_3258(ix);
	case 0x00329Cu:
		return sound_329C(ix);
	case 0x0032D4u:
		return sound_32D4(ix);
	case 0x003316u:
		return fm_effect_35(ix);
	case 0x003336u:
		return fm_effect_36(ix);
	case 0x003353u:
		return sound_3353(ix);
	case 0x003388u:
		sound_3388(ix);
		return carry;
	case 0x003395u:
		return sound_3395(ix);
	case 0x0033C2u:
		return fm_effect_38(ix);
	case 0x0033E9u:
		return sound_33E9(ix);
	case 0x003432u:
		return fm_effect_39(ix);
	case 0x00345Fu:
		return sound_345F(ix, carry);
	case 0x00348Bu:
		return fm_effect_3a(ix);
	case 0x0034C3u:
		return sound_34C3(ix);
	case 0x003524u:
		return fm_effect_3b(ix);
	case 0x00354Cu:
		return sound_354C(ix);
	case 0x003570u:
		return fm_effect_3c(ix);
	case 0x0035A6u:
		return sound_35A6(ix);
	case 0x0035D3u:
		return fm_effect_3d(ix);
	case 0x0035FDu:
		return sound_35FD(ix);
	case 0x003604u:
		return sound_3604(ix);
	case 0x00361Au:
		return sound_361A(ix, carry);
	case 0x003621u:
		return fm_effect_3e(ix);
	case 0x00363Au:
		sound_363A(ix);
		return carry;
	case 0x003644u:
		return sound_3644(ix, carry);
	case 0x003664u:
		return fm_effect_3f(ix);
	case 0x003694u:
		return sound_3694(ix);
	case 0x0036C8u:
		return sound_36C8(ix, carry);
	case 0x003703u:
		return fm_effect_40(ix);
	case 0x00373Fu:
		return fm_effect_41(ix);
	case 0x003769u:
		return sound_3769(ix, carry);
	default:
		sound_invalid_jump(jump_target);
	}
}

uint32_t stop_channel(uint16_t ix)
{
	uint32_t carry = 0;

	z80_block(17);
	fm_key_off(ix);
	z80_block(17);
	carry = fm_fast_release(ix);
	free_channel(ix);
	return carry;
}

void free_channel(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(48);
	CHANNEL(ix)->sound = 0u;
	CHANNEL(ix)->priority = 0u;
	hl = 0x5E7u;
	set_channel_handler(hl, ix);
}

void set_channel_handler(uint16_t hl, uint16_t ix)
{
	z80_block(38);
	CHANNEL(ix)->handler = hl;
	channel_idle();
}

void channel_idle(void)
{
	z80_block(10);
}

uint32_t stop_pcm_channel(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t bc = 0;

	z80_block(51);
	music_attenuation = 0u;
	unk_83CC = 0u;
	bc = 0u;
	carry = set_pcm_volume(bc, ix);
	z80_block(17);
	carry = clear_pcm_loop(ix);
	z80_block(10);
	free_channel(ix);
	return carry;
}
