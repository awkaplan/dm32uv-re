/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: shift_left_64 @ 0306fcd0 (file base 0x03000000; code starts at 0x03001000)
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

int shift_left_64(int param_1,undefined4 param_2,uint param_3)

{
  if (param_3 != 0) {
    if ((int)(0x20 - param_3) < 1) {
      param_1 = 0;
    }
    else {
      param_1 = param_1 << (param_3 & 0x3f);
    }
  }
  return param_1;
}

