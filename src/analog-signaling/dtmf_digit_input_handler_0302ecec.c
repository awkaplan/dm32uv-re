/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_digit_input_handler @ 0302ecec (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dtmf_digit_input_handler(int param_1__w)

{
  byte param_1 = (byte)param_1__w;
  vfo_freq_display_state *pvVar1;
  undefined1 *puVar2;
  
  pvVar1 = p_vfo_freq_display_state;
  p_vfo_freq_display_state->field_0x13 = p_vfo_freq_display_state->field_0x12;
  pvVar1->field_0x12 = param_1;
  puVar2 = PTR_DAT_0302ede0;
  if (param_1 == 3) {
    PTR_DAT_0302ede0[4] = PTR_DAT_0302ede0[4] & 0xfe;
    puVar2[1] = 0;
    PTR_DAT_0302ede4[0x12] = 0;
  }
  else if ((param_1 == 6) && ((*(byte *)p_dialog_flags_from_flash & 1) == 0)) {
    p_vfo_freq_display_state->field_0xf = p_vfo_freq_display_state->field_0xf & 0xbf | 0x40;
  }
  return;
}

