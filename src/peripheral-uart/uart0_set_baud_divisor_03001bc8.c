/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: uart0_set_baud_divisor @ 03001bc8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-uart
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void uart0_set_baud_divisor(uint param_1)

{
  dword dVar1;
  
  dVar1 = UART0_14030000.LCR;
  UART0_14030000.LCR = dVar1 | 0x80;
  param_1 = ((uint)*PTR_LAB_03001c00 >> 4) / param_1;
  UART0_14030000.RBR_THR_DLL = param_1 & 0xff;
  UART0_14030000.IER_DLH = param_1 >> 8 & 0xff;
  dVar1 = UART0_14030000.LCR;
  UART0_14030000.LCR = dVar1 & 0xffffff7f;
  UART0_14030000.IER_DLH = 0;
  dVar1 = UART0_14030000.LCR;
  UART0_14030000.LCR = dVar1 | 3;
  UART0_14030000.IIR_FCR = 0x67;
  return;
}

