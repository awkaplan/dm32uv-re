/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_list_row_draw_with_icon @ 03019ebc (file base 0x03000000; code starts at 0x03001000)
 * Size: 264 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_list_row_draw_with_icon(uint param_1,byte *param_2,char param_3,char param_4)

{
  byte bVar1;
  ushort color;
  ushort fg;
  
  bVar1 = PTR_LAB_0301a080[(param_1 & 0xffff) + 8];
  if (param_3 == '\x01') {
    color = 0xc618;
    fg = 0;
  }
  else {
    color = 0;
    fg = 0xffff;
  }
  display_fill_rect(5,(ushort)(byte)PTR_LAB_0301a080[param_1 & 0xffff],0xe1,bVar1 + 0x1a,color);
  if (*(char *)PTR_DAT_0301a084 == '\x01') {
    if (param_4 == '\x01') {
      if (param_3 == '\x01') {
        display_blit_image(8,bVar1,0x18,0x17,PTR_DAT_0301a088);
      }
      else {
        display_blit_image(8,bVar1,0x18,0x17,PTR_LAB_0301a08c);
      }
    }
    else if (param_3 == '\x01') {
      display_blit_image(8,bVar1,0x18,0x17,PTR_DAT_0301a090);
    }
    else {
      display_blit_image(8,bVar1,0x18,0x17,PTR_LAB_0301a094);
    }
  }
  else if (*(char *)PTR_DAT_0301a084 == '\x03') {
    if (param_3 == '\x01') {
      display_blit_image(8,bVar1,0x18,0x17,PTR_DAT_0301a098);
    }
    else {
      display_blit_image(8,bVar1,0x18,0x17,PTR_LAB_0301a09c);
    }
  }
  else if (param_3 == '\x01') {
    display_blit_image(8,bVar1,0x18,0x17,PTR_DAT_0301a0a0);
  }
  else {
    display_blit_image(8,bVar1,0x18,0x17,PTR_LAB_0301a0a4);
  }
  display_draw_string_gb2312((ushort)bVar1,0x28,param_2,fg,color);
  return;
}

