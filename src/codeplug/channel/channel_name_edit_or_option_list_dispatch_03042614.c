/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_name_edit_or_option_list_dispatch @ 03042614 (file base 0x03000000; code starts at 0x03001000)
 * Size: 300 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_name_edit_or_option_list_dispatch(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  short local_14;
  undefined1 local_12 [2];
  
  channel_offset_minus_0x10(*(char *)PTR_DAT_0304276c + '\x01',local_12,&local_14);
  flash_field_read_cached(local_12[0],local_14 + 0x10,DAT_03042770,1);
  puVar2 = PTR_DAT_03042794;
  cVar4 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03042778 + 2);
  if (cVar4 == '\x01') {
    *(undefined1 *)PTR_DAT_03042764 = 1;
    *(undefined1 *)p_active_screen_state_word = 0;
    *(undefined1 *)PTR_active_screen_subtype_03042750 = 0x20;
    *(ushort *)p_active_screen_index_list = (ushort)*DAT_03042770;
    *(undefined1 *)p_menu_selected_item_index = 0;
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
  }
  else if (cVar4 == '\x02') {
    if (*(char *)PTR_DAT_03042754 == '\x01') {
      *(undefined2 *)PTR_DAT_03042788 = 0;
      *(undefined2 *)PTR_DAT_0304278c = 1;
    }
    puVar1 = PTR_DAT_03042790;
    *(undefined1 *)p_active_screen_option_count = PTR_DAT_03042790[4];
    *p_active_screen_option_ptr_array = *(undefined4 *)puVar1;
    *(undefined1 *)PTR_active_screen_subtype_03042750 = puVar1[5];
    *(undefined2 *)p_active_screen_index_list = 2;
  }
  else if (cVar4 == '\x03') {
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03042794 + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03042750 = *(undefined1 *)((int)puVar2 + 5);
    if (*(char *)PTR_DAT_03042754 == '\x01') {
      dialog_request_init(0x10);
      channel_offset_minus_0x10(*(char *)PTR_DAT_0304276c + '\x01',local_12,&local_14);
      iVar3 = p_text_entry_buffer;
      flash_field_read_cached(local_12[0],local_14,p_text_entry_buffer,0x10);
      cVar4 = strlen_ck803s(iVar3);
      *(byte *)PTR_DAT_0304279c = cVar4 + 1U;
      if (0x10 < (byte)(cVar4 + 1U)) {
        *(undefined1 *)(iVar3 + 0x10) = 0;
        *(undefined1 *)PTR_DAT_0304279c = 0x11;
      }
      *(char *)PTR_DAT_030427a0 = *(char *)PTR_DAT_0304279c + -1;
      *(undefined2 *)PTR_DAT_030427a4 = 0x20;
      *(undefined2 *)p_text_entry_current_char = 5;
      *(undefined1 *)p_text_entry_current_char_alias = 0;
      gb2312_text_wrap_calculate(p_text_entry_buffer);
      p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xdf | 0x20;
    }
  }
  return;
}

