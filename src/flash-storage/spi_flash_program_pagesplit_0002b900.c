/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_flash_program_pagesplit @ 0002b900 (IRAM address; the boot stub copies these bytes from program flash 0x030db520)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_program_pagesplit(int param_1__w,uint param_2,int param_3,uint param_4)

{
  undefined2 param_1 = (undefined2)param_1__w;
  uint uVar1;
  
  param_4 = param_4 & 0xffff;
  if ((param_2 & 0xf00) + 0x100 < param_4 + (param_2 & 0xfff)) {
    uVar1 = ((param_2 & 0xf00) - (param_2 & 0xfff)) + 0x100 & 0xffff;
    spi_flash_shadow_addr_set(param_1);
    spi_flash_page_program_raw(param_3,uVar1);
    spi_flash_shadow_addr_set(param_1,(param_2 & 0xf00) + 0x100);
    spi_flash_page_program_raw(param_3 + uVar1,param_4 - uVar1 & 0xffff);
  }
  else {
    spi_flash_shadow_addr_set(param_1);
    spi_flash_page_program_raw(param_3,param_4);
  }
  return;
}

