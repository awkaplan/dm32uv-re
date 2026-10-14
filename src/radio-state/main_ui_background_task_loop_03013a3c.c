/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: main_ui_background_task_loop @ 03013a3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 1184 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void main_ui_background_task_loop(void)

{
  short sVar1;
  undefined4 *puVar2;
  radio_mode_state_0003e318 *prVar3;
  void *flaggrp;
  int iVar4;
  undefined1 *puVar5;
  vfo_display_state *pvVar6;
  int iVar7;
  undefined2 *puVar8;
  int iVar9;
  byte bVar10;
  undefined1 auStack_28 [4];
  
  iVar7 = _DAT_03013bf0;
  pvVar6 = p_vfo_display_state;
  puVar5 = PTR_DAT_03013be8;
  iVar4 = _DAT_03013be4;
  flaggrp = _p_ucos_flaggrp_0003fd90;
  prVar3 = p_radio_mode_state_0003e318;
  puVar2 = PTR_DAT_03013bcc;
  do {
    OSFlagPend_wrapper_consume(flaggrp,1,0,0,auStack_28);
    OSFlagPost_wrapper_clr(flaggrp,1);
    if ((prVar3[1].flags_0x7 & 0x20) != 0) {
      rf_agc_step_adaptive_control_loop(*(byte *)(iVar4 + 1) & 1);
    }
    if (*puVar5 != '\0') {
      *puVar5 = *puVar5 + -1;
    }
    if ((pvVar6->flags_0x8 & 0xf0) == 0) {
      if ((prVar3[2].flags_0x2 & 4) != 0) {
        if (*(byte *)(iVar7 + 0x25) < 100) {
          *(byte *)(iVar7 + 0x25) = *(byte *)(iVar7 + 0x25) + 1;
        }
        else {
          if ((*(byte *)((int)puVar2 + 3) & 2) == 0) {
            prVar3[2].flags_0x2 = prVar3[2].flags_0x2 & 0xfd | 2;
            bVar10 = pvVar6->field_0x16 & 0xe;
            if (bVar10 == 2) {
              iVar9 = flash_block6_pattern_match_mode_entry();
              if (iVar9 != 0) {
                boot_mode_select_persist_and_reset();
              }
            }
            else if (bVar10 == 6) {
              flash_pending_action_scan_and_apply();
            }
            *(undefined1 *)PTR_DAT_03013bf4 = 0;
            *(undefined1 *)(iVar7 + 0x25) = 0;
            prVar3[2].flags_0x2 = prVar3[2].flags_0x2 & 0xfd;
            memset_ck803s(_DAT_03013bf8,0xff,0x18);
            fd6818b_reg_write(FD6818_PAGE0_REG_3FH,0);
            fd6818b_reg_write(FD6818_PAGE0_REG_3FH,*(undefined2 *)PTR_DAT_03013bfc);
          }
          prVar3[2].flags_0x2 = prVar3[2].flags_0x2 & 0xfb;
        }
      }
      if ((prVar3[2].field_0x1 & 0x40) != 0) {
        if ((*(byte *)((int)puVar2 + 3) & 2) == 0) {
          menu_highlight_position_update(0,0);
          if (*_LAB_03013c00 != 'F') {
            ring_buffer_multi_table_append_and_flush();
          }
          write_status_mode_byte_pair(0x46,0);
          channel_info_screen_refresh();
        }
        prVar3[2].field_0x1 = prVar3[2].field_0x1 & 0xbf;
      }
      if ((pvVar6->field_0x16 & 0xe) == 4) {
        favorite_channel_scan_confirm_and_switch();
      }
    }
    FUN_030300e8();
    if ((*_LAB_03013c04 == '/') && ((*(byte *)((int)puVar2 + 3) & 0x80) != 0)) {
      tone_signaling_scroll_and_display_update();
    }
    bVar10 = *(byte *)((int)puVar2 + 3);
    if (((bVar10 & 2) != 0) && (*_LAB_03013c08 != '\0')) {
      if ((bVar10 & 8) == 0) {
        iVar9 = fd6818b_status_register_poll_with_reinit();
        if (iVar9 == 0) {
          rf_frequency_adjust_and_display_refresh();
        }
LAB_03013c2a:
        bVar10 = *(byte *)((int)puVar2 + 3);
        if ((bVar10 & 8) == 0) goto LAB_03013ce4;
      }
      else if (((bVar10 & 4) == 0) && (*puVar5 == '\0')) {
        iVar9 = fd6818_pa_status_fault_check();
        if (iVar9 != 0) {
          channel_squelch_tone_scan_and_apply();
        }
        goto LAB_03013c2a;
      }
      if ((bVar10 & 4) == 0) {
        if (((*(byte *)puVar2 & 0x20) != 0) &&
           (bVar10 = *_LAB_03013dd8, *_LAB_03013dd8 = bVar10 + 1, 100 < (byte)(bVar10 + 1))) {
          *_LAB_03013dd8 = 0;
          *(byte *)((int)puVar2 + 3) = *(byte *)((int)puVar2 + 3) & 0xfb | 4;
          pvVar6->field_0x11_0 = 0xff;
          pvVar6->field_0x12 = 0xff;
          display_fill_rect(10,0x82,0xf0,0x9a,0);
          display_draw_number_centered(0x82,0xffff,0,_LAB_03013ddc);
          display_draw_number_centered
                    (0xa0,0xffff,0,
                     *(uint *)(_LAB_03013de4 + (*(byte *)(_LAB_03013de0 + 0x30) >> 6 & 1) * 4));
        }
        bVar10 = *_LAB_03013de8;
        *_LAB_03013de8 = bVar10 + 1;
        if (200 < (byte)(bVar10 + 1)) {
          menu_highlight_position_update(0,0);
          draw_dialog_header_and_centered_number();
          *(byte *)((int)puVar2 + 3) = *(byte *)((int)puVar2 + 3) & 0xf3;
          *_LAB_03013de8 = 0;
          *_LAB_03013dec = 0;
          *_LAB_03013dd8 = 0;
        }
      }
    }
LAB_03013ce4:
    gps_nmea_rmc_gga_sentence_parser();
    if ((*(byte *)((int)puVar2 + 2) & 2) != 0) {
      rda5807m_seek_complete_poll();
    }
    keypad_event_maybe_forward_to_dialog();
    if (((*(char *)PTR_DAT_03013df0 != '\0') && ((*_p_call_active_flag & 0xc) == 0)) &&
       (sVar1 = PTR_DAT_03013df0[1], PTR_DAT_03013df0[1] = sVar1 + 1U, puVar8 = PTR_DAT_03013df0,
       *(ushort *)(_LAB_03013df8 + 0x20) <= (ushort)(sVar1 + 1U))) {
      PTR_DAT_03013df0[1] = 0;
      *(undefined1 *)puVar8 = 0;
      *(undefined1 *)((int)puVar8 + 1) = 0;
      *(byte *)(_LAB_03013dfc + 3) = *(byte *)(_LAB_03013dfc + 3) & 0xbf;
      display_refresh_tone_mode_icon();
    }
    if ((((*(byte *)(_LAB_03013dfc + 3) & 0x41) == 1) &&
        (iVar9 = read_byte_field_0302e118(), iVar9 == 0)) &&
       ((*(byte *)((int)puVar2 + 3) & 0x82) == 0)) {
      idle_background_notify_counter();
    }
    call_setup_debounce_and_ui_state_driver();
    call_display_countdown_and_ui_event_trigger();
    FUN_03060280();
    ui_inactivity_timeout_tick();
    if ((*(byte *)puVar2 & 0x40) == 0) {
      if (((*(byte *)puVar2 & 2) == 0) && ((*(byte *)(_LAB_03013f50 + 8) & 1) == 0)) {
        ui_mode_periodic_state_tick();
        iVar9 = read_byte_field_0302e118();
        if (((iVar9 == 0) &&
            (((*(byte *)((int)puVar2 + 1) & 0x82) == 0 &&
             (p_vfo_freq_display_state->field_0x12 == 0)))) &&
           ((((*_LAB_03013f58 == 0 || ((0x3f < *_LAB_03013f58 && (*_LAB_03013f58 < 0x5b)))) &&
             ((((*(byte *)(_LAB_03013f5c + 0x31) & 3) != 0 || *(char *)(_LAB_03013f5c + 0x30) < '\0'
               && (((((prVar3->flags_0x7 & 2) == 0 && ((*_p_call_active_flag & 10) == 0)) &&
                    (iVar9 = keypad_dispatch_not_inhibited(), iVar9 != 0)) &&
                   (((*(byte *)(_DAT_03013f64 + 0x2b) & 8) == 0 &&
                    (iVar9 = call_state_not_idle_check(), iVar9 == 0)))))) &&
              (iVar9 = get_field_0301ea64_0x14(), iVar9 == 0)))) &&
            ((((*_p_call_active_flag & 4) == 0 && (prVar3[1].flags_0x2 == 0)) &&
             (((*_DAT_03013f68 & 4) == 0 && ((*(byte *)((int)puVar2 + 3) & 2) == 0)))))))) {
          rf_mode_debounce_state_machine();
        }
        if ((((*(char *)(_DAT_03013f6c + 1) == '\0') &&
             (iVar9 = get_current_mode_state2(), iVar9 != 0)) && ((*_p_call_active_flag & 10) == 0))
           && (bVar10 = *(char *)(iVar7 + 0x1c) + 1, *(byte *)(iVar7 + 0x1c) = bVar10, 4 < bVar10))
        {
          *(undefined1 *)(iVar7 + 0x1c) = 0;
          if ((((p_dialog_flags_from_flash->flags_0x1 & 3) == 0) &&
              (iVar9 = keypad_dispatch_not_inhibited(), iVar9 != 0)) &&
             (iVar9 = get_current_mode_state1(), iVar9 == 0)) {
            key_hold_debounce_state_dispatcher();
          }
        }
      }
    }
    else if ((*(byte *)((int)puVar2 + 1) & 0x10) == 0) {
      OSTmr_state_dispatch_callback(_p_ucos_tmr_inputcursor,0,0,auStack_28);
      display_fill_screen(0);
      display_blit_bitmap_1bpp(100,0x6e,0x20,0x78,_DAT_03013e04,0xffff);
      display_draw_number_centered
                (0xa0,0xffff,0,
                 **(uint **)(_LAB_03013e08 + (*(byte *)(_LAB_03013de0 + 0x30) >> 6 & 1) * 4));
      *(byte *)((int)puVar2 + 1) = *(byte *)((int)puVar2 + 1) & 0xef | 0x10;
    }
    ui_background_periodic_subtask_dispatcher();
    call_duration_accumulator_tick();
    ui_tick_prescaler_post();
  } while( true );
}

