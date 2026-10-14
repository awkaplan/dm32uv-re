/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_state_mode_dispatch @ 03051bac (file base 0x03000000; code starts at 0x03001000)
 * Size: 586 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_screen_state_mode_dispatch(void)

{
  char cVar1;
  byte bVar2;
  menu_screen_state *pmVar3;
  menu_screen_state *pmVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  pmVar4 = p_menu_screen_state;
  pmVar3 = p_menu_screen_state;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03051cd0 + 2);
  if (cVar1 == '\0') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x6 + DAT_03051cd4 + 2);
    if (cVar1 == '\x01') {
      write_status_mode_byte_pair(0x38,1);
    }
    else if (cVar1 == '\0') {
      if (*(char *)PTR_DAT_03051cd8 == '\x03') {
        write_status_mode_byte_pair(0x38,1);
      }
      else {
        scan_state_tick();
        write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03051cdc + DAT_03051ce0),0);
      }
    }
    else if (cVar1 == '\x02') {
      if (*(char *)PTR_DAT_03051cd8 == '\x03') {
        write_status_mode_byte_pair(0x38,1);
      }
      else {
        scan_state_tick();
        write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03051cdc + DAT_03051ce0),0);
      }
    }
    else if (cVar1 == '\x03') {
      flash_list_entry_remove_and_compact(p_menu_screen_state->index_0x4 + 1,1);
      pmVar3->index_0x4 = 0;
      PTR_DAT_03051ce4[4] = 1;
      history_queue_pop();
      history_queue_pop();
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_03051cec + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
    else {
      write_status_mode_byte_pair(0x38,1);
    }
  }
  else if (cVar1 == '\x03') {
    if (p_menu_screen_state->index_0x6 == 3) {
      flash_list_entry_remove_and_compact(p_menu_screen_state->index_0x4 + 1,3);
      pmVar3->index_0x4 = 0;
      PTR_DAT_03051ce4[4] = 1;
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_03051cec + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      history_queue_pop();
      history_queue_pop();
    }
    else if (p_menu_screen_state->index_0x6 == 2) {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*_LAB_03051e24 + _LAB_03051e28),0);
    }
    else if (*_LAB_03051e2c == '\x03') {
      write_status_mode_byte_pair(0x38,1);
    }
    else {
      scan_state_tick();
      write_status_mode_byte_pair(*(undefined1 *)((uint)*_LAB_03051e24 + _LAB_03051e28),0);
    }
  }
  else if (cVar1 == '\x02') {
    if (*(char *)((uint)p_menu_screen_state->index_0x5 + _LAB_03051e34 + 2) == '\0') {
      cVar1 = *(char *)((uint)p_menu_screen_state->index_0x6 + _LAB_03051e38 + 2);
      if (cVar1 == '\0') {
        history_list_row_lookup(*_DAT_03051e3c + 1);
      }
      else if (cVar1 == '\x01') {
        iVar5 = ascii_digits_to_uint();
        if (iVar5 == 0) {
          write_status_mode_byte_pair(*(undefined1 *)((uint)*_LAB_03051e24 + _LAB_03051e28),0);
        }
        else {
          uVar7 = *_p_text_entry_current_char_alias;
          *_DAT_03051e44 = uVar7;
          if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
            uVar6 = 3;
          }
          else {
            uVar6 = 4;
          }
          channel_select_commit_and_notify
                    (uVar6,uVar7,_p_text_entry_buffer,*_DAT_03051e4c,
                     *(undefined1 *)(_p_dm32_settings_block04 + 0x54));
        }
      }
    }
    else {
      write_status_mode_byte_pair(0x38,1);
    }
  }
  else if (cVar1 == '\x04') {
    bVar2 = p_menu_screen_state->index_0x6;
    if (bVar2 == 0) {
      write_status_mode_byte_pair(0x38,1);
    }
    else if ((bVar2 != 1) && (bVar2 == 2)) {
      flash_list_entry_remove_and_compact(p_menu_screen_state->index_0x4 + 1,5);
      pmVar4->index_0x4 = 0;
      *(undefined1 *)(_DAT_03051e58 + 4) = 1;
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (_DAT_03051e5c + (*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1) * 8));
      history_queue_pop();
      history_queue_pop();
    }
  }
  else {
    write_status_mode_byte_pair(0x38,1);
  }
  return;
}

