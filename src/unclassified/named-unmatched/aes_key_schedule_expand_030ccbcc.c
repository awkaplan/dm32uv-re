/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aes_key_schedule_expand @ 030ccbcc (file base 0x03000000; code starts at 0x03001000)
 * Size: 196 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void aes_key_schedule_expand(int param_1,int param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  param_3 = param_3 & 0xff;
  if (param_3 != 0) {
    pbVar1 = (byte *)(param_1 + 1);
    iVar2 = 0;
    do {
      *(uint *)(param_2 + iVar2) =
           (uint)*pbVar1 * 0x10000 + (uint)*(byte *)(param_1 + iVar2) * 0x1000000 + (uint)pbVar1[2]
           + (uint)pbVar1[1] * 0x100;
      iVar2 = iVar2 + 4;
      pbVar1 = pbVar1 + 4;
    } while (iVar2 != ((param_3 - 1 & 0xff) + 1) * 4);
  }
  iVar2 = _DAT_030ccc90;
  uVar5 = param_3;
  do {
    while( true ) {
      if ((((param_4 & 0xff) + 1) * 4 & 0xff) <= uVar5) {
        return;
      }
      uVar4 = *(uint *)(param_2 + (uVar5 - 1) * 4);
      uVar3 = uVar5 - (uVar5 / param_3) * param_3 & 0xff;
      if (uVar3 != 0) break;
      uVar4 = aes_subword_sbox_substitute((uVar4 >> 0x18) + uVar4 * 0x100);
      uVar4 = *(uint *)(iVar2 + (uVar5 / param_3) * 4 + 0x1fc) ^ uVar4;
LAB_030ccc3a:
      *(uint *)(param_2 + uVar5 * 4) = uVar4 ^ *(uint *)(param_2 + (uVar5 - param_3) * 4);
      uVar5 = uVar5 + 1 & 0xff;
    }
    if ((param_3 < 7) || (uVar3 != 4)) goto LAB_030ccc3a;
    uVar4 = aes_subword_sbox_substitute(uVar4);
    *(uint *)(param_2 + uVar5 * 4) = uVar4 ^ *(uint *)(param_2 + (uVar5 - param_3) * 4);
    uVar5 = uVar5 + 1 & 0xff;
  } while( true );
}

