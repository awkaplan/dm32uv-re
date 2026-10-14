/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_event_flag_dispatcher @ 0305ea44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 284 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_event_flag_dispatcher(void)

{
  ushort uVar1;
  byte bVar2;
  
  bVar2 = get_event_flags_byte_dispatch(6);
  if ((bVar2 & 1) == 0) {
    if ((bVar2 & 2) == 0) {
      if ((bVar2 & 4) == 0) {
        if ((bVar2 & 8) == 0) {
          if ((bVar2 & 0x10) != 0) {
            *(undefined1 *)(PTR_DAT_0305ecec + 0xca) = 0;
            p_radio_mode_state_0003e318[1].flags_0x6 =
                 p_radio_mode_state_0003e318[1].flags_0x6 & 0x7f;
            update_event_flags_byte_dispatch(6,0x10);
            format_and_write_status_field
                      (0x1d,0x14,
                       **(undefined4 **)
                         (PTR_PTR_0305ecf8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
            ui_event_notify(0x1b);
          }
        }
        else {
          tx_led_or_tone_on();
          update_event_flags_byte_dispatch(6,8);
          if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) != 0) {
            *(undefined1 *)p_tx_ptt_ui_state = 10;
            PTR_DAT_0305eb24[0x328] = 2;
          }
        }
      }
      else {
        PTR_DAT_0305eb24[0x328] = 3;
        update_event_flags_byte_dispatch(6,4);
      }
    }
    else {
      update_event_flags_byte_dispatch(6,2);
      if ((PTR_DAT_0305eb2c[10] & 1) == 0) {
        PTR_DAT_0305eb24[0x328] = 3;
        ui_event_notify(0x1b);
      }
      else {
        PTR_DAT_0305eb2c[10] = PTR_DAT_0305eb2c[10] & 0xfe;
        PTR_DAT_0305eb24[0x328] = 0;
      }
    }
  }
  else {
    update_event_flags_byte_dispatch(6,1);
    tx_led_or_tone_on();
    *(undefined1 *)p_tx_ptt_ui_state = 10;
    PTR_DAT_0305eb24[0x328] = 2;
    SUBPIECE_SET(uVar1, 0, 1, p_radio_mode_state_0003e318[1].flags_0x6);
    SUBPIECE_SET(uVar1, 1, 1, p_radio_mode_state_0003e318[1].flags_0x7);
    if ((uVar1 & 0x480) == 0) {
      p_tx_ptt_ui_state->field_0xc = p_tx_ptt_ui_state->field_0xc & 0xdf | 0x20;
      ui_event_notify(0x1c);
    }
  }
  return;
}

