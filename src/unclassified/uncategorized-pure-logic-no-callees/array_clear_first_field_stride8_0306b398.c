/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: array_clear_first_field_stride8 @ 0306b398 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void array_clear_first_field_stride8(void)

{
  ushort uVar1;
  undefined4 *puVar2;
  ushort uVar3;
  
  uVar1 = *PTR_DAT_0306b4d4;
  if (uVar1 != 0) {
    uVar3 = 0;
    puVar2 = PTR_DAT_0306b4d8;
    do {
      *(undefined2 *)puVar2 = 0;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 2;
    } while (uVar3 < uVar1);
  }
  return;
}

