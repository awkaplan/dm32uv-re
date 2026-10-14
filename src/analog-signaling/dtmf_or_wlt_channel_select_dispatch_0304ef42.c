/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_or_wlt_channel_select_dispatch @ 0304ef42 (file base 0x03000000; code starts at 0x03001000)
 * Size: 182 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dtmf_or_wlt_channel_select_dispatch(void)

{
  undefined4 uVar1;
  short *psVar2;
  undefined4 *puVar3;
  char cVar4;
  uint uVar5;
  
  if ((*(byte *)PTR_DAT_0304efb4 & 0x40) == 0) {
    dialog_show_icon_and_number
              (0,**(undefined4 **)
                   (PTR_PTR_0304f118 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else {
    wlt_cmd_string_build(1);
    uVar1 = p_text_entry_buffer;
    cVar4 = strlen_ck803s(p_text_entry_buffer);
    *(char *)PTR_DAT_0304efbc = cVar4 + '\x01';
    p_radio_mode_state_0003e318[1].flags_0x7 = p_radio_mode_state_0003e318[1].flags_0x7 & 0xfb | 4;
    channel_select_commit_and_notify(3,*PTR_DAT_0304efc4,uVar1);
    psVar2 = p_active_screen_index_list;
    menu_option_list_dispatch(1,p_active_screen_index_list,p_active_screen_index_list + 1);
    puVar3 = PTR_PTR_0304f12c;
    if (*psVar2 == 0) {
      history_queue_pop();
    }
    else {
      uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      *(undefined1 *)p_active_screen_option_count =
           *(undefined1 *)(PTR_PTR_0304f12c + uVar5 * 2 + 1);
      *p_active_screen_option_ptr_array = puVar3[uVar5 * 2];
      *(undefined1 *)PTR_active_screen_subtype_0304f138 =
           *(undefined1 *)((int)puVar3 + uVar5 * 8 + 5);
    }
    write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f13c + DAT_0304f140),0);
  }
  return;
}

