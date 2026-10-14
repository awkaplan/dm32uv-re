/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: stored_config_fields_differ @ 03021064 (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool stored_config_fields_differ(char param_1,int param_2,int param_3)

{
  bool bVar1;
  
  if (*(char *)((int)PTR_DAT_03021204 + 1) == param_1) {
    if (PTR_DAT_03021204[4] == param_2) {
      bVar1 = PTR_DAT_03021204[5] != param_3;
    }
    else {
      bVar1 = true;
    }
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

