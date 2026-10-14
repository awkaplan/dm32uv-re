/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: shift_right_64 @ 0306fca8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint shift_right_64(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (param_3 != 0) {
    uVar1 = 0x20 - param_3;
    if ((int)uVar1 < 1) {
      param_1 = param_2 >> (-uVar1 & 0x3f);
    }
    else {
      param_1 = param_1 >> (param_3 & 0x3f) | param_2 << (uVar1 & 0x3f);
    }
  }
  return param_1;
}

