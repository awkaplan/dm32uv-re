/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_tick_event_dispatcher @ 0305e02c (file base 0x03000000; code starts at 0x03001000)
 * Size: 474 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_tick_event_dispatcher(void)

{
  tx_ptt_ui_state *ptVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  bVar2 = get_event_flags_byte_dispatch(0xb);
  if ((bVar2 & 1) == 0) {
    if ((bVar2 & 2) == 0) {
      if ((bVar2 & 4) != 0) {
        update_event_flags_byte_dispatch(0xb,4);
      }
    }
    else {
      update_event_flags_byte_dispatch(0xb,2);
      iVar3 = dialog_state_get_field_03020df8();
      if ((((iVar3 != *(int *)&p_tx_ptt_ui_state->field_0x10_0) ||
           (bVar2 = p_tx_ptt_ui_state->field_0x14, uVar4 = radio_mode_classify_from_status_bytes(),
           bVar2 != uVar4)) || ((p_tx_ptt_ui_state->flags_0xa & 0x30) != 0x10)) ||
         ((*(byte *)p_call_active_flag & 1) == 0)) {
        p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xbf | 0x40;
      }
      if (PTR_DAT_0305e1bc[0x328] == '\x01') {
        dialog_history_show_if_present();
        PTR_DAT_0305e1bc[0x328] = 0;
      }
      if ((((p_dialog_flags_from_flash->flags_0x1d & 1) != 0) &&
          (bVar2 = p_dialog_flags_from_flash->flags_0x1e & 0x70, bVar2 != 0x10)) && (bVar2 != 0x20))
      {
        dialog_tick_idle_check();
      }
      uVar5 = dialog_state_get_field_03020df8();
      ptVar1 = p_tx_ptt_ui_state;
      *(undefined4 *)&p_tx_ptt_ui_state->field_0x10_0 = uVar5;
      bVar2 = radio_mode_classify_from_status_bytes();
      ptVar1->field_0x14 = bVar2;
      ptVar1->field_0xc = ptVar1->field_0xc & 0xfe;
      *(undefined2 *)&ptVar1->field_0x60_0 = 0;
      *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xfe | 1;
      iVar3 = get_field_0301ea64_0x14();
      if (((iVar3 == 0) && ((p_dialog_flags_from_flash->flags_0x1e & 0x70) != 0x10)) &&
         ((p_dialog_flags_from_flash->flags_0x1 & 3) != 1)) {
        iVar3 = radio_mode_classify_from_status_bytes();
        if (iVar3 == 1) {
          if ((p_dm32_settings_block04[0x43] & 4) != 0) {
            character_input_event_dispatcher(0x25);
          }
        }
        else {
          iVar3 = radio_mode_classify_from_status_bytes();
          if (((iVar3 == 2) || (iVar3 = radio_mode_classify_from_status_bytes(), iVar3 == 3)) &&
             ((p_dm32_settings_block04[0x43] & 2) != 0)) {
            character_input_event_dispatcher(0x23);
          }
        }
      }
      if ((PTR_DAT_0305e300[3] & 1) != 0) {
        PTR_DAT_0305e300[3] = PTR_DAT_0305e300[3] & 0xbf | 0x40;
      }
    }
  }
  else {
    update_event_flags_byte_dispatch(0xb,1);
    iVar3 = dialog_state_get_field_03020df8();
    if (((iVar3 != *(int *)&p_tx_ptt_ui_state->field_0x10_0) ||
        (bVar2 = p_tx_ptt_ui_state->field_0x14, uVar4 = radio_mode_classify_from_status_bytes(),
        bVar2 != uVar4)) ||
       (((p_tx_ptt_ui_state->flags_0xa & 0x30) != 0x10 || ((*(byte *)p_call_active_flag & 1) == 0)))
       ) {
      p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xbf | 0x40;
    }
    uVar5 = dialog_state_get_field_03020df8();
    ptVar1 = p_tx_ptt_ui_state;
    *(undefined4 *)&p_tx_ptt_ui_state->field_0x10_0 = uVar5;
    *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xfe | 1;
    bVar2 = radio_mode_classify_from_status_bytes();
    ptVar1->field_0x14 = bVar2;
    ptVar1->field_0xc = ptVar1->field_0xc & 0xfe;
    *(undefined2 *)&ptVar1->field_0x60_0 = 0;
    if ((PTR_DAT_0305e1b8[3] & 1) != 0) {
      PTR_DAT_0305e1b8[3] = PTR_DAT_0305e1b8[3] & 0xbf | 0x40;
    }
  }
  *(undefined1 *)p_tx_ptt_ui_state = 10;
  return;
}

