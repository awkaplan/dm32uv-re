/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_leave_locked_state @ 0305daf0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_leave_locked_state(void)

{
  dialog_flags_from_flash *pdVar1;
  
  pdVar1 = p_dialog_flags_from_flash;
  *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xfe;
  dialog_state_set_2bit_at_1();
  if ((pdVar1->flags_0x2d & 1) != 0) {
    pdVar1->flags_0x2d = pdVar1->flags_0x2d & 0xfe;
    OSFlagPost_wrapper_set(p_ucos_flaggrp_0003fd90,0x10000);
  }
  return;
}

