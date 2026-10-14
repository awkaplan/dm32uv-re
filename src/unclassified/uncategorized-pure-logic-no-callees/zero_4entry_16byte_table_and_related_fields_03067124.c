/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zero_4entry_16byte_table_and_related_fields @ 03067124 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void zero_4entry_16byte_table_and_related_fields(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = PTR_DAT_03067154 + 1;
  puVar3 = PTR_DAT_03067154;
  do {
    *(undefined1 *)puVar3 = 0;
    *(undefined1 *)(puVar3 + 1) = 0;
    *(undefined1 *)(puVar3 + 2) = 0;
    *(undefined1 *)(puVar3 + 3) = 0;
    puVar1 = PTR_DAT_03067158;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  } while (puVar3 != puVar2);
  PTR_DAT_03067158[2] = 0;
  puVar1[1] = 0;
  return;
}

