/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_back_key_press_handler @ 03014a00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void keypad_back_key_press_handler(void)

{
  if ((PTR_DAT_03014ba4[2] & 4) != 0) {
    flash_quad_enable_and_system_reset();
  }
  if ((PTR_DAT_03014ba8[0x2b] & 8) == 0) {
    if ((*(char *)PTR_DAT_03014bb0 == '\0') && ((PTR_DAT_03014bb4[4] & 1) == 0)) {
      *PTR_DAT_03014bb8 = 1;
    }
    else {
      write_field_and_mbox_post(2,6);
    }
  }
  else {
    *(undefined1 *)PTR_DAT_03014bac = 1;
  }
  return;
}

