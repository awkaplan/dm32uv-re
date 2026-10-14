/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_contact_view_or_apply_option_init_030439cc @ 030439cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 286 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_contact_view_or_apply_option_init_030439cc(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_10 [4];
  
  puVar2 = PTR_PTR_03043afc;
  if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03043af4 + 2) == '\0') {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03043afc + uVar5 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar2[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03043b08 = *(undefined1 *)((int)puVar2 + uVar5 * 8 + 5)
    ;
    iVar4 = DAT_03043b14;
    if (*(char *)PTR_DAT_03043b0c == '\x01') {
      flash_talker_record_read(*PTR_DAT_03043b10 + 1,DAT_03043b14);
      iVar3 = p_list_row_text_buffer;
      memcpy_bytes_iram(p_list_row_text_buffer,iVar4 + 0x14,8);
      *(undefined1 *)(iVar3 + 8) = 0;
      build_sequential_index_list
                ((ushort)*(byte *)p_active_screen_option_count,p_active_screen_index_list,
                 (byte *)(p_active_screen_index_list + 1));
    }
  }
  else {
    iVar4 = flash_binary_search_le_record(*p_text_entry_current_char_alias,0);
    if ((p_radio_mode_state_0003e318->flags_0x6 & 1) == 0) {
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_10);
      display_draw_dialog_panel();
      puVar2 = PTR_PTR_03043b2c;
      puVar1 = p_dm32_settings_block04;
      if (iVar4 == 0) {
        display_draw_number_centered
                  (100,0,0xc618,
                   *(uint *)PTR_PTR_03043b2c[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2]);
        display_draw_number_centered
                  (0x82,0,0xc618,*(uint *)(puVar2[((byte)puVar1[0x30] >> 6 & 1) * 2] + 4));
      }
      else {
        display_draw_number_centered
                  (0x82,0,0xc618,PTR_PTR_03043b30[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
      }
      OSTimeDly_ms_wrapper(1000);
      history_queue_pop();
    }
    else {
      if (*(char *)PTR_DAT_03043b0c == '\x01') {
        *PTR_DAT_03043b10 = iVar4 + -1;
        *PTR_DAT_03043b34 = iVar4;
      }
      screen_option_template_load_id_generic();
    }
  }
  return;
}

