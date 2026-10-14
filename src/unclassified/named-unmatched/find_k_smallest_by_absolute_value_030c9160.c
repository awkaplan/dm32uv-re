/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: find_k_smallest_by_absolute_value @ 030c9160 (file base 0x03000000; code starts at 0x03001000)
 * Size: 460 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void find_k_smallest_by_absolute_value
               (uint *param_1,int param_2,ushort param_3,short param_4,short param_5)

{
  short sVar1;
  ushort *puVar2;
  uint *puVar3;
  short *psVar4;
  int iVar5;
  ushort uVar6;
  short sVar7;
  short *psVar8;
  short sVar9;
  ushort uVar11;
  short sVar12;
  uint uVar13;
  uint uVar14;
  short asStack_70 [16];
  ushort auStack_50 [24];
  int iVar10;
  
  uVar13 = 1 << ((int)param_4 & 0x3fU);
  uVar14 = uVar13 & 0xffff;
  uVar11 = (ushort)uVar13;
  auStack_50[0] = uVar11;
  auStack_50[1] = uVar11;
  auStack_50[2] = uVar11;
  auStack_50[3] = uVar11;
  iVar5 = (int)(short)param_3;
  if (iVar5 < 1) {
LAB_030c91fe:
    if (iVar5 < 1) {
      uVar14 = 0;
    }
    else {
      iVar5 = 0;
      uVar14 = 0;
      do {
        psVar8 = (short *)(param_2 + iVar5);
        iVar5 = iVar5 + 2;
        uVar14 = uVar14 * 2 | (int)*psVar8 >> ((int)(short)(param_4 + -1) & 0x3fU);
      } while (iVar5 != ((param_3 - 1 & 0xffff) + 1) * 2);
    }
    *param_1 = uVar14;
    if (1 < param_5) {
      uVar13 = 0;
      puVar3 = param_1;
      while( true ) {
        puVar3 = puVar3 + 1;
        uVar13 = uVar13 + 1;
        *puVar3 = uVar14;
        if ((uVar13 & 1) != 0) {
          uVar14 = uVar14 ^ 1 << ((int)asStack_70[0] & 0x3fU);
          *puVar3 = uVar14;
        }
        if ((uVar13 & 2) != 0) {
          uVar14 = uVar14 ^ 1 << ((int)asStack_70[1] & 0x3fU);
          *puVar3 = uVar14;
        }
        if ((uVar13 & 4) != 0) {
          uVar14 = uVar14 ^ 1 << ((int)asStack_70[2] & 0x3fU);
          *puVar3 = uVar14;
        }
        if ((uVar13 & 8) != 0) {
          *puVar3 = uVar14 ^ 1 << ((int)asStack_70[3] & 0x3fU);
        }
        if (uVar13 == (ushort)(param_5 - 2) + 1) break;
        uVar14 = *param_1;
      }
    }
    return;
  }
  psVar8 = (short *)((iVar5 + -1) * 2 + param_2);
  sVar7 = 0;
  uVar13 = uVar14;
  do {
    uVar6 = (1 - uVar11) + *psVar8 * 2;
    if ((short)uVar6 < 0) {
      uVar6 = ~uVar6 + 1;
    }
    psVar8 = psVar8 + -1;
    if ((short)uVar6 < (short)uVar14) {
      iVar10 = 0;
      sVar9 = 0;
LAB_030c92d4:
      puVar2 = auStack_50 + 2;
      psVar4 = asStack_70 + 2;
      sVar12 = 3;
      do {
        sVar12 = sVar12 + -1;
        sVar1 = *psVar4;
        puVar2[1] = *puVar2;
        psVar4[1] = sVar1;
        puVar2 = puVar2 + -1;
        psVar4 = psVar4 + -1;
      } while (sVar9 < sVar12);
      auStack_50[iVar10] = uVar6;
      asStack_70[iVar10] = sVar7;
    }
    else {
      if ((short)uVar6 < (short)auStack_50[1]) {
        iVar10 = 1;
        sVar9 = 1;
        goto LAB_030c92d4;
      }
      if ((short)uVar6 < (short)uVar13) {
        iVar10 = 2;
        sVar9 = 2;
        goto LAB_030c92d4;
      }
      if ((short)uVar6 < (short)auStack_50[3]) {
        auStack_50[3] = uVar6;
        asStack_70[3] = sVar7;
      }
    }
    sVar7 = sVar7 + 1;
    if (sVar7 == iVar5) goto LAB_030c91fe;
    uVar14 = (uint)auStack_50[0];
    uVar13 = (uint)auStack_50[2];
  } while( true );
}

