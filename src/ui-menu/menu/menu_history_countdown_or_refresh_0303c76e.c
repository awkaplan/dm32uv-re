/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_history_countdown_or_refresh @ 0303c76e (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c842) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_history_countdown_or_refresh(void)

{
  char cVar1;
  ushort uVar2;
  
  uVar2 = *(ushort *)p_active_screen_index_list;
  if (uVar2 < 9) {
    *(char *)PTR_active_screen_visible_rows_0303c7c0 = (char)uVar2;
  }
  else {
    *(undefined1 *)PTR_active_screen_visible_rows_0303c7c0 = 8;
  }
  if (uVar2 == 0) {
    history_queue_pop();
    *(ushort *)p_active_screen_index_list = (ushort)*DAT_0303c7d0;
    p_dialog_history_ui_state->field_0x4 = 0;
  }
  else if (*p_active_screen_option_ptr_array == 0) {
    display_fill_screen(0);
  }
  else {
    display_fill_screen(0);
    channel_number_and_name_screen_draw(*PTR_DAT_0303c94c + 1);
    cVar1 = *(char *)PTR_active_screen_subtype_0303c950;
    if (((((((cVar1 != '\b') && (cVar1 != '\x05')) && (cVar1 != '\x06')) &&
          ((cVar1 != '\x04' && (cVar1 != '\x18')))) &&
         ((cVar1 != '\x03' && ((cVar1 != '\n' && (cVar1 != '\x17')))))) && (cVar1 != '%')) &&
       ((cVar1 != '/' && ((cVar1 != '\x16' || (*(char *)PTR_DAT_0303c954 != '\x01')))))) {
      signal_level_bargraph_mode_select();
    }
    OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x00000020);
  }
  return;
}

