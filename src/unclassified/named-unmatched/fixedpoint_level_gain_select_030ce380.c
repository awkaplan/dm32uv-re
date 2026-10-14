/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fixedpoint_level_gain_select @ 030ce380 (file base 0x03000000; code starts at 0x03001000)
 * Size: 252 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: RAW - unmodified decompiler output; the name, if any, is a guess. */

uint fixedpoint_level_gain_select(int param_1,int param_2,short *param_3)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  iVar5 = (int)*param_3;
  iVar7 = (uint)*(ushort *)(param_1 + 0x4a) * 0x10000;
  iVar6 = iVar5 * 0x10000;
  uVar9 = iVar7 + iVar5 * -0x10000;
  sVar2 = param_3[9];
  uVar10 = uVar9 >> 0x10;
  iVar8 = (int)(short)(uVar9 >> 0x10);
  if (iVar8 < -(int)sVar2) {
    uVar10 = (uint)(ushort)-sVar2;
    iVar8 = (int)-sVar2;
  }
  uVar1 = *(ushort *)(param_1 + 0x50);
  if (sVar2 < iVar8) {
    uVar3 = param_3[5];
  }
  else {
    if (iVar8 < 1) {
      if (*(short *)(param_1 + 0xf6) < 0x4001) {
        if (*(short *)(param_1 + 0xf6) < 0x2001) {
          iVar8 = (int)param_3[10];
          goto LAB_030ce3ce;
        }
LAB_030ce466:
        sVar2 = param_3[10];
      }
      else {
        if (0xccb < *(short *)(param_2 + 10)) goto LAB_030ce466;
        sVar2 = param_3[10];
        iVar8 = (int)sVar2;
        if (iVar8 < (int)(iVar7 + (uint)uVar1 * -0x10000) >> 0x10) {
          sVar2 = (short)((ushort)param_3[7] * uVar10 * 2 + iVar6 >> 0x10);
          *param_3 = sVar2;
          iVar5 = (int)sVar2;
          goto LAB_030ce3ce;
        }
      }
      sVar4 = (short)((ushort)param_3[8] * uVar10 * 2 + iVar6 >> 0x10);
      *param_3 = sVar4;
      iVar8 = (int)sVar2;
      iVar5 = (int)sVar4;
      goto LAB_030ce3ce;
    }
    uVar3 = param_3[6];
  }
  sVar2 = (short)(uVar3 * uVar10 * 2 + iVar6 >> 0x10);
  *param_3 = sVar2;
  iVar8 = (int)param_3[10];
  iVar5 = (int)sVar2;
LAB_030ce3ce:
  sVar2 = param_3[4];
  if (iVar5 < sVar2) {
    *param_3 = sVar2;
    iVar5 = (int)sVar2;
  }
  uVar10 = (uint)(ushort)param_3[1] * 0x10000 + iVar5 * -0x10000;
  sVar2 = (short)(uVar10 >> 0x10);
  uVar9 = (uint)(ushort)param_3[2];
  if ((sVar2 <= param_3[2]) && (uVar9 = uVar10 >> 0x10, sVar2 < param_3[3])) {
    uVar9 = (uint)(ushort)param_3[3];
  }
  iVar5 = (int)(iVar5 * 0x10000 + (uint)uVar1 * -0x10000) >> 0x10;
  if (iVar5 < iVar8) {
    iVar5 = signed_divide_saturating_halved(iVar5 << 0xc);
    uVar9 = (((iVar5 << 0x14) >> 0x10 & 0xffffU) * uVar9 & 0x7fffffff) >> 0xf;
  }
  return uVar9;
}

