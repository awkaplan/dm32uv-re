/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_key_release_history_dispatch @ 03040154 (file base 0x03000000; code starts at 0x03001000)
 * Size: 230 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_key_release_history_dispatch(void)

{
  char cVar1;
  dialog_flags_from_flash *pdVar2;
  undefined4 *puVar3;
  dialog_history_ui_state *pdVar4;
  int iVar5;
  uint uVar6;
  uint unaff_r4;
  
  puVar3 = PTR_DAT_030402dc;
  if (((p_dialog_flags_from_flash->flags_0x1 & 3) == 0) && (p_tx_ptt_ui_state->field_0x9 != 4)) {
    if ((p_radio_mode_state_0003e318[2].flags_0x2 & 1) == 0) {
      cVar1 = PTR_DAT_030402d4[1];
      if (((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\x02')) {
        tx_gate_write_call_record(0);
        dialog_history_menu_step_and_refresh();
      }
      else if (p_dialog_history_ui_state->field_0x3 == 0x69) {
        if ((p_radio_mode_state_0003e318[1].flags_0x7 & 1) != 0) {
          settings_block4_array_entry_read(unaff_r4 - 8 & 0xff,PTR_DAT_030402dc);
          iVar5 = list_screen_event_dispatch(*puVar3,(uint)*(uint3 *)(puVar3 + 1));
          if (iVar5 == 0) {
            ui_event_notify(0x21);
          }
        }
      }
      else {
        field_edit_multikey_input_dispatch(unaff_r4 & 0xff);
      }
    }
    else {
      p_radio_mode_state_0003e318[2].flags_0x2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0xfe;
      pdVar2 = p_dialog_flags_from_flash;
      p_dialog_flags_from_flash->flags_0x1 = p_dialog_flags_from_flash->flags_0x1 & 0xf7;
      pdVar2->flags_0x2d = pdVar2->flags_0x2d & 0xf3;
      *(byte *)PTR_DAT_030402d0 = *(byte *)PTR_DAT_030402d0 & 0x7f;
      tx_gate_write_call_record();
      history_queue_pop();
    }
  }
  else {
    tx_gate_write_call_record(0);
  }
  if (p_dialog_history_ui_state->field_0x4 != 0) {
    history_entry_cancel_pending();
    pdVar4 = p_dialog_history_ui_state;
    uVar6 = PTR_PTR_03040818[(uint)p_dialog_history_ui_state->field_0x3 * 3];
    *PTR_DAT_0304081c = uVar6;
    (*(code *)(uVar6 & 0xfffffffe))();
    pdVar4->field_0x4 = 0;
  }
  if (unaff_r4 == 0x18) {
    PTR_DAT_03040820[1] = 0;
  }
  os_sem_post(p_ucos_mutex_0003e4c0);
  return;
}

