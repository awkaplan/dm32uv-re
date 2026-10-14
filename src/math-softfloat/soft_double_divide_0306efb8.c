/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_divide @ 0306efb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 366 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void soft_double_divide(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint local_5c;
  uint uStack_58;
  int iStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint local_48;
  uint uStack_44;
  int iStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  
  puVar5 = &local_48;
  local_34 = param_3;
  uStack_30 = param_4;
  local_2c = param_1;
  uStack_28 = param_2;
  soft_double_unpack(&local_2c,puVar5);
  soft_double_unpack(&local_34,&local_5c);
  puVar4 = puVar5;
  uVar9 = uStack_3c;
  uVar7 = uStack_38;
  if ((1 < local_48) && (puVar4 = &local_5c, 1 < local_5c)) {
    uStack_44 = uStack_44 ^ uStack_58;
    if ((local_48 == 4) || (local_48 == 2)) {
      if (local_48 == local_5c) {
        puVar5 = PTR_DAT_0306f1ac;
      }
      soft_double_pack_and_round(puVar5);
      return;
    }
    if (local_5c == 4) {
      uStack_3c = 0;
      uStack_38 = 0;
      iStack_40 = 0;
      puVar4 = puVar5;
      uVar9 = uStack_3c;
      uVar7 = uStack_38;
    }
    else {
      if (local_5c == 2) {
        local_48 = 4;
        soft_double_pack_and_round(puVar5);
        return;
      }
      iStack_40 = iStack_40 - iStack_54;
      if ((uStack_38 < uStack_4c) || ((uStack_4c == uStack_38 && (uStack_3c < uStack_50)))) {
        iStack_40 = iStack_40 + -1;
        bVar1 = CARRY4(uStack_3c,uStack_3c);
        uStack_3c = uStack_3c * 2;
        uStack_38 = uStack_38 * 2 - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
      }
      uVar8 = 0;
      iVar10 = 0x3d;
      uVar3 = *PTR_DAT_0306f1a8;
      uVar6 = PTR_DAT_0306f1a8[1];
      uVar9 = 0;
      do {
        uVar11 = uStack_3c;
        uVar12 = uStack_38;
        if ((uStack_4c <= uStack_38) && ((uStack_4c != uStack_38 || (uStack_50 <= uStack_3c)))) {
          uVar11 = uStack_3c - uStack_50;
          uVar12 = (uStack_38 - uStack_4c) - (uStack_50 <= uStack_3c ^ 1);
        }
        uVar7 = uVar9;
        uVar2 = uVar8;
        if (((uStack_4c <= uStack_38) &&
            (uVar7 = uVar9 | uVar6, uVar2 = uVar8 | uVar3, uStack_4c == uStack_38)) &&
           (uStack_3c < uStack_50)) {
          uVar7 = uVar9;
          uVar2 = uVar8;
        }
        uVar8 = uVar2;
        uVar3 = uVar3 >> 1 | uVar6 << 0x1f;
        uVar6 = uVar6 >> 1;
        iVar10 = iVar10 + -1;
        uStack_3c = uVar11 * 2;
        uStack_38 = uVar12 * 2 - ((int)((uint)CARRY4(uVar11,uVar11) << 0x1f) >> 0x1f);
        uVar9 = uVar7;
      } while (iVar10 != 0);
      puVar4 = puVar5;
      uVar9 = uVar8;
      if ((((uVar8 & 0xff) == 0x80) && ((uVar8 & 0x100) == 0)) && (uStack_3c != 0 || uStack_38 != 0)
         ) {
        uVar9 = uVar8 + 0x80 & 0xffffff00;
        uVar7 = uVar7 - ((int)((uint)(0xffffff7f < uVar8) << 0x1f) >> 0x1f);
      }
    }
  }
  uStack_38 = uVar7;
  uStack_3c = uVar9;
  soft_double_pack_and_round(puVar4);
  return;
}

