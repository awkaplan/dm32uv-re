/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: read_channel_field_from_flash @ 030309c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: accessors
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void read_channel_field_from_flash(undefined1 param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 local_14 [2];
  undefined2 local_12;
  
  if (param_2 == 0) {
    uVar1 = *p_dm32_settings_block04;
  }
  else {
    uVar1 = p_dm32_settings_block04[0x13];
  }
  uVar2 = channel_list_index_resolve(uVar1,param_1);
  channel_offset_from_num(uVar2,local_14,&local_12);
  flash_field_read_cached(local_14[0],local_12,param_3,0x10);
  *(undefined1 *)(param_3 + 0x10) = 0;
  return;
}

