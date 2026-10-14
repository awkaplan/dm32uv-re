/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: asterisk_key_and_history_dispatch @ 03040242 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void asterisk_key_and_history_dispatch(void)

{
  dialog_history_ui_state *pdVar1;
  uint uVar2;
  int unaff_r4;
  
  if (((p_dialog_flags_from_flash->flags_0x1 & 3) == 0) && (p_tx_ptt_ui_state->field_0x9 != 4)) {
    asterisk_key_dispatch();
    event_record_guarded_by_state_flags();
  }
  else {
    tx_gate_write_call_record(0);
  }
  if (p_dialog_history_ui_state->field_0x4 != 0) {
    history_entry_cancel_pending();
    pdVar1 = p_dialog_history_ui_state;
    uVar2 = PTR_PTR_03040818[(uint)p_dialog_history_ui_state->field_0x3 * 3];
    *PTR_DAT_0304081c = uVar2;
    (*(code *)(uVar2 & 0xfffffffe))();
    pdVar1->field_0x4 = 0;
  }
  if (unaff_r4 == 0x18) {
    PTR_DAT_03040820[1] = 0;
  }
  os_sem_post(p_ucos_mutex_0003e4c0);
  return;
}

