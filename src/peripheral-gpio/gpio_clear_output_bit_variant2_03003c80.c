/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gpio_clear_output_bit_variant2 @ 03003c80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-gpio
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gpio_clear_output_bit_variant2(uint param_1)

{
  uint uVar1;
  dword dVar2;
  
  if (param_1 < 0x20) {
    dVar2 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR =
         (-2 << (param_1 & 0x3f) | 0xfffffffeU >> 0x20 - (param_1 & 0x3f)) & dVar2;
  }
  else if (param_1 < 0x40) {
    dVar2 = GPIOB_14100000.SWPORTA_DR;
    uVar1 = param_1 - 0x20 & 0x3f;
    GPIOB_14100000.SWPORTA_DR = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & dVar2;
  }
  else {
    dVar2 = GPIOC_14110000.SWPORTA_DR;
    uVar1 = param_1 - 0x40 & 0x3f;
    GPIOC_14110000.SWPORTA_DR = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & dVar2;
  }
  return;
}

