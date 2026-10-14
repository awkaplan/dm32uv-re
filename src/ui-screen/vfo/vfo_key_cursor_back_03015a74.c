/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_key_cursor_back @ 03015a74 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_key_cursor_back(void)

{
  int iVar1;
  
  if (((PTR_DAT_03015ab8[3] & 0x40) == 0) && (iVar1 = poll_condition_group(0x16), iVar1 != 0)) {
    iVar1 = get_current_mode_state1();
    if (iVar1 == 6) {
      iVar1 = vfo_frequency_digit_cursor_step_back();
      if (iVar1 == 0) {
        ui_event_notify(0x21);
      }
      else {
        ui_event_notify(0x1a);
      }
    }
    else {
      ui_event_notify(0x21);
    }
  }
  return;
}

