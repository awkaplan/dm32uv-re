/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_load_and_setting_read @ 0304c928 (file base 0x03000000; code starts at 0x03001000)
 * Size: 546 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_screen_load_and_setting_read(char param_1,char param_2)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = _DAT_0304cad8;
  iVar6 = _DAT_0304cabc;
  if (param_2 == '\0') {
    menu_capability_dispatch(param_1);
  }
  else if (param_2 == '\x01') {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    iVar5 = _DAT_0304cabc + uVar4 * 8;
    bVar1 = *(byte *)(iVar5 + 4);
    *(byte *)PTR_active_screen_option_count_0304cac0 = bVar1;
    *PTR_active_screen_option_ptr_array_0304cac4 = *(undefined4 *)(iVar6 + uVar4 * 8);
    *(undefined1 *)PTR_active_screen_subtype_0304cac8 = *(undefined1 *)(iVar5 + 5);
    if (*(char *)PTR_DAT_0304cacc == '\x01') {
      build_sequential_index_list
                ((ushort)bVar1,(ushort *)PTR_active_screen_index_list_0304cad0,
                 (byte *)((int)PTR_active_screen_index_list_0304cad0 + 2));
    }
    if (param_1 == '\0') {
      uVar3 = settings_read_dispatcher(0x1e);
      *(undefined1 *)p_active_screen_state_word = uVar3;
      PTR_DAT_0304cad4[8] = PTR_DAT_0304cad4[8] & 0xfb | 4;
    }
    else if (param_1 == '\x01') {
      uVar3 = settings_read_dispatcher(0x20);
      *(undefined1 *)p_active_screen_state_word = uVar3;
      PTR_DAT_0304cad4[7] = PTR_DAT_0304cad4[7] & 0x7f | 0x80;
    }
    else if (param_1 == '\x02') {
      uVar3 = settings_read_dispatcher(0x22);
      *(undefined1 *)p_active_screen_state_word = uVar3;
      PTR_DAT_0304cad4[8] = PTR_DAT_0304cad4[8] & 0xfe | 1;
    }
    else if (param_1 == '\x03') {
      uVar3 = settings_read_dispatcher(0x24);
      *(undefined1 *)p_active_screen_state_word = uVar3;
      PTR_DAT_0304cad4[8] = PTR_DAT_0304cad4[8] & 0xfd | 2;
    }
    else if (param_1 == '\x04') {
      uVar3 = settings_read_dispatcher(0x26);
      *(undefined1 *)p_active_screen_state_word = uVar3;
      PTR_DAT_0304cad4[8] = PTR_DAT_0304cad4[8] & 0xf7 | 8;
    }
    else if (param_1 == '\x05') {
      uVar3 = settings_read_dispatcher(0x28);
      *(undefined1 *)p_active_screen_state_word = uVar3;
      PTR_DAT_0304cad4[8] = PTR_DAT_0304cad4[8] & 0xef | 0x10;
    }
    PTR_DAT_0304cad4[8] = PTR_DAT_0304cad4[8] & 0xdf | 0x20;
    cVar2 = *(char *)p_active_screen_state_word;
    *(byte *)p_active_screen_flag_0003e5d5 = cVar2 + 1U;
    if (8 < (byte)(cVar2 + 1U)) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
    }
  }
  else if (param_2 == '\x02') {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    iVar6 = _DAT_0304cad8 + uVar4 * 8;
    bVar1 = *(byte *)(iVar6 + 4);
    *(byte *)PTR_active_screen_option_count_0304cac0 = bVar1;
    *PTR_active_screen_option_ptr_array_0304cac4 = *(undefined4 *)(iVar5 + uVar4 * 8);
    *(undefined1 *)PTR_active_screen_subtype_0304cac8 = *(undefined1 *)(iVar6 + 5);
    if (*(char *)PTR_DAT_0304cacc == '\x01') {
      build_sequential_index_list
                ((ushort)bVar1,(ushort *)PTR_active_screen_index_list_0304cad0,
                 (byte *)((int)PTR_active_screen_index_list_0304cad0 + 2));
    }
    if (param_1 == '\0') {
      uVar3 = settings_read_dispatcher(0x1f);
      *(undefined1 *)p_active_screen_state_word = uVar3;
      PTR_DAT_0304cad4[8] = PTR_DAT_0304cad4[8] & 0xfb | 4;
    }
    else if (param_1 == '\x01') {
      uVar3 = settings_read_dispatcher(0x21);
      *(undefined1 *)PTR_active_screen_state_word_0304cc6c = uVar3;
      PTR_DAT_0304cc70[7] = PTR_DAT_0304cc70[7] & 0x7f | 0x80;
    }
    else if (param_1 == '\x02') {
      uVar3 = settings_read_dispatcher(0x23);
      *(undefined1 *)PTR_active_screen_state_word_0304cc6c = uVar3;
      PTR_DAT_0304cc70[8] = PTR_DAT_0304cc70[8] & 0xfe | 1;
    }
    else if (param_1 == '\x03') {
      uVar3 = settings_read_dispatcher(0x25);
      *(undefined1 *)PTR_active_screen_state_word_0304cc6c = uVar3;
      PTR_DAT_0304cc70[8] = PTR_DAT_0304cc70[8] & 0xfd | 2;
    }
    else if (param_1 == '\x04') {
      uVar3 = settings_read_dispatcher(0x27);
      *(undefined1 *)PTR_active_screen_state_word_0304cc6c = uVar3;
      PTR_DAT_0304cc70[8] = PTR_DAT_0304cc70[8] & 0xf7 | 8;
    }
    else if (param_1 == '\x05') {
      uVar3 = settings_read_dispatcher(0x29);
      *(undefined1 *)PTR_active_screen_state_word_0304cc6c = uVar3;
      PTR_DAT_0304cc70[8] = PTR_DAT_0304cc70[8] & 0xef | 0x10;
    }
    cVar2 = *(char *)PTR_active_screen_state_word_0304cc6c;
    *(byte *)PTR_active_screen_flag_0003e5d5_0304cc74 = cVar2 + 1U;
    if (8 < (byte)(cVar2 + 1U)) {
      *(undefined1 *)PTR_active_screen_flag_0003e5d5_0304cc74 = 8;
    }
  }
  return;
}

