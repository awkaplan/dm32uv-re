/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_history_step_or_mbox_post @ 0301428c (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_history_step_or_mbox_post(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_0301434c[1];
  if (((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\x02')) {
    tx_gate_write_call_record(0);
    dialog_history_menu_step_and_refresh();
  }
  else if (*(char *)PTR_DAT_03014350 == '\0') {
    *(undefined1 *)PTR_active_screen_subtype_03014354 = 2;
    PTR_DAT_03014358[1] = 0xd;
    write_field_and_mbox_post(1,0x18);
  }
  else {
    write_field_and_mbox_post(2,2);
  }
  return;
}

