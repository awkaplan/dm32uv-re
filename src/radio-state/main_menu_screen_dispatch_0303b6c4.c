/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: main_menu_screen_dispatch @ 0303b6c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c842) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void main_menu_screen_dispatch(void)

{
  char cVar1;
  undefined1 auStack_10 [4];
  
  if ((p_dialog_history_ui_state->index_0x2 == 1) && ((*(byte *)PTR_DAT_0303b710 & 2) == 0)) {
    dialog_show_number_or_alt();
  }
  else {
    if (8 < *(byte *)p_active_screen_flag_0003e5d5) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
    }
    if (*(byte *)PTR_active_screen_subtype_0303b718 < 0x32) {
                    /* WARNING: Could not recover jumptable at 0x0303b708. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0303b71c[*(byte *)PTR_active_screen_subtype_0303b718] & 0xfffffffe))();
      return;
    }
    cVar1 = *(char *)PTR_active_screen_subtype_0303c950;
    if (((((((cVar1 != '\b') && (cVar1 != '\x05')) && (cVar1 != '\x06')) &&
          ((cVar1 != '\x04' && (cVar1 != '\x18')))) &&
         ((cVar1 != '\x03' && ((cVar1 != '\n' && (cVar1 != '\x17')))))) && (cVar1 != '%')) &&
       ((cVar1 != '/' && ((cVar1 != '\x16' || (*(char *)PTR_DAT_0303c954 != '\x01')))))) {
      signal_level_bargraph_mode_select();
    }
    OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_10);
  }
  return;
}

