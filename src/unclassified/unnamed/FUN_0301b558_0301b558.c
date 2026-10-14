/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0301b558 @ 0301b558 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0301b558(uint param_1,undefined1 *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  
  uVar1 = PTR_DAT_0301b5a0[4];
  if (param_1 < uVar1) {
    uVar1 = PTR_DAT_0301b5a0[6];
    uVar2 = PTR_DAT_0301b5a0[7];
  }
  else {
    uVar2 = PTR_DAT_0301b5a0[5];
  }
  uVar4 = uVar2 - uVar1 >> 1;
  *param_3 = uVar4;
  if (param_1 == uVar2) {
    uVar3 = 1;
  }
  else {
    uVar3 = (undefined1)((param_1 - uVar1) / uVar4);
  }
  *param_2 = uVar3;
  return;
}

