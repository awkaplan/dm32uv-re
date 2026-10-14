/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: update_and_apply_settings @ 030687f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: accessors
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void update_and_apply_settings(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4__w,undefined4 param_5)

{
  undefined2 param_4 = (undefined2)param_4__w;
  int iVar1;
  
  iVar1 = *PTR_OSTCBCurPtr_03068970;
  *(undefined4 *)(iVar1 + 0x80) = param_3;
  *(undefined2 *)(iVar1 + 0x88) = param_4;
  *(undefined4 *)(iVar1 + 0x84) = 0;
  OS_Pend(param_1,param_2,1,param_5);
  return;
}

