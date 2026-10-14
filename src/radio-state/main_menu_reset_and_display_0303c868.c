/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: main_menu_reset_and_display @ 0303c868 (file base 0x03000000; code starts at 0x03001000)
 * Size: 222 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void main_menu_reset_and_display(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  dialog_history_flush_and_reset();
  if (PTR_DAT_0303c95c[4] == '\x01') {
    iVar2 = get_current_mode_state2();
    if ((iVar2 != 0) && (iVar2 = get_current_mode_state2(), iVar2 != 4)) {
      vfo_exit_dual_watch_and_refresh();
    }
    if ((*PTR_DAT_0303c960 & 0x18000) == 0x8000) {
      if ((PTR_DAT_0303c964[0x2d] & 0x80) == 0) {
        *(undefined2 *)PTR_DAT_0303c968 = 0xb1;
      }
      else {
        *(undefined2 *)PTR_DAT_0303c968 = 0x3b;
      }
      if (PTR_DAT_0303c964[0x6c] == '\0') {
        *(undefined2 *)PTR_DAT_0303c968 = 0x59;
      }
      *(short *)PTR_DAT_0303c968 = *(short *)PTR_DAT_0303c968 + 0x2d;
      *(undefined2 *)PTR_text_entry_current_char_0303c96c = 0x2f;
    }
    else if (((PTR_DAT_0303c964[0x2d] & 4) == 0) && ((PTR_DAT_0303c970[0x15] & 4) == 0)) {
      PTR_DAT_0303c970[6] = PTR_DAT_0303c970[6] & 0xf7 | 8;
      text_entry_status_glyph_set_by_settings_flags_b((byte)PTR_DAT_0303c964[0x2d] >> 7);
    }
    else {
      PTR_DAT_0303c970[6] = PTR_DAT_0303c970[6] & 0xfb | 4;
      text_entry_status_glyph_set_by_settings_flags_a((byte)PTR_DAT_0303c964[0x2d] >> 7);
    }
  }
  puVar1 = PTR_DAT_0303c974;
  *(undefined1 *)PTR_active_screen_option_count_0303c978 = PTR_DAT_0303c974[4];
  *p_active_screen_option_ptr_array = *(undefined4 *)puVar1;
  *(undefined1 *)PTR_active_screen_subtype_0303c950 = puVar1[5];
  main_menu_screen_dispatch();
  return;
}

