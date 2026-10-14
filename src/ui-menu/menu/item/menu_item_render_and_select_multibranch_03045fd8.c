/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_item_render_and_select_multibranch @ 03045fd8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 786 bytes
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

void menu_item_render_and_select_multibranch(void)

{
  char cVar1;
  menu_screen_state *pmVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  int iVar12;
  
  iVar12 = _DAT_03046374;
  iVar8 = _DAT_03046370;
  iVar9 = _p_dm32_settings_block04;
  puVar6 = PTR_DAT_030461a4;
  puVar4 = PTR_PTR_0304617c;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03046170 + 2);
  if (cVar1 == '\x01') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x5 + DAT_03046174 + 2);
    if (cVar1 == '\0') {
      uVar10 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      bVar11 = *(byte *)(PTR_PTR_0304617c + uVar10 * 2 + 1);
      *(byte *)p_active_screen_option_count = bVar11;
      *p_active_screen_option_ptr_array = puVar4[uVar10 * 2];
      *(undefined1 *)PTR_active_screen_subtype_03046188 =
           *(undefined1 *)((int)puVar4 + uVar10 * 8 + 5);
      if (*(char *)PTR_DAT_0304618c == '\x01') {
        build_sequential_index_list
                  ((ushort)bVar11,(ushort *)p_active_screen_index_list,
                   p_active_screen_index_list + 2);
      }
      iVar9 = settings_read_dispatcher(0xf);
      if (iVar9 == 1) {
        *(undefined1 *)p_active_screen_state_word = 1;
      }
      else {
        *(undefined1 *)p_active_screen_state_word = 0;
      }
      *(undefined1 *)PTR_DAT_03046198 = 2;
      cVar1 = *(char *)p_active_screen_state_word;
      *(char *)p_menu_selected_item_index = cVar1;
      *(char *)p_active_screen_flag_0003e5d5 = cVar1 + '\x01';
    }
    else if (cVar1 == '\x01') {
      *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030461a4 + 1);
      *p_active_screen_option_ptr_array = *puVar6;
      *(undefined1 *)PTR_active_screen_subtype_03046188 = *(undefined1 *)((int)puVar6 + 5);
      *(undefined1 *)PTR_DAT_030461a8 = 0x2e;
    }
  }
  else if (cVar1 == '\x02') {
    if (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_030461ac + 2) == '\x11') {
      display_fill_rect(0,0,0xf0,0x1b,0);
      puVar5 = p_active_screen_index_list;
      pmVar2 = p_menu_screen_state;
      display_draw_number_centered
                (1,0xffff,0,
                 *(uint *)(PTR_PTR_030461b0[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                          (uint)(byte)p_active_screen_index_list
                                      [p_menu_screen_state->index_0x5 + 0xd5] * 4));
      iVar8 = _LAB_0304634c;
      iVar9 = _p_dm32_settings_block04;
      puVar4 = PTR_PTR_030461b8;
      puVar7 = PTR_LAB_030461b4;
      puVar3 = p_dm32_settings_block04;
      cVar1 = puVar5[pmVar2->index_0x5 + 0xd5];
      if (cVar1 == '\0') {
        *(undefined *)p_active_screen_option_count = PTR_LAB_030461b4[4];
        *(undefined *)PTR_active_screen_subtype_03046188 = puVar7[5];
        *(undefined1 *)PTR_DAT_030461a8 = 1;
      }
      else if (cVar1 == '\x01') {
        *(undefined *)p_active_screen_option_count = PTR_LAB_030461b4[4];
        *(undefined *)PTR_active_screen_subtype_03046188 = puVar7[5];
        *(undefined1 *)PTR_DAT_030461a8 = 2;
      }
      else if (cVar1 == '\x02') {
        uVar10 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
        bVar11 = *(byte *)(PTR_PTR_030461b8 + uVar10 * 2 + 1);
        *(byte *)p_active_screen_option_count = bVar11;
        *p_active_screen_option_ptr_array = puVar4[uVar10 * 2];
        *(undefined1 *)PTR_active_screen_subtype_03046188 =
             *(undefined1 *)((int)puVar4 + uVar10 * 8 + 5);
        build_sequential_index_list
                  ((ushort)bVar11,(ushort *)p_active_screen_index_list,
                   p_active_screen_index_list + 2);
        *(undefined1 *)PTR_DAT_03046198 = 2;
        if ((puVar3[0x31] & 8) == 0) {
          *_p_active_screen_state_word = 1;
          *_p_menu_selected_item_index = 1;
        }
        else {
          *(undefined1 *)p_active_screen_state_word = 0;
          *(undefined1 *)p_menu_selected_item_index = 0;
        }
        *_p_active_screen_flag_0003e5d5 = *_p_active_screen_state_word + 1;
      }
      else if (cVar1 == '\x03') {
        uVar10 = *(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1;
        iVar12 = _LAB_0304634c + uVar10 * 8;
        bVar11 = *(byte *)(iVar12 + 4);
        *_p_active_screen_option_count = bVar11;
        *_p_active_screen_option_ptr_array = *(undefined4 *)(iVar8 + uVar10 * 8);
        *_DAT_03046358 = *(undefined1 *)(iVar12 + 5);
        build_sequential_index_list
                  ((ushort)bVar11,_p_active_screen_index_list,
                   (byte *)(_p_active_screen_index_list + 1));
        *_DAT_03046360 = 2;
        bVar11 = *(byte *)(iVar9 + 0x31) >> 4 & 1;
        *_p_active_screen_state_word = bVar11;
        *_p_menu_selected_item_index = bVar11;
        *_p_active_screen_flag_0003e5d5 = bVar11 + 1;
      }
    }
  }
  else if ((cVar1 == '\x03') &&
          (*(char *)((uint)p_menu_screen_state->index_0x4 + _DAT_03046368 + 2) == '\x03')) {
    if (*(char *)((uint)p_menu_screen_state->index_0x5 + _DAT_0304636c + 2) == '\0') {
      uVar10 = *(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1;
      iVar12 = _DAT_03046370 + uVar10 * 8;
      bVar11 = *(byte *)(iVar12 + 4);
      *_p_active_screen_option_count = bVar11;
      *_p_active_screen_option_ptr_array = *(undefined4 *)(iVar8 + uVar10 * 8);
      *_DAT_03046358 = *(undefined1 *)(iVar12 + 5);
      build_sequential_index_list
                ((ushort)bVar11,_p_active_screen_index_list,
                 (byte *)(_p_active_screen_index_list + 1));
      if ((*(byte *)(iVar9 + 0x30) & 1) == 0) {
        *_p_active_screen_state_word = 1;
      }
      else {
        *_p_active_screen_state_word = 0;
      }
      *_DAT_03046360 = 2;
      bVar11 = *_p_active_screen_state_word;
      *_p_menu_selected_item_index = bVar11;
      *_p_active_screen_flag_0003e5d5 = bVar11 + 1;
    }
    else {
      uVar10 = *(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1;
      iVar9 = _DAT_03046374 + uVar10 * 8;
      bVar11 = *(byte *)(iVar9 + 4);
      *_p_active_screen_option_count = bVar11;
      *_p_active_screen_option_ptr_array = *(undefined4 *)(iVar12 + uVar10 * 8);
      *_DAT_03046358 = *(undefined1 *)(iVar9 + 5);
      if (*(char *)PTR_DAT_03046378 == '\x01') {
        build_sequential_index_list
                  ((ushort)bVar11,_p_active_screen_index_list,
                   (byte *)(_p_active_screen_index_list + 1));
      }
      bVar11 = *(byte *)(_p_dm32_settings_block04 + 0x5e);
      *_p_active_screen_state_word = bVar11;
      *_p_menu_selected_item_index = bVar11;
      *_DAT_03046360 = 2;
      if ((ushort)bVar11 < *_p_active_screen_index_list) {
        bVar11 = *_p_active_screen_state_word;
        *_p_active_screen_flag_0003e5d5 = bVar11 + 1;
        if (8 < (byte)(bVar11 + 1)) {
          *_p_active_screen_flag_0003e5d5 = 8;
        }
      }
      else {
        *_p_active_screen_state_word = 0;
        *_p_active_screen_flag_0003e5d5 = 1;
      }
    }
  }
  return;
}

