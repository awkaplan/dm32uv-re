/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: parse_bcd_numeric_input_dual_range_validation @ 0304dcc4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 486 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void parse_bcd_numeric_input_dual_range_validation(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  vfo_display_state *pvVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  byte *pbVar12;
  byte bVar13;
  uint uVar14;
  undefined *in_stack_00000000;
  undefined4 in_stack_00000024;
  
  bVar8 = *(byte *)PTR_DAT_0304de88;
  if (2 < bVar8) {
    if (bVar8 == 0) {
      uVar14 = 0;
    }
    else {
      uVar14 = 0;
      uVar10 = DAT_0304de90;
      pbVar12 = PTR_DAT_0304de8c;
      do {
        uVar14 = uVar14 + uVar10 * (*pbVar12 - 0x30);
        uVar10 = uVar10 / 10;
        pbVar12 = pbVar12 + 1;
      } while (pbVar12 != PTR_DAT_0304de8c + (byte)(bVar8 - 1) + 1);
    }
    if ((((uint)*PTR_DAT_0304de94 <= uVar14) && (uVar14 <= (uint)PTR_DAT_0304de94[1])) ||
       (((uint)PTR_DAT_0304de94[2] <= uVar14 && (uVar14 <= (uint)PTR_DAT_0304de94[3])))) {
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x0000002c);
      in_stack_00000000 = PTR_LAB_0304dea4;
      dialog_show_icon_and_two_numbers
                (0x30,0x30,PTR_DAT_0304dea8,
                 **(undefined4 **)
                   (PTR_PTR_0304dea0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304deb0 + 2);
      bVar13 = (byte)(uVar14 >> 0x18);
      bVar8 = (byte)(uVar14 >> 8);
      bVar11 = (byte)(uVar14 >> 0x10);
      if (cVar1 == '\0') {
        iVar9 = is_memory_channel_not_vfo();
        pvVar7 = p_vfo_display_state;
        if (iVar9 == 1) {
          *(byte *)p_vfo_display_state = (byte)uVar14;
          pvVar7->field_0x1 = bVar8;
          pvVar7->field_0x2 = bVar11;
          pvVar7->field_0x3 = bVar13;
          in_stack_00000024 = 1;
          uVar2 = *(undefined4 *)&pvVar7->field_0x4_0;
          SUBPIECE_SET(uVar3, 0, 1, pvVar7->flags_0x8);
          SUBPIECE_SET(uVar3, 1, 1, pvVar7->flags_0x9);
          SUBPIECE_SET(uVar3, 2, 1, pvVar7->field_0xa);
          SUBPIECE_SET(uVar3, 3, 1, pvVar7->field_0xb);
          SUBPIECE_SET(uVar4, 0, 1, pvVar7->field_0xc);
          SUBPIECE_SET(uVar4, 1, 1, pvVar7->flags_0xd);
          SUBPIECE_SET(uVar4, 2, 1, pvVar7->field_0xe);
          SUBPIECE_SET(uVar4, 3, 1, pvVar7->field_0xf);
          memcpy_ck803s(&stack0x00000000,&pvVar7->field_0x10,0x23);
          commit_channel_record_dual_vfo
                    (uVar14 & 0xff000000 |
                     (uVar14 >> 0x10 & 0xff) << 0x10 | uVar14 & 0xff | (uVar14 >> 8 & 0xff) << 8,
                     uVar2,uVar3,uVar4);
        }
        else {
          channel_field_bcd_write_to_flash_block(uVar14,0);
        }
      }
      else if (cVar1 == '\x01') {
        iVar9 = is_memory_channel_not_vfo();
        pvVar7 = p_vfo_display_state;
        if (iVar9 == 1) {
          p_vfo_display_state->field_0x4_0 = (byte)uVar14;
          pvVar7->field_0x5 = bVar8;
          pvVar7->field_0x6 = bVar11;
          pvVar7->field_0x7 = bVar13;
          in_stack_00000024 = 1;
          uVar2 = *(undefined4 *)pvVar7;
          SUBPIECE_SET(uVar5, 0, 1, pvVar7->flags_0x8);
          SUBPIECE_SET(uVar5, 1, 1, pvVar7->flags_0x9);
          SUBPIECE_SET(uVar5, 2, 1, pvVar7->field_0xa);
          SUBPIECE_SET(uVar5, 3, 1, pvVar7->field_0xb);
          SUBPIECE_SET(uVar6, 0, 1, pvVar7->field_0xc);
          SUBPIECE_SET(uVar6, 1, 1, pvVar7->flags_0xd);
          SUBPIECE_SET(uVar6, 2, 1, pvVar7->field_0xe);
          SUBPIECE_SET(uVar6, 3, 1, pvVar7->field_0xf);
          memcpy_ck803s(&stack0x00000000,&pvVar7->field_0x10,0x23);
          commit_channel_record_dual_vfo
                    (uVar2,uVar14 & 0xff000000 |
                           (uVar14 >> 0x10 & 0xff) << 0x10 |
                           uVar14 & 0xff | (uVar14 >> 8 & 0xff) << 8,uVar5,uVar6);
        }
        else {
          channel_field_bcd_write_to_flash_block(uVar14,1);
        }
      }
      goto LAB_0304dec0;
    }
  }
  OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x0000002c);
  in_stack_00000000 = PTR_LAB_0304e58c;
  dialog_show_icon_and_two_numbers
            (0x30,0x30,PTR_DAT_0304e590,
             **(undefined4 **)
               (PTR_PTR_0304e588 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
LAB_0304dec0:
  p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0x9f;
  OSTimeDly_ms_wrapper(1000);
  history_queue_pop();
  return;
}

