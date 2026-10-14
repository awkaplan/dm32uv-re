/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: main_menu_reset_and_enter @ 0303c9fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void main_menu_reset_and_enter(void)

{
  reentrant_state_reset_sequence();
  write_status_mode_byte_pair(0x69,1);
  dialog_history_flush_and_reset();
  call_setup_sm_reset();
  PTR_DAT_0303cacc[10] = 0;
  if ((PTR_DAT_0303cac8[0x11] & 1) == 0) {
    *(undefined1 *)PTR_active_screen_subtype_0303cac4 = 0x17;
  }
  else {
    *(undefined1 *)PTR_active_screen_subtype_0303cac4 = 0x25;
  }
  main_menu_screen_dispatch();
  return;
}

