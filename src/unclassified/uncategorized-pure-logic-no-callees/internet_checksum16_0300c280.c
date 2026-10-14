/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: internet_checksum16 @ 0300c280 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint internet_checksum16(byte *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    do {
      pbVar2 = param_1 + 1;
      bVar1 = *param_1;
      param_1 = param_1 + 2;
      uVar3 = (uint)*pbVar2 * 0x100 + (uint)bVar1 + uVar3;
      uVar3 = (uVar3 & 0xffff) + (uVar3 >> 0x10);
      uVar3 = uVar3 + (uVar3 >> 0x10);
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return ~uVar3 & 0xffff;
}

