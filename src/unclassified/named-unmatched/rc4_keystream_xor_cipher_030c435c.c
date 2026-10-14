/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rc4_keystream_xor_cipher @ 030c435c (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rc4_keystream_xor_cipher(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = 0;
  uVar6 = 0;
  uVar5 = 0;
  do {
    uVar5 = uVar5 + 1 & 0xff;
    bVar1 = *(byte *)(param_1 + uVar5);
    uVar6 = uVar6 + bVar1 & 0xff;
    *(byte *)(param_1 + uVar5) = *(byte *)(param_1 + uVar6);
    iVar2 = iVar2 + 1;
    *(byte *)(param_1 + uVar6) = bVar1;
  } while (iVar2 != 0x100);
  if (param_3 != 0) {
    uVar3 = 0;
    do {
      uVar5 = uVar5 + 1 & 0xff;
      pbVar4 = (byte *)(param_1 + uVar5);
      bVar1 = *pbVar4;
      uVar6 = uVar6 + bVar1 & 0xff;
      *pbVar4 = *(byte *)(param_1 + uVar6);
      *(byte *)(param_1 + uVar6) = bVar1;
      *(byte *)(param_2 + uVar3) =
           *(byte *)(param_1 + ((uint)bVar1 + (uint)*pbVar4 & 0xff)) ^ *(byte *)(param_2 + uVar3);
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_3);
  }
  return;
}

