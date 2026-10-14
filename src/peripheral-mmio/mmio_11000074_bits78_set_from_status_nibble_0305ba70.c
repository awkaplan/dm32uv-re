/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mmio_11000074_bits78_set_from_status_nibble @ 0305ba70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-mmio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void mmio_11000074_bits78_set_from_status_nibble(void)

{
  byte bVar1;
  
  bVar1 = p_vfo_display_state->flags_0x8 & 0xf0;
  if (bVar1 == 0) {
    mmio_11000074_bits_7_8_set_clear(1);
  }
  else if (bVar1 == 0x10) {
    mmio_11000074_bits_7_8_set_clear(1);
  }
  else {
    mmio_11000074_bits_7_8_set_clear(0);
  }
  return;
}

