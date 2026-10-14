/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_edit_field_action_dispatch @ 03043d5c (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void contact_edit_field_action_dispatch(void)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_03043d98 + 2);
  if (uVar1 < 5) {
                    /* WARNING: Could not recover jumptable at 0x03043d72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_03043d9c[uVar1] & 0xfffffffe))();
    return;
  }
  return;
}

