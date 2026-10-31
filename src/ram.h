/**
 *    Name:        ram.h
 *    Description: the game's variables, tables, board registers and structures
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    30-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#ifndef TMNT_RAM_H
#define TMNT_RAM_H

/* the game's variables in work RAM (060000-063FFF) */
#define WORKING_LAYER 0x063300u
#define LAYER_A 0x063340u
#define LAYER_B 0x063380u
#define game_state_ADDRESS 0x060001u
#define game_state RAM8(game_state_ADDRESS)
#define step_timer_ADDRESS 0x060002u
#define step_timer RAM8(step_timer_ADDRESS)
#define game_step_ADDRESS 0x060003u
#define game_step RAM8(game_step_ADDRESS)
#define scene_timer_ADDRESS 0x060004u
#define scene_timer RAM8(scene_timer_ADDRESS)
#define scene_ADDRESS 0x060005u
#define scene RAM8(scene_ADDRESS)
#define continue_count_ADDRESS 0x060006u
#define continue_count RAM8(continue_count_ADDRESS)
#define scene_step_ADDRESS 0x060007u
#define scene_step RAM8(scene_step_ADDRESS)
#define continue_count_time_ADDRESS 0x060008u
#define continue_count_time RAM8(continue_count_time_ADDRESS)
#define scene_substep_ADDRESS 0x060009u
#define scene_substep RAM8(scene_substep_ADDRESS)
#define scene_subsubstep_ADDRESS 0x06000Bu
#define scene_subsubstep RAM8(scene_subsubstep_ADDRESS)
#define job_queue_write_ADDRESS 0x060010u
#define job_queue_write RAM32(job_queue_write_ADDRESS)
#define job_queue_read_ADDRESS 0x060014u
#define job_queue_read RAM32(job_queue_read_ADDRESS)
#define sound_queue_write_ADDRESS 0x060018u
#define sound_queue_write RAM32(sound_queue_write_ADDRESS)
#define sound_queue_read_ADDRESS 0x06001Cu
#define sound_queue_read RAM32(sound_queue_read_ADDRESS)
#define turtle_inputs_ADDRESS 0x060020u
#define turtle_inputs(index) RAM8(turtle_inputs_ADDRESS + (index))
#define turtle_inputs_last_frame_ADDRESS 0x060024u
#define turtle_inputs_last_frame RAM32(turtle_inputs_last_frame_ADDRESS)
#define turtle_inputs_2_frames_ago_ADDRESS 0x060028u
#define turtle_inputs_2_frames_ago RAM32(turtle_inputs_2_frames_ago_ADDRESS)
#define turtle_inputs_3_frames_ago_ADDRESS 0x06002Cu
#define turtle_inputs_3_frames_ago RAM32(turtle_inputs_3_frames_ago_ADDRESS)
#define dip_switches_1_ADDRESS 0x060030u
#define dip_switches_1 RAM8(dip_switches_1_ADDRESS)
#define dip_switches_2_ADDRESS 0x060031u
#define dip_switches_2 RAM8(dip_switches_2_ADDRESS)
#define dip_switches_3_ADDRESS 0x060032u
#define dip_switches_3 RAM8(dip_switches_3_ADDRESS)
#define player_inputs_ADDRESS 0x060034u
#define player_inputs(index) RAM8(player_inputs_ADDRESS + (index))
#define player_inputs_last_frame_ADDRESS 0x060038u
#define player_inputs_last_frame(index) RAM8(player_inputs_last_frame_ADDRESS + (index))
#define player_inputs_2_frames_ago_ADDRESS 0x06003Cu
#define player_inputs_2_frames_ago RAM32(player_inputs_2_frames_ago_ADDRESS)
#define player_inputs_3_frames_ago_ADDRESS 0x060040u
#define player_inputs_3_frames_ago RAM32(player_inputs_3_frames_ago_ADDRESS)
#define coin_switches_ADDRESS 0x060044u
#define coin_switches RAM8(coin_switches_ADDRESS)
#define coin_switches_last_frame_ADDRESS 0x060045u
#define coin_switches_last_frame RAM8(coin_switches_last_frame_ADDRESS)
#define coin_switches_2_frames_ago_ADDRESS 0x060046u
#define coin_switches_2_frames_ago RAM8(coin_switches_2_frames_ago_ADDRESS)
#define coin_switches_3_frames_ago_ADDRESS 0x060047u
#define coin_switches_3_frames_ago RAM8(coin_switches_3_frames_ago_ADDRESS)
#define demo_held_inputs_ADDRESS 0x060048u
#define demo_held_inputs(index) RAM8(demo_held_inputs_ADDRESS + (index))
#define turtle_presses_ADDRESS 0x06004Cu
#define turtle_presses(index) RAM8(turtle_presses_ADDRESS + (index))
#define player_presses_ADDRESS 0x060050u
#define player_presses(index) RAM8(player_presses_ADDRESS + (index))
#define unk_060054_ADDRESS 0x060054u
#define unk_060054 RAM8(unk_060054_ADDRESS)
#define unk_060055_ADDRESS 0x060055u
#define unk_060055 RAM8(unk_060055_ADDRESS)
#define unk_060056_ADDRESS 0x060056u
#define unk_060056 RAM8(unk_060056_ADDRESS)
#define unk_060057_ADDRESS 0x060057u
#define unk_060057 RAM8(unk_060057_ADDRESS)
#define board_control_ADDRESS 0x060058u
#define board_control RAM8(board_control_ADDRESS)
#define layer_priority_ADDRESS 0x060059u
#define layer_priority RAM8(layer_priority_ADDRESS)
#define sprite_control_ADDRESS 0x06005Au
#define sprite_control RAM8(sprite_control_ADDRESS)
#define tile_flip_ADDRESS 0x06005Bu
#define tile_flip RAM8(tile_flip_ADDRESS)
#define layer_a_scroll_x_ADDRESS 0x06005Cu
#define layer_a_scroll_x RAM16(layer_a_scroll_x_ADDRESS)
#define layer_a_scroll_y_ADDRESS 0x06005Eu
#define layer_a_scroll_y RAM16(layer_a_scroll_y_ADDRESS)
#define layer_b_scroll_x_ADDRESS 0x060060u
#define layer_b_scroll_x RAM16(layer_b_scroll_x_ADDRESS)
#define layer_b_scroll_y_ADDRESS 0x060062u
#define layer_b_scroll_y RAM16(layer_b_scroll_y_ADDRESS)
#define tile_banks_0_1_ADDRESS 0x060064u
#define tile_banks_0_1 RAM8(tile_banks_0_1_ADDRESS)
#define tile_banks_2_3_ADDRESS 0x060065u
#define tile_banks_2_3 RAM8(tile_banks_2_3_ADDRESS)
#define scratch_ADDRESS 0x060066u
#define scratch RAM32(scratch_ADDRESS)
#define scratch_byte_ADDRESS 0x060066u
#define scratch_byte RAM8(scratch_byte_ADDRESS)
#define scratch_word_ADDRESS 0x060066u
#define scratch_word RAM16(scratch_word_ADDRESS)
#define balloon_kept_y_ADDRESS 0x060068u
#define balloon_kept_y RAM16(balloon_kept_y_ADDRESS)
#define balloon_kept_line_ADDRESS 0x06006Au
#define balloon_kept_line RAM16(balloon_kept_line_ADDRESS)
#define balloon_kept_bank_ADDRESS 0x06006Cu
#define balloon_kept_bank RAM16(balloon_kept_bank_ADDRESS)
#define top_score_ADDRESS 0x060076u
#define top_score RAM16(top_score_ADDRESS)
#define text_colour_ADDRESS 0x06007Au
#define text_colour RAM8(text_colour_ADDRESS)
#define spare_text_colour_ADDRESS 0x06007Bu
#define spare_text_colour RAM8(spare_text_colour_ADDRESS)
#define music_ADDRESS 0x060080u
#define music RAM8(music_ADDRESS)
#define unk_060081_ADDRESS 0x060081u
#define unk_060081 RAM8(unk_060081_ADDRESS)
#define jobs_pending_ADDRESS 0x060082u
#define jobs_pending RAM8(jobs_pending_ADDRESS)
#define palettes_busy_ADDRESS 0x060083u
#define palettes_busy RAM8(palettes_busy_ADDRESS)
#define lives_per_credit_ADDRESS 0x060090u
#define lives_per_credit RAM8(lives_per_credit_ADDRESS)
#define free_play_ADDRESS 0x060091u
#define free_play RAM8(free_play_ADDRESS)
#define demo_sounds_ADDRESS 0x060092u
#define demo_sounds RAM8(demo_sounds_ADDRESS)
#define unused_dip_flag_ADDRESS 0x060093u
#define unused_dip_flag RAM8(unused_dip_flag_ADDRESS)
#define difficulty_setting_ADDRESS 0x060094u
#define difficulty_setting RAM8(difficulty_setting_ADDRESS)
#define unused_dip_setting_flag_ADDRESS 0x060095u
#define unused_dip_setting_flag RAM8(unused_dip_setting_flag_ADDRESS)
#define unused_dip_setting_value_ADDRESS 0x060096u
#define unused_dip_setting_value RAM32(unused_dip_setting_value_ADDRESS)
#define unused_dip_setting_ADDRESS 0x06009Au
#define unused_dip_setting RAM16(unused_dip_setting_ADDRESS)
#define version_ADDRESS 0x06009Fu
#define version RAM8(version_ADDRESS)
#define players_knocked_out_ADDRESS 0x0600A0u
#define players_knocked_out RAM8(players_knocked_out_ADDRESS)
#define players_in_play_ADDRESS 0x0600A1u
#define players_in_play RAM8(players_in_play_ADDRESS)
#define players_credited_ADDRESS 0x0600A2u
#define players_credited RAM8(players_credited_ADDRESS)
#define game_on_ADDRESS 0x0600A3u
#define game_on RAM8(game_on_ADDRESS)
#define frame_count_ADDRESS 0x0600A4u
#define frame_count RAM16(frame_count_ADDRESS)
#define players_joining_ADDRESS 0x0600A6u
#define players_joining RAM8(players_joining_ADDRESS)
#define attract_timer_ADDRESS 0x0600A8u
#define attract_timer RAM8(attract_timer_ADDRESS)
#define demo_hold_2_ADDRESS 0x0600A9u
#define demo_hold_2 RAM8(demo_hold_2_ADDRESS)
#define demo_inputs_1_ADDRESS 0x0600AAu
#define demo_inputs_1 RAM32(demo_inputs_1_ADDRESS)
#define demo_inputs_2_ADDRESS 0x0600AEu
#define demo_inputs_2 RAM32(demo_inputs_2_ADDRESS)
#define players_out_of_lives_ADDRESS 0x0600B3u
#define players_out_of_lives RAM8(players_out_of_lives_ADDRESS)
#define demo_ADDRESS 0x0600B6u
#define demo RAM8(demo_ADDRESS)
#define players_with_lives_ADDRESS 0x0600B7u
#define players_with_lives RAM8(players_with_lives_ADDRESS)
#define hide_press_start_ADDRESS 0x0600B8u
#define hide_press_start RAM8(hide_press_start_ADDRESS)
#define unused_dip_number_ADDRESS 0x0600B9u
#define unused_dip_number RAM8(unused_dip_number_ADDRESS)
#define area_cleared_ADDRESS 0x0600BDu
#define area_cleared RAM8(area_cleared_ADDRESS)
#define saved_frame_count_ADDRESS 0x0600BEu
#define saved_frame_count RAM16(saved_frame_count_ADDRESS)
#define demo_frames_ADDRESS 0x0600C0u
#define demo_frames RAM16(demo_frames_ADDRESS)
#define game_scene_timer_ADDRESS 0x0600C2u
#define game_scene_timer RAM8(game_scene_timer_ADDRESS)
#define player_turtles_ADDRESS 0x0600C4u
#define player_turtles(index) RAM8(player_turtles_ADDRESS + (index))
#define unused_layer_a_scroll_x_copy_ADDRESS 0x0600C8u
#define unused_layer_a_scroll_x_copy RAM16(unused_layer_a_scroll_x_copy_ADDRESS)
#define unused_layer_a_scroll_y_copy_ADDRESS 0x0600CAu
#define unused_layer_a_scroll_y_copy RAM16(unused_layer_a_scroll_y_copy_ADDRESS)
#define unused_layer_b_scroll_x_copy_ADDRESS 0x0600CCu
#define unused_layer_b_scroll_x_copy RAM16(unused_layer_b_scroll_x_copy_ADDRESS)
#define unused_layer_b_scroll_y_copy_ADDRESS 0x0600CEu
#define unused_layer_b_scroll_y_copy RAM16(unused_layer_b_scroll_y_copy_ADDRESS)
#define demo_hold_3_ADDRESS 0x0600D0u
#define demo_hold_3 RAM8(demo_hold_3_ADDRESS)
#define demo_hold_4_ADDRESS 0x0600D1u
#define demo_hold_4 RAM8(demo_hold_4_ADDRESS)
#define demo_inputs_3_ADDRESS 0x0600D2u
#define demo_inputs_3 RAM32(demo_inputs_3_ADDRESS)
#define demo_inputs_4_ADDRESS 0x0600D6u
#define demo_inputs_4 RAM32(demo_inputs_4_ADDRESS)
#define unk_060100_ADDRESS 0x060100u
#define unk_060100(index) RAM16(unk_060100_ADDRESS + (index) * 2u)
#define unk_060104_ADDRESS 0x060104u
#define unk_060104 RAM16(unk_060104_ADDRESS)
#define unk_060106_ADDRESS 0x060106u
#define unk_060106(index) RAM8(unk_060106_ADDRESS + (index))
#define unk_060108_ADDRESS 0x060108u
#define unk_060108 RAM8(unk_060108_ADDRESS)
#define unk_06010C_ADDRESS 0x06010Cu
#define unk_06010C RAM16(unk_06010C_ADDRESS)
#define unk_06010E_ADDRESS 0x06010Eu
#define unk_06010E RAM8(unk_06010E_ADDRESS)
#define unk_060110_ADDRESS 0x060110u
#define unk_060110 RAM8(unk_060110_ADDRESS)
#define unk_060114_ADDRESS 0x060114u
#define unk_060114 RAM16(unk_060114_ADDRESS)
#define unk_060116_ADDRESS 0x060116u
#define unk_060116 RAM8(unk_060116_ADDRESS)
#define unk_060118_ADDRESS 0x060118u
#define unk_060118 RAM8(unk_060118_ADDRESS)
#define unk_06011C_ADDRESS 0x06011Cu
#define unk_06011C RAM16(unk_06011C_ADDRESS)
#define unk_06011E_ADDRESS 0x06011Eu
#define unk_06011E RAM8(unk_06011E_ADDRESS)
#define area_ADDRESS 0x060120u
#define area RAM8(area_ADDRESS)
#define stage_ADDRESS 0x060121u
#define stage RAM8(stage_ADDRESS)
#define area_continues_scene_ADDRESS 0x060122u
#define area_continues_scene RAM8(area_continues_scene_ADDRESS)
#define unk_060123_ADDRESS 0x060123u
#define unk_060123 RAM8(unk_060123_ADDRESS)
#define unk_060124_ADDRESS 0x060124u
#define unk_060124 RAM8(unk_060124_ADDRESS)
#define entry_without_blink_ADDRESS 0x060127u
#define entry_without_blink RAM8(entry_without_blink_ADDRESS)
#define profile_character_ADDRESS 0x060128u
#define profile_character RAM8(profile_character_ADDRESS)
#define exit_cutscene_ADDRESS 0x060129u
#define exit_cutscene RAM8(exit_cutscene_ADDRESS)
#define difficulty_ADDRESS 0x060130u
#define difficulty RAM8(difficulty_ADDRESS)
#define prompt_shown_ADDRESS 0x06014Cu
#define prompt_shown(index) RAM8(prompt_shown_ADDRESS + (index))
#define time_without_knockout_ADDRESS 0x060150u
#define time_without_knockout RAM16(time_without_knockout_ADDRESS)
#define sound_stopped_by_coin_ADDRESS 0x060152u
#define sound_stopped_by_coin RAM8(sound_stopped_by_coin_ADDRESS)
#define unk_060302_ADDRESS 0x060302u
#define unk_060302 RAM8(unk_060302_ADDRESS)
#define unk_060303_ADDRESS 0x060303u
#define unk_060303 RAM8(unk_060303_ADDRESS)
#define unk_060304_ADDRESS 0x060304u
#define unk_060304 RAM8(unk_060304_ADDRESS)
#define unk_06030A_ADDRESS 0x06030Au
#define unk_06030A RAM8(unk_06030A_ADDRESS)
#define unk_06030B_ADDRESS 0x06030Bu
#define unk_06030B RAM8(unk_06030B_ADDRESS)
#define unk_06030C_ADDRESS 0x06030Cu
#define unk_06030C RAM8(unk_06030C_ADDRESS)
#define unk_060312_ADDRESS 0x060312u
#define unk_060312 RAM8(unk_060312_ADDRESS)
#define unk_06031A_ADDRESS 0x06031Au
#define unk_06031A RAM8(unk_06031A_ADDRESS)
#define extra_credits_ADDRESS 0x060320u
#define extra_credits RAM8(extra_credits_ADDRESS)
#define new_coin_switches_ADDRESS 0x060325u
#define new_coin_switches RAM8(new_coin_switches_ADDRESS)
#define new_credit_ADDRESS 0x060327u
#define new_credit RAM8(new_credit_ADDRESS)
#define job_queue_ADDRESS 0x060380u
#define job_queue(index) RAM16(job_queue_ADDRESS + (index) * 2u)
#define sound_queue_ADDRESS 0x060400u
#define sound_queue(index) RAM8(sound_queue_ADDRESS + (index))
#define vblank_registers_ADDRESS 0x060440u
#define vblank_registers(index) RAM32(vblank_registers_ADDRESS + (index) * 4u)
#define palette_queue_write_ADDRESS 0x060BF0u
#define palette_queue_write RAM32(palette_queue_write_ADDRESS)
#define palette_queue_read_ADDRESS 0x060BF4u
#define palette_queue_read RAM32(palette_queue_read_ADDRESS)
#define palette_area_banks_ADDRESS 0x060BF8u
#define palette_area_banks RAM8(palette_area_banks_ADDRESS)
#define palette_set_banks_ADDRESS 0x060BF9u
#define palette_set_banks RAM8(palette_set_banks_ADDRESS)
#define palette_black_banks_ADDRESS 0x060BFAu
#define palette_black_banks RAM8(palette_black_banks_ADDRESS)
#define palette_second_half_ADDRESS 0x060BFBu
#define palette_second_half RAM8(palette_second_half_ADDRESS)
#define palette_set_ADDRESS 0x060BFCu
#define palette_set RAM32(palette_set_ADDRESS)
#define marker_times_ADDRESS 0x061100u
#define marker_times(index) RAM8(marker_times_ADDRESS + (index))
#define time_since_balloon_ADDRESS 0x061104u
#define time_since_balloon RAM16(time_since_balloon_ADDRESS)
#define balloons_said_ADDRESS 0x061106u
#define balloons_said RAM8(balloons_said_ADDRESS)
#define diagonal_scroll_ADDRESS 0x061107u
#define diagonal_scroll RAM8S(diagonal_scroll_ADDRESS)
#define intro_over_ADDRESS 0x061108u
#define intro_over RAM8(intro_over_ADDRESS)
#define area_entry_done_ADDRESS 0x061109u
#define area_entry_done RAM8(area_entry_done_ADDRESS)
#define unk_06110A_ADDRESS 0x06110Au
#define unk_06110A RAM16(unk_06110A_ADDRESS)
#define unk_06110C_ADDRESS 0x06110Cu
#define unk_06110C RAM16(unk_06110C_ADDRESS)
#define drill_arrival_time_ADDRESS 0x06110Eu
#define drill_arrival_time RAM8(drill_arrival_time_ADDRESS)
#define shake_step_ADDRESS 0x06110Fu
#define shake_step RAM8(shake_step_ADDRESS)
#define tv_time_ADDRESS 0x061110u
#define tv_time RAM16(tv_time_ADDRESS)
#define bebop_exchange_lines_ADDRESS 0x061112u
#define bebop_exchange_lines RAM8(bebop_exchange_lines_ADDRESS)
#define balloon_on_right_ADDRESS 0x061113u
#define balloon_on_right RAM8(balloon_on_right_ADDRESS)
#define unk_061114_ADDRESS 0x061114u
#define unk_061114 RAM16(unk_061114_ADDRESS)
#define unk_061116_ADDRESS 0x061116u
#define unk_061116 RAM16(unk_061116_ADDRESS)
#define floor_cell_down_ADDRESS 0x061118u
#define floor_cell_down RAM8(floor_cell_down_ADDRESS)
#define difficulty_from_time_ADDRESS 0x06111Eu
#define difficulty_from_time RAM8(difficulty_from_time_ADDRESS)
#define spawn_next_ADDRESS 0x061200u
#define spawn_next RAM32(spawn_next_ADDRESS)
#define draw_first_ADDRESS 0x061204u
#define draw_first RAM16(draw_first_ADDRESS)
#define draw_count_ADDRESS 0x061206u
#define draw_count RAM8(draw_count_ADDRESS)
#define turtles_in_play_ADDRESS 0x061207u
#define turtles_in_play RAM8(turtles_in_play_ADDRESS)
#define least_crowded_slot_ADDRESS 0x061208u
#define least_crowded_slot RAM32(least_crowded_slot_ADDRESS)
#define enemies_on_screen_ADDRESS 0x06120Cu
#define enemies_on_screen RAM8(enemies_on_screen_ADDRESS)
#define enemies_per_turtle_ADDRESS 0x06120Du
#define enemies_per_turtle RAM8(enemies_per_turtle_ADDRESS)
#define random_seed_ADDRESS 0x06120Eu
#define random_seed RAM16(random_seed_ADDRESS)
#define spawn_speeds_ADDRESS 0x061210u
#define spawn_speeds RAM32(spawn_speeds_ADDRESS)
#define spawn_directions_ADDRESS 0x061214u
#define spawn_directions RAM32(spawn_directions_ADDRESS)
#define spawn_x_ADDRESS 0x061218u
#define spawn_x RAM32(spawn_x_ADDRESS)
#define spawn_y_ADDRESS 0x06121Cu
#define spawn_y RAM32(spawn_y_ADDRESS)
#define rocksteady_ADDRESS 0x061220u
#define rocksteady RAM32(rocksteady_ADDRESS)
#define pincer_charge_wait_ADDRESS 0x061224u
#define pincer_charge_wait RAM16(pincer_charge_wait_ADDRESS)
#define nearest_slot_ADDRESS 0x061226u
#define nearest_slot RAM32(nearest_slot_ADDRESS)
#define second_nearest_slot_ADDRESS 0x06122Au
#define second_nearest_slot RAM32(second_nearest_slot_ADDRESS)
#define nearest_turtle_ADDRESS 0x06122Eu
#define nearest_turtle RAM32(nearest_turtle_ADDRESS)
#define second_nearest_turtle_ADDRESS 0x061232u
#define second_nearest_turtle RAM32(second_nearest_turtle_ADDRESS)
#define bosses_left_ADDRESS 0x061236u
#define bosses_left RAM8(bosses_left_ADDRESS)
#define rocksteady_hits_to_strike_back_ADDRESS 0x061237u
#define rocksteady_hits_to_strike_back RAM8(rocksteady_hits_to_strike_back_ADDRESS)
#define rocksteady_last_attack_ADDRESS 0x061238u
#define rocksteady_last_attack RAM16(rocksteady_last_attack_ADDRESS)
#define shredder_beaten_ADDRESS 0x06123Au
#define shredder_beaten RAM8(shredder_beaten_ADDRESS)
#define shredder_firing_ray_ADDRESS 0x06123Bu
#define shredder_firing_ray RAM8(shredder_firing_ray_ADDRESS)
#define shredder_clones_made_ADDRESS 0x06123Cu
#define shredder_clones_made RAM8(shredder_clones_made_ADDRESS)
#define bosses_come_out_ADDRESS 0x06123Du
#define bosses_come_out RAM8(bosses_come_out_ADDRESS)
#define pincer_charge_target_ADDRESS 0x06123Eu
#define pincer_charge_target RAM16(pincer_charge_target_ADDRESS)
#define pincer_charge_ADDRESS 0x061240u
#define pincer_charge RAM8(pincer_charge_ADDRESS)
#define pincer_charge_edges_ADDRESS 0x061241u
#define pincer_charge_edges RAM8(pincer_charge_edges_ADDRESS)
#define pincer_charge_at_edges_ADDRESS 0x061242u
#define pincer_charge_at_edges RAM8(pincer_charge_at_edges_ADDRESS)
#define no_pincer_charge_ADDRESS 0x061243u
#define no_pincer_charge RAM8(no_pincer_charge_ADDRESS)
#define rodney_line_said_ADDRESS 0x061244u
#define rodney_line_said RAM8(rodney_line_said_ADDRESS)
#define pincer_charge_crash_ADDRESS 0x061247u
#define pincer_charge_crash RAM8(pincer_charge_crash_ADDRESS)
#define enemy_floor_cell_place_ADDRESS 0x061248u
#define enemy_floor_cell_place RAM32(enemy_floor_cell_place_ADDRESS)
#define stairs_top_height_ADDRESS 0x06124Cu
#define stairs_top_height RAM8(stairs_top_height_ADDRESS)
#define hydrant_sprays_left_ADDRESS 0x061300u
#define hydrant_sprays_left RAM8(hydrant_sprays_left_ADDRESS)
#define unused_grille_ADDRESS 0x061302u
#define unused_grille RAM32(unused_grille_ADDRESS)
#define boss_target_choices_ADDRESS 0x061306u
#define boss_target_choices(index) RAM8(boss_target_choices_ADDRESS + (index))
#define helicopter_count_ADDRESS 0x06130Au
#define helicopter_count RAM8(helicopter_count_ADDRESS)
#define missile_out_ADDRESS 0x06130Bu
#define missile_out RAM8(missile_out_ADDRESS)
#define hold_spent_missiles_ADDRESS 0x06130Cu
#define hold_spent_missiles RAM8(hold_spent_missiles_ADDRESS)
#define spiked_poles_phase_ADDRESS 0x061310u
#define spiked_poles_phase RAM8(spiked_poles_phase_ADDRESS)
#define flying_drones_released_ADDRESS 0x061311u
#define flying_drones_released RAM8(flying_drones_released_ADDRESS)
#define flying_drone_count_ADDRESS 0x061312u
#define flying_drone_count RAM8(flying_drone_count_ADDRESS)
#define mousers_break_down_ADDRESS 0x061313u
#define mousers_break_down RAM8(mousers_break_down_ADDRESS)
#define krang_curtain_ADDRESS 0x061314u
#define krang_curtain RAM32(krang_curtain_ADDRESS)
#define drone_sound_on_ADDRESS 0x061318u
#define drone_sound_on RAM8(drone_sound_on_ADDRESS)
#define drone_sound_wait_ADDRESS 0x061319u
#define drone_sound_wait RAM8(drone_sound_wait_ADDRESS)
#define krang_lasers_waiting_ADDRESS 0x06131Au
#define krang_lasers_waiting RAM8(krang_lasers_waiting_ADDRESS)
#define krang_fist_flying_ADDRESS 0x06131Bu
#define krang_fist_flying RAM8(krang_fist_flying_ADDRESS)
#define krang_posed_last_ADDRESS 0x06131Cu
#define krang_posed_last RAM8(krang_posed_last_ADDRESS)
#define boss_defeated_ADDRESS 0x06131Du
#define boss_defeated RAM8(boss_defeated_ADDRESS)
#define draw_list_ADDRESS 0x061400u
#define draw_list(index) RAM16(draw_list_ADDRESS + (index) * 2u)
#define floor_map_ADDRESS 0x061800u
#define floor_map(index) RAM8(floor_map_ADDRESS + (index))
#define unk_062000_ADDRESS 0x062000u
#define unk_062000 RAM8(unk_062000_ADDRESS)
#define unk_062001_ADDRESS 0x062001u
#define unk_062001 RAM8(unk_062001_ADDRESS)
#define unk_062008_ADDRESS 0x062008u
#define unk_062008 RAM8(unk_062008_ADDRESS)
#define unk_06200C_ADDRESS 0x06200Cu
#define unk_06200C RAM16(unk_06200C_ADDRESS)
#define unk_06200E_ADDRESS 0x06200Eu
#define unk_06200E RAM16(unk_06200E_ADDRESS)
#define unk_062010_ADDRESS 0x062010u
#define unk_062010 RAM16(unk_062010_ADDRESS)
#define unk_062012_ADDRESS 0x062012u
#define unk_062012 RAM32(unk_062012_ADDRESS)
#define unk_062016_ADDRESS 0x062016u
#define unk_062016 RAM32(unk_062016_ADDRESS)
#define unk_06202C_ADDRESS 0x06202Cu
#define unk_06202C RAM8(unk_06202C_ADDRESS)
#define unk_062042_ADDRESS 0x062042u
#define unk_062042 RAM8(unk_062042_ADDRESS)
#define unk_062050_ADDRESS 0x062050u
#define unk_062050 RAM8(unk_062050_ADDRESS)
#define unk_062051_ADDRESS 0x062051u
#define unk_062051 RAM8(unk_062051_ADDRESS)
#define unk_062058_ADDRESS 0x062058u
#define unk_062058 RAM8(unk_062058_ADDRESS)
#define unk_06205C_ADDRESS 0x06205Cu
#define unk_06205C RAM16(unk_06205C_ADDRESS)
#define unk_06205E_ADDRESS 0x06205Eu
#define unk_06205E RAM16(unk_06205E_ADDRESS)
#define unk_062060_ADDRESS 0x062060u
#define unk_062060 RAM16(unk_062060_ADDRESS)
#define unk_062062_ADDRESS 0x062062u
#define unk_062062 RAM32(unk_062062_ADDRESS)
#define unk_062066_ADDRESS 0x062066u
#define unk_062066 RAM32(unk_062066_ADDRESS)
#define unk_06207C_ADDRESS 0x06207Cu
#define unk_06207C RAM8(unk_06207C_ADDRESS)
#define unk_062092_ADDRESS 0x062092u
#define unk_062092 RAM8(unk_062092_ADDRESS)
#define unk_0620A0_ADDRESS 0x0620A0u
#define unk_0620A0 RAM8(unk_0620A0_ADDRESS)
#define unk_0620A1_ADDRESS 0x0620A1u
#define unk_0620A1 RAM8(unk_0620A1_ADDRESS)
#define unk_0620A8_ADDRESS 0x0620A8u
#define unk_0620A8 RAM8(unk_0620A8_ADDRESS)
#define unk_0620AC_ADDRESS 0x0620ACu
#define unk_0620AC RAM16(unk_0620AC_ADDRESS)
#define unk_0620B2_ADDRESS 0x0620B2u
#define unk_0620B2 RAM32(unk_0620B2_ADDRESS)
#define unk_0620B6_ADDRESS 0x0620B6u
#define unk_0620B6 RAM32(unk_0620B6_ADDRESS)
#define unk_0620CC_ADDRESS 0x0620CCu
#define unk_0620CC RAM8(unk_0620CC_ADDRESS)
#define unk_0620F0_ADDRESS 0x0620F0u
#define unk_0620F0 RAM8(unk_0620F0_ADDRESS)
#define unk_0620F1_ADDRESS 0x0620F1u
#define unk_0620F1 RAM8(unk_0620F1_ADDRESS)
#define unk_0620F8_ADDRESS 0x0620F8u
#define unk_0620F8 RAM8(unk_0620F8_ADDRESS)
#define unk_062102_ADDRESS 0x062102u
#define unk_062102 RAM32(unk_062102_ADDRESS)
#define unk_062106_ADDRESS 0x062106u
#define unk_062106 RAM32(unk_062106_ADDRESS)
#define unk_06211C_ADDRESS 0x06211Cu
#define unk_06211C RAM8(unk_06211C_ADDRESS)
#define unk_0621E0_ADDRESS 0x0621E0u
#define unk_0621E0 RAM16(unk_0621E0_ADDRESS)
#define unk_0621EC_ADDRESS 0x0621ECu
#define unk_0621EC RAM32(unk_0621EC_ADDRESS)
#define unk_062213_ADDRESS 0x062213u
#define unk_062213 RAM8(unk_062213_ADDRESS)
#define unk_062222_ADDRESS 0x062222u
#define unk_062222 RAM8(unk_062222_ADDRESS)
#define unk_062230_ADDRESS 0x062230u
#define unk_062230 RAM16(unk_062230_ADDRESS)
#define unk_06223C_ADDRESS 0x06223Cu
#define unk_06223C RAM32(unk_06223C_ADDRESS)
#define unk_062272_ADDRESS 0x062272u
#define unk_062272 RAM16(unk_062272_ADDRESS)
#define unk_0623C0_ADDRESS 0x0623C0u
#define unk_0623C0 RAM8(unk_0623C0_ADDRESS)
#define unk_0623CC_ADDRESS 0x0623CCu
#define unk_0623CC RAM16(unk_0623CC_ADDRESS)
#define unk_0623CE_ADDRESS 0x0623CEu
#define unk_0623CE RAM16(unk_0623CE_ADDRESS)
#define unk_0623DA_ADDRESS 0x0623DAu
#define unk_0623DA RAM16(unk_0623DA_ADDRESS)
#define unk_0623DC_ADDRESS 0x0623DCu
#define unk_0623DC RAM16(unk_0623DC_ADDRESS)
#define unk_0623E0_ADDRESS 0x0623E0u
#define unk_0623E0 RAM16(unk_0623E0_ADDRESS)
#define unk_0623E2_ADDRESS 0x0623E2u
#define unk_0623E2 RAM16(unk_0623E2_ADDRESS)
#define unk_062402_ADDRESS 0x062402u
#define unk_062402 RAM8(unk_062402_ADDRESS)
#define unk_062410_ADDRESS 0x062410u
#define unk_062410 RAM8(unk_062410_ADDRESS)
#define unk_06241F_ADDRESS 0x06241Fu
#define unk_06241F RAM8(unk_06241F_ADDRESS)
#define unk_062452_ADDRESS 0x062452u
#define unk_062452 RAM8(unk_062452_ADDRESS)
#define unk_062460_ADDRESS 0x062460u
#define unk_062460 RAM8(unk_062460_ADDRESS)
#define unk_06246E_ADDRESS 0x06246Eu
#define unk_06246E RAM16(unk_06246E_ADDRESS)
#define unk_0624B0_ADDRESS 0x0624B0u
#define unk_0624B0 RAM8(unk_0624B0_ADDRESS)
#define unk_0624BE_ADDRESS 0x0624BEu
#define unk_0624BE RAM16(unk_0624BE_ADDRESS)
#define unk_062C80_ADDRESS 0x062C80u
#define unk_062C80 RAM16(unk_062C80_ADDRESS)
#define unk_062C8C_ADDRESS 0x062C8Cu
#define unk_062C8C RAM16(unk_062C8C_ADDRESS)
#define unk_062C8E_ADDRESS 0x062C8Eu
#define unk_062C8E RAM16(unk_062C8E_ADDRESS)
#define unk_062C90_ADDRESS 0x062C90u
#define unk_062C90 RAM16(unk_062C90_ADDRESS)
#define unk_062C92_ADDRESS 0x062C92u
#define unk_062C92 RAM32(unk_062C92_ADDRESS)
#define unk_062C96_ADDRESS 0x062C96u
#define unk_062C96 RAM32(unk_062C96_ADDRESS)
#define unk_062C9A_ADDRESS 0x062C9Au
#define unk_062C9A RAM16(unk_062C9A_ADDRESS)
#define unk_062CA0_ADDRESS 0x062CA0u
#define unk_062CA0 RAM8(unk_062CA0_ADDRESS)
#define unk_062CC2_ADDRESS 0x062CC2u
#define unk_062CC2 RAM8(unk_062CC2_ADDRESS)
#define unk_062CD0_ADDRESS 0x062CD0u
#define unk_062CD0 RAM16(unk_062CD0_ADDRESS)
#define unk_062CDC_ADDRESS 0x062CDCu
#define unk_062CDC RAM16(unk_062CDC_ADDRESS)
#define unk_062CDE_ADDRESS 0x062CDEu
#define unk_062CDE RAM16(unk_062CDE_ADDRESS)
#define unk_062CE0_ADDRESS 0x062CE0u
#define unk_062CE0 RAM16(unk_062CE0_ADDRESS)
#define unk_062CE2_ADDRESS 0x062CE2u
#define unk_062CE2 RAM32(unk_062CE2_ADDRESS)
#define unk_062CE6_ADDRESS 0x062CE6u
#define unk_062CE6 RAM32(unk_062CE6_ADDRESS)
#define unk_062D12_ADDRESS 0x062D12u
#define unk_062D12 RAM8(unk_062D12_ADDRESS)
#define unk_062DC0_ADDRESS 0x062DC0u
#define unk_062DC0 RAM8(unk_062DC0_ADDRESS)
#define unk_062DCC_ADDRESS 0x062DCCu
#define unk_062DCC RAM16(unk_062DCC_ADDRESS)
#define unk_062DCE_ADDRESS 0x062DCEu
#define unk_062DCE RAM16(unk_062DCE_ADDRESS)
#define unk_062DD0_ADDRESS 0x062DD0u
#define unk_062DD0 RAM16(unk_062DD0_ADDRESS)
#define unk_062DD2_ADDRESS 0x062DD2u
#define unk_062DD2 RAM32(unk_062DD2_ADDRESS)
#define unk_062DD6_ADDRESS 0x062DD6u
#define unk_062DD6 RAM32(unk_062DD6_ADDRESS)
#define unk_062E02_ADDRESS 0x062E02u
#define unk_062E02 RAM16(unk_062E02_ADDRESS)
#define unk_062E10_ADDRESS 0x062E10u
#define unk_062E10 RAM8(unk_062E10_ADDRESS)
#define unk_062E1C_ADDRESS 0x062E1Cu
#define unk_062E1C RAM16(unk_062E1C_ADDRESS)
#define unk_062E1E_ADDRESS 0x062E1Eu
#define unk_062E1E RAM16(unk_062E1E_ADDRESS)
#define unk_062E20_ADDRESS 0x062E20u
#define unk_062E20 RAM16(unk_062E20_ADDRESS)
#define unk_062E22_ADDRESS 0x062E22u
#define unk_062E22 RAM32(unk_062E22_ADDRESS)
#define unk_062E26_ADDRESS 0x062E26u
#define unk_062E26 RAM32(unk_062E26_ADDRESS)
#define unk_062E52_ADDRESS 0x062E52u
#define unk_062E52 RAM8(unk_062E52_ADDRESS)
#define unk_062E60_ADDRESS 0x062E60u
#define unk_062E60 RAM8(unk_062E60_ADDRESS)
#define unk_062E6C_ADDRESS 0x062E6Cu
#define unk_062E6C RAM16(unk_062E6C_ADDRESS)
#define unk_062E6E_ADDRESS 0x062E6Eu
#define unk_062E6E RAM16(unk_062E6E_ADDRESS)
#define unk_062E72_ADDRESS 0x062E72u
#define unk_062E72 RAM32(unk_062E72_ADDRESS)
#define unk_062E76_ADDRESS 0x062E76u
#define unk_062E76 RAM32(unk_062E76_ADDRESS)
#define unk_062EA2_ADDRESS 0x062EA2u
#define unk_062EA2 RAM8(unk_062EA2_ADDRESS)
#define unk_062EB0_ADDRESS 0x062EB0u
#define unk_062EB0 RAM8(unk_062EB0_ADDRESS)
#define unk_062EBC_ADDRESS 0x062EBCu
#define unk_062EBC RAM16(unk_062EBC_ADDRESS)
#define unk_062EBE_ADDRESS 0x062EBEu
#define unk_062EBE RAM16(unk_062EBE_ADDRESS)
#define unk_062EC2_ADDRESS 0x062EC2u
#define unk_062EC2 RAM32(unk_062EC2_ADDRESS)
#define unk_062EC6_ADDRESS 0x062EC6u
#define unk_062EC6 RAM32(unk_062EC6_ADDRESS)
#define unk_062ECA_ADDRESS 0x062ECAu
#define unk_062ECA RAM8(unk_062ECA_ADDRESS)
#define unk_062EF2_ADDRESS 0x062EF2u
#define unk_062EF2 RAM16(unk_062EF2_ADDRESS)
#define unk_062F00_ADDRESS 0x062F00u
#define unk_062F00 RAM8(unk_062F00_ADDRESS)
#define unk_062F0C_ADDRESS 0x062F0Cu
#define unk_062F0C RAM16(unk_062F0C_ADDRESS)
#define unk_062F0E_ADDRESS 0x062F0Eu
#define unk_062F0E RAM16(unk_062F0E_ADDRESS)
#define unk_062F10_ADDRESS 0x062F10u
#define unk_062F10 RAM16(unk_062F10_ADDRESS)
#define unk_062F12_ADDRESS 0x062F12u
#define unk_062F12 RAM32(unk_062F12_ADDRESS)
#define unk_062F16_ADDRESS 0x062F16u
#define unk_062F16 RAM32(unk_062F16_ADDRESS)
#define unk_062F32_ADDRESS 0x062F32u
#define unk_062F32 RAM8(unk_062F32_ADDRESS)
#define unk_062F33_ADDRESS 0x062F33u
#define unk_062F33 RAM8(unk_062F33_ADDRESS)
#define unk_062F42_ADDRESS 0x062F42u
#define unk_062F42 RAM16(unk_062F42_ADDRESS)
#define unk_062F50_ADDRESS 0x062F50u
#define unk_062F50 RAM8(unk_062F50_ADDRESS)
#define unk_062FA0_ADDRESS 0x062FA0u
#define unk_062FA0 RAM32(unk_062FA0_ADDRESS)
#define unk_062FA4_ADDRESS 0x062FA4u
#define unk_062FA4 RAM32(unk_062FA4_ADDRESS)
#define unk_062FA8_ADDRESS 0x062FA8u
#define unk_062FA8 RAM32(unk_062FA8_ADDRESS)
#define unk_062FAC_ADDRESS 0x062FACu
#define unk_062FAC RAM32(unk_062FAC_ADDRESS)
#define unk_062FB0_ADDRESS 0x062FB0u
#define unk_062FB0 RAM32(unk_062FB0_ADDRESS)
#define unk_062FB4_ADDRESS 0x062FB4u
#define unk_062FB4 RAM32(unk_062FB4_ADDRESS)
#define unk_062FB8_ADDRESS 0x062FB8u
#define unk_062FB8 RAM32(unk_062FB8_ADDRESS)
#define unk_062FBC_ADDRESS 0x062FBCu
#define unk_062FBC RAM32(unk_062FBC_ADDRESS)
#define unk_062FC0_ADDRESS 0x062FC0u
#define unk_062FC0 RAM32(unk_062FC0_ADDRESS)
#define unk_062FC4_ADDRESS 0x062FC4u
#define unk_062FC4 RAM32(unk_062FC4_ADDRESS)
#define unk_062FC8_ADDRESS 0x062FC8u
#define unk_062FC8 RAM32(unk_062FC8_ADDRESS)
#define unk_062FCC_ADDRESS 0x062FCCu
#define unk_062FCC RAM32(unk_062FCC_ADDRESS)
#define unk_062FD0_ADDRESS 0x062FD0u
#define unk_062FD0 RAM32(unk_062FD0_ADDRESS)
#define unk_062FD4_ADDRESS 0x062FD4u
#define unk_062FD4 RAM32(unk_062FD4_ADDRESS)
#define unk_062FD8_ADDRESS 0x062FD8u
#define unk_062FD8 RAM32(unk_062FD8_ADDRESS)
#define unk_062FDC_ADDRESS 0x062FDCu
#define unk_062FDC RAM32(unk_062FDC_ADDRESS)
#define unk_063300_ADDRESS 0x063300u
#define unk_063300 RAM32(unk_063300_ADDRESS)
#define unk_063304_ADDRESS 0x063304u
#define unk_063304 RAM32(unk_063304_ADDRESS)
#define unk_063308_ADDRESS 0x063308u
#define unk_063308 RAM16(unk_063308_ADDRESS)
#define unk_06330A_ADDRESS 0x06330Au
#define unk_06330A RAM16(unk_06330A_ADDRESS)
#define unk_06330C_ADDRESS 0x06330Cu
#define unk_06330C RAM16(unk_06330C_ADDRESS)
#define unk_06330E_ADDRESS 0x06330Eu
#define unk_06330E RAM16(unk_06330E_ADDRESS)
#define unk_063310_ADDRESS 0x063310u
#define unk_063310 RAM16(unk_063310_ADDRESS)
#define unk_063312_ADDRESS 0x063312u
#define unk_063312 RAM32(unk_063312_ADDRESS)
#define unk_063316_ADDRESS 0x063316u
#define unk_063316 RAM32(unk_063316_ADDRESS)
#define unk_06331A_ADDRESS 0x06331Au
#define unk_06331A RAM8(unk_06331A_ADDRESS)
#define unk_06331B_ADDRESS 0x06331Bu
#define unk_06331B RAM8(unk_06331B_ADDRESS)
#define unk_06331C_ADDRESS 0x06331Cu
#define unk_06331C RAM32(unk_06331C_ADDRESS)
#define unk_063320_ADDRESS 0x063320u
#define unk_063320 RAM32(unk_063320_ADDRESS)
#define unk_063324_ADDRESS 0x063324u
#define unk_063324 RAM32(unk_063324_ADDRESS)
#define unk_063328_ADDRESS 0x063328u
#define unk_063328 RAM32(unk_063328_ADDRESS)
#define unk_06332C_ADDRESS 0x06332Cu
#define unk_06332C RAM32(unk_06332C_ADDRESS)
#define unk_063330_ADDRESS 0x063330u
#define unk_063330 RAM32(unk_063330_ADDRESS)
#define unk_063334_ADDRESS 0x063334u
#define unk_063334 RAM8(unk_063334_ADDRESS)
#define unk_063335_ADDRESS 0x063335u
#define unk_063335 RAM8(unk_063335_ADDRESS)
#define unk_063340_ADDRESS 0x063340u
#define unk_063340 RAM32(unk_063340_ADDRESS)
#define unk_063344_ADDRESS 0x063344u
#define unk_063344 RAM32(unk_063344_ADDRESS)
#define unk_063348_ADDRESS 0x063348u
#define unk_063348 RAM16(unk_063348_ADDRESS)
#define unk_06334A_ADDRESS 0x06334Au
#define unk_06334A RAM16(unk_06334A_ADDRESS)
#define unk_06334C_ADDRESS 0x06334Cu
#define unk_06334C RAM16(unk_06334C_ADDRESS)
#define unk_06334E_ADDRESS 0x06334Eu
#define unk_06334E RAM16(unk_06334E_ADDRESS)
#define unk_063350_ADDRESS 0x063350u
#define unk_063350 RAM16(unk_063350_ADDRESS)
#define unk_063352_ADDRESS 0x063352u
#define unk_063352 RAM32(unk_063352_ADDRESS)
#define unk_063356_ADDRESS 0x063356u
#define unk_063356 RAM32(unk_063356_ADDRESS)
#define unk_06335A_ADDRESS 0x06335Au
#define unk_06335A RAM8(unk_06335A_ADDRESS)
#define unk_06335B_ADDRESS 0x06335Bu
#define unk_06335B RAM8(unk_06335B_ADDRESS)
#define unk_06335C_ADDRESS 0x06335Cu
#define unk_06335C RAM32(unk_06335C_ADDRESS)
#define unk_063360_ADDRESS 0x063360u
#define unk_063360 RAM32(unk_063360_ADDRESS)
#define unk_063364_ADDRESS 0x063364u
#define unk_063364 RAM32(unk_063364_ADDRESS)
#define unk_063368_ADDRESS 0x063368u
#define unk_063368 RAM32(unk_063368_ADDRESS)
#define unk_06336C_ADDRESS 0x06336Cu
#define unk_06336C RAM32(unk_06336C_ADDRESS)
#define unk_063370_ADDRESS 0x063370u
#define unk_063370 RAM32(unk_063370_ADDRESS)
#define unk_063374_ADDRESS 0x063374u
#define unk_063374 RAM8(unk_063374_ADDRESS)
#define unk_063375_ADDRESS 0x063375u
#define unk_063375 RAM8(unk_063375_ADDRESS)
#define unk_063380_ADDRESS 0x063380u
#define unk_063380 RAM32(unk_063380_ADDRESS)
#define unk_063384_ADDRESS 0x063384u
#define unk_063384 RAM32(unk_063384_ADDRESS)
#define unk_063388_ADDRESS 0x063388u
#define unk_063388 RAM16(unk_063388_ADDRESS)
#define unk_06338A_ADDRESS 0x06338Au
#define unk_06338A RAM16(unk_06338A_ADDRESS)
#define unk_06338C_ADDRESS 0x06338Cu
#define unk_06338C RAM16(unk_06338C_ADDRESS)
#define unk_06338E_ADDRESS 0x06338Eu
#define unk_06338E RAM16(unk_06338E_ADDRESS)
#define unk_063390_ADDRESS 0x063390u
#define unk_063390 RAM16(unk_063390_ADDRESS)
#define unk_063392_ADDRESS 0x063392u
#define unk_063392 RAM32(unk_063392_ADDRESS)
#define unk_063396_ADDRESS 0x063396u
#define unk_063396 RAM32(unk_063396_ADDRESS)
#define unk_06339A_ADDRESS 0x06339Au
#define unk_06339A RAM8(unk_06339A_ADDRESS)
#define unk_06339B_ADDRESS 0x06339Bu
#define unk_06339B RAM8(unk_06339B_ADDRESS)
#define unk_06339C_ADDRESS 0x06339Cu
#define unk_06339C RAM32(unk_06339C_ADDRESS)
#define unk_0633A0_ADDRESS 0x0633A0u
#define unk_0633A0 RAM32(unk_0633A0_ADDRESS)
#define unk_0633A4_ADDRESS 0x0633A4u
#define unk_0633A4 RAM32(unk_0633A4_ADDRESS)
#define unk_0633A8_ADDRESS 0x0633A8u
#define unk_0633A8 RAM32(unk_0633A8_ADDRESS)
#define unk_0633AC_ADDRESS 0x0633ACu
#define unk_0633AC RAM32(unk_0633AC_ADDRESS)
#define unk_0633B0_ADDRESS 0x0633B0u
#define unk_0633B0 RAM32(unk_0633B0_ADDRESS)
#define unk_0633B4_ADDRESS 0x0633B4u
#define unk_0633B4 RAM8(unk_0633B4_ADDRESS)
#define unk_0633B5_ADDRESS 0x0633B5u
#define unk_0633B5 RAM8(unk_0633B5_ADDRESS)
#define scroll_segment_ADDRESS 0x0633C0u
#define scroll_segment RAM16(scroll_segment_ADDRESS)
#define scroll_held_ADDRESS 0x0633C2u
#define scroll_held RAM32(scroll_held_ADDRESS)
#define scroll_held_left_ADDRESS 0x0633C2u
#define scroll_held_left RAM8(scroll_held_left_ADDRESS)
#define scroll_held_right_ADDRESS 0x0633C3u
#define scroll_held_right RAM8(scroll_held_right_ADDRESS)
#define scroll_held_up_ADDRESS 0x0633C4u
#define scroll_held_up RAM8(scroll_held_up_ADDRESS)
#define scroll_held_down_ADDRESS 0x0633C5u
#define scroll_held_down RAM8(scroll_held_down_ADDRESS)
#define apartment_fire_spot_ADDRESS 0x0633C6u
#define apartment_fire_spot RAM8(apartment_fire_spot_ADDRESS)
#define apartment_fire_frame_ADDRESS 0x0633C7u
#define apartment_fire_frame RAM8(apartment_fire_frame_ADDRESS)
#define area_beaten_ADDRESS 0x0633C8u
#define area_beaten RAM8(area_beaten_ADDRESS)
#define scroll_mode_ADDRESS 0x0633C9u
#define scroll_mode RAM8S(scroll_mode_ADDRESS)
#define turtles_busy_ADDRESS 0x0633CAu
#define turtles_busy RAM8(turtles_busy_ADDRESS)
#define turtles_on_the_way_ADDRESS 0x0633CBu
#define turtles_on_the_way RAM8(turtles_on_the_way_ADDRESS)
#define working_layer_tiles_ADDRESS 0x0633CCu
#define working_layer_tiles RAM32(working_layer_tiles_ADDRESS)
#define layer_loops_ADDRESS 0x0633D0u
#define layer_loops RAM8S(layer_loops_ADDRESS)
#define layers_step_ADDRESS 0x0633D2u
#define layers_step RAM8(layers_step_ADDRESS)
#define floor_cell_ADDRESS 0x0633D3u
#define floor_cell RAM8(floor_cell_ADDRESS)
#define floor_cell_up_ADDRESS 0x0633D4u
#define floor_cell_up RAM8(floor_cell_up_ADDRESS)
#define floor_cell_right_ADDRESS 0x0633D5u
#define floor_cell_right RAM8(floor_cell_right_ADDRESS)
#define floor_cell_left_ADDRESS 0x0633D6u
#define floor_cell_left RAM8(floor_cell_left_ADDRESS)
#define floor_cell_up_right_ADDRESS 0x0633D7u
#define floor_cell_up_right RAM8(floor_cell_up_right_ADDRESS)
#define floor_cell_up_left_ADDRESS 0x0633D8u
#define floor_cell_up_left RAM8(floor_cell_up_left_ADDRESS)
#define height_cell_up_ADDRESS 0x0633D9u
#define height_cell_up RAM8(height_cell_up_ADDRESS)
#define height_cell_right_ADDRESS 0x0633DAu
#define height_cell_right RAM8(height_cell_right_ADDRESS)
#define height_cell_left_ADDRESS 0x0633DBu
#define height_cell_left RAM8(height_cell_left_ADDRESS)
#define height_cell_up_right_ADDRESS 0x0633DCu
#define height_cell_up_right RAM8(height_cell_up_right_ADDRESS)
#define height_cell_up_left_ADDRESS 0x0633DDu
#define height_cell_up_left RAM8(height_cell_up_left_ADDRESS)
#define saved_turtle_ADDRESS 0x0633DEu
#define saved_turtle RAM32(saved_turtle_ADDRESS)
#define cutscene_wait_ADDRESS 0x0633DEu
#define cutscene_wait RAM8(cutscene_wait_ADDRESS)
#define cutscene_time_ADDRESS 0x0633DEu
#define cutscene_time RAM16(cutscene_time_ADDRESS)
#define cutscene_count_ADDRESS 0x0633DFu
#define cutscene_count RAM8(cutscene_count_ADDRESS)
#define cutscene_counter_ADDRESS 0x0633E2u
#define cutscene_counter RAM8(cutscene_counter_ADDRESS)
#define hug_turtle_colours_ADDRESS 0x0633E6u
#define hug_turtle_colours(index) RAM8(hug_turtle_colours_ADDRESS + (index))
#define cutscene_step_ADDRESS 0x0633EAu
#define cutscene_step RAM8(cutscene_step_ADDRESS)
#define turtles_not_waiting_ADDRESS 0x0633EBu
#define turtles_not_waiting RAM8(turtles_not_waiting_ADDRESS)
#define last_segment_ADDRESS 0x0633ECu
#define last_segment RAM8(last_segment_ADDRESS)
#define building_clear_wait_ADDRESS 0x0633EDu
#define building_clear_wait RAM8(building_clear_wait_ADDRESS)
#define unk_0633F0_ADDRESS 0x0633F0u
#define unk_0633F0 RAM8(unk_0633F0_ADDRESS)
#define fire_last_frame_ADDRESS 0x0633F1u
#define fire_last_frame RAM8(fire_last_frame_ADDRESS)
#define building_fire_spot_ADDRESS 0x0633F2u
#define building_fire_spot RAM8(building_fire_spot_ADDRESS)
#define building_fire_frame_ADDRESS 0x0633F3u
#define building_fire_frame RAM8(building_fire_frame_ADDRESS)
#define height_cell_ADDRESS 0x0633F4u
#define height_cell RAM8(height_cell_ADDRESS)
#define building_scroll_hold_ADDRESS 0x0633F5u
#define building_scroll_hold RAM8(building_scroll_hold_ADDRESS)
#define hurry_time_ADDRESS 0x0633F6u
#define hurry_time RAM16(hurry_time_ADDRESS)
#define balloon_place_ADDRESS 0x0633F8u
#define balloon_place RAM32(balloon_place_ADDRESS)
#define balloon_time_ADDRESS 0x0633FCu
#define balloon_time RAM8(balloon_time_ADDRESS)
#define floor_end_walled_ADDRESS 0x0633FDu
#define floor_end_walled RAM8(floor_end_walled_ADDRESS)
#define drill_arrival_ADDRESS 0x0633FEu
#define drill_arrival RAM8S(drill_arrival_ADDRESS)
#define drill_arrival_step_ADDRESS 0x0633FFu
#define drill_arrival_step RAM8(drill_arrival_step_ADDRESS)
#define palette_editor_numbers_ADDRESS 0x063400u
#define palette_editor_numbers(index) RAM8(palette_editor_numbers_ADDRESS + (index))
#define palette_editor_pick_ADDRESS 0x063404u
#define palette_editor_pick RAM8(palette_editor_pick_ADDRESS)
#define palette_editor_last_pick_ADDRESS 0x063405u
#define palette_editor_last_pick RAM8(palette_editor_last_pick_ADDRESS)
#define palette_editor_part_ADDRESS 0x063407u
#define palette_editor_part RAM8(palette_editor_part_ADDRESS)
#define palette_editor_step_ADDRESS 0x063408u
#define palette_editor_step RAM8(palette_editor_step_ADDRESS)
#define fade_state_ADDRESS 0x063410u
#define fade_state RAM32(fade_state_ADDRESS)
#define fading_ADDRESS 0x063410u
#define fading RAM8(fading_ADDRESS)
#define fade_pass_step_ADDRESS 0x063411u
#define fade_pass_step RAM8(fade_pass_step_ADDRESS)
#define fade_part_ADDRESS 0x063412u
#define fade_part RAM8(fade_part_ADDRESS)
#define fade_lists_left_ADDRESS 0x063413u
#define fade_lists_left RAM8(fade_lists_left_ADDRESS)
#define fade_target_ADDRESS 0x063414u
#define fade_target RAM32(fade_target_ADDRESS)
#define fade_part_mask_ADDRESS 0x063418u
#define fade_part_mask RAM8(fade_part_mask_ADDRESS)
#define fade_rate_ADDRESS 0x063419u
#define fade_rate RAM8(fade_rate_ADDRESS)
#define fade_buffer_place_ADDRESS 0x06341Au
#define fade_buffer_place RAM32(fade_buffer_place_ADDRESS)
#define typed_text_place_ADDRESS 0x063420u
#define typed_text_place RAM32(typed_text_place_ADDRESS)
#define typed_text_ADDRESS 0x063424u
#define typed_text RAM32(typed_text_ADDRESS)
#define typed_text_wait_ADDRESS 0x063428u
#define typed_text_wait RAM8(typed_text_wait_ADDRESS)
#define typed_text_delay_ADDRESS 0x063429u
#define typed_text_delay RAM8(typed_text_delay_ADDRESS)
#define unused_typed_text_flag_ADDRESS 0x06342Au
#define unused_typed_text_flag RAM8(unused_typed_text_flag_ADDRESS)
#define typed_text_colour_ADDRESS 0x06342Bu
#define typed_text_colour RAM8(typed_text_colour_ADDRESS)
#define staff_roll_credit_ADDRESS 0x06342Eu
#define staff_roll_credit RAM8(staff_roll_credit_ADDRESS)
#define typed_passes_left_ADDRESS 0x06342Fu
#define typed_passes_left RAM8(typed_passes_left_ADDRESS)
#define unk_063434_ADDRESS 0x063434u
#define unk_063434 RAM32(unk_063434_ADDRESS)
#define technodrome_explosions_ADDRESS 0x063480u
#define technodrome_explosions RAM8(technodrome_explosions_ADDRESS)
#define drill_rumbling_ADDRESS 0x063488u
#define drill_rumbling RAM8(drill_rumbling_ADDRESS)
#define box_place_ADDRESS 0x063490u
#define box_place RAM32(box_place_ADDRESS)
#define box_width_ADDRESS 0x063494u
#define box_width RAM8(box_width_ADDRESS)
#define box_height_ADDRESS 0x063495u
#define box_height RAM8(box_height_ADDRESS)
#define box_tile_ADDRESS 0x063496u
#define box_tile RAM8(box_tile_ADDRESS)
#define box_frames_left_ADDRESS 0x063497u
#define box_frames_left RAM8(box_frames_left_ADDRESS)
#define name_entered_ADDRESS 0x0634A0u
#define name_entered RAM8(name_entered_ADDRESS)
#define ranking_scores_ADDRESS 0x063500u
#define ranking_scores(index) RAM16(ranking_scores_ADDRESS + (index) * 2u)
#define mask_rom_bank_ADDRESS 0x06350Eu
#define mask_rom_bank RAM8(mask_rom_bank_ADDRESS)
#define mask_rom_bits_ADDRESS 0x06350Fu
#define mask_rom_bits RAM8(mask_rom_bits_ADDRESS)
#define mask_rom_part_sums_ADDRESS 0x063510u
#define mask_rom_part_sums(index) RAM16(mask_rom_part_sums_ADDRESS + (index) * 2u)
#define mask_rom_first_bank_ADDRESS 0x063518u
#define mask_rom_first_bank RAM8(mask_rom_first_bank_ADDRESS)
#define mask_rom_last_bank_ADDRESS 0x063519u
#define mask_rom_last_bank RAM8(mask_rom_last_bank_ADDRESS)
#define ranking_new_score_ADDRESS 0x0635C6u
#define ranking_new_score RAM16(ranking_new_score_ADDRESS)
#define ranking_initials_ADDRESS 0x0635C8u
#define ranking_initials(index) RAM8(ranking_initials_ADDRESS + (index))
#define ranking_new_initials_ADDRESS 0x0635F0u
#define ranking_new_initials RAM32(ranking_new_initials_ADDRESS)
#define ranking_places_ADDRESS 0x0635F4u
#define ranking_places(index) RAM8(ranking_places_ADDRESS + (index))
#define ranking_time_ADDRESS 0x0635F8u
#define ranking_time RAM16(ranking_time_ADDRESS)
#define turtles_in_black_ADDRESS 0x0635F8u
#define turtles_in_black RAM8(turtles_in_black_ADDRESS)
#define initials_entered_ADDRESS 0x0635FAu
#define initials_entered(index) RAM8(initials_entered_ADDRESS + (index))
#define players_entering_names_ADDRESS 0x0635FEu
#define players_entering_names RAM8(players_entering_names_ADDRESS)
#define initials_buttons_held_ADDRESS 0x0635FFu
#define initials_buttons_held RAM8(initials_buttons_held_ADDRESS)

