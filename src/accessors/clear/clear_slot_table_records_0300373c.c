/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: clear_slot_table_records @ 0300373c (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: accessors
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void clear_slot_table_records(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 *puVar3;
  
  uVar1 = *_DAT_03003760;
  if (uVar1 != 0) {
    uVar2 = 0;
    puVar3 = _DAT_03003764;
    do {
      *(undefined4 *)(puVar3 + -2) = 0;
      *puVar3 = 0;
      puVar3[1] = 0;
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 4;
    } while (uVar2 < uVar1);
  }
  return;
}

