/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_blit_glyph_6x8 @ 03018278 (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_blit_glyph_6x8
               (short param_1,short param_2,int param_3,undefined2 param_4,undefined2 param_5)

{
  int iVar1;
  uint uVar2;
  
  display_set_window(param_2,param_1,param_2 + 5,param_1 + 7);
  lcd_ram_write_begin();
  uVar2 = 0;
  do {
    iVar1 = 0;
    do {
      if (((uint)*(byte *)(param_3 + iVar1) & 1 << (uVar2 & 0x3f)) == 0) {
        lcd_write_pixel(param_5);
      }
      else {
        lcd_write_pixel(param_4);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != 6);
    uVar2 = uVar2 + 1;
  } while (uVar2 != 8);
  return;
}

