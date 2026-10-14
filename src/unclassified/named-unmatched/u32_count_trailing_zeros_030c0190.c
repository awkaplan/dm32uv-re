/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: u32_count_trailing_zeros @ 030c0190 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int u32_count_trailing_zeros(uint param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0x20;
  }
  else {
    iVar1 = count_leading_zeros_u32(param_1 & -param_1);
    iVar1 = 0x1f - iVar1;
  }
  return iVar1;
}

