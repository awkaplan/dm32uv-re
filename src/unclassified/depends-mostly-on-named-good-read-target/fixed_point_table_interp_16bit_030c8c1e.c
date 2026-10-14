/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fixed_point_table_interp_16bit @ 030c8c1e (file base 0x03000000; code starts at 0x03001000)
 * Size: 2 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint fixed_point_table_interp_16bit(int param_1)

{
  uint uVar1;
  
  stub();
  uVar1 = (param_1 << 0x10) >> 6;
  if ((int)uVar1 < 0) {
    uVar1 = ~uVar1 + 1;
  }
  return ((uVar1 & 0xffff) * (int)(short)PTR_DAT_030c8c58[(uVar1 >> 0x10) + 1 & 0x1ff] +
         (short)PTR_DAT_030c8c58[(short)(uVar1 >> 0x10)] * 0x10000) -
         (int)(short)PTR_DAT_030c8c58[(short)(uVar1 >> 0x10)] * (uVar1 & 0xffff) >> 0x10;
}

