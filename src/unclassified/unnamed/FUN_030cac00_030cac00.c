/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030cac00 @ 030cac00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1380 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x030cb234) */
/* WARNING: Removing unreachable block (ram,0x030cb378) */
/* WARNING: Removing unreachable block (ram,0x030cb382) */
/* WARNING: Removing unreachable block (ram,0x030cb2a2) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030cac00(undefined4 param_1,int param_2__w,short *param_3,short *param_4)

{
  ushort param_2 = (ushort)param_2__w;
  short sVar1;
  undefined2 *puVar2;
  int iVar3;
  short *psVar4;
  ushort *puVar5;
  short sVar6;
  ushort uVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  short sVar17;
  short sVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uStack_330;
  uint uStack_2fc;
  undefined2 auStack_2d8 [256];
  ushort auStack_d8 [80];
  ushort auStack_38 [6];
  short sStack_2c;
  short sStack_2a;
  ushort auStack_28 [2];
  
  iVar13 = iRam030cb38c;
  iVar3 = (int)(short)param_2;
  if (iVar3 < 0x81) {
    uStack_2fc = 8;
  }
  else {
    iVar12 = 0;
    do {
      uVar9 = iVar12 + 8;
      uStack_2fc = iVar12 + 9;
      iVar12 = iVar12 + 1;
    } while (1 << (uVar9 & 0x3f) < iVar3);
  }
  if (iVar3 != 0x50) {
    if (param_2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  array_copy_u16(auStack_d8,iRam030cb38c,0x50);
  auStack_38[0] = *(ushort *)(iVar13 + 0xa0);
  if (*param_4 == 3) {
    u16_buffer_fill_memset(param_3 + 1,0,0x54);
    u16_buffer_fill_memset(auStack_2d8,0,0x100);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar2 = auStack_2d8;
  iVar13 = 0;
  do {
    *puVar2 = (short)((uint)*(ushort *)((int)auStack_d8 + iVar13) *
                      (uint)*(ushort *)((int)param_3 + iVar13 + 2) * 2 >> 0x10);
    puVar2 = puVar2 + 1;
    iVar13 = iVar13 + 2;
  } while (puVar2 != auStack_2d8 + (param_2 - 1 & 0xffff) + 1);
  iVar13 = 0;
  psVar4 = param_3;
  do {
    iVar3 = iVar13 + 0x51;
    iVar13 = iVar13 + 1;
    psVar4[1] = param_3[iVar3];
    psVar4 = psVar4 + 1;
  } while (iVar13 != 4);
  sVar11 = 4;
  psVar4 = param_3 + 4;
  sVar6 = *param_3;
  do {
    psVar4 = psVar4 + 1;
    sVar11 = sVar11 + 1;
    sVar6 = sVar6 * 0xad + 0x3619;
    *psVar4 = sVar6;
  } while (sVar11 < 0x54);
  *param_3 = sVar6;
  puVar5 = auStack_38;
  iVar13 = 0;
  do {
    *(short *)((int)puVar2 + iVar13) =
         (short)((uint)*puVar5 * (uint)*(ushort *)((int)param_3 + iVar13 + 2) * 2 >> 0x10);
    iVar13 = iVar13 + 2;
    puVar5 = puVar5 + -1;
  } while (iVar13 != ((param_2 - 1 & 0xffff) + 1) * 2);
  uVar14 = 1 << (uStack_2fc & 0x3f);
  sVar11 = (short)uVar14;
  u16_buffer_fill_memset((int)puVar2 + iVar13,0,(int)(short)(sVar11 + param_2 * -2));
  sVar1 = func_0x030d52f0(auStack_2d8,0,uStack_2fc,0);
  sVar6 = *param_4;
  uVar7 = param_4[2];
  uVar9 = (uint)(int)sVar11 >> 1;
  if (0 < (short)uVar7) {
    iVar3 = 0;
    puVar5 = (ushort *)(param_4 + 8);
    iVar13 = 0;
    do {
      psVar4 = (short *)(*(int *)(param_4 + 0x40) + iVar3);
      iVar3 = iVar3 + 2;
      if ((*psVar4 == 0) && (iVar13 < (int)((uint)*puVar5 << 0x10))) {
        iVar13 = (uint)*puVar5 << 0x10;
      }
      puVar5 = puVar5 + 1;
    } while (iVar3 != ((uVar7 - 1 & 0xffff) + 1) * 2);
    if (iVar13 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  if ((sVar6 != 2) == true) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  auStack_28[0] = 0x11;
  iVar13 = FUN_030c8f84((uint)uVar7 * 0x86b6,auStack_28);
  auStack_28[0] = auStack_28[0] + 1 + sVar1;
  uVar15 = (iVar13 >> 0x10 & 0xffffU) * 0xaff4 >> 0x10;
  iVar3 = (int)((uVar14 & 0xffff) * (uint)(ushort)param_4[6] * 2) >> 4;
  iVar12 = iVar3 + 0x10000;
  sVar11 = auStack_28[0] + 2;
  uVar14 = iVar12 >> 1;
  iVar13 = u16_buffer_fill_memset(auStack_2d8,0,(int)(short)((short)(iVar12 >> 0x11) * 2));
  if (param_4[2] < 1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar19 = 0;
  sVar17 = 0;
  sVar1 = 0;
  uStack_330 = iVar12 >> 0x11 & 0xffff;
  do {
    uVar14 = uVar14 + iVar3;
    uVar16 = uVar14 >> 0x10;
    if ((short)uVar9 < (short)(uVar14 >> 0x10)) {
      uVar16 = uVar9 & 0xffff;
    }
    uStack_330 = uVar16 - uStack_330;
    sVar18 = (short)uStack_330;
    if (*(short *)(*(int *)(param_4 + 0x40) + iVar19) == 0) {
      if ((sVar6 != 2) == true) {
        iVar21 = (int)(short)(sVar18 * 2);
        iVar12 = FUN_030ca7fc(&sStack_2a,iVar13,iVar13,iVar21);
        if (iVar12 >> 0x10 < 1) {
          sVar8 = 0;
          uVar10 = 0;
        }
        else {
          if ((uStack_330 & 0xffff) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          sStack_2c = 0xf;
          iVar12 = signed_divide_saturating_halved();
          sStack_2c = sStack_2c - sStack_2a;
          uVar10 = FUN_030c8f84(iVar12 << 0x10,&sStack_2c);
          uVar10 = uVar10 >> 0x10;
          sVar8 = sStack_2c;
        }
        uVar7 = sVar8 + auStack_28[0];
        uVar10 = (uVar15 * uVar10 & 0x7fffffff) >> 0xf;
      }
      else {
        iVar21 = (int)(short)(sVar18 * 2);
        uVar10 = uVar15;
        uVar7 = auStack_28[0];
      }
      uVar20 = (uStack_330 & 0xffff) * 2 & 0xffff;
      sVar8 = (uVar7 - sVar11) + 1;
      uVar10 = (uVar10 * *(ushort *)((int)param_4 + iVar19 + 0x10) & 0x7fffffff) >> 0xf;
      if (sVar8 == 0) {
        if (0 < iVar21) {
          iVar12 = 0;
          do {
            *(short *)(iVar13 + iVar12) = (short)(uVar10 * *(ushort *)(iVar13 + iVar12) >> 0x10);
            iVar12 = iVar12 + 2;
          } while (iVar12 != ((uVar20 - 1 & 0xffff) + 1) * 2);
        }
        goto LAB_030cafb8;
      }
      if (sVar8 < 1) {
        if (0 < iVar21) {
          iVar12 = 0;
          do {
            *(short *)(iVar13 + iVar12) =
                 (short)((uint)((int)(uVar10 * *(ushort *)(iVar13 + iVar12)) >>
                               ((int)-sVar8 & 0x3fU)) >> 0x10);
            iVar12 = iVar12 + 2;
          } while (iVar12 != ((uVar20 - 1 & 0xffff) + 1) * 2);
        }
        goto LAB_030cafb8;
      }
      if (iVar21 < 1) goto LAB_030cafb8;
      iVar12 = 0;
      do {
        *(short *)(iVar13 + iVar12) =
             (short)((uVar10 * *(ushort *)(iVar13 + iVar12) << ((int)sVar8 & 0x3fU)) >> 0x10);
        iVar12 = iVar12 + 2;
      } while (iVar12 != ((uVar20 - 1 & 0xffff) + 1) * 2);
      sVar1 = sVar17 + 1;
      if (param_4[2] <= sVar1) {
        halt_baddata();
      }
    }
    else {
      u16_buffer_fill_memset(iVar13,0,(int)(short)(sVar18 * 2));
LAB_030cafb8:
      sVar1 = sVar1 + 1;
      if (param_4[2] <= sVar1) {
        halt_baddata();
      }
    }
    sVar17 = sVar17 + 1;
    iVar19 = iVar19 + 2;
    iVar13 = iVar13 + sVar18 * 4;
    uStack_330 = uVar16;
  } while( true );
}

