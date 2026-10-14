/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: field_entry_confirm_multicontext_dispatch @ 0305063c (file base 0x03000000; code starts at 0x03001000)
 * Size: 488 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void field_entry_confirm_multicontext_dispatch(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint unaff_r4;
  undefined1 auStack_28 [19];
  undefined1 auStack_15 [3];
  undefined1 uStack_12;
  undefined4 local_10;
  
  puVar3 = PTR_DAT_0305088c;
  uVar2 = p_text_entry_buffer;
  if (*(char *)((uint)p_menu_screen_state->index_0x1 + DAT_03050748 + 2) == '\0') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0305074c + 2);
    if (cVar1 == '\0') {
      cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03050720 + 2);
      if (cVar1 == '\x02') {
        cVar1 = *(char *)((uint)p_menu_screen_state->index_0x5 + DAT_03050750 + 2);
        if (cVar1 == '\0') {
          if (*(char *)PTR_DAT_03050754 == '\x03') {
            *(undefined1 *)PTR_DAT_03050758 = 0xf0;
            if (*(char *)p_text_entry_buffer == '\0') {
              dialog_show_icon_and_two_numbers
                        (0x30,0x30,PTR_DAT_03050764,
                         **(undefined4 **)
                           (PTR_PTR_0305075c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                         PTR_LAB_03050760);
              OSTimeDly_ms_wrapper(1000);
            }
            else {
              strcpy_ck803s(p_list_row_text_buffer,p_text_entry_buffer);
            }
            p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xf7;
            history_queue_pop();
          }
          else {
            scan_state_tick();
            write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03050728 + DAT_0305072c),0);
          }
        }
        else if (cVar1 == '\x01') {
          iVar4 = ascii_digits_to_uint();
          if (iVar4 == 1) {
            p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xfb;
            history_queue_pop();
            strcpy_ck803s(DAT_0305076c,_DAT_03050770);
          }
          else {
            write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0305087c + DAT_03050880),0);
          }
        }
      }
      else if (cVar1 == '\x04') {
        cVar1 = *(char *)p_active_screen_state_word;
        if (cVar1 == '\x01') {
          write_status_mode_byte_pair(0x31,1);
        }
        else if (cVar1 == '\x02') {
          buffer_prepend_3byte_le(0,p_text_entry_buffer,*(undefined1 *)PTR_DAT_0305088c);
          contact_edit_save_flow1(uVar2,*(byte *)puVar3 + 3,5,0);
          dialog_show_icon_and_two_numbers
                    (0x30,0x30,PTR_DAT_0305089c,
                     **(undefined4 **)
                       (PTR_PTR_03050894 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                     PTR_LAB_03050898);
          OSTimeDly_ms_wrapper(1000);
          history_queue_pop();
          history_queue_pop();
        }
        else if (cVar1 == '\x03') {
          history_queue_pop();
          history_queue_pop();
        }
        else {
          local_10 = 0;
          history_record_lookup_by_type(2,*(short *)PTR_DAT_030508a0 + 1,auStack_28);
          memcpy_bytes_iram(&local_10,auStack_15,3);
          channel_select_commit_and_notify
                    (uStack_12,local_10,p_text_entry_buffer,*(undefined1 *)PTR_DAT_0305088c,
                     p_dm32_settings_block04[0x54]);
        }
      }
    }
    else if (cVar1 == '\x03') {
      if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_030508a8 + 2) == '\0') {
        if (*(char *)((uint)p_menu_screen_state->index_0x5 + DAT_030508ac + 2) == '\x01') {
          memcpy_bytes_iram(DAT_030508b0,DAT_030508b4,3);
          if ((byte)p_active_screen_index_list[*(byte *)p_active_screen_state_word + 2] < 6) {
                    /* WARNING: Could not recover jumptable at 0x0305087a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)(PTR_PTR_030508bc
                       [(byte)p_active_screen_index_list[*(byte *)p_active_screen_state_word + 2]] &
                      0xfffffffe))();
            return;
          }
          if ((p_vfo_display_state->flags_0x8 & 8) == 0) {
            dialog_request_enqueue(unaff_r4,(void *)*PTR_DAT_03050c1c);
          }
          else {
            format_and_write_status_field2
                      (**(undefined4 **)
                         (PTR_PTR_03050c18 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
          }
          write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03050c20 + DAT_03050c24),0);
        }
        else {
          write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03050c20 + DAT_03050c24),0);
        }
      }
      else {
        write_status_mode_byte_pair(0x31,1);
      }
    }
    else {
      write_status_mode_byte_pair(0x31,1);
    }
  }
  else {
    write_status_mode_byte_pair(0x31,1);
  }
  return;
}

