/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aprs_log_record_id_read @ 03062680 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 aprs_log_record_id_read(uint param_1)

{
  ushort block_id;
  undefined4 local_10;
  
  local_10 = 0;
  block_id = flash_block_id_resolve_locked(1);
  flash_block_read(block_id,(param_1 & 0xffff) * 0x50 + 0x10 & 0xfff0,&local_10,3);
  return local_10;
}

