/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: softfloat32_mul @ 0306e564 (file base 0x03000000; code starts at 0x03001000)
 * Size: 272 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

float softfloat32_mul(float a,float b)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  uint uVar5;
  undefined4 local_48;
  uint uStack_44;
  int iStack_40;
  uint uStack_3c;
  uint local_38;
  uint uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  uint local_28;
  uint uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  float local_18;
  float local_14;
  undefined4 *puVar4;
  
  local_18 = b;
  local_14 = a;
  float32_unpack(&local_14,&local_28);
  float32_unpack(&local_18,&local_38);
  if (1 < local_28) {
    if (local_38 < 2) {
LAB_0306e656:
      uStack_34 = (uint)(uStack_24 != uStack_34);
      fVar3 = (float)float32_pack_round(&local_38);
      return fVar3;
    }
    puVar4 = (undefined4 *)DAT_0306e674;
    if (local_28 == 4) {
      if (local_38 != 2) goto LAB_0306e640;
    }
    else if (local_38 == 4) {
      if (local_28 != 2) goto LAB_0306e656;
    }
    else {
      if (local_28 == 2) goto LAB_0306e640;
      if (local_38 == 2) goto LAB_0306e656;
      uVar5 = 0;
      uVar1 = umul32_to_64(uStack_2c,0,uStack_1c,0);
      uStack_44 = (uint)(uStack_24 != uStack_34);
      iStack_40 = iStack_30 + iStack_20 + 2;
      if ((int)uVar5 < 0) {
        iStack_40 = iStack_30 + iStack_20 + 3;
        if ((uVar5 & 1) != 0) {
          uVar1 = uVar1 >> 1 | 0x80000000;
        }
        uVar5 = uVar5 >> 1;
      }
      if (uVar5 < 0x40000000) {
        do {
          while( true ) {
            uVar2 = uVar1;
            uVar5 = uVar5 * 2;
            iStack_40 = iStack_40 + -1;
            if (-1 < (int)uVar2) break;
            uVar5 = uVar5 | 1;
            uVar1 = uVar2 * 2;
            if (0x3fffffff < uVar5) goto LAB_0306e600;
          }
          uVar1 = uVar2 * 2;
        } while (uVar5 < 0x40000000);
LAB_0306e600:
        uVar1 = uVar2 * 2;
      }
      if ((((uVar5 & 0x7f) == 0x40) && ((uVar5 & 0x80) == 0)) && (uVar1 != 0)) {
        uVar5 = uVar5 + 0x40 & 0xffffff80;
      }
      local_48 = 3;
      puVar4 = &local_48;
      uStack_3c = uVar5;
    }
    fVar3 = (float)float32_pack_round(puVar4);
    return fVar3;
  }
LAB_0306e640:
  uStack_24 = (uint)(uStack_24 != uStack_34);
  fVar3 = (float)float32_pack_round(&local_28);
  return fVar3;
}

