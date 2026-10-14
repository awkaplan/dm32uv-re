# rf-frontend

205 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 72 |
| STRUCTURAL | 133 |
| RAW | 0 |

## Subdirectories

This subsystem is large enough to be split a second level. Grouping key: shared name prefix.

| Directory | Files |
|---|---|
| `fd6818b/` | 48 |
| `fd6818/` | 20 |
| `tx_teardown/` | 17 |
| `tx_led/` | 14 |
| `tx_gate/` | 9 |
| _(subsystem root)_ | 97 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x0002b364` | `tx_audio_dac_envelope_ramp` | 202 | STRUCTURAL |
| `0x0002b440` | `rf_tx_enable_sequence` | 94 | CONFIRMED |
| `0x0002b4a0` | `rf_tx_disable_sequence` | 92 | CONFIRMED |
| `0x0002b50c` | `fd6818b_reg50_tx_audio_unmute_set` | 8 | STRUCTURAL |
| `0x0002b514` | `fd6818b_reg50_tx_audio_mute_set` | 8 | STRUCTURAL |
| `0x0002b51c` | `fd6818b_reg47_tx_bypass_or_rx_afout` | 50 | CONFIRMED |
| `0x0002b550` | `fd6818b_reg47_afout_clear_mode` | 22 | CONFIRMED |
| `0x0002b56c` | `fd6818_set_frequency` | 22 | CONFIRMED |
| `0x0002b584` | `fd6818b_reg47_write_byte_or_6042` | 18 | CONFIRMED |
| `0x0002b598` | `fd6818b_reg50_write_bb18` | 14 | CONFIRMED |
| `0x0002b5a8` | `fd6818b_reg50_write_3b18` | 14 | CONFIRMED |
| `0x0002b5b8` | `fd6818b_init_seq_filter_ctcss_chipmode` | 42 | CONFIRMED |
| `0x0002b5e4` | `fd6818b_filter_select_then_chipmode_normal` | 58 | CONFIRMED |
| `0x0002b624` | `fd6818b_reg48_cic_mode_write` | 16 | CONFIRMED |
| `0x0002b634` | `fd6818b_driver_state_reset` | 64 | STRUCTURAL |
| `0x0002b674` | `fd6818b_retune_and_reinit_sequence` | 42 | CONFIRMED |
| `0x0002b6a0` | `rf_retune_and_apply_channel_mode` | 318 | STRUCTURAL |
| `0x0002c1f8` | `fd6818b_shift_out_8bit` | 78 | CONFIRMED |
| `0x0002c248` | `fd6818b_shift_out_16bit` | 80 | CONFIRMED |
| `0x0002c298` | `fd6818b_shift_in_16bit` | 90 | CONFIRMED |
| `0x0002c33c` | `fd6818_reg_read` | 72 | CONFIRMED |
| `0x0002c838` | `pa_band_select_vhf_uhf_gpio` | 62 | CONFIRMED |
| `0x0002c878` | `antenna_switch_select_gpio_24_22` | 62 | STRUCTURAL |
| `0x0002d040` | `fd6818b_bitbang_write_byte_pin8` | 128 | CONFIRMED |
| `0x0002d230` | `fd6818b_bitbang_read_byte_pin8` | 122 | CONFIRMED |
| `0x0300d4b0` | `rf_chip_init_and_spawn_worker_tasks` | 152 | STRUCTURAL |
| `0x0300d568` | `rf_config_load_from_flash_block2` | 642 | CONFIRMED |
| `0x0300d84c` | `frequency_band_range_check_and_status_set` | 458 | CONFIRMED |
| `0x0300db48` | `freq_calibration_apply_all` | 310 | STRUCTURAL |
| `0x0300dce4` | `rf_tx_flag_wait_then_unkey_loop` | 56 | STRUCTURAL |
| `0x0300dd1c` | `rf_mode_config_entry_0x51_apply` | 120 | STRUCTURAL |
| `0x0300de60` | `fd6818b_reg_write_wrapper` | 20 | CONFIRMED |
| `0x0300df08` | `channel_change_apply_squelch` | 62 | STRUCTURAL |
| `0x0300dfa0` | `tx_power_mode_apply_from_flags` | 56 | STRUCTURAL |
| `0x0300e218` | `rf_channel_mode_select_and_apply` | 134 | STRUCTURAL |
| `0x0300e360` | `tx_abort_reset` | 84 | STRUCTURAL |
| `0x0300e68c` | `fd6818b_pa_power_level_select` | 88 | CONFIRMED |
| `0x0300e6e4` | `fd6818b_mode_register_table_apply` | 174 | STRUCTURAL |
| `0x0300e794` | `fd6818_tx_deviation_bandwidth_mode_set` | 70 | CONFIRMED |
| `0x0300e7e0` | `fd6818b_write_tone_divider_reg07` | 12 | CONFIRMED |
| `0x0300e824` | `fd6818_reg31_clear_bit1` | 24 | STRUCTURAL |
| `0x0300e83c` | `fd6818_reg31_set_bit3` | 22 | STRUCTURAL |
| `0x0300e854` | `fd6818_reg31_clear_bit3` | 24 | STRUCTURAL |
| `0x0300e86c` | `rf_setup_fd6818_regs_47_7e` | 24 | STRUCTURAL |
| `0x0300e93c` | `fd6818b_reg_write_arg37h_1d0fh` | 14 | STRUCTURAL |
| `0x0300e94c` | `rf_band_mode_clear_regs` | 28 | STRUCTURAL |
| `0x0300e96c` | `fd6818b_preset_write_0xf50b` | 8 | STRUCTURAL |
| `0x0300e974` | `fd6818b_preset_write_0xdf22` | 8 | STRUCTURAL |
| `0x0300e97c` | `fd6818b_preset_write_0xd42d` | 8 | STRUCTURAL |
| `0x0300e984` | `fd6818b_preset_write_0xcc35` | 8 | STRUCTURAL |
| `0x0300e98c` | `fd6818b_preset_write_0xfa02` | 8 | STRUCTURAL |
| `0x0300e9a4` | `fd6818b_preset_write_0x9009` | 10 | STRUCTURAL |
| `0x0300e9ae` | `fd6818b_preset_write_0x8f46` | 10 | STRUCTURAL |
| `0x0300e9b8` | `fd6818b_preset_write_0x8ed8` | 10 | STRUCTURAL |
| `0x0300e9c2` | `fd6818b_preset_write_0x8d8f` | 10 | STRUCTURAL |
| `0x0300e9cc` | `fd6818b_preset_write_0x91c1` | 10 | STRUCTURAL |
| `0x0300e9d6` | `fd6818b_preset_write_0x920b` | 10 | STRUCTURAL |
| `0x0300e9e0` | `fd6818b_preset_write_0x935a` | 10 | STRUCTURAL |
| `0x0300e9f0` | `fd6818b_preset_write_0xe61c` | 8 | STRUCTURAL |
| `0x0300e9f8` | `fd6818b_preset_write_0x8f90` | 80 | STRUCTURAL |
| `0x0300ea5c` | `rf_fd6818b_page0_cfg_r41_81c1_a` | 52 | STRUCTURAL |
| `0x0300ea90` | `rf_fd6818b_page0_cfg_r41_81c2` | 52 | STRUCTURAL |
| `0x0300eac4` | `rf_fd6818b_page0_cfg_r41_81c1_b` | 52 | STRUCTURAL |
| `0x0300eaf8` | `rf_fd6818b_page0_preset_3b_3c` | 22 | STRUCTURAL |
| `0x0300eb0e` | `rf_fd6818b_page0_cfg_r41_81c5` | 50 | STRUCTURAL |
| `0x0300eb84` | `fd6818_page0_reg0c_bit2_get` | 14 | STRUCTURAL |
| `0x0300eb94` | `fd6818_reg64h_read_masked` | 28 | STRUCTURAL |
| `0x0300ebc0` | `fd6818_page0_reg65_low7_get` | 14 | STRUCTURAL |
| `0x0300ebd0` | `fd6818_page0_reg63_get` | 12 | STRUCTURAL |
| `0x0300ebdc` | `fd6818b_reg33_indexed_bit_set_and_dispatch` | 50 | STRUCTURAL |
| `0x0300ec14` | `fd6818_p0_r35_set_bits11_8` | 24 | STRUCTURAL |
| `0x0300ec2c` | `fd6818_p0_r35_set_bits7_4` | 24 | STRUCTURAL |
| `0x0300ec44` | `fd6818_page0_reg35_nibble_update` | 22 | STRUCTURAL |
| `0x0300ec5a` | `fd6818_p0_r34_set_bits15_12` | 24 | STRUCTURAL |
| `0x0300ec72` | `fd6818_p0_r34_set_bits11_8` | 24 | STRUCTURAL |
| `0x0300ec8a` | `fd6818_p0_r34_set_bits7_4` | 24 | STRUCTURAL |
| `0x0300eca2` | `fd6818_page0_reg34_nibble_update` | 22 | STRUCTURAL |
| `0x0300ecb8` | `fd6818b_default_register_init` | 290 | CONFIRMED |
| `0x0300eddc` | `fd6818_set_reg33_bit_test_reg0a` | 50 | STRUCTURAL |
| `0x0300eea4` | `fd6818b_status_register_poll_with_reinit` | 160 | CONFIRMED |
| `0x0300ef44` | `fd6818_pa_status_fault_check` | 140 | CONFIRMED |
| `0x0300efd0` | `rf_fd6818b_page0_init` | 80 | STRUCTURAL |
| `0x0300f068` | `fd6818b_dtmf_coefficient_table_load` | 162 | CONFIRMED |
| `0x0300f1b4` | `tx_bandwidth_deviation_mode_set` | 150 | STRUCTURAL |
| `0x0300f268` | `tx_teardown_config_reset` | 58 | CONFIRMED |
| `0x030142d4` | `tx_inactive_mbox_post_0x13` | 56 | STRUCTURAL |
| `0x0301430c` | `tx_inactive_mbox_post_0x12` | 56 | STRUCTURAL |
| `0x03014360` | `tx_state_poll_and_teardown` | 68 | STRUCTURAL |
| `0x030143a4` | `tx_teardown_guard_a` | 36 | STRUCTURAL |
| `0x030143c8` | `tx_teardown_guard_b` | 36 | STRUCTURAL |
| `0x030143ec` | `tx_teardown_guard_c` | 36 | STRUCTURAL |
| `0x03014410` | `tx_teardown_guard_d` | 36 | STRUCTURAL |
| `0x0301454c` | `tx_teardown_check_and_tmrkey_dispatch` | 54 | STRUCTURAL |
| `0x03014e28` | `tx_teardown_reset_if_flags_5_6_set` | 36 | CONFIRMED |
| `0x03014e4c` | `tx_teardown_reset_if_flags_5_6_set_arg11h` | 10 | STRUCTURAL |
| `0x03014e68` | `tx_teardown_reset_if_flags_5_6_set_arg10h` | 10 | STRUCTURAL |
| `0x03014e74` | `tx_teardown_reset_if_flags_5_6_set_argfh` | 10 | STRUCTURAL |
| `0x03014e80` | `tx_teardown_reset_if_flags_5_6_set_argeh` | 10 | STRUCTURAL |
| `0x03014e8c` | `tx_teardown_reset_if_flags_5_6_set_argdh` | 10 | STRUCTURAL |
| `0x03014e98` | `tx_teardown_reset_if_flags_5_6_set_argch` | 10 | STRUCTURAL |
| `0x03014ea4` | `tx_teardown_reset_if_flags_5_6_set_argbh` | 10 | STRUCTURAL |
| `0x03014eb0` | `tx_teardown_reset_if_flags_5_6_set_argah` | 10 | STRUCTURAL |
| `0x03014ebc` | `tx_teardown_reset_if_flags_5_6_set_arg9h` | 10 | STRUCTURAL |
| `0x03014ec8` | `tx_teardown_reset_if_flags_5_6_set_arg8h` | 10 | STRUCTURAL |
| `0x03015cc8` | `tx_abort_check_and_report` | 66 | STRUCTURAL |
| `0x030163d4` | `tx_timeout_tick_and_status_refresh` | 72 | STRUCTURAL |
| `0x03016534` | `tx_call_abort_to_idle` | 164 | CONFIRMED |
| `0x03017040` | `tx_disable_mode_gate_check` | 156 | STRUCTURAL |
| `0x030170ec` | `tx_settings_field_gate_and_validate` | 146 | STRUCTURAL |
| `0x030171a8` | `tx_settings_field_gate_and_validate_arg4h` | 10 | STRUCTURAL |
| `0x030171b4` | `tx_settings_field_gate_and_validate_arg3h` | 10 | STRUCTURAL |
| `0x030171c0` | `tx_settings_field_gate_and_validate_arg2h` | 10 | STRUCTURAL |
| `0x030171cc` | `tx_settings_field_gate_and_validate_arg1h` | 10 | STRUCTURAL |
| `0x030171d8` | `tx_settings_field_gate_and_validate_arg0h` | 10 | STRUCTURAL |
| `0x0301af74` | `frequency_to_step_index_resolve` | 134 | CONFIRMED |
| `0x0301b078` | `frequency_range_clamp_and_dispatch` | 184 | STRUCTURAL |
| `0x0301b130` | `freq_calibration_interpolate_single` | 214 | CONFIRMED |
| `0x0301b424` | `freq_calibration_interpolate_selected` | 308 | STRUCTURAL |
| `0x0301b5a4` | `freq_cal_interp_mode_select` | 78 | STRUCTURAL |
| `0x0301bb44` | `rssi_meter_level_update_and_fault_reset` | 334 | STRUCTURAL |
| `0x0301bf94` | `fd6818_reg7e_set_flag_bit15` | 56 | STRUCTURAL |
| `0x0301bff8` | `rf_agc_step_adaptive_control_loop` | 374 | STRUCTURAL |
| `0x0301d92c` | `tx_forbid_flag_clear` | 34 | CONFIRMED |
| `0x0301d950` | `tx_forbid_flag_clear_call` | 8 | CONFIRMED |
| `0x03021850` | `tx_voice_end_stop_tx_record` | 64 | STRUCTURAL |
| `0x03022fac` | `tx_gate_companded_audio_burst_send` | 150 | CONFIRMED |
| `0x03029c30` | `tx_queue_walk_and_send_per_slot` | 82 | CONFIRMED |
| `0x0302c578` | `tx_ptt_ui_field_set_on_call_match_gate` | 80 | STRUCTURAL |
| `0x0302cf84` | `tx_release_debounce_timer` | 144 | CONFIRMED |
| `0x0302d1c4` | `tx_dialog_state_machine_tick` | 412 | STRUCTURAL |
| `0x0302d79c` | `tx_caller_dialog_screen` | 138 | STRUCTURAL |
| `0x0302ed50` | `tx_is_inhibited` | 154 | CONFIRMED |
| `0x0302fa70` | `tx_abort_and_radio_state_reset` | 272 | CONFIRMED |
| `0x0302fcd0` | `rf_frequency_adjust_and_display_refresh` | 360 | CONFIRMED |
| `0x0302fe94` | `channel_squelch_tone_scan_and_apply` | 378 | CONFIRMED |
| `0x030338d4` | `tx_status_display_adjust` | 66 | STRUCTURAL |
| `0x03034060` | `tx_contact_select_screen` | 570 | CONFIRMED |
| `0x03034624` | `tx_contact_index_rewrite_both_blocks` | 406 | CONFIRMED |
| `0x03034e98` | `tx_contact_select_index_advance` | 88 | CONFIRMED |
| `0x03036064` | `tx_gate_write_call_record_screen_code6fh` | 18 | STRUCTURAL |
| `0x03036078` | `tx_gate_write_call_record_screen_code6eh` | 18 | STRUCTURAL |
| `0x030360a0` | `tx_gate_write_call_record_screen_code6ch` | 18 | STRUCTURAL |
| `0x030360b4` | `tx_gate_write_call_record_screen_code6bh` | 18 | STRUCTURAL |
| `0x03037070` | `tx_stop_and_reset_to_idle` | 88 | STRUCTURAL |
| `0x03037378` | `tx_history_pop_release_a` | 84 | STRUCTURAL |
| `0x030373cc` | `tx_history_pop_release_b` | 84 | STRUCTURAL |
| `0x03037d78` | `diag_rssi_sql_numeric_draw` | 92 | STRUCTURAL |
| `0x03037ee8` | `rssi_sql_meter_tick_decrement` | 170 | CONFIRMED |
| `0x03037f94` | `rssi_sql_meter_tick_increment` | 174 | CONFIRMED |
| `0x030396b0` | `tx_gate_call_record_on_newline_marker` | 30 | CONFIRMED |
| `0x03039a3c` | `tx_gate_press_standby_action_dispatch` | 510 | STRUCTURAL |
| `0x0303be4a` | `frequency_step_number_screen_refresh` | 88 | STRUCTURAL |
| `0x03040b1c` | `tx_gate_call_record_toggle_a` | 36 | CONFIRMED |
| `0x03040f9c` | `tx_gate_call_record_toggle_b` | 36 | CONFIRMED |
| `0x0304142c` | `tx_pending_mbox_post_clear` | 68 | STRUCTURAL |
| `0x03047666` | `frequency_branch_dialog_init` | 102 | STRUCTURAL |
| `0x0304857c` | `band_range_select_screen` | 480 | CONFIRMED |
| `0x03048948` | `frequency_step_cycle_and_field_select_a` | 52 | STRUCTURAL |
| `0x03048afc` | `backlight_or_squelch_step_0to100_and_seconds_display` | 22 | STRUCTURAL |
| `0x03048c6c` | `frequency_step_cycle_and_field_select_b` | 52 | STRUCTURAL |
| `0x03054bb8` | `rf_transceiver_mode_init` | 154 | CONFIRMED |
| `0x03054c54` | `fd6818b_partial_display_mode_reconfigure` | 84 | CONFIRMED |
| `0x03054ca8` | `rf_mode_debounce_state_machine` | 188 | STRUCTURAL |
| `0x03054d80` | `event_queue_reset` | 32 | STRUCTURAL |
| `0x03054da0` | `rf_mode_state_clear_and_reinit_if_mode2` | 32 | CONFIRMED |
| `0x03054e00` | `fd6818b_reg_write_51h_or8000h` | 22 | STRUCTURAL |
| `0x03054e18` | `fd6818b_reg_write_51h_or9000h` | 22 | STRUCTURAL |
| `0x03054e30` | `fd6818b_compander_calibration_write` | 14 | CONFIRMED |
| `0x03055f88` | `rf_mode_transition_on_freq_delta` | 212 | CONFIRMED |
| `0x0305be64` | `tx_key_from_vfo_mode_guard` | 306 | STRUCTURAL |
| `0x0305e2c8` | `tx_led_tone_off_on_event_flag` | 50 | CONFIRMED |
| `0x0305e4e8` | `tx_dialog_event_state_dispatcher` | 400 | STRUCTURAL |
| `0x0305e9cc` | `tx_forbid_event_flag5_handler` | 44 | STRUCTURAL |
| `0x0305ea44` | `tx_event_flag_dispatcher` | 284 | STRUCTURAL |
| `0x0305fc24` | `tx_timeout_cleanup` | 114 | CONFIRMED |
| `0x0305ffe4` | `rssi_rolling_average_meter_update` | 122 | STRUCTURAL |
| `0x030602b0` | `tx_supervisory_tick` | 882 | CONFIRMED |
| `0x03060700` | `tx_state_transition_and_supervisory_tick` | 82 | CONFIRMED |
| `0x03060754` | `tx_state_main_task_loop` | 252 | CONFIRMED |
| `0x030609ec` | `tx_led_or_tone_off_conditional_variant_030609ec` | 26 | STRUCTURAL |
| `0x03060a08` | `tx_led_or_tone_off` | 10 | STRUCTURAL |
| `0x03060a14` | `tx_led_or_tone_off_conditional` | 26 | STRUCTURAL |
| `0x03060a30` | `tx_led_or_tone_on` | 10 | STRUCTURAL |
| `0x03060b78` | `tx_led_or_tone_service_tick_dispatch` | 18 | CONFIRMED |
| `0x03060b94` | `tx_led_tone_blink_toggle_variant_b` | 76 | CONFIRMED |
| `0x03060be0` | `tx_led_or_tone_on_and_conditional_off` | 10 | CONFIRMED |
| `0x03060bea` | `tx_led_or_tone_off_and_conditional` | 10 | CONFIRMED |
| `0x03060bf4` | `tx_led_tone_blink_toggle_variant_c` | 80 | CONFIRMED |
| `0x03060c44` | `tx_led_tone_blink_toggle_variant_a` | 120 | CONFIRMED |
| `0x03060cbc` | `tx_led_or_tone_blink_heartbeat` | 70 | CONFIRMED |
| `0x03060d02` | `tx_led_or_tone_toggle_off_on` | 8 | CONFIRMED |
| `0x03060d14` | `tx_led_tone_task_loop` | 94 | STRUCTURAL |
| `0x030645ac` | `fd6818b_channel_table_register_program` | 64 | STRUCTURAL |
| `0x030645ec` | `fd6818b_channel_table_program_idx5` | 12 | STRUCTURAL |
| `0x03065350` | `tx_disable_gate_check_wrapper` | 8 | CONFIRMED |
| `0x03065824` | `tx_abort_on_condition` | 58 | STRUCTURAL |
| `0x03067224` | `fd6818b_load_coeff_table_regs` | 106 | STRUCTURAL |
| `0x03067564` | `fd6818b_page0_enable_config` | 144 | STRUCTURAL |
| `0x030c6a24` | `tone_squelch_detection_frame_dispatch` | 308 | STRUCTURAL |
| `0x030c6f4c` | `tone_squelch_candidate_select_and_lock` | 258 | STRUCTURAL |
| `0x030c7410` | `tone_squelch_code_match_search` | 1642 | STRUCTURAL |
| `0x030c89f8` | `freq_range_validate_and_select` | 106 | CONFIRMED |
| `0x030cb390` | `tone_squelch_delay_line_shift` | 152 | STRUCTURAL |
| `0x030d01d8` | `tone_squelch_detection_frame_process` | 2178 | STRUCTURAL |
| `0x030d13ec` | `tone_squelch_state_history_update` | 1402 | STRUCTURAL |
