/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_step_permitted @ 0301df0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 168 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

int call_setup_step_permitted(char mode_a,char mode_b,byte *out_flag)

{
  int iVar1;
  
  if (mode_a == '\x02') {
    iVar1 = 0;
  }
  else if (mode_a == '\x03') {
    iVar1 = call_active_and_mode_not_2();
    if (iVar1 == 0) {
      if (p_call_setup_sm_state->field_0x1 == 0) {
        iVar1 = 0;
      }
      else {
        p_call_setup_sm_state_aux->field_0x13 = 1;
        *out_flag = 1;
        iVar1 = 1;
      }
    }
    else {
      p_call_setup_sm_state_aux->field_0x13 = 1;
      *out_flag = 1;
      iVar1 = 1;
    }
  }
  else if (mode_b == '\0') {
    iVar1 = 0;
  }
  else if (mode_b == '\x01') {
    iVar1 = call_active_and_mode_not_2();
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = dmr_call_config_state_field2_not_one();
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        p_call_setup_sm_state_aux->field_0x13 = 1;
        *out_flag = 1;
        iVar1 = 1;
      }
    }
  }
  else if (mode_b == '\x02') {
    iVar1 = call_active_and_mode_not_2();
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = call_setup_state_advance_gate();
      if (iVar1 == 0) {
        iVar1 = dmr_call_config_state_field2_not_one();
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          p_call_setup_sm_state_aux->field_0x13 = 1;
          *out_flag = 1;
          iVar1 = 1;
        }
      }
      else {
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}

