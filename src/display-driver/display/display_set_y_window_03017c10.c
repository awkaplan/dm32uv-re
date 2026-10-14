/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_set_y_window @ 03017c10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_set_y_window(ushort y_start,ushort y_end)

{
  lcd_write_command(MIPI_DCS_SET_PAGE_ADDRESS);
  lcd_write_data(y_start >> 8);
  lcd_write_data(y_start & 0xff);
  lcd_write_data(y_end >> 8);
  lcd_write_data(y_end & 0xff);
  return;
}

