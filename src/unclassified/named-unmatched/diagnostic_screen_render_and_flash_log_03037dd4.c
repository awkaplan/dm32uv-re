/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: diagnostic_screen_render_and_flash_log @ 03037dd4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 228 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void diagnostic_screen_render_and_flash_log(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  bVar1 = p_dialog_history_ui_state->field_0xa08;
  if (bVar1 == 0xf) {
    PTR_DAT_03037eb4[1] = PTR_DAT_03037eb4[1] & 0xf7 | 8;
    write_status_mode_byte_pair
              (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03037eb8),0);
  }
  else if (bVar1 == 0x12) {
    write_status_mode_byte_pair
              (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03037eb8),0);
  }
  else if (bVar1 == 0x13) {
    uVar2 = reg_0x67_lower9_read();
    *(short *)PTR_DAT_03037ebc = (short)uVar2;
    diag_rssi_sql_numeric_draw(3,uVar2);
    write_status_mode_byte_pair
              (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03037eb8),0);
  }
  else {
    if (p_dialog_history_ui_state->field_0xa09 == 0x4a) {
      adc_diag_avg_ch2_display();
    }
    else if (bVar1 == 0x11) {
      adc_diag_avg_ch1_display();
    }
    uStack_8 = (undefined1)*(undefined2 *)PTR_DAT_03037ebc;
    uStack_7 = (undefined1)((ushort)*(undefined2 *)PTR_DAT_03037ebc >> 8);
    if (((p_dialog_history_ui_state->field_0xa09 == 0x1a) ||
        (p_dialog_history_ui_state->field_0xa09 == 0x4a)) ||
       (p_dialog_history_ui_state->field_0xa08 == 0x11)) {
      flash_block_write(2,*(undefined2 *)PTR_DAT_03037ec0,&uStack_8,2);
    }
    else {
      flash_block_write(2,*(undefined2 *)PTR_DAT_03038044,&uStack_8,1);
    }
    write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_03038048[2] + DAT_0303804c),0);
  }
  return;
}

