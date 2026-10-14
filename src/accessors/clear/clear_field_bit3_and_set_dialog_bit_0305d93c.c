/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: clear_field_bit3_and_set_dialog_bit @ 0305d93c (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: accessors
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void clear_field_bit3_and_set_dialog_bit(void)

{
  p_dialog_flags_from_flash->flags_0x2d = p_dialog_flags_from_flash->flags_0x2d & 0xf3;
  dialog_state_set_bit3_wrapper();
  return;
}

