/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_contact_edit_fields_option_init_03043840 @ 03043840 (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_contact_edit_fields_option_init_03043840(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 in_stack_00000000;
  
  puVar1 = PTR_PTR_03043984;
  uVar2 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03043984 + uVar2 * 2 + 1);
  *p_active_screen_option_ptr_array = puVar1[uVar2 * 2];
  *(undefined1 *)PTR_active_screen_subtype_0304396c = *(undefined1 *)((int)puVar1 + uVar2 * 8 + 5);
  if (*(char *)PTR_DAT_0304397c == '\x01') {
    history_record_lookup_by_type
              (p_vfo_display_state->flags_0x8 >> 4,*(short *)PTR_DAT_03043970 + 1,&stack0x00000004);
    memcpy_bytes_iram();
    number_to_string_format_2args(DAT_0304398c,PTR_s__d_030afae0_8_03043990,in_stack_00000000);
    list_row_text_set_or_default(1,&stack0x00000006);
    build_sequential_index_list
              ((ushort)*(byte *)p_active_screen_option_count,(ushort *)p_active_screen_index_list,
               (byte *)((int)p_active_screen_index_list + 2));
  }
  return;
}

