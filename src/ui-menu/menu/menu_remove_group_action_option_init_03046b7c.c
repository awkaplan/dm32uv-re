/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_remove_group_action_option_init @ 03046b7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 382 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_remove_group_action_option_init(void)

{
  char cVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  
  puVar5 = PTR_DAT_03046d04;
  puVar4 = PTR_PTR_03046cf8;
  puVar3 = PTR_DAT_03046cd4;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03046cc0 + 2);
  if (cVar1 == '\x01') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03046cc4 + 2);
    if (cVar1 == '\f') {
      if (p_menu_screen_state->index_0x6 < *(byte *)PTR_DAT_03046cc8) {
        uVar7 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
        bVar2 = *(byte *)(PTR_PTR_03046cf8 + uVar7 * 2 + 1);
        *(byte *)p_active_screen_option_count = bVar2;
        *p_active_screen_option_ptr_array = puVar4[uVar7 * 2];
        *(undefined1 *)PTR_active_screen_subtype_03046ce0 =
             *(undefined1 *)((int)puVar4 + uVar7 * 8 + 5);
        if (*(char *)PTR_DAT_03046cf4 == '\x01') {
          build_sequential_index_list
                    ((ushort)bVar2,(ushort *)p_active_screen_index_list,
                     (byte *)((int)p_active_screen_index_list + 2));
        }
        *(undefined1 *)p_active_screen_state_word = 0;
        *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
      }
      else if (*(byte *)PTR_DAT_03046cc8 < 0x20) {
        *(undefined1 *)p_active_screen_option_count = PTR_DAT_03046cd4[4];
        *p_active_screen_option_ptr_array = *(undefined4 *)puVar3;
        *(undefined1 *)PTR_active_screen_subtype_03046ce0 = puVar3[5];
        uVar6 = contact_count_range_calc(6);
        *(undefined2 *)PTR_DAT_03046ce4 = uVar6;
        *(undefined2 *)p_active_screen_index_list = 2;
        *(undefined2 *)PTR_DAT_03046cec = 0;
        *(undefined2 *)PTR_DAT_03046cf0 = 1;
        if (*(char *)PTR_DAT_03046cf4 == '\x01') {
          set_flag_byte_03064328_variant_0303501c(6);
        }
      }
      else {
        dialog_show_icon_and_number
                  (0,**(undefined4 **)
                       (PTR_PTR_03046cd0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
      }
    }
    else if (cVar1 == '\r') {
      bVar2 = PTR_DAT_03046d04[4];
      *(byte *)p_active_screen_option_count = bVar2;
      *p_active_screen_option_ptr_array = *(undefined4 *)puVar5;
      *(undefined1 *)PTR_active_screen_subtype_03046ce0 = puVar5[5];
      if (*(char *)PTR_DAT_03046cf4 == '\x01') {
        build_sequential_index_list
                  ((ushort)bVar2,(ushort *)p_active_screen_index_list,
                   (byte *)((int)p_active_screen_index_list + 2));
      }
      init_field_pair_0x20_5();
      p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0x9f | 0x40;
      pcVar9 = PTR_DAT_03046d0c + -8;
      uVar7 = DAT_03046d10;
      pcVar8 = PTR_DAT_03046d0c;
      do {
        *pcVar8 = (char)uVar7 + (char)(uVar7 / 10) * -10 + '0';
        pcVar8 = pcVar8 + -1;
        uVar7 = uVar7 / 10;
      } while (pcVar8 != pcVar9);
      *(undefined1 *)PTR_DAT_03046d14 = 8;
      *(undefined2 *)p_text_entry_current_char = 0x48;
    }
  }
  else if (((*(char *)((uint)p_menu_screen_state->index_0x1 + DAT_03046e64 + 2) == '\x05') &&
           (cVar1 == '\0')) &&
          (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03046e68 + 2) == '\x0e')) {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x6 + DAT_03046e6c + 2);
    if (cVar1 == '\0') {
      menu_screen_load_contact_list();
    }
    else if (cVar1 == '\x01') {
      menu_screen_load_static();
    }
  }
  return;
}

