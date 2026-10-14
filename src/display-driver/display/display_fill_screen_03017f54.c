/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_fill_screen @ 03017f54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
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

void display_fill_screen(ushort color)

{
  short sVar1;
  short sVar2;
  
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  display_set_window(0,0x1b,0xef,0x121);
  lcd_ram_write_begin();
  sVar2 = 0;
  sVar1 = 0xf0;
  do {
    do {
      lcd_write_pixel(color);
      sVar1 = sVar1 + -1;
    } while (sVar1 != 0);
    sVar2 = sVar2 + 1;
    sVar1 = 0xf0;
  } while (sVar2 != 0x107);
  os_sem_post(p_ucos_mutex_00039344);
  return;
}

