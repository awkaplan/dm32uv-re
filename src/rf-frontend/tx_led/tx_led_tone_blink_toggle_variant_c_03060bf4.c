/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_led_tone_blink_toggle_variant_c @ 03060bf4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_led_tone_blink_toggle_variant_c(void)

{
  byte bVar1;
  
  if ((p_dialog_flags_from_flash->flags_0x2d & 0x20) != 0) {
    if (p_dialog_flags_from_flash->field_0x2e == 0) {
      tx_led_or_tone_off_conditional_variant_030609ec();
      tx_led_or_tone_off_conditional();
    }
    bVar1 = p_dialog_flags_from_flash->field_0x2e + 1;
    p_dialog_flags_from_flash->field_0x2e = bVar1;
    if (1 < bVar1) {
      tx_led_or_tone_off();
      tx_led_or_tone_on();
      p_dialog_flags_from_flash->flags_0x2d = p_dialog_flags_from_flash->flags_0x2d & 0xdf;
    }
  }
  return;
}