/* the program's data the code reads by name, which the game loads from its assets */
#define indexed_table_of_32_bit_values_0013DE_ADDRESS 0x0013DEu
extern const void *indexed_table_of_32_bit_values_0013DE_data;
#define indexed_table_of_32_bit_values_0013DE ((const uint32_t *)indexed_table_of_32_bit_values_0013DE_data)
#define rom_001426_ADDRESS 0x001426u
extern const void *rom_001426_data;
#define rom_001426 ((const uint8_t *)rom_001426_data)
#define rom_001452_ADDRESS 0x001452u
extern const void *rom_001452_data;
#define rom_001452 ((const uint8_t *)rom_001452_data)
#define rom_001453_ADDRESS 0x001453u
extern const void *rom_001453_data;
#define rom_001453 ((const uint8_t *)rom_001453_data)
#define rom_001472_ADDRESS 0x001472u
extern const void *rom_001472_data;
#define rom_001472 ((const uint8_t *)rom_001472_data)
#define rom_001473_ADDRESS 0x001473u
extern const void *rom_001473_data;
#define rom_001473 ((const uint8_t *)rom_001473_data)
#define indexed_table_of_32_bit_values_0015AC_ADDRESS 0x0015ACu
extern const void *indexed_table_of_32_bit_values_0015AC_data;
#define indexed_table_of_32_bit_values_0015AC ((const uint32_t *)indexed_table_of_32_bit_values_0015AC_data)
#define text_colours_ADDRESS 0x001F1Au
extern const void *text_colours_data;
#define text_colours ((const uint8_t *)text_colours_data)
#define rom_001F1B_ADDRESS 0x001F1Bu
extern const void *rom_001F1B_data;
#define rom_001F1B ((const uint8_t *)rom_001F1B_data)
#define indexed_table_of_32_bit_values_002678_ADDRESS 0x002678u
extern const void *indexed_table_of_32_bit_values_002678_data;
#define indexed_table_of_32_bit_values_002678 ((const uint32_t *)indexed_table_of_32_bit_values_002678_data)
#define text_layer_places_ADDRESS 0x0027A2u
extern const void *text_layer_places_data;
#define text_layer_places ((const uint32_t *)text_layer_places_data)
#define big_font_place_ADDRESS 0x002802u
extern const void *big_font_place_data;
#define big_font_place (*(const uint32_t *)big_font_place_data)
#define indexed_table_of_8_bit_values_002884_ADDRESS 0x002884u
extern const void *indexed_table_of_8_bit_values_002884_data;
#define indexed_table_of_8_bit_values_002884 ((const uint8_t *)indexed_table_of_8_bit_values_002884_data)
#define rom_002885_ADDRESS 0x002885u
extern const void *rom_002885_data;
#define rom_002885 ((const uint8_t *)rom_002885_data)
#define indexed_table_of_32_bit_values_0031F2_ADDRESS 0x0031F2u
extern const void *indexed_table_of_32_bit_values_0031F2_data;
#define indexed_table_of_32_bit_values_0031F2 ((const uint32_t *)indexed_table_of_32_bit_values_0031F2_data)
#define rom_00332A_ADDRESS 0x00332Au
extern const void *rom_00332A_data;
#define rom_00332A ((const uint32_t *)rom_00332A_data)
#define rom_0033A2_ADDRESS 0x0033A2u
extern const void *rom_0033A2_data;
#define rom_0033A2 ((const uint8_t *)rom_0033A2_data)
#define rom_0033A3_ADDRESS 0x0033A3u
extern const void *rom_0033A3_data;
#define rom_0033A3 ((const uint8_t *)rom_0033A3_data)
#define rom_0033B6_ADDRESS 0x0033B6u
extern const void *rom_0033B6_data;
#define rom_0033B6 ((const uint8_t *)rom_0033B6_data)
#define rom_0033B7_ADDRESS 0x0033B7u
extern const void *rom_0033B7_data;
#define rom_0033B7 ((const uint8_t *)rom_0033B7_data)
#define rom_003402_ADDRESS 0x003402u
extern const void *rom_003402_data;
#define rom_003402 ((const uint32_t *)rom_003402_data)
#define positioned_texts_ADDRESS 0x0035ACu
extern const void *positioned_texts_data;
#define positioned_texts ((const uint32_t *)positioned_texts_data)
#define indexed_table_of_32_bit_values_003E60_ADDRESS 0x003E60u
extern const void *indexed_table_of_32_bit_values_003E60_data;
#define indexed_table_of_32_bit_values_003E60 ((const uint32_t *)indexed_table_of_32_bit_values_003E60_data)
#define indexed_table_of_32_bit_values_003F8E_ADDRESS 0x003F8Eu
extern const void *indexed_table_of_32_bit_values_003F8E_data;
#define indexed_table_of_32_bit_values_003F8E ((const uint32_t *)indexed_table_of_32_bit_values_003F8E_data)
#define indexed_table_of_32_bit_values_004100_ADDRESS 0x004100u
extern const void *indexed_table_of_32_bit_values_004100_data;
#define indexed_table_of_32_bit_values_004100 ((const uint32_t *)indexed_table_of_32_bit_values_004100_data)
#define indexed_table_of_32_bit_values_00413A_ADDRESS 0x00413Au
extern const void *indexed_table_of_32_bit_values_00413A_data;
#define indexed_table_of_32_bit_values_00413A ((const uint32_t *)indexed_table_of_32_bit_values_00413A_data)
#define demo_settings_ADDRESS 0x004E88u
extern const void *demo_settings_data;
#define demo_settings ((const uint8_t *)demo_settings_data)
#define rom_004E89_ADDRESS 0x004E89u
extern const void *rom_004E89_data;
#define rom_004E89 ((const uint8_t *)rom_004E89_data)
#define rom_004E8A_ADDRESS 0x004E8Au
extern const void *rom_004E8A_data;
#define rom_004E8A ((const uint8_t *)rom_004E8A_data)
#define demo_inputs_ADDRESS 0x004E94u
extern const void *demo_inputs_data;
#define demo_inputs ((const uint32_t *)demo_inputs_data)
#define rom_004E98_ADDRESS 0x004E98u
extern const void *rom_004E98_data;
#define rom_004E98 ((const uint32_t *)rom_004E98_data)
#define rom_004E9C_ADDRESS 0x004E9Cu
extern const void *rom_004E9C_data;
#define rom_004E9C ((const uint32_t *)rom_004E9C_data)
#define rom_004EA0_ADDRESS 0x004EA0u
extern const void *rom_004EA0_data;
#define rom_004EA0 ((const uint32_t *)rom_004EA0_data)
#define rom_00584C_ADDRESS 0x00584Cu
extern const void *rom_00584C_data;
#define rom_00584C (*(const uint32_t *)rom_00584C_data)
#define rom_005850_ADDRESS 0x005850u
extern const void *rom_005850_data;
#define rom_005850 (*(const uint32_t *)rom_005850_data)
#define indexed_table_of_32_bit_values_0059A6_ADDRESS 0x0059A6u
extern const void *indexed_table_of_32_bit_values_0059A6_data;
#define indexed_table_of_32_bit_values_0059A6 ((const uint32_t *)indexed_table_of_32_bit_values_0059A6_data)
#define rom_0059B6_ADDRESS 0x0059B6u
extern const void *rom_0059B6_data;
#define rom_0059B6 ((const uint32_t *)rom_0059B6_data)
#define rom_0059C6_ADDRESS 0x0059C6u
extern const void *rom_0059C6_data;
#define rom_0059C6 (*(const uint32_t *)rom_0059C6_data)
#define rom_0059CA_ADDRESS 0x0059CAu
extern const void *rom_0059CA_data;
#define rom_0059CA (*(const uint32_t *)rom_0059CA_data)
#define rom_0059CE_ADDRESS 0x0059CEu
extern const void *rom_0059CE_data;
#define rom_0059CE (*(const uint32_t *)rom_0059CE_data)
#define rom_0059D2_ADDRESS 0x0059D2u
extern const void *rom_0059D2_data;
#define rom_0059D2 ((const uint32_t *)rom_0059D2_data)
#define rom_0059DE_ADDRESS 0x0059DEu
extern const void *rom_0059DE_data;
#define rom_0059DE ((const uint32_t *)rom_0059DE_data)
#define unexplained_005B40_ADDRESS 0x005B40u
extern const void *unexplained_005B40_data;
#define unexplained_005B40 (*(const uint32_t *)unexplained_005B40_data)
#define rom_005B44_ADDRESS 0x005B44u
extern const void *rom_005B44_data;
#define rom_005B44 (*(const uint32_t *)rom_005B44_data)
#define indexed_table_of_8_bit_values_006146_ADDRESS 0x006146u
extern const void *indexed_table_of_8_bit_values_006146_data;
#define indexed_table_of_8_bit_values_006146 ((const uint8_t *)indexed_table_of_8_bit_values_006146_data)
#define indexed_table_of_8_bit_values_00634C_ADDRESS 0x00634Cu
extern const void *indexed_table_of_8_bit_values_00634C_data;
#define indexed_table_of_8_bit_values_00634C ((const uint8_t *)indexed_table_of_8_bit_values_00634C_data)
#define rom_00634D_ADDRESS 0x00634Du
extern const void *rom_00634D_data;
#define rom_00634D ((const uint8_t *)rom_00634D_data)
#define area_tile_banks_ADDRESS 0x00676Eu
extern const void *area_tile_banks_data;
#define area_tile_banks ((const uint8_t *)area_tile_banks_data)
#define rom_00676F_ADDRESS 0x00676Fu
extern const void *rom_00676F_data;
#define rom_00676F ((const uint8_t *)rom_00676F_data)
#define area_layer_priorities_ADDRESS 0x006782u
extern const void *area_layer_priorities_data;
#define area_layer_priorities ((const uint8_t *)area_layer_priorities_data)
#define area_settings_060127_ADDRESS 0x00678Cu
extern const void *area_settings_060127_data;
#define area_settings_060127 ((const uint8_t *)area_settings_060127_data)
#define indexed_table_of_8_bit_values_006A18_ADDRESS 0x006A18u
extern const void *indexed_table_of_8_bit_values_006A18_data;
#define indexed_table_of_8_bit_values_006A18 ((const uint8_t *)indexed_table_of_8_bit_values_006A18_data)
#define indexed_table_of_8_bit_values_006DFC_ADDRESS 0x006DFCu
extern const void *indexed_table_of_8_bit_values_006DFC_data;
#define indexed_table_of_8_bit_values_006DFC ((const uint8_t *)indexed_table_of_8_bit_values_006DFC_data)
#define indexed_table_of_16_bit_values_0072E2_ADDRESS 0x0072E2u
extern const void *indexed_table_of_16_bit_values_0072E2_data;
#define indexed_table_of_16_bit_values_0072E2 ((const uint16_t *)indexed_table_of_16_bit_values_0072E2_data)
#define rom_0072E4_ADDRESS 0x0072E4u
extern const void *rom_0072E4_data;
#define rom_0072E4 ((const uint16_t *)rom_0072E4_data)
#define indexed_table_of_8_bit_values_007592_ADDRESS 0x007592u
extern const void *indexed_table_of_8_bit_values_007592_data;
#define indexed_table_of_8_bit_values_007592 ((const uint8_t *)indexed_table_of_8_bit_values_007592_data)
#define rom_007593_ADDRESS 0x007593u
extern const void *rom_007593_data;
#define rom_007593 ((const uint8_t *)rom_007593_data)
#define rom_007594_ADDRESS 0x007594u
extern const void *rom_007594_data;
#define rom_007594 ((const uint8_t *)rom_007594_data)
#define rom_007595_ADDRESS 0x007595u
extern const void *rom_007595_data;
#define rom_007595 ((const uint8_t *)rom_007595_data)
#define unexplained_00917E_ADDRESS 0x00917Eu
extern const void *unexplained_00917E_data;
#define unexplained_00917E (*(const uint32_t *)unexplained_00917E_data)
#define rom_009182_ADDRESS 0x009182u
extern const void *rom_009182_data;
#define rom_009182 (*(const uint32_t *)rom_009182_data)
#define indexed_table_of_32_bit_values_009310_ADDRESS 0x009310u
extern const void *indexed_table_of_32_bit_values_009310_data;
#define indexed_table_of_32_bit_values_009310 ((const uint32_t *)indexed_table_of_32_bit_values_009310_data)
#define rom_009334_ADDRESS 0x009334u
extern const void *rom_009334_data;
#define rom_009334 ((const uint32_t *)rom_009334_data)
#define palette_bank_counts_ADDRESS 0x0095D2u
extern const void *palette_bank_counts_data;
#define palette_bank_counts ((const uint8_t *)palette_bank_counts_data)
#define palette_bank_addresses_ADDRESS 0x0095D6u
extern const void *palette_bank_addresses_data;
#define palette_bank_addresses ((const uint32_t *)palette_bank_addresses_data)
#define indexed_table_of_32_bit_values_00975C_ADDRESS 0x00975Cu
extern const void *indexed_table_of_32_bit_values_00975C_data;
#define indexed_table_of_32_bit_values_00975C ((const uint32_t *)indexed_table_of_32_bit_values_00975C_data)
#define indexed_table_of_32_bit_values_0098F2_ADDRESS 0x0098F2u
extern const void *indexed_table_of_32_bit_values_0098F2_data;
#define indexed_table_of_32_bit_values_0098F2 ((const uint32_t *)indexed_table_of_32_bit_values_0098F2_data)
#define palettes_009A7C_ADDRESS 0x009A7Cu
extern const void *palettes_009A7C_data;
#define palettes_009A7C ((const uint32_t *)palettes_009A7C_data)
#define palette_effects_009AD2_ADDRESS 0x009AD2u
extern const void *palette_effects_009AD2_data;
#define palette_effects_009AD2 ((const uint32_t *)palette_effects_009AD2_data)
#define palette_effects_009B28_ADDRESS 0x009B28u
extern const void *palette_effects_009B28_data;
#define palette_effects_009B28 ((const uint32_t *)palette_effects_009B28_data)
#define indexed_table_of_32_bit_values_009C30_ADDRESS 0x009C30u
extern const void *indexed_table_of_32_bit_values_009C30_data;
#define indexed_table_of_32_bit_values_009C30 ((const uint32_t *)indexed_table_of_32_bit_values_009C30_data)
#define indexed_table_of_32_bit_values_009EFA_ADDRESS 0x009EFAu
extern const void *indexed_table_of_32_bit_values_009EFA_data;
#define indexed_table_of_32_bit_values_009EFA ((const uint32_t *)indexed_table_of_32_bit_values_009EFA_data)
#define rom_009F16_ADDRESS 0x009F16u
extern const void *rom_009F16_data;
#define rom_009F16 ((const uint8_t *)rom_009F16_data)
#define rom_009F1A_ADDRESS 0x009F1Au
extern const void *rom_009F1A_data;
#define rom_009F1A (*(const uint32_t *)rom_009F1A_data)
#define rom_009F1E_ADDRESS 0x009F1Eu
extern const void *rom_009F1E_data;
#define rom_009F1E ((const uint8_t *)rom_009F1E_data)
#define rom_009F22_ADDRESS 0x009F22u
extern const void *rom_009F22_data;
#define rom_009F22 (*(const uint32_t *)rom_009F22_data)
#define rom_009F26_ADDRESS 0x009F26u
extern const void *rom_009F26_data;
#define rom_009F26 (*(const uint32_t *)rom_009F26_data)
#define rom_009F2A_ADDRESS 0x009F2Au
extern const void *rom_009F2A_data;
#define rom_009F2A (*(const uint32_t *)rom_009F2A_data)
#define rom_009F2E_ADDRESS 0x009F2Eu
extern const void *rom_009F2E_data;
#define rom_009F2E ((const uint32_t *)rom_009F2E_data)
#define rom_009F46_ADDRESS 0x009F46u
extern const void *rom_009F46_data;
#define rom_009F46 ((const uint8_t *)rom_009F46_data)
#define indexed_table_of_32_bit_values_00DF92_ADDRESS 0x00DF92u
extern const void *indexed_table_of_32_bit_values_00DF92_data;
#define indexed_table_of_32_bit_values_00DF92 ((const uint32_t *)indexed_table_of_32_bit_values_00DF92_data)
#define indexed_table_of_32_bit_values_00E082_ADDRESS 0x00E082u
extern const void *indexed_table_of_32_bit_values_00E082_data;
#define indexed_table_of_32_bit_values_00E082 ((const uint32_t *)indexed_table_of_32_bit_values_00E082_data)
#define indexed_table_of_32_bit_values_00E13C_ADDRESS 0x00E13Cu
extern const void *indexed_table_of_32_bit_values_00E13C_data;
#define indexed_table_of_32_bit_values_00E13C ((const uint32_t *)indexed_table_of_32_bit_values_00E13C_data)
#define indexed_table_of_32_bit_values_00E1C0_ADDRESS 0x00E1C0u
extern const void *indexed_table_of_32_bit_values_00E1C0_data;
#define indexed_table_of_32_bit_values_00E1C0 ((const uint32_t *)indexed_table_of_32_bit_values_00E1C0_data)
#define indexed_table_of_32_bit_values_00E2F0_ADDRESS 0x00E2F0u
extern const void *indexed_table_of_32_bit_values_00E2F0_data;
#define indexed_table_of_32_bit_values_00E2F0 ((const uint32_t *)indexed_table_of_32_bit_values_00E2F0_data)
#define indexed_table_of_32_bit_values_00E3B0_ADDRESS 0x00E3B0u
extern const void *indexed_table_of_32_bit_values_00E3B0_data;
#define indexed_table_of_32_bit_values_00E3B0 ((const uint32_t *)indexed_table_of_32_bit_values_00E3B0_data)
#define indexed_table_of_16_bit_values_00E48A_ADDRESS 0x00E48Au
extern const void *indexed_table_of_16_bit_values_00E48A_data;
#define indexed_table_of_16_bit_values_00E48A ((const uint16_t *)indexed_table_of_16_bit_values_00E48A_data)
#define indexed_table_of_32_bit_values_00E546_ADDRESS 0x00E546u
extern const void *indexed_table_of_32_bit_values_00E546_data;
#define indexed_table_of_32_bit_values_00E546 ((const uint32_t *)indexed_table_of_32_bit_values_00E546_data)
#define indexed_table_of_32_bit_values_00E582_ADDRESS 0x00E582u
extern const void *indexed_table_of_32_bit_values_00E582_data;
#define indexed_table_of_32_bit_values_00E582 ((const uint32_t *)indexed_table_of_32_bit_values_00E582_data)
#define indexed_table_of_8_bit_values_00E700_ADDRESS 0x00E700u
extern const void *indexed_table_of_8_bit_values_00E700_data;
#define indexed_table_of_8_bit_values_00E700 ((const uint8_t *)indexed_table_of_8_bit_values_00E700_data)
#define indexed_table_of_16_bit_values_00EB1E_ADDRESS 0x00EB1Eu
extern const void *indexed_table_of_16_bit_values_00EB1E_data;
#define indexed_table_of_16_bit_values_00EB1E ((const uint16_t *)indexed_table_of_16_bit_values_00EB1E_data)
#define rom_00EB20_ADDRESS 0x00EB20u
extern const void *rom_00EB20_data;
#define rom_00EB20 ((const uint16_t *)rom_00EB20_data)
#define rom_00EC9C_ADDRESS 0x00EC9Cu
extern const void *rom_00EC9C_data;
#define rom_00EC9C (*(const uint32_t *)rom_00EC9C_data)
#define rom_00ECA0_ADDRESS 0x00ECA0u
extern const void *rom_00ECA0_data;
#define rom_00ECA0 (*(const uint32_t *)rom_00ECA0_data)
#define rom_00ECA4_ADDRESS 0x00ECA4u
extern const void *rom_00ECA4_data;
#define rom_00ECA4 (*(const uint32_t *)rom_00ECA4_data)
#define rom_00ECA8_ADDRESS 0x00ECA8u
extern const void *rom_00ECA8_data;
#define rom_00ECA8 (*(const uint32_t *)rom_00ECA8_data)
#define rom_00ECAC_ADDRESS 0x00ECACu
extern const void *rom_00ECAC_data;
#define rom_00ECAC (*(const uint32_t *)rom_00ECAC_data)
#define rom_00ECB0_ADDRESS 0x00ECB0u
extern const void *rom_00ECB0_data;
#define rom_00ECB0 (*(const uint32_t *)rom_00ECB0_data)
#define rom_00ECB4_ADDRESS 0x00ECB4u
extern const void *rom_00ECB4_data;
#define rom_00ECB4 (*(const uint32_t *)rom_00ECB4_data)
#define rom_00ECB8_ADDRESS 0x00ECB8u
extern const void *rom_00ECB8_data;
#define rom_00ECB8 (*(const uint32_t *)rom_00ECB8_data)
#define rom_00ECBC_ADDRESS 0x00ECBCu
extern const void *rom_00ECBC_data;
#define rom_00ECBC (*(const uint32_t *)rom_00ECBC_data)
#define rom_00ECC0_ADDRESS 0x00ECC0u
extern const void *rom_00ECC0_data;
#define rom_00ECC0 (*(const uint32_t *)rom_00ECC0_data)
#define rom_00ECC4_ADDRESS 0x00ECC4u
extern const void *rom_00ECC4_data;
#define rom_00ECC4 (*(const uint32_t *)rom_00ECC4_data)
#define rom_00ECC8_ADDRESS 0x00ECC8u
extern const void *rom_00ECC8_data;
#define rom_00ECC8 (*(const uint32_t *)rom_00ECC8_data)
#define rom_00ECCC_ADDRESS 0x00ECCCu
extern const void *rom_00ECCC_data;
#define rom_00ECCC (*(const uint32_t *)rom_00ECCC_data)
#define rom_00ECD0_ADDRESS 0x00ECD0u
extern const void *rom_00ECD0_data;
#define rom_00ECD0 (*(const uint32_t *)rom_00ECD0_data)
#define rom_00ECD4_ADDRESS 0x00ECD4u
extern const void *rom_00ECD4_data;
#define rom_00ECD4 (*(const uint32_t *)rom_00ECD4_data)
#define animations_00F674_ADDRESS 0x00F674u
extern const void *animations_00F674_data;
#define animations_00F674 (*(const uint32_t *)animations_00F674_data)
#define rom_00F678_ADDRESS 0x00F678u
extern const void *rom_00F678_data;
#define rom_00F678 (*(const uint32_t *)rom_00F678_data)
#define animations_00F760_ADDRESS 0x00F760u
extern const void *animations_00F760_data;
#define animations_00F760 ((const uint32_t *)animations_00F760_data)
#define rom_00F76C_ADDRESS 0x00F76Cu
extern const void *rom_00F76C_data;
#define rom_00F76C (*(const uint32_t *)rom_00F76C_data)
#define indexed_table_of_16_bit_values_00F938_ADDRESS 0x00F938u
extern const void *indexed_table_of_16_bit_values_00F938_data;
#define indexed_table_of_16_bit_values_00F938 ((const uint16_t *)indexed_table_of_16_bit_values_00F938_data)
#define indexed_table_of_32_bit_values_00FF60_ADDRESS 0x00FF60u
extern const void *indexed_table_of_32_bit_values_00FF60_data;
#define indexed_table_of_32_bit_values_00FF60 ((const uint32_t *)indexed_table_of_32_bit_values_00FF60_data)
#define indexed_table_of_8_bit_values_010012_ADDRESS 0x010012u
extern const void *indexed_table_of_8_bit_values_010012_data;
#define indexed_table_of_8_bit_values_010012 ((const uint8_t *)indexed_table_of_8_bit_values_010012_data)
#define indexed_table_of_32_bit_values_010148_ADDRESS 0x010148u
extern const void *indexed_table_of_32_bit_values_010148_data;
#define indexed_table_of_32_bit_values_010148 ((const uint32_t *)indexed_table_of_32_bit_values_010148_data)
#define indexed_table_of_16_bit_values_010232_ADDRESS 0x010232u
extern const void *indexed_table_of_16_bit_values_010232_data;
#define indexed_table_of_16_bit_values_010232 ((const uint16_t *)indexed_table_of_16_bit_values_010232_data)
#define indexed_table_of_32_bit_values_010616_ADDRESS 0x010616u
extern const void *indexed_table_of_32_bit_values_010616_data;
#define indexed_table_of_32_bit_values_010616 ((const uint32_t *)indexed_table_of_32_bit_values_010616_data)
#define indexed_table_of_8_bit_values_0107AE_ADDRESS 0x0107AEu
extern const void *indexed_table_of_8_bit_values_0107AE_data;
#define indexed_table_of_8_bit_values_0107AE ((const uint8_t *)indexed_table_of_8_bit_values_0107AE_data)
#define nozzle_row_routines_ADDRESS 0x010A0Eu
extern const void *nozzle_row_routines_data;
#define nozzle_row_routines ((const uint32_t *)nozzle_row_routines_data)
#define indexed_table_of_32_bit_values_010AB2_ADDRESS 0x010AB2u
extern const void *indexed_table_of_32_bit_values_010AB2_data;
#define indexed_table_of_32_bit_values_010AB2 ((const uint32_t *)indexed_table_of_32_bit_values_010AB2_data)
#define indexed_table_of_32_bit_values_010B7E_ADDRESS 0x010B7Eu
extern const void *indexed_table_of_32_bit_values_010B7E_data;
#define indexed_table_of_32_bit_values_010B7E ((const uint32_t *)indexed_table_of_32_bit_values_010B7E_data)
#define indexed_table_of_8_bit_values_010EAA_ADDRESS 0x010EAAu
extern const void *indexed_table_of_8_bit_values_010EAA_data;
#define indexed_table_of_8_bit_values_010EAA ((const uint8_t *)indexed_table_of_8_bit_values_010EAA_data)
#define rom_010EAE_ADDRESS 0x010EAEu
extern const void *rom_010EAE_data;
#define rom_010EAE ((const uint16_t *)rom_010EAE_data)
#define indexed_table_of_16_bit_values_010F1C_ADDRESS 0x010F1Cu
extern const void *indexed_table_of_16_bit_values_010F1C_data;
#define indexed_table_of_16_bit_values_010F1C ((const uint16_t *)indexed_table_of_16_bit_values_010F1C_data)
#define rom_010F1E_ADDRESS 0x010F1Eu
extern const void *rom_010F1E_data;
#define rom_010F1E ((const uint16_t *)rom_010F1E_data)
#define rom_010F44_ADDRESS 0x010F44u
extern const void *rom_010F44_data;
#define rom_010F44 ((const uint8_t *)rom_010F44_data)
#define indexed_table_of_16_bit_values_010F62_ADDRESS 0x010F62u
extern const void *indexed_table_of_16_bit_values_010F62_data;
#define indexed_table_of_16_bit_values_010F62 ((const uint16_t *)indexed_table_of_16_bit_values_010F62_data)
#define rom_010F64_ADDRESS 0x010F64u
extern const void *rom_010F64_data;
#define rom_010F64 ((const uint16_t *)rom_010F64_data)
#define indexed_table_of_16_bit_values_0113BE_ADDRESS 0x0113BEu
extern const void *indexed_table_of_16_bit_values_0113BE_data;
#define indexed_table_of_16_bit_values_0113BE ((const uint16_t *)indexed_table_of_16_bit_values_0113BE_data)
#define rom_0113C0_ADDRESS 0x0113C0u
extern const void *rom_0113C0_data;
#define rom_0113C0 ((const uint16_t *)rom_0113C0_data)
#define indexed_table_of_32_bit_values_011562_ADDRESS 0x011562u
extern const void *indexed_table_of_32_bit_values_011562_data;
#define indexed_table_of_32_bit_values_011562 ((const uint32_t *)indexed_table_of_32_bit_values_011562_data)
#define rom_011782_ADDRESS 0x011782u
extern const void *rom_011782_data;
#define rom_011782 ((const uint32_t *)rom_011782_data)
#define indexed_table_of_32_bit_values_0119F2_ADDRESS 0x0119F2u
extern const void *indexed_table_of_32_bit_values_0119F2_data;
#define indexed_table_of_32_bit_values_0119F2 ((const uint32_t *)indexed_table_of_32_bit_values_0119F2_data)
#define indexed_table_of_8_bit_values_011D1A_ADDRESS 0x011D1Au
extern const void *indexed_table_of_8_bit_values_011D1A_data;
#define indexed_table_of_8_bit_values_011D1A ((const uint8_t *)indexed_table_of_8_bit_values_011D1A_data)
#define indexed_table_of_8_bit_values_011DEE_ADDRESS 0x011DEEu
extern const void *indexed_table_of_8_bit_values_011DEE_data;
#define indexed_table_of_8_bit_values_011DEE ((const uint8_t *)indexed_table_of_8_bit_values_011DEE_data)
#define rom_011DF2_ADDRESS 0x011DF2u
extern const void *rom_011DF2_data;
#define rom_011DF2 ((const uint8_t *)rom_011DF2_data)
#define indexed_table_of_8_bit_values_012108_ADDRESS 0x012108u
extern const void *indexed_table_of_8_bit_values_012108_data;
#define indexed_table_of_8_bit_values_012108 ((const uint8_t *)indexed_table_of_8_bit_values_012108_data)
#define rom_012109_ADDRESS 0x012109u
extern const void *rom_012109_data;
#define rom_012109 ((const uint8_t *)rom_012109_data)
#define indexed_table_of_32_bit_values_0121AC_ADDRESS 0x0121ACu
extern const void *indexed_table_of_32_bit_values_0121AC_data;
#define indexed_table_of_32_bit_values_0121AC ((const uint32_t *)indexed_table_of_32_bit_values_0121AC_data)
#define rom_012360_ADDRESS 0x012360u
extern const void *rom_012360_data;
#define rom_012360 ((const uint32_t *)rom_012360_data)
#define indexed_table_of_8_bit_values_01255E_ADDRESS 0x01255Eu
extern const void *indexed_table_of_8_bit_values_01255E_data;
#define indexed_table_of_8_bit_values_01255E ((const uint8_t *)indexed_table_of_8_bit_values_01255E_data)
#define rom_012628_ADDRESS 0x012628u
extern const void *rom_012628_data;
#define rom_012628 ((const uint8_t *)rom_012628_data)
#define indexed_table_of_16_bit_values_012CFE_ADDRESS 0x012CFEu
extern const void *indexed_table_of_16_bit_values_012CFE_data;
#define indexed_table_of_16_bit_values_012CFE ((const uint16_t *)indexed_table_of_16_bit_values_012CFE_data)
#define indexed_table_of_16_bit_values_013092_ADDRESS 0x013092u
extern const void *indexed_table_of_16_bit_values_013092_data;
#define indexed_table_of_16_bit_values_013092 ((const uint16_t *)indexed_table_of_16_bit_values_013092_data)
#define indexed_table_of_16_bit_values_0130F4_ADDRESS 0x0130F4u
extern const void *indexed_table_of_16_bit_values_0130F4_data;
#define indexed_table_of_16_bit_values_0130F4 ((const uint16_t *)indexed_table_of_16_bit_values_0130F4_data)
#define rom_0130FC_ADDRESS 0x0130FCu
extern const void *rom_0130FC_data;
#define rom_0130FC ((const uint16_t *)rom_0130FC_data)
#define indexed_table_of_32_bit_values_0134CA_ADDRESS 0x0134CAu
extern const void *indexed_table_of_32_bit_values_0134CA_data;
#define indexed_table_of_32_bit_values_0134CA ((const uint32_t *)indexed_table_of_32_bit_values_0134CA_data)
#define indexed_table_of_16_bit_values_0138AC_ADDRESS 0x0138ACu
extern const void *indexed_table_of_16_bit_values_0138AC_data;
#define indexed_table_of_16_bit_values_0138AC ((const uint16_t *)indexed_table_of_16_bit_values_0138AC_data)
#define rom_0138B4_ADDRESS 0x0138B4u
extern const void *rom_0138B4_data;
#define rom_0138B4 ((const uint16_t *)rom_0138B4_data)
#define indexed_table_of_8_bit_values_0139A2_ADDRESS 0x0139A2u
extern const void *indexed_table_of_8_bit_values_0139A2_data;
#define indexed_table_of_8_bit_values_0139A2 ((const uint8_t *)indexed_table_of_8_bit_values_0139A2_data)
#define indexed_table_of_8_bit_values_0139D6_ADDRESS 0x0139D6u
extern const void *indexed_table_of_8_bit_values_0139D6_data;
#define indexed_table_of_8_bit_values_0139D6 ((const uint8_t *)indexed_table_of_8_bit_values_0139D6_data)
#define rom_0139DA_ADDRESS 0x0139DAu
extern const void *rom_0139DA_data;
#define rom_0139DA ((const uint16_t *)rom_0139DA_data)
#define rom_0139DC_ADDRESS 0x0139DCu
extern const void *rom_0139DC_data;
#define rom_0139DC ((const uint16_t *)rom_0139DC_data)
#define indexed_table_of_8_bit_values_013A74_ADDRESS 0x013A74u
extern const void *indexed_table_of_8_bit_values_013A74_data;
#define indexed_table_of_8_bit_values_013A74 ((const uint8_t *)indexed_table_of_8_bit_values_013A74_data)
#define indexed_table_of_32_bit_values_013C46_ADDRESS 0x013C46u
extern const void *indexed_table_of_32_bit_values_013C46_data;
#define indexed_table_of_32_bit_values_013C46 ((const uint32_t *)indexed_table_of_32_bit_values_013C46_data)
#define indexed_table_of_8_bit_values_013E30_ADDRESS 0x013E30u
extern const void *indexed_table_of_8_bit_values_013E30_data;
#define indexed_table_of_8_bit_values_013E30 ((const uint8_t *)indexed_table_of_8_bit_values_013E30_data)
#define indexed_table_of_32_bit_values_013F08_ADDRESS 0x013F08u
extern const void *indexed_table_of_32_bit_values_013F08_data;
#define indexed_table_of_32_bit_values_013F08 ((const uint32_t *)indexed_table_of_32_bit_values_013F08_data)
#define indexed_table_of_16_bit_values_01416E_ADDRESS 0x01416Eu
extern const void *indexed_table_of_16_bit_values_01416E_data;
#define indexed_table_of_16_bit_values_01416E ((const uint16_t *)indexed_table_of_16_bit_values_01416E_data)
#define rom_0141B4_ADDRESS 0x0141B4u
extern const void *rom_0141B4_data;
#define rom_0141B4 ((const uint16_t *)rom_0141B4_data)
#define indexed_table_of_8_bit_values_01424A_ADDRESS 0x01424Au
extern const void *indexed_table_of_8_bit_values_01424A_data;
#define indexed_table_of_8_bit_values_01424A ((const uint8_t *)indexed_table_of_8_bit_values_01424A_data)
#define indexed_table_of_16_bit_values_01426A_ADDRESS 0x01426Au
extern const void *indexed_table_of_16_bit_values_01426A_data;
#define indexed_table_of_16_bit_values_01426A ((const uint16_t *)indexed_table_of_16_bit_values_01426A_data)
#define rom_01426C_ADDRESS 0x01426Cu
extern const void *rom_01426C_data;
#define rom_01426C ((const uint16_t *)rom_01426C_data)
#define animations_0143D4_ADDRESS 0x0143D4u
extern const void *animations_0143D4_data;
#define animations_0143D4 ((const uint32_t *)animations_0143D4_data)
#define rom_01443E_ADDRESS 0x01443Eu
extern const void *rom_01443E_data;
#define rom_01443E (*(const uint32_t *)rom_01443E_data)
#define rom_014442_ADDRESS 0x014442u
extern const void *rom_014442_data;
#define rom_014442 (*(const uint32_t *)rom_014442_data)
#define rom_014446_ADDRESS 0x014446u
extern const void *rom_014446_data;
#define rom_014446 (*(const uint32_t *)rom_014446_data)
#define rom_01444A_ADDRESS 0x01444Au
extern const void *rom_01444A_data;
#define rom_01444A (*(const uint32_t *)rom_01444A_data)
#define rom_0144E8_ADDRESS 0x0144E8u
extern const void *rom_0144E8_data;
#define rom_0144E8 ((const uint32_t *)rom_0144E8_data)
#define rom_014598_ADDRESS 0x014598u
extern const void *rom_014598_data;
#define rom_014598 (*(const uint32_t *)rom_014598_data)
#define rom_01459C_ADDRESS 0x01459Cu
extern const void *rom_01459C_data;
#define rom_01459C (*(const uint32_t *)rom_01459C_data)
#define rom_0145A0_ADDRESS 0x0145A0u
extern const void *rom_0145A0_data;
#define rom_0145A0 (*(const uint32_t *)rom_0145A0_data)
#define rom_0145FC_ADDRESS 0x0145FCu
extern const void *rom_0145FC_data;
#define rom_0145FC (*(const uint32_t *)rom_0145FC_data)
#define rom_014600_ADDRESS 0x014600u
extern const void *rom_014600_data;
#define rom_014600 (*(const uint32_t *)rom_014600_data)
#define rom_01461A_ADDRESS 0x01461Au
extern const void *rom_01461A_data;
#define rom_01461A (*(const uint32_t *)rom_01461A_data)
#define rom_01461E_ADDRESS 0x01461Eu
extern const void *rom_01461E_data;
#define rom_01461E (*(const uint32_t *)rom_01461E_data)
#define rom_014636_ADDRESS 0x014636u
extern const void *rom_014636_data;
#define rom_014636 ((const uint32_t *)rom_014636_data)
#define rom_01480E_ADDRESS 0x01480Eu
extern const void *rom_01480E_data;
#define rom_01480E (*(const uint32_t *)rom_01480E_data)
#define rom_014812_ADDRESS 0x014812u
extern const void *rom_014812_data;
#define rom_014812 (*(const uint32_t *)rom_014812_data)
#define rom_014860_ADDRESS 0x014860u
extern const void *rom_014860_data;
#define rom_014860 (*(const uint32_t *)rom_014860_data)
#define rom_014864_ADDRESS 0x014864u
extern const void *rom_014864_data;
#define rom_014864 (*(const uint32_t *)rom_014864_data)
#define rom_014868_ADDRESS 0x014868u
extern const void *rom_014868_data;
#define rom_014868 (*(const uint32_t *)rom_014868_data)
#define rom_01488A_ADDRESS 0x01488Au
extern const void *rom_01488A_data;
#define rom_01488A (*(const uint32_t *)rom_01488A_data)
#define rom_01488E_ADDRESS 0x01488Eu
extern const void *rom_01488E_data;
#define rom_01488E (*(const uint32_t *)rom_01488E_data)
#define rom_014892_ADDRESS 0x014892u
extern const void *rom_014892_data;
#define rom_014892 (*(const uint32_t *)rom_014892_data)
#define rom_014896_ADDRESS 0x014896u
extern const void *rom_014896_data;
#define rom_014896 (*(const uint32_t *)rom_014896_data)
#define rom_01489A_ADDRESS 0x01489Au
extern const void *rom_01489A_data;
#define rom_01489A (*(const uint32_t *)rom_01489A_data)
#define rom_014A26_ADDRESS 0x014A26u
extern const void *rom_014A26_data;
#define rom_014A26 (*(const uint32_t *)rom_014A26_data)
#define rom_014A2A_ADDRESS 0x014A2Au
extern const void *rom_014A2A_data;
#define rom_014A2A (*(const uint32_t *)rom_014A2A_data)
#define rom_014A2E_ADDRESS 0x014A2Eu
extern const void *rom_014A2E_data;
#define rom_014A2E (*(const uint32_t *)rom_014A2E_data)
#define rom_014AA2_ADDRESS 0x014AA2u
extern const void *rom_014AA2_data;
#define rom_014AA2 (*(const uint32_t *)rom_014AA2_data)
#define rom_014AA6_ADDRESS 0x014AA6u
extern const void *rom_014AA6_data;
#define rom_014AA6 (*(const uint32_t *)rom_014AA6_data)
#define rom_014AD6_ADDRESS 0x014AD6u
extern const void *rom_014AD6_data;
#define rom_014AD6 (*(const uint32_t *)rom_014AD6_data)
#define rom_014ADA_ADDRESS 0x014ADAu
extern const void *rom_014ADA_data;
#define rom_014ADA (*(const uint32_t *)rom_014ADA_data)
#define rom_014ADE_ADDRESS 0x014ADEu
extern const void *rom_014ADE_data;
#define rom_014ADE (*(const uint32_t *)rom_014ADE_data)
#define rom_014AE2_ADDRESS 0x014AE2u
extern const void *rom_014AE2_data;
#define rom_014AE2 (*(const uint32_t *)rom_014AE2_data)
#define rom_014BA0_ADDRESS 0x014BA0u
extern const void *rom_014BA0_data;
#define rom_014BA0 (*(const uint32_t *)rom_014BA0_data)
#define rom_014C3A_ADDRESS 0x014C3Au
extern const void *rom_014C3A_data;
#define rom_014C3A (*(const uint32_t *)rom_014C3A_data)
#define rom_014C86_ADDRESS 0x014C86u
extern const void *rom_014C86_data;
#define rom_014C86 (*(const uint32_t *)rom_014C86_data)
#define rom_014D1C_ADDRESS 0x014D1Cu
extern const void *rom_014D1C_data;
#define rom_014D1C (*(const uint32_t *)rom_014D1C_data)
#define rom_014DA0_ADDRESS 0x014DA0u
extern const void *rom_014DA0_data;
#define rom_014DA0 ((const uint32_t *)rom_014DA0_data)
#define rom_014DA4_ADDRESS 0x014DA4u
extern const void *rom_014DA4_data;
#define rom_014DA4 (*(const uint32_t *)rom_014DA4_data)
#define rom_014DA8_ADDRESS 0x014DA8u
extern const void *rom_014DA8_data;
#define rom_014DA8 (*(const uint32_t *)rom_014DA8_data)
#define rom_014DAC_ADDRESS 0x014DACu
extern const void *rom_014DAC_data;
#define rom_014DAC (*(const uint32_t *)rom_014DAC_data)
#define rom_014DB0_ADDRESS 0x014DB0u
extern const void *rom_014DB0_data;
#define rom_014DB0 (*(const uint32_t *)rom_014DB0_data)
#define rom_014FBE_ADDRESS 0x014FBEu
extern const void *rom_014FBE_data;
#define rom_014FBE (*(const uint32_t *)rom_014FBE_data)
#define rom_015042_ADDRESS 0x015042u
extern const void *rom_015042_data;
#define rom_015042 (*(const uint32_t *)rom_015042_data)
#define rom_015046_ADDRESS 0x015046u
extern const void *rom_015046_data;
#define rom_015046 (*(const uint32_t *)rom_015046_data)
#define rom_01504E_ADDRESS 0x01504Eu
extern const void *rom_01504E_data;
#define rom_01504E (*(const uint32_t *)rom_01504E_data)
#define rom_0150E8_ADDRESS 0x0150E8u
extern const void *rom_0150E8_data;
#define rom_0150E8 (*(const uint32_t *)rom_0150E8_data)
#define rom_0150EC_ADDRESS 0x0150ECu
extern const void *rom_0150EC_data;
#define rom_0150EC (*(const uint32_t *)rom_0150EC_data)
#define rom_01519C_ADDRESS 0x01519Cu
extern const void *rom_01519C_data;
#define rom_01519C (*(const uint32_t *)rom_01519C_data)
#define rom_0151AA_ADDRESS 0x0151AAu
extern const void *rom_0151AA_data;
#define rom_0151AA ((const uint32_t *)rom_0151AA_data)
#define rom_015258_ADDRESS 0x015258u
extern const void *rom_015258_data;
#define rom_015258 (*(const uint32_t *)rom_015258_data)
#define rom_0152EE_ADDRESS 0x0152EEu
extern const void *rom_0152EE_data;
#define rom_0152EE (*(const uint32_t *)rom_0152EE_data)
#define rom_0152F2_ADDRESS 0x0152F2u
extern const void *rom_0152F2_data;
#define rom_0152F2 (*(const uint32_t *)rom_0152F2_data)
#define rom_01534A_ADDRESS 0x01534Au
extern const void *rom_01534A_data;
#define rom_01534A (*(const uint32_t *)rom_01534A_data)
#define rom_015360_ADDRESS 0x015360u
extern const void *rom_015360_data;
#define rom_015360 (*(const uint32_t *)rom_015360_data)
#define rom_015368_ADDRESS 0x015368u
extern const void *rom_015368_data;
#define rom_015368 (*(const uint32_t *)rom_015368_data)
#define rom_01536C_ADDRESS 0x01536Cu
extern const void *rom_01536C_data;
#define rom_01536C (*(const uint32_t *)rom_01536C_data)
#define rom_0153D8_ADDRESS 0x0153D8u
extern const void *rom_0153D8_data;
#define rom_0153D8 ((const uint32_t *)rom_0153D8_data)
#define rom_0153DC_ADDRESS 0x0153DCu
extern const void *rom_0153DC_data;
#define rom_0153DC (*(const uint32_t *)rom_0153DC_data)
#define rom_0153E0_ADDRESS 0x0153E0u
extern const void *rom_0153E0_data;
#define rom_0153E0 (*(const uint32_t *)rom_0153E0_data)
#define rom_0153E4_ADDRESS 0x0153E4u
extern const void *rom_0153E4_data;
#define rom_0153E4 (*(const uint32_t *)rom_0153E4_data)
#define rom_0153E8_ADDRESS 0x0153E8u
extern const void *rom_0153E8_data;
#define rom_0153E8 (*(const uint32_t *)rom_0153E8_data)
#define rom_015692_ADDRESS 0x015692u
extern const void *rom_015692_data;
#define rom_015692 (*(const uint32_t *)rom_015692_data)
#define rom_0156DA_ADDRESS 0x0156DAu
extern const void *rom_0156DA_data;
#define rom_0156DA (*(const uint32_t *)rom_0156DA_data)
#define rom_0156F0_ADDRESS 0x0156F0u
extern const void *rom_0156F0_data;
#define rom_0156F0 (*(const uint32_t *)rom_0156F0_data)
#define rom_0156FE_ADDRESS 0x0156FEu
extern const void *rom_0156FE_data;
#define rom_0156FE (*(const uint32_t *)rom_0156FE_data)
#define rom_01574E_ADDRESS 0x01574Eu
extern const void *rom_01574E_data;
#define rom_01574E (*(const uint32_t *)rom_01574E_data)
#define rom_015764_ADDRESS 0x015764u
extern const void *rom_015764_data;
#define rom_015764 ((const uint32_t *)rom_015764_data)
#define rom_01579C_ADDRESS 0x01579Cu
extern const void *rom_01579C_data;
#define rom_01579C (*(const uint32_t *)rom_01579C_data)
#define rom_0157A0_ADDRESS 0x0157A0u
extern const void *rom_0157A0_data;
#define rom_0157A0 (*(const uint32_t *)rom_0157A0_data)
#define rom_0157A4_ADDRESS 0x0157A4u
extern const void *rom_0157A4_data;
#define rom_0157A4 (*(const uint32_t *)rom_0157A4_data)
#define rom_015838_ADDRESS 0x015838u
extern const void *rom_015838_data;
#define rom_015838 (*(const uint32_t *)rom_015838_data)
#define rom_01584E_ADDRESS 0x01584Eu
extern const void *rom_01584E_data;
#define rom_01584E ((const uint32_t *)rom_01584E_data)
#define rom_01587E_ADDRESS 0x01587Eu
extern const void *rom_01587E_data;
#define rom_01587E (*(const uint32_t *)rom_01587E_data)
#define rom_015882_ADDRESS 0x015882u
extern const void *rom_015882_data;
#define rom_015882 (*(const uint32_t *)rom_015882_data)
#define rom_015938_ADDRESS 0x015938u
extern const void *rom_015938_data;
#define rom_015938 ((const uint32_t *)rom_015938_data)
#define rom_01593C_ADDRESS 0x01593Cu
extern const void *rom_01593C_data;
#define rom_01593C ((const uint32_t *)rom_01593C_data)
#define rom_015950_ADDRESS 0x015950u
extern const void *rom_015950_data;
#define rom_015950 (*(const uint32_t *)rom_015950_data)
#define rom_015AA0_ADDRESS 0x015AA0u
extern const void *rom_015AA0_data;
#define rom_015AA0 (*(const uint32_t *)rom_015AA0_data)
#define rom_015B36_ADDRESS 0x015B36u
extern const void *rom_015B36_data;
#define rom_015B36 (*(const uint32_t *)rom_015B36_data)
#define rom_015C70_ADDRESS 0x015C70u
extern const void *rom_015C70_data;
#define rom_015C70 (*(const uint32_t *)rom_015C70_data)
#define rom_015C74_ADDRESS 0x015C74u
extern const void *rom_015C74_data;
#define rom_015C74 (*(const uint32_t *)rom_015C74_data)
#define rom_015C78_ADDRESS 0x015C78u
extern const void *rom_015C78_data;
#define rom_015C78 (*(const uint32_t *)rom_015C78_data)
#define rom_015C7C_ADDRESS 0x015C7Cu
extern const void *rom_015C7C_data;
#define rom_015C7C (*(const uint32_t *)rom_015C7C_data)
#define rom_015D4A_ADDRESS 0x015D4Au
extern const void *rom_015D4A_data;
#define rom_015D4A (*(const uint32_t *)rom_015D4A_data)
#define rom_015D68_ADDRESS 0x015D68u
extern const void *rom_015D68_data;
#define rom_015D68 (*(const uint32_t *)rom_015D68_data)
#define rom_015E02_ADDRESS 0x015E02u
extern const void *rom_015E02_data;
#define rom_015E02 (*(const uint32_t *)rom_015E02_data)
#define rom_015E06_ADDRESS 0x015E06u
extern const void *rom_015E06_data;
#define rom_015E06 (*(const uint32_t *)rom_015E06_data)
#define rom_015EBE_ADDRESS 0x015EBEu
extern const void *rom_015EBE_data;
#define rom_015EBE (*(const uint32_t *)rom_015EBE_data)
#define rom_015EC2_ADDRESS 0x015EC2u
extern const void *rom_015EC2_data;
#define rom_015EC2 (*(const uint32_t *)rom_015EC2_data)
#define rom_015EEA_ADDRESS 0x015EEAu
extern const void *rom_015EEA_data;
#define rom_015EEA (*(const uint32_t *)rom_015EEA_data)
#define rom_015EEE_ADDRESS 0x015EEEu
extern const void *rom_015EEE_data;
#define rom_015EEE (*(const uint32_t *)rom_015EEE_data)
#define indexed_table_of_8_bit_values_0184C2_ADDRESS 0x0184C2u
extern const void *indexed_table_of_8_bit_values_0184C2_data;
#define indexed_table_of_8_bit_values_0184C2 ((const uint8_t *)indexed_table_of_8_bit_values_0184C2_data)
#define rom_018560_ADDRESS 0x018560u
extern const void *rom_018560_data;
#define rom_018560 ((const uint8_t *)rom_018560_data)
#define unexplained_01867E_ADDRESS 0x01867Eu
extern const void *unexplained_01867E_data;
#define unexplained_01867E (*(const uint32_t *)unexplained_01867E_data)
#define unexplained_018710_ADDRESS 0x018710u
extern const void *unexplained_018710_data;
#define unexplained_018710 (*(const uint32_t *)unexplained_018710_data)
#define texts_019272_ADDRESS 0x019272u
extern const void *texts_019272_data;
#define texts_019272 ((const uint32_t *)texts_019272_data)
#define rom_019866_ADDRESS 0x019866u
extern const void *rom_019866_data;
#define rom_019866 ((const uint32_t *)rom_019866_data)
#define indexed_table_of_32_bit_values_019D54_ADDRESS 0x019D54u
extern const void *indexed_table_of_32_bit_values_019D54_data;
#define indexed_table_of_32_bit_values_019D54 ((const uint32_t *)indexed_table_of_32_bit_values_019D54_data)
#define rom_019EB2_ADDRESS 0x019EB2u
extern const void *rom_019EB2_data;
#define rom_019EB2 ((const uint16_t *)rom_019EB2_data)
#define rom_019EB4_ADDRESS 0x019EB4u
extern const void *rom_019EB4_data;
#define rom_019EB4 ((const uint16_t *)rom_019EB4_data)
#define rom_019EB6_ADDRESS 0x019EB6u
extern const void *rom_019EB6_data;
#define rom_019EB6 ((const uint16_t *)rom_019EB6_data)
#define animations_019F24_ADDRESS 0x019F24u
extern const void *animations_019F24_data;
#define animations_019F24 ((const uint32_t *)animations_019F24_data)
#define indexed_table_of_32_bit_values_019F92_ADDRESS 0x019F92u
extern const void *indexed_table_of_32_bit_values_019F92_data;
#define indexed_table_of_32_bit_values_019F92 ((const uint32_t *)indexed_table_of_32_bit_values_019F92_data)
#define indexed_table_of_32_bit_values_019FDE_ADDRESS 0x019FDEu
extern const void *indexed_table_of_32_bit_values_019FDE_data;
#define indexed_table_of_32_bit_values_019FDE ((const uint32_t *)indexed_table_of_32_bit_values_019FDE_data)
#define indexed_table_of_32_bit_values_01A14E_ADDRESS 0x01A14Eu
extern const void *indexed_table_of_32_bit_values_01A14E_data;
#define indexed_table_of_32_bit_values_01A14E ((const uint32_t *)indexed_table_of_32_bit_values_01A14E_data)
#define indexed_table_of_8_bit_values_01A2D2_ADDRESS 0x01A2D2u
extern const void *indexed_table_of_8_bit_values_01A2D2_data;
#define indexed_table_of_8_bit_values_01A2D2 ((const uint8_t *)indexed_table_of_8_bit_values_01A2D2_data)
#define indexed_table_of_8_bit_values_01A3C0_ADDRESS 0x01A3C0u
extern const void *indexed_table_of_8_bit_values_01A3C0_data;
#define indexed_table_of_8_bit_values_01A3C0 ((const uint8_t *)indexed_table_of_8_bit_values_01A3C0_data)
#define indexed_table_of_32_bit_values_01A88C_ADDRESS 0x01A88Cu
extern const void *indexed_table_of_32_bit_values_01A88C_data;
#define indexed_table_of_32_bit_values_01A88C ((const uint32_t *)indexed_table_of_32_bit_values_01A88C_data)
#define indexed_table_of_32_bit_values_01AC9A_ADDRESS 0x01AC9Au
extern const void *indexed_table_of_32_bit_values_01AC9A_data;
#define indexed_table_of_32_bit_values_01AC9A ((const uint32_t *)indexed_table_of_32_bit_values_01AC9A_data)
#define indexed_table_of_32_bit_values_01B714_ADDRESS 0x01B714u
extern const void *indexed_table_of_32_bit_values_01B714_data;
#define indexed_table_of_32_bit_values_01B714 ((const uint32_t *)indexed_table_of_32_bit_values_01B714_data)
#define indexed_table_of_32_bit_values_01BA88_ADDRESS 0x01BA88u
extern const void *indexed_table_of_32_bit_values_01BA88_data;
#define indexed_table_of_32_bit_values_01BA88 ((const uint32_t *)indexed_table_of_32_bit_values_01BA88_data)
#define indexed_table_of_16_bit_values_01C072_ADDRESS 0x01C072u
extern const void *indexed_table_of_16_bit_values_01C072_data;
#define indexed_table_of_16_bit_values_01C072 ((const uint16_t *)indexed_table_of_16_bit_values_01C072_data)
#define rom_01C074_ADDRESS 0x01C074u
extern const void *rom_01C074_data;
#define rom_01C074 ((const uint32_t *)rom_01C074_data)
#define animations_01C08A_ADDRESS 0x01C08Au
extern const void *animations_01C08A_data;
#define animations_01C08A ((const uint32_t *)animations_01C08A_data)
#define indexed_table_of_8_bit_values_01C20E_ADDRESS 0x01C20Eu
extern const void *indexed_table_of_8_bit_values_01C20E_data;
#define indexed_table_of_8_bit_values_01C20E ((const uint8_t *)indexed_table_of_8_bit_values_01C20E_data)
#define indexed_table_of_32_bit_values_01C272_ADDRESS 0x01C272u
extern const void *indexed_table_of_32_bit_values_01C272_data;
#define indexed_table_of_32_bit_values_01C272 ((const uint32_t *)indexed_table_of_32_bit_values_01C272_data)
#define table_loaded_by_lea_01C546_ADDRESS 0x01C546u
extern const void *table_loaded_by_lea_01C546_data;
#define table_loaded_by_lea_01C546 (*(const uint16_t *)table_loaded_by_lea_01C546_data)
#define rom_01C596_ADDRESS 0x01C596u
extern const void *rom_01C596_data;
#define rom_01C596 ((const uint16_t *)rom_01C596_data)
#define indexed_table_of_32_bit_values_01C678_ADDRESS 0x01C678u
extern const void *indexed_table_of_32_bit_values_01C678_data;
#define indexed_table_of_32_bit_values_01C678 ((const uint32_t *)indexed_table_of_32_bit_values_01C678_data)
#define indexed_table_of_32_bit_values_01C764_ADDRESS 0x01C764u
extern const void *indexed_table_of_32_bit_values_01C764_data;
#define indexed_table_of_32_bit_values_01C764 ((const uint32_t *)indexed_table_of_32_bit_values_01C764_data)
#define indexed_table_of_32_bit_values_01C7D0_ADDRESS 0x01C7D0u
extern const void *indexed_table_of_32_bit_values_01C7D0_data;
#define indexed_table_of_32_bit_values_01C7D0 ((const uint32_t *)indexed_table_of_32_bit_values_01C7D0_data)
#define indexed_table_of_32_bit_values_01C8CA_ADDRESS 0x01C8CAu
extern const void *indexed_table_of_32_bit_values_01C8CA_data;
#define indexed_table_of_32_bit_values_01C8CA ((const uint32_t *)indexed_table_of_32_bit_values_01C8CA_data)
#define indexed_table_of_32_bit_values_01C8F8_ADDRESS 0x01C8F8u
extern const void *indexed_table_of_32_bit_values_01C8F8_data;
#define indexed_table_of_32_bit_values_01C8F8 ((const uint32_t *)indexed_table_of_32_bit_values_01C8F8_data)
#define indexed_table_of_32_bit_values_01CA82_ADDRESS 0x01CA82u
extern const void *indexed_table_of_32_bit_values_01CA82_data;
#define indexed_table_of_32_bit_values_01CA82 ((const uint32_t *)indexed_table_of_32_bit_values_01CA82_data)
#define indexed_table_of_32_bit_values_01CAC2_ADDRESS 0x01CAC2u
extern const void *indexed_table_of_32_bit_values_01CAC2_data;
#define indexed_table_of_32_bit_values_01CAC2 ((const uint32_t *)indexed_table_of_32_bit_values_01CAC2_data)
#define indexed_table_of_32_bit_values_01CC6E_ADDRESS 0x01CC6Eu
extern const void *indexed_table_of_32_bit_values_01CC6E_data;
#define indexed_table_of_32_bit_values_01CC6E ((const uint32_t *)indexed_table_of_32_bit_values_01CC6E_data)
#define indexed_table_of_32_bit_values_01CCAA_ADDRESS 0x01CCAAu
extern const void *indexed_table_of_32_bit_values_01CCAA_data;
#define indexed_table_of_32_bit_values_01CCAA ((const uint32_t *)indexed_table_of_32_bit_values_01CCAA_data)
#define indexed_table_of_32_bit_values_01CD44_ADDRESS 0x01CD44u
extern const void *indexed_table_of_32_bit_values_01CD44_data;
#define indexed_table_of_32_bit_values_01CD44 ((const uint32_t *)indexed_table_of_32_bit_values_01CD44_data)
#define indexed_table_of_32_bit_values_01CDBC_ADDRESS 0x01CDBCu
extern const void *indexed_table_of_32_bit_values_01CDBC_data;
#define indexed_table_of_32_bit_values_01CDBC ((const uint32_t *)indexed_table_of_32_bit_values_01CDBC_data)
#define indexed_table_of_32_bit_values_01CE52_ADDRESS 0x01CE52u
extern const void *indexed_table_of_32_bit_values_01CE52_data;
#define indexed_table_of_32_bit_values_01CE52 ((const uint32_t *)indexed_table_of_32_bit_values_01CE52_data)
#define indexed_table_of_32_bit_values_01CF4E_ADDRESS 0x01CF4Eu
extern const void *indexed_table_of_32_bit_values_01CF4E_data;
#define indexed_table_of_32_bit_values_01CF4E ((const uint32_t *)indexed_table_of_32_bit_values_01CF4E_data)
#define indexed_table_of_32_bit_values_01D028_ADDRESS 0x01D028u
extern const void *indexed_table_of_32_bit_values_01D028_data;
#define indexed_table_of_32_bit_values_01D028 ((const uint32_t *)indexed_table_of_32_bit_values_01D028_data)
#define indexed_table_of_32_bit_values_01D100_ADDRESS 0x01D100u
extern const void *indexed_table_of_32_bit_values_01D100_data;
#define indexed_table_of_32_bit_values_01D100 ((const uint32_t *)indexed_table_of_32_bit_values_01D100_data)
#define indexed_table_of_8_bit_values_01D200_ADDRESS 0x01D200u
extern const void *indexed_table_of_8_bit_values_01D200_data;
#define indexed_table_of_8_bit_values_01D200 ((const uint8_t *)indexed_table_of_8_bit_values_01D200_data)
#define rom_01D3FC_ADDRESS 0x01D3FCu
extern const void *rom_01D3FC_data;
#define rom_01D3FC ((const uint8_t *)rom_01D3FC_data)
#define indexed_table_of_8_bit_values_01D526_ADDRESS 0x01D526u
extern const void *indexed_table_of_8_bit_values_01D526_data;
#define indexed_table_of_8_bit_values_01D526 ((const uint8_t *)indexed_table_of_8_bit_values_01D526_data)
#define rom_01D556_ADDRESS 0x01D556u
extern const void *rom_01D556_data;
#define rom_01D556 ((const uint8_t *)rom_01D556_data)
#define rom_01D592_ADDRESS 0x01D592u
extern const void *rom_01D592_data;
#define rom_01D592 ((const uint16_t *)rom_01D592_data)
#define rom_01D5F2_ADDRESS 0x01D5F2u
extern const void *rom_01D5F2_data;
#define rom_01D5F2 ((const uint32_t *)rom_01D5F2_data)
#define indexed_table_of_32_bit_values_01E2DA_ADDRESS 0x01E2DAu
extern const void *indexed_table_of_32_bit_values_01E2DA_data;
#define indexed_table_of_32_bit_values_01E2DA ((const uint32_t *)indexed_table_of_32_bit_values_01E2DA_data)
#define area_layers_ADDRESS 0x01E5A0u
extern const void *area_layers_data;
#define area_layers ((const uint32_t *)area_layers_data)
#define rom_01E5A4_ADDRESS 0x01E5A4u
extern const void *rom_01E5A4_data;
#define rom_01E5A4 ((const uint32_t *)rom_01E5A4_data)
#define rom_01E5A8_ADDRESS 0x01E5A8u
extern const void *rom_01E5A8_data;
#define rom_01E5A8 ((const uint32_t *)rom_01E5A8_data)
#define rom_01E5AC_ADDRESS 0x01E5ACu
extern const void *rom_01E5AC_data;
#define rom_01E5AC ((const uint32_t *)rom_01E5AC_data)
#define rom_01E5B0_ADDRESS 0x01E5B0u
extern const void *rom_01E5B0_data;
#define rom_01E5B0 ((const uint32_t *)rom_01E5B0_data)
#define rom_01E5B4_ADDRESS 0x01E5B4u
extern const void *rom_01E5B4_data;
#define rom_01E5B4 ((const uint32_t *)rom_01E5B4_data)
#define rom_01E5B8_ADDRESS 0x01E5B8u
extern const void *rom_01E5B8_data;
#define rom_01E5B8 ((const uint32_t *)rom_01E5B8_data)
#define rom_01E5BC_ADDRESS 0x01E5BCu
extern const void *rom_01E5BC_data;
#define rom_01E5BC ((const uint32_t *)rom_01E5BC_data)
#define rom_01E5C0_ADDRESS 0x01E5C0u
extern const void *rom_01E5C0_data;
#define rom_01E5C0 ((const uint16_t *)rom_01E5C0_data)
#define rom_01E5C2_ADDRESS 0x01E5C2u
extern const void *rom_01E5C2_data;
#define rom_01E5C2 ((const uint16_t *)rom_01E5C2_data)
#define indexed_table_of_32_bit_values_01ECEC_ADDRESS 0x01ECECu
extern const void *indexed_table_of_32_bit_values_01ECEC_data;
#define indexed_table_of_32_bit_values_01ECEC ((const uint32_t *)indexed_table_of_32_bit_values_01ECEC_data)
#define indexed_table_of_32_bit_values_01F43A_ADDRESS 0x01F43Au
extern const void *indexed_table_of_32_bit_values_01F43A_data;
#define indexed_table_of_32_bit_values_01F43A ((const uint32_t *)indexed_table_of_32_bit_values_01F43A_data)
#define indexed_table_of_32_bit_values_01F82C_ADDRESS 0x01F82Cu
extern const void *indexed_table_of_32_bit_values_01F82C_data;
#define indexed_table_of_32_bit_values_01F82C ((const uint32_t *)indexed_table_of_32_bit_values_01F82C_data)
#define indexed_table_of_32_bit_values_01FC96_ADDRESS 0x01FC96u
extern const void *indexed_table_of_32_bit_values_01FC96_data;
#define indexed_table_of_32_bit_values_01FC96 ((const uint32_t *)indexed_table_of_32_bit_values_01FC96_data)
#define fire_tiles_ADDRESS 0x0200F2u
extern const void *fire_tiles_data;
#define fire_tiles ((const uint32_t *)fire_tiles_data)
#define fire_tiles_area_0_ADDRESS 0x0203D2u
extern const void *fire_tiles_area_0_data;
#define fire_tiles_area_0 ((const uint32_t *)fire_tiles_area_0_data)
#define area_scroll_segments_ADDRESS 0x0205F2u
extern const void *area_scroll_segments_data;
#define area_scroll_segments ((const uint32_t *)area_scroll_segments_data)
#define animations_0208C0_ADDRESS 0x0208C0u
extern const void *animations_0208C0_data;
#define animations_0208C0 ((const uint32_t *)animations_0208C0_data)
#define indexed_table_of_32_bit_values_02B2C6_ADDRESS 0x02B2C6u
extern const void *indexed_table_of_32_bit_values_02B2C6_data;
#define indexed_table_of_32_bit_values_02B2C6 ((const uint32_t *)indexed_table_of_32_bit_values_02B2C6_data)
#define indexed_table_of_32_bit_values_02B62A_ADDRESS 0x02B62Au
extern const void *indexed_table_of_32_bit_values_02B62A_data;
#define indexed_table_of_32_bit_values_02B62A ((const uint32_t *)indexed_table_of_32_bit_values_02B62A_data)
#define indexed_table_of_32_bit_values_02B728_ADDRESS 0x02B728u
extern const void *indexed_table_of_32_bit_values_02B728_data;
#define indexed_table_of_32_bit_values_02B728 ((const uint32_t *)indexed_table_of_32_bit_values_02B728_data)
#define indexed_table_of_32_bit_values_02BB16_ADDRESS 0x02BB16u
extern const void *indexed_table_of_32_bit_values_02BB16_data;
#define indexed_table_of_32_bit_values_02BB16 ((const uint32_t *)indexed_table_of_32_bit_values_02BB16_data)
#define animations_02BC56_ADDRESS 0x02BC56u
extern const void *animations_02BC56_data;
#define animations_02BC56 ((const uint32_t *)animations_02BC56_data)
#define indexed_table_of_32_bit_values_02BC98_ADDRESS 0x02BC98u
extern const void *indexed_table_of_32_bit_values_02BC98_data;
#define indexed_table_of_32_bit_values_02BC98 ((const uint32_t *)indexed_table_of_32_bit_values_02BC98_data)
#define indexed_table_of_32_bit_values_02BD44_ADDRESS 0x02BD44u
extern const void *indexed_table_of_32_bit_values_02BD44_data;
#define indexed_table_of_32_bit_values_02BD44 ((const uint32_t *)indexed_table_of_32_bit_values_02BD44_data)
#define indexed_table_of_32_bit_values_02BF10_ADDRESS 0x02BF10u
extern const void *indexed_table_of_32_bit_values_02BF10_data;
#define indexed_table_of_32_bit_values_02BF10 ((const uint32_t *)indexed_table_of_32_bit_values_02BF10_data)
#define indexed_table_of_32_bit_values_02C04C_ADDRESS 0x02C04Cu
extern const void *indexed_table_of_32_bit_values_02C04C_data;
#define indexed_table_of_32_bit_values_02C04C ((const uint32_t *)indexed_table_of_32_bit_values_02C04C_data)
#define indexed_table_of_16_bit_values_02C0F0_ADDRESS 0x02C0F0u
extern const void *indexed_table_of_16_bit_values_02C0F0_data;
#define indexed_table_of_16_bit_values_02C0F0 ((const uint16_t *)indexed_table_of_16_bit_values_02C0F0_data)
#define rom_02C0F2_ADDRESS 0x02C0F2u
extern const void *rom_02C0F2_data;
#define rom_02C0F2 ((const uint16_t *)rom_02C0F2_data)
#define indexed_table_of_16_bit_values_02C3BA_ADDRESS 0x02C3BAu
extern const void *indexed_table_of_16_bit_values_02C3BA_data;
#define indexed_table_of_16_bit_values_02C3BA ((const uint16_t *)indexed_table_of_16_bit_values_02C3BA_data)
#define rom_02C3BC_ADDRESS 0x02C3BCu
extern const void *rom_02C3BC_data;
#define rom_02C3BC ((const uint16_t *)rom_02C3BC_data)
#define indexed_table_of_32_bit_values_02C93A_ADDRESS 0x02C93Au
extern const void *indexed_table_of_32_bit_values_02C93A_data;
#define indexed_table_of_32_bit_values_02C93A ((const uint32_t *)indexed_table_of_32_bit_values_02C93A_data)
#define indexed_table_of_16_bit_values_02CE62_ADDRESS 0x02CE62u
extern const void *indexed_table_of_16_bit_values_02CE62_data;
#define indexed_table_of_16_bit_values_02CE62 ((const uint16_t *)indexed_table_of_16_bit_values_02CE62_data)
#define rom_02CE64_ADDRESS 0x02CE64u
extern const void *rom_02CE64_data;
#define rom_02CE64 ((const uint16_t *)rom_02CE64_data)
#define indexed_table_of_32_bit_values_02CE8E_ADDRESS 0x02CE8Eu
extern const void *indexed_table_of_32_bit_values_02CE8E_data;
#define indexed_table_of_32_bit_values_02CE8E ((const uint32_t *)indexed_table_of_32_bit_values_02CE8E_data)
#define indexed_table_of_16_bit_values_02D304_ADDRESS 0x02D304u
extern const void *indexed_table_of_16_bit_values_02D304_data;
#define indexed_table_of_16_bit_values_02D304 ((const uint16_t *)indexed_table_of_16_bit_values_02D304_data)
#define rom_02D306_ADDRESS 0x02D306u
extern const void *rom_02D306_data;
#define rom_02D306 ((const uint16_t *)rom_02D306_data)
#define rom_02D308_ADDRESS 0x02D308u
extern const void *rom_02D308_data;
#define rom_02D308 ((const uint16_t *)rom_02D308_data)
#define rom_02D30A_ADDRESS 0x02D30Au
extern const void *rom_02D30A_data;
#define rom_02D30A ((const uint16_t *)rom_02D30A_data)
#define animations_02D4F4_ADDRESS 0x02D4F4u
extern const void *animations_02D4F4_data;
#define animations_02D4F4 ((const uint32_t *)animations_02D4F4_data)
#define indexed_table_of_32_bit_values_02D616_ADDRESS 0x02D616u
extern const void *indexed_table_of_32_bit_values_02D616_data;
#define indexed_table_of_32_bit_values_02D616 ((const uint32_t *)indexed_table_of_32_bit_values_02D616_data)
#define indexed_table_of_32_bit_values_02F654_ADDRESS 0x02F654u
extern const void *indexed_table_of_32_bit_values_02F654_data;
#define indexed_table_of_32_bit_values_02F654 ((const uint32_t *)indexed_table_of_32_bit_values_02F654_data)
#define indexed_table_of_32_bit_values_02F8C6_ADDRESS 0x02F8C6u
extern const void *indexed_table_of_32_bit_values_02F8C6_data;
#define indexed_table_of_32_bit_values_02F8C6 ((const uint32_t *)indexed_table_of_32_bit_values_02F8C6_data)
#define indexed_table_of_16_bit_values_02FBE0_ADDRESS 0x02FBE0u
extern const void *indexed_table_of_16_bit_values_02FBE0_data;
#define indexed_table_of_16_bit_values_02FBE0 ((const uint16_t *)indexed_table_of_16_bit_values_02FBE0_data)
#define indexed_table_of_32_bit_values_0303EE_ADDRESS 0x0303EEu
extern const void *indexed_table_of_32_bit_values_0303EE_data;
#define indexed_table_of_32_bit_values_0303EE ((const uint32_t *)indexed_table_of_32_bit_values_0303EE_data)
#define indexed_table_of_8_bit_values_030652_ADDRESS 0x030652u
extern const void *indexed_table_of_8_bit_values_030652_data;
#define indexed_table_of_8_bit_values_030652 ((const uint8_t *)indexed_table_of_8_bit_values_030652_data)
#define rom_030653_ADDRESS 0x030653u
extern const void *rom_030653_data;
#define rom_030653 ((const uint8_t *)rom_030653_data)
#define indexed_table_of_32_bit_values_030996_ADDRESS 0x030996u
extern const void *indexed_table_of_32_bit_values_030996_data;
#define indexed_table_of_32_bit_values_030996 ((const uint32_t *)indexed_table_of_32_bit_values_030996_data)
#define indexed_table_of_32_bit_values_031152_ADDRESS 0x031152u
extern const void *indexed_table_of_32_bit_values_031152_data;
#define indexed_table_of_32_bit_values_031152 ((const uint32_t *)indexed_table_of_32_bit_values_031152_data)
#define attack_check_objects_ADDRESS 0x0471F4u
extern const void *attack_check_objects_data;
#define attack_check_objects ((const uint32_t *)attack_check_objects_data)
#define object_group_counts_ADDRESS 0x047BDEu
extern const void *object_group_counts_data;
#define object_group_counts ((const uint8_t *)object_group_counts_data)
#define object_groups_ADDRESS 0x047BE2u
extern const void *object_groups_data;
#define object_groups ((const uint32_t *)object_groups_data)
#define rom_04881C_ADDRESS 0x04881Cu
extern const void *rom_04881C_data;
#define rom_04881C ((const uint16_t *)rom_04881C_data)
#define rom_048830_ADDRESS 0x048830u
extern const void *rom_048830_data;
#define rom_048830 ((const uint8_t *)rom_048830_data)
#define indexed_table_of_8_bit_values_048C5E_ADDRESS 0x048C5Eu
extern const void *indexed_table_of_8_bit_values_048C5E_data;
#define indexed_table_of_8_bit_values_048C5E ((const uint8_t *)indexed_table_of_8_bit_values_048C5E_data)
#define animations_04A8A4_ADDRESS 0x04A8A4u
extern const void *animations_04A8A4_data;
#define animations_04A8A4 ((const uint32_t *)animations_04A8A4_data)
#define rom_04B7DE_ADDRESS 0x04B7DEu
extern const void *rom_04B7DE_data;
#define rom_04B7DE ((const uint16_t *)rom_04B7DE_data)
#define animations_04BFD6_ADDRESS 0x04BFD6u
extern const void *animations_04BFD6_data;
#define animations_04BFD6 ((const uint32_t *)animations_04BFD6_data)
#define rom_04BFDA_ADDRESS 0x04BFDAu
extern const void *rom_04BFDA_data;
#define rom_04BFDA ((const uint32_t *)rom_04BFDA_data)
#define indexed_table_of_8_bit_values_04C3EE_ADDRESS 0x04C3EEu
extern const void *indexed_table_of_8_bit_values_04C3EE_data;
#define indexed_table_of_8_bit_values_04C3EE ((const uint8_t *)indexed_table_of_8_bit_values_04C3EE_data)
#define rom_04D764_ADDRESS 0x04D764u
extern const void *rom_04D764_data;
#define rom_04D764 ((const uint8_t *)rom_04D764_data)
#define indexed_table_of_8_bit_values_04DD2C_ADDRESS 0x04DD2Cu
extern const void *indexed_table_of_8_bit_values_04DD2C_data;
#define indexed_table_of_8_bit_values_04DD2C ((const uint8_t *)indexed_table_of_8_bit_values_04DD2C_data)
#define indexed_table_of_8_bit_values_04EFD0_ADDRESS 0x04EFD0u
extern const void *indexed_table_of_8_bit_values_04EFD0_data;
#define indexed_table_of_8_bit_values_04EFD0 ((const uint8_t *)indexed_table_of_8_bit_values_04EFD0_data)
#define animations_04EFD4_ADDRESS 0x04EFD4u
extern const void *animations_04EFD4_data;
#define animations_04EFD4 ((const uint32_t *)animations_04EFD4_data)
#define indexed_table_of_32_bit_values_04EFE0_ADDRESS 0x04EFE0u
extern const void *indexed_table_of_32_bit_values_04EFE0_data;
#define indexed_table_of_32_bit_values_04EFE0 ((const uint32_t *)indexed_table_of_32_bit_values_04EFE0_data)
#define indexed_table_of_16_bit_values_04F58C_ADDRESS 0x04F58Cu
extern const void *indexed_table_of_16_bit_values_04F58C_data;
#define indexed_table_of_16_bit_values_04F58C ((const uint16_t *)indexed_table_of_16_bit_values_04F58C_data)
#define rom_04F58E_ADDRESS 0x04F58Eu
extern const void *rom_04F58E_data;
#define rom_04F58E ((const uint16_t *)rom_04F58E_data)
#define rom_04F5B4_ADDRESS 0x04F5B4u
extern const void *rom_04F5B4_data;
#define rom_04F5B4 ((const uint8_t *)rom_04F5B4_data)
#define rom_04F5C4_ADDRESS 0x04F5C4u
extern const void *rom_04F5C4_data;
#define rom_04F5C4 ((const uint8_t *)rom_04F5C4_data)
#define rom_04F5CC_ADDRESS 0x04F5CCu
extern const void *rom_04F5CC_data;
#define rom_04F5CC ((const uint8_t *)rom_04F5CC_data)
#define indexed_table_of_8_bit_values_04F6B6_ADDRESS 0x04F6B6u
extern const void *indexed_table_of_8_bit_values_04F6B6_data;
#define indexed_table_of_8_bit_values_04F6B6 ((const uint8_t *)indexed_table_of_8_bit_values_04F6B6_data)
#define animations_04F9DA_ADDRESS 0x04F9DAu
extern const void *animations_04F9DA_data;
#define animations_04F9DA ((const uint32_t *)animations_04F9DA_data)
#define indexed_table_of_32_bit_values_04F9DE_ADDRESS 0x04F9DEu
extern const void *indexed_table_of_32_bit_values_04F9DE_data;
#define indexed_table_of_32_bit_values_04F9DE ((const uint32_t *)indexed_table_of_32_bit_values_04F9DE_data)
#define animations_04FE56_ADDRESS 0x04FE56u
extern const void *animations_04FE56_data;
#define animations_04FE56 ((const uint32_t *)animations_04FE56_data)
#define animations_04FEBE_ADDRESS 0x04FEBEu
extern const void *animations_04FEBE_data;
#define animations_04FEBE ((const uint32_t *)animations_04FEBE_data)
#define animations_04FEF6_ADDRESS 0x04FEF6u
extern const void *animations_04FEF6_data;
#define animations_04FEF6 ((const uint32_t *)animations_04FEF6_data)
#define animations_050692_ADDRESS 0x050692u
extern const void *animations_050692_data;
#define animations_050692 ((const uint32_t *)animations_050692_data)
#define animations_05101E_ADDRESS 0x05101Eu
extern const void *animations_05101E_data;
#define animations_05101E ((const uint32_t *)animations_05101E_data)
#define indexed_table_of_16_bit_values_05102A_ADDRESS 0x05102Au
extern const void *indexed_table_of_16_bit_values_05102A_data;
#define indexed_table_of_16_bit_values_05102A ((const uint16_t *)indexed_table_of_16_bit_values_05102A_data)
#define rom_05102C_ADDRESS 0x05102Cu
extern const void *rom_05102C_data;
#define rom_05102C ((const uint16_t *)rom_05102C_data)
#define rom_051036_ADDRESS 0x051036u
extern const void *rom_051036_data;
#define rom_051036 ((const uint8_t *)rom_051036_data)
#define animations_0518CC_ADDRESS 0x0518CCu
extern const void *animations_0518CC_data;
#define animations_0518CC ((const uint32_t *)animations_0518CC_data)
#define animations_051AE2_ADDRESS 0x051AE2u
extern const void *animations_051AE2_data;
#define animations_051AE2 ((const uint32_t *)animations_051AE2_data)
#define table_loaded_by_lea_051AEE_ADDRESS 0x051AEEu
extern const void *table_loaded_by_lea_051AEE_data;
#define table_loaded_by_lea_051AEE ((const uint8_t *)table_loaded_by_lea_051AEE_data)
#define rom_051F9C_ADDRESS 0x051F9Cu
extern const void *rom_051F9C_data;
#define rom_051F9C ((const uint8_t *)rom_051F9C_data)
#define indexed_table_of_8_bit_values_052918_ADDRESS 0x052918u
extern const void *indexed_table_of_8_bit_values_052918_data;
#define indexed_table_of_8_bit_values_052918 ((const uint8_t *)indexed_table_of_8_bit_values_052918_data)
#define indexed_table_of_8_bit_values_052A60_ADDRESS 0x052A60u
extern const void *indexed_table_of_8_bit_values_052A60_data;
#define indexed_table_of_8_bit_values_052A60 ((const uint8_t *)indexed_table_of_8_bit_values_052A60_data)
#define rom_052ADE_ADDRESS 0x052ADEu
extern const void *rom_052ADE_data;
#define rom_052ADE ((const uint8_t *)rom_052ADE_data)
#define indexed_table_of_16_bit_values_052B3A_ADDRESS 0x052B3Au
extern const void *indexed_table_of_16_bit_values_052B3A_data;
#define indexed_table_of_16_bit_values_052B3A ((const uint16_t *)indexed_table_of_16_bit_values_052B3A_data)
#define indexed_table_of_16_bit_values_052B7C_ADDRESS 0x052B7Cu
extern const void *indexed_table_of_16_bit_values_052B7C_data;
#define indexed_table_of_16_bit_values_052B7C ((const uint16_t *)indexed_table_of_16_bit_values_052B7C_data)
#define rom_053896_ADDRESS 0x053896u
extern const void *rom_053896_data;
#define rom_053896 ((const uint32_t *)rom_053896_data)

