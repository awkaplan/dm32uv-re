/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_confirm_and_write_setting @ 0304e168 (file base 0x03000000; code starts at 0x03001000)
 * Size: 164 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_confirm_and_write_setting(void)

{
  int iVar1;
  
  if (*(char *)PTR_active_screen_subtype_0304e278 == '\n') {
    if (*(char *)PTR_DAT_0304e27c == '\x03') {
      p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xdf;
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x0000002c);
      *(undefined1 *)PTR_DAT_0304e288 = 0xf0;
      if (*(char *)p_text_entry_buffer == '\0') {
        dialog_show_icon_and_number
                  (0,**(undefined4 **)
                       (PTR_PTR_0304e28c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      else {
        iVar1 = channel_name_exists(p_text_entry_buffer);
        if (iVar1 == 0) {
          channel_data_block_write_by_list_select
                    (p_dm32_settings_block04[0x26],(byte)p_dm32_settings_block04[0x2d] >> 7,
                     p_text_entry_buffer);
          dialog_show_icon_and_number_from_ptr();
        }
        else {
          dialog_show_icon_and_number
                    (0,PTR_PTR_0304e268[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
        }
      }
    }
    else {
      scan_state_tick();
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304e26c + DAT_0304e270),0);
    }
  }
  return;
}

