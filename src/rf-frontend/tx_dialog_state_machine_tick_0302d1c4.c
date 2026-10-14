/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_dialog_state_machine_tick @ 0302d1c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 412 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_dialog_state_machine_tick(void)

{
  dialog_flags_from_flash *pdVar1;
  int iVar2;
  byte bVar3;
  
  if (((p_dialog_flags_from_flash->flags_0x1 & 3) == 1) &&
     ((p_dialog_flags_from_flash->flags_0x1f & 0x78) != 0x40)) {
    if (((p_dialog_flags_from_flash->field_0x30 & 8) != 0) &&
       (bVar3 = p_dialog_flags_from_flash->field_0x31 + 1,
       p_dialog_flags_from_flash->field_0x31 = bVar3, pdVar1 = p_dialog_flags_from_flash, 4 < bVar3)
       ) {
      p_dialog_flags_from_flash->field_0x30 = p_dialog_flags_from_flash->field_0x30 & 0xf7;
      pdVar1->field_0x31 = 0;
      if (((pdVar1->field_0x3e & 1) == 0) || (iVar2 = read_field_0x18_bit4(), iVar2 != 0)) {
        p_dialog_flags_from_flash->flags_0x1f = p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x28;
      }
      else {
        channel_dialog_commit_flags_update();
      }
    }
    if ((p_dialog_flags_from_flash->field_0x20 & 0xf) !=
        (p_dialog_flags_from_flash->flags_0x1f >> 3 & 0xf)) {
      p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xfe | 1;
      pdVar1 = p_dialog_flags_from_flash;
      bVar3 = p_dialog_flags_from_flash->flags_0x1f & 0x78;
      if (bVar3 == 0x10) {
        if (p_dialog_flags_from_flash->field_0x3f == 5) {
          p_dialog_flags_from_flash->flags_0x1f =
               p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x40;
        }
        else if (p_dialog_flags_from_flash->field_0x33 == 1) {
          *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0x7f | 0x80;
          pdVar1->field_0x30 = pdVar1->field_0x30 & 0xfe | 1;
        }
        else if (p_dialog_flags_from_flash->field_0x33 == 2) {
          p_dialog_flags_from_flash->field_0x30 = p_dialog_flags_from_flash->field_0x30 & 0xf7 | 8;
          pdVar1->field_0x31 = 0;
          p_tx_ptt_ui_state->field_0x4 = 0;
        }
      }
      else if (bVar3 == 0x18) {
        if (p_dialog_flags_from_flash->field_0x3f == 5) {
          p_dialog_flags_from_flash->flags_0x1f =
               p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x40;
        }
        else if (p_dialog_flags_from_flash->field_0x33 == 1) {
          *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0x7f | 0x80;
          pdVar1->field_0x30 = pdVar1->field_0x30 & 0xfe | 1;
        }
        else if (p_dialog_flags_from_flash->field_0x33 == 2) {
          p_dialog_flags_from_flash->field_0x30 = p_dialog_flags_from_flash->field_0x30 & 0xf7 | 8;
          pdVar1->field_0x31 = 0;
          p_tx_ptt_ui_state->field_0x4 = 0;
        }
      }
      p_dialog_flags_from_flash->field_0x20 =
           p_dialog_flags_from_flash->field_0x20 & 0xf0 |
           p_dialog_flags_from_flash->flags_0x1f >> 3 & 0xf;
    }
    if (((p_dialog_flags_from_flash->flags_0x1f & 0x78) == 0x20) &&
       (bVar3 = p_tx_ptt_ui_state->field_0x6 + 1, p_tx_ptt_ui_state->field_0x6 = bVar3, 10 < bVar3))
    {
      p_tx_ptt_ui_state->field_0x6 = 0;
      dialog_history_advance_or_dispatch();
    }
  }
  return;
}

