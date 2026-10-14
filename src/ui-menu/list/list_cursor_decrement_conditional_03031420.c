/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_cursor_decrement_conditional @ 03031420 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_cursor_decrement_conditional(undefined1 *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if (*(char *)((uint)p_menu_screen_state->index_0x5 + DAT_03031490 + 2) == '\x01') {
    uVar1 = 0x32;
  }
  else {
    uVar1 = 0x69;
  }
  list_cursor_decrement(param_1,param_2,uVar1);
  ctcss_dcs_list_row_render(*param_1,*param_2,uVar1);
  return;
}

