/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: lcd_rect_bitmap_blit @ 03038ee0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 164 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void lcd_rect_bitmap_blit(uint param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xffff;
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  uVar1 = (param_2 - 1) * 0x17 + 0x2b & 0xffff;
  if ((param_3 & 0xffff) + param_1 < 0xf1) {
    uVar3 = (param_3 & 0xffff) - 1;
  }
  else {
    uVar3 = 0xf0 - param_1;
  }
  if ((param_4 & 0xffff) + param_2 < 0x141) {
    param_2 = (param_4 & 0xffff) - 1;
  }
  else {
    param_2 = 0x140 - param_2;
  }
  display_set_window(param_1,uVar1,(uVar3 & 0xffff) + param_1 & 0xffff,
                     (param_2 & 0xffff) + uVar1 & 0xffff);
  lcd_ram_write_begin();
  uVar1 = (uVar3 & 0xffff) * 2;
  uVar3 = 0;
  while( true ) {
    uVar2 = 0;
    if (-1 < (int)uVar1) {
      uVar2 = 0;
      do {
        lcd_write_pixel(CONCAT11(*(undefined1 *)(param_5 + uVar2 + 1),
                                 *(undefined1 *)(param_5 + uVar2)));
        uVar2 = uVar2 + 2 & 0xffff;
      } while (uVar2 <= uVar1);
    }
    uVar3 = uVar3 + 1 & 0xffff;
    if ((param_2 & 0xffff) < uVar3) break;
    param_5 = param_5 + uVar2;
  }
  os_sem_post(p_ucos_mutex_00039344);
  return;
}

