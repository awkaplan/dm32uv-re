/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_push_call_and_type3 @ 03029d9c (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void history_push_call_and_type3(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_24;
  undefined1 uStack_23;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  history_record_push_type3_repeated(0,param_1,param_2,p_call_setup_sm_state_aux->field_0x22,0,1);
  local_24 = 4;
  uStack_23 = 0;
  uStack_18 = param_1;
  uStack_14 = param_2;
  history_record_push_type3(&local_24);
  return;
}

