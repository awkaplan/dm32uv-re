/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: owner_slot_array_init_b @ 030c06e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void owner_slot_array_init_b(int param_1,undefined4 *param_2,short param_3)

{
  undefined4 *puVar1;
  
  *(short *)(param_1 + 0x3e) = param_3;
  *(undefined4 **)(param_1 + 0x30) = param_2;
  if (param_3 != 0) {
    puVar1 = param_2 + (uint)(ushort)(param_3 - 1) * 8 + 8;
    do {
      param_2[1] = 0;
      *param_2 = 0;
      param_2[4] = 0;
      param_2[5] = 0;
      *(undefined2 *)(param_2 + 6) = 0;
      param_2[7] = 0;
      param_2[2] = param_1;
      param_2 = param_2 + 8;
    } while (param_2 != puVar1);
  }
  return;
}

