/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_record_detail_screen_draw @ 030334c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 208 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_record_detail_screen_draw(undefined2 param_1)

{
  undefined4 local_2c;
  undefined1 auStack_28 [2];
  byte abStack_26 [17];
  undefined1 auStack_15 [3];
  byte bStack_12;
  
  local_2c = 0;
  history_record_lookup_by_type(0,param_1,auStack_28);
  display_fill_rect(0,0,0xf0,0x1b,0);
  display_fill_screen(0);
  display_draw_number_centered
            (1,0xffff,0,
             **(uint **)(PTR_PTR_0303369c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  display_blit_bitmap_1bpp_clipped(8,1,0x18,0x18,PTR_DAT_030336a0[bStack_12 - 3]);
  display_draw_string_gb2312(0x28,0x28,abStack_26,0xffff,0);
  display_blit_bitmap_1bpp_clipped(8,2,0x14,0x18,PTR_LAB_030336a4);
  memcpy_bytes_iram(&local_2c,auStack_15,3);
  format_number_and_draw_display(0x46,0x28,0xffff,0,PTR_s__d_030afae0_8_030336a8,local_2c);
  if (10 < bStack_12) {
    bStack_12 = 10;
  }
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_draw_string_from_table(0);
  return;
}

