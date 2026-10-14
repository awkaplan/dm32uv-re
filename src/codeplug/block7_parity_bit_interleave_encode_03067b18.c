/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: block7_parity_bit_interleave_encode @ 03067b18 (file base 0x03000000; code starts at 0x03001000)
 * Size: 200 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte * block7_parity_bit_interleave_encode(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  byte local_88 [112];
  
  uVar5 = 0;
  pbVar7 = param_1;
  do {
    uVar2 = 0;
    uVar3 = 0;
    do {
      uVar6 = uVar5 * 2 & 0xff;
      uVar5 = uVar6 | (int)(uint)*pbVar7 >> (uVar3 & 0x3f) & 1U;
      uVar2 = uVar2 | ((uVar6 >> 6 ^ uVar6 >> 5 ^ uVar6 >> 2 ^ uVar5) & 1) << (uVar3 & 0x3f) & 0xff;
      uVar3 = uVar3 + 1;
    } while (uVar3 != 8);
    pbVar7[7] = (byte)uVar2;
    pbVar7 = pbVar7 + 1;
  } while (pbVar7 != param_1 + 7);
  uVar5 = 0;
  pbVar7 = param_1;
  do {
    bVar1 = *pbVar7;
    uVar3 = 0;
    uVar2 = uVar5;
    do {
      local_88[uVar2] = (byte)((int)(uint)bVar1 >> (uVar3 & 0x3f)) & 1;
      uVar5 = uVar2 + 0x10;
      if (0x6f < uVar5) {
        uVar5 = uVar2 - 0x5f;
      }
      uVar3 = uVar3 + 1;
      uVar2 = uVar5;
    } while (uVar3 != 8);
    pbVar7 = pbVar7 + 1;
  } while (pbVar7 != param_1 + 0xe);
  iVar8 = 0;
  pbVar7 = param_1;
  do {
    pbVar4 = local_88 + iVar8;
    uVar5 = 7;
    uVar2 = 0;
    do {
      if (*pbVar4 != 0) {
        uVar2 = uVar2 | 1 << (uVar5 & 0x3f) & 0xffU;
      }
      uVar5 = uVar5 - 1;
      pbVar4 = pbVar4 + 1;
    } while (uVar5 != 0xffffffff);
    iVar8 = iVar8 + 8;
    *pbVar7 = (byte)uVar2;
    pbVar7 = pbVar7 + 1;
  } while (iVar8 != 0x70);
  return param_1 + 0xe;
}

