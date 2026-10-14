/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_blit_rect_from_buffer @ 03017f9c (file base 0x03000000; code starts at 0x03001000)
 * Size: 142 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_blit_rect_from_buffer(uint param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xffff;
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  if ((param_3 & 0xffff) + param_1 < 0xf1) {
    uVar2 = (param_3 & 0xffff) - 1;
  }
  else {
    uVar2 = 0xf0 - param_1;
  }
  if ((param_4 & 0xffff) + param_2 < 0x141) {
    uVar4 = (param_4 & 0xffff) - 1;
  }
  else {
    uVar4 = 0x140 - param_2;
  }
  uVar4 = uVar4 & 0xffff;
  display_set_window(param_1,param_2,(uVar2 & 0xffff) + param_1 & 0xffff,uVar4 + param_2 & 0xffff);
  lcd_ram_write_begin();
  if (uVar4 != 0) {
    uVar3 = 0;
    uVar1 = 0;
    while( true ) {
      do {
        lcd_write_pixel(*(undefined2 *)(param_5 + uVar1 * 2));
        uVar1 = uVar1 + 1 & 0xffff;
      } while (uVar1 <= (uVar2 & 0xffff));
      uVar3 = uVar3 + 1 & 0xffff;
      if (uVar4 <= uVar3) break;
      param_5 = param_5 + uVar1 * 2;
      uVar1 = 0;
    }
  }
  os_sem_post(p_ucos_mutex_00039344);
  return;
}

