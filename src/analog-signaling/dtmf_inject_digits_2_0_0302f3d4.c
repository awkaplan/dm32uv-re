/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_inject_digits_2_0 @ 0302f3d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dtmf_inject_digits_2_0(void)

{
  vfo_freq_display_state *pvVar1;
  int iVar2;
  
  iVar2 = get_current_mode_state1();
  pvVar1 = p_vfo_freq_display_state;
  if (iVar2 != 0) {
    p_vfo_freq_display_state->field_0x11 = p_vfo_freq_display_state->field_0x11 & 0xfe | 1;
    dtmf_digit2_input_and_clear_flag(2);
    dtmf_digit_input_handler(0);
    pvVar1->field_0x11 = pvVar1->field_0x11 & 0xfe;
  }
  return;
}

