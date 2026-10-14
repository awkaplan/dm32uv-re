/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_command_dispatch_select_or_save_name @ 03050450 (file base 0x03000000; code starts at 0x03001000)
 * Size: 264 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_command_dispatch_select_or_save_name(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 auStack_c [4];
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03050574 + 2);
  if (cVar1 == '\x02') {
    uVar2 = *(undefined1 *)PTR_DAT_03050578;
    uVar4 = flash_field_channel_table_lookup(uVar2,*(byte *)p_active_screen_state_word + 1);
    roam_zone_slot_byte_write_with_wear_count(uVar2,uVar4);
    dialog_show_icon_and_number
              (1,**(undefined4 **)
                   (PTR_PTR_0305057c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else if (cVar1 == '\x03') {
    if (*(char *)PTR_active_screen_subtype_03050580 == '\n') {
      if (*(char *)PTR_DAT_03050584 == '\x03') {
        p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xdf;
        OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_c);
        *(undefined1 *)PTR_DAT_03050590 = 0xf0;
        if (*(char *)p_text_entry_buffer == '\0') {
          dialog_show_icon_and_number
                    (0,**(undefined4 **)
                         (PTR_PTR_03050598 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        }
        else {
          iVar5 = flash_block65_string_lookup_exists(p_text_entry_buffer);
          puVar3 = p_text_entry_buffer;
          if (iVar5 == 0) {
            memcpy_bytes_iram(p_list_row_text_buffer,p_text_entry_buffer,0x10);
            flash_block_write(0x65,(uint)*(byte *)PTR_DAT_03050578 * 0x21 + 0x10,puVar3,0x10);
            dialog_show_icon_and_number_from_ptr();
          }
          else {
            dialog_show_icon_and_number
                      (0,PTR_PTR_0305059c[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
          }
        }
      }
      else {
        scan_state_tick();
        write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0305056c + DAT_03050570),0);
      }
    }
  }
  else {
    write_status_mode_byte_pair(0x2a,1);
  }
  return;
}

