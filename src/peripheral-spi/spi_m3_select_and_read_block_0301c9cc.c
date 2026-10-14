/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_m3_select_and_read_block @ 0301c9cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-spi
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_m3_select_and_read_block(undefined4 param_1,int param_2,uint param_3)

{
  dword dVar1;
  undefined1 uVar2;
  uint uVar3;
  
  dVar1 = SSI_Type_14150000.SER;
  SSI_Type_14150000.SER = dVar1 | 1;
  if ((param_3 & 0xff) != 0) {
    uVar3 = 0;
    do {
      uVar2 = spi_drv_txrx(param_1,0xff);
      *(undefined1 *)(param_2 + uVar3) = uVar2;
      uVar3 = uVar3 + 1;
    } while ((uVar3 & 0xff) < (param_3 & 0xff));
  }
  dVar1 = SSI_Type_14150000.SER;
  SSI_Type_14150000.SER = dVar1 & 0xfffffffe;
  return;
}

