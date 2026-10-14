/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_or_teardown_handler @ 0302108c (file base 0x03000000; code starts at 0x03001000)
 * Size: 492 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined1 call_setup_or_teardown_handler(char param_1,uint param_2,undefined4 param_3,char param_4)

{
  byte bVar1;
  undefined4 *puVar2;
  call_setup_sm_state_aux *pcVar3;
  undefined4 uVar4;
  int iVar5;
  byte abStack_24 [15];
  undefined1 local_15;
  
  if (param_4 == '\0') {
    uVar4 = 1;
  }
  else if (p_call_setup_sm_state_aux->mode_0x1 == 2) {
    OSTimeDly_ms_wrapper(0x168);
    uVar4 = 2;
  }
  else {
    uVar4 = 2;
  }
  iVar5 = call_setup_state_machine_step(uVar4,p_call_setup_sm_state_aux->field_0x8,&local_15);
  if (iVar5 != 0) {
    return local_15;
  }
  if (p_call_setup_sm_state->field_0x1 != 0) {
    p_call_setup_sm_state->field_0x1 = 0;
    ui_group_flag_set_and_notify(1,1);
    rx_voice_end_stop_rx_record();
  }
  call_setup_set_pending_flag();
  if (*(char *)PTR_DAT_03021204 != '\0') {
    if (*(char *)PTR_DAT_03021204 != '\x01') {
      return 0;
    }
    iVar5 = stored_config_fields_differ(param_1,param_2,param_3);
    if (iVar5 != 1) {
      return 0;
    }
  }
  if (p_call_setup_sm_state_aux->mode_0x1 < 2) {
    mode_gated_field_copy_or_invert(0);
  }
  puVar2 = PTR_DAT_03021204;
  *(undefined1 *)PTR_DAT_03021204 = 1;
  *(char *)((int)puVar2 + 1) = param_1;
  pcVar3 = p_call_setup_sm_state_aux;
  bVar1 = p_call_setup_sm_state_aux->field_0x1a;
  *(byte *)((int)puVar2 + 3) = bVar1;
  *(undefined1 *)(puVar2 + 1) = pcVar3->field_0xa;
  *(byte *)((int)puVar2 + 6) = pcVar3->field_0xb;
  puVar2[4] = param_2;
  puVar2[5] = param_3;
  puVar2 = PTR_DAT_03021204;
  if (param_1 == '\x01') {
    if (param_2 - 1 < 0xfffcdf) {
      *(undefined1 *)((int)PTR_DAT_03021204 + 2) = 1;
    }
    else if (param_2 - 0xffffe0 < 0x10) {
      *(undefined1 *)((int)PTR_DAT_03021204 + 2) = 2;
    }
    else if (param_2 - 0xfffff0 < 0x10) {
      *(undefined1 *)((int)PTR_DAT_03021204 + 2) = 3;
    }
    ui_mode_dispatch(1);
    if (*(char *)((int)PTR_DAT_03021204 + 6) == '\x01') {
      dmr_lc_call_setup_header_build(abStack_24,param_2);
      FUN_00015bd4(1,DAT_03021210);
      *(undefined1 *)p_call_setup_sm_state = 2;
      call_event_record_append_to_history
                (1,*(undefined1 *)(PTR_DAT_03021204 + 1),1,abStack_24,param_2,param_3);
    }
    else {
      *(undefined1 *)p_call_setup_sm_state = 2;
      memset_bytes(abStack_24,0,0xc);
      call_event_record_append_to_history
                (1,*(undefined1 *)(PTR_DAT_03021204 + 1),0,abStack_24,param_2,param_3);
    }
  }
  else {
    *(undefined1 *)((int)PTR_DAT_03021204 + 2) = 0;
    if ((bVar1 == 1) && (param_4 == '\0')) {
      *(undefined1 *)(puVar2 + 2) = 0;
      *(byte *)((int)puVar2 + 7) = *(byte *)((int)puVar2 + 7) & 0xfe | 1;
      ui_mode_dispatch(4);
      history_push_call_and_type3(puVar2[4],puVar2[5]);
      *(undefined1 *)p_call_setup_sm_state = 2;
    }
    else {
      ui_mode_dispatch(1);
      if (*(char *)((int)PTR_DAT_030212bc + 6) == '\x01') {
        dmr_lc_call_setup_header_build(abStack_24,param_2);
        FUN_00015bd4(1,DAT_030212c0);
        *(undefined1 *)p_call_setup_sm_state = 2;
        call_event_record_append_to_history
                  (0,*(undefined1 *)(PTR_DAT_030212bc + 1),1,abStack_24,param_2,param_3);
      }
      else {
        *(undefined1 *)p_call_setup_sm_state = 2;
        memset_bytes(abStack_24,0,0xc);
        call_event_record_append_to_history
                  (0,*(undefined1 *)(PTR_DAT_030212bc + 1),0,abStack_24,param_2,param_3);
      }
    }
  }
  return 0;
}

