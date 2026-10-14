/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_key_commit_gate_mode1e @ 03016ea4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_key_commit_gate_mode1e(void)

{
  int iVar1;
  
  scan_entry_get_mode_bits(0x1e);
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) {
    iVar1 = poll_condition_group(0x1e);
    if (((PTR_DAT_03016fec[0x2d] & 4) == 0) &&
       (PTR_DAT_03016fe8[1] == '\0' && (*(char *)PTR_DAT_03016fe4 == '\0' && iVar1 != 0))) {
      *(undefined1 *)PTR_active_screen_subtype_03016ff0 = 2;
      PTR_DAT_03016fe8[1] = 3;
      write_field_and_mbox_post(1,0x18);
    }
    else {
      ui_event_notify(0x21);
    }
  }
  return;
}

