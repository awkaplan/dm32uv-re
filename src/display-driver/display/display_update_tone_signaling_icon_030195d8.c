/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_update_tone_signaling_icon @ 030195d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 166 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_update_tone_signaling_icon(char param_1)

{
  int iVar1;
  short y0;
  
  iVar1 = get_current_mode_state1();
  if (iVar1 == 0) {
    if ((PTR_DAT_03019758[1] & 1) == 0) {
      y0 = 0x22;
    }
    else {
      y0 = 0x98;
    }
    if (p_dm32_settings_block04[0x6c] == '\0') {
      y0 = 0x22;
    }
    if (param_1 == '\x01') {
      iVar1 = tone_signaling_type_classify(*(undefined2 *)&p_vfo_display_state->field_0x13_0);
    }
    else {
      iVar1 = tone_signaling_type_classify(*(undefined2 *)&p_vfo_display_state->field_0x11_0);
    }
    display_fill_rect(0x29,y0,0x47,y0 + 0x10,0);
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        display_blit_bitmap_1bpp(0x29,y0,0x1e,0x3c,PTR_LAB_03019764,0xffff);
      }
      else {
        display_blit_bitmap_1bpp(0x29,y0,0x1e,0x3c,PTR_LAB_03019768,0xffff);
      }
    }
  }
  return;
}

