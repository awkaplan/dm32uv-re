/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_index_derive_from_element_count @ 03002fc8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

char table_index_derive_from_element_count(void)

{
  char cVar1;
  int *piVar2;
  char cVar3;
  
  if (*PTR_LAB_03002ff0 == 0) {
    cVar3 = '\0';
    piVar2 = PTR_LAB_03002ff0;
    do {
      cVar3 = cVar3 + ' ';
      piVar2 = piVar2 + 1;
    } while (*piVar2 == 0);
  }
  else {
    cVar3 = '\0';
  }
  cVar1 = FUN_03002208();
  return cVar3 + cVar1;
}

