/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_key_commit_gate_mode0b_variant2 @ 03015a08 (file base 0x03000000; code starts at 0x03001000)
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

void ui_key_commit_gate_mode0b_variant2(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = scan_entry_get_mode_bits(0xb);
  if ((PTR_DAT_03015ab8[3] & 0x40) == 0) {
    iVar2 = poll_condition_group(0xb);
    if ((*(char *)PTR_DAT_03015ad4 == '\0') &&
       (iVar1 != 1 && (iVar1 != 3 && (*(char *)PTR_DAT_03015abc == '\0' && iVar2 != 0)))) {
      *(undefined1 *)PTR_active_screen_subtype_03015ad0 = 2;
      PTR_DAT_03015acc[1] = 0x10;
      write_field_and_mbox_post(1,0x18);
    }
    else {
      ui_event_notify(0x21);
    }
  }
  return;
}

