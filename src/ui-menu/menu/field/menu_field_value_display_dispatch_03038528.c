/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_field_value_display_dispatch @ 03038528 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_field_value_display_dispatch(void)

{
  uint uVar1;
  
  if ((*(byte *)PTR_DAT_03038584 & 2) == 0) {
    display_fill_rect(0,0,0xf0,0x1b,0);
    uVar1 = p_dialog_history_ui_state->field_0x3 - 7 & 0xff;
    if (uVar1 < 0x32) {
                    /* WARNING: Could not recover jumptable at 0x03038570. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_03038588[uVar1] & 0xfffffffe))();
      return;
    }
    display_draw_number_centered(1,0xffff,0,(uint)PTR_LAB_03038e58);
  }
  return;
}

