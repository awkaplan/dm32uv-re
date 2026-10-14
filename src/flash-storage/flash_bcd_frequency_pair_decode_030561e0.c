/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_bcd_frequency_pair_decode @ 030561e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_bcd_frequency_pair_decode(undefined2 param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [24];
  undefined1 local_18 [2];
  undefined2 local_16;
  
  local_16 = 0;
  channel_num_to_block_offset(param_1,local_18,&local_16);
  flash_field_read_cached(local_18[0],local_16,auStack_38,0x20);
  memcpy_bytes_iram(param_2 + 8,auStack_30,0x17);
  uVar1 = bcd_frequency_decode(auStack_38,4);
  *param_2 = (char)uVar1;
  param_2[1] = (char)((uint)uVar1 >> 8);
  param_2[2] = (char)((uint)uVar1 >> 0x10);
  param_2[3] = (char)((uint)uVar1 >> 0x18);
  uVar1 = bcd_frequency_decode(auStack_34,4);
  param_2[4] = (char)uVar1;
  param_2[5] = (char)((uint)uVar1 >> 8);
  param_2[6] = (char)((uint)uVar1 >> 0x10);
  param_2[7] = (char)((uint)uVar1 >> 0x18);
  return;
}

