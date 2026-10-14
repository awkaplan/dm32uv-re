/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_number_centered_then_settings_duration_seconds_display_call_030491dc @ 030491dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_number_centered_then_settings_duration_seconds_display_call_030491dc(void)

{
  display_draw_number_centered
            (100,0,0x7e0,
             *(uint *)(PTR_PTR_030492a8[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 8));
  settings_duration_seconds_display_call(*(undefined1 *)p_active_screen_state_word);
  return;
}

