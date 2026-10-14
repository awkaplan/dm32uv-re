/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_field_write_bit7_at_0x9 @ 03030fbc (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_field_write_bit7_at_0x9(char param_1)

{
  short local_1a;
  undefined1 local_18 [3];
  byte local_15;
  
  vfo_record_offset_select3(local_18,&local_1a);
  flash_field_read_cached(local_18[0],local_1a + 9,&local_15,1);
  local_15 = param_1 << 7 | local_15 & 0x7f;
  flash_field_write_cached(local_18[0],local_1a + 9);
  return;
}

