/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gpio_drv_set_output @ 03001124 (file base 0x03000000; code starts at 0x03001000)
 * Size: 248 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-gpio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gpio_drv_set_output(uint param_1,int param_2)

{
  dword dVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 < 0x20) {
    dVar1 = GPIOA_14020000.INTEN;
    uVar2 = 1 << (param_1 & 0x3f);
    uVar3 = ~uVar2;
    GPIOA_14020000.INTEN = dVar1 & uVar3;
    dVar1 = GPIOA_14020000.INTTYPE_LEVEL;
    GPIOA_14020000.INTTYPE_LEVEL = dVar1 & uVar3;
    dVar1 = GPIOA_14020000.INT_POLARITY;
    GPIOA_14020000.INT_POLARITY = dVar1 & uVar3;
    dVar1 = GPIOA_14020000.SWPORTA_DDR;
    GPIOA_14020000.SWPORTA_DDR = dVar1 | uVar2;
    if (param_2 == 0) {
      dVar1 = GPIOA_14020000.SWPORTA_DR;
      GPIOA_14020000.SWPORTA_DR = uVar3 & dVar1;
    }
    else {
      dVar1 = GPIOA_14020000.SWPORTA_DR;
      GPIOA_14020000.SWPORTA_DR = uVar2 | dVar1;
    }
  }
  else if (param_1 < 0x40) {
    dVar1 = GPIOB_14100000.INTEN;
    uVar2 = 1 << (param_1 - 0x20 & 0x3f);
    uVar3 = ~uVar2;
    GPIOB_14100000.INTEN = dVar1 & uVar3;
    dVar1 = GPIOB_14100000.INTTYPE_LEVEL;
    GPIOB_14100000.INTTYPE_LEVEL = dVar1 & uVar3;
    dVar1 = GPIOB_14100000.INT_POLARITY;
    GPIOB_14100000.INT_POLARITY = dVar1 & uVar3;
    dVar1 = GPIOB_14100000.SWPORTA_DDR;
    GPIOB_14100000.SWPORTA_DDR = dVar1 | uVar2;
    if (param_2 == 0) {
      dVar1 = GPIOB_14100000.SWPORTA_DR;
      GPIOB_14100000.SWPORTA_DR = uVar3 & dVar1;
    }
    else {
      dVar1 = GPIOB_14100000.SWPORTA_DR;
      GPIOB_14100000.SWPORTA_DR = uVar2 | dVar1;
    }
  }
  else {
    dVar1 = GPIOC_14110000.INTEN;
    uVar2 = 1 << (param_1 - 0x40 & 0x3f);
    uVar3 = ~uVar2;
    GPIOC_14110000.INTEN = dVar1 & uVar3;
    dVar1 = GPIOC_14110000.INTTYPE_LEVEL;
    GPIOC_14110000.INTTYPE_LEVEL = dVar1 & uVar3;
    dVar1 = GPIOC_14110000.INT_POLARITY;
    GPIOC_14110000.INT_POLARITY = dVar1 & uVar3;
    dVar1 = GPIOC_14110000.SWPORTA_DDR;
    GPIOC_14110000.SWPORTA_DDR = dVar1 | uVar2;
    if (param_2 == 0) {
      dVar1 = GPIOC_14110000.SWPORTA_DR;
      GPIOC_14110000.SWPORTA_DR = uVar3 & dVar1;
    }
    else {
      dVar1 = GPIOC_14110000.SWPORTA_DR;
      GPIOC_14110000.SWPORTA_DR = uVar2 | dVar1;
    }
  }
  return;
}

