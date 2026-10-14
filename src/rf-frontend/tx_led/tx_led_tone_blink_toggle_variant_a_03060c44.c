/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_led_tone_blink_toggle_variant_a @ 03060c44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_led_tone_blink_toggle_variant_a(void)

{
  char cVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  if ((((p_dialog_flags_from_flash->flags_0x1 & 3) != 1) ||
      (((bVar3 = p_dialog_flags_from_flash->flags_0x1f & 0x78, bVar3 == 0x20 || (bVar3 == 0x28)) &&
       (p_dialog_flags_from_flash->field_0x3f == 2)))) &&
     (cVar1 = PTR_DAT_03060d0c[3], PTR_DAT_03060d0c[3] = cVar1 + 1U, puVar2 = PTR_DAT_03060d0c,
     2 < (byte)(cVar1 + 1U))) {
    PTR_DAT_03060d0c[3] = 0;
    if ((puVar2[4] & 2) == 0) {
      tx_led_or_tone_off_conditional_variant_030609ec();
      tx_led_or_tone_off_conditional();
      PTR_DAT_03060d0c[4] = PTR_DAT_03060d0c[4] & 0xfd | 2;
    }
    else {
      tx_led_or_tone_off();
      tx_led_or_tone_on();
      PTR_DAT_03060d0c[4] = PTR_DAT_03060d0c[4] & 0xfd;
    }
  }
  return;
}

