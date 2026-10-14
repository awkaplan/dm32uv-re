/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: crystal_osc_and_timer5_init @ 03054a6c (file base 0x03000000; code starts at 0x03001000)
 * Size: 266 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-clock
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void crystal_osc_and_timer5_init(void)

{
  dword dVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  stage_hook_dispatch(5);
  uVar3 = DAT_03054bac;
  SystemControl_Type_11000000.LCSFC_BAUDR = 4;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x10;
  SystemControl_Type_11000000.CLK_MGR_REG0x10 = dVar1 & 0xff000000;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x10;
  SystemControl_Type_11000000.CLK_MGR_REG0x10 = dVar1 | 0x40712;
  SystemControl_Type_11000000.CLK_MGR_REG0x28 = 0x70006;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x24;
  SystemControl_Type_11000000.CLK_MGR_REG0x24 = dVar1 & 0xfffffff0;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x24;
  SystemControl_Type_11000000.CLK_MGR_REG0x24 = dVar1 | 2;
  *PTR_DAT_03054b9c = DAT_03054bac;
  *PTR_DAT_03054ba0 = uVar3;
  *PTR_DAT_03054ba4 = DAT_03054bb0;
  *PTR_DAT_03054ba8 = 24000000;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  SystemControl_Type_11000000.CLK_MGR_REG0x04 = dVar1 | 8;
  busy_wait_delay_loop_4arg(10);
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  SystemControl_Type_11000000.CLK_MGR_REG0x04 = dVar1 | 3;
  do {
    busy_wait_delay_loop_4arg(100);
    dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  } while (-1 < (int)dVar1);
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  SystemControl_Type_11000000.CLK_MGR_REG0x04 = dVar1 & 0xfffffffb;
  busy_wait_delay_loop_4arg(100);
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  SystemControl_Type_11000000.CLK_MGR_REG0x04 = dVar1 & 0xfffffff7;
  do {
    busy_wait_delay_loop_4arg(100);
    puVar2 = PTR_DAT_03054b98;
    dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  } while ((dVar1 & 0x40000000) == 0);
  SystemControl_Type_11000000.CLK_MGR_REG0x2c = DAT_03054bb4;
  PTR_DAT_03054b98[0xd2] = PTR_DAT_03054b98[0xd2] & 0xfe;
  puVar2[0xd2] = puVar2[0xd2] & 0xfd;
  timer_ch0_configure_periodic(0,100);
  timer_channel_readwrite_dispatch(5,(uint)*PTR_DAT_03054ba4 / 1000);
  timer_channel_enable_dispatch(5);
  UART0_14030000.IIR_FCR = 0xe7;
  if ((*(byte *)PTR_DAT_03054b84 & 4) != 0) {
    UART_Type_14040000.IIR_FCR = 0xe7;
  }
  return;
}

