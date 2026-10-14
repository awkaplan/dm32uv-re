/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ones_complement_checksum_32word @ 030c7254 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint ones_complement_checksum_32word(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (0 < (int)param_2) {
    uVar4 = 0;
    iVar2 = 0;
    iVar5 = 0;
    do {
      uVar3 = *(uint *)(param_1 + iVar2);
      bVar1 = CARRY4(uVar4,uVar3);
      uVar4 = uVar4 + uVar3;
      iVar5 = (iVar5 + ((int)uVar3 >> 0x1f)) - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
      iVar2 = iVar2 + 4;
    } while (iVar2 != (((param_2 & 0xffff) - 1 & 0xffff) + 1) * 4);
    return iVar5 * 0x20000000 | uVar4 >> 3;
  }
  return 0;
}

