/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_blit_bitmap_16x16_1bpp @ 03018604 (file base 0x03000000; code starts at 0x03001000)
 * Size: 168 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_blit_bitmap_16x16_1bpp
               (short param_1,short param_2,int param_3,undefined2 param_4,undefined2 param_5)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  
  display_set_window(param_2,param_1,param_2 + 0xf,param_1 + 0xf);
  lcd_ram_write_begin();
  uVar4 = 0;
  do {
    iVar2 = 0;
    do {
      if (((uint)*(byte *)(param_3 + iVar2) & 1 << (uVar4 & 0x3f)) == 0) {
        lcd_write_pixel(param_5);
      }
      else {
        lcd_write_pixel(param_4);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x10);
    uVar4 = uVar4 + 1;
  } while (uVar4 != 8);
  uVar4 = 0;
  do {
    pbVar3 = (byte *)(param_3 + 0x10);
    cVar1 = '\x10';
    do {
      if (((uint)*pbVar3 & 1 << (uVar4 & 0x3f)) == 0) {
        lcd_write_pixel(param_5);
      }
      else {
        lcd_write_pixel(param_4);
      }
      cVar1 = cVar1 + -1;
      pbVar3 = pbVar3 + 1;
    } while (cVar1 != '\0');
    uVar4 = uVar4 + 1;
  } while (uVar4 != 8);
  return;
}

