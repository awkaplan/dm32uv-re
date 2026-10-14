/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_field_name_display_dispatch @ 0302c8fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_field_name_display_dispatch(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined4 *unaff_r4;
  byte *pbVar5;
  int unaff_r5;
  undefined *unaff_r6;
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [16];
  
  memset_bytes(auStack_20,0,0x10);
  memset_bytes(auStack_30,0,0x10);
  bVar3 = p_dialog_flags_from_flash->flags_0x1d & 0xe;
  if (bVar3 == 2) {
    uVar4 = p_dialog_flags_from_flash->flags_0x1e & 0xf;
    if (uVar4 < 6) {
                    /* WARNING: Could not recover jumptable at 0x0302c934. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0302c944[uVar4] & 0xfffffffe))();
      return;
    }
  }
  else if ((bVar3 == 6) || (bVar3 == 4)) {
    bVar1 = p_dialog_flags_from_flash->flags_0x1e;
    bVar2 = bVar1 & 0xf;
    if (bVar2 == 2) {
      if (bVar3 == 6) {
        uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
        dialog_show_icon_and_two_numbers
                  (0x30,0x30,PTR_DAT_0302cb28,*(undefined4 *)(PTR_PTR_0302cb20[uVar4 * 2] + 8),
                   *(undefined4 *)(PTR_PTR_0302cb24[uVar4] + 0xc));
      }
      else {
        bVar3 = bVar1 & 0x70;
        if ((bVar1 & 0x70) == 0) {
          dialog_show_icon_and_two_numbers
                    (0x30,0x30,PTR_DAT_0302cb2c,
                     *(undefined4 *)
                      (PTR_PTR_0302cb24[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 0x34),
                     *(undefined4 *)
                      (PTR_PTR_0302cb24[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 8));
        }
        else if (bVar3 == 0x10) {
          dialog_show_icon_and_two_numbers
                    (0x21,0x30,PTR_DAT_0302ccdc,
                     *(undefined4 *)
                      (PTR_PTR_0302ccd4[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 4),
                     PTR_LAB_0302ccd8);
        }
        else if (bVar3 == 0x20) {
          pbVar5 = &p_tx_ptt_ui_state->field_0x2e;
          contact_name_lookup_or_format(1,*(undefined4 *)&p_tx_ptt_ui_state->field_0x10_0,pbVar5,3);
          dialog_show_icon_and_two_numbers
                    (0x21,0x30,PTR_DAT_0302ccdc,pbVar5,
                     *(undefined4 *)
                      (PTR_PTR_0302cce4[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 4));
          display_fill_rect(0,0x122,0xf0,0x140,0);
        }
        else if (bVar3 == 0x30) {
          dialog_show_icon_and_two_numbers
                    (0x30,0x30,PTR_DAT_0302ccec,
                     *(undefined4 *)
                      (PTR_PTR_0302cce8[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 0x18),
                     PTR_LAB_0302ccd8);
        }
      }
    }
    else if (bVar2 == 5) {
      if (bVar3 == 6) {
        unaff_r5 = *(int *)(PTR_PTR_0302cce8[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 0x34);
        unaff_r6 = PTR_DAT_0302ccf0;
      }
      else if (bVar3 == 4) {
        unaff_r5 = *(int *)(PTR_PTR_0302cce8[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 0x2c);
        unaff_r6 = PTR_DAT_0302ccec;
      }
      if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
        dialog_show_icon_and_two_numbers(0x30,0x30,unaff_r6,unaff_r5,PTR_LAB_0302ccd8);
      }
      else {
        memcpy_bytes_iram(auStack_20,unaff_r5,6);
        dialog_show_icon_and_two_numbers(0x30,0x30,unaff_r6,auStack_20,unaff_r5 + 7);
      }
    }
    else {
      if (bVar2 == 1) {
        unaff_r4 = (undefined4 *)
                   (PTR_PTR_0302ccf4[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 4);
      }
      else if (bVar2 == 3) {
        unaff_r4 = (undefined4 *)
                   (PTR_PTR_0302ccf4[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 0xc);
      }
      else if (bVar2 == 4) {
        unaff_r4 = (undefined4 *)
                   (PTR_PTR_0302ccf4[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 0x10);
      }
      if (bVar3 == 6) {
        dialog_show_icon_and_two_numbers
                  (0x30,0x30,PTR_DAT_0302ccf0,*unaff_r4,
                   *(undefined4 *)
                    (PTR_PTR_0302cce8[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 0xc));
      }
      else {
        dialog_show_icon_and_two_numbers
                  (0x30,0x30,PTR_DAT_0302ccec,*unaff_r4,
                   *(undefined4 *)
                    (PTR_PTR_0302cce8[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 8));
      }
    }
  }
  return;
}

