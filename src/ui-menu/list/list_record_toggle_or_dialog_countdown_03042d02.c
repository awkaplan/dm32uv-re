/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_record_toggle_or_dialog_countdown @ 03042d02 (file base 0x03000000; code starts at 0x03001000)
 * Size: 192 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void list_record_toggle_or_dialog_countdown(void)

{
  undefined4 *puVar1;
  char cVar2;
  
  puVar1 = PTR_DAT_03042dfc;
  if (PTR_DAT_03042df8[4] == '\0') {
    display_draw_dialog_panel();
    display_draw_number_centered
              (100,0,0xc618,
               **(uint **)(PTR_PTR_03042e1c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    OSTimeDly_ms_wrapper(1000);
    history_queue_pop();
  }
  else {
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03042dfc + 1);
    *p_active_screen_option_ptr_array = *puVar1;
    *(undefined1 *)PTR_active_screen_subtype_03042dd8 = *(undefined1 *)((int)puVar1 + 5);
    if ((*(char *)PTR_DAT_03042df0 == '\x01') || (*(char *)PTR_DAT_03042df0 == '\x03')) {
      dialog_request_init(0x80);
      list_record_lookup_and_toggle_by_index(4,p_menu_screen_state->index_0x3 + 1);
      cVar2 = strlen_ck803s(p_text_entry_buffer);
      *(byte *)PTR_DAT_03042e04 = cVar2 + 1U;
      if (0x80 < (byte)(cVar2 + 1U)) {
        p_text_entry_buffer[0x80] = 0;
        *(undefined1 *)PTR_DAT_03042e04 = 0x81;
      }
      *(char *)PTR_DAT_03042e08 = *(char *)PTR_DAT_03042e04 + -1;
      *(undefined2 *)PTR_DAT_03042e0c = 0x20;
      *(undefined2 *)p_text_entry_current_char = 5;
      *(undefined1 *)p_text_entry_current_char_alias = 0;
      gb2312_text_wrap_calculate(p_text_entry_buffer);
      p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xef | 0x10;
    }
  }
  return;
}

