/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_selector_byte_dispatch_3way @ 03043b38 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_selector_byte_dispatch_3way(void)

{
  char cVar1;
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03043c8c + 2);
  if (cVar1 == '\x03') {
    menu_contact_view_or_apply_option_init_030439cc();
  }
  else if (cVar1 == '\x04') {
    table_entry_select_and_index_list_build_variant13_03041470();
  }
  else if (cVar1 == '\0') {
    contact_dispatch_by_count_range();
  }
  return;
}

