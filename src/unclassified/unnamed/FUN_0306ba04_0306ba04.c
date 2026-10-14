/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0306ba04 @ 0306ba04 (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

int FUN_0306ba04(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x3c);
  iVar2 = uVar1 - param_3 * (uVar1 / param_3);
  if (iVar2 == 0) {
    param_3 = 0;
  }
  else {
    param_3 = param_3 - iVar2;
  }
  uVar3 = param_3 + param_2;
  if (*(uint *)(param_1 + 0x44) < uVar3) {
    iVar2 = 0;
  }
  else if (uVar3 < param_3) {
    iVar2 = 0;
  }
  else if (uVar3 < param_2) {
    iVar2 = 0;
  }
  else if (uVar1 + uVar3 < uVar1) {
    iVar2 = 0;
  }
  else {
    *(uint *)(param_1 + 0x3c) = uVar1 + uVar3;
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) - uVar3;
    iVar2 = uVar1 + param_3;
  }
  return iVar2;
}

