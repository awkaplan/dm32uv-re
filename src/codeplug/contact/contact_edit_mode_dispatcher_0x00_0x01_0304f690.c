/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_edit_mode_dispatcher_0x00_0x01 @ 0304f690 (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void contact_edit_mode_dispatcher_0x00_0x01(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = PTR_DAT_0304f7dc;
  uVar1 = p_text_entry_buffer;
  if (*(char *)p_active_screen_state_word == '\0') {
    write_status_mode_byte_pair(0x2a,1);
  }
  else if (*(char *)p_active_screen_state_word == '\x01') {
    buffer_prepend_3byte_le(0,p_text_entry_buffer,*(undefined1 *)PTR_DAT_0304f7dc);
    contact_edit_save_flow1(uVar1,*(byte *)puVar2 + 3,5,0);
    dialog_show_icon_and_number
              (1,**(undefined4 **)
                   (PTR_PTR_0304f7e8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    history_queue_pop();
    history_queue_pop();
  }
  return;
}

