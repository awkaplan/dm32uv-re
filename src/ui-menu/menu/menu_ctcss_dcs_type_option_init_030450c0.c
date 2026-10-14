/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_ctcss_dcs_type_option_init @ 030450c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 188 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_ctcss_dcs_type_option_init(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  
  puVar2 = PTR_PTR_03045258;
  uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar6 = *(byte *)(PTR_PTR_03045258 + uVar5 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar6;
  *p_active_screen_option_ptr_array = puVar2[uVar5 * 2];
  *(undefined1 *)PTR_active_screen_subtype_03045264 = *(undefined1 *)((int)puVar2 + uVar5 * 8 + 5);
  *(undefined1 *)PTR_DAT_03045268 = 2;
  if (*(char *)PTR_DAT_0304526c == '\x01') {
    build_sequential_index_list
              ((ushort)bVar6,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  if (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03045278 + 2) == '\0') {
    uVar3 = uint16_classify_by_sign_and_high_nibble
                      (*(undefined2 *)&p_vfo_display_state->field_0x13_0);
    *(undefined1 *)p_active_screen_state_word = uVar3;
  }
  else {
    iVar4 = uint16_classify_by_sign_and_high_nibble
                      (*(undefined2 *)&p_vfo_display_state->field_0x11_0);
    *(char *)p_active_screen_state_word = (char)iVar4;
    if ((p_radio_mode_state_0003e318->flags_0x2 & 0x40) != 0) {
      if (iVar4 == 2) {
        *(undefined1 *)p_active_screen_state_word = 3;
      }
      else {
        if (iVar4 != 3) goto LAB_03045160;
        *(undefined1 *)p_active_screen_state_word = 2;
      }
      cVar1 = *(char *)p_active_screen_state_word;
      *(char *)p_menu_selected_item_index = cVar1;
      *(char *)p_active_screen_flag_0003e5d5 = cVar1 + '\x01';
      return;
    }
  }
LAB_03045160:
  cVar1 = *(char *)p_active_screen_state_word;
  *(char *)p_menu_selected_item_index = cVar1;
  bVar6 = cVar1 + 1;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar6;
  if (8 < bVar6) {
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
  }
  return;
}

