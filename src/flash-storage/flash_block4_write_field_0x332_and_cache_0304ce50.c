/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block4_write_field_0x332_and_cache @ 0304ce50 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_block4_write_field_0x332_and_cache(undefined4 param_1)

{
  undefined4 local_c;
  
  local_c = param_1;
  flash_block_write(4,0x332,&local_c,3);
  PTR_DAT_0304cf2c[2] = local_c;
  return;
}

