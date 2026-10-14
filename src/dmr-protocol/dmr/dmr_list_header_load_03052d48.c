/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_list_header_load @ 03052d48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 dmr_list_header_load(char param_1)

{
  ushort block_id;
  undefined4 uVar1;
  undefined1 auStack_18 [16];
  
  if (param_1 == '\x03') {
    uVar1 = 8;
  }
  else if (param_1 == '\x05') {
    uVar1 = 9;
  }
  else {
    if (param_1 != '\x01') {
      return 0;
    }
    uVar1 = 7;
  }
  block_id = flash_block_id_resolve_locked(uVar1);
  flash_block_read(block_id,0,auStack_18,0xd);
  uVar1 = zero_bit_count_13byte_prefix(auStack_18);
  return uVar1;
}

