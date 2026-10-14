/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block4_write_offset0x700_u16 @ 03065904 (file base 0x03000000; code starts at 0x03001000)
 * Size: 18 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_block4_write_offset0x700_u16(undefined4 param_1)

{
  flash_block_write(4,0x700,param_1,2);
  return;
}

