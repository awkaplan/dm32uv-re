/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_timeout_arm_and_unlink @ 03002b90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_timeout_arm_and_unlink(int param_1,int param_2)

{
  int iStack_10;
  
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x36) = 2;
  }
  else {
    timer_entry_insert_hash_bucketed_list_0300(param_1,param_2,2,&iStack_10);
    if (iStack_10 == 0) {
      *(undefined1 *)(param_1 + 0x36) = 3;
    }
    else {
      *(undefined1 *)(param_1 + 0x36) = 2;
    }
  }
  list_node_unlink_and_free_slot(param_1);
  return;
}

