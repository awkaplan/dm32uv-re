/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: field_edit_multikey_input_dispatch @ 03037718 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1502 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void field_edit_multikey_input_dispatch(char param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  dialog_history_ui_state *pdVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  char cVar11;
  uint uVar12;
  
  puVar2 = PTR_DAT_0303799c;
  bVar8 = *PTR_DAT_03037804;
  if ((bVar8 & 2) != 0) {
    if (((PTR_DAT_03037e9c[8] & 1) == 0) && ((bVar8 & 10) != 2)) {
      return;
    }
LAB_03037d24:
    if ((p_dialog_history_ui_state->field_0xa08 < 8) && (p_dialog_history_ui_state->field_0x3 == 0))
    {
      tx_gate_write_call_record(1);
      puVar2 = p_text_entry_buffer;
      pdVar4 = p_dialog_history_ui_state;
      bVar8 = p_dialog_history_ui_state->field_0xa08;
      p_text_entry_buffer[(uint)bVar8 * 2] = param_1 + '(';
      pdVar4->field_0xa08 = bVar8 + 1;
      display_draw_number_centered(100,0xffff,0,(uint)puVar2);
    }
    else {
      tx_gate_write_call_record(0);
    }
    return;
  }
  if ((PTR_DAT_03037810[8] & 1) != 0) goto LAB_03037d24;
  cVar11 = *(char *)PTR_active_screen_subtype_03037800;
  if (cVar11 != '\x04') {
    if (cVar11 == '\b') {
      if ((*PTR_DAT_03037b34 & 0x18000) == 0x8000) {
        write_byte_field_030596d0(8);
      }
      else if ((p_radio_mode_state_0003e318->flags_0x4 & 0x60) == 0) {
        if ((p_radio_mode_state_0003e318->flags_0x4 & 0x10) == 0) {
          if ((p_radio_mode_state_0003e318->flags_0x5 & 0x10) == 0) {
            if ((p_radio_mode_state_0003e318->flags_0x6 & 4) == 0) {
              write_byte_field_030596d0(8);
            }
            else {
              write_byte_field_030596d0(3);
            }
          }
          else {
            write_byte_field_030596d0(0x40);
          }
        }
        else {
          write_byte_field_030596d0(2);
        }
      }
      else {
        write_byte_field_030596d0(8);
      }
      if (((p_dialog_history_ui_state->field_0x3 == 0x70) &&
          ((p_radio_mode_state_0003e318->flags_0x5 & 0x10) == 0)) &&
         ((*(byte *)p_call_active_flag & 8) != 0)) {
        *(byte *)PTR_DAT_03037b44 = *(byte *)PTR_DAT_03037b44 & 0xfe;
        *(char *)PTR_DAT_03037b30 = param_1 + '(';
        write_status_mode_byte_pair(0x70,1);
      }
      else if (p_dialog_history_ui_state->field_0x3 != 0x5b) {
        if (*(byte *)PTR_DAT_03037cb8 < *(byte *)PTR_DAT_03037cbc) {
          if ((p_radio_mode_state_0003e318->flags_0x5 & 0x10) == 0) {
            if ((*PTR_DAT_03037cc4 & 0x18000) != 0x8000) {
              tx_gate_write_call_record(1);
            }
          }
          else {
            write_flag_and_notify_ui_event0x29(param_1 + -8);
          }
          text_input_append_byte_and_scroll(param_1 + '(');
          display_format_id_with_separators();
        }
        else {
          tx_gate_write_call_record(0);
        }
      }
    }
    else if (cVar11 == '\x18') {
      *(char *)PTR_DAT_03037cc8 = param_1 + '(';
      dtmf_quicktext_scroll_display_dispatch();
    }
    else if (cVar11 == '\n') {
      if (*(ushort *)PTR_DAT_03037cd0 < (ushort)*DAT_03037ccc) {
        if ((*(char *)PTR_DAT_03037cd4 == -0x10) || (1 < (byte)(*(char *)PTR_DAT_03037cd8 - 2U))) {
          tx_gate_write_call_record(0);
        }
        else {
          tx_gate_write_call_record(1);
        }
      }
      else {
        tx_gate_write_call_record(1);
      }
      scan_list_multikey_digit_dispatch(param_1 + -8);
    }
    else if ((*(byte *)p_call_active_flag & 8) == 0) {
      if ((p_dialog_history_ui_state->index_0x2 == 1) && (p_dialog_history_ui_state->field_0x3 == 0)
         ) {
        iVar6 = get_current_mode_state1();
        if (iVar6 == 0) {
          if ((*PTR_DAT_03037cc4 & 0x18000) == 0x8000) {
            if ((byte)(param_1 - 10U) < 4) {
              tx_gate_write_call_record(0);
            }
            else {
              init_field_pair_0x20_5();
              puVar3 = PTR_DAT_03037cc8;
              if ((byte)(param_1 - 8U) < 2) {
                *(char *)PTR_DAT_03037cc8 = param_1 + '(';
                *(undefined1 *)PTR_DAT_03037cb8 = 1;
              }
              else {
                *(undefined1 *)PTR_DAT_03037cc8 = 0x30;
                *(char *)((int)puVar3 + 1) = param_1 + '(';
                *(undefined1 *)PTR_DAT_03037cb8 = 2;
              }
              write_status_mode_byte_pair(0x77,1);
            }
          }
          else {
            init_field_pair_0x20_5();
            *(char *)PTR_DAT_03037e94 = param_1 + '(';
            *(undefined1 *)PTR_DAT_03037e98 = 1;
            tx_gate_write_call_record(1);
            write_status_mode_byte_pair(0x77,1);
          }
        }
      }
      else {
        tx_gate_write_call_record(0);
      }
    }
    else if (((PTR_DAT_03037ce0[1] & 2) != 0) || ((bVar8 & 0x80) != 0)) {
      if (p_dialog_history_ui_state->field_0x3 != 0x70) {
        memset_bytes(PTR_DAT_03037cc8,0,10);
      }
      *(char *)PTR_DAT_03037cc8 = param_1 + '(';
      write_status_mode_byte_pair(0x70,1);
    }
    goto LAB_03037d0a;
  }
  cVar11 = *(char *)PTR_DAT_03037814;
  if (cVar11 == '\x01') {
    bVar8 = param_1 - 8;
    cVar11 = *(char *)PTR_DAT_03037818;
    if (cVar11 == '\0') {
      if (2 < bVar8) {
        bVar8 = 2;
      }
      if ((bVar8 == 2) && (3 < *(byte *)((int)PTR_DAT_0303781c + 1))) {
        *(undefined1 *)((int)PTR_DAT_0303781c + 1) = 3;
      }
    }
    else if (cVar11 == '\x01') {
      if ((1 < *(byte *)PTR_DAT_0303781c) && (3 < bVar8)) {
        bVar8 = 3;
      }
    }
    else if (cVar11 == '\x02') {
      if (5 < bVar8) {
        bVar8 = 5;
      }
    }
    else if ((cVar11 == '\x04') && (5 < bVar8)) {
      bVar8 = 5;
    }
    *(byte *)((int)PTR_DAT_0303781c + (uint)*(byte *)PTR_DAT_03037818) = bVar8;
    menu_item_dispatch_cycle_sub_next();
    tx_gate_write_call_record(1);
    goto LAB_03037d0a;
  }
  if (cVar11 != '\x02') {
    if ((byte)(cVar11 + 0xaeU) < 2) {
      bVar9 = param_1 - 8;
      bVar8 = *(byte *)PTR_DAT_03037b2c;
      if ((bVar8 == 6) || (bVar8 == 0)) {
        *(undefined1 *)PTR_DAT_03037b2c = 6;
        puVar3 = PTR_DAT_03037b30;
        *(byte *)((int)PTR_DAT_03037b30 + 3) = bVar9;
        *(undefined1 *)((int)puVar3 + 2) = 0xff;
        *(undefined1 *)((int)puVar3 + 1) = 0xff;
        *(undefined1 *)puVar3 = 0xff;
      }
      else {
        bVar1 = *(byte *)((int)PTR_DAT_03037b30 + (uint)(bVar8 >> 1));
        if ((bVar8 & 1) == 0) {
          bVar9 = bVar9 | bVar1 & 0xf0;
        }
        else {
          bVar9 = bVar9 * '\x10' | bVar1 & 0xf;
        }
        *(byte *)((int)PTR_DAT_03037b30 + (uint)(bVar8 >> 1)) = bVar9;
      }
      *(char *)PTR_DAT_03037b2c = *(char *)PTR_DAT_03037b2c + -1;
      display_draw_hex_digits_6_with_separator(PTR_DAT_03037b30);
      tx_gate_write_call_record(1);
    }
    goto LAB_03037d0a;
  }
  bVar9 = param_1 - 8;
  uVar7 = (uint)bVar9;
  bVar8 = *(byte *)((int)PTR_DAT_0303781c + 5);
  uVar5 = (uint)(byte)(bVar8 + *(char *)(PTR_DAT_0303781c + 1) * '\n');
  uVar12 = (uint)*(byte *)((int)PTR_DAT_0303781c + 3);
  cVar11 = *(char *)PTR_DAT_03037818;
  if (cVar11 == '\x02') {
    if (uVar7 == 0) {
      bVar9 = 0;
      if (uVar12 == 0) {
        PTR_DAT_0303799c[3] = 1;
      }
    }
    else {
      if (2 < uVar12) {
        *(undefined1 *)((int)PTR_DAT_0303781c + 3) = 2;
      }
      bVar9 = 1;
    }
    puVar2 = PTR_DAT_0303799c;
    uVar7 = (uint)(byte)PTR_DAT_030379a0[(byte)(bVar9 * '\n' + PTR_DAT_0303799c[3])];
    if (uVar5 < (byte)PTR_DAT_030379a0[(byte)(bVar9 * '\n' + PTR_DAT_0303799c[3])]) {
      uVar7 = uVar5;
    }
    cVar11 = (char)(uVar7 / 10);
    PTR_DAT_0303799c[4] = cVar11;
    puVar2[5] = (char)uVar7 + cVar11 * -10;
  }
  else {
    uVar10 = (uint)*(byte *)((int)PTR_DAT_0303781c + 2) * 10 & 0xff;
    if (cVar11 == '\x03') {
      if ((*(byte *)((int)PTR_DAT_0303781c + 2) == 1) && (2 < uVar7)) {
        uVar7 = 2;
      }
      bVar9 = (byte)uVar7;
      uVar7 = uVar7 + uVar10 & 0xff;
      if (uVar7 == 0) {
        uVar7 = 1;
        bVar9 = 1;
      }
      uVar12 = (uint)(byte)PTR_DAT_030379a0[uVar7];
      if (uVar5 < (byte)PTR_DAT_030379a0[uVar7]) {
        uVar12 = uVar5;
      }
      cVar11 = (char)(uVar12 / 10);
      PTR_DAT_0303799c[4] = cVar11;
      puVar2[5] = (char)uVar12 + cVar11 * -10;
    }
    else {
      uVar12 = uVar12 + uVar10 & 0xff;
      uVar5 = *(byte *)((int)PTR_DAT_0303781c + 1) + 2000 + (uint)*(byte *)PTR_DAT_0303781c * 10;
      if (cVar11 == '\x04') {
        if (uVar12 == 2) {
          if (uVar7 < 2) {
LAB_03037944:
            if ((uVar7 == 0) && (bVar8 == 0)) {
              PTR_DAT_0303799c[5] = 1;
            }
          }
          else if (bVar8 < 9) {
            bVar9 = 2;
          }
          else if ((((uVar5 & 3) == 0) && (uVar5 % 100 != 0)) || (uVar5 % 400 == 0)) {
            PTR_DAT_0303799c[5] = 9;
            bVar9 = 2;
          }
          else {
            PTR_DAT_0303799c[5] = 8;
            bVar9 = 2;
          }
        }
        else {
          if (uVar7 < 3) goto LAB_03037944;
          if (1 < bVar8) {
            PTR_DAT_0303799c[5] = 1;
          }
          if ((uint)(byte)PTR_DAT_030379a0[uVar12] < (byte)PTR_DAT_0303799c[5] + 0x1e) {
            PTR_DAT_0303799c[5] = (byte)PTR_DAT_030379a0[uVar12] % 10;
            bVar9 = 3;
          }
          else {
            bVar9 = 3;
          }
        }
      }
      else if (cVar11 == '\x05') {
        if (uVar12 == 2) {
          if (8 < uVar7) {
            if (((uVar5 & 3) == 0) && (uVar5 % 100 != 0)) {
              uVar7 = 9;
            }
            else if (uVar5 % 400 == 0) {
              uVar7 = 9;
            }
            else {
              uVar7 = 8;
            }
          }
        }
        else if (PTR_DAT_03037b24[5] == '\x03') {
          if (bVar9 != 0) {
            uVar7 = 1;
          }
          if ((uint)(byte)PTR_DAT_03037b28[uVar12] < uVar7 + 0x1e) {
            uVar7 = 0;
          }
          bVar9 = (byte)uVar7;
          goto LAB_030379e6;
        }
        bVar9 = (byte)uVar7;
        if ((PTR_DAT_03037b24[5] == '\0') && (uVar7 == 0)) {
          bVar9 = 1;
        }
      }
    }
  }
LAB_030379e6:
  *(byte *)((int)PTR_DAT_03037b30 + (uint)*(byte *)PTR_DAT_03037b2c) = bVar9;
  menu_item_dispatch_cycle_sub_next();
  tx_gate_write_call_record(1);
LAB_03037d0a:
  event_record_guarded_by_state_flags();
  return;
}

