# dmr-protocol

180 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 84 |
| STRUCTURAL | 95 |
| RAW | 1 |

## Subdirectories

This subsystem is large enough to be split a second level. Grouping key: shared name prefix.

| Directory | Files |
|---|---|
| `dmr/` | 99 |
| `call/` | 37 |
| `modem/` | 21 |
| `slot/` | 8 |
| _(subsystem root)_ | 15 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x00010d04` | `fixed_capacity_keyed_record_update` | 64 | CONFIRMED |
| `0x00016ad0` | `modem_workmode_rfmode_reload` | 82 | CONFIRMED |
| `0x0002c2f4` | `fd6818b_reg_write` | 70 | CONFIRMED |
| `0x0002d358` | `dmr_ber_frame_compare_and_report` | 276 | STRUCTURAL |
| `0x030016ac` | `dmr_programming_protocol_command_loop` | 262 | CONFIRMED |
| `0x03002730` | `slot_table_find_and_store_a` | 64 | STRUCTURAL |
| `0x03002770` | `slot_list_table_clear_8` | 24 | STRUCTURAL |
| `0x03002888` | `slot_list_push_front_a` | 96 | STRUCTURAL |
| `0x030028f0` | `slot_list_push_back_a` | 84 | STRUCTURAL |
| `0x03003e4c` | `modem_wait_ready_then_proceed` | 66 | STRUCTURAL |
| `0x0300c2cc` | `modem_fm_bandwidth_write_0x5f` | 14 | STRUCTURAL |
| `0x0300c304` | `modem_fm_ptt_set` | 34 | STRUCTURAL |
| `0x0300c328` | `call_setup_sm_init` | 128 | STRUCTURAL |
| `0x0300c414` | `dmr_call_history_slot_append_batch_thunk` | 8 | STRUCTURAL |
| `0x0300d284` | `call_setup_debounce_and_ui_state_driver` | 326 | CONFIRMED |
| `0x0300dc94` | `dmr_rf_tx_task` | 80 | CONFIRMED |
| `0x0300de10` | `freq_bitpack_crc12_encode` | 80 | CONFIRMED |
| `0x0300e10c` | `ctcss_dcs_tone_apply` | 188 | CONFIRMED |
| `0x0300e7fc` | `fd6818b_write_cdcss_code_reg08` | 24 | STRUCTURAL |
| `0x030134c4` | `tx_gate_write_call_record` | 124 | STRUCTURAL |
| `0x03014d34` | `call_setup_mode_flag_dispatch` | 110 | STRUCTURAL |
| `0x030167a8` | `dmr_scan_entry_toggle_and_reload` | 278 | CONFIRMED |
| `0x03016f10` | `call_setup_control_char_and_reset_arg1h` | 10 | STRUCTURAL |
| `0x03016f28` | `call_setup_reset_or_forward` | 30 | STRUCTURAL |
| `0x0301bd7c` | `call_setup_timeout_countdown` | 192 | CONFIRMED |
| `0x0301cc18` | `modem_sem_create_and_gpio_0x18_high` | 20 | STRUCTURAL |
| `0x0301df0c` | `call_setup_step_permitted` | 168 | CONFIRMED |
| `0x0301dfb4` | `call_setup_step_ready_gate` | 120 | STRUCTURAL |
| `0x0301e034` | `call_setup_state_machine_step` | 1230 | CONFIRMED |
| `0x0301e528` | `call_setup_sm_reset_and_status_clear` | 74 | CONFIRMED |
| `0x0301e5d8` | `modem_buffer_indexed_byte_write_0301e5d8` | 34 | STRUCTURAL |
| `0x0301e628` | `modem_rf_mode_transition_apply` | 462 | STRUCTURAL |
| `0x0301e840` | `call_setup_sm_aux_field24_store` | 6 | CONFIRMED |
| `0x0301e858` | `call_setup_sm_aux_field_0x2c_store` | 12 | CONFIRMED |
| `0x0301e8dc` | `call_setup_sm_arm` | 26 | CONFIRMED |
| `0x0301e8f8` | `call_setup_sm_reset` | 22 | CONFIRMED |
| `0x0301e910` | `call_setup_full_reset_with_clock` | 26 | STRUCTURAL |
| `0x0301e9cc` | `dmr_call_setup_state_machine_task` | 216 | CONFIRMED |
| `0x0301ed68` | `modem_set_digital_mode_enable` | 46 | STRUCTURAL |
| `0x0301eda8` | `call_state_not_idle_check` | 48 | CONFIRMED |
| `0x0301f064` | `dmr_privacy_custom_key_delta_encode` | 14 | STRUCTURAL |
| `0x0301f074` | `dmr_privacy_alg_select_from_cps_type` | 168 | CONFIRMED |
| `0x0301f11c` | `dmr_privacy_type_apply` | 34 | CONFIRMED |
| `0x0301f1c0` | `call_setup_ack_retry_and_history_log_loop` | 3148 | CONFIRMED |
| `0x0301fe80` | `call_setup_task_main_loop` | 78 | STRUCTURAL |
| `0x0301fed0` | `call_setup_connect_with_retry` | 332 | STRUCTURAL |
| `0x03020044` | `dmr_call_setup_teardown_event_loop` | 1600 | CONFIRMED |
| `0x0302072c` | `dmr_config_callback_variant_dispatcher` | 28 | STRUCTURAL |
| `0x03020a8c` | `rxcsbk_build_reply_task` | 842 | CONFIRMED |
| `0x03020f70` | `call_setup_state_machine_step_with_timeout` | 226 | CONFIRMED |
| `0x0302108c` | `call_setup_or_teardown_handler` | 492 | CONFIRMED |
| `0x0302323c` | `modem_layer2_regs_clear` | 22 | CONFIRMED |
| `0x03023254` | `modem_set_layer2_mode` | 150 | CONFIRMED |
| `0x030232ec` | `modem_set_mode_variant` | 56 | CONFIRMED |
| `0x03023324` | `modem_mode_select` | 192 | CONFIRMED |
| `0x030233f8` | `dmr_call_config_reset_and_flag` | 48 | CONFIRMED |
| `0x03023428` | `modem_stop` | 168 | STRUCTURAL |
| `0x030234d0` | `dmr_call_state_timeout_check` | 130 | STRUCTURAL |
| `0x0302357c` | `modem_queue_drain_and_stop` | 140 | STRUCTURAL |
| `0x030238b4` | `dmr_call_setup_block_d_byte5_read` | 6 | CONFIRMED |
| `0x03023a68` | `dmr_rx_deferred_frame_dispatch` | 112 | STRUCTURAL |
| `0x03023af4` | `call_setup_set_pending_flag` | 8 | CONFIRMED |
| `0x03023b10` | `call_setup_sm_aux_field0xb_is_zero` | 10 | STRUCTURAL |
| `0x03023b6c` | `modem_tx_enable` | 26 | STRUCTURAL |
| `0x03023b90` | `call_setup_target_present_check` | 48 | CONFIRMED |
| `0x03023bc0` | `call_setup_sm_field0x72_and_0x78_clear` | 14 | CONFIRMED |
| `0x03023bd0` | `modem_timeout_stop_and_history_record_task` | 198 | CONFIRMED |
| `0x03023cf0` | `call_setup_sm_field0x72_not_one` | 14 | STRUCTURAL |
| `0x03023f4c` | `call_setup_frame_ack_state_machine` | 466 | STRUCTURAL |
| `0x0302417c` | `dmr_lc_call_setup_header_build` | 52 | STRUCTURAL |
| `0x030241b4` | `dmr_call_config_state_reset_and_arm_timer` | 116 | STRUCTURAL |
| `0x030242b8` | `dmr_call_history_slot_append_batch` | 358 | STRUCTURAL |
| `0x030244ac` | `dmr_burst_assemble_and_dispatch` | 158 | STRUCTURAL |
| `0x030245e0` | `dmr_burst_freq_field_pack_and_timer_arm` | 190 | STRUCTURAL |
| `0x030246a8` | `dmr_rx_burst_timer_setup_and_start` | 98 | STRUCTURAL |
| `0x030248fc` | `dmr_rx_control_state_update_from_status` | 44 | STRUCTURAL |
| `0x0302499c` | `dmr_rx_burst_dispatch` | 1342 | STRUCTURAL |
| `0x03026158` | `dmr_message_split_into_history_slots` | 1108 | CONFIRMED |
| `0x030269f0` | `dmr_history_bitmask_record_builder` | 170 | CONFIRMED |
| `0x03026c4c` | `dmr_text_packet_builder_and_log` | 694 | CONFIRMED |
| `0x03026f0c` | `call_setup_packet_build_and_history_push` | 456 | CONFIRMED |
| `0x03027368` | `dmr_call_config_state_not_idle` | 12 | CONFIRMED |
| `0x03027374` | `dmr_call_config_field0x9_not_one` | 12 | STRUCTURAL |
| `0x030273b4` | `dmr_call_config_state_field2_not_one` | 20 | CONFIRMED |
| `0x030273c8` | `call_setup_state_advance_gate` | 36 | CONFIRMED |
| `0x0302741c` | `dmr_incoming_call_setup_conflict_resolve` | 478 | CONFIRMED |
| `0x03027618` | `dmr_call_setup_accept_and_signal` | 72 | STRUCTURAL |
| `0x03027688` | `dmr_call_config_reset` | 52 | STRUCTURAL |
| `0x03027720` | `call_setup_target_id_decode_and_check` | 1244 | STRUCTURAL |
| `0x03027c30` | `dmr_call_setup_event_dispatch` | 548 | CONFIRMED |
| `0x03027e80` | `call_setup_queue_entry_append_and_dialog_advance` | 68 | STRUCTURAL |
| `0x03027ec4` | `dmr_call_config_slot_store_and_flag_post_0x2000000` | 36 | STRUCTURAL |
| `0x03027ee8` | `dmr_call_config_slot_store_and_dialog_substate4` | 46 | STRUCTURAL |
| `0x03027f16` | `dmr_call_setup_message_dispatch_by_type` | 286 | CONFIRMED |
| `0x03028044` | `call_setup_queue_entry_append_flag_signal` | 32 | STRUCTURAL |
| `0x03028064` | `dmr_call_config_slot_store_and_flag_post_0x1000000` | 50 | STRUCTURAL |
| `0x03028096` | `call_setup_frame_ack_dispatch_wrapper` | 8 | CONFIRMED |
| `0x0302809e` | `dmr_state_dependent_table_write` | 36 | STRUCTURAL |
| `0x03028154` | `dmr_call_setup_message_handler` | 170 | CONFIRMED |
| `0x03028214` | `dmr_call_setup_frame_unpack_and_dispatch` | 290 | STRUCTURAL |
| `0x03028338` | `dmr_call_setup_response_process_and_signal` | 864 | STRUCTURAL |
| `0x030286d8` | `dmr_call_state_machine_step` | 1250 | STRUCTURAL |
| `0x03028c40` | `dmr_call_setup_accept_entry` | 6 | STRUCTURAL |
| `0x03028c46` | `dmr_call_setup_response_entry` | 6 | STRUCTURAL |
| `0x03028c4c` | `dmr_call_setup_frame_dispatch_entry` | 6 | STRUCTURAL |
| `0x03028c52` | `dmr_call_setup_event_dispatch_entry` | 6 | STRUCTURAL |
| `0x03028c64` | `dmr_call_config_reset_entry` | 6 | STRUCTURAL |
| `0x03028c78` | `dmr_embedded_lc_superframe_process` | 1716 | STRUCTURAL |
| `0x030293ac` | `modem_control_state_stop` | 26 | CONFIRMED |
| `0x0302945c` | `slottimer_dmr_slot_state` | 88 | STRUCTURAL |
| `0x03029620` | `dmr_call_history_slot_register` | 138 | CONFIRMED |
| `0x030296ac` | `dmr_call_history_slot_register_short` | 92 | CONFIRMED |
| `0x0302990c` | `history_record_push_type3` | 70 | CONFIRMED |
| `0x03029ae2` | `dmr_frame_pack_and_history_record` | 124 | STRUCTURAL |
| `0x03029d0c` | `dmr_layer2_frame_build_and_send` | 128 | STRUCTURAL |
| `0x0303056c` | `rx_forbid_flag_conditional_clear` | 62 | STRUCTURAL |
| `0x03033310` | `talkgroup_index_decode_paged` | 50 | CONFIRMED |
| `0x03034ae8` | `talkgroup_lookup_by_name` | 244 | CONFIRMED |
| `0x03034be4` | `talkgroup_binary_search_by_id_and_flag` | 372 | STRUCTURAL |
| `0x03035070` | `dmr_contact_record_copy` | 66 | STRUCTURAL |
| `0x03035880` | `talkgroup_binary_search_dispatch_by_radio_mode_flag` | 56 | CONFIRMED |
| `0x0303611c` | `call_setup_state_dispatch` | 166 | CONFIRMED |
| `0x03043134` | `dmr_setting_0x47_read_store` | 12 | STRUCTURAL |
| `0x03043164` | `dmr_setting_0x4b_read_store` | 12 | STRUCTURAL |
| `0x03043188` | `dmr_setting_0x4e_read_store` | 12 | STRUCTURAL |
| `0x030431a0` | `dmr_setting_0x4f_read_store` | 44 | STRUCTURAL |
| `0x03043438` | `dmr_channel_load_from_flash_or_dialog` | 396 | CONFIRMED |
| `0x0304ce44` | `call_setup_aux_field24_set` | 12 | STRUCTURAL |
| `0x0304d8a0` | `dmr_id_log_or_zone_name_confirm_dispatch` | 312 | STRUCTURAL |
| `0x0304e044` | `dmr_control_message_dispatch_and_channel_commit` | 156 | CONFIRMED |
| `0x0304eb28` | `dmr_menu_field_edit_key_dispatch` | 32 | CONFIRMED |
| `0x03052d48` | `dmr_list_header_load` | 58 | CONFIRMED |
| `0x03052e88` | `dmr_contact_list_menu_row_render_group3` | 738 | CONFIRMED |
| `0x03053180` | `dmr_contact_list_menu_row_render_group1` | 856 | CONFIRMED |
| `0x03053508` | `dmr_contact_list_menu_row_render_group2` | 856 | CONFIRMED |
| `0x030538b0` | `dmr_contact_list1_active_count` | 176 | CONFIRMED |
| `0x03053960` | `dmr_list_count_block10_clamped` | 54 | STRUCTURAL |
| `0x03053998` | `dmr_list_headers_load_and_validate` | 332 | CONFIRMED |
| `0x03053afc` | `dmr_list_subsystem_init` | 16 | STRUCTURAL |
| `0x03055850` | `modem_buffer_char_remap_write_03055850` | 48 | STRUCTURAL |
| `0x03055eb8` | `dmr_user_register_next_free_bitmap_slot` | 98 | CONFIRMED |
| `0x030560e8` | `dmr_id_log_write` | 190 | CONFIRMED |
| `0x03056880` | `dmr_id_log_append` | 126 | STRUCTURAL |
| `0x0305b798` | `dmr_scan_list_row_up_or_exit` | 74 | CONFIRMED |
| `0x0305ca48` | `dmr_privacy_key_load_and_mi_draw` | 192 | CONFIRMED |
| `0x0305df58` | `call_setup_control_char_and_reset` | 122 | CONFIRMED |
| `0x03060a4c` | `call_status_indicator_byte_compute` | 214 | CONFIRMED |
| `0x0306674c` | `modem_c7000_param_table_defaults_init` | 88 | CONFIRMED |
| `0x0306af04` | `dmr_command_subop_dispatch_with_crit_section` | 188 | CONFIRMED |
| `0x030c0924` | `slot_table_find_and_store_b` | 64 | STRUCTURAL |
| `0x030c0964` | `slot_list_table_clear_64` | 24 | STRUCTURAL |
| `0x030c0b0c` | `slot_list_push_front_b` | 96 | STRUCTURAL |
| `0x030c0b6c` | `slot_list_push_back_b` | 84 | STRUCTURAL |
| `0x030c21a0` | `dmr_message_dispatch_with_reentrancy_guard` | 214 | CONFIRMED |
| `0x030c3980` | `dmr_channel_frequency_validate_and_commit` | 460 | STRUCTURAL |
| `0x030c4480` | `dmr_privacy_mi_advance` | 164 | CONFIRMED |
| `0x030c458c` | `dmr_type_s_scramble_permute_block` | 2234 | STRUCTURAL |
| `0x030c5348` | `dmr_privacy_rx_keystream_setup` | 202 | CONFIRMED |
| `0x030c5414` | `dmr_27byte_block_keyed_scramble` | 140 | STRUCTURAL |
| `0x030c54a0` | `dmr_27byte_block_keyed_descramble` | 150 | STRUCTURAL |
| `0x030c5538` | `dmr_privacy_keystream_apply` | 298 | CONFIRMED |
| `0x030c5664` | `dmr_privacy_keystream_apply_rx_variant` | 298 | CONFIRMED |
| `0x030c5790` | `dmr_privacy_mi_embedded_encode` | 100 | STRUCTURAL |
| `0x030c57f4` | `dmr_privacy_tx_keystream_setup` | 256 | CONFIRMED |
| `0x030c59ac` | `modem_boot_selftest_and_init` | 120 | STRUCTURAL |
| `0x030c5c58` | `dmr_27byte_block_transform_three_chunks_thunk` | 8 | STRUCTURAL |
| `0x030c5ec8` | `modem_codec_pool_and_state_init` | 712 | STRUCTURAL |
| `0x030c6458` | `dmr_27byte_block_transform_three_chunks` | 88 | STRUCTURAL |
| `0x030c69b0` | `dmr_state_init_with_lcg_fill` | 116 | STRUCTURAL |
| `0x030c7318` | `dmr_channel_params_equal` | 184 | STRUCTURAL |
| `0x030c7edc` | `vocoder_frame_params_decode` | 644 | STRUCTURAL |
| `0x030c9378` | `dmr_message_checksum_verify_and_status_resolve` | 500 | STRUCTURAL |
| `0x030c956c` | `dmr_signaling_param_block_build_and_dispatch` | 538 | STRUCTURAL |
| `0x030c9920` | `dmr_filter_block_init_defaults` | 54 | STRUCTURAL |
| `0x030cd000` | `dmr_privacy_mi_expand_lfsr` | 140 | CONFIRMED |
| `0x030cd08c` | `dmr_privacy_aes_ofb_keystream_128` | 74 | CONFIRMED |
| `0x030cd0d8` | `dmr_privacy_alg2_key_setup_stub` | 2 | CONFIRMED |
| `0x030cd0dc` | `dmr_privacy_alg2_block_op_stub` | 2 | CONFIRMED |
| `0x030cd0e4` | `dmr_privacy_alg2_block_encrypt_stub` | 2 | CONFIRMED |
| `0x030cff5c` | `dmr_block_decode_tag6_dispatch` | 392 | RAW |