/* the board's registers (read and written through the bus) */
#define PALETTE_08000D 0x08000Du
#define PALETTE_08000F 0x08000Fu
#define IO_0A0001 0x0A0001u
#define IO_0A0003 0x0A0003u
#define IO_0A0005 0x0A0005u
#define IO_0A0007 0x0A0007u
#define IO_0A0009 0x0A0009u
#define IO_0A0011 0x0A0011u
#define IO_0A0013 0x0A0013u
#define IO_0A0015 0x0A0015u
#define IO_0A0019 0x0A0019u
#define PRIORITY_0C0001 0x0C0001u
#define TILES_10032E 0x10032Eu
#define TILES_10032F 0x10032Fu
#define TILES_100340 0x100340u
#define TILES_100341 0x100341u
#define TILES_100838 0x100838u
#define TILES_100839 0x100839u
#define TILES_102030 0x102030u
#define TILES_1027A9 0x1027A9u
#define TILES_102EAE 0x102EAEu
#define TILES_102EAF 0x102EAFu
#define TILES_102EB8 0x102EB8u
#define TILES_102EB9 0x102EB9u
#define TILES_106018 0x106018u
#define TILES_106019 0x106019u
#define TILES_106400 0x106400u
#define TILES_106401 0x106401u
#define TILES_106402 0x106402u
#define TILES_106403 0x106403u
#define TILES_106900 0x106900u
#define TILES_106B00 0x106B00u
#define TILES_106C00 0x106C00u
#define TILES_106D00 0x106D00u
#define TILES_106E00 0x106E00u
#define UNMAPPED_10E801 0x10E801u
#define SPRITE_CONTROL_140000 0x140000u
#define SPRITE_CONTROL_140001 0x140001u
#define SPRITE_CONTROL_140002 0x140002u
#define SPRITE_CONTROL_140003 0x140003u
#define SPRITE_CONTROL_140004 0x140004u
#define SPRITE_CONTROL_140005 0x140005u
#define SPRITE_CONTROL_140006 0x140006u
#define SPRITE_CONTROL_140007 0x140007u

