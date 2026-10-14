/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c4310 @ 030c4310 (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c4310(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  
  if (param_3 != 0) {
    uVar2 = 0;
    uVar4 = 0;
    uVar3 = 0;
    do {
      uVar3 = uVar3 + 1 & 0xff;
      pbVar5 = (byte *)(param_1 + uVar3);
      bVar1 = *pbVar5;
      uVar4 = uVar4 + bVar1 & 0xff;
      *pbVar5 = *(byte *)(param_1 + uVar4);
      *(byte *)(param_1 + uVar4) = bVar1;
      *(byte *)(param_2 + uVar2) =
           *(byte *)(param_1 + ((uint)bVar1 + (uint)*pbVar5 & 0xff)) ^ *(byte *)(param_2 + uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_3);
  }
  return;
}

