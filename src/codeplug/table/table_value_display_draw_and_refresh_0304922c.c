/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_value_display_draw_and_refresh @ 0304922c (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void table_value_display_draw_and_refresh(void)

{
  display_draw_number_centered
            (100,0,0x7e0,
             *(uint *)(PTR_PTR_030492b4[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                      (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_030492b0 + 2) * 4))
  ;
  display_fill_rect_then_display_draw_number_centered(*(undefined1 *)p_active_screen_state_word);
  return;
}

