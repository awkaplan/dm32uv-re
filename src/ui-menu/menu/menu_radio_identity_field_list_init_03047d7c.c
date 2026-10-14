/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_radio_identity_field_list_init @ 03047d7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 128 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_radio_identity_field_list_init(void)

{
  char cVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  puVar4 = PTR_PTR_03047e40;
  puVar2 = PTR_PTR_03047e24;
  puVar7 = p_active_screen_option_count;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03047e18 + 2);
  if (cVar1 == '\0') {
    uVar6 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03047e24 + uVar6 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar2[uVar6 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03047e2c = 0x16;
    *(undefined1 *)PTR_DAT_03047e30 = 2;
    uVar5 = flash_field_block67_signed_threshold_check(p_vfo_display_state->field_0x1b);
    *p_text_entry_current_char_alias = uVar5;
    puVar3 = p_active_screen_index_list;
    build_sequential_index_list
              ((ushort)*(byte *)puVar7,p_active_screen_index_list,
               (byte *)(p_active_screen_index_list + 1));
    *puVar3 = 1;
  }
  else if (cVar1 == '\x01') {
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03047e40 + 1);
    puVar7 = (undefined4 *)*puVar4;
    *p_active_screen_option_ptr_array = puVar7;
    *(undefined1 *)PTR_active_screen_subtype_03047e2c = *(undefined1 *)((int)puVar4 + 5);
    strcpy_ck803s(*puVar7,PTR_s_DM32_00_01_048_03047e44);
  }
  return;
}

