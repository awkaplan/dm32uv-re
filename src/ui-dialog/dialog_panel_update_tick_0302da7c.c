/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_panel_update_tick @ 0302da7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 384 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_panel_update_tick(void)

{
  char cVar1;
  
  if ((p_tx_ptt_ui_state->flags_0xb & 8) == 0) {
    if (PTR_DAT_0302dbb8[0x329] != PTR_DAT_0302dbb8[0x328]) {
      if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) == 0) {
        display_draw_dialog_panel();
      }
      cVar1 = PTR_DAT_0302dbb8[0x328];
      if (cVar1 == '\x02') {
        if ((p_radio_mode_state_0003e318[1].flags_0x7 & 4) == 0) {
          if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) == 0) {
            display_blit_image(0x60,0x56,0x30,0x29,PTR_DAT_0302dbd0);
            display_draw_number_centered
                      (0x90,0,0xc618,
                       **(uint **)(PTR_PTR_0302dbd4 +
                                  ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
          }
          else {
            p_radio_mode_state_0003e318[1].flags_0x6 =
                 p_radio_mode_state_0003e318[1].flags_0x6 & 0x7f;
            if (PTR_DAT_0302dbcc[1] != 0) {
              ui_event_notify_alt(0x17);
            }
          }
        }
        else {
          if ((*(byte *)PTR_DAT_0302dbc8 & 0x40) != 0) {
            display_fill_screen(0);
            gps_position_display_screen();
            p_tx_ptt_ui_state->field_0x5f = p_tx_ptt_ui_state->field_0x5f & 0xfd | 2;
          }
          p_radio_mode_state_0003e318[1].flags_0x7 = p_radio_mode_state_0003e318[1].flags_0x7 & 0xfb
          ;
        }
      }
      else if (cVar1 == '\x03') {
        display_blit_image(0x60,0x56,0x30,0x29,PTR_DAT_0302dbd8);
        display_draw_number_centered
                  (0x90,0,0xc618,
                   **(uint **)(PTR_PTR_0302dbdc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8
                              ));
      }
      else if (cVar1 == '\x01') {
        display_blit_image(0x60,0x56,0x30,0x29,PTR_DAT_0302dd94);
        display_draw_number_centered
                  (0x90,0,0xc618,
                   **(uint **)(PTR_PTR_0302dd9c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8
                              ));
      }
      PTR_DAT_0302dda0[0x329] = PTR_DAT_0302dda0[0x328];
    }
    if ((byte)(PTR_DAT_0302dda0[0x328] - 2) < 2) {
      PTR_DAT_0302dda0[0x328] = 0;
    }
  }
  else {
    dialog_request_tick();
    p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xf7;
    PTR_DAT_0302dbb8[0x329] = PTR_DAT_0302dbb8[0x328];
  }
  return;
}

