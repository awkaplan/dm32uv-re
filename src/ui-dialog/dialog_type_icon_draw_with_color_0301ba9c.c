/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_type_icon_draw_with_color @ 0301ba9c (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_type_icon_draw_with_color(void)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  
  iVar2 = keypad_dispatch_not_inhibited();
  if (iVar2 != 0) {
    display_fill_rect(0xcd,0,0xf0,0x1a,0);
    bVar1 = *(byte *)PTR_DAT_0301bb2c;
    puVar3 = PTR_DAT_0301bb38;
    if ((((bVar1 == 4) || (puVar3 = (undefined4 *)PTR_DAT_0301bb3c, bVar1 == 3)) ||
        (puVar3 = (undefined4 *)PTR_DAT_0301bb40, bVar1 == 2)) ||
       ((puVar4 = PTR_DAT_0301bb34, bVar1 != 1 &&
        (puVar4 = PTR_DAT_0301bb30, puVar3 = (undefined4 *)PTR_DAT_0301bb30, 1 < bVar1)))) {
      display_blit_bitmap_1bpp(0xcd,4,0x1c,0x40,puVar3,0xffff);
    }
    else {
      display_blit_bitmap_1bpp(0xcd,4,0x1c,0x40,puVar4,0xf800);
    }
  }
  return;
}

