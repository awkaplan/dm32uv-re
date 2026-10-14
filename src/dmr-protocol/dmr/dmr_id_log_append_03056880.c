/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_id_log_append @ 03056880 (file base 0x03000000; code starts at 0x03001000)
 * Size: 126 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_id_log_append(char param_1,uint param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined1 auStack_a0 [128];
  short local_20;
  undefined1 local_1e [2];
  
  channel_offset_minus_0x10(param_1 + '\x01',local_1e,&local_20);
  flash_field_read_cached(local_1e[0],local_20 + 0x11,auStack_a0,0x80);
  puVar2 = PTR_DAT_030569c4;
  bVar1 = *(byte *)PTR_DAT_030569c4;
  auStack_a0[(uint)bVar1 * 2] = (char)(param_2 & 0xffff);
  auStack_a0[(uint)bVar1 * 2 + 1] = (char)((param_2 & 0xffff) >> 8);
  flash_block_write(local_1e[0],local_20 + 0x11,auStack_a0,0x80);
  *(char *)puVar2 = *(char *)puVar2 + '\x01';
  flash_block_write(local_1e[0],local_20 + 0x10,puVar2,1);
  contact_record_copy_with_limit((byte)p_dm32_settings_block04[0x2d] >> 7);
  vfo_load_side_config();
  return;
}

