/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: queue_list_process_and_reset @ 00010c60 (IRAM address; the boot stub copies these bytes from program flash 0x030c0880)
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

void queue_list_process_and_reset(int param_1)

{
  int iVar1;
  short sVar2;
  
  iVar1 = *(int *)(param_1 + 0x30);
  for (sVar2 = *(short *)(param_1 + 0x3e); sVar2 != 0; sVar2 = sVar2 + -1) {
    list_node_unlink_a(*(int *)(iVar1 + 0xc) + 8,iVar1);
    iVar1 = iVar1 + 0x20;
  }
  *(undefined2 *)(param_1 + 0x3e) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}

