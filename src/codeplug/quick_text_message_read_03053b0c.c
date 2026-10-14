/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: quick_text_message_read @ 03053b0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void quick_text_message_read(uint param_1)

{
  ushort block_id;
  
  block_id = flash_block_id_resolve_locked(10);
  flash_block_read(block_id,(param_1 & 0xff) * 0x81 + 0x11 & 0xffff,PTR_DAT_03053cc8,0x80);
  return;
}

