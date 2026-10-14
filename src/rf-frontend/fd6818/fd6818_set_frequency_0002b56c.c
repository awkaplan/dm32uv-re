/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818_set_frequency @ 0002b56c (IRAM address; the boot stub copies these bytes from program flash 0x030db18c)
 * Size: 22 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818_set_frequency(undefined2 param_1,undefined2 param_2)

{
  fd6818b_reg_write(FD6818_PAGE0_REG_38H,param_2);
  fd6818b_reg_write(FD6818_PAGE0_REG_39H,param_1);
  return;
}

