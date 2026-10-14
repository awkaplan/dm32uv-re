/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_squelch_code_match_search @ 030c7410 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1642 bytes
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

short tone_squelch_code_match_search
                (undefined2 *param_1,int param_2,short param_3,short param_4,int param_5,
                short param_6)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  short *psVar16;
  ushort uVar17;
  short *psStack_70;
  int iStack_6c;
  uint uStack_64;
  undefined1 auStack_4c [12];
  undefined4 uStack_40;
  int iStack_3c;
  short sStack_36;
  short sStack_34;
  short sStack_32;
  short sStack_30;
  ushort uStack_2e;
  ushort uStack_2c;
  ushort uStack_2a;
  ushort uStack_28;
  short sStack_26;
  
  sStack_26 = param_3;
  uVar7 = FUN_030ca8ec(param_2,0x80,&sStack_26);
  iVar10 = iRam030c76f8;
  if ((uVar7 >> 0x10 == 0) || (sStack_26 < -0x1a)) {
    return 0xff;
  }
  sVar5 = *(short *)(param_5 + 8);
  tone_code_best_of4_score_argmax(&iStack_3c,&sStack_36,param_2,iRam030c76f8);
  iVar14 = iRam030c76fc;
  tone_code_best_of4_score_argmax(&uStack_40,&sStack_34,param_2,iRam030c76fc);
  iVar8 = (int)param_3;
  sVar3 = FUN_030c7050(&uStack_28,&uStack_2a,param_2,iVar8,(int)*(short *)(iVar10 + sStack_36 * 2),
                       (int)*(short *)(iVar14 + sStack_34 * 2));
  iVar9 = (int)sStack_36;
  iVar13 = (int)sStack_34;
  iVar15 = (int)param_4;
  if ((short)(*(short *)(iRam030c7700 + (iVar9 + iVar13 * 4 & 0xfU) * 2) + 0x80) == sVar5) {
    bVar1 = true;
  }
  else {
    sVar4 = dmr_channel_params_equal
                      ((int)(short)uStack_28,(int)(short)uStack_2a,(int)sVar3,param_2,iVar8,
                       (int)*(short *)(iVar10 + iVar9 * 2),(int)*(short *)(iRam030c7704 + iVar9 * 2)
                       ,(int)*(short *)(iVar14 + iVar13 * 2),
                       (int)*(short *)(iRam030c7708 + iVar13 * 2),0x51ec);
    bVar1 = sVar4 == 1;
  }
  tone_code_best_of4_score_argmax(&iStack_3c,&sStack_30,param_2,iRam030c770c);
  tone_code_best_of4_score_argmax(&uStack_40,&sStack_32,param_2,iRam030c7710);
  sVar4 = FUN_030c7050(&uStack_2c,&uStack_2e,param_2,iVar8,
                       (int)*(short *)(iRam030c770c + sStack_30 * 2),
                       (int)*(short *)(iRam030c7710 + sStack_32 * 2));
  iVar10 = (int)sStack_30;
  iVar14 = (int)sStack_32;
  if (sVar5 == (short)(*(short *)(iRam030c7700 + (iVar10 + iVar14 * 4 & 0xfU) * 2) + 0x90)) {
    bVar2 = true;
  }
  else {
    sVar5 = dmr_channel_params_equal
                      ((int)(short)uStack_2c,(int)(short)uStack_2e,(int)sVar4,param_2,iVar8,
                       (int)*(short *)(iRam030c770c + iVar10 * 2),
                       (int)*(short *)(iRam030c7714 + iVar10 * 2),
                       (int)*(short *)(iRam030c7710 + iVar14 * 2),
                       (int)*(short *)(iRam030c7718 + iVar14 * 2),0x4189);
    bVar2 = sVar5 == 1;
  }
  sVar5 = sStack_26;
  if (bVar1) {
    if (bVar2) {
      iStack_3c = ((int)((uint)uStack_2e << 0x10) >> 1) + ((int)((uint)uStack_2c << 0x10) >> 1);
      if (iStack_3c != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (((int)((uint)uStack_2a << 0x10) >> 1) + ((int)((uint)uStack_28 << 0x10) >> 1) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      uStack_40 = 0;
      fixed_point_exp_aligned_less_than(0,(int)sVar4,0,(int)sVar3);
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (bVar2) {
    halt_baddata();
  }
  sVar3 = *(short *)(param_5 + 8);
  if ((sVar3 == 0xff) || ((ushort)(sVar3 - 5U) < 0x76)) {
    sVar4 = argmax_index_int32_array(param_2 + 0x14,0x76);
    sVar4 = sVar4 + 5;
    iVar10 = (int)sVar4;
    iVar8 = param_2 + (iVar10 + -2) * 4;
    sStack_30 = param_3;
    iVar14 = FUN_030ca8ec(iVar8,5,&sStack_30);
    iVar14 = iVar14 >> 0x10;
    uStack_64 = channel_audio_gain_clamp(iVar14,(int)sStack_30,iVar15);
    uStack_64 = uStack_64 & 0xffff;
    uVar11 = (uint)(short)(sStack_30 - sVar5);
    if ((int)uVar11 < 0) {
      iVar9 = (iVar14 << 0x10) >> (-uVar11 & 0x3f);
    }
    else {
      iVar9 = (iVar14 << 0x10) << (uVar11 & 0x3f);
    }
    uVar7 = (short)(uVar7 >> 0x10) * 0x10000 - iVar9;
    if (uVar7 == 0x80000000) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((int)uVar7 < 0) {
      uVar7 = ~uVar7 + 1;
    }
    if (uVar7 != 0) {
      halt_baddata();
    }
    uVar7 = channel_audio_gain_clamp(0,(int)sVar5,iVar15);
    sVar3 = *(short *)(param_5 + 8);
    uVar7 = uVar7 & 0xffff;
    if ((4 < sVar3) && ((short)(sVar4 - sVar3) != -0x8000)) {
      uVar11 = (uint)(short)(sVar4 - sVar3);
      if ((int)uVar11 < 0) {
        uVar11 = ~uVar11 + 1;
      }
      if ((int)uVar11 < 2) {
        uStack_64 = ((uint)*(ushort *)(param_5 + 0x16) * 0x6fff + uStack_64 * 0x1000) * 2 + 0x8000
                    >> 0x10;
        uVar7 = ((uint)*(ushort *)(param_5 + 0x18) * 0x6fff + uVar7 * 0x1000) * 2 + 0x8000 >> 0x10;
      }
    }
    sVar5 = (short)uStack_64 - (short)uVar7;
    if (((param_6 == 0) || (sVar3 != 0xff)) || (iVar10 < 0x58)) {
      if ((0x1a92 < sVar5) &&
         ((0x12 < iVar10 || ((0x2137 < sVar5 && ((10 < iVar10 || (0x2688 < sVar5))))))))
      goto LAB_030c78b2;
      goto LAB_030c78fc;
    }
    if (0x2a84 < sVar5) {
LAB_030c78b2:
      sStack_32 = param_3;
      FUN_030caaec(auStack_4c,iVar8,5,&sStack_32);
      iVar10 = (int)sStack_30;
      sVar5 = FUN_030c7144(iVar14,iVar10,auStack_4c,(int)sStack_32);
      if (sVar5 != 0) {
        *param_1 = 0xb000;
        uVar6 = channel_audio_gain_clamp(iVar14,iVar10,iVar15);
        param_1[1] = uVar6;
        *(short *)(param_5 + 0x16) = (short)uStack_64;
        *(short *)(param_5 + 0x18) = (short)uVar7;
        return sVar4;
      }
      sVar3 = *(short *)(param_5 + 8);
      goto LAB_030c78fc;
    }
  }
  else {
LAB_030c78fc:
    uVar12 = sVar3 - 0xa0;
    if (uVar12 < 4) {
      psStack_70 = psRam030c7b40;
      goto LAB_030c790e;
    }
  }
  uVar12 = 0;
  psStack_70 = psRam030c7b40;
  iStack_6c = -1;
  psVar16 = psRam030c7b40;
  uVar17 = 0;
  while( true ) {
    sVar5 = *psVar16;
    sVar3 = psVar16[1];
    iVar14 = (short)(sVar3 - sVar5) * 0x10000;
    iVar10 = ones_complement_checksum_32word(param_2 + sVar5 * 4,iVar14 + 0x30000 >> 0x10);
    if (3 < (short)(sVar3 - sVar5)) {
      iVar14 = ones_complement_checksum_32word(param_2 + (sVar5 + 3) * 4,iVar14 + -0x30000 >> 0x10);
      iVar10 = iVar10 - iVar14;
    }
    if (iStack_6c <= iVar10) {
      iStack_6c = iVar10;
      uVar12 = uVar17;
    }
    if ((ushort)(uVar17 + 1) == 4) break;
    psVar16 = psVar16 + 2;
    uVar17 = uVar17 + 1;
  }
LAB_030c790e:
  sStack_32 = param_3;
  sStack_30 = param_3;
  FUN_030ca8ec(param_2 + psStack_70[(short)uVar12 * 2] * 4,3,&sStack_30);
  FUN_030ca8ec(param_2 + psStack_70[(short)uVar12 * 2 + 1] * 4,3,&sStack_32);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

