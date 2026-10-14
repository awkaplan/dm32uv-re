/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timer_entry_insert_hash_bucketed_list_0300 @ 03003804 (file base 0x03000000; code starts at 0x03001000)
 * Size: 296 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void timer_entry_insert_hash_bucketed_list_0300
               (int param_1,uint param_2,short param_3,undefined4 *param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  ushort *puVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  
  if (param_3 == 4) {
    iVar3 = *PTR_DAT_0300392c;
    if (0xffff0000 < (param_2 - iVar3) - 1) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *param_4 = 0x727e;
      return;
    }
    *(uint *)(param_1 + 0x4c) = param_2;
    *(uint *)(param_1 + 0x50) = param_2 - iVar3;
  }
  else {
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *param_4 = 0x727e;
      return;
    }
    if (param_3 == 8) {
      iVar3 = *(int *)(param_1 + 0x48) + param_2;
      uVar9 = *PTR_DAT_0300392c;
      if (~uVar9 + iVar3 < param_2) {
        *(int *)(param_1 + 0x4c) = iVar3;
      }
      else {
        *(uint *)(param_1 + 0x4c) = param_2 + uVar9;
      }
      *(uint *)(param_1 + 0x50) = *(int *)(param_1 + 0x4c) - uVar9;
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x4c);
    }
    else {
      *(uint *)(param_1 + 0x4c) = param_2 + *PTR_DAT_0300392c;
      *(uint *)(param_1 + 0x50) = param_2;
    }
  }
  uVar9 = *(uint *)(param_1 + 0x4c) -
          (uint)*_DAT_03003930 * (*(uint *)(param_1 + 0x4c) / (uint)*_DAT_03003930) & 0xffff;
  puVar8 = PTR_DAT_03003934 + uVar9 * 2;
  if (*(short *)(puVar8 + 1) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    PTR_DAT_03003934[uVar9 * 2] = param_1;
    *(undefined2 *)(puVar8 + 1) = 1;
  }
  else {
    if (PTR_DAT_03003934[uVar9 * 2] != 0) {
      iVar7 = *PTR_DAT_0300392c;
      iVar3 = PTR_DAT_03003934[uVar9 * 2];
      do {
        iVar4 = iVar3;
        uVar2 = *(int *)(iVar4 + 0x4c) - iVar7;
        *(uint *)(iVar4 + 0x50) = uVar2;
        if (*(uint *)(param_1 + 0x50) <= uVar2) {
          iVar3 = *(int *)(iVar4 + 0x18);
          if (iVar3 == 0) {
            *(undefined4 *)(param_1 + 0x18) = 0;
            *(int *)(param_1 + 0x14) = iVar4;
            *(int *)(iVar4 + 0x18) = param_1;
            PTR_DAT_03003934[uVar9 * 2] = param_1;
          }
          else {
            *(int *)(param_1 + 0x18) = iVar3;
            *(int *)(param_1 + 0x14) = iVar4;
            *(int *)(iVar3 + 0x14) = param_1;
            *(int *)(iVar4 + 0x18) = param_1;
          }
          goto LAB_030038fa;
        }
        iVar3 = *(int *)(iVar4 + 0x14);
      } while (*(int *)(iVar4 + 0x14) != 0);
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(int *)(param_1 + 0x18) = iVar4;
      *(int *)(iVar4 + 0x14) = param_1;
    }
LAB_030038fa:
    psVar5 = (short *)(uVar9 * 8 + _DAT_03003938);
    *psVar5 = *psVar5 + 1;
  }
  puVar6 = (ushort *)(uVar9 * 8 + _DAT_03003938);
  uVar1 = *puVar6;
  if (puVar6[1] < uVar1) {
    *(ushort *)(uVar9 * 8 + _DAT_03003938 + 2) = uVar1;
  }
  *(undefined4 **)(param_1 + 0x1c) = puVar8;
  *param_4 = 0;
  return;
}

