/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_record_commit @ 0301765c (file base 0x03000000; code starts at 0x03001000)
 * Size: 564 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_record_commit(void)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  byte bVar7;
  radio_mode_state_0003e318 *prVar8;
  vfo_display_state *pvVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  int iVar12;
  int iVar13;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [2];
  short sStack_22;
  
  puVar10 = p_dm32_settings_block04;
  SUBPIECE_SET(uVar2, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
  SUBPIECE_SET(uVar2, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
  if (uVar2 < 4000) {
    dialog_show_icon_and_two_numbers
              (0x30,0x30,PTR_DAT_030177e4,
               **(undefined4 **)
                 (PTR_PTR_030177dc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
               PTR_LAB_030177e0);
    prVar8 = p_radio_mode_state_0003e318;
    *(short *)&p_radio_mode_state_0003e318[1].field_0x8 =
         *(short *)&p_radio_mode_state_0003e318[1].field_0x8 + 1;
    flash_block_write(0x12,0,&prVar8[1].field_0x8,2);
    SUBPIECE_SET(uVar3, 0, 1, prVar8[1].field_0x8);
    SUBPIECE_SET(uVar3, 1, 1, prVar8[1].field_0x9);
    channel_offset_from_num(uVar3,auStack_24,&sStack_22);
    flash_block_write(auStack_24[0],sStack_22,p_text_entry_buffer,0x10);
    pvVar9 = p_vfo_display_state;
    u32_to_bcd4_encode(*(undefined4 *)p_vfo_display_state,auStack_2c);
    u32_to_bcd4_encode(*(undefined4 *)&pvVar9->field_0x4_0,auStack_28);
    SUBPIECE_SET(uVar4, 0, 1, prVar8[1].field_0x8);
    SUBPIECE_SET(uVar4, 1, 1, prVar8[1].field_0x9);
    channel_num_to_block_offset(uVar4,auStack_24,&sStack_22);
    flash_block_write(auStack_24[0],sStack_22,auStack_2c,8);
    pvVar9->field_0xa = pvVar9->field_0xa & 0x7f;
    flash_block_write(auStack_24[0],sStack_22 + 8,&pvVar9->flags_0x8,0x18);
    bVar7 = puVar10[0x2d];
    puVar10[0x2d] = bVar7 & 0xfb | 4;
    SUBPIECE_SET(uVar5, 0, 1, prVar8[1].field_0x8);
    SUBPIECE_SET(uVar5, 1, 1, prVar8[1].field_0x9);
    dmr_id_log_write(uVar5,*(undefined2 *)&pvVar9->field_0x31_0);
    ui_event_notify(0x1a);
    channel_offset_minus_0x10(puVar10[0x29],auStack_24,&sStack_22);
    puVar11 = PTR_DAT_030177ec;
    flash_field_read_cached(auStack_24[0],sStack_22 + 0x10,PTR_DAT_030177ec,1);
    iVar13 = _p_dm32_settings_block04;
    if ((byte)*puVar11 < 0x40) {
      dialog_show_icon_and_two_numbers
                (0x30,0x30,_DAT_030178d8,
                 **(undefined4 **)
                   (_LAB_030178d0 + (*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1) * 8),
                 _DAT_030178d4);
      SUBPIECE_SET(uVar6, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
      SUBPIECE_SET(uVar6, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
      dmr_id_log_append(*(char *)(iVar13 + 0x29) + -1,uVar6);
      iVar12 = _p_dm32_settings_block04;
      if ((*(byte *)(iVar13 + 0x2d) & 0x80) == 0) {
        *(byte *)(iVar13 + 0x2d) = *(byte *)(iVar13 + 0x2d) & 0xfe | ~*(byte *)(iVar13 + 0x2d) & 1;
        settings_write_dispatcher(0xc);
        uVar1 = *_DAT_030178e0;
        *(undefined1 *)(iVar13 + 0x27) = uVar1;
        *(undefined1 *)(iVar13 + 0x26) = uVar1;
      }
      else {
        *(byte *)(_p_dm32_settings_block04 + 0x2d) =
             *(byte *)(_p_dm32_settings_block04 + 0x2d) & 0xfd |
             (byte)(((*(byte *)(_p_dm32_settings_block04 + 0x2d) ^ 2) >> 1 & 1) << 1);
        settings_write_dispatcher(0xc);
        uVar1 = *_DAT_030178e0;
        *(undefined1 *)(iVar12 + 0x28) = uVar1;
        *(undefined1 *)(iVar12 + 0x26) = uVar1;
      }
      iVar13 = get_current_mode_state2();
      if (iVar13 != 0) {
        set_flag_byte_03064328(4);
        iVar13 = _DAT_030178e4;
        *(undefined1 *)(_DAT_030178e4 + 0x1d) = 0;
        *(undefined1 *)(iVar13 + 0x1c) = 0;
        set_flag_byte_03064328(3);
      }
      vfo_load_side_config();
      settings_bitfield_remap_0x2d();
      *(byte *)(_DAT_030178e8 + 1) =
           *(byte *)(_DAT_030178e8 + 1) & 0xfe | *(byte *)(_p_dm32_settings_block04 + 0x2d) >> 7;
      ui_event_notify_alt(8);
      write_field_and_mbox_post(1,100);
    }
    else {
      puVar10[0x2d] = puVar10[0x2d] & 0xfb | (bVar7 >> 2 & 1) << 2;
      format_and_write_status_field2
                (**(undefined4 **)(PTR_PTR_030177f0 + ((byte)puVar10[0x30] >> 6 & 1) * 8));
    }
  }
  else {
    format_and_write_status_field2(PTR_PTR_030177d8[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
    ui_event_notify(0x21);
  }
  return;
}

