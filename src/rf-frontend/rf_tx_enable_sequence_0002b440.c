/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: rf_tx_enable_sequence @ 0002b440 (IRAM address; the boot stub copies these bytes from program flash 0x030db060)
 * Size: 94 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rf_tx_enable_sequence(void)

{
  antenna_switch_select_gpio_24_22(0);
  if ((PTR_DAT_0002b4fc[8] & 6) == 4) {
    busy_wait_delay_loop_4arg(0x4b0);
  }
  else if ((PTR_DAT_0002b4fc[8] & 6) == 2) {
    busy_wait_delay_loop_4arg(1000);
  }
  else {
    busy_wait_delay_loop_4arg(800);
  }
  fd6818b_retune_and_reinit_sequence(*(undefined4 *)PTR_DAT_0002b500);
  pa_band_select_vhf_uhf_gpio(1);
  tx_audio_dac_envelope_ramp(1,1,PTR_DAT_0002b504[0x28]);
  *PTR_DAT_0002b508 = *PTR_DAT_0002b508 & 0xfe | 1;
  return;
}

