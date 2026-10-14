/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: spi_flash_read_seq @ 0002b99c (IRAM address; the boot stub copies these bytes from program flash 0x030db5bc)
 * Size: 24 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_read_seq(int param_1__w,int param_2__w,undefined4 param_3,int param_4__w)

{
  undefined2 param_1 = (undefined2)param_1__w;
  undefined2 param_2 = (undefined2)param_2__w;
  undefined2 param_4 = (undefined2)param_4__w;
  spi_flash_shadow_addr_set(param_1,param_2);
  spi_flash_read_data_raw(param_3,param_4);
  return;
}

