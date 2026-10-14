/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ctcss_dcs_list_dialog_screen @ 0303c17a (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c842) */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ctcss_dcs_list_dialog_screen(void)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  display_fill_screen(0);
  if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0303c204 + 2) == '\x04') {
    uVar2 = *(undefined2 *)&p_vfo_display_state->field_0x13_0;
  }
  else {
    uVar2 = *(undefined2 *)&p_vfo_display_state->field_0x11_0;
  }
  iVar3 = uint16_classify_by_sign_and_high_nibble(uVar2);
  *(undefined1 *)PTR_active_screen_visible_rows_0303c1f0 = 8;
  if (iVar3 == 1) {
    uVar4 = 0x32;
  }
  else {
    uVar4 = 0x69;
  }
  ctcss_dcs_list_row_render
            (*(undefined1 *)p_active_screen_flag_0003e5d5,*(undefined1 *)p_active_screen_state_word,
             uVar4);
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

