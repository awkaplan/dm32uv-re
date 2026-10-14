/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_header_status_bit4_toggle_and_draw @ 0302fc48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_header_status_bit4_toggle_and_draw(void)

{
  PTR_DAT_0302fe0c[3] = PTR_DAT_0302fe0c[3] & 0xef | ((byte)PTR_DAT_0302fe0c[3] >> 4 & 1 ^ 1) << 4;
  dialog_header_number_draw_variant();
  return;
}

