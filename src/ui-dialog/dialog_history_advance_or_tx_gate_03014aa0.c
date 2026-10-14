/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_history_advance_or_tx_gate @ 03014aa0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_history_advance_or_tx_gate(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = PTR_DAT_03014bc4[1];
  if (((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\x02')) {
    tx_gate_write_call_record(0);
    dialog_history_menu_step_and_refresh();
  }
  else if (*(char *)PTR_DAT_03014bb0 == '\0') {
    iVar2 = tx_disable_mode_gate_check(0);
    if (iVar2 != 0) {
      ui_event_notify(0x1f);
    }
  }
  else {
    write_field_and_mbox_post(2,1);
  }
  return;
}

