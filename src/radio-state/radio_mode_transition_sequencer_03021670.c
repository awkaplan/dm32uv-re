/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_mode_transition_sequencer @ 03021670 (file base 0x03000000; code starts at 0x03001000)
 * Size: 298 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_mode_transition_sequencer(byte param_1)

{
  dword dVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  SystemControl_Type_11000000.SYS_SOFT_RSTN = 0xfffffffc;
  if ((byte)(param_1 - 1) < 4) {
    if (param_1 == 4) {
      SystemControl_Type_11000000.LAYER2_TXRX_CTRL = 0;
      SystemControl_Type_11000000.LAYER2_CONTROL = 0;
      SystemControl_Type_11000000.WORK_MODE = 0x13;
    }
    else {
      SystemControl_Type_11000000.LAYER2_CONTROL = 0x82;
      SystemControl_Type_11000000.LAYER2_TXRX_CTRL = 0x81;
      SystemControl_Type_11000000.WORK_MODE = 2;
      if ((param_1 == 1) || (param_1 == 3)) {
        puVar3 = PTR_DAT_0302182c + 9;
        puVar4 = PTR_DAT_0302182c;
        do {
          *(undefined1 *)puVar4 = 0x5f;
          puVar2 = PTR_DAT_0302182c;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        } while (puVar4 != puVar3);
        sram_16000000_block_write(0,PTR_DAT_0302182c,0x24);
        sram_16000000_block_write(0x24,puVar2,0x24);
        goto LAB_0302176a;
      }
    }
    if (param_1 == 2) {
      puVar3 = PTR_DAT_0302182c + 9;
      puVar4 = PTR_DAT_0302182c;
      do {
        *(undefined1 *)puVar4 = 0x55;
        puVar2 = PTR_DAT_0302182c;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      } while (puVar4 != puVar3);
      sram_16000000_block_write(0,PTR_DAT_0302182c,0x24);
      sram_16000000_block_write(0x24,puVar2,0x24);
      modem_fm_ptt_set(0);
      return;
    }
  }
  else if (param_1 < 0xb) {
    SystemControl_Type_11000000.WORK_MODE = 0x80;
  }
  else {
    SystemControl_Type_11000000.REG_0x168 = 0x98;
    SystemControl_Type_11000000.RF_RECV_DELAY = 0;
    SystemControl_Type_11000000.WORK_MODE = 0x22;
    SystemControl_Type_11000000.LAYER2_CONTROL = 0x40;
    SystemControl_Type_11000000.LAYER2_TXRX_CTRL = 0xc1;
    dVar1 = SystemControl_Type_11000000.RECV_BS_SYNC_H;
    SystemControl_Type_11000000.RECV_BS_SYNC_H = dVar1 | 0x80000000;
    dVar1 = SystemControl_Type_11000000.RECV_MS_SYNC_H;
    SystemControl_Type_11000000.RECV_MS_SYNC_H = dVar1 | 0x80000000;
  }
LAB_0302176a:
  if ((byte)(param_1 - 5) < 3) {
    SystemControl_Type_11000000.WORK_MODE = 0x80;
    modem_fm_ptt_set(1);
  }
  else {
    modem_fm_ptt_set(0);
    if (param_1 == 9) {
      modem_rf_mode_transition_apply(0,0,1);
    }
  }
  return;
}

