# input-keypad

94 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 26 |
| STRUCTURAL | 68 |
| RAW | 0 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x0300e2c0` | `ptt_preamble_end_ui_audio_setup_1` | 160 | STRUCTURAL |
| `0x03012e14` | `keypad_scan_begin_mux_rows_drive_low` | 68 | CONFIRMED |
| `0x03012f58` | `keypad_debounce_and_commit_event` | 190 | CONFIRMED |
| `0x0301305c` | `keypad_read_pin_0x32_active_low` | 14 | STRUCTURAL |
| `0x0301306c` | `keypad_debounced_input_poll_a` | 98 | STRUCTURAL |
| `0x030130d0` | `keypad_read_pin_0x31_active_low` | 14 | STRUCTURAL |
| `0x030130e0` | `keypad_debounced_input_poll_b` | 100 | STRUCTURAL |
| `0x03013660` | `keypad_scan_and_map_pressed_key` | 226 | STRUCTURAL |
| `0x03013744` | `keypad_poll_and_dispatch_key_event` | 540 | STRUCTURAL |
| `0x030139c0` | `keypad_event_maybe_forward_to_dialog` | 122 | STRUCTURAL |
| `0x03014060` | `keypad_key_allowed_by_bitmask_a` | 48 | STRUCTURAL |
| `0x030140a8` | `keypad_key_allowed_check_bel_or_hash` | 34 | STRUCTURAL |
| `0x030140cc` | `keypad_key_allowed_check_hash_or_enq_mode_dependent` | 94 | STRUCTURAL |
| `0x0301412c` | `keypad_key_allowed_by_bitmask_mode_dependent` | 108 | STRUCTURAL |
| `0x03014434` | `keypad_tmrkey_gated_dispatch_a` | 122 | STRUCTURAL |
| `0x030144d0` | `keypad_tmrkey_gated_dispatch_b` | 122 | STRUCTURAL |
| `0x03014584` | `keypad_gate_dispatch_mask01` | 110 | STRUCTURAL |
| `0x03014610` | `keypad_gate_dispatch_mask04` | 114 | STRUCTURAL |
| `0x03014684` | `keypad_gate_dispatch_mask02` | 114 | STRUCTURAL |
| `0x03014748` | `keypad_key_event_post_0x16` | 118 | STRUCTURAL |
| `0x030147c0` | `keypad_key_event_post_0x15` | 118 | STRUCTURAL |
| `0x0301496c` | `keypad_key_event_post_0x1e` | 118 | STRUCTURAL |
| `0x03014a00` | `keypad_back_key_press_handler` | 84 | CONFIRMED |
| `0x03014a54` | `keypad_tmrkey_expiry_dispatch` | 74 | STRUCTURAL |
| `0x03016d48` | `keypad_tmrkey_event_post_and_close` | 28 | CONFIRMED |
| `0x03016d64` | `keypad_tmrkey_state_dispatch` | 254 | STRUCTURAL |
| `0x0301ad00` | `ptt_id_status_screen_render` | 480 | CONFIRMED |
| `0x0302c17c` | `ptt_active_icon_draw_dual_slot` | 216 | CONFIRMED |
| `0x0302c5c8` | `ptt_ui_state_machine_update` | 752 | CONFIRMED |
| `0x03036024` | `keypad_key_a_handler` | 62 | STRUCTURAL |
| `0x030392d4` | `key_event_filter_dispatch1` | 138 | STRUCTURAL |
| `0x03039810` | `character_input_event_dispatcher` | 186 | STRUCTURAL |
| `0x0303af68` | `asterisk_key_dispatch` | 428 | CONFIRMED |
| `0x0303c7fc` | `key_event_character_filter` | 98 | STRUCTURAL |
| `0x03040242` | `asterisk_key_and_history_dispatch` | 42 | STRUCTURAL |
| `0x03040282` | `keypad_event_dispatch_idle_or_menu` | 982 | CONFIRMED |
| `0x03040b68` | `key_shortcut_dispatch_table` | 20 | STRUCTURAL |
| `0x03040bdc` | `key_shortcut_call_030338d4` | 16 | STRUCTURAL |
| `0x03040bec` | `key_shortcut_call_03033a84` | 12 | STRUCTURAL |
| `0x03040bf8` | `key_shortcut_call_030120d8` | 12 | STRUCTURAL |
| `0x03040c04` | `key_shortcut_no_tx_gate_call_03052b90` | 6 | STRUCTURAL |
| `0x03040c0a` | `key_shortcut_call_03052a84_03052a74` | 20 | STRUCTURAL |
| `0x03040c2a` | `key_shortcut_call_03052a84_03058b18` | 24 | STRUCTURAL |
| `0x03040c42` | `key_shortcut_call_0305b480` | 12 | STRUCTURAL |
| `0x03040c4e` | `key_shortcut_call_03056614` | 16 | CONFIRMED |
| `0x03040c5e` | `key_shortcut_call_03066274` | 16 | STRUCTURAL |
| `0x03040c6e` | `key_shortcut_call_03056ba8` | 16 | CONFIRMED |
| `0x03040c7e` | `key_shortcut_call_0306669c` | 16 | STRUCTURAL |
| `0x03040c8e` | `key_shortcut_call_03031420` | 16 | STRUCTURAL |
| `0x03040c9e` | `key_shortcut_call_0302e9e8` | 16 | CONFIRMED |
| `0x03040cae` | `key_shortcut_call_03055e68` | 16 | CONFIRMED |
| `0x03040cbe` | `key_shortcut_call_0302ec90` | 16 | CONFIRMED |
| `0x03040cce` | `key_shortcut_call_03055dfc` | 16 | CONFIRMED |
| `0x03040cde` | `key_shortcut_call_03056718` | 16 | CONFIRMED |
| `0x03040cee` | `key_shortcut_call_0306649c` | 16 | STRUCTURAL |
| `0x03040cfe` | `key_shortcut_call_03061500` | 16 | CONFIRMED |
| `0x03040d0e` | `key_shortcut_call_0305cc2c` | 16 | CONFIRMED |
| `0x03040d1e` | `key_shortcut_call_03062d04` | 16 | CONFIRMED |
| `0x03040d2e` | `key_shortcut_call_list_cursor_and_03062ed8` | 30 | CONFIRMED |
| `0x03040d74` | `key_shortcut_special_case` | 18 | STRUCTURAL |
| `0x03040d86` | `key_shortcut_call_030584ac` | 14 | CONFIRMED |
| `0x03040d94` | `key_shortcut_noop_stub` | 24 | STRUCTURAL |
| `0x03040dac` | `key_shortcut_dispatch_table_screen_code41h` | 8 | STRUCTURAL |
| `0x03040db4` | `key_shortcut_dispatch_table_screen_code3ah` | 8 | STRUCTURAL |
| `0x03040dbc` | `key_shortcut_dispatch_table_screen_code33h` | 8 | STRUCTURAL |
| `0x03040dc4` | `key_shortcut_and_event_record_dispatch_a` | 358 | STRUCTURAL |
| `0x03040f48` | `key_shortcut_dispatch_table_screen_code25h` | 8 | STRUCTURAL |
| `0x03040f50` | `key_shortcut_dispatch_table_screen_code1eh` | 8 | STRUCTURAL |
| `0x03040f58` | `key_shortcut_dispatch_gate_main` | 52 | STRUCTURAL |
| `0x03040f8c` | `key_shortcut_dispatch_table_screen_code10h` | 8 | STRUCTURAL |
| `0x03040f94` | `key_shortcut_dispatch_table_screen_code09h` | 8 | STRUCTURAL |
| `0x03040fc0` | `key_shortcut_dispatch_table_list_screens` | 50 | CONFIRMED |
| `0x030410de` | `control_action_char_dispatch_fwd` | 16 | STRUCTURAL |
| `0x0304119e` | `key_shortcut_channel_list_advance_dispatch` | 30 | CONFIRMED |
| `0x030411e4` | `key_shortcut_special_case_fwd` | 18 | STRUCTURAL |
| `0x03041204` | `key_shortcut_noop_stub_fwd` | 24 | STRUCTURAL |
| `0x0304121c` | `key_shortcut_dispatch_table_list_screens_screen_code42h` | 8 | STRUCTURAL |
| `0x03041224` | `key_shortcut_dispatch_table_list_screens_screen_code3bh` | 8 | STRUCTURAL |
| `0x0304122c` | `key_shortcut_dispatch_table_list_screens_screen_code34h` | 8 | STRUCTURAL |
| `0x03041234` | `key_shortcut_and_event_record_dispatch_b` | 358 | STRUCTURAL |
| `0x030413b8` | `key_shortcut_dispatch_table_list_screens_screen_code26h` | 8 | STRUCTURAL |
| `0x030413c0` | `key_shortcut_dispatch_table_list_screens_screen_code1fh` | 8 | STRUCTURAL |
| `0x030413c8` | `key_shortcut_dispatch_gate_list` | 54 | STRUCTURAL |
| `0x03041400` | `key_shortcut_dispatch_table_list_screens_screen_code11h` | 8 | STRUCTURAL |
| `0x03041408` | `key_shortcut_dispatch_table_list_screens_screen_code0ah` | 8 | STRUCTURAL |
| `0x03054f10` | `keypad_battery_poll_burst_5x20ms` | 50 | STRUCTURAL |
| `0x03055880` | `ptt_preamble_tone_period_lookup` | 72 | STRUCTURAL |
| `0x03056ba8` | `control_action_char_dispatch` | 70 | STRUCTURAL |
| `0x0305bfb8` | `ptt_press_handler` | 2214 | CONFIRMED |
| `0x0305dbe4` | `keypad_dispatch_not_inhibited` | 16 | CONFIRMED |
| `0x0305dc40` | `ptt_release_handler` | 84 | STRUCTURAL |
| `0x0305fbf8` | `ptt_preamble_end_ui_audio_setup_2` | 42 | STRUCTURAL |
| `0x030642c0` | `key_hold_debounce_state_dispatcher` | 468 | STRUCTURAL |
| `0x03064d14` | `key_event_state_clear_preserve_bit0` | 32 | CONFIRMED |
