/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_write_tone_divider_reg07 @ 0300e7e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 12 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818b_write_tone_divider_reg07(undefined2 param_1)

{
  fd6818b_reg_write(FD6818_PAGE0_REG_07H,param_1);
  return;
}

