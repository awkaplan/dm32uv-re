/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_record_offset_select1 @ 03031004 (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_record_offset_select1(byte param_1)

{
  undefined4 uVar1;
  byte local_11;
  
  if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
    uVar1 = 0xfb9;
  }
  else {
    uVar1 = 0xfe9;
  }
  flash_field_read_cached(0x41,uVar1,&local_11,1);
  local_11 = local_11 & 0xfc | param_1 & 3;
  flash_field_write_cached(0x41,uVar1);
  return;
}

