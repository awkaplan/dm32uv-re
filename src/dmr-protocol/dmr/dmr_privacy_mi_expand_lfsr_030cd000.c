/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_privacy_mi_expand_lfsr @ 030cd000 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_privacy_mi_expand_lfsr(byte *param_1,byte *param_2,byte param_3)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  bVar3 = *param_1;
  bVar4 = param_1[1];
  bVar7 = param_1[2];
  bVar1 = param_1[3];
  *param_2 = bVar3;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  if (param_3 != 0) {
    uVar6 = (uint)bVar1 + (uint)bVar3 * 0x1000000 + (uint)bVar4 * 0x10000 + (uint)bVar7 * 0x100;
    bVar7 = 0;
    do {
      iVar5 = 0x20;
      do {
        uVar8 = uVar6 & 3;
        uVar2 = uVar6 >> 0x15;
        uVar10 = uVar6 >> 0x1f;
        uVar9 = uVar6 & 1;
        uVar6 = uVar6 * 2;
        iVar5 = iVar5 + -1;
        if ((uVar10 ^ uVar2 & 1 ^ uVar8 >> 1) != uVar9) {
          uVar6 = uVar6 | 1;
        }
      } while (iVar5 != 0);
      bVar7 = bVar7 + 1;
      param_2[4] = (byte)(uVar6 >> 0x18);
      param_2[5] = (byte)(uVar6 >> 0x10);
      param_2[6] = (byte)(uVar6 >> 8);
      param_2[7] = (byte)uVar6;
      param_2 = param_2 + 4;
    } while (bVar7 < param_3);
  }
  return;
}

