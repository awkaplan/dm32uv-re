/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: malloc_copy_source_range_checked @ 0306fe70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void * malloc_copy_source_range_checked(void *param_1,int param_2)

{
  void *dest;
  
  dest = malloc_best_fit(param_2);
  if (((_DAT_0306fe9c <= param_1) && (param_1 <= _DAT_0306fea0)) && (dest != (void *)0x0)) {
    memcpy_ck803s(dest,param_1,param_2);
  }
  return dest;
}

