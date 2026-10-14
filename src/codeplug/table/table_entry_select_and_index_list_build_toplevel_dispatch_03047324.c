/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_entry_select_and_index_list_build_toplevel_dispatch @ 03047324 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void table_entry_select_and_index_list_build_toplevel_dispatch(void)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_0304736c + 2);
  if (uVar1 < 0x16) {
                    /* WARNING: Could not recover jumptable at 0x0304733e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_03047370[uVar1] & 0xfffffffe))();
    return;
  }
  return;
}

