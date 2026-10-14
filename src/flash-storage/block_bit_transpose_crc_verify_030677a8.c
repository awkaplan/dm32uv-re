/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: block_bit_transpose_crc_verify @ 030677a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 176 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte block_bit_transpose_crc_verify(undefined1 *param_1)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  byte local_8c [112];
  
  iVar7 = 0;
  iVar6 = 0;
  do {
    uVar1 = 7 - iVar7;
    pbVar2 = local_8c + iVar6;
    iVar3 = 0;
    do {
      *pbVar2 = (byte)((int)(uint)(byte)param_1[(uint)(iVar3 + iVar7) >> 3] >> (uVar1 & 7)) & 1;
      iVar3 = iVar3 + 0x10;
      uVar1 = uVar1 - 0x10;
      pbVar2 = pbVar2 + 1;
    } while (iVar3 != 0x70);
    iVar6 = iVar6 + 7;
    iVar7 = iVar7 + 1;
  } while (iVar6 != 0x70);
  iVar6 = 0;
  puVar5 = param_1;
  do {
    pbVar2 = local_8c + iVar6;
    uVar1 = 0;
    uVar4 = 0;
    do {
      if (*pbVar2 != 0) {
        uVar1 = uVar1 | 1 << (uVar4 & 0x3f) & 0xffU;
      }
      uVar4 = uVar4 + 1;
      pbVar2 = pbVar2 + 1;
    } while (uVar4 != 8);
    iVar6 = iVar6 + 8;
    *puVar5 = (char)uVar1;
    puVar5 = puVar5 + 1;
  } while (iVar6 != 0x70);
  block7_syndrome_threshold_bit_correct(param_1);
  uVar1 = crc16_ccitt(param_1,4);
  return ~(CONCAT11(param_1[4],param_1[5]) != uVar1);
}

