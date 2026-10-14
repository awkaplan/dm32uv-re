/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c3dac @ 030c3dac (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c3dac(uint param_1)

{
  dword dVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 < 0x20) {
    uVar2 = 1 << (param_1 & 0x3f);
    dVar1 = GPIOA_14020000.INTEN;
    uVar3 = ~uVar2;
    GPIOA_14020000.INTEN = dVar1 & uVar3;
    dVar1 = GPIOA_14020000.INTTYPE_LEVEL;
    GPIOA_14020000.INTTYPE_LEVEL = dVar1 & uVar3;
    dVar1 = GPIOA_14020000.INT_POLARITY;
    GPIOA_14020000.INT_POLARITY = uVar3 & dVar1;
    dVar1 = GPIOA_14020000.SWPORTA_DDR;
    GPIOA_14020000.SWPORTA_DDR = dVar1 | uVar2;
    dVar1 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = uVar2 | dVar1;
  }
  return;
}

