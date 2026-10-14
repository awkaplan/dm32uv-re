/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: os_rdylist_move_head_to_tail @ 00010fc8 (IRAM address; the boot stub copies these bytes from program flash 0x030c0be8)
 * Size: 60 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void os_rdylist_move_head_to_tail(int *param_1)

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

