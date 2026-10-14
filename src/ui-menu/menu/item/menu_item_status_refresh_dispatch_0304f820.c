/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_item_status_refresh_dispatch @ 0304f820 (file base 0x03000000; code starts at 0x03001000)
 * Size: 596 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_item_status_refresh_dispatch(void)

{
  char cVar1;
  menu_screen_state *pmVar2;
  menu_screen_state *pmVar3;
  int iVar4;
  
  pmVar3 = p_menu_screen_state;
  pmVar2 = p_menu_screen_state;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304f9a8 + 2);
  if (cVar1 == '\x01') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_0304f9ac + 2);
    if (cVar1 == '\x01') {
      if (*(char *)PTR_DAT_0304f9b0 == '\x03') {
        *(undefined1 *)PTR_DAT_0304f9b4 = 0xf0;
        *(undefined2 *)PTR_DAT_0304f9bc = *(undefined2 *)p_text_entry_current_char;
        *(undefined2 *)p_text_entry_buffer_alias = *(undefined2 *)PTR_DAT_0304f9c0;
        write_status_mode_byte_pair(0x2a,1);
      }
      else {
        scan_state_tick();
        write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f9c8 + DAT_0304f9cc),0);
      }
    }
    else if (cVar1 == '\x02') {
      flash_block_config_load_validate_writeback(2,p_menu_screen_state->index_0x3 + 1);
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f9c8 + DAT_0304f9cc),0);
      iVar4 = PTR_LAB_0304f9d0[1];
      pmVar2->index_0x3 = 0;
      PTR_DAT_0304f9d4[3] = 1;
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_0304f9dc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      history_queue_pop();
      if (*(char *)(iVar4 + 4) == '\0') {
        history_queue_pop();
      }
    }
    else {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304faec + DAT_0304faf0),0);
    }
  }
  else if (cVar1 == '\0') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_0304f9ac + 2);
    if (cVar1 == '\x01') {
      if (*(char *)PTR_DAT_0304f9b0 == '\x03') {
        *(undefined1 *)PTR_DAT_0304f9b4 = 0xf0;
        *(undefined2 *)PTR_DAT_0304f9bc = *(undefined2 *)p_text_entry_current_char;
        *(undefined2 *)p_text_entry_buffer_alias = *(undefined2 *)PTR_DAT_0304f9c0;
        write_status_mode_byte_pair(0x2a,1);
      }
      else {
        scan_state_tick();
        write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f9c8 + DAT_0304f9cc),0);
      }
    }
    else if (cVar1 == '\x02') {
      flash_block_config_load_validate_writeback(1,p_menu_screen_state->index_0x3 + 1);
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f9c8 + DAT_0304f9cc),0);
      iVar4 = *PTR_LAB_0304f9d0;
      pmVar2->index_0x3 = 0;
      PTR_DAT_0304f9d4[3] = 1;
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_0304f9dc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      history_queue_pop();
      if (*(char *)(iVar4 + 4) == '\0') {
        history_queue_pop();
      }
    }
    else {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f9c8 + DAT_0304f9cc),0);
    }
  }
  else if (cVar1 == '\x02') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_0304faf8 + 2);
    if (cVar1 == '\x01') {
      if (*(char *)PTR_DAT_0304fafc == '\x03') {
        *(undefined1 *)PTR_DAT_0304fb00 = 0xf0;
        *(undefined2 *)PTR_DAT_0304fb08 = *(undefined2 *)p_text_entry_current_char;
        *(undefined2 *)p_text_entry_buffer_alias = *(undefined2 *)PTR_DAT_0304fb0c;
        write_status_mode_byte_pair(0x2a,1);
      }
      else {
        scan_state_tick();
        write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304faec + DAT_0304faf0),0);
      }
    }
    else if (cVar1 == '\x02') {
      flash_block_config_load_validate_writeback(3,p_menu_screen_state->index_0x3 + 1);
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304faec + DAT_0304faf0),0);
      iVar4 = PTR_LAB_0304fb14[2];
      pmVar3->index_0x3 = 0;
      PTR_DAT_0304fb18[3] = 1;
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_0304fb20 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      history_queue_pop();
      if (*(char *)(iVar4 + 4) == '\0') {
        history_queue_pop();
      }
    }
    else {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304faec + DAT_0304faf0),0);
    }
  }
  return;
}

