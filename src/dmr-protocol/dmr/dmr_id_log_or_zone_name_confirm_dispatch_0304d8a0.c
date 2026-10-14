/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_id_log_or_zone_name_confirm_dispatch @ 0304d8a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 312 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_id_log_or_zone_name_confirm_dispatch(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_14 [4];
  undefined2 uStack_10;
  undefined1 auStack_e [2];
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304d9a4 + 2);
  if (cVar1 == '\x02') {
    uVar2 = *(undefined1 *)PTR_DAT_0304d9a8;
    uVar3 = channel_free_slot_count_until_nth(uVar2,*(short *)PTR_DAT_0304d9ac + 1);
    dmr_id_log_append(uVar2,uVar3);
    dialog_show_icon_and_number
              (1,**(undefined4 **)
                   (PTR_PTR_0304d9b0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else if (cVar1 == '\x03') {
    if (*(char *)PTR_active_screen_subtype_0304d9b4 == '\n') {
      if (*(char *)PTR_DAT_0304d9b8 == '\x03') {
        p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xdf;
        OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_14);
        *(undefined1 *)PTR_DAT_0304d9c4 = 0xf0;
        if (*(char *)p_text_entry_buffer == '\0') {
          dialog_show_icon_and_number
                    (0,**(undefined4 **)
                         (PTR_PTR_0304d9cc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        }
        else {
          iVar4 = zone_name_exists_check(p_text_entry_buffer);
          if (iVar4 == 0) {
            memcpy_bytes_iram(p_list_row_text_buffer,p_text_entry_buffer,0x10);
            if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
              memcpy_bytes_iram(DAT_0304d9d8,p_text_entry_buffer,0x10);
            }
            else {
              memcpy_bytes_iram(DAT_0304db74,p_text_entry_buffer,0x10);
            }
            channel_offset_minus_0x10(*(char *)PTR_DAT_0304db7c + '\x01',auStack_e,&uStack_10);
            flash_block_write(auStack_e[0],uStack_10,p_text_entry_buffer,0x10);
            dialog_show_icon_and_number_from_ptr();
          }
          else {
            dialog_show_icon_and_number
                      (0,PTR_PTR_0304d9d0[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
          }
        }
      }
      else {
        scan_state_tick();
        write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304db80 + DAT_0304db84),0);
      }
    }
  }
  else {
    write_status_mode_byte_pair(0x23,1);
  }
  return;
}

