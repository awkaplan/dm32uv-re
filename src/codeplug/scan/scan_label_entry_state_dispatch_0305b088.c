/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_label_entry_state_dispatch @ 0305b088 (file base 0x03000000; code starts at 0x03001000)
 * Size: 152 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scan_label_entry_state_dispatch(void)

{
  byte bVar1;
  
  bVar1 = *PTR_DAT_0305b188;
  if (bVar1 == 2) {
    if (*(byte *)PTR_DAT_0305b194 + 9 < (uint)*(byte *)PTR_DAT_0305b198) {
      tx_gate_write_call_record(1);
      *(char *)PTR_DAT_0305b194 = *(char *)PTR_DAT_0305b194 + '\t';
    }
    else {
      if ((int)(*(byte *)PTR_DAT_0305b198 - 1) / 9 == *(byte *)PTR_DAT_0305b194 / 9) {
        tx_gate_write_call_record(0);
        return;
      }
      tx_gate_write_call_record(1);
      *(char *)PTR_DAT_0305b194 = *(char *)PTR_DAT_0305b198 + -1;
    }
    text_entry_char_picker_render_fixed();
    scan_list_row_render();
  }
  else if (bVar1 < 3) {
    if (bVar1 == 1) {
      *PTR_DAT_0305b188 = 2;
      *(undefined1 *)PTR_DAT_0305b194 = 0;
      tx_gate_write_call_record(1);
      text_entry_char_picker_render_fixed();
      scan_list_row_render();
    }
  }
  else if (bVar1 == 3) {
    text_entry_char_append_and_scroll();
  }
  else if (bVar1 == 4) {
    text_entry_char_row_step_wrap();
  }
  return;
}

