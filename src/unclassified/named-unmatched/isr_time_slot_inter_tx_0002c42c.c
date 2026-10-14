/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: isr_time_slot_inter_tx @ 0002c42c (IRAM address; the boot stub copies these bytes from program flash 0x030dc04c)
 * Size: 38 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void isr_time_slot_inter_tx(void)

{
  uRam110003b0 = uRam110003b0 | 1;
  if ((*PTR_DAT_0002c4ac & 2) == 0) {
    func_0x0300c53c(PTR_ucos_mutex_00035f50_0002c4b8);
  }
  return;
}

