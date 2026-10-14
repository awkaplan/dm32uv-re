/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: message_phase_advance_dual_path @ 030c10fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void message_phase_advance_dual_path(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_2 + 0x36);
  if (1 < uVar1) {
    if (uVar1 < 4) {
      if (*(char *)(param_2 + 0x34) == '\x03') {
        queued_slot_tag_match_b(param_1,param_2,param_3);
      }
      *(undefined4 *)(param_2 + 0x5c) = 0;
      *(undefined2 *)(param_2 + 0x60) = 0;
      *(undefined4 *)(param_2 + 0x40) = param_3;
      pend_list_drain_and_clear(param_2);
      queued_timer_event_dispatch_if_not_flagged(param_2);
      *(undefined1 *)(param_2 + 0x36) = 0;
      *(undefined1 *)(param_2 + 0x35) = 2;
      *(undefined1 *)(param_2 + 0x34) = 0;
    }
    else if (uVar1 - 6 < 2) {
      if (*(char *)(param_2 + 0x34) == '\x03') {
        queued_slot_tag_match_b(param_1,param_2,param_3);
      }
      *(undefined4 *)(param_2 + 0x5c) = 0;
      *(undefined2 *)(param_2 + 0x60) = 0;
      *(undefined4 *)(param_2 + 0x40) = param_3;
      queued_event_list_unlink(param_2);
      pend_list_drain_and_clear(param_2);
      *(undefined1 *)(param_2 + 0x36) = 4;
      *(undefined1 *)(param_2 + 0x35) = 2;
      *(undefined1 *)(param_2 + 0x34) = 0;
    }
  }
  return;
}

