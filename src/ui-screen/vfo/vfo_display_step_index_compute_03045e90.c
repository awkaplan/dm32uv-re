/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_display_step_index_compute @ 03045e90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 262 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_display_step_index_compute(void)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  vfo_display_state *pvVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  int iVar7;
  
  pvVar4 = p_vfo_display_state;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x5 + DAT_03045fbc + 2);
  if (cVar1 == '\0') {
    return;
  }
  if (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03045f9c + 2) == '\0') {
    iVar7 = uint16_classify_by_sign_and_high_nibble
                      (*(undefined2 *)&p_vfo_display_state->field_0x13_0);
    uVar2 = *(ushort *)&pvVar4->field_0x13_0;
  }
  else {
    iVar7 = uint16_classify_by_sign_and_high_nibble
                      (*(undefined2 *)&p_vfo_display_state->field_0x11_0);
    uVar2 = *(ushort *)&pvVar4->field_0x11_0;
  }
  puVar5 = PTR_DAT_03045fc4;
  *(undefined1 *)p_active_screen_option_count = PTR_DAT_03045fc4[4];
  *p_active_screen_option_ptr_array = *(undefined4 *)puVar5;
  *(undefined1 *)PTR_active_screen_subtype_03045fb0 = 0x14;
  if (cVar1 == '\x01') {
    *(undefined2 *)p_active_screen_index_list = 0x32;
    *(undefined1 *)p_active_screen_state_word = 0;
    if (iVar7 == 1) {
      uVar6 = search_table_u16_for_value(1,uVar2);
      *(undefined1 *)p_active_screen_state_word = uVar6;
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    goto LAB_03045f50;
  }
  *(undefined2 *)p_active_screen_index_list = 0x69;
  *(undefined1 *)p_active_screen_state_word = 0;
  if (iVar7 == 2) {
    if (cVar1 != '\x02') {
      bVar3 = true;
      goto LAB_03045f50;
    }
  }
  else {
    if (iVar7 != 3) {
      bVar3 = true;
      goto LAB_03045f50;
    }
    if (cVar1 != '\x03') {
      bVar3 = true;
      goto LAB_03045f50;
    }
  }
  uVar6 = search_table_u16_for_value(2,uVar2 & 0xfff);
  *(undefined1 *)p_active_screen_state_word = uVar6;
  bVar3 = false;
LAB_03045f50:
  if (*(ushort *)p_active_screen_index_list <= (ushort)*(byte *)p_active_screen_state_word) {
    *(undefined1 *)p_active_screen_state_word = 0;
  }
  *(undefined1 *)PTR_DAT_03045fcc = 2;
  if (bVar3) {
    *(undefined1 *)p_menu_selected_item_index = 0xff;
  }
  else {
    *(undefined1 *)p_menu_selected_item_index = *(undefined1 *)p_active_screen_state_word;
  }
  cVar1 = *(char *)p_active_screen_state_word;
  *(byte *)p_active_screen_flag_0003e5d5 = cVar1 + 1U;
  if (8 < (byte)(cVar1 + 1U)) {
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
  }
  return;
}

