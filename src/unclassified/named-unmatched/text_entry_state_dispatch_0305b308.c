/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_state_dispatch @ 0305b308 (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_state_dispatch(void)

{
  byte bVar1;
  
  bVar1 = *PTR_DAT_0305b45c;
  if (bVar1 == 2) {
    tx_gate_write_call_record(1);
    if (*(byte *)PTR_DAT_0305b460 < 9) {
      *PTR_DAT_0305b45c = 1;
      text_entry_char_picker_render();
      scan_list_row_render();
    }
    else {
      *(byte *)PTR_DAT_0305b460 = *(byte *)PTR_DAT_0305b460 - 9;
      text_entry_char_picker_render_fixed();
      scan_list_row_render();
    }
  }
  else if (bVar1 < 3) {
    if (bVar1 == 1) {
      tx_gate_write_call_record(0);
    }
  }
  else if (bVar1 == 3) {
    text_entry_scroll_and_display_refresh();
  }
  else if (bVar1 == 4) {
    text_entry_char_step_up_and_render();
  }
  return;
}

