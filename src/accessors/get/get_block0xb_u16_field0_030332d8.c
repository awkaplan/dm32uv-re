/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: get_block0xb_u16_field0 @ 030332d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: accessors
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

ushort get_block0xb_u16_field0(void)

{
  ushort block_id;
  ushort local_a;
  
  local_a = 0;
  block_id = flash_block_id_resolve_locked(0xb);
  flash_block_read(block_id,0,&local_a,2);
  if (800 < local_a) {
    local_a = 0;
  }
  return local_a;
}

