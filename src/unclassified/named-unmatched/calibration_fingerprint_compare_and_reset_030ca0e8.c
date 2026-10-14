/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: calibration_fingerprint_compare_and_reset @ 030ca0e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 240 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 calibration_fingerprint_compare_and_reset(short *param_1,short *param_2,short param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined1 *puVar6;
  short sVar7;
  byte *pbVar8;
  int iVar9;
  
  puVar6 = PTR_DAT_030ca1d8;
  bVar1 = PTR_DAT_030ca1d8[0x2a];
  if (param_3 == 1) {
    iVar9 = 0;
  }
  else {
    iVar9 = 0x14;
  }
  bVar2 = PTR_DAT_030ca1d8[0x28];
  bVar3 = PTR_DAT_030ca1d8[0x29];
  bVar4 = PTR_DAT_030ca1d8[0x2b];
  array_copy_u16(param_2 + 1,param_2 + 2,0x10);
  param_2[0x11] = *param_1;
  sVar7 = *param_1;
  if (sVar7 == 0xff) {
    *param_2 = 0;
    return 0;
  }
  if (((0 < *param_2) && (0x12 < sVar7)) && (sVar7 < 0x17)) {
    *param_1 = 0x15 - ((ushort)((int)(((uint)bVar2 << 0x18 | (uint)bVar4 | (uint)bVar3 << 0x10 |
                                      (uint)bVar1 << 8) ^ _DAT_030ca1dc) >>
                               (0x20U - (int)*param_2 & 0x3f)) & 1);
    *param_2 = *param_2 + -1;
    return 1;
  }
  *param_2 = 0;
  pbVar8 = puVar6 + iVar9;
  iVar9 = 0;
  sVar7 = 0x11;
  do {
    while( true ) {
      iVar5 = iVar9 + 2;
      bVar1 = *pbVar8;
      iVar9 = iVar9 + 2;
      pbVar8 = pbVar8 + 1;
      if (*(ushort *)((int)param_2 + iVar5) != (ushort)bVar1) break;
      sVar7 = sVar7 + -1;
      if (iVar9 == 0x22) goto LAB_030ca164;
    }
  } while (iVar9 != 0x22);
LAB_030ca164:
  if (sVar7 < 2) {
    *param_2 = 0x20;
    return 0;
  }
  return 0;
}

