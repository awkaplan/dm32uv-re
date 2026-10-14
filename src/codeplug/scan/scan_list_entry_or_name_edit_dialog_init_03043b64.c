/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_entry_or_name_edit_dialog_init @ 03043b64 (file base 0x03000000; code starts at 0x03001000)
 * Size: 210 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scan_list_entry_or_name_edit_dialog_init(void)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  undefined2 uVar4;
  
  puVar1 = PTR_DAT_03043cb4;
  cVar3 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03043c90 + 2);
  if (cVar3 == '\x01') {
    *(undefined1 *)PTR_DAT_03043c94 = 1;
    puVar1 = p_active_screen_state_word;
    *(undefined1 *)p_active_screen_state_word = 0;
    *(undefined1 *)PTR_active_screen_subtype_03043c9c = 0xf;
    uVar4 = scan_list_entry_byte_read(*(undefined1 *)PTR_DAT_03043ca0);
    p_vfo_freq_display_state->field_0x1 = (byte)uVar4;
    *(undefined2 *)p_active_screen_index_list = uVar4;
    cVar3 = *(char *)puVar1;
    *(char *)p_menu_selected_item_index = cVar3;
    *(char *)p_active_screen_flag_0003e5d5 = cVar3 + '\x01';
  }
  else if (cVar3 == '\x02') {
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03043cb4 + 1);
    *p_active_screen_option_ptr_array = *puVar1;
    *(undefined1 *)PTR_active_screen_subtype_03043c9c = *(undefined1 *)((int)puVar1 + 5);
    if (*(char *)PTR_DAT_03043cc0 == '\x01') {
      dialog_request_init(0xb);
      iVar2 = p_text_entry_buffer;
      flash_field_read_cached
                (0x11,(*(byte *)PTR_DAT_03043ca0 - 1) * 0x39 + 1,p_text_entry_buffer,0xb);
      cVar3 = strlen_ck803s(iVar2);
      *(byte *)PTR_DAT_03043cc8 = cVar3 + 1U;
      if (0xb < (byte)(cVar3 + 1U)) {
        *(undefined1 *)(iVar2 + 0xb) = 0;
        *(undefined1 *)PTR_DAT_03043cc8 = 0xc;
      }
      *(char *)PTR_DAT_03043ccc = *(char *)PTR_DAT_03043cc8 + -1;
      *(undefined2 *)PTR_DAT_03043cd0 = 0x20;
      *(undefined2 *)p_text_entry_current_char = 5;
      *(undefined1 *)p_text_entry_current_char_alias = 0;
      gb2312_text_wrap_calculate(p_text_entry_buffer);
      p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xdf | 0x20;
    }
  }
  return;
}

