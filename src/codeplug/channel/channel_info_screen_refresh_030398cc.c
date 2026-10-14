/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_info_screen_refresh @ 030398cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_info_screen_refresh(void)

{
  undefined1 *puVar1;
  
  settings_set_menu_hold_interval(p_dm32_settings_block04[0x3a]);
  if ((p_radio_mode_state_0003e318[2].field_0x1 & 0x40) == 0) {
    display_fill_screen(0);
    display_draw_status_bar();
    puVar1 = p_dm32_settings_block04;
    dialog_show_icon_and_two_numbers
              (0x30,0x2e,PTR_DAT_03039980,
               **(undefined4 **)
                 (PTR_PTR_03039978 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
               PTR_LAB_0303997c);
    display_fill_rect(0,0x122,0xf0,0x140,0);
    display_update_datetime(1);
    display_draw_gb2312_label_top_by_config_bit(0);
    display_draw_string_from_table(0);
    if (((puVar1[0x43] & 1) != 0) && ((*(byte *)PTR_DAT_03039984 & 4) == 0)) {
      character_input_event_dispatcher(0x21);
    }
  }
  else {
    ptt_id_status_screen_render(PTR_DAT_03039974[1] & 1);
  }
  return;
}

