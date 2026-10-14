/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: slot_list_push_back_b @ 030c0b6c (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
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

void slot_list_push_back_b(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = _DAT_030c0cac;
  uVar3 = (uint)*(byte *)(param_1 + 0x37);
  sVar1 = *(short *)(uVar3 * 0xc + _DAT_030c0ca8);
  if (sVar1 == 0) {
    iVar2 = _DAT_030c0cac + uVar3 * 0xc;
    *(undefined2 *)(iVar2 + 8) = 1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(int *)(uVar3 * 0xc + iVar4) = param_1;
    *(int *)(iVar2 + 4) = param_1;
  }
  else {
    iVar4 = _DAT_030c0cac + uVar3 * 0xc;
    *(short *)(iVar4 + 8) = sVar1 + 1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    piVar5 = (int *)(iVar4 + 4);
    iVar4 = *piVar5;
    *(int *)(param_1 + 0x10) = iVar4;
    *(int *)(iVar4 + 0xc) = param_1;
    *piVar5 = param_1;
  }
  return;
}

