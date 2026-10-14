/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: clock_uart_reconfigure @ 0305499c (file base 0x03000000; code starts at 0x03001000)
 * Size: 208 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-clock
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void clock_uart_reconfigure(void)

{
  dword dVar1;
  
  stage_hook_dispatch(5);
  UART0_14030000.IIR_FCR = 6;
  if ((*(byte *)PTR_DAT_03054b84 & 4) != 0) {
    UART_Type_14040000.IIR_FCR = 6;
    *(undefined1 *)PTR_DAT_03054b88 = 0;
    *(byte *)PTR_DAT_03054b8c = *(byte *)PTR_DAT_03054b8c & 0xfe;
    *(undefined1 *)PTR_DAT_03054b90 = 0;
    memset_bytes(DAT_03054b94,0,0x96);
  }
  PTR_DAT_03054b98[0xd2] = PTR_DAT_03054b98[0xd2] | 3;
  SystemControl_Type_11000000.LCSFC_BAUDR = 2;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x10;
  SystemControl_Type_11000000.CLK_MGR_REG0x10 = dVar1 & 0xff000000;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x10;
  SystemControl_Type_11000000.CLK_MGR_REG0x10 = dVar1 | 0x40623;
  SystemControl_Type_11000000.CLK_MGR_REG0x28 = 0x20005;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x24;
  SystemControl_Type_11000000.CLK_MGR_REG0x24 = dVar1 & 0xfffffff0;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x24;
  SystemControl_Type_11000000.CLK_MGR_REG0x24 = dVar1 | 2;
  SystemControl_Type_11000000.CLK_MGR_REG0x2c = 0xd00200;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x2c;
  SystemControl_Type_11000000.CLK_MGR_REG0x2c = dVar1 | 0x200000;
  *PTR_DAT_03054b9c = 48000000;
  *PTR_DAT_03054ba0 = 48000000;
  *PTR_DAT_03054ba4 = 24000000;
  *PTR_DAT_03054ba8 = 24000000;
  timer_ch0_configure_periodic(0,100);
  timer_channel_readwrite_dispatch(5,48000);
  timer_channel_enable_dispatch(5);
  return;
}

