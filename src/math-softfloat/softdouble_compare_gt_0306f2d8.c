/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: softdouble_compare_gt @ 0306f2d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
softdouble_compare_gt(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint local_48 [5];
  uint local_34 [5];
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_20 = param_3;
  uStack_1c = param_4;
  local_18 = param_1;
  uStack_14 = param_2;
  soft_double_unpack(&local_18,local_34);
  soft_double_unpack(&local_20,local_48);
  uVar1 = 1;
  if ((1 < local_34[0]) && (1 < local_48[0])) {
    uVar1 = soft_double_compare(local_34,local_48);
  }
  return uVar1;
}

