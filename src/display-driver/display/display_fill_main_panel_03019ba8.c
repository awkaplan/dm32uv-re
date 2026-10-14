/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_fill_main_panel @ 03019ba8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_fill_main_panel(void)

{
  short y0;
  short y1;
  
  if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
    y1 = 0xea;
    y0 = 0x98;
  }
  else {
    y1 = 0x74;
    y0 = 0x22;
  }
  display_fill_rect(8,y0,0xe6,y1,0);
  return;
}

