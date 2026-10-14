/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03003d5c @ 03003d5c (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

undefined4 FUN_03003d5c(uint param_1,int param_2,int param_3,undefined1 *param_4)

{
  uint uVar1;
  
  if (param_2 == 1) {
    if (param_1 == 6) {
      uRam03000000 = CONCAT31(SUBPIECE(uRam03000000, 1, 3),6);
      uVar1 = uRam03000000;
    }
    else {
      uVar1 = uRam03000000;
      if (param_1 == 4) {
        uRam03000000 = CONCAT31(SUBPIECE(uRam03000000, 1, 3),4);
        uVar1 = uRam03000000;
      }
    }
  }
  else {
    uVar1 = param_1;
    if ((param_1 >> 0x18 != 0x20) && (uVar1 = uRam03000000, param_1 >> 0x18 == 2)) {
      uRam03800000 = param_1;
      if (param_3 != 1) {
        uVar1 = 0;
        do {
          uRam03800000 = CONCAT31(SUBPIECE(uRam03800000, 1, 3),param_4[uVar1]);
          uVar1 = uVar1 + 1;
        } while (uVar1 < param_3 - 1U);
        param_4 = param_4 + param_3 + -1;
      }
      uRam03000000 = CONCAT31(SUBPIECE(uRam03000000, 1, 3),*param_4);
      uVar1 = uRam03000000;
    }
  }
  uRam03000000 = uVar1;
  return 0;
}