/* data in the program symbols.txt and the assets label */
#define vectors_000000_ADDRESS 0x000000u
#define table_loaded_by_lea_00191E_ADDRESS 0x00191Eu
#define indexed_table_of_32_bit_values_001958_ADDRESS 0x001958u
#define table_loaded_by_lea_001E34_ADDRESS 0x001E34u
#define unexplained_002030_ADDRESS 0x002030u
#define table_loaded_by_lea_0020EC_ADDRESS 0x0020ECu
#define table_loaded_by_lea_0021EE_ADDRESS 0x0021EEu
#define big_font_tiles_ADDRESS 0x002806u
#define game_texts_ADDRESS 0x00292Au
#define unexplained_002989_ADDRESS 0x002989u
#define texts_00298A_ADDRESS 0x00298Au
#define unexplained_002999_ADDRESS 0x002999u
#define texts_00299A_ADDRESS 0x00299Au
#define unexplained_0029E5_ADDRESS 0x0029E5u
#define texts_0029E6_ADDRESS 0x0029E6u
#define unexplained_002AC7_ADDRESS 0x002AC7u
#define texts_002AC8_ADDRESS 0x002AC8u
#define unexplained_002AD3_ADDRESS 0x002AD3u
#define texts_002AD4_ADDRESS 0x002AD4u
#define unexplained_002AF7_ADDRESS 0x002AF7u
#define texts_002AF8_ADDRESS 0x002AF8u
#define unexplained_002CFF_ADDRESS 0x002CFFu
#define texts_002D00_ADDRESS 0x002D00u
#define table_loaded_by_lea_002F26_ADDRESS 0x002F26u
#define demo_texts_ADDRESS 0x0030AEu
#define unexplained_0030EB_ADDRESS 0x0030EBu
#define texts_0030EC_ADDRESS 0x0030ECu
#define unexplained_0030FD_ADDRESS 0x0030FDu
#define texts_0030FE_ADDRESS 0x0030FEu
#define unexplained_00310D_ADDRESS 0x00310Du
#define texts_00310E_ADDRESS 0x00310Eu
#define unexplained_00311D_ADDRESS 0x00311Du
#define texts_00311E_ADDRESS 0x00311Eu
#define indexed_table_of_32_bit_values_00375C_ADDRESS 0x00375Cu
#define big_font_ADDRESS 0x00388Cu
#define channel_records_ADDRESS 0x0047C8u
#define indexed_table_of_32_bit_values_0049DA_ADDRESS 0x0049DAu
#define indexed_table_of_32_bit_values_0049F8_ADDRESS 0x0049F8u
#define indexed_table_of_32_bit_values_004AB4_ADDRESS 0x004AB4u
#define indexed_table_of_16_bit_values_004B58_ADDRESS 0x004B58u
#define indexed_table_of_32_bit_values_004B88_ADDRESS 0x004B88u
#define table_loaded_by_lea_004C76_ADDRESS 0x004C76u
#define indexed_table_of_32_bit_values_004CD2_ADDRESS 0x004CD2u
#define indexed_table_of_32_bit_values_004EE8_ADDRESS 0x004EE8u
#define indexed_table_of_32_bit_values_004F06_ADDRESS 0x004F06u
#define indexed_table_of_32_bit_values_005000_ADDRESS 0x005000u
#define table_loaded_by_lea_005078_ADDRESS 0x005078u
#define indexed_table_of_32_bit_values_0051CE_ADDRESS 0x0051CEu
#define unexplained_00525A_ADDRESS 0x00525Au
#define table_loaded_by_lea_005294_ADDRESS 0x005294u
#define demos_0052D4_ADDRESS 0x0052D4u
#define indexed_table_of_32_bit_values_00569E_ADDRESS 0x00569Eu
#define indexed_table_of_32_bit_values_0056D8_ADDRESS 0x0056D8u
#define indexed_table_of_32_bit_values_005736_ADDRESS 0x005736u
#define indexed_table_of_32_bit_values_005794_ADDRESS 0x005794u
#define table_loaded_by_lea_005846_ADDRESS 0x005846u
#define indexed_table_of_32_bit_values_00586A_ADDRESS 0x00586Au
#define table_loaded_by_lea_005896_ADDRESS 0x005896u
#define indexed_table_of_32_bit_values_005A12_ADDRESS 0x005A12u
#define table_loaded_by_lea_005A58_ADDRESS 0x005A58u
#define indexed_table_of_32_bit_values_005B5E_ADDRESS 0x005B5Eu
#define table_loaded_by_lea_005B9C_ADDRESS 0x005B9Cu
#define indexed_table_of_32_bit_values_005C32_ADDRESS 0x005C32u
#define table_loaded_by_lea_005C5E_ADDRESS 0x005C5Eu
#define test_mode_texts_ADDRESS 0x005E1Eu
#define unexplained_005E8D_ADDRESS 0x005E8Du
#define texts_005E8E_ADDRESS 0x005E8Eu
#define unexplained_006021_ADDRESS 0x006021u
#define texts_006022_ADDRESS 0x006022u
#define unexplained_006035_ADDRESS 0x006035u
#define texts_006036_ADDRESS 0x006036u
#define unexplained_006049_ADDRESS 0x006049u
#define texts_00604A_ADDRESS 0x00604Au
#define unexplained_00605D_ADDRESS 0x00605Du
#define texts_00605E_ADDRESS 0x00605Eu
#define unexplained_00611D_ADDRESS 0x00611Du
#define texts_00611E_ADDRESS 0x00611Eu
#define indexed_table_of_32_bit_values_0061E8_ADDRESS 0x0061E8u
#define indexed_table_of_32_bit_values_006282_ADDRESS 0x006282u
#define indexed_table_of_32_bit_values_0062E2_ADDRESS 0x0062E2u
#define indexed_table_of_32_bit_values_0063A0_ADDRESS 0x0063A0u
#define indexed_table_of_32_bit_values_0063D8_ADDRESS 0x0063D8u
#define indexed_table_of_32_bit_values_0064C6_ADDRESS 0x0064C6u
#define indexed_table_of_32_bit_values_006688_ADDRESS 0x006688u
#define indexed_table_of_32_bit_values_0066A6_ADDRESS 0x0066A6u
#define indexed_table_of_8_bit_values_006B0C_ADDRESS 0x006B0Cu
#define indexed_table_of_32_bit_values_006B42_ADDRESS 0x006B42u
#define indexed_table_of_32_bit_values_006BFA_ADDRESS 0x006BFAu
#define indexed_table_of_32_bit_values_006C18_ADDRESS 0x006C18u
#define indexed_table_of_32_bit_values_006CDE_ADDRESS 0x006CDEu
#define indexed_table_of_32_bit_values_006EE6_ADDRESS 0x006EE6u
#define table_loaded_by_lea_007018_ADDRESS 0x007018u
#define indexed_table_of_32_bit_values_0070BE_ADDRESS 0x0070BEu
#define record_0071DC_ADDRESS 0x0071DCu
#define record_007276_ADDRESS 0x007276u
#define indexed_table_of_16_bit_values_00738C_ADDRESS 0x00738Cu
#define indexed_table_of_32_bit_values_00783A_ADDRESS 0x00783Au
#define indexed_table_of_32_bit_values_007860_ADDRESS 0x007860u
#define indexed_table_of_32_bit_values_0078F8_ADDRESS 0x0078F8u
#define indexed_table_of_32_bit_values_007A0E_ADDRESS 0x007A0Eu
#define indexed_table_of_32_bit_values_007B22_ADDRESS 0x007B22u
#define indexed_table_of_32_bit_values_007B58_ADDRESS 0x007B58u
#define indexed_table_of_8_bit_values_00807E_ADDRESS 0x00807Eu
#define table_loaded_by_lea_0082E6_ADDRESS 0x0082E6u
#define indexed_table_of_32_bit_values_0088F0_ADDRESS 0x0088F0u
#define indexed_table_of_32_bit_values_00890E_ADDRESS 0x00890Eu
#define indexed_table_of_32_bit_values_008A0A_ADDRESS 0x008A0Au
#define table_loaded_by_lea_008ABE_ADDRESS 0x008ABEu
#define table_loaded_by_lea_008BEA_ADDRESS 0x008BEAu
#define indexed_table_of_32_bit_values_008D12_ADDRESS 0x008D12u
#define indexed_table_of_32_bit_values_008D30_ADDRESS 0x008D30u
#define indexed_table_of_32_bit_values_008E6A_ADDRESS 0x008E6Au
#define indexed_table_of_32_bit_values_008E88_ADDRESS 0x008E88u
#define palettes_008F58_ADDRESS 0x008F58u
#define unexplained_008F7D_ADDRESS 0x008F7Du
#define indexed_table_of_32_bit_values_008F94_ADDRESS 0x008F94u
#define indexed_table_of_32_bit_values_009632_ADDRESS 0x009632u
#define table_loaded_by_lea_009872_ADDRESS 0x009872u
#define indexed_table_of_32_bit_values_0099F0_ADDRESS 0x0099F0u
#define table_loaded_by_lea_009C5C_ADDRESS 0x009C5Cu
#define indexed_table_of_8_bit_values_009D40_ADDRESS 0x009D40u
#define area_palettes_ADDRESS 0x009F56u
#define unexplained_00A1DE_ADDRESS 0x00A1DEu
#define palettes_00A1FE_ADDRESS 0x00A1FEu
#define unexplained_00B606_ADDRESS 0x00B606u
#define palettes_00B608_ADDRESS 0x00B608u
#define unexplained_00CD44_ADDRESS 0x00CD44u
#define palettes_00CD48_ADDRESS 0x00CD48u
#define unexplained_00CD68_ADDRESS 0x00CD68u
#define palettes_00CD6C_ADDRESS 0x00CD6Cu
#define unexplained_00CD8C_ADDRESS 0x00CD8Cu
#define palettes_00CD90_ADDRESS 0x00CD90u
#define unexplained_00CDB0_ADDRESS 0x00CDB0u
#define palettes_00CDB4_ADDRESS 0x00CDB4u
#define palette_effects_00D134_ADDRESS 0x00D134u
#define code_table_00DF5E_ADDRESS 0x00DF5Eu
#define table_loaded_by_lea_00E4FE_ADDRESS 0x00E4FEu
#define indexed_table_of_16_bit_values_00E750_ADDRESS 0x00E750u
#define code_table_00E956_ADDRESS 0x00E956u
#define code_table_00E9C6_ADDRESS 0x00E9C6u
#define indexed_table_of_16_bit_values_00EA9E_ADDRESS 0x00EA9Eu
#define code_table_00EB80_ADDRESS 0x00EB80u
#define animations_00EC98_ADDRESS 0x00EC98u
#define sprite_lists_00F03C_ADDRESS 0x00F03Cu
#define sprite_lists_00F6E8_ADDRESS 0x00F6E8u
#define sprite_lists_00F862_ADDRESS 0x00F862u
#define code_table_00F8D2_ADDRESS 0x00F8D2u
#define code_table_00FA14_ADDRESS 0x00FA14u
#define code_table_00FA60_ADDRESS 0x00FA60u
#define code_table_00FAA0_ADDRESS 0x00FAA0u
#define code_table_00FB9C_ADDRESS 0x00FB9Cu
#define code_table_00FCC8_ADDRESS 0x00FCC8u
#define code_table_00FDB6_ADDRESS 0x00FDB6u
#define code_table_00FED2_ADDRESS 0x00FED2u
#define code_table_010098_ADDRESS 0x010098u
#define code_table_0100FC_ADDRESS 0x0100FCu
#define code_table_0101E8_ADDRESS 0x0101E8u
#define code_table_0102F6_ADDRESS 0x0102F6u
#define code_table_010410_ADDRESS 0x010410u
#define code_table_01053C_ADDRESS 0x01053Cu
#define table_loaded_by_lea_010776_ADDRESS 0x010776u
#define code_table_0108C0_ADDRESS 0x0108C0u
#define code_table_01091A_ADDRESS 0x01091Au
#define code_table_0109C6_ADDRESS 0x0109C6u
#define code_table_010AD8_ADDRESS 0x010AD8u
#define code_table_010C4A_ADDRESS 0x010C4Au
#define code_table_010CCE_ADDRESS 0x010CCEu
#define indexed_table_of_8_bit_values_010D5A_ADDRESS 0x010D5Au
#define code_table_010E48_ADDRESS 0x010E48u
#define code_table_011080_ADDRESS 0x011080u
#define code_table_0110FE_ADDRESS 0x0110FEu
#define code_table_01128C_ADDRESS 0x01128Cu
#define code_table_011432_ADDRESS 0x011432u
#define code_table_011532_ADDRESS 0x011532u
#define indexed_table_of_8_bit_values_01175A_ADDRESS 0x01175Au
#define indexed_table_of_8_bit_values_011AD2_ADDRESS 0x011AD2u
#define table_loaded_by_lea_011C42_ADDRESS 0x011C42u
#define indexed_table_of_16_bit_values_011EB2_ADDRESS 0x011EB2u
#define code_table_011FC4_ADDRESS 0x011FC4u
#define code_table_0120A8_ADDRESS 0x0120A8u
#define code_table_01217C_ADDRESS 0x01217Cu
#define indexed_table_of_8_bit_values_012338_ADDRESS 0x012338u
#define table_loaded_by_lea_012486_ADDRESS 0x012486u
#define unexplained_012624_ADDRESS 0x012624u
#define code_table_012660_ADDRESS 0x012660u
#define code_table_0126FE_ADDRESS 0x0126FEu
#define code_table_012884_ADDRESS 0x012884u
#define code_table_01297C_ADDRESS 0x01297Cu
#define code_table_012A16_ADDRESS 0x012A16u
#define code_table_012BC4_ADDRESS 0x012BC4u
#define table_loaded_by_lea_012C10_ADDRESS 0x012C10u
#define code_table_012C76_ADDRESS 0x012C76u
#define code_table_012D32_ADDRESS 0x012D32u
#define indexed_table_of_8_bit_values_013150_ADDRESS 0x013150u
#define code_table_01326E_ADDRESS 0x01326Eu
#define code_table_0133E2_ADDRESS 0x0133E2u
#define indexed_table_of_8_bit_values_013486_ADDRESS 0x013486u
#define indexed_table_of_16_bit_values_013AE4_ADDRESS 0x013AE4u
#define indexed_table_of_16_bit_values_013B72_ADDRESS 0x013B72u
#define code_table_013C16_ADDRESS 0x013C16u
#define code_table_0142C2_ADDRESS 0x0142C2u
#define sprite_lists_015FE0_ADDRESS 0x015FE0u
#define record_0180FA_ADDRESS 0x0180FAu
#define hydrant_struck_stats_ADDRESS 0x018104u
#define hydrant_water_stats_ADDRESS 0x01810Eu
#define roadside_pole_stats_ADDRESS 0x018118u
#define alligator_stats_ADDRESS 0x018122u
#define billboard_stats_ADDRESS 0x01812Cu
#define oil_drum_stats_ADDRESS 0x01815Eu
#define explosion_stats_ADDRESS 0x018168u
#define skateboarder_stats_ADDRESS 0x018172u
#define turret_stats_ADDRESS 0x01817Cu
#define turret_struck_stats_ADDRESS 0x018186u
#define turret_shot_stats_ADDRESS 0x018190u
#define waiting_soldier_stats_ADDRESS 0x01819Au
#define inert_stats_ADDRESS 0x0181A4u
#define freeze_nozzle_stats_ADDRESS 0x0181AEu
#define electric_beam_stats_ADDRESS 0x0181C2u
#define rock_soldier_site_stats_ADDRESS 0x0181CCu
#define gun_blast_stats_ADDRESS 0x0181D6u
#define car_hit_box_stats_ADDRESS 0x0181E0u
#define electric_column_stats_ADDRESS 0x0181EAu
#define helicopter_stats_ADDRESS 0x0181FEu
#define copter_bullet_stats_ADDRESS 0x018208u
#define falling_missile_stats_ADDRESS 0x018212u
#define falling_missile_at_turtle_stats_ADDRESS 0x01821Cu
#define rock_soldier_technodrome_stats_ADDRESS 0x018226u
#define missile_stats_ADDRESS 0x018230u
#define wall_slab_stats_ADDRESS 0x01823Au
#define shock_bars_hit_box_stats_ADDRESS 0x018244u
#define sewer_missile_stats_ADDRESS 0x01824Eu
#define spiked_pole_stats_ADDRESS 0x018258u
#define flying_drone_stats_ADDRESS 0x018262u
#define drone_shot_stats_ADDRESS 0x01826Cu
#define roadside_cone_stats_ADDRESS 0x018276u
#define one_way_sign_stats_ADDRESS 0x018280u
#define stockman_stats_ADDRESS 0x01828Au
#define falling_mouser_stats_ADDRESS 0x018294u
#define ball_stats_ADDRESS 0x01829Eu
#define technodrome_ball_stats_ADDRESS 0x0182A8u
#define ball_dropper_stats_ADDRESS 0x0182B2u
#define road_barrier_stats_ADDRESS 0x0182BCu
#define tire_stack_stats_ADDRESS 0x0182C6u
#define krang_stats_ADDRESS 0x0182D0u
#define krang_laser_stats_ADDRESS 0x0182DAu
#define krang_fist_stats_ADDRESS 0x0182E4u
#define indexed_table_of_8_bit_values_018550_ADDRESS 0x018550u
#define tile_block_places_ADDRESS 0x0187BCu
#define unexplained_01948B_ADDRESS 0x01948Bu
#define texts_01948C_ADDRESS 0x01948Cu
#define unexplained_019577_ADDRESS 0x019577u
#define texts_019578_ADDRESS 0x019578u
#define unexplained_019657_ADDRESS 0x019657u
#define texts_019658_ADDRESS 0x019658u
#define unexplained_01977D_ADDRESS 0x01977Du
#define texts_01977E_ADDRESS 0x01977Eu
#define unexplained_0198C3_ADDRESS 0x0198C3u
#define texts_0198C4_ADDRESS 0x0198C4u
#define unexplained_0198FD_ADDRESS 0x0198FDu
#define texts_0198FE_ADDRESS 0x0198FEu
#define unexplained_019937_ADDRESS 0x019937u
#define texts_019938_ADDRESS 0x019938u
#define unexplained_01996D_ADDRESS 0x01996Du
#define texts_01996E_ADDRESS 0x01996Eu
#define indexed_table_of_16_bit_values_019E62_ADDRESS 0x019E62u
#define indexed_table_of_32_bit_values_01A308_ADDRESS 0x01A308u
#define table_loaded_by_lea_01B5B2_ADDRESS 0x01B5B2u
#define table_loaded_by_lea_01D35C_ADDRESS 0x01D35Cu
#define record_01F0D8_ADDRESS 0x01F0D8u
#define table_loaded_by_lea_01F242_ADDRESS 0x01F242u
#define screen_picture_tiles_ADDRESS 0x01F970u
#define screen_picture_colours_ADDRESS 0x01FAA8u
#define table_loaded_by_lea_01FBE0_ADDRESS 0x01FBE0u
#define sprite_lists_021920_ADDRESS 0x021920u
#define animations_0231F8_ADDRESS 0x0231F8u
#define sprite_lists_02422C_ADDRESS 0x02422Cu
#define animations_025CD4_ADDRESS 0x025CD4u
#define sprite_lists_026CBE_ADDRESS 0x026CBEu
#define animations_02883E_ADDRESS 0x02883Eu
#define sprite_lists_02983C_ADDRESS 0x02983Cu
#define animations_02BA9A_ADDRESS 0x02BA9Au
#define animations_02C640_ADDRESS 0x02C640u
#define animations_02CD74_ADDRESS 0x02CD74u
#define table_loaded_by_lea_02D164_ADDRESS 0x02D164u
#define animations_02D796_ADDRESS 0x02D796u
#define unexplained_02DF52_ADDRESS 0x02DF52u
#define animations_02DF54_ADDRESS 0x02DF54u
#define unexplained_02E16E_ADDRESS 0x02E16Eu
#define animations_02E192_ADDRESS 0x02E192u
#define sprite_lists_02E1E0_ADDRESS 0x02E1E0u
#define table_loaded_by_lea_02FDC0_ADDRESS 0x02FDC0u
#define indexed_table_of_8_bit_values_030350_ADDRESS 0x030350u
#define table_loaded_by_lea_030B16_ADDRESS 0x030B16u
#define animations_030B1A_ADDRESS 0x030B1Au
#define table_loaded_by_lea_030B26_ADDRESS 0x030B26u
#define animations_030D7E_ADDRESS 0x030D7Eu
#define intro_object_animations_ADDRESS 0x030DFCu
#define described_table_030E00_ADDRESS 0x030E00u
#define layers_031280_ADDRESS 0x031280u
#define unexplained_0314C3_ADDRESS 0x0314C3u
#define layers_0314C4_ADDRESS 0x0314C4u
#define unexplained_03163B_ADDRESS 0x03163Bu
#define layers_03163C_ADDRESS 0x03163Cu
#define unexplained_032311_ADDRESS 0x032311u
#define fire_blocks_ADDRESS 0x032312u
#define unexplained_032C9B_ADDRESS 0x032C9Bu
#define layers_032C9C_ADDRESS 0x032C9Cu
#define unexplained_03372C_ADDRESS 0x03372Cu
#define layers_03373C_ADDRESS 0x03373Cu
#define unexplained_034A29_ADDRESS 0x034A29u
#define layers_034A2A_ADDRESS 0x034A2Au
#define unexplained_035241_ADDRESS 0x035241u
#define layers_035242_ADDRESS 0x035242u
#define unexplained_03AB05_ADDRESS 0x03AB05u
#define layers_03AB06_ADDRESS 0x03AB06u
#define unexplained_03E989_ADDRESS 0x03E989u
#define layers_03E98A_ADDRESS 0x03E98Au
#define unexplained_03F195_ADDRESS 0x03F195u
#define layers_03F196_ADDRESS 0x03F196u
#define unexplained_044C8F_ADDRESS 0x044C8Fu
#define layers_044C90_ADDRESS 0x044C90u
#define unexplained_0458F7_ADDRESS 0x0458F7u
#define layers_0458F8_ADDRESS 0x0458F8u
#define unexplained_04618B_ADDRESS 0x04618Bu
#define layers_04618C_ADDRESS 0x04618Cu
#define unexplained_046C51_ADDRESS 0x046C51u
#define layers_046C52_ADDRESS 0x046C52u
#define sprite_sizes_ADDRESS 0x04716Eu
#define indexed_table_of_8_bit_values_0471F0_ADDRESS 0x0471F0u
#define area_spawn_lists_ADDRESS 0x04796Au
#define area_spawn_scrolls_ADDRESS 0x047992u
#define area_spawn_starts_ADDRESS 0x0479E2u
#define indexed_table_of_8_bit_values_047D50_ADDRESS 0x047D50u
#define direction_rows_ADDRESS 0x047DF6u
#define direction_table_ADDRESS 0x047E36u
#define unexplained_048818_ADDRESS 0x048818u
#define code_table_0489C6_ADDRESS 0x0489C6u
#define second_player_through_a_stale_pointer_ADDRESS 0x048A98u
#define indexed_table_of_32_bit_values_048F36_ADDRESS 0x048F36u
#define code_table_04900A_ADDRESS 0x04900Au
#define code_table_049068_ADDRESS 0x049068u
#define code_table_0490C6_ADDRESS 0x0490C6u
#define code_table_04915C_ADDRESS 0x04915Cu
#define code_table_0491E8_ADDRESS 0x0491E8u
#define indexed_table_of_32_bit_values_049240_ADDRESS 0x049240u
#define animations_049258_ADDRESS 0x049258u
#define indexed_table_of_32_bit_values_0492F8_ADDRESS 0x0492F8u
#define indexed_table_of_32_bit_values_049350_ADDRESS 0x049350u
#define animations_049358_ADDRESS 0x049358u
#define indexed_table_of_32_bit_values_049414_ADDRESS 0x049414u
#define indexed_table_of_32_bit_values_0494D2_ADDRESS 0x0494D2u
#define indexed_table_of_32_bit_values_049568_ADDRESS 0x049568u
#define indexed_table_of_32_bit_values_0495D6_ADDRESS 0x0495D6u
#define indexed_table_of_32_bit_values_04965A_ADDRESS 0x04965Au
#define indexed_table_of_32_bit_values_049796_ADDRESS 0x049796u
#define indexed_table_of_32_bit_values_0498A6_ADDRESS 0x0498A6u
#define indexed_table_of_32_bit_values_049940_ADDRESS 0x049940u
#define indexed_table_of_32_bit_values_0499B0_ADDRESS 0x0499B0u
#define indexed_table_of_32_bit_values_049A12_ADDRESS 0x049A12u
#define indexed_table_of_32_bit_values_049A5E_ADDRESS 0x049A5Eu
#define indexed_table_of_32_bit_values_049A9A_ADDRESS 0x049A9Au
#define indexed_table_of_32_bit_values_049AD6_ADDRESS 0x049AD6u
#define indexed_table_of_32_bit_values_049B12_ADDRESS 0x049B12u
#define indexed_table_of_32_bit_values_049BC8_ADDRESS 0x049BC8u
#define indexed_table_of_32_bit_values_049C82_ADDRESS 0x049C82u
#define indexed_table_of_32_bit_values_049DE8_ADDRESS 0x049DE8u
#define indexed_table_of_32_bit_values_049E1C_ADDRESS 0x049E1Cu
#define indexed_table_of_32_bit_values_049E40_ADDRESS 0x049E40u
#define indexed_table_of_32_bit_values_049E64_ADDRESS 0x049E64u
#define indexed_table_of_32_bit_values_049E88_ADDRESS 0x049E88u
#define indexed_table_of_32_bit_values_049FC4_ADDRESS 0x049FC4u
#define indexed_table_of_32_bit_values_04A100_ADDRESS 0x04A100u
#define indexed_table_of_32_bit_values_04A1E0_ADDRESS 0x04A1E0u
#define record_04A332_ADDRESS 0x04A332u
#define indexed_table_of_32_bit_values_04A374_ADDRESS 0x04A374u
#define record_04A3EE_ADDRESS 0x04A3EEu
#define indexed_table_of_32_bit_values_04A432_ADDRESS 0x04A432u
#define record_04A4AC_ADDRESS 0x04A4ACu
#define indexed_table_of_32_bit_values_04A4F0_ADDRESS 0x04A4F0u
#define record_04A56A_ADDRESS 0x04A56Au
#define indexed_table_of_32_bit_values_04A5AE_ADDRESS 0x04A5AEu
#define indexed_table_of_32_bit_values_04A6BE_ADDRESS 0x04A6BEu
#define indexed_table_of_32_bit_values_04A710_ADDRESS 0x04A710u
#define code_table_04A738_ADDRESS 0x04A738u
#define code_table_04A7DE_ADDRESS 0x04A7DEu
#define animations_04A7E6_ADDRESS 0x04A7E6u
#define sprite_lists_04A7F0_ADDRESS 0x04A7F0u
#define code_table_04A816_ADDRESS 0x04A816u
#define animations_04A81E_ADDRESS 0x04A81Eu
#define code_table_04A866_ADDRESS 0x04A866u
#define animations_04A86E_ADDRESS 0x04A86Eu
#define sprite_lists_04A878_ADDRESS 0x04A878u
#define code_table_04A89C_ADDRESS 0x04A89Cu
#define sprite_lists_04A8CE_ADDRESS 0x04A8CEu
#define code_table_04A954_ADDRESS 0x04A954u
#define animations_04A95C_ADDRESS 0x04A95Cu
#define sprite_lists_04A96E_ADDRESS 0x04A96Eu
#define code_table_04A9CA_ADDRESS 0x04A9CAu
#define animations_04A9DA_ADDRESS 0x04A9DAu
#define sprite_lists_04AA3A_ADDRESS 0x04AA3Au
#define code_table_04AB3A_ADDRESS 0x04AB3Au
#define code_table_04AC94_ADDRESS 0x04AC94u
#define code_table_04AD20_ADDRESS 0x04AD20u
#define indexed_table_of_32_bit_values_04ADB8_ADDRESS 0x04ADB8u
#define animations_04ADC0_ADDRESS 0x04ADC0u
#define indexed_table_of_32_bit_values_04ADFA_ADDRESS 0x04ADFAu
#define indexed_table_of_32_bit_values_04AE84_ADDRESS 0x04AE84u
#define indexed_table_of_32_bit_values_04AF30_ADDRESS 0x04AF30u
#define indexed_table_of_32_bit_values_04AFCA_ADDRESS 0x04AFCAu
#define indexed_table_of_32_bit_values_04B03E_ADDRESS 0x04B03Eu
#define animations_04B046_ADDRESS 0x04B046u
#define indexed_table_of_32_bit_values_04B080_ADDRESS 0x04B080u
#define indexed_table_of_32_bit_values_04B13A_ADDRESS 0x04B13Au
#define indexed_table_of_32_bit_values_04B244_ADDRESS 0x04B244u
#define indexed_table_of_32_bit_values_04B2E6_ADDRESS 0x04B2E6u
#define indexed_table_of_32_bit_values_04B322_ADDRESS 0x04B322u
#define indexed_table_of_32_bit_values_04B35E_ADDRESS 0x04B35Eu
#define indexed_table_of_32_bit_values_04B436_ADDRESS 0x04B436u
#define indexed_table_of_32_bit_values_04B4EC_ADDRESS 0x04B4ECu
#define indexed_table_of_32_bit_values_04B5E2_ADDRESS 0x04B5E2u
#define indexed_table_of_32_bit_values_04B63E_ADDRESS 0x04B63Eu
#define indexed_table_of_32_bit_values_04B662_ADDRESS 0x04B662u
#define indexed_table_of_32_bit_values_04B686_ADDRESS 0x04B686u
#define indexed_table_of_32_bit_values_04B6AA_ADDRESS 0x04B6AAu
#define indexed_table_of_32_bit_values_04B6CE_ADDRESS 0x04B6CEu
#define indexed_table_of_32_bit_values_04B6F2_ADDRESS 0x04B6F2u
#define code_table_04B72E_ADDRESS 0x04B72Eu
#define animations_04B742_ADDRESS 0x04B742u
#define indexed_table_of_16_bit_values_04B776_ADDRESS 0x04B776u
#define animations_04B790_ADDRESS 0x04B790u
#define indexed_table_of_16_bit_values_04B7C4_ADDRESS 0x04B7C4u
#define code_table_04B9B6_ADDRESS 0x04B9B6u
#define code_table_04BA42_ADDRESS 0x04BA42u
#define code_table_04BB1E_ADDRESS 0x04BB1Eu
#define code_table_04BBFA_ADDRESS 0x04BBFAu
#define code_table_04BC90_ADDRESS 0x04BC90u
#define code_table_04BD18_ADDRESS 0x04BD18u
#define code_table_04BDFA_ADDRESS 0x04BDFAu
#define code_table_04BEF6_ADDRESS 0x04BEF6u
#define code_table_04BFBE_ADDRESS 0x04BFBEu
#define code_table_04C0A6_ADDRESS 0x04C0A6u
#define code_table_04C106_ADDRESS 0x04C106u
#define code_table_04C174_ADDRESS 0x04C174u
#define code_table_04C1FC_ADDRESS 0x04C1FCu
#define code_table_04C258_ADDRESS 0x04C258u
#define code_table_04C31A_ADDRESS 0x04C31Au
#define flash_colour_past_its_table_ADDRESS 0x04C3F2u
#define code_table_04C400_ADDRESS 0x04C400u
#define animations_04C410_ADDRESS 0x04C410u
#define sprite_lists_04C44E_ADDRESS 0x04C44Eu
#define record_04C4C6_ADDRESS 0x04C4C6u
#define code_table_04C564_ADDRESS 0x04C564u
#define animations_04C56C_ADDRESS 0x04C56Cu
#define sprite_lists_04C5B4_ADDRESS 0x04C5B4u
#define animations_04C5D4_ADDRESS 0x04C5D4u
#define indexed_table_of_16_bit_values_04C5E4_ADDRESS 0x04C5E4u
#define code_table_04C64E_ADDRESS 0x04C64Eu
#define animations_04C65E_ADDRESS 0x04C65Eu
#define sprite_lists_04C688_ADDRESS 0x04C688u
#define record_04C6C8_ADDRESS 0x04C6C8u
#define code_table_04C79C_ADDRESS 0x04C79Cu
#define animations_04C7B2_ADDRESS 0x04C7B2u
#define sprite_lists_04C7F4_ADDRESS 0x04C7F4u
#define code_table_04C87C_ADDRESS 0x04C87Cu
#define code_table_04C99E_ADDRESS 0x04C99Eu
#define code_table_04CAEA_ADDRESS 0x04CAEAu
#define animations_04CAFE_ADDRESS 0x04CAFEu
#define sprite_lists_04CB34_ADDRESS 0x04CB34u
#define record_04CBAC_ADDRESS 0x04CBACu
#define object_tile_block_offsets_ADDRESS 0x04CBB4u
#define object_tile_blocks_ADDRESS 0x04CBC0u
#define code_table_04CD00_ADDRESS 0x04CD00u
#define animations_04CD10_ADDRESS 0x04CD10u
#define record_04CD3C_ADDRESS 0x04CD3Cu
#define object_tile_block_pairs_ADDRESS 0x04CD44u
#define code_table_04CE52_ADDRESS 0x04CE52u
#define animations_04CE5A_ADDRESS 0x04CE5Au
#define sprite_lists_04CE9A_ADDRESS 0x04CE9Au
#define code_table_04CF2A_ADDRESS 0x04CF2Au
#define animations_04CF3E_ADDRESS 0x04CF3Eu
#define code_table_04D05E_ADDRESS 0x04D05Eu
#define code_table_04D0A8_ADDRESS 0x04D0A8u
#define animations_04D0BC_ADDRESS 0x04D0BCu
#define sprite_lists_04D13E_ADDRESS 0x04D13Eu
#define record_04D1A6_ADDRESS 0x04D1A6u
#define code_table_04D2C8_ADDRESS 0x04D2C8u
#define code_table_04D344_ADDRESS 0x04D344u
#define animations_04D35C_ADDRESS 0x04D35Cu
#define sprite_lists_04D3BE_ADDRESS 0x04D3BEu
#define record_04D466_ADDRESS 0x04D466u
#define code_table_04D544_ADDRESS 0x04D544u
#define code_table_04D6A4_ADDRESS 0x04D6A4u
#define code_table_04D74C_ADDRESS 0x04D74Cu
#define code_table_04D810_ADDRESS 0x04D810u
#define code_table_04D8C0_ADDRESS 0x04D8C0u
#define code_table_04D9BA_ADDRESS 0x04D9BAu
#define code_table_04DA0C_ADDRESS 0x04DA0Cu
#define code_table_04DB6A_ADDRESS 0x04DB6Au
#define code_table_04DBE8_ADDRESS 0x04DBE8u
#define code_table_04DC82_ADDRESS 0x04DC82u
#define indexed_table_of_32_bit_values_04DD40_ADDRESS 0x04DD40u
#define animations_04DD48_ADDRESS 0x04DD48u
#define indexed_table_of_32_bit_values_04DD82_ADDRESS 0x04DD82u
#define indexed_table_of_32_bit_values_04DDC0_ADDRESS 0x04DDC0u
#define indexed_table_of_32_bit_values_04DE6C_ADDRESS 0x04DE6Cu
#define indexed_table_of_32_bit_values_04DEEE_ADDRESS 0x04DEEEu
#define indexed_table_of_32_bit_values_04DF70_ADDRESS 0x04DF70u
#define animations_04DF78_ADDRESS 0x04DF78u
#define indexed_table_of_32_bit_values_04DFB2_ADDRESS 0x04DFB2u
#define indexed_table_of_32_bit_values_04DFF0_ADDRESS 0x04DFF0u
#define animations_04DFF8_ADDRESS 0x04DFF8u
#define indexed_table_of_32_bit_values_04E0B4_ADDRESS 0x04E0B4u
#define indexed_table_of_32_bit_values_04E1C4_ADDRESS 0x04E1C4u
#define indexed_table_of_32_bit_values_04E260_ADDRESS 0x04E260u
#define indexed_table_of_32_bit_values_04E2D0_ADDRESS 0x04E2D0u
#define indexed_table_of_32_bit_values_04E342_ADDRESS 0x04E342u
#define indexed_table_of_32_bit_values_04E3D0_ADDRESS 0x04E3D0u
#define indexed_table_of_32_bit_values_04E40C_ADDRESS 0x04E40Cu
#define indexed_table_of_32_bit_values_04E448_ADDRESS 0x04E448u
#define indexed_table_of_32_bit_values_04E4FE_ADDRESS 0x04E4FEu
#define indexed_table_of_32_bit_values_04E572_ADDRESS 0x04E572u
#define indexed_table_of_32_bit_values_04E596_ADDRESS 0x04E596u
#define indexed_table_of_32_bit_values_04E5BA_ADDRESS 0x04E5BAu
#define indexed_table_of_32_bit_values_04E5DE_ADDRESS 0x04E5DEu
#define indexed_table_of_32_bit_values_04E602_ADDRESS 0x04E602u
#define indexed_table_of_32_bit_values_04E626_ADDRESS 0x04E626u
#define indexed_table_of_32_bit_values_04E64A_ADDRESS 0x04E64Au
#define indexed_table_of_32_bit_values_04E66E_ADDRESS 0x04E66Eu
#define code_table_04E686_ADDRESS 0x04E686u
#define code_table_04E71A_ADDRESS 0x04E71Au
#define indexed_table_of_32_bit_values_04E7BA_ADDRESS 0x04E7BAu
#define animations_04E7C2_ADDRESS 0x04E7C2u
#define indexed_table_of_32_bit_values_04E800_ADDRESS 0x04E800u
#define indexed_table_of_32_bit_values_04E83E_ADDRESS 0x04E83Eu
#define indexed_table_of_32_bit_values_04E906_ADDRESS 0x04E906u
#define indexed_table_of_32_bit_values_04E99E_ADDRESS 0x04E99Eu
#define indexed_table_of_32_bit_values_04EA12_ADDRESS 0x04EA12u
#define animations_04EA1A_ADDRESS 0x04EA1Au
#define indexed_table_of_32_bit_values_04EA58_ADDRESS 0x04EA58u
#define indexed_table_of_32_bit_values_04EA96_ADDRESS 0x04EA96u
#define indexed_table_of_32_bit_values_04EAD4_ADDRESS 0x04EAD4u
#define indexed_table_of_32_bit_values_04EB6E_ADDRESS 0x04EB6Eu
#define indexed_table_of_32_bit_values_04EBE2_ADDRESS 0x04EBE2u
#define indexed_table_of_32_bit_values_04EC6A_ADDRESS 0x04EC6Au
#define indexed_table_of_32_bit_values_04ECA6_ADDRESS 0x04ECA6u
#define indexed_table_of_32_bit_values_04ECE2_ADDRESS 0x04ECE2u
#define indexed_table_of_32_bit_values_04ED6A_ADDRESS 0x04ED6Au
#define indexed_table_of_32_bit_values_04ED8E_ADDRESS 0x04ED8Eu
#define indexed_table_of_32_bit_values_04EDB2_ADDRESS 0x04EDB2u
#define indexed_table_of_32_bit_values_04EDD6_ADDRESS 0x04EDD6u
#define indexed_table_of_32_bit_values_04EDFA_ADDRESS 0x04EDFAu
#define code_table_04EE12_ADDRESS 0x04EE12u
#define code_table_04EEAC_ADDRESS 0x04EEACu
#define code_table_04EF40_ADDRESS 0x04EF40u
#define indexed_table_of_32_bit_values_04F082_ADDRESS 0x04F082u
#define indexed_table_of_32_bit_values_04F0F0_ADDRESS 0x04F0F0u
#define code_table_04F1BA_ADDRESS 0x04F1BAu
#define indexed_table_of_32_bit_values_04F296_ADDRESS 0x04F296u
#define indexed_table_of_32_bit_values_04F72E_ADDRESS 0x04F72Eu
#define indexed_table_of_32_bit_values_04F75C_ADDRESS 0x04F75Cu
#define indexed_table_of_32_bit_values_04F78A_ADDRESS 0x04F78Au
#define indexed_table_of_32_bit_values_04F7BE_ADDRESS 0x04F7BEu
#define indexed_table_of_32_bit_values_04F7FA_ADDRESS 0x04F7FAu
#define indexed_table_of_32_bit_values_04F828_ADDRESS 0x04F828u
#define indexed_table_of_32_bit_values_04F8A8_ADDRESS 0x04F8A8u
#define indexed_table_of_32_bit_values_04F92E_ADDRESS 0x04F92Eu
#define indexed_table_of_32_bit_values_04F9CC_ADDRESS 0x04F9CCu
#define indexed_table_of_32_bit_values_04FACE_ADDRESS 0x04FACEu
#define indexed_table_of_32_bit_values_04FC10_ADDRESS 0x04FC10u
#define indexed_table_of_32_bit_values_04FCE0_ADDRESS 0x04FCE0u
#define indexed_table_of_32_bit_values_04FD58_ADDRESS 0x04FD58u
#define indexed_table_of_32_bit_values_04FD94_ADDRESS 0x04FD94u
#define animations_04FDA8_ADDRESS 0x04FDA8u
#define unexplained_04FDAC_ADDRESS 0x04FDACu
#define animations_04FDB0_ADDRESS 0x04FDB0u
#define unexplained_04FDB4_ADDRESS 0x04FDB4u
#define indexed_table_of_32_bit_values_04FE4E_ADDRESS 0x04FE4Eu
#define indexed_table_of_32_bit_values_04FEB6_ADDRESS 0x04FEB6u
#define indexed_table_of_32_bit_values_04FEEE_ADDRESS 0x04FEEEu
#define indexed_table_of_32_bit_values_04FF26_ADDRESS 0x04FF26u
#define animations_04FF3A_ADDRESS 0x04FF3Au
#define record_04FF52_ADDRESS 0x04FF52u
#define indexed_table_of_32_bit_values_050082_ADDRESS 0x050082u
#define animations_050092_ADDRESS 0x050092u
#define record_0500A2_ADDRESS 0x0500A2u
#define code_table_0501AE_ADDRESS 0x0501AEu
#define indexed_table_of_32_bit_values_050286_ADDRESS 0x050286u
#define table_loaded_by_lea_0505E2_ADDRESS 0x0505E2u
#define indexed_table_of_32_bit_values_05068A_ADDRESS 0x05068Au
#define indexed_table_of_32_bit_values_0506E4_ADDRESS 0x0506E4u
#define indexed_table_of_32_bit_values_05077C_ADDRESS 0x05077Cu
#define indexed_table_of_32_bit_values_0507FA_ADDRESS 0x0507FAu
#define indexed_table_of_32_bit_values_0508D8_ADDRESS 0x0508D8u
#define indexed_table_of_32_bit_values_050AE8_ADDRESS 0x050AE8u
#define indexed_table_of_32_bit_values_050B98_ADDRESS 0x050B98u
#define indexed_table_of_32_bit_values_050C74_ADDRESS 0x050C74u
#define indexed_table_of_32_bit_values_050CF2_ADDRESS 0x050CF2u
#define indexed_table_of_32_bit_values_050D38_ADDRESS 0x050D38u
#define indexed_table_of_32_bit_values_050D84_ADDRESS 0x050D84u
#define indexed_table_of_32_bit_values_050E72_ADDRESS 0x050E72u
#define code_table_050F7C_ADDRESS 0x050F7Cu
#define indexed_table_of_32_bit_values_05100E_ADDRESS 0x05100Eu
#define indexed_table_of_16_bit_values_0512E4_ADDRESS 0x0512E4u
#define indexed_table_of_32_bit_values_051340_ADDRESS 0x051340u
#define indexed_table_of_32_bit_values_0514C6_ADDRESS 0x0514C6u
#define code_table_05157C_ADDRESS 0x05157Cu
#define code_table_0515CC_ADDRESS 0x0515CCu
#define code_table_05161C_ADDRESS 0x05161Cu
#define code_table_051694_ADDRESS 0x051694u
#define code_table_051712_ADDRESS 0x051712u
#define indexed_table_of_32_bit_values_05175C_ADDRESS 0x05175Cu
#define animations_05176C_ADDRESS 0x05176Cu
#define indexed_table_of_32_bit_values_051836_ADDRESS 0x051836u
#define indexed_table_of_32_bit_values_0518BC_ADDRESS 0x0518BCu
#define indexed_table_of_32_bit_values_051974_ADDRESS 0x051974u
#define indexed_table_of_32_bit_values_0519CC_ADDRESS 0x0519CCu
#define indexed_table_of_32_bit_values_051A14_ADDRESS 0x051A14u
#define code_table_051AD2_ADDRESS 0x051AD2u
#define animations_051B26_ADDRESS 0x051B26u
#define unexplained_051B2E_ADDRESS 0x051B2Eu
#define animations_051B36_ADDRESS 0x051B36u
#define unexplained_051B3E_ADDRESS 0x051B3Eu
#define animations_051B46_ADDRESS 0x051B46u
#define unexplained_051B4E_ADDRESS 0x051B4Eu
#define code_table_051C2C_ADDRESS 0x051C2Cu
#define indexed_table_of_32_bit_values_051CB8_ADDRESS 0x051CB8u
#define table_loaded_by_lea_051F94_ADDRESS 0x051F94u
#define indexed_table_of_32_bit_values_052002_ADDRESS 0x052002u
#define indexed_table_of_32_bit_values_052142_ADDRESS 0x052142u
#define indexed_table_of_32_bit_values_052234_ADDRESS 0x052234u
#define indexed_table_of_32_bit_values_052312_ADDRESS 0x052312u
#define indexed_table_of_32_bit_values_05242E_ADDRESS 0x05242Eu
#define animations_052450_ADDRESS 0x052450u
#define indexed_table_of_32_bit_values_05260C_ADDRESS 0x05260Cu
#define indexed_table_of_32_bit_values_0526B0_ADDRESS 0x0526B0u
#define code_table_052778_ADDRESS 0x052778u
#define record_052ACE_ADDRESS 0x052ACEu
#define indexed_table_of_32_bit_values_052CA2_ADDRESS 0x052CA2u
#define indexed_table_of_32_bit_values_052D52_ADDRESS 0x052D52u
#define indexed_table_of_32_bit_values_052DDC_ADDRESS 0x052DDCu
#define indexed_table_of_32_bit_values_052E60_ADDRESS 0x052E60u
#define animations_052E74_ADDRESS 0x052E74u
#define indexed_table_of_32_bit_values_052FE4_ADDRESS 0x052FE4u
#define indexed_table_of_32_bit_values_05307C_ADDRESS 0x05307Cu
#define indexed_table_of_32_bit_values_0530F6_ADDRESS 0x0530F6u
#define indexed_table_of_32_bit_values_0531BA_ADDRESS 0x0531BAu
#define indexed_table_of_32_bit_values_05324E_ADDRESS 0x05324Eu
#define indexed_table_of_32_bit_values_0532E0_ADDRESS 0x0532E0u
#define indexed_table_of_32_bit_values_053348_ADDRESS 0x053348u
#define indexed_table_of_32_bit_values_05344C_ADDRESS 0x05344Cu
#define indexed_table_of_32_bit_values_0534D0_ADDRESS 0x0534D0u
#define indexed_table_of_32_bit_values_053530_ADDRESS 0x053530u
#define indexed_table_of_32_bit_values_05357A_ADDRESS 0x05357Au
#define indexed_table_of_32_bit_values_0535C4_ADDRESS 0x0535C4u
#define indexed_table_of_32_bit_values_05360E_ADDRESS 0x05360Eu
#define body_boxes_ADDRESS 0x053756u
#define spawn_offsets_ADDRESS 0x053A5Eu
#define unexplained_053B6E_ADDRESS 0x053B6Eu
#define enemy_definitions_ADDRESS 0x053EFEu
#define unused_enemy_definitions_ADDRESS 0x0543C6u
#define table_loaded_by_lea_054746_ADDRESS 0x054746u
#define animations_0547C6_ADDRESS 0x0547C6u
#define sprite_lists_054F72_ADDRESS 0x054F72u
#define animations_055722_ADDRESS 0x055722u
#define sprite_lists_055ECE_ADDRESS 0x055ECEu
#define animations_0569FE_ADDRESS 0x0569FEu
#define sprite_lists_056BDA_ADDRESS 0x056BDAu
#define animations_056F42_ADDRESS 0x056F42u
#define sprite_lists_057260_ADDRESS 0x057260u
#define animations_0575A0_ADDRESS 0x0575A0u
#define sprite_lists_057806_ADDRESS 0x057806u
#define animations_057B46_ADDRESS 0x057B46u
#define sprite_lists_057CD6_ADDRESS 0x057CD6u
#define animations_058076_ADDRESS 0x058076u
#define sprite_lists_0582B4_ADDRESS 0x0582B4u
#define animations_0585C4_ADDRESS 0x0585C4u
#define sprite_lists_0589F6_ADDRESS 0x0589F6u
#define animations_059066_ADDRESS 0x059066u
#define sprite_lists_0592C0_ADDRESS 0x0592C0u
#define animations_059618_ADDRESS 0x059618u
#define sprite_lists_05965A_ADDRESS 0x05965Au
#define animations_0596BA_ADDRESS 0x0596BAu
#define sprite_lists_0596FC_ADDRESS 0x0596FCu
#define animations_05979C_ADDRESS 0x05979Cu
#define sprite_lists_0597DE_ADDRESS 0x0597DEu
#define animations_05983E_ADDRESS 0x05983Eu
#define sprite_lists_05988C_ADDRESS 0x05988Cu
#define animations_0598E4_ADDRESS 0x0598E4u
#define sprite_lists_059A18_ADDRESS 0x059A18u
#define animations_059CB0_ADDRESS 0x059CB0u
#define sprite_lists_059D9A_ADDRESS 0x059D9Au
#define animations_059FAA_ADDRESS 0x059FAAu
#define sprite_lists_059FFA_ADDRESS 0x059FFAu
#define animations_05A08A_ADDRESS 0x05A08Au
#define sprite_lists_05A1E0_ADDRESS 0x05A1E0u
#define animations_05A430_ADDRESS 0x05A430u
#define sprite_lists_05A472_ADDRESS 0x05A472u
#define animations_05A562_ADDRESS 0x05A562u
#define sprite_lists_05A65E_ADDRESS 0x05A65Eu
#define animations_05A77E_ADDRESS 0x05A77Eu
#define sprite_lists_05A838_ADDRESS 0x05A838u
#define animations_05A930_ADDRESS 0x05A930u
#define sprite_lists_05A97E_ADDRESS 0x05A97Eu
#define animations_05A9BE_ADDRESS 0x05A9BEu
#define sprite_lists_05AA16_ADDRESS 0x05AA16u
#define animations_05AAF6_ADDRESS 0x05AAF6u
#define sprite_lists_05ABC6_ADDRESS 0x05ABC6u
#define animations_05AD06_ADDRESS 0x05AD06u
#define sprite_lists_05AD28_ADDRESS 0x05AD28u
#define animations_05AD40_ADDRESS 0x05AD40u
#define sprite_lists_05AD92_ADDRESS 0x05AD92u
#define animations_05B032_ADDRESS 0x05B032u
#define sprite_lists_05B046_ADDRESS 0x05B046u
#define animations_05B07E_ADDRESS 0x05B07Eu
#define sprite_lists_05B102_ADDRESS 0x05B102u
#define animations_05B22A_ADDRESS 0x05B22Au
#define sprite_lists_05B2AE_ADDRESS 0x05B2AEu
#define animations_05B3AE_ADDRESS 0x05B3AEu
#define sprite_lists_05B3F2_ADDRESS 0x05B3F2u
#define animations_05B4F2_ADDRESS 0x05B4F2u
#define sprite_lists_05B5F6_ADDRESS 0x05B5F6u
#define animations_05B6EE_ADDRESS 0x05B6EEu
#define sprite_lists_05B702_ADDRESS 0x05B702u
#define animations_05B73A_ADDRESS 0x05B73Au
#define sprite_lists_05B7CE_ADDRESS 0x05B7CEu
#define animations_05B91E_ADDRESS 0x05B91Eu
#define sprite_lists_05B9CA_ADDRESS 0x05B9CAu
#define animations_05BB0A_ADDRESS 0x05BB0Au
#define sprite_lists_05BB9E_ADDRESS 0x05BB9Eu
#define animations_05BD3E_ADDRESS 0x05BD3Eu
#define sprite_lists_05BDD2_ADDRESS 0x05BDD2u
#define animations_05BF42_ADDRESS 0x05BF42u
#define sprite_lists_05BFC8_ADDRESS 0x05BFC8u
#define animations_05C220_ADDRESS 0x05C220u
#define sprite_lists_05C2EC_ADDRESS 0x05C2ECu
#define animations_05C52C_ADDRESS 0x05C52Cu
#define sprite_lists_05C546_ADDRESS 0x05C546u
#define animations_05C566_ADDRESS 0x05C566u
#define sprite_lists_05C57C_ADDRESS 0x05C57Cu
#define animations_05C5A4_ADDRESS 0x05C5A4u
#define sprite_lists_05C5D2_ADDRESS 0x05C5D2u
#define animations_05C632_ADDRESS 0x05C632u
#define sprite_lists_05C6DA_ADDRESS 0x05C6DAu
#define animations_05C7CA_ADDRESS 0x05C7CAu
#define sprite_lists_05C7EE_ADDRESS 0x05C7EEu
#define animations_05C846_ADDRESS 0x05C846u
#define sprite_lists_05C8A2_ADDRESS 0x05C8A2u
#define animations_05C92A_ADDRESS 0x05C92Au
#define sprite_lists_05C96C_ADDRESS 0x05C96Cu
#define animations_05C9C4_ADDRESS 0x05C9C4u
#define sprite_lists_05CA02_ADDRESS 0x05CA02u
#define animations_05CA3A_ADDRESS 0x05CA3Au
#define sprite_lists_05CA54_ADDRESS 0x05CA54u
#define animations_05CA64_ADDRESS 0x05CA64u
#define sprite_lists_05CBB6_ADDRESS 0x05CBB6u
#define animations_05CD46_ADDRESS 0x05CD46u
#define sprite_lists_05CD60_ADDRESS 0x05CD60u
#define animations_05CDA0_ADDRESS 0x05CDA0u
#define sprite_lists_05CDB6_ADDRESS 0x05CDB6u
#define animations_05CE06_ADDRESS 0x05CE06u
#define sprite_lists_05CE26_ADDRESS 0x05CE26u
#define animations_05CE9E_ADDRESS 0x05CE9Eu
#define sprite_lists_05CEBE_ADDRESS 0x05CEBEu
#define animations_05CEEE_ADDRESS 0x05CEEEu
#define sprite_lists_05CF92_ADDRESS 0x05CF92u
#define unused_animation_list_ADDRESS 0x05D03Au
#define enemies_05D506_ADDRESS 0x05D506u
#define unexplained_05F402_ADDRESS 0x05F402u

