/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: lcd_blit_image_from_spi_flash @ 0301802c (file base 0x03000000; code starts at 0x03001000)
 * Size: 240 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void lcd_blit_image_from_spi_flash(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xffff;
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  if ((param_3 & 0xffff) + param_1 < 0xf1) {
    uVar3 = (param_3 & 0xffff) - 1;
  }
  else {
    uVar3 = 0xf0 - param_1;
  }
  if ((param_4 & 0xffff) + param_2 < 0x141) {
    uVar4 = (param_4 & 0xffff) - 1;
  }
  else {
    uVar4 = 0x140 - param_2;
  }
  display_set_window(param_1,param_2,(uVar3 & 0xffff) + param_1 & 0xffff,
                     (uVar4 & 0xffff) + param_2 & 0xffff);
  lcd_ram_write_begin();
  puVar2 = PTR_DAT_03018124;
  iVar8 = *PTR_LAB_03018120;
  if (0xfff < param_5) {
    puVar6 = PTR_DAT_03018124 + 0x400;
    iVar7 = iVar8;
    uVar3 = param_5;
    do {
      spi_flash_read_mutex_guarded(iVar7,puVar2,0x1000);
      puVar5 = puVar2;
      do {
        lcd_write_pixel(*(undefined2 *)puVar5);
        puVar5 = (undefined4 *)((int)puVar5 + 2);
      } while (puVar5 != puVar6);
      uVar3 = uVar3 - 0x1000;
      iVar7 = iVar7 + 0x1000;
    } while (0xfff < uVar3);
    uVar3 = param_5 - 0x1000;
    param_5 = uVar3 & 0xfff;
    iVar8 = iVar8 + 0x1000 + (uVar3 & 0xfffff000);
  }
  if (param_5 != 0) {
    spi_flash_read_mutex_guarded(iVar8,PTR_DAT_03018124,param_5 & 0xffff);
    puVar2 = PTR_DAT_03018124;
    uVar3 = 2;
    do {
      lcd_write_pixel(*(undefined2 *)((int)puVar2 + (uVar3 - 2)));
      bVar1 = uVar3 < param_5;
      uVar3 = uVar3 + 2;
    } while (bVar1);
  }
  os_sem_post(p_ucos_mutex_00039344);
  return;
}

