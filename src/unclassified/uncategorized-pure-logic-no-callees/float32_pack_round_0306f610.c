/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: float32_pack_round @ 0306f610 (file base 0x03000000; code starts at 0x03001000)
 * Size: 220 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint float32_pack_round(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *param_1;
  uVar4 = param_1[3];
  uVar2 = param_1[1];
  if (uVar3 < 2) {
    uVar4 = uVar4 & 0x7fffff | 0x100000;
    uVar3 = 0x7f800000;
    goto LAB_0306f656;
  }
  if (uVar3 != 4) {
    if (uVar3 == 2) {
      return uVar2 << 0x1f;
    }
    if (uVar4 == 0) {
      return uVar2 << 0x1f;
    }
    uVar3 = param_1[2];
    if ((int)uVar3 < -0x7e) {
      uVar3 = -uVar3 - 0x7e;
      if ((int)uVar3 < 0x1a) {
        uVar1 = (uint)(((1 << (uVar3 & 0x3f)) - 1U & uVar4) != 0);
        uVar4 = uVar4 >> (uVar3 & 0x3f);
        uVar3 = uVar4 | uVar1;
        if ((uVar4 & 0x7f | uVar1) != 0x40) goto LAB_0306f6e8;
        if ((uVar4 & 0x80) != 0) {
          uVar3 = uVar3 + 0x40;
        }
      }
      else {
        uVar3 = 0;
LAB_0306f6e8:
        uVar3 = uVar3 + 0x3f;
      }
      uVar4 = uVar3 >> 7 & 0x7fffff;
      uVar3 = (uint)(byte)~(uVar3 < 0x40000000) << 0x17;
      goto LAB_0306f656;
    }
    if ((int)uVar3 < 0x80) {
      uVar1 = uVar3 + 0x7f;
      if ((uVar4 & 0x7f) == 0x40) {
        if ((uVar4 & 0x80) != 0) {
          uVar4 = uVar4 + 0x40;
        }
      }
      else {
        uVar4 = uVar4 + 0x3f;
      }
      if ((int)uVar4 < 0) {
        uVar4 = uVar4 >> 1;
        uVar1 = uVar3 + 0x80;
      }
      uVar4 = uVar4 >> 7 & 0x7fffff;
      uVar3 = (uVar1 & 0xff) << 0x17;
      goto LAB_0306f656;
    }
  }
  uVar3 = 0x7f800000;
  uVar4 = 0;
LAB_0306f656:
  return uVar3 | uVar4 | uVar2 << 0x1f;
}

