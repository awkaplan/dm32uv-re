/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_item_plain_dialog_screen @ 0303b878 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_item_plain_dialog_screen(void)

{
  char cVar1;
  char cVar2;
  
  display_fill_rect(0x14,0x5a,0xdc,0xaa,0x7e0);
  menu_item_dispatch_plain();
  cVar1 = *(char *)PTR_DAT_0303b8d4;
  dialog_header_draw_two_lines();
  cVar2 = *(char *)PTR_active_screen_subtype_0303c950;
  if (((((((cVar2 != '\b') && (cVar2 != '\x05')) && (cVar2 != '\x06')) &&
        ((cVar2 != '\x04' && (cVar2 != '\x18')))) &&
       ((cVar2 != '\x03' && ((cVar2 != '\n' && (cVar2 != '\x17')))))) && (cVar2 != '%')) &&
     ((cVar2 != '/' && ((cVar2 != '\x16' || (*(char *)PTR_DAT_0303c954 != '\x01')))))) {
    signal_level_bargraph_mode_select();
  }
  if ((byte)(cVar1 - 1U) < 2) {
    ucos_tmr_del(p_ucos_tmr_inputcursor,&stack0x00000020);
  }
  else {
    OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x00000020);
  }
  return;
}

