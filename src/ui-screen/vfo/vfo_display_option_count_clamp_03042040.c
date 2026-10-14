/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_display_option_count_clamp @ 03042040 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_display_option_count_clamp(void)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = p_vfo_display_state->flags_0x9 & 0x3f;
  *(byte *)p_active_screen_state_word = bVar2;
  *(undefined1 *)PTR_active_screen_subtype_0304216c = 0xe;
  *(ushort *)p_active_screen_index_list = *(byte *)p_vfo_freq_display_state + 1;
  if (bVar2 < 0x21) {
    cVar1 = *(char *)p_active_screen_state_word;
    *(char *)p_menu_selected_item_index = cVar1;
    bVar2 = cVar1 + 1;
    *(byte *)p_active_screen_flag_0003e5d5 = bVar2;
    if (8 < bVar2) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
    }
  }
  else {
    *(undefined1 *)p_active_screen_state_word = 0;
    *(undefined1 *)p_menu_selected_item_index = 0;
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
  }
  return;
}

