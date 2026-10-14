/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_active_side_icon_draw @ 0301ab54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_active_side_icon_draw(char param_1)

{
  short y0;
  undefined4 uVar1;
  
  if (p_dm32_settings_block04[0x6c] != '\0') {
    if (param_1 == '\0') {
      y0 = 0x98;
      uVar1 = 0x22;
    }
    else {
      y0 = 0x22;
      uVar1 = 0x98;
    }
    display_fill_rect(10,y0,0x13,y0 + 0x11,0);
    display_blit_bitmap_1bpp(10,uVar1,9,0x22,PTR_LAB_0301ac04,0xf800);
  }
  return;
}

