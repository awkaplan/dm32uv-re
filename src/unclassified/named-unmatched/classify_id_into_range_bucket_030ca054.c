/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: classify_id_into_range_bucket @ 030ca054 (file base 0x03000000; code starts at 0x03001000)
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

undefined2 classify_id_into_range_bucket(int param_1__w)

{
  short param_1 = (short)param_1__w;
  undefined2 uVar1;
  
  if ((ushort)(param_1 - 5U) < 0x76) {
    return 0;
  }
  if ((ushort)(param_1 - 0x80U) < 0x10) {
    return 1;
  }
  if ((ushort)(param_1 - 0x90U) < 0x10) {
    return 2;
  }
  if ((ushort)(param_1 - 0xa0U) < 4) {
    uVar1 = 3;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}

