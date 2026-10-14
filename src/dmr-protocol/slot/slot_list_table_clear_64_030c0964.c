/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: slot_list_table_clear_64 @ 030c0964 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void slot_list_table_clear_64(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = _DAT_030c0aa8 + 0xc0;
  puVar2 = _DAT_030c0aa8;
  do {
    *(undefined2 *)(puVar2 + 2) = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2 = puVar2 + 3;
  } while (puVar2 != puVar1);
  return;
}

