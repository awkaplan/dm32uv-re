/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: float32_unpack @ 0306f6ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 162 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void float32_unpack(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *param_1;
  uVar2 = uVar1 >> 0x17 & 0xff;
  param_2[1] = uVar1 >> 0x1f;
  uVar3 = uVar1 & 0x7fffff;
  if (uVar2 == 0) {
    if (uVar3 == 0) {
      *param_2 = 2;
      return;
    }
    uVar3 = uVar3 << 7;
    param_2[2] = 0xffffff82;
    *param_2 = 3;
    if (uVar3 < 0x40000000) {
      uVar1 = 0xffffff81;
      do {
        uVar2 = uVar1;
        uVar3 = uVar3 * 2;
        uVar1 = uVar2 - 1;
      } while (uVar3 < 0x40000000);
      param_2[2] = uVar2;
    }
    param_2[3] = uVar3;
  }
  else {
    if (uVar2 != 0xff) {
      param_2[2] = uVar2 - 0x7f;
      *param_2 = 3;
      param_2[3] = uVar3 << 7 | 0x40000000;
      return;
    }
    if (uVar3 == 0) {
      *param_2 = 4;
      return;
    }
    *param_2 = (uint)((uVar1 & 0x100000) != 0);
    param_2[3] = uVar3;
  }
  return;
}

