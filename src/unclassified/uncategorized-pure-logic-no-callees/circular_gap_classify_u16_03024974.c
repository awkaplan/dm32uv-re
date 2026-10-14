/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: circular_gap_classify_u16 @ 03024974 (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined1 circular_gap_classify_u16(uint param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xffff;
  if (param_1 < param_2) {
    uVar1 = (int)(param_3 & 0xffff) < (int)(param_2 - param_1);
  }
  else if ((int)(param_3 & 0xffff) < (int)(param_1 - param_2)) {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

