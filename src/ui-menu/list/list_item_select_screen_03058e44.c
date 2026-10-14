/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_item_select_screen @ 03058e44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 212 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_item_select_screen(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_24 [16];
  
  display_fill_rect(0,0,0xf0,0x1b,0);
  display_fill_screen(0);
  memset_bytes(auStack_24,0,0x10);
  display_draw_number_centered
            (1,0xffff,0,
             *(uint *)(PTR_PTR_03058f8c[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                      (uint)*(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_03058f88 + 2) * 4))
  ;
  iVar1 = contact_name_lookup_by_offset_walk(param_1,param_2,auStack_24);
  if (iVar1 == 0) {
    display_draw_list_row(1,auStack_24,0);
    display_blit_bitmap_1bpp_clipped(8,1,0x14,0x18,PTR_LAB_03058f98);
  }
  else {
    display_draw_list_row(1,auStack_24,0);
    display_blit_image(8,0x28,0x18,0x18,PTR_LAB_03058f90);
    uVar2 = flash_record_read_nth_entry(param_1,param_2);
    number_to_string_format_2args(auStack_24,PTR_s__d_030afae0_8_03058f94,uVar2);
    display_draw_list_row(2,auStack_24,0);
    display_blit_bitmap_1bpp_clipped(8,2,0x14,0x18,PTR_LAB_03058f98);
  }
  datetime_display_gb2312(param_1,param_2);
  return;
}

