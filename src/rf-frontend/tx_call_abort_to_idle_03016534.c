/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_call_abort_to_idle @ 03016534 (file base 0x03000000; code starts at 0x03001000)
 * Size: 164 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_call_abort_to_idle(void)

{
  int iVar1;
  
  if ((*(char *)PTR_DAT_030165dc != '\0') || (iVar1 = get_current_mode_state1(), iVar1 != 0)) {
    ui_event_notify(0x21);
    return;
  }
  if ((*(byte *)PTR_call_active_flag_030165e8 & 8) != 0) {
    return;
  }
  iVar1 = vfo_active_side_mode_nibble();
  if (iVar1 == 2) {
    if ((PTR_DAT_030165e4[3] & 2) != 0) goto LAB_03016594;
    PTR_DAT_030165ec[3] = PTR_DAT_030165ec[3] & 0xfd | 2;
    ui_event_notify_alt(0xd);
  }
  if ((PTR_DAT_030165e4[3] & 2) == 0) {
    if ((PTR_DAT_030165e4[1] & 0x80) != 0) {
      ui_event_notify(0x21);
      return;
    }
    mode_transition_cleanup();
    if (((PTR_DAT_030165f0[8] & 0xf0) != 0) && ((PTR_DAT_030165f0[8] & 0xf0) != 0x20)) {
      ui_event_notify(0x21);
      return;
    }
    tx_abort_and_radio_state_reset();
    return;
  }
LAB_03016594:
  radio_idle_state_reset(1);
  return;
}

