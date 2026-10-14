/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_indexed_u12_field_read @ 03056068 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined2 flash_indexed_u12_field_read(ushort param_1)

{
  ushort block_id;
  byte local_10;
  undefined1 uStack_f;
  
  if (param_1 < 0x800) {
    block_id = flash_block_id_resolve_locked(0x42);
  }
  else {
    block_id = flash_block_id_resolve_locked(0x43);
    param_1 = param_1 - 0x7ff;
  }
  flash_block_read(block_id,(uint)(ushort)((param_1 - 1) * 2),&local_10,2);
  return CONCAT11(local_10 >> 4,uStack_f);
}

