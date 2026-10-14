/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: count_clear_bits_low23 @ 0305f540 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char count_clear_bits_low23(uint param_1)

{
  char cVar1;
  char cVar2;
  
  cVar2 = '\x17';
  cVar1 = '\0';
  while( true ) {
    if ((param_1 & 1) == 0) {
      cVar1 = cVar1 + '\x01';
    }
    cVar2 = cVar2 + -1;
    if (cVar2 == '\0') break;
    param_1 = param_1 >> 1;
  }
  return cVar1;
}

