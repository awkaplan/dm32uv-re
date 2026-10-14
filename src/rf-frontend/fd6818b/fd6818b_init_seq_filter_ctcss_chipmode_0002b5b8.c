/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818b_init_seq_filter_ctcss_chipmode @ 0002b5b8 (IRAM address; the boot stub copies these bytes from program flash 0x030db1d8)
 * Size: 42 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818b_init_seq_filter_ctcss_chipmode(void)

{
  fd6818b_reg_write(FD6818_PAGE0_REG_0X37,0x1d0f);
  fd6818b_reg_write(FD6818_PAGE0_REG_52H,0x28f);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X30,0);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X30,0xc1fe);
  return;
}

