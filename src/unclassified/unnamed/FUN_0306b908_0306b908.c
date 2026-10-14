/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0306b908 @ 0306b908 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

byte FUN_0306b908(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = *(uint *)(param_1 + 0x18);
  if (param_2 < uVar4) {
    bVar1 = 0;
  }
  else if (*(uint *)(param_1 + 0x1c) < param_2) {
    bVar1 = 0;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x34);
    iVar5 = uVar4 - uVar3 * (uVar4 / uVar3);
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = uVar3 - iVar5;
    }
    uVar2 = *(uint *)(param_1 + 0x30);
    iVar6 = uVar2 - uVar3 * (uVar2 / uVar3);
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = uVar3 - iVar6;
    }
    param_2 = param_2 - (uVar4 + iVar5);
    bVar1 = ~((param_2 / (iVar6 + uVar2)) * (iVar6 + uVar2) != param_2);
  }
  return bVar1;
}

