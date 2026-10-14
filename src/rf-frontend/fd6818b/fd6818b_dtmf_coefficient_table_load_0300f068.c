/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_dtmf_coefficient_table_load @ 0300f068 (file base 0x03000000; code starts at 0x03001000)
 * Size: 162 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818b_dtmf_coefficient_table_load(void)

{
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0x6f);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0x106b);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0x2067);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0x3062);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0x4050);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0x5047);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0x603a);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0x702c);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0x8041);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0x9037);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0xa025);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0xb017);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0xc0e4);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0xd0cb);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0xe0b5);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,0xf09f);
  return;
}

