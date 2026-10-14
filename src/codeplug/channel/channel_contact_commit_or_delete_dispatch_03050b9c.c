/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_contact_commit_or_delete_dispatch @ 03050b9c (file base 0x03000000; code starts at 0x03001000)
 * Size: 338 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_contact_commit_or_delete_dispatch(void)

{
  menu_screen_state *pmVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  pmVar1 = p_menu_screen_state;
  cVar3 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03050c2c + 2);
  if (cVar3 == '\x03') {
    if (*(char *)p_active_screen_state_word == '\0') {
      uVar5 = *PTR_DAT_03050c44;
      *PTR_DAT_03050c1c = uVar5;
      cVar3 = strlen_ck803s(p_text_entry_buffer);
      *(char *)PTR_DAT_03050c4c = cVar3 + '\x01';
      if ((PTR_DAT_03050c50[1] & 3) == 1) {
        uVar4 = 4;
      }
      else if ((PTR_DAT_03050c50[1] & 3) == 2) {
        uVar4 = 5;
      }
      else {
        uVar4 = 3;
      }
      channel_select_commit_and_notify
                (uVar4,uVar5,p_text_entry_buffer,cVar3 + '\x01',p_dm32_settings_block04[0x54]);
      history_queue_pop();
      p_radio_mode_state_0003e318[1].flags_0x7 = p_radio_mode_state_0003e318[1].flags_0x7 & 0xfd | 2
      ;
    }
    else {
      write_status_mode_byte_pair(0x31,1);
    }
  }
  else if (cVar3 == '\x02') {
    if (PTR_DAT_03050dac[4] == '\0') {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03050db8 + DAT_03050dbc),0);
    }
    else if (*(char *)((uint)p_menu_screen_state->index_0x5 + DAT_03050db4 + 2) == '\0') {
      write_status_mode_byte_pair(0x31,1);
    }
  }
  else if (cVar3 == '\x04') {
    cVar3 = *(char *)p_active_screen_state_word;
    if (cVar3 == '\0') {
      write_status_mode_byte_pair(0x31,1);
    }
    else if (cVar3 == '\x01') {
      flash_list_entry_remove_and_compact(p_menu_screen_state->index_0x4 + 1,5);
      puVar2 = PTR_DAT_03050dc8;
      uVar5 = p_text_entry_buffer;
      buffer_prepend_3byte_le(0,p_text_entry_buffer,*(undefined1 *)PTR_DAT_03050dc8);
      contact_edit_save_flow1(uVar5,*(byte *)puVar2 + 3,5,0);
      dialog_show_icon_and_two_numbers
                (0x30,0x30,PTR_DAT_03050dd8,
                 **(undefined4 **)
                   (PTR_PTR_03050dd0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                 PTR_LAB_03050dd4);
      OSTimeDly_ms_wrapper(1000);
      pmVar1->index_0x4 = 0;
      PTR_DAT_03050ddc[4] = 1;
      history_queue_pop();
      history_queue_pop();
      history_queue_pop();
    }
    else if (cVar3 == '\x02') {
      write_status_mode_byte_pair(0x31,1);
    }
  }
  else {
    write_status_mode_byte_pair(0x31,1);
  }
  return;
}

