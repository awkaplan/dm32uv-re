/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_request_tick @ 0302d884 (file base 0x03000000; code starts at 0x03001000)
 * Size: 438 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_request_tick(void)

{
  char cVar1;
  undefined1 auStack_1c [20];
  
  cVar1 = PTR_DAT_0302d9d4[0x328];
  if (cVar1 == '\x02') {
    if ((p_radio_mode_state_0003e318[1].flags_0x7 & 4) == 0) {
      if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) == 0) {
        dialog_show_icon_and_two_numbers
                  (0x30,0x29,PTR_DAT_0302d9f0,
                   **(undefined4 **)
                     (PTR_PTR_0302d9e8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                   PTR_LAB_0302d9ec);
      }
      else {
        p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0x7f;
        if (PTR_DAT_0302d9e0[1] != 0) {
          ui_event_notify_alt(0x17);
        }
      }
    }
    else {
      if ((*(byte *)PTR_DAT_0302d9dc & 0x40) != 0) {
        display_fill_screen(0);
        gps_position_display_screen();
        p_tx_ptt_ui_state->field_0x5f = p_tx_ptt_ui_state->field_0x5f & 0xfd | 2;
      }
      p_radio_mode_state_0003e318[1].flags_0x7 = p_radio_mode_state_0003e318[1].flags_0x7 & 0xfb;
    }
  }
  else if (cVar1 == '\x03') {
    dialog_show_icon_and_two_numbers
              (0x30,0x29,PTR_DAT_0302d9f8,
               **(undefined4 **)
                 (PTR_PTR_0302d9f4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
               PTR_LAB_0302d9ec);
  }
  else {
    if (cVar1 != '\x01') {
      return;
    }
    if ((p_radio_mode_state_0003e318[1].flags_0x7 & 4) == 0) {
      if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) == 0) {
        dialog_show_icon_and_two_numbers
                  (0x30,0x29,PTR_DAT_0302dbb4,
                   **(undefined4 **)
                     (PTR_PTR_0302dbac + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                   PTR_LAB_0302dbb0);
      }
      else {
        dialog_show_icon_and_two_numbers
                  (0x30,0x2f,PTR_DAT_0302da08,
                   **(undefined4 **)
                     (PTR_PTR_0302da04 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                   (*(undefined4 **)
                     (PTR_PTR_0302da04 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))[1]);
      }
    }
    else {
      contact_name_lookup_or_format(1,PTR_DAT_0302d9fc[2],auStack_1c,3);
      display_draw_dialog_panel();
      display_draw_number_centered(0x90,0,0xc618,(uint)auStack_1c);
      display_draw_number_centered
                (0xae,0,0xc618,
                 *(uint *)(PTR_PTR_0302da00[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                          0x14));
    }
    PTR_DAT_0302dbb8[0x329] = PTR_DAT_0302dbb8[0x328];
  }
  if (PTR_DAT_0302dbb8[0x328] == '\x01') {
    display_fill_rect(0,0x122,0xf0,0x140,0);
    display_draw_string_gb2312
              (0x122,0xb4,
               (byte *)**(undefined4 **)
                         (PTR_PTR_0302dbbc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
               0xffff,0);
  }
  return;
}

