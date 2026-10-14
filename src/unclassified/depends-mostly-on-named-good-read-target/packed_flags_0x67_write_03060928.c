/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: packed_flags_0x67_write @ 03060928 (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void packed_flags_0x67_write(void)

{
  byte local_8 [4];
  
  flash_field_read_cached(4,0x67,local_8,1);
  if ((*(byte *)PTR_DAT_030609a8 & 2) == 0) {
    local_8[0] = local_8[0] & 0xfb;
  }
  else {
    local_8[0] = local_8[0] | 4;
  }
  if ((*(byte *)PTR_DAT_030609a8 & 1) == 0) {
    local_8[0] = local_8[0] & 0xf7;
  }
  else {
    local_8[0] = local_8[0] | 8;
  }
  local_8[0] = local_8[0] & 0x3f | (*(byte *)PTR_DAT_030609a8 >> 2) << 6;
  flash_field_write_cached(4,0x67);
  return;
}

