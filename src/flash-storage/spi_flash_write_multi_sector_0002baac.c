/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_flash_write_multi_sector @ 0002baac (IRAM address; the boot stub copies these bytes from program flash 0x030db6cc)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 spi_flash_write_multi_sector(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  func_0x0300c500(uRam0002bb14,0);
  uVar2 = param_1 >> 0xc;
  uVar1 = 0x1000 - (param_1 & 0xfff) & 0xffff;
  if (param_3 <= uVar1) {
    uVar1 = param_3 & 0xffff;
  }
  while (spi_flash_write_chunk_pagesplit(param_2,param_1,uVar1), uVar1 != param_3) {
    uVar2 = uVar2 + 1;
    spi_flash_sector_erase(uVar2 & 0xffff);
    param_2 = param_2 + uVar1;
    param_1 = param_1 + uVar1;
    param_3 = param_3 - uVar1;
    uVar1 = 0x1000;
    if (param_3 < 0x1001) {
      uVar1 = param_3 & 0xffff;
    }
  }
  func_0x0300c53c(uRam0002bb14);
  return 1;
}

