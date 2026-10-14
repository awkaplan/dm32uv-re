/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_flags_dismiss_if_state_0x20 @ 0305dd4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_flags_dismiss_if_state_0x20(void)

{
  dialog_flags_from_flash *pdVar1;
  
  pdVar1 = p_dialog_flags_from_flash;
  if (((p_dialog_flags_from_flash->flags_0x1f & 0x78) == 0x20) &&
     ((p_dialog_flags_from_flash->field_0x20 & 0x10) == 0)) {
    p_dialog_flags_from_flash->flags_0x1f = p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x28;
    pdVar1->field_0x20 = pdVar1->field_0x20 & 0xef;
    pdVar1->field_0x21 = 0;
  }
  return;
}

