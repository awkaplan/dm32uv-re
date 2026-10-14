/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_controller_byte_xfer_rdwr @ 0002bfc4 (IRAM address; the boot stub copies these bytes from program flash 0x030dbbe4)
 * Size: 100 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_controller_byte_xfer_rdwr
               (uint param_1,uint param_2,int param_3,uint param_4,int param_5,ushort param_6)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(iRam0002c0dc + (param_1 & 0xff) * 4);
  *(undefined4 *)(iVar3 + 8) = 1;
  *(int *)(iVar3 + 0x10) = 1 << (param_2 & 0x3f);
  if (param_6 != 0) {
    uVar2 = 0;
    do {
      spi_controller_single_byte_xfer(iVar3,*(undefined1 *)(param_5 + uVar2));
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_6);
  }
  if ((param_4 & 0xffff) != 0) {
    uVar2 = 0;
    do {
      uVar1 = spi_controller_single_byte_xfer(iVar3,0xff);
      *(undefined1 *)(param_3 + uVar2) = uVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < (param_4 & 0xffff));
  }
  *(int *)(iVar3 + 0x10) = 0;
  return;
}

