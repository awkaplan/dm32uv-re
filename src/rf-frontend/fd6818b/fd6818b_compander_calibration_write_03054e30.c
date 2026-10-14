/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_compander_calibration_write @ 03054e30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 14 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818b_compander_calibration_write(undefined1 param_1)

{
  PTR_DAT_03054fb0[0x38] = param_1;
  fd6818b_reg_write_wrapper();
  return;
}

