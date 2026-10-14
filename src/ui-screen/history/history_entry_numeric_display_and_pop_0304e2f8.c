/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_entry_numeric_display_and_pop @ 0304e2f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 262 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_entry_numeric_display_and_pop(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  vfo_display_state *pvVar5;
  undefined4 uVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  undefined *in_stack_00000000;
  
  bVar1 = *(byte *)PTR_DAT_0304e490;
  if (bVar1 < 2) {
    OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x0000002c);
    in_stack_00000000 = PTR_LAB_0304e58c;
    dialog_show_icon_and_two_numbers
              (0x30,0x30,PTR_DAT_0304e590,
               **(undefined4 **)
                 (PTR_PTR_0304e588 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else {
    if (bVar1 == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = 0;
      uVar7 = DAT_0304e498;
      pbVar8 = PTR_DAT_0304e494;
      do {
        uVar9 = uVar9 + uVar7 * (*pbVar8 - 0x30);
        uVar7 = uVar7 / 10;
        pbVar8 = pbVar8 + 1;
      } while (pbVar8 != PTR_DAT_0304e494 + (byte)(bVar1 - 1) + 1);
    }
    OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x0000002c);
    in_stack_00000000 = PTR_LAB_0304e4a8;
    dialog_show_icon_and_two_numbers
              (0x30,0x30,PTR_DAT_0304e4ac,
               **(undefined4 **)
                 (PTR_PTR_0304e4a4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    counter_value_bcd_encode_and_save(uVar9 / 10);
    pvVar5 = p_vfo_display_state;
    uVar6 = *(undefined4 *)p_vfo_display_state;
    uVar2 = *(undefined4 *)&p_vfo_display_state->field_0x4_0;
    SUBPIECE_SET(uVar3, 0, 1, p_vfo_display_state->flags_0x8);
    SUBPIECE_SET(uVar3, 1, 1, p_vfo_display_state->flags_0x9);
    SUBPIECE_SET(uVar3, 2, 1, p_vfo_display_state->field_0xa);
    SUBPIECE_SET(uVar3, 3, 1, p_vfo_display_state->field_0xb);
    SUBPIECE_SET(uVar4, 0, 1, p_vfo_display_state->field_0xc);
    SUBPIECE_SET(uVar4, 1, 1, p_vfo_display_state->flags_0xd);
    SUBPIECE_SET(uVar4, 2, 1, p_vfo_display_state->field_0xe);
    SUBPIECE_SET(uVar4, 3, 1, p_vfo_display_state->field_0xf);
    memcpy_ck803s(&stack0x00000000,&p_vfo_display_state->field_0x10,0x23);
    uVar6 = channel_apply_frequency_offset(uVar6,uVar2,uVar3,uVar4);
    pvVar5->field_0x4_0 = (byte)uVar6;
    pvVar5->field_0x5 = (char)((uint)uVar6 >> 8);
    pvVar5->field_0x6 = (char)((uint)uVar6 >> 0x10);
    pvVar5->field_0x7 = (char)((uint)uVar6 >> 0x18);
  }
  p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0x9f;
  OSTimeDly_ms_wrapper(1000);
  history_queue_pop();
  return;
}

