/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_pop_or_status_flag2 @ 0303743c (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_pop_or_status_flag2(void)

{
  if ((*(byte *)PTR_DAT_0303750c & 2) == 0) {
    history_queue_pop();
  }
  else {
    write_status_mode_byte_pair
              (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03037514),0);
  }
  return;
}

