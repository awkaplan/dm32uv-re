/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: field_mode_write_and_dispatch_to_0301f170 @ 0301ec58 (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void field_mode_write_and_dispatch_to_0301f170(int param_1__w,int param_2__w,undefined4 param_3,undefined4 param_4,int param_5__w)

{
  char param_1 = (char)param_1__w;
  byte param_2 = (byte)param_2__w;
  undefined2 param_5 = (undefined2)param_5__w;
  call_setup_sm_state *pcVar1;
  
  pcVar1 = p_call_setup_sm_state;
  p_call_setup_sm_state->flags_0x19 = p_call_setup_sm_state->flags_0x19 & 0xf7;
  pcVar1->field_0x1a = 0;
  if (param_1 == '\x01') {
    p_call_setup_sm_state_aux->field_0x1b = 0;
    config_struct_write_with_flag_post(1,param_4,param_3,param_5);
  }
  else if (param_1 == '\0') {
    p_call_setup_sm_state_aux->field_0x1b = param_2;
    config_struct_write_with_flag_post(0,param_4,param_3,param_5);
  }
  else if (param_1 == '\x02') {
    p_call_setup_sm_state_aux->field_0x1b = 0;
    config_struct_write_with_flag_post(1,param_4,param_3,param_5);
  }
  return;
}

