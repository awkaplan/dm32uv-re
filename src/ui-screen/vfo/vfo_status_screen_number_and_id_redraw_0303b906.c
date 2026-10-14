/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_status_screen_number_and_id_redraw @ 0303b906 (file base 0x03000000; code starts at 0x03001000)
 * Size: 794 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_status_screen_number_and_id_redraw(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  short sVar6;
  uint uVar7;
  
  if ((*PTR_DAT_0303ba80 & 0x18000) == 0x8000) {
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      cVar5 = -0x4f;
    }
    else {
      cVar5 = ';';
    }
    if (p_dm32_settings_block04[0x6c] == '\0') {
      cVar5 = 'Y';
    }
    bVar4 = false;
    display_fill_rect(10,(ushort)(byte)(cVar5 + 0x2d),0xe3,(byte)(cVar5 + 0x2d) + 0x1b,0);
  }
  else if ((p_radio_mode_state_0003e318->flags_0x6 & 0xc) == 0) {
    display_clear_body_and_underline();
    bVar4 = true;
  }
  else {
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      sVar6 = 0x3b;
    }
    else {
      sVar6 = 0xb1;
    }
    if (p_dm32_settings_block04[0x6c] == '\0') {
      bVar4 = false;
      display_fill_rect(8,0x59,0xeb,0x74,0);
    }
    else {
      bVar4 = false;
      display_fill_rect(8,sVar6 + -5,0xeb,sVar6 + 0x23,0);
    }
  }
  display_format_id_with_separators();
  bVar1 = p_radio_mode_state_0003e318->flags_0x4;
  if ((bVar1 & 0x10) == 0) {
    if ((bVar1 & 0x60) != 0) {
      uVar7 = p_radio_mode_state_0003e318->flags_0x4 >> 5 & 3;
      if (uVar7 < 3) {
        display_draw_number_centered
                  (1,0xffff,0,
                   *(uint *)(PTR_PTR_0303ba90[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                            (uVar7 - 1) * 4));
        bVar3 = true;
      }
      else {
        display_draw_number_centered
                  (1,0xffff,0,
                   *(uint *)(PTR_PTR_0303ba8c[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                            0x50));
        bVar3 = true;
      }
      goto LAB_0303bbec;
    }
    if ((bVar1 & 0x80) != 0) {
      display_draw_number_centered
                (1,0xffff,0,
                 *(uint *)(PTR_PTR_0303ba8c[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                          0x1c));
      bVar3 = true;
      goto LAB_0303bbec;
    }
    bVar1 = p_radio_mode_state_0003e318->flags_0x5;
    if ((bVar1 & 4) != 0) {
      display_draw_number_centered
                (1,0xffff,0,
                 *(uint *)(PTR_PTR_0303bc18[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] +
                          (p_radio_mode_state_0003e318->flags_0x3 >> 2 & 1) * 4));
      bVar3 = true;
      goto LAB_0303bbec;
    }
    if ((bVar1 & 0x10) != 0) {
      display_draw_number_centered
                (1,0xffff,0,
                 *(uint *)(PTR_PTR_0303bc1c[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 8)
                );
      bVar3 = true;
      goto LAB_0303bbec;
    }
    bVar2 = p_radio_mode_state_0003e318->flags_0x6;
    if ((bVar2 & 4) == 0) {
      if ((bVar2 & 8) == 0) {
        if ((bVar2 & 0x40) == 0) {
          if ((bVar1 & 0x80) == 0) {
            if ((bVar1 & 0x40) == 0) goto LAB_0303c85c;
            if (*(char *)((uint)p_menu_screen_state->index_0x1 + DAT_0303bc2c + 2) == '\0') {
              bVar3 = false;
              display_fill_rect(0,0x122,0xf0,0x140,0);
              display_draw_gb2312_label_bottom_by_config_bit(0);
              if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
                display_draw_gb2312_label_top_alt(0);
              }
              else {
                bVar3 = false;
              }
            }
            else {
              bVar3 = true;
            }
            display_draw_number_centered
                      (1,0xffff,0,
                       *(uint *)(PTR_PTR_0303bc18[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] +
                                (p_radio_mode_state_0003e318->flags_0x3 >> 2 & 1) * 4));
            scan_channel_icon_draw(1);
          }
          else {
            display_draw_number_centered
                      (1,0xffff,0,
                       *(uint *)(PTR_PTR_0303bc24
                                 [((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 4));
            scan_channel_icon_draw(1);
            bVar3 = true;
          }
        }
        else {
          display_draw_number_centered
                    (1,0xffff,0,PTR_PTR_0303bc20[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
          bVar3 = true;
        }
        goto LAB_0303bbec;
      }
      bVar4 = false;
    }
LAB_0303c85c:
    bVar3 = true;
  }
  else {
    display_draw_number_centered
              (1,0xffff,0,
               *(uint *)(PTR_PTR_0303ba8c[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 0x18
                        ));
    bVar3 = true;
LAB_0303bbec:
    if ((p_radio_mode_state_0003e318->flags_0x5 & 0x10) != 0) {
      display_fill_rect(0,0x122,0xf0,0x140,0);
      goto LAB_0303c7fe;
    }
  }
  if ((((p_radio_mode_state_0003e318->flags_0x6 & 0xc) == 0) &&
      ((*PTR_DAT_0303bdd4 & 0x18000) != 0x8000)) && (bVar3)) {
    dialog_header_draw_two_lines();
  }
LAB_0303c7fe:
  cVar5 = *(char *)PTR_active_screen_subtype_0303c950;
  if ((((cVar5 != '\b') && (cVar5 != '\x05')) &&
      ((cVar5 != '\x06' && ((cVar5 != '\x04' && (cVar5 != '\x18')))))) &&
     ((cVar5 != '\x03' &&
      (((((cVar5 != '\n' && (cVar5 != '\x17')) && (cVar5 != '%')) && (cVar5 != '/')) &&
       ((cVar5 != '\x16' || (*(char *)PTR_DAT_0303c954 != '\x01')))))))) {
    signal_level_bargraph_mode_select();
  }
  if (bVar4) {
    ucos_tmr_del(p_ucos_tmr_inputcursor,&stack0x00000020);
  }
  else {
    OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x00000020);
  }
  return;
}

