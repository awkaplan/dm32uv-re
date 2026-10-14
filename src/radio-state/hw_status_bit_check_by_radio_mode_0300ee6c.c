/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hw_status_bit_check_by_radio_mode @ 0300ee6c (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool hw_status_bit_check_by_radio_mode(void)

{
  uint uVar1;
  
  uVar1 = hw_status_bit10_read();
  if (((byte)PTR_DAT_0300eea0[0x35] >> 2 & 3) < 2) {
    uVar1 = uVar1 & 2;
  }
  else {
    uVar1 = uVar1 & 1;
  }
  return uVar1 != 0;
}

