/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_row_text_buffer_clear @ 03035010 (file base 0x03000000; code starts at 0x03001000)
 * Size: 12 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void list_row_text_buffer_clear(void)

{
  undefined4 *puVar1;
  
  puVar1 = p_list_row_text_buffer;
  *(undefined1 *)p_list_row_text_buffer = 0;
  *(undefined1 *)((int)puVar1 + 0x1a) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  return;
}

