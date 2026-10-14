/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_set_pending_render_flag @ 03055678 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_set_pending_render_flag(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_030557d4;
  if ((p_dialog_flags_from_flash->flags_0x1 & 3) == 1) {
    if (param_1 == 0) {
LAB_030556bc:
      PTR_DAT_030557d4[6] = PTR_DAT_030557d4[6] & 0xfe;
      return;
    }
    if (((p_dialog_flags_from_flash->flags_0x1f & 0x78) == 0x20) &&
       ((p_dialog_flags_from_flash->field_0x20 & 0x10) != 0)) {
      return;
    }
  }
  else if (param_1 == 0) goto LAB_030556bc;
  PTR_DAT_030557d4[6] = PTR_DAT_030557d4[6] & 0xfe | 1;
  puVar1[7] = 1;
  return;
}

