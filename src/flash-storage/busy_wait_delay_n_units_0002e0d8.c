/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: busy_wait_delay_n_units @ 0002e0d8 (IRAM address; the boot stub copies these bytes from program flash 0x030ddcf8)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void busy_wait_delay_n_units(uint param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = 0;
    do {
      busy_wait_delay_loop_4arg(1000);
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_1);
  }
  return;
}

