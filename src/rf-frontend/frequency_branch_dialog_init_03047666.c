/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: frequency_branch_dialog_init @ 03047666 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void frequency_branch_dialog_init(void)

{
  ushort uVar1;
  undefined4 *puVar2;
  char cVar3;
  
  SUBPIECE_SET(uVar1, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
  SUBPIECE_SET(uVar1, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
  if (uVar1 < 4000) {
    dialog_request_init(0x10);
    if (*(char *)PTR_DAT_03047744 == '\x01') {
      cVar3 = strlen_ck803s(p_text_entry_buffer);
      *(char *)PTR_DAT_03047774 = cVar3 + '\x01';
    }
    puVar2 = PTR_DAT_03047778;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03047778 + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03047740 = *(undefined1 *)((int)puVar2 + 5);
    p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xdf | 0x20;
  }
  else {
    format_and_write_status_field2(PTR_PTR_0304776c[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
    history_queue_pop();
  }
  return;
}

