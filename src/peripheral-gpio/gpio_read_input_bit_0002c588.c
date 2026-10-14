/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: gpio_read_input_bit @ 0002c588 (IRAM address; the boot stub copies these bytes from program flash 0x030dc1a8)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-gpio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool gpio_read_input_bit(uint param_1)

{
  bool bVar1;
  
  if (param_1 < 0x20) {
    bVar1 = (1 << (param_1 & 0x3f) & uRam14020050) != 0;
  }
  else if (param_1 < 0x40) {
    bVar1 = (1 << (param_1 - 0x20 & 0x3f) & uRam14100050) != 0;
  }
  else {
    bVar1 = (1 << (param_1 - 0x40 & 0x3f) & uRam14110050) != 0;
  }
  return bVar1;
}

