/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_control_char_dispatch_dialog_history @ 0301eb90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 176 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void protocol_control_char_dispatch_dialog_history(char param_1)

{
  undefined4 *puVar1;
  call_setup_sm_state *pcVar2;
  
  pcVar2 = p_call_setup_sm_state;
  puVar1 = PTR_DAT_0301ec18;
  if (param_1 == '\x02') {
    *(byte *)p_dmr_status_flags = *(byte *)p_dmr_status_flags & 0xbf;
    dialog_state_set_substate(2);
  }
  else if (param_1 == '\b') {
    p_call_setup_sm_state->flags_0x19 = p_call_setup_sm_state->flags_0x19 & 0xf7 | 8;
    if (pcVar2->field_0x1a == 2) {
      OSFlagPost_wrapper_set_passthrough(0x200);
    }
    else if (pcVar2->field_0x1a == 3) {
      OSFlagPost_wrapper_set_passthrough(0x4000);
    }
    else {
      OSFlagPost_wrapper_set_passthrough(0x80);
    }
    p_call_setup_sm_state->field_0x1a = 0;
  }
  else if (param_1 == '\x01') {
    if ((byte)(p_call_setup_sm_state->field_0x5 - 1) < 2) {
      history_slot_allocate_and_init(0,0);
    }
    else if ((*(byte *)((int)PTR_DAT_0301ec18 + 7) & 1) == 0) {
      if (p_call_setup_sm_state->field_0x5 == 4) {
        modem_fm_ptt_set(0);
        p_call_setup_sm_state->field_0x5 = 0;
      }
    }
    else {
      *(byte *)((int)PTR_DAT_0301ec18 + 7) = *(byte *)((int)PTR_DAT_0301ec18 + 7) & 0xfe;
      *(undefined1 *)puVar1 = 0;
      p_call_setup_sm_state->field_0x5 = 0;
    }
    p_call_setup_sm_state->flags_0x18 = p_call_setup_sm_state->flags_0x18 & 0xef;
  }
  return;
}

