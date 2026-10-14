/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_privacy_alg_select_from_cps_type @ 0301f074 (file base 0x03000000; code starts at 0x03001000)
 * Size: 168 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_privacy_alg_select_from_cps_type(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_1 == 0) {
    return;
  }
  if (*(char *)PTR_DAT_0301f148 == '\x01') {
LAB_0301f0a2:
    p_call_setup_sm_state_aux->field_0xb = 0;
    uVar2 = DAT_0301f144;
    memset_bytes(DAT_0301f144,0,10);
    dmr_privacy_custom_key_delta_encode();
    indexed_ramp_field_store_b(uVar2,7);
    indexed_ramp_field_store_a(uVar2,7);
  }
  else {
    stack_buffer_triple_call_helper();
    bVar1 = *(byte *)PTR_DAT_0301f148;
    if (bVar1 == 2) {
      *(undefined1 *)PTR_DAT_0301f150 = 1;
      puVar3 = PTR_DAT_0301f154;
      *(undefined1 *)PTR_DAT_0301f154 = 1;
      if (*(char *)((int)puVar3 + 1) == '\0') {
        return;
      }
      p_call_setup_sm_state_aux->field_0xb = 1;
      return;
    }
    if (bVar1 < 3) {
      if (bVar1 == 1) goto LAB_0301f0a2;
    }
    else {
      if (bVar1 == 3) {
        *(undefined1 *)PTR_DAT_0301f150 = 4;
        puVar3 = PTR_DAT_0301f154;
        *(undefined1 *)PTR_DAT_0301f154 = 4;
        if (*(char *)((int)puVar3 + 1) == '\0') {
          return;
        }
        p_call_setup_sm_state_aux->field_0xb = 1;
        return;
      }
      if (bVar1 == 4) {
        *(undefined1 *)PTR_DAT_0301f150 = 5;
        puVar3 = PTR_DAT_0301f154;
        *(undefined1 *)PTR_DAT_0301f154 = 5;
        if (*(char *)((int)puVar3 + 1) == '\0') {
          return;
        }
        p_call_setup_sm_state_aux->field_0xb = 1;
        return;
      }
    }
    p_call_setup_sm_state_aux->field_0xb = 0;
    *(undefined1 *)PTR_DAT_0301f148 = 0;
  }
  return;
}

