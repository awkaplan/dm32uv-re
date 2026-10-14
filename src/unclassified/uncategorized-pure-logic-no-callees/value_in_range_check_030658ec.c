/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: value_in_range_check @ 030658ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte value_in_range_check(ushort param_1)

{
  byte bVar1;
  
  if (*(ushort *)PTR_DAT_03065974 < param_1) {
    bVar1 = 1;
  }
  else {
    bVar1 = ~(*(ushort *)PTR_DAT_03065978 <= param_1);
  }
  return bVar1;
}

