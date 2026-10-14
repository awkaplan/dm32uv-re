/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_key_from_vfo_mode_guard @ 0305be64 (file base 0x03000000; code starts at 0x03001000)
 * Size: 306 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_key_from_vfo_mode_guard(char param_1,void *param_2,char param_3)

{
  int iVar1;
  byte bVar2;
  uint request_id;
  
  if (param_1 == '\x03') {
    request_id = (uint)(param_3 != '\x01');
    if (((((*(byte *)p_call_active_flag & 1) != 0) ||
         (iVar1 = get_field_0301ea64_0x14(), iVar1 == 1)) && (p_tx_ptt_ui_state->field_0x14 == 1))
       && (*(void **)&p_tx_ptt_ui_state->field_0x10_0 == param_2)) {
      p_tx_ptt_ui_state->field_0xc = p_tx_ptt_ui_state->field_0xc & 0xef | 0x10;
    }
  }
  else if (param_1 == '\x04') {
    request_id = 2;
  }
  else if (param_1 == '\x05') {
    request_id = 3;
  }
  else {
    request_id = 0;
  }
  clear_field_bit3_and_set_dialog_bit();
  PTR_DAT_0305bf80[0x12] = 0;
  if ((*(byte *)((int)PTR_DAT_0305bf84 + 1) & 2) != 0) {
    audio_pa_enable_gate(0);
  }
  bVar2 = p_vfo_display_state->flags_0x8 & 0xf0;
  if (((bVar2 == 0) || (bVar2 == 0x20)) && ((*PTR_DAT_0305bf84 & 0x18000) == 0x8000)) {
    tx_abort_on_condition();
    vfo_screen_redraw();
    display_refresh_tone_mode_icon();
  }
  fd6818b_reg50_tx_audio_mute_set();
  bVar2 = p_vfo_display_state->flags_0x8 & 0xf0;
  if (bVar2 != 0) {
    if (bVar2 != 0x20) {
      *PTR_DAT_0305c0f4 = 1;
      p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf | 0x10;
      fd6818b_reg_write_wrapper();
      fd6818b_reg_write(FD6818_PAGE0_REG_51H,0);
      radio_id_display_field_prep_dispatch();
      dialog_request_enqueue(request_id,param_2);
      return;
    }
    PTR_DAT_0305bf88[3] = PTR_DAT_0305bf88[3] & 0xfd | 2;
    ui_event_notify_alt(0xd);
  }
  if ((p_tx_ptt_ui_state->field_0xc & 1) != 0) {
    p_tx_ptt_ui_state->field_0xc = p_tx_ptt_ui_state->field_0xc & 0xfe;
  }
  status_byte_bit5_set_clear_wrapper(0,1);
  *(undefined2 *)&p_tx_ptt_ui_state->field_0x60_0 = 0;
  dialog_request_enqueue(10,param_2);
  radio_mode_entry_reinit_and_display();
  return;
}

