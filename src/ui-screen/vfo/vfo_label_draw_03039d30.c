/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_label_draw @ 03039d30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 130 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_label_draw(int param_1)

{
  short y0;
  ushort fg;
  
  if (param_1 == 0) {
    fg = PTR_DAT_03039e24[(byte)p_dm32_settings_block04[0x66]];
    y0 = 0x62;
  }
  else {
    fg = PTR_DAT_03039e24[(byte)p_dm32_settings_block04[0x67]];
    y0 = 0xd8;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    display_fill_rect(10,0x81,0xe6,0x99,0);
    display_fill_rect(10,0x3b,0xe6,0x53,0);
    display_draw_number_centered(0x3b,fg,0,(uint)PTR_LAB_03039e30);
  }
  else {
    display_fill_rect(0,y0,0xf0,y0 + 0x10,0);
    display_draw_number_centered_dispatch(y0,fg,0,PTR_LAB_03039e30);
  }
  return;
}

