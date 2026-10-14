/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_task_create_prio5_stk0x80 @ 0301b954 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
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

void ucos3_task_create_prio5_stk0x80(void)

{
  undefined4 uVar1;
  undefined1 auStack_c [4];
  
  uVar1 = _DAT_0301b9cc;
  memset_bytes(_DAT_0301b9cc,0,0x200);
  OSTaskCreate(_DAT_0301b9d0,_DAT_0301b9d4,_DAT_0301b9d8,0,5,uVar1,0,0x80,0,0,0,3,auStack_c);
  return;
}

