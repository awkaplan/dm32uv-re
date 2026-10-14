/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_list_index_resolve_then_channel_frequency_read_decode @ 030309b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 16 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_list_index_resolve_then_channel_frequency_read_decode
               (undefined1 param_1,undefined1 param_2)

{
  channel_list_index_resolve(param_1,param_2);
  channel_frequency_read_decode();
  return;
}

