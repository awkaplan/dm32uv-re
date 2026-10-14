/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_columns_remaining @ 0305a12c (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint text_entry_columns_remaining(uint param_1)

{
  bool bVar1;
  uint uVar2;
  
  param_1 = param_1 & 0xff;
  uVar2 = param_1 + 0x13;
  if ((int)uVar2 < (int)(*(byte *)PTR_DAT_0305a2ac - 1)) {
    if (param_1 < uVar2) {
      bVar1 = false;
      do {
        if (-1 < (char)p_text_entry_buffer[param_1]) {
          bVar1 = (bool)(bVar1 ^ 1);
        }
        param_1 = param_1 + 1 & 0xff;
      } while (param_1 < uVar2);
      if (bVar1) {
        uVar2 = 0x13;
      }
      else {
        uVar2 = 0x12;
      }
    }
    else {
      uVar2 = 0x12;
    }
  }
  else {
    uVar2 = (*(byte *)PTR_DAT_0305a2ac - 1) - param_1 & 0xff;
  }
  return uVar2;
}

