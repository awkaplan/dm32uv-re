/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: busy_wait_delay_loop_counted @ 0002df14 (IRAM address; the boot stub copies these bytes from program flash 0x030ddb34)
 * Size: 42 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 busy_wait_delay_loop_counted(undefined4 param_1)

{
  if ((PTR_DAT_0002df64[0x2d] & 0x80) == 0) {
    func_0x030703bc(param_1,PTR_DAT_0002df68,0x33);
  }
  else {
    func_0x030703bc(param_1,PTR_DAT_0002df6c,0x33);
  }
  return param_1;
}

