/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_forward_navigation_commit @ 0305dd94 (file base 0x03000000; code starts at 0x03001000)
 * Size: 344 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_forward_navigation_commit(byte param_1)

{
  ushort uVar1;
  bool bVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_5c [8];
  byte bStack_54;
  undefined1 auStack_28 [22];
  char cStack_12;
  
  iVar4 = get_current_mode_state1();
  if (iVar4 == 0) {
    mode_transition_cleanup();
    uVar5 = vfo_active_side_mode_nibble();
  }
  else {
    uVar5 = p_vfo_freq_display_state->flags_0x10 >> 5 & 3;
  }
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) != 0) {
    return;
  }
  if ((p_tx_ptt_ui_state->field_0x7 == 4) && ((p_dialog_flags_from_flash->flags_0x1 & 3) == 1)) {
    return;
  }
  iVar4 = poll_condition_group(7);
  if (iVar4 == 0) {
    return;
  }
  if (p_dialog_flags_from_flash->field_0x32 == 0) {
    bVar2 = false;
  }
  else {
    bVar2 = uVar5 != 0 && uVar5 != 2;
    if (p_dialog_flags_from_flash->field_0x32 == 1) goto LAB_0305de12;
  }
  SUBPIECE_SET(uVar1, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
  SUBPIECE_SET(uVar1, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
  if (uVar1 < *(ushort *)&p_dialog_flags_from_flash->field_0x34_0) {
    bVar2 = false;
  }
LAB_0305de12:
  channel_frequencies_read_and_decode
            (*(undefined2 *)&p_dialog_flags_from_flash->field_0x34_0,auStack_5c);
  if (((bStack_54 & 8) != 0) && (p_dialog_flags_from_flash->field_0x32 != 1)) {
    bVar2 = false;
  }
  if (*(short *)&p_dialog_flags_from_flash->field_0x34_0 == 0) {
    if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
      uVar3 = vfo_tx_contact_field_read_wrapper((byte)p_dm32_settings_block04[0x2d] >> 7);
      *(undefined2 *)&p_dialog_flags_from_flash->field_0x36_0 = uVar3;
    }
    else {
      uVar3 = vfo_channel_apply_delegate(*(undefined2 *)&p_vfo_freq_display_state->field_0x54_0);
      *(undefined2 *)&p_dialog_flags_from_flash->field_0x36_0 = uVar3;
    }
  }
  else {
    uVar3 = vfo_channel_apply_delegate();
    *(undefined2 *)&p_dialog_flags_from_flash->field_0x36_0 = uVar3;
  }
  record_read_by_index(*(undefined2 *)&p_dialog_flags_from_flash->field_0x36_0,auStack_28);
  if (((cStack_12 == '\x04') || (p_dialog_flags_from_flash->field_0x32 == 1)) && (bVar2)) {
    if ((*(char *)((int)PTR_DAT_0305df00 + 1) != '\0') && ((*(byte *)PTR_DAT_0305df00 & 1) == 0)) {
      *(byte *)PTR_DAT_0305df00 = *(byte *)PTR_DAT_0305df00 & 0xfe | 1;
    }
    iVar4 = get_current_mode_state1();
    if (iVar4 != 0) {
      dtmf_inject_digits_2_0();
    }
    p_dialog_flags_from_flash->flags_0x2f =
         p_dialog_flags_from_flash->flags_0x2f & 0x8f | (param_1 & 7) << 4;
    sysctl_bit8_toggle_with_mode_flag(0);
    dialog_commit_channel_selection();
  }
  else {
    ui_event_notify(0x1b);
  }
  return;
}

