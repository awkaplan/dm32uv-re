/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_record_offset_select4 @ 0304707c (file base 0x03000000; code starts at 0x03001000)
 * Size: 518 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_record_offset_select4(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  menu_screen_state *pmVar4;
  undefined4 *puVar5;
  int iVar6;
  byte bVar7;
  byte abStack_58 [20];
  undefined4 uStack_44;
  undefined4 uStack_40;
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x1 + DAT_030471c0 + 2);
  if (cVar1 == '\x03') {
    display_fill_screen(0);
    if ((PTR_DAT_030471c4[1] & 3) == 0) {
      display_blit_bitmap_1bpp_clipped(5,1,0x18,0x18,PTR_LAB_030471c8);
      abStack_58[0] = 3;
    }
    else if ((PTR_DAT_030471c4[1] & 3) == 1) {
      display_blit_bitmap_1bpp_clipped(5,1,0x18,0x18,PTR_LAB_030471cc);
      abStack_58[0] = 4;
    }
    else {
      display_blit_bitmap_1bpp_clipped(5,1,0x18,0x18,PTR_LAB_030471d0);
      abStack_58[0] = 5;
    }
    iVar6 = contact_name_lookup_or_format
                      (1,*p_text_entry_current_char_alias,abStack_58,abStack_58[0]);
    display_draw_string_gb2312(0x28,0x23,abStack_58,0xffff,0);
    if (iVar6 != 0) {
      number_to_string_format_2args
                (abStack_58,PTR_s__d_030afae0_8_030471d8,*p_text_entry_current_char_alias);
      display_draw_string_gb2312(0x46,0x23,abStack_58,0xffff,0);
    }
  }
  else {
    if (cVar1 == '\x05') {
      cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03047198 + 2);
      if (cVar1 == '\x01') {
        display_draw_dialog_panel();
        channel_record_load_by_index(&uStack_44);
        cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_030471dc + 2);
        if (cVar1 == '\0') {
          display_draw_number_centered(0x82,0,0xc618,*(uint *)*p_active_screen_option_ptr_array);
          format_and_plot_number_with_decimals
                    ((byte)p_dm32_settings_block04[0x2d] >> 7,0xb6,10,0,0xc618,uStack_44);
        }
        else if (cVar1 == '\x01') {
          display_draw_number_centered
                    (0x82,0,0xc618,*(uint *)(*p_active_screen_option_ptr_array + 4));
          format_and_plot_number_with_decimals
                    ((byte)p_dm32_settings_block04[0x2d] >> 7,0xb6,10,0,0xc618,uStack_40);
        }
      }
      else if (cVar1 == '\x02') {
        display_fill_rect(0,0,0xf0,0x1b,0);
        pmVar4 = p_menu_screen_state;
        puVar3 = p_active_screen_index_list;
        display_draw_number_centered
                  (1,0xffff,0,
                   *(uint *)(PTR_PTR_03047350[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                            (uint)(byte)p_active_screen_index_list
                                        [p_menu_screen_state->index_0x3 + 0x8f] * 4));
        display_fill_screen(0);
        puVar5 = PTR_PTR_03047354;
        puVar2 = p_dm32_settings_block04;
        if ((puVar3[pmVar4->index_0x3 + 0x8f] != '\0') &&
           (puVar3[pmVar4->index_0x3 + 0x8f] == '\x01')) {
          display_draw_string_gb2312
                    (0x28,5,*(byte **)(PTR_PTR_03047354
                                       [((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 8),
                     0xffff,0);
          display_draw_number_centered(0x46,0xffff,0,*(uint *)*p_active_screen_option_ptr_array);
          display_draw_string_gb2312
                    (100,5,*(byte **)(puVar5[((byte)puVar2[0x30] >> 6 & 1) * 2] + 0xc),0xffff,0);
        }
      }
    }
    if (*(byte *)p_active_screen_option_count != 0) {
      bVar7 = 0;
      do {
        bVar7 = bVar7 + 1;
      } while (bVar7 < *(byte *)p_active_screen_option_count);
    }
  }
  return;
}

