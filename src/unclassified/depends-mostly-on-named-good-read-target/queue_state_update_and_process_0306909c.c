/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queue_state_update_and_process @ 0306909c (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void queue_state_update_and_process(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x84) = param_2;
  *(undefined1 *)(param_1 + 0x35) = 0;
  *(undefined1 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x40) = param_3;
  uVar1 = (uint)*(byte *)(param_1 + 0x36);
  if (1 < uVar1) {
    if (uVar1 < 4) {
      queue_item_remove_with_conditional_cleanup();
      *(undefined1 *)(param_1 + 0x36) = 0;
    }
    else if (uVar1 - 6 < 2) {
      *(undefined1 *)(param_1 + 0x36) = 4;
    }
  }
  queue_list_process_and_reset(param_1);
  return;
}

