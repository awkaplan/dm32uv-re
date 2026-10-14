/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_to_int_round_ceil_variant @ 0306d5b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: math-softfloat
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint soft_double_to_int_round_ceil_variant(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 != 0 || param_2 != 0) {
    uVar2 = param_2 >> 0x14 & 0x7ff;
    if (uVar2 - 0x3ff < 0x34) {
      if ((int)(uVar2 - 0x3ff) < 0x15) {
        param_1 = 0;
      }
      else {
        uVar1 = 0x20 - (uVar2 - 0x413);
        uVar3 = param_1 >> (uVar1 & 0x3f);
        if (((int)param_2 < 0) && (param_1 << (uVar2 - 0x413 & 0x3f) != 0)) {
          param_1 = uVar3 + 1 << (uVar1 & 0x3f);
        }
        else {
          param_1 = uVar3 << (uVar1 & 0x3f);
        }
      }
    }
    else if (uVar2 < 0x3ff) {
      if (-1 < (int)param_2) {
        return 0;
      }
      return 0;
    }
  }
  return param_1;
}

