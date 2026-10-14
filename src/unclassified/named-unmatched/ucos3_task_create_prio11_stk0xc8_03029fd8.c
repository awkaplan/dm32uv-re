/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_task_create_prio11_stk0xc8 @ 03029fd8 (file base 0x03000000; code starts at 0x03001000)
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

void ucos3_task_create_prio11_stk0xc8(void)

{
  undefined4 uVar1;
  undefined1 auStack_c [4];
  
  uVar1 = _LAB_0302a18c;
  memset_bytes(_LAB_0302a18c,0,800);
  OSTaskCreate(_LAB_0302a190,_DAT_0302a194,_LAB_0302a198,0,0xb,uVar1,0,200,0,0,0,3,auStack_c);
  return;
}

