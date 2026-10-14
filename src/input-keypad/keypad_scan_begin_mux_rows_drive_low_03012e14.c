/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_scan_begin_mux_rows_drive_low @ 03012e14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void keypad_scan_begin_mux_rows_drive_low(void)

{
  dword dVar1;
  
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX2;
  SystemControl_Type_11000000.IO_DIPLEX2 = dVar1 | 0xfe00;
  dVar1 = GPIOC_14110000.SWPORTA_DR;
  GPIOC_14110000.SWPORTA_DR = dVar1 & 0xfffff07f;
  gpio_pin_set_output_level(0x47,0);
  gpio_pin_set_output_level(0x48,0);
  gpio_pin_set_output_level(0x49,0);
  gpio_pin_set_output_level(0x4a,0);
  gpio_pin_set_output_level(0x4b,0);
  return;
}

