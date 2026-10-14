/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: isxdigit_impl @ 0306b7ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool isxdigit_impl(char param_1)

{
  bool bVar1;
  
  if ((byte)(param_1 - 0x30U) < 10) {
    bVar1 = true;
  }
  else if ((byte)(param_1 + 0xbfU) < 6) {
    bVar1 = true;
  }
  else {
    bVar1 = (byte)(param_1 + 0x9fU) < 6;
  }
  return bVar1;
}

