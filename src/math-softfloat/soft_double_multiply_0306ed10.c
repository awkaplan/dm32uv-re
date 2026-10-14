/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_multiply @ 0306ed10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 668 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void soft_double_multiply
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uStack_98;
  int iStack_94;
  undefined4 uStack_70;
  uint uStack_6c;
  int iStack_68;
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uStack_34 = param_3;
  uStack_30 = param_4;
  uStack_2c = param_1;
  uStack_28 = param_2;
  soft_double_unpack(&uStack_2c,&uStack_48);
  soft_double_unpack(&uStack_34,&uStack_5c);
  if (1 < uStack_48) {
    if (uStack_5c < 2) {
LAB_0306ef96:
      uStack_58 = (uint)(uStack_44 != uStack_58);
      soft_double_pack_and_round(&uStack_5c);
      return;
    }
    puVar6 = _LAB_0306efb4;
    if (uStack_48 == 4) {
      if (uStack_5c != 2) goto LAB_0306ef1e;
    }
    else if (uStack_5c == 4) {
      if (uStack_48 != 2) goto LAB_0306ef96;
    }
    else {
      if (uStack_48 == 2) goto LAB_0306ef1e;
      if (uStack_5c == 2) goto LAB_0306ef96;
      uVar7 = 0;
      uVar2 = umul32_to_64(uStack_3c,0,uStack_50,0,uStack_50);
      uVar8 = 0;
      uVar3 = umul32_to_64(uStack_4c,0,uStack_3c,0);
      iVar9 = 0;
      uVar4 = umul32_to_64(uStack_38,0,uStack_4c,0);
      iVar10 = 0;
      uVar5 = umul32_to_64(uStack_38,0,uStack_50,0);
      uVar11 = (iVar10 + uVar8) - ((int)((uint)CARRY4(uVar5,uVar3) << 0x1f) >> 0x1f);
      if ((uVar11 < uVar8) || ((uVar8 == uVar11 && (uVar5 + uVar3 < uVar3)))) {
        uStack_98 = *PTR_DAT_0306ef34;
        iStack_94 = PTR_DAT_0306ef34[1];
        iVar10 = 1;
      }
      else {
        iVar10 = 0;
        iStack_94 = 0;
        uStack_98 = 1;
      }
      uVar3 = uVar5 + uVar3 + uVar7;
      if (uVar7 <= uVar3) {
        uStack_98 = 0;
        iStack_94 = iVar10;
      }
      uStack_64 = uVar11 + uVar4 + uStack_98;
      uStack_60 = ((iVar9 - ((int)((uint)CARRY4(uVar11,uVar4) << 0x1f) >> 0x1f)) + iStack_94) -
                  ((int)((uint)CARRY4(uVar11 + uVar4,uStack_98) << 0x1f) >> 0x1f);
      uStack_6c = (uint)(uStack_44 != uStack_58);
      iStack_68 = iStack_54 + iStack_40 + 4;
      if (0x1fffffff < uStack_60) {
        uVar4 = uStack_64;
        iVar9 = iStack_54 + iStack_40 + 5;
        do {
          iStack_68 = iVar9;
          uStack_64 = uStack_60 << 0x1f | uVar4 >> 1;
          uStack_60 = uStack_60 >> 1;
          if ((uVar4 & 1) != 0) {
            uVar2 = *PTR_DAT_0306ef38 | uVar2 >> 1 | uVar3 << 0x1f;
            uVar3 = PTR_DAT_0306ef38[1] | uVar3 >> 1;
          }
          uVar4 = uStack_64;
          iVar9 = iStack_68 + 1;
        } while (0x1fffffff < uStack_60);
      }
      while (uStack_60 < 0x10000000) {
        bVar1 = CARRY4(uStack_64,uStack_64);
        uStack_64 = uStack_64 * 2;
        uStack_60 = uStack_60 * 2 - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
        iStack_68 = iStack_68 + -1;
        if ((int)uVar3 < 0) {
          uStack_64 = uStack_64 | 1;
        }
        bVar1 = CARRY4(uVar2,uVar2);
        uVar2 = uVar2 * 2;
        uVar3 = uVar3 * 2 - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
      }
      if ((((uStack_64 & 0xff) == 0x80) && ((uStack_64 & 0x100) == 0)) && (uVar2 != 0 || uVar3 != 0)
         ) {
        uStack_60 = uStack_60 - ((int)((uint)(0xffffff7f < uStack_64) << 0x1f) >> 0x1f);
        uStack_64 = uStack_64 + 0x80 & 0xffffff00;
      }
      uStack_70 = 3;
      puVar6 = &uStack_70;
    }
    soft_double_pack_and_round(puVar6);
    return;
  }
LAB_0306ef1e:
  uStack_44 = (uint)(uStack_44 != uStack_58);
  soft_double_pack_and_round(&uStack_48);
  return;
}

