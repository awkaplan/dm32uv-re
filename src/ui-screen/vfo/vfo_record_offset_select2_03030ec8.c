/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_record_offset_select2 @ 03030ec8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_record_offset_select2(char param_1)

{
  short unaff_r5;
  byte local_11;
  
  if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      unaff_r5 = 0xfaf;
    }
    else {
      unaff_r5 = 0xfdf;
    }
  }
  flash_field_read_cached(0x41,unaff_r5 + 0x19,&local_11,1);
  local_11 = local_11 & 0xf | param_1 << 4;
  flash_field_write_cached(0x41,unaff_r5 + 0x19);
  return;
}

