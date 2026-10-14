/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_tone_or_offset_buffer_build @ 030ca1e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 910 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x030ca452) */
/* WARNING: Removing unreachable block (ram,0x030ca462) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
channel_tone_or_offset_buffer_build
          (undefined2 *param_1,short param_2,ushort param_3,uint param_4,short param_5)

{
  short sVar1;
  short sVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  short sVar12;
  uint uVar13;
  short sVar14;
  uint uVar15;
  
  iVar9 = (int)param_2;
  sVar14 = (short)param_4;
  sVar1 = classify_id_into_range_bucket(iVar9);
  iVar10 = (int)sVar1;
  if (iVar10 == 4) {
    return 4;
  }
  puVar11 = param_1 + 8;
  *param_1 = 3;
  *(undefined4 *)(param_1 + 4) = 1;
  param_1[7] = 0;
  u16_buffer_fill_memset(puVar11,0xffffb001,0x38);
  if (sVar1 == 0) {
    sVar1 = FUN_030ca098(0,iVar9,0);
    iVar10 = (int)sVar1;
    param_1[3] = sVar1;
    param_1[1] = param_2;
    uVar3 = signed_divide_saturating_halved(iVar9 << 0x14,iVar10 * 0x1000000 + 0x1000000 >> 0x10);
    sVar1 = sVar1 + 1;
    param_1[6] = uVar3;
    if (sVar1 < 9) {
      sVar1 = 9;
    }
    if (0x38 < sVar1) {
      sVar1 = 0x38;
    }
    param_1[2] = sVar1;
    uVar5 = (int)sVar14;
    uVar8 = param_4 & 0xffff;
    if (sVar14 < -0x5000) {
      uVar5 = 0xffffb000;
      uVar8 = 0xffffb000;
    }
    if (0x77ff < (int)uVar5) {
      uVar8 = 0x77ff;
    }
    param_1[iVar10 + 8] = (short)uVar8;
    if (param_5 != 0) {
      uVar8 = uVar8 * 0x10000;
      uVar5 = uVar8 + 0xb0000000;
      if ((int)((uVar5 ^ 0xafffffff) & (uVar5 ^ uVar8)) < 0) {
        iVar9 = -0x8000;
        if ((uVar8 & 0x80000000) == 0) {
          iVar9 = 0x7fff;
        }
      }
      else {
        iVar9 = (int)uVar5 >> 0x10;
      }
      clamped_table_entry_update(puVar11,iVar10,iVar9);
      return 0;
    }
    return 0;
  }
  sVar1 = FUN_030ca098(iVar10,iVar9,0);
  sVar2 = FUN_030ca098(iVar10,iVar9,1);
  sVar6 = sVar2 + 1;
  uVar3 = PTR_DAT_030ca418[(short)(param_2 + -0x80)];
  param_1[1] = param_2;
  param_1[3] = sVar1 * 0x100 + sVar2;
  param_1[6] = uVar3;
  if (sVar6 < 9) {
    sVar6 = 9;
  }
  if (0x38 < sVar6) {
    sVar6 = 0x38;
  }
  param_1[2] = sVar6;
  if (param_5 != 0) {
    uVar8 = (((int)((uint)param_3 << 0x10) >> 1) + ((int)(param_4 << 0x10) >> 1) >> 0x10) * 0x10000;
    uVar5 = (uint)(ushort)PTR_DAT_030ca41c[(short)(param_2 + -0x80)] * 0x10000;
    uVar15 = uVar8 + (uint)(ushort)PTR_DAT_030ca41c[(short)(param_2 + -0x80)] * -0x10000;
    if ((int)((uVar15 ^ uVar8) & ~(uVar5 ^ uVar15)) < 0) {
      uVar15 = 0xc0000000;
      if ((uVar8 & 0x80000000) == 0) {
        uVar15 = 0x30000000;
      }
      uVar7 = 0x60000000;
      if ((uVar8 & 0x80000000) == 0) {
        uVar7 = 0x1fff0000;
      }
      uVar4 = 0xb0000000;
      if ((uVar8 & 0x80000000) == 0) {
        uVar4 = 0;
      }
      if ((uVar8 & 0x80000000) == 0) {
        sVar14 = 0x6fff;
      }
      else {
        sVar14 = -0x5000;
      }
    }
    else {
      sVar6 = (short)(uVar15 >> 0x10);
      iVar10 = (int)sVar6;
      iVar9 = -0x5000;
      sVar14 = -0x5000;
      if ((-0x5001 < iVar10) && (iVar9 = iVar10, sVar14 = sVar6, 0x6fff < iVar10)) {
        sVar14 = 0x6fff;
        iVar9 = 0x6fff;
      }
      uVar4 = iVar9 * 0x10000;
      uVar7 = uVar4 + 0xb0000000;
      uVar15 = (uVar7 ^ 0xafffffff) & (uVar7 ^ uVar4);
    }
    uVar13 = uVar8 + uVar5;
    if ((int)((uVar5 ^ uVar13) & (uVar13 ^ uVar8)) < 0) {
      if ((uVar8 & 0x80000000) == 0) {
        sVar6 = 0x6fff;
      }
      else {
        sVar6 = -0x5000;
      }
    }
    else {
      sVar12 = (short)(uVar13 >> 0x10);
      sVar6 = -0x5000;
      if ((-0x5001 < sVar12) && (sVar6 = sVar12, 0x6fff < sVar12)) {
        sVar6 = 0x6fff;
      }
    }
    param_1[sVar1 + 8] = sVar14;
    if ((int)uVar15 < 0) {
      iVar9 = -0x8000;
      if ((uVar4 & 0x80000000) == 0) {
        iVar9 = 0x7fff;
      }
    }
    else {
      iVar9 = (int)uVar7 >> 0x10;
    }
    clamped_table_entry_update(puVar11,(int)sVar1,iVar9);
    param_1[sVar2 + 8] = sVar6;
    clamped_table_entry_update(puVar11);
    return 0;
  }
  if ((short)param_3 < -0x5000) {
    param_3 = 0xb000;
    iVar9 = sVar1 + 8;
  }
  else {
    iVar9 = sVar1 + 8;
    if (0x6fff < (short)param_3) {
      param_1[iVar9] = 0x6fff;
      goto joined_r0x030ca36e;
    }
  }
  param_1[iVar9] = param_3;
joined_r0x030ca36e:
  if (sVar14 < -0x5000) {
    sVar14 = -0x5000;
    iVar9 = sVar2 + 8;
  }
  else {
    iVar9 = sVar2 + 8;
    if (0x6fff < sVar14) {
      param_1[iVar9] = 0x6fff;
      return 0;
    }
  }
  param_1[iVar9] = sVar14;
  return 0;
}

