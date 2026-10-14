/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_task_create_prio34_stk0x100 @ 03055604 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
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

void ucos3_task_create_prio34_stk0x100(void)

{
  undefined4 uVar1;
  undefined1 auStack_c [4];
  
  uVar1 = _DAT_03055668;
  memset_bytes(_DAT_03055668,0,0x400);
  OSTaskCreate(_DAT_0305566c,_DAT_03055670,_DAT_03055674,0,0x22,uVar1,0,0x100,0,0,0,3,auStack_c);
  return;
}

