/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field_read_signed_select @ 0301b65c (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined1 flash_field_read_signed_select(undefined4 param_1,ushort param_2)

{
  ushort block_id;
  undefined1 local_9;
  
  block_id = flash_block_id_resolve_locked(2);
  if (param_2 < 0xd000) {
    if ((short)param_2 < 0) {
      flash_block_read(block_id,0x202,&local_9,1);
    }
    else {
      flash_block_read(block_id,0x201,&local_9,1);
    }
  }
  else {
    local_9 = 0;
  }
  return local_9;
}

