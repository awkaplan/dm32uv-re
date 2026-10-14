/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_pa_power_level_select @ 0300e68c (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818b_pa_power_level_select(char param_1)

{
  if (param_1 == '\x01') {
    fd6818b_reg_write(FD6818_PAGE0_REG_53H,59000);
    fd6818b_reg_write(FD6818_PAGE0_REG_4BH,0x7102);
    fd6818b_reg_write(FD6818_PAGE0_REG_27H,0x7430);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X29,0xab2a);
  }
  else if (param_1 == '\x02') {
    fd6818b_reg_write(FD6818_PAGE0_REG_4BH,0x7120);
    fd6818b_reg_write(FD6818_PAGE0_REG_27H,0xc430);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X29,0xab20);
  }
  return;
}

