/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_history_step_or_exit_to_idle @ 03015678 (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_history_step_or_exit_to_idle(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = PTR_DAT_030157a4[1];
  if (((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\x02')) {
    tx_gate_write_call_record(0);
    dialog_history_menu_step_and_refresh();
  }
  else if ((*(char *)PTR_DAT_030157a8 == '\0') && ((PTR_DAT_030157ac[8] & 1) == 0)) {
    if ((PTR_DAT_0301579c[1] & 0x80) != 0) {
      rda5807m_fm_off();
    }
    mode_transition_cleanup();
    iVar2 = get_current_mode_state2();
    if (iVar2 != 0) {
      set_flag_byte_03064328(4);
    }
    PTR_DAT_030157b0[0x11] = PTR_DAT_030157b0[0x11] & 0xfe | 1;
    write_status_mode_byte_pair(0x69,1);
    ui_event_notify(0x18);
    write_field_and_mbox_post(1,0x2b);
  }
  return;
}

