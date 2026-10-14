/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fixed_point_windowed_correlation_or_convolution @ 030c978c (file base 0x03000000; code starts at 0x03001000)
 * Size: 334 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

short fixed_point_windowed_correlation_or_convolution
                (int param_1,undefined4 param_2,int param_3,short param_4,ushort param_5,
                short param_6,int param_7,short param_8,short param_9)

{
  int iVar1;
  ushort *puVar2;
  short sVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short sVar10;
  uint uVar11;
  uint uVar12;
  ushort auStack_228 [257];
  short sStack_26;
  
  uVar11 = (uint)(short)param_5;
  sStack_26 = 0;
  array_copy_u16(auStack_228,param_2,uVar11);
  FUN_030ca9c0(auStack_228,auStack_228,uVar11,&sStack_26);
  sVar3 = sStack_26;
  iVar8 = (int)(short)(uVar11 >> 1);
  uVar5 = 1 << ((int)param_8 & 0x3fU);
  puVar4 = (undefined2 *)(param_7 + param_6 * 2);
  sVar10 = (short)uVar5;
  puVar6 = puVar4;
  if (param_6 == 0) {
    puVar6 = puVar4 + sVar10;
  }
  puVar2 = auStack_228;
  if ((param_5 & 1) != 0) {
    *puVar4 = (short)((int)((uint)*(ushort *)(param_3 + iVar8 * 2) * (uint)auStack_228[iVar8] +
                           0x4000) >> 0xf);
    puVar2 = auStack_228 + 1;
    puVar4 = puVar4 + 1;
  }
  if (0 < iVar8) {
    iVar1 = (iVar8 + -1) * 2;
    iVar7 = 0;
    iVar9 = 0;
    do {
      puVar6 = puVar6 + -1;
      uVar12 = (uint)*(ushort *)(param_3 + iVar1 + iVar7);
      *(short *)((int)puVar4 + iVar9) =
           (short)((int)(uVar12 * *(ushort *)((int)puVar2 + iVar9 + iVar8 * 2) + 0x4000) >> 0xf);
      iVar9 = iVar9 + 2;
      *puVar6 = (short)((int)(*(ushort *)((int)auStack_228 + iVar7 + iVar1) * uVar12 + 0x4000) >>
                       0xf);
      iVar7 = iVar7 + -2;
    } while (iVar9 != (((uVar11 >> 1 & 0xffff) - 1 & 0xffff) + 1) * 2);
    puVar4 = (undefined2 *)((int)puVar4 + iVar9);
  }
  u16_buffer_fill_memset(puVar4,0,(int)(short)(sVar10 - param_5));
  sVar3 = func_0x030d52f0(param_7,(int)(short)(param_4 + sVar3),(int)param_8,(int)param_9);
  if (param_1 != 0) {
    sVar3 = sVar3 * 2;
    FUN_030ca758(param_1,param_7,
                 (int)(short)(param_9 + ((ushort)((uVar5 & 0xffff) >> 1) ^ 0x4000) + 0xc000));
  }
  return sVar3;
}

