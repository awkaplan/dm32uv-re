/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_menu_wrapper_dispatch @ 0304fab4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_menu_wrapper_dispatch(void)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304fb24 + 2);
  if (cVar1 == '\x01') {
    uVar2 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_0304fbf0 + 2);
    if (uVar2 == 0) {
      write_status_mode_byte_pair(0x2a,1);
    }
    else if ((uVar2 - 1 & 0xff) < 10) {
      if (uVar2 < 10) {
                    /* WARNING: Could not recover jumptable at 0x0304fbe6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(PTR_PTR_0304fbf4[uVar2] & 0xfffffffe))();
        return;
      }
      settings_write_dispatcher(0x4f,*(undefined1 *)p_active_screen_state_word);
      menu_row_highlight_draw();
      dialog_show_icon_and_number_from_ptr();
    }
    else if (uVar2 == 0xb) {
      settings_write_dispatcher(0x51,*(undefined1 *)p_active_screen_state_word);
      dialog_show_icon_and_number_from_ptr();
    }
  }
  else if (cVar1 == '\0') {
    uVar2 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_0304faf8 + 2);
    if (uVar2 < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x0304faea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0304fb28[uVar2] & 0xfffffffe))();
      return;
    }
    menu_row_highlight_draw();
    dialog_show_icon_and_number_from_ptr();
  }
  else if (cVar1 == '\x02') {
    uVar2 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_0304fcb0 + 2);
    if (uVar2 < 0x12) {
                    /* WARNING: Could not recover jumptable at 0x0304fca6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0304fcb4[uVar2] & 0xfffffffe))();
      return;
    }
    menu_row_highlight_draw();
    dialog_show_icon_and_number_from_ptr();
  }
  else if (cVar1 == '\x03') {
    uVar2 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_0304fe84 + 2);
    if (uVar2 < 0x15) {
                    /* WARNING: Could not recover jumptable at 0x0304fe7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0304fe88[uVar2] & 0xfffffffe))();
      return;
    }
    menu_row_highlight_draw();
    dialog_show_icon_and_number_from_ptr();
  }
  return;
}

