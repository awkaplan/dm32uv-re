/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_icon_with_index_label_draw @ 03039db4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_icon_with_index_label_draw(uint param_1,int param_2__w,int param_3__w)

{
  char param_2 = (char)param_2__w;
  undefined2 param_3 = (undefined2)param_3__w;
  uint uVar1;
  byte bVar2;
  char local_18;
  char cStack_17;
  undefined1 uStack_16;
  
  uVar1 = (uint)(byte)PTR_DAT_03039e34[(param_1 & 0xff) - 1];
  display_blit_bitmap_1bpp(8,uVar1,0x18,0x48,PTR_DAT_03039e38,param_3);
  bVar2 = param_2 + 1;
  if (bVar2 < 10) {
    local_18 = param_2 + '1';
    cStack_17 = 0;
    display_draw_string_mixed_ascii_gb2312(uVar1 + 5,0x10,&local_18,param_3);
  }
  else {
    local_18 = bVar2 / 10 + 0x30;
    cStack_17 = bVar2 % 10 + 0x30;
    uStack_16 = 0;
    display_draw_string_mixed_ascii_gb2312(uVar1 + 5,0xc,&local_18,param_3);
  }
  return;
}

