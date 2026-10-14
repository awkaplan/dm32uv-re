/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_mode_reset @ 0300d0cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_mode_reset(void)

{
  call_setup_sm_state *pcVar1;
  
  ui_mode_group2_flag_set(1,1);
  tx_voice_end_stop_tx_record();
  pcVar1 = p_call_setup_sm_state;
  *(undefined1 *)p_call_setup_sm_state = 0;
  *PTR_DAT_0300d240 = 0;
  pcVar1->field_0x5 = 0;
  clear_byte_field_dat03023b88_0x15();
  os_sem_post(p_ucos_mutex_00038438);
  return;
}

