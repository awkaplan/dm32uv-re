/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: slot_table_find_and_store_b @ 030c0924 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void slot_table_find_and_store_b
               (int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5)

{
  int iVar1;
  short sVar2;
  int iVar3;
  
  sVar2 = *(short *)(param_2 + 0x3e);
  if (sVar2 != 0) {
    iVar3 = *(int *)(*(int *)(param_2 + 0x30) + 0xc);
    iVar1 = *(int *)(param_2 + 0x30);
    while (iVar3 != param_1) {
      sVar2 = sVar2 + -1;
      if (sVar2 == 0) {
        return;
      }
      iVar3 = *(int *)(iVar1 + 0x2c);
      iVar1 = iVar1 + 0x20;
    }
    *(int *)(iVar1 + 0x10) = param_1;
    *(undefined4 *)(iVar1 + 0x14) = param_3;
    *(undefined2 *)(iVar1 + 0x18) = param_4;
    *(undefined4 *)(iVar1 + 0x1c) = param_5;
  }
  return;
}

