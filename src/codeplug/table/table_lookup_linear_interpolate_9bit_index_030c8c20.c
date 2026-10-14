/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_lookup_linear_interpolate_9bit_index @ 030c8c20 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint table_lookup_linear_interpolate_9bit_index(int param_1)

{
  uint uVar1;
  
  uVar1 = (param_1 << 0x10) >> 6;
  if ((int)uVar1 < 0) {
    uVar1 = ~uVar1 + 1;
  }
  return ((uVar1 & 0xffff) * (int)(short)PTR_DAT_030c8c58[(uVar1 >> 0x10) + 1 & 0x1ff] +
         (short)PTR_DAT_030c8c58[(short)(uVar1 >> 0x10)] * 0x10000) -
         (int)(short)PTR_DAT_030c8c58[(short)(uVar1 >> 0x10)] * (uVar1 & 0xffff) >> 0x10;
}

