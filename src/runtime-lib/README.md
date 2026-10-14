# runtime-lib

60 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 35 |
| STRUCTURAL | 25 |
| RAW | 0 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x0002b338` | `memcpy_bytes_iram` | 22 | CONFIRMED |
| `0x0002b350` | `memset_bytes` | 18 | CONFIRMED |
| `0x030010e4` | `strlen_unaligned_path` | 28 | CONFIRMED |
| `0x03001810` | `crc16_xmodem` | 74 | CONFIRMED |
| `0x03004274` | `libc_memcpy_bytes` | 22 | CONFIRMED |
| `0x0300428c` | `libc_memset_bytes` | 18 | CONFIRMED |
| `0x0300c154` | `crc9_bitserial` | 102 | CONFIRMED |
| `0x0300c224` | `crc32_mpeg2_bitserial` | 92 | CONFIRMED |
| `0x03010f44` | `bit_matrix_column_transpose_pack` | 136 | STRUCTURAL |
| `0x03011420` | `string_find_nth_comma_index` | 48 | CONFIRMED |
| `0x03011748` | `circular_line_buffer_char_append` | 194 | CONFIRMED |
| `0x03012f48` | `bitwise_not_of_boolean_result` | 14 | CONFIRMED |
| `0x0301b000` | `linear_interpolate_freq_calibration` | 118 | STRUCTURAL |
| `0x0301c780` | `day_of_week_calculate` | 112 | STRUCTURAL |
| `0x0301f040` | `stack_buffer_triple_call_helper` | 36 | STRUCTURAL |
| `0x03020750` | `memcpy_from_const_0302076c` | 12 | CONFIRMED |
| `0x03023b04` | `bitwise_not_of_nonzero_check` | 10 | CONFIRMED |
| `0x03023d00` | `bitmask_nth_set_bit_table_index` | 46 | STRUCTURAL |
| `0x03023d30` | `bit_pattern_match_count_with_position_gate` | 46 | CONFIRMED |
| `0x03023d60` | `count_table_entries_sharing_bit` | 28 | CONFIRMED |
| `0x03024138` | `delta_encode_adjacent_xor` | 54 | STRUCTURAL |
| `0x03029ee0` | `max_linked_list_length_of_two` | 64 | STRUCTURAL |
| `0x03035054` | `string_copy_by_param_select` | 28 | STRUCTURAL |
| `0x0304107a` | `jump_table_dispatch_forward` | 20 | STRUCTURAL |
| `0x0304a118` | `build_sequential_index_list` | 24 | STRUCTURAL |
| `0x03052a74` | `jump_table_dispatch_by_param` | 14 | STRUCTURAL |
| `0x030559b0` | `count_set_bits_in_flash_field` | 72 | STRUCTURAL |
| `0x030599a0` | `ascii_digits_to_uint` | 378 | STRUCTURAL |
| `0x0305f4b4` | `decimal_to_bcd_pack` | 40 | CONFIRMED |
| `0x0305f8cc` | `strcmp_byte_ordinal` | 80 | CONFIRMED |
| `0x0305f990` | `hex_digit_to_value` | 54 | CONFIRMED |
| `0x030640e8` | `circular_buffer_append_3bit_status` | 140 | CONFIRMED |
| `0x030674d4` | `memset_bytes_wrapper` | 14 | CONFIRMED |
| `0x03067664` | `crc16_ccitt` | 116 | CONFIRMED |
| `0x0306ba88` | `memset_with_word_alignment` | 116 | CONFIRMED |
| `0x0306bafc` | `memset_with_word_alignment_const0h_fwd` | 12 | STRUCTURAL |
| `0x0306bb08` | `memmove_overlap_safe` | 182 | CONFIRMED |
| `0x0306c988` | `strlen_unbounded` | 12 | STRUCTURAL |
| `0x0306c994` | `strncpy_nul_terminated` | 98 | CONFIRMED |
| `0x0306c9f8` | `strcpy_unbounded` | 12 | STRUCTURAL |
| `0x0306ca7c` | `strncmp_impl` | 190 | CONFIRMED |
| `0x0306cb3c` | `strcmp_unbounded` | 14 | STRUCTURAL |
| `0x0306cb4c` | `strncmp_ck803s_null_safe` | 236 | CONFIRMED |
| `0x0306cc38` | `strcmp_null_safe_unbounded` | 14 | STRUCTURAL |
| `0x0306e838` | `atoi_clamped` | 96 | STRUCTURAL |
| `0x0306fca8` | `shift_right_64` | 40 | STRUCTURAL |
| `0x0306fcd0` | `shift_left_64` | 40 | STRUCTURAL |
| `0x0306fddc` | `heap_free_with_adjacent_coalesce` | 112 | CONFIRMED |
| `0x0306fe54` | `heap_calloc_zeroed` | 28 | STRUCTURAL |
| `0x03070270` | `buffer_compare_memcmp_style` | 264 | CONFIRMED |
| `0x030703bc` | `memcpy_ck803s` | 126 | CONFIRMED |
| `0x0307043c` | `memset_ck803s` | 158 | CONFIRMED |
| `0x030704dc` | `strcat` | 26 | CONFIRMED |
| `0x0307050c` | `strcpy_ck803s` | 34 | CONFIRMED |
| `0x030705d8` | `strlen_ck803s` | 28 | CONFIRMED |
| `0x03070618` | `strncmp_ck803s` | 36 | STRUCTURAL |
| `0x030706c4` | `snprintf_numeric_to_buffer` | 92 | STRUCTURAL |
| `0x03071068` | `abs_int` | 6 | STRUCTURAL |
| `0x0307175c` | `memmove` | 184 | CONFIRMED |
| `0x030bfa78` | `ascii_ui_string_table_response_prompt` | 6 | CONFIRMED |
