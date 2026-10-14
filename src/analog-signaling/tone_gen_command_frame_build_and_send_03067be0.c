/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_gen_command_frame_build_and_send @ 03067be0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int tone_gen_command_frame_build_and_send
              (int param_1,undefined1 param_2,undefined1 param_3,uint param_4)

{
  undefined *puVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  
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
  iVar3 = block7_parity_bit_interleave_encode(puVar4);
  byte_bitplane_differential_xor_invert(param_1,iVar3 - param_1);
  return iVar3 - param_1;
}

