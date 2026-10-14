/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818b_reg47_afout_clear_mode @ 0002b550 (IRAM address; the boot stub copies these bytes from program flash 0x030db170)
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

void fd6818b_reg47_afout_clear_mode(void)

{
  ushort uVar1;
  
  uVar1 = fd6818_reg_read(FD6818_PAGE0_REG_47H);
  fd6818b_reg_write(FD6818_PAGE0_REG_47H,uVar1 & 0xf0ff);
  return;
}

