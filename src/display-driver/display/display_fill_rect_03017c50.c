/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_fill_rect @ 03017c50 (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
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

void display_fill_rect(short x0,short y0,short x1,short y1,ushort color)

{
  ushort uVar1;
  ushort uVar2;
  
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  display_set_window(x0,y0,x1 + -1,y1 + -1);
  lcd_ram_write_begin();
  if (y1 != y0) {
    uVar2 = 0;
    do {
      uVar1 = 0;
      if (x1 != x0) {
        do {
          lcd_write_pixel(color);
          uVar1 = uVar1 + 1;
        } while (uVar1 < (ushort)(x1 - x0));
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (ushort)(y1 - y0));
  }
  os_sem_post(p_ucos_mutex_00039344);
  return;
}

