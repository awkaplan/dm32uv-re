/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_controller_single_byte_xfer @ 0002bf90 (IRAM address; the boot stub copies these bytes from program flash 0x030dbbb0)
 * Size: 50 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-spi
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint spi_controller_single_byte_xfer(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 0x28);
  do {
  } while ((*puVar1 & 2) == 0);
  *(uint *)(param_1 + 0x60) = param_2 & 0xffff;
  do {
  } while ((*puVar1 & 4) == 0);
  do {
  } while ((*puVar1 & 1) != 0);
  return *(uint *)(param_1 + 0x60) & 0xffff;
}

