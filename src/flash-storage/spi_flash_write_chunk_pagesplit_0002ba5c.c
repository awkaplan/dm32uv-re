/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_flash_write_chunk_pagesplit @ 0002ba5c (IRAM address; the boot stub copies these bytes from program flash 0x030db67c)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_write_chunk_pagesplit(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  param_3 = param_3 & 0xffff;
  uVar1 = 0x100 - (param_2 & 0xff);
  if (param_3 < (uVar1 & 0xffff)) {
    uVar1 = param_3;
  }
  uVar1 = uVar1 & 0xffff;
  while (spi_flash_program_pagesplit(param_2 >> 0xc & 0xffff,param_2 & 0xfff,param_1,uVar1),
        param_3 != uVar1) {
    param_1 = param_1 + uVar1;
    param_2 = param_2 + uVar1;
    param_3 = param_3 - uVar1 & 0xffff;
    uVar1 = param_3;
    if (0x100 < param_3) {
      uVar1 = 0x100;
    }
  }
  return;
}

