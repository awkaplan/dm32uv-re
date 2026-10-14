/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_caller_dialog_screen @ 0302d79c (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_caller_dialog_screen(void)

{
  uint value;
  undefined1 *puVar1;
  
  tx_abort_on_condition();
  value = p_caller_id_display_text;
  contact_name_lookup_or_format
            (1,*(undefined4 *)&p_dialog_flags_from_flash->field_0x24_0,p_caller_id_display_text,3);
  display_draw_dialog_panel();
  display_draw_status_bar();
  puVar1 = p_dm32_settings_block04;
  display_draw_number_centered
            (100,0,0xc618,
             *(uint *)(PTR_PTR_0302d840[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 0x28));
  display_draw_number_centered(0x82,0,0xc618,value);
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_update_datetime(1);
  display_draw_string_gb2312
            (0x122,0xb4,
             (byte *)**(undefined4 **)(PTR_PTR_0302d844 + ((byte)puVar1[0x30] >> 6 & 1) * 8),0xffff,
             0);
  return;
}

