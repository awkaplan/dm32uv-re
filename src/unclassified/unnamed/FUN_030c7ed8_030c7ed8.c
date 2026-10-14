/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c7ed8 @ 030c7ed8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 4 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x030c84a2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_030c7ed8(undefined4 param_1,short param_2,undefined4 param_3,short param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  short *psVar11;
  ushort *puVar12;
  ushort unaff_r4;
  int *unaff_r5;
  int iVar13;
  undefined4 uVar14;
  int *piVar15;
  uint uVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  int iStack_2e8;
  undefined4 uStack_2dc;
  ushort auStack_2c8 [23];
  undefined2 uStack_29a;
  undefined2 uStack_26c;
  undefined1 auStack_1a8 [288];
  uint auStack_88 [16];
  short sStack_46;
  
  unaff_r5[7] = 0;
  *(undefined2 *)(unaff_r5 + 0xc) = 0;
  u16_buffer_fill_memset((int)unaff_r5 + 0x22,0,7);
  u16_buffer_fill_memset(unaff_r5,0,0xe);
  if ((unaff_r4 & 0xc) == 0) {
    if (*(short *)((int)unaff_r5 + 0x42) == 0) {
      param_2 = 0;
    }
    uVar16 = (uint)param_4;
    sVar1 = lookup_table_sequence_processor
                      (auStack_1a8,unaff_r4 & 0xc,(int)*(short *)((int)unaff_r5 + 0x42));
    if (0 < sVar1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *(undefined2 *)(unaff_r5 + 0xc) = 0;
    sVar1 = *(short *)((int)unaff_r5 + 0x42);
    if (sVar1 != 0) {
      *(undefined2 *)((int)unaff_r5 + 0x36) = *(undefined2 *)(iRam030c84c0 + param_2 * 2);
      func_0x030d27f8(auStack_2c8,param_3);
    }
    if (0 < param_2) {
      psVar11 = _FUN_030c81c8;
      do {
        sVar2 = *psVar11;
        psVar11 = psVar11 + 1;
        auStack_2c8[sVar2] = (ushort)(1 << (uVar16 - 1 & 0x3f));
      } while (psVar11 != _FUN_030c81c8 + (ushort)(param_2 - 1) + 1);
    }
    uVar4 = *(ushort *)(unaff_r5 + 0xd);
    if (0 < (short)uVar4) {
      iVar8 = 0;
      puVar12 = auStack_2c8;
      do {
        uVar6 = *puVar12;
        puVar12 = puVar12 + 1;
        uVar7 = (uint)uVar6 * 0x20000 + ((1 << (uVar16 & 0x3f)) + -1) * -0x10000 >> 0x10;
        iVar8 = iVar8 + uVar7 * uVar7;
      } while (puVar12 != auStack_2c8 + (uVar4 - 1 & 0xffff) + 1);
      if (iVar8 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    if ((uint)uVar4 * 0x3f01 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iVar8 = fixed_point_signed_divide_16bit(0,0x1f,0,0x1f,&sStack_46);
    iVar8 = FUN_030c8f84(iVar8 << 0x10,&sStack_46);
    if (iVar8 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar7 = (uint)(short)(sStack_46 + -1);
    if ((int)uVar7 < 0) {
      iVar8 = 0 >> (-uVar7 & 0x3f);
    }
    else {
      iVar8 = 0 << (uVar7 & 0x3f);
    }
    if (0 < (short)uVar4) {
      uVar7 = (uint)sStack_46;
      puVar12 = auStack_2c8;
      do {
        if ((int)uVar7 < 0) {
          iVar9 = (0 >> (-uVar7 & 0x3f)) + (0x400000 - iVar8);
          uVar6 = (ushort)((uint)iVar9 >> 0x10);
          *puVar12 = uVar6;
        }
        else {
          iVar9 = (0 << (uVar7 & 0x3f)) + (0x400000 - iVar8);
          uVar6 = (ushort)((uint)iVar9 >> 0x10);
          *puVar12 = uVar6;
        }
        if (iVar9 < 0) {
          uVar6 = 0;
        }
        if (0x7f < (short)uVar6) {
          uVar6 = 0x7f;
        }
        *puVar12 = uVar6;
        puVar12 = puVar12 + 1;
      } while (puVar12 != auStack_2c8 + (uVar4 - 1 & 0xffff) + 1);
    }
    if (param_2 == 5) {
      uStack_29a = 0x40;
    }
    else if (param_2 == 6) {
      uStack_29a = 0x40;
      uStack_26c = 0x40;
    }
    *(undefined2 *)(unaff_r5 + 0xc) = 0;
    unaff_r5[7] = 0;
    if (sVar1 == 1) {
      iVar8 = 0x18;
      uVar14 = 0x17;
      iStack_2e8 = 0xc;
      uStack_2dc = 0x10;
    }
    else {
      uVar14 = 0x72;
      iStack_2e8 = 0xb;
      iVar8 = 0x17;
      uStack_2dc = 8;
    }
    uVar7 = best_match_index_search_by_cost_metric
                      (unaff_r5,auStack_88,uStack_2dc,auStack_2c8,iVar8,7,uRam030c83d0,uRam030c83d4,
                       sVar1 == 1);
    sVar2 = FUN_030c8610(auStack_88[0] ^ uVar7,iVar8);
    puVar12 = auStack_2c8 + iVar8;
    uVar7 = (int)uVar7 >> iStack_2e8 & 0xfff;
    *(short *)(unaff_r5 + 0xc) = (short)unaff_r5[0xc] + sVar2;
    *(short *)((int)unaff_r5 + 0x22) = sVar2;
    unaff_r5[7] = unaff_r5[7] + *unaff_r5;
    lcg_conditional_reflect_u16_array(puVar12,uVar14,uVar7,0x7f);
    iVar9 = unpack_bits_lsb_first_to_u16_array_signed(uVar7,&stack0xffffffe0,0xc);
    if (sVar1 == 1) {
      sVar2 = 2;
      iStack_2e8 = 0xb;
      iVar8 = 0x17;
    }
    else {
      sVar2 = 4;
    }
    piVar17 = unaff_r5 + 9;
    iVar13 = 1;
    piVar15 = unaff_r5;
    do {
      piVar15 = piVar15 + 1;
      uVar7 = best_match_index_search_by_cost_metric
                        (unaff_r5 + iVar13,auStack_88,uStack_2dc,puVar12,iVar8,7,uRam030c83d0,
                         uRam030c83d4,0);
      sVar3 = func_0x030c8614(auStack_88[0] ^ uVar7,iVar8);
      iVar19 = unaff_r5[7];
      iVar5 = *piVar15;
      iVar18 = unaff_r5[0xc];
      *(short *)piVar17 = sVar3;
      *(short *)(unaff_r5 + 0xc) = sVar3 + (short)iVar18;
      unaff_r5[7] = iVar19 + iVar5;
      iVar9 = unpack_bits_lsb_first_to_u16_array_signed((int)uVar7 >> iStack_2e8 & 0xfff,iVar9,0xc);
      iVar13 = iVar13 + 1;
      puVar12 = puVar12 + 0x17;
      piVar17 = (int *)((int)piVar17 + 2);
      iVar18 = 0;
    } while ((short)iVar13 < sVar2);
    uVar7 = (uint)*(ushort *)((int)unaff_r5 + 0x36) - (iVar9 - (int)&stack0xffffffe0 >> 1);
    uVar10 = uVar7 & 0xffff;
    if ((uVar10 != 0) && (0 < (short)uVar7)) {
      do {
        *(ushort *)(iVar9 + iVar18) = (*(ushort *)((int)puVar12 + iVar18) >> 6 ^ 0x200) - 0x200;
        iVar18 = iVar18 + 2;
      } while (iVar18 != ((uVar10 - 1 & 0xffff) + 1) * 2);
    }
    if (sVar1 == 1) {
      iVar8 = 0x1fc90;
      uVar14 = 0x2f;
      if (param_2 == 0) {
        iVar8 = 0x1dc90;
      }
      sVar2 = 6;
    }
    else {
      uVar14 = 0x89;
      iVar8 = 250000;
      sVar2 = 0xe;
    }
    *(undefined2 *)((int)unaff_r5 + 0x32) = 0;
    uVar4 = FUN_030c7e04((int)(short)unaff_r5[8],(int)(short)unaff_r5[0xc],uVar14);
    *(ushort *)(unaff_r5 + 8) = uVar4;
    if (((int)uVar16 < 2) && (param_2 == 0)) {
      if ((sVar1 == 0) &&
         (sVar2 = (short)((uint)(((int)((uint)uVar4 * 0xa000) >> 0xb) + 0xa0000) >> 0x10),
         0xc < sVar2)) {
        sVar2 = 0xc;
      }
      if ((1 < *(short *)((int)unaff_r5 + 0x22)) &&
         ((sVar2 <= (short)unaff_r5[0xc] || (3 < *(short *)((int)unaff_r5 + 0x22))))) {
        *(undefined2 *)((int)unaff_r5 + 0x32) = 4;
      }
      uVar6 = *(ushort *)((int)unaff_r5 + 0x32);
      sVar1 = 0x3127;
      goto LAB_030c7fe6;
    }
    if (((*(short *)((int)unaff_r5 + 0x22) < 1) ||
        ((int)*(short *)((int)unaff_r5 + 0x22) + (int)(short)unaff_r5[0xc] <= (int)sVar2)) ||
       (*unaff_r5 + unaff_r5[7] < iVar8)) {
      uVar6 = *(ushort *)((int)unaff_r5 + 0x32);
    }
    else {
      *(undefined2 *)((int)unaff_r5 + 0x32) = 4;
      uVar6 = 4;
    }
    if ((int)uVar16 < 2) goto LAB_030c8026;
  }
  else {
    *(undefined2 *)((int)unaff_r5 + 0x32) = 4;
    lookup_table_sequence_processor(&stack0xffffffe0,1,(int)*(short *)((int)unaff_r5 + 0x42));
    uVar4 = *(ushort *)(unaff_r5 + 8);
    uVar6 = *(ushort *)((int)unaff_r5 + 0x32);
    if (param_4 < 2) {
LAB_030c8026:
      if (param_2 == 0) {
        sVar1 = 0x3127;
      }
      else {
        sVar1 = 0x3958;
      }
      goto LAB_030c7fe6;
    }
  }
  sVar1 = 0x3958;
LAB_030c7fe6:
  if (sVar1 < (short)uVar4) {
    *(ushort *)((int)unaff_r5 + 0x32) = uVar6 | 8;
    return uVar6 | 8;
  }
  return *(ushort *)((int)unaff_r5 + 0x32);
}

