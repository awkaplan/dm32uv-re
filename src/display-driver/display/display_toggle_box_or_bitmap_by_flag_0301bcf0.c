/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_toggle_box_or_bitmap_by_flag @ 0301bcf0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_toggle_box_or_bitmap_by_flag(int param_1__w)

{
  char param_1 = (char)param_1__w;
  if (*(char *)PTR_DAT_0301be34 == '\0') {
    if (param_1 == '\0') {
      display_fill_rect(0x43,0,0x54,0x15,0);
    }
    else {
      display_blit_bitmap_1bpp(0x43,3,0x11,0x36,PTR_LAB_0301be38,0xf800);
    }
  }
  return;
}

