/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_item_dialog_screen_jump @ 0303b842 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
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

void menu_item_dialog_screen_jump(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)p_active_screen_option_count;
  *(ushort *)p_active_screen_index_list = (ushort)bVar1;
  if (bVar1 < 9) {
    *(byte *)PTR_active_screen_visible_rows_0303b8ac = bVar1;
  }
  else {
    *(undefined1 *)PTR_active_screen_visible_rows_0303b8ac = 8;
  }
  if (bVar1 != 0) {
    display_fill_screen(0);
  }
  jump_table_dispatch_by_param(*(undefined1 *)PTR_DAT_0303b8d0);
  dialog_header_draw_two_lines();
  cVar2 = *(char *)PTR_active_screen_subtype_0303c950;
  if (((((((cVar2 != '\b') && (cVar2 != '\x05')) && (cVar2 != '\x06')) &&
        ((cVar2 != '\x04' && (cVar2 != '\x18')))) &&
       ((cVar2 != '\x03' && ((cVar2 != '\n' && (cVar2 != '\x17')))))) && (cVar2 != '%')) &&
     ((cVar2 != '/' && ((cVar2 != '\x16' || (*(char *)PTR_DAT_0303c954 != '\x01')))))) {
    signal_level_bargraph_mode_select();
  }
  OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x00000020);
  return;
}

