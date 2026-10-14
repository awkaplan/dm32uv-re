/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: rf_tx_disable_sequence @ 0002b4a0 (IRAM address; the boot stub copies these bytes from program flash 0x030db0c0)
 * Size: 92 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rf_tx_disable_sequence(void)

{
  if ((*PTR_DAT_0002b508 & 1) != 0) {
    busy_wait_delay_loop_4arg(0x640);
    tx_audio_dac_envelope_ramp(1,0,PTR_DAT_0002b504[0x28]);
    busy_wait_delay_loop_4arg(300);
    pa_band_select_vhf_uhf_gpio(0);
    *PTR_DAT_0002b508 = *PTR_DAT_0002b508 & 0xfe;
    busy_wait_delay_loop_4arg(700);
    rf_retune_and_apply_channel_mode(*(undefined4 *)(PTR_DAT_0002b500 + 4));
    antenna_switch_select_gpio_24_22(1);
    busy_wait_delay_loop_4arg(0x32);
  }
  return;
}

