/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_mode_ui_tick @ 030175c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 142 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_mode_ui_tick(void)

{
  int iVar1;
  uint uVar2;
  
  if ((PTR_DAT_030177c4[3] & 2) == 0) {
    mode_transition_cleanup();
    iVar1 = tx_is_inhibited();
    if (((iVar1 == 0) && ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) == 0)) &&
       (iVar1 = get_current_mode_state2(), iVar1 != 0)) {
      set_flag_byte_03064328(1);
    }
    iVar1 = tx_is_inhibited();
    if (iVar1 == 0) {
      uVar2 = vfo_active_side_mode_nibble();
    }
    else {
      uVar2 = (uint)(p_vfo_display_state->flags_0x8 >> 4);
    }
    if (uVar2 == 2) {
      PTR_DAT_030177cc[3] = PTR_DAT_030177cc[3] & 0xfd | 2;
      ui_event_notify_alt(0xd);
      uVar2 = 0;
    }
    iVar1 = get_current_mode_state1();
    if ((iVar1 != 0) && (iVar1 == 3)) {
      uVar2 = (byte)PTR_DAT_030177d0[0x10] >> 5 & 3;
    }
    if (uVar2 == 0) {
      dtmf_key_poll_tick();
    }
    else {
      ui_event_notify_dispatch_by_code(uVar2);
    }
  }
  return;
}

