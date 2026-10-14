/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: refresh_display_based_on_dialog_flags @ 0302d36c (file base 0x03000000; code starts at 0x03001000)
 * Size: 414 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void refresh_display_based_on_dialog_flags(void)

{
  byte bVar1;
  
  if (((p_dialog_flags_from_flash->flags_0x1f & 0x78) == 0x30) ||
     ((p_dialog_flags_from_flash->field_0x32 != 3 && (p_dialog_flags_from_flash->field_0x32 != 4))))
  {
    if (p_dialog_flags_from_flash->field_0x3f != 5) {
      display_fill_screen(0);
    }
    bVar1 = p_dialog_flags_from_flash->flags_0x1f & 0x78;
    if (bVar1 == 8) {
      display_clear_status_row(100,0);
      display_draw_number_centered
                (100,0xffff,0,
                 **(uint **)(PTR_PTR_0302d4d8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))
      ;
    }
    else if (bVar1 == 0x10) {
      if (p_dialog_flags_from_flash->field_0x3f == 2) {
        display_clear_status_row(100,0);
        display_clear_status_row(0x82,0);
        display_draw_number_centered
                  (100,0xffff,0,
                   **(uint **)(PTR_PTR_0302d4dc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8
                              ));
        ui_event_notify(0x1b);
      }
    }
    else if (bVar1 == 0x18) {
      if (p_dialog_flags_from_flash->field_0x3f == 2) {
        display_clear_status_row(100,0);
        display_clear_status_row(0x82,0);
        display_draw_number_centered
                  (100,0xffff,0,
                   **(uint **)(PTR_PTR_0302d4e0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8
                              ));
        ui_event_notify(0x1a);
      }
    }
    else if (bVar1 == 0x30) {
      display_clear_status_row(0x82,0);
      display_draw_number_centered
                (0x82,0xffff,0,
                 **(uint **)(PTR_PTR_0302d4e4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))
      ;
    }
    else if (bVar1 == 0x40) {
      display_clear_status_row(100,0);
      display_clear_status_row(0x82,0);
      display_draw_number_centered
                (0x82,0xffff,0,
                 **(uint **)(PTR_PTR_0302d4e8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))
      ;
      display_blit_image(0x60,0x56,0x30,0x30,PTR_LAB_0302d4ec);
    }
    else if ((bVar1 == 0x20) || (bVar1 == 0x28)) {
      display_clear_status_row(100,0);
      display_clear_status_row(0x82,0);
      display_draw_number_centered
                (100,0xffff,0,
                 *(uint *)(PTR_PTR_0302d67c[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 4));
    }
  }
  return;
}

