/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_flash_page_program_raw @ 0002b8a8 (IRAM address; the boot stub copies these bytes from program flash 0x030db4c8)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_page_program_raw(undefined4 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  spi_flash_cmd1_send(W25Q128JV_CMD_WRITE_ENABLE);
  uStack_14 = 2;
  uVar1 = *puRam0002ba0c;
  uStack_13 = (undefined1)((uint)uVar1 >> 0x10);
  uStack_12 = (undefined1)((uint)uVar1 >> 8);
  uStack_11 = (undefined1)uVar1;
  gpio_clear_output_bit(0x12);
  spi_controller_byte_xfer(0,0,&uStack_14,4);
  spi_controller_byte_xfer(0,0,param_1,param_2);
  gpio_set_output_bit(0x12);
  spi_flash_wait_wip();
  return;
}

