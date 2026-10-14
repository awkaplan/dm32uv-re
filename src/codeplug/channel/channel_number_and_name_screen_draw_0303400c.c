/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_number_and_name_screen_draw @ 0303400c (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_number_and_name_screen_draw(void)

{
  undefined1 auStack_20 [16];
  undefined1 uStack_10;
  
  uStack_10 = 0;
  display_fill_rect(0,0,0xf0,0x1b,0);
  memcpy_bytes_iram(auStack_20,DAT_03034110,0x10);
  display_draw_number_centered(1,0xffff,0,(uint)auStack_20);
  list_string_format_and_draw();
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_draw_string_from_table(0);
  return;
}

