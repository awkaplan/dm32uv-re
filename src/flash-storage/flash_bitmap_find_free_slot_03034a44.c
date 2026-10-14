/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_bitmap_find_free_slot @ 03034a44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 162 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 flash_bitmap_find_free_slot(short *param_1)

{
  ushort uVar1;
  ushort uVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  byte local_2c [8];
  
  uVar1 = flash_block_id_resolve_locked(0xb);
  uVar5 = 0x10;
  sVar6 = 0;
  while (flash_block_read(uVar1,uVar5,local_2c,8), local_2c[0] == 0) {
    iVar4 = 0;
    uVar2 = 1;
    pbVar3 = local_2c;
    do {
      pbVar3 = pbVar3 + 1;
      iVar4 = iVar4 + 1;
      if (*pbVar3 != 0) goto LAB_03034a8c;
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 != 8);
    sVar6 = sVar6 + 8;
    uVar5 = uVar5 + 8;
    if (sVar6 == 0x70) {
      return 0;
    }
  }
  iVar4 = 0;
  uVar2 = 0;
LAB_03034a8c:
  uVar5 = (uint)local_2c[iVar4];
  if ((local_2c[iVar4] & 1) == 0) {
    uVar1 = 1;
    do {
      uVar5 = uVar5 >> 1;
      if ((uVar5 & 1) != 0) break;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 != 8);
  }
  else {
    uVar1 = 0;
  }
  *param_1 = uVar1 + (uVar2 + sVar6) * 8 + 1;
  return 1;
}

