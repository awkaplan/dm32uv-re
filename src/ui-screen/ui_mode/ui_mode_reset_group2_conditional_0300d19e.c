/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_mode_reset_group2_conditional @ 0300d19e (file base 0x03000000; code starts at 0x03001000)
 * Size: 156 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_mode_reset_group2_conditional(void)

{
  call_setup_sm_state *pcVar1;
  
  pcVar1 = p_call_setup_sm_state;
  if ((p_call_setup_sm_state->flags_0x19 & 8) == 0) {
    if (*(char *)PTR_DAT_0300d250 == '\0') {
      if ((((p_radio_mode_state_0003e318[1].flags_0x5 == 0) ||
           (p_radio_mode_state_0003e318[1].flags_0x5 == 2)) && (PTR_DAT_0300d258[1] != '\x01')) &&
         ((p_radio_mode_state_0003e318[1].flags_0x7 & 4) == 0)) {
        ui_mode_group2_flag_set(2,1);
        p_call_setup_sm_state->field_0x5 = 0;
      }
      else {
        ui_mode_group2_flag_set(2,8);
        if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) != 0) {
          p_call_setup_sm_state->field_0x5 = 0;
        }
      }
    }
    else {
      ui_mode_group2_flag_set(2,1);
      p_call_setup_sm_state->field_0x5 = 0;
    }
  }
  else {
    p_call_setup_sm_state->flags_0x19 = p_call_setup_sm_state->flags_0x19 & 0xf7;
    ui_mode_group2_flag_set(2,2);
    if ((pcVar1->field_0x5 == 8) || (pcVar1->field_0x5 == 10)) {
      p_call_setup_sm_state->field_0x5 = 0;
    }
  }
  os_sem_post(p_ucos_mutex_00038438);
  return;
}

