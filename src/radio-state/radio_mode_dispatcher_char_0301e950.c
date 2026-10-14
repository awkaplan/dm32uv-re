/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_mode_dispatcher_char @ 0301e950 (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_mode_dispatcher_char(int param_1__w)

{
  char param_1 = (char)param_1__w;
  undefined1 auStack_8 [4];
  
  if (param_1 == '\0') {
    p_call_setup_sm_state->flags_0x19 = p_call_setup_sm_state->flags_0x19 & 0xfe | 1;
    if ((*(byte *)((int)PTR_DAT_0301ea68 + 7) & 2) != 0) {
      osflag_pend_consume_with_decisecond_timeout_alt(0x1000,0,0,auStack_8);
      os_flag_post_clear_0300c8d4(0x1000);
    }
    if (*(char *)PTR_DAT_0301ea68 != '\0') {
      history_mode_entry_init();
    }
    if (p_call_setup_sm_state->field_0x1 != 0) {
      OSFlagPost_wrapper_set_fixed_grp(4);
    }
    radio_reset_sequence_with_clock_reset();
    set_field_bits_and_post_ui_mode_group_0x10(1);
  }
  else if (param_1 == '\x01') {
    modem_queue_drain_and_stop();
    p_call_setup_sm_state->flags_0x19 = p_call_setup_sm_state->flags_0x19 & 0xfe;
  }
  return;
}

