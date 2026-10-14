# radio-state

79 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 39 |
| STRUCTURAL | 40 |
| RAW | 0 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x00012c3c` | `radio_command_jumptable_dispatch_iram` | 218 | CONFIRMED |
| `0x0001324c` | `radio_command_dispatcher` | 58 | STRUCTURAL |
| `0x030025c8` | `radio_bringup_protocol_request_0x0b` | 58 | STRUCTURAL |
| `0x0300278c` | `radio_device_state_reset_and_bringup_variant` | 188 | STRUCTURAL |
| `0x03002eac` | `radio_list_pool_init_and_transact` | 206 | CONFIRMED |
| `0x0300304c` | `radio_list_command_dispatch_with_iteration` | 228 | STRUCTURAL |
| `0x0300349c` | `radio_list_item_add_forever` | 30 | STRUCTURAL |
| `0x03003b04` | `radio_list_item_add_guarded` | 242 | STRUCTURAL |
| `0x0300c424` | `radio_state_reinit_and_120s_timer_start_thunk` | 8 | STRUCTURAL |
| `0x0300c438` | `radio_event_dispatch_by_name` | 22 | CONFIRMED |
| `0x0300c904` | `radio_task_group_create` | 880 | STRUCTURAL |
| `0x0300e40c` | `radio_init_sequence` | 144 | CONFIRMED |
| `0x0300e530` | `hw_status_debounce_and_alarm_poll` | 266 | STRUCTURAL |
| `0x0300eb54` | `hw_status_bit10_read` | 14 | STRUCTURAL |
| `0x0300eb74` | `hw_status_bit14_read` | 14 | STRUCTURAL |
| `0x0300ee10` | `hw_status_bit_select_by_config_field` | 92 | CONFIRMED |
| `0x0300ee6c` | `hw_status_bit_check_by_radio_mode` | 44 | CONFIRMED |
| `0x03011d24` | `radio_telemetry_format_dispatch` | 688 | STRUCTURAL |
| `0x03012d10` | `main_ptt_and_channel_event_loop` | 260 | CONFIRMED |
| `0x03012e84` | `radio_config_tables_init_with_guard` | 196 | CONFIRMED |
| `0x03013a3c` | `main_ui_background_task_loop` | 1184 | STRUCTURAL |
| `0x030175c8` | `radio_mode_ui_tick` | 142 | STRUCTURAL |
| `0x0301b818` | `radio_boot_gpio_preinit` | 22 | STRUCTURAL |
| `0x0301e92c` | `radio_reset_sequence_with_clock_reset` | 26 | STRUCTURAL |
| `0x0301e950` | `radio_mode_dispatcher_char` | 122 | STRUCTURAL |
| `0x03020e00` | `radio_mode_classify_from_status_bytes` | 40 | STRUCTURAL |
| `0x03021670` | `radio_mode_transition_sequencer` | 298 | STRUCTURAL |
| `0x030217b8` | `radio_mode_reset_to_idle` | 30 | STRUCTURAL |
| `0x0302384c` | `mode_gated_field_copy_or_invert` | 102 | CONFIRMED |
| `0x03024434` | `radio_state_reinit_and_120s_timer_start` | 108 | STRUCTURAL |
| `0x0302fbbc` | `radio_idle_state_reset` | 138 | CONFIRMED |
| `0x0303b6c4` | `main_menu_screen_dispatch` | 70 | STRUCTURAL |
| `0x0303bcae` | `main_menu_open_contact_text_list` | 58 | CONFIRMED |
| `0x0303bce8` | `main_menu_open_tx_contact_select` | 60 | CONFIRMED |
| `0x0303bee0` | `mode_display_icon_draw_dispatch` | 120 | STRUCTURAL |
| `0x0303c868` | `main_menu_reset_and_display` | 222 | CONFIRMED |
| `0x0303c9fc` | `main_menu_reset_and_enter` | 60 | STRUCTURAL |
| `0x0303caf2` | `radio_shutdown_confirm_screen_setup` | 6 | STRUCTURAL |
| `0x0303cbc4` | `main_menu_screen_render_entry` | 414 | CONFIRMED |
| `0x0303cdf0` | `main_menu_render_and_field_edit_dispatch` | 254 | CONFIRMED |
| `0x0303ddb0` | `main_menu_entry_screen_setup` | 302 | CONFIRMED |
| `0x0304118e` | `radio_param_conditional_update_fwd` | 16 | STRUCTURAL |
| `0x03041700` | `radio_id_detail_screen` | 352 | CONFIRMED |
| `0x030425c8` | `mode_index_zone_setup` | 74 | STRUCTURAL |
| `0x0304537c` | `radio_id_list_screen` | 154 | CONFIRMED |
| `0x03046808` | `radio_shutdown_confirm_screen_call` | 8 | CONFIRMED |
| `0x03052c98` | `radio_shutdown_confirm_screen` | 106 | STRUCTURAL |
| `0x030543d4` | `radio_mode_state_field_lookup_if_key_matches` | 116 | STRUCTURAL |
| `0x030582c8` | `radio_id_entry_write` | 26 | CONFIRMED |
| `0x030582e4` | `radio_id_entry_read_and_terminate` | 26 | CONFIRMED |
| `0x0305b480` | `radio_state_render_update` | 140 | STRUCTURAL |
| `0x0305baec` | `radio_mode_entry_reinit_and_display` | 806 | STRUCTURAL |
| `0x0305f2c8` | `radio_boot_full_init_sequence` | 474 | CONFIRMED |
| `0x030608c4` | `radio_id_entry_read_by_stored_index` | 30 | CONFIRMED |
| `0x030608e4` | `radio_id_display_field_prep_dispatch` | 48 | CONFIRMED |
| `0x03062d04` | `radio_param_conditional_update` | 38 | STRUCTURAL |
| `0x030644d8` | `mode_transition_cleanup` | 64 | CONFIRMED |
| `0x030652d8` | `status2_mailbox_post_reason0` | 24 | CONFIRMED |
| `0x030652f0` | `status2_mailbox_post_reason4` | 24 | CONFIRMED |
| `0x03065308` | `status2_mailbox_post_reason5` | 24 | CONFIRMED |
| `0x03065320` | `status2_mailbox_post_reason6` | 24 | CONFIRMED |
| `0x03065338` | `status2_mailbox_post_reason7` | 24 | CONFIRMED |
| `0x03065358` | `status2_mailbox_post_reason8` | 24 | CONFIRMED |
| `0x03065370` | `status2_mailbox_post_reason9` | 24 | CONFIRMED |
| `0x03065388` | `status2_mailbox_post_reason10` | 24 | CONFIRMED |
| `0x0306817c` | `radio_mode_enter_and_refresh` | 102 | STRUCTURAL |
| `0x03068688` | `radio_boot_task_entry` | 20 | STRUCTURAL |
| `0x0306a4b8` | `radio_list_item_reinit_pend_list` | 38 | STRUCTURAL |
| `0x0306a5f8` | `radio_list_item_remove_by_handle` | 306 | CONFIRMED |
| `0x0306a93c` | `radio_state_and_linked_list_node_fields_zero_reset` | 238 | STRUCTURAL |
| `0x030c0674` | `radio_bringup_mem_partition_0x3f` | 58 | STRUCTURAL |
| `0x030c097c` | `radio_device_state_reset_and_bringup` | 298 | STRUCTURAL |
| `0x030c14ec` | `radio_list_pool_init_and_transact_variant` | 206 | CONFIRMED |
| `0x030c1aa4` | `radio_list_item_remove_by_handle_variant` | 306 | CONFIRMED |
| `0x030c1c08` | `OS_SemPost_variant2` | 228 | CONFIRMED |
| `0x030c285c` | `radio_list_command_dispatch_jumptable` | 218 | CONFIRMED |
| `0x030c32e8` | `radio_command_jumptable_dispatch_flash` | 102 | CONFIRMED |
| `0x030c3414` | `radio_command_submit_isr_aware` | 72 | STRUCTURAL |
| `0x030c388c` | `command_dispatch_with_guard_flags_variant_030c388c` | 242 | STRUCTURAL |
