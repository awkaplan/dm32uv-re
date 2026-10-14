/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_blit_mono_bitmap_rows @ 0301847c (file base 0x03000000; code starts at 0x03001000)
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

void display_blit_mono_bitmap_rows
               (short param_1,uint param_2,uint param_3,ushort param_4,ushort *param_5,
               undefined2 param_6,undefined2 param_7)

{
  uint uVar1;
  ushort uVar2;
  
  param_3 = param_3 & 0xffff;
  display_set_window(param_2 & 0xffff,param_1,param_3 + ((param_2 & 0xffff) - 1) & 0xffff,
                     param_4 + param_1 + -1);
  lcd_ram_write_begin();
  if (param_4 != 0) {
    uVar2 = 0;
    do {
      if (param_3 != 0) {
        uVar1 = 0;
        do {
          if (((((0x80 << ((param_3 / 0xc & 7) << 3)) >> (uVar1 & 0x3f) & (uint)*param_5) == 0) &&
              (param_3 < 0xd)) ||
             ((((int)(uint)*param_5 >> (uVar1 & 0x3f) & 1U) == 0 && (0xc < param_3)))) {
            lcd_write_pixel(param_6);
          }
          else {
            lcd_write_pixel(param_7);
          }
          uVar1 = uVar1 + 1;
        } while ((uVar1 & 0xffff) < param_3);
      }
      uVar2 = uVar2 + 1;
      param_5 = param_5 + 1;
    } while (uVar2 < param_4);
  }
  return;
}

