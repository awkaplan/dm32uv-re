/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_flash_read_mutex_guarded @ 0002ba10 (IRAM address; the boot stub copies these bytes from program flash 0x030db630)
 * Size: 76 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_read_mutex_guarded(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  
  uVar1 = uRam0002bb14;
  func_0x0300c500(uRam0002bb14,0);
  uStack_1c = 3;
  uStack_1b = (undefined1)((uint)param_1 >> 0x10);
  uStack_1a = (undefined1)((uint)param_1 >> 8);
  uStack_19 = (undefined1)param_1;
  gpio_clear_output_bit(0x12);
  spi_controller_byte_xfer_rdwr(0,0,param_2,param_3,&uStack_1c,4);
  gpio_set_output_bit(0x12);
  func_0x0300c53c(uVar1);
  return;
}

