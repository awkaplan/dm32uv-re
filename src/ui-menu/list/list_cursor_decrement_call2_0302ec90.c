/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_cursor_decrement_call2 @ 0302ec90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_cursor_decrement_call2(undefined1 *param_1,undefined1 *param_2)

{
  vfo_freq_display_state *pvVar1;
  
  pvVar1 = p_vfo_freq_display_state;
  list_cursor_decrement(param_1,param_2,p_vfo_freq_display_state->field_0x1 + 1);
  channel_list_screen_with_add(*param_1,*param_2,pvVar1->field_0x1 + 1);
  return;
}

