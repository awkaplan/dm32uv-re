/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_history_action_dispatch_with_tx_gate @ 03040052 (file base 0x03000000; code starts at 0x03001000)
 * Size: 220 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_history_action_dispatch_with_tx_gate(void)

{
  char cVar1;
  dialog_history_ui_state *pdVar2;
  undefined *puVar3;
  uint uVar4;
  int unaff_r4;
  
  if ((p_dialog_flags_from_flash->flags_0x1 & 3) == 0) {
    cVar1 = PTR_DAT_03040138[1];
    if (((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\x02')) {
      tx_gate_write_call_record(0);
      dialog_history_menu_step_and_refresh();
    }
    else {
      if ((((p_dialog_history_ui_state->index_0x2 != 1) || (p_tx_ptt_ui_state->field_0x9 != 0)) ||
          ((p_dialog_history_ui_state->field_0x3 == 0x4d ||
           (p_dialog_history_ui_state->field_0x3 == 0x46)))) &&
         (((p_dialog_history_ui_state->field_0x3 != 0x5b &&
           (*(char *)PTR_active_screen_subtype_03040150 != '\n')) &&
          ((*(char *)PTR_active_screen_subtype_03040150 != '\b' &&
           ((*(byte *)p_call_active_flag & 8) == 0)))))) {
        tx_gate_write_call_record(1);
      }
      puVar3 = PTR_s_66660501_03040140;
      pdVar2 = p_dialog_history_ui_state;
      p_dialog_history_ui_state->field_0x3 =
           PTR_s_66660501_03040140[(uint)p_dialog_history_ui_state->field_0x3 * 0xc + 0x12];
      uVar4 = *(uint *)(puVar3 + (uint)pdVar2->field_0x3 * 0xc + 0x14);
      *PTR_DAT_03040144 = uVar4;
      (*(code *)(uVar4 & 0xfffffffe))();
      if ((((pdVar2->index_0x2 != 1) || (p_tx_ptt_ui_state->field_0x9 != 0)) ||
          (pdVar2->field_0x3 == 0x4d)) || (pdVar2->field_0x3 == 0x46)) {
        event_record_guarded_by_state_flags();
      }
    }
  }
  else {
    p_dialog_history_ui_state->field_0x4 = 0;
    tx_gate_write_call_record(0);
  }
  if (p_dialog_history_ui_state->field_0x4 != 0) {
    history_entry_cancel_pending();
    pdVar2 = p_dialog_history_ui_state;
    uVar4 = PTR_PTR_03040818[(uint)p_dialog_history_ui_state->field_0x3 * 3];
    *PTR_DAT_0304081c = uVar4;
    (*(code *)(uVar4 & 0xfffffffe))();
    pdVar2->field_0x4 = 0;
  }
  if (unaff_r4 == 0x18) {
    PTR_DAT_03040820[1] = 0;
  }
  os_sem_post(p_ucos_mutex_0003e4c0);
  return;
}

