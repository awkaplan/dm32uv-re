/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: antenna_switch_select_gpio_24_22 @ 0002c878 (IRAM address; the boot stub copies these bytes from program flash 0x030dc498)
 * Size: 62 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void antenna_switch_select_gpio_24_22(int param_1)

{
  if (param_1 == 0) {
    gpio_clear_output_bit(0x24);
    gpio_clear_output_bit(0x22);
  }
  else if ((*(byte *)(iRam0002c8b8 + 3) & 8) == 0) {
    gpio_clear_output_bit(0x24);
    gpio_set_output_bit(0x22);
  }
  else {
    gpio_clear_output_bit(0x22);
    gpio_set_output_bit(0x24);
  }
  return;
}

