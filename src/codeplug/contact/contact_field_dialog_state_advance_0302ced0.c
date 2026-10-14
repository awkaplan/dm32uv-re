/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_field_dialog_state_advance @ 0302ced0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 180 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void contact_field_dialog_state_advance(void)

{
  byte bVar1;
  
  if ((p_tx_ptt_ui_state->flags_0xb & 4) == 0) {
    if ((p_dialog_flags_from_flash->flags_0x1e & 0xf) == 2) {
      call_dialog_field_progress_and_timeout();
    }
    else if ((p_dialog_flags_from_flash->flags_0x1d >> 4 & 7) ==
             (p_dialog_flags_from_flash->flags_0x1d >> 1 & 7)) {
      bVar1 = p_dialog_flags_from_flash->flags_0x1d & 0xe;
      if (((bVar1 == 6) || (bVar1 == 4)) && ((p_dialog_flags_from_flash->flags_0x1d & 1) != 0)) {
        p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xfe;
      }
    }
    else {
      contact_field_name_display_dispatch();
      bVar1 = p_dialog_flags_from_flash->flags_0x1d & 0xe;
      if (bVar1 == 6) {
        p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xfe;
        ui_event_notify(0x1b);
      }
      else if (bVar1 == 4) {
        p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xfe;
        ui_event_notify(0x1a);
      }
      p_dialog_flags_from_flash->flags_0x1d =
           p_dialog_flags_from_flash->flags_0x1d & 0x8f |
           (p_dialog_flags_from_flash->flags_0x1d >> 1 & 7) << 4;
    }
  }
  else {
    contact_name_field_refresh_dispatch();
    p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xfb;
  }
  return;
}

