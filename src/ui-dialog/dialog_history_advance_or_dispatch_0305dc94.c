/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_history_advance_or_dispatch @ 0305dc94 (file base 0x03000000; code starts at 0x03001000)
 * Size: 184 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_history_advance_or_dispatch(void)

{
  byte *pbVar1;
  dialog_flags_from_flash *pdVar2;
  dialog_flags_from_flash *pdVar3;
  byte bVar4;
  
  pdVar2 = p_dialog_flags_from_flash;
  if ((p_dialog_flags_from_flash->flags_0x1f & 0x78) == 0x20) {
    pbVar1 = &p_dialog_flags_from_flash->field_0x3c;
    if (p_dialog_flags_from_flash->field_0x3d < *pbVar1) {
      bVar4 = p_dialog_flags_from_flash->field_0x21 + 1;
      p_dialog_flags_from_flash->field_0x21 = bVar4;
      pdVar3 = p_dialog_flags_from_flash;
      if ((pdVar2->field_0x20 & 0x10) == 0) {
        if (p_dialog_flags_from_flash->field_0x3b < bVar4) {
          dialog_request_enqueue(2,*(void **)&p_dialog_flags_from_flash->field_0x28_0);
          pdVar3->field_0x20 = pdVar3->field_0x20 & 0xef | 0x10;
          pdVar3->field_0x21 = 0;
        }
      }
      else if ((p_dialog_flags_from_flash->flags_0x2f & 0x70) == 0) {
        p_dialog_flags_from_flash->field_0x3d = *pbVar1;
      }
      else if (p_dialog_flags_from_flash->field_0x3a < bVar4) {
        protocol_control_char_dispatch_dialog_history(1);
        pdVar2 = p_dialog_flags_from_flash;
        p_dialog_flags_from_flash->field_0x20 = p_dialog_flags_from_flash->field_0x20 & 0xef;
        pdVar2->field_0x3d = pdVar2->field_0x3d + 1;
        pdVar2->field_0x21 = 0;
      }
    }
    else {
      p_dialog_flags_from_flash->flags_0x1f = p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x28;
    }
  }
  return;
}

