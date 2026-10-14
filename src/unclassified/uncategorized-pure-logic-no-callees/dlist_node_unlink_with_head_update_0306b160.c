/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dlist_node_unlink_with_head_update @ 0306b160 (file base 0x03000000; code starts at 0x03001000)
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

void dlist_node_unlink_with_head_update(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  iVar2 = *(int *)(param_1 + 0x30);
  if (iVar1 == 0) {
    *PTR_DAT_0306b190 = iVar2;
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x2c) = 0;
    }
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  else if (iVar2 == 0) {
    *(undefined4 *)(iVar1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  else {
    *(int *)(iVar1 + 0x30) = iVar2;
    *(int *)(iVar2 + 0x2c) = iVar1;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return;
}

