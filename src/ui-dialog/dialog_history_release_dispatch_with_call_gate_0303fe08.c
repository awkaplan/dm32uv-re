/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_history_release_dispatch_with_call_gate @ 0303fe08 (file base 0x03000000; code starts at 0x03001000)
 * Size: 542 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_history_release_dispatch_with_call_gate(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  dialog_history_ui_state *pdVar3;
  undefined *puVar4;
  int iVar5;
  char cVar6;
  uint uVar7;
  int unaff_r4;
  byte bVar8;
  
  if (((p_dialog_flags_from_flash->flags_0x1 & 3) == 0) && (p_tx_ptt_ui_state->field_0x7 != 4)) {
    if (p_tx_ptt_ui_state->field_0x7 != 5) {
      cVar6 = PTR_DAT_0303ff5c[1];
      if (cVar6 == '\0') {
        if (p_dialog_history_ui_state->field_0x3 == 0x5b) {
          bVar8 = 0;
        }
        else if ((*(byte *)p_call_active_flag & 8) == 0) {
          iVar5 = get_current_mode_state1();
          if ((iVar5 == 0) ||
             (iVar5 = get_current_mode_state1(), puVar1 = PTR_DAT_0303ff68, iVar5 == 2)) {
            if (p_dialog_history_ui_state->field_0x3 == 0x4d) {
              iVar5 = get_current_mode_state2();
              if (iVar5 == 0) {
                bVar8 = 0;
              }
              else {
                bVar8 = p_radio_mode_state_0003e318[1].flags_0x6 >> 2 & 1;
                if ((PTR_DAT_0303ff70[1] & 1) != bVar8) {
                  PTR_DAT_0303ff70[1] = PTR_DAT_0303ff70[1] & 0xfe | bVar8;
                  vfo_apply_active_side_config();
                }
                set_flag_byte_03064328(4);
                puVar2 = PTR_DAT_0303ff74;
                PTR_DAT_0303ff74[0x1d] = 0;
                puVar2[0x1c] = 0;
                bVar8 = 0;
              }
            }
            else {
              iVar5 = get_current_mode_state2();
              if (iVar5 == 0) {
                bVar8 = 0;
              }
              else {
                iVar5 = get_current_mode_state2();
                puVar1 = PTR_DAT_0303ff68;
                if (iVar5 == 4) {
                  bVar8 = 0;
                }
                else if ((PTR_DAT_0303ff78[3] & 2) == 0) {
                  *(byte *)PTR_DAT_0303ff68 = *(byte *)PTR_DAT_0303ff68 & 0xfb | 4;
                  vfo_exit_dual_watch_and_refresh();
                  bVar8 = 0;
                  *(byte *)puVar1 = *(byte *)puVar1 & 0xfb;
                }
                else {
                  bVar8 = 0;
                }
              }
            }
          }
          else {
            bVar8 = ~(unaff_r4 != 5);
            *(byte *)PTR_DAT_0303ff68 = *(byte *)PTR_DAT_0303ff68 & 0xfb | 4;
            dtmf_digit2_input_and_clear_flag(2);
            *(byte *)puVar1 = *(byte *)puVar1 & 0xfb;
          }
        }
        else {
          bVar8 = 1;
        }
        if (p_dialog_history_ui_state->field_0x3 != 0x70) {
          cVar6 = *(char *)PTR_active_screen_subtype_0303ff7c;
          if (cVar6 == '\b') {
            if ((p_radio_mode_state_0003e318->flags_0x6 & 4) == 0) {
              tx_gate_write_call_record(1);
            }
          }
          else if (cVar6 == '\x12') {
            tx_gate_write_call_record(0);
          }
          else if (cVar6 == '\"') {
            tx_gate_write_call_record(0);
          }
          else if (cVar6 == '\x16') {
            tx_gate_write_call_record(0);
          }
          else if (p_dialog_history_ui_state->index_0x2 < 2) {
            if ((*(byte *)p_call_active_flag & 8) == 0) {
              tx_gate_write_call_record(1);
            }
          }
          else if (bVar8 == 0) {
            tx_gate_write_call_record(1);
          }
        }
        cVar6 = PTR_DAT_03040138[1];
        if (cVar6 != '\0') goto LAB_0303ffcc;
        if ((unaff_r4 == 5) &&
           ((((byte)(p_tx_ptt_ui_state->field_0x9 - 2) < 2 ||
             (iVar5 = get_current_mode_state1(), iVar5 == 2)) &&
            (p_dialog_history_ui_state->field_0x3 == 0x5b)))) {
          reentrant_state_reset_sequence();
        }
LAB_0303fffc:
        puVar4 = PTR_s_66660501_03040140;
        pdVar3 = p_dialog_history_ui_state;
        p_dialog_history_ui_state->field_0x3 =
             PTR_s_66660501_03040140[(uint)p_dialog_history_ui_state->field_0x3 * 0xc + 0x11];
        uVar7 = *(uint *)(puVar4 + (uint)pdVar3->field_0x3 * 0xc + 0x14);
        *PTR_DAT_03040144 = uVar7;
        (*(code *)(uVar7 & 0xfffffffe))();
      }
      else {
LAB_0303ffcc:
        if (unaff_r4 == 0x18) goto LAB_0303fffc;
        if (cVar6 != '\x03') {
          if (p_dialog_history_ui_state->index_0x2 == 1) {
            tx_gate_write_call_record(1);
          }
          menu_mode_transition_and_field_redraw(2);
          write_status_mode_byte_pair
                    (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03040148),0);
        }
      }
      event_record_guarded_by_state_flags();
      if (p_dialog_history_ui_state->field_0x4 != 0) {
        history_entry_cancel_pending();
        pdVar3 = p_dialog_history_ui_state;
        uVar7 = PTR_PTR_03040818[(uint)p_dialog_history_ui_state->field_0x3 * 3];
        *PTR_DAT_0304081c = uVar7;
        (*(code *)(uVar7 & 0xfffffffe))();
        pdVar3->field_0x4 = 0;
      }
      goto LAB_03040700;
    }
    if (PTR_DAT_0303ff5c[1] != '\0') {
      cVar6 = PTR_DAT_03040b5c[1];
      goto LAB_0303ffcc;
    }
  }
  p_dialog_history_ui_state->field_0x4 = 0;
LAB_03040700:
  if (unaff_r4 == 0x18) {
    PTR_DAT_03040820[1] = 0;
  }
  os_sem_post(p_ucos_mutex_0003e4c0);
  return;
}

