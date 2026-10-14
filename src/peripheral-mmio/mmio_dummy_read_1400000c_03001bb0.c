/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mmio_dummy_read_1400000c @ 03001bb0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 8 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-mmio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void mmio_dummy_read_1400000c(void)

{
  dword dVar1;
  
  dVar1 = TIMER_Type_14000000.CH[0].EOI;
  return;
}

