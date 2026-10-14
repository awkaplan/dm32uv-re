/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_clear_status_row_at_y_by_flag @ 0301a494 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_clear_status_row_at_y_by_flag(char param_1)

{
  short y0;
  
  if (param_1 == '\0') {
    y0 = 0x22;
  }
  else {
    y0 = 0x98;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    y0 = 0x22;
  }
  display_fill_rect(0xc3,y0,0xe5,y0 + 0x10,0);
  return;
}

