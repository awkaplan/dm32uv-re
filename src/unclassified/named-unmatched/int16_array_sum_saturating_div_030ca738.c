/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: int16_array_sum_saturating_div @ 030ca738 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void int16_array_sum_saturating_div(short *param_1,short param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (iVar2 = (int)param_2; 0 < iVar2; iVar2 = iVar2 + -1) {
    iVar1 = iVar1 + *param_1;
    param_1 = param_1 + 1;
  }
  signed_divide_saturating(iVar1);
  return;
}

