/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_numeric_setting_commit_with_range_check @ 03036d1c (file base 0x03000000; code starts at 0x03001000)
 * Size: 634 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_numeric_setting_commit_with_range_check(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  short sStack_16;
  undefined2 uStack_14;
  byte bStack_11;
  undefined1 auStack_10 [4];
  
  if ((*(uint *)PTR_DAT_03036de4 & 0x18000) == 0x8000) {
    if (*(char *)PTR_DAT_03036df0 == '\0') {
      uVar7 = 0;
    }
    else {
      uVar5 = 10000;
      uVar7 = 0;
      pbVar6 = PTR_DAT_03036df4;
      do {
        uVar7 = uVar7 + uVar5 * (*pbVar6 - 0x30);
        uVar5 = uVar5 / 10;
        pbVar6 = pbVar6 + 1;
      } while (pbVar6 != PTR_DAT_03036df4 + (byte)(*(char *)PTR_DAT_03036df0 - 1) + 1);
    }
    uStack_14 = flash_block_id_resolve_locked(4);
    iVar4 = value_in_range_check(uVar7 & 0xffff);
    if (iVar4 == 0) {
      *(short *)PTR_DAT_03036df8 = (short)uVar7;
    }
    puVar2 = PTR_DAT_03036df8;
    bcd_pack_and_write_flash_block4_0x702(*(undefined2 *)PTR_DAT_03036df8);
    rda5807m_tune(*(undefined2 *)puVar2);
    OSTmr_state_dispatch_callback(DAT_03036dec,0,0,auStack_10);
    PTR_DAT_03036de0[6] = PTR_DAT_03036de0[6] & 0xf7;
    ui_event_notify(0x1a);
    ui_event_notify_alt(1);
    return;
  }
  if ((PTR_DAT_03036f94[6] & 4) == 0) {
    if ((PTR_DAT_03036f94[6] & 8) != 0) {
      bVar1 = *(byte *)PTR_DAT_03036f9c;
      if (2 < bVar1) {
        if (bVar1 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = 0;
          uVar7 = DAT_03036fb0;
          pbVar6 = (byte *)PTR_DAT_03036fa0;
          do {
            iVar4 = iVar4 + uVar7 * (*pbVar6 - 0x30);
            uVar7 = uVar7 / 10;
            pbVar6 = pbVar6 + 1;
          } while (pbVar6 != (byte *)((int)PTR_DAT_03036fa0 + (byte)(bVar1 - 1) + 1));
        }
        frequency_band_range_check_and_status_set(iVar4,iVar4);
        if ((PTR_DAT_03036f94[3] & 0x40) == 0) {
          OSTmr_state_dispatch_callback(DAT_030372c4,0,0,auStack_10);
          PTR_DAT_030372c8[6] = PTR_DAT_030372c8[6] & 0xf7;
          ui_event_notify(0x1a);
          bcd_pack_and_write_flash_block_0x41(iVar4,(byte)PTR_DAT_030372cc[0x2d] >> 7);
          ui_event_notify_alt(1);
          goto LAB_03036f74;
        }
      }
      OSTmr_state_dispatch_callback(DAT_03036fa8,0,0,auStack_10);
      puVar3 = PTR_DAT_03036f94;
      PTR_DAT_03036f94[6] = PTR_DAT_03036f94[6] & 0xf7;
      puVar3[3] = puVar3[3] & 0x9f;
      ui_event_notify(0x1b);
      history_queue_pop();
    }
  }
  else {
    *PTR_text_entry_current_char_minus_6_03036f98 = 0;
    PTR_DAT_03036f94[6] = PTR_DAT_03036f94[6] & 0xfb;
    if (*(byte *)PTR_DAT_03036f9c != 0) {
      iVar4 = *PTR_text_entry_current_char_minus_6_03036f98;
      uVar7 = 0;
      do {
        iVar4 = (*(byte *)((int)PTR_DAT_03036fa0 + uVar7) - 0x30) + iVar4 * 10;
        uVar7 = uVar7 + 1;
      } while ((uVar7 & 0xff) < (uint)*(byte *)PTR_DAT_03036f9c);
      *PTR_text_entry_current_char_minus_6_03036f98 = iVar4;
    }
    if ((PTR_DAT_03036f94[0x15] & 4) == 0) {
      channel_offset_minus_0x10(PTR_DAT_03036fa4[0x29],&uStack_14,&sStack_16);
      flash_field_read_cached((undefined1)uStack_14,sStack_16 + 0x10,&bStack_11,1);
    }
    else {
      bStack_11 = 10;
    }
    OSTmr_state_dispatch_callback(DAT_03036fa8,0,0,auStack_10);
    if (((uint)bStack_11 < (uint)*PTR_text_entry_current_char_minus_6_03036f98) ||
       (*PTR_text_entry_current_char_minus_6_03036f98 == 0)) {
      ui_event_notify(0x1b);
      history_queue_pop();
    }
    else {
      ui_event_notify(0x1a);
      PTR_DAT_03036fa4[0x26] = *(undefined1 *)PTR_text_entry_current_char_minus_6_03036f98;
      if ((PTR_DAT_03036f94[0x15] & 4) == 0) {
        settings_write_dispatcher(0x2b);
      }
      else {
        settings_write_dispatcher(0x2c);
      }
      ui_event_notify_alt(1);
    }
    PTR_DAT_03036fac[4] = PTR_DAT_03036fac[4] & 0xdf | 0x20;
  }
LAB_03036f74:
  if ((PTR_DAT_03036fa4[0x2d] & 0x80) == 0) {
    *(byte *)PTR_DAT_03036fb4 = *(byte *)PTR_DAT_03036fb4 & 0xf7;
  }
  else {
    *(byte *)PTR_DAT_030372c0 = *(byte *)PTR_DAT_030372c0 & 0xef;
  }
  return;
}

