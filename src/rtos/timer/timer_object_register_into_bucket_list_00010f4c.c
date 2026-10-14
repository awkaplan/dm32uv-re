/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: timer_object_register_into_bucket_list @ 00010f4c (IRAM address; the boot stub copies these bytes from program flash 0x030c0b6c)
 * Size: 84 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void timer_object_register_into_bucket_list(int param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = PTR_OSRdyList_0001108c;
  uVar2 = (uint)*(byte *)(param_1 + 0x37);
  if (*(short *)(PTR_DAT_00011088 + uVar2 * 0xc) == 0) {
    iVar3 = uVar2 * 0xc;
    *(undefined2 *)(PTR_OSRdyList_0001108c + iVar3 + 8) = 1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(int *)(puVar1 + iVar3) = param_1;
    *(int *)(puVar1 + iVar3 + 4) = param_1;
  }
  else {
    *(short *)(PTR_OSRdyList_0001108c + uVar2 * 0xc + 8) =
         *(short *)(PTR_DAT_00011088 + uVar2 * 0xc) + 1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    iVar3 = *(int *)(puVar1 + uVar2 * 0xc + 4);
    *(int *)(param_1 + 0x10) = iVar3;
    *(int *)(iVar3 + 0xc) = param_1;
    *(int *)(puVar1 + uVar2 * 0xc + 4) = param_1;
  }
  return;
}

