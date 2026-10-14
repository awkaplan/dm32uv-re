/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_value_display_or_fallback @ 03040a8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 142 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_block_value_display_or_fallback(void)

{
  ushort block_id;
  undefined1 auStack_20 [20];
  
  if (PTR_DAT_03040b60[0x34] == '\0') {
    lcd_blit_image_from_spi_flash(0,0,0xf0,0x140,0x25800);
  }
  else if (PTR_DAT_03040b60[0x34] == '\x01') {
    block_id = flash_block_id_resolve_locked(4);
    memset_bytes(auStack_20,0,0x11);
    flash_block_read(block_id,1,auStack_20,0x10);
    display_draw_number_centered(100,0xffff,0,(uint)auStack_20);
    memset_bytes(auStack_20,0,0x11);
    flash_block_read(block_id,0xf,auStack_20,0x10);
    display_draw_number_centered(0x82,0xffff,0,(uint)auStack_20);
  }
  else {
    battery_percentage_display_update();
  }
  settings_set_menu_hold_interval(PTR_DAT_03040b60[0x3a]);
  return;
}

