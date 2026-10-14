/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_sector_erase_range_4kb @ 03003e9c (file base 0x03000000; code starts at 0x03001000)
 * Size: 132 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int flash_sector_erase_range_4kb(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*PTR_LAB_03003ff4 == 0) {
    iVar1 = -1;
  }
  else {
    uVar4 = param_2 >> 0xc;
    if ((param_2 & 0xfff) != 0) {
      uVar4 = uVar4 + 1;
    }
    if (uVar4 == 0) {
      iVar1 = 0;
    }
    else {
      uVar3 = param_1 & 0xfff000 | 0x20000000;
      uVar2 = 0;
      while ((iVar1 = FUN_03003d5c(6,1,0,0), iVar1 == 0 &&
             (iVar1 = FUN_03003d5c(uVar3,4,0,0), iVar1 == 0))) {
        FUN_03003cc4(0xa28);
        iVar1 = modem_wait_ready_then_proceed(0xfffff);
        if (iVar1 != 0) {
          return iVar1;
        }
        uVar2 = uVar2 + 1;
        if (uVar4 <= uVar2) {
          return 0;
        }
        uVar3 = uVar3 + 0x1000;
      }
    }
  }
  return iVar1;
}

