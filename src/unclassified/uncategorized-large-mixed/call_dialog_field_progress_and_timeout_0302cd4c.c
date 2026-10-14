/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_dialog_field_progress_and_timeout @ 0302cd4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 292 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_dialog_field_progress_and_timeout(void)

{
  byte *pbVar1;
  dialog_flags_from_flash *pdVar2;
  byte bVar3;
  
  if ((p_dialog_flags_from_flash->flags_0x1d >> 4 & 7) !=
      (p_dialog_flags_from_flash->flags_0x1d >> 1 & 7)) {
    bVar3 = p_dialog_flags_from_flash->flags_0x1d & 0xe;
    if (bVar3 == 6) {
      p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xfe;
      ui_event_notify(0x1b);
    }
    else if (bVar3 == 4) {
      p_dialog_flags_from_flash->flags_0x1e = p_dialog_flags_from_flash->flags_0x1e & 0x8f | 0x10;
      p_tx_ptt_ui_state->field_0x5 = 0;
      ui_event_notify(0x1a);
    }
    contact_field_name_display_dispatch();
    p_dialog_flags_from_flash->flags_0x1d =
         p_dialog_flags_from_flash->flags_0x1d & 0x8f |
         (p_dialog_flags_from_flash->flags_0x1d >> 1 & 7) << 4;
  }
  if ((p_dialog_flags_from_flash->flags_0x1d & 0xe) == 4) {
    bVar3 = p_dialog_flags_from_flash->flags_0x1e & 0x70;
    if (bVar3 == 0x10) {
      bVar3 = p_tx_ptt_ui_state->field_0x5 + 1;
      p_tx_ptt_ui_state->field_0x5 = bVar3;
      if ((*(byte *)p_call_active_flag & 1) == 0) {
        if (0x96 < bVar3) {
          p_dialog_flags_from_flash->flags_0x1e =
               p_dialog_flags_from_flash->flags_0x1e & 0x8f | 0x30;
        }
      }
      else {
        p_dialog_flags_from_flash->flags_0x1e = p_dialog_flags_from_flash->flags_0x1e & 0x8f | 0x20;
        p_tx_ptt_ui_state->field_0x5 = 0;
      }
    }
    else if (bVar3 == 0x20) {
      if ((*(byte *)p_call_active_flag & 1) == 0) {
        p_dialog_flags_from_flash->flags_0x1e = p_dialog_flags_from_flash->flags_0x1e & 0x8f | 0x30;
      }
      *(short *)&p_tx_ptt_ui_state->field_0x60_0 = *(short *)&p_tx_ptt_ui_state->field_0x60_0 + 1;
    }
    if ((p_dialog_flags_from_flash->flags_0x1f & 7) !=
        (p_dialog_flags_from_flash->flags_0x1e >> 4 & 7)) {
      contact_field_name_display_dispatch();
      pdVar2 = p_dialog_flags_from_flash;
      pbVar1 = &p_dialog_flags_from_flash->flags_0x1e;
      p_dialog_flags_from_flash->flags_0x1f =
           p_dialog_flags_from_flash->flags_0x1f & 0xf8 | *pbVar1 >> 4 & 7;
      if ((*pbVar1 & 0x70) == 0x30) {
        pdVar2->flags_0x1d = pdVar2->flags_0x1d & 0xfe;
        pdVar2->flags_0x1e = pdVar2->flags_0x1e & 0xf0;
      }
    }
  }
  return;
}

