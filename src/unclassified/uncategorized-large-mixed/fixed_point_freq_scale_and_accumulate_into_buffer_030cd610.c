/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fixed_point_freq_scale_and_accumulate_into_buffer @ 030cd610 (file base 0x03000000; code starts at 0x03001000)
 * Size: 880 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fixed_point_freq_scale_and_accumulate_into_buffer
               (int param_1,int param_2,short param_3,short param_4,ushort *param_5,short param_6)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  short sVar10;
  uint uVar11;
  uint uVar12;
  int iStack_54;
  uint uStack_40;
  short sStack_3c;
  short sStack_28;
  short sStack_26;
  
  uVar7 = (uint)(short)(param_3 + -0xf);
  if ((int)uVar7 < 0) {
    iVar8 = (param_2 << 0x10) >> (-uVar7 & 0x3f);
    uVar7 = iVar8 + 0xffff;
    sVar1 = (short)(uVar7 >> 0x10);
  }
  else {
    iVar8 = (param_2 << 0x10) << (uVar7 & 0x3f);
    uVar7 = iVar8 + 0xffff;
    sVar1 = (short)(uVar7 >> 0x10);
  }
  iVar5 = (int)sVar1;
  iStack_54 = iVar5 * 0x10000;
  uVar12 = uVar7 >> 0x10;
  if (param_4 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  sVar1 = fixed_point_signed_divide_16bit(0x40000000,1,0,0xfffffffc,&sStack_28);
  iVar2 = freq_range_validate_and_select(param_2,(int)param_3,(int)sVar1,(int)sStack_28,&sStack_26);
  uVar4 = (uint)(short)(sStack_26 + -0xf);
  if ((int)uVar4 < 0) {
    uVar4 = (iVar2 << 0x10) >> (-uVar4 & 0x3f);
  }
  else {
    uVar4 = (iVar2 << 0x10) << (uVar4 & 0x3f);
  }
  sVar1 = (short)(uVar4 >> 0x10);
  uVar3 = uVar4 >> 0x10;
  if (0xa6 < sVar1) {
    uVar3 = 0xa6;
    sVar1 = 0xa6;
  }
  sVar10 = (short)uVar3;
  if (sVar1 < 0x97) {
    if ((short)(sVar10 + 0x10) < 1) {
      return;
    }
    sStack_3c = sVar10 + 0x11;
  }
  else {
    sStack_3c = 0xa7;
  }
  uVar11 = (int)(((uint)(iStack_54 - iVar8) >> 1) << 0x10) >> 0xf;
  uVar4 = ((uVar4 + (uVar4 >> 0x10) * -0x10000 & 0x1ffff ^ 0x10000) - 0x10000 & 0xfffffffe) +
          0xf0000;
  if (iVar5 < 0) {
    if (iVar5 < -0x10) {
      iVar5 = 0x100000;
    }
    else {
      iVar5 = iVar5 * -0x10000;
    }
    uVar11 = uVar11 + iVar5;
    if (sVar10 < 0) {
      uStack_40 = uVar3 + 1 & 0xffff;
      uVar12 = 0;
      uVar4 = uVar4 + (uVar3 + 1) * 0x10000;
      uVar3 = 0;
    }
    else {
      uVar12 = 0;
      uStack_40 = uVar3 + 1 & 0xffff;
      uVar3 = uVar12;
    }
  }
  else {
    uStack_40 = uVar3 + 1 & 0xffff;
    uVar3 = iVar5 << 2;
  }
  sVar1 = (short)uVar12;
  piVar6 = (int *)(param_1 + uVar3);
  if ((short)(((short)(uVar7 >> 0x10) + 0x10) - sVar1) < 1) {
    uVar7 = (uint)(short)(param_6 + -0x10);
    uVar3 = uStack_40 - uVar12 & 0xffff;
    sVar10 = (short)(uStack_40 - uVar12);
    if (0 < sVar10) {
      sVar1 = sVar1 + sVar10;
      if ((int)uVar7 < 0) {
        piVar9 = piVar6 + (uVar3 - 1 & 0xffff) + 1;
        do {
          *piVar6 = (((int)((uint)*param_5 << 0x10) >> 1) >> (-uVar7 & 0x3f)) + *piVar6;
          piVar6 = piVar6 + 1;
        } while (piVar6 != piVar9);
      }
      else {
        piVar9 = piVar6 + (uVar3 - 1 & 0xffff) + 1;
        do {
          *piVar6 = (((int)((uint)*param_5 << 0x10) >> 1) << (uVar7 & 0x3f)) + *piVar6;
          piVar6 = piVar6 + 1;
        } while (piVar6 != piVar9);
      }
    }
    if ((short)(sStack_3c - sVar1) < 1) {
      return;
    }
    table_lookup_linear_interpolate_9bit_index((uVar4 >> 6 & 0xffff ^ 0x8000) - 0x8000);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  table_lookup_linear_interpolate_9bit_index((uVar11 >> 6 & 0xffff ^ 0x8000) - 0x8000);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

