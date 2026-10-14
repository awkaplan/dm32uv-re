/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: u16_byte_swap_via_lookup @ 03067638 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

short u16_byte_swap_via_lookup(uint param_1)

{
  short sVar1;
  short sVar2;
  
  sVar1 = byte_bit_reverse((param_1 & 0xffff) >> 8);
  sVar2 = byte_bit_reverse(param_1 & 0xff);
  return sVar1 * 0x100 + sVar2;
}

