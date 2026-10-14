/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bounded_queue_enqueue_fetched_value @ 030c3d48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void bounded_queue_enqueue_fetched_value(void)

{
  undefined4 uVar1;
  undefined1 auStack_8 [4];
  
  FUN_030c0474();
  uVar1 = func_0x0611caf4();
  bounded_queue_append_with_dropcount
            (_DAT_030c3d7c,_DAT_030c3d80 + (uint)*_DAT_030c3d78 * 0xc,0,0,0,0,uVar1,auStack_8);
  return;
}

