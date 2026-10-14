/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_signaling_menu_option_0x1f_dispatch @ 03047ae8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 146 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tone_signaling_menu_option_0x1f_dispatch(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  
  iVar3 = tone_signaling_type_classify(*(undefined2 *)&p_vfo_display_state->field_0x11_0);
  puVar2 = PTR_PTR_03047cfc;
  puVar1 = PTR_PTR_03047b64;
  if (iVar3 == 0) {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03047b64 + uVar4 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar1[uVar4 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03047b38 = *(undefined1 *)((int)puVar1 + uVar4 * 8 + 5)
    ;
  }
  else {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03047cfc + uVar4 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar2[uVar4 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03047d08 = *(undefined1 *)((int)puVar2 + uVar4 * 8 + 5)
    ;
  }
  menu_option_list_dispatch
            (0x1f,p_active_screen_index_list,(void *)((int)p_active_screen_index_list + 2));
  bVar5 = p_vfo_display_state->field_0x16 >> 4 & 7;
  *(byte *)p_active_screen_state_word = bVar5;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar5 + 1;
  *(undefined1 *)PTR_DAT_03047d1c = 2;
  *(byte *)p_menu_selected_item_index = bVar5;
  return;
}

