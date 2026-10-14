/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_event_record_build_dispatch @ 03029dd0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_event_record_build_dispatch(undefined4 param_1,undefined4 param_2)

{
  if (p_dmr_status_flags->field_0x3 == 6) {
    history_record_push_type3_repeated(1,param_1,param_2,3,0,1);
  }
  else {
    history_record_push_type3_repeated(0,param_1,param_2,p_call_setup_sm_state_aux->field_0x22,0,1);
  }
  if (p_dmr_status_flags->field_0x3 < 7) {
                    /* WARNING: Could not recover jumptable at 0x03029e14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_03029e20[p_dmr_status_flags->field_0x3] & 0xfffffffe))();
    return;
  }
  return;
}

