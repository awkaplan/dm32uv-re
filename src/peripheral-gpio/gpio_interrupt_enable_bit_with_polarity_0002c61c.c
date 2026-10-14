/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: gpio_interrupt_enable_bit_with_polarity @ 0002c61c (IRAM address; the boot stub copies these bytes from program flash 0x030dc23c)
 * Size: 188 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-gpio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gpio_interrupt_enable_bit_with_polarity(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 < 0x20) {
    uVar1 = 1 << (param_1 & 0x3f);
    if (param_2 == 0) {
      uRam1402003c = ~uVar1 & uRam1402003c;
    }
    else {
      uRam1402003c = uRam1402003c | uVar1;
    }
    uRam14020030 = uVar1 | uRam14020030 & ~uVar1;
  }
  else if (param_1 < 0x40) {
    uVar1 = 1 << (param_1 - 0x20 & 0x3f);
    if (param_2 == 0) {
      uRam1410003c = ~uVar1 & uRam1410003c;
    }
    else {
      uRam1410003c = uRam1410003c | uVar1;
    }
    uRam14100030 = uVar1 | uRam14100030 & ~uVar1;
  }
  else {
    uVar1 = 1 << (param_1 - 0x40 & 0x3f);
    if (param_2 == 0) {
      uRam1411003c = ~uVar1 & uRam1411003c;
    }
    else {
      uRam1411003c = uRam1411003c | uVar1;
    }
    uRam14110030 = uVar1 | uRam14110030 & ~uVar1;
  }
  return;
}

