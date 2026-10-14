/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: block_record_template_load_dispatch_0x69 @ 0304812c (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void block_record_template_load_dispatch_0x69(void)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_03048180 + 2);
  if (uVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x03048140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_03048184[uVar1] & 0xfffffffe))();
    return;
  }
  return;
}

