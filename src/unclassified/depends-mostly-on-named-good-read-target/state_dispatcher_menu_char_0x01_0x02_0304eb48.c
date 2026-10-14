/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: state_dispatcher_menu_char_0x01_0x02 @ 0304eb48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 308 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void state_dispatcher_menu_char_0x01_0x02(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 auStack_c [4];
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_0304ec84 + 2);
  if (cVar1 == '\x01') {
    SUBPIECE_SET(uVar2, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
    SUBPIECE_SET(uVar2, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
    iVar4 = vfo_freq_display_index_from_offset(*(undefined1 *)PTR_DAT_0304ec88,uVar2);
    *(short *)PTR_DAT_0304ec90 = (short)iVar4;
    if ((iVar4 == 0) && (p_vfo_freq_display_state->field_0x1 <= *(byte *)p_active_screen_state_word)
       ) {
      dialog_show_icon_and_two_numbers
                (0x30,0x30,PTR_DAT_0304eca8,
                 PTR_PTR_0304eca0[(byte)p_dm32_settings_block04[0x30] >> 6 & 1],PTR_LAB_0304eca4);
      OSTimeDly_ms_wrapper(1000);
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304ecac + DAT_0304ecb0),3);
    }
    else {
      write_status_mode_byte_pair(0x2a,1);
    }
  }
  else if ((cVar1 == '\x02') && (*(char *)PTR_active_screen_subtype_0304ecb4 == '\n')) {
    if (*(char *)PTR_DAT_0304ecb8 == '\x03') {
      p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xdf;
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_c);
      *(undefined1 *)PTR_DAT_0304ecc0 = 0xf0;
      if (*(char *)p_text_entry_buffer == '\0') {
        dialog_show_icon_and_number
                  (0,**(undefined4 **)
                       (PTR_PTR_0304ecc8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      else {
        iVar4 = flash_record_11byte_exists_check_bank1(p_text_entry_buffer);
        puVar3 = p_text_entry_buffer;
        if (iVar4 == 0) {
          flash_block_write(0x11,(*(byte *)PTR_DAT_0304ec88 - 1) * 0x39 + 1,p_text_entry_buffer,0xb)
          ;
          memcpy_bytes_iram(DAT_0304ecd0,puVar3,0xb);
          dialog_show_icon_and_number_from_ptr();
        }
        else {
          dialog_show_icon_and_number
                    (0,PTR_PTR_0304eccc[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
        }
      }
    }
    else {
      scan_state_tick();
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304ecac + DAT_0304ecb0),0);
    }
  }
  return;
}

