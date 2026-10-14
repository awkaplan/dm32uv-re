/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_ab_swap @ 03039988 (file base 0x03000000; code starts at 0x03001000)
 * Size: 180 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_ab_swap(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  if ((((p_dialog_history_ui_state->field_0x3 == 0) ||
       (p_dialog_history_ui_state->field_0x3 == 0x5b)) && ((PTR_DAT_03039b08[8] & 1) == 0)) &&
     ((*(byte *)p_call_active_flag & 8) == 0)) {
    if (((p_dm32_settings_block04[0x6c] != '\0') && (iVar2 = get_current_mode_state2(), iVar2 == 3))
       && ((PTR_DAT_03039b14[1] & 1) == (byte)p_dm32_settings_block04[0x2d] >> 7)) {
      display_draw_tone_mode_icon
                ((byte)p_dm32_settings_block04[0x2d] >> 7,p_vfo_display_state->flags_0x8 >> 4,0xf800
                );
    }
    puVar1 = p_dm32_settings_block04;
    p_dm32_settings_block04[0x2d] =
         p_dm32_settings_block04[0x2d] & 0x7f | (p_dm32_settings_block04[0x2d] ^ 0x80) & 0x80;
    settings_write_dispatcher(0xd);
    contact_record_copy_with_limit((byte)puVar1[0x2d] >> 7);
    vfo_load_side_config();
    settings_bitfield_remap_0x2d();
    PTR_DAT_03039b14[1] = PTR_DAT_03039b14[1] & 0xfe | (byte)puVar1[0x2d] >> 7;
    ui_event_notify_alt(10);
  }
  return;
}

