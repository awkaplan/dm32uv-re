/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zone_confirm_menu_handler @ 0303ab50 (file base 0x03000000; code starts at 0x03001000)
 * Size: 914 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void zone_confirm_menu_handler(void)

{
  char cVar1;
  byte bVar2;
  dialog_history_ui_state *pdVar3;
  dialog_history_ui_state *pdVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte abStack_10 [4];
  
  pdVar4 = p_dialog_history_ui_state;
  pdVar3 = p_dialog_history_ui_state;
  if ((*(byte *)PTR_DAT_0303ac18 & 2) == 0) {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x1 + DAT_0303ade8 + 2);
    if (cVar1 == '\x02') {
      uVar6 = get_zone_count();
      flash_field_read_cached(4,0x500,abStack_10,1);
      if ((*(byte *)p_active_screen_state_word == uVar6) && ((abStack_10[0] & 2) == 0)) {
        ui_event_notify(0x1b);
        write_status_mode_byte_pair
                  (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_0303adec),0);
        return;
      }
      *_LAB_0303af30 = *(byte *)p_active_screen_state_word;
      write_status_mode_byte_pair(0x15,1);
      return;
    }
    if (cVar1 == '\a') {
      if (*_p_active_screen_state_word != 0) {
        write_status_mode_byte_pair(0x15,1);
        return;
      }
      if (*(char *)(_LAB_0303af38 + 5) != '\0') {
        if ((p_vfo_display_state->flags_0x8 & 8) != 0) {
          dialog_show_icon_and_number
                    (3,**(undefined4 **)
                         (_LAB_0303af44 + (*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1) * 8)
                    );
          return;
        }
        write_status_mode_byte_pair(0,1);
        *_LAB_0303af48 = 1;
        return;
      }
      dialog_show_icon_and_number
                (3,**(undefined4 **)
                     (_LAB_0303af4c + (*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1) * 8));
      return;
    }
    if (cVar1 != '\0') {
      if (*_LAB_0303af64 == '\x05') {
        write_status_mode_byte_pair
                  (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + _LAB_0303af60),0);
        return;
      }
      write_status_mode_byte_pair(0x15,1);
      return;
    }
    if (*(char *)(_p_active_screen_index_list + (uint)*_p_active_screen_state_word + 2) == '\x03') {
      iVar7 = flash_read_4byte_mutex_guarded();
      *_LAB_0303af54 = iVar7;
      if (49999 < iVar7 - 1U) {
        display_draw_dialog_panel();
        iVar5 = _LAB_0303af58;
        iVar7 = _p_dm32_settings_block04;
        display_draw_number_centered
                  (0x90,0,0xc618,
                   **(uint **)(_LAB_0303af58 +
                              (*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1) * 8));
        display_draw_number_centered
                  (0xae,0,0xc618,
                   *(uint *)(*(int *)(iVar5 + (*(byte *)(iVar7 + 0x30) >> 6 & 1) * 8) + 4));
        OSTimeDly_ms_wrapper(1000);
        write_status_mode_byte_pair
                  (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + _LAB_0303af60),3);
        return;
      }
      write_status_mode_byte_pair(0x15,1);
      return;
    }
    write_status_mode_byte_pair(0x15,1);
    return;
  }
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x1 + DAT_0303ac1c + 2);
  if (cVar1 == '\0') {
    if (*(char *)p_active_screen_state_word == '\0') {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xf7 | 8;
    }
    else if (*(char *)p_active_screen_state_word == '\x01') {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xf7;
    }
    goto LAB_0303ad7a;
  }
  if (cVar1 == '\x01') {
    cVar1 = p_active_screen_index_list[*(byte *)p_active_screen_state_word + 2];
    if (cVar1 == '\0') {
      p_dialog_history_ui_state->field_0xa09 = 0xf;
      pdVar3->field_0xa08 = 1;
      *(undefined1 *)PTR_DAT_0303ac24 = 1;
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xe7 | 0x18;
    }
    else if (cVar1 == '\x03') {
      p_dialog_history_ui_state->field_0xa09 = 0x1a;
      pdVar3->field_0xa08 = 4;
      *(undefined1 *)PTR_DAT_0303ac24 = 4;
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xe7 | 0x18;
    }
    else {
      if (cVar1 == '\x04') {
LAB_0303ad7a:
        write_status_mode_byte_pair(0x15,1);
        return;
      }
      if (cVar1 == '\x05') {
        p_dialog_history_ui_state->field_0xa09 = 0x2a;
        pdVar4->field_0xa08 = 7;
        *(undefined1 *)PTR_DAT_0303add8 = 7;
      }
      else {
        if (cVar1 != '\x06') goto LAB_0303ad7a;
        p_dialog_history_ui_state->field_0xa09 = 0x21;
        pdVar4->field_0xa08 = 6;
        *(undefined1 *)PTR_DAT_0303add8 = 6;
      }
    }
  }
  else if (cVar1 == '\x02') {
    bVar2 = *(byte *)p_active_screen_state_word;
    p_dialog_history_ui_state->field_0xa09 = bVar2 + 0x35;
    pdVar4->field_0xa08 = bVar2 / 5 + 9;
    if (bVar2 < 10) {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xe7 | 0x18;
    }
    else {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xe7;
    }
  }
  else {
    if (cVar1 != '\x03') goto LAB_0303ad7a;
    bVar2 = *(byte *)p_active_screen_state_word;
    if (bVar2 == 0) {
      p_dialog_history_ui_state->field_0xa09 = 0x4a;
      pdVar4->field_0xa08 = 0xd;
    }
    else if (bVar2 == 1) {
      p_dialog_history_ui_state->field_0xa09 = 0x30;
      pdVar4->field_0xa08 = 0xf;
      *(undefined1 *)PTR_DAT_0303add8 = 10;
    }
    else if (bVar2 == 8) {
      p_dialog_history_ui_state->field_0xa09 = 0x4f;
      pdVar4->field_0xa08 = 0x11;
      *(undefined1 *)PTR_DAT_0303add8 = 0xb;
    }
    else if (bVar2 == 9) {
      p_dialog_history_ui_state->field_0xa09 = 0x50;
      pdVar4->field_0xa08 = 0x11;
      *(undefined1 *)PTR_DAT_0303add8 = 0xb;
    }
    else if ((byte)(bVar2 - 2) < 6) {
      if (bVar2 < 5) {
        p_dialog_history_ui_state->field_0xa09 = bVar2 + 0x4a;
        p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xf7;
      }
      else {
        p_dialog_history_ui_state->field_0xa09 = bVar2 + 0x47;
        p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xf7 | 8;
      }
      p_dialog_history_ui_state->field_0xa08 = 0xf;
      *(undefined1 *)PTR_DAT_0303add8 = 0xb;
    }
    else if (bVar2 == 10) {
      p_dialog_history_ui_state->field_0xa08 = 0x12;
      pdVar4->field_0xa09 = 0x51;
    }
    else {
      if (bVar2 != 0xb) goto LAB_0303ad7a;
      p_dialog_history_ui_state->field_0xa09 = 0x4b;
      pdVar4->field_0xa08 = 0x13;
    }
  }
  write_status_mode_byte_pair(0x62,1);
  return;
}

