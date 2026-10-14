/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: frame_build_two_block_crc_encoded @ 03067c34 (file base 0x03000000; code starts at 0x03001000)
 * Size: 148 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: host-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int frame_build_two_block_crc_encoded
              (int param_1,undefined1 param_2,undefined1 param_3,uint param_4,undefined2 param_5,
              undefined2 param_6)

{
  undefined *puVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  
  puVar1 = PTR_LAB_03067e50;
  memcpy_bytes_iram(param_1,PTR_LAB_03067e50 + 8,3);
  memcpy_bytes_iram(param_1 + 3,puVar1,5);
  puVar4 = (undefined1 *)(param_1 + 8);
  *puVar4 = param_2;
  *(undefined1 *)(param_1 + 9) = param_3;
  *(char *)(param_1 + 10) = (char)((param_4 & 0xffff) >> 8);
  *(char *)(param_1 + 0xb) = (char)(param_4 & 0xffff);
  uVar2 = crc16_ccitt(puVar4,4);
  *(char *)(param_1 + 0xc) = (char)((ushort)uVar2 >> 8);
  *(char *)(param_1 + 0xd) = (char)uVar2;
  *(undefined1 *)(param_1 + 0xe) = 0;
  puVar4 = (undefined1 *)block7_parity_bit_interleave_encode(puVar4);
  iVar5 = (int)puVar4 - param_1;
  byte_bitplane_differential_xor_invert(param_1,iVar5);
  *puVar4 = (char)((ushort)param_5 >> 8);
  puVar4[1] = (char)param_5;
  puVar4[2] = (char)((ushort)param_6 >> 8);
  puVar4[3] = (char)param_6;
  uVar2 = crc16_ccitt(puVar4,4);
  puVar4[4] = (char)((ushort)uVar2 >> 8);
  puVar4[5] = (char)uVar2;
  puVar4[6] = 0;
  iVar3 = block7_parity_bit_interleave_encode(puVar4);
  iVar3 = (iVar3 - param_1) - iVar5;
  byte_bitplane_differential_xor_invert(param_1 + iVar5,iVar3);
  return iVar3 + iVar5;
}

