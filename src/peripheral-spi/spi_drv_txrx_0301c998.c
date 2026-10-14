/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_drv_txrx @ 0301c998 (file base 0x03000000; code starts at 0x03001000)
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

uint spi_drv_txrx(int param_1,uint param_2)

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

