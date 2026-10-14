/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zero_fields_by_index_pair @ 0301bfdc (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void zero_fields_by_index_pair(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_0301c170;
  if (param_1 < 2) {
    *(undefined2 *)((int)PTR_DAT_0301c170 + param_1 * 2 + 8) = 0;
    puVar1[param_1 + 3] = 0;
    puVar1[param_1 + 5] = 0;
  }
  return;
}

