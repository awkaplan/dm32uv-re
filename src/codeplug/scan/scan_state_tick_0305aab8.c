/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_state_tick @ 0305aab8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scan_state_tick(void)

{
  char cVar1;
  
  cVar1 = *(char *)PTR_DAT_0305abb0;
  if (cVar1 == '\x02') {
    *(undefined1 *)PTR_DAT_0305abb0 = 3;
    *(undefined1 *)PTR_DAT_0305aba8 = 0;
    *(undefined1 *)PTR_DAT_0305abb4 = 0;
    *(undefined1 *)PTR_DAT_0305aba0 = 0;
    *(undefined1 *)PTR_DAT_0305abb8 = 0;
    text_entry_char_insert_and_render();
  }
  else if (cVar1 == '\x04') {
    if (*(char *)((int)PTR_DAT_0305abb0 + 3) == '\0') {
      *(undefined1 *)PTR_DAT_0305abb0 = 3;
      *(undefined1 *)PTR_DAT_0305aba8 = 0;
      *(undefined1 *)PTR_DAT_0305abb4 = 0;
      *(undefined1 *)PTR_DAT_0305aba0 = 0;
      *(undefined1 *)PTR_DAT_0305abb8 = 0;
      text_entry_char_insert_and_render();
    }
    else {
      *(undefined *)p_text_entry_buffer_alias =
           PTR_s___________________<>___________0305abc4[*(byte *)p_text_entry_current_char_alias];
      scan_list_scroll_update();
    }
    *(undefined1 *)PTR_DAT_0305abb0 = 3;
  }
  else if (cVar1 == '\x01') {
    *(undefined1 *)PTR_DAT_0305abb0 = 2;
    *(undefined1 *)PTR_DAT_0305abb4 = 0;
    text_entry_char_picker_render_fixed();
    scan_list_row_render();
  }
  return;
}

