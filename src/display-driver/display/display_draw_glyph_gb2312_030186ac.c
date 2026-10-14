/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_glyph_gb2312 @ 030186ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_draw_glyph_gb2312
               (short param_1,short param_2,byte *param_3,undefined2 param_4,undefined2 param_5)

{
  char cVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte local_2c [8];
  
  local_2c[0] = 0x80;
  local_2c[1] = 0x40;
  local_2c[2] = 0x20;
  local_2c[3] = 0x10;
  local_2c[4] = 8;
  local_2c[5] = 4;
  local_2c[6] = 2;
  local_2c[7] = 1;
  display_set_window(param_2,param_1,param_2 + 0x17,param_1 + 0x17);
  lcd_ram_write_begin();
  cVar1 = '\0';
  do {
    pbVar4 = local_2c;
    pbVar3 = param_3;
    cVar2 = '\x18';
    do {
      if ((*pbVar3 & *pbVar4) == 0) {
        lcd_write_pixel(param_5);
      }
      else {
        lcd_write_pixel(param_4);
      }
      cVar2 = cVar2 + -1;
      pbVar3 = pbVar3 + 3;
    } while ((cVar2 != '\0') ||
            (pbVar4 = pbVar4 + 1, pbVar3 = param_3, cVar2 = '\x18', pbVar4 != &stack0xffffffdc));
    cVar1 = cVar1 + '\x01';
    param_3 = param_3 + 1;
  } while (cVar1 != '\x03');
  return;
}

