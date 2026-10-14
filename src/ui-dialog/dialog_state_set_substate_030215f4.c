/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_state_set_substate @ 030215f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_state_set_substate(byte param_1)

{
  dmr_status_flags *pdVar1;
  
  pdVar1 = p_dmr_status_flags;
  p_dmr_status_flags->field_0x2 = param_1;
  if (param_1 == 0) {
    pdVar1->field_0x1 = pdVar1->field_0x1 & 0xfb | 4;
    p_call_setup_sm_state->field_0x5 = 0xb;
  }
  else {
    p_dmr_status_flags->field_0x1 = p_dmr_status_flags->field_0x1 & 0xfb;
    if (param_1 != 1) {
      p_call_setup_sm_state->field_0x5 = 0;
    }
  }
  ui_mode_dispatch(0x20);
  return;
}

