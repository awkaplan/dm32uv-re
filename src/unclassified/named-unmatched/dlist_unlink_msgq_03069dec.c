/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dlist_unlink_msgq @ 03069dec (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
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

void dlist_unlink_msgq(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0x18);
  if (iVar1 == 0) {
    *_DAT_03069f54 = iVar2;
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x14) = 0;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else if (iVar2 == 0) {
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  else {
    *(int *)(iVar1 + 0x18) = iVar2;
    *(int *)(iVar2 + 0x14) = iVar1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}

