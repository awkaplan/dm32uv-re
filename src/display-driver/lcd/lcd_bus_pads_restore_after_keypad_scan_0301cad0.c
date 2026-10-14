/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: lcd_bus_pads_restore_after_keypad_scan @ 0301cad0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 18 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void lcd_bus_pads_restore_after_keypad_scan(void)

{
  dword dVar1;
  
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX2;
  SystemControl_Type_11000000.IO_DIPLEX2 = dVar1 & 0xffff01ff;
  return;
}

