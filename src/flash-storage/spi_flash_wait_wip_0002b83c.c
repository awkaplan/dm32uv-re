/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_flash_wait_wip @ 0002b83c (IRAM address; the boot stub copies these bytes from program flash 0x030db45c)
 * Size: 92 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_wait_wip(void)

{
  short sVar1;
  byte abStack_2c [4];
  undefined1 auStack_28 [4];
  
  sVar1 = 0x578;
  do {
    auStack_28[0] = 5;
    gpio_clear_output_bit(0x12);
    spi_controller_byte_xfer_rdwr(0,0,abStack_2c,1,auStack_28,1);
    gpio_set_output_bit(0x12);
    if ((abStack_2c[0] & 1) == 0) {
      return;
    }
    busy_wait_delay_n_units(5);
    sVar1 = sVar1 + -1;
  } while (sVar1 != 0);
  return;
}

