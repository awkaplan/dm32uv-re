/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_uart1_init_9600 @ 0301d96c (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: gps
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 gps_uart1_init_9600(void)

{
  dword dVar1;
  
  gpio_pin_set_output_level(10,0);
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX0;
  SystemControl_Type_11000000.IO_DIPLEX0 = dVar1 & 0xfffffdff;
  dVar1 = UART_Type_14040000.LCR;
  UART_Type_14040000.LCR = dVar1 | 0x80;
  UART_Type_14040000.RBR_THR_DLL = (uint)*PTR_DAT_0301daa8 / 0x25800 & 0xff;
  UART_Type_14040000.IER_DLH = (uint)*PTR_DAT_0301daa8 / 0x25800 >> 8;
  dVar1 = UART_Type_14040000.LCR;
  UART_Type_14040000.LCR = dVar1 & 0xffffff7f;
  UART_Type_14040000.IER_DLH = 0;
  dVar1 = UART_Type_14040000.LCR;
  UART_Type_14040000.LCR = dVar1 | 3;
  UART_Type_14040000.IIR_FCR = 0xe7;
  UART_Type_14040000.IER_DLH = 5;
  OSSemCreate_shared_name_wrapper(_DAT_0301daac,1);
  irq_controller_unmask_and_register_handler(_DAT_0301dab0,0x2a);
  return 0;
}

