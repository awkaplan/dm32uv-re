/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_id_log_write @ 030560e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_id_log_write(ushort param_1,uint param_2)

{
  ushort block_id;
  uint offset;
  undefined4 uVar1;
  undefined1 auStack_30 [19];
  undefined1 auStack_1d [3];
  char cStack_1a;
  byte local_18;
  undefined1 uStack_17;
  
  param_2 = param_2 & 0xffff;
  if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
    block_id = flash_block_id_resolve_locked(0x43);
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      offset = 0xffa;
    }
    else {
      offset = 0xffc;
    }
    uVar1 = 0x43;
  }
  else {
    if (param_1 < 0x800) {
      block_id = flash_block_id_resolve_locked(0x42);
      uVar1 = 0x42;
    }
    else {
      param_1 = param_1 - 0x7ff;
      block_id = flash_block_id_resolve_locked(0x43);
      uVar1 = 0x43;
    }
    offset = (uint)(ushort)((param_1 - 1) * 2);
  }
  flash_block_read(block_id,offset,&local_18,2);
  uStack_17 = (undefined1)param_2;
  local_18 = local_18 & 0xf | (byte)((param_2 >> 8) << 4) | 1;
  flash_block_write(uVar1,offset,&local_18,2);
  record_read_by_index(param_2,auStack_30);
  *PTR_DAT_030561b0 = 0;
  if (cStack_1a == '\x04') {
    memcpy_bytes_iram(PTR_DAT_030561b0,auStack_1d,3);
  }
  set_call_setup_field_0xac(*PTR_DAT_030561b0);
  return;
}

