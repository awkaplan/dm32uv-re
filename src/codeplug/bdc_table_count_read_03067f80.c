/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bdc_table_count_read @ 03067f80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort bdc_table_count_read(void)

{
  ushort block_id;
  ushort local_a;
  
  block_id = flash_block_id_resolve_locked(6);
  flash_block_read(block_id,0xa90,&local_a,2);
  if (0x40 < local_a) {
    local_a = 0;
  }
  return local_a;
}

