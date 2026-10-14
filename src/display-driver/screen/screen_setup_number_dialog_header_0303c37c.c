/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: screen_setup_number_dialog_header @ 0303c37c (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c842) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void screen_setup_number_dialog_header(void)

{
  char cVar1;
  
  display_fill_screen(0);
  display_fill_rect(0,0,0xf0,0x1b,0);
  display_draw_number_centered
            (1,0xffff,0,
             *(uint *)(PTR_PTR_0303c3fc[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 0x30))
  ;
  if (*(ushort *)p_active_screen_index_list < 9) {
    *(char *)PTR_active_screen_visible_rows_0303c5b0 = (char)*(ushort *)p_active_screen_index_list;
  }
  else {
    *(undefined1 *)PTR_active_screen_visible_rows_0303c3e8 = 8;
  }
  scan_list_screen_with_add
            (*(undefined1 *)p_active_screen_flag_0003e5d5,*(undefined1 *)p_active_screen_state_word,
             *(byte *)PTR_DAT_0303c5b4 + 2);
  dialog_header_draw_two_lines();
  cVar1 = *(char *)PTR_active_screen_subtype_0303c950;
  if (((((((cVar1 != '\b') && (cVar1 != '\x05')) && (cVar1 != '\x06')) &&
        ((cVar1 != '\x04' && (cVar1 != '\x18')))) &&
       ((cVar1 != '\x03' && ((cVar1 != '\n' && (cVar1 != '\x17')))))) && (cVar1 != '%')) &&
     ((cVar1 != '/' && ((cVar1 != '\x16' || (*(char *)PTR_DAT_0303c954 != '\x01')))))) {
    signal_level_bargraph_mode_select();
  }
  OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x00000020);
  return;
}

