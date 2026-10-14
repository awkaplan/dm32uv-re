/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_field_write_3bit_at_0x16 @ 030310a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_field_write_3bit_at_0x16(char param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  short local_1a;
  undefined1 local_18 [3];
  byte local_15;
  
  vfo_record_offset_select3(local_18,&local_1a);
  flash_field_read_cached(local_18[0],local_1a + 0x16,&local_15,1);
  if (param_1 == '\0') {
    bVar2 = local_15 & 0x8f | (param_2 & 7) << 4;
  }
  else {
    bVar1 = (param_2 & 7) * '\x02';
    bVar2 = bVar1 | local_15 & 0xf1;
    if ((param_2 & 7) != (p_vfo_display_state->field_0x16 >> 1 & 7)) {
      p_vfo_display_state->field_0x16 = p_vfo_display_state->field_0x16 & 0x8f;
      bVar2 = bVar1 | local_15 & 0x81;
    }
  }
  local_15 = bVar2;
  flash_field_write_cached(local_18[0],local_1a + 0x16,local_15);
  return;
}

