/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ptt_ui_state_machine_update @ 0302c5c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 752 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte ptt_ui_state_machine_update(void)

{
  byte bVar1;
  byte bVar2;
  undefined3 uVar3;
  tx_ptt_ui_state *ptVar4;
  tx_ptt_ui_state *ptVar5;
  tx_ptt_ui_state *ptVar6;
  dialog_flags_from_flash *pdVar7;
  int iVar8;
  byte bVar9;
  
  if ((*(byte *)((int)p_call_active_flag + 1) & 1) == 0) {
    bVar9 = 0;
  }
  else {
    bVar9 = 8;
  }
  if (((*(byte *)p_call_active_flag & 1) == 0) &&
     ((((*(byte *)p_call_active_flag & 2) == 0 || ((*(byte *)p_dialog_flags_from_flash & 1) != 0))
      && (iVar8 = get_field_0301ea64_0x14(), iVar8 == 0)))) {
    if ((p_tx_ptt_ui_state->flags_0xa & 0x30) != 0) {
      p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xcf;
    }
  }
  else if ((*(char *)PTR_DAT_0302c678 == '\0') || (0x3f < *(byte *)PTR_DAT_0302c678)) {
    if ((*(byte *)p_call_active_flag & 2) != 0) goto LAB_0302c63e;
    if ((*(byte *)p_call_active_flag & 1) == 0) {
      iVar8 = get_field_0301ea64_0x14();
      if (iVar8 == 2) {
        bVar9 = 3;
      }
      else {
        iVar8 = get_field_0301ea64_0x14();
        if (iVar8 == 1) {
          bVar9 = 2;
        }
      }
    }
    else {
      p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xcf | 0x10;
      bVar9 = 2;
    }
  }
  else if ((*(byte *)p_call_active_flag & 2) != 0) {
LAB_0302c63e:
    p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xcf | 0x20;
    bVar9 = 3;
  }
  ptVar4 = p_tx_ptt_ui_state;
  if (PTR_DAT_0302c808[0x328] != '\0') {
    bVar9 = 7;
  }
  bVar1 = *(byte *)p_call_active_flag;
  if ((bVar1 & 0xc0) != 0) {
    bVar9 = 1;
  }
  if (((p_dialog_flags_from_flash->flags_0x2d & 4) != 0) &&
     ((p_radio_mode_state_0003e318[2].flags_0x2 & 1) == 0)) {
    bVar9 = 5;
  }
  if ((p_dialog_flags_from_flash->flags_0x1d & 1) != 0) {
    bVar9 = 6;
  }
  if ((p_dialog_flags_from_flash->flags_0x1 & 3) != 0) {
    bVar9 = 4;
  }
  if ((*(byte *)p_dialog_flags_from_flash & 2) != 0) {
    bVar9 = 0;
  }
  p_tx_ptt_ui_state->field_0x7 = bVar9;
  pdVar7 = p_dialog_flags_from_flash;
  ptVar6 = p_tx_ptt_ui_state;
  ptVar5 = p_tx_ptt_ui_state;
  bVar2 = ptVar4->field_0x8;
  if ((bVar9 == bVar2) && ((p_tx_ptt_ui_state->flags_0xa & 0x44) == 0)) goto LAB_0302c8e6;
  if ((byte)(bVar9 - 2) < 2) {
    p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xf7 | 8;
    if (1 < (byte)(bVar2 - 2)) {
      ptVar5->flags_0xa = ptVar5->flags_0xa & 0xfb | 4;
    }
    ptVar4 = p_tx_ptt_ui_state;
    if ((bVar1 & 1) == 0) {
      uVar3 = *(undefined3 *)&p_tx_ptt_ui_state->field_0x19;
      ptVar4->field_0x64_0 = p_tx_ptt_ui_state->field_0x18_0;
      *(undefined3 *)&ptVar4->field_0x65 = uVar3;
    }
    else {
      uVar3 = *(undefined3 *)&p_tx_ptt_ui_state->field_0x11;
      ptVar4->field_0x64_0 = p_tx_ptt_ui_state->field_0x10_0;
      *(undefined3 *)&ptVar4->field_0x65 = uVar3;
    }
LAB_0302c8b2:
    bVar9 = p_tx_ptt_ui_state->field_0x7;
    if (bVar9 == 8) goto LAB_0302c8d4;
    p_call_active_flag[1] = p_call_active_flag[1] & 0xfe;
    if (1 < (byte)(bVar9 - 2)) goto LAB_0302c8d0;
  }
  else {
    if (bVar9 == 7) {
      p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xf7 | 8;
      ptVar5->flags_0xa = ptVar5->flags_0xa & 0xbf;
      goto LAB_0302c8b2;
    }
    if (bVar9 == 5) {
      if (bVar2 != 5) {
        p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xfb | 4;
      }
      ptVar4 = p_tx_ptt_ui_state;
      p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xfd | 2;
      ptVar4->flags_0xa = ptVar4->flags_0xa & 0xbf;
      goto LAB_0302c8b2;
    }
    if (bVar9 == 4) {
      if (bVar2 != 4) {
        p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xfb | 4;
      }
      p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0x3f | 0x80;
      clear_state_byte_pair_03035a00();
      goto LAB_0302c8b2;
    }
    if (bVar9 == 1) {
      p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xef | 0x10;
      ptVar6->flags_0xa = ptVar6->flags_0xa & 0xbf;
      goto LAB_0302c8b2;
    }
    if (bVar9 == 6) {
      p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0x8f;
      pdVar7->flags_0x1f = pdVar7->flags_0x1f & 0xf8;
      p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xfb | 4;
      goto LAB_0302c8b2;
    }
    if (bVar9 == 8) {
      p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xbf | 0x40;
      goto LAB_0302c8b2;
    }
    if (bVar9 == 0) {
      if ((p_tx_ptt_ui_state->flags_0xb & 0x20) == 0) {
        p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xdf | 0x20;
        ptVar6->field_0x2 = 0;
        ptVar6->flags_0xa = ptVar6->flags_0xa & 0xbf;
      }
      if (bVar2 == 2) {
        tx_ptt_ui_field_set_on_call_match_gate();
      }
      goto LAB_0302c8b2;
    }
    if (bVar9 == 9) {
      p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0x7f | 0x80;
      goto LAB_0302c8b2;
    }
    p_call_active_flag[1] = p_call_active_flag[1] & 0xfe;
LAB_0302c8d0:
    if (bVar9 != 0) {
LAB_0302c8d4:
      p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xcf;
    }
  }
  p_tx_ptt_ui_state->field_0x8 = p_tx_ptt_ui_state->field_0x7;
LAB_0302c8e6:
  return p_tx_ptt_ui_state->field_0x7;
}

