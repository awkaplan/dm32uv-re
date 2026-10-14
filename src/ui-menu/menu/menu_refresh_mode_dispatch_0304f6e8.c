/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_refresh_mode_dispatch @ 0304f6e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_refresh_mode_dispatch(void)

{
  char cVar1;
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304f7f0 + 2);
  if (cVar1 == '\x01') {
    channel_entry_command_byte_router();
  }
  else if (cVar1 == '\x02') {
    contact_edit_mode_dispatcher_0x00_0x01();
  }
  else if (*(char *)PTR_active_screen_subtype_0304f7f4 == '\n') {
    if (*(char *)PTR_DAT_0304f7f8 == '\x03') {
      write_status_mode_byte_pair(0x2a,1);
    }
    else {
      scan_state_tick();
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f7fc + DAT_0304f800),0);
    }
  }
  else {
    write_status_mode_byte_pair(0x2a,1);
  }
  return;
}

