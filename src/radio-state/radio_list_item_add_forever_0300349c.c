/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_list_item_add_forever @ 0300349c (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_list_item_add_forever(void)

{
  undefined4 uVar1;
  undefined1 auStack_14 [4];
  
  FUN_03002364(*PTR_DAT_030034bc);
  uVar1 = *PTR_LAB_030034c0;
  do {
    radio_list_item_add_guarded(uVar1,0,auStack_14);
  } while( true );
}

