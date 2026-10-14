/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_entry_verify_post_or_flag @ 03052764 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_entry_verify_post_or_flag(void)

{
  int iVar1;
  
  if (*(char *)PTR_DAT_03052814 == '\x01') {
    if ((*(char *)((int)PTR_DAT_03052814 + 2) == *(char *)PTR_DAT_03052818) &&
       (iVar1 = buffer_compare_memcmp_style
                          (DAT_03052824,p_menu_screen_state,*(undefined1 *)p_dialog_history_ui_state
                          ), iVar1 == 0)) {
      write_field_and_mbox_post(1,0x2a);
    }
    else {
      *(undefined1 *)((int)PTR_DAT_03052814 + 1) = 1;
    }
  }
  return;
}

