/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0305f620 @ 0305f620 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0305f620(int param_1,uint param_2)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  
  uVar1 = 0;
  while( true ) {
    uVar3 = uVar1 & 0xff;
    if ((uVar1 & 1) == 0) {
      pbVar2 = (byte *)(param_1 + (uVar3 >> 1));
      *pbVar2 = *pbVar2 & 0xf0;
    }
    else {
      pbVar2 = (byte *)(param_1 + (uVar3 >> 1));
      *pbVar2 = *pbVar2 & 0xf;
    }
    pbVar2 = (byte *)((uVar3 >> 1) + param_1);
    *pbVar2 = (byte)(param_2 % 10 << ((uVar1 & 1) << 2)) | *pbVar2;
    uVar1 = uVar1 + 1;
    if (uVar1 == 8) break;
    param_2 = param_2 / 10;
  }
  return;
}

