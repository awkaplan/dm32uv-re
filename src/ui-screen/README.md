# ui-screen

196 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 65 |
| STRUCTURAL | 131 |
| RAW | 0 |

## Subdirectories

This subsystem is large enough to be split a second level. Grouping key: shared name prefix.

| Directory | Files |
|---|---|
| `vfo/` | 61 |
| `history/` | 45 |
| `status/` | 31 |
| `ui_mode/` | 19 |
| `ui_event/` | 13 |
| _(subsystem root)_ | 27 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x0002deb8` | `vfo_active_side_mode_nibble` | 89 | STRUCTURAL |
| `0x0300c85c` | `ui_mode_noop_stub_variant_0300c85c` | 10 | STRUCTURAL |
| `0x0300cdb0` | `ui_mode_group_flag_post` | 24 | STRUCTURAL |
| `0x0300cf8c` | `ui_mode_group1_flag_set` | 76 | STRUCTURAL |
| `0x0300cfd8` | `ui_mode_group2_flag_set` | 76 | STRUCTURAL |
| `0x0300d028` | `ui_mode_group_flag_set_and_post` | 58 | CONFIRMED |
| `0x0300d064` | `ui_group_flag_set_and_notify` | 40 | STRUCTURAL |
| `0x0300d0a4` | `ui_mode_dispatch` | 26 | CONFIRMED |
| `0x0300d0cc` | `ui_mode_reset` | 30 | STRUCTURAL |
| `0x0300d0ea` | `ui_mode_set1` | 38 | STRUCTURAL |
| `0x0300d110` | `ui_mode_set2` | 38 | STRUCTURAL |
| `0x0300d136` | `ui_mode_set4` | 16 | STRUCTURAL |
| `0x0300d146` | `ui_mode_toggle_5_or_reset` | 64 | STRUCTURAL |
| `0x0300d186` | `ui_mode_dispatch_caller_0x20` | 8 | STRUCTURAL |
| `0x0300d18e` | `ui_mode_set8_group2` | 16 | STRUCTURAL |
| `0x0300d19e` | `ui_mode_reset_group2_conditional` | 156 | STRUCTURAL |
| `0x0300d25c` | `ui_mode_set6_group4` | 16 | STRUCTURAL |
| `0x0300d26c` | `ui_mode_reset_group4` | 14 | STRUCTURAL |
| `0x0300d27a` | `ui_mode_noop_stub` | 8 | CONFIRMED |
| `0x0300dd94` | `vfo_display_config_apply` | 88 | STRUCTURAL |
| `0x0300de8c` | `vfo_step_field_write` | 124 | CONFIRMED |
| `0x0300f2a4` | `vfo_display_state_nibble_bits_check` | 40 | STRUCTURAL |
| `0x030131e4` | `ui_background_periodic_subtask_dispatcher` | 482 | CONFIRMED |
| `0x03014ae4` | `ui_dialog_tick_scheduler` | 512 | CONFIRMED |
| `0x03014ed4` | `request_display_refresh` | 20 | STRUCTURAL |
| `0x03015050` | `vfo_freq_display_refresh` | 602 | STRUCTURAL |
| `0x030152cc` | `ui_key_and_menu_event_dispatch_loop` | 294 | CONFIRMED |
| `0x030154a0` | `vfo_ab_display_redraw_dispatch` | 336 | CONFIRMED |
| `0x03015610` | `ui_event_notify_code21_entry_a` | 10 | STRUCTURAL |
| `0x0301561c` | `ui_event_notify_code21_entry_b` | 10 | STRUCTURAL |
| `0x03015628` | `ui_event_notify_code21_entry_c` | 10 | STRUCTURAL |
| `0x03015634` | `ui_event_notify_code21_entry_d` | 10 | STRUCTURAL |
| `0x03015640` | `ui_event_notify_code21_entry_e` | 10 | STRUCTURAL |
| `0x0301564c` | `ui_event_0x21_conditional_notify` | 44 | STRUCTURAL |
| `0x03015988` | `ui_key_commit_gate_mode0b` | 128 | STRUCTURAL |
| `0x03015a08` | `ui_key_commit_gate_mode0b_variant2` | 108 | STRUCTURAL |
| `0x03015a74` | `vfo_key_cursor_back` | 66 | STRUCTURAL |
| `0x03015d0c` | `vfo_channel_step_on_key_event` | 184 | CONFIRMED |
| `0x03015e5c` | `vfo_save_to_memory_channel` | 444 | CONFIRMED |
| `0x03016030` | `vfo_save_to_memory_or_clear_channel` | 436 | CONFIRMED |
| `0x030161fc` | `vfo_scan_add_toggle_on_poll_change` | 132 | STRUCTURAL |
| `0x03016ea4` | `ui_key_commit_gate_mode1e` | 108 | STRUCTURAL |
| `0x03017464` | `ui_notify_event_0x2d_gated` | 42 | STRUCTURAL |
| `0x03017548` | `ui_event_notify_dispatch_by_code` | 126 | CONFIRMED |
| `0x03018ed0` | `vfo_standby_row_render` | 1248 | CONFIRMED |
| `0x0301a7d0` | `vfo_frequency_panel_render` | 742 | CONFIRMED |
| `0x0301aafc` | `status_field_glyph_or_ascii_render` | 88 | CONFIRMED |
| `0x0301ab54` | `vfo_active_side_icon_draw` | 82 | STRUCTURAL |
| `0x0301b990` | `ui_flag_post_0x40000_if_check` | 22 | STRUCTURAL |
| `0x0301be6c` | `vfo_field_write_bit4_at_0x15` | 278 | CONFIRMED |
| `0x0301cc68` | `ui_inactivity_timeout_tick` | 1088 | STRUCTURAL |
| `0x0301e600` | `status_byte_bit5_set_clear` | 38 | CONFIRMED |
| `0x03020e40` | `history_mode_entry_init` | 46 | STRUCTURAL |
| `0x03021ca4` | `ui_event_notify` | 40 | CONFIRMED |
| `0x03021ccc` | `ui_event_0xf_if_status_flag40` | 26 | STRUCTURAL |
| `0x03024828` | `history_record_push` | 210 | CONFIRMED |
| `0x03025e40` | `history_record_push_typed` | 80 | STRUCTURAL |
| `0x030265ac` | `history_record_build_typed_dispatch` | 230 | STRUCTURAL |
| `0x03026694` | `history_message_fragment_and_link` | 710 | CONFIRMED |
| `0x03026960` | `history_slot_alloc_with_data` | 144 | STRUCTURAL |
| `0x030270e4` | `history_log_type3_packet_builder` | 488 | STRUCTURAL |
| `0x030294f8` | `history_slot_allocate` | 90 | STRUCTURAL |
| `0x0302955c` | `history_slot_link_append` | 176 | STRUCTURAL |
| `0x03029838` | `history_slot_allocate_and_init` | 212 | CONFIRMED |
| `0x0302996c` | `history_event_record_build_type0xb8` | 40 | STRUCTURAL |
| `0x03029994` | `history_event_record_build_type0x84` | 44 | STRUCTURAL |
| `0x030299c0` | `history_event_record_build_type0x85` | 48 | STRUCTURAL |
| `0x030299f0` | `history_event_record_build_type0xa0` | 44 | STRUCTURAL |
| `0x03029a1c` | `history_event_record_build_type0xa6` | 50 | STRUCTURAL |
| `0x03029a4e` | `history_event_record_build_type0xbd` | 60 | STRUCTURAL |
| `0x03029a8a` | `history_event_record_build_type0xa7` | 44 | STRUCTURAL |
| `0x03029ab6` | `history_event_record_build_type0x9f` | 44 | STRUCTURAL |
| `0x03029b5e` | `history_event_record_build_type0x9d` | 42 | STRUCTURAL |
| `0x03029b88` | `history_record_conditional_push_by_type` | 68 | STRUCTURAL |
| `0x03029bd0` | `history_record_push_type3_repeated` | 92 | STRUCTURAL |
| `0x03029cd0` | `history_record_build_type3` | 24 | STRUCTURAL |
| `0x03029d9c` | `history_push_call_and_type3` | 52 | CONFIRMED |
| `0x03029dd0` | `history_event_record_build_dispatch` | 70 | STRUCTURAL |
| `0x03029e24` | `history_event_record_build_type0x1f_b` | 26 | STRUCTURAL |
| `0x03029e3e` | `history_event_record_build_type0x1d_b` | 28 | STRUCTURAL |
| `0x03029e5a` | `history_event_record_build_type0x24_a` | 28 | STRUCTURAL |
| `0x03029e76` | `history_event_record_build_type0x24_b` | 28 | STRUCTURAL |
| `0x03029e92` | `history_event_record_build_type0x24_c` | 26 | STRUCTURAL |
| `0x03029eac` | `history_event_record_build_type0x27` | 44 | STRUCTURAL |
| `0x0302c3a8` | `status_datetime_dialog_pending_check` | 34 | CONFIRMED |
| `0x0302d01c` | `vfo_status_screen` | 338 | CONFIRMED |
| `0x0302d530` | `status_row_redraw_with_selftoggle_noop` | 126 | CONFIRMED |
| `0x0302e190` | `vfo_zone_display_refresh` | 54 | STRUCTURAL |
| `0x0302e85c` | `vfo_freq_display_index_from_offset` | 14 | CONFIRMED |
| `0x0302e9c0` | `vfo_scroll_list_cursor_advance` | 40 | STRUCTURAL |
| `0x0302ec58` | `vfo_freq_list_cursor_advance` | 34 | CONFIRMED |
| `0x0302ee14` | `ui_mode_periodic_state_tick` | 1240 | STRUCTURAL |
| `0x0302f344` | `vfo_frequency_digit_cursor_step_back` | 120 | CONFIRMED |
| `0x0302f41c` | `vfo_freq_display_field0x5c_in_range` | 70 | STRUCTURAL |
| `0x030305ac` | `ui_event_notify_alt` | 88 | CONFIRMED |
| `0x03030a04` | `vfo_standby_frequency_panel_render` | 1072 | STRUCTURAL |
| `0x03030ec8` | `vfo_record_offset_select2` | 90 | CONFIRMED |
| `0x03030f24` | `vfo_field_write_2bit_at_8_direct_commit` | 150 | STRUCTURAL |
| `0x03030fbc` | `vfo_field_write_bit7_at_0x9` | 72 | CONFIRMED |
| `0x03031004` | `vfo_record_offset_select1` | 78 | CONFIRMED |
| `0x0303105c` | `vfo_field_write_1bit_at_10` | 72 | CONFIRMED |
| `0x030310a4` | `vfo_field_write_3bit_at_0x16` | 150 | CONFIRMED |
| `0x0303113c` | `vfo_field_write_2bit_at_0x19` | 72 | CONFIRMED |
| `0x03031398` | `vfo_frequency_write` | 136 | CONFIRMED |
| `0x0303169c` | `vfo_record_read` | 340 | STRUCTURAL |
| `0x030317f0` | `vfo_screen_redraw` | 896 | CONFIRMED |
| `0x03033234` | `status_queue_push_and_signal` | 72 | CONFIRMED |
| `0x03033380` | `history_record_lookup_by_type` | 274 | STRUCTURAL |
| `0x030334c8` | `history_record_detail_screen_draw` | 208 | STRUCTURAL |
| `0x03033794` | `range_count_status_display` | 232 | STRUCTURAL |
| `0x030358c8` | `status_field_multi_step_state_machine` | 310 | CONFIRMED |
| `0x03035b44` | `status_message_save_on_confirm` | 56 | STRUCTURAL |
| `0x03035d88` | `menu_confirm_apply_handler3` | 236 | STRUCTURAL |
| `0x03035ec4` | `write_status_mode_byte_pair` | 16 | STRUCTURAL |
| `0x03036c00` | `history_queue_pop` | 166 | STRUCTURAL |
| `0x03037008` | `history_queue_pop_clear_bit0` | 22 | STRUCTURAL |
| `0x030370c8` | `history_pop_clear_pending_flags` | 72 | STRUCTURAL |
| `0x03037434` | `history_queue_pop_thunk` | 8 | STRUCTURAL |
| `0x0303743c` | `history_pop_or_status_flag2` | 42 | STRUCTURAL |
| `0x030376b4` | `ui_key_text_entry_or_history_dispatch` | 98 | STRUCTURAL |
| `0x03039518` | `ui_call_guard_input_dispatch_a` | 160 | STRUCTURAL |
| `0x030395f4` | `ui_call_guard_input_dispatch_b` | 146 | STRUCTURAL |
| `0x030396d0` | `history_list_row_lookup` | 138 | STRUCTURAL |
| `0x03039988` | `vfo_ab_swap` | 180 | STRUCTURAL |
| `0x03039d30` | `vfo_label_draw` | 130 | CONFIRMED |
| `0x0303b8d8` | `vfo_offset_select_and_string_display` | 46 | STRUCTURAL |
| `0x0303b906` | `vfo_status_screen_number_and_id_redraw` | 794 | STRUCTURAL |
| `0x0303bd24` | `range_count_status_dialog_screen` | 72 | STRUCTURAL |
| `0x0303fa04` | `ui_event_code_dispatch_main` | 396 | CONFIRMED |
| `0x0304023a` | `history_dialog_cancel_and_release_mutex` | 8 | STRUCTURAL |
| `0x0304026c` | `vfo_ab_swap_key_and_history_dispatch` | 22 | STRUCTURAL |
| `0x030406da` | `history_dialog_cancel_and_release_mutex_variant` | 62 | STRUCTURAL |
| `0x03040a80` | `ui_event_loop_entry_with_dialog` | 12 | STRUCTURAL |
| `0x03041074` | `call_record_display_update_fwd` | 6 | STRUCTURAL |
| `0x03042040` | `vfo_display_option_count_clamp` | 80 | CONFIRMED |
| `0x03045e90` | `vfo_display_step_index_compute` | 262 | STRUCTURAL |
| `0x0304707c` | `vfo_record_offset_select4` | 518 | STRUCTURAL |
| `0x0304a200` | `vfo_load_side_config` | 188 | CONFIRMED |
| `0x0304cf30` | `status_mode_reset_and_post_0x62_on_bit1` | 44 | STRUCTURAL |
| `0x0304d54c` | `status_mode_byte_pair_select_and_write` | 64 | CONFIRMED |
| `0x0304e232` | `status_mode_write_0x23_1_variant_a` | 10 | CONFIRMED |
| `0x0304e254` | `status_mode_write_0x23_1_variant_b` | 10 | CONFIRMED |
| `0x0304e2f8` | `history_entry_numeric_display_and_pop` | 262 | STRUCTURAL |
| `0x0304e560` | `status_mode_or_settings_menu_command_dispatch` | 24 | CONFIRMED |
| `0x0304e5a0` | `status_mode_write_0x23_1_variant_c` | 10 | CONFIRMED |
| `0x0304e828` | `status_mode_write_from_indexed_field_a` | 20 | STRUCTURAL |
| `0x0304ece4` | `status_dialog_request_by_code_dispatch_b` | 218 | CONFIRMED |
| `0x0304f168` | `status_mode_write_from_indexed_field_b` | 20 | STRUCTURAL |
| `0x0304f17c` | `status_mode_write_or_history_pop_pair` | 56 | CONFIRMED |
| `0x0304f24c` | `status_dialog_show_or_request_by_code` | 80 | STRUCTURAL |
| `0x03050438` | `status_mode_write_from_indexed_field_c` | 22 | STRUCTURAL |
| `0x030508c0` | `status_field_dispatch_variant_6` | 46 | STRUCTURAL |
| `0x030508ee` | `status_field_dispatch_variant_7` | 46 | STRUCTURAL |
| `0x0305091c` | `status_field_dispatch_variant_3` | 154 | STRUCTURAL |
| `0x030509b6` | `status_field_dispatch_variant_1` | 46 | STRUCTURAL |
| `0x030509e4` | `status_field_dispatch_variant_2` | 46 | STRUCTURAL |
| `0x0305169c` | `status_dialog_request_by_code_dispatch` | 130 | CONFIRMED |
| `0x03051764` | `status_field_dispatch_variant_5` | 46 | STRUCTURAL |
| `0x03051792` | `status_mode_screen_select_and_write_var2` | 46 | STRUCTURAL |
| `0x030517c0` | `status_field2_dispatch_with_table_select` | 154 | STRUCTURAL |
| `0x0305185a` | `status_mode_screen_select_and_write_var1` | 46 | STRUCTURAL |
| `0x03051888` | `status_field_dispatch_variant_4` | 46 | STRUCTURAL |
| `0x03052518` | `history_or_channel_selection_key_dispatch` | 462 | STRUCTURAL |
| `0x03052744` | `history_entry_stage` | 32 | STRUCTURAL |
| `0x03052764` | `history_entry_verify_post_or_flag` | 56 | STRUCTURAL |
| `0x030527f4` | `history_entry_cancel_pending` | 32 | STRUCTURAL |
| `0x03052b90` | `call_record_display_update` | 114 | STRUCTURAL |
| `0x030546dc` | `ui_tick_prescaler_post` | 36 | STRUCTURAL |
| `0x0305476c` | `ui_periodic_maintenance_task_loop` | 462 | CONFIRMED |
| `0x03055574` | `ui_deferred_event_task_loop` | 144 | STRUCTURAL |
| `0x030560ac` | `vfo_tx_contact_field_read` | 58 | STRUCTURAL |
| `0x0305624c` | `vfo_channel_apply_delegate` | 10 | STRUCTURAL |
| `0x03056258` | `vfo_tx_contact_field_read_wrapper` | 10 | CONFIRMED |
| `0x030562d8` | `vfo_record_offset_select3` | 74 | CONFIRMED |
| `0x03056324` | `vfo_scan_add_toggle` | 262 | STRUCTURAL |
| `0x03056c54` | `vfo_field_write_bit4_at_0xd` | 234 | CONFIRMED |
| `0x03056d40` | `vfo_field_write_nibble_high` | 208 | CONFIRMED |
| `0x03056e24` | `vfo_field_write_bit5_at_0xd` | 234 | CONFIRMED |
| `0x03056f10` | `vfo_field_write_nibble_low_at_0xd` | 224 | STRUCTURAL |
| `0x03056ff8` | `vfo_field_write_6bit_at_0xf` | 226 | STRUCTURAL |
| `0x030572e0` | `vfo_field_write_byte_at_0x1b` | 246 | STRUCTURAL |
| `0x0305afe0` | `ui_countdown_decrement_wrap` | 60 | CONFIRMED |
| `0x0305ba9c` | `status_byte_bit5_set_clear_wrapper` | 12 | CONFIRMED |
| `0x0305cc74` | `vfo_field_write_byte_at_0xe` | 174 | STRUCTURAL |
| `0x0305cd24` | `vfo_field_write_bit6_at_0xf` | 294 | STRUCTURAL |
| `0x0305d984` | `ui_notify_0x22_on_bit3_set_and_bit1_clear` | 38 | CONFIRMED |
| `0x0305e7c8` | `ui_key_event_dispatcher` | 502 | CONFIRMED |
| `0x0305ee70` | `ui_event_flag_dispatch_loop` | 188 | CONFIRMED |
| `0x03060060` | `vfo_display_debounce_and_hw_flag_clear` | 468 | STRUCTURAL |
| `0x03060a3c` | `ui_background_flag_post_0x4000` | 14 | STRUCTURAL |
| `0x03060e3c` | `ui_mode_noop_stub_variant_03060e3c` | 10 | STRUCTURAL |
| `0x03061f80` | `vfo_field_write_2bit_at_0xc` | 214 | STRUCTURAL |
| `0x03062064` | `vfo_field_write_2bit_at_8_v2` | 212 | STRUCTURAL |
| `0x030641f4` | `vfo_apply_active_side_config` | 140 | CONFIRMED |
| `0x03064280` | `vfo_exit_dual_watch_and_refresh` | 64 | CONFIRMED |
| `0x03064518` | `vfo_sync_active_side_on_ptt` | 62 | CONFIRMED |
