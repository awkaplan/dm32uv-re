/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_apply_zone_handler @ 0304d34c (file base 0x03000000; code starts at 0x03001000)
 * Size: 422 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_confirm_apply_zone_handler(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [16];
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined2 uStack_1a;
  undefined1 auStack_18 [3];
  char cStack_15;
  
  uVar3 = get_zone_count();
  cStack_15 = (char)uVar3;
  if (*(byte *)PTR_DAT_0304d468 < uVar3) {
    cVar1 = *(char *)p_active_screen_state_word;
    if (cVar1 == '\0') {
      dtmf_digit_input_handler(0);
      settings_write_dispatcher(6,*(char *)PTR_DAT_0304d618 + '\x01');
      ui_event_notify_alt(9);
      history_queue_pop();
    }
    else if (cVar1 == '\x01') {
      write_status_mode_byte_pair(0x1c,1);
    }
    else if (cVar1 == '\x02') {
      bVar2 = *(byte *)PTR_DAT_0304d61c;
      sVar5 = *(short *)&p_radio_mode_state_0003e318[1].field_0x8 - (ushort)bVar2;
      *(short *)PTR_DAT_0304d624 = sVar5;
      if (bVar2 < 0x40) {
        if (sVar5 == 0) {
          ui_event_notify(0x1b);
          dialog_show_icon_and_number
                    (0,**(undefined4 **)
                         (PTR_PTR_0304d630 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        }
        else {
          write_status_mode_byte_pair(0x1c,1);
        }
      }
      else {
        ui_event_notify(0x1b);
        dialog_show_icon_and_number
                  (0,**(undefined4 **)
                       (PTR_PTR_0304d62c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
    }
    else {
      write_status_mode_byte_pair(0x1c,1);
    }
  }
  else if (*(char *)PTR_active_screen_subtype_0304d444 == '\n') {
    if (*(char *)PTR_DAT_0304d46c == '\x03') {
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_34);
      *(undefined1 *)PTR_DAT_0304d474 = 0xf0;
      if (*(char *)p_text_entry_buffer == '\0') {
        dialog_show_icon_and_number
                  (0,**(undefined4 **)
                       (PTR_PTR_0304d47c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      else {
        iVar4 = zone_name_exists_check(p_text_entry_buffer);
        if (iVar4 == 0) {
          channel_offset_minus_0x10(cStack_15 + '\x01',auStack_18,&uStack_1a);
          memcpy_bytes_iram(auStack_30,p_text_entry_buffer,0x10);
          uStack_20 = 1;
          uStack_1f = 1;
          uStack_1e = 0;
          flash_block_write(auStack_18[0],uStack_1a,auStack_30,0x13);
          cStack_15 = cStack_15 + '\x01';
          flash_block_write(0x5c,0,&cStack_15,1);
          dialog_show_icon_and_number
                    (1,**(undefined4 **)
                         (PTR_PTR_0304d484 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        }
        else {
          dialog_show_icon_and_number
                    (0,PTR_PTR_0304d480[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
        }
      }
    }
    else {
      scan_state_tick();
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304d60c + DAT_0304d610),0);
    }
  }
  return;
}

