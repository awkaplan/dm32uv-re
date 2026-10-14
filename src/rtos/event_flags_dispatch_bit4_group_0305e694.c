/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: event_flags_dispatch_bit4_group @ 0305e694 (file base 0x03000000; code starts at 0x03001000)
 * Size: 278 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void event_flags_dispatch_bit4_group(void)

{
  byte bVar1;
  
  bVar1 = get_event_flags_byte_dispatch(4);
  if ((bVar1 & 1) == 0) {
    if ((bVar1 & 2) == 0) {
      if ((bVar1 & 4) == 0) {
        if ((bVar1 & 8) == 0) {
          if ((bVar1 & 0x10) != 0) {
            update_event_flags_byte_dispatch(4,0x10);
            format_and_write_status_field
                      (0x1d,0x14,
                       **(undefined4 **)
                         (PTR_PTR_0305e7c4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
            ui_event_notify(0x1b);
          }
        }
        else {
          tx_led_or_tone_on();
          update_event_flags_byte_dispatch(4,8);
        }
      }
      else {
        tx_led_or_tone_on();
        *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0x3f | 0x80;
        update_event_flags_byte_dispatch(2,2);
        update_event_flags_byte_dispatch(4,4);
      }
    }
    else {
      update_event_flags_byte_dispatch(4,2);
      ui_event_notify(0x1b);
    }
  }
  else {
    update_event_flags_byte_dispatch(4,1);
    tx_led_or_tone_on();
    dialog_set_pending_render_flag(0);
    dialog_state_set_2bit_at_1(0);
    *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xfd;
    p_tx_ptt_ui_state->field_0x1 = 5;
    PTR_DAT_0305e7b4[6] = 0;
    if ((*(byte *)p_dialog_flags_from_flash & 1) == 0) {
      if (p_tx_ptt_ui_state->field_0x1c == 1) {
        p_tx_ptt_ui_state->field_0xc = p_tx_ptt_ui_state->field_0xc & 0xfb | 4;
      }
    }
    else {
      dialog_leave_locked_state();
    }
    if ((PTR_DAT_0305e7bc[6] & 2) != 0) {
      PTR_DAT_0305e7bc[6] = PTR_DAT_0305e7bc[6] & 0xfd;
      ui_event_notify(0x1b);
    }
  }
  return;
}

