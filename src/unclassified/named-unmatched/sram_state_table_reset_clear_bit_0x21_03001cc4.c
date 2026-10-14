/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sram_state_table_reset_clear_bit_0x21 @ 03001cc4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
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

void sram_state_table_reset_clear_bit_0x21(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  FUN_03001ca8();
  iVar2 = _DAT_03001cec;
  uVar1 = _DAT_03001ce8;
  iVar3 = 0;
  do {
    *(undefined4 *)(iVar2 + iVar3 * 4) = uVar1;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x40);
  sram_state_word_bit_clear(_DAT_03001cf0,0x21);
  return;
}

