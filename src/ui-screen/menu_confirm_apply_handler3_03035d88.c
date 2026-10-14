/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_apply_handler3 @ 03035d88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 236 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_confirm_apply_handler3(void)

{
  if ((*(byte *)p_call_active_flag & 4) == 0) {
    if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0x10) {
      display_fill_screen(0);
      display_draw_status_bar();
      if (PTR_DAT_03035ee8[0x12] == '\0') {
        PTR_DAT_03035ee8[0x12] = 1;
      }
      dialog_show_icon_and_two_numbers
                (0x30,0x30,PTR_DAT_03035ef8,
                 **(undefined4 **)
                   (PTR_PTR_03035ef0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                 PTR_LAB_03035ef4);
      display_draw_number_centered(0xae,0,0xc618,DAT_03035efc);
      p_radio_mode_state_0003e318[1].flags_0x6 =
           p_radio_mode_state_0003e318[1].flags_0x6 & 0xfb | (PTR_DAT_03035f04[1] & 1) << 2;
      display_fill_rect(0,0x122,0xf0,0x140,0);
      display_update_datetime(1);
      display_draw_gb2312_label_top_by_config_bit(0);
      display_draw_string_from_table(0);
      reentrant_state_reset_sequence();
    }
  }
  else {
    if (p_dialog_history_ui_state->field_0x3 != 0x4d) {
      display_clear_body_and_underline();
      init_field_pair_0x20_5();
    }
    if (p_state_0003ff3c->field_0x1 <= *(byte *)p_state_0003ff3c) {
      display_draw_char_glyph_dispatch();
      p_state_0003ff3c->field_0x1 = p_state_0003ff3c->field_0x1 + 1;
    }
    PTR_DAT_03035ee0[0x1b] = 0;
    p_state_0003ff3c->field_0x2 = p_state_0003ff3c->field_0x2 & 0xfd | 2;
  }
  p_dialog_history_ui_state->field_0x3 = 0x4d;
  return;
}

