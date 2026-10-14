/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: count_leading_zeros_u32 @ 030c0000 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint count_leading_zeros_u32(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 0x10000) {
    if (param_1 < 0x100) {
      uVar1 = *(byte *)(_DAT_030c00f8 + param_1) + 0x18;
    }
    else {
      uVar1 = *(byte *)(_DAT_030c00f8 + (param_1 >> 8)) + 0x10;
    }
  }
  else if (param_1 < 0x1000000) {
    uVar1 = *(byte *)(_DAT_030c00f8 + (param_1 >> 0x10)) + 8;
  }
  else {
    uVar1 = (uint)*(byte *)(_DAT_030c00f8 + (param_1 >> 0x18));
  }
  return uVar1;
}

