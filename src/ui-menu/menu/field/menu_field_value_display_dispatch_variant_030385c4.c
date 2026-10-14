/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_field_value_display_dispatch_variant @ 030385c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_field_value_display_dispatch_variant(void)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x1 + DAT_030385e8 + 2);
  if (uVar1 < 10) {
                    /* WARNING: Could not recover jumptable at 0x030385d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_030385f0[uVar1] & 0xfffffffe))();
    return;
  }
  display_draw_number_centered(1,0xffff,0,(uint)PTR_LAB_03038784);
  return;
}

