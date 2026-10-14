/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_controller_byte_xfer @ 0002c09c (IRAM address; the boot stub copies these bytes from program flash 0x030dbcbc)
 * Size: 64 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_controller_byte_xfer(uint param_1,uint param_2,int param_3,ushort param_4)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(iRam0002c0dc + (param_1 & 0xff) * 4);
  *(undefined4 *)(iVar2 + 8) = 1;
  *(int *)(iVar2 + 0x10) = 1 << (param_2 & 0x3f);
  if (param_4 != 0) {
    uVar1 = 0;
    do {
      spi_controller_single_byte_xfer(iVar2,*(undefined1 *)(param_3 + uVar1));
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_4);
  }
  *(int *)(iVar2 + 0x10) = 0;
  return;
}

