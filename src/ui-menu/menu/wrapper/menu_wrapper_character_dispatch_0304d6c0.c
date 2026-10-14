/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_wrapper_character_dispatch @ 0304d6c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 344 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_wrapper_character_dispatch(void)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  undefined1 auStack_8 [4];
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304d7d4 + 2);
  if (cVar1 == '\0') {
    if (*(char *)p_active_screen_state_word == '\0') {
      settings_write_dispatcher(0x58,1);
    }
    else {
      settings_write_dispatcher(0x58,0);
    }
    menu_row_highlight_draw();
    dialog_show_icon_and_number_from_ptr();
    return;
  }
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      toggle_0x331_write(*(undefined1 *)p_active_screen_state_word);
      menu_row_highlight_draw();
      dialog_show_icon_and_number_from_ptr();
      return;
    }
    if (cVar1 == '\x03') {
      vfo_field_write_2bit_at_8_v2(*(undefined1 *)p_active_screen_state_word);
      dialog_show_icon_and_number_from_ptr();
      return;
    }
    if (cVar1 == '\x04') {
      settings_write_dispatcher(0x59,*(undefined1 *)p_active_screen_state_word);
      dialog_show_icon_and_number_from_ptr();
      return;
    }
    if (cVar1 == '\x05') {
      write_status_mode_byte_pair(0x1c,1);
      return;
    }
    if (cVar1 == '\x06') {
      aprs_related_toggle_0x302_write(*(undefined1 *)p_active_screen_state_word);
      menu_row_highlight_draw();
      dialog_show_icon_and_number_from_ptr();
      return;
    }
    if (cVar1 != '\a') {
      return;
    }
    aprs_log_clear();
    dialog_show_icon_and_number
              (1,**(undefined4 **)
                   (PTR_PTR_0304d98c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    return;
  }
  OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_8);
  uVar4 = (uint)*DAT_0304d7dc;
  if (uVar4 == 0) {
    *(undefined1 *)PTR_DAT_0304d990 = 0;
  }
  else {
    iVar2 = 0;
    pbVar3 = (byte *)PTR_DAT_0304d7e0;
    do {
      iVar2 = (*pbVar3 - 0x30) + iVar2 * 10;
      pbVar3 = pbVar3 + 1;
    } while (pbVar3 != (byte *)((int)PTR_DAT_0304d7e0 + (uVar4 - 1 & 0xff) + 1));
    *(undefined1 *)((int)PTR_DAT_0304d7e0 + uVar4) = 0;
    if (iVar2 - 1U < 0xfffcdf) {
      flash_block4_write_field_0x332_and_cache();
      dialog_show_icon_and_number_from_ptr();
      goto LAB_0304d77c;
    }
  }
  dialog_show_icon_and_two_numbers
            (0x30,0x30,PTR_DAT_0304d7f0,
             **(undefined4 **)
               (PTR_PTR_0304d7e8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
             PTR_LAB_0304d7ec);
  OSTimeDly_ms_wrapper(0x5dc);
  history_queue_pop();
LAB_0304d77c:
  p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xbf;
  return;
}

