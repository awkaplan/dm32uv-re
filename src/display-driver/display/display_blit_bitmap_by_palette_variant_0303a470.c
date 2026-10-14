/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_blit_bitmap_by_palette_variant @ 0303a470 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_blit_bitmap_by_palette_variant(int param_1__w,uint param_2)

{
  char param_1 = (char)param_1__w;
  if (param_1 == '\x01') {
    display_blit_bitmap_1bpp(8,PTR_DAT_0303a4d0[param_2 & 0xffff],0x18,0x48,PTR_LAB_0303a4d4,0xffff)
    ;
  }
  else if (param_1 == '\x02') {
    display_blit_bitmap_1bpp(8,PTR_DAT_0303a4d0[param_2 & 0xffff],0x18,0x48,PTR_LAB_0303a4d8,0xffff)
    ;
  }
  return;
}

