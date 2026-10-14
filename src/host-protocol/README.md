# host-protocol

28 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 22 |
| STRUCTURAL | 6 |
| RAW | 0 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x030032ec` | `protocol_request_struct_build_and_dispatch` | 398 | CONFIRMED |
| `0x03003768` | `protocol_request_validate_and_dispatch` | 114 | STRUCTURAL |
| `0x0300c40c` | `protocol_frame_periodic_timer_state_machine_thunk` | 8 | STRUCTURAL |
| `0x0300c6e4` | `protocol_timer_ensure_valid_or_recreate_wrapper` | 14 | CONFIRMED |
| `0x0301eb90` | `protocol_control_char_dispatch_dialog_history` | 176 | CONFIRMED |
| `0x0302454c` | `protocol_frame_field_pack_and_send_0x12` | 148 | CONFIRMED |
| `0x0302470c` | `protocol_frame_field_copy_and_send` | 124 | CONFIRMED |
| `0x03024788` | `protocol_frame_periodic_timer_state_machine` | 150 | STRUCTURAL |
| `0x03024928` | `protocol_state_write_and_apply_sequence` | 74 | CONFIRMED |
| `0x03025bbc` | `protocol_packet_field_pack_8byte` | 148 | CONFIRMED |
| `0x03025c54` | `protocol_packet_build_with_checksum` | 490 | CONFIRMED |
| `0x0302aaec` | `cps_serial_field_rw_dispatcher` | 122 | CONFIRMED |
| `0x0302ab84` | `cps_serial_field_rw_reentry0` | 36 | CONFIRMED |
| `0x0302aba8` | `cps_serial_field_rw_reentry1` | 36 | CONFIRMED |
| `0x0302abcc` | `cps_serial_field_rw_reentry2` | 38 | CONFIRMED |
| `0x0302abf2` | `cps_serial_field_rw_reentry3` | 36 | CONFIRMED |
| `0x0302ac16` | `cps_serial_field_rw_reentry4` | 38 | CONFIRMED |
| `0x0302ac3c` | `cps_serial_field_rw_reentry5` | 38 | CONFIRMED |
| `0x0302ac62` | `cps_serial_field_rw_reentry6` | 38 | CONFIRMED |
| `0x0302ac88` | `cps_serial_field_rw_reentry7` | 38 | CONFIRMED |
| `0x0302acae` | `cps_serial_field_rw_reentry8` | 36 | CONFIRMED |
| `0x0302acd2` | `cps_serial_field_rw_reentry9` | 36 | CONFIRMED |
| `0x0302ae0e` | `cps_serial_field_rw_dispatcher_variant` | 1136 | CONFIRMED |
| `0x0302b3d4` | `cps_serial_handshake_command_dispatcher` | 736 | CONFIRMED |
| `0x0305df4c` | `protocol_control_char_dispatch_backspace_wrapper` | 10 | CONFIRMED |
| `0x03064f88` | `protocol_command_byte_dispatch` | 420 | STRUCTURAL |
| `0x03067c34` | `frame_build_two_block_crc_encoded` | 148 | STRUCTURAL |
| `0x030c3494` | `mem_partition_config_validate_and_register` | 114 | STRUCTURAL |
