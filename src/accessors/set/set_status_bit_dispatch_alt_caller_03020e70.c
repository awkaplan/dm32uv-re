/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: set_status_bit_dispatch_alt_caller @ 03020e70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 188 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: accessors
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint set_status_bit_dispatch_alt_caller(uint param_1,undefined4 param_2)

{
  dmr_status_flags *pdVar1;
  int iVar2;
  uint uVar3;
  byte local_d;
  
  param_1 = param_1 & 0xff;
  iVar2 = call_setup_state_machine_step(1,p_call_setup_sm_state_aux->field_0x8,&local_d);
  if (iVar2 == 0) {
    call_setup_set_pending_flag();
    if (p_call_setup_sm_state_aux->mode_0x1 < 2) {
      mode_gated_field_copy_or_invert(0);
    }
    pdVar1 = p_dmr_status_flags;
    *(byte *)p_dmr_status_flags = *(byte *)p_dmr_status_flags & 0xbf | 0x40;
    pdVar1->field_0x4 = 0;
    *(undefined4 *)&pdVar1->field_0x8_0 = param_2;
    if (param_1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x03020eb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*(code *)(PTR_PTR_03020ecc[param_1] & 0xfffffffe))();
      return uVar3;
    }
    history_event_record_build_dispatch
              (param_2,*(undefined4 *)&p_call_setup_sm_state_aux->field_0x24_0);
    *(undefined1 *)p_call_setup_sm_state = 2;
    dialog_state_set_substate(0);
    clear_byte_field_dat03023b88_0x15();
    uVar3 = 0;
  }
  else if (param_1 == 4) {
    call_setup_set_pending_flag();
    if (p_call_setup_sm_state_aux->mode_0x1 < 2) {
      mode_gated_field_copy_or_invert(0);
    }
    pdVar1 = p_dmr_status_flags;
    *(byte *)p_dmr_status_flags = *(byte *)p_dmr_status_flags & 0xbf | 0x40;
    pdVar1->field_0x4 = 0;
    *(undefined4 *)&pdVar1->field_0x8_0 = param_2;
    pdVar1->field_0x3 = 6;
    history_event_record_build_dispatch
              (param_2,*(undefined4 *)&p_call_setup_sm_state_aux->field_0x24_0);
    *(undefined1 *)p_call_setup_sm_state = 2;
    dialog_state_set_substate(0);
    clear_byte_field_dat03023b88_0x15();
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)local_d;
  }
  return uVar3;
}

