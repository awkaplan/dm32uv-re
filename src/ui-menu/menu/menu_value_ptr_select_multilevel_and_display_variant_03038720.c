/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_value_ptr_select_multilevel_and_display_variant @ 03038720 (file base 0x03000000; code starts at 0x03001000)
 * Size: 500 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_value_ptr_select_multilevel_and_display_variant(void)

{
  char cVar1;
  undefined *value;
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x1 + DAT_030387b8 + 2);
  if (cVar1 == '\x05') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03038790 + 2);
    if (cVar1 == '\0') {
      value = *(undefined **)
               (PTR_PTR_030387c0[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
               (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_030387bc + 2) * 4);
    }
    else if (cVar1 == '\x01') {
      value = *(undefined **)
               (PTR_PTR_030387c4[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
               (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_030387bc + 2) * 4);
    }
    else if (cVar1 == '\x03') {
      value = *(undefined **)
               (PTR_PTR_03038964[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
               (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_03038960 + 2) * 4);
    }
    else if (cVar1 == '\x04') {
      value = *(undefined **)
               (PTR_PTR_03038968[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
               (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_03038960 + 2) * 4);
    }
    else if (cVar1 == '\x05') {
      value = *(undefined **)
               (PTR_PTR_0303896c[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
               (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_03038960 + 2) * 4);
    }
    else {
      value = PTR_LAB_03038e58;
      if (cVar1 == '\x06') {
        value = *(undefined **)
                 (PTR_PTR_03038970[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                 (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_03038960 + 2) * 4);
      }
    }
  }
  else if (cVar1 == '\0') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03038974 + 2);
    value = p_list_row_text_buffer;
    if (((cVar1 != '\0') && (value = _DAT_03038e84, cVar1 != '\x02')) &&
       (value = PTR_LAB_03038e58, cVar1 == '\x04')) {
      value = *(undefined **)
               (PTR_PTR_03038978[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
               (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_03038960 + 2) * 4);
    }
  }
  else if (cVar1 == '\x01') {
    value = PTR_LAB_03038980;
    if (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03038974 + 2) == '\x01') {
      value = p_list_row_text_buffer;
    }
  }
  else if (cVar1 == '\x03') {
    value = (undefined *)
            **(undefined4 **)(PTR_PTR_03038984 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4)
    ;
  }
  else {
    value = DAT_03038e88;
    if (cVar1 != '\x04') {
      if (cVar1 == '\x06') {
        value = *(undefined **)
                 (PTR_PTR_03038988[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 0x18);
      }
      else if (cVar1 == '\a') {
        cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03038974 + 2);
        value = p_list_row_text_buffer;
        if ((cVar1 != '\x01') && (value = PTR_LAB_03038e58, cVar1 == '\x02')) {
          value = *(undefined **)
                   (PTR_PTR_0303898c[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 8);
        }
      }
      else {
        value = PTR_LAB_03038e58;
        if ((cVar1 == '\b') &&
           (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03038974 + 2) == '\x01')) {
          value = (undefined *)
                  **(undefined4 **)
                    (PTR_PTR_03038990 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4);
        }
      }
    }
  }
  display_draw_number_centered(1,0xffff,0,(uint)value);
  return;
}

