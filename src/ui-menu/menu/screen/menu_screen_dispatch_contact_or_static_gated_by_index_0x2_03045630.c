/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_dispatch_contact_or_static_gated_by_index_0x2 @ 03045630 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_screen_dispatch_contact_or_static_gated_by_index_0x2(void)

{
  char cVar1;
  
  if (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_030457e0 + 2) == '\x01') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_030457e4 + 2);
    if (cVar1 == '\0') {
      menu_screen_load_contact_list();
    }
    else if (cVar1 == '\x01') {
      menu_screen_load_static();
    }
  }
  return;
}

