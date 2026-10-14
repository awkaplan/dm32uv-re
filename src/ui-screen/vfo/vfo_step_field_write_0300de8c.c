/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_step_field_write @ 0300de8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_step_field_write(uint param_1)

{
  vfo_display_state *pvVar1;
  undefined2 uVar2;
  short local_1a;
  undefined1 local_18 [3];
  byte local_15;
  
  vfo_record_offset_select3(local_18,&local_1a);
  flash_field_read_cached(local_18[0],local_1a + 0xc,&local_15,1);
  pvVar1 = p_vfo_display_state;
  local_15 = local_15 & 0xf | (byte)((param_1 & 0xf) << 4);
  p_vfo_display_state->field_0xc =
       p_vfo_display_state->field_0xc & 0xf | (byte)((param_1 & 0xf) << 4);
  flash_field_write_cached(local_18[0],local_1a + 0xc);
  uVar2 = channel_step_frequency_bound_check
                    (*(undefined4 *)pvVar1,pvVar1->field_0xc >> 4,pvVar1->flags_0x9 >> 7);
  PTR_DAT_0300df4c[1] = uVar2;
  hw_register_0x78_write_from_byte_pair();
  return;
}

