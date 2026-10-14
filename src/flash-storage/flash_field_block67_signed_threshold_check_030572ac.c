/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field_block67_signed_threshold_check @ 030572ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int flash_field_block67_signed_threshold_check(uint param_1)

{
  int local_c;
  
  local_c = 0;
  flash_field_read_cached(0x67,((param_1 & 0xff) + 1) * 0x10,&local_c,3);
  if (0xfffcde < local_c - 1U) {
    local_c = 1;
  }
  return local_c;
}

