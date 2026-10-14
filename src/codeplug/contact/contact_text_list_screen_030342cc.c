/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_text_list_screen @ 030342cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 766 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_text_list_screen(byte param_1,uint param_2,uint param_3,ushort param_4)

{
  char cVar1;
  ushort uVar2;
  ushort block_id;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  uint offset;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ushort uStack_42;
  ushort uStack_40;
  byte bStack_3d;
  undefined1 uStack_3c;
  byte bStack_3b;
  undefined1 auStack_3a [15];
  undefined1 uStack_2b;
  byte bStack_26;
  
  param_3 = param_3 & 0xffff;
  uVar6 = (uint)param_4;
  block_id = flash_block_id_resolve_locked(0xb);
  PTR_DAT_03034368[1] = param_4;
  uVar4 = 8;
  if (*(char *)PTR_DAT_03034348 != '\0') {
    uVar4 = 7;
  }
  if (uVar6 == 0) {
    history_queue_pop();
    if (param_1 < 2) {
      format_and_write_status_field
                (0,10,**(undefined4 **)
                        (PTR_PTR_0303475c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
    else {
      format_and_write_status_field
                (0,10,**(undefined4 **)
                        (PTR_PTR_03034760 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
  }
  else {
    uVar3 = get_block0xb_u16_field0();
    if (uVar3 != 0) {
      uVar9 = (param_3 - (param_2 & 0xffff)) + 1 & 0xffff;
      offset = 0x100;
      uVar8 = 0;
      uVar7 = 0;
      uVar5 = 1;
      do {
        flash_block_read(block_id,offset,&uStack_3c,2);
        if (param_1 == 5) {
          if (bStack_3b >> 4 == 3) {
            uVar8 = uVar8 + 1 & 0xffff;
          }
        }
        else if (param_1 == 2) {
          if (bStack_3b >> 4 != 5) {
            uVar8 = uVar8 + 1 & 0xffff;
          }
        }
        else if (param_1 == 6) {
          if (bStack_3b >> 4 == 4) {
            uVar8 = uVar8 + 1 & 0xffff;
          }
        }
        else {
          uVar8 = uVar8 + 1 & 0xffff;
        }
        if (uVar9 + 1 == uVar8) {
          memcpy_bytes_iram(&uStack_42,&uStack_3c,2);
          uStack_42 = uStack_42 & 0xfff;
          talkgroup_index_decode_paged(uStack_42,&uStack_40,&bStack_3d);
          uStack_40 = flash_block_id_resolve_locked((undefined1)uStack_40);
          flash_block_read(uStack_40,(bStack_3d - 1) * 0x18 & 0xfff8,&uStack_3c,0x18);
          uVar2 = uVar5;
          if (*(char *)PTR_DAT_03034558 != '\0') {
            uVar2 = uVar5 + 1;
          }
          uVar2 = uVar2 & 0xff;
          uStack_2b = 0;
          if (uVar9 == param_3) {
            display_draw_list_row(uVar2,auStack_3a,1);
            display_blit_bitmap_1bpp_clipped(8,uVar2,0x18,0x18,PTR_DAT_0303455c[bStack_26 - 3]);
          }
          else {
            display_draw_list_row(uVar2,auStack_3a,0);
            display_blit_bitmap_1bpp_clipped(8,uVar2,0x18,0x18,PTR_DAT_03034560[bStack_26 - 3]);
          }
          uVar9 = uVar9 + 1 & 0xffff;
          if ((uVar6 <= uVar9) || (uVar5 = uVar5 + 1, uVar4 < uVar5)) {
            cVar1 = *(char *)((uint)p_menu_screen_state->index_0x1 + DAT_03034568 + 2);
            if (cVar1 == '\0') {
              if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
                number_to_string_format_2args(&uStack_3c,PTR_LAB_03034570,param_3 + 1,uVar6);
              }
              else {
                number_to_string_format_2args
                          (&uStack_3c,PTR_s_Contacts__d__d_03034574,param_3 + 1,uVar6);
              }
            }
            else if (cVar1 == '\x05') {
              if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03034578 + 2) == '\f') {
                if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
                  number_to_string_format_2args(&uStack_3c,PTR_LAB_03034570,param_3 + 1,uVar6);
                }
                else {
                  number_to_string_format_2args
                            (&uStack_3c,PTR_s_Contacts__d__d_03034574,param_3 + 1,uVar6);
                }
              }
              else if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
                number_to_string_format_2args(&uStack_3c,PTR_LAB_0303457c,param_3 + 1,uVar6);
              }
              else {
                number_to_string_format_2args
                          (&uStack_3c,PTR_s_Tx_Contact__d__d_03034580,param_3 + 1,uVar6);
              }
            }
            else if (cVar1 == '\b') {
              if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
                number_to_string_format_2args(&uStack_3c,PTR_LAB_0303457c,param_3 + 1,uVar6);
              }
              else {
                number_to_string_format_2args
                          (&uStack_3c,PTR_s_Tx_Contact__d__d_03034580,param_3 + 1,uVar6);
              }
            }
            else if (cVar1 == '\x03') {
              if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
                number_to_string_format_2args(&uStack_3c,PTR_DAT_03034754,param_3 + 1,uVar6);
              }
              else {
                number_to_string_format_2args
                          (&uStack_3c,PTR_s_Text_Send__d__d_03034758,param_3 + 1,uVar6);
              }
            }
            display_clear_status_row(0,0);
            display_draw_number_centered(1,0xffff,0,(uint)&uStack_3c);
            return;
          }
        }
        uVar7 = uVar7 + 1 & 0xffff;
        offset = offset + 2 & 0xffff;
      } while (uVar7 < uVar3);
    }
  }
  return;
}

