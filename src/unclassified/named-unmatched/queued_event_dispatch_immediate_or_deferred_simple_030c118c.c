/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queued_event_dispatch_immediate_or_deferred_simple @ 030c118c (file base 0x03000000; code starts at 0x03001000)
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

void queued_event_dispatch_immediate_or_deferred_simple(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_2 + 0x36);
  if (1 < uVar1) {
    if (uVar1 < 4) {
      if (*(char *)(param_2 + 0x34) == '\x03') {
        queued_slot_tag_match_a(param_1,param_2,param_3);
      }
      *(undefined4 *)(param_2 + 0x5c) = 0;
      *(undefined2 *)(param_2 + 0x60) = 0;
      *(undefined4 *)(param_2 + 0x40) = param_3;
      if (param_1 != 0) {
        pend_list_drain_and_clear(param_2);
      }
      queued_timer_event_dispatch_if_not_flagged(param_2);
      *(undefined1 *)(param_2 + 0x36) = 0;
      *(undefined1 *)(param_2 + 0x35) = 1;
      *(undefined1 *)(param_2 + 0x34) = 0;
    }
    else if (uVar1 - 6 < 2) {
      if (*(char *)(param_2 + 0x34) == '\x03') {
        queued_slot_tag_match_a(param_1,param_2,param_3);
      }
      *(undefined4 *)(param_2 + 0x5c) = 0;
      *(undefined2 *)(param_2 + 0x60) = 0;
      *(undefined4 *)(param_2 + 0x40) = param_3;
      if (param_1 != 0) {
        pend_list_drain_and_clear(param_2);
      }
      queued_event_list_unlink(param_2);
      *(undefined1 *)(param_2 + 0x36) = 4;
      *(undefined1 *)(param_2 + 0x35) = 1;
      *(undefined1 *)(param_2 + 0x34) = 0;
    }
  }
  return;
}

