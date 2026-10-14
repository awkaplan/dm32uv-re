/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: clear_counter_block_0302a19c @ 0302a014 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: accessors
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void clear_counter_block_0302a19c(void)

{
  *(undefined2 *)PTR_DAT_0302a19c = 0;
  *(undefined2 *)PTR_DAT_0302a1a0 = 0;
  *(undefined2 *)PTR_DAT_0302a1a4 = 0;
  *(undefined2 *)PTR_DAT_0302a1a8 = 0;
  *(undefined2 *)PTR_DAT_0302a1ac = 0;
  PTR_DAT_0302a1b0[10] = 0;
  return;
}

