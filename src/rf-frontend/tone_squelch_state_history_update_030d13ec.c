/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_squelch_state_history_update @ 030d13ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 1402 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x030d16f0) */
/* WARNING: Removing unreachable block (ram,0x030d1a44) */
/* WARNING: Removing unreachable block (ram,0x030d1a92) */
/* WARNING: Removing unreachable block (ram,0x030d1a68) */
/* WARNING: Removing unreachable block (ram,0x030d1a6e) */
/* WARNING: Removing unreachable block (ram,0x030d1a72) */
/* WARNING: Removing unreachable block (ram,0x030d1bb8) */
/* WARNING: Removing unreachable block (ram,0x030d1b88) */
/* WARNING: Removing unreachable block (ram,0x030d1876) */
/* WARNING: Removing unreachable block (ram,0x030d18a2) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_squelch_state_history_update(uint *param_1,int param_2__w,int param_3,undefined4 param_4,int param_5__w)

{
  short param_2 = (short)param_2__w;
  short param_5 = (short)param_5__w;
  bool bVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  short *psVar13;
  uint uVar14;
  uint *puVar15;
  uint *puVar16;
  uint uVar17;
  short sStack_26;
  
  puVar9 = (uint *)((int)param_1 + 0x686);
  func_0x030d7cf8(param_1 + 0x1b8,param_4,(int)(short)param_1[0x183] >> 1,param_1,
                  (int)(short)param_1[0x183],(int)param_1 + 0x636,puVar9,
                  (int)*(short *)((int)param_1 + 0x6d6));
  if (param_2 < 1) {
    array_copy_u16((int)param_1 + 0x86e,(int)param_1 + 0x7ce,0x50);
    *(undefined2 *)((int)param_1 + 0x916) = *(undefined2 *)((int)param_1 + 0x912);
    *(short *)(param_1 + 0x246) = (short)param_1[0x245];
    array_copy_u16((int)param_1 + 0x7ce,(int)param_1 + 0x72e,0x50);
    *(undefined2 *)((int)param_1 + 0x912) = *(undefined2 *)((int)param_1 + 0x90e);
    *(short *)(param_1 + 0x245) = (short)param_1[0x244];
    array_copy_u16(param_4,param_3 + (short)((-param_5 + 0x72) * 2) * 2,0x50);
    uVar4 = func_0x030d9abc((int)param_1 + 0x72e,param_4,0xf,uRam030d18e4,0x28);
    *(undefined2 *)((int)param_1 + 0x90e) = uVar4;
    array_copy_u16(param_4,param_3 + (short)((-param_5 + 0x86) * 2) * 2,0x50);
    uVar4 = func_0x030d9abc((int)param_1 + 0x77e,param_4,0xf,uRam030d18e4,0x28);
    *(undefined2 *)(param_1 + 0x244) = uVar4;
    return;
  }
  iVar11 = (int)(short)param_1[0x18b];
  if (0x3333 < iVar11) {
    sVar5 = (short)param_1[0x18c];
    iVar10 = (int)sVar5;
    if (0x3332 < iVar10) goto LAB_030d1634;
LAB_030d163a:
    *(undefined2 *)(param_1 + 0x189) = *(undefined2 *)((int)param_1 + 0x626);
    *(short *)((int)param_1 + 0x62e) = sVar5;
    goto LAB_030d1660;
  }
  if (iVar11 < 0x199a) {
    iVar10 = (int)(short)param_1[0x18c];
  }
  else {
    sVar5 = (short)param_1[0x18c];
    iVar10 = (int)sVar5;
LAB_030d1634:
    if (iVar10 < iVar11 >> 1) goto LAB_030d163a;
  }
  if (iVar10 < 0x3334) {
    if (0x1999 < iVar10) {
LAB_030d164e:
      if (iVar11 < iVar10 >> 1) goto LAB_030d1654;
    }
    iVar6 = (uint)*(ushort *)((int)param_1 + 0x626) * 0x10000;
    uVar8 = *(ushort *)((int)param_1 + 0x622);
    iVar7 = (int)((uint)uVar8 * 0x10000) >> 1;
    *(short *)((int)param_1 + 0x62e) = (short)(iVar10 + iVar11 >> 1);
    *(short *)(param_1 + 0x189) = (short)((uint)((iVar6 >> 1) + iVar7) >> 0x10);
    if (iVar11 < 0xccc) {
      uVar12 = (uint)uVar8 * 0x10000 - (iVar6 >> 1);
      if (uVar12 == 0x80000000) {
        uVar12 = 0x7fffffff;
      }
      else if ((int)uVar12 < 0) {
        uVar12 = ~uVar12 + 1;
      }
      if ((int)(uVar12 + (uint)uVar8 * -0x3332) < 0) {
        *(short *)(param_1 + 0x189) = (short)((uint)((iVar6 >> 2) + iVar7) >> 0x10);
      }
      else {
        uVar12 = iVar6 - iVar7;
        if (uVar12 == 0x80000000) {
          uVar12 = 0x7fffffff;
        }
        else if ((int)uVar12 < 0) {
          uVar12 = ~uVar12 + 1;
        }
        if ((int)(uVar12 + (uint)uVar8 * -0x1998) < 0) {
          *(short *)(param_1 + 0x189) = (short)((uint)(iVar7 + iVar6) >> 0x10);
        }
      }
    }
  }
  else {
    if (0x3332 < iVar11) goto LAB_030d164e;
LAB_030d1654:
    *(undefined2 *)(param_1 + 0x189) = *(undefined2 *)((int)param_1 + 0x622);
    *(short *)((int)param_1 + 0x62e) = (short)param_1[0x18b];
  }
LAB_030d1660:
  puVar16 = param_1 + 0x81;
  uVar12 = 0;
  uVar17 = 0;
  puVar15 = param_1;
  do {
    uVar14 = *puVar15;
    bVar1 = CARRY4(uVar12,uVar14);
    uVar12 = uVar12 + uVar14;
    uVar17 = (uVar17 + ((int)uVar14 >> 0x1f)) - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
    puVar15 = puVar15 + 1;
  } while (puVar15 != param_1 + 0x80);
  if (uVar17 != 0 || uVar12 != 0) {
    if ((int)uVar17 < 0) {
      uVar17 = ~uVar17;
    }
    if ((int)uVar17 < 1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar12 = 0;
  uVar17 = 0;
  do {
    uVar14 = *puVar16;
    bVar1 = CARRY4(uVar12,uVar14);
    uVar12 = uVar12 + uVar14;
    uVar17 = (uVar17 + ((int)uVar14 >> 0x1f)) - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
    puVar16 = puVar16 + 1;
  } while (puVar16 != param_1 + 0x101);
  if (uVar17 == 0 && uVar12 == 0) {
    uVar12 = fixed_point_signed_divide_16bit
                       (0,(int)*(short *)((int)param_1 + 0x60e),0x68db,0xfffffff3,&sStack_26);
    sVar5 = *(short *)((int)param_1 + 0x6d6);
    puVar15 = (uint *)((int)param_1 + 0x696);
    *(short *)(param_1 + 0x1b6) = sVar5 + sStack_26;
    sVar2 = *(short *)((int)param_1 + 0x6da);
    psVar13 = (short *)((int)param_1 + 0x646);
    do {
      if (psVar13[-8] < psVar13[8]) {
        *psVar13 = psVar13[-8];
      }
      else {
        *psVar13 = psVar13[8];
      }
      *(ushort *)(puVar9 + 4) = (ushort)((uVar12 & 0xffff) * (uint)(ushort)*puVar9 * 2 >> 0x10);
      puVar9 = (uint *)((int)puVar9 + 2);
      psVar13 = psVar13 + 1;
    } while (puVar9 != param_1 + 0x1a3);
    puVar16 = param_1 + 0x193;
    while( true ) {
      if ((ushort)*puVar9 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if ((ushort)puVar9[8] != 0) break;
      sVar3 = sVar2;
      if (sVar2 < sVar5) {
        sVar3 = sVar5;
      }
      uVar17 = (uint)(short)(sVar5 - (sVar3 + 1));
      if ((int)uVar17 < 0) {
        iVar11 = 0 >> (-uVar17 & 0x3f);
      }
      else {
        iVar11 = 0 << (uVar17 & 0x3f);
      }
      uVar17 = (uint)(short)(sVar2 - (sVar3 + 1));
      if ((int)uVar17 < 0) {
        iVar10 = 0 >> (-uVar17 & 0x3f);
      }
      else {
        iVar10 = 0 << (uVar17 & 0x3f);
      }
      if (iVar10 + iVar11 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      sVar3 = sVar2;
      if (sVar2 < sVar5) {
        sVar3 = sVar5;
      }
      uVar17 = (uint)(short)(sVar5 - (sVar3 + 1));
      if ((int)uVar17 < 0) {
        iVar11 = 0 >> (-uVar17 & 0x3f);
      }
      else {
        iVar11 = 0 << (uVar17 & 0x3f);
      }
      uVar17 = (uint)(short)(sVar2 - (sVar3 + 1));
      if ((int)uVar17 < 0) {
        iVar10 = 0 >> (-uVar17 & 0x3f);
      }
      else {
        iVar10 = 0 << (uVar17 & 0x3f);
      }
      if (iVar10 + iVar11 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      *(undefined2 *)puVar16 = 0x7fff;
      *(ushort *)(puVar9 + 4) = (ushort)((uVar12 & 0xffff) * (uint)(ushort)*puVar9 * 2 >> 0x10);
      puVar9 = (uint *)((int)puVar9 + 2);
      puVar16 = (uint *)((int)puVar16 + 2);
      if (puVar15 == puVar9) {
        uVar8 = 0;
        puVar9 = puVar15;
        do {
          uVar12 = *puVar9;
          puVar9 = (uint *)((int)puVar9 + 2);
          uVar8 = uVar8 | (ushort)uVar12;
        } while (puVar9 != (uint *)((int)param_1 + 0x6a6));
        if (uVar8 == 0) {
          do {
            *(ushort *)puVar15 = 1;
            puVar15 = (uint *)((int)puVar15 + 2);
          } while (puVar15 != (uint *)((int)param_1 + 0x6a6));
        }
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((int)uVar17 < 0) {
    uVar17 = ~uVar17;
  }
  if ((int)uVar17 < 1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

