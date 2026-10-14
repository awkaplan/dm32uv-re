/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_flags_clear_for_channel_sync @ 0305d958 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_flags_clear_for_channel_sync(void)

{
  dialog_flags_from_flash *pdVar1;
  
  pdVar1 = p_dialog_flags_from_flash;
  p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xfe;
  pdVar1->flags_0x1 = pdVar1->flags_0x1 & 0xf8;
  clear_field_bit3_and_set_dialog_bit();
  pdVar1->flags_0x2d = pdVar1->flags_0x2d & 0xf7;
  return;
}

