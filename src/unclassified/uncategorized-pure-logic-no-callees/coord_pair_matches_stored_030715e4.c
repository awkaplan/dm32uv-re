/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: coord_pair_matches_stored @ 030715e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte coord_pair_matches_stored(int param_1,int param_2)

{
  if ((param_1 == 0) && ((param_2 == 0x7ff80000 || (param_2 == 0x7ff00000)))) {
    return 1;
  }
  return ~(param_1 != *PTR_DAT_03071614 || param_2 != PTR_DAT_03071614[1]);
}

