/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_dual_index_state2_check_and_flag @ 030454a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_screen_dual_index_state2_check_and_flag(void)

{
  if ((*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_030455e0 + 2) == '\x02') &&
     (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_030455e4 + 2) == '\x02')) {
    *(undefined1 *)PTR_active_screen_subtype_030455e8 = 0x16;
    *(undefined1 *)PTR_DAT_030455ec = 0;
  }
  return;
}

