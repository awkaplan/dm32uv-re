/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_history_flush_and_reset @ 03036a48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_history_flush_and_reset(void)

{
  undefined2 *puVar1;
  
  if (p_dialog_history_ui_state->field_0x4 == 1) {
    ring_buffer_multi_table_append_and_flush();
    *(undefined1 *)p_active_screen_state_word = 0;
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
    puVar1 = p_active_screen_index_list;
    *(char *)PTR_DAT_03036bd8 = (char)*p_active_screen_index_list;
    *puVar1 = 0;
  }
  return;
}

