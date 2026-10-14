/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818_tx_deviation_bandwidth_mode_set @ 0300e794 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818_tx_deviation_bandwidth_mode_set(char mode)

{
  if (mode == '\x01') {
    fd6818b_reg_write(FD6818_PAGE0_REG_43H,0x2028);
  }
  else if (mode == '\0') {
    fd6818b_reg_write(FD6818_PAGE0_REG_43H,0x4048);
  }
  else if (mode == '\x02') {
    fd6818b_reg_write(FD6818_PAGE0_REG_43H,0x3028);
  }
  else if (mode == '\x03') {
    fd6818b_reg_write(FD6818_PAGE0_REG_43H,0x205c);
  }
  return;
}

