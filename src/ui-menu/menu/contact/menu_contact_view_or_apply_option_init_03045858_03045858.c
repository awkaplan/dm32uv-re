/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_contact_view_or_apply_option_init_03045858 @ 03045858 (file base 0x03000000; code starts at 0x03001000)
 * Size: 408 bytes
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

void menu_contact_view_or_apply_option_init_03045858(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = _DAT_03045a34;
  iVar5 = _DAT_03045a2c;
  iVar6 = _DAT_03045a18;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + _DAT_03045a08 + 2);
  if (cVar1 == '\0') {
    if (*_DAT_03045a0c == '\0') {
      cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + _DAT_03045a10 + 2);
      if (cVar1 == '\x02') {
        text_entry_dialog_init_field_pair_variant2();
      }
      else if (cVar1 == '\x04') {
        uVar4 = *(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1;
        iVar5 = _DAT_03045a18 + uVar4 * 8;
        bVar2 = *(byte *)(iVar5 + 4);
        *_p_active_screen_option_count = bVar2;
        *_p_active_screen_option_ptr_array = *(undefined4 *)(iVar6 + uVar4 * 8);
        *_DAT_03045a00 = *(undefined1 *)(iVar5 + 5);
        if (*_DAT_03045a1c == '\x01') {
          build_sequential_index_list
                    ((ushort)bVar2,_p_active_screen_index_list,
                     (byte *)(_p_active_screen_index_list + 1));
        }
      }
      else if (cVar1 == '\x01') {
        text_entry_dialog_init_field_pair();
      }
    }
  }
  else if (cVar1 == '\x03') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + _DAT_03045a24 + 2);
    if (cVar1 == '\0') {
      if (*(char *)((uint)p_menu_screen_state->index_0x5 + _DAT_03045a28 + 2) == '\0') {
        uVar4 = *(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1;
        iVar6 = _DAT_03045a2c + uVar4 * 8;
        bVar2 = *(byte *)(iVar6 + 4);
        *_p_active_screen_option_count = bVar2;
        *_p_active_screen_option_ptr_array = *(undefined4 *)(iVar5 + uVar4 * 8);
        *_DAT_03045a00 = *(undefined1 *)(iVar6 + 5);
        if (*_DAT_03045a1c == '\x01') {
          build_sequential_index_list
                    ((ushort)bVar2,_p_active_screen_index_list,
                     (byte *)(_p_active_screen_index_list + 1));
        }
      }
      else {
        if (*_DAT_03045a1c == '\x01') {
          menu_option_list_dispatch(1,_p_active_screen_index_list,_p_active_screen_index_list + 1);
        }
        iVar6 = _DAT_03045a30;
        if (*_p_active_screen_index_list == 0) {
          history_queue_pop();
        }
        else {
          uVar4 = *(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1;
          iVar5 = _DAT_03045a30 + uVar4 * 8;
          *_p_active_screen_option_count = *(byte *)(iVar5 + 4);
          *_p_active_screen_option_ptr_array = *(undefined4 *)(iVar6 + uVar4 * 8);
          *_DAT_03045a00 = *(undefined1 *)(iVar5 + 5);
        }
      }
    }
    else if (cVar1 == '\x01') {
      uVar4 = *(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1;
      iVar6 = _DAT_03045a34 + uVar4 * 8;
      *_p_active_screen_option_count = *(byte *)(iVar6 + 4);
      *_p_active_screen_option_ptr_array = *(undefined4 *)(iVar3 + uVar4 * 8);
      *_DAT_03045a00 = *(undefined1 *)(iVar6 + 5);
      *_DAT_03045a38 = 1;
      iVar6 = _DAT_03045a40;
      if (*_DAT_03045a1c == '\x01') {
        flash_talker_record_read(*_DAT_03045a3c + 1,_DAT_03045a40);
        iVar5 = _p_list_row_text_buffer;
        memcpy_bytes_iram(_p_list_row_text_buffer,iVar6 + 0x14,8);
        *(undefined1 *)(iVar5 + 8) = 0;
        build_sequential_index_list
                  ((ushort)*_p_active_screen_option_count,_p_active_screen_index_list,
                   (byte *)(_p_active_screen_index_list + 1));
      }
    }
  }
  return;
}

