/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818b_reg_write @ 0002c2f4 (IRAM address; the boot stub copies these bytes from program flash 0x030dbf14)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818b_reg_write(fd6818_page0 reg,undefined2 value)

{
  undefined4 uVar1;
  
  uVar1 = uRam0002c384;
  func_0x0300c500(uRam0002c384,0);
  uRam14020004 = uRam14020004 | 0x100;
  gpio_clear_output_bit(7);
  gpio_clear_output_bit(0x18);
  busy_wait_delay_loop_short(5);
  fd6818b_shift_out_8bit(reg & 0xff);
  fd6818b_shift_out_16bit(value);
  gpio_set_output_bit(0x18);
  func_0x0300c53c(uVar1);
  return;
}

