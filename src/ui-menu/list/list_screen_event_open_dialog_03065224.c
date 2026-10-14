/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_screen_event_open_dialog @ 03065224 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool list_screen_event_open_dialog(void)

{
  undefined4 uVar1;
  char cVar2;
  int unaff_r8;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000024;
  
  if (unaff_r8 != 0) {
    dialog_request_init(0x80);
    list_record_lookup_and_toggle_by_index(4);
    uVar1 = p_text_entry_buffer;
    cVar2 = strlen_ck803s(p_text_entry_buffer);
    *(char *)PTR_DAT_030652cc = cVar2 + '\x01';
    channel_select_commit_and_notify(SUBPIECE(in_stack_00000024, 2, 1),in_stack_0000000c,uVar1);
  }
  return unaff_r8 != 0;
}

