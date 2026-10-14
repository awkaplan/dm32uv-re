/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_squelch_detection_frame_process @ 030d01d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 2178 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_squelch_detection_frame_process
               (int param_1,int param_2,short param_3,undefined4 param_4,short param_5,int param_6,
               short param_7,short *param_8,undefined4 param_9)

{
  ushort uVar1;
  bool bVar2;
  ushort *puVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  undefined2 uVar9;
  uint uVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  ushort *puVar14;
  uint *puVar15;
  ushort *puVar16;
  short *psVar17;
  int iVar18;
  uint *puVar19;
  undefined1 *puVar20;
  short *psVar21;
  short sVar22;
  int iVar23;
  uint *puVar24;
  int iVar25;
  int iStack_7c8;
  short *psStack_7c4;
  undefined1 *puStack_7bc;
  int iStack_7b4;
  uint uVar26;
  int iStack_78c;
  undefined1 *puStack_788;
  int iStack_748;
  int iStack_714;
  uint auStack_6e4 [128];
  undefined1 auStack_4e4 [64];
  uint auStack_4a4 [129];
  undefined1 auStack_2a0 [352];
  uint auStack_140 [32];
  uint auStack_c0 [14];
  ushort auStack_88 [30];
  undefined1 auStack_4c [12];
  short asStack_40 [8];
  short sStack_30;
  short sStack_2e;
  short sStack_2a;
  short sStack_28;
  short sStack_26;
  
  sVar4 = func_0x030d36c8(param_1,auStack_2a0,auStack_4e4,&sStack_26,param_4,0x17f,(int)param_5);
  tone_squelch_delay_line_shift
            (param_6,auStack_4e4,(int)(short)(*(short *)(param_1 + 0x62c) * 2 + 7),(int)sStack_26);
  if (0 < param_3) {
    iVar11 = (int)sVar4;
    sStack_28 = -0x1e;
    puVar15 = auStack_140;
    do {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    } while (auStack_c0 != puVar15);
    sVar5 = func_0x030ca704(param_1 + 0x620,7);
    sVar8 = *(short *)(param_6 + 0x72);
    sStack_2a = 0;
    sVar22 = *(short *)(param_6 + 0x52);
    psVar21 = (short *)(param_6 + 0x54);
    psVar17 = (short *)(param_6 + 0x74);
    sVar7 = 1;
    do {
      sVar6 = fixed_point_exp_aligned_less_than((int)*psVar21,(int)*psVar17,(int)sVar22,(int)sVar8);
      sVar7 = sVar7 + 1;
      if (sVar6 != 0) {
        sVar22 = *psVar21;
        sVar8 = *psVar17;
      }
      psVar21 = psVar21 + 1;
      psVar17 = psVar17 + 1;
    } while (sVar7 != 0x10);
    psVar17 = (short *)(param_6 + 0x150);
    sVar6 = 8;
    sVar7 = 0;
    do {
      sVar6 = sVar6 + 1;
      sVar7 = freq_range_validate_and_select
                        ((int)sVar7,(int)sStack_2a,(int)*psVar17,(int)psVar17[0x10],&sStack_2a);
      psVar17 = psVar17 + 1;
    } while (sVar6 != 0x10);
    iVar18 = (int)sVar7;
    sVar7 = fixed_point_exp_aligned_less_than(iVar18,(int)sStack_2a,0x7a12,0xfffffff6);
    if ((sVar7 == 0) &&
       ((((sVar7 = fixed_point_exp_aligned_less_than(iVar18,(int)sStack_2a,0xc35,0xfffffff6),
          sVar7 == 0 ||
          (sVar7 = fixed_point_exp_aligned_less_than
                             (iVar18,(int)sStack_2a,
                              (int)((uint)*(ushort *)(param_6 + 0x13c) * 0x8ccc) >> 0x10,
                              (int)*(short *)(param_6 + 0x13e)), sVar7 == 0)) &&
         (*(short *)(param_6 + 0x50) < -0x1dff)) &&
        ((sVar8 = fixed_point_exp_aligned_less_than((int)sVar22,(int)sVar8,0xffffb000,5), sVar8 == 0
         && (0xeff < (int)*(short *)(param_6 + 0x48) - (int)*(short *)(param_6 + 0x50))))))) {
      bVar2 = false;
    }
    else {
      sVar8 = 0;
      do {
        sVar8 = sVar8 + 1;
      } while (sVar8 != 8);
      bVar2 = true;
    }
    puVar3 = puRam030d0758;
    iVar18 = (int)sVar5;
    uVar26 = 0;
    puStack_788 = auStack_2a0;
    puVar15 = auStack_6e4;
    iStack_78c = param_1 + (iVar11 + -9) * 2;
    do {
      psStack_7c4 = &sStack_30;
      iStack_7c8 = 0;
      iStack_7b4 = iStack_78c;
      puStack_7bc = puStack_788;
      puVar19 = puVar15;
      do {
        array_copy_u16(auStack_c0,iStack_7b4,(int)(short)(0x3a - sVar4));
        array_copy_u16((int)auStack_c0 + (iVar11 + -0x3a) * -2,puStack_7bc,iVar11);
        iVar25 = 0;
        psVar17 = (short *)(param_1 + 0x630);
        do {
          sVar8 = *(short *)(param_1 + 0x62e + iVar25);
          uVar10 = iVar18 - *(short *)(param_1 + 0x620 + iVar25);
          psVar21 = (short *)((int)auStack_c0 + sVar8 * 2);
          if ((uVar10 != 0) && (iVar23 = (int)(short)(*psVar17 - sVar8), 0 < iVar23)) {
            iVar13 = 0;
            do {
              iVar13 = iVar13 + 1;
              *psVar21 = (short)((int)*psVar21 >> (uVar10 & 0x3f));
              psVar21 = psVar21 + 1;
            } while (iVar13 < iVar23);
          }
          iVar25 = iVar25 + 2;
          psVar17 = psVar17 + 1;
        } while (iVar25 != 0xc);
        uVar10 = iVar18 - *(short *)(param_1 + 0x62c);
        psVar17 = (short *)((int)auStack_c0 + *(short *)(param_1 + 0x63a) * 2);
        if ((uVar10 != 0) && (iVar25 = (int)(short)(0x3a - *(short *)(param_1 + 0x63a)), 0 < iVar25)
           ) {
          iVar23 = 0;
          do {
            iVar23 = iVar23 + 1;
            *psVar17 = (short)((int)*psVar17 >> (uVar10 & 0x3f));
            psVar17 = psVar17 + 1;
          } while (iVar23 < iVar25);
        }
        puVar12 = auStack_88;
        puVar14 = auStack_88;
        puVar16 = puRam030d075c;
        do {
          puVar14 = puVar14 + 1;
          uVar1 = *puVar16;
          *puVar14 = (ushort)((int)((uint)uVar1 * (uint)*puVar14 + 0x4000) >> 0xf);
          puVar16 = puVar16 + -1;
          *puVar12 = (ushort)((int)((uint)*puVar12 * (uint)uVar1 + 0x4000) >> 0xf);
          puVar12 = puVar12 + -1;
        } while (puVar16 != puVar3);
        u16_buffer_fill_memset(auStack_4c,0,6);
        sVar8 = func_0x030d52f0(auStack_c0,iVar18,6,0);
        sVar8 = sVar8 * 2;
        iVar25 = 0;
        do {
          uVar10 = *(uint *)((int)auStack_c0 + iVar25);
          *(uint *)((int)puVar19 + iVar25) =
               ((uVar10 >> 0x10) * (uVar10 >> 0x10) + (uVar10 & 0xffff) * (uVar10 & 0xffff)) * 2;
          iVar25 = iVar25 + 4;
        } while (iVar25 != 0x80);
        *psStack_7c4 = sVar8;
        puVar19[1] = 0;
        *puVar19 = 0;
        if (bVar2) {
          if ((uVar26 & 0xffff) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          iVar11 = ((int)((uint)*(ushort *)(param_6 + 0x136) << 0x10) >> 1) +
                   ((int)((uint)*(ushort *)(param_6 + 0x134) << 0x10) >> 1);
          if ((short)iStack_7c8 == 1) {
            iVar11 = (((uint)*(ushort *)(param_6 + 0x122) + (uint)*(ushort *)(param_6 + 0x112)) *
                      0x10000 - (iVar11 >> 1)) * 2;
          }
          if (-1 < iVar11 + -0x12000000) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        iVar25 = 0;
        do {
          *(undefined4 *)((int)auStack_4a4 + iVar25) = *(undefined4 *)((int)puVar19 + iVar25);
          iVar25 = iVar25 + 4;
        } while (iVar25 != 0x80);
        uVar10 = (int)sStack_28 - (int)sVar8;
        puVar19 = auStack_4a4;
        puVar24 = auStack_140;
        sVar22 = sStack_28;
        if ((int)uVar10 < 0) {
          uVar10 = -uVar10;
          puVar19 = auStack_140;
          puVar24 = auStack_4a4;
          sVar22 = sVar8;
        }
        iVar25 = 0;
        do {
          *(int *)((int)auStack_140 + iVar25) =
               (*(int *)((int)puVar19 + iVar25) >> (uVar10 & 0x3f)) +
               *(int *)((int)puVar24 + iVar25);
          iVar25 = iVar25 + 4;
        } while (iVar25 != 0x80);
        iStack_7c8 = iStack_7c8 + 1;
        puStack_7bc = puStack_7bc + 0x16;
        iStack_7b4 = iStack_7b4 + 0x62;
        psStack_7c4 = psStack_7c4 + 1;
        sStack_28 = sVar22;
        puVar19 = auStack_c0;
      } while (iStack_7c8 != 2);
      puStack_788 = puStack_788 + 0x2c;
      uVar10 = (int)sStack_30 - (int)sStack_2e;
      puVar19 = puVar15;
      puVar24 = auStack_c0;
      sVar8 = sStack_30;
      if ((int)uVar10 < 0) {
        uVar10 = -uVar10;
        puVar19 = auStack_c0;
        puVar24 = puVar15;
        sVar8 = sStack_2e;
      }
      iVar25 = 0;
      do {
        *(int *)((int)puVar15 + iVar25) =
             (*(int *)((int)puVar24 + iVar25) >> (uVar10 & 0x3f)) + *(int *)((int)puVar19 + iVar25);
        iVar25 = iVar25 + 4;
      } while (iVar25 != 0x80);
      asStack_40[uVar26] = sVar8;
      psVar17 = asStack_40 + uVar26;
      uVar26 = uVar26 + 1;
      FUN_030caaec(puVar15,puVar15,0x20,psVar17);
      iStack_78c = iStack_78c + 0xc4;
      puVar15 = puVar15 + 0x10;
    } while (uVar26 != 8);
    FUN_030caaec(auStack_4e4,auStack_140,0x20,&sStack_28);
  }
  iStack_714 = param_1 + 0x620;
  iStack_748 = (int)sVar4;
  iVar18 = param_1 + iStack_748 * 2;
  iVar11 = param_1 + (iStack_748 + -0x31) * -2;
  puVar20 = auStack_2a0;
  do {
    array_copy_u16(param_1,iVar18,(int)(short)(0x31 - sVar4));
    array_copy_u16(iVar11,puVar20,iStack_748);
    param_1 = param_1 + 0x62;
    iVar18 = iVar18 + 0x62;
    iVar11 = iVar11 + 0x62;
    puVar20 = puVar20 + 0x16;
  } while (param_1 != iStack_714);
  if (param_3 < 1) {
    return;
  }
  fixed_point_windowed_correlation_or_convolution
            (auStack_4a4,param_4,uRam030d0a7c,0xfffffff9,0xff,0,auStack_4a4,8,0);
  sVar4 = func_0x030d5680(param_2 + 0x614,param_2 + 0x622,auStack_4e4,auStack_4a4,param_2,
                          (int)*(short *)(param_2 + 0x91a),(int)param_7,param_8,param_9,
                          (int)*(short *)(param_6 + 0x180));
  *(undefined2 *)(param_2 + 0x91e) = *(undefined2 *)(param_2 + 0x91c);
  *(undefined2 *)(param_2 + 0x91c) = *(undefined2 *)(param_2 + 0x91a);
  uVar9 = func_0x030da640(param_2 + 0x636,(int)sVar4,auStack_6e4,asStack_40);
  uVar26 = (uint)*(short *)(param_2 + 0x622);
  *(undefined2 *)(param_2 + 0x91a) = uVar9;
  if ((int)uVar26 < 0x375a) {
    if (((int)uVar26 < 0x1001) && (*param_8 == 0)) goto LAB_030d08f0;
  }
  else {
    sVar4 = (short)(uVar26 >> 1);
    *(short *)(param_2 + 0x622) = sVar4;
    uVar26 = (uint)sVar4;
  }
  func_0x030da32c(param_2 + 0x636,uVar26,auStack_4a4);
  if ((*param_8 != 0) && (*(short *)(param_2 + 0x644) < 0x1999)) {
    *(undefined2 *)(param_2 + 0x644) = 0x1999;
  }
LAB_030d08f0:
  sVar4 = 0;
  do {
    sVar4 = sVar4 + 1;
  } while (sVar4 < 5);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

