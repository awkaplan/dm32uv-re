/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: peripheral_reset_gpio_pulse_sequence_variant_030654d8 @ 030654d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void peripheral_reset_gpio_pulse_sequence_variant_030654d8(void)

{
  gpio_set_output_bit(0x19);
  iram_delay_call_arg2();
  gpio_set_output_bit(0x1a);
  iram_delay_call_arg2();
  iram_delay_call_arg2();
  iram_delay_call_arg2();
  gpio_clear_output_bit(0x1a);
  iram_delay_call_arg2();
  iram_delay_call_arg2();
  iram_delay_call_arg2();
  gpio_clear_output_bit(0x19);
  iram_delay_call_arg2();
  return;
}

