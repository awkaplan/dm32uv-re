/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_blit_bitmap_1bpp_rows @ 03019904 (file base 0x03000000; code starts at 0x03001000)
 * Size: 274 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_blit_bitmap_1bpp_rows(int param_1__w,uint param_2,int param_3,uint param_4)

{
  short param_1 = (short)param_1__w;
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  
  param_4 = param_4 & 0xff;
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  display_set_window(param_2 & 0xffff,param_1,param_4 + ((param_2 & 0xffff) - 1) & 0xffff,
                     param_1 + 0x17);
  lcd_ram_write_begin();
  uVar3 = 0;
  do {
    if (param_4 != 0) {
      uVar1 = 0;
      do {
        if (((uint)*(byte *)(param_3 + uVar1) & 1 << (uVar3 & 0x3f)) == 0) {
          lcd_write_pixel(0);
        }
        else {
          lcd_write_pixel(0xffff);
        }
        uVar1 = uVar1 + 1;
      } while ((uVar1 & 0xff) < param_4);
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 8);
  uVar3 = 0;
  do {
    if (param_4 != 0) {
      uVar1 = 0;
      pbVar2 = (byte *)(param_3 + param_4);
      do {
        if (((uint)*pbVar2 & 1 << (uVar3 & 0x3f)) == 0) {
          lcd_write_pixel(0);
        }
        else {
          lcd_write_pixel(0xffff);
        }
        uVar1 = uVar1 + 1 & 0xff;
        pbVar2 = pbVar2 + 1;
      } while (uVar1 < param_4);
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 8);
  uVar3 = 0;
  do {
    if (param_4 != 0) {
      uVar1 = 0;
      pbVar2 = (byte *)(param_3 + param_4);
      do {
        if (((uint)*pbVar2 & 1 << (uVar3 & 0x3f)) == 0) {
          lcd_write_pixel(0);
        }
        else {
          lcd_write_pixel(0xffff);
        }
        uVar1 = uVar1 + 1 & 0xff;
        pbVar2 = pbVar2 + 1;
      } while (uVar1 < param_4);
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 8);
  os_sem_post(p_ucos_mutex_00039344);
  return;
}

