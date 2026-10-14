/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: index_1based_to_slot_and_bit @ 03033498 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void index_1based_to_slot_and_bit(uint param_1,short *param_2,undefined1 *param_3)

{
  short sVar1;
  uint uVar2;
  
  sVar1 = (short)((param_1 & 0xffff) >> 3);
  *param_2 = sVar1;
  if ((param_1 & 7) == 0) {
    *param_2 = sVar1 + -1;
  }
  uVar2 = (param_1 & 0xffff) - 1 & 0x80000007;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
  }
  *param_3 = (char)uVar2;
  return;
}

