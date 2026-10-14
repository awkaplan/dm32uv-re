/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_unpack @ 0306fb30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 198 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: math-softfloat
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void soft_double_unpack(uint *param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = *param_1;
  uVar5 = param_1[1];
  param_2[1] = uVar5 >> 0x1f;
  uVar6 = uVar5 >> 0x14 & 0x7ff;
  uVar4 = uVar4 & *PTR_DAT_0306fbf8;
  uVar5 = uVar5 & PTR_DAT_0306fbf8[1];
  if (uVar6 == 0) {
    if (uVar4 != 0 || uVar5 != 0) {
      uVar5 = uVar5 << 8 | uVar4 >> 0x18;
      uVar4 = uVar4 << 8;
      param_2[2] = 0xfffffc02;
      *param_2 = 3;
      if (uVar5 < 0x10000000) {
        uVar6 = 0xfffffc01;
        do {
          uVar2 = uVar6;
          bVar1 = CARRY4(uVar4,uVar4);
          uVar4 = uVar4 * 2;
          uVar5 = uVar5 * 2 - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
          uVar6 = uVar2 - 1;
        } while (uVar5 < 0x10000000);
        param_2[2] = uVar2;
      }
      param_2[3] = uVar4;
      param_2[4] = uVar5;
      return;
    }
    *param_2 = 2;
    return;
  }
  if (uVar6 != 0x7ff) {
    uVar3 = PTR_DAT_0306fbfc[1];
    uVar2 = *PTR_DAT_0306fbfc;
    param_2[2] = uVar6 - 0x3ff;
    *param_2 = 3;
    param_2[3] = uVar4 << 8 | uVar2;
    param_2[4] = uVar5 << 8 | uVar4 >> 0x18 | uVar3;
    return;
  }
  if (uVar4 != 0 || uVar5 != 0) {
    *param_2 = (uint)((*PTR_DAT_0306fc00 & uVar4) != 0 || (PTR_DAT_0306fc00[1] & uVar5) != 0);
    param_2[3] = uVar4;
    param_2[4] = uVar5;
    return;
  }
  *param_2 = 4;
  return;
}

