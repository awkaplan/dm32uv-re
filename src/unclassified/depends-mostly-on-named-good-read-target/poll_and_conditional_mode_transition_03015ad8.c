/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: poll_and_conditional_mode_transition @ 03015ad8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void poll_and_conditional_mode_transition(void)

{
  int iVar1;
  
  iVar1 = poll_condition_group(0x1c);
  if ((iVar1 != 0) && (iVar1 = read_byte_field_0302e118(), iVar1 == 0)) {
    mode_transition_cleanup();
    iVar1 = vfo_active_side_mode_nibble();
    if ((iVar1 == 1) || (iVar1 == 3)) {
      ui_event_notify(0x21);
    }
    else {
      iVar1 = ui_dialog_tick_scheduler(0);
      if (iVar1 != 0) {
        p_radio_mode_state_0003e318[1].flags_0x6 =
             p_radio_mode_state_0003e318[1].flags_0x6 & 0xef | 0x10;
        request_display_refresh(4);
      }
    }
  }
  return;
}

