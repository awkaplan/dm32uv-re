/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fixed_point_signed_divide_16bit @ 030c8b14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 136 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fixed_point_signed_divide_16bit
               (uint param_1,undefined4 param_2,short param_3,undefined4 param_4,undefined2 *param_5
               )

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)param_3;
  uVar1 = uVar2 ^ param_1;
  if ((int)param_1 < 0) {
    if (param_1 == 0x80000000) {
      param_1 = 0x7fffffff;
    }
    else {
      param_1 = -param_1;
    }
  }
  if ((int)uVar2 < 0) {
    if (uVar2 == 0xffff8000) {
      iVar3 = 0x7fff0000;
      uVar2 = 0x7fff;
    }
    else {
      uVar2 = (uint)-param_3;
      iVar3 = uVar2 << 0x10;
    }
  }
  else {
    iVar3 = uVar2 << 0x10;
  }
  if (iVar3 <= (int)param_1) {
    param_1 = (int)param_1 >> 1;
  }
  uVar2 = (uint)((int)param_1 / (int)uVar2) >> 1 & 0xffff;
  if ((int)uVar1 < 0) {
    uVar2 = -uVar2 & 0xffff;
  }
  if (uVar2 == 0) {
    *param_5 = 0;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

