/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_commit_channel_selection @ 0305d9bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 264 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_commit_channel_selection(void)

{
  undefined3 uVar1;
  dialog_flags_from_flash *pdVar2;
  dialog_flags_from_flash *pdVar3;
  vfo_display_state *pvVar4;
  int iVar5;
  tx_ptt_ui_state *ptVar6;
  undefined1 auStack_24 [2];
  undefined1 auStack_22 [17];
  undefined1 auStack_11 [5];
  
  if (p_dialog_flags_from_flash->field_0x32 != 0) {
    tx_abort_on_condition();
    pdVar2 = p_dialog_flags_from_flash;
    p_dialog_flags_from_flash->field_0x20 = p_dialog_flags_from_flash->field_0x20 & 0xf0;
    pvVar4 = p_vfo_display_state;
    pdVar3 = p_dialog_flags_from_flash;
    if (pdVar2->field_0x32 == 1) {
      p_dialog_flags_from_flash->flags_0x1 = p_dialog_flags_from_flash->flags_0x1 & 0xfc | 1;
      pdVar3->flags_0x1f = pdVar3->flags_0x1f & 0x87 | 0x40;
    }
    else {
      p_dialog_flags_from_flash->field_0x30 =
           p_dialog_flags_from_flash->field_0x30 & 0xf9 |
           (p_vfo_display_state->flags_0x8 >> 1 & 3) << 1;
      ui_event_notify_alt(4);
      record_read_by_index(*(undefined2 *)&pvVar4->field_0x31_0,auStack_24);
      iVar5 = p_caller_id_display_text;
      memcpy_bytes_iram(p_caller_id_display_text,auStack_22,0x10);
      memcpy_bytes_iram(iVar5 + 0x36,auStack_11,3);
      if (1 < (byte)(pdVar3->field_0x32 - 3)) {
        ui_event_notify(0x18);
      }
      if ((p_dialog_flags_from_flash->field_0x33 == 3) &&
         (p_dialog_flags_from_flash->field_0x32 != 5)) {
        dialog_state_set_flag_0xc(1);
        ptVar6 = p_tx_ptt_ui_state;
        pdVar2 = p_dialog_flags_from_flash;
        uVar1 = *(undefined3 *)&p_tx_ptt_ui_state->field_0x65;
        pdVar2->field_0x28_0 = p_tx_ptt_ui_state->field_0x64_0;
        *(undefined3 *)&pdVar2->field_0x29 = uVar1;
        pdVar2->flags_0x1 = pdVar2->flags_0x1 & 0xfc | 1;
        pdVar2->flags_0x1f = pdVar2->flags_0x1f & 0x87 | 0x18;
        *(undefined1 *)ptVar6 = 10;
        if ((pdVar2->field_0x3e & 1) == 0) {
          p_dialog_flags_from_flash->flags_0x1f =
               p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x28;
        }
        else {
          channel_dialog_commit_flags_update();
        }
      }
      else {
        dialog_request_enqueue(9,*(void **)&p_tx_ptt_ui_state->field_0x64_0);
      }
    }
  }
  return;
}

