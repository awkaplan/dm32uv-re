/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sorted_bucket_deadline_list_insert @ 0306b26c (file base 0x03000000; code starts at 0x03001000)
 * Size: 228 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void sorted_bucket_deadline_list_insert(int param_1,short param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  short *psVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  
  *(undefined1 *)(param_1 + 0x2a) = 2;
  if (param_2 == 1) {
    *(int *)(param_1 + 0x18) = *PTR_DAT_0306b31c + *(int *)(param_1 + 0x24);
  }
  else if (*(int *)(param_1 + 0x20) == 0) {
    *(int *)(param_1 + 0x18) = *PTR_DAT_0306b31c + *(int *)(param_1 + 0x24);
  }
  else {
    *(int *)(param_1 + 0x18) = *PTR_DAT_0306b31c + *(int *)(param_1 + 0x20);
  }
  uVar4 = *(uint *)(param_1 + 0x18);
  uVar9 = uVar4 - (uint)(ushort)*PTR_DAT_0306b324 * (uVar4 / (ushort)*PTR_DAT_0306b324) & 0xffff;
  if (PTR_DAT_0306b34c[uVar9 * 2] == 0) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    puVar2 = PTR_DAT_0306b34c;
    PTR_DAT_0306b34c[uVar9 * 2] = param_1;
    *(undefined2 *)(puVar2 + uVar9 * 2 + 1) = 1;
  }
  else {
    *(uint *)(param_1 + 0x1c) = uVar4 - *PTR_DAT_0306b31c;
    if (PTR_DAT_0306b34c[uVar9 * 2] != 0) {
      iVar8 = *PTR_DAT_0306b31c;
      iVar3 = PTR_DAT_0306b34c[uVar9 * 2];
      do {
        iVar5 = iVar3;
        uVar4 = *(int *)(iVar5 + 0x18) - iVar8;
        *(uint *)(iVar5 + 0x1c) = uVar4;
        if (*(uint *)(param_1 + 0x1c) <= uVar4) {
          iVar3 = *(int *)(iVar5 + 0x14);
          if (iVar3 == 0) {
            *(undefined4 *)(param_1 + 0x14) = 0;
            *(int *)(param_1 + 0x10) = iVar5;
            *(int *)(iVar5 + 0x14) = param_1;
            PTR_DAT_0306b4cc[uVar9 * 2] = param_1;
          }
          else {
            *(int *)(param_1 + 0x14) = iVar3;
            *(int *)(param_1 + 0x10) = iVar5;
            *(int *)(iVar3 + 0x10) = param_1;
            *(int *)(iVar5 + 0x14) = param_1;
          }
          goto LAB_0306b36c;
        }
        iVar3 = *(int *)(iVar5 + 0x10);
      } while (*(int *)(iVar5 + 0x10) != 0);
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(int *)(param_1 + 0x14) = iVar5;
      *(int *)(iVar5 + 0x10) = param_1;
    }
LAB_0306b36c:
    psVar6 = (short *)(uVar9 * 8 + DAT_0306b4d0);
    *psVar6 = *psVar6 + 1;
  }
  puVar7 = (ushort *)(uVar9 * 8 + DAT_0306b4d0);
  uVar1 = *puVar7;
  if (puVar7[1] < uVar1) {
    *(ushort *)(uVar9 * 8 + DAT_0306b4d0 + 2) = uVar1;
  }
  return;
}

