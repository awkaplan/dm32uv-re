/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: pa_band_select_vhf_uhf_gpio @ 0002c838 (IRAM address; the boot stub copies these bytes from program flash 0x030dc458)
 * Size: 62 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void pa_band_select_vhf_uhf_gpio(int param_1)

{
  if (param_1 == 0) {
    gpio_clear_output_bit(0x37);
    gpio_clear_output_bit(0x23);
  }
  else if ((*(byte *)(iRam0002c8b8 + 3) & 0x10) == 0) {
    gpio_clear_output_bit(0x23);
    gpio_set_output_bit(0x37);
  }
  else {
    gpio_clear_output_bit(0x37);
    gpio_set_output_bit(0x23);
  }
  return;
}

