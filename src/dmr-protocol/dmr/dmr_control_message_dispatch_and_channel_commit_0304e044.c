/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_control_message_dispatch_and_channel_commit @ 0304e044 (file base 0x03000000; code starts at 0x03001000)
 * Size: 156 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_control_message_dispatch_and_channel_commit(void)

{
  int iVar1;
  
  if (*(char *)PTR_active_screen_subtype_0304e0cc == '\n') {
    if (*(char *)PTR_DAT_0304e0d0 == '\x03') {
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x0000002c);
      p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xdf;
      *(undefined1 *)PTR_DAT_0304e0d8 = 0xf0;
      if (*(char *)p_text_entry_buffer == '\0') {
        dialog_show_icon_and_number
                  (0,**(undefined4 **)
                       (PTR_PTR_0304e0e0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      else {
        iVar1 = channel_name_exists(p_text_entry_buffer);
        if (iVar1 == 0) {
          channel_record_commit();
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

