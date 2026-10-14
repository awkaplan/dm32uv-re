/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_display_debounce_and_hw_flag_clear @ 03060060 (file base 0x03000000; code starts at 0x03001000)
 * Size: 468 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte vfo_display_debounce_and_hw_flag_clear(void)

{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = vfo_display_state_nibble_bits_check();
  if (iVar3 == 0) {
    *(undefined1 *)PTR_DAT_0306031c = 0;
    puVar1 = PTR_DAT_03060304;
    bVar2 = PTR_DAT_03060304[0x1d];
    PTR_DAT_03060320[0x1e] = 0;
    puVar1[0x16] = 0;
    puVar1[0x1d] = bVar2 & 0xfc;
    puVar1[0x14] = 0;
    puVar1[4] = 0;
    puVar1[0x15] = 0;
    *(undefined4 *)(puVar1 + 0x18) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    p_radio_mode_state_0003e318[2].flags_0x2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf;
    *(undefined1 *)PTR_DAT_03060324 = 0;
    zero_4entry_16byte_table_and_related_fields();
    bVar2 = 0;
  }
  else {
    if (*(byte *)PTR_DAT_0306017c < 4) {
      *(byte *)PTR_DAT_0306017c = *(byte *)PTR_DAT_0306017c + 1;
    }
    else {
      rf_mode_state_clear_and_reinit_if_mode2();
      iVar3 = get_current_mode_state1();
      if (((iVar3 != 0) &&
          (iVar3 = get_current_mode_state1(), puVar1 = PTR_DAT_03060184, iVar3 == 3)) &&
         ((p_vfo_freq_display_state->flags_0x10 & 1) == 0)) {
        PTR_DAT_03060184[0x12] = 0;
        puVar1[0xf] = 0;
        dtmf_digit_input_handler(4);
      }
      *(undefined1 *)PTR_DAT_03060188 = 0;
      iVar3 = get_current_mode_state2();
      if (((iVar3 != 0) &&
          (iVar3 = get_current_mode_state2(), puVar1 = PTR_DAT_03060184, iVar3 == 1)) &&
         ((PTR_DAT_0306018c[1] & 2) == 0)) {
        PTR_DAT_03060184[0x1c] = 0;
        puVar1[0x1d] = 0;
        set_flag_byte_03064328(2);
      }
      if ((((p_vfo_display_state->flags_0x8 & 0xf0) == 0) &&
          (((*(byte *)PTR_DAT_03060194 >> 2 & 3) + 3 & 3) < 2)) &&
         ((PTR_DAT_03060198[0x35] & 0xc) == 4)) {
        uVar4 = hw_status_bit10_read();
        if (((PTR_DAT_03060198[0x35] & 0xc) == 0) || ((PTR_DAT_03060198[0x35] & 0xc) == 4)) {
          if ((uVar4 & 2) != 0) {
            *PTR_DAT_0306019c = 0;
            PTR_DAT_030601a0[0x1d] = PTR_DAT_030601a0[0x1d] & 0xfc | 1;
          }
        }
        else if ((uVar4 & 1) != 0) {
          *PTR_DAT_03060300 = 0;
          PTR_DAT_03060304[0x1d] = PTR_DAT_03060304[0x1d] & 0xfc | 1;
        }
      }
      if ((*(byte *)PTR_DAT_03060308 & 0x20) == 0) {
        *(byte *)PTR_DAT_03060308 = *(byte *)PTR_DAT_03060308 & 0xdf | 0x20;
        *(undefined2 *)&p_tx_ptt_ui_state->field_0x60_0 = 0;
        if (((((PTR_DAT_03060310[0x35] & 0xc) == 0) ||
             ((p_radio_mode_state_0003e318[1].flags_0x7 & 0x20) != 0)) &&
            ((*(byte *)((int)PTR_DAT_03060308 + 3) & 2) == 0)) &&
           (((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0 ||
            ((p_dm32_settings_block04[0x6d] & 4) == 0)))) {
          PTR_DAT_03060304[0x1d] = PTR_DAT_03060304[0x1d] & 0xfd | 2;
        }
      }
    }
    bVar2 = *(byte *)PTR_DAT_03060308 >> 5 & 1;
  }
  return bVar2;
}

