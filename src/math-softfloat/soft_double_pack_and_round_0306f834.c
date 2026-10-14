/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_pack_and_round @ 0306f834 (file base 0x03000000; code starts at 0x03001000)
 * Size: 744 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: math-softfloat
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint soft_double_pack_and_round(uint *param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_c8;
  uint uStack_74;
  uint uStack_70;
  
  uVar2 = *param_1;
  uVar5 = param_1[3];
  uVar6 = param_1[4];
  if (uVar2 < 2) {
    local_c8 = *PTR_DAT_0306fae4 & (uVar5 | *PTR_DAT_0306fae8);
    uVar2 = *PTR_DAT_0306faec;
    goto LAB_0306f908;
  }
  if (uVar2 == 4) {
    uVar2 = *PTR_DAT_0306faec;
    local_c8 = 0;
    goto LAB_0306f908;
  }
  if (uVar2 == 2) {
    uVar2 = 0;
    local_c8 = 0;
    goto LAB_0306f908;
  }
  if (uVar5 == 0 && uVar6 == 0) {
    local_c8 = 0;
    uVar2 = 0;
    goto LAB_0306f908;
  }
  uVar2 = param_1[2];
  if (-0x3ff < (int)uVar2) {
    if ((int)uVar2 < 0x400) {
      if ((uVar5 & 0xff) == 0x80) {
        if ((uVar5 & 0x100) != 0) {
          bVar1 = 0xffffff7f < uVar5;
          uVar5 = uVar5 + 0x80;
          uVar6 = uVar6 - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
        }
      }
      else {
        bVar1 = 0xffffff80 < uVar5;
        uVar5 = uVar5 + 0x7f;
        uVar6 = uVar6 - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
      }
      if (0x1fffffff < uVar6) {
        uVar5 = uVar6 << 0x1f | uVar5 >> 1;
        uVar6 = uVar6 >> 1;
      }
      uVar2 = 0;
      local_c8 = *PTR_DAT_0306fae4 & (uVar5 >> 8 | uVar6 << 0x18);
    }
    else {
      local_c8 = 0;
      uVar2 = *PTR_DAT_0306fb2c;
    }
    goto LAB_0306f908;
  }
  iVar4 = -0x3fe - uVar2;
  if (iVar4 < 0x39) {
    uStack_70 = uVar6;
    uVar2 = shift_right_64(uVar5,uVar6,iVar4);
    iVar3 = 0;
    iVar4 = shift_left_64(1,0,iVar4);
    uVar5 = (uint)((iVar4 - 1U & uVar5) != 0 ||
                  ((iVar3 + -1) - ((int)((uint)(iVar4 != 0) << 0x1f) >> 0x1f) & uVar6) != 0);
    uStack_74 = uVar5 | uVar2;
    if ((uVar5 | uVar2 & 0xff) != 0x80) goto LAB_0306fb0e;
    if ((uVar2 & 0x100) != 0) {
      bVar1 = 0xffffff7f < uStack_74;
      uStack_74 = uStack_74 + 0x80;
      uStack_70 = uStack_70 - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
    }
  }
  else {
    uStack_74 = 0;
    uStack_70 = 0;
LAB_0306fb0e:
    bVar1 = 0xffffff80 < uStack_74;
    uStack_74 = uStack_74 + 0x7f;
    uStack_70 = uStack_70 - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
  }
  local_c8 = *PTR_DAT_0306fae4 & (uStack_70 << 0x18 | uStack_74 >> 8);
  uVar2 = 0;
LAB_0306f908:
  return uVar2 | local_c8;
}

