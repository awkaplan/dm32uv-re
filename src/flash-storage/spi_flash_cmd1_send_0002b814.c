/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_flash_cmd1_send @ 0002b814 (IRAM address; the boot stub copies these bytes from program flash 0x030db434)
 * Size: 38 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_cmd1_send(w25q128jv_cmd opcode)

{
  undefined1 auStack_c [4];
  
  auStack_c[0] = (undefined1)opcode;
  gpio_clear_output_bit(0x12);
  spi_controller_byte_xfer(0,0,auStack_c,1);
  gpio_set_output_bit(0x12);
  return;
}

