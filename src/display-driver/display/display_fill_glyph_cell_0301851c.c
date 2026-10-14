/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_fill_glyph_cell @ 0301851c (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_fill_glyph_cell(short param_1,short param_2,undefined2 param_3)

{
  char cVar1;
  char cVar2;
  
  display_set_window(param_2,param_1,param_2 + 7,param_1 + 0xf);
  lcd_ram_write_begin();
  cVar2 = '\0';
  cVar1 = '\x10';
  do {
    do {
      lcd_write_pixel(param_3);
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
    cVar2 = cVar2 + '\x01';
    cVar1 = '\x10';
  } while (cVar2 != '\b');
  return;
}

