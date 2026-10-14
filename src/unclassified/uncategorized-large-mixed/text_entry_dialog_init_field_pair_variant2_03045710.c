/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_dialog_init_field_pair_variant2 @ 03045710 (file base 0x03000000; code starts at 0x03001000)
 * Size: 238 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_dialog_init_field_pair_variant2(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte bVar5;
  
  uVar2 = _DAT_03045808;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x5 + DAT_030457e8 + 2);
  if (cVar1 == '\0') {
    dialog_request_init(0x10);
    uVar2 = p_text_entry_buffer;
    if (*(char *)PTR_DAT_030457ec == '\x01') {
      string_copy_by_param_select(1,p_text_entry_buffer);
      bVar5 = strlen_ck803s(uVar2);
      *(byte *)PTR_DAT_030457f4 = bVar5 + 1;
      *(byte *)PTR_DAT_03045824 = bVar5;
      *(ushort *)p_text_entry_current_char = (ushort)bVar5 * 0xc + 5;
      p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xf7 | 8;
    }
    puVar3 = PTR_DAT_0304582c;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_0304582c + 1);
    *p_active_screen_option_ptr_array = *puVar3;
    *(undefined1 *)PTR_active_screen_subtype_03045804 = *(undefined1 *)((int)puVar3 + 5);
  }
  else if (cVar1 == '\x01') {
    if (*(char *)PTR_DAT_030457ec == '\x01') {
      string_copy_by_param_select(2,_DAT_03045808);
      bVar5 = strlen_ck803s(uVar2);
      *(byte *)PTR_DAT_0304580c = bVar5;
      puVar3 = PTR_DAT_03045810;
      *(undefined2 *)p_text_entry_buffer_alias = *(undefined2 *)PTR_DAT_03045810;
      puVar4 = p_text_entry_current_char;
      *(undefined2 *)PTR_DAT_0304581c = *(undefined2 *)p_text_entry_current_char;
      *(undefined2 *)puVar3 = 0x20;
      *(ushort *)puVar4 = (ushort)bVar5 * 0xc + 5;
      p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xfb | 4;
      if (*(char *)PTR_PTR_03045830 == '\x03') {
        p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfb;
      }
      else {
        p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfb | 4;
      }
    }
    puVar3 = _LAB_030459f4;
    *_p_active_screen_option_count = *(undefined1 *)(_LAB_030459f4 + 1);
    *_p_active_screen_option_ptr_array = *puVar3;
    *_DAT_03045a00 = *(undefined1 *)((int)puVar3 + 5);
  }
  return;
}

