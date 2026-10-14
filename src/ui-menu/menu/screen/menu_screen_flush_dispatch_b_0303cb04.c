/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_flush_dispatch_b @ 0303cb04 (file base 0x03000000; code starts at 0x03001000)
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

void menu_screen_flush_dispatch_b(void)

{
  uint uVar1;
  
  dialog_history_flush_and_reset();
  uVar1 = (uint)*(byte *)((uint)(byte)PTR_g_menu_screen_state_0303cb20[1] + DAT_0303cb24 + 2);
  if (uVar1 < 8) {
                    /* WARNING: Could not recover jumptable at 0x0303cb1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0303cb28[uVar1] & 0xfffffffe))();
    return;
  }
  main_menu_screen_dispatch();
  return;
}

