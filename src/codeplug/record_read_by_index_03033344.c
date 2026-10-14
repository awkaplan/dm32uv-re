/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: record_read_by_index @ 03033344 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void record_read_by_index(undefined2 param_1,void *param_2)

{
  ushort local_14;
  byte local_11;
  
  talkgroup_index_decode_paged(param_1,&local_14,&local_11);
  local_14 = flash_block_id_resolve_locked((undefined1)local_14);
  flash_block_read(local_14,(local_11 - 1) * 0x18 & 0xfff8,param_2,0x18);
  return;
}

