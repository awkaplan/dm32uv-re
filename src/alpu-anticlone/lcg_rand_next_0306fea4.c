/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: lcg_rand_next @ 0306fea4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 20 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint lcg_rand_next(void)

{
  uint uVar1;
  
  uVar1 = *PTR_DAT_0306febc * DAT_0306feb8 + 0x3039;
  *PTR_DAT_0306febc = uVar1;
  return uVar1 >> 1;
}

