/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hr_c7000_modem_core_register_init @ 03023608 (file base 0x03000000; code starts at 0x03001000)
 * Size: 498 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void hr_c7000_modem_core_register_init(void)

{
  dword dVar1;
  int iVar2;
  uint uVar3;
  
  FUN_030294cc();
  FUN_03024f00();
  SystemControl_Type_11000000.SYS_SOFT_RSTN = 400;
  OSTimeDly_ms_wrapper(2);
  dVar1 = SystemControl_Type_11000000.DAC_CONTROL;
  SystemControl_Type_11000000.DAC_CONTROL = dVar1 | 0x80000000;
  dVar1 = SystemControl_Type_11000000.DAC_CONTROL;
  SystemControl_Type_11000000.DAC_CONTROL = dVar1 & 0xffffffdf;
  dVar1 = SystemControl_Type_11000000.DAC_CONTROL;
  SystemControl_Type_11000000.DAC_CONTROL = dVar1 & 0xfffffffb;
  dVar1 = SystemControl_Type_11000000.ADC_CONTROL;
  SystemControl_Type_11000000.ADC_CONTROL = dVar1 | 0x41c3;
  SystemControl_Type_11000000.AUDIO_BUFFER_CLR = 3;
  OSTimeDly_ms_wrapper(2);
  SystemControl_Type_11000000.SEND_DATA_SYNC_H = _DAT_0302377c;
  SystemControl_Type_11000000.SEND_DATA_SYNC_L = _DAT_03023780;
  SystemControl_Type_11000000.SEND_RC_SYNC_H = _DAT_03023784;
  SystemControl_Type_11000000.SEND_RC_SYNC_L = _DAT_03023788;
  SystemControl_Type_11000000.RECV_MS_SYNC_H = _DAT_0302377c;
  SystemControl_Type_11000000.RECV_MS_SYNC_L = _DAT_03023780;
  SystemControl_Type_11000000.RECV_BS_SYNC_H = _DAT_0302378c;
  SystemControl_Type_11000000.RECV_BS_SYNC_L = _DAT_03023790;
  SystemControl_Type_11000000.RECV_TDMA1_SYNC_H = _DAT_03023794;
  SystemControl_Type_11000000.RECV_TDMA1_SYNC_L = _DAT_03023798;
  SystemControl_Type_11000000.RECV_TDMA2_SYNC_H = _DAT_0302379c;
  SystemControl_Type_11000000.RECV_TDMA2_SYNC_L = _DAT_030237a0;
  SystemControl_Type_11000000.RECV_RC_SYNC_H = _DAT_03023784;
  SystemControl_Type_11000000.RECV_RC_SYNC_L = _DAT_03023788;
  SystemControl_Type_11000000.THRESHOLD_VALUE = _DAT_030237a4;
  SystemControl_Type_11000000.PI_CRC_MASK = 0x6969;
  SystemControl_Type_11000000.RS_H_MASK = _DAT_030237a8;
  SystemControl_Type_11000000.RS_H_INIT = 0;
  SystemControl_Type_11000000.RS_T_MASK = _DAT_030237ac;
  SystemControl_Type_11000000.RS_T_INIT = 0;
  SystemControl_Type_11000000.CSBK_CRC_MASK = 0xa5a5;
  SystemControl_Type_11000000.MBCH_CRC_MASK = 0xaaaa;
  SystemControl_Type_11000000.DATAH_CRC_MASK = 0xcccc;
  SystemControl_Type_11000000.REG_0x370 = 0xf0;
  SystemControl_Type_11000000.REG_0x374 = 0x1ff;
  SystemControl_Type_11000000.REG_0x378 = 0x10f;
  SystemControl_Type_11000000.REG_0x37c = 0;
  SystemControl_Type_11000000.CRC8_INIT = 0;
  SystemControl_Type_11000000.VOICE_EMB_CTRL = 0;
  SystemControl_Type_11000000.SCRAMBLE_REG = 0;
  SystemControl_Type_11000000.SYS_INTERP_MASK = 0x1187f;
  SystemControl_Type_11000000.LAYER2_SLOT_PRE = _DAT_030237b0;
  SystemControl_Type_11000000.LAYER2_SLOTON = 0x11;
  SystemControl_Type_11000000.FM_DEV_COEF = 0x33500;
  dVar1 = SystemControl_Type_11000000.RF_MODE;
  iVar2 = FUN_0300c2c8();
  if (iVar2 == 3) {
    dVar1 = SystemControl_Type_11000000.RF_MODE;
    SystemControl_Type_11000000.RF_MODE = dVar1 & 0xffffff7f;
  }
  iVar2 = FUN_0300c2c4();
  if (iVar2 == 4) {
    dVar1 = SystemControl_Type_11000000.RF_MODE;
    SystemControl_Type_11000000.RF_MODE = dVar1 | 0x2000000;
    dVar1 = SystemControl_Type_11000000.RF_MODE;
    SystemControl_Type_11000000.RF_MODE = dVar1 | 0x1000000;
    dVar1 = SystemControl_Type_11000000.RF_MODE;
    SystemControl_Type_11000000.RF_MODE = dVar1 | 0x260000;
    SystemControl_Type_11000000.REG_0x168 = 0x14;
    SystemControl_Type_11000000.RF_RECV_DELAY = 14000;
  }
  else {
    SystemControl_Type_11000000.REG_0x168 = 0x98;
    SystemControl_Type_11000000.RF_RECV_DELAY = 0;
  }
  dVar1 = SystemControl_Type_11000000.RF_MODE;
  SystemControl_Type_11000000.RF_MODE = dVar1 & 0xffffff9f;
  dVar1 = SystemControl_Type_11000000.RF_MODE;
  uVar3 = FUN_0300c2c8();
  SystemControl_Type_11000000.RF_MODE = dVar1 | (uVar3 & 3) << 5;
  dVar1 = SystemControl_Type_11000000.RF_MODE;
  SystemControl_Type_11000000.RF_MODE = dVar1 & 0xffff9fff;
  dVar1 = SystemControl_Type_11000000.RF_MODE;
  uVar3 = FUN_0300c2c4();
  SystemControl_Type_11000000.RF_MODE = dVar1 | (uVar3 & 3) << 0xd;
  dVar1 = SystemControl_Type_11000000.RF_MODE;
  SystemControl_Type_11000000.RF_MODE = dVar1 | 0x8000;
  SystemControl_Type_11000000.RX_IF_FREQ = 0xbb800;
  SystemControl_Type_11000000.TX_IF_FREQ = 0xbb800;
  dVar1 = SystemControl_Type_11000000.RF_MODE;
  SystemControl_Type_11000000.RF_MODE = dVar1 & 0x5fffffff;
  SystemControl_Type_11000000.WORK_MODE = 0x6e;
  modem_queue_drain_and_stop();
  mmio_11000074_bits_7_8_set_clear(0);
  return;
}

