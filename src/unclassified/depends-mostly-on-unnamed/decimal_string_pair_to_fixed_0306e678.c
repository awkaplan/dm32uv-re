/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: decimal_string_pair_to_fixed @ 0306e678 (file base 0x03000000; code starts at 0x03001000)
 * Size: 232 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void decimal_string_pair_to_fixed(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_38;
  uint uStack_34;
  int iStack_30;
  uint uStack_2c;
  uint local_28;
  uint uStack_24;
  int iStack_20;
  uint uStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar2 = &local_28;
  local_18 = param_2;
  local_14 = param_1;
  float32_unpack(&local_14,puVar2);
  float32_unpack(&local_18,&local_38);
  puVar1 = puVar2;
  uVar4 = uStack_1c;
  if ((1 < local_28) && (puVar1 = &local_38, 1 < local_38)) {
    uStack_24 = uStack_24 ^ uStack_34;
    if ((local_28 == 4) || (local_28 == 2)) {
      if (local_28 == local_38) {
        puVar2 = PTR_DAT_0306e760;
      }
      float32_pack_round(puVar2);
      return;
    }
    if (local_38 == 4) {
      uStack_1c = 0;
      iStack_20 = 0;
      puVar1 = puVar2;
      uVar4 = uStack_1c;
    }
    else {
      if (local_38 == 2) {
        local_28 = 4;
        float32_pack_round(puVar2);
        return;
      }
      iStack_20 = iStack_20 - iStack_30;
      if (uStack_1c < uStack_2c) {
        iStack_20 = iStack_20 + -1;
        uStack_1c = uStack_1c * 2;
      }
      iVar5 = 0x1f;
      uVar3 = 0x40000000;
      uVar4 = 0;
      do {
        if (uStack_2c <= uStack_1c) {
          uVar4 = uVar4 | uVar3;
          uStack_1c = uStack_1c - uStack_2c;
        }
        iVar5 = iVar5 + -1;
        uVar3 = uVar3 >> 1;
        uStack_1c = uStack_1c * 2;
      } while (iVar5 != 0);
      puVar1 = puVar2;
      if ((((uVar4 & 0x7f) == 0x40) && ((uVar4 & 0x80) == 0)) && (uStack_1c != 0)) {
        uVar4 = uVar4 + 0x40 & 0xffffff80;
      }
    }
  }
  uStack_1c = uVar4;
  float32_pack_round(puVar1);
  return;
}

