/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: add_64 @ 0306f0fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void add_64(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint unaff_r4;
  int unaff_r5;
  int unaff_r8;
  int unaff_r11;
  int in_r12;
  int in_r13;
  undefined4 in_PSR;
  
  if ((!SUB41((uint)in_PSR >> 0x1f,0)) && (param_4 == 0)) {
    if (((unaff_r4 & 0x100) == 0) && (in_r12 != 0 || in_r13 != 0)) {
      unaff_r5 = (unaff_r5 + unaff_r8) - ((int)((uint)CARRY4(unaff_r4,param_3) << 0x1f) >> 0x1f);
      unaff_r4 = unaff_r4 + param_3 & 0xffffff00;
    }
  }
  *(uint *)(unaff_r11 + 0xc) = unaff_r4;
  *(int *)(unaff_r11 + 0x10) = unaff_r5;
  soft_double_pack_and_round();
  return;
}

