/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818b_shift_out_16bit @ 0002c248 (IRAM address; the boot stub copies these bytes from program flash 0x030dbe68)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818b_shift_out_16bit(short param_1)

{
  char cVar1;
  
  gpio_clear_output_bit(7);
  cVar1 = '\x10';
  while( true ) {
    if (param_1 < 0) {
      gpio_set_output_bit(8);
    }
    else {
      gpio_clear_output_bit(8);
    }
    busy_wait_delay_loop_short(5);
    gpio_set_output_bit(7);
    busy_wait_delay_loop_short(5);
    gpio_clear_output_bit(7);
    cVar1 = cVar1 + -1;
    if (cVar1 == '\0') break;
    param_1 = param_1 * 2;
  }
  return;
}

