/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_set_digital_mode_enable @ 0301ed68 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void modem_set_digital_mode_enable(byte param_1)

{
  call_setup_sm_state_aux *pcVar1;
  dmr_call_config_state *pdVar2;
  dword dVar3;
  
  pcVar1 = p_call_setup_sm_state_aux;
  dVar3 = SystemControl_Type_11000000.WORK_MODE;
  if (param_1 == 1) {
    dVar3 = dVar3 | 1;
  }
  else {
    dVar3 = dVar3 & 0xfffe;
  }
  SystemControl_Type_11000000.WORK_MODE = dVar3;
  p_call_setup_sm_state_aux->field_0x3 = param_1;
  pcVar1->field_0x4 = param_1;
  pdVar2 = p_dmr_call_config_state;
  p_dmr_call_config_state->field_0x2 = param_1;
  pdVar2->field_0x4 = param_1;
  return;
}

