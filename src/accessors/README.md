# accessors

163 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 57 |
| STRUCTURAL | 105 |
| RAW | 1 |

## Subdirectories

This subsystem is large enough to be split a second level. Grouping key: shared name prefix.

| Directory | Files |
|---|---|
| `write/` | 63 |
| `get/` | 27 |
| `set/` | 21 |
| `update/` | 18 |
| `clear/` | 13 |
| `read/` | 11 |
| _(subsystem root)_ | 10 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x03001b34` | `get_state_field_03001b34` | 6 | STRUCTURAL |
| `0x0300373c` | `clear_slot_table_records` | 36 | STRUCTURAL |
| `0x0300c3ac` | `read_byte_field_0300c3ac` | 6 | STRUCTURAL |
| `0x0300c3b4` | `write_byte_field_0300c3b4` | 6 | STRUCTURAL |
| `0x0300c3bc` | `write_byte_field_0300c3bc` | 6 | STRUCTURAL |
| `0x0300c3d4` | `set_flag_byte_03064328_call` | 8 | CONFIRMED |
| `0x0300c41c` | `clear_byte_field_dat0302432c_plus3_thunk` | 8 | STRUCTURAL |
| `0x0300c550` | `guarded_timer_config_apply` | 134 | CONFIRMED |
| `0x0300c690` | `guarded_timer_config_apply_wrapper_a` | 14 | STRUCTURAL |
| `0x0300c6ac` | `guarded_timer_config_apply_wrapper_b` | 14 | STRUCTURAL |
| `0x0300c6c8` | `guarded_timer_config_apply_wrapper` | 14 | STRUCTURAL |
| `0x0300cdc8` | `get_event_flags_byte_dispatch` | 14 | STRUCTURAL |
| `0x0300cdf4` | `get_event_flags_byte0` | 8 | CONFIRMED |
| `0x0300cdfc` | `get_event_flags_byte1` | 8 | CONFIRMED |
| `0x0300ce04` | `get_event_flags_byte2` | 8 | CONFIRMED |
| `0x0300ce0c` | `get_event_flags_byte3` | 8 | CONFIRMED |
| `0x0300ce14` | `get_event_flags_byte4` | 8 | CONFIRMED |
| `0x0300ce1c` | `get_event_flags_byte5` | 8 | CONFIRMED |
| `0x0300ce24` | `get_event_flags_byte6` | 8 | CONFIRMED |
| `0x0300ce2c` | `get_event_flags_byte7` | 8 | CONFIRMED |
| `0x0300ce34` | `get_event_flags_byte8` | 8 | CONFIRMED |
| `0x0300ce3c` | `get_event_flags_byte9` | 8 | CONFIRMED |
| `0x0300ce44` | `get_event_flags_packed_nibbles` | 14 | STRUCTURAL |
| `0x0300ce52` | `get_event_flags_byte10` | 8 | CONFIRMED |
| `0x0300ce5a` | `get_event_flags_byte11` | 8 | CONFIRMED |
| `0x0300ce62` | `get_event_flags_byte12` | 8 | CONFIRMED |
| `0x0300ce6a` | `get_event_flags_byte13` | 8 | CONFIRMED |
| `0x0300ce72` | `get_event_flags_byte14` | 8 | CONFIRMED |
| `0x0300ce7a` | `get_event_flags_noop_stub` | 4 | CONFIRMED |
| `0x0300ce80` | `update_event_flags_byte_dispatch` | 16 | CONFIRMED |
| `0x0300ce9c` | `update_event_flags_byte0` | 16 | CONFIRMED |
| `0x0300ceac` | `update_event_flags_byte1` | 16 | CONFIRMED |
| `0x0300cebc` | `update_event_flags_byte2` | 16 | CONFIRMED |
| `0x0300cecc` | `update_event_flags_byte3` | 16 | CONFIRMED |
| `0x0300cedc` | `update_event_flags_byte4` | 16 | CONFIRMED |
| `0x0300ceec` | `update_event_flags_byte5` | 16 | CONFIRMED |
| `0x0300cefc` | `update_event_flags_byte6` | 16 | CONFIRMED |
| `0x0300cf0c` | `update_event_flags_byte7` | 16 | CONFIRMED |
| `0x0300cf1c` | `update_event_flags_byte8` | 16 | CONFIRMED |
| `0x0300cf2c` | `update_event_flags_byte9` | 16 | CONFIRMED |
| `0x0300cf3c` | `update_event_flags_byte10` | 16 | CONFIRMED |
| `0x0300cf4c` | `update_event_flags_byte11` | 16 | CONFIRMED |
| `0x0300cf5c` | `update_event_flags_byte12` | 16 | CONFIRMED |
| `0x0300cf6c` | `update_event_flags_byte13` | 16 | CONFIRMED |
| `0x0300cf7c` | `update_event_flags_byte14` | 14 | CONFIRMED |
| `0x0300cf8a` | `update_event_flags_noop_stub` | 2 | CONFIRMED |
| `0x0300d08c` | `set_field_bits_and_post_ui_mode_group_0x10` | 22 | CONFIRMED |
| `0x0300f258` | `write_flag_and_notify_ui_event0x29` | 14 | CONFIRMED |
| `0x03014274` | `write_field_and_mbox_post_arg2h_2h` | 12 | STRUCTURAL |
| `0x03014280` | `write_field_and_mbox_post_arg2h_1h` | 12 | STRUCTURAL |
| `0x03014da4` | `write_field2_and_mbox_post` | 12 | CONFIRMED |
| `0x03014db0` | `write_field2_and_mbox_post_arg11h_eh` | 12 | STRUCTURAL |
| `0x03014dbc` | `write_field2_and_mbox_post_arg10h_dh` | 12 | STRUCTURAL |
| `0x03014dc8` | `write_field2_and_mbox_post_argfh_ch` | 12 | STRUCTURAL |
| `0x03014dd4` | `write_field2_and_mbox_post_argeh_bh` | 12 | STRUCTURAL |
| `0x03014de0` | `write_field2_and_mbox_post_argdh_ah` | 12 | STRUCTURAL |
| `0x03014dec` | `write_field2_and_mbox_post_argch_9h` | 12 | STRUCTURAL |
| `0x03014df8` | `write_field2_and_mbox_post_argbh_8h` | 12 | STRUCTURAL |
| `0x03014e04` | `write_field2_and_mbox_post_argah_7h` | 12 | STRUCTURAL |
| `0x03014e10` | `write_field2_and_mbox_post_arg9h_6h` | 12 | STRUCTURAL |
| `0x03014e1c` | `write_field2_and_mbox_post_arg8h_5h` | 12 | STRUCTURAL |
| `0x03016e98` | `get_state_field_03016e98` | 6 | STRUCTURAL |
| `0x03019c30` | `clear_screen_color0` | 10 | STRUCTURAL |
| `0x0301d858` | `set_flag_byte_03064328_variant_0301d858` | 6 | STRUCTURAL |
| `0x0301e848` | `set_call_setup_field_0xac` | 8 | STRUCTURAL |
| `0x0301e8d4` | `write_single_byte_0301ea5c` | 8 | STRUCTURAL |
| `0x0301e948` | `get_field_0301ea64_0x14` | 6 | STRUCTURAL |
| `0x0301ed24` | `read_field_0x18_bit4` | 10 | STRUCTURAL |
| `0x0301ed48` | `write_field_0x18_bit7` | 12 | STRUCTURAL |
| `0x0301ed54` | `write_byte_field_0301ed54` | 6 | STRUCTURAL |
| `0x0301ed98` | `write_two_bit_flags_0301eef8` | 16 | STRUCTURAL |
| `0x0301edd8` | `read_bytes_0xe_0xf_or` | 12 | STRUCTURAL |
| `0x03020748` | `get_state_field_03020748` | 6 | STRUCTURAL |
| `0x03020e30` | `read_byte_field_03020e30` | 6 | STRUCTURAL |
| `0x03020e70` | `set_status_bit_dispatch_alt_caller` | 188 | CONFIRMED |
| `0x030212c8` | `set_single_bit_field_0x3` | 12 | STRUCTURAL |
| `0x030212dc` | `write_byte_field_030212dc` | 6 | STRUCTURAL |
| `0x030212e4` | `write_byte_field_030212e4` | 6 | STRUCTURAL |
| `0x03021598` | `set_status_bit_dispatch` | 16 | CONFIRMED |
| `0x030215ac` | `set_status_bit0` | 12 | CONFIRMED |
| `0x030215b8` | `set_status_bit1` | 12 | CONFIRMED |
| `0x030215c4` | `set_status_bit2` | 12 | CONFIRMED |
| `0x030215d0` | `set_status_bit3` | 12 | CONFIRMED |
| `0x030215dc` | `set_status_bit4` | 12 | CONFIRMED |
| `0x030215e8` | `set_status_bit5` | 10 | CONFIRMED |
| `0x030215f2` | `set_status_bit_noop_stub` | 2 | CONFIRMED |
| `0x030217f0` | `set_global_upper_16bits` | 26 | STRUCTURAL |
| `0x03021ce8` | `write_event_record_and_notify` | 40 | STRUCTURAL |
| `0x03023afc` | `clear_byte_field_dat03023b88_0x15` | 8 | CONFIRMED |
| `0x03024228` | `clear_byte_field_dat0302432c_plus3` | 14 | CONFIRMED |
| `0x03029554` | `clear_byte_at_ptr` | 6 | CONFIRMED |
| `0x03029f30` | `clear_two_state_bytes_03029fc8` | 12 | CONFIRMED |
| `0x0302a014` | `clear_counter_block_0302a19c` | 28 | CONFIRMED |
| `0x0302e118` | `read_byte_field_0302e118` | 6 | STRUCTURAL |
| `0x0302e120` | `read_byte_field_0302e120` | 6 | STRUCTURAL |
| `0x0302ed2c` | `get_current_mode_state1` | 6 | STRUCTURAL |
| `0x030309c4` | `read_channel_field_from_flash` | 64 | STRUCTURAL |
| `0x030331c4` | `set_flag_bits_and_post_os_flag_0x8000_arg4h` | 10 | STRUCTURAL |
| `0x030332d8` | `get_block0xb_u16_field0` | 56 | STRUCTURAL |
| `0x0303501c` | `set_flag_byte_03064328_variant_0303501c` | 6 | STRUCTURAL |
| `0x03035024` | `get_state_field_03035024` | 6 | STRUCTURAL |
| `0x030358bc` | `clear_state_byte_pair_03035a00` | 10 | CONFIRMED |
| `0x03035a18` | `read_byte_field_03035a18` | 6 | STRUCTURAL |
| `0x03035bb8` | `clear_field_flag_if_setting0xf_and_empty` | 28 | STRUCTURAL |
| `0x03035f1c` | `write_status_mode_byte_pair_screen_code7ch` | 12 | STRUCTURAL |
| `0x03035f28` | `write_status_mode_byte_pair_screen_code7bh` | 12 | STRUCTURAL |
| `0x03035f34` | `write_status_mode_byte_pair_screen_code7ah` | 12 | STRUCTURAL |
| `0x03035f40` | `write_status_mode_byte_pair_screen_code79h` | 12 | STRUCTURAL |
| `0x03035fcc` | `write_status_mode_byte_pair_screen_code75h` | 12 | STRUCTURAL |
| `0x03035fd8` | `write_status_mode_byte_pair_screen_code74h` | 12 | STRUCTURAL |
| `0x0303608c` | `write_status_mode_byte_pair_arg69h_0h` | 12 | STRUCTURAL |
| `0x030360c8` | `write_status_mode_byte_pair_arg54h_0h` | 12 | STRUCTURAL |
| `0x030360d4` | `write_status_mode_byte_pair_screen_code55h` | 22 | STRUCTURAL |
| `0x030360ec` | `write_status_mode_byte_pair_screen_code67h` | 22 | STRUCTURAL |
| `0x03036104` | `write_status_mode_byte_pair_screen_code66h` | 22 | STRUCTURAL |
| `0x030361c4` | `write_status_mode_byte_pair_screen_code61h` | 22 | STRUCTURAL |
| `0x030361dc` | `write_status_mode_byte_pair_screen_code60h` | 22 | STRUCTURAL |
| `0x030361f4` | `write_status_mode_byte_pair_screen_code5fh` | 22 | STRUCTURAL |
| `0x03036260` | `write_status_mode_byte_pair_screen_code52h` | 12 | STRUCTURAL |
| `0x0303626c` | `write_status_mode_byte_pair_screen_code51h` | 12 | STRUCTURAL |
| `0x03036278` | `write_status_mode_byte_pair_screen_code50h` | 12 | STRUCTURAL |
| `0x03036284` | `write_status_mode_byte_pair_screen_code4fh` | 12 | STRUCTURAL |
| `0x03036290` | `write_status_mode_byte_pair_screen_code4bh` | 12 | STRUCTURAL |
| `0x0303629c` | `write_status_mode_byte_pair_screen_code4ah` | 12 | STRUCTURAL |
| `0x030362d4` | `write_status_mode_byte_pair_screen_code44h` | 22 | STRUCTURAL |
| `0x030362ec` | `write_status_mode_byte_pair_screen_code43h` | 22 | STRUCTURAL |
| `0x03036330` | `write_status_mode_byte_pair_screen_code3dh` | 22 | STRUCTURAL |
| `0x03036348` | `write_status_mode_byte_pair_screen_code3ch` | 22 | STRUCTURAL |
| `0x030363c0` | `write_status_mode_byte_pair_screen_code36h` | 22 | STRUCTURAL |
| `0x030363d8` | `write_status_mode_byte_pair_screen_code35h` | 22 | STRUCTURAL |
| `0x030363f0` | `write_status_mode_byte_pair_screen_code2fh` | 22 | STRUCTURAL |
| `0x03036408` | `write_status_mode_byte_pair_screen_code2eh` | 22 | STRUCTURAL |
| `0x03036490` | `write_status_mode_byte_pair_screen_code28h` | 22 | STRUCTURAL |
| `0x030364b8` | `write_status_mode_byte_pair_screen_code27h` | 22 | STRUCTURAL |
| `0x030364d0` | `write_status_mode_byte_pair_screen_code21h` | 22 | STRUCTURAL |
| `0x030364e8` | `write_status_mode_byte_pair_screen_code20h` | 22 | STRUCTURAL |
| `0x03036500` | `write_status_mode_byte_pair_screen_code1ah` | 22 | STRUCTURAL |
| `0x03036518` | `write_status_mode_byte_pair_screen_code19h` | 22 | STRUCTURAL |
| `0x03036530` | `write_status_mode_byte_pair_screen_code13h` | 22 | STRUCTURAL |
| `0x03036548` | `write_status_mode_byte_pair_screen_code12h` | 22 | STRUCTURAL |
| `0x03036560` | `write_status_mode_byte_pair_argeh_1h` | 12 | STRUCTURAL |
| `0x0303656c` | `write_status_mode_byte_pair_screen_code0ch` | 22 | STRUCTURAL |
| `0x03036584` | `write_status_mode_byte_pair_screen_code0bh` | 22 | STRUCTURAL |
| `0x030391bc` | `check_mode_nibble_eq1_then_write_field_0x2f` | 24 | STRUCTURAL |
| `0x0303bed6` | `set_screen_mode_0x12` | 10 | CONFIRMED |
| `0x03054e40` | `set_global_upper_16bits_fwd_thunk` | 10 | STRUCTURAL |
| `0x03055644` | `set_flag_bits_and_post_os_flag_0x8000` | 22 | CONFIRMED |
| `0x03056444` | `get_zone_count` | 30 | STRUCTURAL |
| `0x030596d0` | `write_byte_field_030596d0` | 6 | STRUCTURAL |
| `0x0305d93c` | `clear_field_bit3_and_set_dialog_bit` | 28 | CONFIRMED |
| `0x0305db88` | `clear_bit1_set_bit2_and_dialog_state` | 20 | STRUCTURAL |
| `0x0305dbf4` | `read_byte_field_0305dbf4` | 8 | STRUCTURAL |
| `0x0305fca8` | `read_byte_field_0305fca8` | 6 | STRUCTURAL |
| `0x030641e4` | `get_current_mode_state2` | 6 | STRUCTURAL |
| `0x030641ec` | `set_flag_byte_03064328` | 6 | STRUCTURAL |
| `0x03065e34` | `read_byte_field_03065e34` | 6 | STRUCTURAL |
| `0x030660b8` | `is_memory_channel_not_vfo` | 68 | STRUCTURAL |
| `0x030687f0` | `update_and_apply_settings` | 34 | STRUCTURAL |
| `0x0306a1b8` | `guarded_request_command_dispatch` | 482 | STRUCTURAL |
| `0x0306afc0` | `guarded_state_validate_dispatch` | 100 | CONFIRMED |
| `0x030c3470` | `clear_slot_table_records_variant2` | 36 | STRUCTURAL |
| `0x030c864c` | `FUN_030c864c` | 74 | RAW |
| `0x030cd33c` | `check_stack_value_halt_if_positive` | 42 | STRUCTURAL |
