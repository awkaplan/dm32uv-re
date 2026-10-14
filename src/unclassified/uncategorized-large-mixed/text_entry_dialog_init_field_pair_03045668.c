/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_dialog_init_field_pair @ 03045668 (file base 0x03000000; code starts at 0x03001000)
 * Size: 166 bytes
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

void text_entry_dialog_init_field_pair(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  byte bVar5;
  
  cVar4 = *(char *)((uint)p_menu_screen_state->index_0x5 + DAT_030457e8 + 2);
  if (cVar4 == '\0') {
    dialog_request_init(0x10);
    uVar1 = p_text_entry_buffer;
    if (*(char *)PTR_DAT_030457ec == '\x01') {
      string_copy_by_param_select(1,p_text_entry_buffer);
      cVar4 = strlen_ck803s(uVar1);
      *(char *)PTR_DAT_030457f4 = cVar4 + '\x01';
    }
    puVar2 = PTR_DAT_030457f8;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030457f8 + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03045804 = *(undefined1 *)((int)puVar2 + 5);
  }
  else if (cVar4 == '\x01') {
    init_field_pair_0x20_5();
    uVar1 = _DAT_03045808;
    if (*(char *)PTR_DAT_030457ec == '\x01') {
      string_copy_by_param_select(2,_DAT_03045808);
      bVar5 = strlen_ck803s(uVar1);
      *(byte *)PTR_DAT_0304580c = bVar5;
      puVar2 = PTR_DAT_03045810;
      *(undefined2 *)p_text_entry_buffer_alias = *(undefined2 *)PTR_DAT_03045810;
      puVar3 = p_text_entry_current_char;
      *(undefined2 *)PTR_DAT_0304581c = *(undefined2 *)p_text_entry_current_char;
      *(undefined2 *)puVar2 = 0x10;
      *(ushort *)puVar3 = (ushort)bVar5 * 8 + 5;
    }
    puVar2 = PTR_DAT_03045820;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03045820 + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03045804 = *(undefined1 *)((int)puVar2 + 5);
  }
  return;
}

