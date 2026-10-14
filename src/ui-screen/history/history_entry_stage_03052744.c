/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_entry_stage @ 03052744 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_entry_stage(void)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_03052814;
  *(undefined1 *)((int)PTR_DAT_03052814 + 1) = 0;
  *(undefined1 *)puVar1 = 1;
  *(undefined1 *)((int)puVar1 + 2) = *(undefined1 *)PTR_DAT_03052818;
  memcpy_bytes_iram((int)puVar1 + 3,p_menu_screen_state,*(undefined1 *)p_dialog_history_ui_state);
  return;
}

