/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: pow10_decimal_exponent @ 0306fecc (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 pow10_decimal_exponent(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 5) {
    return PTR_DAT_0306ff14[param_1 * 2];
  }
  if ((param_1 & 1) == 0) {
    pow10_decimal_exponent(param_1 >> 1);
    uVar1 = soft_double_multiply();
    return uVar1;
  }
  pow10_decimal_exponent(param_1 - 1);
  uVar1 = soft_double_multiply();
  return uVar1;
}

