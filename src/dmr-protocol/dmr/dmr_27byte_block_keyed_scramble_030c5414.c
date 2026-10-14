/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_27byte_block_keyed_scramble @ 030c5414 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_27byte_block_keyed_scramble(int param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  
  param_1 = param_1 + (param_3 & 0xff) * 0x15;
  iVar2 = 0;
  do {
    *(byte *)(param_2 + iVar2) = *(byte *)(param_2 + iVar2) ^ *(byte *)(param_1 + iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 7);
  *(byte *)(param_2 + 6) = *(byte *)(param_2 + 6) & 0x80;
  pbVar1 = (byte *)(param_1 + 7);
  iVar2 = 9;
  do {
    *(byte *)(param_2 + iVar2) = *(byte *)(param_2 + iVar2) ^ *pbVar1;
    iVar2 = iVar2 + 1;
    pbVar1 = pbVar1 + 1;
  } while (iVar2 != 0x10);
  *(byte *)(param_2 + 0xf) = *(byte *)(param_2 + 0xf) & 0x80;
  pbVar1 = (byte *)(param_1 + 0xe);
  iVar2 = 0x12;
  do {
    *(byte *)(param_2 + iVar2) = *(byte *)(param_2 + iVar2) ^ *pbVar1;
    iVar2 = iVar2 + 1;
    pbVar1 = pbVar1 + 1;
  } while (iVar2 != 0x19);
  *(byte *)(param_2 + 0x18) = *(byte *)(param_2 + 0x18) & 0x80;
  dmr_27byte_block_transform_three_chunks_thunk(param_2);
  func_0x060d1774(param_2,0x1b,1);
  return;
}

