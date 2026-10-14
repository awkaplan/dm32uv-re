/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_write_split_across_page_boundary @ 03010848 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_write_split_across_page_boundary(int param_1__w,uint param_2,int param_3,uint param_4)

{
  undefined2 param_1 = (undefined2)param_1__w;
  uint uVar1;
  uint uVar2;
  
  param_4 = param_4 & 0xff;
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar1 = param_2 & 0xfff;
  if ((param_2 & 0xf00) + 0x100 < param_4 + uVar1) {
    uVar2 = ((param_2 & 0xf00) - uVar1) + 0x100 & 0xffff;
    spi_flash_program_pagesplit(param_1,uVar1,param_3,uVar2);
    spi_flash_program_pagesplit
              (param_1,(param_2 & 0xf00) + 0x100,param_3 + uVar2,param_4 - uVar2 & 0xffff);
  }
  else {
    spi_flash_program_pagesplit(param_1,uVar1,param_3,param_4);
  }
  os_sem_post(p_ucos_mutex_0003944c);
  return;
}

