/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: softfloat32_compare @ 0306e7a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 softfloat32_compare(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint local_38 [4];
  uint local_28 [4];
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = param_2;
  local_14 = param_1;
  float32_unpack(&local_14,local_28);
  float32_unpack(&local_18,local_38);
  if ((local_28[0] < 2) || (local_38[0] < 2)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = softfloat_compare_core(local_28,local_38);
  }
  return uVar1;
}

