/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: nibble_to_hex_ascii_uppercase @ 0305f524 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte nibble_to_hex_ascii_uppercase(byte param_1)

{
  if (param_1 < 10) {
    param_1 = param_1 + 0x30;
  }
  else if ((byte)(param_1 - 10) < 6) {
    param_1 = param_1 + 0x37;
  }
  return param_1;
}

