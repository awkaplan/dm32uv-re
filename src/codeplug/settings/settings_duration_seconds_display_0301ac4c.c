/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_duration_seconds_display @ 0301ac4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_duration_seconds_display(int param_1__w)

{
  short param_1 = (short)param_1__w;
  display_fill_rect(0x14,0x82,0xdc,0x9a,0x7e0);
  if (param_1 == 0) {
    display_draw_number_centered
              (0x82,0,0x7e0,
               *(uint *)(PTR_PTR_0301adf4[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 4));
  }
  else {
    display_draw_number_centered(0x82,0,0x7e0,(uint)PTR_s__d_S__0301adec);
  }
  return;
}

