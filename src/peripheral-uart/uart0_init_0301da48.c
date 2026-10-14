/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: uart0_init @ 0301da48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-uart
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 uart0_init(uint param_1)

{
  dword dVar1;
  undefined2 *puVar2;
  
  dVar1 = UART0_14030000.LCR;
  UART0_14030000.LCR = dVar1 | 0x80;
  param_1 = ((uint)*PTR_DAT_0301daa8 >> 4) / param_1;
  UART0_14030000.RBR_THR_DLL = param_1 & 0xff;
  UART0_14030000.IER_DLH = param_1 >> 8 & 0xff;
  dVar1 = UART0_14030000.LCR;
  UART0_14030000.LCR = dVar1 & 0xffffff7f;
  UART0_14030000.IER_DLH = 0;
  dVar1 = UART0_14030000.LCR;
  UART0_14030000.LCR = dVar1 | 3;
  UART0_14030000.IIR_FCR = 0x67;
  UART0_14030000.IER_DLH = 5;
  *(undefined2 *)PTR_DAT_0301dabc = 0;
  *(undefined2 *)PTR_DAT_0301dac0 = 0;
  puVar2 = PTR_DAT_0301dab8;
  *PTR_DAT_0301dab8 = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  OSSemCreate_shared_name_wrapper(_DAT_0301dac4,0);
  irq_controller_unmask_and_register_handler(_DAT_0301dac8,0x2c);
  return 0;
}

