/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_hex_digits_6_with_separator @ 0302f8b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_hex_digits_6_with_separator(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  char cVar4;
  
  display_fill_rect(0x4a,0x7e,0xaa,0x9e,0x7e0);
  bVar1 = *(byte *)(param_1 + 3);
  uVar3 = 5;
  cVar4 = 'N';
  do {
    if ((bVar1 & 0xf) < 10) {
      cVar2 = (bVar1 & 0xf) + 0x30;
    }
    else {
      cVar2 = '-';
    }
    display_draw_glyph_ascii(cVar4,0x82,cVar2,0x18,0,0x7e0);
    cVar2 = cVar4 + '\f';
    if (uVar3 == 3) {
      display_draw_glyph_ascii(cVar2,0x82,0x2d,0x18,0,0x7e0);
      cVar2 = cVar4 + '\x18';
    }
    else if (uVar3 == 0) {
      return;
    }
    bVar1 = *(byte *)(param_1 + (uVar3 >> 1));
    if ((uVar3 & 1) != 0) {
      bVar1 = bVar1 >> 4;
    }
    uVar3 = uVar3 - 1 & 0xff;
    cVar4 = cVar2;
  } while( true );
}

