/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: umul32_to_64 @ 0306f5a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int umul32_to_64(uint param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (param_3 & 0xffff) * (param_1 & 0xffff);
  return ((param_1 >> 0x10) * (param_3 & 0xffff) + (param_3 >> 0x10) * (param_1 & 0xffff) +
         (uVar1 >> 0x10)) * 0x10000 + (uVar1 & 0xffff);
}

