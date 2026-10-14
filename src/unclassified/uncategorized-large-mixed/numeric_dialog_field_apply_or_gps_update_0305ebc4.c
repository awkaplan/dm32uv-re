/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: numeric_dialog_field_apply_or_gps_update @ 0305ebc4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 322 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void numeric_dialog_field_apply_or_gps_update(void)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  
  bVar2 = get_event_flags_byte_dispatch(0xd);
  if ((bVar2 & 1) == 0) {
    if ((bVar2 & 2) != 0) {
      update_event_flags_byte_dispatch(0xd,2);
      iVar5 = keypad_dispatch_not_inhibited();
      if (iVar5 != 0) {
        uVar4 = mmio_read_16bit_offset_14();
        puVar1 = PTR_DAT_0305ecec;
        *(undefined2 *)PTR_DAT_0305ecec = uVar4;
        uVar6 = dialog_state_get_field_03020724();
        puVar1[0xc9] = uVar6;
        if (599 < *(ushort *)puVar1) {
          *(undefined2 *)puVar1 = 599;
        }
        iVar5 = DAT_0305ecfc;
        puVar1 = PTR_DAT_0305ecec;
        memcpy_from_const_0302076c(DAT_0305ecfc,*(undefined2 *)PTR_DAT_0305ecec);
        uVar8 = (uint)*(ushort *)puVar1;
        *(undefined1 *)(iVar5 + uVar8) = 0;
        if ((p_radio_mode_state_0003e318[1].flags_0x7 & 4) == 0) {
          if ((p_vfo_display_state->field_0xa & 4) != 0) {
            p_tx_ptt_ui_state->field_0xc = p_tx_ptt_ui_state->field_0xc & 0x7f | 0x80;
          }
        }
        else {
          if (0x43 < uVar8) {
            *(undefined2 *)puVar1 = 0x43;
          }
          iVar5 = DAT_0305ed0c;
          puVar1 = PTR_DAT_0305ecec;
          iVar7 = record_build_value_plus_csv_field
                            (PTR_DAT_0305ecec[0xc9],DAT_0305ecfc,*(undefined2 *)PTR_DAT_0305ecec,
                             DAT_0305ed0c);
          *(short *)puVar1 = (short)iVar7;
          *(undefined1 *)(iVar5 + iVar7) = 0;
          if (puVar1[0xc9] == PTR_DAT_0305ed10[2]) {
            OSFlagPost_wrapper_set_passthrough(0x4000);
          }
        }
      }
    }
  }
  else {
    update_event_flags_byte_dispatch(0xd,1);
    iVar5 = keypad_dispatch_not_inhibited();
    if (iVar5 != 0) {
      uVar4 = mmio_read_16bit_offset_14();
      puVar1 = PTR_DAT_0305ecec;
      *(undefined2 *)PTR_DAT_0305ecec = uVar4;
      uVar6 = dialog_state_get_field_03020724();
      puVar1[0xc9] = uVar6;
      if (599 < *(ushort *)puVar1) {
        *(undefined2 *)puVar1 = 600;
      }
      iVar5 = DAT_0305ecfc;
      puVar1 = PTR_DAT_0305ecec;
      dmr_config_callback_variant_dispatcher(DAT_0305ecfc,*(undefined2 *)PTR_DAT_0305ecec);
      *(undefined1 *)(iVar5 + (uint)*(ushort *)puVar1) = 0;
      iVar5 = radio_mode_state_field_lookup_if_key_matches(iVar5);
      if (iVar5 == 0) {
        p_tx_ptt_ui_state->field_0xc = p_tx_ptt_ui_state->field_0xc & 0xbf | 0x40;
        uVar3 = get_state_field_03020748();
        PTR_DAT_0305ed08[9] = uVar3;
      }
      else if ((iVar5 == 0x31) && ((*(byte *)PTR_DAT_0305ed00 & 0x40) != 0)) {
        gps_nmea_gprmc_parser(1,puVar1[0xc9]);
      }
    }
  }
  return;
}

