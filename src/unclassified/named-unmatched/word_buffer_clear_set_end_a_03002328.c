/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: word_buffer_clear_set_end_a @ 03002328 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
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

void word_buffer_clear_set_end_a(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)*_DAT_03002354;
  uVar1 = *_DAT_03002358;
  if (uVar1 != 0) {
    uVar3 = 0;
    puVar2 = puVar4;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  *_DAT_0300235c = puVar4 + (uVar1 - 1);
  return;
}

