/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_flags_restore_from_flash_0xf00 @ 0305dbb0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_flags_restore_from_flash_0xf00(void)

{
  byte bStack_9;
  
  flash_field_read_cached(4,0xf00,&bStack_9,1);
  p_dialog_flags_from_flash->field_0x40 = bStack_9;
  if ((byte)(bStack_9 + 0x5b) < 2) {
    clear_bit1_set_bit2_and_dialog_state();
  }
  else {
    dialog_clear_flag_bit1_then_set_state();
  }
  return;
}

