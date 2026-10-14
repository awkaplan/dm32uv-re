/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sram_16000000_block_write @ 0300d3ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void sram_16000000_block_write(int param_1,undefined1 *param_2,short param_3)

{
  undefined *puVar1;
  
  puVar1 = &UNK_16000000 + param_1;
  if (param_3 != 0) {
    do {
      *puVar1 = *param_2;
      param_2 = param_2 + 1;
      puVar1 = puVar1 + 1;
    } while (puVar1 != &UNK_16000001 + (uint)(ushort)(param_3 - 1) + param_1);
  }
  return;
}

