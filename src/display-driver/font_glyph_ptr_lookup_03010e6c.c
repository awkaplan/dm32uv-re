/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: font_glyph_ptr_lookup @ 03010e6c (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined * font_glyph_ptr_lookup(byte *param_1)

{
  int iVar1;
  
  if ((*param_1 - 0x20 & 0xff) < 0x5f) {
    iVar1 = (*param_1 - 0x20) * 0x10;
  }
  else {
    iVar1 = 0;
  }
  return PTR_LAB_03010fb8 + iVar1;
}

