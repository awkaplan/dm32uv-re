/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_TaskBlock @ 030c0f88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_TaskBlock(int param_1,int param_2)

{
  int iStack_10;
  
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x36) = 2;
  }
  else {
    timer_entry_insert_hash_bucketed_list_030c(param_1,param_2,2,&iStack_10);
    if (iStack_10 == 0) {
      *(undefined1 *)(param_1 + 0x36) = 3;
    }
    else {
      *(undefined1 *)(param_1 + 0x36) = 2;
    }
  }
  linked_list_slot_free_and_unlink(param_1);
  return;
}

