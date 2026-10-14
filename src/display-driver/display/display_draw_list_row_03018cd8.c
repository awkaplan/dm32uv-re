/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_list_row @ 03018cd8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_draw_list_row(uint param_1,byte *param_2,char param_3)

{
  byte bVar1;
  ushort y;
  ushort color;
  ushort fg;
  
  bVar1 = PTR_LAB_03018dd4[(param_1 & 0xffff) + 7];
  if (param_3 == '\x01') {
    color = 0xc618;
    fg = 0;
  }
  else {
    color = 0;
    fg = 0xffff;
  }
  display_fill_rect(5,(ushort)(byte)PTR_LAB_03018dd4[(param_1 & 0xffff) - 1],0xe5,bVar1 + 0x1a,color
                   );
  if (*(char *)PTR_active_screen_subtype_03018dd8 == '\x13') {
    y = 8;
  }
  else if (*(char *)PTR_active_screen_subtype_03018dd8 == '\"') {
    y = 8;
  }
  else {
    y = 0x28;
  }
  display_draw_string_gb2312((ushort)bVar1,y,param_2,fg,color);
  return;
}

