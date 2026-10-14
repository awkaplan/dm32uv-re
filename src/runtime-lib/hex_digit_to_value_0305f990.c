/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hex_digit_to_value @ 0305f990 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte hex_digit_to_value(char param_1)

{
  byte bVar1;
  
  bVar1 = param_1 - 0x30;
  if (9 < bVar1) {
    if ((byte)(param_1 + 0xbfU) < 6) {
      bVar1 = param_1 - 0x37;
    }
    else if ((byte)(param_1 + 0x9fU) < 6) {
      bVar1 = param_1 + 0xa9;
    }
    else {
      bVar1 = 0;
    }
  }
  return bVar1;
}

