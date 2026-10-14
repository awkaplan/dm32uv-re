/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fixed_point_exp_aligned_less_than @ 030c8bb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool fixed_point_exp_aligned_less_than(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  
  param_1 = param_1 << 0x10;
  param_3 = param_3 << 0x10;
  if (param_1 == 0) {
    param_2 = param_4;
  }
  if (param_3 == 0) {
    param_3 = 0;
  }
  else {
    uVar1 = param_4 - param_2;
    if (0 < (int)uVar1) {
      return param_3 < param_1 >> (uVar1 & 0x3f);
    }
    param_3 = param_3 >> (-uVar1 & 0x3f);
  }
  return param_3 < param_1;
}

