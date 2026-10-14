/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: slot_list_push_front_a @ 03002888 (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
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

void slot_list_push_front_a(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = _DAT_030028ec;
  uVar3 = (uint)*(byte *)(param_1 + 0x37);
  sVar1 = *(short *)(uVar3 * 0xc + _DAT_030028e8);
  if (sVar1 == 0) {
    iVar4 = _DAT_030028ec + uVar3 * 0xc;
    *(undefined2 *)(iVar4 + 8) = 1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(int *)(uVar3 * 0xc + iVar2) = param_1;
    *(int *)(iVar4 + 4) = param_1;
  }
  else {
    iVar4 = uVar3 * 0xc;
    *(short *)(_DAT_030028ec + iVar4 + 8) = sVar1 + 1;
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar2 + iVar4);
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(int *)(*(int *)(iVar4 + iVar2) + 0x10) = param_1;
    *(int *)(iVar4 + iVar2) = param_1;
  }
  return;
}

