/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_step_ready_gate @ 0301dfb4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 call_setup_step_ready_gate(char param_1,char param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == '\x02') {
    uVar2 = 0;
  }
  else if (param_1 == '\x03') {
    iVar1 = call_setup_target_present_check();
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      p_call_setup_sm_state_aux->field_0x13 = 1;
      *param_3 = 1;
      uVar2 = 1;
    }
  }
  else {
    iVar1 = call_setup_target_present_check();
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else if (param_2 == '\x02') {
      iVar1 = call_setup_state_advance_gate();
      if (iVar1 == 0) {
        iVar1 = dmr_call_config_state_field2_not_one();
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          p_call_setup_sm_state_aux->field_0x13 = 1;
          *param_3 = 1;
          uVar2 = 1;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      iVar1 = dmr_call_config_state_field2_not_one();
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        p_call_setup_sm_state_aux->field_0x13 = 1;
        *param_3 = 1;
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

