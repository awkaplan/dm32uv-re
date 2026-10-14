/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_option_list_init_by_type @ 03045af8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 306 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_screen_option_list_init_by_type(void)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = _DAT_03045e00;
  iVar9 = _DAT_03045c28;
  cVar6 = *(char *)((uint)p_menu_screen_state->index_0x5 + _DAT_03045c20 + 2);
  if (cVar6 == '\x01') {
    uVar7 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    iVar8 = _DAT_03045c28 + uVar7 * 8;
    bVar1 = *(byte *)(iVar8 + 4);
    *(byte *)p_active_screen_option_count = bVar1;
    *p_active_screen_option_ptr_array = *(undefined4 *)(iVar9 + uVar7 * 8);
    *(undefined1 *)PTR_active_screen_subtype_03045bfc = *(undefined1 *)(iVar8 + 5);
    if (*(char *)PTR_DAT_03045be4 == '\x01') {
      build_sequential_index_list
                ((ushort)bVar1,(ushort *)p_active_screen_index_list,
                 (byte *)((int)p_active_screen_index_list + 2));
    }
  }
  else if (cVar6 == '\0') {
    if (*(char *)PTR_DAT_03045be4 == '\x01') {
      dialog_request_init(0x80);
      p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xef | 0x10;
    }
    puVar2 = PTR_DAT_03045c24;
    *(undefined1 *)p_active_screen_option_count = PTR_DAT_03045c24[4];
    *p_active_screen_option_ptr_array = *(undefined4 *)puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03045bfc = puVar2[5];
  }
  else if (cVar6 == '\x02') {
    if (*(char *)PTR_DAT_03045be4 == '\x01') {
      dialog_request_init(0x80);
      list_record_lookup_and_toggle_by_index(1,p_menu_screen_state->index_0x3 + 1);
      uVar3 = _DAT_03045c2c;
      cVar6 = strlen_ck803s(_DAT_03045c2c);
      *(char *)PTR_DAT_03045c30 = cVar6 + '\x01';
      *(char *)PTR_DAT_03045c34 = cVar6;
      puVar4 = PTR_DAT_03045c38;
      *(undefined2 *)PTR_DAT_03045c38 = 0x20;
      puVar5 = PTR_text_entry_current_char_03045c3c;
      *(undefined2 *)PTR_text_entry_current_char_03045c3c = 5;
      gb2312_text_wrap_calculate(uVar3);
      *(undefined2 *)PTR_DAT_03045c40 = *(undefined2 *)puVar5;
      *(undefined2 *)PTR_text_entry_buffer_minus_4_03045c44 = *(undefined2 *)puVar4;
      p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xef | 0x10;
    }
    else {
      text_entry_field_init_and_wrap_calc();
    }
    puVar2 = PTR_DAT_03045dec;
    *(undefined1 *)p_active_screen_option_count = PTR_DAT_03045dec[4];
    *p_active_screen_option_ptr_array = *(undefined4 *)puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03045df8 = puVar2[5];
  }
  else if (cVar6 == '\x03') {
    uVar7 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    iVar9 = _DAT_03045e00 + uVar7 * 8;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(iVar9 + 4);
    *p_active_screen_option_ptr_array = *(undefined4 *)(iVar8 + uVar7 * 8);
    *(undefined1 *)PTR_active_screen_subtype_03045df8 = *(undefined1 *)(iVar9 + 5);
  }
  return;
}

