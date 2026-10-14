/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: msg_node_retire_by_state @ 0001156c (IRAM address; the boot stub copies these bytes from program flash 0x030c118c)
 * Size: 150 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void msg_node_retire_by_state(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_2 + 0x36);
  if (1 < uVar1) {
    if (uVar1 < 4) {
      if (*(char *)(param_2 + 0x34) == '\x03') {
        func_0x00010a90(param_1,param_2,param_3);
      }
      *(undefined4 *)(param_2 + 0x5c) = 0;
      *(undefined2 *)(param_2 + 0x60) = 0;
      *(undefined4 *)(param_2 + 0x40) = param_3;
      if (param_1 != 0) {
        queue_list_process_and_reset(param_2);
      }
      queue_item_remove_with_conditional_cleanup(param_2);
      *(undefined1 *)(param_2 + 0x36) = 0;
      *(undefined1 *)(param_2 + 0x35) = 1;
      *(undefined1 *)(param_2 + 0x34) = 0;
    }
    else if (uVar1 - 6 < 2) {
      if (*(char *)(param_2 + 0x34) == '\x03') {
        func_0x00010a90(param_1,param_2,param_3);
      }
      *(undefined4 *)(param_2 + 0x5c) = 0;
      *(undefined2 *)(param_2 + 0x60) = 0;
      *(undefined4 *)(param_2 + 0x40) = param_3;
      if (param_1 != 0) {
        queue_list_process_and_reset(param_2);
      }
      dll_node_remove(param_2);
      *(undefined1 *)(param_2 + 0x36) = 4;
      *(undefined1 *)(param_2 + 0x35) = 1;
      *(undefined1 *)(param_2 + 0x34) = 0;
    }
  }
  return;
}

