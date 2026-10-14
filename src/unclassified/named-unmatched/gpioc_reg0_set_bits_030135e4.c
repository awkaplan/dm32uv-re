/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gpioc_reg0_set_bits @ 030135e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gpioc_reg0_set_bits(uint param_1)

{
  dword dVar1;
  
  dVar1 = GPIOC_14110000.SWPORTA_DR;
  GPIOC_14110000.SWPORTA_DR = dVar1 | 0x7f80;
  if ((param_1 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x030135fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_03013610[param_1 & 0xff] & 0xfffffffe))();
    return;
  }
  gpio_clear_output_bit(0x4e);
  busy_wait_delay_loop_short(0x32);
  gpio_portb_read_input_bits_17_to_20();
  return;
}

