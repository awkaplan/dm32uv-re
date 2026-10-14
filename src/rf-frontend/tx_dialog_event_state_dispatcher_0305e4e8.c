/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_dialog_event_state_dispatcher @ 0305e4e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 400 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_dialog_event_state_dispatcher(void)

{
  bool bVar1;
  tx_ptt_ui_state *ptVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  bVar3 = get_event_flags_byte_dispatch(3);
  if ((bVar3 & 1) == 0) {
    if ((bVar3 & 2) == 0) {
      if ((bVar3 & 4) != 0) {
        update_event_flags_byte_dispatch(3,4);
        *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xbf | 0x40;
        tx_led_or_tone_off_conditional();
        uVar6 = dialog_state_get_field_0302128c();
        ptVar2 = p_tx_ptt_ui_state;
        *(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0 = uVar6;
        bVar3 = config_status_from_bytes_1_2();
        ptVar2->field_0x1c = bVar3;
      }
    }
    else {
      update_event_flags_byte_dispatch(3,2);
      ptVar2 = p_tx_ptt_ui_state;
      p_tx_ptt_ui_state->field_0x5f = p_tx_ptt_ui_state->field_0x5f & 0xfe;
      memset_bytes(&ptVar2->field_0x3f,0,0x20);
      memset_bytes(DAT_0305e660,0,0x20);
      uVar6 = dialog_state_get_field_0302128c();
      *(undefined4 *)&ptVar2->field_0x18_0 = uVar6;
      bVar3 = config_status_from_bytes_1_2();
      ptVar2->field_0x1c = bVar3;
      *p_call_active_flag = *p_call_active_flag & 0xbd | 2;
      if ((ptVar2->field_0xc & 1) != 0) {
        ptVar2->field_0xc = ptVar2->field_0xc & 0xfe;
      }
      *(undefined2 *)&p_tx_ptt_ui_state->field_0x60_0 = 0;
      tx_voice_start_begin_record();
    }
  }
  else {
    if ((p_dialog_flags_from_flash->flags_0x1 & 3) == 1) {
      bVar1 = (byte)(p_dialog_flags_from_flash->field_0x32 - 3) < 2;
    }
    else {
      bVar1 = false;
    }
    if (((*(byte *)p_dialog_flags_from_flash & 1) == 0) && (!bVar1)) {
      tx_led_or_tone_off_conditional();
    }
    dialog_set_pending_render_flag(1);
    iVar4 = dialog_state_get_field_0302128c();
    if (((iVar4 != *(int *)&p_tx_ptt_ui_state->field_0x18_0) ||
        (bVar3 = p_tx_ptt_ui_state->field_0x1c, uVar5 = config_status_from_bytes_1_2(),
        bVar3 != uVar5)) || ((p_tx_ptt_ui_state->flags_0xa & 0x30) != 0x20)) {
      p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xbf | 0x40;
    }
    uVar6 = dialog_state_get_field_0302128c();
    ptVar2 = p_tx_ptt_ui_state;
    *(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0 = uVar6;
    bVar3 = config_status_from_bytes_1_2();
    ptVar2->field_0x1c = bVar3;
    ptVar2->field_0x5f = ptVar2->field_0x5f & 0xfe;
    memset_bytes(&ptVar2->field_0x3f,0,0x20);
    memset_bytes(DAT_0305e660,0,0x20);
    if ((((*(byte *)p_dialog_flags_from_flash & 1) == 0) && (ptVar2->field_0x9 != 3)) &&
       (iVar4 = get_field_0301ea64_0x14(), iVar4 != 2)) {
      character_input_event_dispatcher(0x29);
    }
    *p_call_active_flag = *p_call_active_flag & 0xbd | 2;
    *(undefined2 *)&p_tx_ptt_ui_state->field_0x60_0 = 0;
    update_event_flags_byte_dispatch(3,1);
  }
  return;
}

