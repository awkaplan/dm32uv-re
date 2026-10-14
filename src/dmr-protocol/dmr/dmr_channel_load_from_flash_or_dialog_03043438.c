/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_channel_load_from_flash_or_dialog @ 03043438 (file base 0x03000000; code starts at 0x03001000)
 * Size: 396 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_channel_load_from_flash_or_dialog(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  uint uVar5;
  
  puVar3 = PTR_DAT_030436b4;
  puVar2 = PTR_PTR_03043698;
  cVar4 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_030434fc + 2);
  if (cVar4 == '\x01') {
    uVar5 = read_byte_field_03065e34();
    puVar2 = PTR_PTR_0304350c;
    if (*(byte *)PTR_DAT_03043508 < uVar5) {
      uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      bVar1 = *(byte *)(PTR_PTR_0304350c + uVar5 * 2 + 1);
      *(byte *)p_active_screen_option_count = bVar1;
      *p_active_screen_option_ptr_array = puVar2[uVar5 * 2];
      *(undefined1 *)PTR_active_screen_subtype_030434e4 =
           *(undefined1 *)((int)puVar2 + uVar5 * 8 + 5);
      if (*(char *)PTR_DAT_030434cc == '\x01') {
        build_sequential_index_list
                  ((ushort)bVar1,(ushort *)p_active_screen_index_list,
                   (byte *)((int)p_active_screen_index_list + 2));
        *(undefined1 *)p_active_screen_state_word = 0;
      }
      cVar4 = *(char *)p_active_screen_state_word;
      *(char *)p_active_screen_flag_0003e5d5 = cVar4 + '\x01';
      *(undefined1 *)PTR_DAT_03043518 = 1;
      *(char *)p_menu_selected_item_index = cVar4;
      flash_field_read_cached(0x65,(uint)*(byte *)PTR_DAT_03043508 * 0x21 + 0x20,DAT_03043520,1);
    }
    else if (uVar5 < 0x40) {
      dialog_request_init(0x10);
      if (*(char *)PTR_DAT_03043674 == '\x01') {
        cVar4 = strlen_ck803s(p_text_entry_buffer);
        *(char *)PTR_DAT_0304367c = cVar4 + '\x01';
      }
      puVar2 = PTR_DAT_03043680;
      *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03043680 + 1);
      *p_active_screen_option_ptr_array = *puVar2;
      *(undefined1 *)PTR_active_screen_subtype_0304368c = *(undefined1 *)((int)puVar2 + 5);
    }
    else {
      dialog_show_icon_and_number
                (0,**(undefined4 **)
                     (PTR_PTR_03043670 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
    }
  }
  else if (cVar4 == '\x02') {
    cVar4 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03043694 + 2);
    if (cVar4 == '\0') {
      uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      bVar1 = *(byte *)(PTR_PTR_03043698 + uVar5 * 2 + 1);
      *(byte *)p_active_screen_option_count = bVar1;
      *p_active_screen_option_ptr_array = puVar2[uVar5 * 2];
      *(undefined1 *)PTR_active_screen_subtype_0304368c =
           *(undefined1 *)((int)puVar2 + uVar5 * 8 + 5);
      build_sequential_index_list
                ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
      if ((*(byte *)PTR_DAT_030436a0 & 1) == 0) {
        *(undefined1 *)p_active_screen_state_word = 1;
      }
      else {
        *(undefined1 *)p_active_screen_state_word = 0;
      }
      cVar4 = *(char *)p_active_screen_state_word;
      *(char *)p_active_screen_flag_0003e5d5 = cVar4 + '\x01';
      *(undefined1 *)PTR_DAT_030436ac = 2;
      *(char *)p_menu_selected_item_index = cVar4;
    }
    else if (cVar4 == '\x01') {
      *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030436b4 + 1);
      *p_active_screen_option_ptr_array = *puVar3;
      *(undefined1 *)PTR_active_screen_subtype_0304368c = *(undefined1 *)((int)puVar3 + 5);
      *(undefined1 *)PTR_DAT_030436b8 = 0x5b;
      *(char *)p_active_screen_state_word = (char)(*(ushort *)((int)PTR_DAT_030436a0 + 1) / 0x3c);
    }
  }
  return;
}

