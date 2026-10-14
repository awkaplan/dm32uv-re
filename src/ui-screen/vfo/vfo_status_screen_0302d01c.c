/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_status_screen @ 0302d01c (file base 0x03000000; code starts at 0x03001000)
 * Size: 338 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_status_screen(void)

{
  dialog_flags_from_flash *pdVar1;
  uint uVar2;
  
  if (((*(byte *)p_call_active_flag & 3) == 0) &&
     ((1 < (byte)(p_dialog_flags_from_flash->field_0x32 - 3) ||
      ((p_dialog_flags_from_flash->flags_0x1 & 3) != 1)))) {
    display_draw_status_bar();
    display_fill_screen(0);
    display_fill_rect(0,0x122,0xf0,0x140,0);
    display_update_datetime(1);
    pdVar1 = p_dialog_flags_from_flash;
    if ((p_dialog_flags_from_flash->flags_0x1 & 3) == 1) {
      if ((p_dialog_flags_from_flash->flags_0x1f & 0x78) == 0x40) {
        display_blit_image(0x60,0x56,0x30,0x30,PTR_LAB_0302d178);
        display_draw_number_centered
                  (0x90,0xffff,0,
                   **(uint **)(PTR_PTR_0302d180 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8
                              ));
      }
      else if (1 < (byte)(p_dialog_flags_from_flash->field_0x32 - 3)) {
        number_to_string_format_2args
                  (p_caller_id_display_text,DAT_0302d188,
                   *(undefined4 *)&p_dialog_flags_from_flash->field_0x28_0);
        contact_name_lookup_or_format(1,*(undefined4 *)&pdVar1->field_0x28_0,&pdVar1->field_0xc,4);
        if ((pdVar1->flags_0x1f & 0x78) == 8) {
          p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xfe | 1;
        }
        else {
          display_draw_number_centered
                    (100,0xffff,0,
                     *(uint *)(PTR_PTR_0302d190[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 4));
          uVar2 = p_caller_id_display_text;
          display_draw_number_centered(0x82,0xffff,0,p_caller_id_display_text);
          *(byte *)(uVar2 - 0x23) = *(byte *)(uVar2 - 0x23) & 0xfe;
        }
      }
    }
    else {
      contact_name_lookup_or_format
                (1,*(undefined4 *)&p_dialog_flags_from_flash->field_0x4_0,p_caller_id_display_text,3
                );
      contact_name_lookup_or_format(1,*(undefined4 *)&pdVar1->field_0x8_0,&pdVar1->field_0xc,4);
      display_draw_number_centered
                (100,0xffff,0,
                 *(uint *)(PTR_PTR_0302d190[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 0x30));
    }
  }
  return;
}

