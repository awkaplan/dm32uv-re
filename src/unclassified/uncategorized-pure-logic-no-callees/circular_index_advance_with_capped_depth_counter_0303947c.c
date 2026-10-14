/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: circular_index_advance_with_capped_depth_counter @ 0303947c (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void circular_index_advance_with_capped_depth_counter(short *param_1,ushort *param_2,uint param_3)

{
  ushort uVar1;
  
  uVar1 = *param_2;
  if ((uint)uVar1 == (param_3 & 0xffff) - 1) {
    *param_2 = 0;
    *param_1 = 1;
  }
  else if (*param_1 == 8) {
    *param_2 = uVar1 + 1;
  }
  else {
    *param_2 = uVar1 + 1;
    *param_1 = *param_1 + 1;
  }
  return;
}

