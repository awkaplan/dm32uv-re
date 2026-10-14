/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_event_maybe_forward_to_dialog @ 030139c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void keypad_event_maybe_forward_to_dialog(void)

{
  int iVar1;
  
  iVar1 = keypad_dispatch_not_inhibited();
  if (iVar1 == 0) {
    return;
  }
  if ((*(byte *)PTR_DAT_03013bcc & 0x40) != 0) {
    return;
  }
  if ((PTR_DAT_03013bd0[1] & 1) == 0) {
    FUN_03013400();
    return;
  }
  if (((PTR_DAT_03013bd4[8] & 1) == 0) && ((p_radio_mode_state_0003e318->flags_0x7 & 0x22) == 0)) {
    if ((p_radio_mode_state_0003e318->flags_0x4 & 4) != 0) {
      return;
    }
    if ((PTR_DAT_03013bdc[0x2b] & 8) != 0) goto LAB_03013a2e;
    keypad_debounce_and_commit_event();
  }
  if ((p_radio_mode_state_0003e318->flags_0x4 & 4) != 0) {
    return;
  }
LAB_03013a2e:
  keypad_poll_and_dispatch_key_event();
  return;
}

