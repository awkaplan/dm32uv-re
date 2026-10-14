/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c81c8 @ 030c81c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

ushort FUN_030c81c8(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  int *unaff_r4;
  int iVar9;
  int unaff_r6;
  int iVar10;
  int unaff_r8;
  undefined4 uVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uStack00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  undefined4 uStack00000014;
  int in_stack_0000001c;
  int iStack00000020;
  int in_stack_00000024;
  uint in_stack_00000268;
  
  if (unaff_r8 == 5) {
    *(undefined2 *)(unaff_r6 + 0x2e) = 0x40;
  }
  else if (unaff_r8 == 6) {
    *(undefined2 *)(unaff_r6 + 0x2e) = 0x40;
    *(undefined2 *)(unaff_r6 + 0x5c) = 0x40;
  }
  iStack00000020 = (int)(short)in_stack_00000024;
  *(undefined2 *)(unaff_r4 + 0xc) = 0;
  unaff_r4[7] = 0;
  if (iStack00000020 == 1) {
    iVar14 = 0x18;
    uVar11 = 0x17;
    uStack00000008 = 0xc;
    uStack00000014 = 0x10;
  }
  else {
    uVar11 = 0x72;
    uStack00000008 = 0xb;
    iVar14 = 0x17;
    uStack00000014 = 8;
  }
  uVar4 = best_match_index_search_by_cost_metric();
  sVar1 = FUN_030c8610(in_stack_00000268 ^ uVar4,iVar14);
  iVar9 = unaff_r6 + iVar14 * 2;
  uVar4 = (int)uVar4 >> (uStack00000008 & 0x3f) & 0xfff;
  *(short *)(unaff_r4 + 0xc) = (short)unaff_r4[0xc] + sVar1;
  *(short *)((int)unaff_r4 + 0x22) = sVar1;
  unaff_r4[7] = unaff_r4[7] + *unaff_r4;
  lcg_conditional_reflect_u16_array(iVar9,uVar11,uVar4,0x7f);
  iVar5 = unpack_bits_lsb_first_to_u16_array_signed(uVar4,in_stack_0000001c,0xc);
  if (iStack00000020 == 1) {
    sVar1 = 2;
    uStack00000008 = 0xb;
    iVar14 = 0x17;
  }
  else {
    sVar1 = 4;
  }
  piVar13 = unaff_r4 + 9;
  iVar10 = 1;
  piVar12 = unaff_r4;
  do {
    piVar12 = piVar12 + 1;
    uVar4 = best_match_index_search_by_cost_metric
                      (unaff_r4 + iVar10,&stack0x00000268,uStack00000014,iVar9);
    sVar2 = func_0x030c8614(in_stack_00000268 ^ uVar4,iVar14);
    iVar16 = unaff_r4[7];
    iVar6 = *piVar12;
    iVar15 = unaff_r4[0xc];
    *(short *)piVar13 = sVar2;
    *(short *)(unaff_r4 + 0xc) = sVar2 + (short)iVar15;
    unaff_r4[7] = iVar16 + iVar6;
    iVar5 = unpack_bits_lsb_first_to_u16_array_signed
                      ((int)uVar4 >> (uStack00000008 & 0x3f) & 0xfff,iVar5,0xc);
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x2e;
    piVar13 = (int *)((int)piVar13 + 2);
    iVar15 = 0;
  } while ((short)iVar10 < sVar1);
  uVar4 = (uint)*(ushort *)((int)unaff_r4 + 0x36) - (iVar5 - in_stack_0000001c >> 1);
  uVar8 = uVar4 & 0xffff;
  if ((uVar8 != 0) && (0 < (short)uVar4)) {
    do {
      *(ushort *)(iVar5 + iVar15) = (*(ushort *)(iVar9 + iVar15) >> 6 ^ 0x200) - 0x200;
      iVar15 = iVar15 + 2;
    } while (iVar15 != ((uVar8 - 1 & 0xffff) + 1) * 2);
  }
  if (iStack00000020 == 1) {
    iVar14 = 0x1fc90;
    uVar11 = 0x2f;
    if (in_stack_00000010 == 0) {
      iVar14 = 0x1dc90;
    }
    sVar1 = 6;
  }
  else {
    uVar11 = 0x89;
    iVar14 = 250000;
    sVar1 = 0xe;
  }
  *(undefined2 *)((int)unaff_r4 + 0x32) = 0;
  uVar3 = FUN_030c7e04((int)(short)unaff_r4[8],(int)(short)unaff_r4[0xc],uVar11);
  *(ushort *)(unaff_r4 + 8) = uVar3;
  if ((in_stack_0000000c < 2) && (in_stack_00000010 == 0)) {
    if ((in_stack_00000024 == 0) &&
       (sVar1 = (short)((uint)(((int)((uint)uVar3 * 0xa000) >> 0xb) + 0xa0000) >> 0x10), 0xc < sVar1
       )) {
      sVar1 = 0xc;
    }
    if ((1 < *(short *)((int)unaff_r4 + 0x22)) &&
       ((sVar1 <= (short)unaff_r4[0xc] || (3 < *(short *)((int)unaff_r4 + 0x22))))) {
      *(undefined2 *)((int)unaff_r4 + 0x32) = 4;
    }
    uVar7 = *(ushort *)((int)unaff_r4 + 0x32);
    sVar1 = 0x3127;
  }
  else {
    if ((*(short *)((int)unaff_r4 + 0x22) < 1) ||
       (((int)*(short *)((int)unaff_r4 + 0x22) + (int)(short)unaff_r4[0xc] <= (int)sVar1 ||
        (*unaff_r4 + unaff_r4[7] < iVar14)))) {
      uVar7 = *(ushort *)((int)unaff_r4 + 0x32);
    }
    else {
      *(undefined2 *)((int)unaff_r4 + 0x32) = 4;
      uVar7 = 4;
    }
    if (in_stack_0000000c < 2) {
      if (in_stack_00000010 == 0) {
        sVar1 = 0x3127;
      }
      else {
        sVar1 = 0x3958;
      }
    }
    else {
      sVar1 = 0x3958;
    }
  }
  if (sVar1 < (short)uVar3) {
    *(ushort *)((int)unaff_r4 + 0x32) = uVar7 | 8;
    return uVar7 | 8;
  }
  return *(ushort *)((int)unaff_r4 + 0x32);
}

