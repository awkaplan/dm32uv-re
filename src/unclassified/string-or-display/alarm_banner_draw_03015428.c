/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: alarm_banner_draw @ 03015428 (file base 0x03000000; code starts at 0x03001000)
 * Size: 118 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void alarm_banner_draw(int param_1__w,int param_2__w)

{
  char param_1 = (char)param_1__w;
  char param_2 = (char)param_2__w;
  short y0;
  
  if (p_dm32_settings_block04[0x6c] == '\0') {
    if (param_2 == '\0') {
      display_fill_rect(0x5a,0x81,0x96,0x99,0);
    }
    else {
      display_draw_string_gb2312(0x81,0x5a,PTR_s_ALARM_03015568,0xf800,0);
    }
  }
  else {
    if (param_1 == '\0') {
      y0 = 0x62;
    }
    else {
      y0 = 0xd8;
    }
    if (param_2 == '\0') {
      display_fill_rect(100,y0,0x8c,y0 + 0x10,0);
    }
    else {
      display_draw_glyph_row_mutex(y0,100,PTR_s_ALARM_03015568,0xf800,0);
    }
  }
  return;
}

