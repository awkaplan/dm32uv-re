/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_frequency_read_decode @ 030308d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_frequency_read_decode(int param_1__w)

{
  undefined2 param_1 = (undefined2)param_1__w;
  undefined1 auStack_34 [32];
  undefined2 local_14;
  undefined1 local_12 [2];
  
  channel_num_to_block_offset(param_1,local_12,&local_14);
  flash_field_read_cached(local_12[0],local_14,auStack_34,0x20);
  bcd_frequency_decode(auStack_34,4);
  return;
}

