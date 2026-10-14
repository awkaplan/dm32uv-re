/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_flash_cmd_sector_erase_raw @ 0002b9b4 (IRAM address; the boot stub copies these bytes from program flash 0x030db5d4)
 * Size: 70 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void spi_flash_cmd_sector_erase_raw(void)

{
  undefined4 uVar1;
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  
  spi_flash_cmd1_send(W25Q128JV_CMD_WRITE_ENABLE);
  uStack_c = 0x20;
  uVar1 = *puRam0002ba0c;
  uStack_b = (undefined1)((uint)uVar1 >> 0x10);
  uStack_a = (undefined1)((uint)uVar1 >> 8);
  uStack_9 = (undefined1)uVar1;
  gpio_clear_output_bit(0x12);
  spi_controller_byte_xfer(0,0,&uStack_c,4);
  gpio_set_output_bit(0x12);
  spi_flash_wait_wip();
  return;
}

