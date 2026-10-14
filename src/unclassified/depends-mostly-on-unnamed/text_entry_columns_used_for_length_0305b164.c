/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_columns_used_for_length @ 0305b164 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int text_entry_columns_used_for_length(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 & 0xff) == 0) {
    iVar1 = 0;
  }
  else {
    uVar2 = 0;
    do {
      iVar1 = text_entry_columns_remaining(uVar2);
      if (iVar1 == 0) {
        return 0;
      }
      uVar2 = uVar2 + iVar1 & 0xff;
    } while (uVar2 < (param_1 & 0xff));
  }
  return iVar1;
}

