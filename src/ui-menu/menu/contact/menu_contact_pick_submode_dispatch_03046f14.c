/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_contact_pick_submode_dispatch @ 03046f14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_contact_pick_submode_dispatch(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_03046fdc + 2);
  if (bVar1 == 2) {
    menu_contact_pick_method_option_init_03046e00();
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      menu_search_contact_manual_dial_option_init();
    }
  }
  else if (bVar1 == 3) {
    menu_message_entry_actions_option_init();
  }
  else if (bVar1 == 4) {
    cVar2 = *(char *)((uint)p_menu_screen_state->field_0x7 + DAT_03046fbc + 2);
    if (cVar2 == '\0') {
      menu_screen_load_contact_list();
    }
    else if (cVar2 == '\x01') {
      menu_screen_load_static();
    }
  }
  return;
}

