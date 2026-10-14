/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_slot_remove_and_resave_confirm @ 0304f744 (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void contact_slot_remove_and_resave_confirm(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  menu_screen_state *pmVar4;
  
  pmVar4 = p_menu_screen_state;
  cVar1 = *(char *)p_active_screen_state_word;
  if (cVar1 == '\0') {
    write_status_mode_byte_pair(0x2a,1);
  }
  else if (cVar1 == '\x01') {
    flash_list_entry_remove_and_compact(p_menu_screen_state->index_0x3 + 1,5);
    puVar3 = PTR_DAT_0304f7dc;
    uVar2 = p_text_entry_buffer;
    buffer_prepend_3byte_le(0,p_text_entry_buffer,*(undefined1 *)PTR_DAT_0304f7dc);
    contact_edit_save_flow1(uVar2,*(byte *)puVar3 + 3,5,0);
    dialog_show_icon_and_two_numbers
              (0x30,0x30,_DAT_0304f808,
               **(undefined4 **)
                 (PTR_PTR_0304f7e8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
               _DAT_0304f804);
    OSTimeDly_ms_wrapper(1000);
    pmVar4->index_0x3 = 0;
    PTR_DAT_0304f80c[3] = 1;
    history_queue_pop();
    history_queue_pop();
    history_queue_pop();
  }
  else if (cVar1 == '\x02') {
    write_status_mode_byte_pair(0x2a,1);
  }
  return;
}

