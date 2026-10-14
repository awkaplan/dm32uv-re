/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_state_dispatcher @ 030454cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 260 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_screen_state_dispatcher(void)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  char cVar5;
  
  bVar1 = *(byte *)PTR_DAT_030455f0;
  flash_field_read_cached(0x65,(uint)bVar1 * 0x21 + 0x20,DAT_030455f4,1);
  puVar3 = PTR_DAT_03045610;
  cVar5 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_030455e4 + 2);
  if (cVar5 == '\x01') {
    *(undefined1 *)PTR_DAT_030455f8 = 1;
    *(undefined1 *)p_active_screen_state_word = 0;
    *(undefined1 *)PTR_active_screen_subtype_030455e8 = 0x29;
    *(ushort *)p_active_screen_index_list = (ushort)*DAT_030455f4;
    *(undefined1 *)p_menu_selected_item_index = 0;
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
  }
  else if (cVar5 == '\x02') {
    if (*(char *)PTR_DAT_03045600 == '\x01') {
      *(undefined1 *)p_active_screen_state_word = 0;
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
    }
    puVar2 = PTR_DAT_03045604;
    *(undefined1 *)p_active_screen_option_count = PTR_DAT_03045604[4];
    *p_active_screen_option_ptr_array = *(undefined4 *)puVar2;
    *(undefined1 *)PTR_active_screen_subtype_030455e8 = 0x2a;
    *(undefined2 *)p_active_screen_index_list = 2;
  }
  else if (cVar5 == '\x03') {
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03045610 + 1);
    *p_active_screen_option_ptr_array = *puVar3;
    *(undefined1 *)PTR_active_screen_subtype_030455e8 = *(undefined1 *)((int)puVar3 + 5);
    if (*(char *)PTR_DAT_03045600 == '\x01') {
      dialog_request_init(0x10);
      iVar4 = p_text_entry_buffer;
      flash_field_read_cached(0x65,(uint)bVar1 * 0x21 + 0x10,p_text_entry_buffer,0x10);
      cVar5 = strlen_ck803s(iVar4);
      *(byte *)PTR_DAT_03045618 = cVar5 + 1U;
      if (0x10 < (byte)(cVar5 + 1U)) {
        *(undefined1 *)(iVar4 + 0x10) = 0;
        *(undefined1 *)PTR_DAT_03045618 = 0x11;
      }
      *(char *)PTR_DAT_0304561c = *(char *)PTR_DAT_03045618 + -1;
      *(undefined2 *)PTR_DAT_03045620 = 0x20;
      *(undefined2 *)p_text_entry_current_char = 5;
      *(undefined1 *)p_text_entry_current_char_alias = 0;
      gb2312_text_wrap_calculate(p_text_entry_buffer);
      p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xdf | 0x20;
    }
  }
  return;
}

