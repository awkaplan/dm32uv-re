/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_lock_status_or_band_select_screen @ 030390f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: gps
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gps_lock_status_or_band_select_screen(char param_1)

{
  if (*PTR_DAT_030391a0 == 0) {
    if ((p_radio_mode_state_0003e318->field_0x8 & 0x40) == 0) goto LAB_03039192;
  }
  else if ((p_radio_mode_state_0003e318->field_0x8 & 0x40) == 0) {
    if (param_1 != '\0') {
      display_clear_and_draw_fixed_region();
      display_blit_bitmap_1bpp(0x32,0x29,0x15,0x3f,PTR_LAB_030391a8,0xffff);
      display_blit_bitmap_1bpp(0x18,0x42,10,0x12,PTR_LAB_030391ac,0xffff);
      display_blit_bitmap_1bpp(0xce,0x42,10,0x12,PTR_LAB_030391b0,0xffff);
    }
    display_fill_rect(0x59,0x2c,0x6d,0x3c,0);
    display_draw_glyph_row_mutex(0x2c,0x59,DAT_030391b4,0xffff,0);
    display_draw_two_tone_progress_bar(0x40,0x10,*(undefined1 *)PTR_DAT_030391b8,0xe);
    return;
  }
  *PTR_DAT_030391a0 = 0;
LAB_03039192:
  band_range_select_screen();
  return;
}

