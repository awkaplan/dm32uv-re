/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_list_screen_adjust_call @ 03040bc8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 20 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void contact_list_screen_adjust_call(void)

{
  undefined4 uVar1;
  
  tx_gate_write_call_record(1);
  uVar1 = get_state_field_03035024();
  contact_select_screen_adjust(uVar1,DAT_03040d4c,DAT_03040d50);
  key_event_filter_dispatch1();
  write_status_mode_byte_pair
            (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03040eec),0);
  return;
}