/* numbers the code uses, by name (symbols.txt constant lines) */


/* the game's structures in work RAM */
#pragma pack(push, 1)
struct object
{
	union
	{
		struct
		{
			uint16_t hit_object;
			uint16_t attacker;
			uint8_t throw;
			uint8_t unk_4A;
			uint8_t unk_49;
			uint8_t unk_48;
			uint8_t unk_47;
			uint8_t unk_46;
			uint8_t unk_45;
			uint8_t unk_44;
			uint8_t animation_delay;
			uint8_t colour;
			union
			{
				uint16_t hit_routine;
				uint8_t hit_state;
			};
			uint16_t draw_next;
			uint32_t shadow;
			uint32_t frame;
			uint16_t depth;
			uint8_t frame_time;
			uint8_t floor_height;
			uint8_t unk_31;
			uint8_t unk_30;
			uint8_t unk_2F;
			uint8_t unk_2E;
			uint16_t unk_2C;
			uint8_t unk_2B;
			uint8_t unk_2A;
			uint16_t unk_28;
			uint8_t unk_27;
			uint8_t unk_26;
			uint8_t unk_25;
			uint8_t unk_24;
			uint8_t unk_23;
			uint8_t unk_22;
			uint16_t unk_20;
			int16_t height_speed;
			int16_t y_speed;
			int16_t x_speed;
			uint32_t y;
			uint32_t x;
			union
			{
				uint16_t height;
				struct
				{
					uint8_t pad_3E[0x1];
					uint8_t height_whole;
				};
			};
			uint16_t screen_y;
			uint16_t screen_x;
			uint16_t damage;
			uint8_t health;
			uint8_t health_bars;
			uint8_t hit;
			uint8_t attack;
			uint8_t state;
			uint8_t routine;
			uint8_t parameter;
		};
		struct
		{
			uint8_t pad_00[0x35];
			uint8_t stepping_left;
		} april;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t balls_left;
		} ball_dropper;
		struct
		{
			uint8_t pad_00[0x2E];
			uint16_t trigger_x;
		} billboard;
		struct
		{
			uint8_t pad_00[0x1F];
			uint8_t timer;
			uint8_t flipped;
			uint8_t pad_21[0xD];
			uint16_t trigger_x;
		} billboard_soldier;
		struct
		{
			uint8_t pad_00[0x2D];
			uint8_t timer;
		} bomber;
		struct
		{
			uint8_t pad_00[0x9];
			uint8_t flight_time;
			uint8_t pad_0A[0x22];
			uint32_t thrower;
		} boomerang;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t explosions;
			uint8_t pad_21[0xB];
			uint32_t target;
		} boss;
		struct
		{
			uint8_t pad_00[0x9];
			uint8_t open_time;
			uint8_t pad_0A[0x16];
			uint8_t explosions;
			uint8_t pad_21[0xB];
			uint32_t target;
		} boss_shutter;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t number;
			uint8_t pad_21[0xD];
			uint16_t stop_y;
		} car_soldier;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t aim;
		} drone_shot;
		struct
		{
			uint8_t pad_00[0x5];
			uint8_t bounces_left;
			uint8_t pad_06[0x20];
			uint16_t hit_sound;
		} dynamite;
		struct
		{
			uint8_t pad_00[0x1F];
			uint8_t timer;
			uint8_t column_done;
			uint8_t pad_21[0xB];
			uint32_t vent;
		} electric;
		struct
		{
			uint8_t pad_00[0x9];
			uint8_t wait;
			uint8_t pad_0A[0x1E];
			uint32_t stop;
		} elevator;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x5];
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x4];
			uint8_t time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_back_off;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t punch_delay;
			uint8_t pad_06[0x3];
			uint8_t timer;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t plan;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_bebop;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t punch_delay;
			uint8_t pad_06[0x3];
			uint8_t timer;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x3];
			uint8_t walk_time;
			uint8_t pad_10[0xE];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t plan;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_bebop_enter;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t punch_delay;
			uint8_t pad_06[0x3];
			uint8_t timer;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x2];
			uint8_t shots_left;
			uint8_t shot_time;
			uint8_t pad_10[0xE];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t plan;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_bebop_shoot;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x1];
			uint32_t boomerang;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_boomerang;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t clockwise;
			uint8_t pad_06[0x4];
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_circle;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x4];
			uint8_t time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_grab;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x4];
			uint8_t down_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_knocked;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x3];
			uint8_t chase_time;
			uint8_t timer;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_mouser;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x4];
			uint8_t aim_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint32_t turtle;
		} enemy_rocket_soldier;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x1];
			uint8_t far_attack_wait;
			uint8_t close_attack_wait;
			uint16_t mode_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x3];
			uint8_t timer;
			uint8_t pad_10[0xE];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t armed;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_rocksteady;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t turn;
			uint8_t far_attack_wait;
			uint8_t close_attack_wait;
			uint16_t mode_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x3];
			uint8_t aim_time;
			uint8_t pad_10[0xE];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t armed;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_rocksteady_circle;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x1];
			uint8_t far_attack_wait;
			uint8_t close_attack_wait;
			uint16_t mode_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x3];
			uint8_t timer;
			uint8_t pad_10[0xE];
			uint8_t aim_time;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t armed;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_rocksteady_close_in;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t blink_time;
			uint8_t far_attack_wait;
			uint8_t close_attack_wait;
			uint16_t mode_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x3];
			uint8_t timer;
			uint8_t pad_10[0xE];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t armed;
			uint16_t move;
			uint32_t animations;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_rocksteady_defeated;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t lie_time;
			uint8_t far_attack_wait;
			uint8_t close_attack_wait;
			uint16_t mode_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x3];
			uint8_t timer;
			uint8_t pad_10[0xE];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t armed;
			uint16_t move;
			uint32_t animations;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_rocksteady_knocked_down;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t aim;
			uint8_t far_attack_wait;
			uint8_t close_attack_wait;
			uint16_t mode_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x2];
			uint8_t shots_left;
			uint8_t shot_time;
			uint8_t pad_10[0xE];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t armed;
			uint16_t move;
			uint32_t bullet;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_rocksteady_shoot;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t aim;
			uint8_t far_attack_wait;
			uint8_t close_attack_wait;
			uint16_t mode_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x2];
			uint8_t shots_left;
			uint8_t shot_time;
			uint8_t pad_10[0xE];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t armed;
			uint16_t move;
			uint32_t bullet;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
			uint8_t pad_30[0x2];
			uint32_t aims;
		} enemy_rocksteady_shoot_around;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x1];
			int16_t brake;
			uint8_t pad_08[0x1];
			uint8_t wait;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_rodney;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x1];
			int16_t brake;
			uint8_t shots_left;
			uint8_t shot_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_rodney_shoot;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t arm_flags;
			int16_t brake;
			uint8_t pad_08[0x1];
			uint8_t arm_length;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t arm;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_rodney_whip;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x3];
			uint8_t shots_left;
			uint8_t shot_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_shoot;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t attack_wait;
			uint8_t pad_06[0x1];
			uint8_t timer;
			uint16_t ray_wait;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t guard_wait;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint8_t pad_28[0x3];
			uint8_t hits_to_knock_back;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_shredder;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x4];
			uint8_t steps;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_shuffle;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t hits_left;
			uint8_t pad_06[0x4];
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_spear;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x3];
			uint8_t time;
			uint8_t turns;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_stalk;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x3];
			uint8_t throws_left;
			uint8_t throw_time;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x12];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_throw;
		struct
		{
			uint8_t pad_00[0x4];
			uint8_t throw;
			uint8_t pad_05[0x1];
			uint32_t animations;
			uint8_t side;
			uint8_t target_faces;
			uint8_t pad_0C[0x2];
			uint16_t speed;
			uint8_t pad_10[0xE];
			uint8_t dodge_chance;
			uint8_t facing;
			uint16_t target_dy;
			uint16_t target_dx;
			uint8_t target_direction;
			uint8_t approach;
			uint16_t move;
			uint32_t definition;
			uint8_t retarget_time;
			uint8_t move_time;
			uint16_t target;
		} enemy_walk;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t hit_sound;
		} falling_debris;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t shots_left;
			uint8_t timer;
			uint8_t aim;
			uint8_t turning;
			union
			{
				uint16_t heading;
				struct
				{
					uint8_t pad_22[0x1];
					uint8_t direction;
				};
			};
			uint8_t turn_speed;
			uint8_t bob;
			uint8_t pad_26[0x4];
			uint16_t time_left;
			uint32_t target;
		} flying_drone;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t hit_sound;
		} foot_car;
		struct
		{
			uint8_t pad_00[0x1F];
			uint8_t timer;
			uint8_t pad_20[0xC];
			uint32_t row_status;
		} freeze_nozzle;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t flies_left;
			uint8_t pad_21[0xB];
			uint32_t shooter;
		} gun_blast;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t shots_left;
			uint8_t timer;
			uint8_t drift;
			uint8_t pad_21[0x1];
			uint16_t stay_time;
		} helicopter;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t jets_left;
			uint8_t timer;
		} hydrant;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t jets_left;
			uint8_t timer;
			uint8_t jet;
		} hydrant_water;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t move_time;
			uint8_t timer;
			uint8_t laser_angle;
			uint8_t close_turtle;
			uint8_t hurt;
			uint8_t pad_23[0x2];
			uint8_t hit_delay;
			uint8_t pad_26[0x5];
			uint8_t hits_left;
		} krang;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t move_time;
			uint8_t timer;
			uint8_t explosions;
			uint8_t close_turtle;
			uint8_t hurt;
			uint8_t pad_23[0x2];
			uint8_t hit_delay;
			uint8_t pad_26[0x5];
			uint8_t hits_left;
		} krang_explode;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t move_time;
			uint8_t timer;
			uint8_t flipped;
			uint8_t close_turtle;
			uint8_t hurt;
			uint8_t pad_23[0x2];
			uint8_t hit_delay;
			uint8_t pad_26[0x5];
			uint8_t hits_left;
			uint32_t shooter;
		} krang_fist;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t last;
			uint8_t delay;
			uint8_t flipped;
			uint8_t close_turtle;
			uint8_t hurt;
			uint8_t pad_23[0x2];
			uint8_t hit_delay;
			uint8_t pad_26[0x5];
			uint8_t hits_left;
			uint32_t shooter;
		} krang_laser;
		struct
		{
			uint8_t pad_00[0x2E];
			uint16_t trigger_x;
		} manhole_soldier;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t flies_left;
			uint8_t pad_21[0xB];
			uint32_t shooter;
		} missile;
		struct
		{
			uint8_t pad_00[0x5];
			uint8_t wheelie;
			uint8_t pad_06[0x3];
			uint8_t aim_time;
			uint8_t pad_0A[0x1C];
			uint16_t hit_sound;
			uint8_t pad_28[0x4];
			uint32_t target_turtle;
		} motorbike;
		struct
		{
			uint8_t pad_00[0x9];
			uint8_t mousers_left;
			uint8_t pad_0A[0x1E];
			uint32_t hole;
			uint8_t pad_2C[0x1];
			uint8_t spawn_time;
		} mouser_hole;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t nozzle_status;
		} nozzle_row;
		struct
		{
			uint8_t pad_00[0x1F];
			uint8_t timer;
		} oil_drum;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t soldier_time;
			uint8_t counter;
			uint8_t pad_20[0x4];
			uint16_t last_screen_x;
			uint8_t pad_26[0x2];
			uint16_t scroll_y;
			uint16_t scroll_x;
			uint32_t blank_row;
		} parked_car;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t announced;
		} pizza;
		struct
		{
			uint8_t pad_00[0x2C];
			uint16_t end_y;
			uint16_t end_x;
		} profile;
		struct
		{
			uint8_t pad_00[0x1F];
			uint8_t timer;
		} rat;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t move_time;
			uint8_t timer;
			uint8_t explosions;
			uint8_t close_turtle;
			uint8_t hurt;
			uint8_t shot_hit;
			uint8_t players;
			uint8_t hit_delay;
			uint8_t pad_26[0x3];
			uint8_t blows;
			uint8_t pad_2A[0x1];
			uint8_t hits_left;
		} rock_soldier;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t hit_sound;
		} rocket;
		struct
		{
			uint8_t pad_00[0x28];
			uint32_t burst;
		} rocksteady_bullet;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t hit_sound;
			uint8_t pad_28[0x5];
			uint8_t hit_delay;
		} rolling;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t hit_sound;
		} scenery_open_manhole;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t hit_sound;
		} set_object_stats;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t missiles_left;
			uint8_t delay;
			uint8_t drift;
		} sewer_launcher;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t goes_right;
		} sewer_missile;
		struct
		{
			uint8_t pad_00[0x9];
			uint8_t swim_time;
		} sewer_ripple;
		struct
		{
			uint8_t pad_00[0x1F];
			uint8_t blink_timer;
			uint8_t pad_20[0x1];
			uint8_t blink_period;
			uint8_t pad_22[0xA];
			uint32_t leader;
		} shock_bars;
		struct
		{
			uint8_t pad_00[0x5];
			uint8_t landings;
		} shredder_piece;
		struct
		{
			uint8_t pad_00[0x28];
			uint32_t shredder;
			uint8_t pad_2C[0x1];
			uint8_t time_left;
		} shredder_ray;
		struct
		{
			uint8_t pad_00[0x1F];
			uint8_t timer;
		} spiked_pole;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t hit_sound;
		} start_shot;
		struct
		{
			uint8_t pad_00[0x1F];
			uint8_t timer;
			uint8_t explosions;
			uint8_t turning;
			union
			{
				uint16_t heading;
				struct
				{
					uint8_t pad_22[0x1];
					uint8_t direction;
				};
			};
			uint8_t turn_speed;
			uint8_t bob;
			uint8_t pad_26[0x4];
			uint16_t time_left;
			uint32_t target;
		} stockman;
		struct
		{
			uint8_t pad_00[0x1F];
			uint8_t shadow_time;
		} technodrome_ball;
		struct
		{
			uint8_t pad_00[0x8];
			uint8_t soldiers_left;
			uint8_t spawn_time;
		} technodrome_door;
		struct
		{
			uint8_t pad_00[0x2E];
			uint16_t trigger_x;
		} tire_soldier;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t shots_left;
			uint8_t timer;
			uint8_t phase;
		} turret;
		struct
		{
			uint8_t pad_00[0x1E];
			uint8_t shots_left;
			uint8_t timer;
			uint8_t flipped;
		} turret_shot;
		struct
		{
			uint16_t prompt_place;
			uint32_t hit_target;
			uint8_t prompt_frame;
			uint8_t prompt_time;
			uint16_t combo;
			uint8_t has_gun;
			uint8_t enemy_behind;
			uint8_t pad_0C[0x12];
			uint8_t attack_press_time;
			uint8_t pad_1F[0x2];
			uint8_t combo_step;
			uint8_t invulnerable_time;
			uint8_t exit_step;
			uint32_t hit_by;
			uint8_t escape_presses;
			uint8_t wait_timer;
			uint8_t reaction_variant;
			uint8_t reaction_step;
			uint8_t hit_reaction;
			uint8_t knockback_flags;
			uint16_t drift_speed;
			uint8_t jump_flip;
			uint8_t idle_time;
			uint8_t move_timer;
			uint8_t falling;
			uint16_t jump_speed;
			uint8_t pad_36[0x16];
			uint8_t scroll_push;
		} turtle;
		struct
		{
			uint16_t prompt_place;
			uint32_t hit_target;
			uint8_t prompt_frame;
			uint8_t prompt_time;
			uint16_t combo;
			uint8_t has_gun;
			uint8_t enemy_behind;
			uint8_t pad_0C[0x12];
			uint8_t attack_press_time;
			uint8_t pad_1F[0x2];
			uint8_t combo_step;
			uint8_t invulnerable_time;
			uint8_t exit_step;
			uint32_t hit_by;
			uint8_t escape_presses;
			uint8_t wait_timer;
			uint8_t reaction_variant;
			uint8_t reaction_step;
			uint8_t hit_reaction;
			uint8_t knockback_flags;
			uint16_t drift_speed;
			int16_t jump_in_speed;
			uint8_t move_timer;
			uint8_t falling;
			uint16_t jump_speed;
			uint8_t pad_36[0x16];
			uint8_t scroll_push;
		} turtle_jump_in;
		struct
		{
			uint8_t pad_00[0x28];
			uint32_t rodney;
		} whip_arm;
		struct
		{
			uint8_t pad_00[0x28];
			uint32_t blocks;
			uint8_t pad_2C[0x2];
			uint16_t trigger_y;
		} window_soldier_dive;
		struct
		{
			uint8_t pad_00[0x8];
			uint8_t delay;
			uint8_t break_time;
			uint8_t pad_0A[0x1E];
			uint32_t blocks;
			uint8_t pad_2C[0x2];
			uint16_t trigger_x;
		} window_soldier_drop;
	};
	uint8_t kind;
	uint8_t contacts;
	uint8_t flags;
};

