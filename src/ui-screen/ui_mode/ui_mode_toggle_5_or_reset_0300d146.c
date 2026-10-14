/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_mode_toggle_5_or_reset @ 0300d146 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_mode_toggle_5_or_reset(void)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_0300d240;
  if ((PTR_DAT_0300d240[7] & 1) == 0) {
    *PTR_DAT_0300d240 = 0;
    p_call_setup_sm_state->field_0x5 = 0;
    if (p_call_setup_sm_state_aux->field_0x16 < (byte)puVar1[8]) {
      ui_mode_group2_flag_set(1,4);
    }
  }
  else {
    *(undefined1 *)PTR_DAT_0300d248 = 0;
    p_call_setup_sm_state->field_0x5 = 5;
    ui_mode_group2_flag_set(1,8);
  }
  os_sem_post(p_ucos_mutex_00038438);
  return;
}

