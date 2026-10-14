/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: gpio_set_output_bit @ 0002c500 (IRAM address; the boot stub copies these bytes from program flash 0x030dc120)
 * Size: 68 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gpio_set_output_bit(uint param_1)

{
  if (param_1 < 0x20) {
    uRam14020000 = 1 << (param_1 & 0x3f) | uRam14020000;
  }
  else if (param_1 < 0x40) {
    uRam14100000 = 1 << (param_1 - 0x20 & 0x3f) | uRam14100000;
  }
  else {
    uRam14110000 = 1 << (param_1 - 0x40 & 0x3f) | uRam14110000;
  }
  return;
}

