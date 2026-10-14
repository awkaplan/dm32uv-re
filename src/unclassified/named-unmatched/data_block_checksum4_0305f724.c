/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: data_block_checksum4 @ 0305f724 (file base 0x03000000; code starts at 0x03001000)
 * Size: 180 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void data_block_checksum4(byte *param_1,byte *param_2)

{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  puVar1 = PTR_LAB_0305f8c0;
  pbVar2 = param_1 + 1;
  *param_2 = param_1[2] & param_1[3] ^ param_1[4] ^ *pbVar2 |
             *param_1 ^ *(byte *)PTR_LAB_0305f8c0 | param_1[5];
  pbVar3 = param_1 + 7;
  param_2[1] = param_1[6] ^ *pbVar3 ^ *(byte *)((int)puVar1 + 1) ^ param_1[8] ^ param_1[9] ^
               param_1[10] ^ param_1[0xb];
  param_2[2] = *pbVar3 & param_1[3] ^ param_1[9] ^ *pbVar2 |
               *(byte *)((int)puVar1 + 2) ^ param_1[6] | param_1[5];
  param_2[3] = *pbVar3 ^ param_1[2] ^ *(byte *)((int)puVar1 + 3) ^ param_1[10] ^ *pbVar2;
  return;
}

