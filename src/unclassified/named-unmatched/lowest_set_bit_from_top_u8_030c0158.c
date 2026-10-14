/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: lowest_set_bit_from_top_u8 @ 030c0158 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int lowest_set_bit_from_top_u8(byte param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 8;
  }
  else {
    iVar1 = FUN_030bffd4(param_1 & -param_1);
    iVar1 = 7 - iVar1;
  }
  return iVar1;
}

