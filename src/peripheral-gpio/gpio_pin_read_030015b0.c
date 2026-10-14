/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gpio_pin_read @ 030015b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-gpio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool gpio_pin_read(uint param_1)

{
  dword dVar1;
  bool bVar2;
  
  if (param_1 < 0x20) {
    dVar1 = GPIOA_14020000.EXT_PORTA;
    bVar2 = (1 << (param_1 & 0x3f) & dVar1) != 0;
  }
  else if (param_1 < 0x40) {
    dVar1 = GPIOB_14100000.EXT_PORTA;
    bVar2 = (1 << (param_1 - 0x20 & 0x3f) & dVar1) != 0;
  }
  else {
    dVar1 = GPIOC_14110000.EXT_PORTA;
    bVar2 = (1 << (param_1 - 0x40 & 0x3f) & dVar1) != 0;
  }
  return bVar2;
}

