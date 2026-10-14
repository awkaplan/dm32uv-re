/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_menu_confirm_dispatch @ 03050414 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_menu_confirm_dispatch(void)

{
  char cVar1;
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03050568 + 2);
  if (cVar1 == '\0') {
    settings_menu_wrapper_dispatch();
  }
  else if (cVar1 == '\x01') {
    menu_confirm_apply_handler2();
  }
  return;
}

