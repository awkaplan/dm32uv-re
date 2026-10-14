/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hw_register_0x78_write_from_byte_pair @ 0300de78 (file base 0x03000000; code starts at 0x03001000)
 * Size: 20 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void hw_register_0x78_write_from_byte_pair(int param_1__w)

{
  ushort param_1 = (ushort)param_1__w;
  fd6818b_reg_write(FD6818_PAGE0_REG_78H,(param_1 & 0xff) - 1 & 0xff | param_1 << 8);
  return;
}

