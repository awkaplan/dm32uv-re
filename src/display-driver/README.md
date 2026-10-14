# display-driver

163 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 88 |
| STRUCTURAL | 75 |
| RAW | 0 |

## Subdirectories

This subsystem is large enough to be split a second level. Grouping key: shared name prefix.

| Directory | Files |
|---|---|
| `display/` | 103 |
| `draw/` | 19 |
| `lcd/` | 16 |
| `screen/` | 9 |
| _(subsystem root)_ | 16 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x0002c1cc` | `lcd_write_command` | 10 | CONFIRMED |
| `0x0002c1d8` | `lcd_write_data` | 10 | CONFIRMED |
| `0x0002c1e4` | `lcd_write_pixel` | 18 | CONFIRMED |
| `0x0002f000` | `display_scroll_task_loop` | 986 | STRUCTURAL |
| `0x03010e24` | `gb2312_glyph_index_lookup2` | 36 | STRUCTURAL |
| `0x03010e48` | `gb2312_glyph_index_lookup1` | 36 | STRUCTURAL |
| `0x03010e6c` | `font_glyph_ptr_lookup` | 28 | CONFIRMED |
| `0x03010ec4` | `gb2312_glyph_flash_offset_read` | 126 | STRUCTURAL |
| `0x030114d4` | `format_computed_ratio_as_string` | 32 | STRUCTURAL |
| `0x03014ee8` | `display_pending_refresh_check` | 76 | STRUCTURAL |
| `0x030158c0` | `screen_subtype_enter_on_flash_flag` | 140 | STRUCTURAL |
| `0x030178ec` | `lcd_set_orientation` | 30 | CONFIRMED |
| `0x0301790c` | `lcd_ram_write_begin` | 10 | CONFIRMED |
| `0x03017918` | `lcd_write_command_arg28h` | 10 | STRUCTURAL |
| `0x03017924` | `lcd_write_command_arg29h` | 10 | STRUCTURAL |
| `0x03017930` | `lcd_sleep_in_and_wait` | 16 | STRUCTURAL |
| `0x03017940` | `lcd_sleep_out_and_wait` | 16 | STRUCTURAL |
| `0x03017950` | `lcd_set_column_range` | 38 | CONFIRMED |
| `0x03017978` | `display_set_cursor_pos` | 44 | STRUCTURAL |
| `0x030179a4` | `display_plot_pixel` | 24 | CONFIRMED |
| `0x030179bc` | `display_plot_glyph_2color` | 148 | CONFIRMED |
| `0x03017a50` | `draw_line_bresenham` | 174 | STRUCTURAL |
| `0x03017b00` | `display_draw_circle_bresenham` | 226 | CONFIRMED |
| `0x03017be8` | `display_set_x_window` | 38 | CONFIRMED |
| `0x03017c10` | `display_set_y_window` | 38 | CONFIRMED |
| `0x03017c38` | `display_set_window` | 24 | CONFIRMED |
| `0x03017c50` | `display_fill_rect` | 106 | CONFIRMED |
| `0x03017cbc` | `draw_rect_outline_mutex_guarded` | 104 | CONFIRMED |
| `0x03017d24` | `display_fill_fullscreen_rect_color` | 26 | CONFIRMED |
| `0x03017d40` | `display_clear_fullscreen` | 10 | STRUCTURAL |
| `0x03017d4c` | `lcd_controller_power_on_init_sequence` | 506 | CONFIRMED |
| `0x03017f54` | `display_fill_screen` | 72 | CONFIRMED |
| `0x03017f9c` | `display_blit_rect_from_buffer` | 142 | STRUCTURAL |
| `0x0301802c` | `lcd_blit_image_from_spi_flash` | 240 | CONFIRMED |
| `0x03018128` | `blit_bitmap_8x8_two_blocks` | 166 | STRUCTURAL |
| `0x030181d0` | `display_bitfield_serialize_16byte` | 166 | CONFIRMED |
| `0x03018278` | `display_blit_glyph_6x8` | 92 | STRUCTURAL |
| `0x03018380` | `lcd_draw_dualcolor_bitmap_40x8` | 250 | CONFIRMED |
| `0x0301847c` | `display_blit_mono_bitmap_rows` | 158 | STRUCTURAL |
| `0x0301851c` | `display_fill_glyph_cell` | 62 | CONFIRMED |
| `0x0301855c` | `blit_bitmap_8x16_two_blocks` | 166 | STRUCTURAL |
| `0x03018604` | `display_blit_bitmap_16x16_1bpp` | 168 | STRUCTURAL |
| `0x030186ac` | `display_draw_glyph_gb2312` | 158 | STRUCTURAL |
| `0x0301874c` | `display_draw_glyph_ascii` | 170 | STRUCTURAL |
| `0x030187f8` | `display_draw_string_mixed_ascii_gb2312` | 196 | CONFIRMED |
| `0x030188bc` | `display_draw_glyph_row_mutex` | 208 | CONFIRMED |
| `0x03018998` | `display_draw_string_gb2312` | 254 | CONFIRMED |
| `0x03018a98` | `display_draw_number_centered_dispatch` | 100 | CONFIRMED |
| `0x03018b08` | `display_draw_formatted_right_aligned` | 84 | STRUCTURAL |
| `0x03018b5c` | `display_draw_number_centered` | 90 | CONFIRMED |
| `0x03018bbc` | `display_draw_formatted_number_centered` | 88 | STRUCTURAL |
| `0x03018c14` | `display_draw_frequency` | 194 | CONFIRMED |
| `0x03018cd8` | `display_draw_list_row` | 116 | STRUCTURAL |
| `0x03018d4c` | `blit_bitmap_with_mutex` | 124 | STRUCTURAL |
| `0x03018de0` | `display_blit_bitmap_1bpp` | 132 | CONFIRMED |
| `0x03019434` | `display_draw_status_bar` | 338 | CONFIRMED |
| `0x030195d8` | `display_update_tone_signaling_icon` | 166 | STRUCTURAL |
| `0x03019770` | `display_blit_packed_bitmap_row` | 210 | CONFIRMED |
| `0x03019844` | `display_blit_packed_bitmap_row_constch_ch_fwd` | 34 | STRUCTURAL |
| `0x03019868` | `format_and_plot_number_with_decimals` | 154 | STRUCTURAL |
| `0x03019904` | `display_blit_bitmap_1bpp_rows` | 274 | CONFIRMED |
| `0x03019a24` | `lcd_draw_monochrome_bitmap_icon` | 258 | CONFIRMED |
| `0x03019b28` | `display_clear_status_row` | 50 | STRUCTURAL |
| `0x03019b60` | `display_clear_channel_row_background` | 70 | CONFIRMED |
| `0x03019ba8` | `display_fill_main_panel` | 62 | STRUCTURAL |
| `0x03019be8` | `display_draw_dialog_panel` | 26 | STRUCTURAL |
| `0x03019c04` | `display_clear_body_and_underline` | 44 | STRUCTURAL |
| `0x03019c9c` | `display_draw_gb2312_label_top_by_config_bit` | 44 | CONFIRMED |
| `0x03019cc8` | `display_draw_string_from_table` | 44 | STRUCTURAL |
| `0x03019d00` | `display_draw_gb2312_label_bottom_by_config_bit` | 44 | CONFIRMED |
| `0x03019d2c` | `display_draw_gb2312_label_top_alt` | 44 | CONFIRMED |
| `0x03019d58` | `display_draw_string_wrapped` | 326 | CONFIRMED |
| `0x03019fc4` | `format_number_and_draw_display` | 46 | STRUCTURAL |
| `0x03019ff4` | `display_draw_string_wrapped2` | 234 | CONFIRMED |
| `0x0301a10c` | `display_draw_string_mutex_variant` | 200 | CONFIRMED |
| `0x0301a1d4` | `display_draw_string_ascii_mixed` | 218 | CONFIRMED |
| `0x0301a2b4` | `draw_string_mixed_charset` | 194 | STRUCTURAL |
| `0x0301a378` | `display_draw_dialog_panel_variant_0301a378` | 24 | STRUCTURAL |
| `0x0301a390` | `display_draw_two_tone_progress_bar` | 68 | CONFIRMED |
| `0x0301a3d4` | `display_status_corner_clear_when_idle` | 44 | STRUCTURAL |
| `0x0301a494` | `display_clear_status_row_at_y_by_flag` | 54 | CONFIRMED |
| `0x0301a4cc` | `display_refresh_tone_mode_icon` | 230 | CONFIRMED |
| `0x0301a5dc` | `display_text_encode_with_width_fit_check` | 190 | CONFIRMED |
| `0x0301a6b4` | `display_draw_string_centered_mixed` | 282 | CONFIRMED |
| `0x0301b6a8` | `display_update_datetime` | 334 | CONFIRMED |
| `0x0301bcf0` | `display_toggle_box_or_bitmap_by_flag` | 62 | CONFIRMED |
| `0x0301cad0` | `lcd_bus_pads_restore_after_keypad_scan` | 18 | CONFIRMED |
| `0x030231ee` | `display_draw_formatted_number_semicolon_eol` | 78 | STRUCTURAL |
| `0x0302b920` | `display_wrapped_text_paginator` | 204 | CONFIRMED |
| `0x0302c2e8` | `draw_dialog_with_status_and_datetime` | 158 | STRUCTURAL |
| `0x0302f8b8` | `display_draw_hex_digits_6_with_separator` | 140 | CONFIRMED |
| `0x0302fa1c` | `draw_dialog_header_and_centered_number` | 82 | STRUCTURAL |
| `0x03030604` | `display_draw_tone_mode_icon` | 232 | CONFIRMED |
| `0x03030714` | `display_draw_channel_frequency` | 114 | CONFIRMED |
| `0x03038058` | `screen_enter_apply_channel_and_rf_mode` | 1148 | STRUCTURAL |
| `0x0303858c` | `display_draw_number1_from_selected_ptr_table` | 22 | STRUCTURAL |
| `0x030385a2` | `draw_number_centered_menu_field_0x1` | 34 | STRUCTURAL |
| `0x030385fa` | `draw_number_centered_menu_field_0x2` | 34 | STRUCTURAL |
| `0x0303861c` | `draw_number_centered_menu_variant` | 34 | STRUCTURAL |
| `0x0303863e` | `draw_number_centered_ptr_0303879c` | 34 | STRUCTURAL |
| `0x03038660` | `draw_number_centered_ptr_030387a0` | 34 | STRUCTURAL |
| `0x03038682` | `draw_number_centered_ptr_030387a4` | 34 | STRUCTURAL |
| `0x030386a4` | `draw_number_centered_ptr_030387a8` | 34 | STRUCTURAL |
| `0x030386c6` | `display_draw_number_centered_wrapper_030386c6` | 34 | CONFIRMED |
| `0x030386e8` | `draw_number_centered_ptr_030387b0` | 34 | STRUCTURAL |
| `0x0303870a` | `draw_number_centered_fixed_field` | 22 | STRUCTURAL |
| `0x03038b9e` | `draw_number_centered_menu_dispatcher` | 320 | STRUCTURAL |
| `0x03038de2` | `draw_number_centered_conditional_state` | 62 | STRUCTURAL |
| `0x03038e20` | `display_draw_number1_white_ptr_label` | 4 | CONFIRMED |
| `0x03038e24` | `display_draw_number1_white_fixed_label` | 20 | CONFIRMED |
| `0x03038ee0` | `lcd_rect_bitmap_blit` | 164 | CONFIRMED |
| `0x03038f84` | `display_blit_bitmap_1bpp_clipped` | 156 | STRUCTURAL |
| `0x03039034` | `display_blit_image` | 150 | CONFIRMED |
| `0x030390cc` | `display_clear_and_draw_fixed_region` | 34 | STRUCTURAL |
| `0x0303a470` | `display_blit_bitmap_by_palette_variant` | 70 | CONFIRMED |
| `0x0303b150` | `display_draw_digit_string_indicators` | 240 | CONFIRMED |
| `0x0303b240` | `display_draw_decimal_string_2color` | 258 | CONFIRMED |
| `0x0303c37c` | `screen_setup_number_dialog_header` | 100 | STRUCTURAL |
| `0x0303c420` | `screen_number_dialog_with_variant` | 80 | STRUCTURAL |
| `0x0303c470` | `screen_number_conditional_draw` | 74 | STRUCTURAL |
| `0x0303c528` | `screen_dual_number_with_table` | 98 | STRUCTURAL |
| `0x0303f864` | `screen_subtype_set_2_post_0x18` | 24 | STRUCTURAL |
| `0x03041644` | `display_list_with_icons_renderer` | 186 | STRUCTURAL |
| `0x030427b4` | `screen_option_template_load_id_generic` | 124 | STRUCTURAL |
| `0x030472d0` | `format_and_write_status_field2` | 82 | STRUCTURAL |
| `0x030484c8` | `format_and_write_status_field` | 98 | STRUCTURAL |
| `0x03048fc6` | `display_number_centered_100_0_color_7e0_with_duration` | 50 | STRUCTURAL |
| `0x03048ff8` | `display_number_centered_100_0_color_7e0_offset_8` | 40 | STRUCTURAL |
| `0x03049020` | `display_number_centered_100_0_color_7e0_offset_16_duration_x30` | 44 | STRUCTURAL |
| `0x0304904c` | `display_draw_number_centered_wrapper_0304904c` | 52 | CONFIRMED |
| `0x03049080` | `display_draw_number_centered_then_display_draw_hex_digits_6_with_separator` | 52 | CONFIRMED |
| `0x03049188` | `display_number_centered_100_0_color_7e0_offset_64_duration_x5` | 44 | STRUCTURAL |
| `0x030491b4` | `display_draw_number_centered_then_display_clear_and_draw_scaled_number_ms_030491b4` | 40 | CONFIRMED |
| `0x030491dc` | `display_draw_number_centered_then_settings_duration_seconds_display_call_030491dc` | 40 | CONFIRMED |
| `0x03049204` | `display_draw_number_centered_then_display_clear_and_draw_number_with_label_arg` | 40 | CONFIRMED |
| `0x03049262` | `display_draw_number_centered_then_display_clear_and_draw_scaled_number_ms_03049262` | 40 | CONFIRMED |
| `0x030492b8` | `display_draw_number_centered_then_settings_duration_seconds_display_call_030492b8` | 40 | CONFIRMED |
| `0x030492e0` | `display_draw_number_centered_then_seconds_decimal_from_int_format` | 54 | CONFIRMED |
| `0x0304c5fc` | `display_mode_state_icon_blit_0x6b` | 142 | STRUCTURAL |
| `0x0304d590` | `backlight_setting_toggle_handler` | 250 | STRUCTURAL |
| `0x0305279c` | `screen_mode_static_table_dispatch` | 86 | CONFIRMED |
| `0x0305298c` | `draw_wrapped_string_then_dialog_header` | 20 | STRUCTURAL |
| `0x03054f44` | `display_lookup_channel_icon_and_bank` | 564 | CONFIRMED |
| `0x0305663c` | `draw_channel_records_from_flash` | 218 | STRUCTURAL |
| `0x03059188` | `display_format_id_with_separators` | 758 | CONFIRMED |
| `0x030594b8` | `display_draw_char_glyph_dispatch` | 30 | CONFIRMED |
| `0x030594e4` | `display_draw_ascii_digit_glyph_advance` | 8 | CONFIRMED |
| `0x030594ec` | `display_draw_glyph_row_advance_0x41` | 8 | CONFIRMED |
| `0x030594f4` | `display_draw_glyph_row_advance_0x42` | 8 | CONFIRMED |
| `0x030594fc` | `display_draw_glyph_row_advance_0x43` | 8 | CONFIRMED |
| `0x03059504` | `display_draw_glyph_row_advance_0x44` | 8 | CONFIRMED |
| `0x0305950c` | `display_draw_glyph_row_advance_asterisk` | 8 | CONFIRMED |
| `0x03059514` | `display_draw_glyph_row_advance_0x23` | 58 | CONFIRMED |
| `0x0305a4dc` | `display_draw_single_char_or_gb2312_glyph` | 272 | CONFIRMED |
| `0x0305ab40` | `draw_wrapped_text_conditional` | 156 | STRUCTURAL |
| `0x0305b984` | `gb2312_text_wrap_calculate` | 122 | CONFIRMED |
| `0x0305d020` | `gb2312_string_reencode` | 960 | CONFIRMED |
| `0x03063cc4` | `display_fill_rect_then_display_draw_number_centered` | 48 | CONFIRMED |
| `0x03067f18` | `display_clear_and_draw_scaled_number_ms_label` | 46 | CONFIRMED |
| `0x03067f48` | `display_clear_and_draw_number_with_label_arg` | 42 | CONFIRMED |
| `0x030bf73c` | `gb2312_ui_string_table_channel_errors` | 1 | CONFIRMED |
| `0x030c84f4` | `display_status_buffer_reset_or_score_calc` | 102 | CONFIRMED |
| `0x030c9958` | `display_buffer_command_dispatch` | 128 | STRUCTURAL |
