/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818_reg_read @ 0002c33c (IRAM address; the boot stub copies these bytes from program flash 0x030dbf5c)
 * Size: 72 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 fd6818_reg_read(fd6818_page0 reg)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = uRam0002c384;
  func_0x0300c500(uRam0002c384,0);
  uRam14020004 = uRam14020004 | 0x100;
  gpio_clear_output_bit(7);
  gpio_clear_output_bit(0x18);
  busy_wait_delay_loop_short(10);
  fd6818b_shift_out_8bit(reg & 0xff | 0x80);
  uVar2 = fd6818b_shift_in_16bit();
  gpio_set_output_bit(0x18);
  func_0x0300c53c(uVar1);
  return uVar2;
}

