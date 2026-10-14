/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: draw_dialog_header_and_centered_number @ 0302fa1c (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void draw_dialog_header_and_centered_number(void)

{
  display_fill_rect(0,0x1b,0xf0,0x140,0);
  dialog_header_draw_two_lines();
  display_blit_bitmap_1bpp(0x68,0x32,0x20,0x88,PTR_LAB_0302fb70,0xffff);
  display_draw_number_centered
            (100,0xffff,0,PTR_PTR_0302fb78[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
  dialog_header_number_draw_variant();
  return;
}

