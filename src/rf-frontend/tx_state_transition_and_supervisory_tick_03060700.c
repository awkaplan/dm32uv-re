/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_state_transition_and_supervisory_tick @ 03060700 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_state_transition_and_supervisory_tick(void)

{
  byte bVar1;
  
  bVar1 = p_vfo_display_state->flags_0x8 & 0xf0;
  if ((bVar1 == 0) || ((PTR_DAT_03060864[3] & 3) == 1)) {
    if ((p_radio_mode_state_0003e318[1].flags_0x7 & 0x20) == 0) {
      hw_status_debounce_and_alarm_poll();
    }
  }
  else if ((p_radio_mode_state_0003e318[1].flags_0x7 & 0x20) == 0) {
    if ((bVar1 != 0x10) && ((PTR_DAT_03060864[3] & 3) != 3)) {
      return;
    }
    idle_timeout_counter_tick();
    return;
  }
  tx_supervisory_tick();
  return;
}

