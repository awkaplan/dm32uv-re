/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: crc16_xmodem @ 03001810 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort crc16_xmodem(byte *param_1,short param_2)

{
  ushort uVar1;
  short sVar2;
  byte *pbVar3;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    pbVar3 = param_1 + (ushort)(param_2 - 1) + 1;
    uVar1 = 0;
    do {
      uVar1 = uVar1 ^ (ushort)*param_1 << 8;
      param_1 = param_1 + 1;
      sVar2 = 8;
      do {
        if ((short)uVar1 < 0) {
          uVar1 = uVar1 * 2 ^ 0x1021;
        }
        else {
          uVar1 = uVar1 * 2;
        }
        sVar2 = sVar2 + -1;
      } while (sVar2 != 0);
    } while (param_1 != pbVar3);
  }
  return uVar1;
}

