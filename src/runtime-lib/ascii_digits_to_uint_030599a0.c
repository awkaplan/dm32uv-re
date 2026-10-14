/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ascii_digits_to_uint @ 030599a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 378 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 ascii_digits_to_uint(void)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  
  uVar5 = (uint)*DAT_03059b14;
  if (uVar5 == 0) {
    *(undefined1 *)PTR_DAT_03059ce4 = 0;
  }
  else {
    iVar3 = 0;
    pbVar4 = (byte *)PTR_DAT_03059b18;
    do {
      iVar3 = (*pbVar4 - 0x30) + iVar3 * 10;
      pbVar4 = pbVar4 + 1;
    } while (pbVar4 != (byte *)((int)PTR_DAT_03059b18 + (uVar5 - 1 & 0xff) + 1));
    *(undefined1 *)((int)PTR_DAT_03059b18 + uVar5) = 0;
    if (iVar3 - 1U < 0xfffcdf) {
      *p_text_entry_current_char_alias = iVar3;
      p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xbb;
      return 1;
    }
  }
  uVar1 = *(undefined1 *)PTR_active_screen_subtype_03059b24;
  *(undefined1 *)PTR_active_screen_subtype_03059b24 = 2;
  if ((p_radio_mode_state_0003e318->flags_0x5 & 4) == 0) {
    tx_gate_write_call_record(0);
  }
  dialog_show_icon_and_two_numbers
            (0x30,0x30,PTR_DAT_03059b34,
             **(undefined4 **)
               (PTR_PTR_03059b2c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
             PTR_LAB_03059b30);
  OSTimeDly_ms_wrapper(1000);
  display_clear_body_and_underline();
  bVar2 = p_radio_mode_state_0003e318->flags_0x5;
  if ((bVar2 & 4) == 0) {
    if ((bVar2 & 0x40) == 0) {
      if ((bVar2 & 0x80) == 0) {
        display_draw_number_centered
                  (1,0xffff,0,
                   *(uint *)(PTR_PTR_03059b40[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                            4));
      }
      else {
        display_draw_number_centered
                  (1,0xffff,0,
                   *(uint *)(PTR_PTR_03059b3c[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                            4));
        scan_channel_icon_draw(1);
      }
    }
    else {
      display_draw_number_centered
                (1,0xffff,0,
                 *(uint *)(PTR_PTR_03059b38[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] +
                          (p_radio_mode_state_0003e318->flags_0x3 >> 2 & 1) * 4));
      scan_channel_icon_draw(1);
    }
  }
  else {
    display_draw_number_centered
              (1,0xffff,0,
               *(uint *)(PTR_PTR_03059b38[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] +
                        (p_radio_mode_state_0003e318->flags_0x3 >> 2 & 1) * 4));
  }
  display_format_id_with_separators();
  *(undefined1 *)PTR_active_screen_subtype_03059b24 = uVar1;
  return 0;
}

