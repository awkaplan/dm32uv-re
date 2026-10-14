/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_list_index_write @ 03066ea4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_list_index_write(void)

{
  undefined1 *puVar1;
  byte local_c;
  undefined1 uStack_b;
  
  puVar1 = PTR_DAT_03066efc;
  flash_block_write(3,0x30,PTR_DAT_03066efc,5);
  flash_field_read_cached(3,0x3f,&local_c,2);
  if ((puVar1[6] & 1) == 0) {
    local_c = local_c & 0xfd;
  }
  else {
    local_c = local_c | 2;
  }
  uStack_b = PTR_DAT_03066efc[5];
  flash_block_write(3,0x3f,&local_c,2);
  return;
}

