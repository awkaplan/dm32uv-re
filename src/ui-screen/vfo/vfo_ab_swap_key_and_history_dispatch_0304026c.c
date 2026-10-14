/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_ab_swap_key_and_history_dispatch @ 0304026c (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_ab_swap_key_and_history_dispatch(void)

{
  dialog_history_ui_state *pdVar1;
  int iVar2;
  uint uVar3;
  int unaff_r4;
  
  iVar2 = get_current_mode_state1();
  if (iVar2 == 0) {
    vfo_ab_swap();
    tx_gate_write_call_record(1);
  }
  if (p_dialog_history_ui_state->field_0x4 != 0) {
    history_entry_cancel_pending();
    pdVar1 = p_dialog_history_ui_state;
    uVar3 = PTR_PTR_03040818[(uint)p_dialog_history_ui_state->field_0x3 * 3];
    *PTR_DAT_0304081c = uVar3;
    (*(code *)(uVar3 & 0xfffffffe))();
    pdVar1->field_0x4 = 0;
  }
  if (unaff_r4 == 0x18) {
    PTR_DAT_03040820[1] = 0;
  }
  os_sem_post(p_ucos_mutex_0003e4c0);
  return;
}

