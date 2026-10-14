/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: linked_list_slot_free_and_unlink @ 030c0cdc (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void linked_list_slot_free_and_unlink(int param_1)

{
  int iVar1;
  uint uVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = _DAT_030c0e3c;
  uVar2 = (uint)*(byte *)(param_1 + 0x37);
  iVar4 = *(int *)(param_1 + 0x10);
  iVar5 = *(int *)(param_1 + 0xc);
  if (iVar4 == 0) {
    if (iVar5 == 0) {
      iVar4 = _DAT_030c0e3c + uVar2 * 0xc;
      *(undefined2 *)(iVar4 + 8) = 0;
      *(undefined4 *)(uVar2 * 0xc + iVar1) = 0;
      *(undefined4 *)(iVar4 + 4) = 0;
      FUN_030c1654(*(undefined1 *)(param_1 + 0x37));
    }
    else {
      psVar3 = (short *)(_DAT_030c0e3c + uVar2 * 0xc + 8);
      *psVar3 = *psVar3 + -1;
      *(undefined4 *)(iVar5 + 0x10) = 0;
      *(int *)(uVar2 * 0xc + iVar1) = iVar5;
    }
  }
  else {
    psVar3 = (short *)(uVar2 * 0xc + _DAT_030c0e40);
    *psVar3 = *psVar3 + -1;
    *(int *)(iVar4 + 0xc) = iVar5;
    if (iVar5 == 0) {
      *(int *)(uVar2 * 0xc + _DAT_030c0e44) = iVar4;
    }
    else {
      *(int *)(iVar5 + 0x10) = iVar4;
    }
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

