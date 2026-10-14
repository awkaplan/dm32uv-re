/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: backlight_setting_toggle_handler @ 0304d590 (file base 0x03000000; code starts at 0x03001000)
 * Size: 250 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void backlight_setting_toggle_handler(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  byte local_d;
  
  puVar2 = p_active_screen_state_word;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304d638 + 2);
  if (cVar1 == '\0') {
    if (*(char *)p_active_screen_state_word == '\0') {
      settings_write_dispatcher(0x3e,1);
      gps_power_set(1);
    }
    else {
      settings_write_dispatcher(0x3e,0);
      gps_power_set(0);
    }
    menu_row_highlight_draw();
    dialog_show_icon_and_number_from_ptr();
  }
  else if (cVar1 == '\x01') {
    iVar3 = vfo_active_side_mode_nibble();
    if ((iVar3 == 1) || (iVar3 = vfo_active_side_mode_nibble(), iVar3 == 3)) {
      write_status_mode_byte_pair(0x1c,1);
    }
    else {
      ui_event_notify(0x21);
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304d60c + DAT_0304d610),0);
    }
  }
  else if (cVar1 == '\x02') {
    settings_write_dispatcher(0x3f,*(undefined1 *)p_active_screen_state_word);
    menu_row_highlight_draw();
    dialog_show_icon_and_number_from_ptr();
  }
  else if (cVar1 == '\x03') {
    settings_write_dispatcher(0x40,*(undefined1 *)p_active_screen_state_word);
    menu_row_highlight_draw();
    dialog_show_icon_and_number_from_ptr();
  }
  else if (cVar1 == '\x04') {
    PTR_DAT_0304d7cc[0xd8] =
         PTR_DAT_0304d7cc[0xd8] & 0xf3 | (*(byte *)p_active_screen_state_word & 3) << 2;
    flash_field_read_cached(4,0x40,&local_d,1);
    local_d = *(char *)puVar2 << 2 | local_d & 0xf3;
    flash_field_write_cached(4,0x40);
    menu_row_highlight_draw();
    dialog_show_icon_and_number_from_ptr();
  }
  else {
    history_queue_pop();
  }
  return;
}

