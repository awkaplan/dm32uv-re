/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_edit_validate_and_save @ 030355ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 578 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 contact_edit_validate_and_save(undefined4 param_1,int param_2__w)

{
  ushort param_2 = (ushort)param_2__w;
  int iVar1;
  char cVar2;
  ushort block_id;
  undefined4 uVar3;
  byte bVar4;
  ushort uStack_3c;
  ushort uStack_3a;
  uint uStack_38;
  byte bStack_34;
  byte bStack_33;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  char acStack_2e [17];
  undefined1 auStack_1d [8];
  byte bStack_15;
  
  iVar1 = p_list_row_text_buffer;
  bVar4 = p_vfo_display_state->flags_0x8 >> 4;
  strcpy_ck803s(acStack_2e,p_list_row_text_buffer);
  uStack_38 = strtol_signed_wrapper(iVar1 + 0x11);
  memcpy_bytes_iram(auStack_1d,&uStack_38,3);
  if (acStack_2e[0] == '\0') {
    dialog_show_icon_and_two_numbers
              (0x30,0x30,PTR_DAT_03035670,
               **(undefined4 **)
                 (PTR_PTR_03035694 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
               PTR_LAB_03035698);
    goto LAB_03035870;
  }
  if (uStack_38 == 0) {
    dialog_show_icon_and_two_numbers
              (0x30,0x30,PTR_DAT_03035670,
               **(undefined4 **)
                 (PTR_PTR_03035678 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
               PTR_LAB_03035698);
    goto LAB_03035870;
  }
  if (bVar4 == 0) {
    if (0xdfff < uStack_38) {
LAB_030356b8:
      dialog_show_icon_and_two_numbers
                (0x30,0x30,PTR_DAT_03035858,
                 **(undefined4 **)
                   (PTR_PTR_03035850 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                 PTR_LAB_03035854);
LAB_03035870:
      OSTimeDly_ms_wrapper(1000);
      return 0;
    }
    uStack_2f = 0;
  }
  else {
    if ((bVar4 == 1) && (0xfffcdf < uStack_38)) goto LAB_030356b8;
    if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
      uStack_2f = 3;
    }
    else {
      uStack_2f = 4;
    }
  }
  uVar3 = get_block0xb_u16_field0();
  block_id = flash_block_id_resolve_locked(0xb);
  bStack_15 = talkgroup_lookup_by_name(acStack_2e,&uStack_3c,uVar3);
  if (bStack_15 == 0) {
    bVar4 = 1;
  }
  else {
    bVar4 = ~(uStack_3c != param_2);
  }
  if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
    cVar2 = talkgroup_binary_search_by_id_and_flag(uStack_38,&uStack_3c,uVar3,3);
  }
  else {
    cVar2 = talkgroup_binary_search_by_id_and_flag(uStack_38,&uStack_3c,uVar3,4);
  }
  if (cVar2 == '\0') {
    if (bVar4 != 0) {
LAB_030357b0:
      dialog_show_icon_and_two_numbers
                (0x30,0x30,PTR_DAT_03035864,
                 **(undefined4 **)
                   (PTR_PTR_03035860 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                 PTR_LAB_03035854);
      flash_block_read(block_id,(uint)(ushort)((param_2 + 0x7f) * 2),&bStack_34,2);
      quick_contact_slot_bitmask_mark(0,param_2);
      cVar2 = contact_edit_save_flow2(&uStack_30,&bStack_15,0);
      if ((cVar2 != '\0') &&
         (PTR_DAT_03035868[1] != (ushort)((bStack_33 & 0xf) << 8 | (ushort)bStack_34))) {
        tx_contact_index_rewrite_both_blocks();
      }
      goto LAB_03035840;
    }
  }
  else if (bVar4 != 0) {
    flash_block_read(block_id,(uint)(ushort)((param_2 + 0x7f) * 2),&uStack_3a,2);
    uStack_3a = uStack_3a & 0xfff;
    flash_block_read(block_id,(uint)(ushort)((uStack_3c + 0x39f) * 2),&uStack_3c,2);
    uStack_3c = uStack_3c & 0xfff;
    if (uStack_3a == uStack_3c) goto LAB_030357b0;
  }
  dialog_show_icon_and_two_numbers
            (0x30,0x30,PTR_DAT_03035858,
             **(undefined4 **)
               (PTR_PTR_0303586c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
             PTR_LAB_03035854);
  OSTimeDly_ms_wrapper(1000);
LAB_03035840:
  OSTimeDly_ms_wrapper(1000);
  return 1;
}

