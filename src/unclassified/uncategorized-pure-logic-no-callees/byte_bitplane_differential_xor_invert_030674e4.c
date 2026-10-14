/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: byte_bitplane_differential_xor_invert @ 030674e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void byte_bitplane_differential_xor_invert(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_2 != 0) {
    uVar3 = 0;
    uVar2 = 0;
    do {
      uVar5 = 0;
      uVar1 = 7;
      uVar4 = uVar3;
      do {
        uVar3 = (int)(uint)*(byte *)(param_1 + uVar2) >> (uVar1 & 0x3f) & 1;
        if (uVar3 != uVar4) {
          uVar5 = uVar5 | 1 << (uVar1 & 0x3f) & 0xffU;
        }
        uVar1 = uVar1 - 1;
        uVar4 = uVar3;
      } while (uVar1 != 0xffffffff);
      *(byte *)(param_1 + uVar2) = ~(byte)uVar5;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return;
}

