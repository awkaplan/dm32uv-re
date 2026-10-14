/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0300491c @ 0300491c (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0300491c(undefined1 *param_1,undefined1 *param_2,byte param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (param_4 < 0x400) {
    uVar2 = 0x80;
    if (0x80 < param_4) {
      param_4 = 0x80;
    }
    *param_2 = 1;
  }
  else {
    uVar2 = 0x400;
    if (0x400 < param_4) {
      param_4 = 0x400;
    }
    *param_2 = 2;
  }
  param_4 = param_4 & 0xffff;
  param_2[1] = param_3;
  param_2[2] = ~param_3;
  if (3 < param_4 + 3) {
    uVar1 = 3;
    do {
      param_2[uVar1] = *param_1;
      param_1 = param_1 + 1;
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < param_4 + 3);
  }
  if (param_4 <= uVar2) {
    for (param_4 = param_4 + 3; param_4 = param_4 & 0xffff, param_4 < uVar2 + 3;
        param_4 = param_4 + 1) {
      param_2[param_4] = 0x1a;
    }
  }
  return;
}

