/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_name_lookup_or_format @ 03034d58 (file base 0x03000000; code starts at 0x03001000)
 * Size: 154 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool contact_name_lookup_or_format
               (undefined4 param_1,undefined4 param_2,void *param_3,undefined1 param_4)

{
  bool bVar1;
  ushort block_id;
  undefined4 uVar2;
  byte local_21;
  ushort local_20;
  ushort local_1e;
  
  uVar2 = get_block0xb_u16_field0();
  local_21 = 0;
  block_id = flash_block_id_resolve_locked(0xb);
  local_21 = talkgroup_binary_search_by_id_and_flag(param_2,&local_20,uVar2,param_4);
  bVar1 = local_21 == 0;
  if (bVar1) {
    number_to_string_format_2args(param_3,PTR_s__d_030afae0_8_03034f4c,param_2);
  }
  else {
    flash_block_read(block_id,(uint)(ushort)((local_20 + 0x39f) * 2),&local_20,2);
    local_20 = local_20 & 0xfff;
    talkgroup_index_decode_paged(local_20,&local_1e,&local_21);
    local_1e = flash_block_id_resolve_locked((undefined1)local_1e);
    flash_block_read(local_1e,(local_21 - 1) * 0x18 + 2 & 0xfffe,param_3,0x10);
    *(undefined1 *)((int)param_3 + 0x10) = 0;
  }
  return !bVar1;
}

