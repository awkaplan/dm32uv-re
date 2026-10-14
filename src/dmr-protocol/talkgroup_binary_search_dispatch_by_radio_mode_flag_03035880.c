/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: talkgroup_binary_search_dispatch_by_radio_mode_flag @ 03035880 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void talkgroup_binary_search_dispatch_by_radio_mode_flag(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_a [2];
  
  uVar1 = get_block0xb_u16_field0();
  if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
    talkgroup_binary_search_by_id_and_flag(param_1,auStack_a,uVar1,3);
  }
  else {
    talkgroup_binary_search_by_id_and_flag(param_1,auStack_a,uVar1,4);
  }
  return;
}

