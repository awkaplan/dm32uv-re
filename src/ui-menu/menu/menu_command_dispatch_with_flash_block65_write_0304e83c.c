/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_command_dispatch_with_flash_block65_write @ 0304e83c (file base 0x03000000; code starts at 0x03001000)
 * Size: 402 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_command_dispatch_with_flash_block65_write(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [16];
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  
  uVar2 = read_byte_field_03065e34();
  if (*(byte *)PTR_DAT_0304e964 < uVar2) {
    cVar4 = *(char *)p_active_screen_state_word;
    if (cVar4 == '\0') {
      flash_field_write_and_readback_channel_data(*(byte *)PTR_DAT_0304e964 + 1 & 0xff);
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_0304e958 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
    else if (cVar4 == '\x01') {
      write_status_mode_byte_pair(0x23,1);
    }
    else if (cVar4 == '\x02') {
      bVar1 = *(byte *)PTR_DAT_0304eaf8;
      cVar4 = PTR_DAT_0304eafc[6] - bVar1;
      *(char *)PTR_DAT_0304eb00 = cVar4;
      if (bVar1 < 0x10) {
        if (cVar4 == '\0') {
          ui_event_notify(0x1b);
          dialog_show_icon_and_number
                    (0,**(undefined4 **)
                         (PTR_PTR_0304eb0c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        }
        else {
          write_status_mode_byte_pair(0x23,1);
        }
      }
      else {
        ui_event_notify(0x1b);
        dialog_show_icon_and_number
                  (0,**(undefined4 **)
                       (PTR_PTR_0304eb08 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
    }
    else {
      write_status_mode_byte_pair(0x23,1);
    }
  }
  else if (*(char *)PTR_active_screen_subtype_0304e968 == '\n') {
    if (*(char *)PTR_DAT_0304e96c == '\x03') {
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_24);
      *(undefined1 *)PTR_DAT_0304e974 = 0xf0;
      if (*(char *)p_text_entry_buffer == '\0') {
        dialog_show_icon_and_number
                  (0,**(undefined4 **)
                       (PTR_PTR_0304e97c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      else {
        iVar3 = flash_block65_string_lookup_exists(p_text_entry_buffer);
        if (iVar3 == 0) {
          memcpy_bytes_iram(auStack_20,p_text_entry_buffer,0x10);
          uStack_10 = 1;
          uStack_f = 1;
          uStack_e = 0;
          flash_block_write(0x65,uVar2 * 0x21 + 0x10 & 0xffff,auStack_20,0x13);
          flash_field_write_cached(0x65,0,uVar2 + 1 & 0xff);
          PTR_DAT_0304e984[7] = (char)(uVar2 + 1);
          dialog_show_icon_and_number
                    (1,**(undefined4 **)
                         (PTR_PTR_0304e988 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        }
        else {
          dialog_show_icon_and_number
                    (0,PTR_PTR_0304e980[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
        }
      }
    }
    else {
      scan_state_tick();
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304e95c + DAT_0304e960),0);
    }
  }
  return;
}

