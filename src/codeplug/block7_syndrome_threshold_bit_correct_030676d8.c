/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: block7_syndrome_threshold_bit_correct @ 030676d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 206 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void block7_syndrome_threshold_bit_correct(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  pbVar6 = (byte *)(param_1 + 7);
  uVar4 = 0;
  uVar2 = 0;
  iVar7 = 0;
  do {
    bVar1 = *(byte *)(param_1 + iVar7);
    uVar8 = 0xfffffff9;
    do {
      uVar3 = uVar2 * 2 & 0xff;
      uVar2 = uVar3 | (int)(uint)bVar1 >> (uVar8 + 7 & 0x3f) & 1U;
      uVar9 = uVar4 * 2;
      uVar4 = uVar9 & 0xff |
              (uint)(((uVar3 >> 5 ^ uVar3 >> 6 ^ uVar2 ^ uVar3 >> 2 ^
                      (int)(uint)*pbVar6 >> (uVar8 + 7 & 0x3f)) & 1) != 0);
      uVar3 = (uVar9 & 0xff) >> 7;
      if ((uVar9 & 0x20) != 0) {
        uVar3 = uVar3 + 1;
      }
      if ((uVar9 & 4) != 0) {
        uVar3 = uVar3 + 1;
      }
      if ((uVar9 & 2) != 0) {
        uVar3 = uVar3 + 1;
      }
      if (2 < uVar3) {
        iVar5 = iVar7;
        uVar9 = uVar8;
        if ((int)uVar8 < 0) {
          iVar5 = iVar7 + -1;
          uVar9 = uVar8 + 8;
        }
        if (-1 < iVar5) {
          *(byte *)(iVar5 + param_1) = (byte)(1 << (uVar9 & 0x3f)) ^ *(byte *)(iVar5 + param_1);
        }
        uVar4 = uVar4 ^ 0xa6;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 != 1);
    iVar7 = iVar7 + 1;
    pbVar6 = pbVar6 + 1;
  } while (iVar7 != 7);
  return;
}

