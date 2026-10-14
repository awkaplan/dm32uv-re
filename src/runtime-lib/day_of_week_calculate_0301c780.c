/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: day_of_week_calculate @ 0301c780 (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint day_of_week_calculate(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2 >> 8 & 0xff;
  uVar2 = (param_2 >> 0x10) % 100;
  if (((param_2 >> 0x10) / 100 & 0xff) == 0x14) {
    uVar2 = uVar2 + 100;
  }
  uVar1 = (param_2 & 0xff) + (uint)*(byte *)(uVar3 + DAT_0301c91c) + ((uVar2 >> 2) + uVar2) % 7;
  if (((uVar2 & 3) == 0) && (uVar3 < 3)) {
    uVar1 = uVar1 - 1 & 0xffff;
  }
  return uVar1 % 7;
}

