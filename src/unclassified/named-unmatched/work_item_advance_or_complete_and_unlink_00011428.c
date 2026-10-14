/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: work_item_advance_or_complete_and_unlink @ 00011428 (IRAM address; the boot stub copies these bytes from program flash 0x030c1048)
 * Size: 180 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void work_item_advance_or_complete_and_unlink
               (int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_2 + 0x36);
  if (1 < uVar1) {
    if (uVar1 < 4) {
      if (*(char *)(param_2 + 0x34) == '\x03') {
        fixed_capacity_keyed_record_update(param_1,param_2,param_3,param_4,param_5);
      }
      else {
        *(undefined4 *)(param_2 + 0x5c) = param_3;
        *(undefined2 *)(param_2 + 0x60) = param_4;
        *(undefined4 *)(param_2 + 0x40) = param_5;
      }
      if (param_1 != 0) {
        queue_list_process_and_reset(param_2);
        FUN_00010b6c(param_1,param_2);
      }
      queue_item_remove_with_conditional_cleanup(param_2);
      *(undefined1 *)(param_2 + 0x36) = 0;
      *(undefined1 *)(param_2 + 0x35) = 0;
      *(undefined1 *)(param_2 + 0x34) = 0;
    }
    else if (uVar1 - 6 < 2) {
      if (*(char *)(param_2 + 0x34) == '\x03') {
        fixed_capacity_keyed_record_update(param_1,param_2,param_3,param_4,param_5);
      }
      else {
        *(undefined4 *)(param_2 + 0x5c) = param_3;
        *(undefined2 *)(param_2 + 0x60) = param_4;
        *(undefined4 *)(param_2 + 0x40) = param_5;
      }
      dll_node_remove(param_2);
      if (param_1 != 0) {
        queue_list_process_and_reset(param_2);
        FUN_00010b6c(param_1,param_2);
      }
      *(undefined1 *)(param_2 + 0x36) = 4;
      *(undefined1 *)(param_2 + 0x35) = 0;
      *(undefined1 *)(param_2 + 0x34) = 0;
    }
  }
  return;
}