struct animation_frame
{
	int16_t attack_depth;
	uint16_t body_box;
	uint32_t sprites;
	uint8_t last_sprite;
	uint8_t time;
};

struct attack_frame
{
	int16_t attack_height;
	int16_t attack_width;
	int16_t attack_y;
	int16_t attack_x;
	int16_t attack_depth;
	uint16_t body_box;
	uint32_t sprites;
	uint8_t last_sprite;
	uint8_t time;
};

struct sprite
{
	int16_t y;
	int16_t x;
	uint8_t flips;
	uint8_t colour;
	uint8_t code;
	uint8_t size_code;
};

struct sprite_size
{
	uint8_t pad_00[0x2];
	int16_t width;
	int16_t bottom;
	int16_t left;
};

struct body_box
{
	int16_t height;
	int16_t half_width;
};

struct player_slot
{
	uint32_t unused;
	uint8_t pad_04[0x3];
	uint8_t grab_time;
	uint8_t mouser_sides;
	uint8_t rodney_sides;
	uint8_t sides;
	uint8_t enemies;
	uint32_t turtle;
};

struct player
{
	uint8_t message;
	uint8_t health_bars;
	uint16_t score;
	uint16_t unused_setting_copy;
	union
	{
		uint16_t lives;
		uint8_t lives_low;
	};
};

