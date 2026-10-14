/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: incoming_call_display_screen @ 0302c41c (file base 0x03000000; code starts at 0x03001000)
 * Size: 218 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void incoming_call_display_screen(void)

{
  tx_ptt_ui_state *ptVar1;
  int iVar2;
  byte *text;
  byte abStack_28 [24];
  
  iVar2 = contact_name_lookup_or_format
                    (1,*(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0,
                     &p_tx_ptt_ui_state->field_0x2e,3);
  if (iVar2 == 0) {
    text = &p_tx_ptt_ui_state->field_0x2e;
    flash_binary_search_le_record(*(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0,text);
    display_fill_screen(0);
    display_draw_status_bar();
    display_draw_string_gb2312(0x28,5,text,0xffff,0);
  }
  else {
    display_fill_screen(0);
    display_draw_status_bar();
    ptVar1 = p_tx_ptt_ui_state;
    number_to_string_format_2args
              (abStack_28,PTR_s__d_030afae0_8_0302c500,
               *(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0);
    display_draw_string_gb2312(0x28,5,abStack_28,0xffff,0);
    display_draw_string_gb2312(0x46,5,&ptVar1->field_0x2e,0xffff,0);
  }
  display_blit_image(0x82,0xd4,0x30,0x30,PTR_LAB_0302c504);
  display_blit_image(0xb0,0xc4,0x40,0x40,PTR_LAB_0302c508);
  display_draw_string_gb2312
            (0x82,5,*(byte **)(PTR_PTR_0302c50c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4
                              ),0xffff,0);
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_update_datetime(0);
  return;
}

