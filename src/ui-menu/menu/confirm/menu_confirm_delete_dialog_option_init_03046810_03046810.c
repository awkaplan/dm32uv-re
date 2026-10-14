/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_delete_dialog_option_init_03046810 @ 03046810 (file base 0x03000000; code starts at 0x03001000)
 * Size: 306 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_confirm_delete_dialog_option_init_03046810(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char cVar5;
  uint uVar6;
  
  puVar4 = PTR_PTR_03046998;
  puVar2 = PTR_PTR_03046974;
  cVar5 = *(char *)((uint)p_menu_screen_state->index_0x6 + DAT_03046964 + 2);
  if (cVar5 == '\x01') {
    uVar6 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar1 = *(byte *)(PTR_PTR_03046974 + uVar6 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar1;
    *p_active_screen_option_ptr_array = puVar2[uVar6 * 2];
    *(undefined1 *)PTR_active_screen_subtype_0304695c = *(undefined1 *)((int)puVar2 + uVar6 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03046968 == '\x01') {
      build_sequential_index_list
                ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
    }
  }
  else if (cVar5 == '\0') {
    if (*(char *)PTR_DAT_03046968 == '\x01') {
      dialog_request_init(0x80);
      p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xef | 0x10;
    }
    puVar2 = PTR_DAT_03046970;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03046970 + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_0304695c = *(undefined1 *)((int)puVar2 + 5);
  }
  else if (cVar5 == '\x02') {
    if (*(char *)PTR_DAT_03046968 == '\x01') {
      dialog_request_init(0x80);
      list_record_lookup_and_toggle_by_index(1,p_menu_screen_state->index_0x4 + 1);
      uVar3 = p_text_entry_buffer;
      cVar5 = strlen_ck803s(p_text_entry_buffer);
      *(char *)PTR_DAT_0304697c = cVar5 + '\x01';
      *(char *)PTR_DAT_03046980 = cVar5;
      puVar2 = PTR_DAT_03046984;
      *(undefined2 *)PTR_DAT_03046984 = 0x20;
      puVar4 = p_text_entry_current_char;
      *(undefined2 *)p_text_entry_current_char = 5;
      gb2312_text_wrap_calculate(uVar3);
      *(undefined2 *)PTR_DAT_0304698c = *(undefined2 *)puVar4;
      *(undefined2 *)p_text_entry_buffer_alias = *(undefined2 *)puVar2;
      p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xef | 0x10;
    }
    else {
      text_entry_field_init_and_wrap_calc();
    }
    puVar2 = PTR_DAT_03046994;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03046994 + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_0304695c = *(undefined1 *)((int)puVar2 + 5);
  }
  else if (cVar5 == '\x03') {
    uVar6 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03046998 + uVar6 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar4[uVar6 * 2];
    *(undefined1 *)PTR_active_screen_subtype_0304695c = *(undefined1 *)((int)puVar4 + uVar6 * 8 + 5)
    ;
  }
  return;
}

