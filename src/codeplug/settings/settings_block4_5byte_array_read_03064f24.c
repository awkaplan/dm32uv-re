/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_block4_5byte_array_read @ 03064f24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_block4_5byte_array_read(uint param_1,void *param_2)

{
  ushort block_id;
  
  if ((param_1 & 0xff) < 5) {
    block_id = flash_block_id_resolve_locked(4);
    flash_block_read(block_id,(param_1 & 0xff) * 5 + 0x200,param_2,5);
  }
  else {
    memset_bytes(param_2,0,5);
  }
  return;
}

