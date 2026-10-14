/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mode_gated_field_copy_or_invert @ 0302384c (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void mode_gated_field_copy_or_invert(char param_1)

{
  byte bVar1;
  int iVar2;
  
  if (p_call_setup_sm_state_aux->mode_0x1 == 0) {
    if (param_1 == '\0') {
      p_dmr_call_config_state->field_0x4 = p_dmr_call_config_state->field_0x2;
    }
    else {
      bVar1 = p_dmr_call_config_state->field_0x2;
      if (*(char *)((uint)bVar1 + p_dmr_config_unpack_state) == '\0') {
        p_dmr_call_config_state->field_0x4 = bVar1;
      }
      else {
        p_dmr_call_config_state->field_0x4 = ~(bVar1 != 0);
      }
    }
  }
  else if (p_call_setup_sm_state_aux->mode_0x1 == 1) {
    if (param_1 == '\0') {
      iVar2 = data_buffer_offset_2_nonzero_check();
      if (iVar2 == 0) {
        p_dmr_call_config_state->field_0x4 = p_dmr_call_config_state->field_0x2;
      }
      else {
        p_dmr_call_config_state->field_0x4 = p_call_setup_sm_state_aux->field_0x3;
      }
    }
    else {
      p_dmr_call_config_state->field_0x4 = ~(p_dmr_call_config_state->field_0x2 != 0);
    }
  }
  return;
}

