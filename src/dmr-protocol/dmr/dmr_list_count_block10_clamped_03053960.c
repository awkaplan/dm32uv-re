/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_list_count_block10_clamped @ 03053960 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte dmr_list_count_block10_clamped(void)

{
  ushort block_id;
  byte bStack_9;
  
  block_id = flash_block_id_resolve_locked(10);
  bStack_9 = 0;
  flash_block_read(block_id,0,&bStack_9,1);
  if (0x14 < bStack_9) {
    bStack_9 = 0;
  }
  return bStack_9;
}

