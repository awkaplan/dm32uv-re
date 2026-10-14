/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gf256_multiply_aes @ 030cc9dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint gf256_multiply_aes(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1;
  if ((param_1 != 0) && (uVar1 = param_2, param_2 != 0)) {
    uVar5 = param_2;
    if (param_2 <= param_1) {
      uVar5 = param_1;
      param_1 = param_2;
    }
    uVar1 = 0;
    if ((param_1 & 1) != 0) {
      uVar1 = uVar5;
    }
    if ((int)param_1 >> 7 == 0) {
      uVar2 = 7;
      do {
        uVar3 = uVar2 - 1;
        uVar2 = uVar3 & 0xff;
      } while ((int)param_1 >> (uVar3 & 0x3f) == 0);
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    else {
      uVar2 = 7;
    }
    uVar3 = 1;
    do {
      uVar4 = uVar5 * 2;
      if ((char)uVar5 < '\0') {
        uVar4 = uVar4 ^ 0x1b;
      }
      uVar5 = uVar4 & 0xff;
      uVar4 = uVar3 & 0x3f;
      uVar3 = uVar3 + 1 & 0xff;
      if (((int)param_1 >> uVar4 & 1U) != 0) {
        uVar1 = (uVar5 ^ uVar1) & 0xff;
      }
    } while (uVar3 <= uVar2);
  }
  return uVar1;
}

