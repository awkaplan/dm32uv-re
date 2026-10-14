/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: byte_bit_reverse @ 030675f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint byte_bit_reverse(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xff;
  return (param_1 & 1) << 7 | (uVar1 >> 1 & 1) << 6 | (uVar1 >> 2 & 1) << 5 | (uVar1 >> 3 & 1) << 4
         | (uVar1 >> 4 & 1) << 3 | (uVar1 >> 5 & 1) << 2 | (uVar1 >> 6 & 1) << 1 | uVar1 >> 7;
}

