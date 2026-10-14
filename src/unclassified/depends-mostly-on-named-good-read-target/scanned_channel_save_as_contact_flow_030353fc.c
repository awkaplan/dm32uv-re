/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scanned_channel_save_as_contact_flow @ 030353fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 440 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 scanned_channel_save_as_contact_flow(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined1 uStack_d;
  
  local_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  bVar1 = p_vfo_display_state->flags_0x8 >> 4;
  uVar2 = get_block0xb_u16_field0();
  display_draw_dialog_panel();
  iVar3 = p_list_row_text_buffer;
  if (799 < uVar2) {
    display_blit_image(0x60,0x56,0x30,0x30,PTR_DAT_030354dc);
    display_draw_number_centered
              (0x90,0,0xc618,
               **(uint **)(PTR_PTR_030354e0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    goto LAB_030355de;
  }
  strcpy_ck803s((int)&local_28 + 2,p_list_row_text_buffer);
  local_2c = strtol_signed_wrapper(iVar3 + 0x11);
  memcpy_bytes_iram((int)&uStack_18 + 3,&local_2c,3);
  if (SUBPIECE_SET(local_28, 2, 1, = '\0') {
    display_blit_image(0x60,0x56,0x30,0x30,PTR_DAT_030354dc));
    display_draw_number_centered
              (0x90,0,0xc618,
               **(uint **)(PTR_PTR_030354e8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    goto LAB_030355de;
  }
  if (local_2c == 0) {
    display_blit_image(0x60,0x56,0x30,0x30,PTR_DAT_03035670);
    display_draw_number_centered
              (0x90,0,0xc618,
               **(uint **)(PTR_PTR_03035678 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    goto LAB_030355de;
  }
  if (bVar1 == 0) {
    if (0xdfff < local_2c) {
LAB_03035540:
      display_blit_image(0x60,0x56,0x30,0x30,PTR_DAT_03035670);
      display_draw_number_centered
                (0x90,0,0xc618,
                 **(uint **)(PTR_PTR_0303567c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))
      ;
      goto LAB_030355de;
    }
    SUBPIECE_SET(local_28, 0, 2, (ushort)(byte)local_28);
  }
  else {
    if ((bVar1 == 1) && (0xfffcdf < local_2c)) goto LAB_03035540;
    if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
      SUBPIECE_SET(local_28, 0, 2, CONCAT11(3,(byte)local_28));
    }
    else {
      SUBPIECE_SET(local_28, 0, 2, CONCAT11(4,(byte)local_28));
    }
  }
  display_blit_image(0x60,0x56,0x30,0x30,PTR_DAT_03035684);
  display_draw_number_centered
            (0x90,0,0xc618,
             **(uint **)(PTR_PTR_03035688 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  iVar3 = contact_edit_save_flow2(&local_28,&uStack_d,0);
  if (iVar3 != 0) {
    OSTimeDly_ms_wrapper(1000);
    return 1;
  }
LAB_030355de:
  OSTimeDly_ms_wrapper(1000);
  return 0;
}

