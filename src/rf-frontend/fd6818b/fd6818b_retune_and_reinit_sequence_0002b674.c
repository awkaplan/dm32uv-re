/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818b_retune_and_reinit_sequence @ 0002b674 (IRAM address; the boot stub copies these bytes from program flash 0x030db294)
 * Size: 42 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818b_retune_and_reinit_sequence(uint param_1)

{
  stage_hook_dispatch(4);
  gpio_interrupt_disable_bit(0x3b);
  fd6818_set_frequency(param_1 >> 0x10,param_1 & 0xffff);
  fd6818b_driver_state_reset();
  fd6818b_reg47_afout_clear_mode();
  fd6818b_init_seq_filter_ctcss_chipmode();
  fd6818b_reg50_tx_audio_unmute_set();
  return;
}

