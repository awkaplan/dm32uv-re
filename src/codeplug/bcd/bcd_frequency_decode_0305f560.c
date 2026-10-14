/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bcd_frequency_decode @ 0305f560 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int bcd_frequency_decode(int param_1,uint param_2)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    pbVar2 = (byte *)(param_1 + (param_2 - 1));
    uVar3 = 0;
    iVar1 = 0;
    do {
      iVar1 = (iVar1 * 10 + (uint)(*pbVar2 >> 4)) * 10 + (*pbVar2 & 0xf);
      uVar3 = uVar3 + 1 & 0xff;
      pbVar2 = pbVar2 + -1;
    } while (uVar3 < param_2);
  }
  return iVar1;
}

