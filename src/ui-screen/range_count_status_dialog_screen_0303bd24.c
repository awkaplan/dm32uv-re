/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: range_count_status_dialog_screen @ 0303bd24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c842) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void range_count_status_dialog_screen(undefined4 param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  
  if (*(short *)p_active_screen_index_list == 0) {
    *(ushort *)p_active_screen_index_list = (ushort)*DAT_0303bdf0;
    write_status_mode_byte_pair(*(undefined1 *)(param_3 + DAT_0303bdf4),0);
    *(undefined1 *)PTR_active_screen_subtype_0303bdf8 = 2;
  }
  else {
    display_fill_screen(0);
    range_count_status_display(*PTR_DAT_0303bdfc,*PTR_DAT_0303be00,*PTR_DAT_0303be04);
    dialog_header_draw_two_lines();
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

