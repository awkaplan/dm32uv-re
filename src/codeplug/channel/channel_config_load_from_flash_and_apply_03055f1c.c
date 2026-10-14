/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_config_load_from_flash_and_apply @ 03055f1c (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_config_load_from_flash_and_apply(uint param_1)

{
  ushort block_id;
  int iVar1;
  undefined1 *puVar2;
  undefined4 local_78;
  undefined1 auStack_74 [96];
  
  memset_ck803s(auStack_74,0,0x60);
  local_78 = 0;
  memset_bytes(auStack_74,0,0x60);
  set_call_setup_field_0xac(*PTR_DAT_03056024);
  if ((param_1 & 0xff) != 0) {
    block_id = flash_block_id_resolve_locked(0xf);
    flash_block_read(block_id,((param_1 & 0xff) - 1) * 0x6d + 0x1c & 0xffff,auStack_74,0x60);
  }
  puVar2 = auStack_74;
  iVar1 = 0;
  do {
    memcpy_bytes_iram(&local_78,puVar2,3);
    call_setup_sm_aux_field_0x2c_store(iVar1,local_78);
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 3;
  } while (iVar1 != 0x20);
  return;
}

