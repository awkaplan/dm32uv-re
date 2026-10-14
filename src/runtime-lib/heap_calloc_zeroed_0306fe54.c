/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: heap_calloc_zeroed @ 0306fe54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void heap_calloc_zeroed(int param_1,int param_2)

{
  void *pvVar1;
  
  param_2 = param_2 * param_1;
  pvVar1 = malloc_best_fit(param_2);
  if ((0 < param_2) && (pvVar1 != (void *)0x0)) {
    memset_ck803s(pvVar1,0,param_2);
  }
  return;
}

