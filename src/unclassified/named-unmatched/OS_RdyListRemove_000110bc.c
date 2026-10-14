/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_RdyListRemove @ 000110bc (IRAM address; the boot stub copies these bytes from program flash 0x030c0cdc)
 * Size: 138 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_RdyListRemove(int param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = PTR_OSRdyList_0001121c;
  uVar2 = (uint)*(byte *)(param_1 + 0x37);
  iVar3 = *(int *)(param_1 + 0x10);
  iVar4 = *(int *)(param_1 + 0xc);
  if (iVar3 == 0) {
    if (iVar4 == 0) {
      iVar3 = uVar2 * 0xc;
      *(undefined2 *)(PTR_OSRdyList_0001121c + iVar3 + 8) = 0;
      *(undefined4 *)(puVar1 + iVar3) = 0;
      *(undefined4 *)(puVar1 + iVar3 + 4) = 0;
      FUN_00011a34(*(undefined1 *)(param_1 + 0x37));
    }
    else {
      *(short *)(PTR_OSRdyList_0001121c + uVar2 * 0xc + 8) =
           *(short *)(PTR_OSRdyList_0001121c + uVar2 * 0xc + 8) + -1;
      *(undefined4 *)(iVar4 + 0x10) = 0;
      *(int *)(puVar1 + uVar2 * 0xc) = iVar4;
    }
  }
  else {
    *(short *)(PTR_DAT_00011220 + uVar2 * 0xc) = *(short *)(PTR_DAT_00011220 + uVar2 * 0xc) + -1;
    *(int *)(iVar3 + 0xc) = iVar4;
    if (iVar4 == 0) {
      *(int *)(PTR_DAT_00011224 + uVar2 * 0xc) = iVar3;
    }
    else {
      *(int *)(iVar4 + 0x10) = iVar3;
    }
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

