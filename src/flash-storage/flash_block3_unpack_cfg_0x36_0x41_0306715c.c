/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block3_unpack_cfg_0x36_0x41 @ 0306715c (file base 0x03000000; code starts at 0x03001000)
 * Size: 200 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_block3_unpack_cfg_0x36_0x41(void)

{
  byte bVar1;
  undefined2 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bStack_1c;
  undefined2 uStack_1b;
  undefined2 uStack_19;
  undefined2 uStack_17;
  undefined2 uStack_15;
  byte bStack_13;
  
  pbVar4 = &bStack_1c;
  flash_field_read_cached(3,0x36,&bStack_1c,0xf);
  puVar2 = PTR_DAT_0306733c;
  PTR_DAT_0306733c[6] = uStack_1b;
  puVar2[7] = uStack_19;
  puVar2[8] = uStack_17;
  puVar2[9] = uStack_15;
  if ((bStack_13 & 1) == 0) {
    *(byte *)(PTR_DAT_0306733c + 0x10) = *(byte *)(PTR_DAT_0306733c + 0x10) & 0xfe;
  }
  else {
    *(byte *)(PTR_DAT_0306733c + 0x10) = *(byte *)(PTR_DAT_0306733c + 0x10) & 0xfe | 1;
  }
  flash_field_read_cached(3,0x41,&bStack_1c,0x10);
  pbVar3 = (byte *)PTR_DAT_0306733c;
  do {
    bVar1 = *pbVar4;
    pbVar3[0x14] = bVar1;
    pbVar3[0x18] = pbVar4[1];
    pbVar3[0x1c] = pbVar4[2] & 1;
    *pbVar3 = bVar1 >> 4;
    pbVar3[4] = bVar1 & 0xf;
    pbVar4 = pbVar4 + 4;
    pbVar3 = pbVar3 + 1;
  } while (pbVar4 != &stack0xfffffff4);
  return;
}

