/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_frequency_digit_cursor_step_back @ 0302f344 (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 vfo_frequency_digit_cursor_step_back(void)

{
  byte bVar1;
  vfo_freq_display_state *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  
  pvVar2 = p_vfo_freq_display_state;
  if (*(short *)&p_vfo_freq_display_state->field_0x8_0 ==
      *(short *)&p_vfo_freq_display_state->field_0x54_0) {
    uVar3 = 0;
  }
  else if (*(short *)&p_vfo_freq_display_state->field_0xa_0 ==
           *(short *)&p_vfo_freq_display_state->field_0x54_0) {
    uVar3 = 0;
  }
  else {
    bVar1 = p_vfo_freq_display_state->field_0x1;
    if (bVar1 < 3) {
      uVar3 = 0;
    }
    else {
      uVar4 = (uint)p_vfo_freq_display_state->field_0xe;
      if (uVar4 != 0) {
        for (; uVar4 < bVar1; uVar4 = uVar4 + 1 & 0xff) {
          *(undefined2 *)(&pvVar2->field_0x14_0 + uVar4 * 2) =
               *(undefined2 *)(&pvVar2->field_0x16_0 + uVar4 * 2);
        }
      }
      pvVar2 = p_vfo_freq_display_state;
      p_vfo_freq_display_state->field_0x1 = bVar1 - 1;
      dtmf_digit_input_handler(3);
      vfo_frequency_panel_render();
      uVar3 = 1;
      pvVar2->flags_0x10 = pvVar2->flags_0x10 & 0xfe | 1;
    }
  }
  return uVar3;
}

