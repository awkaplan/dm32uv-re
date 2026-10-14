/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: softdouble_extract_exponent_mantissa @ 0306f450 (file base 0x03000000; code starts at 0x03001000)
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

void softdouble_extract_exponent_mantissa(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  int iStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = param_1;
  uStack_14 = param_2;
  soft_double_unpack(&local_18,&local_2c);
  uVar1 = iStack_1c << 2 | uStack_20 >> 0x1e;
  if ((uStack_20 & 0x3fffffff) != 0) {
    uVar1 = uVar1 | 1;
  }
  float32_pack_round_from_4args(local_2c,uStack_28,uStack_24,uVar1);
  return;
}

