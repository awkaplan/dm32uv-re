/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gpio_portb_read_input_bits_17_to_20 @ 030135d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 12 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-gpio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint gpio_portb_read_input_bits_17_to_20(void)

{
  dword dVar1;
  
  dVar1 = GPIOB_14100000.EXT_PORTA;
  return dVar1 >> 0x11 & 0xf;
}

