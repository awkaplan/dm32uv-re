/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_timer_live_count_decrement_hook @ 03002a84 (file base 0x03000000; code starts at 0x03001000)
 * Size: 20 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ucos_timer_live_count_decrement_hook(void)

{
  undefined4 uVar1;
  
  if (*(char *)PTR_LAB_03002a98 == '\x01') {
    uVar1 = func_0x05ff3ac0();
    *PTR_DAT_03002a9c = uVar1;
  }
  return;
}

