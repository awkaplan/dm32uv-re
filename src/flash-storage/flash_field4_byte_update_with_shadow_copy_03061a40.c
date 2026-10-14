/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field4_byte_update_with_shadow_copy @ 03061a40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_field4_byte_update_with_shadow_copy(byte param_1)

{
  byte local_d;
  
  flash_field_read_cached(4,0x45,&local_d,1);
  local_d = (param_1 & 3) * '\x02' | local_d & 0xf9;
  flash_field_write_cached(4,0x45);
  PTR_DAT_03061b08[0x2b] = PTR_DAT_03061b08[0x2b] & 0xf | param_1 << 4;
  write_byte_field_030212dc();
  return;
}

