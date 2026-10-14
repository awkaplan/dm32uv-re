/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: pend_list_drain_and_clear @ 030c0880 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void pend_list_drain_and_clear(int param_1)

{
  int iVar1;
  short sVar2;
  
  iVar1 = *(int *)(param_1 + 0x30);
  for (sVar2 = *(short *)(param_1 + 0x3e); sVar2 != 0; sVar2 = sVar2 + -1) {
    list_node_unlink_c(*(int *)(iVar1 + 0xc) + 8,iVar1);
    iVar1 = iVar1 + 0x20;
  }
  *(undefined2 *)(param_1 + 0x3e) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}

