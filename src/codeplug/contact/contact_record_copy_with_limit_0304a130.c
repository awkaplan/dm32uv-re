/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_record_copy_with_limit @ 0304a130 (file base 0x03000000; code starts at 0x03001000)
 * Size: 206 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void contact_record_copy_with_limit(int param_1)

{
  undefined4 *puVar1;
  ushort uVar2;
  ushort local_18;
  undefined1 local_16 [2];
  
  puVar1 = p_dm32_settings_block04;
  channel_offset_minus_0x10(*(undefined1 *)p_dm32_settings_block04,local_16,&local_18);
  uVar2 = flash_block_id_resolve_locked(local_16[0]);
  flash_block_read(uVar2,(uint)(ushort)(local_18 + 0x10),(void *)((int)puVar1 + 0x12),1);
  if (0x40 < *(byte *)((int)puVar1 + 0x12)) {
    *(undefined1 *)((int)puVar1 + 0x12) = 1;
  }
  puVar1 = PTR_DAT_0304a2c0;
  flash_block_read(uVar2,(uint)local_18,PTR_DAT_0304a2c0,0x10);
  *(undefined1 *)(puVar1 + 4) = 0;
  channel_offset_minus_0x10(*(undefined1 *)((int)puVar1 + 0x12),local_16,&local_18);
  uVar2 = flash_block_id_resolve_locked(local_16[0]);
  flash_block_read(uVar2,(uint)(ushort)(local_18 + 0x10),puVar1 + 9,1);
  if (0x40 < *(byte *)(puVar1 + 9)) {
    *(undefined1 *)((int)p_dm32_settings_block04 + 0x25) = 1;
  }
  puVar1 = PTR_DAT_0304a2c4;
  flash_block_read(uVar2,(uint)local_18,PTR_DAT_0304a2c4,0x10);
  *(undefined1 *)(puVar1 + 4) = 0;
  puVar1 = p_dm32_settings_block04;
  if (param_1 == 0) {
    *(undefined1 *)((int)p_dm32_settings_block04 + 0x29) = *(undefined1 *)p_dm32_settings_block04;
    *(undefined1 *)(puVar1 + 0xb) = *(undefined1 *)((int)puVar1 + 0x12);
  }
  else {
    *(undefined1 *)((int)p_dm32_settings_block04 + 0x29) =
         *(undefined1 *)((int)p_dm32_settings_block04 + 0x13);
    *(undefined1 *)(puVar1 + 0xb) = *(undefined1 *)((int)puVar1 + 0x25);
  }
  return;
}

