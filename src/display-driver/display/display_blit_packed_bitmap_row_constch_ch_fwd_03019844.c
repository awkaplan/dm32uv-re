/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_blit_packed_bitmap_row_constch_ch_fwd @ 03019844 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_blit_packed_bitmap_row_constch_ch_fwd
               (undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,
               undefined2 param_5)

{
  display_blit_packed_bitmap_row(param_2,param_1,0xc,0xc,param_3,param_4,param_5);
  return;
}

