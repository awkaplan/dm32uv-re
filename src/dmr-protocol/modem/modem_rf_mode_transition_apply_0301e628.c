/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_rf_mode_transition_apply @ 0301e628 (file base 0x03000000; code starts at 0x03001000)
 * Size: 462 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void modem_rf_mode_transition_apply(char param_1,char param_2,char param_3)

{
  dword dVar1;
  call_setup_sm_state_aux *pcVar2;
  call_setup_sm_state_aux *pcVar3;
  dword dVar4;
  dword dVar5;
  
  pcVar2 = p_call_setup_sm_state_aux;
  SystemControl_Type_11000000.SEND_RC_SYNC_H = DAT_0301e708;
  SystemControl_Type_11000000.SEND_RC_SYNC_L = DAT_0301e70c;
  SystemControl_Type_11000000.RECV_MS_SYNC_H = DAT_0301e710;
  SystemControl_Type_11000000.RECV_MS_SYNC_L = DAT_0301e714;
  SystemControl_Type_11000000.RECV_BS_SYNC_H = DAT_0301e718;
  SystemControl_Type_11000000.RECV_BS_SYNC_L = DAT_0301e71c;
  SystemControl_Type_11000000.RECV_TDMA1_SYNC_H = DAT_0301e720;
  SystemControl_Type_11000000.RECV_TDMA1_SYNC_L = DAT_0301e724;
  SystemControl_Type_11000000.RECV_TDMA2_SYNC_H = DAT_0301e728;
  SystemControl_Type_11000000.RECV_TDMA2_SYNC_L = DAT_0301e72c;
  SystemControl_Type_11000000.RECV_RC_SYNC_H = DAT_0301e708;
  SystemControl_Type_11000000.RECV_RC_SYNC_L = DAT_0301e70c;
  dVar5 = SystemControl_Type_11000000.WORK_MODE;
  dVar4 = SystemControl_Type_11000000.LOCAL_CC;
  dVar4 = dVar4 & 0xfffffcff;
  if (param_1 == '\0') {
    dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x2c;
    SystemControl_Type_11000000.CLK_MGR_REG0x2c = dVar1 | 0xc0;
    *(undefined1 *)p_call_setup_sm_state_aux = 1;
    dVar5 = dVar5 | 0x80;
  }
  else {
    dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x2c;
    SystemControl_Type_11000000.CLK_MGR_REG0x2c = dVar1;
    *(undefined1 *)p_call_setup_sm_state_aux = 0;
    pcVar3 = p_call_setup_sm_state_aux;
    if (param_2 == '\x04') {
      pcVar2->mode_0x1 = 4;
      dVar4 = dVar4 | 0x100;
      PTR_DAT_0301e734[7] = 8;
      pcVar3 = p_call_setup_sm_state_aux;
      pcVar2 = p_call_setup_sm_state_aux;
      dVar1 = SystemControl_Type_11000000.RF_CONTROL;
      SystemControl_Type_11000000.RF_CONTROL = dVar1 | 0x1a00;
      dVar1 = SystemControl_Type_11000000.RF_CONTROL;
      SystemControl_Type_11000000.RF_CONTROL = dVar1 | 0x12;
      dVar1 = SystemControl_Type_11000000.RF_MODE;
      SystemControl_Type_11000000.RF_MODE = dVar1 | 0x800;
      if (param_3 == '\0') {
        SystemControl_Type_11000000.SEND_DATA_SYNC_H = *PTR_DAT_0301e890;
        SystemControl_Type_11000000.SEND_DATA_SYNC_L = PTR_DAT_0301e890[1];
        dVar5 = dVar5 & 0x7e | 4;
        p_call_setup_sm_state_aux->field_0x3 = 0;
        pcVar3->field_0x4 = 0;
      }
      else {
        SystemControl_Type_11000000.SEND_DATA_SYNC_H = *PTR_DAT_0301e738;
        SystemControl_Type_11000000.SEND_DATA_SYNC_L = PTR_DAT_0301e738[1];
        dVar5 = dVar5 & 0xffffff7f | 5;
        p_call_setup_sm_state_aux->field_0x3 = 1;
        pcVar2->field_0x4 = 1;
      }
      dmr_call_config_state_reset_and_arm_timer();
      modem_tx_enable();
      dVar1 = SystemControl_Type_11000000.RECV_TDMA1_SYNC_H;
      SystemControl_Type_11000000.RECV_TDMA1_SYNC_H = dVar1 | 0x80000000;
      dVar1 = SystemControl_Type_11000000.RECV_TDMA2_SYNC_H;
      SystemControl_Type_11000000.RECV_TDMA2_SYNC_H = dVar1 | 0x80000000;
    }
    else {
      SystemControl_Type_11000000.SEND_DATA_SYNC_H = *PTR_DAT_0301e898;
      SystemControl_Type_11000000.SEND_DATA_SYNC_L = PTR_DAT_0301e898[1];
      dVar1 = SystemControl_Type_11000000.RF_CONTROL;
      SystemControl_Type_11000000.RF_CONTROL = dVar1 | 0x1500;
      dVar1 = SystemControl_Type_11000000.RF_CONTROL;
      SystemControl_Type_11000000.RF_CONTROL = dVar1 | 0x12;
      dVar1 = SystemControl_Type_11000000.RF_MODE;
      SystemControl_Type_11000000.RF_MODE = dVar1 & 0xfffff7ff;
      if (param_2 == '\x01') {
        p_call_setup_sm_state_aux->mode_0x1 = 1;
        pcVar2 = p_call_setup_sm_state_aux;
        if (param_3 == '\0') {
          dVar5 = dVar5 & 0x7e | 4;
          p_call_setup_sm_state_aux->field_0x3 = 0;
          pcVar2->field_0x4 = 0;
        }
        else {
          dVar5 = dVar5 & 0xffffff7f | 5;
          pcVar3->field_0x3 = 1;
          pcVar3->field_0x4 = 1;
        }
      }
      else {
        p_call_setup_sm_state_aux->mode_0x1 = 0;
        dVar5 = dVar5 & 0x7e | 4;
        pcVar3->field_0x3 = 0;
        pcVar3->field_0x4 = 0;
      }
      if ((p_call_setup_sm_state->flags_0x18 & 8) == 0) {
        PTR_DAT_0301e8a0[7] = 0;
      }
      else {
        PTR_DAT_0301e8a0[7] = 8;
        dVar4 = dVar4 | 0x100;
      }
      dVar1 = SystemControl_Type_11000000.RECV_BS_SYNC_H;
      SystemControl_Type_11000000.RECV_BS_SYNC_H = dVar1 | 0x80000000;
      dVar1 = SystemControl_Type_11000000.RECV_MS_SYNC_H;
      SystemControl_Type_11000000.RECV_MS_SYNC_H = dVar1 | 0x80000000;
    }
  }
  SystemControl_Type_11000000.WORK_MODE = dVar5;
  SystemControl_Type_11000000.LOCAL_CC = dVar4;
  return;
}

