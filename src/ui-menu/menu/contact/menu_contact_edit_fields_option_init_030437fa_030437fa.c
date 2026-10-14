/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_contact_edit_fields_option_init_030437fa @ 030437fa (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_contact_edit_fields_option_init_030437fa(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = PTR_PTR_03043978;
  uVar2 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03043978 + uVar2 * 2 + 1);
  *p_active_screen_option_ptr_array = puVar1[uVar2 * 2];
  *(undefined1 *)PTR_active_screen_subtype_0304396c = *(undefined1 *)((int)puVar1 + uVar2 * 8 + 5);
  if (*(char *)PTR_DAT_0304397c == '\x01') {
    list_row_text_buffer_clear();
    build_sequential_index_list
              ((ushort)*(byte *)p_active_screen_option_count,(ushort *)p_active_screen_index_list,
               (byte *)((int)p_active_screen_index_list + 2));
  }
  return;
}

