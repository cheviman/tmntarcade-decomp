/**
 *    Name:        objects/states.c
 *    Description: the objects' state dispatcher and the objects' handlers (provisional: by subject later)
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void run_object_state(uint32_t a0, uint32_t a1, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d0 = 0;
	uint32_t a6_2 = 0;

	d0 = (uint16_t)((uint32_t)OBJECT(a0)->state << 2);
	a6_2 = mem_read32(a6 + d0);
	switch (a6_2)
	{
	case 0x00FA00u:
		*p_d7 = ball_land(*p_d7, a0);
		return;
	case 0x00FC00u:
		*p_d7 = hydrant_spray_jet(*p_d7, a0, a6_2);
		return;
	case 0x00FFC0u:
		*p_d7 = rat_run_on(*p_d7, a0);
		return;
	case 0x00FFE0u:
		*p_d7 = rat_squeak(*p_d7, a0);
		return;
	case 0x048F62u:
		enemy_hop_crouch(a0);
		return;
	case 0x048F72u:
		enemy_hop_down(a0);
		return;
	case 0x048FBAu:
		*p_d7 = enemy_hop_fall(*p_d7, a0);
		return;
	case 0x048FFAu:
		enemy_hop_land(a0);
		return;
	case 0x04901Au:
		enemy_hop_right(a0);
		return;
	case 0x049078u:
		enemy_hop_left(a0);
		return;
	case 0x0490D6u:
		enemy_hop_up_crouch(a0);
		return;
	case 0x0490E6u:
		enemy_hop_up(a0);
		return;
	case 0x04911Cu:
		*p_d7 = enemy_hop_up_fall(*p_d7, a0);
		return;
	case 0x04916Cu:
		enemy_hop_up_right(a0);
		return;
	case 0x0491A8u:
		*p_d7 = enemy_hop_up_fall_blocked(*p_d7, a0);
		return;
	case 0x0491F8u:
		enemy_hop_up_left(a0);
		return;
	case 0x049260u:
		enemy_shuffle_start(a0);
		return;
	case 0x049276u:
		enemy_shuffle_step(a0);
		return;
	case 0x0492A8u:
		enemy_shuffle_turn(a0);
		return;
	case 0x0492DEu:
		enemy_shuffle_end(a0);
		return;
	case 0x049300u:
		enemy_retreat_start(a0);
		return;
	case 0x04933Au:
		enemy_retreat_step(a0);
		return;
	case 0x049378u:
		enemy_circle_start(a0, p_d7, p_a5);
		return;
	case 0x0493CAu:
		enemy_circle_step(a0, p_d7, p_a5);
		return;
	case 0x049420u:
		*p_d7 = enemy_charge_start(a0);
		return;
	case 0x049468u:
		*p_d7 = enemy_charge_run(*p_d7, a0);
		return;
	case 0x04949Eu:
		*p_d7 = enemy_charge_brake(*p_d7, a0);
		return;
	case 0x0494DAu:
		*p_d7 = enemy_crash_into_scenery_start(*p_d7, a0);
		return;
	case 0x049534u:
		*p_d7 = enemy_crash_into_scenery_end(*p_d7, a0);
		return;
	case 0x049570u:
		*p_d7 = enemy_crash_into_scenery_low_start(*p_d7, a0);
		return;
	case 0x0495DEu:
		enemy_walk_to_target_start(a0, a1, p_d7, p_a5);
		return;
	case 0x049604u:
		enemy_walk_to_target_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04966Eu:
		enemy_walk_to_side_start(a0, a1, p_d7, p_a5);
		return;
	case 0x049694u:
		enemy_walk_to_side_step(a0, a1, p_d7, p_a5);
		return;
	case 0x0496FAu:
		enemy_walk_to_side_crouch(a0);
		return;
	case 0x04971Eu:
		enemy_walk_to_side_turn(a0, a1, p_d7, p_a5);
		return;
	case 0x04973Eu:
		enemy_walk_to_side_hold(a0, a1, p_d7, p_a5);
		return;
	case 0x0497A6u:
		*p_d7 = enemy_keep_distance_start(*p_d7, a0);
		return;
	case 0x0497C2u:
		enemy_keep_distance_watch(a0, a1, p_d7, p_a5);
		return;
	case 0x04984Cu:
		enemy_keep_distance_back_off(a0, a1, p_d7, p_a5);
		return;
	case 0x049868u:
		enemy_keep_distance_close_in(a0, a1, p_d7, p_a5);
		return;
	case 0x0498B2u:
		enemy_back_off_start(a0, a1, p_d7, p_a5);
		return;
	case 0x0498EEu:
		enemy_back_off_walk(a0, a1, p_d7, p_a5);
		return;
	case 0x04991Eu:
		enemy_back_off_wait(a0, a1);
		return;
	case 0x049948u:
		enemy_run_away_start(a0, a1, p_d7, p_a5);
		return;
	case 0x049980u:
		enemy_run_away_step(a0, a1, p_d7, p_a5);
		return;
	case 0x0499B8u:
		enemy_walk_across_start(a0, a1, p_d7, p_a5);
		return;
	case 0x0499EAu:
		enemy_walk_across_step(a0, a1, p_d7, p_a5);
		return;
	case 0x049A1Au:
		*p_d7 = enemy_jab_start(*p_d7, a0);
		return;
	case 0x049A42u:
		enemy_attack_end(a0);
		return;
	case 0x049A66u:
		*p_d7 = enemy_chop_start(*p_d7, a0);
		return;
	case 0x049AA2u:
		*p_d7 = enemy_swing_start(*p_d7, a0);
		return;
	case 0x049ADEu:
		*p_d7 = enemy_high_kick_start(*p_d7, a0);
		return;
	case 0x049B2Eu:
		*p_d7 = enemy_jump_kick_crouch(*p_d7, a0);
		return;
	case 0x049B56u:
		*p_d7 = enemy_jump_kick_leap(*p_d7, a0);
		return;
	case 0x049B82u:
		*p_d7 = enemy_jump_kick_fly(*p_d7, a0);
		return;
	case 0x049BE4u:
		*p_d7 = enemy_long_jump_kick_crouch(*p_d7, a0);
		return;
	case 0x049C0Cu:
		*p_d7 = enemy_long_jump_kick_leap(*p_d7, a0);
		return;
	case 0x049C38u:
		*p_d7 = enemy_long_jump_kick_fly(*p_d7, a0);
		return;
	case 0x049C92u:
		enemy_grab_start(a0, a1, p_d7, p_a5);
		return;
	case 0x049D06u:
		enemy_grab_run(a0, a1, p_d7, p_a5);
		return;
	case 0x049D7Eu:
		enemy_grab_hold(a0, a1);
		return;
	case 0x049DD0u:
		enemy_grab_end(a0);
		return;
	case 0x049DF0u:
		enemy_flinch_back_start(a0);
		return;
	case 0x049E00u:
		enemy_flinch_end(a0);
		return;
	case 0x049E24u:
		enemy_flinch_bent_start(a0);
		return;
	case 0x049E48u:
		enemy_flinch_reel_start(a0);
		return;
	case 0x049E6Cu:
		enemy_flinch_hunched_start(a0);
		return;
	case 0x049EACu:
		*p_d7 = enemy_killed_back_start(*p_d7, a0, a1);
		return;
	case 0x049EC8u:
		*p_d7 = enemy_killed_back_fly(*p_d7, a0);
		return;
	case 0x049F38u:
		enemy_killed_back_lie(a0, a1);
		return;
	case 0x049F6Au:
		enemy_killed_back_on_wall(a0);
		return;
	case 0x049F78u:
		*p_d7 = enemy_killed_back_slide_down(*p_d7, a0);
		return;
	case 0x049FA0u:
		enemy_killed_back_down(a0, a1);
		return;
	case 0x049FE8u:
		*p_d7 = enemy_killed_forward_start(*p_d7, a0, a1);
		return;
	case 0x04A004u:
		*p_d7 = enemy_killed_forward_fly(*p_d7, a0);
		return;
	case 0x04A074u:
		enemy_killed_forward_lie(a0, a1);
		return;
	case 0x04A0A6u:
		enemy_killed_forward_on_wall(a0);
		return;
	case 0x04A0B4u:
		*p_d7 = enemy_killed_forward_slide_down(*p_d7, a0);
		return;
	case 0x04A0DCu:
		enemy_killed_forward_down(a0, a1);
		return;
	case 0x04A120u:
		*p_d7 = enemy_knocked_forward_start(*p_d7, a0, a1);
		return;
	case 0x04A13Cu:
		*p_d7 = enemy_knocked_forward_fly(*p_d7, a0);
		return;
	case 0x04A176u:
		enemy_knocked_forward_lie(a0, a1);
		return;
	case 0x04A1BAu:
		enemy_knocked_forward_wait(a0);
		return;
	case 0x04A202u:
		unreached_04A202(a0);
		return;
	case 0x04A214u:
		enemy_thrown_by_donatello_swing(a0, a1, p_d7, p_a5);
		return;
	case 0x04A25Au:
		*p_d7 = enemy_thrown_fly(*p_d7, a0);
		return;
	case 0x04A396u:
		unreached_04A396(a0);
		return;
	case 0x04A3A8u:
		enemy_thrown_by_michelangelo_swing(a0, a1, p_d7, p_a5);
		return;
	case 0x04A454u:
		unreached_04A454(a0);
		return;
	case 0x04A466u:
		enemy_thrown_by_raphael_swing(a0, a1, p_d7, p_a5);
		return;
	case 0x04A512u:
		unreached_04A512(a0);
		return;
	case 0x04A524u:
		enemy_thrown_by_leonardo_swing(a0, a1, p_d7, p_a5);
		return;
	case 0x04A5CEu:
		*p_d7 = enemy_knocked_back_start(*p_d7, a0, a1);
		return;
	case 0x04A5F8u:
		*p_d7 = enemy_knocked_back_fly(*p_d7, a0);
		return;
	case 0x04A632u:
		enemy_knocked_back_lie(a0, a1);
		return;
	case 0x04A676u:
		enemy_knocked_back_wait(a0);
		return;
	case 0x04A690u:
		enemy_knocked_back_get_up(a0);
		return;
	case 0x04A6C6u:
		*p_d7 = enemy_die_start(*p_d7, a0);
		return;
	case 0x04A6E6u:
		enemy_die_vanish(a0);
		return;
	case 0x04A718u:
		*p_d7 = enemy_die_on_back_start(*p_d7, a0);
		return;
	case 0x04ADC8u:
		enemy_walk_to_target_sword_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04AE0Eu:
		enemy_walk_to_side_sword_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04AE34u:
		enemy_walk_to_side_sword_crouch(a0);
		return;
	case 0x04AE58u:
		enemy_walk_to_side_sword_turn(a0, a1, p_d7, p_a5);
		return;
	case 0x04AE8Cu:
		enemy_walk_past_sword_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04AEBCu:
		enemy_walk_past_sword_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04AF3Cu:
		enemy_back_off_sword_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04AF78u:
		enemy_back_off_sword_walk(a0, a1, p_d7, p_a5);
		return;
	case 0x04AFA8u:
		enemy_back_off_sword_wait(a0, a1);
		return;
	case 0x04AFD2u:
		enemy_walk_to_line_sword_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04B00Au:
		enemy_walk_to_line_sword_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04B04Eu:
		enemy_walk_to_target_hammer_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04B08Cu:
		enemy_walk_to_side_hammer_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04B0B2u:
		enemy_walk_to_side_far_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04B118u:
		enemy_walk_to_side_far_hold(a0, a1, p_d7, p_a5);
		return;
	case 0x04B146u:
		enemy_stalk_hammer_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04B168u:
		enemy_stalk_hammer_approach(a0, a1, p_d7, p_a5);
		return;
	case 0x04B1ACu:
		enemy_stalk_hammer_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04B250u:
		enemy_walk_away_hammer_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04B284u:
		enemy_walk_away_hammer_walk(a0, a1, p_d7, p_a5);
		return;
	case 0x04B2BCu:
		enemy_walk_away_hammer_wait(a0, a1);
		return;
	case 0x04B2EEu:
		*p_d7 = enemy_slash_sword_start(*p_d7, a0);
		return;
	case 0x04B32Au:
		*p_d7 = enemy_low_slash_sword_start(*p_d7, a0);
		return;
	case 0x04B37Au:
		*p_d7 = enemy_leaping_slash_sword_start(*p_d7, a0);
		return;
	case 0x04B3A2u:
		*p_d7 = enemy_leaping_slash_sword_leap(*p_d7, a0);
		return;
	case 0x04B3F0u:
		*p_d7 = enemy_leaping_slash_sword_fly(*p_d7, a0);
		return;
	case 0x04B452u:
		*p_d7 = enemy_jump_slash_sword_start(*p_d7, a0);
		return;
	case 0x04B47Au:
		*p_d7 = enemy_jump_slash_sword_leap(*p_d7, a0);
		return;
	case 0x04B4A6u:
		*p_d7 = enemy_jump_slash_sword_fly(*p_d7, a0);
		return;
	case 0x04B508u:
		*p_d7 = enemy_flying_slash_sword_start(*p_d7, a0);
		return;
	case 0x04B530u:
		*p_d7 = enemy_flying_slash_sword_leap(*p_d7, a0);
		return;
	case 0x04B588u:
		*p_d7 = enemy_flying_slash_sword_fly(*p_d7, a0);
		return;
	case 0x04B5EAu:
		*p_d7 = enemy_smash_hammer_start(*p_d7, a0);
		return;
	case 0x04B622u:
		enemy_smash_hammer_end(a0);
		return;
	case 0x04B646u:
		enemy_flinch_back_sword_start(a0);
		return;
	case 0x04B66Au:
		enemy_flinch_bent_sword_start(a0);
		return;
	case 0x04B68Eu:
		enemy_flinch_reel_sword_start(a0);
		return;
	case 0x04B6B2u:
		enemy_flinch_hunched_sword_start(a0);
		return;
	case 0x04B6D6u:
		enemy_flinch_back_hammer_start(a0);
		return;
	case 0x04B6FAu:
		enemy_flinch_bent_hammer_start(a0);
		return;
	case 0x04C824u:
		enemy_step_out_start(a0);
		return;
	case 0x04C840u:
		enemy_step_out_wait(a0);
		return;
	case 0x04C860u:
		enemy_step_out_walk(a0);
		return;
	case 0x04CF74u:
		enemy_walk_in_on_ledge_start(a0);
		return;
	case 0x04CF9Au:
		enemy_walk_in_on_ledge_walk(a0, a6_2, p_d5, p_d7, p_a5);
		return;
	case 0x04CFD6u:
		enemy_jump_down_leap(a0);
		return;
	case 0x04D006u:
		*p_d7 = enemy_jump_down_fall_stairs(*p_d7, a0);
		return;
	case 0x04D00Cu:
		*p_d7 = enemy_jump_down_fall(*p_d7, a0);
		return;
	case 0x04D04Au:
		enemy_jump_down_land(a0);
		return;
	case 0x04D072u:
		enemy_step_down_start(a0);
		return;
	case 0x04D08Eu:
		enemy_step_down_wait(a0);
		return;
	case 0x04D2D4u:
		enemy_leap_out_start(a0);
		return;
	case 0x04D2FEu:
		*p_d7 = enemy_leap_out_fly(*p_d7, a0);
		return;
	case 0x04D330u:
		enemy_leap_out_land(a0);
		return;
	case 0x04D820u:
		enemy_hang_in_start(a0);
		return;
	case 0x04D856u:
		enemy_hang_in_move(a0);
		return;
	case 0x04D884u:
		*p_d7 = enemy_hang_in_drop(*p_d7, a0);
		return;
	case 0x04D8ACu:
		enemy_hang_in_land(a0);
		return;
	case 0x04D8E0u:
		enemy_kick_in_start(a0);
		return;
	case 0x04D91Cu:
		enemy_kick_in_run(a0);
		return;
	case 0x04D93Au:
		*p_d7 = enemy_kick_in_leap(*p_d7, a0);
		return;
	case 0x04D96Cu:
		*p_d7 = enemy_kick_in_fly(*p_d7, a0);
		return;
	case 0x04D9A6u:
		enemy_kick_in_land(a0);
		return;
	case 0x04D9C2u:
		enemy_run_in_start(a0);
		return;
	case 0x04D9F8u:
		enemy_run_in_run(a0);
		return;
	case 0x04DA2Cu:
		enemy_dive_in_start(a0);
		return;
	case 0x04DA58u:
		enemy_dive_in_run(a0, a6_2, p_d5, p_d7, p_a5);
		return;
	case 0x04DA92u:
		enemy_dive_in_leap(a0);
		return;
	case 0x04DACAu:
		enemy_dive_in_dive(a0);
		return;
	case 0x04DAF6u:
		enemy_dive_in_curl(a0);
		return;
	case 0x04DB1Au:
		enemy_dive_in_uncurl(a0);
		return;
	case 0x04DB36u:
		*p_d7 = enemy_dive_in_land(*p_d7, a0);
		return;
	case 0x04DB76u:
		enemy_walk_in_start(a0);
		return;
	case 0x04DBAEu:
		enemy_walk_in_walk(a0);
		return;
	case 0x04DBD4u:
		enemy_walk_in_ready(a0);
		return;
	case 0x04DD50u:
		enemy_walk_to_target_spear_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04DD8Eu:
		enemy_walk_to_side_spear_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04DDC8u:
		enemy_walk_off_line_spear_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04DDF8u:
		enemy_walk_off_line_spear_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04DE78u:
		enemy_back_off_spear_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04DEB2u:
		enemy_back_off_spear_walk(a0, a1, p_d7, p_a5);
		return;
	case 0x04DEF6u:
		enemy_step_aside_spear_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04DF40u:
		enemy_step_aside_spear_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04DF80u:
		enemy_walk_to_target_knife_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04DFBEu:
		enemy_walk_to_side_knife_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04E018u:
		enemy_circle_knife_start(a0, p_d7, p_a5);
		return;
	case 0x04E06Au:
		enemy_circle_knife_step(a0, p_d7, p_a5);
		return;
	case 0x04E0C4u:
		*p_d7 = enemy_keep_distance_knife_start(*p_d7, a0);
		return;
	case 0x04E0E0u:
		enemy_keep_distance_knife_watch(a0, a1, p_d7, p_a5);
		return;
	case 0x04E16Au:
		enemy_keep_distance_knife_back_off(a0, a1, p_d7, p_a5);
		return;
	case 0x04E186u:
		enemy_keep_distance_knife_close_in(a0, a1, p_d7, p_a5);
		return;
	case 0x04E1D0u:
		enemy_back_off_knife_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04E20Au:
		enemy_back_off_knife_walk(a0, a1, p_d7, p_a5);
		return;
	case 0x04E23Eu:
		enemy_back_off_knife_wait(a0, a1);
		return;
	case 0x04E268u:
		enemy_step_aside_knife_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04E2A0u:
		enemy_step_aside_knife_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04E2D8u:
		*p_d7 = enemy_spear_thrust_start(*p_d7, a0);
		return;
	case 0x04E300u:
		enemy_spear_thrust_end(a0);
		return;
	case 0x04E354u:
		enemy_spear_throw_start(a0);
		return;
	case 0x04E380u:
		enemy_spear_throw_release(a0, p_d7, p_a5);
		return;
	case 0x04E3A0u:
		enemy_spear_throw_end(a0, a1, a6_2, p_d5, p_d7, p_a5);
		return;
	case 0x04E3D8u:
		*p_d7 = enemy_knife_stab_start(*p_d7, a0);
		return;
	case 0x04E414u:
		*p_d7 = enemy_high_kick_knife_start(*p_d7, a0);
		return;
	case 0x04E464u:
		*p_d7 = enemy_jump_kick_knife_crouch(*p_d7, a0);
		return;
	case 0x04E48Cu:
		*p_d7 = enemy_jump_kick_knife_leap(*p_d7, a0);
		return;
	case 0x04E4B8u:
		*p_d7 = enemy_jump_kick_knife_fly(*p_d7, a0);
		return;
	case 0x04E510u:
		enemy_throw_knife_start(a0);
		return;
	case 0x04E53Cu:
		enemy_throw_knife_release(a0, p_d7, p_a5);
		return;
	case 0x04E556u:
		enemy_throw_knife_end(a0);
		return;
	case 0x04E57Au:
		enemy_flinch_back_spear_start(a0);
		return;
	case 0x04E59Eu:
		enemy_flinch_bent_spear_start(a0);
		return;
	case 0x04E5C2u:
		enemy_flinch_reel_spear_start(a0);
		return;
	case 0x04E5E6u:
		enemy_flinch_hunched_spear_start(a0);
		return;
	case 0x04E60Au:
		enemy_flinch_back_knife_start(a0);
		return;
	case 0x04E62Eu:
		enemy_flinch_bent_knife_start(a0);
		return;
	case 0x04E652u:
		enemy_flinch_reel_knife_start(a0);
		return;
	case 0x04E676u:
		enemy_flinch_hunched_knife_start(a0);
		return;
	case 0x04E7CEu:
		enemy_walk_to_target_gun_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04E80Cu:
		enemy_walk_to_side_gun_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04E84Au:
		enemy_walk_to_range_gun_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04E870u:
		enemy_walk_to_range_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04E8D8u:
		enemy_walk_to_range_hold(a0, a1, p_d7, p_a5);
		return;
	case 0x04E912u:
		enemy_back_off_gun_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04E94Cu:
		enemy_back_off_gun_walk(a0, a1, p_d7, p_a5);
		return;
	case 0x04E97Cu:
		enemy_back_off_gun_wait(a0, a1);
		return;
	case 0x04E9A6u:
		enemy_run_away_gun_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04E9DEu:
		enemy_run_away_gun_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04EA26u:
		enemy_walk_to_target_axe_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04EA64u:
		enemy_walk_to_side_axe_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04EAA2u:
		enemy_walk_to_range_axe_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04EAE0u:
		enemy_back_off_axe_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04EB1Cu:
		enemy_back_off_axe_walk(a0, a1, p_d7, p_a5);
		return;
	case 0x04EB4Cu:
		enemy_back_off_axe_wait(a0, a1);
		return;
	case 0x04EB76u:
		enemy_run_away_axe_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04EBAEu:
		enemy_run_away_axe_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04EBF4u:
		enemy_throw_axes_start(a0);
		return;
	case 0x04EC20u:
		enemy_throw_axes_release(a0, p_d7, p_a5);
		return;
	case 0x04EC72u:
		*p_d7 = enemy_high_kick_axe_start(*p_d7, a0);
		return;
	case 0x04ECAEu:
		*p_d7 = enemy_gun_swing_start(*p_d7, a0);
		return;
	case 0x04ECF4u:
		enemy_shoot_gun_start(a0);
		return;
	case 0x04ED20u:
		enemy_shoot_gun_fire(a0, p_d7, p_a5);
		return;
	case 0x04ED72u:
		enemy_flinch_back_gun_start(a0);
		return;
	case 0x04ED96u:
		enemy_flinch_bent_gun_start(a0);
		return;
	case 0x04EDBAu:
		enemy_flinch_back_axe_start(a0);
		return;
	case 0x04EDDEu:
		enemy_flinch_bent_axe_start(a0);
		return;
	case 0x04EE02u:
		enemy_flinch_reel_axe_start(a0);
		return;
	case 0x04F094u:
		enemy_throw_shuriken_start(a0);
		return;
	case 0x04F0C0u:
		enemy_throw_shuriken_release(a0, p_d7, p_a5);
		return;
	case 0x04F10Au:
		enemy_boomerang_throw_wind_up(a0);
		return;
	case 0x04F11Au:
		enemy_boomerang_throw_aim(a0);
		return;
	case 0x04F150u:
		enemy_boomerang_throw_release(a0, p_d7, p_a5);
		return;
	case 0x04F186u:
		enemy_boomerang_throw_wait(a0);
		return;
	case 0x04F2AEu:
		enemy_rocksteady_enter_wait(a0);
		return;
	case 0x04F2CEu:
		enemy_rocksteady_enter_taunt(d0, a0, p_d5, p_d7);
		return;
	case 0x04F318u:
		*p_d7 = enemy_rocksteady_enter_ready(*p_d7, a0);
		return;
	case 0x04F340u:
		enemy_rocksteady_enter_walk_in(a0);
		return;
	case 0x04F35Eu:
		enemy_rocksteady_enter_wait_for_signal(a0);
		return;
	case 0x04F380u:
		enemy_rocksteady_enter_walk_in_with_bebop(a0, p_d7, p_a5);
		return;
	case 0x04F736u:
		enemy_rocksteady_raise_fist_start(a0, a1);
		return;
	case 0x04F764u:
		enemy_rocksteady_laugh_start(a0, a1);
		return;
	case 0x04F792u:
		enemy_rocksteady_shake_fist_start(a0, a1);
		return;
	case 0x04F7ACu:
		enemy_rocksteady_hold_pose(a0);
		return;
	case 0x04F7C6u:
		enemy_rocksteady_draw_gun_start(a0, a1);
		return;
	case 0x04F7E0u:
		enemy_rocksteady_pose_end(a0);
		return;
	case 0x04F802u:
		enemy_rocksteady_put_gun_away_start(a0, a1);
		return;
	case 0x04F830u:
		enemy_rocksteady_circle_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04F862u:
		enemy_rocksteady_circle_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04F8B0u:
		enemy_rocksteady_line_up_start(a0, a1);
		return;
	case 0x04F8CCu:
		enemy_rocksteady_line_up_step(a0, a1);
		return;
	case 0x04F936u:
		enemy_rocksteady_close_in_start(a0, a1, p_d7, p_a5);
		return;
	case 0x04F952u:
		enemy_rocksteady_close_in_step(a0, a1, p_d7, p_a5);
		return;
	case 0x04F9F2u:
		enemy_rocksteady_shoot_around_start(a0, p_d7, p_a5);
		return;
	case 0x04FA0Au:
		enemy_rocksteady_shoot_around_fire(a0, p_d7, p_a5);
		return;
	case 0x04FAE6u:
		enemy_rocksteady_pincer_charge_start(a0);
		return;
	case 0x04FB06u:
		enemy_rocksteady_pincer_charge_run_to_edge(a0);
		return;
	case 0x04FB3Cu:
		enemy_rocksteady_pincer_charge_wait_for_bebop(a0);
		return;
	case 0x04FB82u:
		enemy_rocksteady_pincer_charge_get_ready(a0);
		return;
	case 0x04FB86u:
		enemy_rocksteady_pincer_charge_run(a0);
		return;
	case 0x04FBEEu:
		enemy_rocksteady_pincer_charge_crash(a0);
		return;
	case 0x04FC1Cu:
		*p_d7 = enemy_rocksteady_charge_start(*p_d7, a0);
		return;
	case 0x04FC4Au:
		enemy_rocksteady_charge_get_ready(a0);
		return;
	case 0x04FC76u:
		enemy_rocksteady_charge_run(a0);
		return;
	case 0x04FCE8u:
		*p_d7 = enemy_rocksteady_punch_start(*p_d7, a0);
		return;
	case 0x04FD2Cu:
		enemy_rocksteady_blow_end(a0);
		return;
	case 0x04FD60u:
		*p_d7 = enemy_rocksteady_gun_butt_start(*p_d7, a0);
		return;
	case 0x04FDB8u:
		*p_a5 = enemy_rocksteady_shoot_start(a0, a1);
		return;
	case 0x04FE02u:
		enemy_rocksteady_shoot_fire(a0, p_d7, p_a5);
		return;
	case 0x04FE5Eu:
		enemy_rocksteady_flinch_start(a0);
		return;
	case 0x04FE7Au:
		enemy_rocksteady_flinch_end(a0);
		return;
	case 0x04FEC6u:
		enemy_rocksteady_reel_start(a0);
		return;
	case 0x04FEFEu:
		enemy_rocksteady_flinch_from_behind_start(a0);
		return;
	case 0x04FF5Eu:
		*p_d7 = enemy_rocksteady_knocked_down_start(*p_d7, a0, a1);
		return;
	case 0x04FF98u:
		*p_d7 = enemy_rocksteady_knocked_down_fall(*p_d7, a0);
		return;
	case 0x04FFCEu:
		enemy_rocksteady_knocked_down_slide(a0);
		return;
	case 0x04FFFCu:
		*p_d7 = enemy_rocksteady_knocked_down_lie(*p_d7, a0);
		return;
	case 0x050036u:
		enemy_rocksteady_knocked_down_get_up(a0);
		return;
	case 0x0500AEu:
		*p_d7 = enemy_rocksteady_defeated_start(*p_d7, a0, a1);
		return;
	case 0x0500F0u:
		*p_d7 = enemy_rocksteady_defeated_fall(*p_d7, a0);
		return;
	case 0x050152u:
		enemy_rocksteady_defeated_slide(a0);
		return;
	case 0x050180u:
		enemy_rocksteady_defeated_blink(a0);
		return;
	case 0x0502A6u:
		*p_d7 = enemy_bebop_enter_wait_for_scroll(*p_d7, a0);
		return;
	case 0x0502DCu:
		enemy_bebop_enter_wait(a0);
		return;
	case 0x0502F2u:
		*p_d7 = enemy_bebop_enter_drop(*p_d7, a0);
		return;
	case 0x050320u:
		*p_d7 = enemy_bebop_enter_jump(*p_d7, a0);
		return;
	case 0x050340u:
		*p_d7 = enemy_bebop_enter_in_air(*p_d7, a0);
		return;
	case 0x05036Eu:
		*p_d7 = enemy_bebop_enter_ready(*p_d7, a0);
		return;
	case 0x050392u:
		enemy_bebop_enter_wait_for_signal(a0);
		return;
	case 0x0503B2u:
		enemy_bebop_enter_walk_in(a0, p_d7, p_a5);
		return;
	case 0x0506A2u:
		*p_d7 = enemy_bebop_stand_start(a0, a1);
		return;
	case 0x0506D2u:
		enemy_bebop_stand_wait(a0);
		return;
	case 0x0506ECu:
		enemy_bebop_walk_to_front_start(a0, a1, p_d7, p_a5);
		return;
	case 0x050708u:
		enemy_bebop_walk_to_front_step(a0, a1, p_d7, p_a5);
		return;
	case 0x050784u:
		enemy_bebop_walk_level_step(a0, a1);
		return;
	case 0x050802u:
		enemy_bebop_walk_start(a0, a1, p_d7, p_a5);
		return;
	case 0x05081Eu:
		enemy_bebop_close_in_step(a0, a1, p_d7, p_a5);
		return;
	case 0x0508F0u:
		enemy_bebop_pincer_charge_start(a0);
		return;
	case 0x050952u:
		enemy_bebop_pincer_charge_run_to_edge(a0);
		return;
	case 0x050988u:
		enemy_bebop_pincer_charge_wait_for_rocksteady(a0);
		return;
	case 0x0509CEu:
		enemy_bebop_pincer_charge_get_ready(a0);
		return;
	case 0x0509D2u:
		*p_d7 = enemy_bebop_pincer_charge_run(*p_d7, a0);
		return;
	case 0x050AB8u:
		enemy_bebop_pincer_charge_crash(a0);
		return;
	case 0x050AF0u:
		*p_d7 = enemy_bebop_punch_start(*p_d7, a0);
		return;
	case 0x050B38u:
		enemy_bebop_punch_end(a0);
		return;
	case 0x050BA4u:
		*p_d7 = enemy_bebop_charge_start(*p_d7, a0);
		return;
	case 0x050BD2u:
		enemy_bebop_charge_get_ready(a0);
		return;
	case 0x050BFEu:
		enemy_bebop_charge_run(a0);
		return;
	case 0x050C82u:
		enemy_bebop_shoot_start(a0);
		return;
	case 0x050CAEu:
		enemy_bebop_shoot_fire(a0, p_d7, p_a5);
		return;
	case 0x050CFAu:
		enemy_bebop_flinch_start(a0);
		return;
	case 0x050D0Au:
		enemy_bebop_strike_back(a0);
		return;
	case 0x050D40u:
		enemy_bebop_flinch_from_behind_start(a0);
		return;
	case 0x050D56u:
		enemy_bebop_flinch_from_behind_end(a0);
		return;
	case 0x050DA4u:
		*p_d7 = enemy_bebop_knocked_down_start(*p_d7, a0, a1);
		return;
	case 0x050DCCu:
		*p_d7 = enemy_bebop_knocked_down_fall(*p_d7, a0);
		return;
	case 0x050E00u:
		enemy_bebop_knocked_down_slide(a0);
		return;
	case 0x050E2Eu:
		*p_d7 = enemy_bebop_knocked_down_lie(*p_d7, a0);
		return;
	case 0x050E8Eu:
		*p_d7 = enemy_bebop_defeated_start(*p_d7, a0, a1);
		return;
	case 0x050EC0u:
		*p_d7 = enemy_bebop_defeated_fall(*p_d7, a0);
		return;
	case 0x050F20u:
		enemy_bebop_defeated_slide(a0);
		return;
	case 0x050F4Eu:
		enemy_bebop_defeated_blink(a0);
		return;
	case 0x05103Au:
		enemy_mouser_enter_start(a0);
		return;
	case 0x05106Eu:
		enemy_mouser_enter_hop(a0);
		return;
	case 0x0510B2u:
		*p_d7 = enemy_mouser_enter_fall(*p_d7, a0);
		return;
	case 0x0510E4u:
		enemy_mouser_enter_land(a0);
		return;
	case 0x05135Cu:
		*p_d7 = enemy_mouser_bite_start(*p_d7, a0);
		return;
	case 0x0513A2u:
		*p_d7 = enemy_mouser_bite_fly(*p_d7, a0, a1);
		return;
	case 0x051404u:
		enemy_mouser_bite_land(a0);
		return;
	case 0x051414u:
		enemy_mouser_bite_hold(a0);
		return;
	case 0x0514EEu:
		enemy_mouser_hop_down(a0);
		return;
	case 0x05152Cu:
		*p_d7 = enemy_mouser_hop_fall(*p_d7, a0);
		return;
	case 0x05156Cu:
		enemy_mouser_hop_land(a0);
		return;
	case 0x051588u:
		enemy_mouser_hop_right(a0);
		return;
	case 0x0515D8u:
		enemy_mouser_hop_left(a0);
		return;
	case 0x051628u:
		enemy_mouser_hop_up(a0);
		return;
	case 0x051654u:
		*p_d7 = enemy_mouser_hop_up_fall(*p_d7, a0);
		return;
	case 0x0516A0u:
		enemy_mouser_hop_up_right(a0);
		return;
	case 0x0516D2u:
		*p_d7 = enemy_mouser_hop_up_fall_blocked(*p_d7, a0);
		return;
	case 0x05171Eu:
		enemy_mouser_hop_up_left(a0);
		return;
	case 0x051774u:
		enemy_mouser_chase_start((uint8_t)d0, a0, p_d7, p_a5);
		return;
	case 0x0517A0u:
		enemy_mouser_chase_run(a0, a1, p_d7, p_a5);
		return;
	case 0x051812u:
		*p_d7 = enemy_mouser_chase_pause(a0);
		return;
	case 0x05181Cu:
		enemy_mouser_chase_wait(a0);
		return;
	case 0x05183Eu:
		enemy_mouser_creep_to_side_start((uint8_t)d0, a0, p_d7, p_a5);
		return;
	case 0x05185Cu:
		enemy_mouser_creep_to_side_step(a0, a1, p_d7, p_a5);
		return;
	case 0x0518D4u:
		enemy_mouser_back_off_start(a0, a1, p_d7, p_a5);
		return;
	case 0x05190Eu:
		enemy_mouser_back_off_run((uint8_t)d0, a0, p_d7, p_a5);
		return;
	case 0x05192Cu:
		*p_d7 = enemy_mouser_sit(a0);
		return;
	case 0x05194Cu:
		enemy_mouser_back_off_wait(a0, a1);
		return;
	case 0x051980u:
		*p_d7 = enemy_mouser_thrown_off_start(*p_d7, a0);
		return;
	case 0x0519E4u:
		*p_d7 = enemy_mouser_break_down_start(*p_d7, a0);
		return;
	case 0x051A2Cu:
		*p_d7 = enemy_mouser_knocked_flying_start(*p_d7, a0, a1);
		return;
	case 0x051A6Cu:
		*p_d7 = enemy_mouser_fly_and_crash(*p_d7, a0);
		return;
	case 0x051AB0u:
		enemy_mouser_remove(a0, a1);
		return;
	case 0x051CC8u:
		*p_d7 = enemy_rodney_enter_wait(*p_d7, a0);
		return;
	case 0x051CFCu:
		enemy_rodney_enter_burst_out(a0);
		return;
	case 0x051D36u:
		enemy_rodney_enter_fall(a0);
		return;
	case 0x051D72u:
		enemy_rodney_enter_land(a0);
		return;
	case 0x05200Eu:
		enemy_rodney_rush_start(a0, a1, p_d7, p_a5);
		return;
	case 0x05207Au:
		*p_d7 = enemy_rodney_rush_run(a0);
		return;
	case 0x052116u:
		enemy_rodney_brake(a0);
		return;
	case 0x05214Eu:
		enemy_rodney_rush_across_start(a0);
		return;
	case 0x052188u:
		*p_d7 = enemy_rodney_rush_across_run(a0);
		return;
	case 0x052244u:
		*p_d7 = enemy_rodney_back_off_start(*p_d7, a0);
		return;
	case 0x052286u:
		enemy_rodney_slide_to_stop(a0, p_d5, p_d7);
		return;
	case 0x0522CCu:
		enemy_rodney_back_off_turn(a0);
		return;
	case 0x0522F0u:
		enemy_rodney_back_off_wait(a0, a1);
		return;
	case 0x052330u:
		*p_d7 = enemy_rodney_shoot_start(*p_d7, a0);
		return;
	case 0x052378u:
		enemy_rodney_shoot_turn(a0);
		return;
	case 0x0523A8u:
		*p_d7 = enemy_rodney_shoot_ready(*p_d7, a0);
		return;
	case 0x0523C6u:
		enemy_rodney_shoot_fire(a0, p_d7, p_a5);
		return;
	case 0x05240Eu:
		enemy_rodney_shoot_end(a0);
		return;
	case 0x052484u:
		*p_d7 = enemy_rodney_whip_start(*p_d7, a0);
		return;
	case 0x05248Cu:
		enemy_rodney_whip_slow_down(a0, p_d5, p_d7);
		return;
	case 0x052494u:
		*p_d7 = enemy_rodney_whip_wind_up(*p_d7, a0);
		return;
	case 0x0524D2u:
		enemy_rodney_whip_throw_arm(a0, p_d7, p_a5);
		return;
	case 0x052530u:
		*p_d7 = enemy_rodney_whip_reach(*p_d7, a0);
		return;
	case 0x0525D0u:
		*p_d7 = enemy_rodney_whip_lash(a0);
		return;
	case 0x0525E6u:
		enemy_rodney_whip_retract(a0);
		return;
	case 0x052624u:
		*p_d7 = enemy_rodney_knocked_back_start(*p_d7, a0, a1);
		return;
	case 0x05265Cu:
		*p_d7 = enemy_rodney_knocked_back_fall(*p_d7, a0);
		return;
	case 0x05268Au:
		enemy_rodney_knocked_back_end(a0);
		return;
	case 0x0526CCu:
		*p_d7 = enemy_rodney_destroyed_start(*p_d7, a0, a1);
		return;
	case 0x052704u:
		*p_d7 = enemy_rodney_destroyed_fall(*p_d7, a0);
		return;
	case 0x05273Cu:
		enemy_rodney_destroyed_land(a0);
		return;
	case 0x052756u:
		enemy_rodney_destroyed_end(a0, a1);
		return;
	case 0x052CAEu:
		*p_d7 = enemy_shredder_appear_wait(*p_d7, a0);
		return;
	case 0x052CDCu:
		*p_d7 = enemy_shredder_appear_step_out(*p_d7, a0);
		return;
	case 0x052D20u:
		*p_d7 = enemy_shredder_appear_walk_in(*p_d7, a0);
		return;
	case 0x052D62u:
		enemy_shredder_split_start(a0, p_d7, p_a5);
		return;
	case 0x052DB2u:
		enemy_shredder_split_blink(a0);
		return;
	case 0x052DE4u:
		enemy_shredder_clone_appear_start(a0);
		return;
	case 0x052E1Au:
		*p_d7 = enemy_shredder_clone_appear_blink(*p_d7, a0);
		return;
	case 0x052E84u:
		enemy_shredder_walk_to_side_start(a0, a1, p_d7, p_a5);
		return;
	case 0x052EAEu:
		enemy_shredder_walk_to_side_step(a0, a1, p_d7, p_a5);
		return;
	case 0x052F20u:
		enemy_shredder_walk_to_side_crouch(a0);
		return;
	case 0x052F52u:
		enemy_shredder_walk_to_side_turn(a0, a1, p_d7, p_a5);
		return;
	case 0x052F80u:
		enemy_shredder_walk_to_side_hold(a0, a1, p_d7, p_a5);
		return;
	case 0x052FECu:
		enemy_shredder_walk_to_target_start(a0, a1, p_d7, p_a5);
		return;
	case 0x053016u:
		enemy_shredder_walk_to_target_step(a0, a1, p_d7, p_a5);
		return;
	case 0x053084u:
		enemy_shredder_guard_start(a0);
		return;
	case 0x0530B0u:
		enemy_shredder_guard_counter(a0);
		return;
	case 0x053102u:
		enemy_shredder_back_off_start(a0, a1, p_d7, p_a5);
		return;
	case 0x05314Cu:
		enemy_shredder_back_off_walk(a0, a1, p_d7, p_a5);
		return;
	case 0x053198u:
		enemy_shredder_back_off_wait(a0, a1);
		return;
	case 0x0531C8u:
		enemy_shredder_lose_bar_start(a0);
		return;
	case 0x0531E4u:
		enemy_shredder_lose_bar_end(a0, p_d7, p_a5);
		return;
	case 0x053256u:
		enemy_shredder_flinch_start(a0);
		return;
	case 0x0532AAu:
		enemy_shredder_flinch_end(a0);
		return;
	case 0x0532E8u:
		enemy_shredder_flinch_from_behind_start(a0);
		return;
	case 0x053368u:
		*p_d7 = enemy_shredder_defeated_start(*p_d7, a0, a1);
		return;
	case 0x053398u:
		*p_d7 = enemy_shredder_defeated_fall(*p_d7, a0);
		return;
	case 0x0533D2u:
		*p_d7 = enemy_shredder_defeated_land(*p_d7, a0);
		return;
	case 0x053422u:
		enemy_shredder_defeated_wait(a0);
		return;
	case 0x05343Eu:
		enemy_shredder_defeated_stay();
		return;
	case 0x053458u:
		enemy_shredder_vanish_start(a0, a1);
		return;
	case 0x053482u:
		enemy_shredder_vanish_wait(a0);
		return;
	case 0x053496u:
		enemy_shredder_vanish_blink(a0);
		return;
	case 0x0534D8u:
		*p_d7 = enemy_shredder_kick_start(*p_d7, a0);
		return;
	case 0x05350Eu:
		enemy_shredder_blow_end(a0);
		return;
	case 0x053538u:
		*p_d7 = enemy_shredder_thrust_start(*p_d7, a0);
		return;
	case 0x053582u:
		*p_d7 = enemy_shredder_slash_start(*p_d7, a0);
		return;
	case 0x0535CCu:
		*p_d7 = enemy_shredder_sweep_start(*p_d7, a0);
		return;
	case 0x053628u:
		enemy_shredder_ray_start(a0, a1, p_d7, p_a5);
		return;
	case 0x053644u:
		enemy_shredder_ray_line_up(a0, a1, p_d7, p_a5);
		return;
	case 0x0536CAu:
		enemy_shredder_ray_charge(a0);
		return;
	case 0x0536EAu:
		enemy_shredder_ray_fire(a0, p_d7, p_a5);
		return;
	case 0x05373Au:
		enemy_shredder_ray_end(a0);
		return;
	}
}

void move_object_with_height(uint32_t a0)
{
	OBJECT(a0)->height += OBJECT(a0)->height_speed;
	move_object(a0);
}

void move_object(uint32_t a0)
{
	OBJECT(a0)->x += OBJECT(a0)->x_speed;
	OBJECT(a0)->y += OBJECT(a0)->y_speed;
}

void move_object_with_height_blocked(uint32_t a0)
{
	OBJECT(a0)->height += OBJECT(a0)->height_speed;
	move_object_blocked(a0);
}

void move_object_blocked(uint32_t a0)
{
	uint32_t d0 = 0;
	uint32_t x_speed = 0, y_speed = 0;

	x_speed = OBJECT(a0)->x_speed;
	d0 = x_speed;
	if ((int32_t)x_speed >= 0)
	{
		if ((OBJECT(a0)->contacts & 8u) == 0u)
			OBJECT(a0)->x += d0;
	}
	else if ((OBJECT(a0)->contacts & 0x10u) == 0u)
	{
		OBJECT(a0)->x += d0;
		y_speed = OBJECT(a0)->y_speed;
		d0 = y_speed;
		if ((int32_t)y_speed < 0)
		{
			if ((OBJECT(a0)->contacts & 4u) == 0u)
				OBJECT(a0)->y += d0;
			return;
		}
		if ((OBJECT(a0)->contacts & 2u) != 0u)
			return;
		OBJECT(a0)->y += d0;
		return;
	}
	y_speed = OBJECT(a0)->y_speed;
	d0 = y_speed;
	if ((int32_t)y_speed < 0)
	{
		if ((OBJECT(a0)->contacts & 4u) == 0u)
			OBJECT(a0)->y += d0;
		return;
	}
	if ((OBJECT(a0)->contacts & 2u) != 0u)
		return;
	OBJECT(a0)->y += d0;
}

void enemy_attack_chance(uint32_t a0, uint32_t *p_d3, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d3 = *p_d3;
	uint32_t d7 = *p_d7;
	uint32_t a6 = *p_a6;
	uint16_t target_dx = 0, target_dy = 0;
	uint32_t d3_2 = 0;
	uint16_t t1 = 0;

	target_dx = OBJECT(a0)->enemy.target_dx;
	if (target_dx >= 0x100u)
		d3_2 = 0xFFFFFFFFu;
	else
	{
		target_dy = OBJECT(a0)->enemy.target_dy;
		if (target_dy >= 0x100u)
			d3_2 = 0xFFFFFFFFu;
		else
		{
			d7 = 3u;
			for (;;)
			{
				if (mem_read8(a6) < (uint8_t)target_dy)
				{
					d3_2 = 0xFFFFFFFFu;
					break;
				}
				if ((uint8_t)target_dx < mem_read8(a6 + 1u) || mem_read8(a6 + 2u) < (uint8_t)target_dx)
				{
					t1 = d7 - 1u;
					d7 = t1;
					a6 += 0xCu;
					if (t1 != 0xFFFFu)
						continue;
					d3_2 = 0xFFFFFFFFu;
					break;
				}
				d3_2 = (d3 & ~0xFFu) | mem_read8(a6 + 3u);
				break;
			}
		}
	}
	*p_d3 = d3_2;
	*p_d7 = d7;
	*p_a6 = a6;
}

void enemy_look_at_target(uint32_t a0, uint32_t turtle, uint32_t *p_d1, uint32_t *p_d2)
{
	uint8_t d0 = 0, d3 = 0;
	uint16_t d1 = 0, d2 = 0, screen_y = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	screen_y = OBJECT(turtle)->screen_y;
	d0 = 0u;
	t1 = OBJECT(turtle)->screen_x - OBJECT(a0)->screen_x;
	d1 = t1;
	if ((int16_t)t1 < 0)
	{
		d1 = (uint16_t)(0u - d1);
		d0 = 0x40u;
	}
	d3 = OBJECT(turtle)->flags ^ d0;
	t2 = screen_y - OBJECT(a0)->screen_y;
	d2 = t2;
	if ((int16_t)t2 >= 0)
		d0 ^= 0xC0u;
	else
		d2 = (uint16_t)(0u - d2);
	if ((d0 & 0x40u) != 0u)
	{
		if (d2 <= d1)
			d0 |= 0x20u;
	}
	else if (d1 <= d2)
		d0 |= 0x20u;
	OBJECT(a0)->enemy.target_direction = d0;
	OBJECT(a0)->enemy.target_dx = d1;
	OBJECT(a0)->enemy.target_dy = d2;
	t3 = (uint32_t)d3 << 1;
	d3 = t3;
	if ((int8_t)t3 >= 0 && d2 < 6u && d1 < 0x40u)
		OBJECT(turtle)->turtle.enemy_behind = 0xFFu;
	OBJECT(a0)->enemy.target_faces = d3;
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_d2 = (*p_d2 & 0xFFFF0000u) | d2;
}

void enemy_nearest_turtles(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5, uint32_t *p_a6)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t a5 = *p_a5;
	uint32_t a6 = *p_a6;
	uint16_t d0 = 0, d1 = 0;
	uint32_t d6 = 0, object = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;
	uint32_t t3 = 0;

	if (turtles_in_play == 0u)
	{
		a6 = nearest_turtle;
		a5 = second_nearest_turtle;
	}
	else
	{
		d7 = 3u;
		object = OBJECT_ADDRESS(0);
		d5 = 0xFFFFFFFFu;
		d6 = 0xFFFFFFFFu;
		do
		{
			if (OBJECT(object)->flags != 0u)
			{
				t1 = OBJECT(a0)->screen_x - OBJECT(object)->screen_x;
				d0 = t1;
				if ((int16_t)t1 < 0)
					d0 = (uint16_t)(0u - d0);
				t2 = OBJECT(a0)->screen_y - OBJECT(object)->screen_y;
				d1 = t2;
				if ((int16_t)t2 < 0)
					d1 = (uint16_t)(0u - d1);
				d0 += d1;
				if ((uint16_t)d6 <= d0)
				{
					if (d0 < (uint16_t)d5)
					{
						d5 = (d5 & ~0xFFFFu) | d0;
						a5 = object;
					}
				}
				else
				{
					t3 = d6;
					d6 = d5;
					d5 = t3;
					a5 = a6;
					d6 = (d6 & ~0xFFFFu) | d0;
					a6 = object;
				}
			}
			t4 = d7 - 1u;
			d7 = t4;
			object += 0x50u;
		} while (t4 != 0xFFFFu);
		nearest_turtle = a6;
		second_nearest_turtle = a5;
	}
	*p_d5 = d5;
	*p_d7 = d7;
	*p_a5 = a5;
	*p_a6 = a6;
}

void enemy_nearest_slots(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5, uint32_t *p_a6)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint32_t a5 = *p_a5;
	uint32_t a6 = *p_a6;
	uint16_t d0 = 0, d1 = 0;
	uint32_t d6 = 0, object = 0, player_slot = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;
	uint32_t t3 = 0;

	if (turtles_in_play == 0u)
	{
		a6 = nearest_slot;
		a5 = second_nearest_slot;
	}
	else
	{
		d7 = 3u;
		player_slot = PLAYER_SLOT_ADDRESS(0);
		d5 = 0xFFFFFFFFu;
		d6 = 0xFFFFFFFFu;
		do
		{
			object = PLAYER_SLOT(player_slot)->turtle;
			if (OBJECT(object)->flags != 0u)
			{
				t1 = OBJECT(a0)->screen_x - OBJECT(object)->screen_x;
				d0 = t1;
				if ((int16_t)t1 < 0)
					d0 = (uint16_t)(0u - d0);
				t2 = OBJECT(a0)->screen_y - OBJECT(object)->screen_y;
				d1 = t2;
				if ((int16_t)t2 < 0)
					d1 = (uint16_t)(0u - d1);
				d0 += d1;
				if ((uint16_t)d6 <= d0)
				{
					if (d0 < (uint16_t)d5)
					{
						d5 = (d5 & ~0xFFFFu) | d0;
						a5 = player_slot;
					}
				}
				else
				{
					t3 = d6;
					d6 = d5;
					d5 = t3;
					a5 = a6;
					d6 = (d6 & ~0xFFFFu) | d0;
					a6 = player_slot;
				}
			}
			t4 = d7 - 1u;
			d7 = t4;
			player_slot += 0x10u;
		} while (t4 != 0xFFFFu);
		nearest_slot = a6;
		second_nearest_slot = a5;
	}
	*p_d5 = d5;
	*p_d7 = d7;
	*p_a5 = a5;
	*p_a6 = a6;
}

uint32_t random_below(uint16_t d7, uint32_t a0)
{
	uint16_t d6 = 0;
	uint32_t d7_2 = 0;

	d6 = (uint16_t)d7;
	d7_2 = (uint16_t)(random_seed + frame_count - (uint16_t)OBJECT(a0)->x + OBJECT(a0)->screen_y - (uint16_t)OBJECT(a0)->y + OBJECT(a0)->screen_x + 0x4ACBu) * 0x17u;
	random_seed = d7_2;
	d7_2 = ((uint32_t)(uint16_t)d7_2 * d6) & ~0xFFFFu;
	d7_2 = (d7_2 << 16) | (d7_2 >> 16);
	return d7_2;
}

void unreached_048480(uint32_t a0, uint32_t a5)
{
	uint16_t d1 = 0, d2 = 0;

	d1 = mem_read16(a0 + 0x2Cu);
	d2 = mem_read16(a0 + 0x2Eu);
	if (d1 <= d2)
		d1 = (uint16_t)d2;
}

void enemy_face_object(uint8_t d0, uint32_t a0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;

	d7 = enemy_facing_bits(d0, d7, a0, a6);
	*p_a5 = enemy_set_facing_animation((uint8_t)d7, a0, *p_a5);
	*p_d7 = d7;
}

uint32_t enemy_set_facing_animation(uint8_t d7, uint32_t a0, uint32_t a5)
{
	uint32_t animation = 0;

	if ((int8_t)d7 < 0)
		a5 += 4u;
	animation = mem_read32(a5);
	set_animation(0u, a0, animation);
	OBJECT(a0)->flags &= 0xBFu;
	if ((d7 & 0x40u) != 0u)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->enemy.facing = d7;
	return a5;
}

void enemy_turn_to_object(uint8_t d0, uint32_t a0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;

	d7 = enemy_facing_bits(d0, d7, a0, a6);
	*p_a5 = enemy_turn_animation((uint8_t)d7, a0, *p_a5);
	*p_d7 = d7;
}

uint32_t enemy_turn_animation(uint8_t d7, uint32_t a0, uint32_t a5)
{
	uint32_t animation = 0;
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->enemy.facing ^ d7;
	OBJECT(a0)->enemy.facing = t1;
	if ((int8_t)t1 >= 0)
	{
		if ((OBJECT(a0)->enemy.facing & 0x40u) != 0u)
			OBJECT(a0)->flags ^= 0x40u;
		OBJECT(a0)->enemy.facing = d7;
		return a5;
	}
	if ((int8_t)d7 < 0)
		a5 += 4u;
	animation = mem_read32(a5);
	set_animation(0u, a0, animation);
	if ((OBJECT(a0)->enemy.facing & 0x40u) != 0u)
		OBJECT(a0)->flags ^= 0x40u;
	OBJECT(a0)->enemy.facing = d7;
	return a5;
}

uint32_t enemy_facing_bits(uint8_t d0, uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint16_t d6 = 0;
	uint16_t t1 = 0;

	d7 &= ~0xFFFFu;
	t1 = mem_read16(a6 + 0xEu) - OBJECT(a0)->screen_y;
	d6 = t1;
	if ((int16_t)t1 >= 0 && d6 >= 4u)
		d7 |= 0x80u;
	if ((int8_t)(d0 - 0x40u) < 0)
		d7 |= 0x40u;
	return d7;
}

void enemy_face_direction(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;

	d7 = direction_facing_bits(d0, d7);
	*p_a5 = enemy_set_facing_animation((uint8_t)d7, a0, *p_a5);
	*p_d7 = d7;
}

void enemy_turn_to_direction(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;

	d7 = direction_facing_bits(d0, d7);
	*p_a5 = enemy_turn_animation((uint8_t)d7, a0, *p_a5);
	*p_d7 = d7;
}

uint32_t direction_facing_bits(uint8_t d0, uint32_t d7)
{
	d7 &= ~0xFFu;
	if ((uint8_t)d0 >= 0x84u && (uint8_t)d0 < 0xFDu)
		d7 |= 0x80u;
	if ((int8_t)(d0 - 0x40u) < 0)
		d7 |= 0x40u;
	return d7;
}

void enemy_keep_on_screen(uint32_t a0)
{
	if (OBJECT(a0)->screen_x >= 0x170u)
		OBJECT(a0)->contacts |= 8u;
	if (OBJECT(a0)->screen_x < 0x80u)
		OBJECT(a0)->contacts |= 0x10u;
}

void enemy_on_screen(uint32_t a0, uint32_t *p_d7, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;

	if (OBJECT(a0)->screen_x >= 0x190u || OBJECT(a0)->screen_x < 0x70u)
	{
		zero = 0xFFFFFFFFu == 0u;
		*p_d7 = 0xFFFFFFFFu;
	}
	else
	{
		zero = 1u;
		*p_d7 &= ~0xFFu;
	}
	*p_zero = zero;
}

uint32_t enemy_set_health(uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;
	uint32_t health_bars_halfword = 0;

	d7_2 = (d7 & ~0xFFu) | difficulty;
	d7_2 = d7_2 & ~0xFFF8u;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 1);
	health_bars_halfword = mem_read16(a6 + (uint16_t)d7_2);
	OBJECT(a0)->health_bars = (uint8_t)(health_bars_halfword >> 8u);
	OBJECT(a0)->health = (uint8_t)health_bars_halfword;
	return d7_2;
}

uint32_t enemy_refill_health(uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | difficulty;
	d7_2 = d7_2 & ~0xFFF8u;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 1);
	OBJECT(a0)->health = mem_read8(a6 + 1u + (uint16_t)d7_2);
	return d7_2;
}

uint32_t enemy_face_target(uint32_t d7, uint32_t a0)
{
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy.target_direction - 0x40u) < 0)
	{
		OBJECT(a0)->flags |= 0x40u;
		d7 = d7 | 0x80u;
	}
	OBJECT(a0)->attack = d7;
	return d7;
}

void enemy_back_to_thinking(uint32_t a0)
{
	OBJECT(a0)->flags &= ~4u;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->enemy.move_time = 0u;
}

void enemy_back_to_thinking_hittable(uint32_t a0)
{
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->enemy.move_time = 0u;
}

void enemy_landed(uint32_t a0, uint32_t *p_d7, uint32_t *p_zero)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = *p_zero;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | OBJECT(a0)->height_whole;
	if ((uint8_t)d7_2 >= 0xF0u || (uint8_t)d7_2 < OBJECT(a0)->floor_height)
	{
		OBJECT(a0)->height_whole = OBJECT(a0)->floor_height;
		zero = 1u;
		OBJECT(a0)->height &= 0xFF00u;
	}
	else
	{
		zero = 0xFFFFFFFFu == 0u;
		d7_2 = 0xFFFFFFFFu;
	}
	*p_d7 = d7_2;
	*p_zero = zero;
}

uint32_t enemy_start_arc(uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;
	uint32_t t1 = 0;

	OBJECT(a0)->x_speed = mem_read16(a6);
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = mem_read16(a6 + 4u);
	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a6 + 8u);
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(0u - d7_2);
	}
	if (area == 7u && OBJECT(a0)->floor_height != 0u)
		return d7_2;
	t1 = (int16_t)d7_2;
	d7_2 = t1;
	if ((int32_t)t1 >= 0)
	{
		if ((OBJECT(a0)->contacts & 8u) == 0u)
			OBJECT(a0)->x += d7_2;
		return d7_2;
	}
	if ((OBJECT(a0)->contacts & 0x10u) != 0u)
		return d7_2;
	OBJECT(a0)->x += d7_2;
	return d7_2;
}

void enemy_arc_step(uint32_t a0, uint32_t a6)
{
	uint16_t d0 = 0, d1 = 0;

	d0 = mem_read16(a6 + 2u);
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		d0 = (uint16_t)(0u - d0);
	d1 = (uint16_t)d0;
	d0 += OBJECT(a0)->x_speed;
	if ((int16_t)(d1 ^ d0) < 0)
		OBJECT(a0)->x_speed = d0;
	d0 = (uint16_t)(mem_read16(a6 + 6u) + OBJECT(a0)->height_speed);
	if ((int16_t)mem_read16(a6 + 0xAu) <= (int16_t)d0)
		OBJECT(a0)->height_speed = d0;
}

void enemy_leave_side(uint32_t a0, uint32_t a1)
{
	if (OBJECT(a0)->enemy.approach != 1u)
		return;
	enemy_give_side_back(a0, a1);
}

void enemy_give_side_back(uint32_t a0, uint32_t a1)
{
	uint8_t d0 = 0;
	uint8_t side = 0;

	d0 = 0x7Fu;
	side = OBJECT(a0)->enemy.side;
	OBJECT(a0)->enemy.side = side & 0x7Fu;
	if ((side & 0x80u) != 0u)
		d0 = 0xBFu;
	PLAYER_SLOT(a1)->sides &= d0;
	OBJECT(a0)->enemy.approach = 0u;
	OBJECT(a0)->enemy.move_time = 0u;
}

void enemy_face_target_animation(uint32_t a0, uint32_t a6, uint32_t *p_d0, uint32_t *p_d7)
{
	uint16_t d7 = 0, target_direction = 0;
	uint32_t animation = 0;

	target_direction = OBJECT(a0)->enemy.target_direction;
	OBJECT(a0)->enemy.facing = (uint8_t)target_direction;
	d7 = target_direction >> 3;
	animation = mem_read32(a6 + d7);
	set_animation(0u, a0, animation);
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	*p_d0 = (*p_d0 & 0xFFFF0000u) | target_direction;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
}

void enemy_flash_when_weak(uint8_t d7, uint32_t a0)
{
	if (OBJECT(a0)->health_bars <= 6u)
	{
		OBJECT(a0)->colour = d7;
		if ((frame_count & 4u) != 0u)
			OBJECT(a0)->colour = 0xFFu;
	}
}

void enemy_set_floor(uint32_t a0)
{
	if (area != 3u || OBJECT(a0)->y < 0x5800u)
	{
		OBJECT(a0)->floor_height = 0u;
		return;
	}
	OBJECT(a0)->floor_height = 0x18u;
}

void enemy_floor_contacts(uint32_t a0, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_d3, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t a6 = 0;

	if ((OBJECT(a0)->flags & 0x20u) != 0u || (int16_t)OBJECT(a0)->screen_y < 8)
	{
		*p_d0 = 1u;
		*p_d1 = 1u;
		*p_d2 = 1u;
		*p_d3 = 1u;
	}
	else
	{
		read_floor_cells_on_screen(a0, &d5, p_a5, &a6);
		enemy_floor_cell_place = a6;
		if (floor_cell >= 0xFDu)
		{
			enemy_floor_edges(a0, p_d0, p_d1, p_d2, p_d3, p_d7);
			*p_a5 = 0x4881Bu;
			OBJECT(a0)->contacts &= mem_read8(0x4881Bu + (int16_t)(int8_t)floor_cell);
		}
		else
			enemy_floor_edges(a0, p_d0, p_d1, p_d2, p_d3, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
}

void enemy_floor_edges(uint32_t a0, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_d3, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint8_t d0 = 0, d1 = 0, d2 = 0, d3 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	d7 &= ~0xFFu;
	t1 = floor_cell_right;
	d0 = t1;
	if ((int8_t)t1 < 0 && d0 == height_cell_right)
		d7 = 8u;
	t2 = floor_cell_left;
	d1 = t2;
	if ((int8_t)t2 < 0 && d1 == height_cell_left)
		d7 |= 0x10u;
	t3 = floor_cell_up;
	d2 = t3;
	if ((int8_t)t3 < 0 && d2 == height_cell_up)
		d7 |= 2u;
	t4 = floor_cell_down;
	d3 = t4;
	if ((int8_t)t4 < 0)
		d7 |= 4u;
	OBJECT(a0)->contacts |= d7;
	*p_d0 = (*p_d0 & 0xFFFFFF00u) | d0;
	*p_d1 = (*p_d1 & 0xFFFFFF00u) | d1;
	*p_d2 = (*p_d2 & 0xFFFFFF00u) | d2;
	*p_d3 = (*p_d3 & 0xFFFFFF00u) | d3;
	*p_d7 = d7;
}

void enemy_check_floor_edge(uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_zero)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = *p_zero;
	uint16_t d7_2 = 0;
	uint32_t a6 = 0;

	d7_2 = (uint16_t)((d7 & ~0xFFu) | OBJECT(a0)->floor_height);
	if ((uint8_t)d7_2 != OBJECT(a0)->height_whole)
	{
		if (area == 3u)
		{
			if ((uint8_t)(OBJECT(a0)->y >> 8u) >= 0x4Bu)
			{
				OBJECT(a0)->height = 0x1800u;
				OBJECT(a0)->floor_height = 0x18u;
			}
			else
			{
				OBJECT(a0)->height = 0u;
				OBJECT(a0)->floor_height = 0u;
			}
		}
		zero = 1u;
		d7_2 = 0u;
	}
	else if ((OBJECT(a0)->contacts & 1u) == 0u)
	{
		a6 = mem_read32(a1);
		if ((uint8_t)d7_2 == mem_read8(a6 + 0x32u))
		{
			zero = 1u;
			d7_2 = 0u;
		}
		else if (mem_read8(a6 + 0x32u) <= (uint8_t)d7_2)
		{
			if ((uint8_t)d3 != 0xFCu)
			{
				if ((uint8_t)d0 != 0xFAu)
				{
					if ((uint8_t)d1 != 0xFBu)
					{
						zero = 1u;
						d7_2 = 0u;
					}
					else
					{
						OBJECT(a0)->enemy.move = 0x14u;
						zero = 0x600u == 0u;
						OBJECT(a0)->routine = 6u;
						OBJECT(a0)->state = 0u;
					}
				}
				else
				{
					OBJECT(a0)->enemy.move = 0x10u;
					zero = 0x600u == 0u;
					OBJECT(a0)->routine = 6u;
					OBJECT(a0)->state = 0u;
				}
			}
			else
			{
				OBJECT(a0)->enemy.move = 0xCu;
				zero = 0x600u == 0u;
				OBJECT(a0)->routine = 6u;
				OBJECT(a0)->state = 0u;
			}
		}
		else if ((uint8_t)d0 != 0xFBu)
		{
			if ((uint8_t)d1 != 0xFAu)
			{
				if ((uint8_t)d2 != 0xFCu)
				{
					zero = 1u;
					d7_2 = 0u;
				}
				else
				{
					OBJECT(a0)->enemy.move = 0u;
					zero = 0x600u == 0u;
					OBJECT(a0)->routine = 6u;
					OBJECT(a0)->state = 0u;
				}
			}
			else
			{
				OBJECT(a0)->enemy.move = 8u;
				zero = 0x600u == 0u;
				OBJECT(a0)->routine = 6u;
				OBJECT(a0)->state = 0u;
			}
		}
		else
		{
			OBJECT(a0)->enemy.move = 4u;
			zero = 0x600u == 0u;
			OBJECT(a0)->routine = 6u;
			OBJECT(a0)->state = 0u;
		}
	}
	else
	{
		OBJECT(a0)->enemy.move = 0x18u;
		zero = 0x600u == 0u;
		OBJECT(a0)->routine = 6u;
		OBJECT(a0)->state = 0u;
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_2;
	*p_zero = zero;
}

void enemy_follow_stairs(uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	a6 = enemy_floor_cell_place;
	d0 = floor_cell;
	if (d0 < 0xFAu || d0 >= 0xFCu)
		return;
	if (d0 == floor_cell_up)
	{
		enemy_stairs_up(a0, a6);
		return;
	}
	enemy_stairs_down(a0, a6);
}

void enemy_follow_stairs_down(uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	a6 = enemy_floor_cell_place;
	d0 = floor_cell;
	if (d0 < 0xFAu || d0 >= 0xFDu)
		return;
	enemy_stairs_down(a0, a6);
}

void enemy_stairs_down(uint32_t a0, uint32_t a6)
{
	uint8_t floor_height = 0;

	do
	{
		floor_height = OBJECT(a0)->floor_height;
		OBJECT(a0)->floor_height = floor_height - 8u;
		if (floor_height < 8u)
			OBJECT(a0)->floor_height = 0u;
		a6 += 0x40u;
		if (a6 >= OBJECT_ADDRESS(0))
			a6 -= 0x800u;
	} while ((int8_t)mem_read8(a6) < 0);
}

void enemy_follow_stairs_up(uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	a6 = enemy_floor_cell_place;
	d0 = floor_cell;
	if (d0 < 0xFAu || d0 >= 0xFDu)
		return;
	enemy_stairs_up(a0, a6);
}

void enemy_stairs_up(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0;

	do
	{
		OBJECT(a0)->floor_height += 8u;
		d0 = stairs_top_height;
		if (d0 < OBJECT(a0)->floor_height)
			OBJECT(a0)->floor_height = d0;
		a6 -= 0x40u;
		if (a6 < floor_map_ADDRESS)
			a6 += 0x800u;
	} while ((int8_t)mem_read8(a6) < 0);
}

void enemy_foot_soldier_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	enemy_set_floor(a0);
	enemies_on_screen++;
	enemy_foot_soldier_setup(a0, a6, p_d5, p_d7, p_a5);
}

void enemy_foot_soldier_setup(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t animation = 0;
	uint8_t parameter = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy.target = a6;
	OBJECT(a0)->enemy.retarget_time = 0x10u;
	OBJECT(a0)->enemy.move_time = 0u;
	OBJECT(a0)->enemy.approach = 0u;
	OBJECT(a0)->enemy.dodge_chance = 5u;
	OBJECT(a0)->depth = 4u;
	OBJECT(a0)->throw = 0x84u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->health_bars = 3u;
	OBJECT(a0)->health = 6u;
	OBJECT(a0)->enemy.definition = enemy_definitions_ADDRESS;
	parameter = OBJECT(a0)->parameter;
	d0 = parameter;
	if (parameter != 0u)
	{
		OBJECT(a0)->enemy.move = (uint32_t)d0 << 2;
		OBJECT(a0)->routine++;
		return;
	}
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->routine += 2u;
	animation = animations_0547C6_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_enter(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, slot = 0, turtle = 0;

	slot = 0x60000u | OBJECT(a0)->enemy.target;
	turtle = PLAYER_SLOT(slot)->turtle;
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	enemy_collide_with_objects(a0, p_d5, p_d7, p_a5);
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	a6 = mem_read32(0x53ED6u + (int16_t)OBJECT(a0)->enemy.move);
	run_object_state(a0, slot, a6, p_d5, p_d7, p_a5);
	*p_a1 = slot;
}

void enemy_think(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	bool L_048BCA = false, L_048CC0 = false;
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint16_t d6 = 0;
	uint32_t a6_2 = 0, d0_2 = 0, d1 = 0, d2 = 0, d3 = 0, ignored = 0, ignored_2 = 0, turtle = 0;
	uint8_t retarget_time = 0, t3 = 0, floor_height = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t10 = 0;
	uint16_t t8 = 0, t11 = 0;
	uint32_t t1 = 0, t2 = 0;

	*p_a1 = 0x60000u | OBJECT(a0)->enemy.target;
	retarget_time = OBJECT(a0)->enemy.retarget_time;
	OBJECT(a0)->enemy.retarget_time = retarget_time - 1u;
	if (retarget_time == 1u)
	{
		OBJECT(a0)->enemy.retarget_time = 0x10u;
		if (turtles_in_play != 0u)
		{
			PLAYER_SLOT(*p_a1)->enemies--;
			enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
			d0 = enemies_per_turtle;
			if (d0 <= PLAYER_SLOT(a6)->enemies)
			{
				t1 = *p_a5;
				*p_a5 = a6;
				a6 = t1;
				if (d0 <= mem_read8(a6 + 4u))
				{
					a6 = least_crowded_slot;
					if (d0 <= PLAYER_SLOT(a6)->enemies)
					{
						t2 = *p_a5;
						*p_a5 = a6;
						a6 = t2;
					}
				}
			}
			*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)a6;
			if ((uint16_t)*p_d7 != OBJECT(a0)->enemy.target)
				enemy_leave_side(a0, *p_a1);
			OBJECT(a0)->enemy.target = a6;
			*p_a1 = a6;
			mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
		}
	}
	if (boss_defeated != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t3 = enemies_on_screen - 1u;
		enemies_on_screen = t3;
		if ((int8_t)t3 < 0)
			enemies_on_screen = 0u;
		return;
	}
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		enemy_leave_side(a0, *p_a1);
		mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t3 = enemies_on_screen - 1u;
		enemies_on_screen = t3;
		if ((int8_t)t3 < 0)
			enemies_on_screen = 0u;
		return;
	}
	floor_height = OBJECT(a0)->floor_height;
	*p_d7 = (*p_d7 & ~0xFFFFu) | floor_height;
	if (floor_height != 0u)
	{
		*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)(*p_d7 + OBJECT(a0)->screen_y);
		if ((int16_t)*p_d7 >= 0xF0)
		{
			enemy_leave_side(a0, *p_a1);
			mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
			OBJECT(a0)->flags = 0u;
			OBJECT(a0)->contacts = 0u;
			t3 = enemies_on_screen - 1u;
			enemies_on_screen = t3;
			if ((int8_t)t3 < 0)
				enemies_on_screen = 0u;
			return;
		}
	}
	turtle = mem_read32(*p_a1);
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	enemy_collide_with_objects(a0, p_d5, p_d7, p_a5);
	enemy_floor_contacts(a0, &d0_2, &d1, &d2, &d3, p_d5, p_d7, p_a5);
	enemy_check_floor_edge((uint8_t)d0_2, (uint8_t)d1, (uint8_t)d2, (uint8_t)d3, a0, *p_a1, p_d7, &zero);
	if (zero == 0u)
	{
		return;
	}
	if (OBJECT(a0)->enemy.approach != 0u)
	{
		if (OBJECT(a0)->enemy.approach != 1u)
		{
			if (OBJECT(a0)->enemy.approach == 2u && mem_read8(*p_a1 + 5u) < 0xC0u)
			{
				OBJECT(a0)->enemy.approach = 0u;
				OBJECT(a0)->enemy.move_time = 0u;
			}
		}
		else if (OBJECT(a0)->enemy.target_dx >= 0x50u || OBJECT(a0)->enemy.target_dy >= 0x50u)
			enemy_give_side_back(a0, *p_a1);
	}
	else if (mem_read8(*p_a1 + 5u) < 0xC0u)
	{
		if (OBJECT(a0)->enemy.target_dx < 0x40u && OBJECT(a0)->enemy.target_dy < 0x40u)
		{
			OBJECT(a0)->enemy.approach = 1u;
			OBJECT(a0)->enemy.move_time = 0u;
			do
			{
				if (L_048BCA || (int8_t)(OBJECT(a0)->enemy.target_direction - 0x40u) < 0)
				{
					for (;;)
					{
						L_048BCA = false;
						t4 = mem_read8(*p_a1 + 5u);
						mem_write8(*p_a1 + 5u, t4 | 0x40u);
						if ((t4 & 0x40u) != 0u)
						{
							t5 = mem_read8(*p_a1 + 5u);
							mem_write8(*p_a1 + 5u, t5 | 0x80u);
							if ((t5 & 0x80u) != 0u)
								continue;
							OBJECT(a0)->enemy.side &= 0x7Fu;
							break;
						}
						OBJECT(a0)->enemy.side |= 0x80u;
						break;
					}
				}
				else
				{
					t5 = mem_read8(*p_a1 + 5u);
					mem_write8(*p_a1 + 5u, t5 | 0x80u);
					L_048BCA = (t5 & 0x80u) != 0u;
					if (!L_048BCA)
						OBJECT(a0)->enemy.side &= 0x7Fu;
				}
			} while (L_048BCA);
		}
	}
	else
	{
		OBJECT(a0)->enemy.approach = 2u;
		OBJECT(a0)->enemy.move_time = 0u;
	}
	if (OBJECT(a0)->enemy.approach != 1u)
		L_048CC0 = true;
	else
	{
		a6_2 = mem_read32(*p_a1);
		if (mem_read8(a6_2 + 4u) != 4u || indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] != 0u)
		{
			L_048CC0 = mem_read8(mem_read32(*p_a1) + 4u) != 3u || OBJECT(a0)->enemy.target_dy >= 8u || (int8_t)OBJECT(a0)->enemy.target_faces >= 0;
			if (!L_048CC0)
			{
				*p_d7 = 0x64u;
				*p_d7 = random_below((uint16_t)*p_d7, a0);
				L_048CC0 = OBJECT(a0)->enemy.dodge_chance <= (uint8_t)*p_d7;
				if (!L_048CC0)
				{
					enemy_give_side_back(a0, *p_a1);
					OBJECT(a0)->enemy.approach = 4u;
					OBJECT(a0)->enemy.move_time = 0u;
				}
			}
		}
		else
		{
			enemy_give_side_back(a0, *p_a1);
			OBJECT(a0)->enemy.approach = 3u;
			OBJECT(a0)->enemy.move_time = 0u;
		}
	}
	if (L_048CC0)
	{
		enemy_on_screen(a0, p_d7, &zero);
		if (zero)
		{
			a6_2 = mem_read32(*p_a1);
			if (mem_read8(a6_2 + 4u) != 4u || (int8_t)indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] < 0)
			{
				a6_2 = OBJECT(a0)->enemy.definition + 0x28u;
				enemy_attack_chance(a0, &d3, p_d7, &a6_2);
				if ((int8_t)d3 >= 0)
				{
					*p_d7 = 0x64u;
					*p_d7 = random_below((uint16_t)*p_d7, a0);
					if ((uint8_t)*p_d7 < (uint8_t)d3)
					{
						*p_d7 = 0x64u;
						*p_d7 = random_below((uint16_t)*p_d7, a0);
						d6 = 3u;
						do
						{
							t6 = mem_read8(a6_2 + 8u + (int16_t)d6);
							t7 = *p_d7;
							*p_d7 = (*p_d7 & ~0xFFu) | (uint8_t)(t7 - t6);
							if (t7 < t6)
							{
								OBJECT(a0)->enemy.move = ((d6 & ~0xFFu) | mem_read8(a6_2 + 4u + (int16_t)d6)) << 2;
								OBJECT(a0)->routine = 3u;
								OBJECT(a0)->state = 0u;
								OBJECT(a0)->flags &= ~8u;
								return;
							}
							t8 = d6 - 1u;
							d6 = t8;
						} while (t8 != 0xFFFFu);
					}
				}
			}
		}
	}
	if (OBJECT(a0)->enemy.move_time == 0u)
	{
		a6_2 = OBJECT(a0)->enemy.definition + (uint16_t)((uint32_t)OBJECT(a0)->enemy.approach << 3);
		*p_d7 = 0x64u;
		*p_d7 = random_below((uint16_t)*p_d7, a0);
		d6 = 3u;
		for (;;)
		{
			t9 = mem_read8(a6_2 + 4u + (int16_t)d6);
			t10 = *p_d7;
			*p_d7 = (*p_d7 & ~0xFFu) | (uint8_t)(t10 - t9);
			if (t10 < t9)
				break;
			t11 = d6 - 1u;
			d6 = t11;
			if (t11 == 0xFFFFu)
			{
				d6 = 0u;
				break;
			}
		}
		OBJECT(a0)->enemy.move = ((d6 & ~0xFFu) | mem_read8(a6_2 + (int16_t)d6)) << 2;
		OBJECT(a0)->state = 0u;
	}
	switch ((uint32_t)(int16_t)OBJECT(a0)->enemy.move)
	{
	case 20:
		enemy_shuffle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 28:
		enemy_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 36:
		enemy_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0:
		enemy_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 4:
		enemy_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 8:
		enemy_keep_distance(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 12:
		enemy_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 16:
		enemy_run_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 44:
		enemy_walk_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 48:
		enemy_walk_to_target_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 52:
		enemy_walk_to_side_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 24:
		enemy_walk_past_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 32:
		enemy_back_off_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 40:
		enemy_walk_to_line_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 56:
		enemy_walk_to_target_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 60:
		enemy_walk_to_side_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 68:
		enemy_stalk_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 64:
		enemy_walk_away_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 72:
		enemy_walk_to_target_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 76:
		enemy_walk_to_side_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 104:
		enemy_walk_off_line_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 108:
		enemy_back_off_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 112:
		enemy_step_aside_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 80:
		enemy_walk_to_target_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 84:
		enemy_walk_to_side_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 116:
		enemy_circle_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 124:
		enemy_keep_distance_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 120:
		enemy_back_off_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 128:
		enemy_step_aside_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 88:
		enemy_walk_to_target_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 92:
		enemy_walk_to_side_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 152:
		enemy_walk_to_range_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 140:
		enemy_back_off_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 144:
		enemy_run_away_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 96:
		enemy_walk_to_target_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 100:
		enemy_walk_to_side_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 148:
		enemy_walk_to_range_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 132:
		enemy_back_off_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 136:
		enemy_run_away_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 196:
		enemy_rocksteady_raise_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 200:
		enemy_rocksteady_laugh(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 192:
		enemy_rocksteady_shake_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 184:
		enemy_rocksteady_draw_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 188:
		enemy_rocksteady_put_gun_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 204:
		enemy_rocksteady_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 208:
		enemy_rocksteady_line_up(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 212:
		enemy_rocksteady_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 232:
		enemy_rocksteady_shoot_around(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 228:
		enemy_bebop_stand(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 216:
		enemy_bebop_walk_to_front(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 224:
		enemy_bebop_walk_level(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 220:
		enemy_bebop_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 156:
		enemy_mouser_chase(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 164:
		enemy_mouser_creep_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 160:
		enemy_mouser_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 172:
		enemy_rodney_rush(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 176:
		enemy_rodney_rush_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 180:
		enemy_rodney_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 236:
		enemy_shredder_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 240:
		enemy_shredder_split(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 168:
		enemy_shredder_clone_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 244:
		enemy_shredder_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 248:
		enemy_shredder_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 252:
		enemy_shredder_guard(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 256:
		enemy_shredder_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

void enemy_attack(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;
	uint32_t jump_target = 0;

	*p_a1 = 0x60000u | OBJECT(a0)->enemy.target;
	turtle = PLAYER_SLOT(*p_a1)->turtle;
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	enemy_collide_with_objects(a0, p_d5, p_d7, p_a5);
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	jump_target = mem_read32(0x53D2Au + (int16_t)OBJECT(a0)->enemy.move);
	switch (jump_target)
	{
	case 0x049A06u:
		enemy_jab(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049A52u:
		enemy_chop(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049A8Eu:
		enemy_swing(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049ACAu:
		enemy_high_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049B06u:
		enemy_jump_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049BBCu:
		enemy_long_jump_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049C72u:
		func_049C72();
		return;
	case 0x049C74u:
		func_049C74();
		return;
	case 0x049C76u:
		enemy_grab(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B2DAu:
		enemy_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B316u:
		enemy_low_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B352u:
		enemy_leaping_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B42Au:
		enemy_jump_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B4E0u:
		enemy_flying_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B5D6u:
		enemy_smash_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E2C4u:
		enemy_spear_thrust(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E336u:
		enemy_spear_throw(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E3C4u:
		enemy_knife_stab(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E400u:
		enemy_high_kick_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E43Cu:
		enemy_jump_kick_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E4F2u:
		enemy_throw_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04EBD6u:
		enemy_throw_axes(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04EC5Eu:
		enemy_high_kick_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04EC9Au:
		enemy_gun_swing(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04ECD6u:
		enemy_shoot_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04F076u:
		enemy_throw_shuriken(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04F0E4u:
		enemy_boomerang_throw(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FA96u:
		enemy_rocksteady_pincer_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FC04u:
		enemy_rocksteady_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FCD4u:
		enemy_rocksteady_punch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FD4Cu:
		enemy_rocksteady_gun_butt(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FD88u:
		enemy_rocksteady_shoot(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x0508A0u:
		enemy_bebop_pincer_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x050ADCu:
		enemy_bebop_punch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x050B8Cu:
		enemy_bebop_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x050C68u:
		enemy_bebop_shoot(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x052306u:
		enemy_rodney_shoot(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x052422u:
		enemy_rodney_whip(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x0534C4u:
		enemy_shredder_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x053524u:
		enemy_shredder_thrust(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x05356Eu:
		enemy_shredder_slash(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x0535B8u:
		enemy_shredder_sweep(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x053602u:
		enemy_shredder_ray(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

void enemy_hit(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint8_t d7 = 0;
	uint16_t d1 = 0;
	uint32_t object = 0;

	OBJECT(a0)->flags &= ~4u;
	d7 = 0xA8u;
	queue_sound(d7, 0u);
	if (OBJECT(a0)->enemy.move == 0x20u && (uint8_t)(OBJECT(a0)->hit_routine >> 8u) == 3u && OBJECT(a0)->hit_state != 0u)
	{
		OBJECT(a0)->flags |= 0x80u;
		object = 0x60000u | OBJECT(a0)->hit_object;
		if (OBJECT(object)->routine == 4u && (OBJECT(object)->unk_23 == 0xEu || OBJECT(object)->unk_23 == 0x15u))
			OBJECT(object)->unk_27 = 0x10u;
	}
	d1 = OBJECT(a0)->hit;
	if ((int8_t)(((uint32_t)OBJECT(a0)->flags << 1) ^ d1) >= 0)
	{
		if (OBJECT(a0)->health != 0u)
		{
			if (OBJECT(a0)->floor_height != OBJECT(a0)->height_whole)
				OBJECT(a0)->enemy.move = 0x10u;
			else
			{
				d1 &= 0x7Fu;
				OBJECT(a0)->enemy.move = (uint32_t)mem_read8(OBJECT(a0)->enemy.definition + 0x58u + d1) << 2;
			}
		}
		else
		{
			if (diagonal_scroll >= 0 && (int8_t)mem_read8(OBJECT(a0)->enemy.definition + 0x58u + (d1 & 0x7Fu)) >= 0)
			{
				OBJECT(a0)->enemy.move = 0x10u;
				OBJECT(a0)->routine++;
				enemy_react(a0, p_d5, p_d7, p_a1, p_a5);
				return;
			}
			OBJECT(a0)->enemy.move = 0x20u;
		}
	}
	else if (OBJECT(a0)->health == 0u)
	{
		if (diagonal_scroll < 0 || (int8_t)mem_read8(OBJECT(a0)->enemy.definition + 0x58u + (d1 & 0x7Fu)) < 0)
			OBJECT(a0)->enemy.move = 0x24u;
		else
			OBJECT(a0)->enemy.move = 0x14u;
	}
	else
	{
		if (OBJECT(a0)->floor_height != OBJECT(a0)->height_whole)
		{
			OBJECT(a0)->enemy.move = 0x14u;
			OBJECT(a0)->routine++;
			enemy_react(a0, p_d5, p_d7, p_a1, p_a5);
			return;
		}
		OBJECT(a0)->enemy.move = 0xCu;
	}
	OBJECT(a0)->routine++;
	enemy_react(a0, p_d5, p_d7, p_a1, p_a5);
}

void enemy_react(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	*p_a1 = 0x60000u | OBJECT(a0)->enemy.target;
	enemy_collide_with_objects(a0, p_d5, p_d7, p_a5);
	enemy_floor_contacts(a0, &ignored, &ignored_2, &ignored_3, &ignored_4, p_d5, p_d7, p_a5);
	switch ((uint32_t)(int16_t)OBJECT(a0)->enemy.move)
	{
	case 228:
		enemy_crash_into_scenery(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 232:
		enemy_crash_into_scenery_low(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0:
		enemy_flinch_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 4:
		enemy_flinch_bent(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 8:
		enemy_flinch_reel(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 12:
		enemy_flinch_hunched(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 36:
		enemy_killed_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 32:
		enemy_killed_forward(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 16:
		enemy_knocked_forward(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 128:
		enemy_thrown_by_donatello(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 132:
		*p_a5 = unreached_04A338(a0, *p_a1);
		return;
	case 136:
		enemy_thrown_by_michelangelo(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 140:
		*p_a5 = unreached_04A3F4(a0, *p_a1);
		return;
	case 188:
		enemy_thrown_by_raphael(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 192:
		*p_a5 = unreached_04A4B2(a0, *p_a1);
		return;
	case 196:
		enemy_thrown_by_leonardo(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 200:
		*p_a5 = unreached_04A570(a0, *p_a1);
		return;
	case 20:
		enemy_knocked_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 24:
		enemy_die(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 28:
		enemy_die_on_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 40:
		enemy_flinch_back_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 44:
		enemy_flinch_bent_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 48:
		enemy_flinch_reel_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 52:
		enemy_flinch_hunched_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 56:
		enemy_flinch_back_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 60:
		enemy_flinch_bent_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 68:
		enemy_flinch_hunched_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 72:
		enemy_flinch_back_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 76:
		enemy_flinch_bent_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 80:
		enemy_flinch_reel_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 84:
		enemy_flinch_hunched_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 88:
		enemy_flinch_back_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 92:
		enemy_flinch_bent_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 96:
		enemy_flinch_reel_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 100:
		enemy_flinch_hunched_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 120:
		enemy_flinch_back_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 124:
		enemy_flinch_bent_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 104:
		enemy_flinch_back_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 108:
		enemy_flinch_bent_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 112:
		enemy_flinch_reel_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 164:
		enemy_rocksteady_flinch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 168:
		enemy_rocksteady_reel(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 160:
		enemy_rocksteady_flinch_from_behind(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 152:
		enemy_rocksteady_knocked_down(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 156:
		enemy_rocksteady_defeated(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 172:
		enemy_bebop_flinch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 176:
		enemy_bebop_flinch_from_behind(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 180:
		enemy_bebop_knocked_down(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 184:
		enemy_bebop_defeated(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 148:
		enemy_mouser_thrown_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 224:
		enemy_mouser_break_down(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 144:
		enemy_mouser_knocked_flying(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 64:
		enemy_rodney_knocked_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 116:
		enemy_rodney_destroyed(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 204:
		enemy_shredder_lose_bar(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 208:
		enemy_shredder_flinch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 212:
		enemy_shredder_flinch_from_behind(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 216:
		enemy_shredder_defeated(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 220:
		enemy_shredder_vanish(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

void enemy_step_over_edge(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, slot = 0, turtle = 0;

	slot = 0x60000u | OBJECT(a0)->enemy.target;
	turtle = PLAYER_SLOT(slot)->turtle;
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	enemy_collide_with_objects(a0, p_d5, p_d7, p_a5);
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	a6 = TABLE32(indexed_table_of_32_bit_values_048F36, (uint32_t)(int16_t)OBJECT(a0)->enemy.move);
	run_object_state(a0, slot, a6, p_d5, p_d7, p_a5);
	*p_a1 = slot;
}

void enemy_hop_crouch(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
}

void enemy_hop_down(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->height_speed = rom_04881C[area & 0xFu];
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0x100;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	animation = 0x54ADAu;
	set_animation(0u, a0, animation);
}

uint32_t enemy_hop_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	enemy_follow_stairs_up(a0);
	move_object_with_height_blocked(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->enemy.move_time = 0x10u;
	OBJECT(a0)->state++;
	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_hop_land(uint32_t a0)
{
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy.move_time;
	OBJECT(a0)->enemy.move_time = move_time - 1u;
	if (move_time == 1u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
	}
}

void enemy_hop_right(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->height_speed = rom_04881C[area & 0xFu];
	OBJECT(a0)->x_speed = 0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	OBJECT(a0)->flags |= 0x40u;
	animation = 0x54ADAu;
	set_animation(0u, a0, animation);
}

void enemy_hop_left(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->height_speed = rom_04881C[area & 0xFu];
	OBJECT(a0)->x_speed = -0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	OBJECT(a0)->flags &= 0xBFu;
	animation = 0x54ADAu;
	set_animation(0u, a0, animation);
}

void enemy_hop_up_crouch(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = animations_04CF3E_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_hop_up(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = -0x80;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	animation = 0x4CF5Eu;
	set_animation(0u, a0, animation);
}

uint32_t enemy_hop_up_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	enemy_follow_stairs_down(a0);
	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->enemy.move_time = 0x10u;
	OBJECT(a0)->state++;
	animation = 0x4CB1Eu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_hop_up_right(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->x_speed = 0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	OBJECT(a0)->flags |= 0x40u;
	animation = 0x54ADAu;
	set_animation(0u, a0, animation);
}

uint32_t enemy_hop_up_fall_blocked(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	enemy_follow_stairs_down(a0);
	move_object_with_height_blocked(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->enemy.move_time = 0x10u;
	OBJECT(a0)->state++;
	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_hop_up_left(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->x_speed = -0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	OBJECT(a0)->flags &= 0xBFu;
	animation = 0x54ADAu;
	set_animation(0u, a0, animation);
}

void enemy_shuffle(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049240_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shuffle_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->enemy_shuffle.steps = 4u;
	OBJECT(a0)->state++;
	animation = 0x54A18u;
	set_animation(0u, a0, animation);
}

void enemy_shuffle_step(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->x_speed = 0x100;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->state++;
	animation = 0x54A38u;
	set_animation(0u, a0, animation);
}

void enemy_shuffle_turn(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t steps = 0;

	if (OBJECT(a0)->frame_time != 0u)
	{
		move_object_blocked(a0);
		return;
	}
	steps = OBJECT(a0)->enemy_shuffle.steps;
	OBJECT(a0)->enemy_shuffle.steps = steps - 1u;
	if (steps != 1u)
	{
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		animation = 0x54A38u;
		set_animation(0u, a0, animation);
		return;
	}
	OBJECT(a0)->state++;
	animation = 0x54A62u;
	set_animation(0u, a0, animation);
}

void enemy_shuffle_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy_shuffle.move_time = 0u;
		OBJECT(a0)->enemy_shuffle.retarget_time = 0u;
	}
}

void unreached_0492EC(uint32_t d7, uint32_t a0, uint32_t a1, uint32_t a5)
{
	uint32_t a6 = 0, ignored = 0;

	a6 = indexed_table_of_32_bit_values_0492F8_ADDRESS;
	run_object_state(a0, a1, a6, &ignored, &d7, &a5);
}

/* Unused: the enemy backs away from its turtle facing it */
void enemy_retreat_start(uint32_t a0)
{
	uint8_t target_direction = 0;
	uint32_t animation = 0;

	OBJECT(a0)->enemy.move_time = 0x54u;
	target_direction = OBJECT(a0)->enemy.target_direction;
	OBJECT(a0)->x_speed = 0x180;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(target_direction - 0x40u) < 0)
	{
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		OBJECT(a0)->flags |= 0x40u;
	}
	OBJECT(a0)->state++;
	animation = 0x54908u;
	set_animation(0u, a0, animation);
}

/* Unused: the enemy backs away until its move is over */
void enemy_retreat_step(uint32_t a0)
{
	OBJECT(a0)->enemy.move_time--;
	move_object_blocked(a0);
}

void enemy_circle(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049350_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_circle_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d0 = 0, ignored = 0;

	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_circle.move_time = 0xB4u;
	a6 = animations_049358_ADDRESS;
	enemy_face_target_animation(a0, a6, &d0, &ignored);
	OBJECT(a0)->enemy_circle.clockwise = 0u;
	if ((int8_t)(uint8_t)(random_seed >> 8u) >= 0)
	{
		enemy_circle_aim((uint8_t)d0, a0, p_d7, p_a5);
		return;
	}
	OBJECT(a0)->enemy_circle.clockwise = 1u;
	enemy_circle_aim((uint8_t)d0, a0, p_d7, p_a5);
}

void enemy_circle_aim(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t d6 = 0;

	if (OBJECT(a0)->enemy_circle.clockwise != 0u)
		d0 += 0x50u;
	else
		d0 -= 0x30u;
	d1 = 0x180u;
	speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
}

void enemy_circle_step(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	OBJECT(a0)->enemy_circle.move_time--;
	d7_2 = (d7 & ~0xFFu) | OBJECT(a0)->contacts;
	t1 = d7_2 & 0x1Eu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 != 0u)
	{
		OBJECT(a0)->enemy_circle.clockwise ^= 1u;
		a6 = animations_049358_ADDRESS;
		enemy_face_target_animation(a0, a6, &d0, &ignored);
		enemy_circle_aim((uint8_t)d0, a0, &d7_2, p_a5);
		move_object_blocked(a0);
		*p_d7 = d7_2;
		return;
	}
	if (OBJECT(a0)->enemy_circle.target_direction != OBJECT(a0)->enemy_circle.facing)
	{
		a6 = animations_049358_ADDRESS;
		enemy_face_target_animation(a0, a6, &d0, &ignored);
		enemy_circle_aim((uint8_t)d0, a0, &d7_2, p_a5);
	}
	move_object_blocked(a0);
	*p_d7 = d7_2;
}

void enemy_charge(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049414_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_charge_start(uint32_t a0)
{
	uint8_t target_direction = 0;
	uint32_t animation = 0, d7 = 0;

	d7 = 0x100u;
	d7 = random_below((uint16_t)d7, a0);
	OBJECT(a0)->unk_46 = d7;
	target_direction = OBJECT(a0)->enemy.target_direction;
	OBJECT(a0)->x_speed = 0x300;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->flags |= 0x40u;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		OBJECT(a0)->flags &= 0xBFu;
	}
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy.move_time = 0xB4u;
	animation = 0x54A78u;
	set_animation(0u, a0, animation);
	return d7;
}

uint32_t enemy_charge_run(uint32_t d7, uint32_t a0)
{
	uint16_t target_dy = 0;

	target_dy = OBJECT(a0)->enemy.target_dy;
	if (OBJECT(a0)->enemy.target_dx > 0x28u)
	{
		move_object_blocked(a0);
		return d7;
	}
	d7 = (d7 & ~0xFFu) | 7u;
	if (target_dy >= 0x10u && (int8_t)OBJECT(a0)->unk_46 < 0)
		d7 = (d7 & ~0xFFu) | 0x20u;
	OBJECT(a0)->enemy.move_time = d7;
	OBJECT(a0)->state++;
	move_object_blocked(a0);
	return d7;
}

uint32_t enemy_charge_brake(uint32_t d7, uint32_t a0)
{
	OBJECT(a0)->enemy.move_time--;
	if (OBJECT(a0)->enemy.move_time >= 7u)
	{
		move_object_blocked(a0);
		return d7;
	}
	d7 = (d7 & ~0xFFFFu) | 0x80u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		d7 = (d7 & ~0xFFFFu) | (uint16_t)(0u - d7);
	OBJECT(a0)->x_speed += d7;
	move_object_blocked(a0);
	return d7;
}

/* Unused: an enemy crashes into the scenery, which breaks, and dies */
void enemy_crash_into_scenery(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0494D2_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

/* Unused: the scenery breaks where the enemy crashes, and it lies there */
uint32_t enemy_crash_into_scenery_start(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x40u;
	queue_sound((uint8_t)d7_2, 0u);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x14u;
	a6 = 0x189D8u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x15u;
	a6 = 0x18A12u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x16u;
	a6 = 0x18A70u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x17u;
	a6 = 0x18A8Au;
	draw_tile_block((uint16_t)d7_2, a6);
	OBJECT(a0)->state++;
	animation = animations_05C9C4_ADDRESS;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* Unused: the crashed enemy is gone when its animation ends */
uint32_t enemy_crash_into_scenery_end(uint32_t d7, uint32_t a0)
{
	uint8_t t1 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		d7 = (d7 & ~0xFFu) | 0x10u;
		queue_sound((uint8_t)d7, 0u);
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
			enemies_on_screen = 0u;
	}
	return d7;
}

/* Unused: the same crash lower in the scenery */
void enemy_crash_into_scenery_low(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049568_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

/* Unused: the scenery breaks lower down where the enemy crashes */
uint32_t enemy_crash_into_scenery_low_start(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x40u;
	queue_sound((uint8_t)d7_2, 0u);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x18u;
	a6 = 0x18A24u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x19u;
	a6 = 0x18A5Eu;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x1Au;
	a6 = 0x18A70u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x1Bu;
	a6 = 0x18A8Au;
	draw_tile_block((uint16_t)d7_2, a6);
	OBJECT(a0)->state++;
	animation = animations_05C9C4_ADDRESS;
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_walk_to_target(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0495D6_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_target_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 8u;
	OBJECT(a0)->state++;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	a6 = mem_read32(a1);
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	*p_a5 = animations_049258_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_049258_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_to_target_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t speed = 0;
	uint32_t a5 = 0, a6 = 0, d0 = 0, d6 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy_walk.move_time;
	OBJECT(a0)->enemy_walk.move_time = move_time - 1u;
	if (move_time == 1u)
	{
		a6 = mem_read32(a1);
		d0 = direction_to_object(0u, a0, a6);
		a5 = OBJECT(a0)->enemy_walk.animations;
		enemy_turn_to_object((uint8_t)d0, a0, a6, p_d7, &a5);
		speed = OBJECT(a0)->enemy_walk.speed;
		speeds_from_direction((uint8_t)d0, speed, &d6, p_d7, p_a5);
		OBJECT(a0)->x_speed = d6;
		OBJECT(a0)->y_speed = *p_d7;
		OBJECT(a0)->enemy_walk.move_time = 8u;
	}
	if (OBJECT(a0)->enemy_walk.target_dx >= 0x20u || OBJECT(a0)->enemy_walk.target_dy >= 0x20u)
		move_object_blocked(a0);
}

void enemy_walk_to_side(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04965A_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_side_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xF0u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x140u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_049258_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_to_side_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time--;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = OBJECT(a0)->enemy_walk.animations;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	if (OBJECT(a0)->enemy_walk.target_dx < 0x20u || (int8_t)(target_direction - 0x40u - OBJECT(a0)->enemy_walk.side) < 0)
	{
		OBJECT(a0)->y_speed = 0;
		OBJECT(a0)->x_speed = OBJECT(a0)->enemy_walk.speed;
		if ((int8_t)OBJECT(a0)->enemy_walk.side < 0)
			OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	else
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = OBJECT(a0)->enemy_walk.speed;
		if ((int8_t)OBJECT(a0)->enemy_walk.target_direction >= 0)
			OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	}
	if (OBJECT(a0)->enemy_walk.target_dy < 3u)
		OBJECT(a0)->state++;
	move_object_blocked(a0);
}

void enemy_walk_to_side_crouch(uint32_t a0)
{
	uint32_t animation = 0;

	if ((frame_count & 7u) != 0u)
	{
		OBJECT(a0)->state += 2u;
		return;
	}
	OBJECT(a0)->state++;
	animation = 0x549E4u;
	set_animation(0u, a0, animation);
}

void enemy_walk_to_side_turn(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->state++;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_to_side_hold(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time--;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = OBJECT(a0)->enemy_walk.animations;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	if (OBJECT(a0)->enemy_walk.target_dx >= 0x10u)
	{
		OBJECT(a0)->y_speed = 0;
		OBJECT(a0)->x_speed = OBJECT(a0)->enemy_walk.speed;
		if ((int8_t)(target_direction - 0x40u) >= 0)
			OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	else
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = 0;
	}
	if (OBJECT(a0)->enemy_walk.target_dy < 3u)
	{
		move_object_blocked(a0);
		return;
	}
	OBJECT(a0)->state -= 3u;
	move_object_blocked(a0);
}

void enemy_keep_distance(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049796_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_keep_distance_start(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, ignored = 0;

	OBJECT(a0)->enemy.move_time = 0xFFu;
	OBJECT(a0)->state++;
	a6 = animations_049358_ADDRESS;
	enemy_face_target_animation(a0, a6, &ignored, &d7);
	OBJECT(a0)->frame_time = 0u;
	return d7;
}

void enemy_keep_distance_watch(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a5 = 0, a6 = 0, d6 = 0, ignored = 0;

	OBJECT(a0)->enemy.move_time--;
	if (OBJECT(a0)->enemy.target_direction != OBJECT(a0)->enemy.facing)
	{
		a6 = animations_049358_ADDRESS;
		enemy_face_target_animation(a0, a6, &ignored, p_d7);
		OBJECT(a0)->frame_time = 0u;
	}
	if (OBJECT(a0)->enemy.target_dx < 0x50u && OBJECT(a0)->enemy.target_dy < 0x20u)
	{
		OBJECT(a0)->state = 2u;
		d0 = (uint8_t)(OBJECT(a0)->enemy.target_direction - 0x80u);
		a5 = animations_049258_ADDRESS;
		a6 = mem_read32(a1);
		enemy_face_object(d0, a0, a6, p_d7, &a5);
		d1 = 0x100u;
		speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
		OBJECT(a0)->x_speed = d6;
		OBJECT(a0)->y_speed = *p_d7;
		return;
	}
	if (OBJECT(a0)->enemy.target_dx >= 0x70u || OBJECT(a0)->enemy.target_dy >= 0x40u)
	{
		OBJECT(a0)->state = 3u;
		d0 = OBJECT(a0)->enemy.target_direction;
		a5 = animations_049258_ADDRESS;
		a6 = mem_read32(a1);
		enemy_face_object(d0, a0, a6, p_d7, &a5);
		d1 = 0x100u;
		speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
		OBJECT(a0)->x_speed = d6;
		OBJECT(a0)->y_speed = *p_d7;
	}
}

void enemy_keep_distance_back_off(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	if (OBJECT(a0)->enemy.target_dx >= 0x50u || OBJECT(a0)->enemy.target_dy >= 0x20u)
		OBJECT(a0)->state = 0u;
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

void enemy_keep_distance_close_in(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	if (OBJECT(a0)->enemy.target_dx < 0x70u && OBJECT(a0)->enemy.target_dy < 0x40u)
		OBJECT(a0)->state = 0u;
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

void enemy_back_off(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0498A6_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_back_off_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d6 = 0;

	OBJECT(a0)->enemy_back_off.move_time = 0x40u;
	OBJECT(a0)->enemy_back_off.time = 0x28u;
	d0 = OBJECT(a0)->enemy_back_off.target_direction;
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(d0, a0, a6, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x100u;
	speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->state++;
}

void enemy_back_off_walk(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0, animation = 0;
	uint8_t time = 0;

	target_direction = OBJECT(a0)->enemy_back_off.target_direction;
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
	time = OBJECT(a0)->enemy_back_off.time;
	OBJECT(a0)->enemy_back_off.time = time - 1u;
	if (time != 1u)
	{
		enemy_back_off_wait(a0, a1);
		return;
	}
	OBJECT(a0)->state++;
	animation = 0x549E4u;
	set_animation(0u, a0, animation);
}

void enemy_back_off_wait(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		OBJECT(a0)->enemy_back_off.approach = 0u;
		OBJECT(a0)->enemy_back_off.move_time = 0u;
	}
}

void enemy_run_away(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049940_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_run_away_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0, target_direction = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d6 = 0, ignored = 0;

	OBJECT(a0)->enemy.move_time = 8u;
	d0 = (uint8_t)(OBJECT(a0)->enemy.target_direction - 0x80u);
	d1 = 0x200u;
	speeds_from_direction(d0, d1, &d6, p_d7, &ignored);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->state++;
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
	enemy_run_away_step(a0, a1, p_d7, p_a5);
}

void enemy_run_away_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy.move_time;
	OBJECT(a0)->enemy.move_time = move_time - 1u;
	if (move_time == 1u)
		OBJECT(a0)->enemy.approach = 0u;
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

void enemy_walk_across(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0499B0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_across_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0x78u;
	OBJECT(a0)->x_speed = 0x100;
	OBJECT(a0)->y_speed = 0;
	if ((int8_t)(OBJECT(a0)->enemy_walk.target_direction - 0x40u) >= 0)
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	OBJECT(a0)->state++;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_across_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time--;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

void enemy_jab(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049A12_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_jab_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x54CC8u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x201u;
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

void enemy_attack_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	enemy_back_to_thinking(a0);
}

void enemy_chop(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049A5E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_chop_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x54D02u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x201u;
	d7_2 = (d7 & ~0xFFu) | 1u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

void enemy_swing(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049A9A_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_swing_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;

	animation = 0x54D3Cu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x201u;
	d7 &= ~0xFFu;
	d7 = enemy_face_target(d7, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7;
}

void enemy_high_kick(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049AD6_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_high_kick_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x54D76u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x201u;
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

void enemy_jump_kick(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049B12_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_jump_kick_crouch(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x203u;
	d7_2 = (d7 & ~0xFFu) | 4u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

uint32_t enemy_jump_kick_leap(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	a6 = 0x49B22u;
	d7 = enemy_start_arc(d7, a0, a6);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	animation = 0x54B1Cu;
	set_animation(0u, a0, animation);
	return d7;
}

uint32_t enemy_jump_kick_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x49B22u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_long_jump_kick(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049BC8_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_long_jump_kick_crouch(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x203u;
	d7_2 = (d7 & ~0xFFu) | 4u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

uint32_t enemy_long_jump_kick_leap(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	a6 = 0x49BD8u;
	d7 = enemy_start_arc(d7, a0, a6);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	animation = 0x54B1Cu;
	set_animation(0u, a0, animation);
	return d7;
}

uint32_t enemy_long_jump_kick_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x49BD8u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
	return d7;
}

void func_049C72(void)
{
}

void func_049C74(void)
{
}

void enemy_grab(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049C82_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_grab_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t a6 = 0, animation = 0, d0 = 0, d6 = 0, d7 = 0;

	if ((int8_t)OBJECT(a0)->enemy_grab.target_faces < 0 || mem_read8(mem_read32(a1) + 4u) == 4u || mem_read8(a1 + 8u) != 0u)
		enemy_back_to_thinking(a0);
	else
	{
		animation = 0x54872u;
		set_animation(0u, a0, animation);
		OBJECT(a0)->damage = 0x101u;
		d7 = 0xEu;
		enemy_face_target(d7, a0);
		mem_write8(a1 + 8u, 0x60u);
		OBJECT(a0)->enemy_grab.time = 0x3Cu;
		a6 = mem_read32(a1);
		d0 = direction_to_object(0u, a0, a6);
		d1 = 0x200u;
		speeds_from_direction((uint8_t)d0, d1, &d6, p_d7, p_a5);
		OBJECT(a0)->x_speed = d6;
		OBJECT(a0)->y_speed = *p_d7;
		OBJECT(a0)->flags |= 4u;
		OBJECT(a0)->state++;
		move_object_blocked(a0);
	}
}

void enemy_grab_run(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t a6 = 0, d0 = 0, d6 = 0;
	uint8_t time = 0;

	mem_write8(a1 + 8u, 0x60u);
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_grab.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		enemy_leave_side(a0, a1);
		OBJECT(a0)->flags &= 0x73u;
		OBJECT(a0)->state++;
		return;
	}
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		time = OBJECT(a0)->enemy_grab.time;
		OBJECT(a0)->enemy_grab.time = time - 1u;
		if (time != 1u)
		{
			a6 = mem_read32(a1);
			d0 = direction_to_object(0u, a0, a6);
			d1 = 0x200u;
			speeds_from_direction((uint8_t)d0, d1, &d6, p_d7, p_a5);
			OBJECT(a0)->x_speed = d6;
			OBJECT(a0)->y_speed = *p_d7;
			move_object_blocked(a0);
			return;
		}
	}
	OBJECT(a0)->flags &= ~4u;
	enemy_back_to_thinking(a0);
}

void enemy_grab_hold(uint32_t a0, uint32_t a1)
{
	uint32_t object = 0;
	uint8_t t1 = 0;

	mem_write8(a1 + 8u, 0x60u);
	object = 0x60000u | OBJECT(a0)->hit_object;
	if (OBJECT(object)->routine == 4u)
	{
		if (OBJECT(object)->unk_23 == 0xEu || OBJECT(object)->unk_23 == 0x15u)
		{
			OBJECT(object)->unk_28 = (uint16_t)(a0 >> 16u);
			OBJECT(object)->unk_2A = (uint8_t)(a0 >> 8u);
			OBJECT(object)->unk_2B = (uint8_t)a0;
			return;
		}
		OBJECT(a0)->state++;
		return;
	}
	OBJECT(a0)->flags = 0u;
	OBJECT(a0)->contacts = 0u;
	t1 = enemies_on_screen - 1u;
	enemies_on_screen = t1;
	if ((int8_t)t1 < 0)
		enemies_on_screen = 0u;
}

void enemy_grab_end(uint32_t a0)
{
	OBJECT(a0)->flags |= 0x82u;
	enemy_back_to_thinking(a0);
}

void enemy_flinch_back(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049DE8_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_back_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x54B4Eu;
	set_animation(0u, a0, animation);
}

void enemy_flinch_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	enemy_back_to_thinking_hittable(a0);
}

void enemy_flinch_bent(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049E1C_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_bent_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x54B82u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_reel(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049E40_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_reel_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x54BACu;
	set_animation(0u, a0, animation);
}

void enemy_flinch_hunched(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049E64_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_hunched_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x54BD6u;
	set_animation(0u, a0, animation);
}

void enemy_killed_back(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049E88_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_killed_back_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	a6 = 0x49EA0u;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x54C54u;
	set_animation(0u, a0, animation);
	enemy_leave_side(a0, a1);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

uint32_t enemy_killed_back_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	d0 = 8u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & OBJECT(a0)->contacts) != 0u)
	{
		OBJECT(a0)->state = 3u;
		d7_2 = (d7 & ~0xFFu) | 0x89u;
		queue_sound((uint8_t)d7_2, 0u);
		animation = 0x54EACu;
		set_animation(0u, a0, animation);
		return d7_2;
	}
	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x49EA0u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x54C6Au;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_killed_back_lie(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	if ((uint16_t)OBJECT(a0)->x_speed != 0u)
	{
		move_object_blocked(a0);
		a6 = 0x4A5C2u;
		enemy_arc_step(a0, a6);
	}
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy.move = 0x1Cu;
		OBJECT(a0)->state = 0u;
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
	}
}

void enemy_killed_back_on_wall(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
		OBJECT(a0)->state++;
}

uint32_t enemy_killed_back_slide_down(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	OBJECT(a0)->height -= 0x100u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->state++;
	OBJECT(a0)->contacts &= 0x7Fu;
	animation = 0x54ECCu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_killed_back_down(uint32_t a0, uint32_t a1)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy.move = 0x1Cu;
		OBJECT(a0)->state = 0u;
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
	}
}

void enemy_killed_forward(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049FC4_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_killed_forward_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	a6 = 0x49FDCu;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x54BECu;
	set_animation(0u, a0, animation);
	enemy_leave_side(a0, a1);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

uint32_t enemy_killed_forward_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	d0 = 8u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		d0 = 0x10u;
	if ((d0 & OBJECT(a0)->contacts) != 0u)
	{
		OBJECT(a0)->state = 3u;
		d7_2 = (d7 & ~0xFFu) | 0x89u;
		queue_sound((uint8_t)d7_2, 0u);
		animation = 0x54E62u;
		set_animation(0u, a0, animation);
		return d7_2;
	}
	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x49FDCu;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x54BF6u;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_killed_forward_lie(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	if ((uint16_t)OBJECT(a0)->x_speed != 0u)
	{
		move_object_blocked(a0);
		a6 = 0x4A114u;
		enemy_arc_step(a0, a6);
	}
	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->enemy.move = 0x18u;
	OBJECT(a0)->state = 0u;
	mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
}

void enemy_killed_forward_on_wall(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
		OBJECT(a0)->state++;
}

uint32_t enemy_killed_forward_slide_down(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	OBJECT(a0)->height -= 0x100u;
	enemy_landed(a0, &d7, &zero);
	if (zero)
	{
		OBJECT(a0)->state++;
		OBJECT(a0)->contacts &= 0x7Fu;
		animation = 0x54E82u;
		set_animation(0u, a0, animation);
	}
	return d7;
}

void enemy_killed_forward_down(uint32_t a0, uint32_t a1)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy.move = 0x18u;
		OBJECT(a0)->state = 0u;
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
	}
}

void enemy_knocked_forward(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A100_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_knocked_forward_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	a6 = 0x4A114u;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x54BECu;
	set_animation(0u, a0, animation);
	enemy_leave_side(a0, a1);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

uint32_t enemy_knocked_forward_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x4A114u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x54BF6u;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_knocked_forward_lie(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	if ((uint16_t)OBJECT(a0)->x_speed != 0u)
	{
		move_object_blocked(a0);
		a6 = 0x4A114u;
		enemy_arc_step(a0, a6);
	}
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy_knocked.down_time = 0x1Eu;
		OBJECT(a0)->state++;
		if (OBJECT(a0)->health_bars == 0u)
		{
			OBJECT(a0)->enemy_knocked.move = 0x18u;
			OBJECT(a0)->state = 0u;
			mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
		}
	}
}

void enemy_knocked_forward_wait(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t down_time = 0;

	down_time = OBJECT(a0)->enemy_knocked.down_time;
	OBJECT(a0)->enemy_knocked.down_time = down_time - 1u;
	if (down_time == 1u)
	{
		OBJECT(a0)->state++;
		animation = 0x54C16u;
		set_animation(0u, a0, animation);
	}
}

void enemy_thrown_by_donatello(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A1E0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void unreached_04A202(uint32_t a0)
{
	OBJECT(a0)->flags &= 0x7Fu;
	OBJECT(a0)->unk_22 = 0xCu;
	OBJECT(a0)->state++;
}

void enemy_thrown_by_donatello_swing(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy.move_time;
	OBJECT(a0)->enemy.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)OBJECT(a0)->enemy.facing >= 0)
		OBJECT(a0)->flags |= 0x40u;
	a6 = 0x60000u | OBJECT(a0)->attacker;
	*p_a5 = 0x4A1FCu;
	enemy_place_by(a0, *p_a5, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0x306u;
	enemy_take_damage((uint16_t)d7_2, a0);
	OBJECT(a0)->flags |= 0x80u;
	d7_2 = enemy_knocked_back_start(d7_2, a0, a1);
	*p_d7 = d7_2;
}

uint32_t enemy_thrown_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	d0 = 8u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & OBJECT(a0)->contacts) != 0u)
	{
		OBJECT(a0)->state = 4u;
		d7_2 = (d7 & ~0xFFu) | 0x89u;
		queue_sound((uint8_t)d7_2, 0u);
		animation = 0x54EACu;
		set_animation(0u, a0, animation);
		return d7_2;
	}
	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x4A5C2u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x54C6Au;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_take_damage(uint16_t d7, uint32_t a0)
{
	uint16_t d2 = 0, health_bars = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	health_bars = (((uint32_t)OBJECT(a0)->health_bars << 8u) | OBJECT(a0)->health);
	t1 = (uint8_t)health_bars;
	d2 = (uint16_t)((health_bars & ~0xFFu) | (uint8_t)(t1 - d7));
	if (t1 <= (uint8_t)d7)
	{
		t2 = (d2 & ~0xFFu) | (uint8_t)d7;
		d2 = (uint16_t)(t2 - d7);
		if (t2 < (uint16_t)d7)
			d2 = 0u;
	}
	OBJECT(a0)->health_bars = (uint8_t)(d2 >> 8u);
	OBJECT(a0)->health = (uint8_t)d2;
}

void enemy_place_by(uint32_t a0, uint32_t a5, uint32_t a6)
{
	uint16_t d1 = 0;

	d1 = (uint16_t)(OBJECT(a6)->screen_x - OBJECT(a0)->screen_x + mem_read16(a5));
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		d1 = (uint16_t)(d1 - mem_read16(a5) - mem_read16(a5));
	OBJECT(a0)->x += (uint32_t)(int16_t)d1 << 8;
	OBJECT(a0)->y += (uint32_t)(int16_t)(OBJECT(a6)->screen_y - OBJECT(a0)->screen_y + mem_read16(a5 + 2u)) << 8;
	OBJECT(a0)->height_whole = OBJECT(a6)->height_whole + mem_read8(a5 + 4u);
	OBJECT(a0)->floor_height = OBJECT(a6)->floor_height;
}

uint32_t unreached_04A338(uint32_t a0, uint32_t a1)
{
	uint32_t a5 = 0, a6 = 0;

	OBJECT(a0)->flags |= 0x82u;
	enemy_leave_side(a0, a1);
	a6 = 0x60000u | OBJECT(a0)->attacker;
	a5 = record_04A332_ADDRESS;
	enemy_place_by(a0, a5, a6);
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->unk_22 = 0u;
	OBJECT(a0)->unk_2A = 0u;
	return a5;
}

void enemy_thrown_by_michelangelo(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A374_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void unreached_04A396(uint32_t a0)
{
	OBJECT(a0)->flags &= 0x7Fu;
	OBJECT(a0)->unk_22 = 0x12u;
	OBJECT(a0)->state++;
}

void enemy_thrown_by_michelangelo_swing(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy.move_time;
	OBJECT(a0)->enemy.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	a6 = 0x60000u | OBJECT(a0)->attacker;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)OBJECT(a0)->enemy.facing >= 0)
		OBJECT(a0)->flags |= 0x40u;
	*p_a5 = 0x4A390u;
	enemy_place_by(a0, *p_a5, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0x306u;
	enemy_take_damage((uint16_t)d7_2, a0);
	OBJECT(a0)->flags |= 0x80u;
	d7_2 = enemy_knocked_back_start(d7_2, a0, a1);
	*p_d7 = d7_2;
}

uint32_t unreached_04A3F4(uint32_t a0, uint32_t a1)
{
	uint32_t a5 = 0, a6 = 0;

	OBJECT(a0)->flags |= 0x82u;
	enemy_leave_side(a0, a1);
	a6 = 0x60000u | OBJECT(a0)->attacker;
	a5 = record_04A3EE_ADDRESS;
	enemy_place_by(a0, a5, a6);
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->unk_22 = 0u;
	OBJECT(a0)->unk_2A = 0u;
	return a5;
}

void enemy_thrown_by_raphael(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A432_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void unreached_04A454(uint32_t a0)
{
	OBJECT(a0)->flags &= 0x7Fu;
	OBJECT(a0)->unk_22 = 0x10u;
	OBJECT(a0)->state++;
}

void enemy_thrown_by_raphael_swing(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy.move_time;
	OBJECT(a0)->enemy.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	a6 = 0x60000u | OBJECT(a0)->attacker;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)OBJECT(a0)->enemy.facing >= 0)
		OBJECT(a0)->flags |= 0x40u;
	*p_a5 = 0x4A44Eu;
	enemy_place_by(a0, *p_a5, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0x306u;
	enemy_take_damage((uint16_t)d7_2, a0);
	OBJECT(a0)->flags |= 0x80u;
	d7_2 = enemy_knocked_back_start(d7_2, a0, a1);
	*p_d7 = d7_2;
}

uint32_t unreached_04A4B2(uint32_t a0, uint32_t a1)
{
	uint32_t a5 = 0, a6 = 0;

	OBJECT(a0)->flags |= 0x82u;
	enemy_leave_side(a0, a1);
	a6 = 0x60000u | OBJECT(a0)->attacker;
	a5 = record_04A4AC_ADDRESS;
	enemy_place_by(a0, a5, a6);
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->unk_22 = 0u;
	OBJECT(a0)->unk_2A = 0u;
	return a5;
}

void enemy_thrown_by_leonardo(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A4F0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void unreached_04A512(uint32_t a0)
{
	OBJECT(a0)->flags &= 0x7Fu;
	OBJECT(a0)->unk_22 = 0x14u;
	OBJECT(a0)->state++;
}

void enemy_thrown_by_leonardo_swing(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy.move_time;
	OBJECT(a0)->enemy.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	a6 = 0x60000u | OBJECT(a0)->attacker;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)OBJECT(a0)->enemy.facing >= 0)
		OBJECT(a0)->flags |= 0x40u;
	*p_a5 = 0x4A50Cu;
	enemy_place_by(a0, *p_a5, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0x306u;
	enemy_take_damage((uint16_t)d7_2, a0);
	OBJECT(a0)->flags |= 0x80u;
	d7_2 = enemy_knocked_back_start(d7_2, a0, a1);
	*p_d7 = d7_2;
}

uint32_t unreached_04A570(uint32_t a0, uint32_t a1)
{
	uint32_t a5 = 0, a6 = 0;

	OBJECT(a0)->flags |= 0x82u;
	enemy_leave_side(a0, a1);
	a6 = 0x60000u | OBJECT(a0)->attacker;
	a5 = record_04A56A_ADDRESS;
	enemy_place_by(a0, a5, a6);
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->unk_22 = 0u;
	OBJECT(a0)->unk_2A = 0u;
	return a5;
}

void enemy_knocked_back(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A5AE_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_knocked_back_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	a6 = 0x4A5C2u;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x54C54u;
	set_animation(0u, a0, animation);
	enemy_leave_side(a0, a1);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

uint32_t enemy_knocked_back_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x4A5C2u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x54C6Au;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_knocked_back_lie(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	if ((uint16_t)OBJECT(a0)->x_speed != 0u)
	{
		move_object_blocked(a0);
		a6 = 0x4A5C2u;
		enemy_arc_step(a0, a6);
	}
	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->enemy_knocked.down_time = 0x1Eu;
	OBJECT(a0)->state++;
	if (OBJECT(a0)->health_bars == 0u)
	{
		OBJECT(a0)->enemy_knocked.move = 0x1Cu;
		OBJECT(a0)->state = 0u;
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
	}
}

void enemy_knocked_back_wait(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t down_time = 0;

	down_time = OBJECT(a0)->enemy_knocked.down_time;
	OBJECT(a0)->enemy_knocked.down_time = down_time - 1u;
	if (down_time != 1u)
		return;
	OBJECT(a0)->state++;
	animation = 0x54C94u;
	set_animation(0u, a0, animation);
}

void enemy_knocked_back_get_up(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		enemy_back_to_thinking_hittable(a0);
		OBJECT(a0)->enemy_knocked.approach = 0u;
		if (OBJECT(a0)->health == 0u)
			OBJECT(a0)->health = 6u;
	}
}

void enemy_die(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A6BE_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_die_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x10u;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->state++;
	OBJECT(a0)->flags &= ~6u;
	animation = 0x54DBAu;
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_die_vanish(uint32_t a0)
{
	uint8_t t1 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
			enemies_on_screen = 0u;
	}
}

void enemy_die_on_back(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A710_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_die_on_back_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x10u;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->state++;
	OBJECT(a0)->flags &= ~6u;
	animation = 0x54E16u;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the closed roll-up door of area 4, with its colours */
void boss_shutter_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0, animation = 0;

	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->routine++;
	d7 = 0x43Au;
	a6 = 0xC704u;
	*p_a5 = post_palette_request(d7, a6);
	animation = animations_05CE06_ADDRESS;
	set_animation(0u, a0, animation);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
}

/* the scroll reaches the door: the music stops and it rolls up */
uint32_t boss_shutter_wait(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	if (LAYER(LAYER_B)->x < 0x3F000u)
		return d7;
	OBJECT(a0)->boss_shutter.open_time = 0x5Au;
	OBJECT(a0)->routine++;
	d7_2 = (d7 & ~0xFFFFu) | 0xFEu;
	music = d7_2;
	queue_sound((uint8_t)d7_2, 0u);
	d7_2 = (d7_2 & ~0xFFu) | 0x36u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = 0x5CE10u;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the door stays open, then Bebop and Rocksteady are told to come out, with their music */
uint32_t boss_shutter_open(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t open_time = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags &= 0x7Fu;
		open_time = OBJECT(a0)->boss_shutter.open_time;
		OBJECT(a0)->boss_shutter.open_time = open_time - 1u;
		if (open_time == 1u)
		{
			OBJECT(a0)->flags = 0u;
			OBJECT(a0)->contacts = 0u;
			bosses_come_out = 0xFFu;
			d7_2 = (d7 & ~0xFFFFu) | 0x64u;
			music = d7_2;
			queue_sound((uint8_t)d7_2, 0u);
			return d7_2;
		}
	}
	return d7;
}

/* a floor lamp */
void scenery_lamp_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->depth = 4u;
	OBJECT(a0)->routine++;
	animation = animations_04A7E6_ADDRESS;
	set_animation(0u, a0, animation);
}

/* the scenery stays as it is */
void scenery_stay(void)
{
}

/* an open manhole a turtle can fall into */
void scenery_open_manhole_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->scenery_open_manhole.hit_sound = 0xDCu;
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->attack = 0xCu;
	OBJECT(a0)->damage = 0u;
	OBJECT(a0)->routine++;
	animation = animations_04A81E_ADDRESS;
	set_animation(0u, a0, animation);
}

/* the scenery is gone once it leaves the screen */
void scenery_gone_off_screen(uint32_t a0)
{
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

/* a toppled chair */
void scenery_chair_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->depth = 4u;
	OBJECT(a0)->routine++;
	animation = animations_04A86E_ADDRESS;
	set_animation(0u, a0, animation);
}

/* flames on the floor, of the size its parameter gives */
void scenery_fire_start(uint32_t a0)
{
	uint32_t animation = 0;

	animation = TABLE32(animations_04A8A4, OBJECT(a0)->parameter);
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->depth = 4u;
}

/* the car full of Foot soldiers starts behind the screen's left edge */
uint32_t start_foot_car(uint32_t d7)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t object = 0;

	d0 = 2u;
	take_free_object_in_group(d0, &d7, &object, &zero);
	if (zero)
	{
		OBJECT(object)->flags = 1u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->kind = 0x3Bu;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->routine = 0u;
		OBJECT(object)->state = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		OBJECT(object)->throw = 0u;
		OBJECT(object)->height = 0u;
		OBJECT(object)->x = spawn_x - 0x18000u;
		OBJECT(object)->y = 0x6000u;
	}
	return d7;
}

/* the car drives across, knocking flying the turtles it runs into */
void foot_car_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->attack = 0x87u;
	OBJECT(a0)->damage = 0x403u;
	OBJECT(a0)->foot_car.hit_sound = 0xD4u;
	animation = animations_04A95C_ADDRESS;
	set_animation(0u, a0, animation);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->x_speed = 0x400;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->depth = 0x10u;
	OBJECT(a0)->routine++;
	foot_car_drive(a0);
}

/* the car drives on until it is past the screen */
void foot_car_drive(uint32_t a0)
{
	if ((int16_t)OBJECT(a0)->screen_x >= 0x1E0)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
	move_object(a0);
}

/* a burning piece of the ceiling, hidden until it falls */
void falling_debris_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->attack = 0u;
	OBJECT(a0)->damage = 0x103u;
	OBJECT(a0)->depth = 3u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->falling_debris.hit_sound = 0x70u;
	animation = animations_04A9DA_ADDRESS;
	set_animation(0u, a0, animation);
}

/* the debris falls when a turtle comes under it */
void falling_debris_wait(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d1 = 0, d2 = 0;

	if (OBJECT(a0)->screen_x >= 0x100u)
	{
		enemy_nearest_turtles(a0, p_d5, p_d7, p_a5, &a6);
		enemy_look_at_target(a0, a6, &d1, &d2);
		if ((uint16_t)d1 > 0x10u || (uint16_t)d2 > 0x10u)
		{
			falling_debris_burn(a0);
			return;
		}
	}
	OBJECT(a0)->flags = 0x85u;
	OBJECT(a0)->height_speed = -0x100;
	OBJECT(a0)->routine++;
	falling_debris_burn(a0);
}

/* the debris falls and burns on the floor */
uint32_t falling_debris_fall(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	OBJECT(a0)->height += OBJECT(a0)->height_speed;
	OBJECT(a0)->height_speed -= 0x40u;
	if ((int8_t)OBJECT(a0)->height_whole >= 0 || OBJECT(a0)->height_whole < 0xF0u)
		return d7;
	OBJECT(a0)->height = 0u;
	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->routine++;
	d7_2 = (d7 & ~0xFFu) | 0x31u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = 0x4AA16u;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the burning debris is gone once it leaves the screen */
void falling_debris_burn(uint32_t a0)
{
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

/* a Foot soldier rides in on a motorbike */
uint32_t motorbike_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	OBJECT(a0)->damage = 0x206u;
	OBJECT(a0)->attack = 7u;
	OBJECT(a0)->depth = 6u;
	OBJECT(a0)->motorbike.hit_sound = 0x44u;
	OBJECT(a0)->health_bars = 1u;
	OBJECT(a0)->health = 1u;
	d7_2 = (d7 & ~0xFFu) | 0x3Au;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->flags |= 0x86u;
	OBJECT(a0)->x_speed = -0x300;
	OBJECT(a0)->y_speed = 0;
	if (OBJECT(a0)->parameter != 0u)
	{
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->attack |= 0x80u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	animation = animations_05C632_ADDRESS;
	set_animation(0u, a0, animation);
	OBJECT(a0)->routine++;
	OBJECT(a0)->motorbike.aim_time = 1u;
	OBJECT(a0)->motorbike.wheelie = 0u;
	return d7_2;
}

/* the motorbike rides on and rears up at a turtle in its way */
void motorbike_ride(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0, d1 = 0, d2 = 0, target_turtle = 0;
	uint8_t aim_time = 0;

	aim_time = OBJECT(a0)->motorbike.aim_time;
	OBJECT(a0)->motorbike.aim_time = aim_time - 1u;
	if (aim_time == 1u)
	{
		OBJECT(a0)->motorbike.aim_time = 8u;
		enemy_nearest_turtles(a0, p_d5, p_d7, p_a5, &a6);
		OBJECT(a0)->motorbike.target_turtle = a6;
	}
	target_turtle = OBJECT(a0)->motorbike.target_turtle;
	enemy_look_at_target(a0, target_turtle, &d1, &d2);
	if ((uint16_t)d2 >= 8u || (uint16_t)d1 >= 0x40u)
	{
		motorbike_ride_off(a0);
		return;
	}
	OBJECT(a0)->motorbike.wheelie = 1u;
	animation = 0x5C686u;
	set_animation(d1, a0, animation);
	motorbike_ride_off(a0);
}

/* the riderless motorbike rides on off the screen */
void motorbike_ride_off(uint32_t a0)
{
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
	move_object(a0);
}

/* the rider is knocked off the motorbike */
void motorbike_struck(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t zero = 0;
	uint8_t d7 = 0;
	uint32_t a5 = 0, animation = 0, d7_2 = 0, object = 0;

	d7 = 0xA8u;
	queue_sound(d7, 0u);
	animation = 0x5C65Cu;
	a5 = 0x4AB4Eu;
	if (OBJECT(a0)->motorbike.wheelie != 0u)
	{
		animation = 0x5C6B0u;
		a5 = 0x4AB56u;
	}
	set_animation(0u, a0, animation);
	start_object_from_record(a0, a5, &d7_2, &object, &zero);
	if (zero)
	{
		OBJECT(object)->flags = OBJECT(a0)->flags;
		OBJECT(object)->flags &= 0xC1u;
		OBJECT(object)->routine = 5u;
		OBJECT(object)->state = 0u;
		OBJECT(object)->health_bars = 0u;
		OBJECT(object)->health = 0u;
		OBJECT(object)->enemy.move = 0x10u;
		OBJECT(object)->shadow = 0x2E928u;
		enemies_on_screen++;
	}
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_2 & 0xFFFFu);
	*p_a5 = a5;
}

void enemy_sword_soldier_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy.target = a6;
	OBJECT(a0)->enemy.retarget_time = 0x10u;
	OBJECT(a0)->enemy.move_time = 0u;
	OBJECT(a0)->enemy.approach = 0u;
	OBJECT(a0)->enemy.dodge_chance = 5u;
	OBJECT(a0)->depth = 4u;
	enemies_on_screen++;
	OBJECT(a0)->throw = 0x87u;
	OBJECT(a0)->colour = 7u;
	OBJECT(a0)->floor_height = 0u;
	enemy_set_floor(a0);
	OBJECT(a0)->health_bars = 3u;
	OBJECT(a0)->health = 6u;
	OBJECT(a0)->enemy.definition = 0x53F86u;
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine += 2u;
	animation = animations_055722_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_hammer_soldier_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy.target = a6;
	OBJECT(a0)->enemy.retarget_time = 0x10u;
	OBJECT(a0)->enemy.move_time = 0u;
	OBJECT(a0)->enemy.approach = 0u;
	OBJECT(a0)->enemy.dodge_chance = 0u;
	OBJECT(a0)->depth = 4u;
	enemies_on_screen++;
	OBJECT(a0)->throw = 0x85u;
	OBJECT(a0)->colour = 5u;
	OBJECT(a0)->floor_height = 0u;
	enemy_set_floor(a0);
	OBJECT(a0)->health_bars = 3u;
	OBJECT(a0)->health = 6u;
	OBJECT(a0)->enemy.definition = 0x5400Eu;
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine += 2u;
	animation = animations_057B46_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_walk_to_target_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ADB8_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_target_sword_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 8u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04ADC0_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04ADC0_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_to_side_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ADFA_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_side_sword_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xF0u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x140u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04ADC0_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_to_side_sword_crouch(uint32_t a0)
{
	uint32_t animation = 0;

	if ((frame_count & 0x700u) != 0u)
	{
		OBJECT(a0)->state += 2u;
		return;
	}
	OBJECT(a0)->state++;
	animation = 0x55852u;
	set_animation(0u, a0, animation);
}

void enemy_walk_to_side_sword_turn(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->state++;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_past_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04AE84_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_past_sword_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xB4u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	if ((int8_t)(OBJECT(a0)->enemy_walk.target_direction - 0x40u) >= 0)
		OBJECT(a0)->enemy_walk.speed = 0u - OBJECT(a0)->enemy_walk.speed;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04ADC0_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_past_sword_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time--;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	if (OBJECT(a0)->enemy_walk.target_dy >= 0x20u)
	{
		OBJECT(a0)->y_speed = 0;
		OBJECT(a0)->x_speed = OBJECT(a0)->enemy_walk.speed;
		if (OBJECT(a0)->enemy_walk.target_dx >= 0x40u)
		{
			OBJECT(a0)->enemy_walk.speed = 0x100u;
			if ((int8_t)(OBJECT(a0)->enemy_walk.target_direction - 0x40u) >= 0)
				OBJECT(a0)->enemy_walk.speed = 0u - OBJECT(a0)->enemy_walk.speed;
		}
	}
	else
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = 0x100;
		if ((int8_t)OBJECT(a0)->enemy_walk.target_direction < 0)
			OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	}
	move_object_blocked(a0);
}

void enemy_back_off_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04AF30_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_back_off_sword_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d6 = 0;

	OBJECT(a0)->enemy_back_off.move_time = 0x40u;
	OBJECT(a0)->enemy_back_off.time = 0x28u;
	d0 = OBJECT(a0)->enemy_back_off.target_direction;
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(d0, a0, a6, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x100u;
	speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->state++;
}

void enemy_back_off_sword_walk(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0, animation = 0;
	uint8_t time = 0;

	target_direction = OBJECT(a0)->enemy_back_off.target_direction;
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
	time = OBJECT(a0)->enemy_back_off.time;
	OBJECT(a0)->enemy_back_off.time = time - 1u;
	if (time != 1u)
	{
		enemy_back_off_sword_wait(a0, a1);
		return;
	}
	OBJECT(a0)->state++;
	animation = 0x55852u;
	set_animation(0u, a0, animation);
}

void enemy_back_off_sword_wait(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		OBJECT(a0)->enemy_back_off.approach = 0u;
		OBJECT(a0)->enemy_back_off.move_time = 0u;
	}
}

void enemy_walk_to_line_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04AFCA_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_line_sword_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0x10u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0x100;
	if ((int8_t)OBJECT(a0)->enemy_walk.target_direction < 0)
		OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	OBJECT(a0)->state++;
	move_object_blocked(a0);
}

void enemy_walk_to_line_sword_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;
	uint8_t move_time = 0;

	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
	move_time = OBJECT(a0)->enemy_walk.move_time;
	OBJECT(a0)->enemy_walk.move_time = move_time - 1u;
	if (move_time == 1u)
		OBJECT(a0)->enemy_walk.approach = 0u;
}

void enemy_walk_to_target_hammer(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B03E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_target_hammer_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 8u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04B046_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04B046_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_to_side_hammer(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B080_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_side_hammer_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xF0u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04B046_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04B046_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_to_side_far_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time--;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = OBJECT(a0)->enemy_walk.animations;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	if (OBJECT(a0)->enemy_walk.target_dx < 0x40u || (int8_t)(target_direction - 0x40u - OBJECT(a0)->enemy_walk.side) < 0)
	{
		OBJECT(a0)->y_speed = 0;
		OBJECT(a0)->x_speed = OBJECT(a0)->enemy_walk.speed;
		if ((int8_t)OBJECT(a0)->enemy_walk.side < 0)
			OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	else
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = OBJECT(a0)->enemy_walk.speed;
		if ((int8_t)OBJECT(a0)->enemy_walk.target_direction >= 0)
			OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	}
	if (OBJECT(a0)->enemy_walk.target_dy < 3u)
		OBJECT(a0)->state++;
	move_object_blocked(a0);
}

void enemy_walk_to_side_far_hold(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	enemy_walk_to_side_hold(a0, a1, p_d7, p_a5);
	if ((int8_t)OBJECT(a0)->state < 0)
		OBJECT(a0)->state = 1u;
}

void enemy_stalk_hammer(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B13A_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_stalk_hammer_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_stalk.move_time = 0xFFu;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_stalk.turns = 0u;
	OBJECT(a0)->enemy_stalk.time = 1u;
	target_direction = OBJECT(a0)->enemy_stalk.target_direction;
	*p_a5 = animations_04B046_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_stalk_hammer_approach(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	target_direction = OBJECT(a0)->enemy_stalk.target_direction;
	*p_a5 = animations_04B046_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	if (OBJECT(a0)->enemy_stalk.target_dx < 0x40u)
		OBJECT(a0)->state++;
	OBJECT(a0)->enemy_stalk.time = 1u;
	OBJECT(a0)->x_speed = 0x100;
	OBJECT(a0)->y_speed = 0;
	if ((int8_t)(OBJECT(a0)->enemy_stalk.target_direction - 0x40u) >= 0)
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	move_object_blocked(a0);
}

void enemy_stalk_hammer_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0, animation = 0;
	uint8_t time = 0;

	if (OBJECT(a0)->enemy_stalk.target_dx >= 0x50u)
	{
		OBJECT(a0)->state--;
		if ((OBJECT(a0)->enemy_stalk.turns & 1u) == 0u)
		{
			target_direction = OBJECT(a0)->enemy_stalk.target_direction;
			*p_a5 = animations_04B046_ADDRESS;
			a6 = mem_read32(a1);
			enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
			return;
		}
		return;
	}
	time = OBJECT(a0)->enemy_stalk.time;
	OBJECT(a0)->enemy_stalk.time = time - 1u;
	if (time != 1u)
	{
		if ((OBJECT(a0)->enemy_stalk.turns & 1u) != 0u)
		{
			target_direction = OBJECT(a0)->enemy_stalk.target_direction;
			*p_a5 = animations_04B046_ADDRESS;
			a6 = mem_read32(a1);
			enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
		}
		move_object_blocked(a0);
		return;
	}
	OBJECT(a0)->enemy_stalk.time = 0x30u;
	OBJECT(a0)->enemy_stalk.turns++;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	if ((OBJECT(a0)->enemy_stalk.turns & 1u) == 0u)
	{
		animation = 0x57BF2u;
		set_animation(0u, a0, animation);
		return;
	}
	OBJECT(a0)->y_speed = 0x100;
	if ((int8_t)OBJECT(a0)->enemy_stalk.target_direction >= 0)
		OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	target_direction = OBJECT(a0)->enemy_stalk.target_direction;
	*p_a5 = animations_04B046_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_away_hammer(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B244_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_away_hammer_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0x40u;
	OBJECT(a0)->state++;
	OBJECT(a0)->x_speed = 0x100;
	OBJECT(a0)->y_speed = 0;
	if ((int8_t)(OBJECT(a0)->enemy_walk.target_direction - 0x40u) < 0)
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04B046_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_away_hammer_walk(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0, animation = 0;
	uint8_t move_time = 0;

	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04B046_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
	move_time = OBJECT(a0)->enemy_walk.move_time;
	OBJECT(a0)->enemy_walk.move_time = move_time - 1u;
	if (move_time == 1u)
	{
		OBJECT(a0)->enemy_walk.move_time = 0xFFu;
		OBJECT(a0)->state++;
		animation = 0x57BF2u;
		set_animation(0u, a0, animation);
	}
}

void enemy_walk_away_hammer_wait(uint32_t a0, uint32_t a1)
{
	if (OBJECT(a0)->frame_time == 0u && mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		OBJECT(a0)->enemy_walk.move_time = 0u;
		OBJECT(a0)->enemy_walk.approach = 0u;
	}
}

void enemy_slash_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B2E6_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_slash_sword_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;

	animation = 0x55948u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x302u;
	d7 &= ~0xFFu;
	d7 = enemy_face_target(d7, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7;
}

void enemy_low_slash_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B322_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_low_slash_sword_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x5598Cu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x302u;
	d7_2 = (d7 & ~0xFFu) | 1u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

void enemy_leaping_slash_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B35E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_leaping_slash_sword_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x559C8u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x403u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

uint32_t enemy_leaping_slash_sword_leap(uint32_t d7, uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t a6 = 0, animation = 0, d1 = 0;
	uint16_t target_dx = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	a6 = 0x4B36Eu;
	d7 = enemy_start_arc(d7, a0, a6);
	target_dx = OBJECT(a0)->enemy.target_dx;
	d0 = (uint16_t)(target_dx - 0x10u);
	if (target_dx < 0x10u)
		d0 = 0u;
	d1 = 6u * d0;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		d1 = (uint16_t)(0u - d1);
	OBJECT(a0)->x_speed = d1;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	animation = 0x559DEu;
	set_animation(d1, a0, animation);
	return d7;
}

uint32_t enemy_leaping_slash_sword_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x4B36Eu;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x55A18u;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_jump_slash_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B436_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_jump_slash_sword_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x55824u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x303u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

uint32_t enemy_jump_slash_sword_leap(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	a6 = 0x4B446u;
	d7 = enemy_start_arc(d7, a0, a6);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	animation = 0x55878u;
	set_animation(0u, a0, animation);
	return d7;
}

uint32_t enemy_jump_slash_sword_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x4B446u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x55824u;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_flying_slash_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B4EC_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_flying_slash_sword_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x55824u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x503u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

uint32_t enemy_flying_slash_sword_leap(uint32_t d7, uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t a6 = 0, animation = 0, d1 = 0;
	uint16_t target_dx = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	a6 = 0x4B4FCu;
	d7 = enemy_start_arc(d7, a0, a6);
	target_dx = OBJECT(a0)->enemy.target_dx;
	d0 = (uint16_t)(target_dx - 0x10u);
	if (target_dx < 0x10u)
		d0 = 0u;
	d1 = (0x2AAu * d0) >> 8;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		d1 = (uint16_t)(0u - d1);
	OBJECT(a0)->x_speed = d1;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->unk_46 = 0x48u;
	OBJECT(a0)->state++;
	animation = 0x55830u;
	set_animation(d1, a0, animation);
	return d7;
}

uint32_t enemy_flying_slash_sword_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0, ignored = 0;
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->unk_46;
	OBJECT(a0)->unk_46 = t1 - 1u;
	if (t1 == 1u)
	{
		animation = 0x55840u;
		set_animation(0u, a0, animation);
	}
	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x4B4FCu;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x55852u;
	set_animation(ignored, a0, animation);
	return d7;
}

void enemy_smash_hammer(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B5E2_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_smash_hammer_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x57BFEu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x303u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	d7_2 = (d7_2 & ~0xFFu) | 8u;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->unk_46 = 0x3Au;
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

void enemy_smash_hammer_end(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->unk_46;
	OBJECT(a0)->unk_46 = t1 - 1u;
	if (t1 != 1u)
		return;
	enemy_back_to_thinking(a0);
}

void enemy_flinch_back_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B63E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_back_sword_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x558AAu;
	set_animation(0u, a0, animation);
}

void enemy_flinch_bent_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B662_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_bent_sword_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x558DEu;
	set_animation(0u, a0, animation);
}

void enemy_flinch_reel_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B686_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_reel_sword_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x55908u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_hunched_sword(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B6AA_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_hunched_sword_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x55932u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_back_hammer(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B6CE_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_back_hammer_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x57C62u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_bent_hammer(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B6F2_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_bent_hammer_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x57C96u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_hunched_hammer(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B6CE_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void unreached_04B716(uint32_t a0)
{
	uint32_t animation = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	animation = 0x57C96u;
	set_animation(0u, a0, animation);
}

/* Rodney's whip arm, whose grab holds a turtle */
void whip_arm_start(uint16_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	OBJECT(a0)->damage = 0u;
	OBJECT(a0)->depth = 4u;
	OBJECT(a0)->flags |= 0x86u;
	OBJECT(a0)->attack = 0x8Fu;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		OBJECT(a0)->attack &= 0x7Fu;
	OBJECT(a0)->routine++;
	OBJECT(a0)->unk_46 = 0u;
	OBJECT(a0)->unk_47 = 0u;
	whip_arm_follow(d0, a0, p_d7, p_a1);
}

/* the arm reaches out, is drawn in or put away as Rodney does it */
void whip_arm_follow(uint32_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a6 = 0, animation = 0, rodney = 0;

	rodney = OBJECT(a0)->whip_arm.rodney;
	if ((mem_read8(rodney + 0x4Au) & 0x80u) == 0u)
	{
		if ((mem_read8(rodney + 0x4Au) & 0x40u) == 0u)
		{
			if ((mem_read8(rodney + 0x4Au) & 0x20u) == 0u)
			{
				a6 = indexed_table_of_16_bit_values_04B776_ADDRESS;
				whip_arm_place(a0, rodney, a6, &d0, p_d7);
				a6 = animations_04B742_ADDRESS;
			}
			else
			{
				OBJECT(a0)->routine = 3u;
				OBJECT(a0)->flags &= ~0xEu;
				a6 = indexed_table_of_16_bit_values_04B7C4_ADDRESS;
				whip_arm_place(a0, rodney, a6, &d0, p_d7);
				a6 = animations_04B790_ADDRESS;
			}
		}
		else
		{
			OBJECT(a0)->flags &= ~0xEu;
			a6 = indexed_table_of_16_bit_values_04B776_ADDRESS;
			whip_arm_place(a0, rodney, a6, &d0, p_d7);
			a6 = animations_04B742_ADDRESS;
		}
		animation = DATA32(a6 + (uint16_t)(IN_PAGE(d0, mem_read8(rodney + 0x46u)) << 2));
		set_animation(0u, a0, animation);
	}
	else
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
	*p_a1 = rodney;
}

/* the turtle broke free of the arm */
void whip_arm_let_go(uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t rodney = 0;

	rodney = OBJECT(a0)->whip_arm.rodney;
	mem_write8(rodney + 0x4Au, mem_read8(rodney + 0x4Au) | 4u);
	OBJECT(a0)->routine = 1u;
	whip_arm_drag(a0, p_d7, p_a1);
}

/* the arm drags the turtle it caught */
void whip_arm_drag(uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t d1 = 0, rodney = 0, screen_y = 0, turtle = 0;

	rodney = OBJECT(a0)->whip_arm.rodney;
	*p_d7 = 0x60000u | OBJECT(a0)->hit_object;
	turtle = *p_d7;
	if (mem_read8(rodney + 4u) != 5u)
	{
		screen_y = OBJECT(a0)->screen_y;
		OBJECT(turtle)->y = (uint32_t)(uint16_t)(screen_y - 2u) << 8;
		d1 = rom_04B7DE[mem_read8(rodney + 0x46u)];
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
			d1 = (uint16_t)(0u - d1);
		OBJECT(turtle)->x = (uint32_t)(uint16_t)(d1 + OBJECT(a0)->screen_x) << 8;
	}
	else
	{
		OBJECT(turtle)->turtle.escape_presses = 0x10u;
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
	*p_a1 = rodney;
}

/* a turtle's attack hits the arm, which lets go of a turtle it holds */
void whip_arm_struck(uint32_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a6 = 0, animation = 0, rodney = 0, turtle = 0;

	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		*p_d7 = 0x60000u | OBJECT(a0)->hit_object;
		turtle = *p_d7;
		OBJECT(turtle)->turtle.escape_presses = 0x10u;
		rodney = OBJECT(a0)->whip_arm.rodney;
		mem_write8(rodney + 0x4Au, mem_read8(rodney + 0x4Au) | 4u);
	}
	OBJECT(a0)->flags &= ~0xEu;
	rodney = OBJECT(a0)->whip_arm.rodney;
	mem_write8(rodney + 0x4Au, mem_read8(rodney + 0x4Au) | 2u);
	OBJECT(a0)->routine = 1u;
	a6 = indexed_table_of_16_bit_values_04B776_ADDRESS;
	whip_arm_place(a0, rodney, a6, &d0, p_d7);
	a6 = animations_04B742_ADDRESS;
	animation = DATA32(a6 + (uint16_t)(IN_PAGE(d0, mem_read8(rodney + 0x46u)) << 2));
	set_animation(0u, a0, animation);
	*p_a1 = rodney;
}

/* the arm at Rodney's side, as long as Rodney stretches it */
void whip_arm_place(uint32_t a0, uint32_t a1, uint32_t a6, uint32_t *p_d0, uint32_t *p_d7)
{
	uint16_t d0 = (uint16_t)*p_d0;
	uint16_t d1 = 0;
	uint32_t turtle = 0;

	if (mem_read8(a1 + 4u) != 5u)
	{
		d0 = (uint16_t)((uint32_t)mem_read8(a1 + 0x46u) << 1);
		d1 = mem_read16(a6 + d0);
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
			d1 = (uint16_t)(0u - d1);
		OBJECT(a0)->x = (int16_t)d1 + mem_read32(a1 + 0x12u);
		OBJECT(a0)->y = mem_read32(a1 + 0x16u);
	}
	else
	{
		if ((OBJECT(a0)->flags & 8u) != 0u)
		{
			*p_d7 = 0x60000u | OBJECT(a0)->hit_object;
			turtle = *p_d7;
			OBJECT(turtle)->turtle.escape_presses = 0x10u;
		}
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
	*p_d0 = (*p_d0 & 0xFFFF0000u) | d0;
}

/* a laser bolt flies the way Rodney faces */
void laser_bolt_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->depth = 3u;
	OBJECT(a0)->flags |= 0x85u;
	OBJECT(a0)->damage = 0x201u;
	OBJECT(a0)->attack = 0x80u;
	OBJECT(a0)->x_speed = 0x800;
	OBJECT(a0)->y_speed = 0;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		OBJECT(a0)->attack = 0u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->routine++;
	animation = 0x58880u;
	set_animation(0u, a0, animation);
}

/* the bolt flies until it hits a turtle or leaves the screen */
void laser_bolt_fly(uint32_t a0)
{
	uint32_t animation = 0;

	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		return;
	}
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		OBJECT(a0)->routine++;
		animation = 0x58892u;
		set_animation(0u, a0, animation);
		return;
	}
	move_object(a0);
}

/* the bolt's burst ends and it is gone */
void laser_bolt_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

/* a thrown manhole cover rolls at the turtles, knocking them flying */
void rolling_manhole_cover_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x84u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->damage = 0x306u;
	OBJECT(a0)->depth = 6u;
	OBJECT(a0)->rolling.hit_sound = 0x44u;
	OBJECT(a0)->attack = 0x87u;
	OBJECT(a0)->x_speed = 0x400;
	OBJECT(a0)->y_speed = 0;
	if ((int8_t)OBJECT(a0)->parameter >= 0)
	{
		OBJECT(a0)->attack &= 0x7Fu;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->rolling.hit_delay = 0xAu;
	OBJECT(a0)->routine++;
	OBJECT(a0)->shadow = 0x2E928u;
	animation = 0x54F60u;
	set_animation(0u, a0, animation);
}

/* it rolls, and a turtle can hit it after a few frames */
void rolling_wait_hittable(uint32_t a0)
{
	uint8_t hit_delay = 0;

	hit_delay = OBJECT(a0)->rolling.hit_delay;
	OBJECT(a0)->rolling.hit_delay = hit_delay - 1u;
	if (hit_delay != 1u)
	{
		rolling_roll(a0);
		return;
	}
	OBJECT(a0)->routine++;
	OBJECT(a0)->flags |= 2u;
	rolling_roll(a0);
}

/* it rolls on until it leaves the screen */
void rolling_roll(uint32_t a0)
{
	uint8_t t1 = 0;

	if ((OBJECT(a0)->flags & 0x20u) == 0u)
	{
		move_object(a0);
		return;
	}
	t1 = enemies_on_screen - 1u;
	enemies_on_screen = t1;
	if ((int8_t)t1 < 0)
		enemies_on_screen = 0u;
	OBJECT(a0)->flags = 0u;
	OBJECT(a0)->contacts = 0u;
	move_object(a0);
}

/* a turtle's attack sends it rolling back the other way */
uint32_t rolling_struck(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x25u;
	if (OBJECT(a0)->kind != 0x19u)
		d7_2 = (d7_2 & ~0xFFu) | 0x41u;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->rolling.hit_delay = 0xAu;
	OBJECT(a0)->attack ^= 0x80u;
	OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	OBJECT(a0)->routine = 1u;
	return d7_2;
}

/* a thrown knife flies the way its thrower faces; on the skateboards it is carried along with the ride */
void knife_start(uint32_t a0)
{
	uint32_t animation = 0;

	if (area == 6u)
		OBJECT(a0)->x += 0x600u;
	OBJECT(a0)->damage = 0x202u;
	OBJECT(a0)->depth = 2u;
	OBJECT(a0)->flags |= 0x86u;
	OBJECT(a0)->attack = 0x80u;
	OBJECT(a0)->x_speed = 0x400;
	OBJECT(a0)->y_speed = 0;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		OBJECT(a0)->attack = 0u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->routine++;
	animation = 0x5711Au;
	set_animation(0u, a0, animation);
}

/* the knife flies until it hits a turtle or leaves the screen */
void knife_fly(uint32_t a0)
{
	uint32_t animation = 0;

	if (area == 6u)
		OBJECT(a0)->x += 0x600u;
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		return;
	}
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		OBJECT(a0)->flags &= ~0xEu;
		OBJECT(a0)->routine = 2u;
		animation = 0x5712Cu;
		set_animation(0u, a0, animation);
		return;
	}
	move_object(a0);
}

/* the knife's burst ends and it is gone */
void knife_vanish(uint32_t a0)
{
	if (area == 6u)
		OBJECT(a0)->x += 0x600u;
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

/* a turtle's attack knocks the knife away */
uint32_t knife_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x25u;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->flags &= ~0xEu;
	OBJECT(a0)->routine = 2u;
	animation = 0x5712Cu;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* a thrown spear flies the way its thrower faces */
void spear_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->damage = 0x303u;
	OBJECT(a0)->depth = 2u;
	OBJECT(a0)->flags |= 0x86u;
	OBJECT(a0)->attack = 0x80u;
	OBJECT(a0)->x_speed = 0x600;
	OBJECT(a0)->y_speed = 0;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		OBJECT(a0)->attack = 0u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->routine++;
	animation = 0x55DF4u;
	set_animation(0u, a0, animation);
}

/* the spear flies through what it hits until it leaves the screen */
void spear_fly(uint32_t a0)
{
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		return;
	}
	move_object(a0);
}

/* the broken spear is gone */
void spear_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

/* a turtle's attack breaks the spear */
uint32_t spear_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x25u;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->flags &= ~0xEu;
	OBJECT(a0)->routine = 2u;
	animation = 0x55E06u;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* a thrown axe flies spinning the way its thrower faces; it cannot be hit */
void axe_start(uint32_t a0)
{
	uint32_t animation = 0;

	if (area == 6u)
		OBJECT(a0)->x += 0x600u;
	OBJECT(a0)->damage = 0x301u;
	OBJECT(a0)->depth = 2u;
	OBJECT(a0)->flags |= 0x84u;
	OBJECT(a0)->attack = 0x80u;
	OBJECT(a0)->x_speed = 0x400;
	OBJECT(a0)->y_speed = 0;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		OBJECT(a0)->attack = 0u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->routine++;
	animation = 0x576F0u;
	set_animation(0u, a0, animation);
}

/* the axe flies through what it hits until it leaves the screen */
void axe_fly(uint32_t a0)
{
	if (area == 6u)
		OBJECT(a0)->x += 0x600u;
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		return;
	}
	move_object(a0);
}

/* a gun shot flies the way the soldier faces, dropping as it goes */
void gun_shot_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->damage = 0x301u;
	OBJECT(a0)->depth = 2u;
	OBJECT(a0)->flags |= 0x85u;
	OBJECT(a0)->attack = 0x80u;
	OBJECT(a0)->x_speed = 0x600;
	OBJECT(a0)->y_speed = 0;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		OBJECT(a0)->attack = 0u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->height_speed = -0x200;
	OBJECT(a0)->routine++;
	animation = 0x56B2Au;
	set_animation(0u, a0, animation);
	if (area == 6u)
		OBJECT(a0)->x += 0x600u;
}

/* the shot flies until it hits a turtle, the ground, or leaves the screen */
void gun_shot_fly(uint32_t a0)
{
	uint32_t animation = 0;

	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		if (area == 6u)
			OBJECT(a0)->x += 0x600u;
		return;
	}
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		OBJECT(a0)->flags &= ~0xEu;
		OBJECT(a0)->routine = 2u;
		animation = 0x56B5Cu;
		set_animation(0u, a0, animation);
		return;
	}
	if (OBJECT(a0)->height_whole == 0u)
	{
		OBJECT(a0)->flags &= ~0xEu;
		OBJECT(a0)->routine = 2u;
		animation = 0x56B3Cu;
		set_animation(0u, a0, animation);
		return;
	}
	move_object_with_height(a0);
	if (area == 6u)
		OBJECT(a0)->x += 0x600u;
}

/* the shot's burst ends and it is gone */
void gun_shot_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
	if (area == 6u)
		OBJECT(a0)->x += 0x600u;
}

/* the shot bursts; a turtle's attack can never strike it */
uint32_t gun_shot_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x25u;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->flags &= ~0xEu;
	OBJECT(a0)->routine = 2u;
	animation = 0x56B5Cu;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* a thrown boomerang flies out */
void boomerang_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x86u;
	OBJECT(a0)->damage = 0x201u;
	OBJECT(a0)->depth = 2u;
	OBJECT(a0)->attack = 0x80u;
	OBJECT(a0)->x_speed = 0x580;
	OBJECT(a0)->y_speed = 0;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		OBJECT(a0)->attack = 0u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->boomerang.flight_time = 0x20u;
	OBJECT(a0)->routine++;
	animation = 0x55B96u;
	set_animation(0u, a0, animation);
}

/* the boomerang flies out a while, then turns back */
void boomerang_fly_out(uint32_t a0)
{
	uint8_t flight_time = 0;

	flight_time = OBJECT(a0)->boomerang.flight_time;
	OBJECT(a0)->boomerang.flight_time = flight_time - 1u;
	if (flight_time == 1u)
	{
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		OBJECT(a0)->attack ^= 0x80u;
		OBJECT(a0)->boomerang.flight_time = 0x20u;
		OBJECT(a0)->routine++;
	}
	move_object(a0);
	if (mem_read8(OBJECT(a0)->boomerang.thrower + 4u) == 5u)
		OBJECT(a0)->routine = 3u;
}

/* the boomerang flies back a while and is gone */
void boomerang_fly_back(uint32_t a0)
{
	uint8_t flight_time = 0;

	if (mem_read8(OBJECT(a0)->boomerang.thrower + 4u) != 5u)
	{
		flight_time = OBJECT(a0)->boomerang.flight_time;
		OBJECT(a0)->boomerang.flight_time = flight_time - 1u;
		if (flight_time == 1u)
		{
			OBJECT(a0)->flags = 0u;
			OBJECT(a0)->contacts = 0u;
		}
	}
	else
		OBJECT(a0)->routine++;
	move_object(a0);
}

/* the boomerang's thrower was hit: it flies on off the screen */
void boomerang_fly_on(uint32_t a0)
{
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
	move_object(a0);
}

/* a turtle's attack breaks the boomerang */
uint32_t boomerang_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	OBJECT(a0)->routine++;
	d7_2 = (d7 & ~0xFFu) | 0x25u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = 0x55C2Cu;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the broken boomerang is gone */
void boomerang_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

/* a thrown shuriken flies the way its thrower faces */
void shuriken_start(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t flags = 0;

	OBJECT(a0)->flags |= 0x86u;
	OBJECT(a0)->damage = 0x301u;
	OBJECT(a0)->depth = 2u;
	OBJECT(a0)->attack = 0x80u;
	OBJECT(a0)->x_speed = 0x500;
	OBJECT(a0)->y_speed = 0;
	flags = OBJECT(a0)->flags;
	OBJECT(a0)->flags = flags & 0xBFu;
	if ((flags & 0x40u) == 0u)
	{
		OBJECT(a0)->attack = 0u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->routine++;
	animation = 0x55A62u;
	set_animation(0u, a0, animation);
}

/* the shuriken flies until it hits a turtle or leaves the screen */
void shuriken_fly(uint32_t a0)
{
	uint32_t animation = 0;

	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		return;
	}
	if ((OBJECT(a0)->flags & 8u) == 0u)
	{
		move_object(a0);
		return;
	}
	OBJECT(a0)->flags &= ~0xEu;
	OBJECT(a0)->routine++;
	animation = 0x55AA8u;
	set_animation(0u, a0, animation);
}

void unreached_04BF5A(uint32_t a0)
{
	uint32_t animation = 0;

	mem_write8(a0, mem_read8(a0) & ~0xEu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	animation = 0x55A9Eu;
	set_animation(0u, a0, animation);
}

/* the shuriken's burst ends and it is gone */
void shuriken_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

/* a turtle's attack knocks the shuriken away */
uint32_t shuriken_struck(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	OBJECT(a0)->routine--;
	d7_2 = (d7 & ~0xFFu) | 0x25u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = 0x55A9Eu;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* Rocksteady's bullet flies level, or up at a turtle in the air */
void rocksteady_bullet_start(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d5 = 0;
	uint32_t a6 = 0, animation = 0, d1 = 0, d6 = 0, ignored = 0;

	OBJECT(a0)->damage = 0x101u;
	OBJECT(a0)->depth = 2u;
	OBJECT(a0)->flags |= 0x85u;
	OBJECT(a0)->routine++;
	d5 = OBJECT(a0)->parameter;
	a6 = 0x4BFD4u;
	OBJECT(a0)->attack = 0x80u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		a6 = 0x4BFD2u;
		OBJECT(a0)->attack = 0u;
	}
	d0 = DATA8(a6 + d5);
	d1 = 0x600u;
	speeds_from_direction(d0, (uint16_t)d1, &d6, p_d7, &ignored);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->height_speed = *p_d7;
	OBJECT(a0)->y_speed = 0;
	d5 = (uint16_t)((uint32_t)d5 << 3);
	*p_a5 = animations_04BFD6_ADDRESS;
	animation = animations_04BFD6[d5 / 4u];
	OBJECT(a0)->rocksteady_bullet.burst = rom_04BFDA[d5 / 4u];
	set_animation(d1, a0, animation);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
}

/* the bullet flies until it hits a turtle or leaves the screen */
void rocksteady_bullet_fly(uint32_t a0)
{
	uint32_t burst = 0;

	if (OBJECT(a0)->height_whole >= 0xF8u || (OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		return;
	}
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		OBJECT(a0)->flags &= ~0xEu;
		OBJECT(a0)->routine = 2u;
		burst = OBJECT(a0)->rocksteady_bullet.burst;
		set_animation(0u, a0, burst);
		return;
	}
	move_object_with_height(a0);
}

/* the bullet's burst ends and it is gone */
void rocksteady_bullet_vanish(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

void unreached_04C086(uint32_t a0)
{
	uint8_t d7 = 0;
	uint32_t animation = 0;

	d7 = 0x25u;
	queue_sound(d7, 0u);
	mem_write8(a0, mem_read8(a0) & ~0xEu);
	mem_write8(a0 + 4u, 2u);
	animation = mem_read32(a0 + 0x24u);
	set_animation(0u, a0, animation);
}

/* Bebop's shot flies the way he faces */
void bebop_shot_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->damage = 0x401u;
	OBJECT(a0)->depth = 4u;
	OBJECT(a0)->flags |= 0x84u;
	OBJECT(a0)->attack = 0x80u;
	OBJECT(a0)->x_speed = 0x400;
	OBJECT(a0)->y_speed = 0;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		OBJECT(a0)->attack = 0u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->routine++;
	animation = 0x5A7CAu;
	set_animation(0u, a0, animation);
}

/* the shot flies through what it hits until it leaves the screen */
void bebop_shot_fly(uint32_t a0)
{
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		return;
	}
	move_object(a0);
}

/* a thrown tire rolls at the turtles, knocking them flying */
void rolling_tire_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x84u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->damage = 0x606u;
	OBJECT(a0)->depth = 0x12u;
	OBJECT(a0)->rolling.hit_sound = 0x44u;
	OBJECT(a0)->attack = 0x80u;
	OBJECT(a0)->x_speed = 0x400;
	OBJECT(a0)->y_speed = 0;
	if ((int8_t)OBJECT(a0)->parameter >= 0)
	{
		OBJECT(a0)->attack = 0u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->rolling.hit_delay = 0xAu;
	OBJECT(a0)->routine++;
	OBJECT(a0)->shadow = 0x2E928u;
	animation = 0x5C890u;
	set_animation(0u, a0, animation);
}

/* a piece of Shredder flies off */
void shredder_piece_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->shredder_piece.landings = 0xFFu;
	OBJECT(a0)->x_speed = 0x300;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0x100;
	OBJECT(a0)->routine++;
	animation = 0x5B5BEu;
	set_animation(0u, a0, animation);
}

/* the piece bounces lower and lower until it leaves the screen */
uint32_t shredder_piece_bounce(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;
	uint8_t t1 = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	enemy_landed(a0, &d7, &zero);
	if (zero)
	{
		OBJECT(a0)->height_speed = (int16_t)(0u - OBJECT(a0)->height_speed) >> 1;
		t1 = OBJECT(a0)->shredder_piece.landings + 1u;
		OBJECT(a0)->shredder_piece.landings = t1;
		if (t1 == 0u)
		{
			animation = 0x5B5C8u;
			set_animation(0u, a0, animation);
		}
	}
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
	return d7;
}

/* Shredder's ray */
void shredder_ray_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->damage = 0xA03u;
	OBJECT(a0)->flags |= 0x84u;
	OBJECT(a0)->attack = 0x98u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		OBJECT(a0)->attack &= 0x7Fu;
	OBJECT(a0)->shredder_ray.time_left = 0x3Cu;
	OBJECT(a0)->routine++;
	animation = animations_05C220_ADDRESS;
	set_animation(0u, a0, animation);
}

/* the ray lasts a second, less if Shredder is hit */
void shredder_ray_shine(uint32_t a0)
{
	uint8_t time_left = 0;

	if (mem_read8(OBJECT(a0)->shredder_ray.shredder + 4u) != 5u)
	{
		time_left = OBJECT(a0)->shredder_ray.time_left;
		OBJECT(a0)->shredder_ray.time_left = time_left - 1u;
		if (time_left == 1u)
		{
			OBJECT(a0)->flags = 0u;
			OBJECT(a0)->contacts = 0u;
		}
		return;
	}
	OBJECT(a0)->flags = 0u;
	OBJECT(a0)->contacts = 0u;
}

/* a rocket is fired the way the soldier faces, or dropped when the soldier is hit */
void rocket_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x84u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->damage = 0x102u;
	OBJECT(a0)->depth = 3u;
	OBJECT(a0)->rocket.hit_sound = 0x70u;
	OBJECT(a0)->x_speed = 0x400;
	if (OBJECT(a0)->parameter != 0u)
		OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->attack = 0x80u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		OBJECT(a0)->attack = 0u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0x200;
	OBJECT(a0)->routine++;
	OBJECT(a0)->shadow = 0x2E928u;
	animation = 0x5C95Au;
	set_animation(0u, a0, animation);
}

/* the rocket comes down and explodes */
uint32_t rocket_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x80u;
	enemy_landed(a0, &d7, &zero);
	if (zero)
	{
		d7 = (d7 & ~0xFFu) | 0x13u;
		queue_sound((uint8_t)d7, 0u);
		animation = rom_015258;
		set_animation(0u, a0, animation);
		OBJECT(a0)->damage = 0x303u;
		OBJECT(a0)->attack |= 7u;
		OBJECT(a0)->routine++;
	}
	return d7;
}

/* the explosion ends and the rocket is gone */
void rocket_explode(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

/* a stick of dynamite with its fuse burning */
void dynamite_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->damage = 0x206u;
	OBJECT(a0)->attack = 7u;
	OBJECT(a0)->flags |= 0x80u;
	animation = 0x5CB10u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->dynamite.hit_sound = 0x70u;
	OBJECT(a0)->dynamite.bounces_left = 3u;
	OBJECT(a0)->depth = 0u;
	OBJECT(a0)->routine++;
}

/* the dynamite is thrown at the nearest turtle */
void dynamite_throw(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t d0 = 0, d6 = 0, d7 = 0, ignored = 0;

	enemy_nearest_turtles(a0, p_d5, &ignored, p_a5, &a6);
	d0 = direction_to_object(0u, a0, a6);
	d1 = 0x100u;
	speeds_from_direction((uint8_t)d0, d1, &d6, &d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = d7;
	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->routine++;
	d7 = dynamite_bounce(d7, a0);
	*p_d7 = d7;
}

/* the dynamite bounces, flashing, and explodes on its last bounce */
uint32_t dynamite_bounce(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;
	uint8_t bounces_left = 0;

	OBJECT(a0)->colour = indexed_table_of_8_bit_values_04C3EE[(uint8_t)frame_count & 4u];
	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	enemy_landed(a0, &d7, &zero);
	if (zero)
	{
		OBJECT(a0)->height_speed = (int16_t)(0u - OBJECT(a0)->height_speed) >> 1;
		bounces_left = OBJECT(a0)->dynamite.bounces_left;
		OBJECT(a0)->dynamite.bounces_left = bounces_left - 1u;
		if (bounces_left == 1u)
		{
			d7 = (d7 & ~0xFFu) | 0x11u;
			queue_sound((uint8_t)d7, 0u);
			animation = animations_05CEEE_ADDRESS;
			set_animation(0u, a0, animation);
			OBJECT(a0)->colour = 0xFFu;
			OBJECT(a0)->flags |= 4u;
			OBJECT(a0)->routine++;
		}
	}
	return d7;
}

/* the explosion ends and the dynamite is gone */
void dynamite_explode(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

/* a closed door */
void kicked_door_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->routine++;
	animation = animations_04C410_ADDRESS;
	set_animation(0u, a0, animation);
}

/* on the screen, a Foot soldier kicks the door down */
uint32_t kicked_door_wait(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	if (OBJECT(a0)->screen_x >= 0x100u)
		return d7;
	OBJECT(a0)->routine++;
	d7_2 = (d7 & ~0xFFu) | 0xDu;
	queue_sound((uint8_t)d7_2, 0u);
	animation = 0x4C41Au;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* the door's pieces fly off */
void kicked_door_break(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t a5 = *p_a5;
	uint32_t zero = 0;
	uint16_t d6 = 0;
	uint32_t a5_2 = 0, animation = 0, d7_2 = 0, ignored = 0;
	uint16_t t1 = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	d6 = 3u;
	a5_2 = record_04C4C6_ADDRESS;
	do
	{
		start_object_from_record(a0, a5_2, &d7_2, &ignored, &zero);
		t1 = d6 - 1u;
		d6 = t1;
		a5_2 += 8u;
	} while (t1 != 0xFFFFu);
	OBJECT(a0)->routine++;
	animation = 0x4C444u;
	set_animation(0u, a0, animation);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_2 & 0xFFFFu);
	*p_a5 = a5_2;
}

/* the soldier who kicked the door goes on as a Foot soldier */
void kicked_door_become_foot_soldier(uint32_t a0)
{
	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->contacts = 0u;
	OBJECT(a0)->kind = 0u;
	OBJECT(a0)->parameter = 0u;
	OBJECT(a0)->routine = 0u;
	OBJECT(a0)->state = 0u;
}

/* a piece of the kicked door flies off */
void door_piece_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0_2 = 0;
	uint16_t d0 = 0, d1 = 0;
	uint32_t animation = 0, d6 = 0;

	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->contacts = 0u;
	d0 = (uint16_t)((uint32_t)(int8_t)OBJECT(a0)->parameter << 2);
	animation = TABLE32(animations_04C5D4, (uint32_t)(int16_t)d0);
	set_animation(0u, a0, animation);
	OBJECT(a0)->height_speed = mem_read16(0x4C5E6u + (int16_t)d0);
	d0_2 = (uint8_t)TABLE16(indexed_table_of_16_bit_values_04C5E4, (uint32_t)(int16_t)d0);
	d1 = 0x500u;
	speeds_from_direction(d0_2, d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->routine++;
}

/* the door's piece flies until it leaves the screen */
void door_piece_fly(uint32_t a0)
{
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
	move_object(a0);
}

/* an elevator with its doors closed */
void elevator_start(uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;

	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->contacts = 0u;
	a6 = 0x4C6E0u;
	if (OBJECT(a0)->parameter != 0u)
		a6 = 0x4C6E4u;
	OBJECT(a0)->elevator.stop = a6;
	OBJECT(a0)->routine++;
	animation = animations_04C65E_ADDRESS;
	set_animation(0u, a0, animation);
}

/* the elevator waits until the scroll brings it to its place */
uint32_t elevator_wait_on_screen(uint32_t a0)
{
	uint32_t stop = 0;

	stop = OBJECT(a0)->elevator.stop;
	if (OBJECT(a0)->screen_x <= mem_read16(stop))
	{
		OBJECT(a0)->elevator.wait = mem_read8(stop + 2u);
		OBJECT(a0)->routine++;
	}
	return stop;
}

/* the elevator's doors open and a Foot soldier comes out, two with three turtles or more in play */
void elevator_open(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a5 = *p_a5;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t a5_2 = 0, animation = 0, ignored = 0, ignored_3 = 0;
	uint8_t wait = 0;

	wait = OBJECT(a0)->elevator.wait;
	OBJECT(a0)->elevator.wait = wait - 1u;
	if (wait == 1u)
	{
		d7_2 = 0x36u;
		queue_sound(d7_2, 0u);
		animation = 0x4C668u;
		set_animation(0u, a0, animation);
		OBJECT(a0)->routine++;
		if (turtles_in_play < 3u)
		{
			a5 = 0x4C6D8u;
			start_object_from_record(a0, a5, &d7, &ignored, &zero);
		}
		else
		{
			a5_2 = record_04C6C8_ADDRESS;
			start_object_from_record(a0, a5_2, &ignored_3, &ignored, &zero);
			a5 = 0x4C6D0u;
			start_object_from_record(a0, a5, &d7, &ignored, &zero);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
	*p_a5 = a5;
}

/* the open elevator is gone once it leaves the screen */
void elevator_scroll_off(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u && (OBJECT(a0)->flags & 0x20u) != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
}

void enemy_step_out_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->unk_46 = 0x18u;
	OBJECT(a0)->state++;
	animation = animations_04C7B2_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_step_out_wait(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->unk_46;
	OBJECT(a0)->unk_46 = t1 - 1u;
	if (t1 != 1u)
		return;
	OBJECT(a0)->unk_46 = 0x20u;
	OBJECT(a0)->state++;
	animation = animations_04C7B2_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_step_out_walk(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->unk_46;
	OBJECT(a0)->unk_46 = t1 - 1u;
	if (t1 == 1u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy.move_time = 0u;
	}
	OBJECT(a0)->y -= 0x100u;
}

/* a tire with a Foot soldier behind it, counted as an enemy */
void tire_soldier_start(uint32_t a0)
{
	uint32_t animation = 0;

	enemies_on_screen++;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->tire_soldier.trigger_x = 0x168u;
	if ((OBJECT(a0)->parameter & 0x80u) != 0u)
	{
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->tire_soldier.trigger_x = 0xA0u;
	}
	OBJECT(a0)->routine++;
	OBJECT(a0)->shadow = 0x2E928u;
	animation = 0x5C890u;
	set_animation(0u, a0, animation);
}

/* the soldier comes up out of the tire */
void tire_soldier_wait(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->tire_soldier.trigger_x < OBJECT(a0)->screen_x)
		return;
	OBJECT(a0)->y -= 0x1000u;
	OBJECT(a0)->routine++;
	animation = animations_05C846_ADDRESS;
	set_animation(0u, a0, animation);
}

/* the soldier jumps */
void tire_soldier_jump(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0x80;
	if ((OBJECT(a0)->parameter & 0x40u) != 0u)
		OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->routine++;
}

/* the soldier's jump comes down until it lands */
uint32_t tire_soldier_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->routine++;
	OBJECT(a0)->contacts &= 0x7Fu;
	animation = 0x5C87Au;
	set_animation(0u, a0, animation);
	return d7;
}

/* the soldier throws the tire */
void tire_soldier_throw(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t animation = 0, object = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		d7_2 = 8u;
		queue_sound(d7_2, 0u);
		*p_a5 = 0x4C894u;
		start_object_from_record(a0, *p_a5, &d7, &object, &zero);
		if (zero)
			OBJECT(object)->parameter = OBJECT(a0)->parameter;
		OBJECT(a0)->routine++;
		animation = 0x54F36u;
		set_animation(0u, a0, animation);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* a manhole with a Foot soldier under its cover, counted as an enemy */
void manhole_soldier_start(uint32_t a0)
{
	uint32_t animation = 0;

	enemies_on_screen++;
	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->manhole_soldier.trigger_x = 0x160u;
	if ((OBJECT(a0)->parameter & 0x80u) != 0u)
	{
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->manhole_soldier.trigger_x = 0xA0u;
	}
	OBJECT(a0)->routine++;
	OBJECT(a0)->shadow = 0x2E928u;
	animation = 0x54F56u;
	set_animation(0u, a0, animation);
}

/* the soldier comes up out of the manhole holding its cover */
void manhole_soldier_wait(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->manhole_soldier.trigger_x < OBJECT(a0)->screen_x)
		return;
	OBJECT(a0)->y -= 0x1000u;
	OBJECT(a0)->routine++;
	animation = 0x54EECu;
	set_animation(0u, a0, animation);
}

/* the soldier jumps out and leaves the manhole open */
void manhole_soldier_jump_out(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t ignored = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->contacts |= 0x80u;
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = 0x80;
		if ((OBJECT(a0)->parameter & 0x40u) != 0u)
			OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
		OBJECT(a0)->height_speed = 0x400;
		OBJECT(a0)->routine++;
		*p_a5 = 0x4C9BEu;
		start_object_from_record(a0, *p_a5, &d7, &ignored, &zero);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* the soldier's jump comes down to the ground */
void manhole_soldier_fly(uint32_t a0)
{
	uint32_t animation = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	if ((int8_t)OBJECT(a0)->height_whole >= 0)
		return;
	OBJECT(a0)->height = 0u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->contacts &= 0x7Fu;
	animation = 0x54F20u;
	set_animation(0u, a0, animation);
}

/* the soldier throws the manhole cover */
void manhole_soldier_throw(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t animation = 0, object = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		d7_2 = 8u;
		queue_sound(d7_2, 0u);
		*p_a5 = 0x4C9B6u;
		start_object_from_record(a0, *p_a5, &d7, &object, &zero);
		if (zero)
			OBJECT(object)->parameter = OBJECT(a0)->parameter;
		OBJECT(a0)->routine++;
		animation = 0x54F36u;
		set_animation(0u, a0, animation);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* after its throw the soldier goes on as a Foot soldier */
void thrower_become_foot_soldier(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0x81u;
		OBJECT(a0)->contacts = 0u;
		OBJECT(a0)->kind = 0u;
		OBJECT(a0)->parameter = 0u;
		OBJECT(a0)->routine = 0u;
		OBJECT(a0)->state = 0u;
	}
}

/* a Foot soldier behind a window, waiting for its place on the screen */
uint32_t window_soldier_drop_start(uint32_t a0)
{
	uint32_t a5 = 0;
	uint32_t break_time_halfword = 0;

	a5 = object_tile_blocks_ADDRESS + (int16_t)TABLE16(object_tile_block_offsets, (uint32_t)(int16_t)((uint32_t)(int8_t)OBJECT(a0)->parameter << 1));
	OBJECT(a0)->window_soldier_drop.trigger_x = mem_read16(a5);
	a5 += 2u;
	break_time_halfword = mem_read16(a5);
	OBJECT(a0)->window_soldier_drop.break_time = (uint8_t)(break_time_halfword >> 8u);
	OBJECT(a0)->window_soldier_drop.delay = (uint8_t)break_time_halfword;
	a5 += 2u;
	OBJECT(a0)->window_soldier_drop.blocks = a5;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine++;
	return a5;
}

/* the soldier jumps out through the window and the glass shatters */
void window_soldier_drop_jump_out(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint32_t animation = 0, d7_2 = 0, ignored = 0;
	uint8_t delay = 0;

	if (OBJECT(a0)->window_soldier_drop.trigger_x < OBJECT(a0)->screen_x)
		return;
	delay = OBJECT(a0)->window_soldier_drop.delay;
	OBJECT(a0)->window_soldier_drop.delay = delay - 1u;
	if (delay != 1u)
		return;
	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->window_soldier_drop.break_time = 4u;
	*p_a5 = record_04CBAC_ADDRESS;
	start_object_from_record(a0, *p_a5, &d7_2, &ignored, &zero);
	OBJECT(a0)->routine++;
	animation = animations_04CAFE_ADDRESS;
	set_animation(0u, a0, animation);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_2 & 0xFFFFu);
}

/* the window is drawn broken */
void window_soldier_drop_break_window(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t a5 = *p_a5;
	uint32_t a6 = 0;
	uint8_t break_time = 0;

	break_time = OBJECT(a0)->window_soldier_drop.break_time;
	OBJECT(a0)->window_soldier_drop.break_time = break_time - 1u;
	if (break_time != 1u)
		window_soldier_drop_fall(a0);
	else
	{
		do
		{
			a5 = OBJECT(a0)->window_soldier_drop.blocks;
			a6 = mem_read32(a5);
			a5 += 4u;
			d7 = (uint16_t)(int8_t)mem_read8(a5);
			a5++;
			OBJECT(a0)->window_soldier_drop.break_time = mem_read8(a5);
			a5++;
			OBJECT(a0)->window_soldier_drop.blocks = a5;
			draw_tile_block(d7, a6);
		} while (OBJECT(a0)->window_soldier_drop.break_time != 0u);
		OBJECT(a0)->routine++;
		window_soldier_drop_fall(a0);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
	*p_a5 = a5;
}

/* the soldier comes down from the window until it lands */
void window_soldier_drop_fall(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->y -= 0x80u;
	OBJECT(a0)->height += OBJECT(a0)->height_speed;
	OBJECT(a0)->height_speed -= 0x40u;
	if (OBJECT(a0)->height_speed < -0x4000)
		OBJECT(a0)->height_speed = -0x400;
	if (OBJECT(a0)->height_whole < 0xF0u)
		return;
	OBJECT(a0)->height = 0u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->contacts &= 0x7Fu;
	animation = 0x4CB1Eu;
	set_animation(0u, a0, animation);
}

/* the soldier who came out of the window goes on as a Foot soldier */
void window_soldier_become_foot_soldier(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->kind = 0u;
		OBJECT(a0)->parameter = 0u;
		OBJECT(a0)->routine = 0u;
		OBJECT(a0)->state = 0u;
	}
}

/* a Foot soldier behind a window, waiting for its place on the screen */
void window_soldier_dive_start(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = object_tile_block_pairs_ADDRESS + (int16_t)((int8_t)OBJECT(a0)->parameter * 0xCu);
	OBJECT(a0)->window_soldier_dive.trigger_y = mem_read16(a6);
	OBJECT(a0)->window_soldier_dive.blocks = a6 + 2u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine++;
}

/* the window is drawn broken and the soldier dives out through the glass */
void window_soldier_dive_wait(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint16_t d7_2 = 0;
	uint32_t a6 = 0, animation = 0, blocks = 0, d7_3 = 0, ignored = 0;

	if ((int16_t)OBJECT(a0)->screen_y < (int16_t)OBJECT(a0)->window_soldier_dive.trigger_y)
		return;
	blocks = OBJECT(a0)->window_soldier_dive.blocks;
	d7_2 = (uint16_t)(int8_t)mem_read8(blocks);
	a6 = mem_read32(blocks + 2u);
	draw_tile_block(d7_2, a6);
	d7_2 = (uint16_t)(int8_t)mem_read8(blocks + 1u);
	a6 = mem_read32(blocks + 6u);
	draw_tile_block(d7_2, a6);
	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->routine++;
	*p_a5 = record_04CD3C_ADDRESS;
	start_object_from_record(a0, *p_a5, &d7_3, &ignored, &zero);
	animation = animations_04CD10_ADDRESS;
	set_animation(0u, a0, animation);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_3 & 0xFFFFu);
}

/* the soldier's dive comes down until it lands */
void window_soldier_dive_fall(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->x -= 0x280u;
	OBJECT(a0)->height += OBJECT(a0)->height_speed;
	OBJECT(a0)->height_speed -= 0x40u;
	if (OBJECT(a0)->height_speed < -0x4000)
		OBJECT(a0)->height_speed = -0x400;
	if (OBJECT(a0)->height_whole < 0xF0u)
		return;
	OBJECT(a0)->height = 0u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->contacts &= 0x7Fu;
	animation = 0x4CD26u;
	set_animation(0u, a0, animation);
}

/* a window's glass shatters into shards */
uint32_t glass_shards_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d0 = 0, d7_2 = 0;

	OBJECT(a0)->flags = 0x81u;
	animation = animations_04CE5A_ADDRESS;
	d0 = 0x80u;
	if ((int8_t)OBJECT(a0)->parameter < 0)
	{
		animation = 0x4CE7Au;
		d0 = 0xFF800000u;
	}
	OBJECT(a0)->x_speed = (uint16_t)(d0 >> 16u);
	OBJECT(a0)->y_speed = (uint16_t)d0;
	set_animation(0u, a0, animation);
	OBJECT(a0)->height_speed = 0;
	d7_2 = (d7 & ~0xFFu) | 0x40u;
	queue_sound((uint8_t)d7_2, animation);
	OBJECT(a0)->routine++;
	return d7_2;
}

/* the glass shards fall until they are gone */
void glass_shards_fall(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
	}
	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
}

void enemy_walk_in_on_ledge_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->x_speed = -0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->floor_height = 0x50u;
	OBJECT(a0)->state++;
	animation = animations_0547C6_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_walk_in_on_ledge_walk(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	move_object_blocked(a0);
	if (OBJECT(a0)->screen_x >= 0x120u)
		return;
	enemy_nearest_turtles(a0, p_d5, p_d7, p_a5, &a6);
	if (OBJECT(a6)->floor_height != 0x50u)
	{
		OBJECT(a0)->state++;
		animation = animations_04CF3E_ADDRESS;
		set_animation(0u, a0, animation);
		return;
	}
	OBJECT(a0)->enemy_walk.move_time = 0u;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
}

void enemy_jump_down_leap(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->height_speed = 0x200;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = -0x80;
	OBJECT(a0)->state++;
	OBJECT(a0)->contacts |= 0x80u;
	animation = 0x4CF5Eu;
	set_animation(0u, a0, animation);
}

uint32_t enemy_jump_down_fall_stairs(uint32_t d7, uint32_t a0)
{
	enemy_follow_stairs_down(a0);
	return enemy_jump_down_fall(d7, a0);
}

uint32_t enemy_jump_down_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	if (OBJECT(a0)->height_speed < -0x4000)
		OBJECT(a0)->height_speed = -0x400;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->state++;
	OBJECT(a0)->contacts &= 0x7Fu;
	animation = 0x4CB1Eu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_jump_down_land(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy.move_time = 0u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
	}
}

void enemy_step_down_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->state++;
	OBJECT(a0)->unk_46 = 0x10u;
	animation = 0x4C444u;
	set_animation(0u, a0, animation);
}

void enemy_step_down_wait(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->unk_46;
	OBJECT(a0)->unk_46 = t1 - 1u;
	if (t1 != 1u)
		return;
	OBJECT(a0)->state++;
	animation = animations_04CF3E_ADDRESS;
	set_animation(0u, a0, animation);
}

/* a ripple on the sewer's water, a Foot soldier under it, counted as an enemy */
void sewer_ripple_start(uint32_t a0)
{
	uint32_t animation = 0;

	enemies_on_screen++;
	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->x_speed = -0x80;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->sewer_ripple.swim_time = 0x5Au;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->routine++;
	animation = animations_04D0BC_ADDRESS;
	set_animation(0u, a0, animation);
}

/* the ripple moves back and forth, then splashes */
uint32_t sewer_ripple_swim(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;
	uint8_t swim_time = 0, t1 = 0;

	if (OBJECT(a0)->screen_x >= 0xA0u)
	{
		if (OBJECT(a0)->screen_x >= 0x160u)
			OBJECT(a0)->x_speed = -0x80;
	}
	else
		OBJECT(a0)->x_speed = 0x80;
	move_object(a0);
	if ((OBJECT(a0)->flags & 0x20u) == 0u)
	{
		swim_time = OBJECT(a0)->sewer_ripple.swim_time;
		OBJECT(a0)->sewer_ripple.swim_time = swim_time - 1u;
		if (swim_time != 1u)
			return d7;
		OBJECT(a0)->routine++;
		d7_2 = (d7 & ~0xFFu) | 0xEu;
		queue_sound((uint8_t)d7_2, 0u);
		animation = 0x4D0D6u;
		set_animation(0u, a0, animation);
		return d7_2;
	}
	OBJECT(a0)->flags = 0u;
	OBJECT(a0)->contacts = 0u;
	t1 = enemies_on_screen - 1u;
	enemies_on_screen = t1;
	if ((int8_t)t1 < 0)
		enemies_on_screen = 0u;
	return d7;
}

/* the soldier leaps out of the water */
void sewer_ripple_leap_out(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t animation = 0, object = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		animation = 0x4D100u;
		set_animation(0u, a0, animation);
		*p_a5 = record_04D1A6_ADDRESS;
		start_object_from_record(a0, *p_a5, &d7, &object, &zero);
		if (zero == 0u)
			OBJECT(a0)->routine += 2u;
		else
		{
			OBJECT(object)->flags = OBJECT(a0)->flags;
			OBJECT(object)->flags &= 0x41u;
			OBJECT(a0)->routine++;
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* the splash ends and the ripple is gone */
void sewer_ripple_vanish(uint32_t a0)
{
	uint8_t t1 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
			enemies_on_screen = 0u;
	}
}

/* no room for the soldier: the ripple swims on */
void sewer_ripple_swim_again(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->routine = 1u;
	OBJECT(a0)->sewer_ripple.swim_time = 0x5Au;
	animation = animations_04D0BC_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_leap_out_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0x600;
	OBJECT(a0)->state++;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->contacts |= 0x80u;
	animation = 0x54ADAu;
	set_animation(0u, a0, animation);
}

uint32_t enemy_leap_out_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	OBJECT(a0)->floor_height = 0u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->state++;
	OBJECT(a0)->contacts &= 0x7Fu;
	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_leap_out_land(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy.move_time = 0u;
	}
}

/* a Foot soldier behind cover with a stick of dynamite */
void bomber_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t d6 = 0;

	d0 = 0x10u;
	d1 = 0x180u;
	speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->routine++;
}

/* on the screen, the soldier leans out */
void bomber_wait(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->screen_x >= 0x160u)
		return;
	OBJECT(a0)->bomber.timer = 0x4Au;
	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->routine++;
	animation = animations_04D35C_ADDRESS;
	set_animation(0u, a0, animation);
}

/* the soldier gets ready to throw */
void bomber_lean_out(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->bomber.timer;
	OBJECT(a0)->bomber.timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(a0)->routine++;
	OBJECT(a0)->bomber.timer = 0x48u;
	animation = animations_05CA64_ADDRESS;
	set_animation(0u, a0, animation);
}

/* the soldier throws the dynamite, then steps out */
void bomber_throw(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t animation = 0, ignored = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->bomber.timer;
	OBJECT(a0)->bomber.timer = timer - 1u;
	if (timer == 1u)
	{
		*p_a5 = record_04D466_ADDRESS;
		start_shot(a0, *p_a5, &d7, &ignored, &zero);
	}
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine++;
		animation = 0x4D3A8u;
		set_animation(0u, a0, animation);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* the soldier turns and walks out */
void bomber_step_out(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->x += 0x1000u;
	OBJECT(a0)->bomber.timer = 0x1Eu;
	OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->routine++;
	animation = 0x547F8u;
	set_animation(0u, a0, animation);
}

/* the soldier walks in and goes on as a Foot soldier */
void bomber_walk_in(uint32_t a0)
{
	uint8_t timer = 0;

	move_object(a0);
	timer = OBJECT(a0)->bomber.timer;
	OBJECT(a0)->bomber.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->kind = 0u;
		OBJECT(a0)->parameter = 0u;
		OBJECT(a0)->routine = 0u;
		OBJECT(a0)->state = 0u;
	}
}

void enemy_rocket_soldier_start(uint32_t a0)
{
	uint32_t animation = 0;

	enemies_on_screen++;
	OBJECT(a0)->flags |= 0x82u;
	animation = animations_05C92A_ADDRESS;
	set_animation(0u, a0, animation);
	OBJECT(a0)->x_speed = -0x40;
	OBJECT(a0)->enemy_rocket_soldier.aim_time = 1u;
	OBJECT(a0)->routine++;
}

void enemy_rocket_soldier_line_up(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, animation = 0, ignored = 0, ignored_2 = 0;
	uint8_t aim_time = 0;

	a6 = OBJECT(a0)->enemy_rocket_soldier.turtle;
	aim_time = OBJECT(a0)->enemy_rocket_soldier.aim_time;
	OBJECT(a0)->enemy_rocket_soldier.aim_time = aim_time - 1u;
	if (aim_time == 1u)
	{
		OBJECT(a0)->enemy_rocket_soldier.aim_time = 8u;
		enemy_nearest_turtles(a0, p_d5, p_d7, p_a5, &a6);
		OBJECT(a0)->enemy_rocket_soldier.turtle = a6;
	}
	enemy_look_at_target(a0, a6, &ignored, &ignored_2);
	OBJECT(a0)->y_speed = 0x80;
	if ((int8_t)OBJECT(a0)->enemy_rocket_soldier.target_direction >= 0)
		OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	move_object_blocked(a0);
	if (OBJECT(a0)->screen_x < 0x170u && OBJECT(a0)->enemy_rocket_soldier.target_dy < 0x10u)
	{
		OBJECT(a0)->routine++;
		animation = 0x5C944u;
		set_animation(ignored, a0, animation);
	}
}

void enemy_rocket_soldier_fire(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t animation = 0, d7_3 = 0, ignored = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->flags &= ~2u;
	d7_2 = 8u;
	queue_sound(d7_2, 0u);
	*p_a5 = 0x4D558u;
	start_shot(a0, *p_a5, &d7_3, &ignored, &zero);
	OBJECT(a0)->routine++;
	animation = 0x54F36u;
	set_animation(0u, a0, animation);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_3 & 0xFFFFu);
}

void enemy_rocket_soldier_unarmed(uint32_t a0)
{
	uint8_t t1 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0x81u;
		OBJECT(a0)->contacts = 0u;
		OBJECT(a0)->kind = 0u;
		OBJECT(a0)->parameter = 0u;
		OBJECT(a0)->routine = 0u;
		OBJECT(a0)->state = 0u;
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
			enemies_on_screen = 0u;
	}
}

void enemy_rocket_soldier_struck(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t zero = 0;
	uint32_t ignored = 0, object = 0;
	uint8_t t1 = 0;

	*p_a5 = 0x4D55Eu;
	start_shot(a0, *p_a5, &ignored, &object, &zero);
	if (zero)
		OBJECT(object)->parameter = 1u;
	t1 = enemies_on_screen - 1u;
	enemies_on_screen = t1;
	if ((int8_t)t1 < 0)
		enemies_on_screen = 0u;
	enemy_foot_soldier_start(a0, object, p_d5, &ignored, p_a5);
	OBJECT(a0)->kind = 0u;
	OBJECT(a0)->parameter = 0u;
	OBJECT(a0)->routine = 4u;
	OBJECT(a0)->state = 0u;
	if ((int8_t)mem_read8(OBJECT(a0)->enemy_rocket_soldier.definition + 0x58u + (OBJECT(a0)->hit & 0x7Fu)) < 0)
	{
		OBJECT(a0)->health_bars = 0u;
		OBJECT(a0)->health = 0u;
	}
	enemy_hit(a0, p_d5, p_d7, p_a1, p_a5);
}

/* two closed doors */
void double_door_start(uint32_t a0)
{
	OBJECT(a0)->routine++;
}

/* the doors swing open and two Foot soldiers come out */
void double_door_wait(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint16_t d7_3 = 0;
	uint32_t a5 = 0, a6 = 0, animation = 0, ignored = 0, ignored_3 = 0;

	if (OBJECT(a0)->screen_x < 0x100u)
	{
		OBJECT(a0)->flags |= 0x80u;
		animation = animations_05CDA0_ADDRESS;
		set_animation(0u, a0, animation);
		d7_2 = 0x3Fu;
		queue_sound(d7_2, animation);
		d7_3 = 0x22u;
		a6 = 0x1904Au;
		draw_tile_block(d7_3, a6);
		OBJECT(a0)->routine++;
		a5 = 0x4D6B8u;
		start_object_from_record(a0, a5, &ignored, &ignored_3, &zero);
		*p_a5 = 0x4D6C0u;
		start_object_from_record(a0, *p_a5, &d7, &ignored_3, &zero);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* the open doorway stays in the layer and the doors are gone */
uint32_t double_door_open(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	OBJECT(a0)->flags = 0u;
	OBJECT(a0)->contacts = 0u;
	d7_2 = (d7 & ~0xFFFFu) | 0x23u;
	a6 = 0x19100u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x24u;
	a6 = 0x19152u;
	draw_tile_block((uint16_t)d7_2, a6);
	return d7_2;
}

/* a closed door of the Technodrome */
void technodrome_door_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->routine++;
	animation = animations_05CE9E_ADDRESS;
	set_animation(0u, a0, animation);
}

/* on the screen, the door opens and the first Foot soldier comes out */
void technodrome_door_wait(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint16_t d7_3 = 0;
	uint32_t animation = 0, d7_2 = 0, ignored = 0;

	if (OBJECT(a0)->screen_x >= 0x140u)
		return;
	OBJECT(a0)->routine++;
	*p_a5 = 0x4D75Cu;
	start_object_from_record(a0, *p_a5, &d7_2, &ignored, &zero);
	d7_3 = (uint16_t)((d7_2 & ~0xFFu) | 0x36u);
	queue_sound((uint8_t)d7_3, ignored);
	OBJECT(a0)->technodrome_door.spawn_time = 0x18u;
	OBJECT(a0)->technodrome_door.soldiers_left = rom_04D764[difficulty & 7u];
	animation = 0x5CEA8u;
	set_animation(0u, a0, animation);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_3;
}

/* the door is open */
void technodrome_door_open(uint32_t a0)
{
	OBJECT(a0)->technodrome_door.spawn_time--;
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags &= 0x7Fu;
		OBJECT(a0)->routine++;
	}
}

/* more Foot soldiers come out, as many as the players' setting gives */
void technodrome_door_let_out(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t ignored = 0;
	uint8_t spawn_time = 0, soldiers_left = 0;

	spawn_time = OBJECT(a0)->technodrome_door.spawn_time;
	OBJECT(a0)->technodrome_door.spawn_time = spawn_time - 1u;
	if (spawn_time == 1u)
	{
		OBJECT(a0)->technodrome_door.spawn_time = 0x18u;
		*p_a5 = 0x4D75Cu;
		start_object_from_record(a0, *p_a5, &d7, &ignored, &zero);
		soldiers_left = OBJECT(a0)->technodrome_door.soldiers_left;
		OBJECT(a0)->technodrome_door.soldiers_left = soldiers_left - 1u;
		if (soldiers_left == 1u)
		{
			OBJECT(a0)->flags = 0u;
			OBJECT(a0)->contacts = 0u;
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void enemy_hang_in_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->state++;
	OBJECT(a0)->unk_46 = 0x60u;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->x_speed = -0x100;
	OBJECT(a0)->y_speed = 0;
	if ((uint8_t)(OBJECT(a0)->screen_x >> 8u) == 0u)
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	animation = animations_05C52C_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_hang_in_move(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t t1 = 0;

	move_object(a0);
	t1 = OBJECT(a0)->unk_46;
	OBJECT(a0)->unk_46 = t1 - 1u;
	if (t1 != 1u)
		return;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->state++;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->height_speed = 0;
	OBJECT(a0)->x_speed = 0;
	animation = 0x4CF68u;
	set_animation(0u, a0, animation);
}

uint32_t enemy_hang_in_drop(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	OBJECT(a0)->floor_height = 0u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->state++;
	animation = 0x4CB1Eu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_hang_in_land(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy.move_time = 0u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
	}
}

void enemy_kick_in_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0xC2u;
	OBJECT(a0)->x_speed = 0x300;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->flags |= 0x40u;
	if ((uint8_t)(OBJECT(a0)->screen_x >> 8u) != 0u)
	{
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		OBJECT(a0)->flags &= 0xBFu;
	}
	OBJECT(a0)->state++;
	OBJECT(a0)->unk_46 = 0x28u;
	animation = 0x54A78u;
	set_animation(0u, a0, animation);
}

void enemy_kick_in_run(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->unk_46;
	OBJECT(a0)->unk_46 = t1 - 1u;
	if (t1 != 1u)
	{
		move_object_blocked(a0);
		return;
	}
	OBJECT(a0)->state++;
	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
}

uint32_t enemy_kick_in_leap(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	a6 = 0x4D8D4u;
	d7 = enemy_start_arc(d7, a0, a6);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	animation = 0x54B1Cu;
	set_animation(0u, a0, animation);
	return d7;
}

uint32_t enemy_kick_in_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	move_object_with_height_blocked(a0);
	a6 = 0x4D8D4u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->flags &= ~4u;
	OBJECT(a0)->state++;
	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_kick_in_land(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy.move_time = 0u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
	}
}

void enemy_run_in_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->unk_46 = 0x7Eu;
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->x_speed = 0x180;
	OBJECT(a0)->y_speed = 0;
	if ((uint8_t)(OBJECT(a0)->screen_x >> 8u) != 0u)
	{
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		OBJECT(a0)->flags |= 0x40u;
	}
	OBJECT(a0)->state++;
	animation = 0x54908u;
	set_animation(0u, a0, animation);
}

void enemy_run_in_run(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->unk_46;
	OBJECT(a0)->unk_46 = t1 - 1u;
	if (t1 == 1u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
	}
	move_object_blocked(a0);
}

void enemy_dive_in_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->x_speed = -0x300;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->state++;
	OBJECT(a0)->unk_46 = 0x20u;
	OBJECT(a0)->floor_height = 0x50u;
	animation = 0x54A78u;
	set_animation(0u, a0, animation);
}

void enemy_dive_in_run(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->screen_x >= 0x120u)
	{
		move_object_blocked(a0);
		return;
	}
	enemy_nearest_turtles(a0, p_d5, p_d7, p_a5, &a6);
	if (OBJECT(a6)->floor_height == 0x50u)
	{
		OBJECT(a0)->enemy.move_time = 0u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
	}
	OBJECT(a0)->state++;
	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
}

void enemy_dive_in_leap(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->x_speed = -0x80;
	OBJECT(a0)->y_speed = -0x80;
	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->unk_46 = 0xCu;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	animation = 0x54ADAu;
	set_animation(0u, a0, animation);
}

void enemy_dive_in_dive(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->unk_46;
	OBJECT(a0)->unk_46 = t1 - 1u;
	if (t1 == 1u)
	{
		OBJECT(a0)->state++;
		animation = animations_05C566_ADDRESS;
		set_animation(0u, a0, animation);
	}
	enemy_follow_stairs_down(a0);
	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x38u;
}

void enemy_dive_in_curl(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->state++;
		OBJECT(a0)->unk_46 = 0x14u;
		OBJECT(a0)->animation_delay = 2u;
		animation = 0x54AEEu;
		set_animation(0u, a0, animation);
	}
	enemy_follow_stairs_down(a0);
	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x38u;
}

void enemy_dive_in_uncurl(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->unk_46;
	OBJECT(a0)->unk_46 = t1 - 1u;
	if (t1 == 1u)
	{
		OBJECT(a0)->state++;
		OBJECT(a0)->animation_delay = 0u;
		animation = 0x54AE4u;
		set_animation(0u, a0, animation);
	}
	enemy_follow_stairs_down(a0);
	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x38u;
}

uint32_t enemy_dive_in_land(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	enemy_follow_stairs_down(a0);
	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x38u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x54ACEu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_walk_in_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x81u;
	OBJECT(a0)->x_speed = -0x140;
	if ((uint8_t)(OBJECT(a0)->screen_x >> 8u) != 0u)
	{
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->enemy_walk.animations = (OBJECT(a0)->enemy_walk.animations & 0xFFFFFFu) | 0x1A000000u;
	OBJECT(a0)->state++;
	animation = animations_0547C6_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_walk_in_walk(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t t1 = 0;

	move_object_blocked(a0);
	t1 = (uint8_t)(OBJECT(a0)->enemy_walk.animations >> 24u);
	OBJECT(a0)->enemy_walk.animations = (OBJECT(a0)->enemy_walk.animations & 0xFFFFFFu) | ((t1 - 1u & 0xFFu) << 24u);
	if (t1 != 1u)
		return;
	OBJECT(a0)->enemy_walk.animations = (OBJECT(a0)->enemy_walk.animations & 0xFFFFFFu) | 0x30000000u;
	OBJECT(a0)->state++;
	animation = animations_05C5A4_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_walk_in_ready(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = (uint8_t)(OBJECT(a0)->enemy_walk.animations >> 24u);
	OBJECT(a0)->enemy_walk.animations = (OBJECT(a0)->enemy_walk.animations & 0xFFFFFFu) | ((t1 - 1u & 0xFFu) << 24u);
	if (t1 == 1u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_walk.move_time = 0u;
	}
}

/* a Foot soldier with knives: its definition, colour, bars and first move by its parameter */
void enemy_knife_soldier_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy.target = a6;
	OBJECT(a0)->enemy.retarget_time = 0x10u;
	OBJECT(a0)->enemy.move_time = 0u;
	OBJECT(a0)->enemy.approach = 0u;
	OBJECT(a0)->enemy.dodge_chance = 5u;
	OBJECT(a0)->depth = 4u;
	enemies_on_screen++;
	OBJECT(a0)->throw = 0x87u;
	OBJECT(a0)->colour = 7u;
	OBJECT(a0)->floor_height = 0u;
	enemy_set_floor(a0);
	OBJECT(a0)->health_bars = 3u;
	OBJECT(a0)->health = 6u;
	OBJECT(a0)->enemy.definition = 0x54096u;
	OBJECT(a0)->enemy.move = (OBJECT(a0)->parameter & 0xF0u) << 2;
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine += 2u;
	animation = animations_056F42_ADDRESS;
	set_animation(0u, a0, animation);
}

/* a Foot soldier with a spear, and the hits it lands before it throws the spear */
void enemy_spear_soldier_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy_spear.target = a6;
	OBJECT(a0)->enemy_spear.retarget_time = 0x10u;
	OBJECT(a0)->enemy_spear.move_time = 0u;
	OBJECT(a0)->enemy_spear.approach = 0u;
	OBJECT(a0)->enemy_spear.dodge_chance = 5u;
	OBJECT(a0)->depth = 4u;
	enemies_on_screen++;
	OBJECT(a0)->throw = 0x84u;
	OBJECT(a0)->colour = 4u;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->enemy_spear.hits_left = indexed_table_of_8_bit_values_04DD2C[difficulty & 7u];
	OBJECT(a0)->health_bars = 3u;
	OBJECT(a0)->health = 6u;
	OBJECT(a0)->enemy_spear.definition = 0x5411Eu;
	OBJECT(a0)->enemy_spear.move = (OBJECT(a0)->parameter & 0xF0u) << 2;
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine += 2u;
	animation = 0x55C60u;
	set_animation(0u, a0, animation);
}

/* walks to its turtle with the spear */
void enemy_walk_to_target_spear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DD40_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_target_spear_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 8u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04DD48_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* walks to its side of its turtle with the spear */
void enemy_walk_to_side_spear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DD82_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_side_spear_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xF0u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04DD48_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04DD48_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* keeps off its turtle's line, crossing the screen */
void enemy_walk_off_line_spear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DDC0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_off_line_spear_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xB4u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	if ((int8_t)(OBJECT(a0)->enemy_walk.target_direction - 0x40u) >= 0)
		OBJECT(a0)->enemy_walk.speed = 0u - OBJECT(a0)->enemy_walk.speed;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_walk_off_line_spear_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time--;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04DD48_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	if (OBJECT(a0)->enemy_walk.target_dy >= 0x20u)
	{
		OBJECT(a0)->y_speed = 0;
		OBJECT(a0)->x_speed = OBJECT(a0)->enemy_walk.speed;
		if (OBJECT(a0)->enemy_walk.target_dx >= 0x40u)
		{
			OBJECT(a0)->enemy_walk.speed = 0x100u;
			if ((int8_t)(OBJECT(a0)->enemy_walk.target_direction - 0x40u) >= 0)
				OBJECT(a0)->enemy_walk.speed = 0u - OBJECT(a0)->enemy_walk.speed;
		}
	}
	else
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = 0x100;
		if ((int8_t)OBJECT(a0)->enemy_walk.target_direction < 0)
			OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	}
	move_object_blocked(a0);
}

/* walks away, crouches and waits while its turtle is down */
void enemy_back_off_spear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DE6C_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_back_off_spear_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_back_off.move_time = 0xFFu;
	OBJECT(a0)->enemy_back_off.time = 0x20u;
	OBJECT(a0)->x_speed = 0x100;
	OBJECT(a0)->y_speed = 0;
	if ((int8_t)(OBJECT(a0)->enemy_back_off.target_direction - 0x40u) < 0)
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	target_direction = OBJECT(a0)->enemy_back_off.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_back_off_spear_walk(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0, animation = 0;
	uint8_t time = 0;

	target_direction = OBJECT(a0)->enemy_back_off.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	time = OBJECT(a0)->enemy_back_off.time;
	OBJECT(a0)->enemy_back_off.time = time - 1u;
	if (time != 1u)
	{
		move_object_blocked(a0);
		return;
	}
	OBJECT(a0)->state++;
	animation = 0x55D62u;
	set_animation(0u, a0, animation);
}

/* steps up or down out of the way of its turtle's attack */
void enemy_step_aside_spear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DEEE_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_step_aside_spear_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0, target_direction = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d6 = 0, ignored = 0;

	OBJECT(a0)->enemy.move_time = 0x10u;
	OBJECT(a0)->state++;
	d0 = 0x60u;
	if ((int8_t)OBJECT(a0)->enemy.target_direction >= 0)
		d0 = (uint8_t)(0u - d0);
	if ((int8_t)(OBJECT(a0)->enemy.target_direction - 0x40u) < 0)
		d0 ^= 0x40u;
	d1 = 0x100u;
	speeds_from_direction(d0, d1, &d6, p_d7, &ignored);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	target_direction = OBJECT(a0)->enemy.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_step_aside_spear_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy.move_time;
	OBJECT(a0)->enemy.move_time = move_time - 1u;
	if (move_time == 1u)
		OBJECT(a0)->enemy.approach = 0u;
	target_direction = OBJECT(a0)->enemy.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

/* walks to its turtle with the knife */
void enemy_walk_to_target_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DF70_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_target_knife_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 8u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x140u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04DF78_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04DF78_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* walks to its side of its turtle with the knife */
void enemy_walk_to_side_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DFB2_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_side_knife_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xF0u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x140u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04DF78_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* runs round its turtle with the knife */
void enemy_circle_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DFF0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_circle_knife_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d0 = 0, ignored = 0;

	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_circle.move_time = 0xB4u;
	a6 = animations_04DFF8_ADDRESS;
	enemy_face_target_animation(a0, a6, &d0, &ignored);
	OBJECT(a0)->enemy_circle.clockwise = 0u;
	if ((int8_t)(uint8_t)(random_seed >> 8u) >= 0)
	{
		enemy_circle_knife_aim((uint8_t)d0, a0, p_d7, p_a5);
		return;
	}
	OBJECT(a0)->enemy_circle.clockwise = 1u;
	enemy_circle_knife_aim((uint8_t)d0, a0, p_d7, p_a5);
}

void enemy_circle_knife_aim(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t d6 = 0;

	if (OBJECT(a0)->enemy_circle.clockwise != 0u)
		d0 += 0x50u;
	else
		d0 -= 0x30u;
	d1 = 0x140u;
	speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
}

void enemy_circle_knife_step(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	OBJECT(a0)->enemy_circle.move_time--;
	d7_2 = (d7 & ~0xFFu) | OBJECT(a0)->contacts;
	t1 = d7_2 & 0x1Eu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 != 0u)
	{
		OBJECT(a0)->enemy_circle.clockwise ^= 1u;
		a6 = animations_04DFF8_ADDRESS;
		enemy_face_target_animation(a0, a6, &d0, &ignored);
		enemy_circle_knife_aim((uint8_t)d0, a0, &d7_2, p_a5);
		move_object_blocked(a0);
		*p_d7 = d7_2;
		return;
	}
	if (OBJECT(a0)->enemy_circle.target_direction != OBJECT(a0)->enemy_circle.facing)
	{
		a6 = animations_04DFF8_ADDRESS;
		enemy_face_target_animation(a0, a6, &d0, &ignored);
		enemy_circle_knife_aim((uint8_t)d0, a0, &d7_2, p_a5);
	}
	move_object_blocked(a0);
	*p_d7 = d7_2;
}

/* keeps its distance from its turtle with the knife */
void enemy_keep_distance_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E0B4_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_keep_distance_knife_start(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, ignored = 0;

	OBJECT(a0)->enemy.move_time = 0xFFu;
	OBJECT(a0)->state++;
	a6 = animations_04DFF8_ADDRESS;
	enemy_face_target_animation(a0, a6, &ignored, &d7);
	OBJECT(a0)->frame_time = 0u;
	return d7;
}

void enemy_keep_distance_knife_watch(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a5 = 0, a6 = 0, d6 = 0, ignored = 0;

	OBJECT(a0)->enemy.move_time--;
	if (OBJECT(a0)->enemy.target_direction != OBJECT(a0)->enemy.facing)
	{
		a6 = animations_04DFF8_ADDRESS;
		enemy_face_target_animation(a0, a6, &ignored, p_d7);
		OBJECT(a0)->frame_time = 0u;
	}
	if (OBJECT(a0)->enemy.target_dx < 0x50u && OBJECT(a0)->enemy.target_dy < 0x20u)
	{
		OBJECT(a0)->state = 2u;
		d0 = (uint8_t)(OBJECT(a0)->enemy.target_direction - 0x80u);
		a5 = animations_04DF78_ADDRESS;
		a6 = mem_read32(a1);
		enemy_face_object(d0, a0, a6, p_d7, &a5);
		d1 = 0x100u;
		speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
		OBJECT(a0)->x_speed = d6;
		OBJECT(a0)->y_speed = *p_d7;
		return;
	}
	if (OBJECT(a0)->enemy.target_dx >= 0x70u || OBJECT(a0)->enemy.target_dy >= 0x40u)
	{
		OBJECT(a0)->state = 3u;
		d0 = OBJECT(a0)->enemy.target_direction;
		a5 = animations_04DF78_ADDRESS;
		a6 = mem_read32(a1);
		enemy_face_object(d0, a0, a6, p_d7, &a5);
		d1 = 0x100u;
		speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
		OBJECT(a0)->x_speed = d6;
		OBJECT(a0)->y_speed = *p_d7;
	}
}

void enemy_keep_distance_knife_back_off(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	if (OBJECT(a0)->enemy.target_dx >= 0x50u || OBJECT(a0)->enemy.target_dy >= 0x20u)
		OBJECT(a0)->state = 0u;
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

void enemy_keep_distance_knife_close_in(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	if (OBJECT(a0)->enemy.target_dx < 0x70u && OBJECT(a0)->enemy.target_dy < 0x40u)
		OBJECT(a0)->state = 0u;
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

/* walks away, turns and waits while its turtle is down */
void enemy_back_off_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E1C4_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_back_off_knife_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d6 = 0;

	OBJECT(a0)->enemy_back_off.move_time = 0x40u;
	OBJECT(a0)->enemy_back_off.time = 0x1Eu;
	d0 = OBJECT(a0)->enemy_back_off.target_direction;
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(d0, a0, a6, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x140u;
	speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->state++;
}

void enemy_back_off_knife_walk(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t time = 0;

	target_direction = OBJECT(a0)->enemy_back_off.target_direction;
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
	time = OBJECT(a0)->enemy_back_off.time;
	OBJECT(a0)->enemy_back_off.time = time - 1u;
	if (time != 1u)
	{
		enemy_back_off_knife_wait(a0, a1);
		return;
	}
	a6 = animations_04DFF8_ADDRESS;
	enemy_face_target_animation(a0, a6, &ignored, p_d7);
	OBJECT(a0)->frame_time = 0u;
	OBJECT(a0)->state++;
	enemy_back_off_knife_wait(a0, a1);
}

void enemy_back_off_knife_wait(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		OBJECT(a0)->enemy_back_off.approach = 0u;
		OBJECT(a0)->enemy_back_off.move_time = 0u;
	}
}

/* steps up or down out of the way of its turtle's attack */
void enemy_step_aside_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E260_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_step_aside_knife_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy.move_time = 8u;
	OBJECT(a0)->state++;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0x140;
	if ((int8_t)OBJECT(a0)->enemy.target_direction < 0)
		OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

void enemy_step_aside_knife_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy.move_time;
	OBJECT(a0)->enemy.move_time = move_time - 1u;
	if (move_time == 1u)
		OBJECT(a0)->enemy.approach = 0u;
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

/* thrusts the spear; enough hits and it throws it next */
void enemy_spear_thrust(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E2D0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_spear_thrust_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x55D6Cu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x202u;
	d7_2 = (d7 & ~0xFFu) | 3u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

void enemy_spear_thrust_end(uint32_t a0)
{
	uint8_t hits_left = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		hits_left = OBJECT(a0)->enemy_spear.hits_left;
		OBJECT(a0)->enemy_spear.hits_left = hits_left - 1u;
		if (hits_left == 1u)
		{
			OBJECT(a0)->enemy_spear.move = 0x4Cu;
			OBJECT(a0)->routine = 3u;
			OBJECT(a0)->state = 0u;
			OBJECT(a0)->flags &= ~8u;
			return;
		}
	}
	enemy_back_to_thinking(a0);
}

/* throws its spear and fights on bare-handed */
void enemy_spear_throw(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E342_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_spear_throw_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_spear.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->enemy_spear.move_time = 0x14u;
	OBJECT(a0)->state++;
	animation = 0x55DB6u;
	set_animation(0u, a0, animation);
}

void enemy_spear_throw_release(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint32_t d7_2 = 0, ignored = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy_spear.move_time;
	OBJECT(a0)->enemy_spear.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	*p_a5 = 0x4E34Eu;
	start_shot(a0, *p_a5, &d7_2, &ignored, &zero);
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_2 & 0xFFFFu);
}

void enemy_spear_throw_end(uint32_t a0, uint32_t a1, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	enemy_leave_side(a0, a1);
	mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
	OBJECT(a0)->kind = 0u;
	OBJECT(a0)->parameter = 0u;
	enemy_foot_soldier_setup(a0, a6, p_d5, p_d7, p_a5);
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
}

/* stabs with the knife */
void enemy_knife_stab(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E3D0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_knife_stab_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x570AAu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x202u;
	d7_2 = (d7 & ~0xFFu) | 3u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

/* a high kick */
void enemy_high_kick_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E40C_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_high_kick_knife_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x5714Cu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x302u;
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

/* a flying kick */
void enemy_jump_kick_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E448_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_jump_kick_knife_crouch(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x57088u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x303u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

uint32_t enemy_jump_kick_knife_leap(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	a6 = 0x4E458u;
	d7 = enemy_start_arc(d7, a0, a6);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	animation = 0x57190u;
	set_animation(0u, a0, animation);
	return d7;
}

uint32_t enemy_jump_kick_knife_fly(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x4E458u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x57088u;
	set_animation(0u, a0, animation);
	return d7;
}

/* throws a knife */
void enemy_throw_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E4FE_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_throw_knife_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_throw.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->enemy_throw.throw_time = 0x14u;
	OBJECT(a0)->state++;
	animation = 0x570DCu;
	set_animation(0u, a0, animation);
}

void enemy_throw_knife_release(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint32_t d7_2 = 0, ignored = 0;
	uint8_t throw_time = 0;

	throw_time = OBJECT(a0)->enemy_throw.throw_time;
	OBJECT(a0)->enemy_throw.throw_time = throw_time - 1u;
	if (throw_time != 1u)
		return;
	OBJECT(a0)->state++;
	*p_a5 = 0x4E50Au;
	start_shot(a0, *p_a5, &d7_2, &ignored, &zero);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_2 & 0xFFFFu);
}

void enemy_throw_knife_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	enemy_back_to_thinking(a0);
}

/* hit: its head thrown back */
void enemy_flinch_back_spear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E572_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_back_spear_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x55E30u;
	set_animation(0u, a0, animation);
}

/* hit: bent over */
void enemy_flinch_bent_spear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E596_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_bent_spear_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x55E64u;
	set_animation(0u, a0, animation);
}

/* hit: reeling */
void enemy_flinch_reel_spear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E5BA_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_reel_spear_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x55E8Eu;
	set_animation(0u, a0, animation);
}

/* hit: hunched */
void enemy_flinch_hunched_spear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E5DE_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_hunched_spear_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x55EB8u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_back_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E602_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_back_knife_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x571C2u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_bent_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E626_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_bent_knife_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x571F6u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_reel_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E64A_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_reel_knife_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x57220u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_hunched_knife(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E66E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_hunched_knife_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x5724Au;
	set_animation(0u, a0, animation);
}

/* a Foot soldier with throwing axes */
void enemy_axe_soldier_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy.target = a6;
	OBJECT(a0)->enemy.retarget_time = 0x10u;
	OBJECT(a0)->enemy.move_time = 0u;
	OBJECT(a0)->enemy.approach = 0u;
	OBJECT(a0)->enemy.dodge_chance = 5u;
	OBJECT(a0)->depth = 4u;
	enemies_on_screen++;
	OBJECT(a0)->throw = 0x85u;
	OBJECT(a0)->colour = 5u;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->health_bars = 3u;
	OBJECT(a0)->health = 6u;
	OBJECT(a0)->enemy.definition = 0x541A6u;
	OBJECT(a0)->enemy.move = (OBJECT(a0)->parameter & 0xF0u) << 2;
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine += 2u;
	animation = 0x575AAu;
	set_animation(0u, a0, animation);
}

/* a Foot soldier with a gun */
void enemy_gun_soldier_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy.target = a6;
	OBJECT(a0)->enemy.retarget_time = 0x10u;
	OBJECT(a0)->enemy.move_time = 0u;
	OBJECT(a0)->enemy.approach = 0u;
	OBJECT(a0)->enemy.dodge_chance = 5u;
	OBJECT(a0)->depth = 4u;
	enemies_on_screen++;
	OBJECT(a0)->throw = 0x85u;
	OBJECT(a0)->colour = 5u;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->health_bars = 3u;
	OBJECT(a0)->health = 6u;
	OBJECT(a0)->enemy.definition = 0x5422Eu;
	OBJECT(a0)->enemy.move = (OBJECT(a0)->parameter & 0xF0u) << 2;
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine += 2u;
	animation = 0x56A08u;
	set_animation(0u, a0, animation);
}

/* walks to its turtle with the gun */
void enemy_walk_to_target_gun(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E7BA_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_target_gun_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 8u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x120u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04E7C2_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04E7C2_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* walks to its side of its turtle with the gun */
void enemy_walk_to_side_gun(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E800_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_side_gun_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xF0u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04E7C2_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04E7C2_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* walks to its turtle's row at shooting distance and stands there */
void enemy_walk_to_range_gun(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E83E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_range_gun_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xF0u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04E7C2_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04E7C2_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* walks to its turtle's row at 0x5A across, then stands in its ready pose */
void enemy_walk_to_range_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0, animation = 0;

	OBJECT(a0)->enemy_walk.move_time--;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = OBJECT(a0)->enemy_walk.animations;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	if (OBJECT(a0)->enemy_walk.target_dx < 0x5Au)
	{
		OBJECT(a0)->y_speed = 0;
		OBJECT(a0)->x_speed = OBJECT(a0)->enemy_walk.speed;
		if ((int8_t)OBJECT(a0)->enemy_walk.side < 0)
			OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	else
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = OBJECT(a0)->enemy_walk.speed;
		if ((int8_t)OBJECT(a0)->enemy_walk.target_direction >= 0)
			OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	}
	if (OBJECT(a0)->enemy_walk.target_dy >= 2u)
	{
		move_object_blocked(a0);
		return;
	}
	OBJECT(a0)->state++;
	*p_a5 = OBJECT(a0)->enemy_walk.animations;
	animation = mem_read32(*p_a5 + 8u);
	set_animation(0u, a0, animation);
}

/* stands ready while level with its turtle, walks again when off its row */
void enemy_walk_to_range_hold(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time--;
	if (OBJECT(a0)->enemy_walk.target_dy < 3u)
		return;
	OBJECT(a0)->state--;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = OBJECT(a0)->enemy_walk.animations;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* walks away, crouches and waits while its turtle is down */
void enemy_back_off_gun(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E906_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_back_off_gun_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d6 = 0;

	OBJECT(a0)->enemy_back_off.move_time = 0x40u;
	OBJECT(a0)->enemy_back_off.time = 0x20u;
	d0 = OBJECT(a0)->enemy_back_off.target_direction;
	*p_a5 = animations_04E7C2_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(d0, a0, a6, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x100u;
	speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->state++;
}

void enemy_back_off_gun_walk(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0, animation = 0;
	uint8_t time = 0;

	target_direction = OBJECT(a0)->enemy_back_off.target_direction;
	*p_a5 = animations_04E7C2_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
	time = OBJECT(a0)->enemy_back_off.time;
	OBJECT(a0)->enemy_back_off.time = time - 1u;
	if (time != 1u)
	{
		enemy_back_off_gun_wait(a0, a1);
		return;
	}
	OBJECT(a0)->state++;
	animation = 0x56B1Eu;
	set_animation(0u, a0, animation);
}

void enemy_back_off_gun_wait(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		OBJECT(a0)->enemy_back_off.approach = 0u;
		OBJECT(a0)->enemy_back_off.move_time = 0u;
	}
}

/* runs straight away from its turtle for a moment */
void enemy_run_away_gun(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E99E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_run_away_gun_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0, target_direction = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d6 = 0, ignored = 0;

	OBJECT(a0)->enemy.move_time = 8u;
	d0 = (uint8_t)(OBJECT(a0)->enemy.target_direction - 0x80u);
	d1 = 0x100u;
	speeds_from_direction(d0, d1, &d6, p_d7, &ignored);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->state++;
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_04E7C2_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
	enemy_run_away_gun_step(a0, a1, p_d7, p_a5);
}

void enemy_run_away_gun_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy.move_time;
	OBJECT(a0)->enemy.move_time = move_time - 1u;
	if (move_time == 1u)
	{
		OBJECT(a0)->enemy.approach = 0u;
		OBJECT(a0)->enemy.move_time = 0u;
	}
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_04E7C2_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

/* walks to its turtle with the axes */
void enemy_walk_to_target_axe(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EA12_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_target_axe_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 8u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x140u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_04EA1A_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04EA1A_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* walks to its side of its turtle with the axes */
void enemy_walk_to_side_axe(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EA58_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_side_axe_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xF0u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x140u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04EA1A_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04EA1A_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* walks to its turtle's row at throwing distance and stands there */
void enemy_walk_to_range_axe(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EA96_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_walk_to_range_axe_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_walk.move_time = 0xF0u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_walk.speed = 0x100u;
	target_direction = OBJECT(a0)->enemy_walk.target_direction;
	*p_a5 = animations_04EA1A_ADDRESS;
	OBJECT(a0)->enemy_walk.animations = animations_04EA1A_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

/* walks away, crouches and waits while its turtle is down */
void enemy_back_off_axe(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EAD4_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_back_off_axe_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d6 = 0;

	OBJECT(a0)->enemy_back_off.move_time = 0x40u;
	OBJECT(a0)->enemy_back_off.time = 0x28u;
	d0 = OBJECT(a0)->enemy_back_off.target_direction;
	*p_a5 = animations_04EA1A_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(d0, a0, a6, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x100u;
	speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->state++;
}

void enemy_back_off_axe_walk(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0, animation = 0;
	uint8_t time = 0;

	target_direction = OBJECT(a0)->enemy_back_off.target_direction;
	*p_a5 = animations_04EA1A_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
	time = OBJECT(a0)->enemy_back_off.time;
	OBJECT(a0)->enemy_back_off.time = time - 1u;
	if (time != 1u)
	{
		enemy_back_off_axe_wait(a0, a1);
		return;
	}
	OBJECT(a0)->state++;
	animation = 0x576E4u;
	set_animation(0u, a0, animation);
}

void enemy_back_off_axe_wait(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		OBJECT(a0)->enemy_back_off.approach = 0u;
		OBJECT(a0)->enemy_back_off.move_time = 0u;
	}
}

/* runs straight away from its turtle for a moment */
void enemy_run_away_axe(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EB6E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_run_away_axe_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0, target_direction = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d6 = 0, ignored = 0;

	OBJECT(a0)->enemy.move_time = 8u;
	d0 = (uint8_t)(OBJECT(a0)->enemy.target_direction - 0x80u);
	d1 = 0x180u;
	speeds_from_direction(d0, d1, &d6, p_d7, &ignored);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->state++;
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_04EA1A_ADDRESS;
	a6 = mem_read32(a1);
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
	enemy_run_away_axe_step(a0, a1, p_d7, p_a5);
}

void enemy_run_away_axe_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy.move_time;
	OBJECT(a0)->enemy.move_time = move_time - 1u;
	if (move_time == 1u)
	{
		OBJECT(a0)->enemy.approach = 0u;
		OBJECT(a0)->enemy.move_time = 0u;
	}
	target_direction = OBJECT(a0)->enemy.target_direction;
	*p_a5 = animations_04EA1A_ADDRESS;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
}

/* throws three axes */
void enemy_throw_axes(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EBE2_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_throw_axes_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_throw.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->enemy_throw.throw_time = 0x10u;
	OBJECT(a0)->enemy_throw.throws_left = 3u;
	OBJECT(a0)->state++;
	animation = 0x576ACu;
	set_animation(0u, a0, animation);
}

void enemy_throw_axes_release(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t animation = 0, ignored = 0;
	uint8_t throw_time = 0, throws_left = 0;

	throw_time = OBJECT(a0)->enemy_throw.throw_time;
	OBJECT(a0)->enemy_throw.throw_time = throw_time - 1u;
	if (throw_time == 1u)
	{
		d7_2 = 2u;
		queue_sound(d7_2, 0u);
		*p_a5 = 0x4EBEEu;
		start_shot(a0, *p_a5, &d7, &ignored, &zero);
		OBJECT(a0)->enemy_throw.throw_time = 0x10u;
		throws_left = OBJECT(a0)->enemy_throw.throws_left;
		OBJECT(a0)->enemy_throw.throws_left = throws_left - 1u;
		if (throws_left == 1u)
		{
			OBJECT(a0)->state++;
			animation = 0x576E4u;
			set_animation(0u, a0, animation);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* a high kick */
void enemy_high_kick_axe(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EC6A_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_high_kick_axe_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x5773Au;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x302u;
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

/* swings the gun like a club */
void enemy_gun_swing(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ECA6_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_gun_swing_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = 0x56AB4u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x302u;
	d7_2 = (d7 & ~0xFFu) | 1u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

/* fires four shots */
void enemy_shoot_gun(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ECE2_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shoot_gun_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_shoot.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->enemy_shoot.shot_time = 8u;
	OBJECT(a0)->enemy_shoot.shots_left = 4u;
	OBJECT(a0)->state++;
	animation = 0x56AF0u;
	set_animation(0u, a0, animation);
}

void enemy_shoot_gun_fire(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t animation = 0, ignored = 0;
	uint8_t shot_time = 0, shots_left = 0;

	shot_time = OBJECT(a0)->enemy_shoot.shot_time;
	OBJECT(a0)->enemy_shoot.shot_time = shot_time - 1u;
	if (shot_time == 1u)
	{
		d7_2 = 0x18u;
		queue_sound(d7_2, 0u);
		*p_a5 = 0x4ECEEu;
		start_shot(a0, *p_a5, &d7, &ignored, &zero);
		OBJECT(a0)->enemy_shoot.shot_time = 8u;
		shots_left = OBJECT(a0)->enemy_shoot.shots_left;
		OBJECT(a0)->enemy_shoot.shots_left = shots_left - 1u;
		if (shots_left == 1u)
		{
			OBJECT(a0)->state++;
			animation = 0x56B1Eu;
			set_animation(0u, a0, animation);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void enemy_flinch_back_gun(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ED6A_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_back_gun_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x56B7Cu;
	set_animation(0u, a0, animation);
}

void enemy_flinch_bent_gun(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ED8E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_bent_gun_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x56BB0u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_back_axe(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EDB2_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_back_axe_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x5777Eu;
	set_animation(0u, a0, animation);
}

void enemy_flinch_bent_axe(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EDD6_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_bent_axe_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x577B2u;
	set_animation(0u, a0, animation);
}

void enemy_flinch_reel_axe(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EDFA_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_flinch_reel_axe_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x577DCu;
	set_animation(0u, a0, animation);
}

/* a bare-handed Foot soldier that also throws a boomerang */
void enemy_boomerang_soldier_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy_boomerang.target = a6;
	OBJECT(a0)->enemy_boomerang.retarget_time = 0x10u;
	OBJECT(a0)->enemy_boomerang.move_time = 0u;
	OBJECT(a0)->enemy_boomerang.approach = 0u;
	OBJECT(a0)->enemy_boomerang.dodge_chance = 5u;
	OBJECT(a0)->depth = 4u;
	enemies_on_screen++;
	OBJECT(a0)->throw = 0x86u;
	OBJECT(a0)->colour = 6u;
	OBJECT(a0)->floor_height = 0u;
	enemy_set_floor(a0);
	OBJECT(a0)->health_bars = 3u;
	OBJECT(a0)->health = 6u;
	OBJECT(a0)->enemy_boomerang.definition = 0x542B6u;
	OBJECT(a0)->enemy_boomerang.move = (OBJECT(a0)->parameter & 0xF0u) << 2;
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine += 2u;
	animation = animations_0547C6_ADDRESS;
	set_animation(0u, a0, animation);
}

/* a bare-handed Foot soldier that also throws shuriken */
void enemy_shuriken_soldier_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy.target = a6;
	OBJECT(a0)->enemy.retarget_time = 0x10u;
	OBJECT(a0)->enemy.move_time = 0u;
	OBJECT(a0)->enemy.approach = 0u;
	OBJECT(a0)->enemy.dodge_chance = 5u;
	OBJECT(a0)->depth = 4u;
	enemies_on_screen++;
	OBJECT(a0)->throw = 0x85u;
	OBJECT(a0)->colour = 5u;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->health_bars = 3u;
	OBJECT(a0)->health = 6u;
	OBJECT(a0)->enemy.definition = 0x5433Eu;
	OBJECT(a0)->enemy.move = (OBJECT(a0)->parameter & 0xF0u) << 2;
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine += 2u;
	animation = animations_0547C6_ADDRESS;
	set_animation(0u, a0, animation);
}

/* a gun, axe or knife soldier on a rocket skateboard, by its parameter */
void enemy_skateboard_soldier_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d0 = 0;
	uint32_t animation = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy.target = a6;
	OBJECT(a0)->enemy.retarget_time = 0x10u;
	OBJECT(a0)->enemy.move_time = 0u;
	OBJECT(a0)->enemy.approach = 0u;
	OBJECT(a0)->enemy.dodge_chance = 5u;
	OBJECT(a0)->depth = 3u;
	enemies_on_screen++;
	d0 = OBJECT(a0)->parameter;
	OBJECT(a0)->colour = indexed_table_of_8_bit_values_04EFD0[d0];
	d0 = (uint16_t)((uint32_t)d0 << 2);
	OBJECT(a0)->enemy.definition = indexed_table_of_32_bit_values_04EFE0[d0 / 4u];
	animation = animations_04EFD4[d0 / 4u];
	set_animation(0u, a0, animation);
	OBJECT(a0)->health_bars = 3u;
	OBJECT(a0)->health = 6u;
	OBJECT(a0)->shadow = sprite_lists_05CA54_ADDRESS;
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->routine += 2u;
}

/* the thinking, carried along with the ride, standing on the board */
void enemy_skateboard_think(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	enemy_think(a0, a6, p_d5, p_d7, p_a1, p_a5);
	OBJECT(a0)->x += 0x600u;
	enemy_skateboard_stand(a0);
	OBJECT(a0)->contacts |= 0x80u;
	if ((frame_count & 4u) == 0u)
		OBJECT(a0)->shadow = sprite_lists_05CA54_ADDRESS;
	else
		OBJECT(a0)->shadow = 0x5CA5Cu;
}

/* the attack, carried along with the ride */
void enemy_skateboard_attack(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	enemy_attack(a0, p_d5, p_d7, p_a1, p_a5);
	OBJECT(a0)->x += 0x600u;
	OBJECT(a0)->contacts |= 0x80u;
	if ((frame_count & 4u) == 0u)
		OBJECT(a0)->shadow = sprite_lists_05CA54_ADDRESS;
	else
		OBJECT(a0)->shadow = 0x5CA5Cu;
}

/* the hit, carried along with the ride */
void enemy_skateboard_hit(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	enemy_hit(a0, p_d5, p_d7, p_a1, p_a5);
	OBJECT(a0)->x += 0x600u;
	OBJECT(a0)->contacts |= 0x80u;
	if ((frame_count & 4u) == 0u)
		OBJECT(a0)->shadow = sprite_lists_05CA54_ADDRESS;
	else
		OBJECT(a0)->shadow = 0x5CA5Cu;
}

/* the reaction to a hit, carried along with the ride */
void enemy_skateboard_react(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	OBJECT(a0)->x += 0x600u;
	enemy_react(a0, p_d5, p_d7, p_a1, p_a5);
	OBJECT(a0)->contacts |= 0x80u;
	if ((frame_count & 4u) == 0u)
		OBJECT(a0)->shadow = sprite_lists_05CA54_ADDRESS;
	else
		OBJECT(a0)->shadow = 0x5CA5Cu;
}

/* its standing pose, then the board with its flickering flame under it */
void enemy_skateboard_stand(uint32_t a0)
{
	uint32_t animation = 0;

	animation = animations_04EFD4[OBJECT(a0)->parameter];
	set_animation(0u, a0, animation);
}

/* throws a shuriken */
void enemy_throw_shuriken(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F082_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_throw_shuriken_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_throw.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->enemy_throw.throw_time = 0x14u;
	OBJECT(a0)->state++;
	animation = 0x55A24u;
	set_animation(0u, a0, animation);
}

void enemy_throw_shuriken_release(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t d7_3 = 0, ignored = 0;
	uint8_t throw_time = 0;

	throw_time = OBJECT(a0)->enemy_throw.throw_time;
	OBJECT(a0)->enemy_throw.throw_time = throw_time - 1u;
	if (throw_time != 1u)
		return;
	OBJECT(a0)->state++;
	d7_2 = 0x2Au;
	queue_sound(d7_2, 0u);
	*p_a5 = 0x4F08Eu;
	start_shot(a0, *p_a5, &d7_3, &ignored, &zero);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_3 & 0xFFFFu);
}

/* throws a boomerang and waits for it to come back */
void enemy_boomerang_throw(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F0F0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_boomerang_throw_wind_up(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x55ABEu;
	set_animation(0u, a0, animation);
}

void enemy_boomerang_throw_aim(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_boomerang.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->enemy_boomerang.move_time = 0x10u;
	OBJECT(a0)->state++;
	animation = 0x55AF2u;
	set_animation(0u, a0, animation);
}

void enemy_boomerang_throw_release(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t d7_3 = 0, object = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy_boomerang.move_time;
	OBJECT(a0)->enemy_boomerang.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	d7_2 = 0x2Au;
	queue_sound(d7_2, 0u);
	*p_a5 = 0x4F104u;
	start_shot(a0, *p_a5, &d7_3, &object, &zero);
	if (zero)
	{
		OBJECT(object)->unk_20 = (uint16_t)(a0 >> 16u);
		OBJECT(object)->unk_22 = (uint8_t)(a0 >> 8u);
		OBJECT(object)->unk_23 = (uint8_t)a0;
		OBJECT(a0)->enemy_boomerang.boomerang = object;
	}
	OBJECT(a0)->enemy_boomerang.move_time = 0x3Cu;
	OBJECT(a0)->state++;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_3 & 0xFFFFu);
}

void enemy_boomerang_throw_wait(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t move_time = 0;

	if (mem_read8(OBJECT(a0)->enemy_boomerang.boomerang + 4u) == 4u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_boomerang.move_time = 0u;
		return;
	}
	move_time = OBJECT(a0)->enemy_boomerang.move_time;
	OBJECT(a0)->enemy_boomerang.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	OBJECT(a0)->state++;
	animation = 0x55B3Au;
	set_animation(0u, a0, animation);
}

/* Rocksteady comes in alone or beside Bebop, counted as a boss */
void enemy_rocksteady_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	enemy_nearest_turtles(a0, p_d5, p_d7, p_a5, &a6);
	OBJECT(a0)->enemy_rocksteady.target = a6;
	OBJECT(a0)->enemy_rocksteady.retarget_time = 0x10u;
	OBJECT(a0)->enemy_rocksteady.move_time = 0u;
	OBJECT(a0)->enemy_rocksteady.armed = 0u;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->depth = 4u;
	OBJECT(a0)->enemy_rocksteady.mode_time = 0x12Cu;
	OBJECT(a0)->enemy_rocksteady.close_attack_wait = 0x10u;
	OBJECT(a0)->enemy_rocksteady.far_attack_wait = 0x10u;
	enemies_on_screen++;
	bosses_left++;
	rocksteady_hits_to_strike_back = rom_04F5B4[difficulty & 7u];
	OBJECT(a0)->shadow = sprite_lists_059A18_ADDRESS;
	if (OBJECT(a0)->parameter != 0u)
	{
		OBJECT(a0)->parameter = 0xAu;
		rocksteady = a0;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->state = 4u;
		OBJECT(a0)->flags |= 0x80u;
		animation = 0x59CFCu;
		set_animation(0u, a0, animation);
		return;
	}
	OBJECT(a0)->parameter = 0xCu;
	*p_d7 = (*p_d7 & ~0xFFFFu) | 0xFEu;
	music = *p_d7;
	queue_sound((uint8_t)*p_d7, a6);
	OBJECT(a0)->enemy_rocksteady.timer = 0xAu;
	OBJECT(a0)->routine++;
	OBJECT(a0)->flags |= 0x80u;
	animation = 0x59CBAu;
	set_animation(0u, a0, animation);
}

/* his way in: a laugh and his taunt, or waiting for Bebop, then walking in */
void enemy_rocksteady_enter(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F296_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_enter_wait(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_rocksteady.timer;
	OBJECT(a0)->enemy_rocksteady.timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(a0)->enemy_rocksteady.timer = 0x32u;
	OBJECT(a0)->state++;
	animation = animations_059CB0_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_rocksteady_enter_taunt(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d7 = *p_d7;
	uint16_t d0_2 = 0, screen_y = 0;
	uint32_t animation = 0, d1 = 0, d7_2 = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_rocksteady.timer;
	OBJECT(a0)->enemy_rocksteady.timer = timer - 1u;
	if (timer != 1u)
		return;
	d7_2 = (d7 & ~0xFFFFu) | 0x64u;
	music = d7_2;
	queue_sound((uint8_t)d7_2, 0u);
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
	d1 = (uint16_t)(OBJECT(a0)->screen_x - 0x10u);
	screen_y = OBJECT(a0)->screen_y;
	say_your_prayers_toitles(d0_2, d1, screen_y, &d5, &d7_2);
	OBJECT(a0)->y = 0x6C00u;
	OBJECT(a0)->enemy_rocksteady.timer = 0x78u;
	OBJECT(a0)->state++;
	animation = 0x59D58u;
	set_animation(d1, a0, animation);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d7 = d7_2;
}

uint32_t enemy_rocksteady_enter_ready(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_rocksteady.timer;
	OBJECT(a0)->enemy_rocksteady.timer = timer - 1u;
	if (timer != 1u)
		return d7;
	OBJECT(a0)->state++;
	a6 = table_loaded_by_lea_054746_ADDRESS;
	d7 = enemy_set_health(d7, a0, a6);
	OBJECT(a0)->enemy_rocksteady.timer = 0x10u;
	animation = animations_0596BA_ADDRESS;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_rocksteady_enter_walk_in(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_rocksteady.timer;
	OBJECT(a0)->enemy_rocksteady.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
	}
	OBJECT(a0)->y -= 0x100u;
}

void enemy_rocksteady_enter_wait_for_signal(uint32_t a0)
{
	uint32_t animation = 0;

	if (bosses_come_out == 0u)
		return;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_rocksteady.timer = 0x20u;
	animation = animations_0596BA_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_rocksteady_enter_walk_in_with_bebop(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_rocksteady.timer;
	OBJECT(a0)->enemy_rocksteady.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->flags |= 2u;
		a6 = 0x54766u;
		enemy_set_health(d7, a0, a6);
		a6 = 0xD0B4u;
		d7 = 0x43Au;
		*p_a5 = post_palette_request((uint16_t)d7, a6);
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
	}
	OBJECT(a0)->y -= 0x100u;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* his thinking: the gun drawn or put away in turns, blows close by, shots from afar, the pincer charge
   with Bebop */
void enemy_rocksteady_think(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint16_t d0 = 0, d6 = 0;
	uint32_t a6_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;
	uint8_t retarget_time = 0, far_attack_wait = 0, close_attack_wait = 0, t1 = 0, t2 = 0;
	uint16_t mode_time = 0, t3 = 0;

	*p_d7 = (*p_d7 & ~0xFFu) | OBJECT(a0)->parameter;
	enemy_flash_when_weak((uint8_t)*p_d7, a0);
	retarget_time = OBJECT(a0)->enemy_rocksteady.retarget_time;
	OBJECT(a0)->enemy_rocksteady.retarget_time = retarget_time - 1u;
	if (retarget_time == 1u)
	{
		OBJECT(a0)->enemy_rocksteady.retarget_time = 0x10u;
		if (turtles_in_play != 0u)
		{
			enemy_nearest_turtles(a0, p_d5, p_d7, p_a5, &a6);
			OBJECT(a0)->enemy_rocksteady.target = a6;
		}
	}
	*p_a1 = 0x60000u | OBJECT(a0)->enemy_rocksteady.target;
	turtle = *p_a1;
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	OBJECT(a0)->contacts &= 0xE0u;
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	enemy_keep_on_screen(a0);
	if (pincer_charge != 0u)
	{
		OBJECT(a0)->enemy_rocksteady.target = pincer_charge_target;
		OBJECT(a0)->enemy_rocksteady.move = 0x98u;
		OBJECT(a0)->routine = 3u;
		OBJECT(a0)->state = 0u;
		return;
	}
	mode_time = OBJECT(a0)->enemy_rocksteady.mode_time;
	OBJECT(a0)->enemy_rocksteady.mode_time = mode_time - 1u;
	if (mode_time != 1u)
	{
		if ((OBJECT(*p_a1)->routine != 4u || indexed_table_of_8_bit_values_048C5E[OBJECT(*p_a1)->turtle.hit_reaction] != 0u) && OBJECT(a0)->enemy_rocksteady.target_dy <= 8u)
		{
			if (OBJECT(a0)->enemy_rocksteady.target_dx > 0x32u)
			{
				far_attack_wait = OBJECT(a0)->enemy_rocksteady.far_attack_wait;
				OBJECT(a0)->enemy_rocksteady.far_attack_wait = far_attack_wait - 1u;
				if (far_attack_wait == 1u && (OBJECT(a0)->enemy_rocksteady.armed != 0u || rocksteady_last_attack != 0x88u))
				{
					a6_2 = 0x4F5C0u;
					*p_a5 = rom_04F5CC_ADDRESS;
					enemy_rocksteady_pick_attack(a0, a6_2, p_d7, p_a5);
					OBJECT(a0)->enemy_rocksteady.far_attack_wait = mem_read8(*p_a5 + *p_d7);
					OBJECT(a0)->routine = 3u;
					OBJECT(a0)->state = 0u;
					OBJECT(a0)->flags &= ~8u;
					return;
				}
			}
			else
			{
				close_attack_wait = OBJECT(a0)->enemy_rocksteady.close_attack_wait;
				OBJECT(a0)->enemy_rocksteady.close_attack_wait = close_attack_wait - 1u;
				if (close_attack_wait == 1u)
				{
					a6_2 = 0x4F5BCu;
					*p_a5 = rom_04F5C4_ADDRESS;
					enemy_rocksteady_pick_attack(a0, a6_2, p_d7, p_a5);
					OBJECT(a0)->enemy_rocksteady.close_attack_wait = mem_read8(*p_a5 + *p_d7);
					OBJECT(a0)->routine = 3u;
					OBJECT(a0)->state = 0u;
					OBJECT(a0)->flags &= ~8u;
					return;
				}
			}
		}
		if (OBJECT(a0)->enemy_rocksteady.move_time == 0u)
		{
			a6_2 = 0x4F5D4u + (uint16_t)((uint32_t)OBJECT(a0)->enemy_rocksteady.armed << 3);
			*p_d7 = 0x64u;
			*p_d7 = random_below((uint16_t)*p_d7, a0);
			d6 = 3u;
			for (;;)
			{
				t1 = mem_read8(a6_2 + 4u + (int16_t)d6);
				t2 = *p_d7;
				*p_d7 = (*p_d7 & ~0xFFu) | (uint8_t)(t2 - t1);
				if (t2 < t1)
					break;
				t3 = d6 - 1u;
				d6 = t3;
				if (t3 != 0xFFFFu)
					continue;
				*p_d7 = 0x64u;
				*p_d7 = random_below((uint16_t)*p_d7, a0);
				d6 = 3u;
			}
			OBJECT(a0)->enemy_rocksteady.move = ((d6 & ~0xFFu) | mem_read8(a6_2 + (int16_t)d6)) << 2;
			OBJECT(a0)->state = 0u;
		}
	}
	else
	{
		OBJECT(a0)->enemy_rocksteady.armed ^= 1u;
		d0 = (uint16_t)((uint32_t)OBJECT(a0)->enemy_rocksteady.armed << 2);
		OBJECT(a0)->enemy_rocksteady.move = indexed_table_of_16_bit_values_04F58C[d0 / 2u];
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_rocksteady.mode_time = mem_read16(0x4F594u + (int16_t)rom_04F58E[d0 / 2u] + (uint16_t)((uint32_t)difficulty << 2));
		*p_a5 = rom_04F5C4_ADDRESS;
		OBJECT(a0)->enemy_rocksteady.close_attack_wait = rom_04F5C4[d0];
		OBJECT(a0)->enemy_rocksteady.far_attack_wait = rom_04F5CC[d0];
	}
	switch ((uint32_t)(int16_t)OBJECT(a0)->enemy_rocksteady.move)
	{
	case 20:
		enemy_shuffle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 28:
		enemy_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 36:
		enemy_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0:
		enemy_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 4:
		enemy_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 8:
		enemy_keep_distance(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 12:
		enemy_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 16:
		enemy_run_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 44:
		enemy_walk_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 48:
		enemy_walk_to_target_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 52:
		enemy_walk_to_side_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 24:
		enemy_walk_past_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 32:
		enemy_back_off_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 40:
		enemy_walk_to_line_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 56:
		enemy_walk_to_target_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 60:
		enemy_walk_to_side_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 68:
		enemy_stalk_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 64:
		enemy_walk_away_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 72:
		enemy_walk_to_target_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 76:
		enemy_walk_to_side_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 104:
		enemy_walk_off_line_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 108:
		enemy_back_off_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 112:
		enemy_step_aside_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 80:
		enemy_walk_to_target_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 84:
		enemy_walk_to_side_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 116:
		enemy_circle_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 124:
		enemy_keep_distance_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 120:
		enemy_back_off_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 128:
		enemy_step_aside_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 88:
		enemy_walk_to_target_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 92:
		enemy_walk_to_side_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 152:
		enemy_walk_to_range_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 140:
		enemy_back_off_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 144:
		enemy_run_away_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 96:
		enemy_walk_to_target_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 100:
		enemy_walk_to_side_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 148:
		enemy_walk_to_range_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 132:
		enemy_back_off_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 136:
		enemy_run_away_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 196:
		enemy_rocksteady_raise_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 200:
		enemy_rocksteady_laugh(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 192:
		enemy_rocksteady_shake_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 184:
		enemy_rocksteady_draw_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 188:
		enemy_rocksteady_put_gun_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 204:
		enemy_rocksteady_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 208:
		enemy_rocksteady_line_up(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 212:
		enemy_rocksteady_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 232:
		enemy_rocksteady_shoot_around(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 228:
		enemy_bebop_stand(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 216:
		enemy_bebop_walk_to_front(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 224:
		enemy_bebop_walk_level(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 220:
		enemy_bebop_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 156:
		enemy_mouser_chase(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 164:
		enemy_mouser_creep_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 160:
		enemy_mouser_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 172:
		enemy_rodney_rush(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 176:
		enemy_rodney_rush_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 180:
		enemy_rodney_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 236:
		enemy_shredder_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 240:
		enemy_shredder_split(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 168:
		enemy_shredder_clone_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 244:
		enemy_shredder_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 248:
		enemy_shredder_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 252:
		enemy_shredder_guard(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 256:
		enemy_shredder_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

/* picks his attack by whether he has the gun out */
void enemy_rocksteady_pick_attack(uint32_t a0, uint32_t a6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d0 = 0;
	uint32_t d7 = 0;

	d0 = (uint16_t)((uint32_t)OBJECT(a0)->enemy_rocksteady.armed << 1);
	OBJECT(a0)->enemy_rocksteady.move = mem_read16(a6 + d0);
	rocksteady_last_attack = OBJECT(a0)->enemy_rocksteady.move;
	*p_a5 += (uint16_t)((uint32_t)d0 << 1);
	d7 = 4u;
	d7 = random_below((uint16_t)d7, a0);
	*p_d7 = d7;
}

/* his attack, flashing when weak */
void enemy_rocksteady_attack(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | OBJECT(a0)->parameter;
	enemy_flash_when_weak((uint8_t)d7_2, a0);
	*p_d7 = d7_2;
	enemy_boss_attack_move(a0, p_d5, p_d7, p_a1, p_a5);
}

/* Rocksteady's and Bebop's attack by their move */
void enemy_boss_attack_move(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;
	uint32_t jump_target = 0;

	*p_a1 = 0x60000u | OBJECT(a0)->enemy.target;
	turtle = *p_a1;
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	OBJECT(a0)->contacts &= 0xE0u;
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	enemy_keep_on_screen(a0);
	jump_target = mem_read32(0x53D2Au + (int16_t)OBJECT(a0)->enemy.move);
	switch (jump_target)
	{
	case 0x049A06u:
		enemy_jab(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049A52u:
		enemy_chop(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049A8Eu:
		enemy_swing(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049ACAu:
		enemy_high_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049B06u:
		enemy_jump_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049BBCu:
		enemy_long_jump_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049C72u:
		func_049C72();
		return;
	case 0x049C74u:
		func_049C74();
		return;
	case 0x049C76u:
		enemy_grab(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B2DAu:
		enemy_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B316u:
		enemy_low_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B352u:
		enemy_leaping_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B42Au:
		enemy_jump_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B4E0u:
		enemy_flying_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B5D6u:
		enemy_smash_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E2C4u:
		enemy_spear_thrust(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E336u:
		enemy_spear_throw(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E3C4u:
		enemy_knife_stab(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E400u:
		enemy_high_kick_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E43Cu:
		enemy_jump_kick_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E4F2u:
		enemy_throw_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04EBD6u:
		enemy_throw_axes(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04EC5Eu:
		enemy_high_kick_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04EC9Au:
		enemy_gun_swing(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04ECD6u:
		enemy_shoot_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04F076u:
		enemy_throw_shuriken(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04F0E4u:
		enemy_boomerang_throw(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FA96u:
		enemy_rocksteady_pincer_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FC04u:
		enemy_rocksteady_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FCD4u:
		enemy_rocksteady_punch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FD4Cu:
		enemy_rocksteady_gun_butt(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FD88u:
		enemy_rocksteady_shoot(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x0508A0u:
		enemy_bebop_pincer_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x050ADCu:
		enemy_bebop_punch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x050B8Cu:
		enemy_bebop_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x050C68u:
		enemy_bebop_shoot(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x052306u:
		enemy_rodney_shoot(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x052422u:
		enemy_rodney_whip(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x0534C4u:
		enemy_shredder_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x053524u:
		enemy_shredder_thrust(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x05356Eu:
		enemy_shredder_slash(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x0535B8u:
		enemy_shredder_sweep(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x053602u:
		enemy_shredder_ray(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

/* hit: his reaction by what is left of his health and where the hit came from */
void enemy_rocksteady_hit(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint8_t hit = 0;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0;

	rocksteady_hits_to_strike_back--;
	d7_2 = (d7 & ~0xFFu) | 0x82u;
	queue_sound((uint8_t)d7_2, 0u);
	pincer_charge = 0u;
	d0 = 0x9Cu;
	if ((OBJECT(a0)->health_bars | OBJECT(a0)->health) != 0u)
	{
		d0 = 0x98u;
		if (OBJECT(a0)->health != 0u)
		{
			d0 = OBJECT(a0)->flags;
			hit = OBJECT(a0)->hit;
			d0 = (uint8_t)((uint32_t)d0 << 1);
			if ((int8_t)(d0 ^ hit) >= 0)
				d0 = (uint16_t)((uint32_t)indexed_table_of_8_bit_values_04F6B6[hit & 0x7Fu] << 2);
			else
				d0 = 0xA0u;
		}
	}
	OBJECT(a0)->enemy_rocksteady.move = d0;
	OBJECT(a0)->routine++;
	*p_d7 = d7_2;
	enemy_rocksteady_react(a0, p_d5, p_d7, p_a1, p_a5);
}

/* his reaction to a hit, flashing when weak */
void enemy_rocksteady_react(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | OBJECT(a0)->parameter;
	enemy_flash_when_weak((uint8_t)d7_2, a0);
	*p_d7 = d7_2;
	enemy_boss_react_move(a0, p_d5, p_d7, p_a1, p_a5);
}

/* Rocksteady's and Bebop's reaction by their move */
void enemy_boss_react_move(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	*p_a1 = 0x60000u | OBJECT(a0)->attacker;
	OBJECT(a0)->contacts &= 0xE0u;
	enemy_floor_contacts(a0, &ignored, &ignored_2, &ignored_3, &ignored_4, p_d5, p_d7, p_a5);
	enemy_keep_on_screen(a0);
	switch ((uint32_t)(int16_t)OBJECT(a0)->enemy.move)
	{
	case 228:
		enemy_crash_into_scenery(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 232:
		enemy_crash_into_scenery_low(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0:
		enemy_flinch_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 4:
		enemy_flinch_bent(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 8:
		enemy_flinch_reel(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 12:
		enemy_flinch_hunched(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 36:
		enemy_killed_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 32:
		enemy_killed_forward(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 16:
		enemy_knocked_forward(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 128:
		enemy_thrown_by_donatello(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 132:
		*p_a5 = unreached_04A338(a0, *p_a1);
		return;
	case 136:
		enemy_thrown_by_michelangelo(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 140:
		*p_a5 = unreached_04A3F4(a0, *p_a1);
		return;
	case 188:
		enemy_thrown_by_raphael(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 192:
		*p_a5 = unreached_04A4B2(a0, *p_a1);
		return;
	case 196:
		enemy_thrown_by_leonardo(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 200:
		*p_a5 = unreached_04A570(a0, *p_a1);
		return;
	case 20:
		enemy_knocked_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 24:
		enemy_die(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 28:
		enemy_die_on_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 40:
		enemy_flinch_back_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 44:
		enemy_flinch_bent_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 48:
		enemy_flinch_reel_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 52:
		enemy_flinch_hunched_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 56:
		enemy_flinch_back_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 60:
		enemy_flinch_bent_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 68:
		enemy_flinch_hunched_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 72:
		enemy_flinch_back_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 76:
		enemy_flinch_bent_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 80:
		enemy_flinch_reel_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 84:
		enemy_flinch_hunched_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 88:
		enemy_flinch_back_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 92:
		enemy_flinch_bent_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 96:
		enemy_flinch_reel_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 100:
		enemy_flinch_hunched_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 120:
		enemy_flinch_back_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 124:
		enemy_flinch_bent_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 104:
		enemy_flinch_back_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 108:
		enemy_flinch_bent_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 112:
		enemy_flinch_reel_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 164:
		enemy_rocksteady_flinch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 168:
		enemy_rocksteady_reel(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 160:
		enemy_rocksteady_flinch_from_behind(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 152:
		enemy_rocksteady_knocked_down(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 156:
		enemy_rocksteady_defeated(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 172:
		enemy_bebop_flinch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 176:
		enemy_bebop_flinch_from_behind(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 180:
		enemy_bebop_knocked_down(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 184:
		enemy_bebop_defeated(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 148:
		enemy_mouser_thrown_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 224:
		enemy_mouser_break_down(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 144:
		enemy_mouser_knocked_flying(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 64:
		enemy_rodney_knocked_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 116:
		enemy_rodney_destroyed(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 204:
		enemy_shredder_lose_bar(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 208:
		enemy_shredder_flinch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 212:
		enemy_shredder_flinch_from_behind(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 216:
		enemy_shredder_defeated(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 220:
		enemy_shredder_vanish(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

uint32_t start_rocksteady(uint32_t d7)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t object = 0;

	d0 = 0u;
	take_free_object_in_group(d0, &d7, &object, &zero);
	if (zero)
	{
		OBJECT(object)->flags = 1u;
		OBJECT(object)->contacts = 0u;
		OBJECT(object)->kind = 0x11u;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->routine = 0u;
		OBJECT(object)->state = 0u;
		OBJECT(object)->colour = 0xFFu;
		OBJECT(object)->animation_delay = 0u;
		OBJECT(object)->throw = 0u;
		OBJECT(object)->height = 0u;
		OBJECT(object)->x = 0x16800u;
		OBJECT(object)->y = 0x11400u;
	}
	return d7;
}

/* raises his fist at his turtle */
void enemy_rocksteady_raise_fist(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F72E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_raise_fist_start(uint32_t a0, uint32_t a1)
{
	uint32_t animation = 0;

	enemy_boss_face_target(a0, a1);
	OBJECT(a0)->enemy_rocksteady.move_time = 1u;
	OBJECT(a0)->state++;
	animation = 0x59CFCu;
	set_animation(0u, a0, animation);
}

/* laughs at his turtle */
void enemy_rocksteady_laugh(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F75C_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_laugh_start(uint32_t a0, uint32_t a1)
{
	uint32_t animation = 0;

	enemy_boss_face_target(a0, a1);
	OBJECT(a0)->enemy_rocksteady.move_time = 0x88u;
	OBJECT(a0)->state++;
	animation = 0x59D58u;
	set_animation(0u, a0, animation);
}

/* shakes his fist at his turtle */
void enemy_rocksteady_shake_fist(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F78A_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_shake_fist_start(uint32_t a0, uint32_t a1)
{
	uint32_t animation = 0;

	enemy_boss_face_target(a0, a1);
	OBJECT(a0)->enemy_rocksteady.move_time = 0x40u;
	OBJECT(a0)->state++;
	animation = 0x59CC4u;
	set_animation(0u, a0, animation);
}

/* holds the pose until his move's time runs out */
void enemy_rocksteady_hold_pose(uint32_t a0)
{
	OBJECT(a0)->enemy_rocksteady.move_time--;
}

/* draws his gun */
void enemy_rocksteady_draw_gun(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F7BE_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_draw_gun_start(uint32_t a0, uint32_t a1)
{
	uint32_t animation = 0;

	enemy_boss_face_target(a0, a1);
	OBJECT(a0)->enemy_rocksteady.move_time = 0xFFu;
	OBJECT(a0)->state++;
	animation = animations_05A08A_ADDRESS;
	set_animation(0u, a0, animation);
}

/* the move is over when its animation ends */
void enemy_rocksteady_pose_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
		OBJECT(a0)->enemy_rocksteady.move_time = 0u;
}

/* puts his gun away */
void enemy_rocksteady_put_gun_away(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F7FA_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_put_gun_away_start(uint32_t a0, uint32_t a1)
{
	uint32_t animation = 0;

	enemy_boss_face_target(a0, a1);
	OBJECT(a0)->enemy_rocksteady.move_time = 0xFFu;
	OBJECT(a0)->state++;
	animation = 0x5A0D2u;
	set_animation(0u, a0, animation);
}

/* walks round his turtle */
void enemy_rocksteady_circle(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F828_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_circle_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	OBJECT(a0)->enemy_rocksteady_circle.move_time = 0xB4u;
	OBJECT(a0)->enemy_rocksteady_circle.aim_time = 1u;
	OBJECT(a0)->enemy_rocksteady_circle.turn = 0u;
	if ((random_seed & 0x80u) != 0u)
		OBJECT(a0)->enemy_rocksteady_circle.turn = 0x40u;
	OBJECT(a0)->state++;
	animation = animations_0596BA_ADDRESS;
	set_animation(0u, a0, animation);
	enemy_rocksteady_circle_step(a0, a1, p_d7, p_a5);
}

void enemy_rocksteady_circle_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t d6 = 0;
	uint8_t aim_time = 0;

	OBJECT(a0)->enemy_rocksteady_circle.move_time--;
	aim_time = OBJECT(a0)->enemy_rocksteady_circle.aim_time;
	OBJECT(a0)->enemy_rocksteady_circle.aim_time = aim_time - 1u;
	if (aim_time == 1u)
	{
		OBJECT(a0)->enemy_rocksteady_circle.aim_time = 8u;
		enemy_boss_face_target(a0, a1);
		d0 = (uint8_t)((OBJECT(a0)->enemy_rocksteady_circle.target_direction & 0xC0u) + OBJECT(a0)->enemy_rocksteady_circle.turn);
		d1 = 0x160u;
		speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
		OBJECT(a0)->x_speed = d6;
		OBJECT(a0)->y_speed = *p_d7;
	}
	move_object_blocked(a0);
}

/* lines up with his turtle with the gun up */
void enemy_rocksteady_line_up(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F8A8_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_line_up_start(uint32_t a0, uint32_t a1)
{
	uint32_t animation = 0;

	OBJECT(a0)->enemy_rocksteady.move_time = 0xF0u;
	OBJECT(a0)->enemy_rocksteady.timer = 1u;
	OBJECT(a0)->state++;
	animation = animations_05979C_ADDRESS;
	set_animation(0u, a0, animation);
	enemy_rocksteady_line_up_step(a0, a1);
}

void enemy_rocksteady_line_up_step(uint32_t a0, uint32_t a1)
{
	OBJECT(a0)->enemy_rocksteady.move_time--;
	enemy_boss_face_target(a0, a1);
	if (OBJECT(a0)->enemy_rocksteady.target_dx < 0x50u)
	{
		OBJECT(a0)->x_speed = 0x200;
		OBJECT(a0)->y_speed = 0;
		if ((int8_t)(OBJECT(a0)->enemy_rocksteady.target_direction - 0x40u) < 0)
			OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		move_object_blocked(a0);
		return;
	}
	if (OBJECT(a0)->enemy_rocksteady.target_dy < 3u)
		return;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0x200;
	if ((int8_t)OBJECT(a0)->enemy_rocksteady.target_direction < 0)
	{
		move_object_blocked(a0);
		return;
	}
	OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	move_object_blocked(a0);
}

/* walks up to his turtle with the gun level */
void enemy_rocksteady_close_in(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F92E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_close_in_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	OBJECT(a0)->enemy_rocksteady_close_in.move_time = 0x80u;
	OBJECT(a0)->enemy_rocksteady_close_in.aim_time = 1u;
	OBJECT(a0)->state++;
	animation = animations_059618_ADDRESS;
	set_animation(0u, a0, animation);
	enemy_rocksteady_close_in_step(a0, a1, p_d7, p_a5);
}

void enemy_rocksteady_close_in_step(uint32_t a0, uint32_t turtle, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1_2 = 0;
	uint32_t d0 = 0, d1 = 0, d2 = 0, d6 = 0;
	uint8_t aim_time = 0;

	OBJECT(a0)->enemy_rocksteady_close_in.move_time--;
	aim_time = OBJECT(a0)->enemy_rocksteady_close_in.aim_time;
	OBJECT(a0)->enemy_rocksteady_close_in.aim_time = aim_time - 1u;
	if (aim_time != 1u)
	{
		move_object_blocked(a0);
		return;
	}
	enemy_boss_face_target(a0, turtle);
	d1 = 0x20u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		d1 = (uint16_t)(0u - d1);
	d1 = (uint16_t)(d1 + OBJECT(turtle)->screen_x);
	d2 = OBJECT(turtle)->screen_y;
	direction_to(a0, &d0, &d1, &d2);
	d1_2 = 0x180u;
	speeds_from_direction((uint8_t)d0, d1_2, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = (int16_t)d6 >> 1;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->enemy_rocksteady_close_in.aim_time = 8u;
	move_object_blocked(a0);
}

/* looks at its turtle and turns to it */
void enemy_boss_face_target(uint32_t a0, uint32_t a1)
{
	uint32_t ignored = 0, ignored_2 = 0, turtle = 0;

	turtle = a1;
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
}

/* fires three shots each way round */
void enemy_rocksteady_shoot_around(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F9CC_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_shoot_around_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_rocksteady_shoot_around.aims = 0x4F9D4u;
	OBJECT(a0)->enemy_rocksteady_shoot_around.move_time = 7u;
	OBJECT(a0)->enemy_rocksteady_shoot_around.shot_time = 1u;
	OBJECT(a0)->enemy_rocksteady_shoot_around.shots_left = 1u;
	enemy_rocksteady_shoot_around_fire(a0, p_d7, p_a5);
}

void enemy_rocksteady_shoot_around_fire(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a5 = *p_a5;
	uint32_t zero = 0;
	uint32_t aims = 0, animation = 0, d7_2 = 0, object = 0;
	uint8_t shot_time = 0, shots_left = 0, move_time = 0;
	uint32_t t1 = 0;

	shot_time = OBJECT(a0)->enemy_rocksteady_shoot_around.shot_time;
	OBJECT(a0)->enemy_rocksteady_shoot_around.shot_time = shot_time - 1u;
	if (shot_time == 1u)
	{
		shots_left = OBJECT(a0)->enemy_rocksteady_shoot_around.shots_left;
		OBJECT(a0)->enemy_rocksteady_shoot_around.shots_left = shots_left - 1u;
		if (shots_left != 1u)
		{
			OBJECT(a0)->enemy_rocksteady_shoot_around.shot_time = 8u;
			d7 = IN_PAGE(d7, 0x18u);
			queue_sound((uint8_t)d7, animation);
			a5 = OBJECT(a0)->enemy_rocksteady_shoot_around.bullet;
			start_shot(a0, a5, &d7, &object, &zero);
			if (zero)
				OBJECT(object)->parameter = OBJECT(a0)->enemy_rocksteady_shoot_around.aim;
		}
		else
		{
			move_time = OBJECT(a0)->enemy_rocksteady_shoot_around.move_time;
			OBJECT(a0)->enemy_rocksteady_shoot_around.move_time = move_time - 1u;
			if (move_time != 1u)
			{
				OBJECT(a0)->enemy_rocksteady_shoot_around.shots_left = 3u;
				aims = OBJECT(a0)->enemy_rocksteady_shoot_around.aims;
				d7_2 = LINKED(d7, mem_read8(aims));
				OBJECT(a0)->enemy_rocksteady_shoot_around.aims = aims + 1u;
				OBJECT(a0)->flags &= 0xBFu;
				t1 = d7_2;
				d7 = t1 & ~0x80u;
				if ((t1 & 0x80u) != 0u)
					OBJECT(a0)->flags |= 0x40u;
				OBJECT(a0)->enemy_rocksteady_shoot_around.aim = 0u;
				if ((uint8_t)d7 != 0u)
					OBJECT(a0)->enemy_rocksteady_shoot_around.aim = 1u;
				d7 = LINKED(d7, (uint16_t)(d7 << 3));
				OBJECT(a0)->enemy_rocksteady_shoot_around.bullet = indexed_table_of_32_bit_values_04F9DE[(uint16_t)d7 / 4u];
				animation = animations_04F9DA[(uint16_t)d7 / 4u];
				set_animation(0u, a0, animation);
				OBJECT(a0)->enemy_rocksteady_shoot_around.shot_time = 8u;
				d7 = IN_PAGE(d7, 0x18u);
				queue_sound((uint8_t)d7, animation);
				a5 = OBJECT(a0)->enemy_rocksteady_shoot_around.bullet;
				start_shot(a0, a5, &d7, &object, &zero);
				if (zero)
					OBJECT(object)->parameter = OBJECT(a0)->enemy_rocksteady_shoot_around.aim;
			}
		}
	}
	*p_d7 = d7;
	*p_a5 = a5;
}

/* charges across from his edge while Bebop charges from the other */
void enemy_rocksteady_pincer_charge(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FACE_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
	if (pincer_charge == 0u && pincer_charge_crash == 0u)
	{
		OBJECT(a0)->flags &= ~4u;
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_rocksteady.move_time = 0u;
	}
}

void enemy_rocksteady_pincer_charge_start(uint32_t a0)
{
	uint32_t animation = 0;

	animation = animations_0596BA_ADDRESS;
	if (OBJECT(a0)->enemy_rocksteady.armed != 0u)
		animation = animations_059618_ADDRESS;
	set_animation(0u, a0, animation);
	enemy_pincer_charge_take_edge(a0);
}

void enemy_rocksteady_pincer_charge_run_to_edge(uint32_t a0)
{
	uint8_t d0 = 0;

	move_object_blocked(a0);
	d0 = 8u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & OBJECT(a0)->contacts) != 0u)
	{
		OBJECT(a0)->flags ^= 0x40u;
		pincer_charge_at_edges |= OBJECT(a0)->enemy_rocksteady.side;
		OBJECT(a0)->state++;
	}
}

void enemy_rocksteady_pincer_charge_wait_for_bebop(uint32_t a0)
{
	uint32_t animation = 0;

	if (pincer_charge_at_edges < 0xC0u)
		return;
	animation = animations_05983E_ADDRESS;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x103u;
	OBJECT(a0)->attack = 7u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->attack |= 0x80u;
	OBJECT(a0)->flags &= ~0xAu;
	OBJECT(a0)->enemy_rocksteady.move_time = 0x1Eu;
	OBJECT(a0)->state++;
}

void enemy_rocksteady_pincer_charge_get_ready(uint32_t a0)
{
	enemy_rocksteady_charge_get_ready(a0);
}

void enemy_rocksteady_pincer_charge_run(uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t animation = 0, d1 = 0;

	d0 = 8u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & OBJECT(a0)->contacts) != 0u)
	{
		pincer_charge = 0u;
		return;
	}
	d1 = 0u;
	if (OBJECT(a0)->enemy_rocksteady.target_dy >= 3u)
	{
		d1 = 0x200u;
		if ((int8_t)OBJECT(a0)->enemy_rocksteady.target_direction >= 0)
			d1 = (uint16_t)(0u - d1);
	}
	OBJECT(a0)->y_speed = d1;
	move_object_blocked(a0);
	if (pincer_charge_crash != 0u)
	{
		animation = animations_05AD06_ADDRESS;
		set_animation(d1, a0, animation);
		OBJECT(a0)->flags &= ~4u;
		OBJECT(a0)->state++;
	}
}

void enemy_rocksteady_pincer_charge_crash(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy_rocksteady.move = 0x98u;
		OBJECT(a0)->routine = 5u;
		OBJECT(a0)->state = 0u;
	}
}

/* charges across the screen */
void enemy_rocksteady_charge(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FC10_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rocksteady_charge_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = animations_05983E_ADDRESS;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x103u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags &= ~0xAu;
	OBJECT(a0)->enemy_rocksteady.move_time = 0x1Eu;
	OBJECT(a0)->state++;
	return d7_2;
}

void enemy_rocksteady_charge_get_ready(uint32_t a0)
{
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy_rocksteady.move_time;
	OBJECT(a0)->enemy_rocksteady.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->x_speed = -0x380;
	OBJECT(a0)->y_speed = 0;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	OBJECT(a0)->state++;
}

void enemy_rocksteady_charge_run(uint32_t a0)
{
	uint8_t contacts = 0;
	uint16_t d1 = 0;

	contacts = OBJECT(a0)->contacts;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		if ((contacts & 8u) != 0u)
		{
			OBJECT(a0)->flags &= ~4u;
			OBJECT(a0)->flags |= 2u;
			OBJECT(a0)->routine = 2u;
			OBJECT(a0)->state = 0u;
			OBJECT(a0)->enemy_rocksteady.move_time = 0u;
			return;
		}
		d1 = 0u;
		if (OBJECT(a0)->enemy_rocksteady.target_dy >= 3u)
		{
			d1 = 0x200u;
			if ((int8_t)OBJECT(a0)->enemy_rocksteady.target_direction >= 0)
				d1 = (uint16_t)(0u - d1);
		}
		OBJECT(a0)->y_speed = d1;
		move_object_blocked(a0);
		return;
	}
	if ((contacts & 0x10u) != 0u)
	{
		OBJECT(a0)->flags &= ~4u;
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_rocksteady.move_time = 0u;
		return;
	}
	d1 = 0u;
	if (OBJECT(a0)->enemy_rocksteady.target_dy >= 3u)
	{
		d1 = 0x200u;
		if ((int8_t)OBJECT(a0)->enemy_rocksteady.target_direction >= 0)
			d1 = (uint16_t)(0u - d1);
	}
	OBJECT(a0)->y_speed = d1;
	move_object_blocked(a0);
}

/* punches */
void enemy_rocksteady_punch(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FCE0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rocksteady_punch_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;
	uint8_t flags = 0;

	animation = animations_059FAA_ADDRESS;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x203u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	flags = OBJECT(a0)->flags;
	OBJECT(a0)->flags = flags | 2u;
	if ((flags & 2u) == 0u && turtles_in_play >= 2u)
		OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	return d7_2;
}

/* the blow over, back to thinking */
void enemy_rocksteady_blow_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags &= ~4u;
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_rocksteady.move_time = 0u;
	}
}

/* hits with the gun's butt */
void enemy_rocksteady_gun_butt(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FD58_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rocksteady_gun_butt_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0;

	animation = 0x59FD2u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x203u;
	d7 &= ~0xFFu;
	d7 = enemy_face_target(d7, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7;
}

/* shoots, up at a turtle in the air */
void enemy_rocksteady_shoot(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FD94_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rocksteady_shoot_start(uint32_t a0, uint32_t turtle)
{
	uint32_t a5 = 0, animation = 0;

	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_rocksteady_shoot.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->enemy_rocksteady_shoot.shot_time = 1u;
	OBJECT(a0)->enemy_rocksteady_shoot.shots_left = 4u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_rocksteady_shoot.aim = 0u;
	a5 = animations_04FDA8_ADDRESS;
	if (OBJECT(turtle)->height_whole >= 0x40u)
	{
		OBJECT(a0)->enemy_rocksteady_shoot.aim = 1u;
		a5 += 8u;
	}
	animation = DATA32(a5);
	a5 += 4u;
	OBJECT(a0)->enemy_rocksteady_shoot.bullet = DATA32(a5);
	set_animation(0u, a0, animation);
	return a5;
}

void enemy_rocksteady_shoot_fire(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t object = 0;
	uint8_t shot_time = 0, shots_left = 0;

	shot_time = OBJECT(a0)->enemy_rocksteady_shoot.shot_time;
	OBJECT(a0)->enemy_rocksteady_shoot.shot_time = shot_time - 1u;
	if (shot_time == 1u)
	{
		d7_2 = 0x18u;
		queue_sound(d7_2, 0u);
		*p_a5 = OBJECT(a0)->enemy_rocksteady_shoot.bullet;
		start_shot(a0, *p_a5, &d7, &object, &zero);
		if (zero)
			OBJECT(object)->parameter = OBJECT(a0)->enemy_rocksteady_shoot.aim;
		OBJECT(a0)->enemy_rocksteady_shoot.shot_time = 8u;
		shots_left = OBJECT(a0)->enemy_rocksteady_shoot.shots_left;
		OBJECT(a0)->enemy_rocksteady_shoot.shots_left = shots_left - 1u;
		if (shots_left == 1u)
		{
			OBJECT(a0)->routine = 2u;
			OBJECT(a0)->state = 0u;
			OBJECT(a0)->enemy_rocksteady_shoot.move_time = 0u;
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* hit from the front */
void enemy_rocksteady_flinch(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FE4E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_flinch_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = animations_04FE56[OBJECT(a0)->enemy_rocksteady.armed];
	set_animation(0u, a0, animation);
}

/* back to thinking, or striking back at once when he has taken enough hits */
void enemy_rocksteady_flinch_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_rocksteady.move_time = 0u;
		if (rocksteady_hits_to_strike_back == 0u)
		{
			OBJECT(a0)->flags &= ~2u;
			OBJECT(a0)->enemy_rocksteady.close_attack_wait = 1u;
		}
	}
}

/* hit from the front, the other way */
void enemy_rocksteady_reel(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FEB6_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_reel_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = animations_04FEBE[OBJECT(a0)->enemy_rocksteady.armed];
	set_animation(0u, a0, animation);
}

/* hit from behind */
void enemy_rocksteady_flinch_from_behind(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FEEE_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rocksteady_flinch_from_behind_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = animations_04FEF6[OBJECT(a0)->enemy_rocksteady.armed];
	set_animation(0u, a0, animation);
}

/* knocked down, lies, gets up with his health back */
void enemy_rocksteady_knocked_down(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FF26_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rocksteady_knocked_down_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	enemy_boss_face_target(a0, a1);
	a6 = record_04FF52_ADDRESS;
	d7 = enemy_start_arc(d7, a0, a6);
	a6 = animations_04FF3A_ADDRESS;
	if (OBJECT(a0)->enemy_rocksteady_knocked_down.armed != 0u)
		a6 += 0xCu;
	OBJECT(a0)->enemy_rocksteady_knocked_down.animations = a6;
	animation = DATA32(a6);
	set_animation(0u, a0, animation);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

uint32_t enemy_rocksteady_knocked_down_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	move_object_with_height_blocked(a0);
	a6 = record_04FF52_ADDRESS;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = mem_read32(OBJECT(a0)->enemy_rocksteady_knocked_down.animations + 4u);
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_rocksteady_knocked_down_slide(uint32_t a0)
{
	uint32_t a6 = 0;

	if ((uint16_t)OBJECT(a0)->x_speed != 0u)
	{
		move_object_blocked(a0);
		a6 = record_04FF52_ADDRESS;
		enemy_arc_step(a0, a6);
	}
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy_rocksteady_knocked_down.lie_time = 0x1Eu;
		OBJECT(a0)->state++;
	}
}

uint32_t enemy_rocksteady_knocked_down_lie(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;
	uint8_t lie_time = 0;

	lie_time = OBJECT(a0)->enemy_rocksteady_knocked_down.lie_time;
	OBJECT(a0)->enemy_rocksteady_knocked_down.lie_time = lie_time - 1u;
	if (lie_time != 1u)
		return d7;
	OBJECT(a0)->state++;
	a6 = table_loaded_by_lea_054746_ADDRESS;
	if (area != 2u)
		a6 = 0x54766u;
	d7 = enemy_refill_health(d7, a0, a6);
	animation = mem_read32(OBJECT(a0)->enemy_rocksteady_knocked_down.animations + 8u);
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_rocksteady_knocked_down_get_up(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		rocksteady_hits_to_strike_back = rom_04F5B4[difficulty & 7u];
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_rocksteady_knocked_down.move_time = 0u;
		if (OBJECT(a0)->enemy_rocksteady_knocked_down.armed == 0u)
			OBJECT(a0)->enemy_rocksteady_knocked_down.mode_time = 1u;
	}
}

/* defeated: falls, the last boss clears the area, blinks and is gone */
void enemy_rocksteady_defeated(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050082_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rocksteady_defeated_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	no_pincer_charge = 0xFFu;
	enemy_boss_face_target(a0, a1);
	a6 = record_0500A2_ADDRESS;
	d7 = enemy_start_arc(d7, a0, a6);
	a6 = animations_050092_ADDRESS;
	if (OBJECT(a0)->enemy_rocksteady_defeated.armed != 0u)
		a6 += 8u;
	OBJECT(a0)->enemy_rocksteady_defeated.animations = a6;
	animation = DATA32(a6);
	set_animation(0u, a0, animation);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

uint32_t enemy_rocksteady_defeated_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0, d7_2 = 0;
	uint8_t t1 = 0;

	move_object_with_height_blocked(a0);
	a6 = record_0500A2_ADDRESS;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	t1 = bosses_left;
	bosses_left = t1 - 1u;
	if (t1 == 1u)
	{
		boss_defeated = 1u;
		d7 &= ~0xFFFFu;
		music = d7;
		queue_sound((uint8_t)d7, a6);
	}
	d7_2 = (d7 & ~0xFFu) | 0x8Bu;
	queue_sound((uint8_t)d7_2, a6);
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = mem_read32(OBJECT(a0)->enemy_rocksteady_defeated.animations + 4u);
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_rocksteady_defeated_slide(uint32_t a0)
{
	uint32_t a6 = 0;

	if ((uint16_t)OBJECT(a0)->x_speed != 0u)
	{
		move_object_blocked(a0);
		a6 = record_0500A2_ADDRESS;
		enemy_arc_step(a0, a6);
	}
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy_rocksteady_defeated.blink_time = 0x78u;
		OBJECT(a0)->state++;
	}
}

void enemy_rocksteady_defeated_blink(uint32_t a0)
{
	uint8_t blink_time = 0, t1 = 0;

	if ((OBJECT(a0)->enemy_rocksteady_defeated.blink_time & 0x10u) == 0u)
		OBJECT(a0)->flags ^= 0x80u;
	blink_time = OBJECT(a0)->enemy_rocksteady_defeated.blink_time;
	OBJECT(a0)->enemy_rocksteady_defeated.blink_time = blink_time - 1u;
	if (blink_time == 1u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
			enemies_on_screen = 0u;
	}
}

/* Bebop comes in alone or beside Rocksteady, counted as a boss */
void enemy_bebop_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0, animation = 0;

	enemy_nearest_turtles(a0, p_d5, p_d7, p_a5, &a6);
	OBJECT(a0)->enemy_bebop.target = a6;
	OBJECT(a0)->enemy_bebop.retarget_time = 0x10u;
	OBJECT(a0)->enemy_bebop.move_time = 0u;
	OBJECT(a0)->enemy_bebop.plan = 0u;
	OBJECT(a0)->depth = 4u;
	OBJECT(a0)->enemy_bebop.punch_delay = 3u;
	OBJECT(a0)->shadow = sprite_lists_059A18_ADDRESS;
	enemies_on_screen++;
	bosses_left++;
	if (OBJECT(a0)->parameter != 0u)
	{
		OBJECT(a0)->floor_height = 0u;
		pincer_charge_wait = 0x168u;
		no_pincer_charge = 0u;
		pincer_charge = 0u;
		OBJECT(a0)->parameter = 0xEu;
		OBJECT(a0)->routine = 1u;
		OBJECT(a0)->state = 6u;
		OBJECT(a0)->flags |= 0x80u;
		animation = 0x5A5AEu;
		set_animation(0u, a0, animation);
		return;
	}
	OBJECT(a0)->flags |= 0x80u;
	animation = 0x5A5E6u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->frame_time = 0u;
	OBJECT(a0)->floor_height = 0x28u;
	no_pincer_charge = 0xFFu;
	OBJECT(a0)->routine++;
	OBJECT(a0)->parameter = 0xCu;
	a6_2 = 0xD094u;
	*p_d7 = (*p_d7 & ~0xFFFFu) | 0x43Cu;
	*p_a5 = post_palette_request((uint16_t)*p_d7, a6_2);
}

/* his way in: drops in, then jumps forward to the ground, or waits for Rocksteady and walks in */
void enemy_bebop_enter(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050286_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_bebop_enter_wait_for_scroll(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (LAYER(LAYER_B)->x < 0x8C000u)
		return d7;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_bebop_enter.timer = 0x5Au;
	d7_2 = (d7 & ~0xFFFFu) | 0xFEu;
	music = d7_2;
	queue_sound((uint8_t)d7_2, 0u);
	a6 = 0x54756u;
	return enemy_set_health(d7_2, a0, a6);
}

void enemy_bebop_enter_wait(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_bebop_enter.timer;
	OBJECT(a0)->enemy_bebop_enter.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->state++;
		OBJECT(a0)->y_speed = 0;
		OBJECT(a0)->height_speed = 0;
		OBJECT(a0)->x_speed = 0;
	}
}

uint32_t enemy_bebop_enter_drop(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0, d7_2 = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x60u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	d7_2 = (d7 & ~0xFFu) | 0x3Eu;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->state++;
	animation = 0x5A61Eu;
	set_animation(0u, a0, animation);
	return d7_2;
}

uint32_t enemy_bebop_enter_jump(uint32_t d7, uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	OBJECT(a0)->height_speed = 0x600;
	OBJECT(a0)->x_speed = 0x100;
	OBJECT(a0)->y_speed = -0x100;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->state++;
	return enemy_bebop_enter_in_air(d7, a0);
}

uint32_t enemy_bebop_enter_in_air(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0, d7_2 = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x60u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	d7_2 = (d7 & ~0xFFu) | 0x3Fu;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->state++;
	animation = 0x5A648u;
	set_animation(0u, a0, animation);
	return enemy_bebop_enter_ready(d7_2, a0);
}

uint32_t enemy_bebop_enter_ready(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->flags |= 2u;
	d7_2 = (d7 & ~0xFFFFu) | 0x64u;
	music = d7_2;
	queue_sound((uint8_t)d7_2, 0u);
	return d7_2;
}

void enemy_bebop_enter_wait_for_signal(uint32_t a0)
{
	uint32_t animation = 0;

	if (bosses_come_out == 0u)
		return;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_bebop_enter.walk_time = 0x20u;
	animation = animations_05A430_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_bebop_enter_walk_in(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0;
	uint8_t walk_time = 0;

	walk_time = OBJECT(a0)->enemy_bebop_enter.walk_time;
	OBJECT(a0)->enemy_bebop_enter.walk_time = walk_time - 1u;
	if (walk_time == 1u)
	{
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		a6 = 0x54776u;
		enemy_set_health(d7, a0, a6);
		a6 = 0xD094u;
		d7 = 0x43Eu;
		*p_a5 = post_palette_request((uint16_t)d7, a6);
	}
	OBJECT(a0)->y -= 0x100u;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* his thinking: his two taunts, the pincer charge with Rocksteady, a punch when close, an attack or a
   move by plan */
void enemy_bebop_think(uint32_t d0, uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t zero = 0;
	uint8_t d6 = 0;
	uint16_t d0_2 = 0, screen_x = 0, screen_y = 0;
	uint32_t a6_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;
	uint8_t retarget_time = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	*p_d7 = (*p_d7 & ~0xFFu) | OBJECT(a0)->parameter;
	enemy_flash_when_weak((uint8_t)*p_d7, a0);
	if (area == 2u)
	{
		if (bebop_exchange_lines == 0u && time_since_balloon >= 0x80u)
		{
			d0 = (d0 & ~0xFFu) | 0xFFu;
			if ((OBJECT(a0)->flags & 0x40u) != 0u)
				d0 &= ~0xFFu;
			screen_x = OBJECT(a0)->screen_x;
			screen_y = OBJECT(a0)->screen_y;
			say_youre_dead_shell_brain(screen_x, screen_y, &d0, p_d5, p_d7, &a6);
		}
		if (bebop_exchange_lines == 2u && time_since_balloon >= 0x60u)
		{
			d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
			if ((OBJECT(a0)->flags & 0x40u) != 0u)
				d0_2 &= ~0xFFu;
			screen_x = OBJECT(a0)->screen_x;
			screen_y = OBJECT(a0)->screen_y;
			say_watch_your_mouth(d0_2, screen_x, screen_y, p_d5, p_d7, &a6);
		}
	}
	retarget_time = OBJECT(a0)->enemy_bebop.retarget_time;
	OBJECT(a0)->enemy_bebop.retarget_time = retarget_time - 1u;
	if (retarget_time == 1u)
	{
		OBJECT(a0)->enemy_bebop.retarget_time = 0x10u;
		if (turtles_in_play != 0u)
		{
			enemy_nearest_turtles(a0, p_d5, p_d7, p_a5, &a6);
			OBJECT(a0)->enemy_bebop.target = a6;
		}
	}
	*p_a1 = 0x60000u | OBJECT(a0)->enemy_bebop.target;
	turtle = *p_a1;
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	OBJECT(a0)->contacts &= 0xE0u;
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	enemy_keep_on_screen(a0);
	if (no_pincer_charge == 0u)
	{
		t1 = pincer_charge_wait;
		pincer_charge_wait = t1 - 1u;
		if (t1 == 1u)
		{
			pincer_charge_wait = 0x1Eu;
			pincer_charge = 1u;
			pincer_charge_target = *p_a1;
			pincer_charge_edges = 0u;
			pincer_charge_at_edges = 0u;
			pincer_charge_crash = 0u;
			OBJECT(a0)->enemy_bebop.move = 0x84u;
			OBJECT(a0)->routine = 3u;
			OBJECT(a0)->state = 0u;
			return;
		}
	}
	if (OBJECT(*p_a1)->routine != 4u || indexed_table_of_8_bit_values_048C5E[OBJECT(*p_a1)->turtle.hit_reaction] != 0u)
	{
		enemy_on_screen(a0, p_d7, &zero);
		if (zero)
		{
			if (OBJECT(a0)->enemy_bebop.target_dx >= 0x28u)
			{
				a6_2 = table_loaded_by_lea_0505E2_ADDRESS + (uint16_t)((OBJECT(a0)->enemy_bebop.plan & 3u) << 3);
				*p_d7 = 0x64u;
				*p_d7 = random_below((uint16_t)*p_d7, a0);
				if (*p_d7 < DATA16(a6_2 + 6u) && OBJECT(a0)->enemy_bebop.target_dy <= DATA16(a6_2) && OBJECT(a0)->enemy_bebop.target_dx <= DATA16(a6_2 + 2u))
				{
					OBJECT(a0)->enemy_bebop.move = DATA16(a6_2 + 4u);
					OBJECT(a0)->routine = 3u;
					OBJECT(a0)->state = 0u;
					OBJECT(a0)->flags &= ~8u;
					return;
				}
			}
			else if (OBJECT(a0)->enemy_bebop.target_dy < 5u)
			{
				OBJECT(a0)->enemy_bebop.move = 0x7Cu;
				OBJECT(a0)->routine = 3u;
				OBJECT(a0)->state = 0u;
				OBJECT(a0)->flags &= ~8u;
				return;
			}
		}
	}
	if (OBJECT(a0)->enemy_bebop.move_time == 0u)
	{
		a6_2 = 0x50602u;
		*p_d7 = 0x64u;
		*p_d7 = random_below((uint16_t)*p_d7, a0);
		d6 = 0u;
		for (;;)
		{
			t2 = DATA16(a6_2);
			t3 = *p_d7;
			*p_d7 = (uint16_t)(t3 - t2);
			if (t3 < t2)
				break;
			d6++;
			a6_2 += 4u;
			if (d6 >= 4u)
			{
				a6_2 = 0x50602u;
				d6 = 0u;
				break;
			}
		}
		OBJECT(a0)->enemy_bebop.plan = d6;
		OBJECT(a0)->enemy_bebop.move = DATA16(a6_2 + 2u);
		OBJECT(a0)->state = 0u;
	}
	switch ((uint32_t)(int16_t)OBJECT(a0)->enemy_bebop.move)
	{
	case 20:
		enemy_shuffle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 28:
		enemy_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 36:
		enemy_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0:
		enemy_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 4:
		enemy_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 8:
		enemy_keep_distance(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 12:
		enemy_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 16:
		enemy_run_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 44:
		enemy_walk_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 48:
		enemy_walk_to_target_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 52:
		enemy_walk_to_side_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 24:
		enemy_walk_past_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 32:
		enemy_back_off_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 40:
		enemy_walk_to_line_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 56:
		enemy_walk_to_target_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 60:
		enemy_walk_to_side_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 68:
		enemy_stalk_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 64:
		enemy_walk_away_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 72:
		enemy_walk_to_target_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 76:
		enemy_walk_to_side_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 104:
		enemy_walk_off_line_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 108:
		enemy_back_off_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 112:
		enemy_step_aside_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 80:
		enemy_walk_to_target_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 84:
		enemy_walk_to_side_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 116:
		enemy_circle_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 124:
		enemy_keep_distance_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 120:
		enemy_back_off_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 128:
		enemy_step_aside_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 88:
		enemy_walk_to_target_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 92:
		enemy_walk_to_side_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 152:
		enemy_walk_to_range_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 140:
		enemy_back_off_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 144:
		enemy_run_away_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 96:
		enemy_walk_to_target_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 100:
		enemy_walk_to_side_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 148:
		enemy_walk_to_range_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 132:
		enemy_back_off_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 136:
		enemy_run_away_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 196:
		enemy_rocksteady_raise_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 200:
		enemy_rocksteady_laugh(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 192:
		enemy_rocksteady_shake_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 184:
		enemy_rocksteady_draw_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 188:
		enemy_rocksteady_put_gun_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 204:
		enemy_rocksteady_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 208:
		enemy_rocksteady_line_up(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 212:
		enemy_rocksteady_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 232:
		enemy_rocksteady_shoot_around(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 228:
		enemy_bebop_stand(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 216:
		enemy_bebop_walk_to_front(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 224:
		enemy_bebop_walk_level(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 220:
		enemy_bebop_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 156:
		enemy_mouser_chase(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 164:
		enemy_mouser_creep_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 160:
		enemy_mouser_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 172:
		enemy_rodney_rush(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 176:
		enemy_rodney_rush_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 180:
		enemy_rodney_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 236:
		enemy_shredder_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 240:
		enemy_shredder_split(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 168:
		enemy_shredder_clone_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 244:
		enemy_shredder_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 248:
		enemy_shredder_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 252:
		enemy_shredder_guard(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 256:
		enemy_shredder_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

/* his attack, flashing when weak */
void enemy_bebop_attack(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | OBJECT(a0)->parameter;
	enemy_flash_when_weak((uint8_t)d7_2, a0);
	*p_d7 = d7_2;
	enemy_boss_attack_move(a0, p_d5, p_d7, p_a1, p_a5);
}

/* hit: his reaction by what is left of his health and where the hit came from */
void enemy_bebop_hit(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x82u;
	queue_sound((uint8_t)d7_2, 0u);
	pincer_charge = 0u;
	d0 = 0xB8u;
	if ((OBJECT(a0)->health_bars | OBJECT(a0)->health) != 0u)
	{
		d0 = 0xB4u;
		if (OBJECT(a0)->health != 0u)
		{
			if ((int8_t)(((uint32_t)OBJECT(a0)->flags << 1) ^ OBJECT(a0)->hit) >= 0)
				d0 = 0xACu;
			else
				d0 = 0xB0u;
		}
	}
	OBJECT(a0)->enemy_bebop.move = d0;
	OBJECT(a0)->routine++;
	*p_d7 = d7_2;
	enemy_bebop_react(a0, p_d5, p_d7, p_a1, p_a5);
}

/* his reaction to a hit, flashing when weak */
void enemy_bebop_react(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | OBJECT(a0)->parameter;
	enemy_flash_when_weak((uint8_t)d7_2, a0);
	*p_d7 = d7_2;
	enemy_boss_react_move(a0, p_d5, p_d7, p_a1, p_a5);
}

/* stands facing his turtle */
void enemy_bebop_stand(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05068A_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_bebop_stand_start(uint32_t a0, uint32_t a1)
{
	uint32_t animation = 0, d7 = 0;

	enemy_boss_face_target(a0, a1);
	OBJECT(a0)->enemy_bebop.move_time = 0x78u;
	OBJECT(a0)->state++;
	d7 = 4u;
	d7 = random_below((uint16_t)d7, a0);
	d7 = d7 & 3u;
	d7 = (uint16_t)(d7 << 2);
	animation = animations_050692[d7 / 4u];
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_bebop_stand_wait(uint32_t a0)
{
	OBJECT(a0)->enemy_bebop.move_time--;
}

/* walks to his turtle's front */
void enemy_bebop_walk_to_front(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0506E4_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_bebop_walk_to_front_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	OBJECT(a0)->enemy_bebop.move_time = 0xF0u;
	OBJECT(a0)->enemy_bebop.timer = 1u;
	OBJECT(a0)->state++;
	animation = animations_05A430_ADDRESS;
	set_animation(0u, a0, animation);
	enemy_bebop_walk_to_front_step(a0, a1, p_d7, p_a5);
}

void enemy_bebop_walk_to_front_step(uint32_t a0, uint32_t turtle, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1_2 = 0;
	uint32_t d0 = 0, d1 = 0, d2 = 0, d6 = 0;
	uint8_t timer = 0;

	OBJECT(a0)->enemy_bebop.move_time--;
	timer = OBJECT(a0)->enemy_bebop.timer;
	OBJECT(a0)->enemy_bebop.timer = timer - 1u;
	if (timer != 1u)
	{
		move_object_blocked(a0);
		return;
	}
	enemy_boss_face_target(a0, turtle);
	d1 = 0x50u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		d1 = (uint16_t)(0u - d1);
	d1 = (uint16_t)(d1 + OBJECT(turtle)->screen_x);
	d2 = OBJECT(turtle)->screen_y;
	direction_to(a0, &d0, &d1, &d2);
	d1_2 = 0x200u;
	speeds_from_direction((uint8_t)d0, d1_2, &d6, p_d7, p_a5);
	d6 = (uint16_t)((int16_t)d6 >> 1);
	if (OBJECT(a0)->enemy_bebop.target_dx <= 0x50u)
		d6 = (uint16_t)((int16_t)d6 >> 1);
	if (OBJECT(a0)->enemy_bebop.target_dy <= 2u)
		*p_d7 = (uint16_t)((int16_t)*p_d7 >> 1);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->enemy_bebop.timer = 4u;
	move_object_blocked(a0);
}

/* walks level with his turtle, then to it */
void enemy_bebop_walk_level(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05077C_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_bebop_walk_level_step(uint32_t a0, uint32_t a1)
{
	uint8_t timer = 0;

	OBJECT(a0)->enemy_bebop.move_time--;
	timer = OBJECT(a0)->enemy_bebop.timer;
	OBJECT(a0)->enemy_bebop.timer = timer - 1u;
	if (timer != 1u)
	{
		move_object_blocked(a0);
		return;
	}
	enemy_boss_face_target(a0, a1);
	if (OBJECT(a0)->enemy_bebop.target_dy > 4u)
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = 0x100;
		if ((int8_t)OBJECT(a0)->enemy_bebop.target_direction >= 0)
			OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
		OBJECT(a0)->enemy_bebop.timer = 4u;
		move_object_blocked(a0);
		return;
	}
	OBJECT(a0)->x_speed = 0x80;
	OBJECT(a0)->y_speed = 0;
	if (OBJECT(a0)->enemy_bebop.target_dx >= 0x50u)
		OBJECT(a0)->x_speed = 0x100;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		OBJECT(a0)->enemy_bebop.timer = 4u;
		move_object_blocked(a0);
		return;
	}
	OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	OBJECT(a0)->enemy_bebop.timer = 4u;
	move_object_blocked(a0);
}

/* walks up close to his turtle */
void enemy_bebop_close_in(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0507FA_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

/* starts one of his walks */
void enemy_bebop_walk_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	OBJECT(a0)->enemy_bebop.move_time = 0xF0u;
	OBJECT(a0)->enemy_bebop.timer = 1u;
	OBJECT(a0)->state++;
	animation = animations_05A430_ADDRESS;
	set_animation(0u, a0, animation);
	enemy_bebop_close_in_step(a0, a1, p_d7, p_a5);
}

void enemy_bebop_close_in_step(uint32_t a0, uint32_t turtle, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1_2 = 0;
	uint32_t d0 = 0, d1 = 0, d2 = 0, d6 = 0;
	uint8_t timer = 0;

	OBJECT(a0)->enemy_bebop.move_time--;
	timer = OBJECT(a0)->enemy_bebop.timer;
	OBJECT(a0)->enemy_bebop.timer = timer - 1u;
	if (timer != 1u)
	{
		move_object_blocked(a0);
		return;
	}
	enemy_boss_face_target(a0, turtle);
	if (OBJECT(a0)->enemy_bebop.target_dy > 4u)
	{
		d1 = 0x30u;
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
			d1 = (uint16_t)(0u - d1);
		d1 = (uint16_t)(d1 + OBJECT(turtle)->screen_x);
		d2 = OBJECT(turtle)->screen_y;
		direction_to(a0, &d0, &d1, &d2);
		d1_2 = 0x180u;
		speeds_from_direction((uint8_t)d0, d1_2, &d6, p_d7, p_a5);
		OBJECT(a0)->x_speed = d6;
		OBJECT(a0)->y_speed = *p_d7;
	}
	else
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = 0;
		if ((uint16_t)OBJECT(a0)->x_speed >= 0x10u)
		{
			OBJECT(a0)->x_speed = 0x100;
			if ((OBJECT(a0)->flags & 0x40u) == 0u)
				OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		}
	}
	OBJECT(a0)->enemy_bebop.timer = 4u;
	move_object_blocked(a0);
}

/* charges across from his edge while Rocksteady charges from the other, crashing into him */
void enemy_bebop_pincer_charge(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0508D8_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
	if (pincer_charge == 0u && pincer_charge_crash == 0u)
	{
		OBJECT(a0)->flags &= ~4u;
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_bebop.move_time = 0u;
	}
}

void enemy_bebop_pincer_charge_start(uint32_t a0)
{
	uint32_t animation = 0;

	animation = animations_05A430_ADDRESS;
	set_animation(0u, a0, animation);
	enemy_pincer_charge_take_edge(a0);
}

/* takes a free edge of the screen for the pincer charge and runs to it */
void enemy_pincer_charge_take_edge(uint32_t a0)
{
	uint8_t t1 = 0, t2 = 0;

	OBJECT(a0)->enemy.side = 0u;
	if (OBJECT(a0)->screen_x < 0x100u)
	{
		t1 = pincer_charge_edges;
		pincer_charge_edges = t1 | 0x40u;
		if ((t1 & 0x40u) == 0u)
		{
			OBJECT(a0)->enemy.side |= 0x40u;
			OBJECT(a0)->flags &= 0xBFu;
			OBJECT(a0)->x_speed = -0x200;
			OBJECT(a0)->y_speed = 0;
			OBJECT(a0)->state++;
			return;
		}
	}
	do
	{
		t2 = pincer_charge_edges;
		pincer_charge_edges = t2 | 0x80u;
		if ((t2 & 0x80u) == 0u)
		{
			OBJECT(a0)->enemy.side |= 0x80u;
			OBJECT(a0)->flags |= 0x40u;
			OBJECT(a0)->x_speed = 0x200;
			OBJECT(a0)->y_speed = 0;
			OBJECT(a0)->state++;
			return;
		}
		t1 = pincer_charge_edges;
		pincer_charge_edges = t1 | 0x40u;
	} while ((t1 & 0x40u) != 0u);
	OBJECT(a0)->enemy.side |= 0x40u;
	OBJECT(a0)->flags &= 0xBFu;
	OBJECT(a0)->x_speed = -0x200;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->state++;
}

void enemy_bebop_pincer_charge_run_to_edge(uint32_t a0)
{
	uint8_t d0 = 0;

	move_object_blocked(a0);
	d0 = 8u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & OBJECT(a0)->contacts) != 0u)
	{
		OBJECT(a0)->flags ^= 0x40u;
		pincer_charge_at_edges |= OBJECT(a0)->enemy_bebop.side;
		OBJECT(a0)->state++;
	}
}

void enemy_bebop_pincer_charge_wait_for_rocksteady(uint32_t a0)
{
	uint32_t animation = 0;

	if (pincer_charge_at_edges < 0xC0u)
		return;
	animation = animations_05A930_ADDRESS;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x103u;
	OBJECT(a0)->attack = 7u;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->attack |= 0x80u;
	OBJECT(a0)->flags &= ~0xAu;
	OBJECT(a0)->enemy_bebop.move_time = 0x1Eu;
	OBJECT(a0)->state++;
}

void enemy_bebop_pincer_charge_get_ready(uint32_t a0)
{
	enemy_bebop_charge_get_ready(a0);
}

uint32_t enemy_bebop_pincer_charge_run(uint32_t d7, uint32_t a0)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t animation = 0, d1_2 = 0, d7_2 = 0, ignored = 0, ignored_2 = 0, object = 0;
	uint8_t t1 = 0;

	d0 = 8u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & OBJECT(a0)->contacts) != 0u)
	{
		pincer_charge = 0u;
		pincer_charge_wait = 0x168u;
		return d7;
	}
	d1 = 0u;
	if (OBJECT(a0)->enemy_bebop.target_dy >= 3u)
	{
		d1 = 0x200u;
		if ((int8_t)OBJECT(a0)->enemy_bebop.target_direction >= 0)
			d1 = (uint16_t)(0u - d1);
	}
	OBJECT(a0)->y_speed = d1;
	move_object_blocked(a0);
	object = rocksteady;
	enemy_look_at_target(a0, object, &ignored, &ignored_2);
	OBJECT(a0)->enemy_bebop.target_direction -= 0x40u;
	t1 = OBJECT(a0)->enemy_bebop.target_direction ^ ((uint32_t)OBJECT(a0)->flags << 1);
	OBJECT(a0)->enemy_bebop.target_direction = t1;
	if ((int8_t)t1 < 0 || OBJECT(a0)->enemy_bebop.target_dx >= 0x38u || OBJECT(a0)->enemy_bebop.target_dy >= 5u)
		return d7;
	OBJECT(a0)->flags &= ~4u;
	OBJECT(a0)->state++;
	pincer_charge_crash = 1u;
	OBJECT(object)->y = OBJECT(a0)->y;
	OBJECT(object)->y += 0x200u;
	d1_2 = 0x4000u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		d1_2 = (uint16_t)(0u - d1_2);
	OBJECT(object)->x = (int16_t)d1_2 + OBJECT(a0)->x;
	OBJECT(object)->attacker = a0;
	OBJECT(a0)->attacker = object;
	animation = 0x5AD12u;
	set_animation(d1_2, a0, animation);
	d7_2 = (d7 & ~0xFFu) | 0x3Eu;
	queue_sound((uint8_t)d7_2, animation);
	d7 = (d7_2 & ~0xFFu) | 0x8Fu;
	queue_sound((uint8_t)d7, animation);
	return d7;
}

void enemy_bebop_pincer_charge_crash(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		pincer_charge = 0u;
		pincer_charge_wait = 0x708u;
		OBJECT(a0)->enemy_bebop.move = 0xB4u;
		OBJECT(a0)->routine = 5u;
		OBJECT(a0)->state = 0u;
	}
}

/* punches, lunging when he strikes back */
void enemy_bebop_punch(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050AE8_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_bebop_punch_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;
	uint8_t flags = 0;

	OBJECT(a0)->animation_delay = OBJECT(a0)->enemy_bebop.punch_delay;
	OBJECT(a0)->damage = 0x203u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	flags = OBJECT(a0)->flags;
	OBJECT(a0)->flags = flags | 2u;
	if ((flags & 2u) == 0u && turtles_in_play >= 2u)
		OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	animation = animations_05A9BE_ADDRESS;
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_bebop_punch_end(uint32_t a0)
{
	uint16_t d0 = 0;

	if (OBJECT(a0)->animation_delay != 1u || OBJECT(a0)->enemy_bebop.target_dx < 0x28u)
	{
		if (OBJECT(a0)->frame_time == 0u)
		{
			OBJECT(a0)->animation_delay = 0u;
			OBJECT(a0)->enemy_bebop.punch_delay = 3u;
			OBJECT(a0)->flags &= ~4u;
			OBJECT(a0)->flags |= 2u;
			OBJECT(a0)->routine = 2u;
			OBJECT(a0)->state = 0u;
			OBJECT(a0)->enemy_bebop.move_time = 0u;
		}
		return;
	}
	d0 = 0x80u;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
		d0 = (uint16_t)(0u - d0);
	OBJECT(a0)->x += (int16_t)d0;
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->animation_delay = 0u;
		OBJECT(a0)->enemy_bebop.punch_delay = 3u;
		OBJECT(a0)->flags &= ~4u;
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_bebop.move_time = 0u;
	}
}

/* charges across the screen */
void enemy_bebop_charge(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050B98_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_bebop_charge_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = animations_05A930_ADDRESS;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x103u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags &= ~0xAu;
	OBJECT(a0)->enemy_bebop.move_time = 0x1Eu;
	OBJECT(a0)->state++;
	return d7_2;
}

void enemy_bebop_charge_get_ready(uint32_t a0)
{
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy_bebop.move_time;
	OBJECT(a0)->enemy_bebop.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->x_speed = -0x380;
	OBJECT(a0)->y_speed = 0;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	OBJECT(a0)->state++;
}

void enemy_bebop_charge_run(uint32_t a0)
{
	uint8_t contacts = 0;
	uint16_t d1 = 0;

	contacts = OBJECT(a0)->contacts;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		if ((contacts & 8u) == 0u)
		{
			d1 = 0u;
			if (OBJECT(a0)->enemy_bebop.target_dy >= 3u)
			{
				d1 = 0x200u;
				if ((int8_t)OBJECT(a0)->enemy_bebop.target_direction >= 0)
					d1 = (uint16_t)(0u - d1);
			}
			OBJECT(a0)->y_speed = d1;
			move_object_blocked(a0);
			return;
		}
	}
	else if ((contacts & 0x10u) == 0u)
	{
		d1 = 0u;
		if (OBJECT(a0)->enemy_bebop.target_dy >= 3u)
		{
			d1 = 0x200u;
			if ((int8_t)OBJECT(a0)->enemy_bebop.target_direction >= 0)
				d1 = (uint16_t)(0u - d1);
		}
		OBJECT(a0)->y_speed = d1;
		move_object_blocked(a0);
		return;
	}
	OBJECT(a0)->flags &= ~4u;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->enemy_bebop.move = 0xD8u;
	OBJECT(a0)->enemy_bebop.plan = 0u;
	OBJECT(a0)->enemy_bebop.move_time = 1u;
}

/* fires three shots */
void enemy_bebop_shoot(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050C74_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_bebop_shoot_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_bebop_shoot.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->enemy_bebop_shoot.shot_time = 0x14u;
	OBJECT(a0)->enemy_bebop_shoot.shots_left = 3u;
	OBJECT(a0)->state++;
	animation = animations_05A77E_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_bebop_shoot_fire(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t ignored = 0;
	uint8_t shot_time = 0, shots_left = 0;

	shot_time = OBJECT(a0)->enemy_bebop_shoot.shot_time;
	OBJECT(a0)->enemy_bebop_shoot.shot_time = shot_time - 1u;
	if (shot_time == 1u)
	{
		d7_2 = 2u;
		queue_sound(d7_2, 0u);
		*p_a5 = 0x50C7Cu;
		start_shot(a0, *p_a5, &d7, &ignored, &zero);
		OBJECT(a0)->enemy_bebop_shoot.shot_time = 0xCu;
		shots_left = OBJECT(a0)->enemy_bebop_shoot.shots_left;
		OBJECT(a0)->enemy_bebop_shoot.shots_left = shots_left - 1u;
		if (shots_left == 1u)
		{
			OBJECT(a0)->routine = 2u;
			OBJECT(a0)->state = 0u;
			OBJECT(a0)->enemy_bebop_shoot.move_time = 0u;
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* hit from the front, then strikes back */
void enemy_bebop_flinch(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050CF2_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_bebop_flinch_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	animation = 0x5AB38u;
	set_animation(0u, a0, animation);
}

/* punches at once after a hit */
void enemy_bebop_strike_back(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine = 3u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_bebop.move = 0x7Cu;
		OBJECT(a0)->enemy_bebop.plan = 1u;
		OBJECT(a0)->enemy_bebop.punch_delay = 1u;
	}
}

/* hit from behind, then strikes back */
void enemy_bebop_flinch_from_behind(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050D38_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_bebop_flinch_from_behind_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_bebop.move_time = 0x30u;
	animation = animations_05AAF6_ADDRESS;
	set_animation(0u, a0, animation);
}

void enemy_bebop_flinch_from_behind_end(uint32_t a0)
{
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy_bebop.move_time;
	OBJECT(a0)->enemy_bebop.move_time = move_time - 1u;
	if (move_time == 1u)
	{
		OBJECT(a0)->routine = 3u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_bebop.move = 0x7Cu;
		OBJECT(a0)->enemy_bebop.plan = 1u;
		OBJECT(a0)->enemy_bebop.punch_delay = 1u;
	}
}

/* knocked down, lies, gets up with his health back and strikes back */
void enemy_bebop_knocked_down(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050D84_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_bebop_knocked_down_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	enemy_boss_face_target(a0, a1);
	a6 = 0x50D98u;
	d7 = enemy_start_arc(d7, a0, a6);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	animation = 0x5AB58u;
	set_animation(0u, a0, animation);
	return d7;
}

uint32_t enemy_bebop_knocked_down_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	move_object_with_height_blocked(a0);
	a6 = 0x50D98u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x5AB6Eu;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_bebop_knocked_down_slide(uint32_t a0)
{
	uint32_t a6 = 0;

	if ((uint16_t)OBJECT(a0)->x_speed != 0u)
	{
		move_object_blocked(a0);
		a6 = 0x50D98u;
		enemy_arc_step(a0, a6);
	}
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy_bebop.timer = 0x14u;
		OBJECT(a0)->state++;
	}
}

uint32_t enemy_bebop_knocked_down_lie(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_bebop.timer;
	OBJECT(a0)->enemy_bebop.timer = timer - 1u;
	if (timer != 1u)
		return d7;
	OBJECT(a0)->state++;
	a6 = 0x54756u;
	if (area != 3u)
		a6 = 0x54776u;
	d7 = enemy_refill_health(d7, a0, a6);
	animation = 0x5AB7Au;
	set_animation(0u, a0, animation);
	return d7;
}

/* defeated: falls, the last boss clears the area, blinks and is gone */
void enemy_bebop_defeated(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050E72_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_bebop_defeated_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	no_pincer_charge = 0xFFu;
	enemy_boss_face_target(a0, a1);
	a6 = 0x50E82u;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x5AB9Au;
	set_animation(0u, a0, animation);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

uint32_t enemy_bebop_defeated_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0, d7_2 = 0;
	uint8_t t1 = 0;

	move_object_with_height_blocked(a0);
	a6 = 0x50E82u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	t1 = bosses_left;
	bosses_left = t1 - 1u;
	if (t1 == 1u)
	{
		boss_defeated = 1u;
		d7 &= ~0xFFFFu;
		music = d7;
		queue_sound((uint8_t)d7, a6);
	}
	d7_2 = (d7 & ~0xFFu) | 0x8Bu;
	queue_sound((uint8_t)d7_2, a6);
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x5ABBAu;
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_bebop_defeated_slide(uint32_t a0)
{
	uint32_t a6 = 0;

	if ((uint16_t)OBJECT(a0)->x_speed != 0u)
	{
		move_object_blocked(a0);
		a6 = 0x50E82u;
		enemy_arc_step(a0, a6);
	}
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy_bebop.timer = 0x78u;
		OBJECT(a0)->state++;
	}
}

void enemy_bebop_defeated_blink(uint32_t a0)
{
	uint8_t timer = 0, t1 = 0;

	if ((OBJECT(a0)->enemy_bebop.timer & 0x10u) == 0u)
		OBJECT(a0)->flags ^= 0x80u;
	timer = OBJECT(a0)->enemy_bebop.timer;
	OBJECT(a0)->enemy_bebop.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
			enemies_on_screen = 0u;
	}
}

/* a Mouser: one bar, thinking at once, hopping in or on the floor by its parameter */
void enemy_mouser_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;
	uint8_t parameter = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy_mouser.target = a6;
	OBJECT(a0)->enemy_mouser.retarget_time = 0x10u;
	OBJECT(a0)->enemy_mouser.move_time = 0u;
	OBJECT(a0)->enemy_mouser.approach = 0u;
	OBJECT(a0)->depth = 4u;
	enemies_on_screen++;
	OBJECT(a0)->health_bars = 1u;
	OBJECT(a0)->health = 1u;
	OBJECT(a0)->shadow = sprite_lists_0582B4_ADDRESS;
	parameter = OBJECT(a0)->parameter;
	OBJECT(a0)->parameter = parameter & 0x7Fu;
	if ((parameter & 0x80u) != 0u)
	{
		OBJECT(a0)->flags |= 0x82u;
		OBJECT(a0)->routine += 2u;
		animation = 0x5811Au;
		set_animation(0u, a0, animation);
	}
	else if (OBJECT(a0)->parameter == 0u)
	{
		enemy_set_floor(a0);
		OBJECT(a0)->flags |= 0x82u;
		OBJECT(a0)->routine += 2u;
		animation = 0x5811Au;
		set_animation(0u, a0, animation);
	}
	else
		OBJECT(a0)->routine++;
}

/* hops in from its parameter's height onto the floor */
void enemy_mouser_enter(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05100E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_mouser_enter_start(uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->state++;
	d0 = OBJECT(a0)->parameter;
	d0 = (uint8_t)(d0 - 1u);
	OBJECT(a0)->parameter = (uint8_t)d0;
	OBJECT(a0)->floor_height = DATA8(rom_051036_ADDRESS + d0);
	animation = DATA32(animations_05101E_ADDRESS + (uint16_t)((uint32_t)d0 << 2));
	set_animation(0u, a0, animation);
}

void enemy_mouser_enter_hop(uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->flags |= 2u;
	d0 = (uint16_t)((uint32_t)OBJECT(a0)->parameter << 2);
	OBJECT(a0)->y_speed = indexed_table_of_16_bit_values_05102A[d0 / 2u];
	OBJECT(a0)->height_speed = rom_05102C[d0 / 2u];
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->height += 0x1000u;
	OBJECT(a0)->state++;
	animation = 0x581BAu;
	set_animation(0u, a0, animation);
}

uint32_t enemy_mouser_enter_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0, d7_2 = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->state++;
	d7_2 = (d7 & ~0xFFu) | 0x39u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = 0x581C4u;
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_mouser_enter_land(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
	}
}

/* goes after the turtle with the fewest enemies and bites it; breaks down when the boss is beaten */
void enemy_mouser_think(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	bool L_051210 = false;
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6_2 = 0, d0_2 = 0, d1 = 0, d2 = 0, d3 = 0, ignored = 0, ignored_2 = 0, turtle = 0;
	uint8_t retarget_time = 0, t3 = 0, t4 = 0, t5 = 0;
	uint32_t t1 = 0, t2 = 0;

	*p_a1 = 0x60000u | OBJECT(a0)->enemy_mouser.target;
	retarget_time = OBJECT(a0)->enemy_mouser.retarget_time;
	OBJECT(a0)->enemy_mouser.retarget_time = retarget_time - 1u;
	if (retarget_time == 1u)
	{
		OBJECT(a0)->enemy_mouser.retarget_time = 0x10u;
		if (turtles_in_play != 0u)
		{
			mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
			enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
			d0 = enemies_per_turtle;
			if (d0 <= PLAYER_SLOT(a6)->enemies)
			{
				t1 = *p_a5;
				*p_a5 = a6;
				a6 = t1;
				if (d0 <= mem_read8(a6 + 4u))
				{
					a6 = least_crowded_slot;
					if (d0 <= PLAYER_SLOT(a6)->enemies)
					{
						t2 = *p_a5;
						*p_a5 = a6;
						a6 = t2;
					}
				}
			}
			*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)a6;
			if ((uint16_t)*p_d7 != OBJECT(a0)->enemy_mouser.target)
				enemy_mouser_leave_side(a0, *p_a1);
			OBJECT(a0)->enemy_mouser.target = a6;
			*p_a1 = a6;
			mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
		}
	}
	if (mousers_break_down != 0u)
	{
		OBJECT(a0)->enemy_mouser.move = 0xE0u;
		OBJECT(a0)->routine = 5u;
		OBJECT(a0)->state = 0u;
		return;
	}
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		enemy_mouser_leave_side(a0, *p_a1);
		mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t3 = enemies_on_screen - 1u;
		enemies_on_screen = t3;
		if ((int8_t)t3 >= 0)
		{
			return;
		}
		enemies_on_screen = 0u;
		return;
	}
	turtle = mem_read32(*p_a1);
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	enemy_collide_with_objects(a0, p_d5, p_d7, p_a5);
	enemy_floor_contacts(a0, &d0_2, &d1, &d2, &d3, p_d5, p_d7, p_a5);
	enemy_check_floor_edge((uint8_t)d0_2, (uint8_t)d1, (uint8_t)d2, (uint8_t)d3, a0, *p_a1, p_d7, &zero);
	if (zero == 0u)
	{
		return;
	}
	if (OBJECT(a0)->enemy_mouser.approach != 0u)
	{
		if (OBJECT(a0)->enemy_mouser.approach == 1u && (OBJECT(a0)->enemy_mouser.target_dx >= 0x54u || OBJECT(a0)->enemy_mouser.target_dy >= 0x34u))
			enemy_mouser_give_side_back(a0, *p_a1);
		if (OBJECT(a0)->enemy_mouser.approach != 2u)
		{
			a6_2 = mem_read32(*p_a1);
			if (mem_read8(a6_2 + 4u) == 4u && indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] == 0u)
			{
				enemy_mouser_leave_side(a0, *p_a1);
				OBJECT(a0)->enemy_mouser.approach = 2u;
				OBJECT(a0)->enemy_mouser.move_time = 0u;
			}
		}
	}
	else if (mem_read8(*p_a1 + 7u) >= 0xC0u || OBJECT(a0)->enemy_mouser.target_dx >= 0x40u || OBJECT(a0)->enemy_mouser.target_dy >= 0x20u)
	{
		if (OBJECT(a0)->enemy_mouser.approach != 2u)
		{
			a6_2 = mem_read32(*p_a1);
			if (mem_read8(a6_2 + 4u) == 4u && indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] == 0u)
			{
				enemy_mouser_leave_side(a0, *p_a1);
				OBJECT(a0)->enemy_mouser.approach = 2u;
				OBJECT(a0)->enemy_mouser.move_time = 0u;
			}
		}
	}
	else
	{
		OBJECT(a0)->enemy_mouser.approach = 1u;
		OBJECT(a0)->enemy_mouser.move_time = 0u;
		do
		{
			if (L_051210 || (int8_t)(OBJECT(a0)->enemy_mouser.target_direction - 0x40u) < 0)
			{
				for (;;)
				{
					L_051210 = false;
					t4 = mem_read8(*p_a1 + 7u);
					mem_write8(*p_a1 + 7u, t4 | 0x40u);
					if ((t4 & 0x40u) != 0u)
					{
						t5 = mem_read8(*p_a1 + 7u);
						mem_write8(*p_a1 + 7u, t5 | 0x80u);
						if ((t5 & 0x80u) != 0u)
							continue;
						OBJECT(a0)->enemy_mouser.side &= 0x7Fu;
						break;
					}
					OBJECT(a0)->enemy_mouser.side |= 0x80u;
					break;
				}
			}
			else
			{
				t5 = mem_read8(*p_a1 + 7u);
				mem_write8(*p_a1 + 7u, t5 | 0x80u);
				L_051210 = (t5 & 0x80u) != 0u;
				if (!L_051210)
					OBJECT(a0)->enemy_mouser.side &= 0x7Fu;
			}
		} while (L_051210);
	}
	enemy_on_screen(a0, p_d7, &zero);
	if (zero && mem_read8(mem_read32(*p_a1) + 4u) != 4u && OBJECT(a0)->enemy_mouser.target_dy < 4u && OBJECT(a0)->enemy_mouser.target_dx < 0x30u)
	{
		OBJECT(a0)->routine = 3u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->flags &= ~8u;
		return;
	}
	if (OBJECT(a0)->enemy_mouser.move_time == 0u)
	{
		OBJECT(a0)->enemy_mouser.move = TABLE16(indexed_table_of_16_bit_values_0512E4, (uint32_t)(int16_t)((uint32_t)(int8_t)OBJECT(a0)->enemy_mouser.approach << 1));
		OBJECT(a0)->state = 0u;
	}
	switch ((uint32_t)(int16_t)OBJECT(a0)->enemy_mouser.move)
	{
	case 20:
		enemy_shuffle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 28:
		enemy_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 36:
		enemy_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0:
		enemy_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 4:
		enemy_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 8:
		enemy_keep_distance(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 12:
		enemy_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 16:
		enemy_run_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 44:
		enemy_walk_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 48:
		enemy_walk_to_target_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 52:
		enemy_walk_to_side_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 24:
		enemy_walk_past_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 32:
		enemy_back_off_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 40:
		enemy_walk_to_line_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 56:
		enemy_walk_to_target_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 60:
		enemy_walk_to_side_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 68:
		enemy_stalk_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 64:
		enemy_walk_away_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 72:
		enemy_walk_to_target_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 76:
		enemy_walk_to_side_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 104:
		enemy_walk_off_line_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 108:
		enemy_back_off_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 112:
		enemy_step_aside_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 80:
		enemy_walk_to_target_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 84:
		enemy_walk_to_side_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 116:
		enemy_circle_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 124:
		enemy_keep_distance_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 120:
		enemy_back_off_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 128:
		enemy_step_aside_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 88:
		enemy_walk_to_target_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 92:
		enemy_walk_to_side_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 152:
		enemy_walk_to_range_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 140:
		enemy_back_off_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 144:
		enemy_run_away_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 96:
		enemy_walk_to_target_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 100:
		enemy_walk_to_side_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 148:
		enemy_walk_to_range_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 132:
		enemy_back_off_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 136:
		enemy_run_away_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 196:
		enemy_rocksteady_raise_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 200:
		enemy_rocksteady_laugh(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 192:
		enemy_rocksteady_shake_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 184:
		enemy_rocksteady_draw_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 188:
		enemy_rocksteady_put_gun_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 204:
		enemy_rocksteady_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 208:
		enemy_rocksteady_line_up(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 212:
		enemy_rocksteady_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 232:
		enemy_rocksteady_shoot_around(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 228:
		enemy_bebop_stand(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 216:
		enemy_bebop_walk_to_front(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 224:
		enemy_bebop_walk_level(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 220:
		enemy_bebop_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 156:
		enemy_mouser_chase(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 164:
		enemy_mouser_creep_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 160:
		enemy_mouser_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 172:
		enemy_rodney_rush(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 176:
		enemy_rodney_rush_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 180:
		enemy_rodney_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 236:
		enemy_shredder_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 240:
		enemy_shredder_split(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 168:
		enemy_shredder_clone_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 244:
		enemy_shredder_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 248:
		enemy_shredder_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 252:
		enemy_shredder_guard(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 256:
		enemy_shredder_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

/* gives its side of its turtle back when it stands by it */
void enemy_mouser_leave_side(uint32_t a0, uint32_t a1)
{
	if (OBJECT(a0)->enemy_mouser.approach != 1u)
		return;
	enemy_mouser_give_side_back(a0, a1);
}

/* gives its side of its turtle back */
void enemy_mouser_give_side_back(uint32_t a0, uint32_t a1)
{
	uint8_t d0 = 0;
	uint8_t side = 0;

	d0 = 0x7Fu;
	side = OBJECT(a0)->enemy_mouser.side;
	OBJECT(a0)->enemy_mouser.side = side & 0x7Fu;
	if ((side & 0x80u) != 0u)
		d0 = 0xB7u;
	mem_write8(a1 + 7u, mem_read8(a1 + 7u) & d0);
	OBJECT(a0)->enemy_mouser.approach = 0u;
	OBJECT(a0)->enemy_mouser.move_time = 0u;
}

/* leaps at its turtle and hangs on to it, gone when the turtle is free */
void enemy_mouser_bite(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t a1 = 0, a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;

	a1 = 0x60000u | OBJECT(a0)->enemy_mouser.target;
	turtle = mem_read32(a1);
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	enemy_collide_with_objects(a0, p_d5, p_d7, p_a5);
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	a6 = indexed_table_of_32_bit_values_051340_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
	*p_a1 = a1;
}

uint32_t enemy_mouser_bite_start(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	animation = 0x58134u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x103u;
	d7_2 = (d7 & ~0xFFu) | 0x10u;
	d7_2 = enemy_face_target(d7_2, a0);
	a6 = 0x51350u;
	d7_2 = enemy_start_arc(d7_2, a0, a6);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->flags &= ~8u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_mouser.move = 0xA0u;
	return d7_2;
}

uint32_t enemy_mouser_bite_fly(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;
	uint32_t flags_halfword = 0;

	enemy_follow_stairs(a0);
	move_object_with_height_blocked(a0);
	a6 = 0x51350u;
	enemy_arc_step(a0, a6);
	if ((OBJECT(a0)->flags & 8u) != 0u)
	{
		flags_halfword = (((uint32_t)OBJECT(a0)->flags << 8u) | OBJECT(a0)->contacts) & 0x7100u;
		OBJECT(a0)->flags = (uint8_t)(flags_halfword >> 8u);
		OBJECT(a0)->contacts = (uint8_t)flags_halfword;
		OBJECT(a0)->state = 3u;
		enemy_mouser_leave_side(a0, a1);
		return d7;
	}
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->flags &= ~4u;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->enemy_mouser.move_time = 0x10u;
	OBJECT(a0)->state = 2u;
	animation = animations_058076_ADDRESS;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_mouser_bite_land(uint32_t a0)
{
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy_mouser.move_time;
	OBJECT(a0)->enemy_mouser.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	enemy_back_to_thinking(a0);
}

void enemy_mouser_bite_hold(uint32_t a0)
{
	uint8_t t1 = 0;

	if ((frame_count & 3u) == 0u && OBJECT(0x60000u | OBJECT(a0)->hit_object)->routine != 4u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
			enemies_on_screen = 0u;
	}
}

/* hit: lets go of the turtle it held and is knocked flying */
void enemy_mouser_hit(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint8_t d7 = 0;
	uint32_t object = 0;
	uint8_t flags = 0;

	d7 = 0xA8u;
	queue_sound(d7, 0u);
	flags = OBJECT(a0)->flags;
	OBJECT(a0)->flags = flags & ~8u;
	if ((flags & 8u) != 0u)
	{
		object = 0x60000u | OBJECT(a0)->hit_object;
		if (OBJECT(object)->routine == 4u)
			OBJECT(object)->unk_27 = 0x10u;
	}
	OBJECT(a0)->enemy_mouser.move = 0x90u;
	OBJECT(a0)->enemy_mouser.move_time = 0u;
	OBJECT(a0)->routine++;
	enemy_react(a0, p_d5, p_d7, p_a1, p_a5);
}

/* a step over the floor's edge */
void enemy_mouser_step_over_edge(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t a1 = 0, a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;

	a1 = 0x60000u | OBJECT(a0)->enemy_mouser.target;
	turtle = mem_read32(a1);
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	enemy_collide_with_objects(a0, p_d5, p_d7, p_a5);
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	a6 = TABLE32(indexed_table_of_32_bit_values_0514C6, (uint32_t)(int16_t)OBJECT(a0)->enemy_mouser.move);
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
	*p_a1 = a1;
}

void enemy_mouser_hop_down(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->height_speed = rom_04881C[area & 0xFu];
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0x100;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	animation = 0x58134u;
	set_animation(0u, a0, animation);
}

uint32_t enemy_mouser_hop_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	enemy_follow_stairs_up(a0);
	move_object_with_height_blocked(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->enemy_mouser.move_time = 0x10u;
	OBJECT(a0)->state++;
	animation = animations_058076_ADDRESS;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_mouser_hop_land(uint32_t a0)
{
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy_mouser.move_time;
	OBJECT(a0)->enemy_mouser.move_time = move_time - 1u;
	if (move_time == 1u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
	}
}

void enemy_mouser_hop_right(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->height_speed = rom_04881C[area & 0xFu];
	OBJECT(a0)->x_speed = 0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	OBJECT(a0)->flags |= 0x40u;
	animation = 0x58134u;
	set_animation(0u, a0, animation);
}

void enemy_mouser_hop_left(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->height_speed = rom_04881C[area & 0xFu];
	OBJECT(a0)->x_speed = -0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	OBJECT(a0)->flags &= 0xBFu;
	animation = 0x58134u;
	set_animation(0u, a0, animation);
}

void enemy_mouser_hop_up(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = -0x80;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	animation = 0x581BAu;
	set_animation(0u, a0, animation);
}

uint32_t enemy_mouser_hop_up_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	enemy_follow_stairs_down(a0);
	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->enemy_mouser.move_time = 0x10u;
	OBJECT(a0)->state++;
	animation = 0x581C4u;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_mouser_hop_up_right(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->x_speed = 0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	OBJECT(a0)->flags |= 0x40u;
	animation = 0x58134u;
	set_animation(0u, a0, animation);
}

uint32_t enemy_mouser_hop_up_fall_blocked(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t animation = 0;

	enemy_follow_stairs_down(a0);
	move_object_with_height_blocked(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->enemy_mouser.move_time = 0x10u;
	OBJECT(a0)->state++;
	animation = animations_058076_ADDRESS;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_mouser_hop_up_left(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->x_speed = -0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->flags &= ~2u;
	OBJECT(a0)->state++;
	OBJECT(a0)->flags &= 0xBFu;
	animation = 0x58134u;
	set_animation(0u, a0, animation);
}

/* chases its turtle, sitting now and then */
void enemy_mouser_chase(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05175C_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_mouser_chase_start(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = 0;

	OBJECT(a0)->enemy_mouser.move_time = 0xFFu;
	OBJECT(a0)->enemy_mouser.timer = 8u;
	d7 = 0xF0u;
	d7 = random_below((uint16_t)d7, a0);
	OBJECT(a0)->enemy_mouser.chase_time = d7;
	OBJECT(a0)->state++;
	*p_a5 = animations_05176C_ADDRESS;
	*p_d7 = d7;
	enemy_face_direction(d0, a0, p_d7, p_a5);
}

void enemy_mouser_chase_run(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d1 = 0;
	uint32_t a5 = 0, a6 = 0, d0 = 0, d6 = 0;
	uint8_t chase_time = 0, timer = 0;

	if (OBJECT(a0)->enemy_mouser.target_dx >= 0x3Eu || OBJECT(a0)->enemy_mouser.target_dy >= 0x1Eu)
	{
		chase_time = OBJECT(a0)->enemy_mouser.chase_time;
		OBJECT(a0)->enemy_mouser.chase_time = chase_time - 1u;
		if (chase_time != 1u)
		{
			timer = OBJECT(a0)->enemy_mouser.timer;
			OBJECT(a0)->enemy_mouser.timer = timer - 1u;
			if (timer == 1u)
			{
				a6 = mem_read32(a1);
				d0 = direction_to_object(0u, a0, a6);
				a5 = animations_05176C_ADDRESS;
				enemy_turn_to_direction((uint8_t)d0, a0, &d7, &a5);
				d1 = 0xC0u;
				speeds_from_direction((uint8_t)d0, d1, &d6, &d7, p_a5);
				OBJECT(a0)->x_speed = d6;
				d7 = (uint16_t)((int16_t)d7 >> 1);
				OBJECT(a0)->y_speed = d7;
				OBJECT(a0)->enemy_mouser.timer = 8u;
			}
			move_object_blocked(a0);
		}
		else
		{
			d7 = 0xF0u;
			d7 = random_below((uint16_t)d7, a0);
			OBJECT(a0)->enemy_mouser.chase_time = d7;
			OBJECT(a0)->state++;
		}
	}
	else
		OBJECT(a0)->state++;
	*p_d7 = d7;
}

uint32_t enemy_mouser_chase_pause(uint32_t a0)
{
	OBJECT(a0)->enemy_mouser.timer = 0x78u;
	return enemy_mouser_sit(a0);
}

void enemy_mouser_chase_wait(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_mouser.timer;
	OBJECT(a0)->enemy_mouser.timer = timer - 1u;
	if (timer == 1u)
		OBJECT(a0)->state = 0u;
}

/* creeps to its side of its turtle */
void enemy_mouser_creep_to_side(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_051836_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_mouser_creep_to_side_start(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	OBJECT(a0)->enemy_mouser.move_time = 0xFFu;
	OBJECT(a0)->enemy_mouser.timer = 8u;
	OBJECT(a0)->state++;
	*p_a5 = animations_05176C_ADDRESS;
	enemy_face_direction(d0, a0, p_d7, p_a5);
}

void enemy_mouser_creep_to_side_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1_2 = 0;
	uint32_t a5 = 0, a6 = 0, d0 = 0, d1 = 0, d2 = 0, d6 = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_mouser.timer;
	OBJECT(a0)->enemy_mouser.timer = timer - 1u;
	if (timer != 1u)
	{
		move_object_blocked(a0);
		return;
	}
	a6 = mem_read32(a1);
	d1 = 0x20u;
	if ((OBJECT(a0)->enemy_mouser.side & 0x80u) != 0u)
		d1 = (uint16_t)(0u - d1);
	d1 = (uint16_t)(d1 + mem_read16(a6 + 0xCu));
	d2 = mem_read16(a6 + 0xEu);
	direction_to(a0, &d0, &d1, &d2);
	a5 = animations_05176C_ADDRESS;
	enemy_turn_to_direction((uint8_t)d0, a0, p_d7, &a5);
	d1_2 = 0x80u;
	speeds_from_direction((uint8_t)d0, d1_2, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	*p_d7 = (uint16_t)((int16_t)*p_d7 >> 1);
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->enemy_mouser.timer = 8u;
	move_object_blocked(a0);
}

/* runs away, sits and waits while its turtle is down */
void enemy_mouser_back_off(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0518BC_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_mouser_back_off_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t a6 = 0, d0 = 0, d6 = 0, ignored = 0;

	OBJECT(a0)->enemy_mouser.move_time = 0xFFu;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_mouser.timer = 0x20u;
	a6 = mem_read32(a1);
	d0 = direction_to_object(0u, a0, a6);
	d0 = (uint8_t)(d0 - 0x80u);
	d1 = 0x100u;
	speeds_from_direction((uint8_t)d0, d1, &d6, p_d7, &ignored);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	*p_a5 = animations_05176C_ADDRESS;
	enemy_face_direction((uint8_t)d0, a0, p_d7, p_a5);
}

void enemy_mouser_back_off_run(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_mouser.timer;
	OBJECT(a0)->enemy_mouser.timer = timer - 1u;
	if (timer == 1u)
		OBJECT(a0)->state++;
	*p_a5 = animations_05176C_ADDRESS;
	enemy_turn_to_direction(d0, a0, p_d7, p_a5);
	move_object_blocked(a0);
}

/* sits in one of two poses */
uint32_t enemy_mouser_sit(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0;

	OBJECT(a0)->state++;
	d7 = 2u;
	d7 = random_below((uint16_t)d7, a0);
	d7 = (uint16_t)(d7 << 2);
	animation = animations_0518CC[d7 / 4u];
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_mouser_back_off_wait(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_mouser.approach = 0u;
		OBJECT(a0)->enemy_mouser.move_time = 0u;
	}
}

/* thrown off by the turtle it held */
void enemy_mouser_thrown_off(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_051974_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_mouser_thrown_off_start(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;

	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->flags &= 0xBFu;
	if ((OBJECT(a0)->enemy_mouser.facing & 0x80u) != 0u)
		OBJECT(a0)->flags |= 0x40u;
	a6 = 0x51A20u;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x58146u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

/* hops away and breaks when the boss is beaten */
void enemy_mouser_break_down(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0519CC_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_mouser_break_down_start(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;

	a6 = 0x519D8u;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x58146u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

/* knocked flying by a hit */
void enemy_mouser_knocked_flying(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_051A14_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_mouser_knocked_flying_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	enemy_mouser_leave_side(a0, a1);
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_mouser.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	a6 = 0x51A20u;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x58146u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

/* flies until it hits the floor and breaks */
uint32_t enemy_mouser_fly_and_crash(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	enemy_follow_stairs(a0);
	move_object_with_height(a0);
	a6 = 0x51A20u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	d7_2 = (d7 & ~0xFFu) | 0xFu;
	queue_sound((uint8_t)d7_2, a6);
	OBJECT(a0)->state++;
	animation = 0x581D0u;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* gone when its wreck's animation ends */
void enemy_mouser_remove(uint32_t a0, uint32_t a1)
{
	uint8_t t1 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
			enemies_on_screen = 0u;
	}
}

/* a wall with Mousers behind it */
void mouser_hole_start(uint32_t a0)
{
	uint32_t a6 = 0, animation = 0;

	OBJECT(a0)->flags = 0x81u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->mouser_hole.mousers_left = table_loaded_by_lea_051AEE[(uint32_t)(uint16_t)((OBJECT(a0)->parameter & 0xFu) << 3) + difficulty];
	a6 = TABLE32(animations_051AE2, (OBJECT(a0)->parameter & 0xF0u) >> 2);
	OBJECT(a0)->mouser_hole.hole = a6;
	animation = mem_read32(a6);
	set_animation(0u, a0, animation);
}

/* on the screen, the wall breaks open */
uint32_t mouser_hole_wait(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, hole = 0;

	if (OBJECT(a0)->screen_x < 0x100u)
	{
		enemies_on_screen += 6u;
		hole = OBJECT(a0)->mouser_hole.hole;
		animation = mem_read32(hole + 4u);
		set_animation(0u, a0, animation);
		OBJECT(a0)->mouser_hole.hole = hole + 8u;
		OBJECT(a0)->routine++;
		d7 = (d7 & ~0xFFu) | 0x31u;
		queue_sound((uint8_t)d7, animation);
	}
	return d7;
}

/* the broken wall is down */
void mouser_hole_open(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->mouser_hole.spawn_time = 0x10u;
		OBJECT(a0)->flags &= 1u;
		OBJECT(a0)->routine++;
	}
}

/* Mousers come out of the hole one after another until the last */
void mouser_hole_let_out(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t ignored = 0;
	uint8_t spawn_time = 0, mousers_left = 0, t1 = 0;

	spawn_time = OBJECT(a0)->mouser_hole.spawn_time;
	OBJECT(a0)->mouser_hole.spawn_time = spawn_time - 1u;
	if (spawn_time == 1u)
	{
		*p_a5 = OBJECT(a0)->mouser_hole.hole;
		start_object_from_record(a0, *p_a5, &d7, &ignored, &zero);
		OBJECT(a0)->mouser_hole.spawn_time = 0x3Cu;
		mousers_left = OBJECT(a0)->mouser_hole.mousers_left;
		OBJECT(a0)->mouser_hole.mousers_left = mousers_left - 1u;
		if (mousers_left == 1u)
		{
			OBJECT(a0)->flags = 0u;
			OBJECT(a0)->contacts = 0u;
			t1 = enemies_on_screen - 6u;
			enemies_on_screen = t1;
			if ((int8_t)t1 < 0)
				enemies_on_screen = 0u;
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* a Roadkill Rodney: one bar, coming up through the floor */
void enemy_rodney_start(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t animation = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy_rodney.target = a6;
	OBJECT(a0)->enemy_rodney.retarget_time = 0x10u;
	OBJECT(a0)->enemy_rodney.move_time = 0u;
	OBJECT(a0)->enemy_rodney.approach = 0u;
	OBJECT(a0)->depth = 4u;
	OBJECT(a0)->floor_height = 0u;
	enemies_on_screen++;
	OBJECT(a0)->health_bars = 1u;
	OBJECT(a0)->health = 0xCu;
	OBJECT(a0)->shadow = 0x2E928u;
	if ((int8_t)OBJECT(a0)->parameter >= 0)
	{
		OBJECT(a0)->flags |= 0x82u;
		OBJECT(a0)->routine += 2u;
		animation = animations_0585C4_ADDRESS;
		set_animation(0u, a0, animation);
		return;
	}
	OBJECT(a0)->frame_time = 0u;
	OBJECT(a0)->routine++;
	OBJECT(a0)->enemy_rodney.wait = 0xB4u;
}

/* comes up through the floor with a jump and lands */
void enemy_rodney_enter(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_051CB8_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rodney_enter_wait(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;
	uint8_t wait = 0;

	if (OBJECT(a0)->screen_x >= 0x140u)
	{
		wait = OBJECT(a0)->enemy_rodney.wait;
		OBJECT(a0)->enemy_rodney.wait = wait - 1u;
		if (wait != 1u)
			return d7;
	}
	d7_2 = (d7 & ~0xFFu) | 0x2Eu;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->flags |= 0x80u;
	OBJECT(a0)->state++;
	animation = 0x58960u;
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_rodney_enter_burst_out(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->height = 0x1800u;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = 0x10;
	OBJECT(a0)->height_speed = 0x400;
	OBJECT(a0)->flags |= 2u;
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	animation = 0x589A8u;
	set_animation(0u, a0, animation);
}

void enemy_rodney_enter_fall(uint32_t a0)
{
	uint8_t height_whole = 0;
	uint32_t animation = 0;

	move_object_with_height(a0);
	OBJECT(a0)->height_speed -= 0x40u;
	height_whole = OBJECT(a0)->height_whole;
	if (height_whole <= OBJECT(a0)->floor_height || height_whole >= 0xF8u)
	{
		OBJECT(a0)->height = 0u;
		OBJECT(a0)->state++;
		OBJECT(a0)->contacts &= 0x7Fu;
		animation = 0x589CCu;
		set_animation(0u, a0, animation);
		return;
	}
}

void enemy_rodney_enter_land(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
		OBJECT(a0)->routine++;
}

/* goes after the turtle with the fewest enemies: rushes at it, whips or shoots it; gone when the area is
   cleared */
void enemy_rodney_think(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	bool L_051E78 = false;
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint16_t approach = 0, d0_2 = 0;
	uint32_t a6_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;
	uint8_t retarget_time = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t6 = 0;
	uint32_t t1 = 0, t2 = 0;

	*p_a1 = 0x60000u | OBJECT(a0)->enemy_rodney.target;
	retarget_time = OBJECT(a0)->enemy_rodney.retarget_time;
	OBJECT(a0)->enemy_rodney.retarget_time = retarget_time - 1u;
	if (retarget_time == 1u)
	{
		OBJECT(a0)->enemy_rodney.retarget_time = 0x10u;
		if (turtles_in_play != 0u)
		{
			mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
			enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
			d0 = enemies_per_turtle;
			if (d0 <= PLAYER_SLOT(a6)->enemies)
			{
				t1 = *p_a5;
				*p_a5 = a6;
				a6 = t1;
				if (d0 <= mem_read8(a6 + 4u))
				{
					a6 = least_crowded_slot;
					if (d0 <= PLAYER_SLOT(a6)->enemies)
					{
						t2 = *p_a5;
						*p_a5 = a6;
						a6 = t2;
					}
				}
			}
			*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)a6;
			if ((uint16_t)*p_d7 != OBJECT(a0)->enemy_rodney.target)
				enemy_rodney_leave_side(a0, *p_a1);
			OBJECT(a0)->enemy_rodney.target = a6;
			*p_a1 = a6;
			mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
		}
	}
	if (boss_defeated != 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t3 = enemies_on_screen - 1u;
		enemies_on_screen = t3;
		if ((int8_t)t3 < 0)
			enemies_on_screen = 0u;
		return;
	}
	if ((OBJECT(a0)->flags & 0x20u) != 0u)
	{
		enemy_rodney_leave_side(a0, *p_a1);
		mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t3 = enemies_on_screen - 1u;
		enemies_on_screen = t3;
		if ((int8_t)t3 < 0)
			enemies_on_screen = 0u;
		return;
	}
	turtle = mem_read32(*p_a1);
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	enemy_collide_with_objects(a0, p_d5, p_d7, p_a5);
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	if (OBJECT(a0)->enemy_rodney.approach != 0u)
	{
		if (OBJECT(a0)->enemy_rodney.approach == 1u && ((int16_t)OBJECT(a0)->screen_x < 0x70 || (int16_t)OBJECT(a0)->screen_x >= 0x190))
		{
			OBJECT(a0)->enemy_rodney.approach = 0u;
			OBJECT(a0)->enemy_rodney.move_time = 0u;
			enemy_rodney_give_side_back(a0, *p_a1);
		}
	}
	else if (mem_read8(*p_a1 + 6u) < 0xC0u && OBJECT(a0)->enemy_rodney.target_dx < 0x20u)
	{
		OBJECT(a0)->enemy_rodney.approach = 1u;
		OBJECT(a0)->enemy_rodney.move_time = 0u;
		do
		{
			if (L_051E78 || (int8_t)(OBJECT(a0)->enemy_rodney.target_direction - 0x40u) < 0)
			{
				for (;;)
				{
					L_051E78 = false;
					t4 = mem_read8(*p_a1 + 6u);
					mem_write8(*p_a1 + 6u, t4 | 0x40u);
					if ((t4 & 0x40u) != 0u)
					{
						t5 = mem_read8(*p_a1 + 6u);
						mem_write8(*p_a1 + 6u, t5 | 0x80u);
						if ((t5 & 0x80u) != 0u)
							continue;
						OBJECT(a0)->enemy_rodney.side &= 0x7Fu;
						break;
					}
					OBJECT(a0)->enemy_rodney.side |= 0x80u;
					break;
				}
			}
			else
			{
				t5 = mem_read8(*p_a1 + 6u);
				mem_write8(*p_a1 + 6u, t5 | 0x80u);
				L_051E78 = (t5 & 0x80u) != 0u;
				if (!L_051E78)
					OBJECT(a0)->enemy_rodney.side &= 0x7Fu;
			}
		} while (L_051E78);
	}
	if (OBJECT(a0)->enemy_rodney.approach != 1u)
	{
		enemy_on_screen(a0, p_d7, &zero);
		if (zero && OBJECT(a0)->enemy_rodney.approach == 1u && mem_read8(mem_read32(*p_a1) + 4u) != 4u && OBJECT(a0)->enemy_rodney.target_dy < 6u)
		{
			*p_d7 = 0x64u;
			*p_d7 = random_below((uint16_t)*p_d7, a0);
			d0_2 = 1u;
			a6_2 = table_loaded_by_lea_051F94_ADDRESS;
			do
			{
				if (DATA16(a6_2) <= OBJECT(a0)->enemy_rodney.target_dx && (uint8_t)*p_d7 < DATA8(a6_2 + 2u))
				{
					OBJECT(a0)->enemy_rodney.move = (uint32_t)DATA8(a6_2 + 3u) << 2;
					OBJECT(a0)->routine = 3u;
					OBJECT(a0)->state = 0u;
					OBJECT(a0)->flags &= ~8u;
					return;
				}
				t6 = d0_2 - 1u;
				d0_2 = t6;
				a6_2 += 4u;
			} while (t6 != 0xFFFFu);
		}
	}
	else
	{
		a6_2 = mem_read32(*p_a1);
		if (mem_read8(a6_2 + 4u) != 4u || indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] != 0u)
		{
			enemy_on_screen(a0, p_d7, &zero);
			if (zero && OBJECT(a0)->enemy_rodney.approach == 1u && mem_read8(mem_read32(*p_a1) + 4u) != 4u && OBJECT(a0)->enemy_rodney.target_dy < 6u)
			{
				*p_d7 = 0x64u;
				*p_d7 = random_below((uint16_t)*p_d7, a0);
				d0_2 = 1u;
				a6_2 = table_loaded_by_lea_051F94_ADDRESS;
				do
				{
					if (DATA16(a6_2) <= OBJECT(a0)->enemy_rodney.target_dx && (uint8_t)*p_d7 < DATA8(a6_2 + 2u))
					{
						OBJECT(a0)->enemy_rodney.move = (uint32_t)DATA8(a6_2 + 3u) << 2;
						OBJECT(a0)->routine = 3u;
						OBJECT(a0)->state = 0u;
						OBJECT(a0)->flags &= ~8u;
						return;
					}
					t6 = d0_2 - 1u;
					d0_2 = t6;
					a6_2 += 4u;
				} while (t6 != 0xFFFFu);
			}
		}
		else
		{
			enemy_rodney_give_side_back(a0, *p_a1);
			OBJECT(a0)->enemy_rodney.approach = 2u;
			OBJECT(a0)->enemy_rodney.move_time = 0u;
		}
	}
	if (OBJECT(a0)->enemy_rodney.move_time == 0u)
	{
		approach = OBJECT(a0)->enemy_rodney.approach;
		OBJECT(a0)->enemy_rodney.move = (uint32_t)DATA8(rom_051F9C_ADDRESS + approach) << 2;
		OBJECT(a0)->state = 0u;
	}
	switch ((uint32_t)(int16_t)OBJECT(a0)->enemy_rodney.move)
	{
	case 20:
		enemy_shuffle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 28:
		enemy_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 36:
		enemy_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0:
		enemy_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 4:
		enemy_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 8:
		enemy_keep_distance(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 12:
		enemy_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 16:
		enemy_run_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 44:
		enemy_walk_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 48:
		enemy_walk_to_target_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 52:
		enemy_walk_to_side_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 24:
		enemy_walk_past_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 32:
		enemy_back_off_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 40:
		enemy_walk_to_line_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 56:
		enemy_walk_to_target_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 60:
		enemy_walk_to_side_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 68:
		enemy_stalk_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 64:
		enemy_walk_away_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 72:
		enemy_walk_to_target_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 76:
		enemy_walk_to_side_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 104:
		enemy_walk_off_line_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 108:
		enemy_back_off_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 112:
		enemy_step_aside_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 80:
		enemy_walk_to_target_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 84:
		enemy_walk_to_side_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 116:
		enemy_circle_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 124:
		enemy_keep_distance_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 120:
		enemy_back_off_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 128:
		enemy_step_aside_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 88:
		enemy_walk_to_target_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 92:
		enemy_walk_to_side_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 152:
		enemy_walk_to_range_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 140:
		enemy_back_off_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 144:
		enemy_run_away_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 96:
		enemy_walk_to_target_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 100:
		enemy_walk_to_side_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 148:
		enemy_walk_to_range_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 132:
		enemy_back_off_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 136:
		enemy_run_away_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 196:
		enemy_rocksteady_raise_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 200:
		enemy_rocksteady_laugh(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 192:
		enemy_rocksteady_shake_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 184:
		enemy_rocksteady_draw_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 188:
		enemy_rocksteady_put_gun_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 204:
		enemy_rocksteady_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 208:
		enemy_rocksteady_line_up(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 212:
		enemy_rocksteady_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 232:
		enemy_rocksteady_shoot_around(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 228:
		enemy_bebop_stand(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 216:
		enemy_bebop_walk_to_front(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 224:
		enemy_bebop_walk_level(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 220:
		enemy_bebop_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 156:
		enemy_mouser_chase(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 164:
		enemy_mouser_creep_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 160:
		enemy_mouser_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 172:
		enemy_rodney_rush(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 176:
		enemy_rodney_rush_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 180:
		enemy_rodney_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 236:
		enemy_shredder_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 240:
		enemy_shredder_split(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 168:
		enemy_shredder_clone_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 244:
		enemy_shredder_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 248:
		enemy_shredder_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 252:
		enemy_shredder_guard(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 256:
		enemy_shredder_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

/* hit: knocked back, or destroyed with no health left */
void enemy_rodney_hit(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0;

	d7 = 5u;
	queue_sound(d7, 0u);
	d0 = 0x40u;
	if (OBJECT(a0)->health == 0u)
		d0 = 0x74u;
	OBJECT(a0)->enemy_rodney.move = d0;
	OBJECT(a0)->enemy_rodney.move_time = 0u;
	OBJECT(a0)->routine++;
	enemy_react(a0, p_d5, p_d7, p_a1, p_a5);
}

/* gives its side of its turtle back when it stands by it */
void enemy_rodney_leave_side(uint32_t a0, uint32_t a1)
{
	if (OBJECT(a0)->enemy_rodney.approach != 1u)
		return;
	enemy_rodney_give_side_back(a0, a1);
}

/* gives its side of its turtle back */
void enemy_rodney_give_side_back(uint32_t a0, uint32_t a1)
{
	uint8_t d0 = 0;
	uint8_t side = 0;

	d0 = 0x7Fu;
	side = OBJECT(a0)->enemy_rodney.side;
	OBJECT(a0)->enemy_rodney.side = side & 0x7Fu;
	if ((side & 0x80u) != 0u)
		d0 = 0xB7u;
	mem_write8(a1 + 6u, mem_read8(a1 + 6u) & d0);
	OBJECT(a0)->enemy_rodney.approach = 0u;
	OBJECT(a0)->enemy_rodney.move_time = 0u;
}

/* rushes at and past its turtle, then brakes */
void enemy_rodney_rush(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052002_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rodney_rush_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, animation = 0, d0 = 0, d1 = 0, d2 = 0, d6 = 0;

	d0 = 0x80u;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_rodney.target_direction - 0x40u) < 0)
	{
		d0 = 0u;
		OBJECT(a0)->flags |= 0x40u;
	}
	if (OBJECT(a0)->enemy_rodney.target_dy < 0x20u)
	{
		d2 = 0x20u;
		if ((int8_t)OBJECT(a0)->enemy_rodney.target_direction < 0)
			d2 = (uint16_t)(0u - d2);
		a6 = mem_read32(a1);
		d1 = mem_read16(a6 + 0xCu);
		d2 = (uint16_t)(d2 + mem_read16(a6 + 0xEu));
		direction_to(a0, &d0, &d1, &d2);
	}
	d1 = 0x300u;
	speeds_from_direction((uint8_t)d0, (uint16_t)d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->enemy_rodney.move_time = 0xB4u;
	OBJECT(a0)->state++;
	animation = animations_0585C4_ADDRESS;
	set_animation(d1, a0, animation);
}

uint32_t enemy_rodney_rush_run(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0;

	OBJECT(a0)->enemy_rodney.move_time--;
	d7 = 0xFFFFFFFFu;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		if ((OBJECT(a0)->contacts & 8u) != 0u)
		{
			OBJECT(a0)->y -= 0x100u;
			d7 &= ~0xFFu;
		}
	}
	else if ((OBJECT(a0)->contacts & 0x10u) != 0u)
	{
		OBJECT(a0)->y -= 0x100u;
		d7 &= ~0xFFu;
	}
	if ((int8_t)((OBJECT(a0)->enemy_rodney.target_direction - 0x40u) ^ ((uint32_t)OBJECT(a0)->flags << 1)) >= 0)
	{
		move_object_blocked(a0);
		return d7;
	}
	if ((int8_t)d7 >= 0)
		OBJECT(a0)->enemy_rodney.move_time = 0u;
	if (OBJECT(a0)->enemy_rodney.target_dx < 0x50u)
	{
		move_object_blocked(a0);
		return d7;
	}
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_rodney.brake = 0x20;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->enemy_rodney.brake = 0u - OBJECT(a0)->enemy_rodney.brake;
	OBJECT(a0)->y_speed = -0x40;
	animation = 0x58636u;
	if ((int8_t)OBJECT(a0)->enemy_rodney.target_direction < 0)
	{
		OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
		animation = 0x58660u;
	}
	set_animation(0u, a0, animation);
	return d7;
}

/* brakes to a stop, then thinks */
void enemy_rodney_brake(uint32_t a0)
{
	OBJECT(a0)->x_speed += OBJECT(a0)->enemy_rodney.brake;
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_rodney.move_time = 0u;
	}
	move_object_blocked(a0);
}

/* rushes across past its turtle, then brakes toward its row */
void enemy_rodney_rush_across(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052142_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_rodney_rush_across_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->x_speed = -0x300;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_rodney.target_direction - 0x40u) < 0)
	{
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		OBJECT(a0)->flags |= 0x40u;
	}
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_rodney.move_time = 0xB4u;
	animation = animations_0585C4_ADDRESS;
	set_animation(0u, a0, animation);
}

uint32_t enemy_rodney_rush_across_run(uint32_t a0)
{
	uint32_t animation = 0, d7 = 0;

	OBJECT(a0)->enemy_rodney.move_time--;
	d7 = 0xFFFFFFFFu;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
	{
		if ((OBJECT(a0)->contacts & 8u) != 0u)
		{
			OBJECT(a0)->y -= 0x100u;
			d7 &= ~0xFFu;
		}
	}
	else if ((OBJECT(a0)->contacts & 0x10u) != 0u)
	{
		OBJECT(a0)->y -= 0x100u;
		d7 &= ~0xFFu;
	}
	if ((int8_t)((OBJECT(a0)->enemy_rodney.target_direction - 0x40u) ^ ((uint32_t)OBJECT(a0)->flags << 1)) >= 0)
	{
		move_object_blocked(a0);
		return d7;
	}
	if ((int8_t)d7 >= 0)
		OBJECT(a0)->enemy_rodney.move_time = 0u;
	if (OBJECT(a0)->enemy_rodney.target_dx < 0x50u)
	{
		move_object_blocked(a0);
		return d7;
	}
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_rodney.brake = 0x20;
	if ((OBJECT(a0)->flags & 0x40u) != 0u)
		OBJECT(a0)->enemy_rodney.brake = 0u - OBJECT(a0)->enemy_rodney.brake;
	OBJECT(a0)->y_speed = (uint32_t)OBJECT(a0)->enemy_rodney.target_dy << 3;
	animation = 0x58660u;
	if ((int8_t)OBJECT(a0)->enemy_rodney.target_direction >= 0)
	{
		OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
		animation = 0x58636u;
	}
	set_animation(0u, a0, animation);
	return d7;
}

/* slides back and waits while its turtle is down */
void enemy_rodney_back_off(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052234_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rodney_back_off_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x8Cu;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->enemy_rodney.brake = -0x20;
	OBJECT(a0)->x_speed = 0x200;
	if ((OBJECT(a0)->flags & 0x40u) == 0u)
	{
		OBJECT(a0)->enemy_rodney.brake = 0u - OBJECT(a0)->enemy_rodney.brake;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_rodney.move_time = 0xB4u;
	animation = 0x585DEu;
	set_animation(0u, a0, animation);
	return d7_2;
}

/* slows its slide to a stop, saying "Do not resist us" once */
void enemy_rodney_slide_to_stop(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint16_t brake = 0, d0 = 0, screen_y = 0;
	uint32_t animation = 0, d1 = 0;
	uint16_t t1 = 0;

	brake = (uint16_t)OBJECT(a0)->enemy_rodney.brake;
	t1 = OBJECT(a0)->x_speed + brake;
	OBJECT(a0)->x_speed = t1;
	if (t1 != 0u)
		move_object_blocked(a0);
	else
	{
		OBJECT(a0)->state++;
		if (rodney_line_said == 0u)
		{
			d0 = (uint16_t)((brake & ~0xFFu) | 0xFFu);
			d1 = OBJECT(a0)->screen_x;
			screen_y = OBJECT(a0)->screen_y;
			say_do_not_resist_us(d0, d1, screen_y, &d5, p_d7);
			rodney_line_said = 0xFFu;
		}
		animation = 0x5860Cu;
		set_animation(d1, a0, animation);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

void enemy_rodney_back_off_turn(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_rodney.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->state++;
}

void enemy_rodney_back_off_wait(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		OBJECT(a0)->enemy_rodney.approach = 0u;
		OBJECT(a0)->enemy_rodney.move_time = 0u;
	}
}

/* slides back, turns and fires three laser bolts */
void enemy_rodney_shoot(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052312_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rodney_shoot_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x8Cu;
	queue_sound((uint8_t)d7_2, 0u);
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->flags &= 0xBFu;
	OBJECT(a0)->enemy_rodney_shoot.brake = 0x20;
	OBJECT(a0)->x_speed = -0x200;
	if ((int8_t)(OBJECT(a0)->enemy_rodney_shoot.target_direction - 0x40u) < 0)
	{
		OBJECT(a0)->flags |= 0x40u;
		OBJECT(a0)->enemy_rodney_shoot.brake = 0u - OBJECT(a0)->enemy_rodney_shoot.brake;
		OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	OBJECT(a0)->state++;
	animation = 0x585DEu;
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_rodney_shoot_turn(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_rodney_shoot.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->state++;
	animation = 0x587FAu;
	set_animation(0u, a0, animation);
}

uint32_t enemy_rodney_shoot_ready(uint32_t d7, uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy_rodney_shoot.shot_time = 1u;
		OBJECT(a0)->enemy_rodney_shoot.shots_left = 3u;
		OBJECT(a0)->state++;
		d7 = (d7 & ~0xFFu) | 0x14u;
		queue_sound((uint8_t)d7, 0u);
	}
	return d7;
}

void enemy_rodney_shoot_fire(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t animation = 0, object = 0;
	uint8_t shot_time = 0, shots_left = 0;

	shot_time = OBJECT(a0)->enemy_rodney_shoot.shot_time;
	OBJECT(a0)->enemy_rodney_shoot.shot_time = shot_time - 1u;
	if (shot_time == 1u)
	{
		OBJECT(a0)->enemy_rodney_shoot.shot_time = 4u;
		*p_a5 = 0x5232Au;
		start_shot(a0, *p_a5, &d7, &object, &zero);
		if (zero == 0u)
		{
			OBJECT(a0)->state++;
			animation = 0x58856u;
			set_animation(0u, a0, animation);
		}
		else
		{
			OBJECT(object)->parameter = (uint32_t)OBJECT(a0)->flags << 1;
			OBJECT(object)->start_shot.hit_sound = OBJECT(a0)->enemy_rodney_shoot.move;
			shots_left = OBJECT(a0)->enemy_rodney_shoot.shots_left;
			OBJECT(a0)->enemy_rodney_shoot.shots_left = shots_left - 1u;
			if (shots_left == 1u)
			{
				OBJECT(a0)->state++;
				animation = 0x58856u;
				set_animation(0u, a0, animation);
			}
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void enemy_rodney_shoot_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_rodney_shoot.move_time = 0u;
		OBJECT(a0)->enemy_rodney_shoot.retarget_time = 0u;
	}
}

/* throws its whip arm at its turtle and lashes it with it */
void enemy_rodney_whip(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05242E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rodney_whip_start(uint32_t d7, uint32_t a0)
{
	enemy_rodney_follow_row(a0);
	return enemy_rodney_shoot_start(d7, a0);
}

void enemy_rodney_whip_slow_down(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;

	enemy_rodney_follow_row(a0);
	enemy_rodney_slide_to_stop(a0, &d5, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
}

uint32_t enemy_rodney_whip_wind_up(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	enemy_rodney_follow_row(a0);
	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_rodney_whip.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	OBJECT(a0)->state++;
	d7_2 = (d7 & ~0xFFu) | 0x2Au;
	queue_sound((uint8_t)d7_2, 0u);
	animation = 0x588BCu;
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_rodney_whip_throw_arm(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t animation = 0, object = 0;

	enemy_rodney_follow_row(a0);
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->state++;
		OBJECT(a0)->enemy_rodney_whip.arm_flags = 0u;
		OBJECT(a0)->enemy_rodney_whip.arm_length = 0u;
		*p_a5 = 0x5244Au;
		start_shot(a0, *p_a5, &d7, &object, &zero);
		if (zero == 0u)
		{
			OBJECT(a0)->routine = 2u;
			OBJECT(a0)->state = 0u;
			OBJECT(a0)->enemy_rodney_whip.move_time = 0u;
			OBJECT(a0)->enemy_rodney_whip.retarget_time = 0u;
		}
		else
		{
			OBJECT(a0)->enemy_rodney_whip.arm = object;
			OBJECT(object)->unk_24 = (uint8_t)(a0 >> 24u);
			OBJECT(object)->unk_25 = (uint8_t)(a0 >> 16u);
			OBJECT(object)->unk_26 = (uint8_t)(a0 >> 8u);
			OBJECT(object)->unk_27 = (uint8_t)a0;
			animation = 0x58918u;
			set_animation(0u, a0, animation);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* keeps toward its turtle's row */
void enemy_rodney_follow_row(uint32_t a0)
{
	uint16_t d1 = 0;

	d1 = 0x200u;
	if (OBJECT(a0)->enemy_rodney.target_dy < 3u)
		return;
	if ((int8_t)OBJECT(a0)->enemy_rodney.target_direction >= 0)
		d1 = (uint16_t)(0u - d1);
	OBJECT(a0)->y += (int16_t)d1;
}

uint32_t enemy_rodney_whip_reach(uint32_t d7, uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t animation = 0, arm = 0, d7_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	enemy_rodney_follow_row(a0);
	arm = OBJECT(a0)->enemy_rodney_whip.arm;
	if ((mem_read8(arm) & 8u) == 0u)
	{
		if ((OBJECT(a0)->enemy_rodney_whip.arm_flags & 2u) != 0u)
		{
			enemy_rodney_whip_pull_in(a0);
			return d7;
		}
		OBJECT(a0)->enemy_rodney_whip.arm_length++;
		if (OBJECT(a0)->enemy_rodney_whip.arm_length != 0xDu)
			return d7;
		OBJECT(a0)->enemy_rodney_whip.arm_length--;
		enemy_rodney_whip_pull_in(a0);
		return d7;
	}
	d7_2 = 0x60000u | mem_read16(arm + 0x4Eu);
	t1 = mem_read16(d7_2 + 0xCu) - OBJECT(a0)->screen_x;
	d0 = (uint8_t)t1;
	if ((int16_t)t1 < 0)
		d0 = (uint8_t)(uint16_t)(0u - d0);
	t2 = d0;
	d0 = (uint8_t)(t2 - 0x30u);
	if (t2 < 0x30u)
		d0 = 0u;
	d0 = d0 >> 3;
	if (d0 >= 0xCu)
		d0 = 0xCu;
	OBJECT(a0)->enemy_rodney_whip.arm_length = d0;
	OBJECT(a0)->enemy_rodney_whip.arm_flags |= 0x20u;
	OBJECT(a0)->state = 5u;
	animation = 0x59150u;
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_rodney_whip_pull_in(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->enemy_rodney_whip.arm_flags |= 0x40u;
	animation = TABLE32(animations_052450, (uint32_t)(int16_t)((uint32_t)(int8_t)OBJECT(a0)->enemy_rodney_whip.arm_length << 2));
	set_animation(0u, a0, animation);
	OBJECT(a0)->state = 6u;
}

uint32_t enemy_rodney_whip_lash(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 0x60000u | OBJECT(a0)->hit_object;
	if ((OBJECT(a0)->enemy_rodney_whip.arm_flags & 4u) != 0u)
	{
		enemy_rodney_whip_pull_in(a0);
		return d7;
	}
	return d7;
}

void enemy_rodney_whip_retract(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = OBJECT(a0)->enemy_rodney_whip.arm_length - 1u;
	OBJECT(a0)->enemy_rodney_whip.arm_length = t1;
	if ((int8_t)t1 < 0)
	{
		OBJECT(a0)->enemy_rodney_whip.arm_flags |= 0x80u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_rodney_whip.move_time = 0u;
		OBJECT(a0)->enemy_rodney_whip.retarget_time = 0u;
	}
}

/* knocked back by a hit */
void enemy_rodney_knocked_back(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05260C_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rodney_knocked_back_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_rodney.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	a6 = 0x526C0u;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x5877Eu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->state++;
	enemy_rodney_leave_side(a0, a1);
	return d7;
}

uint32_t enemy_rodney_knocked_back_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	move_object_with_height_blocked(a0);
	a6 = 0x52618u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->state++;
	animation = 0x58788u;
	set_animation(0u, a0, animation);
	return d7;
}

void enemy_rodney_knocked_back_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		OBJECT(a0)->enemy_rodney.move_time = 0u;
		OBJECT(a0)->flags |= 2u;
	}
}

/* destroyed: falls, lands as a wreck, gone */
void enemy_rodney_destroyed(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0526B0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_rodney_destroyed_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_rodney.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	a6 = 0x526C0u;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x58794u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->state++;
	enemy_rodney_leave_side(a0, a1);
	return d7;
}

uint32_t enemy_rodney_destroyed_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0, d7_2 = 0;

	move_object_with_height_blocked(a0);
	a6 = 0x526C0u;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	d7_2 = (d7 & ~0xFFu) | 0xFu;
	queue_sound((uint8_t)d7_2, a6);
	OBJECT(a0)->state++;
	animation = 0x5879Eu;
	set_animation(0u, a0, animation);
	return d7_2;
}

void enemy_rodney_destroyed_land(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->state++;
	animation = 0x5879Eu;
	set_animation(0u, a0, animation);
}

void enemy_rodney_destroyed_end(uint32_t a0, uint32_t a1)
{
	uint8_t t1 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
			enemies_on_screen = 0u;
	}
}

/* Shredder or one of his clones, by the parameter */
void enemy_shredder_start(uint32_t a0, uint32_t a1, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d0 = 0;

	enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
	PLAYER_SLOT(a6)->enemies++;
	OBJECT(a0)->enemy_shredder.target = a6;
	OBJECT(a0)->enemy_shredder.retarget_time = 0x10u;
	OBJECT(a0)->enemy_shredder.move_time = 0u;
	OBJECT(a0)->enemy_shredder.approach = 0u;
	OBJECT(a0)->enemy_shredder.side = 0u;
	OBJECT(a0)->enemy_shredder.hits_to_knock_back = 3u;
	d0 = difficulty & 7u;
	OBJECT(a0)->enemy_shredder.guard_wait = DATA8(indexed_table_of_8_bit_values_052A60_ADDRESS + d0);
	OBJECT(a0)->enemy_shredder.attack_wait = DATA8(rom_052ADE_ADDRESS + d0);
	OBJECT(a0)->enemy_shredder.ray_wait = DATA16(indexed_table_of_16_bit_values_052B3A_ADDRESS + (uint16_t)((uint32_t)d0 << 1));
	OBJECT(a0)->depth = 4u;
	OBJECT(a0)->floor_height = 0u;
	OBJECT(a0)->shadow = 0x2E928u;
	OBJECT(a0)->routine++;
	enemies_on_screen++;
	if ((int8_t)OBJECT(a0)->parameter < 0)
	{
		OBJECT(a0)->flags |= 0x80u;
		OBJECT(a0)->enemy_shredder.move = 0xA8u;
		enemy_shredder_enter(a0, a1, p_d5, p_d7, p_a5);
		return;
	}
	shredder_beaten = 0u;
	shredder_firing_ray = 0u;
	shredder_clones_made = 0u;
	OBJECT(a0)->enemy_shredder.move = 0xECu;
}

/* his first move, without thinking */
void enemy_shredder_enter(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	switch ((uint32_t)(int16_t)OBJECT(a0)->enemy_shredder.move)
	{
	case 20:
		enemy_shuffle(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 28:
		enemy_circle(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 36:
		enemy_charge(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 0:
		enemy_walk_to_target(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 4:
		enemy_walk_to_side(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 8:
		enemy_keep_distance(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 12:
		enemy_back_off(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 16:
		enemy_run_away(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 44:
		enemy_walk_across(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 48:
		enemy_walk_to_target_sword(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 52:
		enemy_walk_to_side_sword(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 24:
		enemy_walk_past_sword(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 32:
		enemy_back_off_sword(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 40:
		enemy_walk_to_line_sword(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 56:
		enemy_walk_to_target_hammer(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 60:
		enemy_walk_to_side_hammer(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 68:
		enemy_stalk_hammer(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 64:
		enemy_walk_away_hammer(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 72:
		enemy_walk_to_target_spear(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 76:
		enemy_walk_to_side_spear(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 104:
		enemy_walk_off_line_spear(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 108:
		enemy_back_off_spear(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 112:
		enemy_step_aside_spear(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 80:
		enemy_walk_to_target_knife(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 84:
		enemy_walk_to_side_knife(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 116:
		enemy_circle_knife(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 124:
		enemy_keep_distance_knife(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 120:
		enemy_back_off_knife(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 128:
		enemy_step_aside_knife(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 88:
		enemy_walk_to_target_gun(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 92:
		enemy_walk_to_side_gun(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 152:
		enemy_walk_to_range_gun(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 140:
		enemy_back_off_gun(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 144:
		enemy_run_away_gun(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 96:
		enemy_walk_to_target_axe(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 100:
		enemy_walk_to_side_axe(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 148:
		enemy_walk_to_range_axe(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 132:
		enemy_back_off_axe(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 136:
		enemy_run_away_axe(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 196:
		enemy_rocksteady_raise_fist(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 200:
		enemy_rocksteady_laugh(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 192:
		enemy_rocksteady_shake_fist(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 184:
		enemy_rocksteady_draw_gun(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 188:
		enemy_rocksteady_put_gun_away(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 204:
		enemy_rocksteady_circle(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 208:
		enemy_rocksteady_line_up(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 212:
		enemy_rocksteady_close_in(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 232:
		enemy_rocksteady_shoot_around(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 228:
		enemy_bebop_stand(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 216:
		enemy_bebop_walk_to_front(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 224:
		enemy_bebop_walk_level(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 220:
		enemy_bebop_close_in(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 156:
		enemy_mouser_chase(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 164:
		enemy_mouser_creep_to_side(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 160:
		enemy_mouser_back_off(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 172:
		enemy_rodney_rush(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 176:
		enemy_rodney_rush_across(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 180:
		enemy_rodney_back_off(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 236:
		enemy_shredder_appear(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 240:
		enemy_shredder_split(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 168:
		enemy_shredder_clone_appear(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 244:
		enemy_shredder_walk_to_side(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 248:
		enemy_shredder_walk_to_target(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 252:
		enemy_shredder_guard(a0, a1, p_d5, p_d7, p_a5);
		return;
	case 256:
		enemy_shredder_back_off(a0, a1, p_d5, p_d7, p_a5);
		return;
	}
}

/* his thinking: clones, guards, blows by the distance and his ray */
void enemy_shredder_think(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	bool L_052920 = false, L_052992 = false, L_052A68 = false;
	uint8_t d0 = 0;
	uint16_t d6 = 0, target_dx = 0;
	uint32_t a6_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;
	uint8_t retarget_time = 0, t3 = 0, t4 = 0, guard_wait = 0, attack_wait = 0;
	uint16_t t5 = 0, ray_wait = 0;
	uint32_t t1 = 0, t2 = 0;

	*p_a1 = 0x60000u | OBJECT(a0)->enemy_shredder.target;
	retarget_time = OBJECT(a0)->enemy_shredder.retarget_time;
	OBJECT(a0)->enemy_shredder.retarget_time = retarget_time - 1u;
	if (retarget_time == 1u)
	{
		OBJECT(a0)->enemy_shredder.retarget_time = 0x10u;
		if (turtles_in_play != 0u)
		{
			mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
			enemy_nearest_slots(a0, p_d5, p_d7, p_a5, &a6);
			d0 = enemies_per_turtle;
			if (d0 <= PLAYER_SLOT(a6)->enemies)
			{
				t1 = *p_a5;
				*p_a5 = a6;
				a6 = t1;
				if (d0 <= mem_read8(a6 + 4u))
				{
					a6 = least_crowded_slot;
					if (d0 <= PLAYER_SLOT(a6)->enemies)
					{
						t2 = *p_a5;
						*p_a5 = a6;
						a6 = t2;
					}
				}
			}
			*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)a6;
			if ((uint16_t)*p_d7 != OBJECT(a0)->enemy_shredder.target)
				enemy_leave_side(a0, *p_a1);
			OBJECT(a0)->enemy_shredder.target = a6;
			*p_a1 = a6;
			mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
		}
	}
	turtle = mem_read32(*p_a1);
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	OBJECT(a0)->contacts &= 0xE0u;
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	enemy_keep_on_screen(a0);
	if ((OBJECT(a0)->flags & 2u) != 0u)
	{
		L_052920 = (int8_t)OBJECT(a0)->parameter < 0;
		if (!L_052920)
		{
			d0 = turtles_in_play;
			L_052920 = d0 < enemies_on_screen || indexed_table_of_8_bit_values_052918[d0 & 7u] < shredder_clones_made;
			if (!L_052920)
			{
				shredder_clones_made++;
				OBJECT(a0)->enemy_shredder.move = 0xF0u;
				OBJECT(a0)->state = 0u;
			}
		}
		if (L_052920)
		{
			if (shredder_beaten != 0u)
			{
				OBJECT(a0)->flags |= 0x80u;
				OBJECT(a0)->flags &= ~2u;
				OBJECT(a0)->enemy_shredder.move = 0xDCu;
				OBJECT(a0)->routine = 5u;
				OBJECT(a0)->state = 0u;
				return;
			}
			if (OBJECT(a0)->enemy_shredder.approach != 0u || mem_read8(*p_a1 + 5u) >= 0xC0u)
			{
				if (OBJECT(a0)->enemy_shredder.approach == 1u && (OBJECT(a0)->enemy_shredder.target_dx >= 0x50u || OBJECT(a0)->enemy_shredder.target_dy >= 0x50u))
					enemy_give_side_back(a0, *p_a1);
			}
			else if (OBJECT(a0)->enemy_shredder.target_dx < 0x40u && OBJECT(a0)->enemy_shredder.target_dy < 0x40u)
			{
				OBJECT(a0)->enemy_shredder.approach = 1u;
				OBJECT(a0)->enemy_shredder.move_time = 0u;
				do
				{
					if (L_052992 || (int8_t)(OBJECT(a0)->enemy_shredder.target_direction - 0x40u) < 0)
					{
						for (;;)
						{
							L_052992 = false;
							t3 = mem_read8(*p_a1 + 5u);
							mem_write8(*p_a1 + 5u, t3 | 0x40u);
							if ((t3 & 0x40u) != 0u)
							{
								t4 = mem_read8(*p_a1 + 5u);
								mem_write8(*p_a1 + 5u, t4 | 0x80u);
								if ((t4 & 0x80u) != 0u)
									continue;
								OBJECT(a0)->enemy_shredder.side &= 0x7Fu;
								break;
							}
							OBJECT(a0)->enemy_shredder.side |= 0x80u;
							break;
						}
					}
					else
					{
						t4 = mem_read8(*p_a1 + 5u);
						mem_write8(*p_a1 + 5u, t4 | 0x80u);
						L_052992 = (t4 & 0x80u) != 0u;
						if (!L_052992)
							OBJECT(a0)->enemy_shredder.side &= 0x7Fu;
					}
				} while (L_052992);
			}
			if (OBJECT(a0)->enemy_shredder.approach != 1u)
				L_052A68 = true;
			else
			{
				a6_2 = mem_read32(*p_a1);
				if (mem_read8(a6_2 + 4u) != 4u || indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] != 0u)
				{
					guard_wait = OBJECT(a0)->enemy_shredder.guard_wait;
					OBJECT(a0)->enemy_shredder.guard_wait = guard_wait - 1u;
					L_052A68 = guard_wait != 1u;
					if (!L_052A68)
					{
						OBJECT(a0)->enemy_shredder.guard_wait = indexed_table_of_8_bit_values_052A60[difficulty & 7u];
						L_052A68 = mem_read8(mem_read32(*p_a1) + 4u) != 3u || OBJECT(a0)->enemy_shredder.target_dy >= 6u || OBJECT(a0)->enemy_shredder.target_dx >= 0x50u || (int8_t)OBJECT(a0)->enemy_shredder.target_faces >= 0;
						if (!L_052A68)
						{
							enemy_give_side_back(a0, *p_a1);
							OBJECT(a0)->enemy_shredder.approach = 2u;
							OBJECT(a0)->enemy_shredder.move_time = 0u;
						}
					}
				}
				else
				{
					enemy_give_side_back(a0, *p_a1);
					OBJECT(a0)->enemy_shredder.approach = 3u;
					OBJECT(a0)->enemy_shredder.move_time = 0u;
				}
			}
			if (L_052A68)
			{
				if (mem_read8(mem_read32(*p_a1) + 4u) != 4u)
				{
					attack_wait = OBJECT(a0)->enemy_shredder.attack_wait;
					OBJECT(a0)->enemy_shredder.attack_wait = attack_wait - 1u;
					if (attack_wait == 1u)
					{
						OBJECT(a0)->enemy_shredder.attack_wait = rom_052ADE[difficulty & 7u];
						if (OBJECT(a0)->enemy_shredder.target_dy <= 5u)
						{
							a6_2 = record_052ACE_ADDRESS;
							target_dx = OBJECT(a0)->enemy_shredder.target_dx;
							d6 = 3u;
							do
							{
								if (target_dx < DATA16(a6_2))
								{
									OBJECT(a0)->enemy_shredder.move = DATA16(a6_2 + 8u);
									OBJECT(a0)->routine = 3u;
									OBJECT(a0)->state = 0u;
									OBJECT(a0)->flags &= ~8u;
									return;
								}
								t5 = d6 - 1u;
								d6 = t5;
								a6_2 += 2u;
							} while (t5 != 0xFFFFu);
						}
					}
					if ((int8_t)OBJECT(a0)->health_bars < 0 && shredder_firing_ray == 0u)
					{
						ray_wait = OBJECT(a0)->enemy_shredder.ray_wait;
						OBJECT(a0)->enemy_shredder.ray_wait = ray_wait - 1u;
						if (ray_wait == 1u)
						{
							OBJECT(a0)->enemy_shredder.ray_wait = indexed_table_of_16_bit_values_052B3A[difficulty & 7u];
							OBJECT(a0)->enemy_shredder.move = 0xB0u;
							OBJECT(a0)->routine = 3u;
							OBJECT(a0)->state = 0u;
							OBJECT(a0)->flags &= ~8u;
							OBJECT(a0)->enemy_shredder.side |= 1u;
							shredder_firing_ray = 0xFFu;
							return;
						}
					}
				}
			}
			if (OBJECT(a0)->enemy_shredder.move_time == 0u)
			{
				OBJECT(a0)->enemy_shredder.move = indexed_table_of_16_bit_values_052B7C[OBJECT(a0)->enemy_shredder.approach & 3u];
				OBJECT(a0)->state = 0u;
			}
		}
	}
	switch ((uint32_t)(int16_t)OBJECT(a0)->enemy_shredder.move)
	{
	case 20:
		enemy_shuffle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 28:
		enemy_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 36:
		enemy_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0:
		enemy_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 4:
		enemy_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 8:
		enemy_keep_distance(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 12:
		enemy_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 16:
		enemy_run_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 44:
		enemy_walk_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 48:
		enemy_walk_to_target_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 52:
		enemy_walk_to_side_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 24:
		enemy_walk_past_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 32:
		enemy_back_off_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 40:
		enemy_walk_to_line_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 56:
		enemy_walk_to_target_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 60:
		enemy_walk_to_side_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 68:
		enemy_stalk_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 64:
		enemy_walk_away_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 72:
		enemy_walk_to_target_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 76:
		enemy_walk_to_side_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 104:
		enemy_walk_off_line_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 108:
		enemy_back_off_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 112:
		enemy_step_aside_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 80:
		enemy_walk_to_target_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 84:
		enemy_walk_to_side_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 116:
		enemy_circle_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 124:
		enemy_keep_distance_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 120:
		enemy_back_off_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 128:
		enemy_step_aside_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 88:
		enemy_walk_to_target_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 92:
		enemy_walk_to_side_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 152:
		enemy_walk_to_range_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 140:
		enemy_back_off_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 144:
		enemy_run_away_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 96:
		enemy_walk_to_target_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 100:
		enemy_walk_to_side_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 148:
		enemy_walk_to_range_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 132:
		enemy_back_off_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 136:
		enemy_run_away_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 196:
		enemy_rocksteady_raise_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 200:
		enemy_rocksteady_laugh(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 192:
		enemy_rocksteady_shake_fist(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 184:
		enemy_rocksteady_draw_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 188:
		enemy_rocksteady_put_gun_away(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 204:
		enemy_rocksteady_circle(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 208:
		enemy_rocksteady_line_up(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 212:
		enemy_rocksteady_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 232:
		enemy_rocksteady_shoot_around(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 228:
		enemy_bebop_stand(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 216:
		enemy_bebop_walk_to_front(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 224:
		enemy_bebop_walk_level(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 220:
		enemy_bebop_close_in(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 156:
		enemy_mouser_chase(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 164:
		enemy_mouser_creep_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 160:
		enemy_mouser_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 172:
		enemy_rodney_rush(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 176:
		enemy_rodney_rush_across(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 180:
		enemy_rodney_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 236:
		enemy_shredder_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 240:
		enemy_shredder_split(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 168:
		enemy_shredder_clone_appear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 244:
		enemy_shredder_walk_to_side(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 248:
		enemy_shredder_walk_to_target(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 252:
		enemy_shredder_guard(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 256:
		enemy_shredder_back_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

/* his attack, keeping his ray's time */
void enemy_shredder_attack(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, turtle = 0;
	uint16_t ray_wait = 0;
	uint32_t jump_target = 0;

	ray_wait = OBJECT(a0)->enemy_shredder.ray_wait;
	OBJECT(a0)->enemy_shredder.ray_wait = ray_wait - 1u;
	if (ray_wait == 1u)
		OBJECT(a0)->enemy_shredder.ray_wait = 1u;
	*p_a1 = 0x60000u | OBJECT(a0)->enemy_shredder.target;
	turtle = mem_read32(*p_a1);
	enemy_look_at_target(a0, turtle, &ignored, &ignored_2);
	OBJECT(a0)->contacts &= 0xE0u;
	enemy_floor_contacts(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d7, p_a5);
	enemy_keep_on_screen(a0);
	jump_target = mem_read32(0x53D2Au + (int16_t)OBJECT(a0)->enemy_shredder.move);
	switch (jump_target)
	{
	case 0x049A06u:
		enemy_jab(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049A52u:
		enemy_chop(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049A8Eu:
		enemy_swing(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049ACAu:
		enemy_high_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049B06u:
		enemy_jump_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049BBCu:
		enemy_long_jump_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x049C72u:
		func_049C72();
		return;
	case 0x049C74u:
		func_049C74();
		return;
	case 0x049C76u:
		enemy_grab(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B2DAu:
		enemy_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B316u:
		enemy_low_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B352u:
		enemy_leaping_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B42Au:
		enemy_jump_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B4E0u:
		enemy_flying_slash_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04B5D6u:
		enemy_smash_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E2C4u:
		enemy_spear_thrust(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E336u:
		enemy_spear_throw(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E3C4u:
		enemy_knife_stab(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E400u:
		enemy_high_kick_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E43Cu:
		enemy_jump_kick_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04E4F2u:
		enemy_throw_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04EBD6u:
		enemy_throw_axes(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04EC5Eu:
		enemy_high_kick_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04EC9Au:
		enemy_gun_swing(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04ECD6u:
		enemy_shoot_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04F076u:
		enemy_throw_shuriken(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04F0E4u:
		enemy_boomerang_throw(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FA96u:
		enemy_rocksteady_pincer_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FC04u:
		enemy_rocksteady_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FCD4u:
		enemy_rocksteady_punch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FD4Cu:
		enemy_rocksteady_gun_butt(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x04FD88u:
		enemy_rocksteady_shoot(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x0508A0u:
		enemy_bebop_pincer_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x050ADCu:
		enemy_bebop_punch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x050B8Cu:
		enemy_bebop_charge(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x050C68u:
		enemy_bebop_shoot(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x052306u:
		enemy_rodney_shoot(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x052422u:
		enemy_rodney_whip(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x0534C4u:
		enemy_shredder_kick(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x053524u:
		enemy_shredder_thrust(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x05356Eu:
		enemy_shredder_slash(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x0535B8u:
		enemy_shredder_sweep(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0x053602u:
		enemy_shredder_ray(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

/* hit: shrugged off in the air, else his reaction by his health */
void enemy_shredder_hit(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint8_t side = 0;

	*p_d7 = (*p_d7 & ~0xFFu) | 0x92u;
	queue_sound((uint8_t)*p_d7, 0u);
	side = OBJECT(a0)->enemy_shredder.side;
	OBJECT(a0)->enemy_shredder.side = side & ~1u;
	if ((side & 1u) != 0u)
	{
		shredder_firing_ray = 0u;
		if (OBJECT(a0)->hit_state < 4u)
			OBJECT(a0)->enemy_shredder.ray_wait = 1u;
	}
	if ((OBJECT(a0)->health_bars | OBJECT(a0)->health) != 0u)
	{
		if (OBJECT(a0)->health == 0u)
		{
			OBJECT(a0)->enemy_shredder.move = 0xCCu;
			OBJECT(a0)->routine++;
			enemy_shredder_react(a0, p_d5, p_d7, p_a1, p_a5);
			return;
		}
		*p_d7 = ((*p_d7 & ~0xFFFFu) | (((uint32_t)OBJECT(a0)->floor_height << 8u) | OBJECT(a0)->frame_time)) & ~0xFFu;
		if ((uint16_t)*p_d7 != OBJECT(a0)->height)
		{
			OBJECT(a0)->colour = 0xBu;
			OBJECT(a0)->routine = 2u;
			return;
		}
		if ((int8_t)(((uint32_t)OBJECT(a0)->flags << 1) ^ OBJECT(a0)->hit) >= 0)
			OBJECT(a0)->enemy_shredder.move = 0xD0u;
		else
			OBJECT(a0)->enemy_shredder.move = 0xD4u;
	}
	else if ((int8_t)OBJECT(a0)->parameter >= 0)
		OBJECT(a0)->enemy_shredder.move = 0xD8u;
	else
		OBJECT(a0)->enemy_shredder.move = 0xDCu;
	OBJECT(a0)->routine++;
	enemy_shredder_react(a0, p_d5, p_d7, p_a1, p_a5);
}

/* his reaction to a hit */
void enemy_shredder_react(uint32_t a0, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	*p_a1 = 0x60000u | OBJECT(a0)->enemy_shredder.target;
	OBJECT(a0)->contacts &= 0xE0u;
	enemy_floor_contacts(a0, &ignored, &ignored_2, &ignored_3, &ignored_4, p_d5, p_d7, p_a5);
	enemy_keep_on_screen(a0);
	switch ((uint32_t)(int16_t)OBJECT(a0)->enemy_shredder.move)
	{
	case 228:
		enemy_crash_into_scenery(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 232:
		enemy_crash_into_scenery_low(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 0:
		enemy_flinch_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 4:
		enemy_flinch_bent(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 8:
		enemy_flinch_reel(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 12:
		enemy_flinch_hunched(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 36:
		enemy_killed_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 32:
		enemy_killed_forward(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 16:
		enemy_knocked_forward(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 128:
		enemy_thrown_by_donatello(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 132:
		*p_a5 = unreached_04A338(a0, *p_a1);
		return;
	case 136:
		enemy_thrown_by_michelangelo(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 140:
		*p_a5 = unreached_04A3F4(a0, *p_a1);
		return;
	case 188:
		enemy_thrown_by_raphael(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 192:
		*p_a5 = unreached_04A4B2(a0, *p_a1);
		return;
	case 196:
		enemy_thrown_by_leonardo(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 200:
		*p_a5 = unreached_04A570(a0, *p_a1);
		return;
	case 20:
		enemy_knocked_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 24:
		enemy_die(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 28:
		enemy_die_on_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 40:
		enemy_flinch_back_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 44:
		enemy_flinch_bent_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 48:
		enemy_flinch_reel_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 52:
		enemy_flinch_hunched_sword(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 56:
		enemy_flinch_back_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 60:
		enemy_flinch_bent_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 68:
		enemy_flinch_hunched_hammer(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 72:
		enemy_flinch_back_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 76:
		enemy_flinch_bent_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 80:
		enemy_flinch_reel_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 84:
		enemy_flinch_hunched_spear(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 88:
		enemy_flinch_back_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 92:
		enemy_flinch_bent_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 96:
		enemy_flinch_reel_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 100:
		enemy_flinch_hunched_knife(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 120:
		enemy_flinch_back_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 124:
		enemy_flinch_bent_gun(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 104:
		enemy_flinch_back_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 108:
		enemy_flinch_bent_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 112:
		enemy_flinch_reel_axe(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 164:
		enemy_rocksteady_flinch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 168:
		enemy_rocksteady_reel(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 160:
		enemy_rocksteady_flinch_from_behind(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 152:
		enemy_rocksteady_knocked_down(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 156:
		enemy_rocksteady_defeated(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 172:
		enemy_bebop_flinch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 176:
		enemy_bebop_flinch_from_behind(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 180:
		enemy_bebop_knocked_down(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 184:
		enemy_bebop_defeated(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 148:
		enemy_mouser_thrown_off(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 224:
		enemy_mouser_break_down(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 144:
		enemy_mouser_knocked_flying(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 64:
		enemy_rodney_knocked_back(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 116:
		enemy_rodney_destroyed(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 204:
		enemy_shredder_lose_bar(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 208:
		enemy_shredder_flinch(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 212:
		enemy_shredder_flinch_from_behind(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 216:
		enemy_shredder_defeated(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	case 220:
		enemy_shredder_vanish(a0, *p_a1, p_d5, p_d7, p_a5);
		return;
	}
}

/* comes out of the screen when he is the last enemy, with his music */
void enemy_shredder_appear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052CA2_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_shredder_appear_wait(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	if (enemies_on_screen != 1u)
		return d7;
	OBJECT(a0)->state++;
	OBJECT(a0)->flags |= 0x80u;
	d7_2 = (d7 & ~0xFFu) | 0x16u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = animations_05AD40_ADDRESS;
	set_animation(0u, a0, animation);
	return d7_2;
}

uint32_t enemy_shredder_appear_step_out(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return d7;
	OBJECT(a0)->x_speed = 0;
	OBJECT(a0)->y_speed = -0x100;
	OBJECT(a0)->enemy_shredder.timer = 0x20u;
	OBJECT(a0)->state++;
	d7_2 = (d7 & ~0xFFFFu) | 0x6Au;
	music = d7_2;
	queue_sound((uint8_t)d7_2, 0u);
	d7_2 = (d7_2 & ~0xFFu) | 0xA7u;
	queue_sound((uint8_t)d7_2, 0u);
	animation = animations_05B07E_ADDRESS;
	set_animation(0u, a0, animation);
	return d7_2;
}

uint32_t enemy_shredder_appear_walk_in(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_shredder.timer;
	OBJECT(a0)->enemy_shredder.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->flags |= 2u;
		OBJECT(a0)->routine = 2u;
		OBJECT(a0)->state = 0u;
		a6 = 0x54786u;
		d7 = enemy_set_health(d7, a0, a6);
	}
	move_object(a0);
	return d7;
}

/* makes a clone of himself, blinking */
void enemy_shredder_split(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052D52_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_split_start(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t zero = 0;
	uint16_t d7_2 = 0;
	uint32_t animation = 0, d7 = 0, object = 0;

	OBJECT(a0)->flags &= ~2u;
	animation = animations_05B032_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5B03Cu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->state++;
	OBJECT(a0)->x_speed = 0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->enemy_shredder.timer = 0x20u;
	*p_a5 = 0x52D5Au;
	start_object_from_record(a0, *p_a5, &d7, &object, &zero);
	OBJECT(object)->health_bars = OBJECT(a0)->health_bars;
	d7_2 = (uint16_t)((d7 & ~0xFFu) | 0x3Du);
	queue_sound((uint8_t)d7_2, object);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_2;
}

void enemy_shredder_split_blink(uint32_t a0)
{
	uint8_t timer = 0;

	OBJECT(a0)->flags ^= 0x80u;
	timer = OBJECT(a0)->enemy_shredder.timer;
	OBJECT(a0)->enemy_shredder.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->flags |= 0x82u;
		OBJECT(a0)->enemy_shredder.move_time = 0u;
	}
	move_object_blocked(a0);
}

/* a clone comes in blinking */
void enemy_shredder_clone_appear(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052DDC_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_clone_appear_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->flags |= 0x80u;
	animation = animations_05B032_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5B03Cu;
	set_animation(0u, a0, animation);
	OBJECT(a0)->state++;
	OBJECT(a0)->x_speed = -0x100;
	OBJECT(a0)->y_speed = 0;
	OBJECT(a0)->enemy_shredder.move_time = 0x20u;
}

uint32_t enemy_shredder_clone_appear_blink(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t move_time = 0;

	OBJECT(a0)->flags ^= 0x80u;
	move_time = OBJECT(a0)->enemy_shredder.move_time;
	OBJECT(a0)->enemy_shredder.move_time = move_time - 1u;
	if (move_time != 1u)
	{
		move_object_blocked(a0);
		return d7;
	}
	OBJECT(a0)->flags |= 0x82u;
	OBJECT(a0)->routine = 2u;
	OBJECT(a0)->state = 0u;
	a6 = 0x547A6u;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		a6 = 0x547B6u;
	d7 = enemy_set_health(d7, a0, a6);
	move_object_blocked(a0);
	return d7;
}

/* walks to his side of his turtle */
void enemy_shredder_walk_to_side(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052E60_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_walk_to_side_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_shredder.move_time = 0xF0u;
	OBJECT(a0)->state++;
	target_direction = OBJECT(a0)->enemy_shredder.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		*p_a5 = 0x52E7Cu;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_shredder_walk_to_side_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	target_direction = OBJECT(a0)->enemy_shredder.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		*p_a5 = 0x52E7Cu;
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	if (OBJECT(a0)->enemy_shredder.target_dx < 0x40u || (int8_t)(target_direction - 0x40u - OBJECT(a0)->enemy_shredder.side) < 0)
	{
		OBJECT(a0)->x_speed = 0x180;
		OBJECT(a0)->y_speed = 0;
		if ((int8_t)OBJECT(a0)->enemy_shredder.side < 0)
			OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	else
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = 0x180;
		if ((int8_t)OBJECT(a0)->enemy_shredder.target_direction >= 0)
			OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	}
	if (OBJECT(a0)->enemy_shredder.target_dy < 3u)
		OBJECT(a0)->state++;
	move_object_blocked(a0);
}

void enemy_shredder_walk_to_side_crouch(uint32_t a0)
{
	uint32_t animation = 0;

	if ((frame_count & 0x700u) != 0u)
	{
		OBJECT(a0)->state += 2u;
		return;
	}
	OBJECT(a0)->state++;
	animation = 0x5B9B2u;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5B9BEu;
	set_animation(0u, a0, animation);
}

void enemy_shredder_walk_to_side_turn(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->state++;
		target_direction = OBJECT(a0)->enemy_shredder.target_direction;
		a6 = mem_read32(a1);
		*p_a5 = animations_052E74_ADDRESS;
		if ((int8_t)OBJECT(a0)->health_bars >= 0)
			*p_a5 = 0x52E7Cu;
		enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
	}
}

void enemy_shredder_walk_to_side_hold(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	target_direction = OBJECT(a0)->enemy_shredder.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		*p_a5 = 0x52E7Cu;
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	if (OBJECT(a0)->enemy_shredder.target_dx >= 0x10u)
	{
		OBJECT(a0)->x_speed = 0x180;
		OBJECT(a0)->y_speed = 0;
		if ((int8_t)(target_direction - 0x40u) >= 0)
			OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	else
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = 0;
	}
	if (OBJECT(a0)->enemy_shredder.target_dy < 3u)
	{
		move_object_blocked(a0);
		return;
	}
	OBJECT(a0)->state -= 3u;
	move_object_blocked(a0);
}

/* walks to his turtle */
void enemy_shredder_walk_to_target(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052FE4_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_walk_to_target_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_shredder.move_time = 1u;
	OBJECT(a0)->state++;
	target_direction = OBJECT(a0)->enemy_shredder.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		*p_a5 = 0x52E7Cu;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_shredder_walk_to_target_step(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t a5 = 0, a6 = 0, d0 = 0, d6 = 0;
	uint8_t move_time = 0;

	move_time = OBJECT(a0)->enemy_shredder.move_time;
	OBJECT(a0)->enemy_shredder.move_time = move_time - 1u;
	if (move_time == 1u)
	{
		a6 = mem_read32(a1);
		d0 = direction_to_object(0u, a0, a6);
		a5 = animations_052E74_ADDRESS;
		if ((int8_t)OBJECT(a0)->health_bars >= 0)
			a5 = 0x52E7Cu;
		enemy_turn_to_object((uint8_t)d0, a0, a6, p_d7, &a5);
		d1 = 0x180u;
		speeds_from_direction((uint8_t)d0, d1, &d6, p_d7, p_a5);
		OBJECT(a0)->x_speed = d6;
		OBJECT(a0)->y_speed = *p_d7;
		OBJECT(a0)->enemy_shredder.move_time = 8u;
	}
	if (OBJECT(a0)->enemy_shredder.target_dx >= 0x3Cu || OBJECT(a0)->enemy_shredder.target_dy >= 0x20u)
		move_object_blocked(a0);
}

/* guards against his turtle's attack, then strikes back */
void enemy_shredder_guard(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05307C_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_guard_start(uint32_t a0)
{
	uint32_t animation = 0;

	animation = animations_05B6EE_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5B6F8u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->flags &= ~0xEu;
	OBJECT(a0)->enemy_shredder.move_time = 0x1Eu;
	OBJECT(a0)->state++;
}

void enemy_shredder_guard_counter(uint32_t a0)
{
	uint16_t d6 = 0, target_dx = 0;
	uint32_t a6 = 0;
	uint8_t move_time = 0;
	uint16_t t1 = 0;

	move_time = OBJECT(a0)->enemy_shredder.move_time;
	OBJECT(a0)->enemy_shredder.move_time = move_time - 1u;
	if (move_time != 1u)
		return;
	OBJECT(a0)->enemy_shredder.approach = 0u;
	a6 = record_052ACE_ADDRESS;
	target_dx = OBJECT(a0)->enemy_shredder.target_dx;
	d6 = 2u;
	do
	{
		if (target_dx < DATA16(a6))
			break;
		t1 = d6 - 1u;
		d6 = t1;
		a6 += 2u;
	} while (t1 != 0xFFFFu);
	OBJECT(a0)->enemy_shredder.move = DATA16(a6 + 8u);
	OBJECT(a0)->routine = 3u;
	OBJECT(a0)->state = 0u;
	OBJECT(a0)->flags &= ~8u;
}

/* walks away and waits while his turtle is down */
void enemy_shredder_back_off(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0530F6_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_back_off_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d6 = 0;

	OBJECT(a0)->enemy_shredder.move_time = 0x40u;
	OBJECT(a0)->enemy_shredder.timer = 0x28u;
	d0 = OBJECT(a0)->enemy_shredder.target_direction;
	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		*p_a5 = 0x52E7Cu;
	a6 = mem_read32(a1);
	enemy_face_object(d0, a0, a6, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x100u;
	speeds_from_direction(d0, d1, &d6, p_d7, p_a5);
	OBJECT(a0)->x_speed = d6;
	OBJECT(a0)->y_speed = *p_d7;
	OBJECT(a0)->state++;
}

void enemy_shredder_back_off_walk(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0, animation = 0;
	uint8_t timer = 0;

	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		*p_a5 = 0x52E7Cu;
	target_direction = OBJECT(a0)->enemy_shredder.target_direction;
	a6 = mem_read32(a1);
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	move_object_blocked(a0);
	timer = OBJECT(a0)->enemy_shredder.timer;
	OBJECT(a0)->enemy_shredder.timer = timer - 1u;
	if (timer != 1u)
	{
		enemy_shredder_back_off_wait(a0, a1);
		return;
	}
	OBJECT(a0)->state++;
	animation = animations_05B032_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5B03Cu;
	set_animation(0u, a0, animation);
}

void enemy_shredder_back_off_wait(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		OBJECT(a0)->enemy_shredder.approach = 0u;
		OBJECT(a0)->enemy_shredder.move_time = 0u;
	}
}

/* a bar gone: a piece of him flies off, his health back */
void enemy_shredder_lose_bar(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0531BA_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_lose_bar_start(uint32_t a0)
{
	uint32_t animation = 0;

	OBJECT(a0)->colour = 0xBu;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_shredder.timer = 0xCu;
	animation = 0x5B572u;
	set_animation(0u, a0, animation);
}

void enemy_shredder_lose_bar_end(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t timer = 0;

	enemy_shredder_flash(a0);
	if (OBJECT(a0)->frame_time != 0u)
	{
		timer = OBJECT(a0)->enemy_shredder.timer;
		OBJECT(a0)->enemy_shredder.timer = timer - 1u;
		if (timer == 1u)
		{
			*p_a5 = 0x531C2u;
			start_shot(a0, *p_a5, &d7, &ignored, &zero);
		}
	}
	else
	{
		OBJECT(a0)->colour = 0xFFu;
		a6 = 0x54796u;
		if ((int8_t)OBJECT(a0)->parameter < 0)
			a6 = 0x547B6u;
		d7 = enemy_set_health(d7, a0, a6);
		enemy_back_to_thinking_hittable(a0);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

/* his colour flashing while hit */
void enemy_shredder_flash(uint32_t a0)
{
	uint8_t d0 = 0;

	d0 = 0xBu;
	if ((frame_count & 2u) != 0u)
		d0 = 0xFFu;
	OBJECT(a0)->colour = d0;
}

/* hit from the front, knocked back every third hit */
void enemy_shredder_flinch(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05324E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_flinch_start(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t hits_to_knock_back = 0;

	OBJECT(a0)->colour = 0xBu;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_shredder.timer = 0u;
	hits_to_knock_back = OBJECT(a0)->enemy_shredder.hits_to_knock_back;
	OBJECT(a0)->enemy_shredder.hits_to_knock_back = hits_to_knock_back - 1u;
	if (hits_to_knock_back == 1u)
	{
		OBJECT(a0)->enemy_shredder.hits_to_knock_back = 3u;
		OBJECT(a0)->enemy_shredder.timer = 0x10u;
		OBJECT(a0)->x_speed = 0x200;
		OBJECT(a0)->y_speed = 0;
		if ((OBJECT(a0)->flags & 0x40u) != 0u)
			OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	animation = animations_05B4F2_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5B512u;
	set_animation(0u, a0, animation);
}

void enemy_shredder_flinch_end(uint32_t a0)
{
	enemy_shredder_flash(a0);
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->colour = 0xFFu;
		enemy_back_to_thinking_hittable(a0);
		return;
	}
	if (OBJECT(a0)->enemy_shredder.timer == 0u)
		return;
	OBJECT(a0)->enemy_shredder.timer--;
	move_object_blocked(a0);
}

/* hit from behind, knocked back every third hit */
void enemy_shredder_flinch_from_behind(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0532E0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_flinch_from_behind_start(uint32_t a0)
{
	uint32_t animation = 0;
	uint8_t hits_to_knock_back = 0;

	OBJECT(a0)->colour = 0xBu;
	OBJECT(a0)->state++;
	OBJECT(a0)->enemy_shredder.timer = 0u;
	hits_to_knock_back = OBJECT(a0)->enemy_shredder.hits_to_knock_back;
	OBJECT(a0)->enemy_shredder.hits_to_knock_back = hits_to_knock_back - 1u;
	if (hits_to_knock_back == 1u)
	{
		OBJECT(a0)->enemy_shredder.hits_to_knock_back = 3u;
		OBJECT(a0)->enemy_shredder.timer = 0x10u;
		OBJECT(a0)->x_speed = 0x200;
		OBJECT(a0)->y_speed = 0;
		if ((OBJECT(a0)->flags & 0x40u) == 0u)
			OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
	}
	animation = 0x5B532u;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5B552u;
	set_animation(0u, a0, animation);
}

/* beaten: falls, the music stops, his clones vanish */
void enemy_shredder_defeated(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_053348_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_shredder_defeated_start(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, animation = 0;

	OBJECT(a0)->colour = 0xBu;
	enemy_boss_face_target(a0, a1);
	a6 = 0x5335Cu;
	d7 = enemy_start_arc(d7, a0, a6);
	animation = 0x5B592u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->contacts |= 0x80u;
	OBJECT(a0)->state++;
	return d7;
}

uint32_t enemy_shredder_defeated_fall(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, animation = 0;

	OBJECT(a0)->colour = 0xFFu;
	move_object_with_height_blocked(a0);
	a6 = 0x5335Cu;
	enemy_arc_step(a0, a6);
	enemy_landed(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	OBJECT(a0)->contacts &= 0x7Fu;
	OBJECT(a0)->state++;
	animation = 0x5B5A8u;
	set_animation(0u, a0, animation);
	return d7;
}

uint32_t enemy_shredder_defeated_land(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if ((uint16_t)OBJECT(a0)->x_speed != 0u)
	{
		move_object_blocked(a0);
		a6 = 0x5335Cu;
		enemy_arc_step(a0, a6);
	}
	if (OBJECT(a0)->frame_time == 0u)
	{
		d7 &= ~0xFFFFu;
		music = d7;
		queue_sound((uint8_t)d7, a6);
		d7 |= 0x81u;
		queue_sound((uint8_t)d7, a6);
		OBJECT(a0)->enemy_shredder.timer = 0x78u;
		OBJECT(a0)->state++;
		shredder_beaten = 0xFFu;
	}
	return d7;
}

void enemy_shredder_defeated_wait(uint32_t a0)
{
	uint8_t timer = 0, t1 = 0;

	timer = OBJECT(a0)->enemy_shredder.timer;
	OBJECT(a0)->enemy_shredder.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->state++;
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
		{
			enemies_on_screen = 0u;
			enemy_shredder_defeated_stay();
			return;
		}
	}
	enemy_shredder_defeated_stay();
}

void enemy_shredder_defeated_stay(void)
{
}

/* a clone beaten or told to vanish blinks and is gone */
void enemy_shredder_vanish(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05344C_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_vanish_start(uint32_t a0, uint32_t a1)
{
	uint32_t animation = 0;

	OBJECT(a0)->colour = 0xAu;
	enemy_leave_side(a0, a1);
	OBJECT(a0)->state++;
	animation = animations_05B4F2_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5B512u;
	set_animation(0u, a0, animation);
}

void enemy_shredder_vanish_wait(uint32_t a0)
{
	if (OBJECT(a0)->frame_time == 0u)
	{
		OBJECT(a0)->enemy_shredder.timer = 0x78u;
		OBJECT(a0)->state++;
	}
}

void enemy_shredder_vanish_blink(uint32_t a0)
{
	uint8_t timer = 0, t1 = 0;

	if ((OBJECT(a0)->enemy_shredder.timer & 0x10u) == 0u)
		OBJECT(a0)->flags ^= 0x80u;
	timer = OBJECT(a0)->enemy_shredder.timer;
	OBJECT(a0)->enemy_shredder.timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(a0)->flags = 0u;
		OBJECT(a0)->contacts = 0u;
		t1 = enemies_on_screen - 1u;
		enemies_on_screen = t1;
		if ((int8_t)t1 < 0)
			enemies_on_screen = 0u;
	}
}

/* kicks */
void enemy_shredder_kick(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0534D0_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_shredder_kick_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = animations_05B91E_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5B968u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x301u;
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

/* the blow over, back to thinking */
void enemy_shredder_blow_end(uint32_t a0)
{
	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->flags |= 2u;
	enemy_back_to_thinking(a0);
}

/* thrusts the sword */
void enemy_shredder_thrust(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_053530_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_shredder_thrust_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = animations_05BB0A_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5BB54u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x301u;
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

/* slashes with the sword, knocking down */
void enemy_shredder_slash(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05357A_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_shredder_slash_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = animations_05B73A_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5B784u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x103u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

/* sweeps low with the sword */
void enemy_shredder_sweep(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0535C4_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

uint32_t enemy_shredder_sweep_start(uint32_t d7, uint32_t a0)
{
	uint32_t animation = 0, d7_2 = 0;

	animation = animations_05BD3E_ADDRESS;
	if ((int8_t)OBJECT(a0)->health_bars >= 0)
		animation = 0x5BD88u;
	set_animation(0u, a0, animation);
	OBJECT(a0)->damage = 0x203u;
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = enemy_face_target(d7_2, a0);
	OBJECT(a0)->flags |= 4u;
	OBJECT(a0)->state++;
	return d7_2;
}

/* lines up with his turtle and fires his ray */
void enemy_shredder_ray(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05360E_ADDRESS;
	run_object_state(a0, a1, a6, p_d5, p_d7, p_a5);
}

void enemy_shredder_ray_start(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t target_direction = 0;
	uint32_t a6 = 0;

	OBJECT(a0)->enemy_shredder.timer = 0xF0u;
	OBJECT(a0)->state++;
	target_direction = OBJECT(a0)->enemy_shredder.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	enemy_face_object(target_direction, a0, a6, p_d7, p_a5);
}

void enemy_shredder_ray_line_up(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0, target_direction = 0;
	uint32_t a6 = 0, animation = 0;
	uint8_t timer = 0;

	target_direction = OBJECT(a0)->enemy_shredder.target_direction;
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	enemy_turn_to_object(target_direction, a0, a6, p_d7, p_a5);
	if (OBJECT(a0)->enemy_shredder.target_dx < 0x50u)
	{
		OBJECT(a0)->y_speed = 0;
		d0 = 8u;
		OBJECT(a0)->x_speed = 0x280;
		if ((int8_t)(OBJECT(a0)->enemy_shredder.target_direction - 0x40u) < 0)
		{
			d0 = 0x10u;
			OBJECT(a0)->x_speed = 0u - OBJECT(a0)->x_speed;
		}
		if ((d0 & OBJECT(a0)->contacts) != 0u)
		{
			OBJECT(a0)->x_speed = 0;
			OBJECT(a0)->y_speed = 0x280;
			if ((int8_t)OBJECT(a0)->enemy_shredder.target_direction >= 0)
				OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
		}
	}
	else
	{
		OBJECT(a0)->x_speed = 0;
		OBJECT(a0)->y_speed = 0x280;
		if ((int8_t)OBJECT(a0)->enemy_shredder.target_direction >= 0)
			OBJECT(a0)->y_speed = 0u - OBJECT(a0)->y_speed;
	}
	move_object_blocked(a0);
	timer = OBJECT(a0)->enemy_shredder.timer;
	OBJECT(a0)->enemy_shredder.timer = timer - 1u;
	if (timer == 1u || OBJECT(a0)->enemy_shredder.target_dy < 3u)
	{
		OBJECT(a0)->state++;
		animation = 0x5BF4Cu;
		set_animation(0u, a0, animation);
	}
}

void enemy_shredder_ray_charge(uint32_t a0)
{
	uint32_t animation = 0;

	if (OBJECT(a0)->frame_time != 0u)
		return;
	OBJECT(a0)->enemy_shredder.timer = 0xCu;
	OBJECT(a0)->state++;
	animation = 0x5BF8Au;
	set_animation(0u, a0, animation);
}

void enemy_shredder_ray_fire(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint16_t d7_3 = 0;
	uint32_t animation = 0, d7_2 = 0, object = 0;
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_shredder.timer;
	OBJECT(a0)->enemy_shredder.timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(a0)->flags &= 0xBFu;
	if ((int8_t)(OBJECT(a0)->enemy_shredder.target_direction - 0x40u) < 0)
		OBJECT(a0)->flags |= 0x40u;
	*p_a5 = 0x53622u;
	start_shot(a0, *p_a5, &d7_2, &object, &zero);
	OBJECT(object)->unk_24 = (uint8_t)(a0 >> 24u);
	OBJECT(object)->unk_25 = (uint8_t)(a0 >> 16u);
	OBJECT(object)->unk_26 = (uint8_t)(a0 >> 8u);
	OBJECT(object)->unk_27 = (uint8_t)a0;
	d7_3 = (uint16_t)((d7_2 & ~0xFFu) | 0x1Cu);
	queue_sound((uint8_t)d7_3, object);
	OBJECT(a0)->enemy_shredder.timer = 0x3Cu;
	OBJECT(a0)->state++;
	animation = 0x5BFAEu;
	set_animation(0u, a0, animation);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_3;
}

void enemy_shredder_ray_end(uint32_t a0)
{
	uint8_t timer = 0;

	timer = OBJECT(a0)->enemy_shredder.timer;
	OBJECT(a0)->enemy_shredder.timer = timer - 1u;
	if (timer == 1u)
	{
		shredder_firing_ray = 0u;
		OBJECT(a0)->enemy_shredder.side &= ~1u;
		enemy_back_to_thinking(a0);
	}
}
