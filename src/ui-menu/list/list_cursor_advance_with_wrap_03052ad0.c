/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_cursor_advance_with_wrap @ 03052ad0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void list_cursor_advance_with_wrap(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = *(char *)p_active_screen_flag_0003e5d5;
  if (cVar1 == '\b') {
    if (*(byte *)p_active_screen_state_word + 1 == (uint)*(byte *)p_active_screen_option_count) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
      *(undefined1 *)p_active_screen_state_word = 0;
    }
    else {
      *(byte *)p_active_screen_state_word = *(byte *)p_active_screen_state_word + 1;
    }
  }
  else {
    cVar2 = *(char *)p_active_screen_state_word;
    *(char *)p_active_screen_state_word = cVar2 + '\x01';
    if (*(char *)p_active_screen_option_count == (char)(cVar2 + '\x01')) {
      *(undefined1 *)p_active_screen_state_word = 0;
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
    }
    else {
      *(char *)p_active_screen_flag_0003e5d5 = cVar1 + '\x01';
    }
  }
  return;
}

