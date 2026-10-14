/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block11_indexed_u16_read @ 03034df4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined2 flash_block11_indexed_u16_read(short param_1)

{
  ushort block_id;
  undefined2 uStack_a;
  
  block_id = flash_block_id_resolve_locked(0xb);
  flash_block_read(block_id,(uint)(ushort)((param_1 + 0x7f) * 2),&uStack_a,2);
  return uStack_a;
}

