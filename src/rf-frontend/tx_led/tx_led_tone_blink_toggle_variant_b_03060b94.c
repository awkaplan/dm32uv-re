/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_led_tone_blink_toggle_variant_b @ 03060b94 (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_led_tone_blink_toggle_variant_b(void)

{
  char cVar1;
  undefined1 *puVar2;
  
  cVar1 = PTR_DAT_03060d0c[1];
  PTR_DAT_03060d0c[1] = cVar1 + 1U;
  puVar2 = PTR_DAT_03060d0c;
  if (4 < (byte)(cVar1 + 1U)) {
    PTR_DAT_03060d0c[1] = 0;
    if ((puVar2[4] & 1) == 0) {
      tx_led_or_tone_off();
      tx_led_or_tone_on();
      PTR_DAT_03060d0c[4] = PTR_DAT_03060d0c[4] & 0xfe | 1;
    }
    else {
      tx_led_or_tone_off_conditional_variant_030609ec();
      tx_led_or_tone_off_conditional();
      PTR_DAT_03060d0c[4] = PTR_DAT_03060d0c[4] & 0xfe;
    }
  }
  return;
}

