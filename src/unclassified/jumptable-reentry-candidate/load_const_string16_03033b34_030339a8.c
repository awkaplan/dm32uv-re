/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: load_const_string16_03033b34 @ 030339a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 18 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void load_const_string16_03033b34(undefined4 param_1,undefined4 param_2)

{
  int unaff_r4;
  
  memcpy_bytes_iram(param_2,DAT_03033b34,0x10);
  *(undefined1 *)(unaff_r4 + 0x10) = 0;
  return;
}

