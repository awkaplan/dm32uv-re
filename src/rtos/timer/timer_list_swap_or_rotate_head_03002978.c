/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timer_list_swap_or_rotate_head @ 03002978 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void timer_list_swap_or_rotate_head(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (1 < *(ushort *)(param_1 + 2)) {
    if (*(ushort *)(param_1 + 2) == 2) {
      iVar2 = *param_1;
      iVar1 = param_1[1];
      *(int *)(iVar2 + 0x10) = iVar1;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      *(int *)(iVar1 + 0xc) = iVar2;
      *param_1 = iVar1;
      param_1[1] = iVar2;
    }
    else {
      iVar3 = *param_1;
      iVar1 = param_1[1];
      iVar2 = *(int *)(iVar3 + 0xc);
      *(undefined4 *)(iVar2 + 0x10) = 0;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(int *)(iVar3 + 0x10) = iVar1;
      *(int *)(iVar1 + 0xc) = iVar3;
      *param_1 = iVar2;
      param_1[1] = iVar3;
    }
  }
  return;
}

