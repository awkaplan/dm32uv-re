/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_led_tone_off_on_event_flag @ 0305e2c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_led_tone_off_on_event_flag(void)

{
  byte bVar1;
  
  bVar1 = get_event_flags_byte_dispatch(7);
  if ((bVar1 & 1) != 0) {
    tx_led_or_tone_off_conditional();
    if (p_tx_ptt_ui_state->field_0x7 != 8) {
      p_call_active_flag[1] = p_call_active_flag[1] & 0xfe | 1;
    }
    update_event_flags_byte_dispatch(7,1);
  }
  return;
}