struct coin_slot
{
	uint16_t credits;
	uint8_t counter_on;
	uint8_t credits_per_coins;
	uint8_t coins_per_credit;
	uint8_t counter_pulse;
	uint8_t coins;
	uint8_t coins_to_count;
};

struct palette_effect
{
	uint32_t colour;
	uint32_t step;
	uint8_t time;
	uint8_t flags;
};

struct palette_request
{
	uint32_t data;
	uint16_t kind;
};

struct layer
{
	uint8_t pad_00[0xA];
	uint8_t new_column;
	uint8_t new_row;
	uint32_t new_row_y;
	uint32_t new_column_x;
	uint32_t y_min;
	uint32_t x_min;
	uint32_t y_max;
	uint32_t x_max;
	int8_t x_direction;
	int8_t y_direction;
	uint32_t blocks;
	uint32_t map;
	uint16_t map_width;
	uint16_t y_speed;
	uint16_t x_speed;
	uint16_t row_phase;
	uint16_t column_phase;
	union
	{
		uint32_t y;
		struct
		{
			uint8_t pad_38[0x1];
			uint8_t y_pixel;
			uint8_t y_page;
		};
	};
	union
	{
		uint32_t x;
		struct
		{
			uint8_t pad_3C[0x2];
			uint8_t x_page;
		};
	};
};

