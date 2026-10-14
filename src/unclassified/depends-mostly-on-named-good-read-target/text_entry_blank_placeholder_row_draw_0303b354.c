/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_blank_placeholder_row_draw @ 0303b354 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void text_entry_blank_placeholder_row_draw(void)

{
  undefined1 *value;
  
  value = p_text_entry_buffer;
  memset_bytes(p_text_entry_buffer,0,0x10);
  *value = 0x5f;
  value[2] = 0x5f;
  value[4] = 0x5f;
  value[6] = 0x5f;
  value[8] = 0x5f;
  value[10] = 0x5f;
  value[0xc] = 0x5f;
  value[0xe] = 0x5f;
  value[1] = 0x20;
  value[3] = 0x20;
  value[5] = 0x20;
  value[7] = 0x20;
  value[9] = 0x20;
  value[0xb] = 0x20;
  value[0xd] = 0x20;
  display_draw_number_centered(100,0xffff,0,(uint)value);
  return;
}

