/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_stop_and_reset_to_idle @ 03037070 (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_stop_and_reset_to_idle(void)

{
  tx_audio_dac_envelope_ramp(1,0,0);
  pa_band_select_vhf_uhf_gpio(0);
  antenna_switch_select_gpio_24_22(0);
  tx_led_or_tone_on();
  tx_led_or_tone_off();
  radio_mode_reset_to_idle();
  if (0x31 < (byte)PTR_DAT_030372d8[0xa09]) {
    audio_pa_enable_gate(0);
  }
  history_queue_pop();
  noop_stub_0300c0ec();
  write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_030372d8[2] + DAT_030372e4),0);
  return;
}