struct typed_pass
{
	uint8_t delay;
	uint8_t wait;
	uint32_t text;
	uint32_t place;
};

struct object_stats
{
	uint16_t hit_sound;
	uint16_t depth;
	uint16_t damage;
	uint8_t health;
	uint8_t health_bars;
	uint8_t hit;
	uint8_t attack;
};

#pragma pack(pop)

_Static_assert(sizeof(struct object) == 0x50, "struct object has the size of the game's blocks");
_Static_assert(sizeof(struct animation_frame) == 0xA, "struct animation_frame has the size of the program ROM's records");
_Static_assert(sizeof(struct attack_frame) == 0x12, "struct attack_frame has the size of the program ROM's records");
_Static_assert(sizeof(struct sprite) == 0x8, "struct sprite has the size of the program ROM's records");
_Static_assert(sizeof(struct sprite_size) == 0x8, "struct sprite_size has the size of the program ROM's records");
_Static_assert(sizeof(struct body_box) == 0x4, "struct body_box has the size of the program ROM's records");
_Static_assert(sizeof(struct player_slot) == 0x10, "struct player_slot has the size of the game's blocks");
_Static_assert(sizeof(struct player) == 0x8, "struct player has the size of the game's blocks");
_Static_assert(sizeof(struct coin_slot) == 0x8, "struct coin_slot has the size of the game's blocks");
_Static_assert(sizeof(struct palette_effect) == 0xA, "struct palette_effect has the size of the game's blocks");
_Static_assert(sizeof(struct palette_request) == 0x6, "struct palette_request has the size of the game's blocks");
_Static_assert(sizeof(struct layer) == 0x40, "struct layer has the size of the game's blocks");
_Static_assert(sizeof(struct typed_pass) == 0xA, "struct typed_pass has the size of the game's blocks");
_Static_assert(sizeof(struct object_stats) == 0xA, "struct object_stats has the size of the program ROM's records");

#define OBJECT(address) ((struct object *)ram((address), sizeof(struct object)))
#define ANIMATION_FRAME(address) ((const struct animation_frame *)data_record((address), sizeof(struct animation_frame)))
#define ATTACK_FRAME(address) ((const struct attack_frame *)data_record((address), sizeof(struct attack_frame)))
#define SPRITE(address) ((const struct sprite *)data_record((address), sizeof(struct sprite)))
#define SPRITE_SIZE(address) ((const struct sprite_size *)data_record((address), sizeof(struct sprite_size)))
#define BODY_BOX(address) ((const struct body_box *)data_record((address), sizeof(struct body_box)))
#define PLAYER_SLOT(address) ((struct player_slot *)ram((address), sizeof(struct player_slot)))
#define PLAYER(address) ((struct player *)ram((address), sizeof(struct player)))
#define COIN_SLOT(address) ((struct coin_slot *)ram((address), sizeof(struct coin_slot)))
#define PALETTE_EFFECT(address) ((struct palette_effect *)ram((address), sizeof(struct palette_effect)))
#define PALETTE_REQUEST(address) ((struct palette_request *)ram((address), sizeof(struct palette_request)))
#define LAYER(address) ((struct layer *)ram((address), sizeof(struct layer)))
#define TYPED_PASS(address) ((struct typed_pass *)ram((address), sizeof(struct typed_pass)))
#define OBJECT_STATS(address) ((const struct object_stats *)data_record((address), sizeof(struct object_stats)))
#define OBJECT_ADDRESS(n) (0x62000u + (n) * 0x50u)    /* the 50 of them, from 0 */
#define PLAYER_ADDRESS(n) (0x60100u + (n) * 0x8u)    /* the 4 of them, from 0 */
#define COIN_SLOT_ADDRESS(n) (0x60300u + (n) * 0x8u)    /* the 4 of them, from 0 */
#define PALETTE_EFFECT_ADDRESS(n) (0x60480u + (n) * 0xAu)    /* the 64 of them, from 0 */
#define PALETTE_REQUEST_ADDRESS(n) (0x60B00u + (n) * 0x6u)    /* the 40 of them, from 0 */
#define PLAYER_SLOT_ADDRESS(n) (0x62FA0u + (n) * 0x10u)    /* the 4 of them, from 0 */
#define LAYER_ADDRESS(n) (0x63300u + (n) * 0x40u)    /* the 3 of them, from 0 */
#define TYPED_PASS_ADDRESS(n) (0x63430u + (n) * 0xAu)    /* the 8 of them, from 0 */

#endif
