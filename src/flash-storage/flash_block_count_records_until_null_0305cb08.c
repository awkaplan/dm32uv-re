/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_count_records_until_null @ 0305cb08 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char flash_block_count_records_until_null(void)

{
  ushort block_id;
  uint offset;
  char cVar1;
  char local_1c [4];
  
  block_id = flash_block_id_resolve_locked(0x10);
  offset = 0x300;
  cVar1 = '\0';
  do {
    flash_block_read(block_id,offset,local_1c,1);
    if (local_1c[0] == '\0') {
      return cVar1;
    }
    cVar1 = cVar1 + '\x01';
    offset = offset + 0x2c;
  } while (cVar1 != ' ');
  return ' ';
}

