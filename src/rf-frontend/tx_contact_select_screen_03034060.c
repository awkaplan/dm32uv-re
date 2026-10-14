/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_contact_select_screen @ 03034060 (file base 0x03000000; code starts at 0x03001000)
 * Size: 570 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_contact_select_screen(int param_1__w,uint param_2,uint param_3,uint param_4)

{
  byte param_1 = (byte)param_1__w;
  ushort uVar1;
  int iVar2;
  ushort block_id;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  ushort uStack_40;
  byte bStack_3d;
  undefined4 local_3c;
  undefined1 uStack_38;
  undefined1 uStack_2b;
  byte bStack_26;
  
  param_3 = param_3 & 0xffff;
  uVar7 = param_4 & 0xffff;
  block_id = flash_block_id_resolve_locked(0xb);
  PTR_DAT_03034114[1] = (short)param_4;
  iVar2 = p_dm32_settings_block04;
  uVar3 = 8;
  if (*(char *)PTR_DAT_03034118 != '\0') {
    uVar3 = 7;
  }
  if (uVar7 == 0) {
    display_fill_screen(0);
    if (param_1 < 2) {
      format_and_write_status_field
                (0,10,**(undefined4 **)
                        (PTR_PTR_03034360 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
    else {
      format_and_write_status_field
                (0,10,**(undefined4 **)
                        (PTR_PTR_03034364 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
    ui_event_notify(0x1b);
  }
  else {
    uVar4 = (param_3 - (param_2 & 0xffff)) + 1 & 0xffff;
    uVar8 = 0;
    uVar5 = 0;
    uVar6 = 1;
    do {
      if (uVar4 == 0) {
        if ((*(byte *)(iVar2 + 0x30) & 0x40) == 0) {
          local_3c = CONCAT13(SUBPIECE(local_3c, 3, 1),0xdece);
        }
        else {
          local_3c = DAT_03034120;
          uStack_38 = 0;
        }
        if (param_3 == 0) {
          display_draw_list_row(uVar6,&local_3c,1);
        }
        else {
          display_draw_list_row(uVar6,&local_3c,0);
        }
        uVar4 = 1;
        uVar6 = uVar6 + 1;
      }
      else {
        flash_block_read(block_id,(uVar4 + 0x7f) * 2 & 0xffff,&local_3c,2);
        if (param_1 == 5) {
          if (SUBPIECE(local_3c, 1, 1) >> 4 == 3) {
            uVar8 = uVar8 + 1 & 0xffff;
          }
        }
        else if (param_1 == 2) {
          if (SUBPIECE(local_3c, 1, 1) >> 4 != 5) {
            uVar8 = uVar8 + 1 & 0xffff;
          }
        }
        else if (param_1 == 6) {
          if (SUBPIECE(local_3c, 1, 1) >> 4 == 4) {
            uVar8 = uVar8 + 1 & 0xffff;
          }
        }
        else {
          uVar8 = uVar8 + 1 & 0xffff;
        }
        if (uVar4 == uVar8) {
          talkgroup_index_decode_paged(local_3c & 0xfff,&uStack_40,&bStack_3d);
          uStack_40 = flash_block_id_resolve_locked((undefined1)uStack_40);
          flash_block_read(uStack_40,(bStack_3d - 1) * 0x18 & 0xfff8,&local_3c,0x18);
          uVar1 = uVar6;
          if (*(char *)PTR_DAT_03034348 != '\0') {
            uVar1 = uVar6 + 1;
          }
          uVar1 = uVar1 & 0xff;
          uStack_2b = 0;
          if (uVar4 == param_3) {
            display_draw_list_row(uVar1,(int)&local_3c + 2,1);
            display_blit_bitmap_1bpp_clipped(8,uVar1,0x18,0x18,PTR_DAT_0303434c[bStack_26 - 3]);
          }
          else {
            display_draw_list_row(uVar1,(int)&local_3c + 2,0);
            display_blit_bitmap_1bpp_clipped(8,uVar1,0x18,0x18,PTR_DAT_03034350[bStack_26 - 3]);
          }
          uVar4 = uVar4 + 1 & 0xffff;
          uVar6 = uVar6 + 1;
        }
        if ((uVar7 <= uVar4) || (uVar3 < uVar6)) {
          if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
            number_to_string_format_2args(&local_3c,PTR_LAB_03034358,param_3 + 1,uVar7);
          }
          else {
            number_to_string_format_2args
                      (&local_3c,PTR_s_Tx_Contact__d__d_0303435c,param_3 + 1,uVar7);
          }
          display_clear_status_row(0,0);
          display_draw_number_centered(1,0xffff,0,(uint)&local_3c);
          return;
        }
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < uVar7);
  }
  return;
}

